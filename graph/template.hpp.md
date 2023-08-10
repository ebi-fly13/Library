---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/two_sat.hpp
    title: algorithm/two_sat.hpp
  - icon: ':warning:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra_fibheap.hpp
    title: graph/dijkstra_fibheap.hpp
  - icon: ':heavy_check_mark:'
    path: graph/scc_graph.hpp
    title: graph/scc_graph.hpp
  - icon: ':heavy_check_mark:'
    path: tree/tree_diameter.hpp
    title: Tree Diameter
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/Two_Sat.test.cpp
    title: test/algorithm/Two_Sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2450.test.cpp
    title: test/aoj/aoj_2450.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Vertex_Add_Path_Sum.test.cpp
    title: test/data_structure/Vertex_Add_Path_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Vertex_Add_Subtree_Sum.test.cpp
    title: test/data_structure/Vertex_Add_Subtree_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Biconnected_Components.test.cpp
    title: test/graph/Biconnected_Components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/fibonacci_heap.test.cpp
    title: test/graph/fibonacci_heap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/scc_graph.test.cpp
    title: test/graph/scc_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Frequency_Table_of_Tree_Distance.test.cpp
    title: test/tree/Frequency_Table_of_Tree_Distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Jump_on_Tree.test.cpp
    title: test/tree/Jump_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Jump_on_Tree_HLD.test.cpp
    title: test/tree/Jump_on_Tree_HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Tree_Diameter.test.cpp
    title: test/tree/Tree_Diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/level_ancestor_lca.test.cpp
    title: test/tree/level_ancestor_lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/lowest_common_ancestor.test.cpp
    title: test/tree/lowest_common_ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/template.hpp\"\n\r\n#include <vector>\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <class T> struct Edge {\r\n    int to;\r\n    T cost;\r\
    \n    Edge(int _to, T _cost = 1) : to(_to), cost(_cost) {}\r\n};\r\n\r\ntemplate\
    \ <class T> struct Graph : std::vector<std::vector<Edge<T>>> {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\
    \n    void add_edge(int u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if (directed) return;\r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if (directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate\
    \ <class T> struct Edge {\r\n    int to;\r\n    T cost;\r\n    Edge(int _to, T\
    \ _cost = 1) : to(_to), cost(_cost) {}\r\n};\r\n\r\ntemplate <class T> struct\
    \ Graph : std::vector<std::vector<Edge<T>>> {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\
    \n    void add_edge(int u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if (directed) return;\r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if (directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: graph/template.hpp
  requiredBy:
  - algorithm/two_sat.hpp
  - tree/tree_diameter.hpp
  - graph/scc_graph.hpp
  - graph/dijkstra_fibheap.hpp
  - graph/dijkstra.hpp
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Vertex_Add_Path_Sum.test.cpp
  - test/data_structure/Vertex_Add_Subtree_Sum.test.cpp
  - test/algorithm/Two_Sat.test.cpp
  - test/aoj/aoj_2450.test.cpp
  - test/tree/Frequency_Table_of_Tree_Distance.test.cpp
  - test/tree/Jump_on_Tree.test.cpp
  - test/tree/level_ancestor_lca.test.cpp
  - test/tree/lowest_common_ancestor.test.cpp
  - test/tree/Tree_Diameter.test.cpp
  - test/tree/Jump_on_Tree_HLD.test.cpp
  - test/graph/Biconnected_Components.test.cpp
  - test/graph/scc_graph.test.cpp
  - test/graph/fibonacci_heap.test.cpp
documentation_of: graph/template.hpp
layout: document
redirect_from:
- /library/graph/template.hpp
- /library/graph/template.hpp.html
title: graph/template.hpp
---
