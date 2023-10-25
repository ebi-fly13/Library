#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"

#include "../../convolution/subset_convolution.hpp"

#include <iostream>
#include <vector>

#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int n;
    std::cin >> n;
    std::vector<mint> a(1 << n), b(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < (1 << n); i++) {
        std::cin >> b[i];
    }
    auto c = ebi::subset_convolution<mint, 20>(a, b);
    for (int i = 0; i < (1 << n); i++) {
        std::cout << c[i] << ((i == (1 << n) - 1) ? "\n" : " ");
    }
}