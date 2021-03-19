#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B&lang=ja"

#include <iostream>

#include "../math/pow.hpp"
#include "../utility/int_alias.hpp"

int main() {
    u64 m,n;
    std::cin >> m >> n;
    std::cout << ebi::pow(m,n,1e9+7) << '\n';
}