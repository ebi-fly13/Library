---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: NTT
  - icon: ':heavy_check_mark:'
    path: math/internal_math.hpp
    title: math/internal_math.hpp
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':question:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/Convolution_Mod_2_64.test.cpp
    title: test/convolution/Convolution_Mod_2_64.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Frequency_Table_of_Tree_Distance_MODE_0.test.cpp
    title: test/tree/Frequency_Table_of_Tree_Distance_MODE_0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp
    title: test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Frequency_Table_of_Tree_Distance_MODE_2.test.cpp
    title: test/tree/Frequency_Table_of_Tree_Distance_MODE_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/convolution_mod_2_64.hpp\"\n\n#include <cstdint>\n\
    #include <vector>\n\n#line 2 \"convolution/convolution.hpp\"\n\n#include <algorithm>\n\
    #include <bit>\n#line 6 \"convolution/convolution.hpp\"\n\n#line 2 \"convolution/ntt.hpp\"\
    \n\n#line 4 \"convolution/ntt.hpp\"\n#include <array>\n#line 6 \"convolution/ntt.hpp\"\
    \n#include <cassert>\n#line 8 \"convolution/ntt.hpp\"\n\n#line 2 \"math/internal_math.hpp\"\
    \n\n#line 4 \"math/internal_math.hpp\"\n\nnamespace ebi {\n\nnamespace internal\
    \ {\n\nconstexpr int primitive_root_constexpr(int m) {\n    if (m == 2) return\
    \ 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049) return 3;\n \
    \   if (m == 754974721) return 11;\n    if (m == 998244353) return 3;\n    if\
    \ (m == 880803841) return 26;\n    if (m == 924844033) return 5;\n    return -1;\n\
    }\ntemplate <int m> constexpr int primitive_root = primitive_root_constexpr(m);\n\
    \n}  // namespace internal\n\n}  // namespace ebi\n#line 2 \"modint/base.hpp\"\
    \n\n#include <concepts>\n#include <iostream>\n#include <utility>\n\nnamespace\
    \ ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n    a +\
    \ b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 2 \"\
    template/int_alias.hpp\"\n\n#line 4 \"template/int_alias.hpp\"\n\nnamespace ebi\
    \ {\n\nusing ld = long double;\nusing std::size_t;\nusing i8 = std::int8_t;\n\
    using u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing u16 = std::uint16_t;\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    \n}  // namespace ebi\n#line 12 \"convolution/ntt.hpp\"\n\nnamespace ebi {\n\n\
    namespace internal {\n\ntemplate <Modint mint, int g = internal::primitive_root<mint::mod()>>\n\
    struct ntt_info {\n    static constexpr int rank2 =\n        std::countr_zero((unsigned\
    \ int)(mint::mod() - 1));\n\n    std::array<mint, rank2 + 1> root, inv_root;\n\
    \n    ntt_info() {\n        root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);\n\
    \        inv_root[rank2] = root[rank2].inv();\n        for (int i = rank2 - 1;\
    \ i >= 0; i--) {\n            root[i] = root[i + 1] * root[i + 1];\n         \
    \   inv_root[i] = inv_root[i + 1] * inv_root[i + 1];\n        }\n    }\n};\n\n\
    template <Modint mint> void fft2(std::vector<mint>& a) {\n    static const ntt_info<mint>\
    \ info;\n    int n = int(a.size());\n    int bit_size = std::countr_zero(a.size());\n\
    \    assert(n == 1 << bit_size);\n    for (int bit = bit_size - 1; bit >= 0; bit--)\
    \ {\n        int m = 1 << bit;\n        for (int i = 0; i < n; i += 2 * m) {\n\
    \            mint w = 1;\n            for (int j = 0; j < m; j++) {\n        \
    \        mint p1 = a[i + j];\n                mint p2 = a[i + j + m];\n      \
    \          a[i + j] = p1 + p2;\n                a[i + j + m] = (p1 - p2) * w;\n\
    \                w *= info.root[bit + 1];\n            }\n        }\n    }\n}\n\
    \ntemplate <Modint mint> void ifft2(std::vector<mint>& a) {\n    static const\
    \ ntt_info<mint> info;\n    int n = int(a.size());\n    int bit_size = std::countr_zero(a.size());\n\
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
    #line 9 \"convolution/convolution.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint\
    \ mint>\nstd::vector<mint> convolution_naive(const std::vector<mint>& f,\n   \
    \                                 const std::vector<mint>& g) {\n    if (f.empty()\
    \ || g.empty()) return {};\n    int n = int(f.size()), m = int(g.size());\n  \
    \  std::vector<mint> c(n + m - 1);\n    if (n < m) {\n        for (int j = 0;\
    \ j < m; j++) {\n            for (int i = 0; i < n; i++) {\n                c[i\
    \ + j] += f[i] * g[j];\n            }\n        }\n    } else {\n        for (int\
    \ i = 0; i < n; i++) {\n            for (int j = 0; j < m; j++) {\n          \
    \      c[i + j] += f[i] * g[j];\n            }\n        }\n    }\n    return c;\n\
    }\n\ntemplate <Modint mint>\nstd::vector<mint> convolution(const std::vector<mint>&\
    \ f,\n                              const std::vector<mint>& g) {\n    if (f.empty()\
    \ || g.empty()) return {};\n    if (std::min(f.size(), g.size()) < 60) return\
    \ convolution_naive(f, g);\n    int n = (int)std::bit_ceil(f.size() + g.size()\
    \ - 1);\n    std::vector<mint> a(n), b(n);\n    std::copy(f.begin(), f.end(),\
    \ a.begin());\n    std::copy(g.begin(), g.end(), b.begin());\n    internal::fft4(a);\n\
    \    internal::fft4(b);\n    for (int i = 0; i < n; i++) {\n        a[i] *= b[i];\n\
    \    }\n    internal::ifft4(a);\n    a.resize(f.size() + g.size() - 1);\n    mint\
    \ inv_n = mint(n).inv();\n    for (auto& x : a) x *= inv_n;\n    return a;\n}\n\
    \n}  // namespace ebi\n#line 2 \"modint/modint.hpp\"\n\r\n#line 5 \"modint/modint.hpp\"\
    \n\r\n#line 7 \"modint/modint.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate <int\
    \ m> struct static_modint {\r\n  private:\r\n    using modint = static_modint;\r\
    \n\r\n  public:\r\n    static constexpr int mod() {\r\n        return m;\r\n \
    \   }\r\n\r\n    static constexpr modint raw(int v) {\r\n        modint x;\r\n\
    \        x._v = v;\r\n        return x;\r\n    }\r\n\r\n    constexpr static_modint()\
    \ : _v(0) {}\r\n\r\n    template <std::signed_integral T> constexpr static_modint(T\
    \ v) {\r\n        long long x = (long long)(v % (long long)(umod()));\r\n    \
    \    if (x < 0) x += umod();\r\n        _v = (unsigned int)(x);\r\n    }\r\n\r\
    \n    template <std::unsigned_integral T> constexpr static_modint(T v) {\r\n \
    \       _v = (unsigned int)(v % umod());\r\n    }\r\n\r\n    constexpr unsigned\
    \ int val() const {\r\n        return _v;\r\n    }\r\n\r\n    constexpr unsigned\
    \ int value() const {\r\n        return val();\r\n    }\r\n\r\n    constexpr modint\
    \ &operator++() {\r\n        _v++;\r\n        if (_v == umod()) _v = 0;\r\n  \
    \      return *this;\r\n    }\r\n    constexpr modint &operator--() {\r\n    \
    \    if (_v == 0) _v = umod();\r\n        _v--;\r\n        return *this;\r\n \
    \   }\r\n\r\n    constexpr modint operator++(int) {\r\n        modint res = *this;\r\
    \n        ++*this;\r\n        return res;\r\n    }\r\n    constexpr modint operator--(int)\
    \ {\r\n        modint res = *this;\r\n        --*this;\r\n        return res;\r\
    \n    }\r\n\r\n    constexpr modint &operator+=(const modint &rhs) {\r\n     \
    \   _v += rhs._v;\r\n        if (_v >= umod()) _v -= umod();\r\n        return\
    \ *this;\r\n    }\r\n    constexpr modint &operator-=(const modint &rhs) {\r\n\
    \        _v -= rhs._v;\r\n        if (_v >= umod()) _v += umod();\r\n        return\
    \ *this;\r\n    }\r\n    constexpr modint &operator*=(const modint &rhs) {\r\n\
    \        unsigned long long x = _v;\r\n        x *= rhs._v;\r\n        _v = (unsigned\
    \ int)(x % (unsigned long long)umod());\r\n        return *this;\r\n    }\r\n\
    \    constexpr modint &operator/=(const modint &rhs) {\r\n        return *this\
    \ = *this * rhs.inv();\r\n    }\r\n\r\n    constexpr modint operator+() const\
    \ {\r\n        return *this;\r\n    }\r\n    constexpr modint operator-() const\
    \ {\r\n        return modint() - *this;\r\n    }\r\n\r\n    constexpr modint pow(long\
    \ long n) const {\r\n        assert(0 <= n);\r\n        modint x = *this, res\
    \ = 1;\r\n        while (n) {\r\n            if (n & 1) res *= x;\r\n        \
    \    x *= x;\r\n            n >>= 1;\r\n        }\r\n        return res;\r\n \
    \   }\r\n    constexpr modint inv() const {\r\n        assert(_v);\r\n       \
    \ return pow(umod() - 2);\r\n    }\r\n\r\n    friend modint operator+(const modint\
    \ &lhs, const modint &rhs) {\r\n        return modint(lhs) += rhs;\r\n    }\r\n\
    \    friend modint operator-(const modint &lhs, const modint &rhs) {\r\n     \
    \   return modint(lhs) -= rhs;\r\n    }\r\n    friend modint operator*(const modint\
    \ &lhs, const modint &rhs) {\r\n        return modint(lhs) *= rhs;\r\n    }\r\n\
    \r\n    friend modint operator/(const modint &lhs, const modint &rhs) {\r\n  \
    \      return modint(lhs) /= rhs;\r\n    }\r\n    friend bool operator==(const\
    \ modint &lhs, const modint &rhs) {\r\n        return lhs.val() == rhs.val();\r\
    \n    }\r\n    friend bool operator!=(const modint &lhs, const modint &rhs) {\r\
    \n        return !(lhs == rhs);\r\n    }\r\n\r\n  private:\r\n    unsigned int\
    \ _v = 0;\r\n\r\n    static constexpr unsigned int umod() {\r\n        return\
    \ m;\r\n    }\r\n};\r\n\r\nusing modint998244353 = static_modint<998244353>;\r\
    \nusing modint1000000007 = static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n\
    #line 9 \"convolution/convolution_mod_2_64.hpp\"\n\nnamespace ebi {\n\nnamespace\
    \ internal {\n\ntemplate <Modint mint>\nstd::vector<mint> multiply_uint64_t(const\
    \ std::vector<std::uint64_t>& f,\n                                    const std::vector<std::uint64_t>&\
    \ g) {\n    std::vector<mint> a, b;\n    a.reserve(f.size());\n    b.reserve(g.size());\n\
    \    for (auto x : f) a.emplace_back(x % mint::mod());\n    for (auto x : g) b.emplace_back(x\
    \ % mint::mod());\n    return convolution<mint>(a, b);\n}\n\n}  // namespace internal\n\
    \nstd::vector<std::uint64_t> convolution_mod_2_64(\n    const std::vector<std::uint64_t>&\
    \ f, const std::vector<std::uint64_t>& g) {\n    if (f.empty() || g.empty()) return\
    \ {};\n    using i32 = std::int32_t;\n    using i64 = std::int64_t;\n    using\
    \ u64 = std::uint64_t;\n    static constexpr i32 m0 = 998244353;\n    static constexpr\
    \ i32 m1 = 754974721;\n    static constexpr i32 m2 = 167772161;\n    static constexpr\
    \ i32 m3 = 469762049;\n    static constexpr i32 m4 = 880803841;\n    using mint0\
    \ = static_modint<m0>;\n    using mint1 = static_modint<m1>;\n    using mint2\
    \ = static_modint<m2>;\n    using mint3 = static_modint<m3>;\n    using mint4\
    \ = static_modint<m4>;\n\n    auto d0 = internal::multiply_uint64_t<mint0>(f,\
    \ g);\n    auto d1 = internal::multiply_uint64_t<mint1>(f, g);\n    auto d2 =\
    \ internal::multiply_uint64_t<mint2>(f, g);\n    auto d3 = internal::multiply_uint64_t<mint3>(f,\
    \ g);\n    auto d4 = internal::multiply_uint64_t<mint4>(f, g);\n\n    static const\
    \ mint1 inv10 = mint1(m0).inv();\n    static const mint2 inv21 = mint2(m1).inv(),\
    \ inv20 = inv21 / mint2(m0);\n    static const mint3 inv32 = mint3(m2).inv(),\
    \ inv31 = inv32 / mint3(m1),\n                       inv30 = inv31 / mint3(m0);\n\
    \    static const mint4 inv43 = mint4(m3).inv(), inv42 = inv43 / mint4(m2),\n\
    \                       inv41 = inv42 / mint4(m1), inv40 = inv41 / mint4(m0);\n\
    \    int n = d0.size();\n    std::vector<u64> res(n);\n    for (int i = 0; i <\
    \ n; i++) {\n        i64 x0 = d0[i].val();\n        i64 x1 = ((d1[i] - x0) * inv10).val();\n\
    \        i64 x2 = (((d2[i] - x0)) * inv20 - mint2(x1) * inv21).val();\n      \
    \  i64 x3 = ((d3[i] - x0) * inv30 - mint3(x1) * inv31 - mint3(x2) * inv32)\n \
    \                    .val();\n        i64 x4 = ((d4[i] - x0) * inv40 - mint4(x1)\
    \ * inv41 - mint4(x2) * inv42 -\n                  mint4(x3) * inv43)\n      \
    \               .val();\n        res[i] = x0 + m0 * (x1 + m1 * (x2 + m2 * (x3\
    \ + m3 * (u64(x4)))));\n    }\n    return res;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cstdint>\n#include <vector>\n\n#include \"../convolution/convolution.hpp\"\
    \n#include \"../modint/base.hpp\"\n#include \"../modint/modint.hpp\"\n\nnamespace\
    \ ebi {\n\nnamespace internal {\n\ntemplate <Modint mint>\nstd::vector<mint> multiply_uint64_t(const\
    \ std::vector<std::uint64_t>& f,\n                                    const std::vector<std::uint64_t>&\
    \ g) {\n    std::vector<mint> a, b;\n    a.reserve(f.size());\n    b.reserve(g.size());\n\
    \    for (auto x : f) a.emplace_back(x % mint::mod());\n    for (auto x : g) b.emplace_back(x\
    \ % mint::mod());\n    return convolution<mint>(a, b);\n}\n\n}  // namespace internal\n\
    \nstd::vector<std::uint64_t> convolution_mod_2_64(\n    const std::vector<std::uint64_t>&\
    \ f, const std::vector<std::uint64_t>& g) {\n    if (f.empty() || g.empty()) return\
    \ {};\n    using i32 = std::int32_t;\n    using i64 = std::int64_t;\n    using\
    \ u64 = std::uint64_t;\n    static constexpr i32 m0 = 998244353;\n    static constexpr\
    \ i32 m1 = 754974721;\n    static constexpr i32 m2 = 167772161;\n    static constexpr\
    \ i32 m3 = 469762049;\n    static constexpr i32 m4 = 880803841;\n    using mint0\
    \ = static_modint<m0>;\n    using mint1 = static_modint<m1>;\n    using mint2\
    \ = static_modint<m2>;\n    using mint3 = static_modint<m3>;\n    using mint4\
    \ = static_modint<m4>;\n\n    auto d0 = internal::multiply_uint64_t<mint0>(f,\
    \ g);\n    auto d1 = internal::multiply_uint64_t<mint1>(f, g);\n    auto d2 =\
    \ internal::multiply_uint64_t<mint2>(f, g);\n    auto d3 = internal::multiply_uint64_t<mint3>(f,\
    \ g);\n    auto d4 = internal::multiply_uint64_t<mint4>(f, g);\n\n    static const\
    \ mint1 inv10 = mint1(m0).inv();\n    static const mint2 inv21 = mint2(m1).inv(),\
    \ inv20 = inv21 / mint2(m0);\n    static const mint3 inv32 = mint3(m2).inv(),\
    \ inv31 = inv32 / mint3(m1),\n                       inv30 = inv31 / mint3(m0);\n\
    \    static const mint4 inv43 = mint4(m3).inv(), inv42 = inv43 / mint4(m2),\n\
    \                       inv41 = inv42 / mint4(m1), inv40 = inv41 / mint4(m0);\n\
    \    int n = d0.size();\n    std::vector<u64> res(n);\n    for (int i = 0; i <\
    \ n; i++) {\n        i64 x0 = d0[i].val();\n        i64 x1 = ((d1[i] - x0) * inv10).val();\n\
    \        i64 x2 = (((d2[i] - x0)) * inv20 - mint2(x1) * inv21).val();\n      \
    \  i64 x3 = ((d3[i] - x0) * inv30 - mint3(x1) * inv31 - mint3(x2) * inv32)\n \
    \                    .val();\n        i64 x4 = ((d4[i] - x0) * inv40 - mint4(x1)\
    \ * inv41 - mint4(x2) * inv42 -\n                  mint4(x3) * inv43)\n      \
    \               .val();\n        res[i] = x0 + m0 * (x1 + m1 * (x2 + m2 * (x3\
    \ + m3 * (u64(x4)))));\n    }\n    return res;\n}\n\n}  // namespace ebi"
  dependsOn:
  - convolution/convolution.hpp
  - convolution/ntt.hpp
  - math/internal_math.hpp
  - modint/base.hpp
  - template/int_alias.hpp
  - modint/modint.hpp
  isVerificationFile: false
  path: convolution/convolution_mod_2_64.hpp
  requiredBy: []
  timestamp: '2024-05-23 21:35:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp
  - test/tree/Frequency_Table_of_Tree_Distance_MODE_2.test.cpp
  - test/tree/Frequency_Table_of_Tree_Distance_MODE_0.test.cpp
  - test/convolution/Convolution_Mod_2_64.test.cpp
documentation_of: convolution/convolution_mod_2_64.hpp
layout: document
title: Convolution $\pmod{2^{64}}$
---

## 説明

$\mod 2^{64}$ における $O(N\log N)$ 時間での畳み込み。