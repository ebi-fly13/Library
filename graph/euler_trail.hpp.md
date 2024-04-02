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
    path: test/graph/Eulerian_Trail_Directed.test.cpp
    title: test/graph/Eulerian_Trail_Directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Eulerian_Trail_Undirected.test.cpp
    title: test/graph/Eulerian_Trail_Undirected.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/euler_trail.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <optional>\n#include <ranges>\n#include <utility>\n#include\
    \ <vector>\n\n#line 2 \"graph/base.hpp\"\n\n#line 4 \"graph/base.hpp\"\n#include\
    \ <iostream>\n#line 7 \"graph/base.hpp\"\n\n#line 2 \"data_structure/simple_csr.hpp\"\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 11 \"graph/euler_trail.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T>\nstd::optional<std::pair<std::vector<int>,\
    \ std::vector<int>>>\neuler_trail_undirected(const Graph<T> &g, bool circuit =\
    \ false) {\n    int n = g.node_number();\n    int m = g.edge_number();\n    int\
    \ s = -1, t = -1;\n    for (int v : std::views::iota(0, n)) {\n        if (g[v].size()\
    \ & 1) {\n            if (s < 0)\n                s = v;\n            else if\
    \ (t < 0)\n                t = v;\n            else\n                return std::nullopt;\n\
    \        }\n    }\n    if (circuit && s != -1) return std::nullopt;\n    if (!circuit\
    \ && (s != -1 && t == -1)) return std::nullopt;\n    if (m == 0) return std::pair<std::vector<int>,\
    \ std::vector<int>>({0}, {});\n    if (s < 0) s = g.get_edge(0).from;\n    std::vector<int>\
    \ ids(n, 0);\n    std::vector<bool> used(m, false);\n    std::vector<int> vs,\
    \ es;\n    auto dfs = [&](auto &&self, int v) -> void {\n        while (ids[v]\
    \ < (int)g[v].size()) {\n            auto e = g[v][ids[v]++];\n            if\
    \ (used[e.id]) continue;\n            used[e.id] = true;\n            self(self,\
    \ e.to);\n            es.emplace_back(e.id);\n        }\n        vs.emplace_back(v);\n\
    \    };\n    dfs(dfs, s);\n    if ((int)es.size() != m) return std::nullopt;\n\
    \    return std::pair<std::vector<int>, std::vector<int>>(vs, es);\n}\n\ntemplate\
    \ <class T>\nstd::optional<std::pair<std::vector<int>, std::vector<int>>>\neuler_trail_directed(const\
    \ Graph<T> &g, bool circuit = false) {\n    int n = g.node_number();\n    int\
    \ m = g.edge_number();\n    std::vector<int> in(n, 0), out(n, 0);\n    for (auto\
    \ e : g.get_edges()) {\n        in[e.to]++;\n        out[e.from]++;\n    }\n \
    \   int s = -1, t = -1;\n    for (auto v : std::views::iota(0, n)) {\n       \
    \ if (in[v] + 1 == out[v]) {\n            if (s != -1) return std::nullopt;\n\
    \            s = v;\n        } else if (in[v] == out[v] + 1) {\n            if\
    \ (t != -1) return std::nullopt;\n            t = v;\n        } else if (in[v]\
    \ == out[v])\n            continue;\n        else\n            return std::nullopt;\n\
    \    }\n    if (circuit && (s != -1 || t != -1)) return std::nullopt;\n    if\
    \ (!circuit && ((s == -1 && t != -1) || (s != -1 && t == -1)))\n        return\
    \ std::nullopt;\n    if (m == 0) return std::pair<std::vector<int>, std::vector<int>>({0},\
    \ {});\n    if (s == -1) s = g.get_edge(0).from;\n    std::vector<int> vs, es;\n\
    \    std::vector<int> ids(n, 0);\n    auto dfs = [&](auto &&self, int v) -> void\
    \ {\n        while (ids[v] < (int)g[v].size()) {\n            auto e = g[v][ids[v]++];\n\
    \            self(self, e.to);\n            es.emplace_back(e.id);\n        }\n\
    \        vs.emplace_back(v);\n    };\n    dfs(dfs, s);\n    if ((int)es.size()\
    \ != m) return std::nullopt;\n    std::reverse(vs.begin(), vs.end());\n    std::reverse(es.begin(),\
    \ es.end());\n    return std::pair<std::vector<int>, std::vector<int>>(vs, es);\n\
    }\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <optional>\n\
    #include <ranges>\n#include <utility>\n#include <vector>\n\n#include \"../graph/base.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T>\nstd::optional<std::pair<std::vector<int>,\
    \ std::vector<int>>>\neuler_trail_undirected(const Graph<T> &g, bool circuit =\
    \ false) {\n    int n = g.node_number();\n    int m = g.edge_number();\n    int\
    \ s = -1, t = -1;\n    for (int v : std::views::iota(0, n)) {\n        if (g[v].size()\
    \ & 1) {\n            if (s < 0)\n                s = v;\n            else if\
    \ (t < 0)\n                t = v;\n            else\n                return std::nullopt;\n\
    \        }\n    }\n    if (circuit && s != -1) return std::nullopt;\n    if (!circuit\
    \ && (s != -1 && t == -1)) return std::nullopt;\n    if (m == 0) return std::pair<std::vector<int>,\
    \ std::vector<int>>({0}, {});\n    if (s < 0) s = g.get_edge(0).from;\n    std::vector<int>\
    \ ids(n, 0);\n    std::vector<bool> used(m, false);\n    std::vector<int> vs,\
    \ es;\n    auto dfs = [&](auto &&self, int v) -> void {\n        while (ids[v]\
    \ < (int)g[v].size()) {\n            auto e = g[v][ids[v]++];\n            if\
    \ (used[e.id]) continue;\n            used[e.id] = true;\n            self(self,\
    \ e.to);\n            es.emplace_back(e.id);\n        }\n        vs.emplace_back(v);\n\
    \    };\n    dfs(dfs, s);\n    if ((int)es.size() != m) return std::nullopt;\n\
    \    return std::pair<std::vector<int>, std::vector<int>>(vs, es);\n}\n\ntemplate\
    \ <class T>\nstd::optional<std::pair<std::vector<int>, std::vector<int>>>\neuler_trail_directed(const\
    \ Graph<T> &g, bool circuit = false) {\n    int n = g.node_number();\n    int\
    \ m = g.edge_number();\n    std::vector<int> in(n, 0), out(n, 0);\n    for (auto\
    \ e : g.get_edges()) {\n        in[e.to]++;\n        out[e.from]++;\n    }\n \
    \   int s = -1, t = -1;\n    for (auto v : std::views::iota(0, n)) {\n       \
    \ if (in[v] + 1 == out[v]) {\n            if (s != -1) return std::nullopt;\n\
    \            s = v;\n        } else if (in[v] == out[v] + 1) {\n            if\
    \ (t != -1) return std::nullopt;\n            t = v;\n        } else if (in[v]\
    \ == out[v])\n            continue;\n        else\n            return std::nullopt;\n\
    \    }\n    if (circuit && (s != -1 || t != -1)) return std::nullopt;\n    if\
    \ (!circuit && ((s == -1 && t != -1) || (s != -1 && t == -1)))\n        return\
    \ std::nullopt;\n    if (m == 0) return std::pair<std::vector<int>, std::vector<int>>({0},\
    \ {});\n    if (s == -1) s = g.get_edge(0).from;\n    std::vector<int> vs, es;\n\
    \    std::vector<int> ids(n, 0);\n    auto dfs = [&](auto &&self, int v) -> void\
    \ {\n        while (ids[v] < (int)g[v].size()) {\n            auto e = g[v][ids[v]++];\n\
    \            self(self, e.to);\n            es.emplace_back(e.id);\n        }\n\
    \        vs.emplace_back(v);\n    };\n    dfs(dfs, s);\n    if ((int)es.size()\
    \ != m) return std::nullopt;\n    std::reverse(vs.begin(), vs.end());\n    std::reverse(es.begin(),\
    \ es.end());\n    return std::pair<std::vector<int>, std::vector<int>>(vs, es);\n\
    }\n\n}  // namespace ebi"
  dependsOn:
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: false
  path: graph/euler_trail.hpp
  requiredBy: []
  timestamp: '2024-04-02 14:52:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Eulerian_Trail_Undirected.test.cpp
  - test/graph/Eulerian_Trail_Directed.test.cpp
documentation_of: graph/euler_trail.hpp
layout: document
title: Euler Trail
---

## 説明

与えたグラフに対して、オイラー路を構築する。`circuit` に `true` を渡すと、オイラー閉路を構築する。