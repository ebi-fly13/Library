#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

#include "../../fps/polynomial_interpolation.hpp"

#include "../../convolution/convolution.hpp"
#include "../../modint/modint.hpp"
#include "../../template/template.hpp"

namespace ebi {

using mint = modint998244353;

void main_() {
    int n;
    std::cin >> n;
    std::vector<mint> x(n), y(n);
    std::cin >> x >> y;
    auto f = polynomial_interpolation<mint, convolution>(x, y);
    rep(i, 0, n) {
        std::cout << f[i] << " \n"[i == n - 1];
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