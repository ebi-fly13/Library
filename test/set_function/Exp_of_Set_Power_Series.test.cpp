#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_set_power_series"

#include <iostream>
#include <vector>

#include "../../set_function/exp_of_sps.hpp"
#include "../../utility/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int n;
    std::cin >> n;
    std::vector<mint> b(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        int x;
        std::cin >> x;
        b[i] = x;
    }
    auto c = ebi::sps_exp<mint, 20>(b);
    for (int i = 0; i < (1 << n); i++) {
        std::cout << c[i].val() << " \n"[i == (1 << n) - 1];
    }
}