#define PROBLEM                        \
    "https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series_large"

#include "../../fps/compositional_inverse_of_fps.hpp"
#include "../../fps/ntt_friendly_fps.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    int n;
    std::cin >> n;
    FormalPowerSeries<mint> f(n);
    std::cin >> f;
    std::cout << compositional_inverse_of_fps(f) << '\n';
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