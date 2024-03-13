---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: Graph (CSR format)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    \ = default;\n\n    void add_edge(int u, int v, cost_type c) {\n        buff.emplace_back(u,\
    \ edge_type{u, v, c, m});\n        edges.emplace_back(edge_type{u, v, c, m++});\n\
    \    }\n\n    void add_undirected_edge(int u, int v, cost_type c) {\n        buff.emplace_back(u,\
    \ edge_type{u, v, c, m});\n        buff.emplace_back(v, edge_type{v, u, c, m});\n\
    \        edges.emplace_back(edge_type{u, v, c, m});\n        m++;\n    }\n\n \
    \   void read_tree(int offset = 1, bool is_weighted = false) {\n        read_graph(n\
    \ - 1, offset, false, is_weighted);\n    }\n\n    void read_parents(int offset\
    \ = 1) {\n        for (auto i : std::views::iota(1, n)) {\n            int p;\n\
    \            std::cin >> p;\n            p -= offset;\n            add_undirected_edge(p,\
    \ i, 1);\n        }\n        build();\n    }\n\n    void read_graph(int e, int\
    \ offset = 1, bool is_directed = false,\n                    bool is_weighted\
    \ = false) {\n        for (int i = 0; i < e; i++) {\n            int u, v;\n \
    \           std::cin >> u >> v;\n            u -= offset;\n            v -= offset;\n\
    \            if (is_weighted) {\n                cost_type c;\n              \
    \  std::cin >> c;\n                if (is_directed) {\n                    add_edge(u,\
    \ v, c);\n                } else {\n                    add_undirected_edge(u,\
    \ v, c);\n                }\n            } else {\n                if (is_directed)\
    \ {\n                    add_edge(u, v, 1);\n                } else {\n      \
    \              add_undirected_edge(u, v, 1);\n                }\n            }\n\
    \        }\n        build();\n    }\n\n    void build() {\n        assert(!prepared);\n\
    \        csr = simple_csr<edge_type>(n, buff);\n        buff.clear();\n      \
    \  prepared = true;\n    }\n\n    int size() const {\n        return n;\n    }\n\
    \n    int node_number() const {\n        return n;\n    }\n\n    int edge_number()\
    \ const {\n        return m;\n    }\n\n    edge_type get_edge(int i) const {\n\
    \        return edges[i];\n    }\n\n    std::vector<edge_type> get_edges() const\
    \ {\n        return edges;\n    }\n\n    const auto operator[](int i) const {\n\
    \        return csr[i];\n    }\n    auto operator[](int i) {\n        return csr[i];\n\
    \    }\n\n  private:\n    int n, m = 0;\n\n    std::vector<std::pair<int,edge_type>>\
    \ buff;\n\n    std::vector<edge_type> edges;\n    simple_csr<edge_type> csr;\n\
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 8 \"tree/rerooting.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T, class V, class E, E (*e)(), E (*merge)(E,\
    \ E),\n          E (*put_edge)(T, V), V (*put_root)(int, E)>\nstruct rerooting\
    \ {\n  private:\n    V dfs_sub(int v, int par = -1) {\n        E ret = e();\n\
    \        for (auto &edge : g[v]) {\n            if (edge.to == par && g[v].back().to\
    \ != par)\n                std::swap(g[v].back(), edge);\n            if (edge.to\
    \ == par) continue;\n            E val = put_edge(edge.cost, dfs_sub(edge.to,\
    \ v));\n            outs[v].emplace_back(val);\n            ret = merge(ret, val);\n\
    \        }\n        sub[v] = put_root(v, ret);\n        return sub[v];\n    }\n\
    \n    void dfs_all(int v, int par = -1, E rev = e()) {\n        int sz = outs[v].size();\n\
    \        std::vector<E> lcum(sz + 1, e()), rcum(sz + 1, e());\n        for (int\
    \ i = 0; i < sz; i++) {\n            lcum[i + 1] = merge(lcum[i], outs[v][i]);\n\
    \            rcum[sz - i - 1] = merge(rcum[sz - i], outs[v][sz - i - 1]);\n  \
    \      }\n        for (int i = 0; i < sz; i++) {\n            auto edge = g[v][i];\n\
    \            E ret =\n                put_edge(edge.cost,\n                  \
    \       put_root(v, merge(merge(lcum[i], rcum[i + 1]), rev)));\n            dfs_all(edge.to,\
    \ v, ret);\n        }\n        dp[v] = put_root(v, merge(lcum[sz], rev));\n  \
    \  }\n\n  public:\n    rerooting(int n, const Graph<T> &g_) : n(n), g(g_), sub(n),\
    \ dp(n), outs(n) {\n        dfs_sub(0);\n        dfs_all(0);\n    }\n\n    V get(int\
    \ v) const {\n        return dp[v];\n    }\n\n  private:\n    int n;\n    Graph<T>\
    \ g;\n    std::vector<V> sub;\n    std::vector<V> dp;\n    std::vector<std::vector<E>>\
    \ outs;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \n#include \"../graph/base.hpp\"\n\nnamespace ebi {\n\ntemplate <class T, class\
    \ V, class E, E (*e)(), E (*merge)(E, E),\n          E (*put_edge)(T, V), V (*put_root)(int,\
    \ E)>\nstruct rerooting {\n  private:\n    V dfs_sub(int v, int par = -1) {\n\
    \        E ret = e();\n        for (auto &edge : g[v]) {\n            if (edge.to\
    \ == par && g[v].back().to != par)\n                std::swap(g[v].back(), edge);\n\
    \            if (edge.to == par) continue;\n            E val = put_edge(edge.cost,\
    \ dfs_sub(edge.to, v));\n            outs[v].emplace_back(val);\n            ret\
    \ = merge(ret, val);\n        }\n        sub[v] = put_root(v, ret);\n        return\
    \ sub[v];\n    }\n\n    void dfs_all(int v, int par = -1, E rev = e()) {\n   \
    \     int sz = outs[v].size();\n        std::vector<E> lcum(sz + 1, e()), rcum(sz\
    \ + 1, e());\n        for (int i = 0; i < sz; i++) {\n            lcum[i + 1]\
    \ = merge(lcum[i], outs[v][i]);\n            rcum[sz - i - 1] = merge(rcum[sz\
    \ - i], outs[v][sz - i - 1]);\n        }\n        for (int i = 0; i < sz; i++)\
    \ {\n            auto edge = g[v][i];\n            E ret =\n                put_edge(edge.cost,\n\
    \                         put_root(v, merge(merge(lcum[i], rcum[i + 1]), rev)));\n\
    \            dfs_all(edge.to, v, ret);\n        }\n        dp[v] = put_root(v,\
    \ merge(lcum[sz], rev));\n    }\n\n  public:\n    rerooting(int n, const Graph<T>\
    \ &g_) : n(n), g(g_), sub(n), dp(n), outs(n) {\n        dfs_sub(0);\n        dfs_all(0);\n\
    \    }\n\n    V get(int v) const {\n        return dp[v];\n    }\n\n  private:\n\
    \    int n;\n    Graph<T> g;\n    std::vector<V> sub;\n    std::vector<V> dp;\n\
    \    std::vector<std::vector<E>> outs;\n};\n\n}  // namespace ebi\n"
  dependsOn:
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: false
  path: tree/rerooting.hpp
  requiredBy: []
  timestamp: '2024-03-13 15:52:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Tree_Path_Composite_Sum.test.cpp
documentation_of: tree/rerooting.hpp
layout: document
title: Rerooting DP
---

## 説明

抽象化全方位木DPライブラリ。各頂点を根としたときの木DPを求める。$O(N)$

### コンストラクタ

```
rerooting<V, E, e, merge, put_edge, put_root> dp(int n, std::vector<std::pair<int,int>> edges);
```

- DPの値の型 `V`
- 可換モノイドの型 `E`
- `E` の単位元を返す関数 `E e()`
- `E` の演算子 `E merge(E s, E t)`
- 辺 `i` を根に付与する関数 `E put_edge(T edge, V x)`
- 頂点 $v$ を根として追加する関数 `V put_root(int v, E x)`

をテンプレートとして用いている。