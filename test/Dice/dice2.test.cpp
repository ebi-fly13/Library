#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_B"

#include <iostream>

#include "../../Dice/Dice.hpp"

int main() {
    ebi::Dice d;
    std::cin >> d;
    int q;
    std::cin >> q;
    while (q--) {
        int a, b;
        std::cin >> a >> b;
        d.set(d.get_index(a), d.get_index(b));
        std::cout << d.right_val() << '\n';
    }
}