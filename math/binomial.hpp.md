---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/taylor_shift.hpp
    title: $f(x + c)$
  - icon: ':heavy_check_mark:'
    path: math/stirling_number_1st.hpp
    title: Stirling Numbers of the First Kind
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_3361.test.cpp
    title: test/aoj/aoj_3361.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
    title: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Stirling_Number_of_the_First_Kind.test.cpp
    title: test/math/Stirling_Number_of_the_First_Kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Polynomial_Taylor_Shift.test.cpp
    title: test/polynomial/Polynomial_Taylor_Shift.test.cpp
  - icon: ':x:'
    path: test/yuki/yuki_1302.test.cpp
    title: test/yuki/yuki_1302.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/binomial.hpp\"\n\n#include <bit>\n#include <cassert>\n\
    #include <iostream>\n#include <ranges>\n#include <vector>\n\n#line 2 \"modint/base.hpp\"\
    \n\n#include <concepts>\n#line 5 \"modint/base.hpp\"\n#include <utility>\n\nnamespace\
    \ ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n    a +\
    \ b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 10 \"\
    math/binomial.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint> struct Binomial\
    \ {\n  private:\n    static void extend(int len = -1) {\n        int sz = (int)fact.size();\n\
    \        if (len < 0)\n            len = 2 * sz;\n        else\n            len\
    \ = std::max(2 * sz, (int)std::bit_ceil(std::uint32_t(len)));\n        len = std::min(len,\
    \ mint::mod());\n        assert(sz <= len);\n        fact.resize(len);\n     \
    \   inv_fact.resize(len);\n        for (int i : std::views::iota(sz, len)) {\n\
    \            fact[i] = fact[i - 1] * i;\n        }\n        inv_fact[len - 1]\
    \ = fact[len - 1].inv();\n        for (int i : std::views::iota(sz, len) | std::views::reverse)\
    \ {\n            inv_fact[i - 1] = inv_fact[i] * i;\n        }\n    }\n\n  public:\n\
    \    Binomial() = default;\n\n    Binomial(int n) {\n        extend(n + 1);\n\
    \    }\n\n    static mint f(int n) {\n        if (n >= (int)fact.size()) [[unlikely]]\
    \ {\n            extend(n + 1);\n        }\n        return fact[n];\n    }\n\n\
    \    static mint inv_f(int n) {\n        if (n >= (int)fact.size()) [[unlikely]]\
    \ {\n            extend(n + 1);\n        }\n        return inv_fact[n];\n    }\n\
    \n    static mint c(int n, int r) {\n        if (r < 0 || n < r) return 0;\n \
    \       return f(n) * inv_f(r) * inv_f(n - r);\n    }\n\n    static mint p(int\
    \ n, int r) {\n        if (r < 0 || n < r) return 0;\n        return f(n) * inv_f(n\
    \ - r);\n    }\n\n    static mint inv(int n) {\n        return inv_f(n) * f(n\
    \ - 1);\n    }\n\n    static void reserve(int n) {\n        extend(n + 1);\n \
    \   }\n\n  private:\n    static std::vector<mint> fact, inv_fact;\n};\n\ntemplate\
    \ <Modint mint>\nstd::vector<mint> Binomial<mint>::fact = std::vector<mint>(2,\
    \ 1);\n\ntemplate <Modint mint>\nstd::vector<mint> Binomial<mint>::inv_fact =\
    \ std::vector<mint>(2, 1);\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <bit>\n#include <cassert>\n#include <iostream>\n\
    #include <ranges>\n#include <vector>\n\n#include \"../modint/base.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <Modint mint> struct Binomial {\n  private:\n    static void\
    \ extend(int len = -1) {\n        int sz = (int)fact.size();\n        if (len\
    \ < 0)\n            len = 2 * sz;\n        else\n            len = std::max(2\
    \ * sz, (int)std::bit_ceil(std::uint32_t(len)));\n        len = std::min(len,\
    \ mint::mod());\n        assert(sz <= len);\n        fact.resize(len);\n     \
    \   inv_fact.resize(len);\n        for (int i : std::views::iota(sz, len)) {\n\
    \            fact[i] = fact[i - 1] * i;\n        }\n        inv_fact[len - 1]\
    \ = fact[len - 1].inv();\n        for (int i : std::views::iota(sz, len) | std::views::reverse)\
    \ {\n            inv_fact[i - 1] = inv_fact[i] * i;\n        }\n    }\n\n  public:\n\
    \    Binomial() = default;\n\n    Binomial(int n) {\n        extend(n + 1);\n\
    \    }\n\n    static mint f(int n) {\n        if (n >= (int)fact.size()) [[unlikely]]\
    \ {\n            extend(n + 1);\n        }\n        return fact[n];\n    }\n\n\
    \    static mint inv_f(int n) {\n        if (n >= (int)fact.size()) [[unlikely]]\
    \ {\n            extend(n + 1);\n        }\n        return inv_fact[n];\n    }\n\
    \n    static mint c(int n, int r) {\n        if (r < 0 || n < r) return 0;\n \
    \       return f(n) * inv_f(r) * inv_f(n - r);\n    }\n\n    static mint p(int\
    \ n, int r) {\n        if (r < 0 || n < r) return 0;\n        return f(n) * inv_f(n\
    \ - r);\n    }\n\n    static mint inv(int n) {\n        return inv_f(n) * f(n\
    \ - 1);\n    }\n\n    static void reserve(int n) {\n        extend(n + 1);\n \
    \   }\n\n  private:\n    static std::vector<mint> fact, inv_fact;\n};\n\ntemplate\
    \ <Modint mint>\nstd::vector<mint> Binomial<mint>::fact = std::vector<mint>(2,\
    \ 1);\n\ntemplate <Modint mint>\nstd::vector<mint> Binomial<mint>::inv_fact =\
    \ std::vector<mint>(2, 1);\n\n}  // namespace ebi\n"
  dependsOn:
  - modint/base.hpp
  isVerificationFile: false
  path: math/binomial.hpp
  requiredBy:
  - fps/taylor_shift.hpp
  - math/stirling_number_1st.hpp
  timestamp: '2023-10-26 12:28:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/polynomial/Polynomial_Taylor_Shift.test.cpp
  - test/yuki/yuki_1302.test.cpp
  - test/aoj/aoj_3361.test.cpp
  - test/math/Stirling_Number_of_the_First_Kind.test.cpp
  - test/math/Binomial_Coefficient_Prime_Mod.test.cpp
documentation_of: math/binomial.hpp
layout: document
title: Binomial Coefficient
---

## 説明

組み合わせを求める構造体。クエリの最大値を $N$ として、前計算 $O(N)$ クエリ $O(1)$ である。

### c(int n, int r)

$\binom{n}{r}$ を求める。

### p(int n, int r)

$n$ この中から $r$ 個選び、それを一列に並べる組み合わせを返す。

### f(int n)

$n!$ を求める。

### inv_f(int n)

$(n!)^{-1}$ を求める。

### inv(int n)

$n^{-1}$ を求める。

## reserve(int n)

処理できるクエリの最大値を $n$ にする。
