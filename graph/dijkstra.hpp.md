---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dijkstra.test.cpp
    title: test/dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dijkstra.hpp\"\n\r\n#line 2 \"graph/template.hpp\"\
    \n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class T>\r\nstruct\
    \ Edge {\r\n    int to;\r\n    T cost;\r\n    Edge(int _to, T _cost=1) : to(_to),\
    \ cost(_cost) { }\r\n};\r\n\r\ntemplate<class T>\r\nstruct Graph : std::vector<std::vector<Edge<T>>>\
    \ {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\n    void add_edge(int\
    \ u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if(directed) return; \r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if(directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n} // namespace\
    \ ebi\n#line 4 \"graph/dijkstra.hpp\"\n\r\n#line 6 \"graph/dijkstra.hpp\"\n#include\
    \ <limits>\r\n#include <queue>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class T>\r\
    \nstd::vector<T> dijkstra(int s, int n, const Graph<T> &g){\r\n    typedef std::pair<T,\
    \ int> P;\r\n    std::vector<T> d(n, std::numeric_limits<T>::max());\r\n    std::priority_queue<\
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
  timestamp: '2021-10-31 15:43:33+09:00'
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
