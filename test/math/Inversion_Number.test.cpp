#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D"

#include "../../math/inversion_number.hpp"

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::cout << ebi::inversion_number(a) << '\n';
}