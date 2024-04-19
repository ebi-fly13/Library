#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"

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
    auto inv_a = a.inv();
    if (!inv_a) {
        std::cout << "-1\n";
    } else {
        std::cout << inv_a.value() << '\n';
    }
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