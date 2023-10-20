---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2450.test.cpp
    title: test/aoj/aoj_2450.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Vertex_Add_Path_Sum.test.cpp
    title: test/data_structure/Vertex_Add_Path_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Vertex_Add_Subtree_Sum.test.cpp
    title: test/data_structure/Vertex_Add_Subtree_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Vertex_Set_Path_Compositie.test.cpp
    title: test/data_structure/Vertex_Set_Path_Compositie.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Jump_on_Tree_HLD.test.cpp
    title: test/tree/Jump_on_Tree_HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_2439.test.cpp
    title: test/yuki/yuki_2439.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/heavy_light_decomposition.hpp\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <vector>\n\nnamespace ebi {\n\nstruct heavy_light_decomposition\
    \ {\n  private:\n    void dfs_sz(int v) {\n        for (auto &nv : g[v]) {\n \
    \           if (nv == par[v]) continue;\n            par[nv] = v;\n          \
    \  depth[nv] = depth[v] + 1;\n            dfs_sz(nv);\n            sz[v] += sz[nv];\n\
    \            if (sz[nv] > sz[g[v][0]] || g[v][0] == par[v])\n                std::swap(nv,\
    \ g[v][0]);\n        }\n    }\n\n    void dfs_hld(int v) {\n        in[v] = t++;\n\
    \        rev[in[v]] = v;\n        for (auto nv : g[v]) {\n            if (nv ==\
    \ par[v]) continue;\n            nxt[nv] = (nv == g[v][0] ? nxt[v] : nv);\n  \
    \          dfs_hld(nv);\n        }\n        out[v] = t;\n    }\n\n    // [u, v)\
    \ \u30D1\u30B9\u306E\u53D6\u5F97 (v \u306F u \u306E\u7956\u5148)\n    std::vector<std::pair<int,\
    \ int>> ascend(int u, int v) const {\n        std::vector<std::pair<int, int>>\
    \ res;\n        while (nxt[u] != nxt[v]) {\n            res.emplace_back(in[u],\
    \ in[nxt[u]]);\n            u = par[nxt[u]];\n        }\n        if (u != v) res.emplace_back(in[u],\
    \ in[v] + 1);\n        return res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\
    \u5F97 (u \u306F v \u306E\u7956\u5148)\n    std::vector<std::pair<int, int>> descend(int\
    \ u, int v) const {\n        if (u == v) return {};\n        if (nxt[u] == nxt[v])\
    \ return {{in[u] + 1, in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n\
    \        res.emplace_back(in[nxt[v]], in[v]);\n        return res;\n    }\n\n\
    \  public:\n    heavy_light_decomposition(const std::vector<std::vector<int>>\
    \ &gh,\n                              int root = 0)\n        : n(gh.size()),\n\
    \          g(gh),\n          sz(n, 1),\n          in(n),\n          out(n),\n\
    \          nxt(n),\n          par(n, -1),\n          depth(n, 0),\n          rev(n)\
    \ {\n        nxt[root] = root;\n        dfs_sz(root);\n        dfs_hld(root);\n\
    \    }\n\n    int idx(int u) const {\n        return in[u];\n    }\n\n    int\
    \ rev_idx(int i) const {\n        return rev[i];\n    }\n\n    int la(int v, int\
    \ k) const {\n        while (1) {\n            int u = nxt[v];\n            if\
    \ (in[u] <= in[v] - k) return rev[in[v] - k];\n            k -= in[v] - in[u]\
    \ + 1;\n            v = par[u];\n        }\n    }\n\n    int lca(int u, int v)\
    \ const {\n        while (nxt[u] != nxt[v]) {\n            if (in[u] < in[v])\
    \ std::swap(u, v);\n            u = par[nxt[u]];\n        }\n        return depth[u]\
    \ < depth[v] ? u : v;\n    }\n\n    int jump(int s, int t, int i) const {\n  \
    \      if (i == 0) return s;\n        int l = lca(s, t);\n        int d = depth[s]\
    \ + depth[t] - depth[l] * 2;\n        if (d < i) return -1;\n        if (depth[s]\
    \ - depth[l] >= i) return la(s, i);\n        i = d - i;\n        return la(t,\
    \ i);\n    }\n\n    std::vector<int> path(int s, int t) const {\n        int l\
    \ = lca(s, t);\n        std::vector<int> a, b;\n        for (; s != l; s = par[s])\
    \ a.emplace_back(s);\n        for (; t != l; t = par[t]) b.emplace_back(t);\n\
    \        a.emplace_back(l);\n        std::reverse(b.begin(), b.end());\n     \
    \   a.insert(a.end(), b.begin(), b.end());\n        return a;\n    }\n\n    int\
    \ parent(int u) const {\n        return par[u];\n    }\n\n    int distance(int\
    \ u, int v) const {\n        return depth[u] + depth[v] - 2 * depth[lca(u, v)];\n\
    \    }\n\n    int distance_from_root(int v) const {\n        return depth[v];\n\
    \    }\n\n    bool at_path(int u, int v, int s) const {\n        return distance(u,\
    \ v) == distance(u, s) + distance(s, v);\n    }\n\n    template <class F>\n  \
    \  void path_noncommutative_query(int u, int v, bool vertex,\n               \
    \                    const F &f) const {\n        int l = lca(u, v);\n       \
    \ for (auto [a, b] : ascend(u, l)) f(a + 1, b);\n        if (vertex) f(in[l],\
    \ in[l] + 1);\n        for (auto [a, b] : descend(l, v)) f(a, b + 1);\n    }\n\
    \n    std::vector<std::pair<int, int>> path_sections(int u, int v,\n         \
    \                                          bool vertex) const {\n        int l\
    \ = lca(u, v);\n        std::vector<std::pair<int, int>> sections;\n        for\
    \ (auto [a, b] : ascend(u, l)) sections.emplace_back(a + 1, b);\n        if (vertex)\
    \ sections.emplace_back(in[l], in[l] + 1);\n        for (auto [a, b] : descend(l,\
    \ v)) sections.emplace_back(a, b + 1);\n        return sections;\n    }\n\n  \
    \  template <class F>\n    int max_path(int u, int v, bool vertex, F binary_search)\
    \ const {\n        int prev = -1;\n        int l = lca(u, v);\n        for (auto\
    \ [a, b] : ascend(u, l)) {\n            a++;\n            int m = binary_search(a,\
    \ b);\n            if (m == b) {\n                prev = rev[b];\n           \
    \ } else {\n                return (m == a ? prev : rev[m]);\n            }\n\
    \        }\n        if (vertex) {\n            int m = binary_search(in[l], in[l]\
    \ + 1);\n            if (m == in[l]) {\n                return prev;\n       \
    \     } else {\n                prev = l;\n            }\n        }\n        for\
    \ (auto [a, b] : descend(l, v)) {\n            b++;\n            int m = binary_search(a,\
    \ b);\n            if (m == b) {\n                prev = rev[b - 1];\n       \
    \     } else {\n                return m == a ? prev : rev[m - 1];\n         \
    \   }\n        }\n        return v;\n    }\n\n    template <class F> void subtree_query(int\
    \ u, bool vertex, const F &f) {\n        f(in[u] + int(!vertex), out[u]);\n  \
    \  }\n\n  private:\n    int n;\n    std::vector<std::vector<int>> g;\n    std::vector<int>\
    \ sz, in, out, nxt, par, depth, rev;\n\n    int t = 0;\n};\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\
    \nnamespace ebi {\n\nstruct heavy_light_decomposition {\n  private:\n    void\
    \ dfs_sz(int v) {\n        for (auto &nv : g[v]) {\n            if (nv == par[v])\
    \ continue;\n            par[nv] = v;\n            depth[nv] = depth[v] + 1;\n\
    \            dfs_sz(nv);\n            sz[v] += sz[nv];\n            if (sz[nv]\
    \ > sz[g[v][0]] || g[v][0] == par[v])\n                std::swap(nv, g[v][0]);\n\
    \        }\n    }\n\n    void dfs_hld(int v) {\n        in[v] = t++;\n       \
    \ rev[in[v]] = v;\n        for (auto nv : g[v]) {\n            if (nv == par[v])\
    \ continue;\n            nxt[nv] = (nv == g[v][0] ? nxt[v] : nv);\n          \
    \  dfs_hld(nv);\n        }\n        out[v] = t;\n    }\n\n    // [u, v) \u30D1\
    \u30B9\u306E\u53D6\u5F97 (v \u306F u \u306E\u7956\u5148)\n    std::vector<std::pair<int,\
    \ int>> ascend(int u, int v) const {\n        std::vector<std::pair<int, int>>\
    \ res;\n        while (nxt[u] != nxt[v]) {\n            res.emplace_back(in[u],\
    \ in[nxt[u]]);\n            u = par[nxt[u]];\n        }\n        if (u != v) res.emplace_back(in[u],\
    \ in[v] + 1);\n        return res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\
    \u5F97 (u \u306F v \u306E\u7956\u5148)\n    std::vector<std::pair<int, int>> descend(int\
    \ u, int v) const {\n        if (u == v) return {};\n        if (nxt[u] == nxt[v])\
    \ return {{in[u] + 1, in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n\
    \        res.emplace_back(in[nxt[v]], in[v]);\n        return res;\n    }\n\n\
    \  public:\n    heavy_light_decomposition(const std::vector<std::vector<int>>\
    \ &gh,\n                              int root = 0)\n        : n(gh.size()),\n\
    \          g(gh),\n          sz(n, 1),\n          in(n),\n          out(n),\n\
    \          nxt(n),\n          par(n, -1),\n          depth(n, 0),\n          rev(n)\
    \ {\n        nxt[root] = root;\n        dfs_sz(root);\n        dfs_hld(root);\n\
    \    }\n\n    int idx(int u) const {\n        return in[u];\n    }\n\n    int\
    \ rev_idx(int i) const {\n        return rev[i];\n    }\n\n    int la(int v, int\
    \ k) const {\n        while (1) {\n            int u = nxt[v];\n            if\
    \ (in[u] <= in[v] - k) return rev[in[v] - k];\n            k -= in[v] - in[u]\
    \ + 1;\n            v = par[u];\n        }\n    }\n\n    int lca(int u, int v)\
    \ const {\n        while (nxt[u] != nxt[v]) {\n            if (in[u] < in[v])\
    \ std::swap(u, v);\n            u = par[nxt[u]];\n        }\n        return depth[u]\
    \ < depth[v] ? u : v;\n    }\n\n    int jump(int s, int t, int i) const {\n  \
    \      if (i == 0) return s;\n        int l = lca(s, t);\n        int d = depth[s]\
    \ + depth[t] - depth[l] * 2;\n        if (d < i) return -1;\n        if (depth[s]\
    \ - depth[l] >= i) return la(s, i);\n        i = d - i;\n        return la(t,\
    \ i);\n    }\n\n    std::vector<int> path(int s, int t) const {\n        int l\
    \ = lca(s, t);\n        std::vector<int> a, b;\n        for (; s != l; s = par[s])\
    \ a.emplace_back(s);\n        for (; t != l; t = par[t]) b.emplace_back(t);\n\
    \        a.emplace_back(l);\n        std::reverse(b.begin(), b.end());\n     \
    \   a.insert(a.end(), b.begin(), b.end());\n        return a;\n    }\n\n    int\
    \ parent(int u) const {\n        return par[u];\n    }\n\n    int distance(int\
    \ u, int v) const {\n        return depth[u] + depth[v] - 2 * depth[lca(u, v)];\n\
    \    }\n\n    int distance_from_root(int v) const {\n        return depth[v];\n\
    \    }\n\n    bool at_path(int u, int v, int s) const {\n        return distance(u,\
    \ v) == distance(u, s) + distance(s, v);\n    }\n\n    template <class F>\n  \
    \  void path_noncommutative_query(int u, int v, bool vertex,\n               \
    \                    const F &f) const {\n        int l = lca(u, v);\n       \
    \ for (auto [a, b] : ascend(u, l)) f(a + 1, b);\n        if (vertex) f(in[l],\
    \ in[l] + 1);\n        for (auto [a, b] : descend(l, v)) f(a, b + 1);\n    }\n\
    \n    std::vector<std::pair<int, int>> path_sections(int u, int v,\n         \
    \                                          bool vertex) const {\n        int l\
    \ = lca(u, v);\n        std::vector<std::pair<int, int>> sections;\n        for\
    \ (auto [a, b] : ascend(u, l)) sections.emplace_back(a + 1, b);\n        if (vertex)\
    \ sections.emplace_back(in[l], in[l] + 1);\n        for (auto [a, b] : descend(l,\
    \ v)) sections.emplace_back(a, b + 1);\n        return sections;\n    }\n\n  \
    \  template <class F>\n    int max_path(int u, int v, bool vertex, F binary_search)\
    \ const {\n        int prev = -1;\n        int l = lca(u, v);\n        for (auto\
    \ [a, b] : ascend(u, l)) {\n            a++;\n            int m = binary_search(a,\
    \ b);\n            if (m == b) {\n                prev = rev[b];\n           \
    \ } else {\n                return (m == a ? prev : rev[m]);\n            }\n\
    \        }\n        if (vertex) {\n            int m = binary_search(in[l], in[l]\
    \ + 1);\n            if (m == in[l]) {\n                return prev;\n       \
    \     } else {\n                prev = l;\n            }\n        }\n        for\
    \ (auto [a, b] : descend(l, v)) {\n            b++;\n            int m = binary_search(a,\
    \ b);\n            if (m == b) {\n                prev = rev[b - 1];\n       \
    \     } else {\n                return m == a ? prev : rev[m - 1];\n         \
    \   }\n        }\n        return v;\n    }\n\n    template <class F> void subtree_query(int\
    \ u, bool vertex, const F &f) {\n        f(in[u] + int(!vertex), out[u]);\n  \
    \  }\n\n  private:\n    int n;\n    std::vector<std::vector<int>> g;\n    std::vector<int>\
    \ sz, in, out, nxt, par, depth, rev;\n\n    int t = 0;\n};\n\n}  // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: tree/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2023-10-20 17:50:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Jump_on_Tree_HLD.test.cpp
  - test/yuki/yuki_2439.test.cpp
  - test/aoj/aoj_2450.test.cpp
  - test/data_structure/Vertex_Add_Path_Sum.test.cpp
  - test/data_structure/Vertex_Set_Path_Compositie.test.cpp
  - test/data_structure/Vertex_Add_Subtree_Sum.test.cpp
documentation_of: tree/heavy_light_decomposition.hpp
layout: document
title: Heavy Light Decomposition
---

## 説明

木をHLDする。パスクエリ、部分木クエリを処理することができる。

### コンストラクタ

`HeavyLightDecomposition(std::vector<std::vector<int>> g, int root = 0)`

木グラフ g と root ノード番号を与えてHLDする。デフォルトで root は頂点 0

### idx(int u)

頂点 $u$ のDFS行きがけ順の番号を返す。このidxの位置にデータ構造のインデックスを対応させればパスクエリや部分木クエリを処理することができる。具体的には使い方を参照。

### la(int v, int k)

頂点 $v$ から $k$ だけ親方向に上った頂点を返す。 $O(\log N)$ 

### lca(int u, int v)

頂点 $u$, $v$ のLCAを返す。 $O(\log N)$

### jump(int s, int t, int k)

頂点 $s$ から $t$ の方向に $k$ だけ移動した頂点を返す。 $O(\log N)$

### path(int s, int t)

頂点 $s$, $t$ の単純パスを返す。

### parent(int u)

頂点 $u$ の親を返す。 $u$ が根である場合は、 $-1$ を返す。

### distance(int u, int v)

頂点 $u$, $v$ の距離を返す。 $O(\log N)$

### at_path(int u, int v, int s)

$u-v$ パスに $s$ が含まれるか判定。 $O(\log N)$

### path_noncommutative_query(int u, int v, bool vertex, const F &f)

パス $u-v$ にクエリ`f`を適用する。非可換。vertexがtrueのとき、頂点に属性がある。vertexがfalseのとき、辺に属性がある。親-子間の辺属性は子のidxに持つ。

### max_path(int u, int v, bool vertex, F binary_search)

パス $u-v$ に含まれる頂点で、 $u-m$ での値が `true` を返す最大のパスとなる $m$ を二分探索で求める。
`binary_search` という関数を引数に渡すが、これは `path_noncommutative_query` で渡す `f` と同じ引数を取り、返り値をデータ構造の二分探索した後の `id` とする。
計算量はデータ構造に対する二分探索の計算量を $O(\log N)$ とすると $O((\log N)^2)$

### subtree_query(int u, bool vertex, const F &f)

頂点 $u$ の部分木にクエリ`f`を適用する。vertexがtrueのとき、根頂点である $u$ にもクエリを適用する。

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
