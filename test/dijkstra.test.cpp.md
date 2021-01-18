---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':question:'
    path: graph/template.hpp
    title: graph/template.hpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.hpp
    title: utility/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"test/dijkstra.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \r\n\r\n#line 2 \"graph/dijkstra.hpp\"\n\r\n#line 2 \"graph/template.hpp\"\n\r\
    \n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class T>\r\nstruct\
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
    \    }\r\n    return d;\r\n}\r\n\r\n} // namespace ebi\n#line 2 \"utility/int_alias.hpp\"\
    \n\r\n#include <cstddef>\r\n#include <cstdint>\r\n\r\nusing i32 = std::int32_t;\r\
    \nusing i64 = std::int64_t;\r\nusing u16 = std::uint16_t;\r\nusing u32 = std::uint32_t;\r\
    \nusing u64 = std::uint64_t;\r\nusing usize = std::size_t;\n#line 6 \"test/dijkstra.test.cpp\"\
    \n\r\n#include <iostream>\r\n#line 10 \"test/dijkstra.test.cpp\"\n\r\nint main()\
    \ {\r\n    int v,e,r;\r\n    std::cin >> v >> e >> r;\r\n    ebi::Graph<i64> g(v);\r\
    \n    while(e--){\r\n        int s,t;\r\n        i64 d;\r\n        std::cin >>\
    \ s >> t >> d;\r\n        g[s].emplace_back(t, d);\r\n    }\r\n    std::vector<i64>\
    \ dest = ebi::dijkstra(r, v, g);\r\n    for(auto di: dest){\r\n        if(di ==\
    \ std::numeric_limits<i64>::max()){\r\n            std::cout << \"INF\" << std::endl;\r\
    \n            continue;\r\n        }\r\n        std::cout << di << std::endl;\r\
    \n    }\r\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \r\n\r\n#include \"../graph/dijkstra.hpp\"\r\n#include \"../graph/template.hpp\"\
    \r\n#include \"../utility/int_alias.hpp\"\r\n\r\n#include <iostream>\r\n#include\
    \ <vector>\r\n#include <limits>\r\n\r\nint main() {\r\n    int v,e,r;\r\n    std::cin\
    \ >> v >> e >> r;\r\n    ebi::Graph<i64> g(v);\r\n    while(e--){\r\n        int\
    \ s,t;\r\n        i64 d;\r\n        std::cin >> s >> t >> d;\r\n        g[s].emplace_back(t,\
    \ d);\r\n    }\r\n    std::vector<i64> dest = ebi::dijkstra(r, v, g);\r\n    for(auto\
    \ di: dest){\r\n        if(di == std::numeric_limits<i64>::max()){\r\n       \
    \     std::cout << \"INF\" << std::endl;\r\n            continue;\r\n        }\r\
    \n        std::cout << di << std::endl;\r\n    }\r\n}"
  dependsOn:
  - graph/dijkstra.hpp
  - graph/template.hpp
  - utility/int_alias.hpp
  isVerificationFile: true
  path: test/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2021-01-18 10:56:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/test/dijkstra.test.cpp
- /verify/test/dijkstra.test.cpp.html
title: test/dijkstra.test.cpp
---
