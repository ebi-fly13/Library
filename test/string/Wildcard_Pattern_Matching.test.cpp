#define PROBLEM "https://judge.yosupo.jp/problem/wildcard_pattern_matching"

#include "../../string/wildcard_pattern_matching.hpp"

#include "../../template/template.hpp"

namespace ebi {

void main_() {
    std::string s, t;
    std::cin >> s >> t;
    for (auto r : wildcard_pattern_matching(s, t)) {
        if (r)
            std::cout << '1';
        else
            std::cout << '0';
    }
    std::cout << '\n';
}

}  // namespace ebi

int main() {
    ebi::fast_io();
    int t = 1;
    // std::cin >> t;
    while (t--) {
        ebi::main_();
    }
    return 0;
}