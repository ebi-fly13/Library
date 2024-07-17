---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/sum_of_exp_times_poly.hpp
    title: $\sum_{i = 0}^{n-1} a^i f(i)$
  - icon: ':heavy_check_mark:'
    path: math/sum_of_powers_iota.hpp
    title: $\sum_{i = 0}^{n-1} i^k$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Exponential_Times_Polynomial.test.cpp
    title: test/math/Sum_of_Exponential_Times_Polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Exponential_Times_Polynomial_Limit.test.cpp
    title: test/math/Sum_of_Exponential_Times_Polynomial_Limit.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Powers_Iota.test.cpp
    title: test/math/Sum_of_Powers_Iota.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_2747.test.cpp
    title: test/yuki/yuki_2747.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc208/editorial/2195
    - https://atcoder.jp/contests/abc208/tasks/abc208_f
  bundledCode: "#line 2 \"math/lagrange_interpolation.hpp\"\n\n#include <vector>\n\
    \n/*\n    reference: https://atcoder.jp/contests/abc208/editorial/2195\n    verify:\
    \ https://atcoder.jp/contests/abc208/tasks/abc208_f\n*/\n\nnamespace ebi {\n\n\
    template <class mint>\nmint lagrange_interpolation(const std::vector<mint> &f,\
    \ long long n) {\n    const int d = int(f.size()) - 1;  // N\u306Ed\u6B21\u4EE5\
    \u4E0B\u306E\u591A\u9805\u5F0F\n    mint fact = 1;\n    std::vector<mint> inv_fact(d\
    \ + 1);\n    for (int i = 1; i < d + 1; ++i) {\n        fact *= i;\n    }\n  \
    \  inv_fact[d] = fact.inv();\n    for (int i = d; i > 0; i--) {\n        inv_fact[i\
    \ - 1] = inv_fact[i] * i;\n    }\n    std::vector<mint> l(d + 1), r(d + 1);\n\
    \    l[0] = 1;\n    for (int i = 0; i < d; ++i) {\n        l[i + 1] = l[i] * (n\
    \ - i);\n    }\n    r[d] = 1;\n    for (int i = d; i > 0; --i) {\n        r[i\
    \ - 1] = r[i] * (n - i);\n    }\n    mint res = 0;\n    for (int i = 0; i < d\
    \ + 1; ++i) {\n        res += mint((d - i) % 2 == 1 ? -1 : 1) * f[i] * l[i] *\
    \ r[i] *\n               inv_fact[i] * inv_fact[d - i];\n    }\n    return res;\n\
    }\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <vector>\n\n/*\n    reference: https://atcoder.jp/contests/abc208/editorial/2195\n\
    \    verify: https://atcoder.jp/contests/abc208/tasks/abc208_f\n*/\n\nnamespace\
    \ ebi {\n\ntemplate <class mint>\nmint lagrange_interpolation(const std::vector<mint>\
    \ &f, long long n) {\n    const int d = int(f.size()) - 1;  // N\u306Ed\u6B21\u4EE5\
    \u4E0B\u306E\u591A\u9805\u5F0F\n    mint fact = 1;\n    std::vector<mint> inv_fact(d\
    \ + 1);\n    for (int i = 1; i < d + 1; ++i) {\n        fact *= i;\n    }\n  \
    \  inv_fact[d] = fact.inv();\n    for (int i = d; i > 0; i--) {\n        inv_fact[i\
    \ - 1] = inv_fact[i] * i;\n    }\n    std::vector<mint> l(d + 1), r(d + 1);\n\
    \    l[0] = 1;\n    for (int i = 0; i < d; ++i) {\n        l[i + 1] = l[i] * (n\
    \ - i);\n    }\n    r[d] = 1;\n    for (int i = d; i > 0; --i) {\n        r[i\
    \ - 1] = r[i] * (n - i);\n    }\n    mint res = 0;\n    for (int i = 0; i < d\
    \ + 1; ++i) {\n        res += mint((d - i) % 2 == 1 ? -1 : 1) * f[i] * l[i] *\
    \ r[i] *\n               inv_fact[i] * inv_fact[d - i];\n    }\n    return res;\n\
    }\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: math/lagrange_interpolation.hpp
  requiredBy:
  - math/sum_of_exp_times_poly.hpp
  - math/sum_of_powers_iota.hpp
  timestamp: '2023-10-26 02:38:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki/yuki_2747.test.cpp
  - test/math/Sum_of_Exponential_Times_Polynomial_Limit.test.cpp
  - test/math/Sum_of_Exponential_Times_Polynomial.test.cpp
  - test/math/Sum_of_Powers_Iota.test.cpp
documentation_of: math/lagrange_interpolation.hpp
layout: document
title: Lagrange Interpolation
---

## 説明

$d$ 次多項式 $f$ について $f(0), f(1), \dots, f(d)$ の $d+1$ 点の値を与え、 $f(n)$ の値を求める。 $O(d)$