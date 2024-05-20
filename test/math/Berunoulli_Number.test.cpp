#define PROBLEM "https://judge.yosupo.jp/problem/bernoulli_number"

#include <iostream>
#include <numeric>
#include <vector>

#include "../../convolution/convolution.hpp"
#include "../../math/bernoulli_number.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int n;
    std::cin >> n;
    auto ans = ebi::bernoulli_number_egf<mint, ebi::convolution>(n);
    mint fact = 1;
    for (int i = 0; i <= n; i++) {
        std::cout << ans[i] * fact << " \n"[i == n];
        fact *= i + 1;
    }
}