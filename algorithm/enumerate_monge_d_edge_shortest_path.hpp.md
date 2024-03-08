---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/monotone_minima.hpp
    title: Monotone Minima
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_952.test.cpp
    title: test/yuki/yuki_952.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/enumerate_monge_d_edge_shortest_path.hpp\"\n\n\
    #include <limits>\n#include <utility>\n#include <vector>\n\n#line 2 \"algorithm/monotone_minima.hpp\"\
    \n\n#include <functional>\n#line 6 \"algorithm/monotone_minima.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <class F,\n          class T = decltype(std::declval<F>()(std::declval<int>(),\n\
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
    \    return {argmin, min_val};\n}\n\n}  // namespace ebi\n#line 8 \"algorithm/enumerate_monge_d_edge_shortest_path.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class F, class T = decltype(std::declval<F>()(std::declval<int>(),\n\
    \                                                        std::declval<int>()))>\n\
    std::vector<T> enumerate_monge_d_edge_shortest_path(int n, F f) {\n    const T\
    \ max = std::numeric_limits<T>::max();\n    std::vector<T> res(n, max);\n    std::vector<T>\
    \ dp(n, max);\n    dp[0] = 0;\n    auto g = [&](int j, int i) -> T {\n       \
    \ if (dp[i] == max || i >= j) return max;\n        return dp[i] + f(i, j);\n \
    \   };\n    for (int d = 1; d < n; d++) {\n        std::vector<int> argmin = monotone_minima(n,\
    \ n, g).first;\n        for (int i = n - 1; i >= d; i--) dp[i] = g(i, argmin[i]);\n\
    \        res[d] = dp[n - 1];\n    }\n    return res;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <limits>\n#include <utility>\n#include <vector>\n\
    \n#include \"../algorithm/monotone_minima.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class F, class T = decltype(std::declval<F>()(std::declval<int>(),\n      \
    \                                                  std::declval<int>()))>\nstd::vector<T>\
    \ enumerate_monge_d_edge_shortest_path(int n, F f) {\n    const T max = std::numeric_limits<T>::max();\n\
    \    std::vector<T> res(n, max);\n    std::vector<T> dp(n, max);\n    dp[0] =\
    \ 0;\n    auto g = [&](int j, int i) -> T {\n        if (dp[i] == max || i >=\
    \ j) return max;\n        return dp[i] + f(i, j);\n    };\n    for (int d = 1;\
    \ d < n; d++) {\n        std::vector<int> argmin = monotone_minima(n, n, g).first;\n\
    \        for (int i = n - 1; i >= d; i--) dp[i] = g(i, argmin[i]);\n        res[d]\
    \ = dp[n - 1];\n    }\n    return res;\n}\n\n}  // namespace ebi"
  dependsOn:
  - algorithm/monotone_minima.hpp
  isVerificationFile: false
  path: algorithm/enumerate_monge_d_edge_shortest_path.hpp
  requiredBy: []
  timestamp: '2023-11-08 15:46:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki/yuki_952.test.cpp
documentation_of: algorithm/enumerate_monge_d_edge_shortest_path.hpp
layout: document
title: Enumerate Monge d-edge shortest path
---

## 説明

辺の重みがMongeであるようなグラフに対して $0$ からスタートして、 $N-1$ へちょうど $d$ 辺使った場合の最短路の値を $d = 1, 2, \dots, N-1$ について求める。 $O(N^2 \log N)$