#pragma once

#include <cassert>

#include "../fps/composition_of_fps.hpp"
#include "../fps/fps.hpp"

namespace ebi {

template <class mint, std::vector<mint> (*convolution)(
                          const std::vector<mint> &, const std::vector<mint> &)>
FormalPowerSeries<mint, convolution> compositional_inverse_of_fps(
    FormalPowerSeries<mint, convolution> f, int d = -1) {
    using FPS = FormalPowerSeries<mint, convolution>;
    if (d < 0) d = f.deg();
    assert((int)f.size() >= 2 && f[0] == 0 && f[1] != 0);
    FPS df = f.differential();
    FPS g = {0, f[1].inv()};
    for (int n = 2; n < d; n <<= 1) {
        g.resize(2 * n);
        if (f.deg() < 2 * n) f.resize(2 * n);
        if (df.deg() < 2 * n) df.resize(2 * n);
        FPS fg = composition_of_fps(f.pre(2 * n), g);
        FPS fdg = composition_of_fps(df.pre(2 * n), g);
        g -= ((fg - FPS{0, 1}) * fdg.inv(2 * n)).pre(2 * n);
    }
    g.resize(d);
    return g;
}

}  // namespace ebi