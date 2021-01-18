#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include "../math/FormalPowerSeries.hpp"

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    ebi::FormalPowerSeries a(n);
    for(int i = 0; i<n; ++i) {
        std::cin >> a[i].a;
    }
    ebi::FormalPowerSeries b = a.inv();
    for(int i = 0; i<n; ++i) {
        std::cout << b[i].value() << " ";
    }
    std::cout << std::endl;
}