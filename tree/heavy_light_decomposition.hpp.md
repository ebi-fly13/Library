---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2450.test.cpp
    title: test/aoj/aoj_2450.test.cpp
  - icon: ':x:'
    path: test/vertex_add_path_sum.test.cpp
    title: test/vertex_add_path_sum.test.cpp
  - icon: ':x:'
    path: test/vertex_add_subtree_sum.test.cpp
    title: test/vertex_add_subtree_sum.test.cpp
  - icon: ':x:'
    path: test/vertex_set_path_compositie.test.cpp
    title: test/vertex_set_path_compositie.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ v, bool vertex, const F &f) const {\n        int l = lca(u, v);\n        for\
    \ (auto [a, b] : ascend(u, l)) f(a + 1, b);\n        if(vertex) f(in[l], in[l]\
    \ + 1);\n        for (auto [a, b] : descend(l, v)) f(a, b + 1);\n    }\n\n   \
    \ template <class F>\n    void subtree_query(int u, bool vertex, const F &f) {\n\
    \        f(in[u] + int(!vertex), out[u]);\n    }\n\n   private:\n    int n;\n\
    \    std::vector<std::vector<int>> g;\n    std::vector<int> sz, in, out, nxt,\
    \ par, depth;\n};\n\n}  // namespace ebi\n"
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
    \ v, bool vertex, const F &f) const {\n        int l = lca(u, v);\n        for\
    \ (auto [a, b] : ascend(u, l)) f(a + 1, b);\n        if(vertex) f(in[l], in[l]\
    \ + 1);\n        for (auto [a, b] : descend(l, v)) f(a, b + 1);\n    }\n\n   \
    \ template <class F>\n    void subtree_query(int u, bool vertex, const F &f) {\n\
    \        f(in[u] + int(!vertex), out[u]);\n    }\n\n   private:\n    int n;\n\
    \    std::vector<std::vector<int>> g;\n    std::vector<int> sz, in, out, nxt,\
    \ par, depth;\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: tree/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2023-04-24 21:46:33+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/vertex_add_subtree_sum.test.cpp
  - test/vertex_add_path_sum.test.cpp
  - test/aoj/aoj_2450.test.cpp
  - test/vertex_set_path_compositie.test.cpp
documentation_of: tree/heavy_light_decomposition.hpp
layout: document
title: heavy light decomposition
---

## 説明

木をHLDする。パスクエリ、部分木クエリを処理することができる。

### コンストラクタ

`HeavyLightDecomposition(std::vector<std::vector<int>> g, int root = 0)`

木グラフ g と root ノード番号を与えてHLDする。デフォルトで root は頂点 0

### idx(int u)

頂点 u のDFS行きがけ順の番号を返す。このidxの位置にデータ構造のインデックスを対応させればパスクエリや部分木クエリを処理することができる。具体的には使い方を参照。

### lca(int u, int v)

頂点 u, v のLCAを返す。

### distance(int u, int v)

頂点 u, v の距離を返す。

### path_noncommutative_query(int u, int v, bool vertex, const F &f)

パス u-v にクエリ`f`を適用する。非可換。vertexがtrueのとき、頂点に属性がある。vertexがfalseのとき、辺に属性がある。親-子間の辺属性は子のidxに持つ。

### subtree_query(int u, bool vertex, const F &f)

頂点 u の部分木にクエリ`f`を適用する。vertexがtrueのとき、根頂点である u にもクエリを適用する。

## 使い方

```
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    rep(i,0,m) {
        int u,v;
        std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    lib::HeavyLightDecomposition hld(g);
    segtree<S, op, e> seg1(n) 
    segtree<S, op_rev, e> seg2(n);
    auto set = [&](int u, S x) {
        int idx = hld.idx(u);
        seg1.set(idx, x);
        seg2.set(idx, x);
    };
    S ans = e();
    auto f = [&](int l, int r) {
        if(l <= r) ans = op(ans, seg1.prod(l, r));
        else ans = op(ans, seg2.prod(r, l)); 
    };
    int u,v;
    std::cin >> u >> v;
    ans = e();
    hld.path_noncommutative_query(u, v, true, f);
    std::cout << ans << '\n';
}
```
