#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include <iostream>
#include <string>

#include "../../data_structure/predecessor_set.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    std::string t;
    std::cin >> t;
    ebi::predecessor_set set;
    for (int i = 0; i < n; i++) {
        if (t[i] == '1') {
            set.insert(i);
        }
    }
    while (q--) {
        int flag, k;
        std::cin >> flag >> k;
        if (flag == 0) {
            set.insert(k);
        } else if (flag == 1) {
            set.erase(k);
        } else if (flag == 2) {
            std::cout << (set.find(k) ? 1 : 0) << '\n';
        } else if (flag == 3) {
            std::cout << set.find_next(k) << '\n';
        } else {
            std::cout << set.find_prev(k) << '\n';
        }
    }
}