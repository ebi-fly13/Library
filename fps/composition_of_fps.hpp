#pragma once

#include <cassert>
#include <vector>

#include "../fps/fps.hpp"

namespace ebi {

template <class mint, std::vector<mint> (*convolution)(
                          const std::vector<mint> &, const std::vector<mint> &)>
FormalPowerSeries<mint, convolution> composition_of_fps(
    const FormalPowerSeries<mint, convolution> &f,
    const FormalPowerSeries<mint, convolution> &g) {
    using FPS = FormalPowerSeries<mint, convolution>;
    // assert(f.deg() == g.deg());
    int n = f.deg();
    int k = 1;
    while (k * k < n) k++;
    std::vector<FPS> baby(k + 1);
    baby[0] = FPS{1};
    baby[1] = g;
    for (int i = 2; i < k + 1; i++) {
        baby[i] = (baby[i - 1] * g).pre(n);
    }
    std::vector<FPS> giant(k + 1);
    giant[0] = FPS{1};
    giant[1] = baby[k];
    for (int i = 2; i < k + 1; i++) {
        giant[i] = (giant[i - 1] * giant[1]).pre(n);
    }
    FPS h(n);
    for (int i = 0; i < k + 1; i++) {
        FPS a(n);
        for (int j = 0; j < k; j++) {
            if (k * i + j < n) {
                mint coef = f[k * i + j];
                a += baby[j] * coef;
            } else
                break;
        }
        h += (giant[i] * a).pre(n);
    }
    return h;
}

}  // namespace ebi