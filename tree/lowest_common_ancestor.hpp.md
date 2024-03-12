---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: Sparse Table
  - icon: ':question:'
    path: graph/base.hpp
    title: Graph (CSR format)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/Jump_on_Tree.test.cpp
    title: test/tree/Jump_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/lowest_common_ancestor.test.cpp
    title: test/tree/lowest_common_ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/lowest_common_ancestor.hpp\"\n\r\n#include <vector>\r\
    \n\r\n#line 2 \"data_structure/sparse_table.hpp\"\n\r\n#line 4 \"data_structure/sparse_table.hpp\"\
    \n\r\n/*\r\n    reference: https://scrapbox.io/data-structures/Sparse_Table\r\n\
    */\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class Band, Band (*op)(Band, Band)>\
    \ struct sparse_table {\r\n  public:\r\n    sparse_table() = default;\r\n\r\n\
    \    sparse_table(const std::vector<Band> &a) : n(a.size()) {\r\n        table\
    \ = std::vector(std::__lg(n) + 1, std::vector<Band>(n));\r\n        for (int i\
    \ = 0; i < n; i++) {\r\n            table[0][i] = a[i];\r\n        }\r\n     \
    \   for (int k = 1; (1 << k) <= n; k++) {\r\n            for (int i = 0; i + (1\
    \ << k) <= n; i++) {\r\n                table[k][i] =\r\n                    op(table[k\
    \ - 1][i], table[k - 1][i + (1 << (k - 1))]);\r\n            }\r\n        }\r\n\
    \    }\r\n\r\n    void build(const std::vector<Band> &a) {\r\n        n = (int)a.size();\r\
    \n        table = std::vector(std::__lg(n) + 1, std::vector<Band>(n));\r\n   \
    \     for (int i = 0; i < n; i++) {\r\n            table[0][i] = a[i];\r\n   \
    \     }\r\n        for (int k = 1; (1 << k) <= n; k++) {\r\n            for (int\
    \ i = 0; i + (1 << k) <= n; i++) {\r\n                table[k][i] =\r\n      \
    \              op(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);\r\n    \
    \        }\r\n        }\r\n    }\r\n\r\n    // [l, r)\r\n    Band fold(int l,\
    \ int r) {\r\n        int k = std::__lg(r - l);\r\n        return op(table[k][l],\
    \ table[k][r - (1 << k)]);\r\n    }\r\n\r\n  private:\r\n    int n;\r\n    std::vector<std::vector<Band>>\
    \ table;\r\n};\r\n\r\n}  // namespace ebi\n#line 2 \"graph/base.hpp\"\n\n#include\
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
    \ {\n\ntemplate <class T> struct Edge {\n    int to;\n    T cost;\n    int id;\n\
    };\n\ntemplate <class E> struct Graph {\n  private:\n    using cost_type = E;\n\
    \    using edge_type = Edge<cost_type>;\n\n  public:\n    Graph(int n_) : n(n_)\
    \ {}\n\n    Graph() = default;\n\n    void add_edge(int u, int v, cost_type c)\
    \ {\n        edges.emplace_back(u, edge_type{v, c, m++});\n    }\n\n    void read_tree(int\
    \ offset = 1, bool is_weighted = false) {\n        read_graph(n - 1, offset, false,\
    \ is_weighted);\n    }\n\n    void read_parents(int offset = 1) {\n        for\
    \ (auto i : std::views::iota(1, n)) {\n            int p;\n            std::cin\
    \ >> p;\n            p -= offset;\n            add_edge(p, i, 1);\n          \
    \  add_edge(i, p, 1);\n        }\n        build();\n    }\n\n    void read_graph(int\
    \ e, int offset = 1, bool is_directed = false,\n                    bool is_weighted\
    \ = false) {\n        for (int i = 0; i < e; i++) {\n            int u, v;\n \
    \           std::cin >> u >> v;\n            u -= offset;\n            v -= offset;\n\
    \            if (is_weighted) {\n                cost_type c;\n              \
    \  std::cin >> c;\n                add_edge(u, v, c);\n                if (!is_directed)\
    \ {\n                    add_edge(v, u, c);\n                }\n            }\
    \ else {\n                add_edge(u, v, 1);\n                if (!is_directed)\
    \ {\n                    add_edge(v, u, 1);\n                }\n            }\n\
    \        }\n        build();\n    }\n\n    void build() {\n        assert(!prepared);\n\
    \        csr = simple_csr<edge_type>(n, edges);\n        edges.clear();\n    \
    \    prepared = true;\n    }\n\n    int size() const {\n        return n;\n  \
    \  }\n\n    const auto operator[](int i) const {\n        return csr[i];\n   \
    \ }\n    auto operator[](int i) {\n        return csr[i];\n    }\n\n  private:\n\
    \    int n, m = 0;\n\n    std::vector<std::pair<int, edge_type>> edges;\n    simple_csr<edge_type>\
    \ csr;\n    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 7 \"tree/lowest_common_ancestor.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\nnamespace internal_lca {\r\nstd::pair<int, int> op(std::pair<int,\
    \ int> a, std::pair<int, int> b) {\r\n    return a.second < b.second ? a : b;\r\
    \n}\r\n}  // namespace internal_lca\r\n\r\ntemplate <class T> struct lowest_common_ancestor\
    \ {\r\n  public:\r\n    lowest_common_ancestor(const Graph<T> &gh, int root =\
    \ 0)\r\n        : n(gh.size()), id(n), dist(n, 0) {\r\n        auto dfs = [&](auto\
    \ &&self, int v, int par = -1, T d = 0) -> void {\r\n            id[v] = int(vs.size());\r\
    \n            vs.emplace_back(v, d);\r\n            for (const auto &e : gh[v])\r\
    \n                if (e.to != par) {\r\n                    dist[e.to] = dist[v]\
    \ + e.cost;\r\n                    self(self, e.to, v, d + 1);\r\n           \
    \         vs.emplace_back(v, d);\r\n                }\r\n        };\r\n      \
    \  dfs(dfs, root);\r\n        st.build(vs);\r\n    }\r\n\r\n    int lca(int u,\
    \ int v) {\r\n        int l = id[u], r = id[v];\r\n        if (r < l) std::swap(l,\
    \ r);\r\n        return st.fold(l, r + 1).first;\r\n    }\r\n\r\n    T distance(int\
    \ u, int v) {\r\n        int w = lca(u, v);\r\n        return dist[u] + dist[v]\
    \ - 2 * dist[w];\r\n    }\r\n\r\n  private:\r\n    int n;\r\n    std::vector<int>\
    \ id;\r\n    std::vector<T> dist;\r\n    std::vector<std::pair<int, int>> vs;\r\
    \n    sparse_table<std::pair<int, int>, internal_lca::op> st;\r\n};\r\n\r\n} \
    \ // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\n#include \"../data_structure/sparse_table.hpp\"\
    \r\n#include \"../graph/base.hpp\"\r\n\r\nnamespace ebi {\r\n\r\nnamespace internal_lca\
    \ {\r\nstd::pair<int, int> op(std::pair<int, int> a, std::pair<int, int> b) {\r\
    \n    return a.second < b.second ? a : b;\r\n}\r\n}  // namespace internal_lca\r\
    \n\r\ntemplate <class T> struct lowest_common_ancestor {\r\n  public:\r\n    lowest_common_ancestor(const\
    \ Graph<T> &gh, int root = 0)\r\n        : n(gh.size()), id(n), dist(n, 0) {\r\
    \n        auto dfs = [&](auto &&self, int v, int par = -1, T d = 0) -> void {\r\
    \n            id[v] = int(vs.size());\r\n            vs.emplace_back(v, d);\r\n\
    \            for (const auto &e : gh[v])\r\n                if (e.to != par) {\r\
    \n                    dist[e.to] = dist[v] + e.cost;\r\n                    self(self,\
    \ e.to, v, d + 1);\r\n                    vs.emplace_back(v, d);\r\n         \
    \       }\r\n        };\r\n        dfs(dfs, root);\r\n        st.build(vs);\r\n\
    \    }\r\n\r\n    int lca(int u, int v) {\r\n        int l = id[u], r = id[v];\r\
    \n        if (r < l) std::swap(l, r);\r\n        return st.fold(l, r + 1).first;\r\
    \n    }\r\n\r\n    T distance(int u, int v) {\r\n        int w = lca(u, v);\r\n\
    \        return dist[u] + dist[v] - 2 * dist[w];\r\n    }\r\n\r\n  private:\r\n\
    \    int n;\r\n    std::vector<int> id;\r\n    std::vector<T> dist;\r\n    std::vector<std::pair<int,\
    \ int>> vs;\r\n    sparse_table<std::pair<int, int>, internal_lca::op> st;\r\n\
    };\r\n\r\n}  // namespace ebi"
  dependsOn:
  - data_structure/sparse_table.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: false
  path: tree/lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2024-03-12 17:35:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/lowest_common_ancestor.test.cpp
  - test/tree/Jump_on_Tree.test.cpp
documentation_of: tree/lowest_common_ancestor.hpp
layout: document
title: Lowest Common Ancestor
---

## 説明

根付き木の最小共通祖先を、構築 $O(N\log N)$ / クエリ $O(1)$ で求める。

### lca(u, v)

`u`と`v`の最小共通祖先を返す。 $O(1)$

### distance(u, v)

`u`と`v`の距離を返す。