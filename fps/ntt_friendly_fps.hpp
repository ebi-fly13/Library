#pragma once

#include <bit>

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

template <Modint mint> void FormalPowerSeries<mint>::fft() {
    this->resize(std::bit_ceil(this->size()));
    internal::fft4(*this);
}

template <Modint mint> void FormalPowerSeries<mint>::ifft() {
    this->resize(std::bit_ceil(this->size()));
    internal::ifft4(*this);
}

}  // namespace ebi