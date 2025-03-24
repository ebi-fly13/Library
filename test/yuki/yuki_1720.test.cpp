#define PROBLEM "https://yukicoder.me/problems/no/1720"

#include "../../convolution/convolution.hpp"
#include "../../math/binomial.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"
#include "../../tree/common_interval_decomposition_tree.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> p(n);
    std::cin >> p;
    rep(i, 0, n) p[i]--;
    Binomial<mint> binom(n);
    common_interval_decomposition_tree permutation_tree(p);
    auto dfs = [&](auto &&self, int v) -> std::vector<mint> {
        auto node = permutation_tree.get_node(v);
        if (node.is_leaf()) {
            std::vector<mint> ret(k + 1, 0);
            ret[1] = 1;
            return ret;
        }
        std::vector<mint> ret(k + 1, 0), prev(k + 1, 0), sum(k + 1, 0);
        ret[0] = 1;
        prev[0] = 1;
        for (auto ch : node.child) {
            ret = convolution_naive(ret, self(self, ch));
            ret.resize(k + 1);
            if (node.is_linear()) {
                rep(i, 0, k) {
                    ret[i + 1] += sum[i];
                }
            }
            rep(i,0,k) {
                sum[i] += prev[i];
            }
            prev = ret;
        }
        ret.resize(k + 1);
        if (node.is_prime()) ret[1]++;
        return ret;
    };
    auto ans = dfs(dfs, permutation_tree.root_id());
    ans.resize(k + 1);
    rep(i, 1, k + 1) {
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