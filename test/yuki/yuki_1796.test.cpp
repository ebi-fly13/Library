#define PROBLEM "https://yukicoder.me/problems/no/1796"

#include "../../convolution/convolution.hpp"
#include "../../fps/middle_product.hpp"
#include "../../graph/base.hpp"
#include "../../math/binomial.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"
#include "../../tree/centroid_decomposition.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    Binomial<mint> binom(300000);
    int n;
    std::cin >> n;
    std::vector<mint> q(n);
    std::cin >> q;
    Graph<int> tree(n);
    auto ans = q;
    rep(i, 0, n - 1) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        tree.add_edge(u, v, 1);
        tree.add_edge(v, u, 1);
        ans[u] += q[v] * binom.inv(4);
        ans[v] += q[u] * binom.inv(4);
    }
    tree.build();
    auto calc = [&](const std::vector<int> &par, const std::vector<int> &vs,
                    int n0, int n1) {
        int sz = (int)par.size();
        std::vector<int> depth(sz, 0);
        rep(i, 1, sz) {
            depth[i] = depth[par[i]] + 1;
        }
        auto calc2 = [&](int l0, int r0, int l1, int r1) -> void {
            int sz0 = *std::max_element(depth.begin() + l0, depth.begin() + r0);
            int sz1 = *std::max_element(depth.begin() + l1, depth.begin() + r1);
            std::vector<mint> f(sz0 + sz1 + 1), g(sz1 + 1);
            rep(i, 0, f.size()) {
                f[i] = binom.inv(i + 1) * binom.inv(i + 1);
            }
            rep(i, l1, r1) {
                g[depth[i]] += q[vs[i]];
            }
            auto h = middle_product<mint, convolution>(f, g);
            assert((int)h.size() == sz0 + 1);
            rep(i, l0, r0) {
                ans[vs[i]] += h[depth[i]];
            }
        };
        calc2(1, 1 + n0, 1 + n0, 1 + n0 + n1);
        calc2(1 + n0, 1 + n0 + n1, 1, 1 + n0);
    };
    centroid_decomposition<1>(tree, calc);
    rep(i, 0, n) {
        ans[i] *= binom.f(n) * binom.f(n);
        std::cout << ans[i] << '\n';
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