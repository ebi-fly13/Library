#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include "../../math/binomial.hpp"
#include "../../modint/dynamic_modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = dynamic_modint<0>;

void main_() {
    int t, m;
    std::cin >> t >> m;
    mint::set_mod(m);
    Binomial<mint>::reserve(std::min(m - 1, 10'000'000));
    rep(i, 0, t) {
        int n, k;
        std::cin >> n >> k;
        std::cout << Binomial<mint>::c(n, k).val() << '\n';
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