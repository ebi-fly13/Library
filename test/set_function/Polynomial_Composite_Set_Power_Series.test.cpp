#define PROBLEM \
    "https://judge.yosupo.jp/problem/polynomial_composite_set_power_series"

#include <iostream>
#include <vector>

#include "../../set_function/poly_composite_sps.hpp"
#include "../../utility/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int m, n;
    std::cin >> m >> n;
    std::vector<mint> f(m);
    for (int i = 0; i < m; i++) std::cin >> f[i];
    std::vector<mint> b(1 << n);
    for (int i = 0; i < (1 << n); i++) std::cin >> b[i];
    auto c = ebi::poly_composite_sps<mint, 20>(b, f);
    for (int i = 0; i < (1 << n); i++) {
        std::cout << c[i] << " \n"[i == (1 << n) - 1];
    }
}