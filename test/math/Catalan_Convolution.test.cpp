#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../math/catalan_convolution.hpp"

#include "../../convolution/ntt.hpp"
#include "../../math/catalan_number.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    const int n = 100000;
    int t = 10;
    std::vector<mint> c(n);
    rep(i, 0, n) c[i] = catalan_number<mint>(i);
    std::vector<mint> a = {1};
    rep(i, 1, t) {
        a = convolution(a, c);
        a.resize(n);
        rep(j, 0, n) assert(a[j] == catalan_convolution<mint>(i, j));
    }
    return;
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