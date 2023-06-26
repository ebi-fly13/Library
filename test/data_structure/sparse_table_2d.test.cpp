#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068"

#include "../../data_structure/sparse_table_2d.hpp"

#include <iostream>
#include <vector>

int op(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int r, c, q;
    while (std::cin >> r >> c >> q, !(r == 0 && c == 0 && q == 0)) {
        std::vector grid(r, std::vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                std::cin >> grid[i][j];
            }
        }
        ebi::sparse_table_2d<int, op> st2d(grid);
        while (q--) {
            int l, d, r, u;
            std::cin >> l >> d >> r >> u;
            r++;
            u++;
            std::cout << st2d.prod(l, d, r, u) << '\n';
        }
    }
}