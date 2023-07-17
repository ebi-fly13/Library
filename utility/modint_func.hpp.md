---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/fps_sparse.hpp
    title: Formal Power Series (Sparse)
  - icon: ':heavy_check_mark:'
    path: fps/fps_sqrt.hpp
    title: $\sqrt{f}$
  - icon: ':warning:'
    path: fps/product_of_one_minus_xn.hpp
    title: $\prod (1 - x^{a_i}) \mod x^d$
  - icon: ':warning:'
    path: fps/product_of_one_plus_xn.hpp
    title: $\prod (1 + x^{a_i}) \mod x^d$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_3361.test.cpp
    title: test/aoj/aoj_3361.test.cpp
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
  bundledCode: "#line 2 \"utility/modint_func.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n\nnamespace ebi {\n\ntemplate <class mint> mint inv(int n) {\n  \
    \  static const int mod = mint::mod();\n    static std::vector<mint> dat = {0,\
    \ 1};\n    assert(0 <= n);\n    if (n >= mod) n -= mod;\n    while (int(dat.size())\
    \ <= n) {\n        int num = dat.size();\n        int q = (mod + num - 1) / num;\n\
    \        dat.emplace_back(dat[num * q - mod] * mint(q));\n    }\n    return dat[n];\n\
    }\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\nnamespace ebi {\n\
    \ntemplate <class mint> mint inv(int n) {\n    static const int mod = mint::mod();\n\
    \    static std::vector<mint> dat = {0, 1};\n    assert(0 <= n);\n    if (n >=\
    \ mod) n -= mod;\n    while (int(dat.size()) <= n) {\n        int num = dat.size();\n\
    \        int q = (mod + num - 1) / num;\n        dat.emplace_back(dat[num * q\
    \ - mod] * mint(q));\n    }\n    return dat[n];\n}\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: utility/modint_func.hpp
  requiredBy:
  - fps/product_of_one_plus_xn.hpp
  - fps/fps_sparse.hpp
  - fps/product_of_one_minus_xn.hpp
  - fps/fps_sqrt.hpp
  timestamp: '2023-06-08 01:58:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_3361.test.cpp
  - test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - test/polynomial/Exp_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Log_of_Formal_Power_Series_Sparse.test.cpp
documentation_of: utility/modint_func.hpp
layout: document
redirect_from:
- /library/utility/modint_func.hpp
- /library/utility/modint_func.hpp.html
title: utility/modint_func.hpp
---
