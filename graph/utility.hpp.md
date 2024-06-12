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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/utility.hpp\"\n\n#line 2 \"graph/base.hpp\"\n\n#include\
    \ <cassert>\n#include <iostream>\n#include <ranges>\n#include <vector>\n\n#line\
    \ 2 \"data_structure/simple_csr.hpp\"\n\n#line 4 \"data_structure/simple_csr.hpp\"\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 4 \"graph/utility.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> Graph<T> remove_isolated_vertex(const\
    \ Graph<T> &g) {\n    const int n = g.node_number();\n    std::vector<int> seen(n,\
    \ -1);\n    for (auto e : g.get_edges()) {\n        seen[e.from] = seen[e.to]\
    \ = 1;\n    }\n    int sz = 0;\n    for (int i = 0; i < n; i++) {\n        if\
    \ (seen[i] != -1) seen[i] = sz++;\n    }\n    Graph<T> gh(sz);\n    for (auto\
    \ e : g.get_edges()) {\n        gh.add_undirected_edge(seen[e.from], seen[e.to],\
    \ e.cost);\n    }\n    gh.build();\n    return gh;\n}\n\ntemplate <class T>\n\
    std::vector<std::vector<T>> remove_isolated_vertex(\n    const std::vector<std::vector<T>>\
    \ &g) {\n    const int n = (int)g.size();\n    std::vector<int> seen(n, -1);\n\
    \    for (int i = 0; i < n; i++) {\n        for (int j = 0; j < n; j++) {\n  \
    \          if (g[i][j] != 0) seen[i] = seen[j] = 1;\n        }\n    }\n    int\
    \ sz = 0;\n    for (int i = 0; i < n; i++) {\n        if (seen[i] != -1) seen[i]\
    \ = sz++;\n    }\n    std::vector gh(sz, std::vector<int>(sz, 0));\n    for (int\
    \ i = 0; i < n; i++) {\n        if (seen[i] == -1) continue;\n        for (int\
    \ j = 0; j < n; j++) {\n            if (seen[j] == -1) continue;\n           \
    \ gh[seen[i]][seen[j]] += g[i][j];\n        }\n    }\n    return gh;\n}\n\n} \
    \ // namespace ebi\n"
  code: "#pragma once\n\n#include \"graph/base.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class T> Graph<T> remove_isolated_vertex(const Graph<T> &g) {\n    const int\
    \ n = g.node_number();\n    std::vector<int> seen(n, -1);\n    for (auto e : g.get_edges())\
    \ {\n        seen[e.from] = seen[e.to] = 1;\n    }\n    int sz = 0;\n    for (int\
    \ i = 0; i < n; i++) {\n        if (seen[i] != -1) seen[i] = sz++;\n    }\n  \
    \  Graph<T> gh(sz);\n    for (auto e : g.get_edges()) {\n        gh.add_undirected_edge(seen[e.from],\
    \ seen[e.to], e.cost);\n    }\n    gh.build();\n    return gh;\n}\n\ntemplate\
    \ <class T>\nstd::vector<std::vector<T>> remove_isolated_vertex(\n    const std::vector<std::vector<T>>\
    \ &g) {\n    const int n = (int)g.size();\n    std::vector<int> seen(n, -1);\n\
    \    for (int i = 0; i < n; i++) {\n        for (int j = 0; j < n; j++) {\n  \
    \          if (g[i][j] != 0) seen[i] = seen[j] = 1;\n        }\n    }\n    int\
    \ sz = 0;\n    for (int i = 0; i < n; i++) {\n        if (seen[i] != -1) seen[i]\
    \ = sz++;\n    }\n    std::vector gh(sz, std::vector<int>(sz, 0));\n    for (int\
    \ i = 0; i < n; i++) {\n        if (seen[i] == -1) continue;\n        for (int\
    \ j = 0; j < n; j++) {\n            if (seen[j] == -1) continue;\n           \
    \ gh[seen[i]][seen[j]] += g[i][j];\n        }\n    }\n    return gh;\n}\n\n} \
    \ // namespace ebi"
  dependsOn:
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: false
  path: graph/utility.hpp
  requiredBy: []
  timestamp: '2024-06-06 22:34:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/utility.hpp
layout: document
title: "\u4FBF\u5229\u95A2\u6570"
---

## 説明

グラフを取り扱う便利関数詰め合わせ。

### remove_isolated_vertex(Graph<T> g)

$g$ から孤立点を取り除いたグラフを返す。

### remove_isolated_vertex(std::vector<std::vector<int>> g)

グラフを隣接行列表現で与え、 $g$ から孤立店を取り除いたグラフを返す。