#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include <iostream>
#include <vector>

#include "../../data_structure/WaveletMatrix.hpp"
#include "../../template/int_alias.hpp"

using ebi::i64;

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