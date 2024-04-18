#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"

#include "../../matrix/square_matrix.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;
using matrix = square_matrix<mint, 0>;

void main_() {
    int n;
    i64 k;
    std::cin >> n >> k;
    matrix::set_size(n);
    matrix a;
    std::cin >> a;
    std::cout << a.pow(k) << '\n';
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