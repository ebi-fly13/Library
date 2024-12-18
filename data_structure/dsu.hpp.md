---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/range_parallel_dsu.hpp
    title: Range Parallel DSU
  - icon: ':heavy_check_mark:'
    path: graph/manhattan_mst.hpp
    title: Manhattan MST
  - icon: ':heavy_check_mark:'
    path: graph/mst.hpp
    title: Minimum Spanning Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Parallel_DSU_Stress_test.test.cpp
    title: test/data_structure/Range_Parallel_DSU_Stress_test.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Parallel_Unionfind.test.cpp
    title: test/data_structure/Range_Parallel_Unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Union_Find.test.cpp
    title: test/data_structure/Union_Find.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Manhattan_MST.test.cpp
    title: test/graph/Manhattan_MST.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Minimum_Spanning_Tree.test.cpp
    title: test/graph/Minimum_Spanning_Tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/dsu.hpp\"\n\r\n#include <algorithm>\r\n#include\
    \ <vector>\r\n\r\nnamespace ebi {\r\n\r\nstruct dsu {\r\n  private:\r\n    std::vector<int>\
    \ par;\r\n    int c;\r\n\r\n  public:\r\n    dsu(int n = 0) : par(n, -1), c(n)\
    \ {}\r\n\r\n    bool same(int x, int y) {\r\n        return leader(x) == leader(y);\r\
    \n    }\r\n\r\n    bool merge(int x, int y) {\r\n        x = leader(x);\r\n  \
    \      y = leader(y);\r\n        if (x == y) return false;\r\n        if (par[x]\
    \ > par[y]) std::swap(x, y);\r\n        par[x] += par[y];\r\n        par[y] =\
    \ x;\r\n        c--;\r\n        return true;\r\n    }\r\n\r\n    int leader(int\
    \ x) {\r\n        if (par[x] < 0)\r\n            return x;\r\n        else\r\n\
    \            return par[x] = leader(par[x]);\r\n    }\r\n\r\n    int size(int\
    \ x) {\r\n        return -par[leader(x)];\r\n    }\r\n\r\n    int count_group()\
    \ const {\r\n        return c;\r\n    }\r\n\r\n    std::vector<std::vector<int>>\
    \ groups() {\r\n        int n = par.size();\r\n        std::vector result(n, std::vector<int>());\r\
    \n        for (int i = 0; i < n; i++) {\r\n            result[leader(i)].emplace_back(i);\r\
    \n        }\r\n        result.erase(std::remove_if(result.begin(), result.end(),\r\
    \n                                    [](const std::vector<int> &v) -> bool {\r\
    \n                                        return v.empty();\r\n              \
    \                      }),\r\n                     result.end());\r\n        return\
    \ result;\r\n    }\r\n\r\n    void clear() {\r\n        for (int i = 0; i < int(par.size());\
    \ i++) {\r\n            par[i] = -1;\r\n        }\r\n    }\r\n};\r\n\r\n}  //\
    \ namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <algorithm>\r\n#include <vector>\r\n\r\nnamespace\
    \ ebi {\r\n\r\nstruct dsu {\r\n  private:\r\n    std::vector<int> par;\r\n   \
    \ int c;\r\n\r\n  public:\r\n    dsu(int n = 0) : par(n, -1), c(n) {}\r\n\r\n\
    \    bool same(int x, int y) {\r\n        return leader(x) == leader(y);\r\n \
    \   }\r\n\r\n    bool merge(int x, int y) {\r\n        x = leader(x);\r\n    \
    \    y = leader(y);\r\n        if (x == y) return false;\r\n        if (par[x]\
    \ > par[y]) std::swap(x, y);\r\n        par[x] += par[y];\r\n        par[y] =\
    \ x;\r\n        c--;\r\n        return true;\r\n    }\r\n\r\n    int leader(int\
    \ x) {\r\n        if (par[x] < 0)\r\n            return x;\r\n        else\r\n\
    \            return par[x] = leader(par[x]);\r\n    }\r\n\r\n    int size(int\
    \ x) {\r\n        return -par[leader(x)];\r\n    }\r\n\r\n    int count_group()\
    \ const {\r\n        return c;\r\n    }\r\n\r\n    std::vector<std::vector<int>>\
    \ groups() {\r\n        int n = par.size();\r\n        std::vector result(n, std::vector<int>());\r\
    \n        for (int i = 0; i < n; i++) {\r\n            result[leader(i)].emplace_back(i);\r\
    \n        }\r\n        result.erase(std::remove_if(result.begin(), result.end(),\r\
    \n                                    [](const std::vector<int> &v) -> bool {\r\
    \n                                        return v.empty();\r\n              \
    \                      }),\r\n                     result.end());\r\n        return\
    \ result;\r\n    }\r\n\r\n    void clear() {\r\n        for (int i = 0; i < int(par.size());\
    \ i++) {\r\n            par[i] = -1;\r\n        }\r\n    }\r\n};\r\n\r\n}  //\
    \ namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/dsu.hpp
  requiredBy:
  - data_structure/range_parallel_dsu.hpp
  - graph/manhattan_mst.hpp
  - graph/mst.hpp
  timestamp: '2024-08-22 02:20:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Range_Parallel_DSU_Stress_test.test.cpp
  - test/data_structure/Range_Parallel_Unionfind.test.cpp
  - test/data_structure/Union_Find.test.cpp
  - test/graph/Minimum_Spanning_Tree.test.cpp
  - test/graph/Manhattan_MST.test.cpp
documentation_of: data_structure/dsu.hpp
layout: document
title: DSU
---

## 説明

$2$ つのグループを同じグループにする、 $2$ つの要素が同じグループか判定、が可能なデータ構造。ここで、 $\alpha(N)$ をアッカーマン関数の逆関数とする。

### dsu(int n)

$N$ 要素のdsuを構築する。 $O(N)$

### same(int x, int y)

$x$ と $y$ が同じグループか判定。 $O(\alpha(N))$

### merge(int x, int y)

$x$ のグループと $y$ のグループをマージ。 $O(\alpha(N))$

### leader(int x)

$x$ のグループの代表を返す。 $O(\alpha(N))$

### size(int x)

$x$ のグループのサイズを返す。 $O(\alpha(N))$

### count_group()

グループの個数を求める。 $O(n)$

### clear()

初期状態にする。 $O(N)$