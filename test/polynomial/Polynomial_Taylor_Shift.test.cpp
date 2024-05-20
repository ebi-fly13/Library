#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include <iostream>

#include "../../convolution/convolution.hpp"
#include "../../fps/fps.hpp"
#include "../../fps/taylor_shift.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int n, c;
    std::cin >> n >> c;
    ebi::FormalPowerSeries<mint, ebi::convolution<mint>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    auto b = ebi::taylor_shift<mint, ebi::convolution>(a, c);
    for (int i = 0; i < n; i++) {
        std::cout << b[i] << " \n"[i == n - 1];
    }
}