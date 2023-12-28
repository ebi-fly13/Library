#pragma once

#include <cassert>
#include <concepts>
#include <iostream>
#include <optional>
#include <vector>
#include <cstdint>

namespace ebi {

struct stern_brocot_tree {
  private:
    using value_type = std::int64_t;
    using T = value_type;
    using Fraction = std::pair<T, T>;

  public:
    stern_brocot_tree() = default;

    static std::vector<T> encode_path(const Fraction &f) {
        auto [x, y] = f;
        std::vector<T> path;
        while (x != y) {
            T m = (x - 1) / y;
            path.emplace_back(m);
            x -= m * y;
            std::swap(x, y);
        }
        return path;
    }

    static std::pair<Fraction, Fraction> decode_path(
        const std::vector<T> &path) {
        T lx = 0, ly = 1, rx = 1, ry = 0;
        for (bool is_right = true; auto n : path) {
            if (is_right) {
                lx += rx * n;
                ly += ry * n;
            } else {
                rx += lx * n;
                ry += ly * n;
            }
            is_right = !is_right;
        }
        return {{lx, ly}, {rx, ry}};
    }

    static std::pair<Fraction, Fraction> decode_path(
        const std::vector<std::pair<char, T>> &path) {
        if (path.empty()) {
            return {{0, 1}, {1, 0}};
        }
        std::vector<T> p;
        bool is_right = true;
        if (path[0].first == 'L') {
            p.emplace_back(0);
            is_right = !is_right;
        }
        for (auto [c, n] : path) {
            assert(c == (is_right ? 'R' : 'L'));
            p.emplace_back(n);
            is_right = !is_right;
        }
        return decode_path(p);
    }

    static Fraction lca(Fraction f, Fraction g) {
        auto path_f = encode_path(f);
        auto path_g = encode_path(g);
        std::vector<T> path_h;
        for (int i = 0; i < (int)std::min(path_f.size(), path_g.size()); i++) {
            int k = std::min(path_f[i], path_g[i]);
            path_h.emplace_back(k);
            if (path_f[i] != path_g[i]) {
                break;
            }
        }
        return val(decode_path(path_h));
    }

    static std::optional<Fraction> ancestor(T k, Fraction f) {
        std::vector<T> path;
        for (auto n : encode_path(f)) {
            T m = std::min(k, n);
            path.emplace_back(m);
            k -= m;
            if (k == 0) break;
        }
        if (k > 0) return std::nullopt;
        return val(decode_path(path));
    }

    static std::pair<Fraction, Fraction> range(Fraction f) {
        return decode_path(encode_path(f));
    }

    static Fraction val(std::pair<Fraction, Fraction> f) {
        auto [l, r] = f;
        return {l.first + r.first, l.second + r.second};
    }

    static void print_path(const std::vector<T> &path) {
        if (path.empty()) {
            std::cout << "0\n";
            return;
        }
        int k = path.size() - int(path[0] == 0);
        std::cout << k;
        for (bool is_right = true; auto c : path) {
            if (c > 0) {
                std::cout << " " << (is_right ? 'R' : 'L') << " " << c;
            }
            is_right = !is_right;
        }
        std::cout << '\n';
        return;
    }
};

}  // namespace ebi