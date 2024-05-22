#pragma once

#include <algorithm>
#include <bit>
#include <cassert>
#include <ranges>
#include <vector>

#include "../convolution/ntt.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint>
std::vector<mint> middle_product(const std::vector<mint> &a,
                                 const std::vector<mint> &b) {
    assert(a.size() >= b.size());
    if (std::min(a.size() - b.size() + 1, b.size()) <= 60) {
        return middle_product_naive<mint>(a, b);
    }
    int n = std::bit_ceil(a.size());
    std::vector<mint> fa(n), fb(n);
    std::copy(a.begin(), a.end(), fa.begin());
    std::copy(b.rbegin(), b.rend(), fb.begin());
    internal::fft4(fa);
    internal::fft4(fb);
    for (int i = 0; i < n; i++) {
        fa[i] *= fb[i];
    }
    internal::ifft4(fa);
    mint inv_n = mint(n).inv();
    for (auto &x : fa) {
        x *= inv_n;
    }
    fa.resize(a.size());
    fa.erase(fa.begin(), fa.begin() + b.size() - 1);
    return fa;
}

template <class T>
std::vector<T> middle_product_naive(const std::vector<T> &a,
                                       const std::vector<T> &b) {
    int n = (int)a.size();
    int m = (int)b.size();
    assert(n >= m);
    std::vector<T> c(n - m + 1, 0);
    for (int i : std::views::iota(0, n - m + 1)) {
        for (int j : std::views::iota(0, m)) {
            c[i] += b[j] * a[i + j];
        }
    }
    return c;
}

}  // namespace ebi