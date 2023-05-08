#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../data_structure/WaveletMatrix.hpp"

#include <iostream>
#include <vector>

#include "../utility/int_alias.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    ebi::WaveletMatrix<i64> wm(a);
    while (q--) {
        int l, r, k;
        std::cin >> l >> r >> k;
        std::cout << wm.quantile(l, r, k + 1) << std::endl;
    }
}