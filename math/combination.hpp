#pragma once

#include <cassert>
#include <vector>

#include "../utility/modint_base.hpp"

namespace ebi {

template <class mint, internal::is_modint_t<mint>* = nullptr>
struct combination {
    combination(int n) : m(n), fact(n + 1), inv_fact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }
        inv_fact[n] = fact[n].inv();
        for (int i = n; i > 0; i--) {
            inv_fact[i - 1] = inv_fact[i] * i;
        }
    }

    mint operator()(int n, int k) const {
        assert(n <= m);
        if (k < 0 || n < k) return 0;
        return fact[n] * inv_fact[k] * inv_fact[n - k];
    }

    mint f(int n) const {
        assert(n <= m);
        if (n < 0) return 0;
        return fact[n];
    }

    mint inv_f(int n) const {
        assert(n <= m);
        if (n < 0) return 0;
        return inv_fact[n];
    }

    mint inv(int n) const {
        assert(n <= m);
        return inv_fact[n] * fact[n-1];
    }

  private:
    int m;
    std::vector<mint> fact, inv_fact;
};

}  // namespace ebi