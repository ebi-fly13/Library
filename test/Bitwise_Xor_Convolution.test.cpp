#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include <iostream>
#include <vector>

#include "../set_function/xor_convolution.hpp"
#include "../utility/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int n;
    std::cin >> n;
    std::vector<mint> a(1 << n), b(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        int val;
        std::cin >> val;
        a[i] = val;
    }
    for (int i = 0; i < (1 << n); i++) {
        int val;
        std::cin >> val;
        b[i] = val;
    }
    auto c = ebi::xor_convolution(a, b);
    for (int i = 0; i < (1 << n); i++) {
        std::cout << c[i].val() << " \n"[i == (1 << n) - 1];
    }
}
