---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: algorithm/two_sat.hpp
    title: algorithm/two_sat.hpp
  - icon: ':x:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':x:'
    path: graph/dijkstra_fibheap.hpp
    title: graph/dijkstra_fibheap.hpp
  - icon: ':x:'
    path: graph/scc_graph.hpp
    title: graph/scc_graph.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Jump_on_Tree.test.cpp
    title: test/Jump_on_Tree.test.cpp
  - icon: ':x:'
    path: test/aoj/aoj_2450.test.cpp
    title: test/aoj/aoj_2450.test.cpp
  - icon: ':x:'
    path: test/dijkstra.test.cpp
    title: test/dijkstra.test.cpp
  - icon: ':x:'
    path: test/fibonacci_heap.test.cpp
    title: test/fibonacci_heap.test.cpp
  - icon: ':x:'
    path: test/level_ancestor_lca.test.cpp
    title: test/level_ancestor_lca.test.cpp
  - icon: ':x:'
    path: test/lowest_common_ancestor.test.cpp
    title: test/lowest_common_ancestor.test.cpp
  - icon: ':x:'
    path: test/scc_graph.test.cpp
    title: test/scc_graph.test.cpp
  - icon: ':x:'
    path: test/two_sat.test.cpp
    title: test/two_sat.test.cpp
  - icon: ':x:'
    path: test/vertex_add_path_sum.test.cpp
    title: test/vertex_add_path_sum.test.cpp
  - icon: ':x:'
    path: test/vertex_add_subtree_sum.test.cpp
    title: test/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/template.hpp\"\n\r\n#include <vector>\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate<class T>\r\nstruct Edge {\r\n    int to;\r\n    T cost;\r\
    \n    Edge(int _to, T _cost=1) : to(_to), cost(_cost) { }\r\n};\r\n\r\ntemplate<class\
    \ T>\r\nstruct Graph : std::vector<std::vector<Edge<T>>> {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\
    \n    void add_edge(int u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if(directed) return; \r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if(directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n} // namespace\
    \ ebi\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class\
    \ T>\r\nstruct Edge {\r\n    int to;\r\n    T cost;\r\n    Edge(int _to, T _cost=1)\
    \ : to(_to), cost(_cost) { }\r\n};\r\n\r\ntemplate<class T>\r\nstruct Graph :\
    \ std::vector<std::vector<Edge<T>>> {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\
    \n    void add_edge(int u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if(directed) return; \r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if(directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n} // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: graph/template.hpp
  requiredBy:
  - graph/scc_graph.hpp
  - graph/dijkstra_fibheap.hpp
  - graph/dijkstra.hpp
  - algorithm/two_sat.hpp
  timestamp: '2021-10-31 15:43:33+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/level_ancestor_lca.test.cpp
  - test/two_sat.test.cpp
  - test/vertex_add_subtree_sum.test.cpp
  - test/scc_graph.test.cpp
  - test/dijkstra.test.cpp
  - test/vertex_add_path_sum.test.cpp
  - test/aoj/aoj_2450.test.cpp
  - test/fibonacci_heap.test.cpp
  - test/Jump_on_Tree.test.cpp
  - test/lowest_common_ancestor.test.cpp
documentation_of: graph/template.hpp
layout: document
redirect_from:
- /library/graph/template.hpp
- /library/graph/template.hpp.html
title: graph/template.hpp
---
