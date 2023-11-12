---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/unionfind_with_potential.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace ebi {\n\ntemplate <class T> struct\
    \ unionfind_with_potential {\n  private:\n  public:\n    unionfind_with_potential(int\
    \ n) : data_(n, -1), potential_(n, T()) {}\n\n    bool same(int x, int y) {\n\
    \        return leader(x) == leader(y);\n    }\n\n    // potential(x) = potential(y)\
    \ + p\n    bool merge(int x, int y, T p) {\n        p = potential(x) - p - potential(y);\n\
    \        x = leader(x);\n        y = leader(y);\n        if (x == y) return p\
    \ == T();\n        if (data_[x] > data_[y]) {\n            std::swap(x, y);\n\
    \            p = -p;\n        }\n        data_[x] += data_[y];\n        data_[y]\
    \ = x;\n        potential_[y] = p;\n        return true;\n    }\n\n    int leader(int\
    \ x) {\n        if (data_[x] < 0) return x;\n        int l = leader(data_[x]);\n\
    \        potential_[x] = potential_[data_[x]] + potential_[x];\n        return\
    \ data_[x] = l;\n    }\n\n    int size(int x) {\n        return -data_[leader(x)];\n\
    \    }\n\n    T potential(int x) {\n        leader(x);\n        return potential_[x];\n\
    \    }\n\n    T diff(int x, int y) {\n        return potential(x) - potential(y);\n\
    \    }\n\n  private:\n    std::vector<int> data_;\n    std::vector<T> potential_;\n\
    };\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\nnamespace ebi {\n\
    \ntemplate <class T> struct unionfind_with_potential {\n  private:\n  public:\n\
    \    unionfind_with_potential(int n) : data_(n, -1), potential_(n, T()) {}\n\n\
    \    bool same(int x, int y) {\n        return leader(x) == leader(y);\n    }\n\
    \n    // potential(x) = potential(y) + p\n    bool merge(int x, int y, T p) {\n\
    \        p = potential(x) - p - potential(y);\n        x = leader(x);\n      \
    \  y = leader(y);\n        if (x == y) return p == T();\n        if (data_[x]\
    \ > data_[y]) {\n            std::swap(x, y);\n            p = -p;\n        }\n\
    \        data_[x] += data_[y];\n        data_[y] = x;\n        potential_[y] =\
    \ p;\n        return true;\n    }\n\n    int leader(int x) {\n        if (data_[x]\
    \ < 0) return x;\n        int l = leader(data_[x]);\n        potential_[x] = potential_[data_[x]]\
    \ + potential_[x];\n        return data_[x] = l;\n    }\n\n    int size(int x)\
    \ {\n        return -data_[leader(x)];\n    }\n\n    T potential(int x) {\n  \
    \      leader(x);\n        return potential_[x];\n    }\n\n    T diff(int x, int\
    \ y) {\n        return potential(x) - potential(y);\n    }\n\n  private:\n   \
    \ std::vector<int> data_;\n    std::vector<T> potential_;\n};\n\n}  // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/unionfind_with_potential.hpp
  requiredBy: []
  timestamp: '2023-11-13 02:14:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/unionfind_with_potential.hpp
layout: document
title: UnionFind with potential
---

## 説明

ポテンシャル付きUnionFind。ここで、 $\alpha(N)$ をアッカーマン関数の逆関数とする。

### same(int x, int y)

$x$ と $y$ が同じグループか判定。 $O(\alpha(N))$

### merge(int x, int y, T p)

$x$ のグループと $y$ のグループをマージ。ポテンシャルは $potential(x) = potential(y) + p$ とする。 $O(\alpha(N))$

### leader(int x)

$x$ のグループの代表を返す。 $O(\alpha(N))$

### size(int x)

$x$ のグループのサイズを返す。 $O(\alpha(N))$

### potential(int x)

$x$ のポテンシャルを返す。 $O(\alpha(N))$

### diff(int x, int y)

$x$ と $y$ のポテンシャルの差分を返す。 $O(\alpha(N))$
