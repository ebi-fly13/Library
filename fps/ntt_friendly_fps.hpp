#pragma once

#include "../convolution/convolution.hpp"
#include "../fps/fps.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint>
FormalPowerSeries<mint> &FormalPowerSeries<mint>::operator*=(
    const FormalPowerSeries<mint> &rhs) {
    *this = convolution(*this, rhs);
    return *this;
}

}  // namespace ebi