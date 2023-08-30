---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/template.hpp
    title: graph/template.hpp
  - icon: ':heavy_check_mark:'
    path: tree/level_ancestor.hpp
    title: Level Ancestor
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/tree/level_ancestor_lca.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\r\n\r\n#include <iostream>\r\n\r\n#line\
    \ 2 \"graph/template.hpp\"\n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\
    \ntemplate <class T> struct Edge {\r\n    int to;\r\n    T cost;\r\n    Edge(int\
    \ _to, T _cost = 1) : to(_to), cost(_cost) {}\r\n};\r\n\r\ntemplate <class T>\
    \ struct Graph : std::vector<std::vector<Edge<T>>> {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\
    \n    void add_edge(int u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if (directed) return;\r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if (directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\n#line 2 \"tree/level_ancestor.hpp\"\n\r\n#include <algorithm>\r\n#include\
    \ <cassert>\r\n#line 6 \"tree/level_ancestor.hpp\"\n\r\nnamespace ebi {\r\n\r\n\
    struct level_ancestor {\r\n  private:\r\n    int n;\r\n    std::vector<int> in;\r\
    \n    std::vector<int> inv_in;\r\n    std::vector<int> depths;\r\n    std::vector<std::vector<int>>\
    \ s;\r\n\r\n  public:\r\n    level_ancestor(const std::vector<std::vector<int>>\
    \ &gh, int root = 0)\r\n        : n(gh.size()), in(n), inv_in(n), depths(n) {\r\
    \n        int cnt = 0;\r\n        int max = 0;\r\n        auto dfs = [&](auto\
    \ &&self, int v, int par = -1) -> void {\r\n            inv_in[cnt] = v;\r\n \
    \           in[v] = cnt++;\r\n            max = std::max(max, depths[v]);\r\n\
    \            for (auto nv : gh[v])\r\n                if (nv != par) {\r\n   \
    \                 depths[nv] = depths[v] + 1;\r\n                    self(self,\
    \ nv, v);\r\n                }\r\n        };\r\n        dfs(dfs, root);\r\n  \
    \      s.resize(max + 1);\r\n        for (int i = 0; i < n; i++) {\r\n       \
    \     int u = inv_in[i];\r\n            s[depths[u]].emplace_back(i);\r\n    \
    \    }\r\n    }\r\n\r\n    int query(int u, int k) const {\r\n        int m =\
    \ depths[u] - k;\r\n        assert(m >= 0);\r\n        return inv_in[*std::prev(\r\
    \n            std::upper_bound(s[m].begin(), s[m].end(), in[u]))];\r\n    }\r\n\
    \r\n    int depth(int u) const {\r\n        return depths[u];\r\n    }\r\n};\r\
    \n\r\n}  // namespace ebi\n#line 7 \"test/tree/level_ancestor_lca.test.cpp\"\n\
    \r\nint main() {\r\n    int n, q;\r\n    std::cin >> n >> q;\r\n    ebi::graph\
    \ g(n);\r\n    for (int i = 1; i < n; i++) {\r\n        int p;\r\n        std::cin\
    \ >> p;\r\n        g.add_edge(p, i);\r\n    }\r\n    ebi::level_ancestor la(g);\r\
    \n    auto lca = [&](int u, int v) -> int {\r\n        if (la.depth(u) > la.depth(v))\
    \ std::swap(u, v);\r\n        v = la.query(v, la.depth(v) - la.depth(u));\r\n\
    \        int ng = -1, ok = la.depth(u);\r\n        while (std::abs(ok - ng) >\
    \ 1) {\r\n            int mid = (ok + ng) / 2;\r\n            if (la.query(u,\
    \ mid) == la.query(v, mid))\r\n                ok = mid;\r\n            else\r\
    \n                ng = mid;\r\n        }\r\n        return la.query(u, ok);\r\n\
    \    };\r\n    while (q--) {\r\n        int u, v;\r\n        std::cin >> u >>\
    \ v;\r\n        std::cout << lca(u, v) << '\\n';\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\r\n\r\n#include <iostream>\r\
    \n\r\n#include \"../../graph/template.hpp\"\r\n#include \"../../tree/level_ancestor.hpp\"\
    \r\n\r\nint main() {\r\n    int n, q;\r\n    std::cin >> n >> q;\r\n    ebi::graph\
    \ g(n);\r\n    for (int i = 1; i < n; i++) {\r\n        int p;\r\n        std::cin\
    \ >> p;\r\n        g.add_edge(p, i);\r\n    }\r\n    ebi::level_ancestor la(g);\r\
    \n    auto lca = [&](int u, int v) -> int {\r\n        if (la.depth(u) > la.depth(v))\
    \ std::swap(u, v);\r\n        v = la.query(v, la.depth(v) - la.depth(u));\r\n\
    \        int ng = -1, ok = la.depth(u);\r\n        while (std::abs(ok - ng) >\
    \ 1) {\r\n            int mid = (ok + ng) / 2;\r\n            if (la.query(u,\
    \ mid) == la.query(v, mid))\r\n                ok = mid;\r\n            else\r\
    \n                ng = mid;\r\n        }\r\n        return la.query(u, ok);\r\n\
    \    };\r\n    while (q--) {\r\n        int u, v;\r\n        std::cin >> u >>\
    \ v;\r\n        std::cout << lca(u, v) << '\\n';\r\n    }\r\n}"
  dependsOn:
  - graph/template.hpp
  - tree/level_ancestor.hpp
  isVerificationFile: true
  path: test/tree/level_ancestor_lca.test.cpp
  requiredBy: []
  timestamp: '2023-06-15 15:16:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/level_ancestor_lca.test.cpp
layout: document
redirect_from:
- /verify/test/tree/level_ancestor_lca.test.cpp
- /verify/test/tree/level_ancestor_lca.test.cpp.html
title: test/tree/level_ancestor_lca.test.cpp
---
