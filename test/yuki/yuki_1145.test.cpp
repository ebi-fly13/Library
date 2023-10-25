#define PROBLEM "https://yukicoder.me/problems/no/1145"

#include "../../convolution/ntt.hpp"
#include "../../fps/fps.hpp"
#include "../../fps/sums_of_powers.hpp"
#include "../../graph/template.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;
using FPS = FormalPowerSeries<mint, convolution>;

void main_() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    std::cin >> a;
    auto ans = sums_of_powers<mint, convolution>(a, m);
    rep(i, 1, m + 1) {
        std::cout << ans[i] << " \n"[i == m];
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