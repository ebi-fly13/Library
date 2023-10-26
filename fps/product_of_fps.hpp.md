---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: fps/sums_of_powers.hpp
    title: $\sum_i (\sum_n A_n^i) x^i$
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/polynomial/Product_of_Polynomial_Sequence.test.cpp
    title: test/polynomial/Product_of_Polynomial_Sequence.test.cpp
  - icon: ':x:'
    path: test/yuki/yuki_1145.test.cpp
    title: test/yuki/yuki_1145.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/product_of_fps.hpp\"\n\n#include <deque>\n#include <vector>\n\
    \n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#include <iostream>\n#include\
    \ <utility>\n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint = requires(T\
    \ a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n  \
    \  a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n};\n\ntemplate\
    \ <Modint mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long\
    \ long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <Modint mint>\n\
    std::ostream &operator<<(std::ostream &os, const mint &a) {\n    return os <<\
    \ a.val();\n}\n\n}  // namespace ebi\n#line 7 \"fps/product_of_fps.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <Modint mint,\n          std::vector<mint> (*convolution)(const\
    \ std::vector<mint> &,\n                                           const std::vector<mint>\
    \ &)>\nstd::vector<mint> product_of_fps(const std::vector<std::vector<mint>> &fs)\
    \ {\n    if (fs.empty()) return {1};\n    std::deque<std::vector<mint>> deque;\n\
    \    for (auto &f : fs) deque.push_back(f);\n    while (deque.size() > 1) {\n\
    \        auto f = deque.front();\n        deque.pop_front();\n        auto g =\
    \ deque.front();\n        deque.pop_front();\n        deque.push_back(convolution(f,\
    \ g));\n    }\n    return deque.front();\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <deque>\n#include <vector>\n\n#include \"../modint/base.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint,\n          std::vector<mint> (*convolution)(const\
    \ std::vector<mint> &,\n                                           const std::vector<mint>\
    \ &)>\nstd::vector<mint> product_of_fps(const std::vector<std::vector<mint>> &fs)\
    \ {\n    if (fs.empty()) return {1};\n    std::deque<std::vector<mint>> deque;\n\
    \    for (auto &f : fs) deque.push_back(f);\n    while (deque.size() > 1) {\n\
    \        auto f = deque.front();\n        deque.pop_front();\n        auto g =\
    \ deque.front();\n        deque.pop_front();\n        deque.push_back(convolution(f,\
    \ g));\n    }\n    return deque.front();\n}\n\n}  // namespace ebi"
  dependsOn:
  - modint/base.hpp
  isVerificationFile: false
  path: fps/product_of_fps.hpp
  requiredBy:
  - fps/sums_of_powers.hpp
  timestamp: '2023-10-26 11:41:06+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/polynomial/Product_of_Polynomial_Sequence.test.cpp
  - test/yuki/yuki_1145.test.cpp
documentation_of: fps/product_of_fps.hpp
layout: document
title: $\prod_{i=0}^n f_i$
---

## 説明

$\prod_{i = 0}^n f_i$ を $O(N(\log N)^2)$ で計算する。