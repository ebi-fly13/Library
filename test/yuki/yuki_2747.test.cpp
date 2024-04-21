#define PROBLEM "https://yukicoder.me/problems/no/2747"

#include "../../math/factorial_mod_998.hpp"
#include "../../math/lagrange_interpolation.hpp"
#include "../../math/linear_sieve.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    int n, k;
    std::cin >> n >> k;
    linear_sieve sieve(k + 5);
    auto f = [&](int s) -> mint {
        std::vector<mint> f(s + 2, 0);
        auto pow_table = sieve.pow_table<mint>(s);
        rep(i, 1, s + 2) {
            f[i] = f[i - 1] + pow_table[i];
        }
        return lagrange_interpolation(f, n - 1);
    };
    mint ans = factorial_mod_998(n - 1) * 2 * (n * f(k) - f(k + 1));
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