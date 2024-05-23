#pragma once

#include "../fps/fps.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint> FormalPowerSeries<mint> bernoulli_number_egf(int n) {
    using FPS = FormalPowerSeries<mint>;
    FPS f(n + 1);
    mint fact = 1;
    for (int i = 2; i <= n + 1; i++) fact *= i;
    mint inv_fact = fact.inv();
    for (int i = n; i >= 0; i--) {
        f[i] = inv_fact;
        inv_fact *= i + 1;
    }
    return f.inv();
}

}  // namespace ebi