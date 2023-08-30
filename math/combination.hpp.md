---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_3361.test.cpp
    title: test/aoj/aoj_3361.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
    title: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - icon: ':x:'
    path: test/yuki/yuki_1302.test.cpp
    title: test/yuki/yuki_1302.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/combination.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \nnamespace ebi {\n\ntemplate <class mint>\nstruct combination {\n    combination(int\
    \ n) : m(n), fact(n + 1), inv_fact(n + 1) {\n        fact[0] = 1;\n        for\
    \ (int i = 1; i <= n; i++) {\n            fact[i] = fact[i - 1] * i;\n       \
    \ }\n        inv_fact[n] = fact[n].inv();\n        for (int i = n; i > 0; i--)\
    \ {\n            inv_fact[i - 1] = inv_fact[i] * i;\n        }\n    }\n\n    mint\
    \ operator()(int n, int k) const {\n        assert(n <= m);\n        if (k < 0\
    \ || n < k) return 0;\n        return fact[n] * inv_fact[k] * inv_fact[n - k];\n\
    \    }\n\n    mint f(int n) const {\n        assert(n <= m);\n        if (n <\
    \ 0) return 0;\n        return fact[n];\n    }\n\n    mint inv_f(int n) const\
    \ {\n        assert(n <= m);\n        if (n < 0) return 0;\n        return inv_fact[n];\n\
    \    }\n\n    mint inv(int n) const {\n        assert(n <= m);\n        return\
    \ inv_fact[n] * fact[n-1];\n    }\n\n  private:\n    int m;\n    std::vector<mint>\
    \ fact, inv_fact;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\nnamespace ebi {\n\
    \ntemplate <class mint>\nstruct combination {\n    combination(int n) : m(n),\
    \ fact(n + 1), inv_fact(n + 1) {\n        fact[0] = 1;\n        for (int i = 1;\
    \ i <= n; i++) {\n            fact[i] = fact[i - 1] * i;\n        }\n        inv_fact[n]\
    \ = fact[n].inv();\n        for (int i = n; i > 0; i--) {\n            inv_fact[i\
    \ - 1] = inv_fact[i] * i;\n        }\n    }\n\n    mint operator()(int n, int\
    \ k) const {\n        assert(n <= m);\n        if (k < 0 || n < k) return 0;\n\
    \        return fact[n] * inv_fact[k] * inv_fact[n - k];\n    }\n\n    mint f(int\
    \ n) const {\n        assert(n <= m);\n        if (n < 0) return 0;\n        return\
    \ fact[n];\n    }\n\n    mint inv_f(int n) const {\n        assert(n <= m);\n\
    \        if (n < 0) return 0;\n        return inv_fact[n];\n    }\n\n    mint\
    \ inv(int n) const {\n        assert(n <= m);\n        return inv_fact[n] * fact[n-1];\n\
    \    }\n\n  private:\n    int m;\n    std::vector<mint> fact, inv_fact;\n};\n\n\
    }  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: math/combination.hpp
  requiredBy: []
  timestamp: '2023-06-15 15:11:09+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/aoj_3361.test.cpp
  - test/yuki/yuki_1302.test.cpp
  - test/math/Binomial_Coefficient_Prime_Mod.test.cpp
documentation_of: math/combination.hpp
layout: document
title: Combination
---

## 説明

組み合わせを求める構造体。クエリの最大値を $N$ として、前計算 $O(N)$ クエリ $O(1)$ である。

### operator()(int n, int k)

$\binom{n}{k}$ を求める。

### f(int n)

$n!$ を求める。

### inv_f(int n)

$(n!)^{-1}$ を求める。

### inv(int n)

$n^{-1}$ を求める。