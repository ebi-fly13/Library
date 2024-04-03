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
    path: test/tree/Jump_on_Tree.test.cpp
    title: test/tree/Jump_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/level_ancestor_lca.test.cpp
    title: test/tree/level_ancestor_lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/level_ancestor.hpp\"\n\r\n#include <algorithm>\r\n\
    #include <cassert>\r\n#include <vector>\r\n\r\n#line 2 \"graph/base.hpp\"\n\n\
    #line 4 \"graph/base.hpp\"\n#include <iostream>\n#include <ranges>\n#line 7 \"\
    graph/base.hpp\"\n\n#line 2 \"data_structure/simple_csr.hpp\"\n\n#line 4 \"data_structure/simple_csr.hpp\"\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 8 \"tree/level_ancestor.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class T> struct level_ancestor {\r\n  private:\r\
    \n    int n;\r\n    std::vector<int> in;\r\n    std::vector<int> inv_in;\r\n \
    \   std::vector<int> depths;\r\n    std::vector<std::vector<int>> s;\r\n\r\n \
    \ public:\r\n    level_ancestor(const Graph<T> &gh, int root = 0)\r\n        :\
    \ n(gh.size()), in(n), inv_in(n), depths(n) {\r\n        int cnt = 0;\r\n    \
    \    int max = 0;\r\n        auto dfs = [&](auto &&self, int v, int par = -1)\
    \ -> void {\r\n            inv_in[cnt] = v;\r\n            in[v] = cnt++;\r\n\
    \            max = std::max(max, depths[v]);\r\n            for (auto e : gh[v])\r\
    \n                if (e.to != par) {\r\n                    depths[e.to] = depths[v]\
    \ + 1;\r\n                    self(self, e.to, v);\r\n                }\r\n  \
    \      };\r\n        dfs(dfs, root);\r\n        s.resize(max + 1);\r\n       \
    \ for (int i = 0; i < n; i++) {\r\n            int u = inv_in[i];\r\n        \
    \    s[depths[u]].emplace_back(i);\r\n        }\r\n    }\r\n\r\n    int query(int\
    \ u, int k) const {\r\n        int m = depths[u] - k;\r\n        assert(m >= 0);\r\
    \n        return inv_in[*std::prev(\r\n            std::upper_bound(s[m].begin(),\
    \ s[m].end(), in[u]))];\r\n    }\r\n\r\n    int depth(int u) const {\r\n     \
    \   return depths[u];\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <algorithm>\r\n#include <cassert>\r\n#include\
    \ <vector>\r\n\r\n#include \"../graph/base.hpp\"\r\n\r\nnamespace ebi {\r\n\r\n\
    template <class T> struct level_ancestor {\r\n  private:\r\n    int n;\r\n   \
    \ std::vector<int> in;\r\n    std::vector<int> inv_in;\r\n    std::vector<int>\
    \ depths;\r\n    std::vector<std::vector<int>> s;\r\n\r\n  public:\r\n    level_ancestor(const\
    \ Graph<T> &gh, int root = 0)\r\n        : n(gh.size()), in(n), inv_in(n), depths(n)\
    \ {\r\n        int cnt = 0;\r\n        int max = 0;\r\n        auto dfs = [&](auto\
    \ &&self, int v, int par = -1) -> void {\r\n            inv_in[cnt] = v;\r\n \
    \           in[v] = cnt++;\r\n            max = std::max(max, depths[v]);\r\n\
    \            for (auto e : gh[v])\r\n                if (e.to != par) {\r\n  \
    \                  depths[e.to] = depths[v] + 1;\r\n                    self(self,\
    \ e.to, v);\r\n                }\r\n        };\r\n        dfs(dfs, root);\r\n\
    \        s.resize(max + 1);\r\n        for (int i = 0; i < n; i++) {\r\n     \
    \       int u = inv_in[i];\r\n            s[depths[u]].emplace_back(i);\r\n  \
    \      }\r\n    }\r\n\r\n    int query(int u, int k) const {\r\n        int m\
    \ = depths[u] - k;\r\n        assert(m >= 0);\r\n        return inv_in[*std::prev(\r\
    \n            std::upper_bound(s[m].begin(), s[m].end(), in[u]))];\r\n    }\r\n\
    \r\n    int depth(int u) const {\r\n        return depths[u];\r\n    }\r\n};\r\
    \n\r\n}  // namespace ebi"
  dependsOn:
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: false
  path: tree/level_ancestor.hpp
  requiredBy: []
  timestamp: '2024-03-13 15:52:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Jump_on_Tree.test.cpp
  - test/tree/level_ancestor_lca.test.cpp
documentation_of: tree/level_ancestor.hpp
layout: document
title: Level Ancestor
---

## 説明

根付き木のLevel Ancestorを構築 $O(N)$ / クエリ $O(\log N)$

### query(u, k)

頂点`u`の根方向に $k$ だけ上った頂点を返す。 $O(\log N)$