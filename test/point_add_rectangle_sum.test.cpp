#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include <cstdint>
#include <iostream>

#include "../data_structure/compress.hpp"
#include "../data_structure/segtree_2d.hpp"

using i64 = std::int64_t;

i64 op(i64 a, i64 b) {
    return a + b;
}

i64 e() {
    return 0;
}

struct Query {
    i64 x, y, w;
    i64 l, d, r, u;
    int flag;
};

int main() {
    int n, q;
    std::cin >> n >> q;
    ebi::compress<i64> cp;
    std::vector<i64> x(n), y(n), w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i] >> w[i];
        cp.add(x[i]);
    }
    std::vector<Query> query(q);
    for (int i = 0; i < q; i++) {
        std::cin >> query[i].flag;
        if (query[i].flag == 0) {
            std::cin >> query[i].x >> query[i].y >> query[i].w;
            cp.add(query[i].x);
        } else {
            std::cin >> query[i].l >> query[i].d >> query[i].r >> query[i].u;
        }
    }
    cp.build();
    ebi::segtree_2d<i64, op, e> seg(cp.size());
    for (int i = 0; i < n; i++) {
        seg.pre_set(cp.get(x[i]), y[i]);
    }
    for (int i = 0; i < q; i++) {
        if (query[i].flag == 0) {
            seg.pre_set(cp.get(query[i].x), query[i].y);
        }
    }
    seg.build();
    for (int i = 0; i < n; i++) {
        seg.set(cp.get(x[i]), y[i], w[i]);
    }
    for (int i = 0; i < q; i++) {
        if (query[i].flag == 0) {
            seg.set(cp.get(query[i].x), query[i].y, query[i].w);
        } else {
            std::cout << seg.prod(cp.get(query[i].l), cp.get(query[i].r),
                                  query[i].d, query[i].u)
                      << '\n';
        }
    }
}