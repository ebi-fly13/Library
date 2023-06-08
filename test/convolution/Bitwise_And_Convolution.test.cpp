#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include <iostream>
#include <vector>

#include "../../convolution/and_convolution.hpp"
#include "../../utility/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int n;
    std::cin >> n;
    std::vector<mint> a(1 << n), b(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        int x;
        std::cin >> x;
        a[i] = x;
    }
    for (int i = 0; i < (1 << n); i++) {
        int x;
        std::cin >> x;
        b[i] = x;
    }
    auto c = ebi::and_convolution(a, b);
    for (int i = 0; i < (1 << n); i++) {
        std::cout << c[i].val() << " \n"[i == (1 << n) - 1];
    }
}