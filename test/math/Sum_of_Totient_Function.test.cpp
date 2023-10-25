#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"

#include "../../graph/template.hpp"
#include "../../math/DirichletSeries.hpp"
#include "../../template/template.hpp"
#include "../../modint/modint.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    i64 n;
    std::cin >> n;
    using DirichletSeries = DirichletSeries<mint, 0>;
    DirichletSeries::set_size(n);
    mint ans = (DirichletSeries::zeta1() / DirichletSeries::zeta()).get_sum();
    std::cout << ans << '\n';
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