#define PROBLEM "https://yukicoder.me/problems/no/901"

#include "../../data_structure/segtree.hpp"
#include "../../graph/template.hpp"
#include "../../template/template.hpp"
#include "../../tree/heavy_light_decomposition.hpp"
#include "../../tree/lca_based_auxiliary_tree.hpp"

namespace ebi {

i64 op(i64 a, i64 b) {
    return a + b;
}

i64 e() {
    return 0;
}

void main_() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 3>> edges(n - 1);
    graph g(n);
    for (auto &[u, v, w] : edges) {
        std::cin >> u >> v >> w;
        g.add_edge(u, v);
    }
    heavy_light_decomposition hld(g);
    segtree<i64, op, e> seg(n);
    for (auto [u, v, w] : edges) {
        if (hld.parent(v) == u) std::swap(u, v);
        seg.set(hld.idx(u), w);
    }
    auto path_sum = [&](int u, int v) -> i64 {
        i64 sum = 0;
        auto f = [&](int l, int r) -> void {
            if (l > r) std::swap(l, r);
            sum += seg.prod(l, r);
        };
        hld.path_noncommutative_query(u, v, false, f);
        return sum;
    };
    int q;
    std::cin >> q;
    while (q--) {
        int k;
        std::cin >> k;
        std::vector<int> vs(k);
        for (auto &v : vs) std::cin >> v;
        auto [ids, tree] = hld.lca_based_auxiliary_tree(vs);
        std::vector<int> par(tree.size(), -1);
        i64 ans = 0;
        auto dfs = [&](auto &&self, int v) -> void {
            for (auto nv : tree[v]) {
                if (par[v] == nv) continue;
                ans += path_sum(ids[v], ids[nv]);
                par[nv] = v;
                self(self, nv);
            }
        };
        dfs(dfs, 0);
        std::cout << ans << '\n';
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