#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include <iostream>

#include "../../convolution/ntt.hpp"
#include "../../fps/fps.hpp"
#include "../../utility/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int n;
    std::cin >> n;
    ebi::FormalPowerSeries<mint, ebi::convolution> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    auto b = a.inv();
    for (int i = 0; i < n; ++i) {
        std::cout << b[i].val() << " ";
    }
    std::cout << std::endl;
}