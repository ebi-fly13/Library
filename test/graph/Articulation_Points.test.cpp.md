---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/low_link.hpp
    title: Low Link
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
  bundledCode: "#line 1 \"test/graph/Articulation_Points.test.cpp\"\n#define PROBLEM\
    \ \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n#line 2 \"\
    graph/low_link.hpp\"\n\n#line 4 \"graph/low_link.hpp\"\n#include <utility>\n#line\
    \ 6 \"graph/low_link.hpp\"\n\nnamespace ebi {\n\nstruct low_link {\n  private:\n\
    \    void dfs(int v, int par = -1) {\n        static int k = 0;\n        low[v]\
    \ = ord[v] = k++;\n        int cnt = 0;\n        bool is_arti = false, is_second\
    \ = false;\n        for (auto nv : g[v]) {\n            if (ord[nv] == -1) {\n\
    \                cnt++;\n                dfs(nv, v);\n                low[v] =\
    \ std::min(low[v], low[nv]);\n                is_arti |= (par != -1) && (low[nv]\
    \ >= ord[v]);\n                if (ord[v] < low[nv]) {\n                    _bridge.emplace_back(std::minmax(v,\
    \ nv));\n                }\n            } else if (nv != par || is_second) {\n\
    \                low[v] = std::min(low[v], ord[nv]);\n            } else {\n \
    \               is_second = true;\n            }\n        }\n        is_arti |=\
    \ par == -1 && cnt > 1;\n        if (is_arti) _articulation.emplace_back(v);\n\
    \    }\n\n  public:\n    low_link(const std::vector<std::vector<int>> &g)\n  \
    \      : n(g.size()), g(g), ord(n, -1), low(n) {\n        for (int i = 0; i <\
    \ n; i++) {\n            if (ord[i] == -1) dfs(i);\n        }\n    }\n\n    std::vector<int>\
    \ articulation() const {\n        return _articulation;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> bridge() const {\n        return _bridge;\n    }\n\n  protected:\n   \
    \ int n;\n    std::vector<std::vector<int>> g;\n    std::vector<int> ord, low,\
    \ _articulation;\n    std::vector<std::pair<int, int>> _bridge;\n};\n\n}  // namespace\
    \ ebi\n#line 9 \"test/graph/Articulation_Points.test.cpp\"\n\nint main() {\n \
    \   int n, m;\n    std::cin >> n >> m;\n    std::vector<std::vector<int>> g(n);\n\
    \    for (int i = 0; i < m; i++) {\n        int a, b;\n        std::cin >> a >>\
    \ b;\n        g[a].emplace_back(b);\n        g[b].emplace_back(a);\n    }\n  \
    \  ebi::low_link low(g);\n    auto arti = low.articulation();\n    std::sort(arti.begin(),\
    \ arti.end());\n    for (auto v : arti) {\n        std::cout << v << '\\n';\n\
    \    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n#include \"\
    ../../graph/low_link.hpp\"\n\nint main() {\n    int n, m;\n    std::cin >> n >>\
    \ m;\n    std::vector<std::vector<int>> g(n);\n    for (int i = 0; i < m; i++)\
    \ {\n        int a, b;\n        std::cin >> a >> b;\n        g[a].emplace_back(b);\n\
    \        g[b].emplace_back(a);\n    }\n    ebi::low_link low(g);\n    auto arti\
    \ = low.articulation();\n    std::sort(arti.begin(), arti.end());\n    for (auto\
    \ v : arti) {\n        std::cout << v << '\\n';\n    }\n}"
  dependsOn:
  - graph/low_link.hpp
  isVerificationFile: true
  path: test/graph/Articulation_Points.test.cpp
  requiredBy: []
  timestamp: '2023-07-10 11:25:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Articulation_Points.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Articulation_Points.test.cpp
- /verify/test/graph/Articulation_Points.test.cpp.html
title: test/graph/Articulation_Points.test.cpp
---
