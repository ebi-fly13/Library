---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/convolution.hpp
    title: algorithm/convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DynamicSegmentTree.test.cpp
    title: test/DynamicSegmentTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ImplicitTreap.test.cpp
    title: test/ImplicitTreap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LazySegtree.test.cpp
    title: test/LazySegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/SWAG.test.cpp
    title: test/SWAG.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution.test.cpp
    title: test/convolution.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://noshi91.hatenablog.com/entry/2019/03/31/174006
  bundledCode: "#line 2 \"utility/modint.hpp\"\n\r\n/*\r\n    author: noshi91\r\n\
    \    reference: https://noshi91.hatenablog.com/entry/2019/03/31/174006\r\n   \
    \ noshi91\u306E\u30D6\u30ED\u30B0\u3067\u516C\u958B\u3055\u308C\u3066\u3044\u308B\
    modint\u3092\u5143\u306Binv(), pow()\u3092\u8FFD\u52A0\u3057\u305F\u3082\u306E\
    \u3067\u3059\r\n*/\r\n\r\n#include <cstdint>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<std::uint_fast64_t\
    \ Modulus>\r\nclass modint {\r\n  using u64 = std::uint_fast64_t;\r\n\r\npublic:\r\
    \n    u64 a;\r\n\r\n    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus)\
    \ {}\r\n    constexpr u64 &value() noexcept { return a; }\r\n    constexpr const\
    \ u64 &value() const noexcept { return a; }\r\n    constexpr modint operator+(const\
    \ modint rhs) const noexcept {\r\n        return modint(*this) += rhs;\r\n   \
    \ }\r\n    constexpr modint operator-(const modint rhs) const noexcept {\r\n \
    \       return modint(*this) -= rhs;\r\n    }\r\n    constexpr modint operator*(const\
    \ modint rhs) const noexcept {\r\n        return modint(*this) *= rhs;\r\n   \
    \ }\r\n    constexpr modint operator/(const modint rhs) const noexcept {\r\n \
    \       return modint(*this) /= rhs;\r\n    }\r\n    constexpr modint &operator+=(const\
    \ modint rhs) noexcept {\r\n        a += rhs.a;\r\n        if (a >= Modulus) {\r\
    \n            a -= Modulus;\r\n        }\r\n        return *this;\r\n    }\r\n\
    \    constexpr modint &operator-=(const modint rhs) noexcept {\r\n        if (a\
    \ < rhs.a) {\r\n        a += Modulus;\r\n        }\r\n        a -= rhs.a;\r\n\
    \        return *this;\r\n    }\r\n    constexpr modint &operator*=(const modint\
    \ rhs) noexcept {\r\n        a = a * rhs.a % Modulus;\r\n        return *this;\r\
    \n    }\r\n    constexpr modint &operator/=(modint rhs) noexcept {\r\n       \
    \ u64 exp = Modulus - 2;\r\n        while (exp) {\r\n        if (exp % 2) {\r\n\
    \            *this *= rhs;\r\n        }\r\n        rhs *= rhs;\r\n        exp\
    \ /= 2;\r\n        }\r\n        return *this;\r\n    }\r\n    modint pow(u64 n)\
    \ const noexcept {\r\n        modint res = 1;\r\n        modint x = a;\r\n   \
    \     while(n>0){\r\n            if(n&1) res *= x;\r\n            x *= x;\r\n\
    \            n >>=1;\r\n        }\r\n        return res;\r\n    }\r\n    modint\
    \ inv() const {\r\n        return pow(Modulus-2);\r\n    }\r\n\r\n    static u64\
    \ mod() {\r\n        return Modulus;\r\n    }\r\n};\r\n\r\nusing modint998244353\
    \ = modint<998244353>;\r\nusing modint1000000007 = modint<1000000007>;\r\n\r\n\
    } // namespace ebi\n"
  code: "#pragma once\r\n\r\n/*\r\n    author: noshi91\r\n    reference: https://noshi91.hatenablog.com/entry/2019/03/31/174006\r\
    \n    noshi91\u306E\u30D6\u30ED\u30B0\u3067\u516C\u958B\u3055\u308C\u3066\u3044\
    \u308Bmodint\u3092\u5143\u306Binv(), pow()\u3092\u8FFD\u52A0\u3057\u305F\u3082\
    \u306E\u3067\u3059\r\n*/\r\n\r\n#include <cstdint>\r\n\r\nnamespace ebi {\r\n\r\
    \ntemplate<std::uint_fast64_t Modulus>\r\nclass modint {\r\n  using u64 = std::uint_fast64_t;\r\
    \n\r\npublic:\r\n    u64 a;\r\n\r\n    constexpr modint(const u64 x = 0) noexcept\
    \ : a(x % Modulus) {}\r\n    constexpr u64 &value() noexcept { return a; }\r\n\
    \    constexpr const u64 &value() const noexcept { return a; }\r\n    constexpr\
    \ modint operator+(const modint rhs) const noexcept {\r\n        return modint(*this)\
    \ += rhs;\r\n    }\r\n    constexpr modint operator-(const modint rhs) const noexcept\
    \ {\r\n        return modint(*this) -= rhs;\r\n    }\r\n    constexpr modint operator*(const\
    \ modint rhs) const noexcept {\r\n        return modint(*this) *= rhs;\r\n   \
    \ }\r\n    constexpr modint operator/(const modint rhs) const noexcept {\r\n \
    \       return modint(*this) /= rhs;\r\n    }\r\n    constexpr modint &operator+=(const\
    \ modint rhs) noexcept {\r\n        a += rhs.a;\r\n        if (a >= Modulus) {\r\
    \n            a -= Modulus;\r\n        }\r\n        return *this;\r\n    }\r\n\
    \    constexpr modint &operator-=(const modint rhs) noexcept {\r\n        if (a\
    \ < rhs.a) {\r\n        a += Modulus;\r\n        }\r\n        a -= rhs.a;\r\n\
    \        return *this;\r\n    }\r\n    constexpr modint &operator*=(const modint\
    \ rhs) noexcept {\r\n        a = a * rhs.a % Modulus;\r\n        return *this;\r\
    \n    }\r\n    constexpr modint &operator/=(modint rhs) noexcept {\r\n       \
    \ u64 exp = Modulus - 2;\r\n        while (exp) {\r\n        if (exp % 2) {\r\n\
    \            *this *= rhs;\r\n        }\r\n        rhs *= rhs;\r\n        exp\
    \ /= 2;\r\n        }\r\n        return *this;\r\n    }\r\n    modint pow(u64 n)\
    \ const noexcept {\r\n        modint res = 1;\r\n        modint x = a;\r\n   \
    \     while(n>0){\r\n            if(n&1) res *= x;\r\n            x *= x;\r\n\
    \            n >>=1;\r\n        }\r\n        return res;\r\n    }\r\n    modint\
    \ inv() const {\r\n        return pow(Modulus-2);\r\n    }\r\n\r\n    static u64\
    \ mod() {\r\n        return Modulus;\r\n    }\r\n};\r\n\r\nusing modint998244353\
    \ = modint<998244353>;\r\nusing modint1000000007 = modint<1000000007>;\r\n\r\n\
    } // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: utility/modint.hpp
  requiredBy:
  - algorithm/convolution.hpp
  timestamp: '2021-01-18 11:46:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/SWAG.test.cpp
  - test/DynamicSegmentTree.test.cpp
  - test/ImplicitTreap.test.cpp
  - test/convolution.test.cpp
  - test/LazySegtree.test.cpp
documentation_of: utility/modint.hpp
layout: document
redirect_from:
- /library/utility/modint.hpp
- /library/utility/modint.hpp.html
title: utility/modint.hpp
---
