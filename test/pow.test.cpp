#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include <iostream>

#include "../utility/modint.hpp"

using mint = ebi::modint1000000007;

int main() {
    long long m, n;
    std::cin >> m >> n;
    std::cout << mint(m).pow(n) << '\n';
}