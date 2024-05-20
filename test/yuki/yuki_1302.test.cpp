#define PROBLEM "https://yukicoder.me/problems/no/1302"

#include <iostream>

#include "../../convolution/convolution.hpp"
#include "../../fps/fps.hpp"
#include "../../math/binomial.hpp"
#include "../../modint/modint.hpp"

using mint = ebi::modint998244353;
using FPS = ebi::FormalPowerSeries<mint, ebi::convolution>;
using Binomial = ebi::Binomial<mint>;

int main() {
    int n;
    std::cin >> n;
    FPS f(n + 1);
    Binomial::reserve(n);
    for (int i = 0; i < n + 1; i++) {
        f[i] = (i + 1) * Binomial::inv_f(i);
    }
    mint ans = f.pow(n)[n - 2] * Binomial::f(n - 2) / mint(n).pow(n - 2);
    std::cout << ans.val() << '\n';
}