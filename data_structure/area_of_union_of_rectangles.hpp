#pragma once

#include <cassert>
#include <limits>
#include <vector>

#include "../data_structure/compress.hpp"
#include "../data_structure/lazy_segtree.hpp"
#include "../template/int_alias.hpp"

namespace ebi {

namespace internal {

using S = std::pair<int, i64>;

S op(S a, S b) {
    if (a.first == b.first)
        return {a.first, a.second + b.second};
    else if (a.first < b.first)
        return a;
    else
        return b;
}

S e() {
    return {std::numeric_limits<int>::max(), 0};
}

S mapping(int f, S x) {
    return {x.first + f, x.second};
}

int composition(int f, int g) {
    return f + g;
}

int id() {
    return 0;
}

}  // namespace internal

struct area_of_union_of_rectangles {
  private:
    using S = std::pair<int, i64>;

    static S op(S a, S b) {
        if (a.first == b.first)
            return {a.first, a.second + b.second};
        else if (a.first < b.first)
            return a;
        else
            return b;
    }

    static S e() {
        return {std::numeric_limits<int>::max(), 0};
    }

    static S mapping(int f, S x) {
        return {x.first + f, x.second};
    }

    static int composition(int f, int g) {
        return f + g;
    }

    static int id() {
        return 0;
    }

  public:
    area_of_union_of_rectangles() = default;

    void add_rectangle(i64 l, i64 d, i64 r, i64 u) {
        qs.push_back({l, d, r, u});
        cp_x.add(l);
        cp_x.add(r);
        cp_y.add(d);
        cp_y.add(u);
    }

    i64 run() {
        assert(is_first);
        is_first = false;
        cp_x.build();
        cp_y.build();
        int n = cp_x.size(), m = cp_y.size();
        lazy_segtree<S, op, e, int, mapping, composition, id> seg(
            [&]() -> std::vector<S> {
                std::vector<S> data(m - 1);
                for (int i = 0; i < m - 1; i++) {
                    data[i] = {0, cp_y.val(i + 1) - cp_y.val(i)};
                }
                return data;
            }());
        std::vector table(n,
                          std::vector(2, std::vector<std::pair<i64, i64>>()));
        for (auto [l, d, r, u] : qs) {
            int x = cp_y.get(d);
            int y = cp_y.get(u);
            table[cp_x.get(l)][0].emplace_back(x, y);
            table[cp_x.get(r)][1].emplace_back(x, y);
        }
        i64 ans = 0;
        for (int i = 0; i < n - 1; i++) {
            i64 wy = cp_y.val(m - 1) - cp_y.val(0);
            i64 wx = cp_x.val(i + 1) - cp_x.val(i);
            for (auto [d, u] : table[i][0]) {
                seg.apply(d, u, 1);
            }
            for (auto [d, u] : table[i][1]) {
                seg.apply(d, u, -1);
            }
            auto [min, cnt] = seg.all_prod();
            if (min == 0) wy -= cnt;
            ans += wx * wy;
        }
        return ans;
    }

  private:
    bool is_first = true;
    std::vector<std::array<i64, 4>> qs;
    compress<i64> cp_x, cp_y;
};

}  // namespace ebi