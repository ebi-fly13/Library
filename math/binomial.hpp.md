---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/aoj_3361.test.cpp
    title: test/aoj/aoj_3361.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
    title: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1302.test.cpp
    title: test/yuki/yuki_1302.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/binomial.hpp\"\n\n#include <cassert>\n#include <ranges>\n\
    #include <vector>\n\nnamespace ebi {\n\ntemplate <class mint> struct Binomial\
    \ {\n  private:\n    static void extend(int len) {\n        int sz = (int)fact.size();\n\
    \        assert(sz <= len);\n        fact.resize(len);\n        inv_fact.resize(len);\n\
    \        for (int i : std::views::iota(sz, len)) {\n            fact[i] = fact[i\
    \ - 1] * i;\n        }\n        inv_fact[len - 1] = fact[len - 1].inv();\n   \
    \     for (int i : std::views::iota(sz, len) | std::views::reverse) {\n      \
    \      inv_fact[i - 1] = inv_fact[i] * i;\n        }\n    }\n\n  public:\n   \
    \ Binomial(int n) {\n        extend(n + 1);\n    }\n\n    static mint c(int n,\
    \ int r) {\n        assert(n < (int)fact.size());\n        if (r < 0 || n < r)\
    \ return 0;\n        return fact[n] * inv_fact[r] * inv_fact[n - r];\n    }\n\n\
    \    static mint p(int n, int r) {\n        assert(n < (int)fact.size());\n  \
    \      if (r < 0 || n < r) return 0;\n        return fact[n] * inv_fact[n - r];\n\
    \    }\n\n    static mint f(int n) {\n        assert(n < (int)fact.size());\n\
    \        return fact[n];\n    }\n\n    static mint inv_f(int n) {\n        assert(n\
    \ < (int)fact.size());\n        return inv_fact[n];\n    }\n\n    static mint\
    \ inv(int n) {\n        assert(n < (int)fact.size());\n        return inv_fact[n]\
    \ * fact[n - 1];\n    }\n\n    static void reserve(int n) {\n        extend(n\
    \ + 1);\n    }\n\n  private:\n    static std::vector<mint> fact, inv_fact;\n};\n\
    \ntemplate <class mint>\nstd::vector<mint> Binomial<mint>::fact = std::vector<mint>(2,\
    \ 1);\n\ntemplate <class mint>\nstd::vector<mint> Binomial<mint>::inv_fact = std::vector<mint>(2,\
    \ 1);\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <ranges>\n#include <vector>\n\
    \nnamespace ebi {\n\ntemplate <class mint> struct Binomial {\n  private:\n   \
    \ static void extend(int len) {\n        int sz = (int)fact.size();\n        assert(sz\
    \ <= len);\n        fact.resize(len);\n        inv_fact.resize(len);\n       \
    \ for (int i : std::views::iota(sz, len)) {\n            fact[i] = fact[i - 1]\
    \ * i;\n        }\n        inv_fact[len - 1] = fact[len - 1].inv();\n        for\
    \ (int i : std::views::iota(sz, len) | std::views::reverse) {\n            inv_fact[i\
    \ - 1] = inv_fact[i] * i;\n        }\n    }\n\n  public:\n    Binomial(int n)\
    \ {\n        extend(n + 1);\n    }\n\n    static mint c(int n, int r) {\n    \
    \    assert(n < (int)fact.size());\n        if (r < 0 || n < r) return 0;\n  \
    \      return fact[n] * inv_fact[r] * inv_fact[n - r];\n    }\n\n    static mint\
    \ p(int n, int r) {\n        assert(n < (int)fact.size());\n        if (r < 0\
    \ || n < r) return 0;\n        return fact[n] * inv_fact[n - r];\n    }\n\n  \
    \  static mint f(int n) {\n        assert(n < (int)fact.size());\n        return\
    \ fact[n];\n    }\n\n    static mint inv_f(int n) {\n        assert(n < (int)fact.size());\n\
    \        return inv_fact[n];\n    }\n\n    static mint inv(int n) {\n        assert(n\
    \ < (int)fact.size());\n        return inv_fact[n] * fact[n - 1];\n    }\n\n \
    \   static void reserve(int n) {\n        extend(n + 1);\n    }\n\n  private:\n\
    \    static std::vector<mint> fact, inv_fact;\n};\n\ntemplate <class mint>\nstd::vector<mint>\
    \ Binomial<mint>::fact = std::vector<mint>(2, 1);\n\ntemplate <class mint>\nstd::vector<mint>\
    \ Binomial<mint>::inv_fact = std::vector<mint>(2, 1);\n\n}  // namespace ebi\n"
  dependsOn: []
  isVerificationFile: false
  path: math/binomial.hpp
  requiredBy: []
  timestamp: '2023-10-24 00:42:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yuki/yuki_1302.test.cpp
  - test/aoj/aoj_3361.test.cpp
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
