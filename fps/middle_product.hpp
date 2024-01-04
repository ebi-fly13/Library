#pragma once

#include <algorithm>
#include <bit>
#include <cassert>
#include <ranges>
#include <vector>

#include "../modint/base.hpp"

namespace ebi {

template <Modint mint,
          std::vector<mint> (*convolution)(const std::vector<mint> &,
                                           const std::vector<mint> &)>
std::vector<mint> middle_product(const std::vector<mint> &a,
                                 const std::vector<mint> &b) {
    assert(a.size() >= b.size());
    if (std::min(a.size() - b.size() + 1, b.size()) <= 60) {
        return middle_product_naive<mint>(a, b);
    }
    auto rb = b;
    std::reverse(rb.begin(), rb.end());
    std::vector<mint> c = convolution(a, rb);
    c.resize(a.size());
    c.erase(c.begin(), c.begin() + b.size() - 1);
    return c;
}

template <Modint mint>
std::vector<mint> middle_product_naive(const std::vector<mint> &a,
                                       const std::vector<mint> &b) {
    int n = (int)a.size();
    int m = (int)b.size();
    assert(n >= m);
    std::vector<mint> c(n - m + 1, 0);
    for (int i : std::views::iota(0, n - m + 1)) {
        for (int j : std::views::iota(0, m)) {
            c[i] += b[j] * a[i + j];
        }
    }
    return c;
}

}  // namespace ebi