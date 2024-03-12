#define PROBLEM \
    "https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree"

#include "../../data_structure/segtree.hpp"
#include "../../graph/base.hpp"
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
    Graph<int> g(n);
    g.read_tree(0);
    contour_query_on_tree cq(g);
    std::vector<i64> data(cq.size(), 0);
    rep(v, 0, n) {
        for (auto i : cq.get_vertex(v)) {
            data[i] += a[v];
        }
    }
    segtree<i64, op, e> seg(data);
    while (q--) {
        int type;
        std::cin >> type;
        if (type == 0) {
            int p;
            i64 x;
            std::cin >> p >> x;
            a[p] += x;
            for (auto i : cq.get_vertex(p)) {
                seg.set(i, seg.get(i) + x);
            }
        } else {
            int p, l, r;
            std::cin >> p >> l >> r;
            i64 ans = 0;
            if (l == 0) ans += a[p];
            for (auto [il, ir] : cq.get_contour_from_vertex(p, l, r)) {
                ans += seg.prod(il, ir);
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