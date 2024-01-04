---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/Frequency_Table_of_Tree_Distance_Old.test.cpp
    title: test/tree/Frequency_Table_of_Tree_Distance_Old.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://ferin-tech.hatenablog.com/entry/2020/03/06/162311
    - https://qiita.com/drken/items/4b4c3f1824339b090202
  bundledCode: "#line 2 \"tree/centroid_decomposition_old.hpp\"\n\r\n#include <vector>\r\
    \n\r\n/*\r\n    reference: https://qiita.com/drken/items/4b4c3f1824339b090202\r\
    \n               https://ferin-tech.hatenablog.com/entry/2020/03/06/162311\r\n\
    */\r\n\r\nnamespace ebi {\r\n\r\nstruct centroid_decomposition {\r\n  private:\r\
    \n    int find_centroid(int _root) {\r\n        auto get_size = [&](auto &&self,\
    \ int v, int p = -1) -> int {\r\n            sz[v] = 1;\r\n            for (auto\
    \ nv : g[v])\r\n                if (nv != p && !dead[nv]) {\r\n              \
    \      sz[v] += self(self, nv, v);\r\n                }\r\n            return\
    \ sz[v];\r\n        };\r\n        get_size(get_size, _root);\r\n        auto dfs_centroid\
    \ = [&](auto &&self, int v, int p = -1) -> int {\r\n            for (auto nv :\
    \ g[v])\r\n                if (nv != p && !dead[nv]) {\r\n                   \
    \ if (sz[nv] > sz[_root] / 2) return self(self, nv, v);\r\n                }\r\
    \n            return v;\r\n        };\r\n        return dfs_centroid(dfs_centroid,\
    \ _root);\r\n    }\r\n\r\n    int build(int v = 0, int depth = 0) {\r\n      \
    \  int c = find_centroid(v);\r\n        dead[c] = true;\r\n        for (auto nv\
    \ : g[c])\r\n            if (!dead[nv]) {\r\n                int ch = build(nv,\
    \ depth + 1);\r\n                belong[c].emplace_back(ch);\r\n             \
    \   par[ch] = c;\r\n            }\r\n        dead[c] = false;\r\n        return\
    \ root = c;\r\n    }\r\n\r\n  public:\r\n    centroid_decomposition(const std::vector<std::vector<int>>\
    \ &_g)\r\n        : n(int(_g.size())),\r\n          g(_g),\r\n          dead(n,\
    \ false),\r\n          sz(n, -1),\r\n          par(n, -1),\r\n          belong(n)\
    \ {\r\n        build();\r\n    }\r\n\r\n    std::pair<int, std::vector<std::vector<int>>>\r\
    \n    get_centroid_decomposition_tree() const {\r\n        return {root, belong};\r\
    \n    }\r\n\r\n    int parent(int v) const {\r\n        return par[v];\r\n   \
    \ }\r\n\r\n  private:\r\n    int n;\r\n    int root;\r\n    std::vector<std::vector<int>>\
    \ g;\r\n    std::vector<bool> dead;\r\n    std::vector<int> sz;\r\n    std::vector<int>\
    \ par;\r\n    std::vector<std::vector<int>> belong;\r\n};\r\n\r\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\n/*\r\n    reference: https://qiita.com/drken/items/4b4c3f1824339b090202\r\
    \n               https://ferin-tech.hatenablog.com/entry/2020/03/06/162311\r\n\
    */\r\n\r\nnamespace ebi {\r\n\r\nstruct centroid_decomposition {\r\n  private:\r\
    \n    int find_centroid(int _root) {\r\n        auto get_size = [&](auto &&self,\
    \ int v, int p = -1) -> int {\r\n            sz[v] = 1;\r\n            for (auto\
    \ nv : g[v])\r\n                if (nv != p && !dead[nv]) {\r\n              \
    \      sz[v] += self(self, nv, v);\r\n                }\r\n            return\
    \ sz[v];\r\n        };\r\n        get_size(get_size, _root);\r\n        auto dfs_centroid\
    \ = [&](auto &&self, int v, int p = -1) -> int {\r\n            for (auto nv :\
    \ g[v])\r\n                if (nv != p && !dead[nv]) {\r\n                   \
    \ if (sz[nv] > sz[_root] / 2) return self(self, nv, v);\r\n                }\r\
    \n            return v;\r\n        };\r\n        return dfs_centroid(dfs_centroid,\
    \ _root);\r\n    }\r\n\r\n    int build(int v = 0, int depth = 0) {\r\n      \
    \  int c = find_centroid(v);\r\n        dead[c] = true;\r\n        for (auto nv\
    \ : g[c])\r\n            if (!dead[nv]) {\r\n                int ch = build(nv,\
    \ depth + 1);\r\n                belong[c].emplace_back(ch);\r\n             \
    \   par[ch] = c;\r\n            }\r\n        dead[c] = false;\r\n        return\
    \ root = c;\r\n    }\r\n\r\n  public:\r\n    centroid_decomposition(const std::vector<std::vector<int>>\
    \ &_g)\r\n        : n(int(_g.size())),\r\n          g(_g),\r\n          dead(n,\
    \ false),\r\n          sz(n, -1),\r\n          par(n, -1),\r\n          belong(n)\
    \ {\r\n        build();\r\n    }\r\n\r\n    std::pair<int, std::vector<std::vector<int>>>\r\
    \n    get_centroid_decomposition_tree() const {\r\n        return {root, belong};\r\
    \n    }\r\n\r\n    int parent(int v) const {\r\n        return par[v];\r\n   \
    \ }\r\n\r\n  private:\r\n    int n;\r\n    int root;\r\n    std::vector<std::vector<int>>\
    \ g;\r\n    std::vector<bool> dead;\r\n    std::vector<int> sz;\r\n    std::vector<int>\
    \ par;\r\n    std::vector<std::vector<int>> belong;\r\n};\r\n\r\n}  // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: tree/centroid_decomposition_old.hpp
  requiredBy: []
  timestamp: '2024-01-04 03:14:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Frequency_Table_of_Tree_Distance_Old.test.cpp
documentation_of: tree/centroid_decomposition_old.hpp
layout: document
title: Centroid Decomposition (old)
---

## 説明

重心分解をした木を構築する。 $O(N\log N)$

### get_centroid_decomposition()

重心と重心分解した後の木を返す。

### parent(v)

重心分解後の木について`v`の親を返す。