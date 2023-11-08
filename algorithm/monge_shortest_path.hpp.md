---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/monge_d_edge_shortest_path.hpp
    title: Monge d-edge shortest path
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_3086.test.cpp
    title: test/aoj/aoj_3086.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/monge_shortest_path.hpp\"\n\n#include <limits>\n\
    #include <vector>\n\nnamespace ebi {\n\ntemplate <class F, class T = decltype(std::declval<F>()(std::declval<int>(),\n\
    \                                                        std::declval<int>()))>\n\
    std::vector<T> monge_shortest_path(int n, F f) {\n    const T max = std::numeric_limits<T>::max();\n\
    \    std::vector<int> argmin(n, 0);\n    std::vector<T> dp(n, max);\n    dp[0]\
    \ = 0;\n    auto get = [&](int i, int j) -> T {\n        T val = f(j, i);\n  \
    \      if (val == max || dp[j] == max) return max;\n        return dp[j] + val;\n\
    \    };\n    auto check = [&](int i, int j) -> void {\n        T val = get(i,\
    \ j);\n        if (val < dp[i]) {\n            dp[i] = val;\n            argmin[i]\
    \ = j;\n        }\n    };\n    dp[n - 1] = get(n - 1, 0);\n    auto dfs = [&](auto\
    \ &&self, int l, int r) -> void {\n        if (r - l == 1) return;\n        int\
    \ m = (l + r) >> 1;\n        for (int i = argmin[l]; i <= argmin[r]; i++) {\n\
    \            check(m, i);\n        }\n        self(self, l, m);\n        for (int\
    \ i = l + 1; i <= m; i++) {\n            check(r, i);\n        }\n        self(self,\
    \ m, r);\n    };\n    dfs(dfs, 0, n - 1);\n    return dp;\n}\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <limits>\n#include <vector>\n\nnamespace ebi {\n\
    \ntemplate <class F, class T = decltype(std::declval<F>()(std::declval<int>(),\n\
    \                                                        std::declval<int>()))>\n\
    std::vector<T> monge_shortest_path(int n, F f) {\n    const T max = std::numeric_limits<T>::max();\n\
    \    std::vector<int> argmin(n, 0);\n    std::vector<T> dp(n, max);\n    dp[0]\
    \ = 0;\n    auto get = [&](int i, int j) -> T {\n        T val = f(j, i);\n  \
    \      if (val == max || dp[j] == max) return max;\n        return dp[j] + val;\n\
    \    };\n    auto check = [&](int i, int j) -> void {\n        T val = get(i,\
    \ j);\n        if (val < dp[i]) {\n            dp[i] = val;\n            argmin[i]\
    \ = j;\n        }\n    };\n    dp[n - 1] = get(n - 1, 0);\n    auto dfs = [&](auto\
    \ &&self, int l, int r) -> void {\n        if (r - l == 1) return;\n        int\
    \ m = (l + r) >> 1;\n        for (int i = argmin[l]; i <= argmin[r]; i++) {\n\
    \            check(m, i);\n        }\n        self(self, l, m);\n        for (int\
    \ i = l + 1; i <= m; i++) {\n            check(r, i);\n        }\n        self(self,\
    \ m, r);\n    };\n    dfs(dfs, 0, n - 1);\n    return dp;\n}\n\n}  // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/monge_shortest_path.hpp
  requiredBy:
  - algorithm/monge_d_edge_shortest_path.hpp
  timestamp: '2023-11-08 11:18:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_3086.test.cpp
documentation_of: algorithm/monge_shortest_path.hpp
layout: document
title: Monge shortest path
---

## 説明

辺の重みがMongeであるようなグラフに対して $0$ からスタートして、 $v = 0, 1, \dots, N-1$ への最短路の値を求める。 $O(N\log N)$

詳細は [このブログ](https://noshi91.hatenablog.com/entry/2023/02/18/005856) にある。