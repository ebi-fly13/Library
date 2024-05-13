#pragma once

#include <cassert>
#include <vector>

#include "../math/binomial.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint,
          std::vector<mint> (*convolution)(const std::vector<mint> &,
                                           const std::vector<mint> &)>
std::vector<mint> shift_of_sampling_points_of_poly(std::vector<mint> f, int c,
                                                   int m) {
    int n = (int)f.size();
    Binomial<mint> binom(std::max(n, m));
    {
        std::vector<mint> g(n);
        for (int i = 0; i < n; i++) {
            f[i] *= binom.inv_f(i);
            g[i] = i % 2 == 0 ? binom.inv_f(i) : -binom.inv_f(i);
        }
        f = convolution(f, g);
        f.resize(n);
    }
    {
        mint cc = 1;
        std::vector<mint> g(n);
        for (int i = 0; i < n; i++) {
            f[i] *= binom.f(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            g[i] = cc * binom.inv_f(n - 1 - i);
            cc *= c - (n - 1 - i);
        }
        auto fg = convolution(f, g);
        for (int i = 0; i < n; i++) {
            f[i] = fg[n - 1 + i] * binom.inv_f(i);
        }
    }
    {
        std::vector<mint> g(m);
        for (int i = 0; i < m; i++) {
            g[i] = binom.inv_f(i);
        }
        f = convolution(f, g);
        f.resize(m);
        for (int i = 0; i < m; i++) {
            f[i] *= binom.f(i);
        }
    }
    return f;
}

}  // namespace ebi