---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: NTT
  - icon: ':heavy_check_mark:'
    path: fps/middle_product.hpp
    title: $[x^i]c = \sum_{j} [x^{i+j}]a [x^j]b$
  - icon: ':heavy_check_mark:'
    path: math/internal_math.hpp
    title: math/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':heavy_check_mark:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/wildcard_pattern_matching.hpp
    title: Wildcard Pattern Matching
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/Wildcard_Pattern_Matching.test.cpp
    title: test/string/Wildcard_Pattern_Matching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/middle_product_arbitrary.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\n#line 2 \"convolution/ntt.hpp\"\n\n#line\
    \ 4 \"convolution/ntt.hpp\"\n#include <array>\n#include <bit>\n#line 8 \"convolution/ntt.hpp\"\
    \n\n#line 2 \"math/internal_math.hpp\"\n\n#line 4 \"math/internal_math.hpp\"\n\
    \nnamespace ebi {\n\nnamespace internal {\n\nconstexpr int primitive_root_constexpr(int\
    \ m) {\n    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m\
    \ == 469762049) return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353)\
    \ return 3;\n    if (m == 880803841) return 26;\n    if (m == 924844033) return\
    \ 5;\n    return -1;\n}\ntemplate <int m> constexpr int primitive_root = primitive_root_constexpr(m);\n\
    \n}  // namespace internal\n\n}  // namespace ebi\n#line 2 \"template/int_alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace ebi {\n\nusing ld = long double;\nusing std::size_t;\n\
    using i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\n\
    using u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\n}  // namespace ebi\n#line 2 \"modint/base.hpp\"\n\
    \n#include <concepts>\n#include <iostream>\n#include <utility>\n\nnamespace ebi\
    \ {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n    a + b;\n\
    \    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 12 \"\
    convolution/ntt.hpp\"\n\nnamespace ebi {\n\nnamespace internal {\n\ntemplate <Modint\
    \ mint, int g = internal::primitive_root<mint::mod()>>\nstruct ntt_info {\n  \
    \  static constexpr int rank2 =\n        std::countr_zero((unsigned int)(mint::mod()\
    \ - 1));\n\n    std::array<mint, rank2 + 1> root, inv_root;\n\n    ntt_info()\
    \ {\n        root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);\n        inv_root[rank2]\
    \ = root[rank2].inv();\n        for (int i = rank2 - 1; i >= 0; i--) {\n     \
    \       root[i] = root[i + 1] * root[i + 1];\n            inv_root[i] = inv_root[i\
    \ + 1] * inv_root[i + 1];\n        }\n    }\n};\n\ntemplate <Modint mint> void\
    \ fft2(std::vector<mint>& a) {\n    static const ntt_info<mint> info;\n    int\
    \ n = int(a.size());\n    int bit_size = std::countr_zero(a.size());\n    assert(n\
    \ == 1 << bit_size);\n    for (int bit = bit_size - 1; bit >= 0; bit--) {\n  \
    \      int m = 1 << bit;\n        for (int i = 0; i < n; i += 2 * m) {\n     \
    \       mint w = 1;\n            for (int j = 0; j < m; j++) {\n             \
    \   mint p1 = a[i + j];\n                mint p2 = a[i + j + m];\n           \
    \     a[i + j] = p1 + p2;\n                a[i + j + m] = (p1 - p2) * w;\n   \
    \             w *= info.root[bit + 1];\n            }\n        }\n    }\n}\n\n\
    template <Modint mint> void ifft2(std::vector<mint>& a) {\n    static const ntt_info<mint>\
    \ info;\n    int n = int(a.size());\n    int bit_size = std::countr_zero(a.size());\n\
    \    assert(n == 1 << bit_size);\n\n    for (int bit = 0; bit < bit_size; bit++)\
    \ {\n        for (int i = 0; i < n / (1 << (bit + 1)); i++) {\n            mint\
    \ w = 1;\n            for (int j = 0; j < (1 << bit); j++) {\n               \
    \ int idx = i * (1 << (bit + 1)) + j;\n                int jdx = idx + (1 << bit);\n\
    \                mint p1 = a[idx];\n                mint p2 = w * a[jdx];\n  \
    \              a[idx] = p1 + p2;\n                a[jdx] = p1 - p2;\n        \
    \        w *= info.inv_root[bit + 1];\n            }\n        }\n    }\n}\n\n\
    template <Modint mint> void fft4(std::vector<mint>& a) {\n    static const ntt_info<mint>\
    \ info;\n    const u32 mod = mint::mod();\n    const u64 iw = info.root[2].val();\n\
    \    int n = int(a.size());\n    int bit_size = std::countr_zero(a.size());\n\
    \    assert(n == 1 << bit_size);\n    int len = bit_size;\n    while (len > 0)\
    \ {\n        if (len == 1) {\n            for (int i = 0; i < n; i += 2) {\n \
    \               mint p0 = a[i];\n                mint p1 = a[i + 1];\n       \
    \         a[i] = p0 + p1;\n                a[i + 1] = p0 - p1;\n            }\n\
    \            len--;\n        } else {\n            int m = 1 << (len - 2);\n \
    \           u64 w1 = 1, w2 = 1, w3 = 1, iw1 = iw, iw3 = iw;\n            for (int\
    \ i = 0; i < m; i++) {\n                for (int j = 0; j < n; j += 4 * m) {\n\
    \                    int i0 = i + j, i1 = i0 + m, i2 = i1 + m, i3 = i2 + m;\n\
    \                    u32 a0 = a[i0].val();\n                    u32 a1 = a[i1].val();\n\
    \                    u32 a2 = a[i2].val();\n                    u32 a3 = a[i3].val();\n\
    \                    u32 a0_plus_a2 = a0 + a2;\n                    u32 a1_plus_a3\
    \ = a1 + a3;\n                    u32 a0_minus_a2 = a0 + mod - a2;\n         \
    \           u32 a1_minus_a3 = a1 + mod - a3;\n                    a[i0] = a0_plus_a2\
    \ + a1_plus_a3;\n                    a[i1] = a0_minus_a2 * w1 + a1_minus_a3 *\
    \ iw1;\n                    a[i2] = (a0_plus_a2 + 2 * mod - a1_plus_a3) * w2;\n\
    \                    a[i3] = a0_minus_a2 * w3 + (2 * mod - a1_minus_a3) * iw3;\n\
    \                }\n                w1 = w1 * info.root[len].val() % mod;\n  \
    \              w2 = w1 * w1 % mod;\n                w3 = w2 * w1 % mod;\n    \
    \            iw1 = iw * w1 % mod;\n                iw3 = iw * w3 % mod;\n    \
    \        }\n            len -= 2;\n        }\n    }\n}\n\ntemplate <Modint mint>\
    \ void ifft4(std::vector<mint>& a) {\n    static const ntt_info<mint> info;\n\
    \    const u32 mod = mint::mod();\n    const u64 mod2 = u64(mod) * mod;\n    const\
    \ u64 iw = info.inv_root[2].val();\n    int n = int(a.size());\n    int bit_size\
    \ = std::countr_zero(a.size());\n    assert(n == 1 << bit_size);\n    int len\
    \ = (bit_size & 1 ? 1 : 2);\n    while (len <= bit_size) {\n        if (len ==\
    \ 1) {\n            for (int i = 0; i < n; i += 2) {\n                mint a0\
    \ = a[i];\n                mint a1 = a[i + 1];\n                a[i] = a0 + a1;\n\
    \                a[i + 1] = a0 - a1;\n            }\n        } else {\n      \
    \      int m = 1 << (len - 2);\n            u64 w1 = 1, w2 = 1, w3 = 1, iw1 =\
    \ iw, iw3 = iw;\n            for (int i = 0; i < m; i++) {\n                for\
    \ (int j = 0; j < n; j += 4 * m) {\n                    int i0 = i + j, i1 = i0\
    \ + m, i2 = i1 + m, i3 = i2 + m;\n                    u64 a0 = a[i0].val();\n\
    \                    u64 a1 = w1 * a[i1].val();\n                    u64 a2 =\
    \ w2 * a[i2].val();\n                    u64 a3 = w3 * a[i3].val();\n        \
    \            u64 b1 = iw1 * a[i1].val();\n                    u64 b3 = iw3 * a[i3].val();\n\
    \                    u64 a0_plus_a2 = a0 + a2;\n                    u64 a1_plus_a3\
    \ = a1 + a3;\n                    u64 a0_minus_a2 = a0 + mod2 - a2;\n        \
    \            u64 b1_minus_b3 = b1 + mod2 - b3;\n                    a[i0] = a0_plus_a2\
    \ + a1_plus_a3;\n                    a[i1] = a0_minus_a2 + b1_minus_b3;\n    \
    \                a[i2] = a0_plus_a2 + mod2 * 2 - a1_plus_a3;\n               \
    \     a[i3] = a0_minus_a2 + mod2 * 2 - b1_minus_b3;\n                }\n     \
    \           w1 = w1 * info.inv_root[len].val() % mod;\n                w2 = w1\
    \ * w1 % mod;\n                w3 = w2 * w1 % mod;\n                iw1 = iw *\
    \ w1 % mod;\n                iw3 = iw * w3 % mod;\n            }\n        }\n\
    \        len += 2;\n    }\n}\n\n}  // namespace internal\n\n}  // namespace ebi\n\
    #line 2 \"modint/modint.hpp\"\n\r\n#line 5 \"modint/modint.hpp\"\n\r\n#line 7\
    \ \"modint/modint.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate <int m> struct static_modint\
    \ {\r\n  private:\r\n    using modint = static_modint;\r\n\r\n  public:\r\n  \
    \  static constexpr int mod() {\r\n        return m;\r\n    }\r\n\r\n    static\
    \ constexpr modint raw(int v) {\r\n        modint x;\r\n        x._v = v;\r\n\
    \        return x;\r\n    }\r\n\r\n    constexpr static_modint() : _v(0) {}\r\n\
    \r\n    template<std::signed_integral T>\r\n    constexpr static_modint(T v) {\r\
    \n        long long x = (long long)(v % (long long)(umod()));\r\n        if (x\
    \ < 0) x += umod();\r\n        _v = (unsigned int)(x);\r\n    }\r\n\r\n    template<std::unsigned_integral\
    \ T>\r\n    constexpr static_modint(T v) {\r\n        _v = v % umod();\r\n   \
    \ }\r\n\r\n    constexpr unsigned int val() const {\r\n        return _v;\r\n\
    \    }\r\n\r\n    constexpr unsigned int value() const {\r\n        return val();\r\
    \n    }\r\n\r\n    constexpr modint &operator++() {\r\n        _v++;\r\n     \
    \   if (_v == umod()) _v = 0;\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator--() {\r\n        if (_v == 0) _v = umod();\r\n        _v--;\r\
    \n        return *this;\r\n    }\r\n\r\n    constexpr modint operator++(int) {\r\
    \n        modint res = *this;\r\n        ++*this;\r\n        return res;\r\n \
    \   }\r\n    constexpr modint operator--(int) {\r\n        modint res = *this;\r\
    \n        --*this;\r\n        return res;\r\n    }\r\n\r\n    constexpr modint\
    \ &operator+=(const modint &rhs) {\r\n        _v += rhs._v;\r\n        if (_v\
    \ >= umod()) _v -= umod();\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator-=(const modint &rhs) {\r\n        _v -= rhs._v;\r\n       \
    \ if (_v >= umod()) _v += umod();\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator*=(const modint &rhs) {\r\n        unsigned long long x = _v;\r\
    \n        x *= rhs._v;\r\n        _v = (unsigned int)(x % (unsigned long long)umod());\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator/=(const modint\
    \ &rhs) {\r\n        return *this = *this * rhs.inv();\r\n    }\r\n\r\n    constexpr\
    \ modint operator+() const {\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint operator-() const {\r\n        return modint() - *this;\r\n    }\r\n\r\
    \n    constexpr modint pow(long long n) const {\r\n        assert(0 <= n);\r\n\
    \        modint x = *this, res = 1;\r\n        while (n) {\r\n            if (n\
    \ & 1) res *= x;\r\n            x *= x;\r\n            n >>= 1;\r\n        }\r\
    \n        return res;\r\n    }\r\n    constexpr modint inv() const {\r\n     \
    \   assert(_v);\r\n        return pow(umod() - 2);\r\n    }\r\n\r\n    friend\
    \ modint operator+(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
    \ += rhs;\r\n    }\r\n    friend modint operator-(const modint &lhs, const modint\
    \ &rhs) {\r\n        return modint(lhs) -= rhs;\r\n    }\r\n    friend modint\
    \ operator*(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
    \ *= rhs;\r\n    }\r\n\r\n    friend modint operator/(const modint &lhs, const\
    \ modint &rhs) {\r\n        return modint(lhs) /= rhs;\r\n    }\r\n    friend\
    \ bool operator==(const modint &lhs, const modint &rhs) {\r\n        return lhs.val()\
    \ == rhs.val();\r\n    }\r\n    friend bool operator!=(const modint &lhs, const\
    \ modint &rhs) {\r\n        return !(lhs == rhs);\r\n    }\r\n\r\n  private:\r\
    \n    unsigned int _v = 0;\r\n\r\n    static constexpr unsigned int umod() {\r\
    \n        return m;\r\n    }\r\n};\r\n\r\nusing modint998244353 = static_modint<998244353>;\r\
    \nusing modint1000000007 = static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n\
    #line 2 \"fps/middle_product.hpp\"\n\n#line 6 \"fps/middle_product.hpp\"\n#include\
    \ <ranges>\n#line 8 \"fps/middle_product.hpp\"\n\n#line 11 \"fps/middle_product.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint>\nstd::vector<mint> middle_product(const\
    \ std::vector<mint> &a,\n                                 const std::vector<mint>\
    \ &b) {\n    assert(a.size() >= b.size());\n    if (std::min(a.size() - b.size()\
    \ + 1, b.size()) <= 60) {\n        return middle_product_naive<mint>(a, b);\n\
    \    }\n    int n = std::bit_ceil(a.size());\n    std::vector<mint> fa(n), fb(n);\n\
    \    std::copy(a.begin(), a.end(), fa.begin());\n    std::copy(b.rbegin(), b.rend(),\
    \ fb.begin());\n    internal::fft4(fa);\n    internal::fft4(fb);\n    for (int\
    \ i = 0; i < n; i++) {\n        fa[i] *= fb[i];\n    }\n    internal::ifft4(fa);\n\
    \    mint inv_n = mint(n).inv();\n    for (auto &x : fa) {\n        x *= inv_n;\n\
    \    }\n    fa.resize(a.size());\n    fa.erase(fa.begin(), fa.begin() + b.size()\
    \ - 1);\n    return fa;\n}\n\ntemplate <class T>\nstd::vector<T> middle_product_naive(const\
    \ std::vector<T> &a,\n                                       const std::vector<T>\
    \ &b) {\n    int n = (int)a.size();\n    int m = (int)b.size();\n    assert(n\
    \ >= m);\n    std::vector<T> c(n - m + 1, 0);\n    for (int i : std::views::iota(0,\
    \ n - m + 1)) {\n        for (int j : std::views::iota(0, m)) {\n            c[i]\
    \ += b[j] * a[i + j];\n        }\n    }\n    return c;\n}\n\n}  // namespace ebi\n\
    #line 12 \"fps/middle_product_arbitrary.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint\
    \ mint>\nstd::vector<mint> middle_product_arbitrary(const std::vector<mint> &a,\n\
    \                                 const std::vector<mint> &b) {\n    static constexpr\
    \ i32 m0 = 167772161;  // 2^25\n    static constexpr i32 m1 = 469762049;  // 2^26\n\
    \    static constexpr i32 m2 = 754974721;  // 2^24\n    using mint0 = static_modint<m0>;\n\
    \    using mint1 = static_modint<m1>;\n    using mint2 = static_modint<m2>;\n\
    \    static constexpr i32 inv01 = mint1(m0).inv().val();\n    static constexpr\
    \ i32 inv02 = mint2(m0).inv().val();\n    static constexpr i32 inv12 = mint2(m1).inv().val();\n\
    \    static constexpr i32 inv02inv12 = i64(inv02) * inv12 % m2;\n    static constexpr\
    \ i64 w1 = m0;\n    static constexpr i64 w2 = i64(m0) * m1;\n    const i32 mod\
    \ = mint::mod();\n\n    assert(a.size() >= b.size());\n    if (std::min(a.size()\
    \ - b.size() + 1, b.size()) <= 60) {\n        return middle_product_naive<mint>(a,\
    \ b);\n    }\n    int n = (int)a.size(), m = (int)b.size();\n    std::vector<mint0>\
    \ a0(n), b0(m);\n    std::vector<mint1> a1(n), b1(m);\n    std::vector<mint2>\
    \ a2(n), b2(m);\n\n    for (int i = 0; i < n; i++) {\n        a0[i] = a[i].val();\n\
    \        a1[i] = a[i].val();\n        a2[i] = a[i].val();\n    }\n    for(int\
    \ i = 0; i < m; i++) {\n        b0[i] = b[i].val();\n        b1[i] = b[i].val();\n\
    \        b2[i] = b[i].val();\n    }\n\n    auto c0 = middle_product<mint0>(a0,\
    \ b0);\n    auto c1 = middle_product<mint1>(a1, b1);\n    auto c2 = middle_product<mint2>(a2,\
    \ b2);\n\n    std::vector<mint> res(n - m + 1);\n    const i32 W1 = w1 % mod;\n\
    \    const i32 W2 = w2 % mod;\n    for(int i = 0; i < n - m + 1; i++) {\n    \
    \    i32 n1 = c1[i].val(), n2 = c2[i].val(), a = c0[i].val();\n        i32 b =\
    \ i64(n1 + m1 - a) * inv01 % m1;\n        i32 c = (i64(n2 + m2 - a) * inv02inv12\
    \ + i64(m2 - b) * inv12) % m2;\n        res[i] = (i64(a) + i64(b) * W1 + i64(c)\
    \ * W2) % mod;\n    }\n    return res;\n}\n\n\nstd::vector<u64> middle_product_mod_2_64(const\
    \ std::vector<u64> &a,\n                                 const std::vector<u64>\
    \ &b) {\n    static constexpr i32 m0 = 998244353;\n    static constexpr i32 m1\
    \ = 754974721;\n    static constexpr i32 m2 = 167772161;\n    static constexpr\
    \ i32 m3 = 469762049;\n    static constexpr i32 m4 = 880803841;\n    using mint0\
    \ = static_modint<m0>;\n    using mint1 = static_modint<m1>;\n    using mint2\
    \ = static_modint<m2>;\n    using mint3 = static_modint<m3>;\n    using mint4\
    \ = static_modint<m4>;\n\n    static const mint1 inv10 = mint1(m0).inv();\n  \
    \  static const mint2 inv21 = mint2(m1).inv(), inv20 = inv21 / mint2(m0);\n  \
    \  static const mint3 inv32 = mint3(m2).inv(), inv31 = inv32 / mint3(m1),\n  \
    \                     inv30 = inv31 / mint3(m0);\n    static const mint4 inv43\
    \ = mint4(m3).inv(), inv42 = inv43 / mint4(m2),\n                       inv41\
    \ = inv42 / mint4(m1), inv40 = inv41 / mint4(m0);\n\n    assert(a.size() >= b.size());\n\
    \    if (std::min(a.size() - b.size() + 1, b.size()) <= 60) {\n        return\
    \ middle_product_naive(a, b);\n    }\n    int n = (int)a.size(), m = (int)b.size();\n\
    \    std::vector<mint0> a0(n), b0(m);\n    std::vector<mint1> a1(n), b1(m);\n\
    \    std::vector<mint2> a2(n), b2(m);\n    std::vector<mint3> a3(n), b3(m);\n\
    \    std::vector<mint4> a4(n), b4(m);\n\n    for (int i = 0; i < n; i++) {\n \
    \       a0[i] = a[i];\n        a1[i] = a[i];\n        a2[i] = a[i];\n        a3[i]\
    \ = a[i];\n        a4[i] = a[i];\n    }\n    for(int i = 0; i < m; i++) {\n  \
    \      b0[i] = b[i];\n        b1[i] = b[i];\n        b2[i] = b[i];\n        b3[i]\
    \ = b[i];\n        b4[i] = b[i];\n    }\n\n    auto c0 = middle_product<mint0>(a0,\
    \ b0);\n    auto c1 = middle_product<mint1>(a1, b1);\n    auto c2 = middle_product<mint2>(a2,\
    \ b2);\n    auto c3 = middle_product<mint3>(a3, b3);\n    auto c4 = middle_product<mint4>(a4,\
    \ b4);\n\n    std::vector<u64> res(n - m + 1);\n    for(int i = 0; i < n - m +\
    \ 1; i++) {\n        i64 x0 = c0[i].val();\n        i64 x1 = ((c1[i] - x0) * inv10).val();\n\
    \        i64 x2 = (((c2[i] - x0)) * inv20 - mint2(x1) * inv21).val();\n      \
    \  i64 x3 = ((c3[i] - x0) * inv30 - mint3(x1) * inv31 - mint3(x2) * inv32)\n \
    \                    .val();\n        i64 x4 = ((c4[i] - x0) * inv40 - mint4(x1)\
    \ * inv41 - mint4(x2) * inv42 -\n                  mint4(x3) * inv43)\n      \
    \               .val();\n        res[i] = x0 + m0 * (x1 + m1 * (x2 + m2 * (x3\
    \ + m3 * (u64(x4)))));\n    }\n    return res;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \n#include \"../convolution/ntt.hpp\"\n#include \"../modint/modint.hpp\"\n#include\
    \ \"../fps/middle_product.hpp\"\n#include \"../modint/base.hpp\"\n#include \"\
    ../template/int_alias.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint>\nstd::vector<mint>\
    \ middle_product_arbitrary(const std::vector<mint> &a,\n                     \
    \            const std::vector<mint> &b) {\n    static constexpr i32 m0 = 167772161;\
    \  // 2^25\n    static constexpr i32 m1 = 469762049;  // 2^26\n    static constexpr\
    \ i32 m2 = 754974721;  // 2^24\n    using mint0 = static_modint<m0>;\n    using\
    \ mint1 = static_modint<m1>;\n    using mint2 = static_modint<m2>;\n    static\
    \ constexpr i32 inv01 = mint1(m0).inv().val();\n    static constexpr i32 inv02\
    \ = mint2(m0).inv().val();\n    static constexpr i32 inv12 = mint2(m1).inv().val();\n\
    \    static constexpr i32 inv02inv12 = i64(inv02) * inv12 % m2;\n    static constexpr\
    \ i64 w1 = m0;\n    static constexpr i64 w2 = i64(m0) * m1;\n    const i32 mod\
    \ = mint::mod();\n\n    assert(a.size() >= b.size());\n    if (std::min(a.size()\
    \ - b.size() + 1, b.size()) <= 60) {\n        return middle_product_naive<mint>(a,\
    \ b);\n    }\n    int n = (int)a.size(), m = (int)b.size();\n    std::vector<mint0>\
    \ a0(n), b0(m);\n    std::vector<mint1> a1(n), b1(m);\n    std::vector<mint2>\
    \ a2(n), b2(m);\n\n    for (int i = 0; i < n; i++) {\n        a0[i] = a[i].val();\n\
    \        a1[i] = a[i].val();\n        a2[i] = a[i].val();\n    }\n    for(int\
    \ i = 0; i < m; i++) {\n        b0[i] = b[i].val();\n        b1[i] = b[i].val();\n\
    \        b2[i] = b[i].val();\n    }\n\n    auto c0 = middle_product<mint0>(a0,\
    \ b0);\n    auto c1 = middle_product<mint1>(a1, b1);\n    auto c2 = middle_product<mint2>(a2,\
    \ b2);\n\n    std::vector<mint> res(n - m + 1);\n    const i32 W1 = w1 % mod;\n\
    \    const i32 W2 = w2 % mod;\n    for(int i = 0; i < n - m + 1; i++) {\n    \
    \    i32 n1 = c1[i].val(), n2 = c2[i].val(), a = c0[i].val();\n        i32 b =\
    \ i64(n1 + m1 - a) * inv01 % m1;\n        i32 c = (i64(n2 + m2 - a) * inv02inv12\
    \ + i64(m2 - b) * inv12) % m2;\n        res[i] = (i64(a) + i64(b) * W1 + i64(c)\
    \ * W2) % mod;\n    }\n    return res;\n}\n\n\nstd::vector<u64> middle_product_mod_2_64(const\
    \ std::vector<u64> &a,\n                                 const std::vector<u64>\
    \ &b) {\n    static constexpr i32 m0 = 998244353;\n    static constexpr i32 m1\
    \ = 754974721;\n    static constexpr i32 m2 = 167772161;\n    static constexpr\
    \ i32 m3 = 469762049;\n    static constexpr i32 m4 = 880803841;\n    using mint0\
    \ = static_modint<m0>;\n    using mint1 = static_modint<m1>;\n    using mint2\
    \ = static_modint<m2>;\n    using mint3 = static_modint<m3>;\n    using mint4\
    \ = static_modint<m4>;\n\n    static const mint1 inv10 = mint1(m0).inv();\n  \
    \  static const mint2 inv21 = mint2(m1).inv(), inv20 = inv21 / mint2(m0);\n  \
    \  static const mint3 inv32 = mint3(m2).inv(), inv31 = inv32 / mint3(m1),\n  \
    \                     inv30 = inv31 / mint3(m0);\n    static const mint4 inv43\
    \ = mint4(m3).inv(), inv42 = inv43 / mint4(m2),\n                       inv41\
    \ = inv42 / mint4(m1), inv40 = inv41 / mint4(m0);\n\n    assert(a.size() >= b.size());\n\
    \    if (std::min(a.size() - b.size() + 1, b.size()) <= 60) {\n        return\
    \ middle_product_naive(a, b);\n    }\n    int n = (int)a.size(), m = (int)b.size();\n\
    \    std::vector<mint0> a0(n), b0(m);\n    std::vector<mint1> a1(n), b1(m);\n\
    \    std::vector<mint2> a2(n), b2(m);\n    std::vector<mint3> a3(n), b3(m);\n\
    \    std::vector<mint4> a4(n), b4(m);\n\n    for (int i = 0; i < n; i++) {\n \
    \       a0[i] = a[i];\n        a1[i] = a[i];\n        a2[i] = a[i];\n        a3[i]\
    \ = a[i];\n        a4[i] = a[i];\n    }\n    for(int i = 0; i < m; i++) {\n  \
    \      b0[i] = b[i];\n        b1[i] = b[i];\n        b2[i] = b[i];\n        b3[i]\
    \ = b[i];\n        b4[i] = b[i];\n    }\n\n    auto c0 = middle_product<mint0>(a0,\
    \ b0);\n    auto c1 = middle_product<mint1>(a1, b1);\n    auto c2 = middle_product<mint2>(a2,\
    \ b2);\n    auto c3 = middle_product<mint3>(a3, b3);\n    auto c4 = middle_product<mint4>(a4,\
    \ b4);\n\n    std::vector<u64> res(n - m + 1);\n    for(int i = 0; i < n - m +\
    \ 1; i++) {\n        i64 x0 = c0[i].val();\n        i64 x1 = ((c1[i] - x0) * inv10).val();\n\
    \        i64 x2 = (((c2[i] - x0)) * inv20 - mint2(x1) * inv21).val();\n      \
    \  i64 x3 = ((c3[i] - x0) * inv30 - mint3(x1) * inv31 - mint3(x2) * inv32)\n \
    \                    .val();\n        i64 x4 = ((c4[i] - x0) * inv40 - mint4(x1)\
    \ * inv41 - mint4(x2) * inv42 -\n                  mint4(x3) * inv43)\n      \
    \               .val();\n        res[i] = x0 + m0 * (x1 + m1 * (x2 + m2 * (x3\
    \ + m3 * (u64(x4)))));\n    }\n    return res;\n}\n\n}  // namespace ebi"
  dependsOn:
  - convolution/ntt.hpp
  - math/internal_math.hpp
  - template/int_alias.hpp
  - modint/base.hpp
  - modint/modint.hpp
  - fps/middle_product.hpp
  isVerificationFile: false
  path: fps/middle_product_arbitrary.hpp
  requiredBy:
  - string/wildcard_pattern_matching.hpp
  timestamp: '2024-05-22 14:27:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/Wildcard_Pattern_Matching.test.cpp
documentation_of: fps/middle_product_arbitrary.hpp
layout: document
title: $[x^i]c = \sum_{j} [x^{i+j}]a [x^j]b$
---

## 説明

任意mod係数の $N$ 次多項式 $a$ と $M$ 次多項式 $b$ について $[x^i]c = \sum_{j} [x^{i+j}]a [x^j]b$ となる $N-M$ 次多項式 $c$ を求める。 $O(N\log N)$