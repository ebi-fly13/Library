#define PROBLEM "https://yukicoder.me/problems/no/2747"

#include "../../math/factorial_mod_998.hpp"
#include "../../math/lagrange_interpolation.hpp"
#include "../../math/linear_sieve.hpp"
#include "../../math/sum_of_powers_iota.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    int n, k;
    std::cin >> n >> k;
    mint ans = factorial_mod_998(n - 1) * 2 *
               (n * sum_of_powers_iota<mint>(n, k) -
                sum_of_powers_iota<mint>(n, k + 1));
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