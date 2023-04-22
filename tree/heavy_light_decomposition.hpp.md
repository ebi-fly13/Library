---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/vertex_add_path_sum.test.cpp
    title: test/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_add_subtree_sum.test.cpp
    title: test/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_set_path_compositie.test.cpp
    title: test/vertex_set_path_compositie.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/heavy_light_decomposition.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n\nnamespace ebi {\n\nstruct heavy_light_decomposition {\n \
    \  private:\n    void dfs_sz(int v) {\n        for (auto &nv : g[v]) {\n     \
    \       if (nv == par[v]) continue;\n            par[nv] = v;\n            depth[nv]\
    \ = depth[v] + 1;\n            dfs_sz(nv);\n            sz[v] += sz[nv];\n   \
    \         if (sz[nv] > sz[g[v][0]] || g[v][0] == par[v])\n                std::swap(nv,\
    \ g[v][0]);\n        }\n    }\n\n    void dfs_hld(int v) {\n        static int\
    \ t = 0;\n        in[v] = t++;\n        for (auto nv : g[v]) {\n            if\
    \ (nv == par[v]) continue;\n            nxt[nv] = (nv == g[v][0] ? nxt[v] : nv);\n\
    \            dfs_hld(nv);\n        }\n        out[v] = t;\n    }\n\n    // [u,\
    \ v) \u30D1\u30B9\u306E\u53D6\u5F97 (v \u306F u \u306E\u7956\u5148)\n    std::vector<std::pair<int,\
    \ int>> ascend(int u, int v) const {\n        std::vector<std::pair<int, int>>\
    \ res;\n        while (nxt[u] != nxt[v]) {\n            res.emplace_back(in[u],\
    \ in[nxt[u]]);\n            u = par[nxt[u]];\n        }\n        if (u != v) res.emplace_back(in[u],\
    \ in[v] + 1);\n        return res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\
    \u5F97 (u \u306F v \u306E\u7956\u5148)\n    std::vector<std::pair<int, int>> descend(int\
    \ u, int v) const {\n        if (u == v) return {};\n        if (nxt[u] == nxt[v])\
    \ return {{in[u] + 1, in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n\
    \        res.emplace_back(in[nxt[v]], in[v]);\n        return res;\n    }\n\n\
    \   public:\n    heavy_light_decomposition(const std::vector<std::vector<int>>\
    \ &gh,\n                              int root = 0)\n        : n(gh.size()),\n\
    \          g(gh),\n          sz(n, 1),\n          in(n),\n          out(n),\n\
    \          nxt(n),\n          par(n, -1),\n          depth(n, 0) {\n        dfs_sz(root);\n\
    \        dfs_hld(root);\n    }\n\n    int idx(int u) const { return in[u]; }\n\
    \n    int lca(int u, int v) const {\n        while (nxt[u] != nxt[v]) {\n    \
    \        if (in[u] < in[v]) std::swap(u, v);\n            u = par[nxt[u]];\n \
    \       }\n        return depth[u] < depth[v] ? u : v;\n    }\n\n    int distance(int\
    \ u, int v) const {\n        return depth[u] + depth[v] - 2 * depth[lca(u, v)];\n\
    \    }\n\n    template <class F>\n    void path_noncommutative_query(int u, int\
    \ v, const F &f) const {\n        int l = lca(u, v);\n        for (auto [a, b]\
    \ : ascend(u, l)) f(a + 1, b);\n        f(in[l], in[l] + 1);\n        for (auto\
    \ [a, b] : descend(l, v)) f(a, b + 1);\n    }\n\n    template <class F>\n    void\
    \ subtree_query(int u, bool vertex, const F &f) {\n        f(in[u] + int(!vertex),\
    \ out[u]);\n    }\n\n   private:\n    int n;\n    std::vector<std::vector<int>>\
    \ g;\n    std::vector<int> sz, in, out, nxt, par, depth;\n};\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <iostream>\n#include <vector>\n\nnamespace ebi {\n\
    \nstruct heavy_light_decomposition {\n   private:\n    void dfs_sz(int v) {\n\
    \        for (auto &nv : g[v]) {\n            if (nv == par[v]) continue;\n  \
    \          par[nv] = v;\n            depth[nv] = depth[v] + 1;\n            dfs_sz(nv);\n\
    \            sz[v] += sz[nv];\n            if (sz[nv] > sz[g[v][0]] || g[v][0]\
    \ == par[v])\n                std::swap(nv, g[v][0]);\n        }\n    }\n\n  \
    \  void dfs_hld(int v) {\n        static int t = 0;\n        in[v] = t++;\n  \
    \      for (auto nv : g[v]) {\n            if (nv == par[v]) continue;\n     \
    \       nxt[nv] = (nv == g[v][0] ? nxt[v] : nv);\n            dfs_hld(nv);\n \
    \       }\n        out[v] = t;\n    }\n\n    // [u, v) \u30D1\u30B9\u306E\u53D6\
    \u5F97 (v \u306F u \u306E\u7956\u5148)\n    std::vector<std::pair<int, int>> ascend(int\
    \ u, int v) const {\n        std::vector<std::pair<int, int>> res;\n        while\
    \ (nxt[u] != nxt[v]) {\n            res.emplace_back(in[u], in[nxt[u]]);\n   \
    \         u = par[nxt[u]];\n        }\n        if (u != v) res.emplace_back(in[u],\
    \ in[v] + 1);\n        return res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\
    \u5F97 (u \u306F v \u306E\u7956\u5148)\n    std::vector<std::pair<int, int>> descend(int\
    \ u, int v) const {\n        if (u == v) return {};\n        if (nxt[u] == nxt[v])\
    \ return {{in[u] + 1, in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n\
    \        res.emplace_back(in[nxt[v]], in[v]);\n        return res;\n    }\n\n\
    \   public:\n    heavy_light_decomposition(const std::vector<std::vector<int>>\
    \ &gh,\n                              int root = 0)\n        : n(gh.size()),\n\
    \          g(gh),\n          sz(n, 1),\n          in(n),\n          out(n),\n\
    \          nxt(n),\n          par(n, -1),\n          depth(n, 0) {\n        dfs_sz(root);\n\
    \        dfs_hld(root);\n    }\n\n    int idx(int u) const { return in[u]; }\n\
    \n    int lca(int u, int v) const {\n        while (nxt[u] != nxt[v]) {\n    \
    \        if (in[u] < in[v]) std::swap(u, v);\n            u = par[nxt[u]];\n \
    \       }\n        return depth[u] < depth[v] ? u : v;\n    }\n\n    int distance(int\
    \ u, int v) const {\n        return depth[u] + depth[v] - 2 * depth[lca(u, v)];\n\
    \    }\n\n    template <class F>\n    void path_noncommutative_query(int u, int\
    \ v, const F &f) const {\n        int l = lca(u, v);\n        for (auto [a, b]\
    \ : ascend(u, l)) f(a + 1, b);\n        f(in[l], in[l] + 1);\n        for (auto\
    \ [a, b] : descend(l, v)) f(a, b + 1);\n    }\n\n    template <class F>\n    void\
    \ subtree_query(int u, bool vertex, const F &f) {\n        f(in[u] + int(!vertex),\
    \ out[u]);\n    }\n\n   private:\n    int n;\n    std::vector<std::vector<int>>\
    \ g;\n    std::vector<int> sz, in, out, nxt, par, depth;\n};\n\n}  // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: tree/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2023-04-22 18:39:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/vertex_add_path_sum.test.cpp
  - test/vertex_set_path_compositie.test.cpp
  - test/vertex_add_subtree_sum.test.cpp
documentation_of: tree/heavy_light_decomposition.hpp
layout: document
redirect_from:
- /library/tree/heavy_light_decomposition.hpp
- /library/tree/heavy_light_decomposition.hpp.html
title: tree/heavy_light_decomposition.hpp
---
