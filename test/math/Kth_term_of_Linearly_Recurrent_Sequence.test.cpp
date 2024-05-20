#define PROBLEM \
    "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include <iostream>
#include <vector>

#include "../../convolution/convolution.hpp"
#include "../../math/bostan_mori_algorithm.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;

int main() {
    int d;
    long long k;
    std::cin >> d >> k;
    std::vector<mint> a(d), c(d);
    for (int i = 0; i < d; i++) {
        int val;
        std::cin >> val;
        a[i] = val;
    }
    for (int i = 0; i < d; i++) {
        int val;
        std::cin >> val;
        c[i] = val;
    }
    std::cout << ebi::kitamasa<mint, ebi::convolution>(k, a, c).val() << '\n';
}