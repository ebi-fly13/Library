#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include "../../math/combination.hpp"
#include "../../template/template.hpp"
#include "../../utility/dynamic_modint.hpp"

namespace ebi {

using mint = dynamic_modint<0>;

void main_() {
    int t, m;
    std::cin >> t >> m;
    mint::set_mod(m);
    combination<mint> comb(std::min(m, 10000010) - 1);
    rep(i, 0, t) {
        int n, k;
        std::cin >> n >> k;
        std::cout << comb(n, k).val() << '\n';
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