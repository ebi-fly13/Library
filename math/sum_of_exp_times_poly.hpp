#pragma once

#include <cassert>
#include <vector>

#include "../math/binomial.hpp"
#include "../math/lagrange_interpolation.hpp"
#include "../math/linear_sieve.hpp"
#include "../modint/base.hpp"
#include "../template/int_alias.hpp"

namespace ebi {

template <Modint mint>
mint sum_of_exp_times_poly(const std::vector<mint> &f, mint a, i64 n) {
    if (n == 0) return 0;
    if (a == 0) return f[0];
    if (a == 1) {
        std::vector<mint> g(f.size() + 1, 0);
        for (int i = 1; i < (int)g.size(); i++) {
            g[i] = g[i - 1] + f[i - 1];
        }
        return lagrange_interpolation(g, n);
    }
    int k = (int)f.size() - 1;
    Binomial<mint> binom(k + 1);
    std::vector<mint> g(k + 1, 0);
    {
        mint pow_a = 1;
        for (int i = 0; i < k + 1; i++) {
            g[i] = f[i] * pow_a;
            pow_a *= a;
        }
        for (int i = 0; i < k; i++) {
            g[i + 1] += g[i];
        }
    }
    mint c = 0;
    {
        mint pow_neg_a = 1;
        for (int i = 0; i < k + 1; i++) {
            c += binom.c(k + 1, i) * g[k - i] * pow_neg_a;
            pow_neg_a *= -a;
        }
    }
    c /= (1 - a).pow(k + 1);

    {
        mint inv_a_pow = 1, inv_a = a.inv();
        for (int i = 0; i < k + 1; i++) {
            g[i] = (-c + g[i]) * inv_a_pow;
            inv_a_pow *= inv_a;
        }
    }
    mint tn = lagrange_interpolation(g, n - 1);
    return tn * a.pow(n - 1) + c;
}

template <Modint mint>
mint sum_of_exp_times_poly_limit(const std::vector<mint> &f, mint a) {
    assert(a != 1);
    if (a == 0) return f[0];
    int k = (int)f.size() - 1;
    Binomial<mint> binom(k + 1);
    std::vector<mint> g(k + 1, 0);
    {
        mint pow_a = 1;
        for (int i = 0; i < k + 1; i++) {
            g[i] = f[i] * pow_a;
            pow_a *= a;
        }
        for (int i = 0; i < k; i++) {
            g[i + 1] += g[i];
        }
    }
    mint c = 0;
    {
        mint pow_neg_a = 1;
        for (int i = 0; i < k + 1; i++) {
            c += binom.c(k + 1, i) * g[k - i] * pow_neg_a;
            pow_neg_a *= -a;
        }
    }
    c /= (1 - a).pow(k + 1);
    return c;
}

template <Modint mint> mint sum_of_exp2(mint r, int d, i64 n) {
    linear_sieve sieve(d);
    auto f = sieve.pow_table<mint>(d, d);
    return sum_of_exp_times_poly(f, r, n);
}

template <Modint mint> mint sum_of_exp2_limit(mint r, int d) {
    linear_sieve sieve(d);
    auto f = sieve.pow_table<mint>(d, d);
    return sum_of_exp_times_poly_limit(f, r);
}

}  // namespace ebi