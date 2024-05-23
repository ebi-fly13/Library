#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include <iostream>

#include "../../fps/ntt_friendly_fps.hpp"
#include "../../fps/taylor_shift.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int n, c;
    std::cin >> n >> c;
    ebi::FormalPowerSeries<mint> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    auto b = ebi::taylor_shift<mint>(a, c);
    for (int i = 0; i < n; i++) {
        std::cout << b[i] << " \n"[i == n - 1];
    }
}