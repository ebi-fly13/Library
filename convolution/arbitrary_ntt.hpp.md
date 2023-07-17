---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/ntt.hpp
    title: NTT Convolution
  - icon: ':question:'
    path: math/internal_math.hpp
    title: math/internal_math.hpp
  - icon: ':question:'
    path: utility/bit_operator.hpp
    title: utility/bit_operator.hpp
  - icon: ':question:'
    path: utility/modint_base.hpp
    title: utility/modint_base.hpp
  - icon: ':x:'
    path: utility/montgomery_modint.hpp
    title: utility/montgomery_modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/convolution/Convolution_Mod_1000000007.test.cpp
    title: test/convolution/Convolution_Mod_1000000007.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/arbitrary_ntt.hpp\"\n\n#include <cstdint>\n\
    #include <vector>\n\n#line 2 \"convolution/ntt.hpp\"\n\n#include <array>\n#include\
    \ <cassert>\n#include <type_traits>\n#line 7 \"convolution/ntt.hpp\"\n\n#line\
    \ 2 \"math/internal_math.hpp\"\n\n#line 4 \"math/internal_math.hpp\"\n\nnamespace\
    \ ebi {\n\nnamespace internal {\n\nconstexpr int primitive_root_constexpr(int\
    \ m) {\n    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m\
    \ == 469762049) return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353)\
    \ return 3;\n    assert(0);\n    return -1;\n}\ntemplate <int m> constexpr int\
    \ primitive_root = primitive_root_constexpr(m);\n\n}  // namespace internal\n\n\
    }  // namespace ebi\n#line 2 \"utility/bit_operator.hpp\"\n\nnamespace ebi {\n\
    \nconstexpr int bsf_constexpr(unsigned int n) {\n    int x = 0;\n    while (!(n\
    \ & (1 << x))) x++;\n    return x;\n}\n\nint bit_reverse(int n, int bit_size)\
    \ {\n    int rev_n = 0;\n    for (int i = 0; i < bit_size; i++) {\n        rev_n\
    \ |= ((n >> i) & 1) << (bit_size - i - 1);\n    }\n    return rev_n;\n}\n\nint\
    \ ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n))\
    \ x++;\n    return x;\n}\n\nint popcnt(int x) {\n    return __builtin_popcount(x);\n\
    }\n\nint msb(int x) {\n    return (x == 0) ? -1 : 31 - __builtin_clz(x);\n}\n\n\
    int bsf(int x) {\n    return (x == 0) ? -1 : __builtin_ctz(x);\n}\n\n}  // namespace\
    \ ebi\n#line 2 \"utility/modint_base.hpp\"\n\n#line 4 \"utility/modint_base.hpp\"\
    \n\nnamespace ebi {\n\nnamespace internal {\n\nstruct modint_base {};\n\ntemplate\
    \ <class T> using is_modint = std::is_base_of<modint_base, T>;\ntemplate <class\
    \ T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\nstruct static_modint_base\
    \ : modint_base {};\n\ntemplate <class T>\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\ntemplate <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace ebi\n#line 11 \"convolution/ntt.hpp\"\
    \n\nnamespace ebi {\n\nnamespace internal {\n\ntemplate <class mint, int g = internal::primitive_root<mint::mod()>,\n\
    \          internal::is_static_modint_t<mint>* = nullptr>\nstruct ntt_info {\n\
    \    static constexpr int rank2 = bsf_constexpr(mint::mod() - 1);\n\n    std::array<mint,\
    \ rank2 + 1> root, inv_root;\n\n    ntt_info() {\n        root[rank2] = mint(g).pow((mint::mod()\
    \ - 1) >> rank2);\n        inv_root[rank2] = root[rank2].inv();\n        for (int\
    \ i = rank2 - 1; i >= 0; i--) {\n            root[i] = root[i + 1] * root[i +\
    \ 1];\n            inv_root[i] = inv_root[i + 1] * inv_root[i + 1];\n        }\n\
    \    }\n};\n\ntemplate <class mint, internal::is_static_modint_t<mint>* = nullptr>\n\
    void butterfly(std::vector<mint>& a) {\n    static const ntt_info<mint> info;\n\
    \    int n = int(a.size());\n    int bit_size = bsf(n);\n    assert(n == 1 <<\
    \ ceil_pow2(n));\n    // bit reverse\n    for (int i = 0; i < n; i++) {\n    \
    \    int rev = bit_reverse(i, bit_size);\n        if (i < rev) {\n           \
    \ std::swap(a[i], a[rev]);\n        }\n    }\n\n    for (int bit = 0; bit < bit_size;\
    \ bit++) {\n        for (int i = 0; i < n / (1 << (bit + 1)); i++) {\n       \
    \     mint zeta1 = 1;\n            mint zeta2 = info.root[1];\n            for\
    \ (int j = 0; j < (1 << bit); j++) {\n                int idx = i * (1 << (bit\
    \ + 1)) + j;\n                int jdx = idx + (1 << bit);\n                mint\
    \ p1 = a[idx];\n                mint p2 = a[jdx];\n                a[idx] = p1\
    \ + zeta1 * p2;\n                a[jdx] = p1 + zeta2 * p2;\n                zeta1\
    \ *= info.root[bit + 1];\n                zeta2 *= info.root[bit + 1];\n     \
    \       }\n        }\n    }\n}\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nvoid butterfly_inv(std::vector<mint>& a) {\n    static const ntt_info<mint>\
    \ info;\n    int n = int(a.size());\n    int bit_size = bsf(n);\n    assert(n\
    \ == 1 << ceil_pow2(n));\n    // bit reverse\n    for (int i = 0; i < n; i++)\
    \ {\n        int rev = bit_reverse(i, bit_size);\n        if (i < rev) std::swap(a[i],\
    \ a[rev]);\n    }\n\n    for (int bit = 0; bit < bit_size; bit++) {\n        for\
    \ (int i = 0; i < n / (1 << (bit + 1)); i++) {\n            mint zeta1 = 1;\n\
    \            mint zeta2 = info.inv_root[1];\n            for (int j = 0; j < (1\
    \ << bit); j++) {\n                int idx = i * (1 << (bit + 1)) + j;\n     \
    \           int jdx = idx + (1 << bit);\n                mint p1 = a[idx];\n \
    \               mint p2 = a[jdx];\n                a[idx] = p1 + zeta1 * p2;\n\
    \                a[jdx] = p1 + zeta2 * p2;\n                zeta1 *= info.inv_root[bit\
    \ + 1];\n                zeta2 *= info.inv_root[bit + 1];\n            }\n   \
    \     }\n    }\n    mint inv_n = mint(n).inv();\n    for (int i = 0; i < n; i++)\
    \ {\n        a[i] *= inv_n;\n    }\n}\n\n}  // namespace internal\n\ntemplate\
    \ <class mint, internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint>\
    \ convolution(const std::vector<mint>& f,\n                              const\
    \ std::vector<mint>& g) {\n    int n = 1 << ceil_pow2(f.size() + g.size() - 1);\n\
    \    std::vector<mint> a(n), b(n);\n    std::copy(f.begin(), f.end(), a.begin());\n\
    \    std::copy(g.begin(), g.end(), b.begin());\n    internal::butterfly(a);\n\
    \    internal::butterfly(b);\n    for (int i = 0; i < n; i++) {\n        a[i]\
    \ *= b[i];\n    }\n    internal::butterfly_inv(a);\n    a.resize(f.size() + g.size()\
    \ - 1);\n    return a;\n}\n\n}  // namespace ebi\n#line 2 \"utility/montgomery_modint.hpp\"\
    \n\n#line 4 \"utility/montgomery_modint.hpp\"\n#include <iostream>\n\n#line 7\
    \ \"utility/montgomery_modint.hpp\"\n\nnamespace ebi {\n\ntemplate <int m> struct\
    \ montgomery_modint : internal::static_modint_base {\n  private:\n    using modint\
    \ = montgomery_modint;\n    using i32 = std::int32_t;\n    using u32 = std::uint32_t;\n\
    \    using i64 = std::int64_t;\n    using u64 = std::uint64_t;\n\n    static constexpr\
    \ u32 umod() {\n        return m;\n    }\n\n    static constexpr u32 get_r() {\n\
    \        u32 ret = umod();\n        for (i32 i = 0; i < 4; i++) ret *= 2 - umod()\
    \ * ret;\n        return ret;\n    }\n\n    static constexpr u32 r = get_r();\n\
    \    static constexpr u32 n2 = -u64(umod()) % umod();\n\n    static constexpr\
    \ modint one = 1;\n\n    static constexpr u32 reduce(const u64 &b) {\n       \
    \ return u32(b >> 32) + umod() - u32((u64(u32(b) * r) * umod()) >> 32);\n    }\n\
    \n    static_assert(r * umod() == 1, \"invalid, r * mod != 1\");\n    static_assert(umod()\
    \ < (1 << 30), \"invalid, mod >= 2 ^ 30\");\n    static_assert((umod() & 1) ==\
    \ 1, \"invalid, mod % 2 == 0\");\n\n  public:\n    static constexpr int mod()\
    \ {\n        return m;\n    }\n\n    constexpr montgomery_modint() : _v(0) {}\n\
    \n    constexpr montgomery_modint(i64 v)\n        : _v(reduce((v % i64(umod())\
    \ + i64(umod())) * n2)) {}\n\n    constexpr modint &operator+=(const modint &rhs)\
    \ {\n        if (i32(_v += rhs._v - 2 * umod()) < 0) _v += 2 * umod();\n     \
    \   return *this;\n    }\n\n    constexpr modint &operator-=(const modint &rhs)\
    \ {\n        if (i32(_v -= rhs._v) < 0) _v += 2 * umod();\n        return *this;\n\
    \    }\n\n    constexpr modint &operator*=(const modint &rhs) {\n        _v =\
    \ reduce(u64(_v) * rhs._v);\n        return *this;\n    }\n\n    constexpr modint\
    \ &operator/=(const modint &rhs) {\n        *this *= rhs.inv();\n        return\
    \ *this;\n    }\n\n    constexpr modint &operator++() {\n        *this += one;\n\
    \        return *this;\n    }\n\n    constexpr modint &operator--() {\n      \
    \  *this -= one;\n        return *this;\n    }\n\n    constexpr modint operator++(int)\
    \ {\n        modint res = *this;\n        ++*this;\n        return res;\n    }\n\
    \n    constexpr modint operator--(int) {\n        modint res = *this;\n      \
    \  --*this;\n        return res;\n    }\n\n    constexpr modint operator+() const\
    \ {\n        return *this;\n    }\n\n    constexpr modint operator-() const {\n\
    \        return modint() - *this;\n    }\n\n    friend modint operator+(const\
    \ modint &lhs, const modint &rhs) {\n        return modint(lhs) += rhs;\n    }\n\
    \    friend modint operator-(const modint &lhs, const modint &rhs) {\n       \
    \ return modint(lhs) -= rhs;\n    }\n    friend modint operator*(const modint\
    \ &lhs, const modint &rhs) {\n        return modint(lhs) *= rhs;\n    }\n    friend\
    \ modint operator/(const modint &lhs, const modint &rhs) {\n        return modint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const modint &lhs, const modint &rhs)\
    \ {\n        return (lhs._v >= umod() ? lhs._v - umod() : lhs._v) ==\n       \
    \        (rhs._v >= umod() ? rhs._v - umod() : rhs._v);\n    }\n    friend bool\
    \ operator!=(const modint &lhs, const modint &rhs) {\n        return !(lhs ==\
    \ rhs);\n    }\n\n    constexpr modint pow(u64 n) const {\n        modint x =\
    \ *this, res = 1;\n        while (n) {\n            if (n & 1) res *= x;\n   \
    \         x *= x;\n            n >>= 1;\n        }\n        return res;\n    }\n\
    \n    constexpr modint inv() const {\n        return pow(umod() - 2);\n    }\n\
    \n    constexpr u32 val() const {\n        u32 ret = reduce(i64(_v));\n      \
    \  return ret >= umod() ? ret - umod() : ret;\n    }\n\n  private:\n    u32 _v\
    \ = 0;\n};\n\ntemplate <int m>\nstd::istream &operator>>(std::istream &os, montgomery_modint<m>\
    \ &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n}\ntemplate\
    \ <int m>\nstd::ostream &operator<<(std::ostream &os, const montgomery_modint<m>\
    \ &a) {\n    return os << a.val();\n}\n\nusing montgomery_modint998244353 = montgomery_modint<998244353>;\n\
    using montgomery_modint1000000007 = montgomery_modint<1'000'000'007>;\n\n}  //\
    \ namespace ebi\n#line 9 \"convolution/arbitrary_ntt.hpp\"\n\nnamespace ebi {\n\
    \nnamespace internal {\n\ntemplate <class T, class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstd::vector<mint> multiply(const std::vector<T>& f, const std::vector<T>&\
    \ g) {\n    std::vector<mint> a, b;\n    a.reserve(f.size());\n    b.reserve(g.size());\n\
    \    for (auto x : f) a.emplace_back(x.val());\n    for (auto x : g) b.emplace_back(x.val());\n\
    \    return convolution<mint>(a, b);\n}\n\n}  // namespace internal\n\ntemplate\
    \ <class mint, internal::is_modint_t<mint>* = nullptr>\nstd::vector<mint> arbitary_convolution(const\
    \ std::vector<mint>& f,\n                                       const std::vector<mint>&\
    \ g) {\n    using i32 = std::int64_t;\n    using i64 = std::int64_t;\n    static\
    \ constexpr i32 m0 = 167772161;  // 2^25\n    static constexpr i32 m1 = 469762049;\
    \  // 2^26\n    static constexpr i32 m2 = 754974721;  // 2^24\n    using mint0\
    \ = montgomery_modint<m0>;\n    using mint1 = montgomery_modint<m1>;\n    using\
    \ mint2 = montgomery_modint<m2>;\n    static constexpr i32 inv01 = mint1(m0).inv().val();\n\
    \    static constexpr i32 inv02 = mint2(m0).inv().val();\n    static constexpr\
    \ i32 inv12 = mint2(m1).inv().val();\n    static constexpr i32 inv02inv12 = i64(inv02)\
    \ * inv12 % m2;\n    static constexpr i64 w1 = m0;\n    static constexpr i64 w2\
    \ = i64(m0) * m1;\n\n    const i32 mod = mint::mod();\n\n    auto d0 = internal::multiply<mint,\
    \ mint0>(f, g);\n    auto d1 = internal::multiply<mint, mint1>(f, g);\n    auto\
    \ d2 = internal::multiply<mint, mint2>(f, g);\n\n    int n = d0.size();\n    std::vector<mint>\
    \ res(n);\n    const int W1 = w1 % mod;\n    const int W2 = w2 % mod;\n\n    for\
    \ (int i = 0; i < n; i++) {\n        i32 n1 = d1[i].val(), n2 = d2[i].val(), a\
    \ = d0[i].val();\n        i32 b = i64(n1 + m1 - a) * inv01 % m1;\n        i32\
    \ c = (i64(n2 + m2 - a) * inv02inv12 + i64(m2 - b) * inv12) % m2;\n        res[i]\
    \ = (i64(a) + i64(b) * W1 + i64(c) * W2) % mod;\n    }\n    return res;\n}\n\n\
    }  // namespace ebi\n"
  code: "#pragma once\n\n#include <cstdint>\n#include <vector>\n\n#include \"../convolution/ntt.hpp\"\
    \n#include \"../utility/modint_base.hpp\"\n#include \"../utility/montgomery_modint.hpp\"\
    \n\nnamespace ebi {\n\nnamespace internal {\n\ntemplate <class T, class mint,\
    \ internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> multiply(const\
    \ std::vector<T>& f, const std::vector<T>& g) {\n    std::vector<mint> a, b;\n\
    \    a.reserve(f.size());\n    b.reserve(g.size());\n    for (auto x : f) a.emplace_back(x.val());\n\
    \    for (auto x : g) b.emplace_back(x.val());\n    return convolution<mint>(a,\
    \ b);\n}\n\n}  // namespace internal\n\ntemplate <class mint, internal::is_modint_t<mint>*\
    \ = nullptr>\nstd::vector<mint> arbitary_convolution(const std::vector<mint>&\
    \ f,\n                                       const std::vector<mint>& g) {\n \
    \   using i32 = std::int64_t;\n    using i64 = std::int64_t;\n    static constexpr\
    \ i32 m0 = 167772161;  // 2^25\n    static constexpr i32 m1 = 469762049;  // 2^26\n\
    \    static constexpr i32 m2 = 754974721;  // 2^24\n    using mint0 = montgomery_modint<m0>;\n\
    \    using mint1 = montgomery_modint<m1>;\n    using mint2 = montgomery_modint<m2>;\n\
    \    static constexpr i32 inv01 = mint1(m0).inv().val();\n    static constexpr\
    \ i32 inv02 = mint2(m0).inv().val();\n    static constexpr i32 inv12 = mint2(m1).inv().val();\n\
    \    static constexpr i32 inv02inv12 = i64(inv02) * inv12 % m2;\n    static constexpr\
    \ i64 w1 = m0;\n    static constexpr i64 w2 = i64(m0) * m1;\n\n    const i32 mod\
    \ = mint::mod();\n\n    auto d0 = internal::multiply<mint, mint0>(f, g);\n   \
    \ auto d1 = internal::multiply<mint, mint1>(f, g);\n    auto d2 = internal::multiply<mint,\
    \ mint2>(f, g);\n\n    int n = d0.size();\n    std::vector<mint> res(n);\n   \
    \ const int W1 = w1 % mod;\n    const int W2 = w2 % mod;\n\n    for (int i = 0;\
    \ i < n; i++) {\n        i32 n1 = d1[i].val(), n2 = d2[i].val(), a = d0[i].val();\n\
    \        i32 b = i64(n1 + m1 - a) * inv01 % m1;\n        i32 c = (i64(n2 + m2\
    \ - a) * inv02inv12 + i64(m2 - b) * inv12) % m2;\n        res[i] = (i64(a) + i64(b)\
    \ * W1 + i64(c) * W2) % mod;\n    }\n    return res;\n}\n\n}  // namespace ebi"
  dependsOn:
  - convolution/ntt.hpp
  - math/internal_math.hpp
  - utility/bit_operator.hpp
  - utility/modint_base.hpp
  - utility/montgomery_modint.hpp
  isVerificationFile: false
  path: convolution/arbitrary_ntt.hpp
  requiredBy: []
  timestamp: '2023-07-17 13:16:33+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/convolution/Convolution_Mod_1000000007.test.cpp
documentation_of: convolution/arbitrary_ntt.hpp
layout: document
title: Arbitrary Convolution
---

## 説明

任意の素数 mod における $O(N\log N)$ 時間での畳み込み。
