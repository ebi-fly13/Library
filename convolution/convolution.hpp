#pragma once

#include <algorithm>
#include <bit>
#include <vector>

#include "../convolution/ntt.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint>
std::vector<mint> convolution_naive(const std::vector<mint>& f,
                                    const std::vector<mint>& g) {
    if (f.empty() || g.empty()) return {};
    int n = int(f.size()), m = int(g.size());
    std::vector<mint> c(n + m - 1);
    if (n < m) {
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                c[i + j] += f[i] * g[j];
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c[i + j] += f[i] * g[j];
            }
        }
    }
    return c;
}

template <Modint mint>
std::vector<mint> convolution(const std::vector<mint>& f,
                              const std::vector<mint>& g) {
    if (f.empty() || g.empty()) return {};
    if (std::min(f.size(), g.size()) < 60) return convolution_naive(f, g);
    int n = (int)std::bit_ceil(f.size() + g.size() - 1);
    std::vector<mint> a(n), b(n);
    std::copy(f.begin(), f.end(), a.begin());
    std::copy(g.begin(), g.end(), b.begin());
    internal::fft4(a);
    internal::fft4(b);
    for (int i = 0; i < n; i++) {
        a[i] *= b[i];
    }
    internal::ifft4(a);
    a.resize(f.size() + g.size() - 1);
    mint inv_n = mint(n).inv();
    for(auto &x: a) x *= inv_n;
    return a;
}

}  // namespace ebi