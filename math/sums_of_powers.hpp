#pragma once

#include "../fps/fps.hpp"
#include "../fps/product_of_fps.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint,
          std::vector<mint> (*convolution)(const std::vector<mint> &,
                                           const std::vector<mint> &)>
std::vector<mint> sums_of_powers(const std::vector<int> &a,
                                                    int d) {
    using FPS = FormalPowerSeries<mint, convolution>;
    int n = a.size();
    std::vector fs(n, std::vector<mint>(2, 1));
    for (int i = 0; i < n; i++) {
        fs[i][1] = -a[i];
    }
    FPS g = product_of_fps<mint, convolution>(fs);
    return (-g.log(d + 1).differential() << 1) + n;
}

}  // namespace ebi