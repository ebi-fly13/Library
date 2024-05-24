#define PROBLEM \
    "https://judge.yosupo.jp/problem/composition_of_formal_power_series_large"

#include "../../fps/composition_of_fps.hpp"
#include "../../fps/ntt_friendly_fps.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;
using FPS = FormalPowerSeries<mint>;

void main_() {
    int n;
    std::cin >> n;
    FPS f(n), g(n);
    std::cin >> f >> g;
    std::cout << composition_of_fps(f, g) << '\n';
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