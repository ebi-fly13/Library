#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include <iostream>

#include "../../math/mod_sqrt.hpp"

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int y, p;
        std::cin >> y >> p;
        auto x = ebi::mod_sqrt(y, p);
        if (x) {
            std::cout << x.value() << '\n';
        } else {
            std::cout << "-1\n";
        }
    }
}