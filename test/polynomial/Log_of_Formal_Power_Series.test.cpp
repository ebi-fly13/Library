#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"

#include <iostream>

#include "../../convolution/ntt.hpp"
#include "../../fps/fps.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int n;
    std::cin >> n;
    ebi::FormalPowerSeries<mint, ebi::convolution> a(n);
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        a[i] = val;
    }
    auto b = a.log();
    for (int i = 0; i < n; ++i) {
        std::cout << b[i].val() << " \n"[i == n - 1];
    }
}