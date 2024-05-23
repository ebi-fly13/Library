#pragma once

#include "../fps/fps.hpp"
#include "../fps/fps_sparse.hpp"
#include "../math/mod_sqrt.hpp"
#include "../modint/base.hpp"

namespace ebi {

template <Modint mint>
std::optional<FormalPowerSeries<mint>> FormalPowerSeries<mint>::sqrt(
    int d) const {
    using FPS = FormalPowerSeries<mint>;
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
    if (this->count_terms() <= 200) {
        mint y = s.value();
        std::vector<mint> sqrt_f =
            pow_sparse_1(*this / (*this)[0], mint(2).inv().val(), d);
        FPS g(d);
        for (int i = 0; i < d; i++) g[i] = sqrt_f[i] * y;
        return g;
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