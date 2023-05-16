#pragma once

#include <cassert>
#include <vector>

#include "../set_function/hadamard_transform.hpp"

namespace ebi {

template <class T>
std::vector<T> xor_convolution(const std::vector<T> &a,
                               const std::vector<T> &b) {
    assert(a.size() == b.size());
    auto ta = hadamard_transform(a);
    auto tb = hadamard_transform(b);
    for (int i = 0; i < (int)a.size(); i++) {
        ta[i] *= tb[i];
    }
    return hadamard_transform(ta, true);
}

}  // namespace ebi