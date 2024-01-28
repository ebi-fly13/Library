#pragma once

#include "../math/binomial.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint> mint catalan_convolution(int pow, int n) {
    return Binomial<mint>::c(n + n + pow - 1, n) * pow *
           Binomial<mint>::inv(n + pow);
}

}  // namespace ebi