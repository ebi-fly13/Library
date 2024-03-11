---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_grl_1_b.test.cpp
    title: test/aoj/aoj_grl_1_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/bellman_ford.hpp\"\n\n#include <cassert>\n#include\
    \ <limits>\n#include <ranges>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\n#line 2 \"graph/template.hpp\"\n\r\n#line 4 \"graph/template.hpp\"\
    \n#include <iostream>\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class T> struct\
    \ Edge {\r\n    int to;\r\n    T cost;\r\n    Edge(int _to, T _cost = 1) : to(_to),\
    \ cost(_cost) {}\r\n};\r\n\r\ntemplate <class T> struct Graph : std::vector<std::vector<Edge<T>>>\
    \ {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\n    void add_edge(int\
    \ u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if (directed) return;\r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if (directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n\r\n    void read_tree(int\
    \ offset = 1) {\r\n        read_graph((int)size()-1, offset);\r\n    }\r\n\r\n\
    \    void read_graph(int m, int offset = 1, bool directed = false) {\r\n     \
    \   for(int i = 0; i < m; i++) {\r\n            int u,v;\r\n            std::cin\
    \ >> u >> v;\r\n            u -= offset;\r\n            v -= offset;\r\n     \
    \       add_edge(u, v, directed);\r\n        }\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\n#line 11 \"graph/bellman_ford.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ T> std::vector<T> bellman_ford(int s, const Graph<T> &g) {\n    int n = (int)g.size();\n\
    \    assert(0 <= s && s < n);\n    std::vector<T> dist(n, std::numeric_limits<T>::max());\n\
    \    dist[s] = 0;\n    std::vector<std::tuple<int, int, T>> edges;\n    for (auto\
    \ from : std::views::iota(0, n)) {\n        for (auto [to, cost] : g[from]) {\n\
    \            edges.emplace_back(from, to, cost);\n        }\n    }\n    for (auto\
    \ i : std::views::iota(0, n)) {\n        for (auto [from, to, cost] : edges) {\n\
    \            if (dist[from] == std::numeric_limits<T>::max()) continue;\n    \
    \        if (dist[from] + cost < dist[to]) {\n                dist[to] = dist[from]\
    \ + cost;\n                if (i == n - 1) {\n                    return {};\n\
    \                }\n            }\n        }\n    }\n    return dist;\n}\n\n}\
    \  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <limits>\n#include <ranges>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n\n#include \"../graph/template.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> std::vector<T> bellman_ford(int s, const\
    \ Graph<T> &g) {\n    int n = (int)g.size();\n    assert(0 <= s && s < n);\n \
    \   std::vector<T> dist(n, std::numeric_limits<T>::max());\n    dist[s] = 0;\n\
    \    std::vector<std::tuple<int, int, T>> edges;\n    for (auto from : std::views::iota(0,\
    \ n)) {\n        for (auto [to, cost] : g[from]) {\n            edges.emplace_back(from,\
    \ to, cost);\n        }\n    }\n    for (auto i : std::views::iota(0, n)) {\n\
    \        for (auto [from, to, cost] : edges) {\n            if (dist[from] ==\
    \ std::numeric_limits<T>::max()) continue;\n            if (dist[from] + cost\
    \ < dist[to]) {\n                dist[to] = dist[from] + cost;\n             \
    \   if (i == n - 1) {\n                    return {};\n                }\n   \
    \         }\n        }\n    }\n    return dist;\n}\n\n}  // namespace ebi"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '2024-03-11 15:33:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_grl_1_b.test.cpp
documentation_of: graph/bellman_ford.hpp
layout: document
title: Bellman-Ford
---

## 説明

負辺ありのグラフについて、単一始点最短路を求める。 $O(|V||E|)$

負の閉路が存在する場合、返り値の配列は空である。