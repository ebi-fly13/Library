---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/biconnected_components.hpp
    title: graph/biconnected_components.hpp
  - icon: ':heavy_check_mark:'
    path: graph/two_edge_connected_components.hpp
    title: Two Edge Connected Components
  - icon: ':heavy_check_mark:'
    path: tree/block_cut_tree.hpp
    title: Block Cut Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Articulation_Points.test.cpp
    title: test/graph/Articulation_Points.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Biconnected_Components.test.cpp
    title: test/graph/Biconnected_Components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Two_Edge_Connected_Components.test.cpp
    title: test/graph/Two_Edge_Connected_Components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/low_link.hpp\"\n\n#include <algorithm>\n#include <utility>\n\
    #include <vector>\n\nnamespace ebi {\n\nstruct low_link {\n  private:\n    void\
    \ dfs(int v, int par = -1) {\n        static int k = 0;\n        low[v] = ord[v]\
    \ = k++;\n        int cnt = 0;\n        bool is_arti = false, is_second = false;\n\
    \        for (auto nv : g[v]) {\n            if (ord[nv] == -1) {\n          \
    \      cnt++;\n                dfs(nv, v);\n                low[v] = std::min(low[v],\
    \ low[nv]);\n                is_arti |= (par != -1) && (low[nv] >= ord[v]);\n\
    \                if (ord[v] < low[nv]) {\n                    _bridge.emplace_back(std::minmax(v,\
    \ nv));\n                }\n            } else if (nv != par || is_second) {\n\
    \                low[v] = std::min(low[v], ord[nv]);\n            } else {\n \
    \               is_second = true;\n            }\n        }\n        is_arti |=\
    \ par == -1 && cnt > 1;\n        if (is_arti) _articulation.emplace_back(v);\n\
    \    }\n\n  public:\n    low_link(const std::vector<std::vector<int>> &g)\n  \
    \      : n(g.size()), g(g), ord(n, -1), low(n) {\n        for (int i = 0; i <\
    \ n; i++) {\n            if (ord[i] == -1) dfs(i);\n        }\n    }\n\n    std::vector<int>\
    \ articulation() const {\n        return _articulation;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> bridge() const {\n        return _bridge;\n    }\n\n  protected:\n   \
    \ int n;\n    std::vector<std::vector<int>> g;\n    std::vector<int> ord, low,\
    \ _articulation;\n    std::vector<std::pair<int, int>> _bridge;\n};\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    \nnamespace ebi {\n\nstruct low_link {\n  private:\n    void dfs(int v, int par\
    \ = -1) {\n        static int k = 0;\n        low[v] = ord[v] = k++;\n       \
    \ int cnt = 0;\n        bool is_arti = false, is_second = false;\n        for\
    \ (auto nv : g[v]) {\n            if (ord[nv] == -1) {\n                cnt++;\n\
    \                dfs(nv, v);\n                low[v] = std::min(low[v], low[nv]);\n\
    \                is_arti |= (par != -1) && (low[nv] >= ord[v]);\n            \
    \    if (ord[v] < low[nv]) {\n                    _bridge.emplace_back(std::minmax(v,\
    \ nv));\n                }\n            } else if (nv != par || is_second) {\n\
    \                low[v] = std::min(low[v], ord[nv]);\n            } else {\n \
    \               is_second = true;\n            }\n        }\n        is_arti |=\
    \ par == -1 && cnt > 1;\n        if (is_arti) _articulation.emplace_back(v);\n\
    \    }\n\n  public:\n    low_link(const std::vector<std::vector<int>> &g)\n  \
    \      : n(g.size()), g(g), ord(n, -1), low(n) {\n        for (int i = 0; i <\
    \ n; i++) {\n            if (ord[i] == -1) dfs(i);\n        }\n    }\n\n    std::vector<int>\
    \ articulation() const {\n        return _articulation;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> bridge() const {\n        return _bridge;\n    }\n\n  protected:\n   \
    \ int n;\n    std::vector<std::vector<int>> g;\n    std::vector<int> ord, low,\
    \ _articulation;\n    std::vector<std::pair<int, int>> _bridge;\n};\n\n}  // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: graph/low_link.hpp
  requiredBy:
  - tree/block_cut_tree.hpp
  - graph/two_edge_connected_components.hpp
  - graph/biconnected_components.hpp
  timestamp: '2023-07-10 11:25:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Two_Edge_Connected_Components.test.cpp
  - test/graph/Articulation_Points.test.cpp
  - test/graph/Biconnected_Components.test.cpp
documentation_of: graph/low_link.hpp
layout: document
title: Low Link
---

## 説明

与えたグラフに対して、Low Linkを計算し間節点と橋を求める。 $O(N)$