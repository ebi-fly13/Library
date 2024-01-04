---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Union_Find.test.cpp
    title: test/data_structure/Union_Find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/unionfind.hpp\"\n\r\n#include <vector>\r\n\
    \r\nnamespace ebi {\r\n\r\nstruct unionfind {\r\n  private:\r\n    std::vector<int>\
    \ par;\r\n\r\n  public:\r\n    unionfind(int n = 0) : par(n, -1) {}\r\n\r\n  \
    \  bool same(int x, int y) {\r\n        return leader(x) == leader(y);\r\n   \
    \ }\r\n\r\n    bool merge(int x, int y) {\r\n        x = leader(x);\r\n      \
    \  y = leader(y);\r\n        if (x == y) return false;\r\n        if (par[x] >\
    \ par[y]) std::swap(x, y);\r\n        par[x] += par[y];\r\n        par[y] = x;\r\
    \n        return true;\r\n    }\r\n\r\n    int leader(int x) {\r\n        if (par[x]\
    \ < 0)\r\n            return x;\r\n        else\r\n            return par[x] =\
    \ leader(par[x]);\r\n    }\r\n\r\n    int size(int x) {\r\n        return -par[leader(x)];\r\
    \n    }\r\n\r\n    int count_group() {\r\n        int c = 0;\r\n        for (int\
    \ i = 0; i < int(par.size()); i++) {\r\n            if (par[i] < 0) c++;\r\n \
    \       }\r\n        return c;\r\n    }\r\n\r\n    void clear() {\r\n        for\
    \ (int i = 0; i < int(par.size()); i++) {\r\n            par[i] = -1;\r\n    \
    \    }\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\nstruct\
    \ unionfind {\r\n  private:\r\n    std::vector<int> par;\r\n\r\n  public:\r\n\
    \    unionfind(int n = 0) : par(n, -1) {}\r\n\r\n    bool same(int x, int y) {\r\
    \n        return leader(x) == leader(y);\r\n    }\r\n\r\n    bool merge(int x,\
    \ int y) {\r\n        x = leader(x);\r\n        y = leader(y);\r\n        if (x\
    \ == y) return false;\r\n        if (par[x] > par[y]) std::swap(x, y);\r\n   \
    \     par[x] += par[y];\r\n        par[y] = x;\r\n        return true;\r\n   \
    \ }\r\n\r\n    int leader(int x) {\r\n        if (par[x] < 0)\r\n            return\
    \ x;\r\n        else\r\n            return par[x] = leader(par[x]);\r\n    }\r\
    \n\r\n    int size(int x) {\r\n        return -par[leader(x)];\r\n    }\r\n\r\n\
    \    int count_group() {\r\n        int c = 0;\r\n        for (int i = 0; i <\
    \ int(par.size()); i++) {\r\n            if (par[i] < 0) c++;\r\n        }\r\n\
    \        return c;\r\n    }\r\n\r\n    void clear() {\r\n        for (int i =\
    \ 0; i < int(par.size()); i++) {\r\n            par[i] = -1;\r\n        }\r\n\
    \    }\r\n};\r\n\r\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/unionfind.hpp
  requiredBy: []
  timestamp: '2023-11-13 02:14:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Union_Find.test.cpp
documentation_of: data_structure/unionfind.hpp
layout: document
title: UnionFind
---

## 説明

$2$ つのグループを同じグループにする、 $2$ つの要素が同じグループか判定、が可能なデータ構造。ここで、 $\alpha(N)$ をアッカーマン関数の逆関数とする。

### unionfind(int n)

$N$ 要素のunionfindを構築する。 $O(N)$

### same(int x, int y)

$x$ と $y$ が同じグループか判定。 $O(\alpha(N))$

### merge(int x, int y, T p)

$x$ のグループと $y$ のグループをマージ。 $O(\alpha(N))$

### leader(int x)

$x$ のグループの代表を返す。 $O(\alpha(N))$

### size(int x)

$x$ のグループのサイズを返す。 $O(\alpha(N))$

### count_group()

グループの個数を求める。 $O(n)$

### clear()

初期状態にする。 $O(N)$