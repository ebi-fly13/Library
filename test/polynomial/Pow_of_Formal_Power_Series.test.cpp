#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include <iostream>

#include "../../convolution/convolution.hpp"
#include "../../fps/fps.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int n;
    long long m;
    std::cin >> n >> m;
    ebi::FormalPowerSeries<mint, ebi::convolution<mint>> f(n);
    for (int i = 0; i < n; i++) {
        std::cin >> f[i];
    }
    auto b = f.pow(m);
    for (int i = 0; i < n; i++) {
        std::cout << b[i] << " \n"[i == n - 1];
    }
}