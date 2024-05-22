#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

#include "../convolution/ntt.hpp"
#include "../modint/modint.hpp"
#include "../fps/middle_product.hpp"
#include "../modint/base.hpp"
#include "../template/int_alias.hpp"

namespace ebi {

template <Modint mint>
std::vector<mint> middle_product_arbitrary(const std::vector<mint> &a,
                                 const std::vector<mint> &b) {
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

    assert(a.size() >= b.size());
    if (std::min(a.size() - b.size() + 1, b.size()) <= 60) {
        return middle_product_naive<mint>(a, b);
    }
    int n = (int)a.size(), m = (int)b.size();
    std::vector<mint0> a0(n), b0(m);
    std::vector<mint1> a1(n), b1(m);
    std::vector<mint2> a2(n), b2(m);

    for (int i = 0; i < n; i++) {
        a0[i] = a[i].val();
        a1[i] = a[i].val();
        a2[i] = a[i].val();
    }
    for(int i = 0; i < m; i++) {
        b0[i] = b[i].val();
        b1[i] = b[i].val();
        b2[i] = b[i].val();
    }

    auto c0 = middle_product<mint0>(a0, b0);
    auto c1 = middle_product<mint1>(a1, b1);
    auto c2 = middle_product<mint2>(a2, b2);

    std::vector<mint> res(n - m + 1);
    const i32 W1 = w1 % mod;
    const i32 W2 = w2 % mod;
    for(int i = 0; i < n - m + 1; i++) {
        i32 n1 = c1[i].val(), n2 = c2[i].val(), a = c0[i].val();
        i32 b = i64(n1 + m1 - a) * inv01 % m1;
        i32 c = (i64(n2 + m2 - a) * inv02inv12 + i64(m2 - b) * inv12) % m2;
        res[i] = (i64(a) + i64(b) * W1 + i64(c) * W2) % mod;
    }
    return res;
}


std::vector<u64> middle_product_mod_2_64(const std::vector<u64> &a,
                                 const std::vector<u64> &b) {
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

    static const mint1 inv10 = mint1(m0).inv();
    static const mint2 inv21 = mint2(m1).inv(), inv20 = inv21 / mint2(m0);
    static const mint3 inv32 = mint3(m2).inv(), inv31 = inv32 / mint3(m1),
                       inv30 = inv31 / mint3(m0);
    static const mint4 inv43 = mint4(m3).inv(), inv42 = inv43 / mint4(m2),
                       inv41 = inv42 / mint4(m1), inv40 = inv41 / mint4(m0);

    assert(a.size() >= b.size());
    if (std::min(a.size() - b.size() + 1, b.size()) <= 60) {
        return middle_product_naive(a, b);
    }
    int n = (int)a.size(), m = (int)b.size();
    std::vector<mint0> a0(n), b0(m);
    std::vector<mint1> a1(n), b1(m);
    std::vector<mint2> a2(n), b2(m);
    std::vector<mint3> a3(n), b3(m);
    std::vector<mint4> a4(n), b4(m);

    for (int i = 0; i < n; i++) {
        a0[i] = a[i];
        a1[i] = a[i];
        a2[i] = a[i];
        a3[i] = a[i];
        a4[i] = a[i];
    }
    for(int i = 0; i < m; i++) {
        b0[i] = b[i];
        b1[i] = b[i];
        b2[i] = b[i];
        b3[i] = b[i];
        b4[i] = b[i];
    }

    auto c0 = middle_product<mint0>(a0, b0);
    auto c1 = middle_product<mint1>(a1, b1);
    auto c2 = middle_product<mint2>(a2, b2);
    auto c3 = middle_product<mint3>(a3, b3);
    auto c4 = middle_product<mint4>(a4, b4);

    std::vector<u64> res(n - m + 1);
    for(int i = 0; i < n - m + 1; i++) {
        i64 x0 = c0[i].val();
        i64 x1 = ((c1[i] - x0) * inv10).val();
        i64 x2 = (((c2[i] - x0)) * inv20 - mint2(x1) * inv21).val();
        i64 x3 = ((c3[i] - x0) * inv30 - mint3(x1) * inv31 - mint3(x2) * inv32)
                     .val();
        i64 x4 = ((c4[i] - x0) * inv40 - mint4(x1) * inv41 - mint4(x2) * inv42 -
                  mint4(x3) * inv43)
                     .val();
        res[i] = x0 + m0 * (x1 + m1 * (x2 + m2 * (x3 + m3 * (u64(x4)))));
    }
    return res;
}

}  // namespace ebi