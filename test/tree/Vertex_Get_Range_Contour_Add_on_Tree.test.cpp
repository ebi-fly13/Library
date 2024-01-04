#define PROBLEM \
    "https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree"

#include "../../data_structure/dual_segtree.hpp"
#include "../../graph/template.hpp"
#include "../../template/template.hpp"
#include "../../tree/contour_query_on_tree.hpp"

namespace ebi {

i64 op(i64 a, i64 b) {
    return a + b;
}

i64 e() {
    return 0;
}

void main_() {
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> a(n);
    std::cin >> a;
    graph g(n);
    rep(i, 0, n - 1) {
        int u, v;
        std::cin >> u >> v;
        g.add_edge(u, v);
    }
    contour_query_on_tree cq(g);
    dual_segtree<i64, op, e> seg(cq.size());
    while (q--) {
        int type;
        std::cin >> type;
        if (type == 0) {
            int p, l, r;
            i64 x;
            std::cin >> p >> l >> r >> x;
            if (l == 0) a[p] += x;
            for (auto [il, ir] : cq.get_contour_from_vertex(p, l, r)) {
                seg.apply(il, ir, x);
            }
        } else {
            int p;
            std::cin >> p;
            i64 ans = a[p];
            for (auto i : cq.get_vertex(p)) {
                ans += seg.get(i);
            }
            std::cout << ans << '\n';
        }
    }
}

}  // namespace ebi

int main() {
    ebi::fast_io();
    int t = 1;
    // std::cin >> t;
    while (t--) {
        ebi::main_();
    }
    return 0;
}