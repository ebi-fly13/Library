#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <cstdint>
#include <iostream>

#include "../../data_structure/compress.hpp"
#include "../../data_structure/offline_segtree_2d.hpp"

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
    ebi::compress<i64> cp;
    std::vector<i64> x(n), y(n), w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i] >> w[i];
        cp.add(x[i]);
    }
    cp.build();
    ebi::offline_segtree_2d<i64, op, e> seg(cp.size());
    for (int i = 0; i < n; i++) {
        seg.pre_set(cp.get(x[i]), y[i]);
    }
    seg.build();
    for (int i = 0; i < n; i++) {
        seg.add(cp.get(x[i]), y[i], w[i]);
    }
    while (q--) {
        i64 l, d, r, u;
        std::cin >> l >> d >> r >> u;
        std::cout << seg.prod(cp.get(l), cp.get(r), d, u) << std::endl;
    }
}