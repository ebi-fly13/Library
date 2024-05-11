#pragma once

#include <cassert>

#include "../fps/fps.hpp"
#include "../fps/product_of_fps.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint,
          std::vector<mint> (*convolution)(const std::vector<mint> &,
                                           const std::vector<mint> &)>
std::vector<mint> sums_of_powers_iota(long long n, int k) {
    assert(n > 0 && k >= 0);
    using FPS = FormalPowerSeries<mint, convolution>;
    FPS p = FPS{0, n}.exp(k + 2) >> 1;
    FPS q = FPS::exp_x(k + 2) >> 1;
    FPS pq = (p * q.inv()).pre(k + 1);
    std::vector<mint> res(k + 1);
    mint fact = 1;
    for (int i = 0; i < k + 1; i++) {
        res[i] = pq[i] * fact;
        fact *= i + 1;
    }
    return res;
}

}  // namespace ebi