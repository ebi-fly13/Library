#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include "../../convolution/gcd_convolution.hpp"

#include <iostream>
#include <vector>

#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int n;
    std::cin >> n;
    std::vector<mint> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
    }
    auto c = ebi::gcd_convolution(a, b);
    for (int i = 1; i <= n; i++) {
        std::cout << c[i].val() << " \n"[i == n];
    }
}