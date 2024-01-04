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
    auto calc = [&](const std::vector<int> &par, const std::vector<int> &vs,
                    const std::vector<int> &color) -> void {
        int sz = (int)par.size();
        std::vector<int> dist(n, 0);
        for (const int v : std::views::iota(1, sz)) {
            dist[v] = dist[par[v]] + 1;
        }
        std::vector<u64> f(sz, 0), g(sz, 0);
        for (const int v : std::views::iota(0, sz)) {
            if (color[v] == 0) f[dist[v]]++;
            if (color[v] == 1) g[dist[v]]++;
        }
        while (!f.empty() && f.back() == 0) {
            f.pop_back();
        }
        while (!g.empty() && g.back() == 0) {
            g.pop_back();
        }
        auto h = convolution_mod_2_64(f, g);
        for (const int i : std::views::iota(0, (int)h.size())) {
            ans[i] += h[i];
        }
    };
    centroid_decomposition<2>(tree, calc);
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