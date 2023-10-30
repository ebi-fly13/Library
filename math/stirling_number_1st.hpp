#pragma once

#include <bit>
#include <cassert>

#include "../fps/fps.hpp"
#include "../fps/taylor_shift.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint,
          std::vector<mint> (*convolution)(const std::vector<mint> &,
                                           const std::vector<mint> &)>
FormalPowerSeries<mint, convolution> stirling_number_1st(int n) {
    using FPS = FormalPowerSeries<mint, convolution>;
    assert(n >= 0);
    if (n == 0) return {1};
    int lg = std::bit_width((unsigned int)(n)) - 1;
    FPS f = {0, 1};
    for (int i = lg - 1; i >= 0; i--) {
        int mid = n >> i;
        f *= taylor_shift<mint, convolution>(f, mid >> 1);
        if (mid & 1) f = (f << 1) + f * (mid - 1);
    }
    return f;
}

}  // namespace ebi