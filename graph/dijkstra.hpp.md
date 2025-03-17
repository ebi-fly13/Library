---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':question:'
    path: graph/base.hpp
    title: Graph (CSR format)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Shortest_Path.test.cpp
    title: test/graph/Shortest_Path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra.test.cpp
    title: test/graph/dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dijkstra.hpp\"\n\r\n#include <algorithm>\r\n#include\
    \ <limits>\r\n#include <queue>\r\n#include <vector>\r\n\r\n#line 2 \"graph/base.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n#include <ranges>\n#line 7 \"graph/base.hpp\"\
    \n\n#line 2 \"data_structure/simple_csr.hpp\"\n\n#line 4 \"data_structure/simple_csr.hpp\"\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 9 \"graph/dijkstra.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class T> std::vector<T> dijkstra(int s,\
    \ const Graph<T> &g) {\r\n    typedef std::pair<T, int> P;\r\n    int n = g.node_number();\r\
    \n    std::vector<T> d(n, std::numeric_limits<T>::max());\r\n    std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> que;\r\n    que.push(P(0, s));\r\n    d[s]\
    \ = 0;\r\n    while (!que.empty()) {\r\n        auto [ret, v] = que.top();\r\n\
    \        que.pop();\r\n        if (d[v] < ret) continue;\r\n        for (auto\
    \ e : g[v]) {\r\n            if (d[e.to] > d[v] + e.cost) {\r\n              \
    \  d[e.to] = d[v] + e.cost;\r\n                que.push(P(d[e.to], e.to));\r\n\
    \            }\r\n        }\r\n    }\r\n    return d;\r\n}\r\n\r\ntemplate <class\
    \ T> struct dijkstra_path {\r\n  public:\r\n    dijkstra_path(int s_, const Graph<T>\
    \ &g)\r\n        : s(s_),\r\n          dist(g.size(), std::numeric_limits<T>::max()),\r\
    \n          prev(g.size(), -1) {\r\n        dist[s] = 0;\r\n        using P =\
    \ std::pair<T, int>;\r\n        std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ que;\r\n        que.push(P(0, s));\r\n        while (!que.empty()) {\r\n   \
    \         auto [ret, v] = que.top();\r\n            que.pop();\r\n           \
    \ if (dist[v] < ret) continue;\r\n            for (auto e : g[v]) {\r\n      \
    \          if (dist[e.to] > dist[v] + e.cost) {\r\n                    dist[e.to]\
    \ = dist[v] + e.cost;\r\n                    prev[e.to] = v;\r\n             \
    \       que.push(P(dist[e.to], e.to));\r\n                }\r\n            }\r\
    \n        }\r\n    }\r\n\r\n    std::pair<T, std::vector<int>> shortest_path(int\
    \ v) const {\r\n        if (dist[v] == std::numeric_limits<T>::max()) return {dist[v],\
    \ {}};\r\n        std::vector<int> path;\r\n        int u = v;\r\n        while\
    \ (u != s) {\r\n            path.emplace_back(u);\r\n            u = prev[u];\r\
    \n        }\r\n        path.emplace_back(u);\r\n        std::reverse(path.begin(),\
    \ path.end());\r\n        return {dist[v], path};\r\n    }\r\n\r\n  private:\r\
    \n    int s;\r\n    std::vector<T> dist;\r\n    std::vector<int> prev;\r\n};\r\
    \n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <algorithm>\r\n#include <limits>\r\n#include\
    \ <queue>\r\n#include <vector>\r\n\r\n#include \"../graph/base.hpp\"\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <class T> std::vector<T> dijkstra(int s, const Graph<T>\
    \ &g) {\r\n    typedef std::pair<T, int> P;\r\n    int n = g.node_number();\r\n\
    \    std::vector<T> d(n, std::numeric_limits<T>::max());\r\n    std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> que;\r\n    que.push(P(0, s));\r\n    d[s]\
    \ = 0;\r\n    while (!que.empty()) {\r\n        auto [ret, v] = que.top();\r\n\
    \        que.pop();\r\n        if (d[v] < ret) continue;\r\n        for (auto\
    \ e : g[v]) {\r\n            if (d[e.to] > d[v] + e.cost) {\r\n              \
    \  d[e.to] = d[v] + e.cost;\r\n                que.push(P(d[e.to], e.to));\r\n\
    \            }\r\n        }\r\n    }\r\n    return d;\r\n}\r\n\r\ntemplate <class\
    \ T> struct dijkstra_path {\r\n  public:\r\n    dijkstra_path(int s_, const Graph<T>\
    \ &g)\r\n        : s(s_),\r\n          dist(g.size(), std::numeric_limits<T>::max()),\r\
    \n          prev(g.size(), -1) {\r\n        dist[s] = 0;\r\n        using P =\
    \ std::pair<T, int>;\r\n        std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ que;\r\n        que.push(P(0, s));\r\n        while (!que.empty()) {\r\n   \
    \         auto [ret, v] = que.top();\r\n            que.pop();\r\n           \
    \ if (dist[v] < ret) continue;\r\n            for (auto e : g[v]) {\r\n      \
    \          if (dist[e.to] > dist[v] + e.cost) {\r\n                    dist[e.to]\
    \ = dist[v] + e.cost;\r\n                    prev[e.to] = v;\r\n             \
    \       que.push(P(dist[e.to], e.to));\r\n                }\r\n            }\r\
    \n        }\r\n    }\r\n\r\n    std::pair<T, std::vector<int>> shortest_path(int\
    \ v) const {\r\n        if (dist[v] == std::numeric_limits<T>::max()) return {dist[v],\
    \ {}};\r\n        std::vector<int> path;\r\n        int u = v;\r\n        while\
    \ (u != s) {\r\n            path.emplace_back(u);\r\n            u = prev[u];\r\
    \n        }\r\n        path.emplace_back(u);\r\n        std::reverse(path.begin(),\
    \ path.end());\r\n        return {dist[v], path};\r\n    }\r\n\r\n  private:\r\
    \n    int s;\r\n    std::vector<T> dist;\r\n    std::vector<int> prev;\r\n};\r\
    \n\r\n}  // namespace ebi"
  dependsOn:
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2025-03-18 01:14:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/dijkstra.test.cpp
  - test/graph/Shortest_Path.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
title: dijkstra
---

## 説明

辺重みが非負のグラフについて、単一始点最短路を求める。 $O((N+M)\log{M})$