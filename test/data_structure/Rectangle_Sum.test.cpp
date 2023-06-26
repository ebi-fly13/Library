#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <cstdint>
#include <iostream>

#include "../../data_structure/compress.hpp"
#include "../../data_structure/offline_segtree_2d.hpp"
#include "../../data_structure/segtree.hpp"

using i64 = std::int64_t;

i64 op(i64 a, i64 b) {
    return a + b;
}

i64 e() {
    return 0;
}

int main() {
    int n, q;
    std::cin >> n >> q;
    ebi::offline_segtree_2d<i64, op, e, ebi::segtree<i64, op, e>> seg2d;
    std::vector<std::tuple<int, int, i64>> ps(n);
    for (auto &[x, y, w] : ps) {
        std::cin >> x >> y >> w;
        seg2d.pre_set({x, y});
    }
    seg2d.build();
    for (auto &[x, y, w] : ps) {
        seg2d.set(x, y, seg2d.get(x, y) + w);
    }
    while (q--) {
        int l, d, r, u;
        std::cin >> l >> d >> r >> u;
        std::cout << seg2d.prod(l, d, r, u) << '\n';
    }
}