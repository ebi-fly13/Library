#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include <iostream>

#include "../../fps/ntt_friendly_fps.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    long long m;
    std::cin >> n >> m;
    ebi::FormalPowerSeries<mint> f(n);
    for (int i = 0; i < n; i++) {
        std::cin >> f[i];
    }
    auto b = f.pow(m);
    for (int i = 0; i < n; i++) {
        std::cout << b[i] << " \n"[i == n - 1];
    }
}