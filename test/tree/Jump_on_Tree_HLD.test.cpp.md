---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/template.hpp
    title: graph/template.hpp
  - icon: ':heavy_check_mark:'
    path: tree/heavy_light_decomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/jump_on_tree
    links:
    - https://judge.yosupo.jp/problem/jump_on_tree
  bundledCode: "#line 1 \"test/tree/Jump_on_Tree_HLD.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/jump_on_tree\"\n\n#include <iostream>\n\n#line\
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
    \ ebi\n#line 2 \"tree/heavy_light_decomposition.hpp\"\n\n#include <algorithm>\n\
    #line 6 \"tree/heavy_light_decomposition.hpp\"\n\nnamespace ebi {\n\nstruct heavy_light_decomposition\
    \ {\n  private:\n    void dfs_sz(int v) {\n        for (auto &nv : g[v]) {\n \
    \           if (nv == par[v]) continue;\n            par[nv] = v;\n          \
    \  depth[nv] = depth[v] + 1;\n            dfs_sz(nv);\n            sz[v] += sz[nv];\n\
    \            if (sz[nv] > sz[g[v][0]] || g[v][0] == par[v])\n                std::swap(nv,\
    \ g[v][0]);\n        }\n    }\n\n    void dfs_hld(int v) {\n        static int\
    \ t = 0;\n        in[v] = t++;\n        rev[in[v]] = v;\n        for (auto nv\
    \ : g[v]) {\n            if (nv == par[v]) continue;\n            nxt[nv] = (nv\
    \ == g[v][0] ? nxt[v] : nv);\n            dfs_hld(nv);\n        }\n        out[v]\
    \ = t;\n    }\n\n    // [u, v) \u30D1\u30B9\u306E\u53D6\u5F97 (v \u306F u \u306E\
    \u7956\u5148)\n    std::vector<std::pair<int, int>> ascend(int u, int v) const\
    \ {\n        std::vector<std::pair<int, int>> res;\n        while (nxt[u] != nxt[v])\
    \ {\n            res.emplace_back(in[u], in[nxt[u]]);\n            u = par[nxt[u]];\n\
    \        }\n        if (u != v) res.emplace_back(in[u], in[v] + 1);\n        return\
    \ res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\u5F97 (u \u306F v \u306E\
    \u7956\u5148)\n    std::vector<std::pair<int, int>> descend(int u, int v) const\
    \ {\n        if (u == v) return {};\n        if (nxt[u] == nxt[v]) return {{in[u]\
    \ + 1, in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n        res.emplace_back(in[nxt[v]],\
    \ in[v]);\n        return res;\n    }\n\n  public:\n    heavy_light_decomposition(const\
    \ std::vector<std::vector<int>> &gh,\n                              int root =\
    \ 0)\n        : n(gh.size()),\n          g(gh),\n          sz(n, 1),\n       \
    \   in(n),\n          out(n),\n          nxt(n),\n          par(n, -1),\n    \
    \      depth(n, 0),\n          rev(n) {\n        dfs_sz(root);\n        dfs_hld(root);\n\
    \    }\n\n    int idx(int u) const {\n        return in[u];\n    }\n\n    int\
    \ la(int v, int k) const {\n        while (1) {\n            int u = nxt[v];\n\
    \            if (in[u] <= in[v] - k) return rev[in[v] - k];\n            k -=\
    \ in[v] - in[u] + 1;\n            v = par[u];\n        }\n    }\n\n    int lca(int\
    \ u, int v) const {\n        while (nxt[u] != nxt[v]) {\n            if (in[u]\
    \ < in[v]) std::swap(u, v);\n            u = par[nxt[u]];\n        }\n       \
    \ return depth[u] < depth[v] ? u : v;\n    }\n\n    int jump(int s, int t, int\
    \ i) const {\n        if (i == 0) return s;\n        int l = lca(s, t);\n    \
    \    int d = depth[s] + depth[t] - depth[l] * 2;\n        if (d < i) return -1;\n\
    \        if (depth[s] - depth[l] >= i) return la(s, i);\n        i = d - i;\n\
    \        return la(t, i);\n    }\n\n    std::vector<int> path(int s, int t) const\
    \ {\n        int l = lca(s, t);\n        std::vector<int> a, b;\n        for (;\
    \ s != l; s = par[s]) a.emplace_back(s);\n        for (; t != l; t = par[t]) b.emplace_back(t);\n\
    \        a.emplace_back(l);\n        std::reverse(b.begin(), b.end());\n     \
    \   a.insert(a.end(), b.begin(), b.end());\n        return a;\n    }\n\n    int\
    \ distance(int u, int v) const {\n        return depth[u] + depth[v] - 2 * depth[lca(u,\
    \ v)];\n    }\n\n    bool at_path(int u, int v, int s) const {\n        return\
    \ distance(u, v) == distance(u, s) + distance(s, v);\n    }\n\n    template <class\
    \ F>\n    void path_noncommutative_query(int u, int v, bool vertex,\n        \
    \                           const F &f) const {\n        int l = lca(u, v);\n\
    \        for (auto [a, b] : ascend(u, l)) f(a + 1, b);\n        if (vertex) f(in[l],\
    \ in[l] + 1);\n        for (auto [a, b] : descend(l, v)) f(a, b + 1);\n    }\n\
    \n    template <class F> void subtree_query(int u, bool vertex, const F &f) {\n\
    \        f(in[u] + int(!vertex), out[u]);\n    }\n\n  private:\n    int n;\n \
    \   std::vector<std::vector<int>> g;\n    std::vector<int> sz, in, out, nxt, par,\
    \ depth, rev;\n};\n\n}  // namespace ebi\n#line 7 \"test/tree/Jump_on_Tree_HLD.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    ebi::graph g(n);\n\
    \    for (int i = 0; i < n - 1; i++) {\n        int a, b;\n        std::cin >>\
    \ a >> b;\n        g.add_edge(a, b);\n    }\n    ebi::heavy_light_decomposition\
    \ hld(g);\n    while (q--) {\n        int s, t, i;\n        std::cin >> s >> t\
    \ >> i;\n        std::cout << hld.jump(s, t, i) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\n\n#include\
    \ <iostream>\n\n#include \"../../graph/template.hpp\"\n#include \"../../tree/heavy_light_decomposition.hpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    ebi::graph g(n);\n\
    \    for (int i = 0; i < n - 1; i++) {\n        int a, b;\n        std::cin >>\
    \ a >> b;\n        g.add_edge(a, b);\n    }\n    ebi::heavy_light_decomposition\
    \ hld(g);\n    while (q--) {\n        int s, t, i;\n        std::cin >> s >> t\
    \ >> i;\n        std::cout << hld.jump(s, t, i) << '\\n';\n    }\n}"
  dependsOn:
  - graph/template.hpp
  - tree/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: test/tree/Jump_on_Tree_HLD.test.cpp
  requiredBy: []
  timestamp: '2023-07-11 13:12:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/Jump_on_Tree_HLD.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Jump_on_Tree_HLD.test.cpp
- /verify/test/tree/Jump_on_Tree_HLD.test.cpp.html
title: test/tree/Jump_on_Tree_HLD.test.cpp
---
