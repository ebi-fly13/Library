#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"

#include "../../convolution/lcm_convolution.hpp"

#include <iostream>
#include <vector>

#include "../../utility/modint.hpp"

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
    auto c = ebi::lcm_convolution(a, b);
    for (int i = 1; i <= n; i++) {
        std::cout << c[i].val() << " \n"[i == n];
    }
}