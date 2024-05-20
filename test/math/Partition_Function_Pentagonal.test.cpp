#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include <iostream>
#include <numeric>
#include <vector>

#include "../../convolution/convolution.hpp"
#include "../../math/partition_function.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int n;
    std::cin >> n;
    auto ans = ebi::partition_function<mint, ebi::convolution>(n);
    for (int i = 0; i <= n; i++) {
        std::cout << ans[i] << " \n"[i == n];
    }
}