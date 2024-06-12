---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/dsu.hpp
    title: DSU
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Parallel_DSU_Stress_test.test.cpp
    title: test/data_structure/Range_Parallel_DSU_Stress_test.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Parallel_Unionfind.test.cpp
    title: test/data_structure/Range_Parallel_Unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/range_parallel_dsu.hpp\"\n\n#include <bit>\n\
    #include <cassert>\n#include <vector>\n\n#line 2 \"data_structure/dsu.hpp\"\n\r\
    \n#line 4 \"data_structure/dsu.hpp\"\n\r\nnamespace ebi {\r\n\r\nstruct dsu {\r\
    \n  private:\r\n    std::vector<int> par;\r\n\r\n  public:\r\n    dsu(int n =\
    \ 0) : par(n, -1) {}\r\n\r\n    bool same(int x, int y) {\r\n        return leader(x)\
    \ == leader(y);\r\n    }\r\n\r\n    bool merge(int x, int y) {\r\n        x =\
    \ leader(x);\r\n        y = leader(y);\r\n        if (x == y) return false;\r\n\
    \        if (par[x] > par[y]) std::swap(x, y);\r\n        par[x] += par[y];\r\n\
    \        par[y] = x;\r\n        return true;\r\n    }\r\n\r\n    int leader(int\
    \ x) {\r\n        if (par[x] < 0)\r\n            return x;\r\n        else\r\n\
    \            return par[x] = leader(par[x]);\r\n    }\r\n\r\n    int size(int\
    \ x) {\r\n        return -par[leader(x)];\r\n    }\r\n\r\n    int count_group()\
    \ {\r\n        int c = 0;\r\n        for (int i = 0; i < int(par.size()); i++)\
    \ {\r\n            if (par[i] < 0) c++;\r\n        }\r\n        return c;\r\n\
    \    }\r\n\r\n    std::vector<std::vector<int>> groups() {\r\n        int n =\
    \ par.size();\r\n        std::vector result(n, std::vector<int>());\r\n      \
    \  for (int i = 0; i < n; i++) {\r\n            result[leader(i)].emplace_back(i);\r\
    \n        }\r\n        result.erase(std::remove_if(result.begin(), result.end(),\r\
    \n                                    [](const std::vector<int> &v) -> bool {\r\
    \n                                        return v.empty();\r\n              \
    \                      }),\r\n                     result.end());\r\n        return\
    \ result;\r\n    }\r\n\r\n    void clear() {\r\n        for (int i = 0; i < int(par.size());\
    \ i++) {\r\n            par[i] = -1;\r\n        }\r\n    }\r\n};\r\n\r\n}  //\
    \ namespace ebi\n#line 8 \"data_structure/range_parallel_dsu.hpp\"\n\nnamespace\
    \ ebi {\n\nstruct range_parallel_dsu {\n  private:\n    void merge_(int u, int\
    \ v, int d) {\n        if (uf[d].same(u, v)) return;\n        uf[d].merge(u, v);\n\
    \        if (d > 0) {\n            merge_(u, v, d - 1);\n            merge_(u\
    \ + (1 << (d - 1)), v + (1 << (d - 1)), d - 1);\n        }\n    }\n\n    template\
    \ <class F> void merge_(int u, int v, int d, F f) {\n        if (d == 0) {\n \
    \           u = uf[0].leader(u);\n            v = uf[0].leader(v);\n         \
    \   if (u == v) return;\n            uf[0].merge(u, v);\n            int leader\
    \ = uf[0].leader(u);\n            f(leader, u ^ v ^ leader);\n            return;\n\
    \        } else if (d > 0) {\n            if (!uf[d].merge(u, v)) return;\n  \
    \          merge_(u, v, d - 1, f);\n            merge_(u + (1 << (d - 1)), v +\
    \ (1 << (d - 1)), d - 1, f);\n        } else\n            assert(0);\n    }\n\n\
    \  public:\n    range_parallel_dsu(int n_)\n        : n(n_), uf(std::bit_width((unsigned\
    \ int)n), dsu(n)) {}\n\n    void merge(int u, int v, int w) {\n        if (u >\
    \ v) std::swap(u, v);\n        w = std::min(w, n - v);\n        if (w == 0 ||\
    \ u == v) return;\n        int lg2 = std::bit_width((unsigned int)w) - 1;\n  \
    \      merge_(u, v, lg2);\n        merge_(u + w - (1 << lg2), v + w - (1 << lg2),\
    \ lg2);\n    }\n\n    template <class F> void merge(int u, int v, int w, F f)\
    \ {\n        if (u > v) std::swap(u, v);\n        w = std::min(w, n - v);\n  \
    \      if (w == 0 || u == v) return;\n        int lg2 = std::bit_width((unsigned\
    \ int)w) - 1;\n        merge_(u, v, lg2, f);\n        merge_(u + w - (1 << lg2),\
    \ v + w - (1 << lg2), lg2, f);\n    }\n\n    bool same(int u, int v) {\n     \
    \   return uf[0].same(u, v);\n    }\n\n    int size(int u) {\n        return uf[0].size(u);\n\
    \    }\n\n    int leader(int u) {\n        return uf[0].leader(u);\n    }\n\n\
    \    std::vector<std::vector<int>> groups() {\n        return uf[0].groups();\n\
    \    }\n\n    int count_group() {\n        return uf[0].count_group();\n    }\n\
    \n  private:\n    int n;\n    std::vector<dsu> uf;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <bit>\n#include <cassert>\n#include <vector>\n\n\
    #include \"../data_structure/dsu.hpp\"\n\nnamespace ebi {\n\nstruct range_parallel_dsu\
    \ {\n  private:\n    void merge_(int u, int v, int d) {\n        if (uf[d].same(u,\
    \ v)) return;\n        uf[d].merge(u, v);\n        if (d > 0) {\n            merge_(u,\
    \ v, d - 1);\n            merge_(u + (1 << (d - 1)), v + (1 << (d - 1)), d - 1);\n\
    \        }\n    }\n\n    template <class F> void merge_(int u, int v, int d, F\
    \ f) {\n        if (d == 0) {\n            u = uf[0].leader(u);\n            v\
    \ = uf[0].leader(v);\n            if (u == v) return;\n            uf[0].merge(u,\
    \ v);\n            int leader = uf[0].leader(u);\n            f(leader, u ^ v\
    \ ^ leader);\n            return;\n        } else if (d > 0) {\n            if\
    \ (!uf[d].merge(u, v)) return;\n            merge_(u, v, d - 1, f);\n        \
    \    merge_(u + (1 << (d - 1)), v + (1 << (d - 1)), d - 1, f);\n        } else\n\
    \            assert(0);\n    }\n\n  public:\n    range_parallel_dsu(int n_)\n\
    \        : n(n_), uf(std::bit_width((unsigned int)n), dsu(n)) {}\n\n    void merge(int\
    \ u, int v, int w) {\n        if (u > v) std::swap(u, v);\n        w = std::min(w,\
    \ n - v);\n        if (w == 0 || u == v) return;\n        int lg2 = std::bit_width((unsigned\
    \ int)w) - 1;\n        merge_(u, v, lg2);\n        merge_(u + w - (1 << lg2),\
    \ v + w - (1 << lg2), lg2);\n    }\n\n    template <class F> void merge(int u,\
    \ int v, int w, F f) {\n        if (u > v) std::swap(u, v);\n        w = std::min(w,\
    \ n - v);\n        if (w == 0 || u == v) return;\n        int lg2 = std::bit_width((unsigned\
    \ int)w) - 1;\n        merge_(u, v, lg2, f);\n        merge_(u + w - (1 << lg2),\
    \ v + w - (1 << lg2), lg2, f);\n    }\n\n    bool same(int u, int v) {\n     \
    \   return uf[0].same(u, v);\n    }\n\n    int size(int u) {\n        return uf[0].size(u);\n\
    \    }\n\n    int leader(int u) {\n        return uf[0].leader(u);\n    }\n\n\
    \    std::vector<std::vector<int>> groups() {\n        return uf[0].groups();\n\
    \    }\n\n    int count_group() {\n        return uf[0].count_group();\n    }\n\
    \n  private:\n    int n;\n    std::vector<dsu> uf;\n};\n\n}  // namespace ebi"
  dependsOn:
  - data_structure/dsu.hpp
  isVerificationFile: false
  path: data_structure/range_parallel_dsu.hpp
  requiredBy: []
  timestamp: '2024-06-12 20:05:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Range_Parallel_DSU_Stress_test.test.cpp
  - test/data_structure/Range_Parallel_Unionfind.test.cpp
documentation_of: data_structure/range_parallel_dsu.hpp
layout: document
title: Range Parallel DSU
---

## 説明

### range_parallel_dsu(int n)

要素数 $n$ のdsuを作る。空間 $O(N\log{N})$

### same(int x, int y)

$x$ と $y$ が同じグループか判定。 $O(\alpha(N))$

### merge(int x, int y, int w)

$i \in [0, w)$ について $x + i$ と $y + i$ を同じグループにする。

### leader(int x)

$x$ のグループの代表を返す。 $O(\alpha(N))$

### size(int x)

$x$ のグループのサイズを返す。 $O(\alpha(N))$

### groups()

グループを列挙する。 $O(N\alpha(N))$

### count_group()

グループの個数を求める。 $O(n)$