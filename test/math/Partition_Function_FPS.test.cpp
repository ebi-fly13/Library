#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include <iostream>
#include <numeric>
#include <vector>

#include "../../convolution/convolution.hpp"
#include "../../fps/fps.hpp"
#include "../../fps/product_of_one_minus_xn.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;
using FPS = ebi::FormalPowerSeries<mint, ebi::convolution>;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 1);
    FPS f = ebi::product_of_one_minus_xn<mint, ebi::convolution>(a, n + 1);
    f = f.inv();
    for (int i = 0; i <= n; i++) {
        std::cout << f[i].val() << " \n"[i == n];
    }
}