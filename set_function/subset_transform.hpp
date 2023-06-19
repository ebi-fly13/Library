#pragma once

#include <cassert>
#include <vector>

#include "../utility/bit_operator.hpp"

namespace ebi {

template <class T> std::vector<T> subset_zeta(const std::vector<T> &a) {
    int n = msb(a.size());
    assert((1 << n) == (int)a.size());
    std::vector<T> ra = a;
    for (int i = 0; i < n; i++) {
        int w = 1 << i;
        for (int p = 0; p < (1 << n); p += 2 * w) {
            for (int s = p; s < p + w; s++) {
                int t = s | w;
                ra[t] += ra[s];
            }
        }
    }
    return ra;
}

template <class T> std::vector<T> subset_mobius(const std::vector<T> &ra) {
    int n = msb(ra.size());
    assert((1 << n) == (int)ra.size());
    std::vector<T> a = ra;
    for (int i = 0; i < n; i++) {
        int w = 1 << i;
        for (int p = 0; p < (1 << n); p += 2 * w) {
            for (int s = p; s < p + w; s++) {
                int t = s | w;
                a[t] -= a[s];
            }
        }
    }
    return a;
}

}  // namespace ebi