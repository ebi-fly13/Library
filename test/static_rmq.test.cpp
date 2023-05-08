#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <vector>

#include "../data_structure/sparse_table.hpp"

int op(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    ebi::sparse_table<int, op> st(a);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << st.fold(l, r) << std::endl;
    }
}