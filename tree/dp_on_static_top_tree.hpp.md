---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: "\u4FBF\u5229\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: tree/static_top_tree.hpp
    title: Static Top Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/Point_Set_Tree_Path_Composition_Sum_Fixed_Root.test.cpp
    title: test/tree/Point_Set_Tree_Path_Composition_Sum_Fixed_Root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/dp_on_static_top_tree.hpp\"\n\n#line 2 \"tree/static_top_tree.hpp\"\
    \n\n#line 2 \"graph/base.hpp\"\n\n#include <cassert>\n#include <iostream>\n#include\
    \ <ranges>\n#include <vector>\n\n#line 2 \"data_structure/simple_csr.hpp\"\n\n\
    #line 4 \"data_structure/simple_csr.hpp\"\n#include <utility>\n#line 6 \"data_structure/simple_csr.hpp\"\
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
    };\n\n}  // namespace ebi\n#line 4 \"tree/dp_on_static_top_tree.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <class T, class Path, class Point, class Compress, class Rake,\n\
    \          class Add_edge, class Add_vertex>\nstruct dp_on_static_top_tree {\n\
    \  private:\n    void dfs(int v) {\n        auto [lch, rch] = stt.child(v);\n\
    \        if (lch != -1) dfs(lch);\n        if (rch != -1) dfs(rch);\n        update_(v);\n\
    \    }\n\n    void update_(int v) {\n        if (stt.type(v) == Type::Vertex)\
    \ {\n            path[v] = vertex[v];\n        } else if (stt.type(v) == Type::Compress)\
    \ {\n            path[v] =\n                compress(path[stt.left_child(v)],\
    \ path[stt.right_child(v)]);\n        } else if (stt.type(v) == Type::Rake) {\n\
    \            point[v] =\n                rake(point[stt.left_child(v)], point[stt.right_child(v)]);\n\
    \        } else if (stt.type(v) == Type::AddEdge) {\n            point[v] = add_edge(path[stt.left_child(v)]);\n\
    \        } else if (stt.type(v) == Type::AddVertex) {\n            path[v] = add_vertex(point[stt.left_child(v)],\
    \ vertex[v]);\n        }\n    }\n\n    void update(int v) {\n        while (v\
    \ != -1) {\n            update_(v);\n            v = stt.parent(v);\n        }\n\
    \    }\n\n  public:\n    dp_on_static_top_tree(const Graph<T> &g, int root,\n\
    \                          const std::vector<Path> &vertex_,\n               \
    \           const Compress &compress_, const Rake &rake_,\n                  \
    \        const Add_edge &add_edge_,\n                          const Add_vertex\
    \ &add_vertex_)\n        : stt(g, root),\n          n(stt.node_num()),\n     \
    \     path(n),\n          point(n),\n          vertex(vertex_),\n          compress(compress_),\n\
    \          rake(rake_),\n          add_edge(add_edge_),\n          add_vertex(add_vertex_)\
    \ {\n        dfs(stt.root());\n    }\n\n    Path get() const {\n        return\
    \ path[stt.root()];\n    }\n\n    void set(int v, Path x) {\n        vertex[v]\
    \ = x;\n        update(v);\n    }\n\n  private:\n    static_top_tree<T> stt;\n\
    \n    int n;\n    std::vector<Path> path;\n    std::vector<Point> point;\n   \
    \ std::vector<Path> vertex;\n    const Compress compress;\n    const Rake rake;\n\
    \    const Add_edge add_edge;\n    const Add_vertex add_vertex;\n};\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include \"../tree/static_top_tree.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <class T, class Path, class Point, class Compress, class Rake,\n\
    \          class Add_edge, class Add_vertex>\nstruct dp_on_static_top_tree {\n\
    \  private:\n    void dfs(int v) {\n        auto [lch, rch] = stt.child(v);\n\
    \        if (lch != -1) dfs(lch);\n        if (rch != -1) dfs(rch);\n        update_(v);\n\
    \    }\n\n    void update_(int v) {\n        if (stt.type(v) == Type::Vertex)\
    \ {\n            path[v] = vertex[v];\n        } else if (stt.type(v) == Type::Compress)\
    \ {\n            path[v] =\n                compress(path[stt.left_child(v)],\
    \ path[stt.right_child(v)]);\n        } else if (stt.type(v) == Type::Rake) {\n\
    \            point[v] =\n                rake(point[stt.left_child(v)], point[stt.right_child(v)]);\n\
    \        } else if (stt.type(v) == Type::AddEdge) {\n            point[v] = add_edge(path[stt.left_child(v)]);\n\
    \        } else if (stt.type(v) == Type::AddVertex) {\n            path[v] = add_vertex(point[stt.left_child(v)],\
    \ vertex[v]);\n        }\n    }\n\n    void update(int v) {\n        while (v\
    \ != -1) {\n            update_(v);\n            v = stt.parent(v);\n        }\n\
    \    }\n\n  public:\n    dp_on_static_top_tree(const Graph<T> &g, int root,\n\
    \                          const std::vector<Path> &vertex_,\n               \
    \           const Compress &compress_, const Rake &rake_,\n                  \
    \        const Add_edge &add_edge_,\n                          const Add_vertex\
    \ &add_vertex_)\n        : stt(g, root),\n          n(stt.node_num()),\n     \
    \     path(n),\n          point(n),\n          vertex(vertex_),\n          compress(compress_),\n\
    \          rake(rake_),\n          add_edge(add_edge_),\n          add_vertex(add_vertex_)\
    \ {\n        dfs(stt.root());\n    }\n\n    Path get() const {\n        return\
    \ path[stt.root()];\n    }\n\n    void set(int v, Path x) {\n        vertex[v]\
    \ = x;\n        update(v);\n    }\n\n  private:\n    static_top_tree<T> stt;\n\
    \n    int n;\n    std::vector<Path> path;\n    std::vector<Point> point;\n   \
    \ std::vector<Path> vertex;\n    const Compress compress;\n    const Rake rake;\n\
    \    const Add_edge add_edge;\n    const Add_vertex add_vertex;\n};\n\n}  // namespace\
    \ ebi"
  dependsOn:
  - tree/static_top_tree.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: false
  path: tree/dp_on_static_top_tree.hpp
  requiredBy: []
  timestamp: '2024-05-23 21:35:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Point_Set_Tree_Path_Composition_Sum_Fixed_Root.test.cpp
documentation_of: tree/dp_on_static_top_tree.hpp
layout: document
title: DP on Static Top Tree
---

## 説明

$1$ 点更新・木DP計算が可能なデータ構造である。

必要な関数は以下である。

- `compress(Path p, Path c) -> Path`: path clusterをマージしてpath clusterを返す関数
- `rake(Point a, Point b) -> Point`: point clusterをマージしてpoint clusterを返す関数
- `add_edge(Path a) -> Point`: path clusterに仮想的な頂点を追加してpoint clusterを返す関数
- `add_vertex(Point a, Path v) -> Path`: point clusterに頂点 $v$ を追加してpath clusterを返す関数

### 参考文献

[AtCoder Beginner Contest 351 解説](https://atcoder.jp/contests/abc351/editorial/9868)