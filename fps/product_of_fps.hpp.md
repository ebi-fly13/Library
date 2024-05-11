---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/sums_of_powers.hpp
    title: "$\\sum_n A_n^i$ \u306E $i = 0, 1,\\dots, k$ \u306E\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: math/sums_of_powers_iota.hpp
    title: "$\\sum_{i = 0}^{n-1} i^k$ \u306E $k$ \u306B\u95A2\u3059\u308B\u5217\u6319"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Powers_Iota.test.cpp
    title: test/math/Sum_of_Powers_Iota.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Product_of_Polynomial_Sequence.test.cpp
    title: test/polynomial/Product_of_Polynomial_Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1145.test.cpp
    title: test/yuki/yuki_1145.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1857.test.cpp
    title: test/yuki/yuki_1857.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/product_of_fps.hpp\"\n\n#include <vector>\n\n#line 2\
    \ \"modint/base.hpp\"\n\n#include <concepts>\n#include <iostream>\n#include <utility>\n\
    \nnamespace ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n\
    \    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n\
    \    a.pow(std::declval<long long>());\n    T::mod();\n};\n\ntemplate <Modint\
    \ mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long long x;\n\
    \    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <Modint mint>\nstd::ostream\
    \ &operator<<(std::ostream &os, const mint &a) {\n    return os << a.val();\n\
    }\n\n}  // namespace ebi\n#line 6 \"fps/product_of_fps.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <Modint mint,\n          std::vector<mint> (*convolution)(const\
    \ std::vector<mint> &,\n                                           const std::vector<mint>\
    \ &)>\nstd::vector<mint> product_of_fps(std::vector<std::vector<mint>> fs) {\n\
    \    if (fs.empty()) return {1};\n    int i = 0;\n    while (i + 1 < (int)fs.size())\
    \ {\n        fs.emplace_back(convolution(fs[i], fs[i+1]));\n        i += 2;\n\
    \    }\n    return fs.back();\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <vector>\n\n#include \"../modint/base.hpp\"\n\n\
    namespace ebi {\n\ntemplate <Modint mint,\n          std::vector<mint> (*convolution)(const\
    \ std::vector<mint> &,\n                                           const std::vector<mint>\
    \ &)>\nstd::vector<mint> product_of_fps(std::vector<std::vector<mint>> fs) {\n\
    \    if (fs.empty()) return {1};\n    int i = 0;\n    while (i + 1 < (int)fs.size())\
    \ {\n        fs.emplace_back(convolution(fs[i], fs[i+1]));\n        i += 2;\n\
    \    }\n    return fs.back();\n}\n\n}  // namespace ebi"
  dependsOn:
  - modint/base.hpp
  isVerificationFile: false
  path: fps/product_of_fps.hpp
  requiredBy:
  - math/sums_of_powers.hpp
  - math/sums_of_powers_iota.hpp
  timestamp: '2024-05-11 20:19:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki/yuki_1857.test.cpp
  - test/yuki/yuki_1145.test.cpp
  - test/math/Sum_of_Powers_Iota.test.cpp
  - test/polynomial/Product_of_Polynomial_Sequence.test.cpp
documentation_of: fps/product_of_fps.hpp
layout: document
title: $\prod f_i$
---

## 説明

$\prod_{i = 0}^{n-1} f_i$ を $O(N(\log N)^2)$ で計算する。