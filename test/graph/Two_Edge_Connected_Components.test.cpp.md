---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/low_link.hpp
    title: Low Link
  - icon: ':heavy_check_mark:'
    path: graph/two_edge_connected_components.hpp
    title: Two Edge Connected Components
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/graph/Two_Edge_Connected_Components.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\n\n\
    #line 2 \"graph/two_edge_connected_components.hpp\"\n\n#line 2 \"graph/low_link.hpp\"\
    \n\n#include <algorithm>\n#include <utility>\n#include <vector>\n\nnamespace ebi\
    \ {\n\nstruct low_link {\n  private:\n    void dfs(int v, int par = -1) {\n  \
    \      static int k = 0;\n        low[v] = ord[v] = k++;\n        int cnt = 0;\n\
    \        bool is_arti = false, is_second = false;\n        for (auto nv : g[v])\
    \ {\n            if (ord[nv] == -1) {\n                cnt++;\n              \
    \  dfs(nv, v);\n                low[v] = std::min(low[v], low[nv]);\n        \
    \        is_arti |= (par != -1) && (low[nv] >= ord[v]);\n                if (ord[v]\
    \ < low[nv]) {\n                    _bridge.emplace_back(std::minmax(v, nv));\n\
    \                }\n            } else if (nv != par || is_second) {\n       \
    \         low[v] = std::min(low[v], ord[nv]);\n            } else {\n        \
    \        is_second = true;\n            }\n        }\n        is_arti |= par ==\
    \ -1 && cnt > 1;\n        if (is_arti) _articulation.emplace_back(v);\n    }\n\
    \n  public:\n    low_link(const std::vector<std::vector<int>> &g)\n        : n(g.size()),\
    \ g(g), ord(n, -1), low(n) {\n        for (int i = 0; i < n; i++) {\n        \
    \    if (ord[i] == -1) dfs(i);\n        }\n    }\n\n    std::vector<int> articulation()\
    \ const {\n        return _articulation;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> bridge() const {\n        return _bridge;\n    }\n\n  protected:\n   \
    \ int n;\n    std::vector<std::vector<int>> g;\n    std::vector<int> ord, low,\
    \ _articulation;\n    std::vector<std::pair<int, int>> _bridge;\n};\n\n}  // namespace\
    \ ebi\n#line 4 \"graph/two_edge_connected_components.hpp\"\n\nnamespace ebi {\n\
    \nstruct two_edge_connected_components : low_link {\n  private:\n    void dfs(int\
    \ v, int par = -1) {\n        if (par != -1 && this->ord[par] >= this->low[v])\n\
    \            id[v] = id[par];\n        else\n            id[v] = k++;\n      \
    \  for (auto nv : this->g[v]) {\n            if (id[nv] == -1) dfs(nv, v);\n \
    \       }\n    }\n\n  public:\n    two_edge_connected_components(const std::vector<std::vector<int>>\
    \ &_g)\n        : low_link(_g), id(this->n, -1) {\n        for (int i = 0; i <\
    \ this->n; i++) {\n            if (id[i] == -1) dfs(i);\n        }\n        t.resize(k);\n\
    \        for (auto [u, v] : this->_bridge) {\n            u = id[u];\n       \
    \     v = id[v];\n            t[u].emplace_back(v);\n            t[v].emplace_back(u);\n\
    \        }\n    }\n\n    std::vector<std::vector<int>> tecc() const {\n      \
    \  return t;\n    }\n\n    std::vector<std::vector<int>> groups() const {\n  \
    \      std::vector _groups(k, std::vector<int>());\n        for (int i = 0; i\
    \ < n; i++) {\n            _groups[id[i]].emplace_back(i);\n        }\n      \
    \  return _groups;\n    }\n\n  private:\n    int k = 0;\n    std::vector<int>\
    \ id;\n    std::vector<std::vector<int>> t;\n};\n\n}  // namespace ebi\n#line\
    \ 4 \"test/graph/Two_Edge_Connected_Components.test.cpp\"\n\n#include <iostream>\n\
    #line 7 \"test/graph/Two_Edge_Connected_Components.test.cpp\"\n\nint main() {\n\
    \    int n, m;\n    std::cin >> n >> m;\n    std::vector g(n, std::vector<int>());\n\
    \    for (int i = 0; i < m; i++) {\n        int a, b;\n        std::cin >> a >>\
    \ b;\n        g[a].emplace_back(b);\n        g[b].emplace_back(a);\n    }\n  \
    \  ebi::two_edge_connected_components tecc(g);\n    auto groups = tecc.groups();\n\
    \    std::cout << groups.size() << '\\n';\n    for (auto group : groups) {\n \
    \       std::cout << group.size();\n        for (auto v : group) {\n         \
    \   std::cout << \" \" << v;\n        }\n        std::cout << '\\n';\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include \"../../graph/two_edge_connected_components.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n\nint main() {\n    int n, m;\n    std::cin >> n >> m;\n  \
    \  std::vector g(n, std::vector<int>());\n    for (int i = 0; i < m; i++) {\n\
    \        int a, b;\n        std::cin >> a >> b;\n        g[a].emplace_back(b);\n\
    \        g[b].emplace_back(a);\n    }\n    ebi::two_edge_connected_components\
    \ tecc(g);\n    auto groups = tecc.groups();\n    std::cout << groups.size() <<\
    \ '\\n';\n    for (auto group : groups) {\n        std::cout << group.size();\n\
    \        for (auto v : group) {\n            std::cout << \" \" << v;\n      \
    \  }\n        std::cout << '\\n';\n    }\n}"
  dependsOn:
  - graph/two_edge_connected_components.hpp
  - graph/low_link.hpp
  isVerificationFile: true
  path: test/graph/Two_Edge_Connected_Components.test.cpp
  requiredBy: []
  timestamp: '2023-07-11 11:01:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/Two_Edge_Connected_Components.test.cpp
layout: document
redirect_from:
- /verify/test/graph/Two_Edge_Connected_Components.test.cpp
- /verify/test/graph/Two_Edge_Connected_Components.test.cpp.html
title: test/graph/Two_Edge_Connected_Components.test.cpp
---
