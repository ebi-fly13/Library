#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"

#include "../../matrix/base.hpp"
#include "../../matrix/gauss_jordan.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    int n, m;
    std::cin >> n >> m;
    matrix<mint> a(n, m);
    std::cin >> a;
    int r = gauss_jordan(a);
    std::cout << r << '\n';
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