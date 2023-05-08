#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_D"

#include <iostream>

#include "../../Dice/Dice.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<ebi::Dice> d(n);
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (d[i] == d[j]) {
                std::cout << "No\n";
                return 0;
            }
        }
    }
    std::cout << "Yes\n";
}