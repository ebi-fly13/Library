---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/Tree_Diameter.test.cpp
    title: test/tree/Tree_Diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/tree_diameter.hpp\"\n\n#include <algorithm>\n#include\
    \ <vector>\n\n#line 2 \"graph/template.hpp\"\n\r\n#line 4 \"graph/template.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class T> struct Edge {\r\n    int to;\r\
    \n    T cost;\r\n    Edge(int _to, T _cost = 1) : to(_to), cost(_cost) {}\r\n\
    };\r\n\r\ntemplate <class T> struct Graph : std::vector<std::vector<Edge<T>>>\
    \ {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\n    void add_edge(int\
    \ u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if (directed) return;\r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if (directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\n#line 7 \"tree/tree_diameter.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ T>\nstd::pair<T, std::vector<int>> tree_diameter(const Graph<T> &g) {\n    int\
    \ n = g.size();\n    std::vector<T> dp(n);\n    std::vector<int> par(n, -1);\n\
    \    dp[0] = 0;\n    auto dfs = [&](auto &&self, int v) -> void {\n        for\
    \ (const auto &[nv, cost] : g[v]) {\n            if (nv == par[v]) continue;\n\
    \            par[nv] = v;\n            dp[nv] = dp[v] + cost;\n            self(self,\
    \ nv);\n        }\n    };\n    dfs(dfs, 0);\n    int u = std::max_element(dp.begin(),\
    \ dp.end()) - dp.begin();\n    par[u] = -1;\n    dp[u] = 0;\n    dfs(dfs, u);\n\
    \    int v = std::max_element(dp.begin(), dp.end()) - dp.begin();\n    std::vector<int>\
    \ path;\n    while (u != v) {\n        path.emplace_back(v);\n        v = par[v];\n\
    \    }\n    path.emplace_back(u);\n    return {dp[*path.begin()], path};\n}\n\n\
    std::pair<int, std::vector<int>> tree_diameter(const graph &g) {\n    int n =\
    \ g.size();\n    std::vector<int> dp(n);\n    std::vector<int> par(n, -1);\n \
    \   dp[0] = 0;\n    auto dfs = [&](auto &&self, int v) -> void {\n        for\
    \ (const auto &nv : g[v]) {\n            if (nv == par[v]) continue;\n       \
    \     par[nv] = v;\n            dp[nv] = dp[v] + 1;\n            self(self, nv);\n\
    \        }\n    };\n    dfs(dfs, 0);\n    int u = std::max_element(dp.begin(),\
    \ dp.end()) - dp.begin();\n    par[u] = -1;\n    dp[u] = 0;\n    dfs(dfs, u);\n\
    \    int v = std::max_element(dp.begin(), dp.end()) - dp.begin();\n    std::vector<int>\
    \ path;\n    while (u != v) {\n        path.emplace_back(v);\n        v = par[v];\n\
    \    }\n    path.emplace_back(u);\n    return {dp[*path.begin()], path};\n}\n\n\
    }  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\n#include \"../graph/template.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T>\nstd::pair<T, std::vector<int>> tree_diameter(const\
    \ Graph<T> &g) {\n    int n = g.size();\n    std::vector<T> dp(n);\n    std::vector<int>\
    \ par(n, -1);\n    dp[0] = 0;\n    auto dfs = [&](auto &&self, int v) -> void\
    \ {\n        for (const auto &[nv, cost] : g[v]) {\n            if (nv == par[v])\
    \ continue;\n            par[nv] = v;\n            dp[nv] = dp[v] + cost;\n  \
    \          self(self, nv);\n        }\n    };\n    dfs(dfs, 0);\n    int u = std::max_element(dp.begin(),\
    \ dp.end()) - dp.begin();\n    par[u] = -1;\n    dp[u] = 0;\n    dfs(dfs, u);\n\
    \    int v = std::max_element(dp.begin(), dp.end()) - dp.begin();\n    std::vector<int>\
    \ path;\n    while (u != v) {\n        path.emplace_back(v);\n        v = par[v];\n\
    \    }\n    path.emplace_back(u);\n    return {dp[*path.begin()], path};\n}\n\n\
    std::pair<int, std::vector<int>> tree_diameter(const graph &g) {\n    int n =\
    \ g.size();\n    std::vector<int> dp(n);\n    std::vector<int> par(n, -1);\n \
    \   dp[0] = 0;\n    auto dfs = [&](auto &&self, int v) -> void {\n        for\
    \ (const auto &nv : g[v]) {\n            if (nv == par[v]) continue;\n       \
    \     par[nv] = v;\n            dp[nv] = dp[v] + 1;\n            self(self, nv);\n\
    \        }\n    };\n    dfs(dfs, 0);\n    int u = std::max_element(dp.begin(),\
    \ dp.end()) - dp.begin();\n    par[u] = -1;\n    dp[u] = 0;\n    dfs(dfs, u);\n\
    \    int v = std::max_element(dp.begin(), dp.end()) - dp.begin();\n    std::vector<int>\
    \ path;\n    while (u != v) {\n        path.emplace_back(v);\n        v = par[v];\n\
    \    }\n    path.emplace_back(u);\n    return {dp[*path.begin()], path};\n}\n\n\
    }  // namespace ebi"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: tree/tree_diameter.hpp
  requiredBy: []
  timestamp: '2023-06-19 13:52:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Tree_Diameter.test.cpp
documentation_of: tree/tree_diameter.hpp
layout: document
title: Tree Diameter
---

## 説明

木の直径とパスを求める。 $O(N)$