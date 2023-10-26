#pragma once

#include "../fps/fps.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint,
          std::vector<mint> (*convolution)(const std::vector<mint> &,
                                           const std::vector<mint> &)>
std::vector<mint> multipoint_evaluation(
    const FormalPowerSeries<mint, convolution> &f, const std::vector<mint> &p) {
    using FPS = FormalPowerSeries<mint, convolution>;
    int m = 1;
    while (m < (int)p.size()) m <<= 1;
    std::vector<FPS> subproduct_tree(2 * m, {1});
    for (int i = 0; i < (int)p.size(); i++) {
        subproduct_tree[i + m] = FPS{-p[i], 1};
    }
    for (int i = m - 1; i >= 1; i--) {
        subproduct_tree[i] =
            subproduct_tree[2 * i] * subproduct_tree[2 * i + 1];
    }
    std::vector<FPS> subremainder_tree(2 * m);
    subremainder_tree[1] = f % subproduct_tree[1];
    for (int i = 2; i < m + (int)p.size(); i++) {
        if (subremainder_tree[i / 2].empty()) continue;
        subremainder_tree[i] = subremainder_tree[i / 2] % subproduct_tree[i];
    }
    std::vector<mint> fp(p.size());
    for (int i = 0; i < (int)p.size(); i++) {
        if (subremainder_tree[i + m].empty())
            fp[i] = 0;
        else
            fp[i] = subremainder_tree[i + m][0];
    }
    return fp;
}

}  // namespace ebi