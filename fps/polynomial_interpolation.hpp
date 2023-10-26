#pragma once

#include "../fps/fps.hpp"
#include "../fps/multipoint_evaluation.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint,
          std::vector<mint> (*convolution)(const std::vector<mint> &,
                                           const std::vector<mint> &)>
FormalPowerSeries<mint, convolution> polynomial_interpolation(
    const std::vector<mint> &xs, const std::vector<mint> &ys) {
    using FPS = FormalPowerSeries<mint, convolution>;
    assert(xs.size() == ys.size());
    int m = 1;
    int n = xs.size();
    while (m < n) m <<= 1;
    std::vector<FPS> subproduct_tree(2 * m, {1});
    for (int i = 0; i < (int)xs.size(); i++) {
        subproduct_tree[i + m] = FPS{-xs[i], 1};
    }
    for (int i = m - 1; i >= 1; i--) {
        subproduct_tree[i] =
            subproduct_tree[2 * i] * subproduct_tree[2 * i + 1];
    }
    std::vector<mint> fp =
        multipoint_evaluation(subproduct_tree[1].differential(), xs);
    std::vector<FPS> f(2 * m);
    for (int i = 0; i < n; i++) {
        f[i + m] = FPS{ys[i] / fp[i]};
    }
    for (int i = m - 1; i >= 1; i--) {
        f[i] = f[2 * i] * subproduct_tree[2 * i + 1] +
               subproduct_tree[2 * i] * f[2 * i + 1];
    }
    f[1].resize(n);
    return f[1];
}

}  // namespace ebi