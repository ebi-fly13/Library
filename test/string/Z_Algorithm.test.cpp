#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../../string/Z_Algorithm.hpp"

#include <iostream>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;
    auto A = ebi::Z_Algorithm(s);
    std::cout << A[0];
    for (int i = 1; i < s.size(); i++) {
        std::cout << " " << A[i];
    }
    std::cout << '\n';
}
