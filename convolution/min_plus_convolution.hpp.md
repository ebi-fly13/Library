---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/monotone_minima.hpp
    title: Monotone Minima
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/Min_Plus_Convolution_Convex_and_Arbitary.test.cpp
    title: test/convolution/Min_Plus_Convolution_Convex_and_Arbitary.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/min_plus_convolution.hpp\"\n\n#include <cassert>\n\
    #include <limits>\n#include <vector>\n\n#line 2 \"algorithm/monotone_minima.hpp\"\
    \n\n#include <functional>\n#include <utility>\n#line 6 \"algorithm/monotone_minima.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class F,\n          class T = decltype(std::declval<F>()(std::declval<int>(),\n\
    \                                               std::declval<int>())),\n     \
    \     class Compare = std::less<T>>\nstd::pair<std::vector<int>, std::vector<T>>\
    \ monotone_minima(\n    int n, int m, F f, const Compare &compare = Compare())\
    \ {\n    std::vector<int> argmin(n);\n    std::vector<T> min_val(n);\n    auto\
    \ dfs = [&](auto &&self, int top, int bottom, int left,\n                   int\
    \ right) -> void {\n        if (top > bottom) return;\n        int mid = (top\
    \ + bottom) >> 1;\n        argmin[mid] = left;\n        min_val[mid] = f(mid,\
    \ left);\n        for (int i = left + 1; i <= right; i++) {\n            T val\
    \ = f(mid, i);\n            if (min_val[mid] == val || compare(val, min_val[mid]))\
    \ {\n                argmin[mid] = i;\n                min_val[mid] = val;\n \
    \           }\n        }\n        self(self, top, mid - 1, left, argmin[mid]);\n\
    \        self(self, mid + 1, bottom, argmin[mid], right);\n    };\n    dfs(dfs,\
    \ 0, n - 1, 0, m - 1);\n    return {argmin, min_val};\n}\n\ntemplate <class T,\
    \ class F, class Compare = std::less<T>>\nstd::pair<std::vector<int>, std::vector<T>>\
    \ slide_monotone_minima(\n    int n, int m, F f, const Compare &compare = Compare())\
    \ {\n    std::vector<int> argmin(n);\n    std::vector<T> min_val(n);\n    auto\
    \ dfs = [&](auto &&self, int top, int bottom, int left, int right,\n         \
    \          int depth) -> void {\n        if (top > bottom) return;\n        int\
    \ mid = (top + bottom) >> 1;\n        argmin[mid] = left;\n        min_val[mid]\
    \ = f(mid, left, depth);\n        for (int i = left + 1; i <= right; i++) {\n\
    \            T val = f(mid, i, depth);\n            if (min_val[mid] == val ||\
    \ compare(val, min_val[mid])) {\n                argmin[mid] = i;\n          \
    \      min_val[mid] = val;\n            }\n        }\n        self(self, top,\
    \ mid - 1, left, argmin[mid], depth + 1);\n        self(self, mid + 1, bottom,\
    \ argmin[mid], right, depth + 1);\n    };\n    dfs(dfs, 0, n - 1, 0, m - 1, 0);\n\
    \    return {argmin, min_val};\n}\n\n}  // namespace ebi\n#line 8 \"convolution/min_plus_convolution.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T>\nstd::vector<T> min_plus_convolution_convex_and_arbitary(\n\
    \    const std::vector<T> &a, const std::vector<T> &b) {\n    int n = (int)a.size();\n\
    \    int m = (int)b.size();\n    for (int i = 0; i < n - 2; i++) {\n        assert(a[i\
    \ + 1] - a[i] <= a[i + 2] - a[i + 1]);\n    }\n    auto f = [&](int i, int j)\
    \ -> T {\n        if (i - j < 0 || i - j >= n) return std::numeric_limits<T>::max();\n\
    \        return a[i - j] + b[j];\n    };\n    auto [argmin, min_val] = monotone_minima(n\
    \ + m - 1, m, f);\n    return min_val;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <limits>\n#include <vector>\n\
    \n#include \"../algorithm/monotone_minima.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class T>\nstd::vector<T> min_plus_convolution_convex_and_arbitary(\n    const\
    \ std::vector<T> &a, const std::vector<T> &b) {\n    int n = (int)a.size();\n\
    \    int m = (int)b.size();\n    for (int i = 0; i < n - 2; i++) {\n        assert(a[i\
    \ + 1] - a[i] <= a[i + 2] - a[i + 1]);\n    }\n    auto f = [&](int i, int j)\
    \ -> T {\n        if (i - j < 0 || i - j >= n) return std::numeric_limits<T>::max();\n\
    \        return a[i - j] + b[j];\n    };\n    auto [argmin, min_val] = monotone_minima(n\
    \ + m - 1, m, f);\n    return min_val;\n}\n\n}  // namespace ebi"
  dependsOn:
  - algorithm/monotone_minima.hpp
  isVerificationFile: false
  path: convolution/min_plus_convolution.hpp
  requiredBy: []
  timestamp: '2023-11-08 11:18:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/Min_Plus_Convolution_Convex_and_Arbitary.test.cpp
documentation_of: convolution/min_plus_convolution.hpp
layout: document
title: Min Plus Convolution
---

## 説明

長さ$N$ の凸な整数列 $a$ と 長さ $M$ の整数列 $b$ について、 $c_k = \min_{i + j = k} (a_i + b_j)$ となる長さ $N+M-1$ の整数列を求める。 $O(N + M\log N)$

ここで、凸な数列とは $0 \leq i < N-2$ に対して $a_{i + 1} - a_i \leq a_{i + 2} - a_{i + 1}$ が成り立つことをいう。