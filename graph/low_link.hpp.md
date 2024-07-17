---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: Graph (CSR format)
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/biconnected_components.hpp
    title: graph/biconnected_components.hpp
  - icon: ':heavy_check_mark:'
    path: graph/two_edge_connected_components.hpp
    title: Two Edge Connected Components
  - icon: ':heavy_check_mark:'
    path: tree/block_cut_tree.hpp
    title: Block Cut Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Articulation_Points.test.cpp
    title: test/graph/Articulation_Points.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Biconnected_Components.test.cpp
    title: test/graph/Biconnected_Components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Two_Edge_Connected_Components.test.cpp
    title: test/graph/Two_Edge_Connected_Components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/low_link.hpp\"\n\n#include <algorithm>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"graph/base.hpp\"\n\n#include <cassert>\n#include\
    \ <iostream>\n#include <ranges>\n#line 7 \"graph/base.hpp\"\n\n#line 2 \"data_structure/simple_csr.hpp\"\
    \n\n#line 6 \"data_structure/simple_csr.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ E> struct simple_csr {\n    simple_csr() = default;\n\n    simple_csr(int n,\
    \ const std::vector<std::pair<int, E>>& elements)\n        : start(n + 1, 0),\
    \ elist(elements.size()) {\n        for (auto e : elements) {\n            start[e.first\
    \ + 1]++;\n        }\n        for (auto i : std::views::iota(0, n)) {\n      \
    \      start[i + 1] += start[i];\n        }\n        auto counter = start;\n \
    \       for (auto [i, e] : elements) {\n            elist[counter[i]++] = e;\n\
    \        }\n    }\n\n    simple_csr(const std::vector<std::vector<E>>& es)\n \
    \       : start(es.size() + 1, 0) {\n        int n = es.size();\n        for (auto\
    \ i : std::views::iota(0, n)) {\n            start[i + 1] = (int)es[i].size()\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 8 \"graph/low_link.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> struct low_link {\n  private:\n    void\
    \ dfs(int v, int par = -1) {\n        static int k = 0;\n        low[v] = ord[v]\
    \ = k++;\n        int cnt = 0;\n        bool is_arti = false, is_second = false;\n\
    \        for (auto e : g[v]) {\n            int nv = e.to;\n            if (ord[nv]\
    \ == -1) {\n                cnt++;\n                dfs(nv, v);\n            \
    \    low[v] = std::min(low[v], low[nv]);\n                is_arti |= (par != -1)\
    \ && (low[nv] >= ord[v]);\n                if (ord[v] < low[nv]) {\n         \
    \           _bridge.emplace_back(std::minmax(v, nv));\n                }\n   \
    \         } else if (nv != par || is_second) {\n                low[v] = std::min(low[v],\
    \ ord[nv]);\n            } else {\n                is_second = true;\n       \
    \     }\n        }\n        is_arti |= par == -1 && cnt > 1;\n        if (is_arti)\
    \ _articulation.emplace_back(v);\n    }\n\n  public:\n    low_link(const Graph<T>\
    \ &g) : n(g.size()), g(g), ord(n, -1), low(n) {\n        for (int i = 0; i < n;\
    \ i++) {\n            if (ord[i] == -1) dfs(i);\n        }\n    }\n\n    std::vector<int>\
    \ articulation() const {\n        return _articulation;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> bridge() const {\n        return _bridge;\n    }\n\n  protected:\n   \
    \ int n;\n    Graph<T> g;\n    std::vector<int> ord, low, _articulation;\n   \
    \ std::vector<std::pair<int, int>> _bridge;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    \n#include \"../graph/base.hpp\"\n\nnamespace ebi {\n\ntemplate <class T> struct\
    \ low_link {\n  private:\n    void dfs(int v, int par = -1) {\n        static\
    \ int k = 0;\n        low[v] = ord[v] = k++;\n        int cnt = 0;\n        bool\
    \ is_arti = false, is_second = false;\n        for (auto e : g[v]) {\n       \
    \     int nv = e.to;\n            if (ord[nv] == -1) {\n                cnt++;\n\
    \                dfs(nv, v);\n                low[v] = std::min(low[v], low[nv]);\n\
    \                is_arti |= (par != -1) && (low[nv] >= ord[v]);\n            \
    \    if (ord[v] < low[nv]) {\n                    _bridge.emplace_back(std::minmax(v,\
    \ nv));\n                }\n            } else if (nv != par || is_second) {\n\
    \                low[v] = std::min(low[v], ord[nv]);\n            } else {\n \
    \               is_second = true;\n            }\n        }\n        is_arti |=\
    \ par == -1 && cnt > 1;\n        if (is_arti) _articulation.emplace_back(v);\n\
    \    }\n\n  public:\n    low_link(const Graph<T> &g) : n(g.size()), g(g), ord(n,\
    \ -1), low(n) {\n        for (int i = 0; i < n; i++) {\n            if (ord[i]\
    \ == -1) dfs(i);\n        }\n    }\n\n    std::vector<int> articulation() const\
    \ {\n        return _articulation;\n    }\n\n    std::vector<std::pair<int, int>>\
    \ bridge() const {\n        return _bridge;\n    }\n\n  protected:\n    int n;\n\
    \    Graph<T> g;\n    std::vector<int> ord, low, _articulation;\n    std::vector<std::pair<int,\
    \ int>> _bridge;\n};\n\n}  // namespace ebi"
  dependsOn:
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: false
  path: graph/low_link.hpp
  requiredBy:
  - tree/block_cut_tree.hpp
  - graph/biconnected_components.hpp
  - graph/two_edge_connected_components.hpp
  timestamp: '2024-03-13 15:52:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Articulation_Points.test.cpp
  - test/graph/Biconnected_Components.test.cpp
  - test/graph/Two_Edge_Connected_Components.test.cpp
documentation_of: graph/low_link.hpp
layout: document
title: Low Link
---

## 説明

与えたグラフに対して、Low Linkを計算し間節点と橋を求める。 $O(N)$