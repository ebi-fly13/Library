#pragma once

#include <cassert>
#include <vector>

#include "../algorithm/subset_convolution.hpp"
#include "../utility/bit_operator.hpp"

namespace ebi {

template <class T, int LIM> std::vector<T> sps_exp(const std::vector<T> &s) {
    int n = topbit(s.size());
    assert(n <= LIM);
    assert((int)s.size() == (1 << n));
    std::vector<T> fs(1 << n);
    fs[0] = T(1);
    for (int i = 0; i < n; i++) {
        std::vector<T> a = {s.begin() + (1 << i), s.begin() + (2 << i)};
        std::vector<T> b = {fs.begin(), fs.begin() + (1 << i)};
        a = subset_convolution<T, LIM>(a, b);
        std::copy(a.begin(), a.end(), fs.begin() + (1 << i));
    }
    return fs;
}

}  // namespace ebi