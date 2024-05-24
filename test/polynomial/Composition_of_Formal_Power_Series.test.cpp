#define PROBLEM \
    "https://judge.yosupo.jp/problem/composition_of_formal_power_series"

#include <iostream>

#include "../../fps/composition_of_fps_old.hpp"
#include "../../fps/ntt_friendly_fps.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;
using FPS = ebi::FormalPowerSeries<mint>;

int main() {
    int n;
    std::cin >> n;
    FPS f(n), g(n);
    for (int i = 0; i < n; i++) {
        std::cin >> f[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> g[i];
    }
    FPS h = ebi::composition_of_fps(f, g);
    for (int i = 0; i < n; i++) {
        std::cout << h[i].val() << " \n"[i == n - 1];
    }
}