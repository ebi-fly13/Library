#pragma once

#include "../fps/fps.hpp"

namespace ebi {

template <class mint, std::vector<mint> (*convolution)(
                          const std::vector<mint> &, const std::vector<mint> &)>
std::vector<mint> partition_function(int n) {
    using FPS = FormalPowerSeries<mint, convolution>;
    FPS f(n+1);
    f[0] = 1;
    for(int k = 1; k <= n; k++) {
        long long k1 = 1LL * k * (3 * k + 1) / 2;
        long long k2 = 1LL * k *(3 * k - 1) / 2;
        if(k2 > n) break;
        if(k1 <= n) f[k1] = ((k & 1) ? -1 : 1);
        if(k2 <= n) f[k2] = ((k & 1) ? -1 : 1); 
    }
    return f.inv();
}

}