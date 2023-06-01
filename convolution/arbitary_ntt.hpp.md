---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: convolution/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: math/internal_math.hpp
    title: math/internal_math.hpp
  - icon: ':question:'
    path: utility/bit_operator.hpp
    title: utility/bit_operator.hpp
  - icon: ':question:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  - icon: ':question:'
    path: utility/modint_base.hpp
    title: utility/modint_base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Convolution_Mod_1000000007.test.cpp
    title: test/Convolution_Mod_1000000007.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/arbitary_ntt.hpp\"\n\n#include <cstdint>\n#include\
    \ <vector>\n\n#line 2 \"convolution/ntt.hpp\"\n\n#include <array>\n#include <type_traits>\n\
    #line 6 \"convolution/ntt.hpp\"\n\n#line 2 \"math/internal_math.hpp\"\n\nnamespace\
    \ ebi {\n\nnamespace internal {\n\nconstexpr int primitive_root_constexpr(int\
    \ m) {\n    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m\
    \ == 469762049) return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353)\
    \ return 3;\n}\ntemplate <int m> constexpr int primitive_root = primitive_root_constexpr(m);\n\
    \n}  // namespace internal\n\n}  // namespace ebi\n#line 2 \"utility/bit_operator.hpp\"\
    \n\nnamespace ebi {\n\nconstexpr int bsf_constexpr(unsigned int n) {\n    int\
    \ x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n}\n\nint bit_reverse(int\
    \ n, int bit_size) {\n    int rev_n = 0;\n    for (int i = 0; i < bit_size; i++)\
    \ {\n        rev_n |= ((n >> i) & 1) << (bit_size - i - 1);\n    }\n    return\
    \ rev_n;\n}\n\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) <\
    \ (unsigned int)(n)) x++;\n    return x;\n}\n\nint popcnt(int x) {\n    return\
    \ __builtin_popcount(x);\n}\n\nint msb(int x) {\n    return (x == 0) ? -1 : 31\
    \ - __builtin_clz(x);\n}\n\nint bsf(int x) {\n    return (x == 0) ? -1 : __builtin_ctz(x);\n\
    }\n\n}  // namespace ebi\n#line 2 \"utility/modint.hpp\"\n\r\n#include <cassert>\r\
    \n#include <iostream>\r\n#line 6 \"utility/modint.hpp\"\n\r\n#line 2 \"utility/modint_base.hpp\"\
    \n\n#line 4 \"utility/modint_base.hpp\"\n\nnamespace ebi {\n\nnamespace internal\
    \ {\n\nstruct modint_base {};\n\ntemplate <class T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace ebi\n#line 8 \"utility/modint.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\nnamespace internal {\r\n\r\nstruct static_modint_base\
    \ : modint_base {};\r\n\r\ntemplate <class T>\r\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\r\n\r\ntemplate <class T>\r\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\r\
    \n\r\n}  // namespace internal\r\n\r\ntemplate <int m> struct static_modint :\
    \ internal::static_modint_base {\r\n  private:\r\n    using modint = static_modint;\r\
    \n\r\n  public:\r\n    static constexpr int mod() {\r\n        return m;\r\n \
    \   }\r\n\r\n    static constexpr modint raw(int v) {\r\n        modint x;\r\n\
    \        x._v = v;\r\n        return x;\r\n    }\r\n\r\n    constexpr static_modint()\
    \ : _v(0) {}\r\n\r\n    constexpr static_modint(long long v) {\r\n        v %=\
    \ (long long)umod();\r\n        if (v < 0) v += (long long)umod();\r\n       \
    \ _v = (unsigned int)v;\r\n    }\r\n\r\n    constexpr unsigned int val() const\
    \ {\r\n        return _v;\r\n    }\r\n\r\n    constexpr unsigned int value() const\
    \ {\r\n        return val();\r\n    }\r\n\r\n    constexpr modint &operator++()\
    \ {\r\n        _v++;\r\n        if (_v == umod()) _v = 0;\r\n        return *this;\r\
    \n    }\r\n    constexpr modint &operator--() {\r\n        if (_v == 0) _v = umod();\r\
    \n        _v--;\r\n        return *this;\r\n    }\r\n    constexpr modint &operator+=(const\
    \ modint &rhs) {\r\n        _v += rhs._v;\r\n        if (_v >= umod()) _v -= umod();\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator-=(const modint\
    \ &rhs) {\r\n        _v -= rhs._v;\r\n        if (_v >= umod()) _v += umod();\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator*=(const modint\
    \ &rhs) {\r\n        unsigned long long x = _v;\r\n        x *= rhs._v;\r\n  \
    \      _v = (unsigned int)(x % (unsigned long long)umod());\r\n        return\
    \ *this;\r\n    }\r\n    constexpr modint &operator/=(const modint &rhs) {\r\n\
    \        return *this = *this * rhs.inv();\r\n    }\r\n\r\n    constexpr modint\
    \ operator+() const {\r\n        return *this;\r\n    }\r\n    constexpr modint\
    \ operator-() const {\r\n        return modint() - *this;\r\n    }\r\n\r\n   \
    \ constexpr modint pow(long long n) const {\r\n        assert(0 <= n);\r\n   \
    \     modint x = *this, res = 1;\r\n        while (n) {\r\n            if (n &\
    \ 1) res *= x;\r\n            x *= x;\r\n            n >>= 1;\r\n        }\r\n\
    \        return res;\r\n    }\r\n    constexpr modint inv() const {\r\n      \
    \  assert(_v);\r\n        return pow(umod() - 2);\r\n    }\r\n\r\n    friend modint\
    \ operator+(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
    \ += rhs;\r\n    }\r\n    friend modint operator-(const modint &lhs, const modint\
    \ &rhs) {\r\n        return modint(lhs) -= rhs;\r\n    }\r\n    friend modint\
    \ operator*(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
    \ *= rhs;\r\n    }\r\n\r\n    friend modint operator/(const modint &lhs, const\
    \ modint &rhs) {\r\n        return modint(lhs) /= rhs;\r\n    }\r\n    friend\
    \ bool operator==(const modint &lhs, const modint &rhs) {\r\n        return lhs.val()\
    \ == rhs.val();\r\n    }\r\n    friend bool operator!=(const modint &lhs, const\
    \ modint &rhs) {\r\n        return !(lhs == rhs);\r\n    }\r\n\r\n  private:\r\
    \n    unsigned int _v = 0;\r\n\r\n    static constexpr unsigned int umod() {\r\
    \n        return m;\r\n    }\r\n};\r\n\r\ntemplate <int m>\r\nstd::istream &operator>>(std::istream\
    \ &os, static_modint<m> &a) {\r\n    long long x;\r\n    os >> x;\r\n    a = x;\r\
    \n    return os;\r\n}\r\ntemplate <int m>\r\nstd::ostream &operator<<(std::ostream\
    \ &os, const static_modint<m> &a) {\r\n    return os << a.val();\r\n}\r\n\r\n\
    using modint998244353 = static_modint<998244353>;\r\nusing modint1000000007 =\
    \ static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 10 \"convolution/ntt.hpp\"\
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
    \ - 1);\n    return a;\n}\n\n}  // namespace ebi\n#line 8 \"convolution/arbitary_ntt.hpp\"\
    \n\nnamespace ebi {\n\nnamespace internal {\n\ntemplate <class T, class mint,\
    \ internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> multiply(const\
    \ std::vector<T>& f, const std::vector<T>& g) {\n    std::vector<mint> a, b;\n\
    \    a.reserve(f.size());\n    b.reserve(g.size());\n    for (auto x : f) a.emplace_back(x.val());\n\
    \    for (auto x : g) b.emplace_back(x.val());\n    return convolution<mint>(a,\
    \ b);\n}\n\n}  // namespace internal\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstd::vector<mint> arbitary_convolution(const std::vector<mint>&\
    \ f,\n                                       const std::vector<mint>& g) {\n \
    \   using i32 = std::int64_t;\n    using i64 = std::int64_t;\n    static constexpr\
    \ i32 m0 = 167772161;  // 2^25\n    static constexpr i32 m1 = 469762049;  // 2^26\n\
    \    static constexpr i32 m2 = 754974721;  // 2^24\n    using mint0 = static_modint<m0>;\n\
    \    using mint1 = static_modint<m1>;\n    using mint2 = static_modint<m2>;\n\
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
    \ * W1 + i64(c) * W2) % mod;\n    }\n    return res;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cstdint>\n#include <vector>\n\n#include \"../convolution/ntt.hpp\"\
    \n#include \"../utility/modint.hpp\"\n\nnamespace ebi {\n\nnamespace internal\
    \ {\n\ntemplate <class T, class mint, internal::is_static_modint_t<mint>* = nullptr>\n\
    std::vector<mint> multiply(const std::vector<T>& f, const std::vector<T>& g) {\n\
    \    std::vector<mint> a, b;\n    a.reserve(f.size());\n    b.reserve(g.size());\n\
    \    for (auto x : f) a.emplace_back(x.val());\n    for (auto x : g) b.emplace_back(x.val());\n\
    \    return convolution<mint>(a, b);\n}\n\n}  // namespace internal\n\ntemplate\
    \ <class mint, internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint>\
    \ arbitary_convolution(const std::vector<mint>& f,\n                         \
    \              const std::vector<mint>& g) {\n    using i32 = std::int64_t;\n\
    \    using i64 = std::int64_t;\n    static constexpr i32 m0 = 167772161;  // 2^25\n\
    \    static constexpr i32 m1 = 469762049;  // 2^26\n    static constexpr i32 m2\
    \ = 754974721;  // 2^24\n    using mint0 = static_modint<m0>;\n    using mint1\
    \ = static_modint<m1>;\n    using mint2 = static_modint<m2>;\n    static constexpr\
    \ i32 inv01 = mint1(m0).inv().val();\n    static constexpr i32 inv02 = mint2(m0).inv().val();\n\
    \    static constexpr i32 inv12 = mint2(m1).inv().val();\n    static constexpr\
    \ i32 inv02inv12 = i64(inv02) * inv12 % m2;\n    static constexpr i64 w1 = m0;\n\
    \    static constexpr i64 w2 = i64(m0) * m1;\n\n    const i32 mod = mint::mod();\n\
    \n    auto d0 = internal::multiply<mint, mint0>(f, g);\n    auto d1 = internal::multiply<mint,\
    \ mint1>(f, g);\n    auto d2 = internal::multiply<mint, mint2>(f, g);\n\n    int\
    \ n = d0.size();\n    std::vector<mint> res(n);\n    const int W1 = w1 % mod;\n\
    \    const int W2 = w2 % mod;\n\n    for (int i = 0; i < n; i++) {\n        i32\
    \ n1 = d1[i].val(), n2 = d2[i].val(), a = d0[i].val();\n        i32 b = i64(n1\
    \ + m1 - a) * inv01 % m1;\n        i32 c = (i64(n2 + m2 - a) * inv02inv12 + i64(m2\
    \ - b) * inv12) % m2;\n        res[i] = (i64(a) + i64(b) * W1 + i64(c) * W2) %\
    \ mod;\n    }\n    return res;\n}\n\n}  // namespace ebi"
  dependsOn:
  - convolution/ntt.hpp
  - math/internal_math.hpp
  - utility/bit_operator.hpp
  - utility/modint.hpp
  - utility/modint_base.hpp
  isVerificationFile: false
  path: convolution/arbitary_ntt.hpp
  requiredBy: []
  timestamp: '2023-05-31 02:50:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Convolution_Mod_1000000007.test.cpp
documentation_of: convolution/arbitary_ntt.hpp
layout: document
redirect_from:
- /library/convolution/arbitary_ntt.hpp
- /library/convolution/arbitary_ntt.hpp.html
title: convolution/arbitary_ntt.hpp
---
