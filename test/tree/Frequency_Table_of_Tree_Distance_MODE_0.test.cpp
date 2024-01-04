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
    graph g(n);
    rep(i, 0, n - 1) {
        int a, b;
        std::cin >> a >> b;
        g.add_edge(a, b);
    }
    std::vector<i64> ans(n, 0);
    auto f = [&](const std::vector<int> &par, const std::vector<int> &vs,
                 const std::vector<int> &index_ptr) -> void {
        int sz = par.size();
        std::vector<int> dist(sz, 0);
        rep(v, 1, sz) {
            dist[v] = dist[par[v]] + 1;
        }
        auto calc = [&](int l, int r, int sgn) -> void {
            int max = *std::max_element(dist.begin() + l, dist.begin() + r);
            std::vector<u64> table(max + 1, 0);
            rep(v, l, r) {
                table[dist[v]]++;
            }
            auto a = convolution_mod_2_64(table, table);
            rep(i, 1, a.size()) {
                ans[i] += sgn * i64(a[i]);
            }
        };
        calc(0, sz, 1);
        rep(c, 1, index_ptr.size() - 1) {
            int l = index_ptr[c];
            int r = index_ptr[c + 1];
            calc(l, r, -1);
        }
    };
    centroid_decomposition<0>(g, f);
    ans.erase(ans.begin());
    for (auto &x : ans) {
        x /= 2;
    }
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