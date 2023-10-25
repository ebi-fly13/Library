#pragma once

#include <cstdint>
#include <vector>

#include "../convolution/ntt.hpp"
#include "../utility/modint.hpp"
#include "../utility/modint_concept.hpp"

namespace ebi {

namespace internal {

template <class T, modint mint>
std::vector<mint> multiply(const std::vector<T>& f, const std::vector<T>& g) {
    std::vector<mint> a, b;
    a.reserve(f.size());
    b.reserve(g.size());
    for (auto x : f) a.emplace_back(x.val());
    for (auto x : g) b.emplace_back(x.val());
    return convolution<mint>(a, b);
}

}  // namespace internal

template <modint mint>
std::vector<mint> arbitary_convolution(const std::vector<mint>& f,
                                       const std::vector<mint>& g) {
    if (f.empty() || g.empty()) return {};
    using i32 = std::int32_t;
    using i64 = std::int64_t;
    static constexpr i32 m0 = 167772161;  // 2^25
    static constexpr i32 m1 = 469762049;  // 2^26
    static constexpr i32 m2 = 754974721;  // 2^24
    using mint0 = static_modint<m0>;
    using mint1 = static_modint<m1>;
    using mint2 = static_modint<m2>;
    static constexpr i32 inv01 = mint1(m0).inv().val();
    static constexpr i32 inv02 = mint2(m0).inv().val();
    static constexpr i32 inv12 = mint2(m1).inv().val();
    static constexpr i32 inv02inv12 = i64(inv02) * inv12 % m2;
    static constexpr i64 w1 = m0;
    static constexpr i64 w2 = i64(m0) * m1;

    const i32 mod = mint::mod();

    auto d0 = internal::multiply<mint, mint0>(f, g);
    auto d1 = internal::multiply<mint, mint1>(f, g);
    auto d2 = internal::multiply<mint, mint2>(f, g);

    int n = d0.size();
    std::vector<mint> res(n);
    const int W1 = w1 % mod;
    const int W2 = w2 % mod;

    for (int i = 0; i < n; i++) {
        i32 n1 = d1[i].val(), n2 = d2[i].val(), a = d0[i].val();
        i32 b = i64(n1 + m1 - a) * inv01 % m1;
        i32 c = (i64(n2 + m2 - a) * inv02inv12 + i64(m2 - b) * inv12) % m2;
        res[i] = (i64(a) + i64(b) * W1 + i64(c) * W2) % mod;
    }
    return res;
}

}  // namespace ebi