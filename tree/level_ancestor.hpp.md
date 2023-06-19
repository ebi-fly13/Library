---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/Jump_on_Tree.test.cpp
    title: test/tree/Jump_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/level_ancestor_lca.test.cpp
    title: test/tree/level_ancestor_lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/level_ancestor.hpp\"\n\r\n#include <algorithm>\r\n\
    #include <cassert>\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\nstruct level_ancestor\
    \ {\r\n  private:\r\n    int n;\r\n    std::vector<int> in;\r\n    std::vector<int>\
    \ inv_in;\r\n    std::vector<int> depths;\r\n    std::vector<std::vector<int>>\
    \ s;\r\n\r\n  public:\r\n    level_ancestor(const std::vector<std::vector<int>>\
    \ &gh, int root = 0)\r\n        : n(gh.size()), in(n), inv_in(n), depths(n) {\r\
    \n        int cnt = 0;\r\n        int max = 0;\r\n        auto dfs = [&](auto\
    \ &&self, int v, int par = -1) -> void {\r\n            inv_in[cnt] = v;\r\n \
    \           in[v] = cnt++;\r\n            max = std::max(max, depths[v]);\r\n\
    \            for (auto nv : gh[v])\r\n                if (nv != par) {\r\n   \
    \                 depths[nv] = depths[v] + 1;\r\n                    self(self,\
    \ nv, v);\r\n                }\r\n        };\r\n        dfs(dfs, root);\r\n  \
    \      s.resize(max + 1);\r\n        for (int i = 0; i < n; i++) {\r\n       \
    \     int u = inv_in[i];\r\n            s[depths[u]].emplace_back(i);\r\n    \
    \    }\r\n    }\r\n\r\n    int query(int u, int k) const {\r\n        int m =\
    \ depths[u] - k;\r\n        assert(m >= 0);\r\n        return inv_in[*std::prev(\r\
    \n            std::upper_bound(s[m].begin(), s[m].end(), in[u]))];\r\n    }\r\n\
    \r\n    int depth(int u) const {\r\n        return depths[u];\r\n    }\r\n};\r\
    \n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <algorithm>\r\n#include <cassert>\r\n#include\
    \ <vector>\r\n\r\nnamespace ebi {\r\n\r\nstruct level_ancestor {\r\n  private:\r\
    \n    int n;\r\n    std::vector<int> in;\r\n    std::vector<int> inv_in;\r\n \
    \   std::vector<int> depths;\r\n    std::vector<std::vector<int>> s;\r\n\r\n \
    \ public:\r\n    level_ancestor(const std::vector<std::vector<int>> &gh, int root\
    \ = 0)\r\n        : n(gh.size()), in(n), inv_in(n), depths(n) {\r\n        int\
    \ cnt = 0;\r\n        int max = 0;\r\n        auto dfs = [&](auto &&self, int\
    \ v, int par = -1) -> void {\r\n            inv_in[cnt] = v;\r\n            in[v]\
    \ = cnt++;\r\n            max = std::max(max, depths[v]);\r\n            for (auto\
    \ nv : gh[v])\r\n                if (nv != par) {\r\n                    depths[nv]\
    \ = depths[v] + 1;\r\n                    self(self, nv, v);\r\n             \
    \   }\r\n        };\r\n        dfs(dfs, root);\r\n        s.resize(max + 1);\r\
    \n        for (int i = 0; i < n; i++) {\r\n            int u = inv_in[i];\r\n\
    \            s[depths[u]].emplace_back(i);\r\n        }\r\n    }\r\n\r\n    int\
    \ query(int u, int k) const {\r\n        int m = depths[u] - k;\r\n        assert(m\
    \ >= 0);\r\n        return inv_in[*std::prev(\r\n            std::upper_bound(s[m].begin(),\
    \ s[m].end(), in[u]))];\r\n    }\r\n\r\n    int depth(int u) const {\r\n     \
    \   return depths[u];\r\n    }\r\n};\r\n\r\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: tree/level_ancestor.hpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Jump_on_Tree.test.cpp
  - test/tree/level_ancestor_lca.test.cpp
documentation_of: tree/level_ancestor.hpp
layout: document
title: Level Ancestor
---

## 説明

根付き木のLevel Ancestorを構築 $O(N)$ / クエリ $O(\log N)$

### query(u, k)

頂点`u`の根方向に $k$ だけ上った頂点を返す。 $O(\log N)$