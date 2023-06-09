#pragma once

#include "../math/divisor_transform.hpp"

namespace ebi {

template <class mint>
std::vector<mint> lcm_convolution(const std::vector<mint> &a,
                                  const std::vector<mint> &b) {
    int n = a.size();
    assert(a.size() == b.size());
    auto ra = divisor_transform::zeta_transform(a);
    auto rb = divisor_transform::zeta_transform(b);
    for (int i = 0; i < n; i++) {
        ra[i] *= rb[i];
    }
    return divisor_transform::mobius_transform(ra);
}

}  // namespace ebi