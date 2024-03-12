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
        std::cin >> vs;
        i64 ans = 0;
        auto auxiliary_tree = hld.lca_based_auxiliary_tree_dfs_order(vs);
        for (auto [v, par] : auxiliary_tree) {
            if (par != -1) {
                ans += hld.distance(par, v);
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