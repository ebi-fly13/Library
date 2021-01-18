---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/dijkstra.test.cpp
    title: test/dijkstra.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/template.hpp\"\n\r\n#include <vector>\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate<class T>\r\nstruct Edge {\r\n    int to;\r\n    T cost;\r\
    \n    Edge(int to, T cost=1) : to(to), cost(cost) { }\r\n};\r\n\r\ntemplate<class\
    \ T>\r\nusing Graph = std::vector<std::vector<Edge<T>>>;\r\n\r\nusing graph =\
    \ std::vector<std::vector<int>>;\r\n\r\n} // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class\
    \ T>\r\nstruct Edge {\r\n    int to;\r\n    T cost;\r\n    Edge(int to, T cost=1)\
    \ : to(to), cost(cost) { }\r\n};\r\n\r\ntemplate<class T>\r\nusing Graph = std::vector<std::vector<Edge<T>>>;\r\
    \n\r\nusing graph = std::vector<std::vector<int>>;\r\n\r\n} // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: graph/template.hpp
  requiredBy:
  - graph/dijkstra.hpp
  timestamp: '2021-01-18 10:56:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/dijkstra.test.cpp
documentation_of: graph/template.hpp
layout: document
redirect_from:
- /library/graph/template.hpp
- /library/graph/template.hpp.html
title: graph/template.hpp
---
