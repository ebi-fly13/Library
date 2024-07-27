#pragma once

#include <bit>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <vector>

#include "../modint/base.hpp"

namespace ebi {

template <Modint mint> struct Binomial {
  private:
    static void extend(int len = -1) {
        int sz = (int)fact.size();
        if (len < 0)
            len = 2 * sz;
        else if (len <= sz)
            return;
        else
            len = std::max(2 * sz, (int)std::bit_ceil(std::uint32_t(len)));
        len = std::min(len, mint::mod());
        assert(sz <= len);
        fact.resize(len);
        inv_fact.resize(len);
        for (int i : std::views::iota(sz, len)) {
            fact[i] = fact[i - 1] * i;
        }
        inv_fact[len - 1] = fact[len - 1].inv();
        for (int i : std::views::iota(sz, len) | std::views::reverse) {
            inv_fact[i - 1] = inv_fact[i] * i;
        }
    }

  public:
    Binomial() = default;

    Binomial(int n) {
        extend(n + 1);
    }

    static mint f(int n) {
        if (n >= (int)fact.size()) [[unlikely]] {
            extend(n + 1);
        }
        return fact[n];
    }

    static mint inv_f(int n) {
        if (n >= (int)fact.size()) [[unlikely]] {
            extend(n + 1);
        }
        return inv_fact[n];
    }

    static mint c(int n, int r) {
        if (r < 0 || n < r) return 0;
        return f(n) * inv_f(r) * inv_f(n - r);
    }

    static mint neg_c(int k, int d) {
        assert(d > 0);
        return c(k + d - 1, d - 1);
    }

    static mint p(int n, int r) {
        if (r < 0 || n < r) return 0;
        return f(n) * inv_f(n - r);
    }

    static mint catalan_number(int n) {
        return c(2 * n, n) * inv(n + 1);
    }

    static mint inv(int n) {
        return inv_f(n) * f(n - 1);
    }

    static void reserve(int n) {
        extend(n + 1);
    }

  private:
    static std::vector<mint> fact, inv_fact;
};

template <Modint mint>
std::vector<mint> Binomial<mint>::fact = std::vector<mint>(2, 1);

template <Modint mint>
std::vector<mint> Binomial<mint>::inv_fact = std::vector<mint>(2, 1);

}  // namespace ebi
