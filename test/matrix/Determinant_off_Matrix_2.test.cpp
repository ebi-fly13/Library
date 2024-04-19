#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "../../matrix/base.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    int n;
    std::cin >> n;
    matrix<mint> a(n, n);
    std::cin >> a;
    std::cout << det(a) << '\n';
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