#pragma once

#include <cassert>
#include <limits>
#include <vector>

#include "../algorithm/monotone_minima.hpp"

namespace ebi {

template <class T>
std::vector<T> min_plus_convolution_convex_and_arbitary(
    const std::vector<T> &a, const std::vector<T> &b) {
    int n = (int)a.size();
    int m = (int)b.size();
    for (int i = 0; i < n - 2; i++) {
        assert(a[i + 1] - a[i] <= a[i + 2] - a[i + 1]);
    }
    auto f = [&](int i, int j) -> T {
        if (i - j < 0 || i - j >= n) return std::numeric_limits<T>::max();
        return a[i - j] + b[j];
    };
    auto [argmin, min_val] = monotone_minima<T>(n + m - 1, m, f);
    return min_val;
}

}  // namespace ebi