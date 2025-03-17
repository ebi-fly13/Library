---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':question:'
    path: graph/base.hpp
    title: Graph (CSR format)
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/dp_on_static_top_tree.hpp
    title: DP on Static Top Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/Point_Set_Tree_Path_Composition_Sum_Fixed_Root.test.cpp
    title: test/tree/Point_Set_Tree_Path_Composition_Sum_Fixed_Root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/static_top_tree.hpp\"\n\n#line 2 \"graph/base.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n#include <ranges>\n#include <vector>\n\
    \n#line 2 \"data_structure/simple_csr.hpp\"\n\n#line 4 \"data_structure/simple_csr.hpp\"\
    \n#include <utility>\n#line 6 \"data_structure/simple_csr.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <class E> struct simple_csr {\n    simple_csr() = default;\n\n\
    \    simple_csr(int n, const std::vector<std::pair<int, E>>& elements)\n     \
    \   : start(n + 1, 0), elist(elements.size()) {\n        for (auto e : elements)\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 4 \"tree/static_top_tree.hpp\"\
    \n\nnamespace ebi {\n\nenum Type { Vertex, Compress, Rake, AddEdge, AddVertex\
    \ };\n\ntemplate <class T> struct static_top_tree {\n  private:\n    struct Node\
    \ {\n        int par = -1, lch = -1, rch = -1;\n        Type ty = Type::Vertex;\n\
    \    };\n\n    void dfs_sz(int v) {\n        for (auto &e : g[v]) {\n        \
    \    if (e.to == par[v]) continue;\n            par[e.to] = v;\n            dfs_sz(e.to);\n\
    \            sz[v] += sz[e.to];\n            if (sz[e.to] > sz[g[v][0].to] ||\
    \ g[v][0].to == par[v]) {\n                std::swap(e, g[v][0]);\n          \
    \  }\n        }\n    }\n\n    int new_node(int k, int l, int r, Type t) {\n  \
    \      if (k == -1) {\n            k = (int)stt.size();\n            stt.emplace_back(-1,\
    \ l, r, t);\n        } else {\n            stt[k].lch = l;\n            stt[k].rch\
    \ = r;\n            stt[k].ty = t;\n        }\n        if (l != -1) stt[l].par\
    \ = k;\n        if (r != -1) stt[r].par = k;\n        return k;\n    }\n\n   \
    \ std::pair<int, int> merge(const std::vector<std::pair<int, int>> &a,\n     \
    \                         Type t) {\n        if (a.size() == 1) {\n          \
    \  return a[0];\n        }\n        int sum = 0;\n        for (auto [v_, s] :\
    \ a) sum += s;\n        std::vector<std::pair<int, int>> b, c;\n        for (auto\
    \ [i, s] : a) {\n            if (sum > s)\n                b.emplace_back(i, s);\n\
    \            else\n                c.emplace_back(i, s);\n            sum -= 2\
    \ * s;\n        }\n        auto [i, si] = merge(b, t);\n        auto [j, sj] =\
    \ merge(c, t);\n        return {new_node(-1, i, j, t), si + sj};\n    }\n\n  \
    \  std::pair<int, int> compress(int v) {\n        std::vector<std::pair<int, int>>\
    \ path{add_vertex(v)};\n        while (g[v][0].to != par[v]) {\n            path.emplace_back(add_vertex(v\
    \ = g[v][0].to));\n        }\n        return merge(path, Type::Compress);\n  \
    \  }\n\n    std::pair<int, int> rake(int v) {\n        std::vector<std::pair<int,\
    \ int>> ch;\n        for (int i = 1; i < (int)g[v].size(); i++) {\n          \
    \  if (g[v][i].to == par[v]) continue;\n            ch.emplace_back(add_edge(g[v][i].to));\n\
    \        }\n        return ch.empty() ? std::pair<int, int>{-1, 0} : merge(ch,\
    \ Type::Rake);\n    }\n\n    std::pair<int, int> add_edge(int v) {\n        auto\
    \ [i, si] = compress(v);\n        return {new_node(-1, i, -1, Type::AddEdge),\
    \ si};\n    }\n\n    std::pair<int, int> add_vertex(int v) {\n        auto [i,\
    \ si] = rake(v);\n        return {new_node(v, i, -1, i == -1 ? Type::Vertex :\
    \ Type::AddVertex),\n                si + 1};\n    }\n\n  public:\n    static_top_tree(Graph<T>\
    \ g_, int root = 0)\n        : n(g_.size()), g(g_), par(n, -1), sz(n, 1), stt(n)\
    \ {\n        if (n == 1) {\n            stt_root = 0;\n            return;\n \
    \       }\n        dfs_sz(root);\n        stt_root = compress(root).first;\n \
    \   }\n\n    int node_num() const {\n        return (int)stt.size();\n    }\n\n\
    \    int parent(int v) const {\n        return stt[v].par;\n    }\n\n    std::pair<int,\
    \ int> child(int v) const {\n        return {stt[v].lch, stt[v].rch};\n    }\n\
    \n    int left_child(int v) const {\n        return stt[v].lch;\n    }\n\n   \
    \ int right_child(int v) const {\n        return stt[v].rch;\n    }\n\n    Type\
    \ type(int v) const {\n        return stt[v].ty;\n    }\n\n    int root() const\
    \ {\n        return stt_root;\n    }\n\n  private:\n    int n;\n    Graph<T> g;\n\
    \    std::vector<int> par, sz;\n    std::vector<Node> stt;\n    int stt_root;\n\
    };\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include \"../graph/base.hpp\"\n\nnamespace ebi {\n\nenum\
    \ Type { Vertex, Compress, Rake, AddEdge, AddVertex };\n\ntemplate <class T> struct\
    \ static_top_tree {\n  private:\n    struct Node {\n        int par = -1, lch\
    \ = -1, rch = -1;\n        Type ty = Type::Vertex;\n    };\n\n    void dfs_sz(int\
    \ v) {\n        for (auto &e : g[v]) {\n            if (e.to == par[v]) continue;\n\
    \            par[e.to] = v;\n            dfs_sz(e.to);\n            sz[v] += sz[e.to];\n\
    \            if (sz[e.to] > sz[g[v][0].to] || g[v][0].to == par[v]) {\n      \
    \          std::swap(e, g[v][0]);\n            }\n        }\n    }\n\n    int\
    \ new_node(int k, int l, int r, Type t) {\n        if (k == -1) {\n          \
    \  k = (int)stt.size();\n            stt.emplace_back(-1, l, r, t);\n        }\
    \ else {\n            stt[k].lch = l;\n            stt[k].rch = r;\n         \
    \   stt[k].ty = t;\n        }\n        if (l != -1) stt[l].par = k;\n        if\
    \ (r != -1) stt[r].par = k;\n        return k;\n    }\n\n    std::pair<int, int>\
    \ merge(const std::vector<std::pair<int, int>> &a,\n                         \
    \     Type t) {\n        if (a.size() == 1) {\n            return a[0];\n    \
    \    }\n        int sum = 0;\n        for (auto [v_, s] : a) sum += s;\n     \
    \   std::vector<std::pair<int, int>> b, c;\n        for (auto [i, s] : a) {\n\
    \            if (sum > s)\n                b.emplace_back(i, s);\n           \
    \ else\n                c.emplace_back(i, s);\n            sum -= 2 * s;\n   \
    \     }\n        auto [i, si] = merge(b, t);\n        auto [j, sj] = merge(c,\
    \ t);\n        return {new_node(-1, i, j, t), si + sj};\n    }\n\n    std::pair<int,\
    \ int> compress(int v) {\n        std::vector<std::pair<int, int>> path{add_vertex(v)};\n\
    \        while (g[v][0].to != par[v]) {\n            path.emplace_back(add_vertex(v\
    \ = g[v][0].to));\n        }\n        return merge(path, Type::Compress);\n  \
    \  }\n\n    std::pair<int, int> rake(int v) {\n        std::vector<std::pair<int,\
    \ int>> ch;\n        for (int i = 1; i < (int)g[v].size(); i++) {\n          \
    \  if (g[v][i].to == par[v]) continue;\n            ch.emplace_back(add_edge(g[v][i].to));\n\
    \        }\n        return ch.empty() ? std::pair<int, int>{-1, 0} : merge(ch,\
    \ Type::Rake);\n    }\n\n    std::pair<int, int> add_edge(int v) {\n        auto\
    \ [i, si] = compress(v);\n        return {new_node(-1, i, -1, Type::AddEdge),\
    \ si};\n    }\n\n    std::pair<int, int> add_vertex(int v) {\n        auto [i,\
    \ si] = rake(v);\n        return {new_node(v, i, -1, i == -1 ? Type::Vertex :\
    \ Type::AddVertex),\n                si + 1};\n    }\n\n  public:\n    static_top_tree(Graph<T>\
    \ g_, int root = 0)\n        : n(g_.size()), g(g_), par(n, -1), sz(n, 1), stt(n)\
    \ {\n        if (n == 1) {\n            stt_root = 0;\n            return;\n \
    \       }\n        dfs_sz(root);\n        stt_root = compress(root).first;\n \
    \   }\n\n    int node_num() const {\n        return (int)stt.size();\n    }\n\n\
    \    int parent(int v) const {\n        return stt[v].par;\n    }\n\n    std::pair<int,\
    \ int> child(int v) const {\n        return {stt[v].lch, stt[v].rch};\n    }\n\
    \n    int left_child(int v) const {\n        return stt[v].lch;\n    }\n\n   \
    \ int right_child(int v) const {\n        return stt[v].rch;\n    }\n\n    Type\
    \ type(int v) const {\n        return stt[v].ty;\n    }\n\n    int root() const\
    \ {\n        return stt_root;\n    }\n\n  private:\n    int n;\n    Graph<T> g;\n\
    \    std::vector<int> par, sz;\n    std::vector<Node> stt;\n    int stt_root;\n\
    };\n\n}  // namespace ebi"
  dependsOn:
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: false
  path: tree/static_top_tree.hpp
  requiredBy:
  - tree/dp_on_static_top_tree.hpp
  timestamp: '2025-03-18 01:14:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Point_Set_Tree_Path_Composition_Sum_Fixed_Root.test.cpp
documentation_of: tree/static_top_tree.hpp
layout: document
title: Static Top Tree
---

## 説明

Static Top Treeを構成する。 $O(N)$

Static Top Treeの各ノードには次のタイプがある。

- `Vertex`: 頂点属性
- `Compress`: path clusterをマージしている属性
- `Rake`: point clusterをマージしている属性
- `AddEdge`: point clusterを作成している属性
- `AddVertex`: point clusterに頂点を追加してpath clusterにしている属性

### 参考文献

[AtCoder Beginner Contest 351 解説](https://atcoder.jp/contests/abc351/editorial/9868)