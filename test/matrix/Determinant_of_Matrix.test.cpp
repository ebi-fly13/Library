#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include <iostream>

#include "../../matrix/square_matrix.hpp"
#include "../../utility/modint.hpp"

using Matrix = ebi::square_matrix<ebi::modint998244353, 0>;

int main() {
    int n;
    std::cin >> n;
    Matrix::set_size(n);
    Matrix a;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val;
            std::cin >> val;
            a[i][j] = val;
        }
    }
    std::cout << a.det().val() << std::endl;
}