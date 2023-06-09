#pragma once

#include "../math/multiple_transform.hpp"

namespace ebi {

template <class mint>
std::vector<mint> gcd_convolution(const std::vector<mint> &a,
                                  const std::vector<mint> &b) {
    int n = a.size();
    assert(a.size() == b.size());
    auto ra = multiple_transform::zeta_transform(a);
    auto rb = multiple_transform::zeta_transform(b);
    for (int i = 0; i < n; i++) {
        ra[i] *= rb[i];
    }
    return multiple_transform::mobius_transform(ra);
}

}  // namespace ebi