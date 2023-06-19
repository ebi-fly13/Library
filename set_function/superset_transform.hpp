#pragma once

#include <cassert>
#include <vector>

#include "../utility/bit_operator.hpp"

namespace ebi {

template <class T> std::vector<T> superset_zeta(const std::vector<T> &a) {
    int n = msb(a.size());
    assert((1 << n) == (int)a.size());
    std::vector<T> ra = a;
    for (int i = 0; i < n; i++) {
        int w = 1 << i;
        for (int p = 0; p < (1 << n); p += 2 * w) {
            for (int s = p; s < p + w; s++) {
                int t = s | w;
                ra[s] += ra[t];
            }
        }
    }
    return ra;
}

template <class T> std::vector<T> superset_mobius(const std::vector<T> &ra) {
    int n = msb(ra.size());
    assert((1 << n) == (int)ra.size());
    std::vector<T> a = ra;
    for (int i = 0; i < n; i++) {
        int w = 1 << i;
        for (int p = 0; p < (1 << n); p += 2 * w) {
            for (int s = p; s < p + w; s++) {
                int t = s | w;
                a[s] -= a[t];
            }
        }
    }
    return a;
}

}  // namespace ebi