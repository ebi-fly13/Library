#pragma once

#include "../fps/fps.hpp"
#include "../fps/power_projection_of_fps.hpp"
#include "../math/mod_inv.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint>
FormalPowerSeries<mint> compositional_inverse_of_fps(
    FormalPowerSeries<mint> f) {
    using FPS = FormalPowerSeries<mint>;
    assert((int)f.size() >= 2 && f[0] == 0 && f[1] != 0);
    int n = (int)f.size() - 1;
    mint inv_c = f[1].inv();
    f *= inv_c;
    std::vector<mint> w(n + 1);
    w[n] = 1;
    auto s = power_projection(f, w, n);
    FPS g(n);
    for (int i = 1; i < n + 1; i++) {
        g[n - i] = n * s[i] * inv<mint>(i);
    }
    g = g.pow_1(mint(-n).inv()) << 1;
    mint p = 1;
    for (int i = 0; i < n + 1; i++) {
        g[i] *= p;
        p *= inv_c;
    }
    return g;
}

}  // namespace ebi