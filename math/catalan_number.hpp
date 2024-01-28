#pragma once

#include "../math/binomial.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint> mint catalan_number(int n) {
    return Binomial<mint>::c(2 * n, n) * Binomial<mint>::inv(n + 1);
}

}  // namespace ebi