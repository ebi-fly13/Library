---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/Jump_on_Tree.test.cpp
    title: test/tree/Jump_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/lowest_common_ancestor.test.cpp
    title: test/tree/lowest_common_ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/lowest_common_ancestor.hpp\"\n\r\n#include <vector>\r\
    \n\r\n#line 2 \"data_structure/sparse_table.hpp\"\n\r\n#line 4 \"data_structure/sparse_table.hpp\"\
    \n\r\n/*\r\n    reference: https://scrapbox.io/data-structures/Sparse_Table\r\n\
    */\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class Band, Band (*op)(Band, Band)>\
    \ struct sparse_table {\r\n  public:\r\n    sparse_table() = default;\r\n\r\n\
    \    sparse_table(const std::vector<Band> &a) : n(a.size()) {\r\n        table\
    \ = std::vector(std::__lg(n) + 1, std::vector<Band>(n));\r\n        for (int i\
    \ = 0; i < n; i++) {\r\n            table[0][i] = a[i];\r\n        }\r\n     \
    \   for (int k = 1; (1 << k) <= n; k++) {\r\n            for (int i = 0; i + (1\
    \ << k) <= n; i++) {\r\n                table[k][i] =\r\n                    op(table[k\
    \ - 1][i], table[k - 1][i + (1 << (k - 1))]);\r\n            }\r\n        }\r\n\
    \    }\r\n\r\n    void build(const std::vector<Band> &a) {\r\n        n = (int)a.size();\r\
    \n        table = std::vector(std::__lg(n) + 1, std::vector<Band>(n));\r\n   \
    \     for (int i = 0; i < n; i++) {\r\n            table[0][i] = a[i];\r\n   \
    \     }\r\n        for (int k = 1; (1 << k) <= n; k++) {\r\n            for (int\
    \ i = 0; i + (1 << k) <= n; i++) {\r\n                table[k][i] =\r\n      \
    \              op(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);\r\n    \
    \        }\r\n        }\r\n    }\r\n\r\n    // [l, r)\r\n    Band fold(int l,\
    \ int r) {\r\n        int k = std::__lg(r - l);\r\n        return op(table[k][l],\
    \ table[k][r - (1 << k)]);\r\n    }\r\n\r\n  private:\r\n    int n;\r\n    std::vector<std::vector<Band>>\
    \ table;\r\n};\r\n\r\n}  // namespace ebi\n#line 6 \"tree/lowest_common_ancestor.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\nnamespace internal_lca {\r\nstd::pair<int, int> op(std::pair<int,\
    \ int> a, std::pair<int, int> b) {\r\n    return a.second < b.second ? a : b;\r\
    \n}\r\n}  // namespace internal_lca\r\n\r\nstruct lowest_common_ancestor {\r\n\
    \  public:\r\n    lowest_common_ancestor(const std::vector<std::vector<int>> &gh,\r\
    \n                           int root = 0)\r\n        : n(gh.size()), id(n), depth(n)\
    \ {\r\n        auto dfs = [&](auto &&self, int v, int par = -1, int d = 0) ->\
    \ void {\r\n            id[v] = int(vs.size());\r\n            depth[v] = d;\r\
    \n            vs.emplace_back(v, d);\r\n            for (const auto &nv : gh[v])\r\
    \n                if (nv != par) {\r\n                    self(self, nv, v, d\
    \ + 1);\r\n                    vs.emplace_back(v, d);\r\n                }\r\n\
    \        };\r\n        dfs(dfs, root);\r\n        st.build(vs);\r\n    }\r\n\r\
    \n    int lca(int u, int v) {\r\n        int l = id[u], r = id[v];\r\n       \
    \ if (r < l) std::swap(l, r);\r\n        return st.fold(l, r + 1).first;\r\n \
    \   }\r\n\r\n    int distance(int u, int v) {\r\n        int w = lca(u, v);\r\n\
    \        return depth[u] + depth[v] - 2 * depth[w];\r\n    }\r\n\r\n  private:\r\
    \n    int n;\r\n    std::vector<int> id, depth;\r\n    std::vector<std::pair<int,\
    \ int>> vs;\r\n    sparse_table<std::pair<int, int>, internal_lca::op> st;\r\n\
    };\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\n#include \"../data_structure/sparse_table.hpp\"\
    \r\n\r\nnamespace ebi {\r\n\r\nnamespace internal_lca {\r\nstd::pair<int, int>\
    \ op(std::pair<int, int> a, std::pair<int, int> b) {\r\n    return a.second <\
    \ b.second ? a : b;\r\n}\r\n}  // namespace internal_lca\r\n\r\nstruct lowest_common_ancestor\
    \ {\r\n  public:\r\n    lowest_common_ancestor(const std::vector<std::vector<int>>\
    \ &gh,\r\n                           int root = 0)\r\n        : n(gh.size()),\
    \ id(n), depth(n) {\r\n        auto dfs = [&](auto &&self, int v, int par = -1,\
    \ int d = 0) -> void {\r\n            id[v] = int(vs.size());\r\n            depth[v]\
    \ = d;\r\n            vs.emplace_back(v, d);\r\n            for (const auto &nv\
    \ : gh[v])\r\n                if (nv != par) {\r\n                    self(self,\
    \ nv, v, d + 1);\r\n                    vs.emplace_back(v, d);\r\n           \
    \     }\r\n        };\r\n        dfs(dfs, root);\r\n        st.build(vs);\r\n\
    \    }\r\n\r\n    int lca(int u, int v) {\r\n        int l = id[u], r = id[v];\r\
    \n        if (r < l) std::swap(l, r);\r\n        return st.fold(l, r + 1).first;\r\
    \n    }\r\n\r\n    int distance(int u, int v) {\r\n        int w = lca(u, v);\r\
    \n        return depth[u] + depth[v] - 2 * depth[w];\r\n    }\r\n\r\n  private:\r\
    \n    int n;\r\n    std::vector<int> id, depth;\r\n    std::vector<std::pair<int,\
    \ int>> vs;\r\n    sparse_table<std::pair<int, int>, internal_lca::op> st;\r\n\
    };\r\n\r\n}  // namespace ebi"
  dependsOn:
  - data_structure/sparse_table.hpp
  isVerificationFile: false
  path: tree/lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/lowest_common_ancestor.test.cpp
  - test/tree/Jump_on_Tree.test.cpp
documentation_of: tree/lowest_common_ancestor.hpp
layout: document
title: Lowest Common Ancestor
---

## 説明

根付き木の最小共通祖先を、構築 $O(N\log N)$ / クエリ $O(1)$ で求める。

### lca(u, v)

`u`と`v`の最小共通祖先を返す。 $O(1)$

### distance(u, v)

`u`と`v`の距離を返す。