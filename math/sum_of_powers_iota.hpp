#pragma once

#include <cassert>

#include "../math/lagrange_interpolation.hpp"
#include "../math/linear_sieve.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint> mint sum_of_powers_iota(long long n, int k) {
    assert(n > 0 && k >= 0);
    linear_sieve sieve(k + 1);
    auto pow_table = sieve.pow_table<mint>(k + 1, k);
    for (int i = 0; i < k + 1; i++) {
        pow_table[i + 1] += pow_table[i];
    }
    return lagrange_interpolation(pow_table, n - 1);
}

}  // namespace ebi