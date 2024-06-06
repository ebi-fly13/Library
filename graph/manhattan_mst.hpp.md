---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/dsu.hpp
    title: DSU
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: "\u4FBF\u5229\u95A2\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Manhattan_MST.test.cpp
    title: test/graph/Manhattan_MST.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/manhattan_mst.hpp\"\n\n#include <algorithm>\n#include\
    \ <map>\n#include <numeric>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
    \n#line 2 \"data_structure/dsu.hpp\"\n\r\n#line 4 \"data_structure/dsu.hpp\"\n\
    \r\nnamespace ebi {\r\n\r\nstruct dsu {\r\n  private:\r\n    std::vector<int>\
    \ par;\r\n\r\n  public:\r\n    dsu(int n = 0) : par(n, -1) {}\r\n\r\n    bool\
    \ same(int x, int y) {\r\n        return leader(x) == leader(y);\r\n    }\r\n\r\
    \n    bool merge(int x, int y) {\r\n        x = leader(x);\r\n        y = leader(y);\r\
    \n        if (x == y) return false;\r\n        if (par[x] > par[y]) std::swap(x,\
    \ y);\r\n        par[x] += par[y];\r\n        par[y] = x;\r\n        return true;\r\
    \n    }\r\n\r\n    int leader(int x) {\r\n        if (par[x] < 0)\r\n        \
    \    return x;\r\n        else\r\n            return par[x] = leader(par[x]);\r\
    \n    }\r\n\r\n    int size(int x) {\r\n        return -par[leader(x)];\r\n  \
    \  }\r\n\r\n    int count_group() {\r\n        int c = 0;\r\n        for (int\
    \ i = 0; i < int(par.size()); i++) {\r\n            if (par[i] < 0) c++;\r\n \
    \       }\r\n        return c;\r\n    }\r\n\r\n    std::vector<std::vector<int>>\
    \ groups() {\r\n        int n = par.size();\r\n        std::vector result(n, std::vector<int>());\r\
    \n        for (int i = 0; i < n; i++) {\r\n            result[leader(i)].emplace_back(i);\r\
    \n        }\r\n        result.erase(std::remove_if(result.begin(), result.end(),\r\
    \n                                    [](const std::vector<int> &v) -> bool {\r\
    \n                                        return v.empty();\r\n              \
    \                      }),\r\n                     result.end());\r\n        return\
    \ result;\r\n    }\r\n\r\n    void clear() {\r\n        for (int i = 0; i < int(par.size());\
    \ i++) {\r\n            par[i] = -1;\r\n        }\r\n    }\r\n};\r\n\r\n}  //\
    \ namespace ebi\n#line 2 \"graph/base.hpp\"\n\n#include <cassert>\n#include <iostream>\n\
    #include <ranges>\n#line 7 \"graph/base.hpp\"\n\n#line 2 \"data_structure/simple_csr.hpp\"\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 12 \"graph/manhattan_mst.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T>\nstd::pair<T, std::vector<std::pair<int,\
    \ int>>> manhattan_mst(\n    std::vector<T> &xs, std::vector<T> &ys) {\n    const\
    \ int n = xs.size();\n    std::vector<int> ids(n);\n    std::iota(ids.begin(),\
    \ ids.end(), 0);\n    std::vector<std::tuple<T, int, int>> edges;\n    for (int\
    \ s = 0; s < 2; s++) {\n        for (int t = 0; t < 2; t++) {\n            std::sort(ids.begin(),\
    \ ids.end(), [&](int i, int j) -> bool {\n                return xs[i] + ys[i]\
    \ < xs[j] + ys[j];\n            });\n            std::map<T, int> sweep;\n   \
    \         for (int i : ids) {\n                for (auto itr = sweep.lower_bound(-ys[i]);\
    \ itr != sweep.end();\n                     itr = sweep.erase(itr)) {\n      \
    \              int j = itr->second;\n                    if (xs[i] - xs[j] < ys[i]\
    \ - ys[j]) break;\n                    edges.emplace_back(\n                 \
    \       std::abs(ys[i] - ys[j]) + std::abs(xs[i] - xs[j]), i,\n              \
    \          j);\n                }\n                sweep[-ys[i]] = i;\n      \
    \      }\n            std::swap(xs, ys);\n        }\n        for (auto &x : xs)\
    \ x = -x;\n    }\n    std::sort(edges.begin(), edges.end(), [&](auto a, auto b)\
    \ -> bool {\n        return std::get<0>(a) < std::get<0>(b);\n    });\n    dsu\
    \ uf(n);\n    std::vector<std::pair<int, int>> es;\n    T sum = 0;\n    for (auto\
    \ [cost, i, j] : edges) {\n        if (uf.same(i, j)) continue;\n        uf.merge(i,\
    \ j);\n        sum += cost;\n        es.emplace_back(i, j);\n    }\n    return\
    \ {sum, es};\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <map>\n#include <numeric>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n\n#include \"../data_structure/dsu.hpp\"\
    \n#include \"../graph/base.hpp\"\n\nnamespace ebi {\n\ntemplate <class T>\nstd::pair<T,\
    \ std::vector<std::pair<int, int>>> manhattan_mst(\n    std::vector<T> &xs, std::vector<T>\
    \ &ys) {\n    const int n = xs.size();\n    std::vector<int> ids(n);\n    std::iota(ids.begin(),\
    \ ids.end(), 0);\n    std::vector<std::tuple<T, int, int>> edges;\n    for (int\
    \ s = 0; s < 2; s++) {\n        for (int t = 0; t < 2; t++) {\n            std::sort(ids.begin(),\
    \ ids.end(), [&](int i, int j) -> bool {\n                return xs[i] + ys[i]\
    \ < xs[j] + ys[j];\n            });\n            std::map<T, int> sweep;\n   \
    \         for (int i : ids) {\n                for (auto itr = sweep.lower_bound(-ys[i]);\
    \ itr != sweep.end();\n                     itr = sweep.erase(itr)) {\n      \
    \              int j = itr->second;\n                    if (xs[i] - xs[j] < ys[i]\
    \ - ys[j]) break;\n                    edges.emplace_back(\n                 \
    \       std::abs(ys[i] - ys[j]) + std::abs(xs[i] - xs[j]), i,\n              \
    \          j);\n                }\n                sweep[-ys[i]] = i;\n      \
    \      }\n            std::swap(xs, ys);\n        }\n        for (auto &x : xs)\
    \ x = -x;\n    }\n    std::sort(edges.begin(), edges.end(), [&](auto a, auto b)\
    \ -> bool {\n        return std::get<0>(a) < std::get<0>(b);\n    });\n    dsu\
    \ uf(n);\n    std::vector<std::pair<int, int>> es;\n    T sum = 0;\n    for (auto\
    \ [cost, i, j] : edges) {\n        if (uf.same(i, j)) continue;\n        uf.merge(i,\
    \ j);\n        sum += cost;\n        es.emplace_back(i, j);\n    }\n    return\
    \ {sum, es};\n}\n\n}  // namespace ebi"
  dependsOn:
  - data_structure/dsu.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: false
  path: graph/manhattan_mst.hpp
  requiredBy: []
  timestamp: '2024-04-24 16:34:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Manhattan_MST.test.cpp
documentation_of: graph/manhattan_mst.hpp
layout: document
title: Manhattan MST
---

## 説明

 $2$ 次元座標上の $N$ 点を与えて、マンハッタン距離におけるMSTを構築する。返り値 $(x, es)$ について、 $x$ は木の重みの総和、 $es$ には使用した辺 $(u_i, v_i)$ が格納されている。