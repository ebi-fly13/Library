#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <cstdint>
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
    g.read_parents(0);
    ebi::heavy_light_decomposition hld(g);
    ebi::segtree<i64, op, e> seg(n);
    auto set = [&](int u, i64 x) {
        int idx = hld.idx(u);
        seg.set(idx, seg.get(idx) + x);
    };
    for (int i = 0; i < n; i++) set(i, a[i]);
    i64 ans = 0;
    auto f = [&](int l, int r) { ans = op(ans, seg.prod(l, r)); };
    while (q--) {
        int flag;
        std::cin >> flag;
        if (flag == 0) {
            int u;
            i64 x;
            std::cin >> u >> x;
            set(u, x);
        } else {
            int u;
            std::cin >> u;
            ans = e();
            hld.subtree_query(u, true, f);
            std::cout << ans << '\n';
        }
    }
}