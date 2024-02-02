---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/enumerate_monge_d_edge_shortest_path.hpp
    title: Enumerate Monge d-edge shortest path
  - icon: ':heavy_check_mark:'
    path: convolution/min_plus_convolution.hpp
    title: Min Plus Convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/Min_Plus_Convolution_Convex_and_Arbitary.test.cpp
    title: test/convolution/Min_Plus_Convolution_Convex_and_Arbitary.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_952.test.cpp
    title: test/yuki/yuki_952.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/monotone_minima.hpp\"\n\n#include <functional>\n\
    #include <utility>\n#include <vector>\n\nnamespace ebi {\n\ntemplate <class F,\n\
    \          class T = decltype(std::declval<F>()(std::declval<int>(),\n       \
    \                                        std::declval<int>())),\n          class\
    \ Compare = std::less<T>>\nstd::pair<std::vector<int>, std::vector<T>> monotone_minima(\n\
    \    int n, int m, F f, const Compare &compare = Compare()) {\n    std::vector<int>\
    \ argmin(n);\n    std::vector<T> min_val(n);\n    auto dfs = [&](auto &&self,\
    \ int top, int bottom, int left,\n                   int right) -> void {\n  \
    \      if (top > bottom) return;\n        int mid = (top + bottom) >> 1;\n   \
    \     argmin[mid] = left;\n        min_val[mid] = f(mid, left);\n        for (int\
    \ i = left + 1; i <= right; i++) {\n            T val = f(mid, i);\n         \
    \   if (min_val[mid] == val || compare(val, min_val[mid])) {\n               \
    \ argmin[mid] = i;\n                min_val[mid] = val;\n            }\n     \
    \   }\n        self(self, top, mid - 1, left, argmin[mid]);\n        self(self,\
    \ mid + 1, bottom, argmin[mid], right);\n    };\n    dfs(dfs, 0, n - 1, 0, m -\
    \ 1);\n    return {argmin, min_val};\n}\n\ntemplate <class T, class F, class Compare\
    \ = std::less<T>>\nstd::pair<std::vector<int>, std::vector<T>> slide_monotone_minima(\n\
    \    int n, int m, F f, const Compare &compare = Compare()) {\n    std::vector<int>\
    \ argmin(n);\n    std::vector<T> min_val(n);\n    auto dfs = [&](auto &&self,\
    \ int top, int bottom, int left, int right,\n                   int depth) ->\
    \ void {\n        if (top > bottom) return;\n        int mid = (top + bottom)\
    \ >> 1;\n        argmin[mid] = left;\n        min_val[mid] = f(mid, left, depth);\n\
    \        for (int i = left + 1; i <= right; i++) {\n            T val = f(mid,\
    \ i, depth);\n            if (min_val[mid] == val || compare(val, min_val[mid]))\
    \ {\n                argmin[mid] = i;\n                min_val[mid] = val;\n \
    \           }\n        }\n        self(self, top, mid - 1, left, argmin[mid],\
    \ depth + 1);\n        self(self, mid + 1, bottom, argmin[mid], right, depth +\
    \ 1);\n    };\n    dfs(dfs, 0, n - 1, 0, m - 1, 0);\n    return {argmin, min_val};\n\
    }\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <functional>\n#include <utility>\n#include <vector>\n\
    \nnamespace ebi {\n\ntemplate <class F,\n          class T = decltype(std::declval<F>()(std::declval<int>(),\n\
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
    \    return {argmin, min_val};\n}\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/monotone_minima.hpp
  requiredBy:
  - algorithm/enumerate_monge_d_edge_shortest_path.hpp
  - convolution/min_plus_convolution.hpp
  timestamp: '2023-11-08 11:18:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/Min_Plus_Convolution_Convex_and_Arbitary.test.cpp
  - test/yuki/yuki_952.test.cpp
documentation_of: algorithm/monotone_minima.hpp
layout: document
title: Monotone Minima
---

## 説明

Monotoneな行列の各行の行最小値を求める。 $O(N + M\log N)$

### monotone_minima(n, m, f, compare)

$n \times m$ の行列に対してmonotone minimaを行う。 $f(i, j)$ は行列の $(i, j)$ 成分を返す。また、`compare`は比較関数を与える。デフォルトはminである。

### slide_monotone_minima(n, m, f, compare)

$n \times m$ の行列に対してmonotone minimaを行う。 $f(i, j, depth)$ は行列の $(i, j)$ 成分を返す。ここで、再帰の深さ毎にカーソルを持つことでスライドでの行列成分のアクセスを可能にする。また、`compare`は比較関数を与える。デフォルトはminである。