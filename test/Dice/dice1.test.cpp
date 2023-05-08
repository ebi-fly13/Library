#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_A"

#include <iostream>

#include "../../Dice/Dice.hpp"

int main() {
    ebi::Dice d;
    std::cin >> d;
    std::string s;
    std::cin >> s;
    for (auto c : s) {
        if (c == 'E') d.rollE();
        if (c == 'N') d.rollN();
        if (c == 'S') d.rollS();
        if (c == 'W') d.rollW();
    }
    std::cout << d.top_val() << '\n';
}