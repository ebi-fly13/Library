#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include <iostream>
#include <vector>

#include "../../data_structure/segtree.hpp"
#include "../../graph/base.hpp"
#include "../../tree/heavy_light_decomposition.hpp"

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
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    ebi::Graph<int> g(n);
    g.read_tree(0);
    ebi::heavy_light_decomposition hld(g);
    ebi::segtree<i64, op, e> seg(n);
    i64 ans = e();
    auto set = [&](int u, i64 x) {
        int idx = hld.idx(u);
        seg.set(idx, seg.get(idx) + x);
    };
    auto f = [&](int l, int r) {
        if (l <= r)
            ans = op(ans, seg.prod(l, r));
        else
            ans = op(ans, seg.prod(r, l));
    };
    for (int i = 0; i < n; i++) {
        set(i, a[i]);
    }
    while (q--) {
        int flag;
        std::cin >> flag;
        if (flag == 0) {
            int p;
            i64 x;
            std::cin >> p >> x;
            set(p, x);
        } else {
            int u, v;
            std::cin >> u >> v;
            ans = e();
            hld.path_noncommutative_query(u, v, true, f);
            std::cout << ans << '\n';
        }
    }
}