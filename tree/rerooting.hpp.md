---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':question:'
    path: graph/base.hpp
    title: Graph (CSR format)
  - icon: ':question:'
    path: tree/heavy_light_decomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/subtree_hash.hpp
    title: Subtree Hash
  - icon: ':heavy_check_mark:'
    path: tree/tree_hash.hpp
    title: Tree Hash
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2821.test.cpp
    title: test/aoj/aoj_2821.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
    title: test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Tree_Path_Composite_Sum.test.cpp
    title: test/tree/Tree_Path_Composite_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/rerooting.hpp\"\n\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"graph/base.hpp\"\n\n#line 4 \"graph/base.hpp\"\n\
    #include <iostream>\n#include <ranges>\n#line 7 \"graph/base.hpp\"\n\n#line 2\
    \ \"data_structure/simple_csr.hpp\"\n\n#line 6 \"data_structure/simple_csr.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class E> struct simple_csr {\n    simple_csr()\
    \ = default;\n\n    simple_csr(int n, const std::vector<std::pair<int, E>>& elements)\n\
    \        : start(n + 1, 0), elist(elements.size()) {\n        for (auto e : elements)\
    \ {\n            start[e.first + 1]++;\n        }\n        for (auto i : std::views::iota(0,\
    \ n)) {\n            start[i + 1] += start[i];\n        }\n        auto counter\
    \ = start;\n        for (auto [i, e] : elements) {\n            elist[counter[i]++]\
    \ = e;\n        }\n    }\n\n    simple_csr(const std::vector<std::vector<E>>&\
    \ es)\n        : start(es.size() + 1, 0) {\n        int n = es.size();\n     \
    \   for (auto i : std::views::iota(0, n)) {\n            start[i + 1] = (int)es[i].size()\
    \ + start[i];\n        }\n        elist.resize(start.back());\n        for (auto\
    \ i : std::views::iota(0, n)) {\n            std::copy(es[i].begin(), es[i].end(),\
    \ elist.begin() + start[i]);\n        }\n    }\n\n    int size() const {\n   \
    \     return (int)start.size() - 1;\n    }\n\n    const auto operator[](int i)\
    \ const {\n        return std::ranges::subrange(elist.begin() + start[i],\n  \
    \                                   elist.begin() + start[i + 1]);\n    }\n  \
    \  auto operator[](int i) {\n        return std::ranges::subrange(elist.begin()\
    \ + start[i],\n                                     elist.begin() + start[i +\
    \ 1]);\n    }\n\n    const auto operator()(int i, int l, int r) const {\n    \
    \    return std::ranges::subrange(elist.begin() + start[i] + l,\n            \
    \                         elist.begin() + start[i + 1] + r);\n    }\n    auto\
    \ operator()(int i, int l, int r) {\n        return std::ranges::subrange(elist.begin()\
    \ + start[i] + l,\n                                     elist.begin() + start[i\
    \ + 1] + r);\n    }\n\n  private:\n    std::vector<int> start;\n    std::vector<E>\
    \ elist;\n};\n\n}  // namespace ebi\n#line 9 \"graph/base.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <class T> struct Edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n};\n\ntemplate <class E> struct Graph {\n    using cost_type = E;\n   \
    \ using edge_type = Edge<cost_type>;\n\n    Graph(int n_) : n(n_) {}\n\n    Graph()\
    \ = default;\n\n    void add_edge(int u, int v, cost_type c) {\n        assert(!prepared\
    \ && u < n && v < n);\n        buff.emplace_back(u, edge_type{u, v, c, m});\n\
    \        edges.emplace_back(edge_type{u, v, c, m++});\n    }\n\n    void add_undirected_edge(int\
    \ u, int v, cost_type c) {\n        assert(!prepared && u < n && v < n);\n   \
    \     buff.emplace_back(u, edge_type{u, v, c, m});\n        buff.emplace_back(v,\
    \ edge_type{v, u, c, m});\n        edges.emplace_back(edge_type{u, v, c, m});\n\
    \        m++;\n    }\n\n    void read_tree(int offset = 1, bool is_weighted =\
    \ false) {\n        read_graph(n - 1, offset, false, is_weighted);\n    }\n\n\
    \    void read_parents(int offset = 1) {\n        for (auto i : std::views::iota(1,\
    \ n)) {\n            int p;\n            std::cin >> p;\n            p -= offset;\n\
    \            add_undirected_edge(p, i, 1);\n        }\n        build();\n    }\n\
    \n    void read_graph(int e, int offset = 1, bool is_directed = false,\n     \
    \               bool is_weighted = false) {\n        for (int i = 0; i < e; i++)\
    \ {\n            int u, v;\n            std::cin >> u >> v;\n            u -=\
    \ offset;\n            v -= offset;\n            if (is_weighted) {\n        \
    \        cost_type c;\n                std::cin >> c;\n                if (is_directed)\
    \ {\n                    add_edge(u, v, c);\n                } else {\n      \
    \              add_undirected_edge(u, v, c);\n                }\n            }\
    \ else {\n                if (is_directed) {\n                    add_edge(u,\
    \ v, 1);\n                } else {\n                    add_undirected_edge(u,\
    \ v, 1);\n                }\n            }\n        }\n        build();\n    }\n\
    \n    void build() {\n        assert(!prepared);\n        csr = simple_csr<edge_type>(n,\
    \ buff);\n        buff.clear();\n        prepared = true;\n    }\n\n    int size()\
    \ const {\n        return n;\n    }\n\n    int node_number() const {\n       \
    \ return n;\n    }\n\n    int edge_number() const {\n        return m;\n    }\n\
    \n    edge_type get_edge(int i) const {\n        assert(prepared);\n        return\
    \ edges[i];\n    }\n\n    std::vector<edge_type> get_edges() const {\n       \
    \ assert(!prepared);\n        return edges;\n    }\n\n    const auto operator[](int\
    \ i) const {\n        assert(prepared);\n        return csr[i];\n    }\n    auto\
    \ operator[](int i) {\n        assert(prepared);\n        return csr[i];\n   \
    \ }\n\n  private:\n    int n, m = 0;\n\n    std::vector<std::pair<int, edge_type>>\
    \ buff;\n\n    std::vector<edge_type> edges;\n    simple_csr<edge_type> csr;\n\
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 2 \"tree/heavy_light_decomposition.hpp\"\
    \n\n#include <algorithm>\n#line 6 \"tree/heavy_light_decomposition.hpp\"\n\n#line\
    \ 8 \"tree/heavy_light_decomposition.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ T> struct heavy_light_decomposition {\n  private:\n    void dfs_sz(int v) {\n\
    \        for (auto &e : g[v]) {\n            if (e.to == par[v]) continue;\n \
    \           par[e.to] = v;\n            depth_[e.to] = depth_[v] + 1;\n      \
    \      dist[e.to] = dist[v] + e.cost;\n            dfs_sz(e.to);\n           \
    \ sz[v] += sz[e.to];\n            if (sz[e.to] > sz[g[v][0].to] || g[v][0].to\
    \ == par[v])\n                std::swap(e, g[v][0]);\n        }\n    }\n\n   \
    \ void dfs_hld(int v) {\n        in[v] = num++;\n        rev[in[v]] = v;\n   \
    \     for (auto e : g[v]) {\n            if (e.to == par[v]) continue;\n     \
    \       nxt[e.to] = (e.to == g[v][0].to ? nxt[v] : e.to);\n            dfs_hld(e.to);\n\
    \        }\n        out[v] = num;\n    }\n\n    // [u, v) \u30D1\u30B9\u306E\u53D6\
    \u5F97 (v \u306F u \u306E\u7956\u5148)\n    std::vector<std::pair<int, int>> ascend(int\
    \ u, int v) const {\n        std::vector<std::pair<int, int>> res;\n        while\
    \ (nxt[u] != nxt[v]) {\n            res.emplace_back(in[u], in[nxt[u]]);\n   \
    \         u = par[nxt[u]];\n        }\n        if (u != v) res.emplace_back(in[u],\
    \ in[v] + 1);\n        return res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\
    \u5F97 (u \u306F v \u306E\u7956\u5148)\n    std::vector<std::pair<int, int>> descend(int\
    \ u, int v) const {\n        if (u == v) return {};\n        if (nxt[u] == nxt[v])\
    \ return {{in[u] + 1, in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n\
    \        res.emplace_back(in[nxt[v]], in[v]);\n        return res;\n    }\n\n\
    \  public:\n    heavy_light_decomposition(const Graph<T> &gh, int root_ = 0)\n\
    \        : n(gh.size()),\n          root(root_),\n          g(gh),\n         \
    \ sz(n, 1),\n          in(n),\n          out(n),\n          nxt(n),\n        \
    \  par(n, -1),\n          depth_(n, 0),\n          rev(n),\n          dist(n,\
    \ 0) {\n        nxt[root] = root;\n        dfs_sz(root);\n        dfs_hld(root);\n\
    \    }\n\n    int idx(int u) const {\n        return in[u];\n    }\n\n    int\
    \ rev_idx(int i) const {\n        return rev[i];\n    }\n\n    int la(int v, int\
    \ k) const {\n        while (1) {\n            int u = nxt[v];\n            if\
    \ (in[u] <= in[v] - k) return rev[in[v] - k];\n            k -= in[v] - in[u]\
    \ + 1;\n            v = par[u];\n        }\n    }\n\n    int lca(int u, int v)\
    \ const {\n        while (nxt[u] != nxt[v]) {\n            if (in[u] < in[v])\
    \ std::swap(u, v);\n            u = par[nxt[u]];\n        }\n        return depth_[u]\
    \ < depth_[v] ? u : v;\n    }\n\n    int jump(int s, int t, int i) const {\n \
    \       if (i == 0) return s;\n        int l = lca(s, t);\n        int d = depth_[s]\
    \ + depth_[t] - depth_[l] * 2;\n        if (d < i) return -1;\n        if (depth_[s]\
    \ - depth_[l] >= i) return la(s, i);\n        i = d - i;\n        return la(t,\
    \ i);\n    }\n\n    std::vector<int> path(int s, int t) const {\n        int l\
    \ = lca(s, t);\n        std::vector<int> a, b;\n        for (; s != l; s = par[s])\
    \ a.emplace_back(s);\n        for (; t != l; t = par[t]) b.emplace_back(t);\n\
    \        a.emplace_back(l);\n        std::reverse(b.begin(), b.end());\n     \
    \   a.insert(a.end(), b.begin(), b.end());\n        return a;\n    }\n\n    int\
    \ root_of_heavy_path(int u) const {\n        return nxt[u];\n    }\n\n    int\
    \ parent(int u) const {\n        return par[u];\n    }\n\n    T distance(int u,\
    \ int v) const {\n        return dist[u] + dist[v] - 2 * dist[lca(u, v)];\n  \
    \  }\n\n    T distance_from_root(int v) const {\n        return dist[v];\n   \
    \ }\n\n    T depth(int v) const {\n        return depth_[v];\n    }\n\n    bool\
    \ at_path(int u, int v, int s) const {\n        return distance(u, v) == distance(u,\
    \ s) + distance(s, v);\n    }\n\n    std::pair<int, int> subtree_section(int v)\
    \ const {\n        return {in[v], out[v]};\n    }\n\n    bool is_subtree(int u,\
    \ int v) const {\n        return in[u] <= in[v] && in[v] < out[u];\n    }\n\n\
    \    template <class F>\n    void path_noncommutative_query(int u, int v, bool\
    \ vertex,\n                                   const F &f) const {\n        int\
    \ l = lca(u, v);\n        for (auto [a, b] : ascend(u, l)) f(a + 1, b);\n    \
    \    if (vertex) f(in[l], in[l] + 1);\n        for (auto [a, b] : descend(l, v))\
    \ f(a, b + 1);\n    }\n\n    std::vector<std::pair<int, int>> path_sections(int\
    \ u, int v,\n                                                   bool vertex) const\
    \ {\n        int l = lca(u, v);\n        std::vector<std::pair<int, int>> sections;\n\
    \        for (auto [a, b] : ascend(u, l)) sections.emplace_back(a + 1, b);\n \
    \       if (vertex) sections.emplace_back(in[l], in[l] + 1);\n        for (auto\
    \ [a, b] : descend(l, v)) sections.emplace_back(a, b + 1);\n        return sections;\n\
    \    }\n\n    template <class F>\n    int max_path(int u, int v, bool vertex,\
    \ F binary_search) const {\n        int prev = -1;\n        int l = lca(u, v);\n\
    \        for (auto [a, b] : ascend(u, l)) {\n            a++;\n            int\
    \ m = binary_search(a, b);\n            if (m == b) {\n                prev =\
    \ rev[b];\n            } else {\n                return (m == a ? prev : rev[m]);\n\
    \            }\n        }\n        if (vertex) {\n            int m = binary_search(in[l],\
    \ in[l] + 1);\n            if (m == in[l]) {\n                return prev;\n \
    \           } else {\n                prev = l;\n            }\n        }\n  \
    \      for (auto [a, b] : descend(l, v)) {\n            b++;\n            int\
    \ m = binary_search(a, b);\n            if (m == b) {\n                prev =\
    \ rev[b - 1];\n            } else {\n                return m == a ? prev : rev[m\
    \ - 1];\n            }\n        }\n        return v;\n    }\n\n    template <class\
    \ F> void subtree_query(int u, bool vertex, const F &f) {\n        f(in[u] + int(!vertex),\
    \ out[u]);\n    }\n\n    const std::vector<int> &dfs_order() const {\n       \
    \ return rev;\n    }\n\n    template <class ADD, class QUERY, class CLEAR, class\
    \ RESET>\n    void dsu_on_tree(const ADD &add, const QUERY &query, const CLEAR\
    \ &clear,\n                     const RESET &reset) const;\n\n    std::vector<std::pair<int,\
    \ int>> lca_based_auxiliary_tree_dfs_order(\n        std::vector<int> vs) const;\n\
    \n    std::pair<std::vector<int>, Graph<T>> lca_based_auxiliary_tree(\n      \
    \  std::vector<int> vs) const;\n\n  private:\n    int n, root;\n    Graph<T> g;\n\
    \    std::vector<int> sz, in, out, nxt, par, depth_, rev;\n    std::vector<T>\
    \ dist;\n\n    int num = 0;\n};\n\n}  // namespace ebi\n#line 9 \"tree/rerooting.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T, class V> struct rerooting_dp {\n   \
    \ template <class MERGE, class PUT_EDGE, class PUT_ROOT>\n    rerooting_dp(const\
    \ Graph<T> &tree, const V e, const MERGE &merge,\n                 const PUT_EDGE\
    \ &put_edge, const PUT_ROOT &put_root)\n        : n(tree.node_number()),\n   \
    \       hld(tree),\n          full_tree_dp(n, e),\n          child_dp(n, e),\n\
    \          parent_dp(n, e) {\n        auto dfs_sub = [&](auto &&self, int v, int\
    \ par = -1) -> void {\n            for (const auto &edge : tree[v]) {\n      \
    \          if (edge.to == par) continue;\n                self(self, edge.to,\
    \ v);\n                child_dp[v] =\n                    merge(child_dp[v], put_edge(edge,\
    \ child_dp[edge.to]));\n            }\n            child_dp[v] = put_root(v, child_dp[v]);\n\
    \        };\n        dfs_sub(dfs_sub, 0);\n        auto dfs_all = [&](auto &&self,\
    \ int v, int par = -1) -> void {\n            std::vector<int> ch;\n         \
    \   std::vector<V> dp;\n            V ret = e;\n            for (const auto &edge\
    \ : tree[v]) {\n                if (edge.to == par) {\n                    ret\
    \ = put_edge(edge, parent_dp[v]);\n                } else {\n                \
    \    ch.emplace_back(edge.to);\n                    dp.emplace_back(put_edge(edge,\
    \ child_dp[edge.to]));\n                }\n            }\n            int sz =\
    \ (int)ch.size();\n            if (ch.empty()) {\n                full_tree_dp[v]\
    \ = put_root(v, ret);\n                return;\n            }\n            std::vector<V>\
    \ lcum(sz, ret);\n            for (int i = 0; i < sz - 1; i++) {\n           \
    \     lcum[i + 1] = merge(lcum[i], dp[i]);\n            }\n            V rcum\
    \ = e;\n            for (int i = sz - 1; i >= 0; i--) {\n                parent_dp[ch[i]]\
    \ = put_root(v, merge(lcum[i], rcum));\n                rcum = merge(rcum, dp[i]);\n\
    \            }\n            for (int i = 0; i < sz; i++) {\n                self(self,\
    \ ch[i], v);\n            }\n            full_tree_dp[v] = put_root(v, merge(rcum,\
    \ ret));\n        };\n        dfs_all(dfs_all, 0);\n    }\n\n    V get(int v)\
    \ const {\n        return get(v, v);\n    }\n\n    V get(int v, int root) const\
    \ {\n        if (root == v) return full_tree_dp[v];\n        if (!hld.is_subtree(v,\
    \ root)) {\n            return child_dp[v];\n        }\n        return parent_dp[hld.jump(v,\
    \ root, 1)];\n    }\n\n    std::vector<V> get_full_dp() const {\n        return\
    \ full_tree_dp;\n    }\n\n  private:\n    int n;\n    heavy_light_decomposition<T>\
    \ hld;\n    std::vector<V> full_tree_dp;\n    std::vector<V> child_dp;\n    std::vector<V>\
    \ parent_dp;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \n#include \"../graph/base.hpp\"\n#include \"../tree/heavy_light_decomposition.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T, class V> struct rerooting_dp {\n   \
    \ template <class MERGE, class PUT_EDGE, class PUT_ROOT>\n    rerooting_dp(const\
    \ Graph<T> &tree, const V e, const MERGE &merge,\n                 const PUT_EDGE\
    \ &put_edge, const PUT_ROOT &put_root)\n        : n(tree.node_number()),\n   \
    \       hld(tree),\n          full_tree_dp(n, e),\n          child_dp(n, e),\n\
    \          parent_dp(n, e) {\n        auto dfs_sub = [&](auto &&self, int v, int\
    \ par = -1) -> void {\n            for (const auto &edge : tree[v]) {\n      \
    \          if (edge.to == par) continue;\n                self(self, edge.to,\
    \ v);\n                child_dp[v] =\n                    merge(child_dp[v], put_edge(edge,\
    \ child_dp[edge.to]));\n            }\n            child_dp[v] = put_root(v, child_dp[v]);\n\
    \        };\n        dfs_sub(dfs_sub, 0);\n        auto dfs_all = [&](auto &&self,\
    \ int v, int par = -1) -> void {\n            std::vector<int> ch;\n         \
    \   std::vector<V> dp;\n            V ret = e;\n            for (const auto &edge\
    \ : tree[v]) {\n                if (edge.to == par) {\n                    ret\
    \ = put_edge(edge, parent_dp[v]);\n                } else {\n                \
    \    ch.emplace_back(edge.to);\n                    dp.emplace_back(put_edge(edge,\
    \ child_dp[edge.to]));\n                }\n            }\n            int sz =\
    \ (int)ch.size();\n            if (ch.empty()) {\n                full_tree_dp[v]\
    \ = put_root(v, ret);\n                return;\n            }\n            std::vector<V>\
    \ lcum(sz, ret);\n            for (int i = 0; i < sz - 1; i++) {\n           \
    \     lcum[i + 1] = merge(lcum[i], dp[i]);\n            }\n            V rcum\
    \ = e;\n            for (int i = sz - 1; i >= 0; i--) {\n                parent_dp[ch[i]]\
    \ = put_root(v, merge(lcum[i], rcum));\n                rcum = merge(rcum, dp[i]);\n\
    \            }\n            for (int i = 0; i < sz; i++) {\n                self(self,\
    \ ch[i], v);\n            }\n            full_tree_dp[v] = put_root(v, merge(rcum,\
    \ ret));\n        };\n        dfs_all(dfs_all, 0);\n    }\n\n    V get(int v)\
    \ const {\n        return get(v, v);\n    }\n\n    V get(int v, int root) const\
    \ {\n        if (root == v) return full_tree_dp[v];\n        if (!hld.is_subtree(v,\
    \ root)) {\n            return child_dp[v];\n        }\n        return parent_dp[hld.jump(v,\
    \ root, 1)];\n    }\n\n    std::vector<V> get_full_dp() const {\n        return\
    \ full_tree_dp;\n    }\n\n  private:\n    int n;\n    heavy_light_decomposition<T>\
    \ hld;\n    std::vector<V> full_tree_dp;\n    std::vector<V> child_dp;\n    std::vector<V>\
    \ parent_dp;\n};\n\n}  // namespace ebi\n"
  dependsOn:
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  - tree/heavy_light_decomposition.hpp
  isVerificationFile: false
  path: tree/rerooting.hpp
  requiredBy:
  - tree/subtree_hash.hpp
  - tree/tree_hash.hpp
  timestamp: '2025-03-18 01:14:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Tree_Path_Composite_Sum.test.cpp
  - test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
  - test/aoj/aoj_2821.test.cpp
documentation_of: tree/rerooting.hpp
layout: document
title: Rerooting DP
---

## 説明

抽象化全方位木DPライブラリ。各頂点を根としたときの木DPを求める。$O(N)$

### 使用方法

```
rerooting_dp dp(tree, e, merge, put_edge, put_root)
```

- DPの値の型 `V`
- DPの単位元 `e`
- 辺を追加したDP同士をマージする関数 `V merge(V a, V b)`
- 辺 `i` を根に付与する関数 `V put_edge(Edge edge, V x)`
- 頂点 $v$ を根として追加する関数 `V put_root(int v, V x)`

を渡して使用する。

### get(int v)

頂点 $v$ を根としたDPの値を返す。

### get(int v, int root)

頂点 $root$ を根としたときの頂点 $v$ の部分木のDPの値を返す。

### get_full_dp()

各頂点を根としたときのDPの配列を返す。