#define PROBLEM "https://yukicoder.me/problems/no/2633"

#include <atcoder/modint>

#include "../../convolution/online_convolution.hpp"
#include "../../math/binomial.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = atcoder::modint998244353;

void main_() {
    const int max = 100'010;
    Binomial<mint> binom(max);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::cin >> a;
    std::vector<int> table(max, 0);
    rep(i, 0, n) table[a[i]]++;
    online_convolution oc;
    mint ans = 0;
    rep(i, 0, max) {
        mint ret = binom.inv_f(i);
        if (i > 0) ret += oc[i - 1];
        ret *= mint(2).pow(table[i]) - 1;
        ans += ret * binom.f(i);
        oc.add(i, binom.inv_f(i + 1), ret);
    }
    std::cout << ans << '\n';
}

}

int main() {
    ebi::fast_io();
    int t = 1;
    // std::cin >> t;
    while (t--) {
        ebi::main_();
    }
    return 0;
}