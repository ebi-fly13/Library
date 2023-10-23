#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3361"

#include <cassert>
#include <iostream>
#include <vector>

#include "../../fps/fps_sparse.hpp"
#include "../../math/binomial.hpp"
#include "../../utility/modint.hpp"

using mint = ebi::modint998244353;
ebi::Binomial<mint> comb(1000000);

int main() {
    int k, n;
    std::vector<mint> f(300);
    f[1] = 1;
    f[256] = -256;
    f[257] = 255;
    while (std::cin >> k >> n, !(n == 0 && k == 0)) {
        auto dp = ebi::pow_sparse(f, k, n + 1);
        assert(int(dp.size()) == n + 1);
        mint ans = 0;
        for (int i = n; i >= 0; i--) {
            ans += dp[i] * comb.c(2 * k - 1 + n - i, n - i);
        }
        std::cout << ans.val() << '\n';
    }
}