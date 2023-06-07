---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/fps_sparse.hpp
    title: Formal Power Series (Sparse)
  - icon: ':warning:'
    path: fps/product_of_one_minus_xn.hpp
    title: $\prod (1 - x^{a_i}) \mod x^d$
  - icon: ':warning:'
    path: fps/product_of_one_plus_xn.hpp
    title: $\prod (1 + x^{a_i}) \mod x^d$
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  timestamp: '2023-06-08 01:58:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/modint_func.hpp
layout: document
title: modint function
---

## 説明

`modint`の便利関数寄せ集め。