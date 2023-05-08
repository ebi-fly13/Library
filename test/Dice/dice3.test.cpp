#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_C"

#include <iostream>

#include "../../Dice/Dice.hpp"

int main() {
    ebi::Dice a, b;
    std::cin >> a >> b;
    if (a == b)
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
}