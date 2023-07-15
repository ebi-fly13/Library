#pragma once

#include <cassert>
#include <vector>

#include "../set_function/egf_composite_sps.hpp"
#include "../utility/bit_operator.hpp"

namespace ebi {

template <class T, int LIM>
std::vector<T> poly_composite_sps(std::vector<T> a, const std::vector<T> &f) {
    int n = msb(a.size());
    assert(n <= LIM);
    if (f.empty()) return std::vector<T>(1 << n, 0);
    int d = std::min((int)f.size() - 1, n);
    std::vector<T> g(d + 1);
    T c = a[0];
    a[0] = 0;
    std::vector<T> pow(d + 1);
    pow[0] = 1;
    for (int i = 0; i < (int)f.size(); i++) {
        for (int j = 0; j < d + 1; j++) g[j] += f[i] * pow[j];
        for (int j = d; j >= 0; j--)
            pow[j] = pow[j] * c + (j == 0 ? 0 : pow[j - 1]);
    }
    T fact = 1;
    for (int i = 0; i < d + 1; i++) {
        g[i] *= fact;
        fact *= (i + 1);
    }
    return egf_composite_sps<T, LIM>(a, g);
}

}  // namespace ebi