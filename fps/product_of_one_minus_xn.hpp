#pragma once

#include <vector>

#include "../fps/fps.hpp"
#include "../utility/modint_func.hpp"

namespace ebi {

// prod (1 - x^a_i) mod x^d
template <class mint, std::vector<mint> (*convolution)(
                          const std::vector<mint> &, const std::vector<mint> &)>
FormalPowerSeries<mint, convolution> product_of_one_minus_xn(std::vector<int> a,
                                                             int d) {
    using FPS = FormalPowerSeries<mint, convolution>;
    std::vector<int> cnt(d, 0);
    for (auto x : a)
        if (x < d) cnt[x]++;
    if (cnt[0]) return FPS(d);
    FPS log_f(d);
    for (int x = 1; x < d; x++) {
        for (int i = 1; x * i < d; i++) {
            log_f[x * i] -= mint(cnt[x]) * inv<mint>(i);
        }
    }
    return log_f.exp(d);
}

}  // namespace ebi