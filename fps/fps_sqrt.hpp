#pragma once

#include "../fps/fps.hpp"
#include "../math/mod_sqrt.hpp"

namespace ebi {

template <class mint, std::vector<mint> (*convolution)(
                          const std::vector<mint> &, const std::vector<mint> &)>
std::optional<FormalPowerSeries<mint, convolution>>
FormalPowerSeries<mint, convolution>::sqrt(int d) const {
    using FPS = FormalPowerSeries<mint, convolution>;
    if (d < 0) d = deg();
    if ((*this)[0] == 0) {
        for (int i = 1; i < this->deg(); i++) {
            if ((*this)[i] != 0) {
                if (i & 1) return std::nullopt;
                if (d - i / 2 <= 0) break;
                auto opt = ((*this) >> i).sqrt(d - i / 2);
                if (!opt) return std::nullopt;
                auto ret = opt.value() << (i / 2);
                if ((int)ret.deg() < d) ret.resize(d);
                return ret;
            }
        }
        return FPS(d, 0);
    }
    auto s = mod_sqrt((*this)[0].val(), mint::mod());
    if (!s) {
        return std::nullopt;
    }
    int n = 1;
    FPS g(n);
    g[0] = s.value();
    mint inv_two = mint(2).inv();
    while (n < d) {
        n <<= 1;
        g = (g + this->pre(n) * g.inv(n)).pre(n) * inv_two;
    }
    g.resize(d);
    return g;
}

}  // namespace ebi