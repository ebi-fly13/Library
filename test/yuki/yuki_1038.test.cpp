#define PROBLEM "https://yukicoder.me/problems/no/1038"

#include "../../data_structure/dual_segtree.hpp"
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
    Graph<int> g(n);
    g.read_tree(1);
    std::vector<i64> res(n, 0);
    contour_query_on_tree cq(g);
    dual_segtree<i64, op, e> seg(cq.size());
    while (q--) {
        int x, y;
        i64 z;
        std::cin >> x >> y >> z;
        x--;
        i64 ans = res[x];
        for (auto i : cq.get_vertex(x)) {
            ans += seg.get(i);
        }
        std::cout << ans << '\n';
        y++;
        res[x] += z;
        for (auto [l, r] : cq.get_contour_from_vertex(x, 0, y)) {
            seg.apply(l, r, z);
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