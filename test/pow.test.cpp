#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include "../math/pow.hpp"

#include <iostream>

#include "../utility/modint.hpp"

using mint = ebi::modint1000000007;

int main() {
    u64 m, n;
    std::cin >> m >> n;
    std::cout << mint(m).pow(n) << '\n';
}