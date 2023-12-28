#pragma once

#include <cassert>
#include <concepts>
#include <cstdint>
#include <iostream>
#include <optional>
#include <vector>

namespace ebi {

struct stern_brocot_tree {
  private:
    using value_type = std::int64_t;
    using T = value_type;
    using Fraction = std::pair<T, T>;

    static Fraction add(const Fraction &lhs, const Fraction &rhs) {
        return {lhs.first + rhs.first, lhs.second + rhs.second};
    }

    static Fraction mul(const T k, const Fraction &a) {
        return {k * a.first, k * a.second};
    }

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
            T k = std::min(path_f[i], path_g[i]);
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

    template <class F> static Fraction binary_search(const T max_value, F f) {
        Fraction l = {0, 1}, r = {1, 0};
        while (true) {
            Fraction now = val({l, r});
            bool flag = f(now);
            Fraction from = flag ? l : r;
            Fraction to = flag ? r : l;
            T ok = 1, ng = 2;
            while (f(add(from, mul(ng, to))) == flag) {
                ok <<= 1;
                ng <<= 1;
                auto nxt = add(from, mul(ok, to));
                if (nxt.first > max_value || nxt.second > max_value) return to;
            }
            while (ng - ok > 1) {
                T mid = (ok + ng) >> 1;
                if (f(add(from, mul(mid, to))) == flag) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            (flag ? l : r) = add(from, mul(ok, to));
        }
        assert(0);
        return l;
    }

    static Fraction val(const std::pair<Fraction, Fraction> &f) {
        return add(f.first, f.second);
    }

    static void print_path(const std::vector<T> &path) {
        if (path.empty()) {
            std::cout << "0\n";
            return;
        }
        int k = (int)path.size() - int(path[0] == 0);
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