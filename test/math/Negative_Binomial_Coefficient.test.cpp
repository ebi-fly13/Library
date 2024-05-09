#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../math/binomial.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"
#include "../../utility/random_number_generator.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    random_number_generator rng;
    int sz = 1000;
    std::vector<mint> a(sz, 0);
    a[0] = 1;
    int d = rng.get(1, 2000);
    rep(i, 0, d) {
        rep(j, 0, sz - 1) {
            a[j + 1] += a[j];
        }
    }
    rep(i, 0, sz) {
        assert(a[i] == Binomial<mint>::neg_c(i, d));
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
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}