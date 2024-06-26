#pragma once

#include "../fps/fps.hpp"
#include "../math/binomial.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint>
FormalPowerSeries<mint> taylor_shift(FormalPowerSeries<mint> f, mint a) {
    int d = f.deg();
    Binomial<mint>::reserve(d);
    for (int i = 0; i < d; i++) f[i] *= Binomial<mint>::f(i);
    std::reverse(f.begin(), f.end());
    FormalPowerSeries<mint> g(d, 1);
    mint pow_a = a;
    for (int i = 1; i < d; i++) {
        g[i] = pow_a * Binomial<mint>::inv_f(i);
        pow_a *= a;
    }
    f = (f * g).pre(d);
    std::reverse(f.begin(), f.end());
    for (int i = 0; i < d; i++) f[i] *= Binomial<mint>::inv_f(i);
    return f;
}

}  // namespace ebi