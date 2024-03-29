#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <iostream>

#include "../../convolution/ntt.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<mint> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    auto c = ebi::convolution<mint>(a, b);
    for (int i = 0; i < n + m - 1; ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << '\n';
}