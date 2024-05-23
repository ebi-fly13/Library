#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include "../../fps/ntt_friendly_fps.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    int n;
    std::cin >> n;
    FormalPowerSeries<mint> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    auto b = a.exp();
    for (int i = 0; i < n; ++i) {
        std::cout << b[i].val() << " \n"[i == n - 1];
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