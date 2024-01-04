#define PROBLEM \
    "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include "../../convolution/convolution_mod_2_64.hpp"
#include "../../graph/template.hpp"
#include "../../template/template.hpp"
#include "../../tree/centroid_decomposition.hpp"

namespace ebi {

void main_() {
    int n;
    std::cin >> n;
    graph tree(n);
    rep(i, 0, n - 1) {
        int a, b;
        std::cin >> a >> b;
        tree.add_edge(a, b);
    }
    std::vector<u64> ans(n, 0);
    ans[1] = n - 1;
    auto calc = [&](const std::vector<int> &par, const std::vector<int> &vs,
                    int n0, int n1) -> void {
        int sz = (int)par.size();
        assert(sz - 1 == n0 + n1);
        std::vector<int> dist(sz, 0);
        for (const int v : std::views::iota(1, sz)) {
            dist[v] = dist[par[v]] + 1;
        }
        std::vector<u64> f(sz, 0), g(sz, 0);
        for (const int v : std::views::iota(1, sz)) {
            if(v < 1 + n0) f[dist[v]]++;
            else g[dist[v]]++;
        }
        while (!f.empty() && f.back() == 0) f.pop_back();
        while (!g.empty() && g.back() == 0) g.pop_back();
        auto h = convolution_mod_2_64(f, g);
        for (const int i : std::views::iota(0, (int)h.size())) {
            ans[i] += h[i];
        }
    };
    centroid_decomposition<1>(tree, calc);
    ans.erase(ans.begin());
    std::cout << ans << '\n';
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