#pragma once

#include <vector>

#include "../fps/fps.hpp"
#include "../math/mod_inv.hpp"
#include "../modint/base.hpp"

namespace ebi {

// prod (1 + x^a_i) mod x^d
template <Modint mint>
FormalPowerSeries<mint> product_of_one_plus_xn(std::vector<int> a, int d) {
    using FPS = FormalPowerSeries<mint>;
    std::vector<int> cnt(d, 0);
    for (auto x : a)
        if (x < d) cnt[x]++;
    FPS log_f(d);
    for (int x = 1; x < d; x++) {
        for (int i = 1; x * i < d; i++) {
            if (i & 1)
                log_f[x * i] += mint(cnt[x]) * inv<mint>(i);
            else
                log_f[x * i] -= mint(cnt[x]) * inv<mint>(i);
        }
    }
    mint ret = mint(2).pow(cnt[0]);
    auto f = log_f.exp(d);
    for (auto &x : f) x *= ret;
    return f;
}

}  // namespace ebi