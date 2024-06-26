#pragma once

#include "../convolution/convolution.hpp"
#include "../fps/fps.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint>
FormalPowerSeries<mint> &FormalPowerSeries<mint>::operator*=(
    const FormalPowerSeries<mint> &rhs) {
    *this = convolution_naive(*this, rhs);
    return *this;
}

template <Modint mint> void FormalPowerSeries<mint>::fft() {
    assert(false);
}

template <Modint mint> void FormalPowerSeries<mint>::ifft() {
    assert(false);
}

}  // namespace ebi