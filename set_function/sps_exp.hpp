#pragma once

#include <cassert>
#include <vector>

#include "../convolution/subset_convolution.hpp"
#include "../utility/bit_operator.hpp"

namespace ebi {

template <class T, int LIM> std::vector<T> sps_exp(const std::vector<T> &a) {
    int n = msb(a.size());
    assert(n <= LIM);
    assert((int)a.size() == (1 << n));
    std::vector<T> fa(1 << n);
    fa[0] = T(1);
    for (int i = 0; i < n; i++) {
        std::vector<T> s = {a.begin() + (1 << i), a.begin() + (2 << i)};
        std::vector<T> t = {fa.begin(), fa.begin() + (1 << i)};
        auto c = subset_convolution<T, LIM>(s, t);
        std::copy(c.begin(), c.end(), fa.begin() + (1 << i));
    }
    return fa;
}

}  // namespace ebi