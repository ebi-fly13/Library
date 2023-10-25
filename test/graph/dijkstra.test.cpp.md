---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':question:'
    path: graph/template.hpp
    title: graph/template.hpp
  - icon: ':question:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"test/graph/dijkstra.test.cpp\"\n#define PROBLEM \\\r\n \
    \   \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\r\n\r\
    \n#line 2 \"graph/dijkstra.hpp\"\n\r\n#include <limits>\r\n#include <queue>\r\n\
    #include <vector>\r\n\r\n#line 2 \"graph/template.hpp\"\n\r\n#line 4 \"graph/template.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class T> struct Edge {\r\n    int to;\r\
    \n    T cost;\r\n    Edge(int _to, T _cost = 1) : to(_to), cost(_cost) {}\r\n\
    };\r\n\r\ntemplate <class T> struct Graph : std::vector<std::vector<Edge<T>>>\
    \ {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\n    void add_edge(int\
    \ u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if (directed) return;\r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if (directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\n#line 8 \"graph/dijkstra.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate <class\
    \ T> std::vector<T> dijkstra(int s, int n, const Graph<T> &g) {\r\n    typedef\
    \ std::pair<T, int> P;\r\n    std::vector<T> d(n, std::numeric_limits<T>::max());\r\
    \n    std::priority_queue<P, std::vector<P>, std::greater<P>> que;\r\n    que.push(P(0,\
    \ s));\r\n    d[s] = 0;\r\n    while (!que.empty()) {\r\n        auto [ret, v]\
    \ = que.top();\r\n        que.pop();\r\n        if (d[v] < ret) continue;\r\n\
    \        for (auto e : g[v]) {\r\n            if (d[e.to] > d[v] + e.cost) {\r\
    \n                d[e.to] = d[v] + e.cost;\r\n                que.push(P(d[e.to],\
    \ e.to));\r\n            }\r\n        }\r\n    }\r\n    return d;\r\n}\r\n\r\n\
    }  // namespace ebi\n#line 5 \"test/graph/dijkstra.test.cpp\"\n\r\n#include <iostream>\r\
    \n#line 9 \"test/graph/dijkstra.test.cpp\"\n\r\n#line 2 \"template/int_alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace ebi {\n\nusing std::size_t;\nusing i8 = std::int8_t;\n\
    using u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing u16 = std::uint16_t;\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    \n}  // namespace ebi\n#line 12 \"test/graph/dijkstra.test.cpp\"\n\r\nusing ebi::i64;\r\
    \n\r\nint main() {\r\n    int v, e, r;\r\n    std::cin >> v >> e >> r;\r\n   \
    \ ebi::Graph<i64> g(v);\r\n    while (e--) {\r\n        int s, t;\r\n        i64\
    \ d;\r\n        std::cin >> s >> t >> d;\r\n        g[s].emplace_back(t, d);\r\
    \n    }\r\n    std::vector<i64> dest = ebi::dijkstra(r, v, g);\r\n    for (auto\
    \ di : dest) {\r\n        if (di == std::numeric_limits<i64>::max()) {\r\n   \
    \         std::cout << \"INF\" << std::endl;\r\n            continue;\r\n    \
    \    }\r\n        std::cout << di << std::endl;\r\n    }\r\n}\n"
  code: "#define PROBLEM \\\r\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \r\n\r\n#include \"../../graph/dijkstra.hpp\"\r\n\r\n#include <iostream>\r\n#include\
    \ <limits>\r\n#include <vector>\r\n\r\n#include \"../../graph/template.hpp\"\r\
    \n#include \"../../template/int_alias.hpp\"\r\n\r\nusing ebi::i64;\r\n\r\nint\
    \ main() {\r\n    int v, e, r;\r\n    std::cin >> v >> e >> r;\r\n    ebi::Graph<i64>\
    \ g(v);\r\n    while (e--) {\r\n        int s, t;\r\n        i64 d;\r\n      \
    \  std::cin >> s >> t >> d;\r\n        g[s].emplace_back(t, d);\r\n    }\r\n \
    \   std::vector<i64> dest = ebi::dijkstra(r, v, g);\r\n    for (auto di : dest)\
    \ {\r\n        if (di == std::numeric_limits<i64>::max()) {\r\n            std::cout\
    \ << \"INF\" << std::endl;\r\n            continue;\r\n        }\r\n        std::cout\
    \ << di << std::endl;\r\n    }\r\n}"
  dependsOn:
  - graph/dijkstra.hpp
  - graph/template.hpp
  - template/int_alias.hpp
  isVerificationFile: true
  path: test/graph/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2023-10-26 02:38:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/test/graph/dijkstra.test.cpp
- /verify/test/graph/dijkstra.test.cpp.html
title: test/graph/dijkstra.test.cpp
---
