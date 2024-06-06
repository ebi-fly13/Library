---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: "\u4FBF\u5229\u95A2\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Maximum_Independent_Set.test.cpp
    title: test/graph/Maximum_Independent_Set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/maximum_independent_set.hpp\"\n\n#include <cassert>\n\
    #include <ranges>\n#include <vector>\n\n#line 2 \"graph/base.hpp\"\n\n#line 4\
    \ \"graph/base.hpp\"\n#include <iostream>\n#line 7 \"graph/base.hpp\"\n\n#line\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 8 \"graph/maximum_independent_set.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> std::vector<int> maximum_independent_set(const\
    \ Graph<T> &g) {\n    int n = g.node_number();\n    std::vector<int> deg(n);\n\
    \    for (auto v : std::views::iota(0, n)) {\n        deg[v] = g[v].size();\n\
    \    }\n    std::vector<int> max_set;\n    std::vector<int> used;\n    std::vector<int>\
    \ dead(n, 0);\n    int alive = n;\n    auto dfs = [&](auto &&self) -> void {\n\
    \        if ((int)used.size() + alive <= (int)max_set.size()) return;\n      \
    \  int v = -1;\n        for (auto u : std::views::iota(0, n)) {\n            if\
    \ (dead[u]) continue;\n            if (deg[u] <= 1) {\n                v = u;\n\
    \                break;\n            }\n            if (v == -1 || deg[v] < deg[u])\
    \ v = u;\n        }\n        if (v < 0) return;\n\n        if (deg[v] > 1) {\n\
    \            dead[v] = 1;\n            alive--;\n            for (auto e : g[v])\
    \ deg[e.to]--;\n\n            self(self);\n\n            dead[v] = 0;\n      \
    \      alive++;\n            for (auto e : g[v]) deg[e.to]++;\n        }\n   \
    \     {\n            used.emplace_back(v);\n            dead[v] = 1;\n       \
    \     alive--;\n            for (auto e : g[v]) {\n                if (dead[e.to]++\
    \ == 0) {\n                    alive--;\n                }\n            }\n  \
    \          if (max_set.size() < used.size()) max_set = used;\n\n            self(self);\n\
    \n            used.pop_back();\n            dead[v] = 0;\n            alive++;\n\
    \            for (auto e : g[v]) {\n                if (--dead[e.to] == 0) {\n\
    \                    alive++;\n                }\n            }\n        }\n \
    \   };\n    dfs(dfs);\n    return max_set;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <ranges>\n#include <vector>\n\
    \n#include \"../graph/base.hpp\"\n\nnamespace ebi {\n\ntemplate <class T> std::vector<int>\
    \ maximum_independent_set(const Graph<T> &g) {\n    int n = g.node_number();\n\
    \    std::vector<int> deg(n);\n    for (auto v : std::views::iota(0, n)) {\n \
    \       deg[v] = g[v].size();\n    }\n    std::vector<int> max_set;\n    std::vector<int>\
    \ used;\n    std::vector<int> dead(n, 0);\n    int alive = n;\n    auto dfs =\
    \ [&](auto &&self) -> void {\n        if ((int)used.size() + alive <= (int)max_set.size())\
    \ return;\n        int v = -1;\n        for (auto u : std::views::iota(0, n))\
    \ {\n            if (dead[u]) continue;\n            if (deg[u] <= 1) {\n    \
    \            v = u;\n                break;\n            }\n            if (v\
    \ == -1 || deg[v] < deg[u]) v = u;\n        }\n        if (v < 0) return;\n\n\
    \        if (deg[v] > 1) {\n            dead[v] = 1;\n            alive--;\n \
    \           for (auto e : g[v]) deg[e.to]--;\n\n            self(self);\n\n  \
    \          dead[v] = 0;\n            alive++;\n            for (auto e : g[v])\
    \ deg[e.to]++;\n        }\n        {\n            used.emplace_back(v);\n    \
    \        dead[v] = 1;\n            alive--;\n            for (auto e : g[v]) {\n\
    \                if (dead[e.to]++ == 0) {\n                    alive--;\n    \
    \            }\n            }\n            if (max_set.size() < used.size()) max_set\
    \ = used;\n\n            self(self);\n\n            used.pop_back();\n       \
    \     dead[v] = 0;\n            alive++;\n            for (auto e : g[v]) {\n\
    \                if (--dead[e.to] == 0) {\n                    alive++;\n    \
    \            }\n            }\n        }\n    };\n    dfs(dfs);\n    return max_set;\n\
    }\n\n}  // namespace ebi"
  dependsOn:
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: false
  path: graph/maximum_independent_set.hpp
  requiredBy: []
  timestamp: '2024-04-03 15:35:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Maximum_Independent_Set.test.cpp
documentation_of: graph/maximum_independent_set.hpp
layout: document
title: Maximum Independent Set
---

## 説明

グラフを与えて、最大独立集合を求める。