#define PROBLEM                        \
    "https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit"

#include "../../math/sum_of_exp_times_poly.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    i64 r, d;
    std::cin >> r >> d;
    std::cout << sum_of_exp2_limit<mint>(r, d) << '\n';
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