#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det_arbitrary_mod"

#include "../../matrix/base.hpp"
#include "../../matrix/det_arbitrary_mod.hpp"
#include "../../modint/dynamic_modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = dynamic_modint<0>;

void main_() {
    int n, m;
    std::cin >> n >> m;
    mint::set_mod(m);
    matrix<mint> a(n, n);
    std::cin >> a;
    std::cout << det_arbitrary_mod(a) << '\n';
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