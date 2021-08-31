---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ferin-tech.hatenablog.com/entry/2020/03/06/162311
    - https://qiita.com/drken/items/4b4c3f1824339b090202
  bundledCode: "#line 2 \"tree/centroid_decomposition.hpp\"\n\r\n#include <vector>\r\
    \n\r\n#line 2 \"graph/template.hpp\"\n\r\n#line 4 \"graph/template.hpp\"\n\r\n\
    namespace ebi {\r\n\r\ntemplate<class T>\r\nstruct Edge {\r\n    int to;\r\n \
    \   T cost;\r\n    Edge(int to, T cost=1) : to(to), cost(cost) { }\r\n};\r\n\r\
    \ntemplate<class T>\r\nstruct Graph : std::vector<std::vector<Edge<T>>> {\r\n\
    \    using std::vector<std::vector<Edge<T>>>::vector;\r\n    void add_edge(int\
    \ u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if(directed) return; \r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if(directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n} // namespace\
    \ ebi\n#line 6 \"tree/centroid_decomposition.hpp\"\n\r\n/*\r\n    reference: https://qiita.com/drken/items/4b4c3f1824339b090202\r\
    \n               https://ferin-tech.hatenablog.com/entry/2020/03/06/162311\r\n\
    */\r\n\r\nnamespace ebi {\r\n\r\nstruct centroid_decomposition {\r\nprivate:\r\
    \n    int find_centrioid(int _root) {\r\n        auto get_size = [&](auto &&self,\
    \ int v, int p = -1) -> int {\r\n            sz[v] = 1;\r\n            for(auto\
    \ nv: g[v]) if(nv != p && !dead[nv]) {\r\n                sz[v] += self(self,\
    \ nv, v);\r\n            }\r\n            return sz[v];\r\n        };\r\n    \
    \    get_size(get_size, _root);\r\n        auto dfs_centrioid = [&](auto &&self,\
    \ int v, int p = -1) -> int {\r\n            for(auto nv: g[v]) if(nv != p &&\
    \ !dead[nv]) {\r\n                if(sz[nv] > sz[_root]/2) return self(self, nv,\
    \ v);\r\n            }\r\n            return v;\r\n        };\r\n        return\
    \ dfs_centrioid(dfs_centrioid, _root);\r\n    }\r\npublic:\r\n    centroid_decomposition(int\
    \ _n) : n(_n), g(_n), dead(_n, false), sz(_n, -1), par(_n, -1), belong(_n) { }\r\
    \n\r\n    centroid_decomposition(const graph &_g) : n(int(_g.size())), g(_g),\
    \ dead(n, false), sz(n, -1), par(n, -1), belong(n) { }\r\n\r\n    int build(int\
    \ v = 0, int depth = 0) {\r\n        int c = find_centrioid(v);\r\n        dead[c]\
    \ = true;\r\n        for(auto nv: g[c]) if(!dead[nv]) {\r\n            int ch\
    \ = build(nv, depth + 1);\r\n            belong[c].emplace_back(ch);\r\n     \
    \       par[ch] = c;\r\n        }\r\n        dead[c] = false;\r\n        return\
    \ root = c;\r\n    }\r\n\r\n    void add_edge(int u, int v) {\r\n        g[u].emplace_back(v);\r\
    \n        g[v].emplace_back(u);\r\n    }\r\n\r\n    int parent(int v) {\r\n  \
    \      return par[v];\r\n    }\r\nprivate:\r\n    int n;\r\n    int root;\r\n\
    \    graph g;\r\n    std::vector<bool> dead;\r\n    std::vector<int> sz;\r\n \
    \   std::vector<int> par;\r\n    std::vector<std::vector<int>> belong;\r\n};\r\
    \n\r\n}\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\n#include \"graph/template.hpp\"\
    \r\n\r\n/*\r\n    reference: https://qiita.com/drken/items/4b4c3f1824339b090202\r\
    \n               https://ferin-tech.hatenablog.com/entry/2020/03/06/162311\r\n\
    */\r\n\r\nnamespace ebi {\r\n\r\nstruct centroid_decomposition {\r\nprivate:\r\
    \n    int find_centrioid(int _root) {\r\n        auto get_size = [&](auto &&self,\
    \ int v, int p = -1) -> int {\r\n            sz[v] = 1;\r\n            for(auto\
    \ nv: g[v]) if(nv != p && !dead[nv]) {\r\n                sz[v] += self(self,\
    \ nv, v);\r\n            }\r\n            return sz[v];\r\n        };\r\n    \
    \    get_size(get_size, _root);\r\n        auto dfs_centrioid = [&](auto &&self,\
    \ int v, int p = -1) -> int {\r\n            for(auto nv: g[v]) if(nv != p &&\
    \ !dead[nv]) {\r\n                if(sz[nv] > sz[_root]/2) return self(self, nv,\
    \ v);\r\n            }\r\n            return v;\r\n        };\r\n        return\
    \ dfs_centrioid(dfs_centrioid, _root);\r\n    }\r\npublic:\r\n    centroid_decomposition(int\
    \ _n) : n(_n), g(_n), dead(_n, false), sz(_n, -1), par(_n, -1), belong(_n) { }\r\
    \n\r\n    centroid_decomposition(const graph &_g) : n(int(_g.size())), g(_g),\
    \ dead(n, false), sz(n, -1), par(n, -1), belong(n) { }\r\n\r\n    int build(int\
    \ v = 0, int depth = 0) {\r\n        int c = find_centrioid(v);\r\n        dead[c]\
    \ = true;\r\n        for(auto nv: g[c]) if(!dead[nv]) {\r\n            int ch\
    \ = build(nv, depth + 1);\r\n            belong[c].emplace_back(ch);\r\n     \
    \       par[ch] = c;\r\n        }\r\n        dead[c] = false;\r\n        return\
    \ root = c;\r\n    }\r\n\r\n    void add_edge(int u, int v) {\r\n        g[u].emplace_back(v);\r\
    \n        g[v].emplace_back(u);\r\n    }\r\n\r\n    int parent(int v) {\r\n  \
    \      return par[v];\r\n    }\r\nprivate:\r\n    int n;\r\n    int root;\r\n\
    \    graph g;\r\n    std::vector<bool> dead;\r\n    std::vector<int> sz;\r\n \
    \   std::vector<int> par;\r\n    std::vector<std::vector<int>> belong;\r\n};\r\
    \n\r\n}"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: tree/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2021-08-31 14:46:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/centroid_decomposition.hpp
layout: document
redirect_from:
- /library/tree/centroid_decomposition.hpp
- /library/tree/centroid_decomposition.hpp.html
title: tree/centroid_decomposition.hpp
---
