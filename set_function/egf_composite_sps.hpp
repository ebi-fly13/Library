#pragma once

#include <cassert>
#include <vector>

#include "../convolution/subset_convolution.hpp"

namespace ebi {

template <class T, int LIM>
std::vector<T> egf_composite_sps(const std::vector<T> &a, std::vector<T> egf) {
    int n = std::bit_width(a.size()) - 1;
    assert(n <= LIM);
    assert((int)a.size() == (1 << n) && a[0] == T(0));
    if ((int)egf.size() > n) egf.resize(n + 1);
    int d = egf.size() - 1;
    std::vector<T> f(1 << n);
    f[0] = egf[d];
    for (int k = d - 1; k >= 0; k--) {
        std::vector<T> fk(1 << n);
        fk[0] = egf[k];
        for (int i = 0; i < n - k; i++) {
            std::vector<T> s = {a.begin() + (1 << i), a.begin() + (2 << i)};
            std::vector<T> t = {f.begin(), f.begin() + (1 << i)};
            auto c = subset_convolution<T, LIM>(s, t);
            std::copy(c.begin(), c.end(), fk.begin() + (1 << i));
        }
        f = fk;
    }
    return f;
}

}  // namespace ebi