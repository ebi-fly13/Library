---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/fps_sparse.hpp
    title: Formal Power Series (Sparse)
  - icon: ':heavy_check_mark:'
    path: fps/fps_sqrt.hpp
    title: $\sqrt{f}$
  - icon: ':heavy_check_mark:'
    path: fps/product_of_one_minus_xn.hpp
    title: $\prod (1 - x^{a_i}) \mod x^d$
  - icon: ':heavy_check_mark:'
    path: fps/product_of_one_plus_xn.hpp
    title: $\prod (1 + x^{a_i}) \mod x^d$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_3361.test.cpp
    title: test/aoj/aoj_3361.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Partition_Function_FPS.test.cpp
    title: test/math/Partition_Function_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/sharp_p_subset_sum.test.cpp
    title: test/math/sharp_p_subset_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Exp_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Exp_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Log_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Log_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mod_inv.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#include <iostream>\n#include\
    \ <utility>\n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint = requires(T\
    \ a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n  \
    \  a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n};\n\ntemplate\
    \ <Modint mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long\
    \ long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <Modint mint>\n\
    std::ostream &operator<<(std::ostream &os, const mint &a) {\n    return os <<\
    \ a.val();\n}\n\n}  // namespace ebi\n#line 7 \"math/mod_inv.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <Modint mint> mint inv(int n) {\n    static const int mod\
    \ = mint::mod();\n    static std::vector<mint> dat = {0, 1};\n    assert(0 <=\
    \ n);\n    if (n >= mod) n -= mod;\n    while (int(dat.size()) <= n) {\n     \
    \   int num = dat.size();\n        int q = (mod + num - 1) / num;\n        dat.emplace_back(dat[num\
    \ * q - mod] * mint(q));\n    }\n    return dat[n];\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../modint/base.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint> mint inv(int n) {\n    static const\
    \ int mod = mint::mod();\n    static std::vector<mint> dat = {0, 1};\n    assert(0\
    \ <= n);\n    if (n >= mod) n -= mod;\n    while (int(dat.size()) <= n) {\n  \
    \      int num = dat.size();\n        int q = (mod + num - 1) / num;\n       \
    \ dat.emplace_back(dat[num * q - mod] * mint(q));\n    }\n    return dat[n];\n\
    }\n\n}  // namespace ebi"
  dependsOn:
  - modint/base.hpp
  isVerificationFile: false
  path: math/mod_inv.hpp
  requiredBy:
  - fps/fps_sparse.hpp
  - fps/product_of_one_plus_xn.hpp
  - fps/fps_sqrt.hpp
  - fps/product_of_one_minus_xn.hpp
  timestamp: '2023-10-26 11:41:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Exp_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - test/polynomial/Log_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
  - test/math/sharp_p_subset_sum.test.cpp
  - test/math/Partition_Function_FPS.test.cpp
  - test/aoj/aoj_3361.test.cpp
documentation_of: math/mod_inv.hpp
layout: document
title: Mod Inv
---

## 説明

素数 $p$ に対して、 $x^{-1} \pmod p$ を返す。線形で逆元テーブルを作成する。