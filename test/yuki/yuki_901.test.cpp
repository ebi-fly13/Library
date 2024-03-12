#define PROBLEM "https://yukicoder.me/problems/no/901"

#include "../../graph/base.hpp"
#include "../../template/template.hpp"
#include "../../tree/heavy_light_decomposition.hpp"
#include "../../tree/lca_based_auxiliary_tree.hpp"

namespace ebi {

void main_() {
    int n;
    std::cin >> n;
    Graph<i64> g(n);
    g.read_tree(0, true);
    heavy_light_decomposition hld(g);
    int q;
    std::cin >> q;
    while (q--) {
        int k;
        std::cin >> k;
        std::vector<int> vs(k);
        for (auto &v : vs) std::cin >> v;
        if (k == 1) {
            std::cout << "0\n";
            continue;
        }
        auto [ids, tree] = hld.lca_based_auxiliary_tree(vs);
        std::vector<int> par(tree.size(), -1);
        i64 ans = 0;
        auto dfs = [&](auto &&self, int v) -> void {
            for (auto e : tree[v]) {
                if (par[v] == e.to) continue;
                ans += e.cost;
                par[e.to] = v;
                self(self, e.to);
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