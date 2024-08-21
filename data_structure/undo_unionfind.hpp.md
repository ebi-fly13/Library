---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/offline_dynamic_connectivity.hpp
    title: Offline Dynamic Connectivity
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_1645.test.cpp
    title: test/aoj/aoj_1645.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2235.test.cpp
    title: test/aoj/aoj_2235.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2995.test.cpp
    title: test/aoj/aoj_2995.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/undo_unionfind.hpp\"\n\n#include <cassert>\n\
    #include <stack>\n#include <vector>\n\nnamespace ebi {\n\nstruct undo_unionfind\
    \ {\n  private:\n    std::stack<std::pair<int, int> > stack;\n\n  public:\n  \
    \  std::vector<int> par;\n\n    undo_unionfind(int n = 0) : par(n, -1) {}\n\n\
    \    bool same(int x, int y) const {\n        return leader(x) == leader(y);\n\
    \    }\n\n    bool merge(int x, int y) {\n        x = leader(x);\n        y =\
    \ leader(y);\n        stack.push({x, par[x]});\n        stack.push({y, par[y]});\n\
    \        if (x == y) return false;\n        if (par[x] > par[y]) std::swap(x,\
    \ y);\n        par[x] += par[y];\n        par[y] = x;\n        return true;\n\
    \    }\n\n    int leader(int x) const {\n        if (par[x] < 0)\n           \
    \ return x;\n        else\n            return leader(par[x]);\n    }\n\n    int\
    \ size(int x) const {\n        return -par[leader(x)];\n    }\n\n    int count_group()\
    \ const {\n        int c = 0;\n        for (int i = 0; i < int(par.size()); i++)\
    \ {\n            if (par[i] < 0) c++;\n        }\n        return c;\n    }\n\n\
    \    void undo() {\n        assert(!stack.empty());\n        par[stack.top().first]\
    \ = stack.top().second;\n        stack.pop();\n        par[stack.top().first]\
    \ = stack.top().second;\n        stack.pop();\n        return;\n    }\n};\n\n\
    }  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <stack>\n#include <vector>\n\
    \nnamespace ebi {\n\nstruct undo_unionfind {\n  private:\n    std::stack<std::pair<int,\
    \ int> > stack;\n\n  public:\n    std::vector<int> par;\n\n    undo_unionfind(int\
    \ n = 0) : par(n, -1) {}\n\n    bool same(int x, int y) const {\n        return\
    \ leader(x) == leader(y);\n    }\n\n    bool merge(int x, int y) {\n        x\
    \ = leader(x);\n        y = leader(y);\n        stack.push({x, par[x]});\n   \
    \     stack.push({y, par[y]});\n        if (x == y) return false;\n        if\
    \ (par[x] > par[y]) std::swap(x, y);\n        par[x] += par[y];\n        par[y]\
    \ = x;\n        return true;\n    }\n\n    int leader(int x) const {\n       \
    \ if (par[x] < 0)\n            return x;\n        else\n            return leader(par[x]);\n\
    \    }\n\n    int size(int x) const {\n        return -par[leader(x)];\n    }\n\
    \n    int count_group() const {\n        int c = 0;\n        for (int i = 0; i\
    \ < int(par.size()); i++) {\n            if (par[i] < 0) c++;\n        }\n   \
    \     return c;\n    }\n\n    void undo() {\n        assert(!stack.empty());\n\
    \        par[stack.top().first] = stack.top().second;\n        stack.pop();\n\
    \        par[stack.top().first] = stack.top().second;\n        stack.pop();\n\
    \        return;\n    }\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/undo_unionfind.hpp
  requiredBy:
  - data_structure/offline_dynamic_connectivity.hpp
  timestamp: '2023-10-26 16:27:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_2995.test.cpp
  - test/aoj/aoj_1645.test.cpp
  - test/aoj/aoj_2235.test.cpp
documentation_of: data_structure/undo_unionfind.hpp
layout: document
title: Undo UnionFind
---

## 説明

ロールバック可能なUnionFind。

### same(int x, int y)

$x$ と $y$ が同じグループか判定。 $O(\log N)$

### merge(int x, int y)

$x$ のグループと $y$ のグループをマージ。 $O(\log N)$

### leader(int x)

$x$ のグループの代表を返す。 $O(\log N)$

### size(int x)

$x$ のグループのサイズを返す。 $O(\log N)$

### count_group()

グループの個数を返す。 $O(N)$

### undo()

$1$ つ前の処理をしてない状態にロールバックする。 $O(1)$
