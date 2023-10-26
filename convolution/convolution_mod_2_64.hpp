#pragma once

#include <cstdint>
#include <vector>

#include "../convolution/ntt.hpp"
#include "../modint/base.hpp"
#include "../modint/modint.hpp"

namespace ebi {

namespace internal {

template <Modint mint>
std::vector<mint> multiply_uint64_t(const std::vector<std::uint64_t>& f,
                                    const std::vector<std::uint64_t>& g) {
    std::vector<mint> a, b;
    a.reserve(f.size());
    b.reserve(g.size());
    for (auto x : f) a.emplace_back(x % mint::mod());
    for (auto x : g) b.emplace_back(x % mint::mod());
    return convolution<mint>(a, b);
}

}  // namespace internal

std::vector<std::uint64_t> convolution_mod_2_64(
    const std::vector<std::uint64_t>& f, const std::vector<std::uint64_t>& g) {
    if (f.empty() || g.empty()) return {};
    using i32 = std::int32_t;
    using i64 = std::int64_t;
    using u64 = std::uint64_t;
    static constexpr i32 m0 = 998244353;
    static constexpr i32 m1 = 754974721;
    static constexpr i32 m2 = 167772161;
    static constexpr i32 m3 = 469762049;
    static constexpr i32 m4 = 880803841;
    using mint0 = static_modint<m0>;
    using mint1 = static_modint<m1>;
    using mint2 = static_modint<m2>;
    using mint3 = static_modint<m3>;
    using mint4 = static_modint<m4>;

    auto d0 = internal::multiply_uint64_t<mint0>(f, g);
    auto d1 = internal::multiply_uint64_t<mint1>(f, g);
    auto d2 = internal::multiply_uint64_t<mint2>(f, g);
    auto d3 = internal::multiply_uint64_t<mint3>(f, g);
    auto d4 = internal::multiply_uint64_t<mint4>(f, g);

    static const mint1 inv10 = mint1(m0).inv();
    static const mint2 inv21 = mint2(m1).inv(), inv20 = inv21 / mint2(m0);
    static const mint3 inv32 = mint3(m2).inv(), inv31 = inv32 / mint3(m1),
                       inv30 = inv31 / mint3(m0);
    static const mint4 inv43 = mint4(m3).inv(), inv42 = inv43 / mint4(m2),
                       inv41 = inv42 / mint4(m1), inv40 = inv41 / mint4(m0);
    int n = d0.size();
    std::vector<u64> res(n);
    for (int i = 0; i < n; i++) {
        i64 x0 = d0[i].val();
        i64 x1 = ((d1[i] - x0) * inv10).val();
        i64 x2 = (((d2[i] - x0)) * inv20 - mint2(x1) * inv21).val();
        i64 x3 = ((d3[i] - x0) * inv30 - mint3(x1) * inv31 - mint3(x2) * inv32)
                     .val();
        i64 x4 = ((d4[i] - x0) * inv40 - mint4(x1) * inv41 - mint4(x2) * inv42 -
                  mint4(x3) * inv43)
                     .val();
        res[i] = x0 + m0 * (x1 + m1 * (x2 + m2 * (x3 + m3 * (u64(x4)))));
    }
    return res;
}

}  // namespace ebi