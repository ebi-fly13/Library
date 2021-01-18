---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dijkstra.test.cpp
    title: test/dijkstra.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dijkstra.hpp\"\n\r\n#line 2 \"graph/template.hpp\"\
    \n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class T>\r\nstruct\
    \ Edge {\r\n    int to;\r\n    T cost;\r\n    Edge(int to, T cost=1) : to(to),\
    \ cost(cost) { }\r\n};\r\n\r\ntemplate<class T>\r\nusing Graph = std::vector<std::vector<Edge<T>>>;\r\
    \n\r\nusing graph = std::vector<std::vector<int>>;\r\n\r\n} // namespace ebi\n\
    #line 4 \"graph/dijkstra.hpp\"\n\r\n#line 6 \"graph/dijkstra.hpp\"\n#include <limits>\r\
    \n#include <queue>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class T>\r\nstd::vector<T>\
    \ dijkstra(int s, int n, const Graph<T> &g){\r\n    typedef std::pair<T, int>\
    \ P;\r\n    std::vector<T> d(n, std::numeric_limits<T>::max());\r\n    std::priority_queue<\
    \ P, std::vector<P>, std::greater<P>> que;\r\n    que.push(P(0, s));\r\n    d[s]\
    \ = 0;\r\n    while(!que.empty()){\r\n        auto [ret, v] = que.top();\r\n \
    \       que.pop();\r\n        if(d[v]<ret) continue;\r\n        for(auto e: g[v]){\r\
    \n            if(d[e.to]>d[v]+e.cost){\r\n                d[e.to] = d[v]+e.cost;\r\
    \n                que.push(P(d[e.to], e.to));\r\n            }\r\n        }\r\n\
    \    }\r\n    return d;\r\n}\r\n\r\n} // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include \"../graph/template.hpp\"\r\n\r\n#include <vector>\r\
    \n#include <limits>\r\n#include <queue>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class\
    \ T>\r\nstd::vector<T> dijkstra(int s, int n, const Graph<T> &g){\r\n    typedef\
    \ std::pair<T, int> P;\r\n    std::vector<T> d(n, std::numeric_limits<T>::max());\r\
    \n    std::priority_queue< P, std::vector<P>, std::greater<P>> que;\r\n    que.push(P(0,\
    \ s));\r\n    d[s] = 0;\r\n    while(!que.empty()){\r\n        auto [ret, v] =\
    \ que.top();\r\n        que.pop();\r\n        if(d[v]<ret) continue;\r\n     \
    \   for(auto e: g[v]){\r\n            if(d[e.to]>d[v]+e.cost){\r\n           \
    \     d[e.to] = d[v]+e.cost;\r\n                que.push(P(d[e.to], e.to));\r\n\
    \            }\r\n        }\r\n    }\r\n    return d;\r\n}\r\n\r\n} // namespace\
    \ ebi"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-01-18 10:56:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dijkstra.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: graph/dijkstra.hpp
---
