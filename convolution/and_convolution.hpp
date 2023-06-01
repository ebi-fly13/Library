#pragma once

#include <vector>

#include "../set_function/superset_zeta.hpp"

namespace ebi {

template <class T>
std::vector<T> and_convolution(const std::vector<T> &a,
                               const std::vector<T> &b) {
    int n = a.size();
    auto ra = superset_zeta(a);
    auto rb = superset_zeta(b);
    for (int i = 0; i < n; i++) {
        ra[i] *= rb[i];
    }
    return superset_mobius(ra);
}

}  // namespace ebi