#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"

#include "../algorithm/subset_convolution.hpp"

#include <iostream>
#include <vector>

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
    auto c = ebi::subset_convolution(a, b, n);
    for (int i = 0; i < (1 << n); i++) {
        std::cout << c[i].val() << ((i == (1 << n) - 1) ? "\n" : " ");
    }
}