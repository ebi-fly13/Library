#define PROBLEM "https://yukicoder.me/problems/no/1857"

#include "../../fps/ntt_friendly_fps.hpp"
#include "../../fps/product_of_fps.hpp"
#include "../../fps/sum_of_rational_fps.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;
using FPS = FormalPowerSeries<mint>;

void main_() {
    int n, s;
    std::cin >> n >> s;
    std::vector<mint> p(n);
    mint inv_s = mint(s).inv();
    rep(i, 0, n) {
        std::cin >> p[i];
        p[i] *= inv_s;
    }
    std::vector<FPS> fs(n);
    std::vector<std::pair<FPS, FPS>> gs(n);
    rep(i, 0, n) {
        fs[i] = FPS{1, p[i]};
        gs[i] = {{0, 0, p[i] * p[i]}, {1, p[i]}};
    }
    auto lhs = product_of_fps<mint>(fs);
    auto rhs = sum_of_rational_fps<mint>(gs);
    auto f = (lhs * (rhs.first * rhs.second.inv(n + 2)).pre(n + 2)).pre(n + 2);
    mint ans = 0;
    mint fact = 1;
    rep(i, 2, n + 2) {
        ans += f[i] * fact * i;
        fact *= i;
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