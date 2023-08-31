---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/sums_of_powers.hpp
    title: $\sum_i (\sum_n A_n^i) x^i$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Product_of_Polynomial_Sequence.test.cpp
    title: test/polynomial/Product_of_Polynomial_Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1145.test.cpp
    title: test/yuki/yuki_1145.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/product_of_fps.hpp\"\n\n#include <deque>\n#include <vector>\n\
    \nnamespace ebi {\n\ntemplate <class mint, std::vector<mint> (*convolution)(\n\
    \                          const std::vector<mint> &, const std::vector<mint>\
    \ &)>\nstd::vector<mint> product_of_fps(const std::vector<std::vector<mint>> &fs)\
    \ {\n    if (fs.empty()) return {1};\n    std::deque<std::vector<mint>> deque;\n\
    \    for (auto &f : fs) deque.push_back(f);\n    while (deque.size() > 1) {\n\
    \        auto f = deque.front();\n        deque.pop_front();\n        auto g =\
    \ deque.front();\n        deque.pop_front();\n        deque.push_back(convolution(f,\
    \ g));\n    }\n    return deque.front();\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <deque>\n#include <vector>\n\nnamespace ebi {\n\n\
    template <class mint, std::vector<mint> (*convolution)(\n                    \
    \      const std::vector<mint> &, const std::vector<mint> &)>\nstd::vector<mint>\
    \ product_of_fps(const std::vector<std::vector<mint>> &fs) {\n    if (fs.empty())\
    \ return {1};\n    std::deque<std::vector<mint>> deque;\n    for (auto &f : fs)\
    \ deque.push_back(f);\n    while (deque.size() > 1) {\n        auto f = deque.front();\n\
    \        deque.pop_front();\n        auto g = deque.front();\n        deque.pop_front();\n\
    \        deque.push_back(convolution(f, g));\n    }\n    return deque.front();\n\
    }\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: fps/product_of_fps.hpp
  requiredBy:
  - fps/sums_of_powers.hpp
  timestamp: '2023-06-15 03:20:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/polynomial/Product_of_Polynomial_Sequence.test.cpp
  - test/yuki/yuki_1145.test.cpp
documentation_of: fps/product_of_fps.hpp
layout: document
title: $\prod_{i=0}^n f_i$
---

## 説明

$\prod_{i = 0}^n f_i$ を $O(N(\log N)^2)$ で計算する。