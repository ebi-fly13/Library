#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include "../math/FormalPowerSeries.hpp"

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    ebi::FormalPowerSeries a(n);
    for(int i = 0; i<n; ++i) {
        int val;
        std::cin >> val;
        a[i] = val;
    }
    ebi::FormalPowerSeries b = a.exp();
    for(int i = 0; i<n; ++i) {
        std::cout << b[i].value() << " ";
    }
    std::cout << '\n';
}