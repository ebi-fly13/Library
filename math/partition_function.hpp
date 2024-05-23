#pragma once

#include "../fps/fps.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint> std::vector<mint> partition_function(int n) {
    using FPS = FormalPowerSeries<mint>;
    FPS f(n + 1);
    f[0] = 1;
    for (int k = 1; k <= n; k++) {
        long long k1 = 1LL * k * (3 * k + 1) / 2;
        long long k2 = 1LL * k * (3 * k - 1) / 2;
        if (k2 > n) break;
        if (k1 <= n) f[k1] = ((k & 1) ? -1 : 1);
        if (k2 <= n) f[k2] = ((k & 1) ? -1 : 1);
    }
    return f.inv();
}

}  // namespace ebi