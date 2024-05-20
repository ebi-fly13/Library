#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"

#include <iostream>
#include <vector>

#include "../../convolution/convolution.hpp"
#include "../../fps/product_of_fps.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<mint>> fs(n);
    int D = 0;
    for (int i = 0; i < n; i++) {
        int d;
        std::cin >> d;
        D += d;
        std::vector<mint> f(d + 1);
        for (int j = 0; j < d + 1; j++) std::cin >> f[j];
        fs[i] = f;
    }
    auto f = ebi::product_of_fps<mint, ebi::convolution>(fs);
    for (int i = 0; i < D + 1; i++) {
        std::cout << f[i] << " \n"[i == D];
    }
}