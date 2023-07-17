#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include <cstdint>
#include <iostream>
#include <vector>

#include "../../data_structure/WaveletMatrix.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (auto &val : a) {
        std::cin >> val;
    }
    ebi::WaveletMatrix<int> wm(a);
    while (q--) {
        int l, r, x;
        std::cin >> l >> r >> x;
        if (l == r) {
            std::cout << "0\n";
            continue;
        }
        std::cout << wm.rank(r, x) - wm.rank(l, x) << '\n';
    }
    return 0;
}