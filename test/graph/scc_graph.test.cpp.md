---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/scc_graph.hpp
    title: graph/scc_graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/graph/scc_graph.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \r\n\r\n#line 2 \"graph/scc_graph.hpp\"\n\r\n#line 2 \"graph/template.hpp\"\n\r\
    \n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class T> struct Edge\
    \ {\r\n    int to;\r\n    T cost;\r\n    Edge(int _to, T _cost = 1) : to(_to),\
    \ cost(_cost) {}\r\n};\r\n\r\ntemplate <class T> struct Graph : std::vector<std::vector<Edge<T>>>\
    \ {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\n    void add_edge(int\
    \ u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if (directed) return;\r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if (directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\n#line 4 \"graph/scc_graph.hpp\"\n\r\n#include <algorithm>\r\n#line 7 \"\
    graph/scc_graph.hpp\"\n\r\nnamespace ebi {\r\n\r\nstruct scc_graph {\r\n  private:\r\
    \n    graph g, rg;\r\n    int n, k;\r\n\r\n    std::vector<int> vs, cmp;\r\n \
    \   std::vector<bool> seen;\r\n\r\n    void dfs(int v) {\r\n        seen[v] =\
    \ true;\r\n        for (auto &nv : g[v]) {\r\n            if (!seen[nv]) dfs(nv);\r\
    \n        }\r\n        vs.emplace_back(v);\r\n    }\r\n\r\n    void rdfs(int v)\
    \ {\r\n        cmp[v] = k;\r\n        for (auto nv : rg[v]) {\r\n            if\
    \ (cmp[nv] < 0) {\r\n                rdfs(nv);\r\n            }\r\n        }\r\
    \n    }\r\n\r\n  public:\r\n    scc_graph(int n) : n(n) {\r\n        g.resize(n);\r\
    \n        rg.resize(n);\r\n    }\r\n\r\n    void add_edge(int from, int to) {\r\
    \n        g[from].emplace_back(to);\r\n        rg[to].emplace_back(from);\r\n\
    \    }\r\n\r\n    std::vector<std::vector<int>> scc() {\r\n        seen.assign(n,\
    \ false);\r\n        for (int i = 0; i < n; i++) {\r\n            if (!seen[i])\
    \ {\r\n                dfs(i);\r\n            }\r\n        }\r\n        std::reverse(vs.begin(),\
    \ vs.end());\r\n        cmp.assign(n, -1);\r\n        k = 0;\r\n        for (auto\
    \ &v : vs) {\r\n            if (cmp[v] < 0) {\r\n                rdfs(v);\r\n\
    \                k++;\r\n            }\r\n        }\r\n        std::vector<std::vector<int>>\
    \ res(k);\r\n        for (int i = 0; i < n; i++) {\r\n            res[cmp[i]].emplace_back(i);\r\
    \n        }\r\n        return res;\r\n    }\r\n\r\n    std::vector<int> scc_id()\
    \ {\r\n        return cmp;\r\n    }\r\n\r\n    bool same(int u, int v) {\r\n \
    \       return cmp[u] == cmp[v];\r\n    }\r\n\r\n    graph create_graph() {\r\n\
    \        graph t(k);\r\n        for (int i = 0; i < n; i++) {\r\n            int\
    \ v = cmp[i];\r\n            for (auto to : g[i]) {\r\n                int nv\
    \ = cmp[to];\r\n                if (v == nv) continue;\r\n                t[v].emplace_back(nv);\r\
    \n            }\r\n        }\r\n        for (int i = 0; i < k; i++) {\r\n    \
    \        std::sort(t[i].begin(), t[i].end());\r\n            t[i].erase(std::unique(t[i].begin(),\
    \ t[i].end()), t[i].end());\r\n        }\r\n        return t;\r\n    }\r\n};\r\
    \n\r\n}  // namespace ebi\n#line 4 \"test/graph/scc_graph.test.cpp\"\n\r\n#include\
    \ <iostream>\r\n\r\n#line 8 \"test/graph/scc_graph.test.cpp\"\n\r\nint main()\
    \ {\r\n    int n, m;\r\n    std::cin >> n >> m;\r\n    ebi::scc_graph g(n);\r\n\
    \    for (int i = 0; i < m; ++i) {\r\n        int a, b;\r\n        std::cin >>\
    \ a >> b;\r\n        g.add_edge(a, b);\r\n    }\r\n    auto scc = g.scc();\r\n\
    \    int sz = scc.size();\r\n    std::cout << sz << '\\n';\r\n    for (int i =\
    \ 0; i < sz; ++i) {\r\n        std::cout << scc[i].size();\r\n        for (auto\
    \ v : scc[i]) {\r\n            std::cout << \" \" << v;\r\n        }\r\n     \
    \   std::cout << '\\n';\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\r\n\r\n#include \"\
    ../../graph/scc_graph.hpp\"\r\n\r\n#include <iostream>\r\n\r\n#include \"../../graph/template.hpp\"\
    \r\n\r\nint main() {\r\n    int n, m;\r\n    std::cin >> n >> m;\r\n    ebi::scc_graph\
    \ g(n);\r\n    for (int i = 0; i < m; ++i) {\r\n        int a, b;\r\n        std::cin\
    \ >> a >> b;\r\n        g.add_edge(a, b);\r\n    }\r\n    auto scc = g.scc();\r\
    \n    int sz = scc.size();\r\n    std::cout << sz << '\\n';\r\n    for (int i\
    \ = 0; i < sz; ++i) {\r\n        std::cout << scc[i].size();\r\n        for (auto\
    \ v : scc[i]) {\r\n            std::cout << \" \" << v;\r\n        }\r\n     \
    \   std::cout << '\\n';\r\n    }\r\n}"
  dependsOn:
  - graph/scc_graph.hpp
  - graph/template.hpp
  isVerificationFile: true
  path: test/graph/scc_graph.test.cpp
  requiredBy: []
  timestamp: '2023-07-10 01:20:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/scc_graph.test.cpp
layout: document
redirect_from:
- /verify/test/graph/scc_graph.test.cpp
- /verify/test/graph/scc_graph.test.cpp.html
title: test/graph/scc_graph.test.cpp
---