#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <iostream>
#include <vector>

#include "../../convolution/arbitrary_convolution.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint1000000007;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<mint> a(n), b(m);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < m; i++) std::cin >> b[i];
    auto c = ebi::arbitary_convolution<mint>(a, b);
    for (int i = 0; i < n + m - 1; i++) {
        std::cout << c[i].val() << " \n"[i == n + m - 2];
    }
}