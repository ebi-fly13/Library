---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: data_structure/sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lowest_common_ancestor.test.cpp
    title: test/lowest_common_ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/lowest_common_ancestor.hpp\"\n\r\n#include <vector>\r\
    \n\r\n#line 2 \"data_structure/sparse_table.hpp\"\n\r\n#line 4 \"data_structure/sparse_table.hpp\"\
    \n\r\n/*\r\n    reference: https://scrapbox.io/data-structures/Sparse_Table\r\n\
    */\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class Band, Band (*op)(Band, Band)>\r\
    \nstruct sparse_table {\r\npublic:\r\n    sparse_table() = default;\r\n\r\n  \
    \  sparse_table(const std::vector<Band> &a) : n(a.size()) {\r\n        table =\
    \ std::vector(std::__lg(n) + 1, std::vector<Band>(n));\r\n        for(int i =\
    \ 0; i < n; i++) {\r\n            table[0][i] = a[i];\r\n        }\r\n       \
    \ for(int k = 1; (1<<k) <= n; k++) {\r\n            for(int i = 0; i + (1<<k)\
    \ <= n; i++) {\r\n                table[k][i] = op(table[k-1][i], table[k-1][i\
    \ + (1<<(k-1))]);\r\n            }\r\n        }\r\n    }\r\n\r\n    void build(const\
    \ std::vector<Band> &a) {\r\n        n = (int)a.size();\r\n        table = std::vector(std::__lg(n)\
    \ + 1, std::vector<Band>(n));\r\n        for(int i = 0; i < n; i++) {\r\n    \
    \        table[0][i] = a[i];\r\n        }\r\n        for(int k = 1; (1<<k) <=\
    \ n; k++) {\r\n            for(int i = 0; i + (1<<k) <= n; i++) {\r\n        \
    \        table[k][i] = op(table[k-1][i], table[k-1][i + (1<<(k-1))]);\r\n    \
    \        }\r\n        }\r\n    }\r\n\r\n    // [l, r)\r\n    Band fold(int l,\
    \ int r) {\r\n        int k = std::__lg(r-l);\r\n        return op(table[k][l],\
    \ table[k][r-(1<<k)]);\r\n    }\r\nprivate:\r\n    int n;\r\n    std::vector<std::vector<Band>>\
    \ table;\r\n};\r\n\r\n}\n#line 2 \"graph/template.hpp\"\n\r\n#line 4 \"graph/template.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate<class T>\r\nstruct Edge {\r\n    int to;\r\
    \n    T cost;\r\n    Edge(int _to, T _cost=1) : to(_to), cost(_cost) { }\r\n};\r\
    \n\r\ntemplate<class T>\r\nstruct Graph : std::vector<std::vector<Edge<T>>> {\r\
    \n    using std::vector<std::vector<Edge<T>>>::vector;\r\n    void add_edge(int\
    \ u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if(directed) return; \r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if(directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n} // namespace\
    \ ebi\n#line 7 \"tree/lowest_common_ancestor.hpp\"\n\r\nnamespace ebi {\r\n\r\n\
    namespace internal_lca {\r\n    std::pair<int,int> op(std::pair<int,int> a, std::pair<int,int>\
    \ b) {\r\n        return a.second < b.second ? a : b;\r\n    }\r\n}\r\n\r\nstruct\
    \ lowest_common_ancestor {\r\npublic:\r\n    lowest_common_ancestor(int _n) :\
    \ n(_n), id(_n), depth(_n), g(_n) { }\r\n\r\n    void add_edge(int u, int v) {\r\
    \n        g[u].emplace_back(v);\r\n        g[v].emplace_back(u);\r\n    }\r\n\r\
    \n    void build(int root = 0) {\r\n        auto dfs = [&](auto &&self, int v,\
    \ int par = -1, int d = 0) -> void {\r\n            id[v] = int(vs.size());\r\n\
    \            depth[v] = d;\r\n            vs.emplace_back(v, d);\r\n         \
    \   for(const auto &nv: g[v]) if(nv != par) {\r\n                self(self, nv,\
    \ v, d+1);\r\n                vs.emplace_back(v, d);\r\n            }\r\n    \
    \    };\r\n        dfs(dfs, root);\r\n        st.build(vs);\r\n    }\r\n\r\n \
    \   int lca(int u, int v) {\r\n        int l = id[u], r = id[v];\r\n        if(r\
    \ < l) std::swap(l, r);\r\n        return st.fold(l, r+1).first;\r\n    }\r\n\r\
    \n    int distance(int u, int v) {\r\n        int w = lca(u, v);\r\n        return\
    \ depth[u] + depth[v] - 2 * depth[w];\r\n    }\r\n\r\nprivate:\r\n    int n;\r\
    \n    std::vector<int> id, depth;\r\n    std::vector<std::pair<int,int>> vs;\r\
    \n    graph g;\r\n    sparse_table<std::pair<int,int>, internal_lca::op> st;\r\
    \n};\r\n\r\n}\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\n#include \"../data_structure/sparse_table.hpp\"\
    \r\n#include \"../graph/template.hpp\"\r\n\r\nnamespace ebi {\r\n\r\nnamespace\
    \ internal_lca {\r\n    std::pair<int,int> op(std::pair<int,int> a, std::pair<int,int>\
    \ b) {\r\n        return a.second < b.second ? a : b;\r\n    }\r\n}\r\n\r\nstruct\
    \ lowest_common_ancestor {\r\npublic:\r\n    lowest_common_ancestor(int _n) :\
    \ n(_n), id(_n), depth(_n), g(_n) { }\r\n\r\n    void add_edge(int u, int v) {\r\
    \n        g[u].emplace_back(v);\r\n        g[v].emplace_back(u);\r\n    }\r\n\r\
    \n    void build(int root = 0) {\r\n        auto dfs = [&](auto &&self, int v,\
    \ int par = -1, int d = 0) -> void {\r\n            id[v] = int(vs.size());\r\n\
    \            depth[v] = d;\r\n            vs.emplace_back(v, d);\r\n         \
    \   for(const auto &nv: g[v]) if(nv != par) {\r\n                self(self, nv,\
    \ v, d+1);\r\n                vs.emplace_back(v, d);\r\n            }\r\n    \
    \    };\r\n        dfs(dfs, root);\r\n        st.build(vs);\r\n    }\r\n\r\n \
    \   int lca(int u, int v) {\r\n        int l = id[u], r = id[v];\r\n        if(r\
    \ < l) std::swap(l, r);\r\n        return st.fold(l, r+1).first;\r\n    }\r\n\r\
    \n    int distance(int u, int v) {\r\n        int w = lca(u, v);\r\n        return\
    \ depth[u] + depth[v] - 2 * depth[w];\r\n    }\r\n\r\nprivate:\r\n    int n;\r\
    \n    std::vector<int> id, depth;\r\n    std::vector<std::pair<int,int>> vs;\r\
    \n    graph g;\r\n    sparse_table<std::pair<int,int>, internal_lca::op> st;\r\
    \n};\r\n\r\n}"
  dependsOn:
  - data_structure/sparse_table.hpp
  - graph/template.hpp
  isVerificationFile: false
  path: tree/lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2021-10-31 15:43:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lowest_common_ancestor.test.cpp
documentation_of: tree/lowest_common_ancestor.hpp
layout: document
redirect_from:
- /library/tree/lowest_common_ancestor.hpp
- /library/tree/lowest_common_ancestor.hpp.html
title: tree/lowest_common_ancestor.hpp
---
