#pragma once

#include <cassert>
#include <ranges>
#include <vector>

namespace ebi {

template <class mint> struct Binomial {
  private:
    static void extend(int len) {
        int sz = (int)fact.size();
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
    Binomial(int n) {
        extend(n + 1);
    }

    static mint c(int n, int r) {
        assert(n < (int)fact.size());
        if (r < 0 || n < r) return 0;
        return fact[n] * inv_fact[r] * inv_fact[n - r];
    }

    static mint p(int n, int r) {
        assert(n < (int)fact.size());
        if (r < 0 || n < r) return 0;
        return fact[n] * inv_fact[n - r];
    }

    static mint f(int n) {
        assert(n < (int)fact.size());
        return fact[n];
    }

    static mint inv_f(int n) {
        assert(n < (int)fact.size());
        return inv_fact[n];
    }

    static mint inv(int n) {
        assert(n < (int)fact.size());
        return inv_fact[n] * fact[n - 1];
    }

    static void reserve(int n) {
        extend(n + 1);
    }

  private:
    static std::vector<mint> fact, inv_fact;
};

template <class mint>
std::vector<mint> Binomial<mint>::fact = std::vector<mint>(2, 1);

template <class mint>
std::vector<mint> Binomial<mint>::inv_fact = std::vector<mint>(2, 1);

}  // namespace ebi
