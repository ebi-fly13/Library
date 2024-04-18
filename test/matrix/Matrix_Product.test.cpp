#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include "../../matrix/base.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    int n, m, k;
    std::cin >> n >> m >> k;
    matrix<mint> a(n, m), b(m, k);
    std::cin >> a >> b;
    matrix<mint> c = a * b;
    std::cout << c << '\n';
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