---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/unionfind.hpp
    title: UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/range_parallel_dsu.hpp\"\n\n#include <bit>\n\
    #include <cassert>\n#include <vector>\n\n#line 2 \"data_structure/unionfind.hpp\"\
    \n\r\n#line 4 \"data_structure/unionfind.hpp\"\n\r\nnamespace ebi {\r\n\r\nstruct\
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
    \    }\r\n};\r\n\r\n}  // namespace ebi\n#line 8 \"data_structure/range_parallel_dsu.hpp\"\
    \n\nnamespace ebi {\n\nstruct range_parallel_dsu {\n  private:\n    void merge_(int\
    \ u, int v, int d) {\n        if (uf[d].same(u, v)) return;\n        uf[d].merge(u,\
    \ v);\n        if (d > 0) {\n            merge_(u, v, d - 1);\n            merge_(u\
    \ + (1 << (d - 1)), v + (1 << (d - 1)), d - 1);\n        }\n    }\n\n  public:\n\
    \    range_parallel_dsu(int n_)\n        : n(n_), uf(std::bit_width((unsigned\
    \ int)n), unionfind(n)) {}\n\n    void merge(int u, int v, int w) {\n        if\
    \ (u > v) std::swap(u, v);\n        w = std::min(w, n - v);\n        if (w ==\
    \ 0 || u == v) return;\n        int lg2 = std::bit_width((unsigned int)w) - 1;\n\
    \        merge_(u, v, lg2);\n        merge_(u + w - (1 << lg2), v + w - (1 <<\
    \ lg2), lg2);\n    }\n\n    bool same(int u, int v) {\n        return uf[0].same(u,\
    \ v);\n    }\n\n    int size(int u) {\n        return uf[0].size(u);\n    }\n\n\
    \    int leader(int u) {\n        return uf[0].leader(u);\n    }\n\n  private:\n\
    \    int n;\n    std::vector<unionfind> uf;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <bit>\n#include <cassert>\n#include <vector>\n\n\
    #include \"../data_structure/unionfind.hpp\"\n\nnamespace ebi {\n\nstruct range_parallel_dsu\
    \ {\n  private:\n    void merge_(int u, int v, int d) {\n        if (uf[d].same(u,\
    \ v)) return;\n        uf[d].merge(u, v);\n        if (d > 0) {\n            merge_(u,\
    \ v, d - 1);\n            merge_(u + (1 << (d - 1)), v + (1 << (d - 1)), d - 1);\n\
    \        }\n    }\n\n  public:\n    range_parallel_dsu(int n_)\n        : n(n_),\
    \ uf(std::bit_width((unsigned int)n), unionfind(n)) {}\n\n    void merge(int u,\
    \ int v, int w) {\n        if (u > v) std::swap(u, v);\n        w = std::min(w,\
    \ n - v);\n        if (w == 0 || u == v) return;\n        int lg2 = std::bit_width((unsigned\
    \ int)w) - 1;\n        merge_(u, v, lg2);\n        merge_(u + w - (1 << lg2),\
    \ v + w - (1 << lg2), lg2);\n    }\n\n    bool same(int u, int v) {\n        return\
    \ uf[0].same(u, v);\n    }\n\n    int size(int u) {\n        return uf[0].size(u);\n\
    \    }\n\n    int leader(int u) {\n        return uf[0].leader(u);\n    }\n\n\
    \  private:\n    int n;\n    std::vector<unionfind> uf;\n};\n\n}  // namespace\
    \ ebi"
  dependsOn:
  - data_structure/unionfind.hpp
  isVerificationFile: false
  path: data_structure/range_parallel_dsu.hpp
  requiredBy: []
  timestamp: '2024-04-24 15:16:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/range_parallel_dsu.hpp
layout: document
redirect_from:
- /library/data_structure/range_parallel_dsu.hpp
- /library/data_structure/range_parallel_dsu.hpp.html
title: data_structure/range_parallel_dsu.hpp
---
