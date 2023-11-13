#define PROBLEM "https://yukicoder.me/problems/no/901"

#include "../../graph/template.hpp"
#include "../../template/template.hpp"
#include "../../tree/heavy_light_decomposition.hpp"
#include "../../tree/lca_based_auxiliary_tree.hpp"

namespace ebi {

void main_() {
    int n;
    std::cin >> n;
    graph g(n);
    std::vector<std::tuple<int, int, i64>> edges(n - 1);
    for (auto &[u, v, w] : edges) {
        std::cin >> u >> v >> w;
        g.add_edge(u, v);
    }
    heavy_light_decomposition hld(g);
    std::vector<i64> sum(n + 1, 0);
    for (auto [u, v, w] : edges) {
        if (hld.parent(v) == u) std::swap(u, v);
        sum[hld.idx(u) + 1] += w;
    }
    rep(i, 0, n) {
        sum[i + 1] += sum[i];
    }
    auto path_sum = [&](int u, int v) -> i64 {
        i64 ret = 0;
        auto f = [&](int l, int r) -> void {
            if (l > r) std::swap(l, r);
            ret += sum[r] - sum[l];
        };
        hld.path_noncommutative_query(u, v, false, f);
        return ret;
    };
    int q;
    std::cin >> q;
    while (q--) {
        int k;
        std::cin >> k;
        std::vector<int> vs(k);
        std::cin >> vs;
        i64 ans = 0;
        auto auxiliary_tree = hld.lca_based_auxiliary_tree_dfs_order(vs);
        for (auto [v, par] : auxiliary_tree) {
            if (par != -1) {
                ans += path_sum(v, par);
            }
        }
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