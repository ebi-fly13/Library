---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1857.test.cpp
    title: test/yuki/yuki_1857.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/sum_of_rational_fps.hpp\"\n\n#include <algorithm>\n\
    #include <vector>\n\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#include\
    \ <iostream>\n#include <utility>\n\nnamespace ebi {\n\ntemplate <class T>\nconcept\
    \ Modint = requires(T a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n\
    \    a.inv();\n    a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n\
    };\n\ntemplate <Modint mint> std::istream &operator>>(std::istream &os, mint &a)\
    \ {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate\
    \ <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const mint &a) {\n\
    \    return os << a.val();\n}\n\n}  // namespace ebi\n#line 7 \"fps/sum_of_rational_fps.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint,\n          std::vector<mint> (*convolution)(const\
    \ std::vector<mint> &,\n                                           const std::vector<mint>\
    \ &)>\nstd::pair<std::vector<mint>, std::vector<mint>> sum_of_rational_fps(\n\
    \    std::vector<std::pair<std::vector<mint>, std::vector<mint>>> fs) {\n    if\
    \ (fs.empty()) {\n        return {{0}, {1}};\n    }\n    using P = std::pair<std::vector<mint>,\
    \ std::vector<mint>>;\n    auto add = [&](const P &a, const P &b) -> P {\n   \
    \     int na = a.first.size() - 1, ma = a.second.size() - 1;\n        int nb =\
    \ b.first.size() - 1, mb = b.second.size() - 1;\n        int n = std::max(na +\
    \ mb, nb + ma);\n        std::vector<mint> p(n + 1, 0);\n        {\n         \
    \   auto f = convolution(a.first, b.second);\n            for (int i = 0; i <\
    \ na + mb + 1; i++) {\n                p[i] += f[i];\n            }\n        }\n\
    \        {\n            auto f = convolution(a.second, b.first);\n           \
    \ for (int i = 0; i < nb + ma + 1; i++) {\n                p[i] += f[i];\n   \
    \         }\n        }\n        return {p, convolution(a.second, b.second)};\n\
    \    };\n    int i = 0;\n    while (i + 1 < (int)fs.size()) {\n        fs.emplace_back(add(fs[i],\
    \ fs[i + 1]));\n        i += 2;\n    }\n    return fs.back();\n}\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\n#include \"../modint/base.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint,\n          std::vector<mint> (*convolution)(const\
    \ std::vector<mint> &,\n                                           const std::vector<mint>\
    \ &)>\nstd::pair<std::vector<mint>, std::vector<mint>> sum_of_rational_fps(\n\
    \    std::vector<std::pair<std::vector<mint>, std::vector<mint>>> fs) {\n    if\
    \ (fs.empty()) {\n        return {{0}, {1}};\n    }\n    using P = std::pair<std::vector<mint>,\
    \ std::vector<mint>>;\n    auto add = [&](const P &a, const P &b) -> P {\n   \
    \     int na = a.first.size() - 1, ma = a.second.size() - 1;\n        int nb =\
    \ b.first.size() - 1, mb = b.second.size() - 1;\n        int n = std::max(na +\
    \ mb, nb + ma);\n        std::vector<mint> p(n + 1, 0);\n        {\n         \
    \   auto f = convolution(a.first, b.second);\n            for (int i = 0; i <\
    \ na + mb + 1; i++) {\n                p[i] += f[i];\n            }\n        }\n\
    \        {\n            auto f = convolution(a.second, b.first);\n           \
    \ for (int i = 0; i < nb + ma + 1; i++) {\n                p[i] += f[i];\n   \
    \         }\n        }\n        return {p, convolution(a.second, b.second)};\n\
    \    };\n    int i = 0;\n    while (i + 1 < (int)fs.size()) {\n        fs.emplace_back(add(fs[i],\
    \ fs[i + 1]));\n        i += 2;\n    }\n    return fs.back();\n}\n\n}  // namespace\
    \ ebi"
  dependsOn:
  - modint/base.hpp
  isVerificationFile: false
  path: fps/sum_of_rational_fps.hpp
  requiredBy: []
  timestamp: '2024-05-11 20:19:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki/yuki_1857.test.cpp
documentation_of: fps/sum_of_rational_fps.hpp
layout: document
title: $\sum \frac{f_i}{g_i}$
---

## 説明

$\sum_{i = 0}^{n-1} \frac{f_i}{g_i}$ を $O(N(\log N)^2)$ で計算する。