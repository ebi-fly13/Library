#pragma once

#include "../set_function/subset_zeta.hpp"

namespace ebi {

template <class T>
std::vector<T> or_convolution(const std::vector<T> &a,
                              const std::vector<T> &b) {
    int n = a.size();
    auto ra = subset_zeta(a);
    auto rb = subset_zeta(b);
    for (int i = 0; i < n; i++) {
        ra[i] *= rb[i];
    }
    return subset_mobius(ra);
}

}  // namespace ebi