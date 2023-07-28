#define PROBLEM "https://yukicoder.me/problems/no/1302"

#include <iostream>

#include "../../convolution/ntt.hpp"
#include "../../fps/fps.hpp"
#include "../../math/combination.hpp"
#include "../../utility/modint.hpp"

using mint = ebi::modint998244353;
using FPS = ebi::FormalPowerSeries<mint, ebi::convolution>;

int main() {
    int n;
    std::cin >> n;
    FPS f(n + 1);
    ebi::combination<mint> comb(n);
    for (int i = 0; i < n + 1; i++) {
        f[i] = (i + 1) * comb.inv_f(i);
    }
    mint ans = f.pow(n)[n - 2] * comb.f(n - 2) / mint(n).pow(n - 2);
    std::cout << ans.val() << '\n';
}