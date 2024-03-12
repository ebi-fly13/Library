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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/complement_graph_bfs.hpp\"\n\n#include <numeric>\n\
    #include <queue>\n#include <vector>\n\n#line 2 \"graph/base.hpp\"\n\n#include\
    \ <cassert>\n#include <iostream>\n#include <ranges>\n#line 7 \"graph/base.hpp\"\
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
    \ id;\n};\n\ntemplate <class E> struct Graph {\n  private:\n    using cost_type\
    \ = E;\n    using edge_type = Edge<cost_type>;\n\n  public:\n    Graph(int n_)\
    \ : n(n_) {}\n\n    Graph() = default;\n\n    void add_edge(int u, int v, cost_type\
    \ c) {\n        edges.emplace_back(u, edge_type{u, v, c, m++});\n    }\n\n   \
    \ void add_undirected_edge(int u, int v, cost_type c) {\n        edges.emplace_back(u,\
    \ edge_type{u, v, c, m});\n        edges.emplace_back(v, edge_type{v, u, c, m});\n\
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
    \ edges);\n        edges.clear();\n        prepared = true;\n    }\n\n    int\
    \ size() const {\n        return n;\n    }\n\n    const auto operator[](int i)\
    \ const {\n        return csr[i];\n    }\n    auto operator[](int i) {\n     \
    \   return csr[i];\n    }\n\n  private:\n    int n, m = 0;\n\n    std::vector<std::pair<int,\
    \ edge_type>> edges;\n    simple_csr<edge_type> csr;\n    bool prepared = false;\n\
    };\n\n}  // namespace ebi\n#line 8 \"graph/complement_graph_bfs.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <class T, class F>\nvoid complement_graph_bfs(int s, const\
    \ Graph<T> &h, const F &func) {\n    const int n = h.size();\n    std::vector<int>\
    \ not_visit;\n    not_visit.reserve(n - 1);\n    for (int i = 0; i < n; i++)\n\
    \        if (i != s) not_visit.emplace_back(i);\n    std::vector<bool> f(n, false);\n\
    \    std::queue<int> que;\n    que.push(s);\n    while (!que.empty()) {\n    \
    \    int v = que.front();\n        que.pop();\n        for (auto e : h[v]) {\n\
    \            f[e.to] = true;\n        }\n        std::vector<int> L;\n       \
    \ for (auto u : not_visit) {\n            if (f[u])\n                L.emplace_back(u);\n\
    \            else {\n                que.push(u);\n                func(v, u);\n\
    \            }\n        }\n        for (auto e : h[v]) {\n            f[e.to]\
    \ = false;\n        }\n        std::swap(not_visit, L);\n    }\n    return;\n\
    }\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <numeric>\n#include <queue>\n#include <vector>\n\
    \n#include \"../graph/base.hpp\"\n\nnamespace ebi {\n\ntemplate <class T, class\
    \ F>\nvoid complement_graph_bfs(int s, const Graph<T> &h, const F &func) {\n \
    \   const int n = h.size();\n    std::vector<int> not_visit;\n    not_visit.reserve(n\
    \ - 1);\n    for (int i = 0; i < n; i++)\n        if (i != s) not_visit.emplace_back(i);\n\
    \    std::vector<bool> f(n, false);\n    std::queue<int> que;\n    que.push(s);\n\
    \    while (!que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \        for (auto e : h[v]) {\n            f[e.to] = true;\n        }\n     \
    \   std::vector<int> L;\n        for (auto u : not_visit) {\n            if (f[u])\n\
    \                L.emplace_back(u);\n            else {\n                que.push(u);\n\
    \                func(v, u);\n            }\n        }\n        for (auto e :\
    \ h[v]) {\n            f[e.to] = false;\n        }\n        std::swap(not_visit,\
    \ L);\n    }\n    return;\n}\n\n}  // namespace ebi"
  dependsOn:
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: false
  path: graph/complement_graph_bfs.hpp
  requiredBy: []
  timestamp: '2024-03-13 01:44:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/complement_graph_bfs.hpp
layout: document
title: Complement Graph BFS
---

## 説明

頂点 $s$ から始めて、 $h$ の補グラフをBFSする。頂点数を $N$ 、辺の本数を $M$ 、`func`の計算量を $F$ として計算量は $O(NF + M)$ である。

インターフェースは以下である。ここで、 `func(v, u)` はBFSの際に頂点 $v$ から $u$ に遷移するときに呼ばれる関数である。

```
void complement_graph_bfs(int s, std::vector<std::vector<int>> h, F func)
```
