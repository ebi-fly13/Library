#define PROBLEM                        \
    "https://judge.yosupo.jp/problem/" \
    "compositional_inverse_of_formal_power_series"

#include <iostream>

#include "../../convolution/ntt.hpp"
#include "../../fps/compositional_inverse_of_fps.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;
using FPS = ebi::FormalPowerSeries<mint, ebi::convolution>;

int main() {
    int n;
    std::cin >> n;
    FPS f(n);
    for (int i = 0; i < n; i++) {
        std::cin >> f[i];
    }
    FPS g = ebi::compositional_inverse_of_fps(f);
    for (int i = 0; i < n; i++) {
        std::cout << g[i] << " \n"[i == n - 1];
    }
}