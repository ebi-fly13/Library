#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../math/sum_of_powers_iota.hpp"
#include "../../convolution/convolution.hpp"
#include "../../math/sums_of_powers_iota.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"
#include "../../utility/random_number_generator.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    random_number_generator rng;
    i64 n = rng.get(1, 1'000'000'000);
    int k = 2'000;
    auto f = sums_of_powers_iota<mint, convolution>(n, k);
    rep(i, 0, k) {
        assert(f[i] == sum_of_powers_iota<mint>(n, i));
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
    int a,b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}