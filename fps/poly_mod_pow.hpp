#pragma once

#include "../fps/fps.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint>
FormalPowerSeries<mint> poly_mod_pow(FormalPowerSeries<mint> f, long long k,
                                     const FormalPowerSeries<mint> &g) {
    FormalPowerSeries<mint> res = {1};
    while (k > 0) {
        if (k & 1) {
            res *= f;
            res %= g;
            res.shrink();
        }
        f *= f;
        f %= g;
        f.shrink();
        k >>= 1;
    }
    return res;
}

}  // namespace ebi