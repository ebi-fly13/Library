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
    path: test/graph/Cycle_Detection_Directed.test.cpp
    title: test/graph/Cycle_Detection_Directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Cycle_Detection_Undirected.test.cpp
    title: test/graph/Cycle_Detection_Undirected.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/cycle_detection.hpp\"\n\n#include <algorithm>\n#include\
    \ <optional>\n#include <utility>\n#include <vector>\n\n#line 2 \"graph/base.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n#include <ranges>\n#line 7 \"graph/base.hpp\"\
    \n\n#line 2 \"data_structure/simple_csr.hpp\"\n\n#line 6 \"data_structure/simple_csr.hpp\"\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 9 \"graph/cycle_detection.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T>\nstd::optional<std::pair<std::vector<int>,\
    \ std::vector<int>>>\ncycle_detection_directed(const Graph<T> &g) {\n    int n\
    \ = g.node_number();\n    std::vector<int> used(n, -1);\n    std::vector<int>\
    \ par_idx(n, -1);\n\n    std::vector<int> vs, es;\n    auto dfs = [&](auto &&self,\
    \ int v) -> void {\n        used[v] = 1;\n        for (auto e : g[v]) {\n    \
    \        if (!es.empty()) return;\n            if (used[e.to] == -1) {\n     \
    \           used[e.to] = 1;\n                par_idx[e.to] = e.id;\n         \
    \       self(self, e.to);\n            } else if (used[e.to] == 1) {\n       \
    \         int now = v;\n                vs.emplace_back(now);\n              \
    \  es.emplace_back(e.id);\n                while (now != e.to) {\n           \
    \         es.emplace_back(par_idx[now]);\n                    now = g.get_edge(par_idx[now]).from;\n\
    \                }\n                std::reverse(vs.begin(), vs.end());\n    \
    \            std::reverse(es.begin(), es.end());\n                return;\n  \
    \          }\n        }\n        used[v] = 2;\n    };\n    for (auto v : std::views::iota(0,\
    \ n)) {\n        if (used[v] != -1) continue;\n        dfs(dfs, v);\n        if\
    \ (!es.empty()) {\n            return std::pair<std::vector<int>, std::vector<int>>{vs,\
    \ es};\n        }\n    }\n    return std::nullopt;\n}\n\ntemplate <class T>\n\
    std::optional<std::pair<std::vector<int>, std::vector<int>>>\ncycle_detection_undirected(const\
    \ Graph<T> &g) {\n    int n = g.node_number();\n    int m = g.edge_number();\n\
    \    std::vector<bool> used_edge(m, false);\n    std::vector<int> depth(n, -1);\n\
    \    std::vector<int> par_idx(n, -1);\n\n    auto dfs = [&](auto &&self, int v)\
    \ -> int {\n        for (auto e : g[v]) {\n            if (used_edge[e.id]) continue;\n\
    \            if (depth[e.to] != -1) return e.id;\n            used_edge[e.id]\
    \ = true;\n            par_idx[e.to] = e.id;\n            depth[e.to] = depth[v]\
    \ + 1;\n            int x = self(self, e.to);\n            if (x != -1) return\
    \ x;\n        }\n        return -1;\n    };\n\n    for (auto v : std::views::iota(0,\
    \ n)) {\n        if (depth[v] != -1) continue;\n        depth[v] = 0;\n      \
    \  int id = dfs(dfs, v);\n        if (id == -1) continue;\n        int s = -1;\n\
    \        {\n            auto e = g.get_edge(id);\n            if (depth[e.to]\
    \ < depth[e.from])\n                s = e.to;\n            else\n            \
    \    s = e.from;\n        }\n        std::vector<int> vs, es;\n        vs.emplace_back(s),\
    \ es.emplace_back(id);\n        while (1) {\n            auto e = g.get_edge(es.back());\n\
    \            int u = e.from ^ e.to ^ vs.back();\n            if (u == s) break;\n\
    \            vs.emplace_back(u), es.emplace_back(par_idx[u]);\n        }\n   \
    \     return std::pair<std::vector<int>, std::vector<int>>{vs, es};\n    }\n \
    \   return std::nullopt;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <optional>\n#include <utility>\n\
    #include <vector>\n\n#include \"../graph/base.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class T>\nstd::optional<std::pair<std::vector<int>, std::vector<int>>>\ncycle_detection_directed(const\
    \ Graph<T> &g) {\n    int n = g.node_number();\n    std::vector<int> used(n, -1);\n\
    \    std::vector<int> par_idx(n, -1);\n\n    std::vector<int> vs, es;\n    auto\
    \ dfs = [&](auto &&self, int v) -> void {\n        used[v] = 1;\n        for (auto\
    \ e : g[v]) {\n            if (!es.empty()) return;\n            if (used[e.to]\
    \ == -1) {\n                used[e.to] = 1;\n                par_idx[e.to] = e.id;\n\
    \                self(self, e.to);\n            } else if (used[e.to] == 1) {\n\
    \                int now = v;\n                vs.emplace_back(now);\n       \
    \         es.emplace_back(e.id);\n                while (now != e.to) {\n    \
    \                es.emplace_back(par_idx[now]);\n                    now = g.get_edge(par_idx[now]).from;\n\
    \                }\n                std::reverse(vs.begin(), vs.end());\n    \
    \            std::reverse(es.begin(), es.end());\n                return;\n  \
    \          }\n        }\n        used[v] = 2;\n    };\n    for (auto v : std::views::iota(0,\
    \ n)) {\n        if (used[v] != -1) continue;\n        dfs(dfs, v);\n        if\
    \ (!es.empty()) {\n            return std::pair<std::vector<int>, std::vector<int>>{vs,\
    \ es};\n        }\n    }\n    return std::nullopt;\n}\n\ntemplate <class T>\n\
    std::optional<std::pair<std::vector<int>, std::vector<int>>>\ncycle_detection_undirected(const\
    \ Graph<T> &g) {\n    int n = g.node_number();\n    int m = g.edge_number();\n\
    \    std::vector<bool> used_edge(m, false);\n    std::vector<int> depth(n, -1);\n\
    \    std::vector<int> par_idx(n, -1);\n\n    auto dfs = [&](auto &&self, int v)\
    \ -> int {\n        for (auto e : g[v]) {\n            if (used_edge[e.id]) continue;\n\
    \            if (depth[e.to] != -1) return e.id;\n            used_edge[e.id]\
    \ = true;\n            par_idx[e.to] = e.id;\n            depth[e.to] = depth[v]\
    \ + 1;\n            int x = self(self, e.to);\n            if (x != -1) return\
    \ x;\n        }\n        return -1;\n    };\n\n    for (auto v : std::views::iota(0,\
    \ n)) {\n        if (depth[v] != -1) continue;\n        depth[v] = 0;\n      \
    \  int id = dfs(dfs, v);\n        if (id == -1) continue;\n        int s = -1;\n\
    \        {\n            auto e = g.get_edge(id);\n            if (depth[e.to]\
    \ < depth[e.from])\n                s = e.to;\n            else\n            \
    \    s = e.from;\n        }\n        std::vector<int> vs, es;\n        vs.emplace_back(s),\
    \ es.emplace_back(id);\n        while (1) {\n            auto e = g.get_edge(es.back());\n\
    \            int u = e.from ^ e.to ^ vs.back();\n            if (u == s) break;\n\
    \            vs.emplace_back(u), es.emplace_back(par_idx[u]);\n        }\n   \
    \     return std::pair<std::vector<int>, std::vector<int>>{vs, es};\n    }\n \
    \   return std::nullopt;\n}\n\n}  // namespace ebi"
  dependsOn:
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: false
  path: graph/cycle_detection.hpp
  requiredBy: []
  timestamp: '2024-03-13 17:06:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Cycle_Detection_Directed.test.cpp
  - test/graph/Cycle_Detection_Undirected.test.cpp
documentation_of: graph/cycle_detection.hpp
layout: document
title: Cycle Detection
---

## 説明

グラフを与えてサイクルを検出する。サイクルが存在する場合、サイクルの $1$ つを返す。 $O(N+M)$