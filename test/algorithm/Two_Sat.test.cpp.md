---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/two_sat.hpp
    title: algorithm/two_sat.hpp
  - icon: ':heavy_check_mark:'
    path: graph/scc_graph.hpp
    title: graph/scc_graph.hpp
  - icon: ':question:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/algorithm/Two_Sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n\n#line 2 \"algorithm/two_sat.hpp\"\n\n#include <cassert>\n\n#line 2 \"graph/scc_graph.hpp\"\
    \n\r\n#include <algorithm>\r\n#include <vector>\r\n\r\n#line 2 \"graph/template.hpp\"\
    \n\r\n#line 4 \"graph/template.hpp\"\n#include <iostream>\r\n\r\nnamespace ebi\
    \ {\r\n\r\ntemplate <class T> struct Edge {\r\n    int to;\r\n    T cost;\r\n\
    \    Edge(int _to, T _cost = 1) : to(_to), cost(_cost) {}\r\n};\r\n\r\ntemplate\
    \ <class T> struct Graph : std::vector<std::vector<Edge<T>>> {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\
    \n    void add_edge(int u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
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
    \ ebi\n#line 7 \"graph/scc_graph.hpp\"\n\r\nnamespace ebi {\r\n\r\nstruct scc_graph\
    \ {\r\n  private:\r\n    graph g, rg;\r\n    int n, k;\r\n\r\n    std::vector<int>\
    \ vs, cmp;\r\n    std::vector<bool> seen;\r\n\r\n    void dfs(int v) {\r\n   \
    \     seen[v] = true;\r\n        for (auto &nv : g[v]) {\r\n            if (!seen[nv])\
    \ dfs(nv);\r\n        }\r\n        vs.emplace_back(v);\r\n    }\r\n\r\n    void\
    \ rdfs(int v) {\r\n        cmp[v] = k;\r\n        for (auto nv : rg[v]) {\r\n\
    \            if (cmp[nv] < 0) {\r\n                rdfs(nv);\r\n            }\r\
    \n        }\r\n    }\r\n\r\n  public:\r\n    scc_graph(int n) : n(n) {\r\n   \
    \     g.resize(n);\r\n        rg.resize(n);\r\n    }\r\n\r\n    void add_edge(int\
    \ from, int to) {\r\n        g[from].emplace_back(to);\r\n        rg[to].emplace_back(from);\r\
    \n    }\r\n\r\n    std::vector<std::vector<int>> scc() {\r\n        seen.assign(n,\
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
    \n\r\n}  // namespace ebi\n#line 6 \"algorithm/two_sat.hpp\"\n\nnamespace ebi\
    \ {\n\nstruct two_sat {\n  public:\n    two_sat(int _n) : n(_n), scc(2 * n) {}\n\
    \n    void add_clause(int p, bool _p, int q, bool _q) {\n        assert(0 <= p\
    \ && p < n);\n        assert(0 <= q && q < n);\n        scc.add_edge(2 * p + (_p\
    \ ? 1 : 0), 2 * q + (_q ? 0 : 1));\n        scc.add_edge(2 * q + (_q ? 1 : 0),\
    \ 2 * p + (_p ? 0 : 1));\n    }\n\n    bool satisfiable() {\n        scc.scc();\n\
    \        std::vector<int> id = scc.scc_id();\n        _answer.resize(n);\n   \
    \     for (int i = 0; i < n; i++) {\n            if (id[2 * i] == id[2 * i + 1])\
    \ {\n                return false;\n            }\n            _answer[i] = id[2\
    \ * i] > id[2 * i + 1];\n        }\n        return true;\n    }\n\n    std::vector<bool>\
    \ answer() {\n        return _answer;\n    }\n\n  private:\n    int n;\n    scc_graph\
    \ scc;\n    std::vector<bool> _answer;\n};\n\n}  // namespace ebi\n#line 4 \"\
    test/algorithm/Two_Sat.test.cpp\"\n\n#line 6 \"test/algorithm/Two_Sat.test.cpp\"\
    \n\nint main() {\n    char p;\n    std::string cnf;\n    std::cin >> p >> cnf;\n\
    \    int n, m;\n    std::cin >> n >> m;\n    ebi::two_sat ts(n);\n    for (int\
    \ i = 0; i < m; i++) {\n        int a, b, c;\n        std::cin >> a >> b >> c;\n\
    \        ts.add_clause(std::abs(a) - 1, a > 0, std::abs(b) - 1, b > 0);\n    }\n\
    \    bool flag = ts.satisfiable();\n    std::cout << \"s \" << (flag ? \"SATISFIABLE\"\
    \ : \"UNSATISFIABLE\") << std::endl;\n    if (flag) {\n        std::cout << \"\
    v\";\n        auto ans = ts.answer();\n        for (int i = 0; i < n; i++) {\n\
    \            std::cout << \" \" << (ans[i] ? i + 1 : -(i + 1));\n        }\n \
    \       std::cout << \" 0\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include \"\
    ../../algorithm/two_sat.hpp\"\n\n#include <iostream>\n\nint main() {\n    char\
    \ p;\n    std::string cnf;\n    std::cin >> p >> cnf;\n    int n, m;\n    std::cin\
    \ >> n >> m;\n    ebi::two_sat ts(n);\n    for (int i = 0; i < m; i++) {\n   \
    \     int a, b, c;\n        std::cin >> a >> b >> c;\n        ts.add_clause(std::abs(a)\
    \ - 1, a > 0, std::abs(b) - 1, b > 0);\n    }\n    bool flag = ts.satisfiable();\n\
    \    std::cout << \"s \" << (flag ? \"SATISFIABLE\" : \"UNSATISFIABLE\") << std::endl;\n\
    \    if (flag) {\n        std::cout << \"v\";\n        auto ans = ts.answer();\n\
    \        for (int i = 0; i < n; i++) {\n            std::cout << \" \" << (ans[i]\
    \ ? i + 1 : -(i + 1));\n        }\n        std::cout << \" 0\\n\";\n    }\n}"
  dependsOn:
  - algorithm/two_sat.hpp
  - graph/scc_graph.hpp
  - graph/template.hpp
  isVerificationFile: true
  path: test/algorithm/Two_Sat.test.cpp
  requiredBy: []
  timestamp: '2024-03-08 14:06:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/algorithm/Two_Sat.test.cpp
layout: document
redirect_from:
- /verify/test/algorithm/Two_Sat.test.cpp
- /verify/test/algorithm/Two_Sat.test.cpp.html
title: test/algorithm/Two_Sat.test.cpp
---
