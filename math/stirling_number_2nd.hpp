#pragma once

#include <cassert>
#include <vector>

#include "../fps/fps.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint,
          std::vector<mint> (*convolution)(const std::vector<mint> &,
                                           const std::vector<mint> &)>
FormalPowerSeries<mint, convolution> stirling_number_2nd(int n) {
    using FPS = FormalPowerSeries<mint, convolution>;
    assert(n >= 0);
    FPS f(n + 1), g(n + 1);
    std::vector<mint> fact(n + 1, 1);
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
    std::vector<mint> inv_fact(n + 1);
    inv_fact[n] = fact[n].inv();
    for (int i = n; i > 0; i--) {
        inv_fact[i - 1] = inv_fact[i] * i;
    }
    for (int i = 0; i <= n; i++) {
        f[i] = mint(i).pow(n) * inv_fact[i];
        g[i] = (i & 1) ? -inv_fact[i] : inv_fact[i];
    }
    return (f * g).pre(n + 1);
}

}  // namespace ebi