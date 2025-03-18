---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: Graph (CSR format)
  - icon: ':heavy_check_mark:'
    path: graph/biconnected_components.hpp
    title: graph/biconnected_components.hpp
  - icon: ':heavy_check_mark:'
    path: graph/low_link.hpp
    title: Low Link
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Biconnected_Components.test.cpp
    title: test/graph/Biconnected_Components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/block_cut_tree.hpp\"\n\n#include <cassert>\n\n#line\
    \ 2 \"graph/biconnected_components.hpp\"\n\n#line 2 \"graph/low_link.hpp\"\n\n\
    #include <algorithm>\n#include <utility>\n#include <vector>\n\n#line 2 \"graph/base.hpp\"\
    \n\n#line 4 \"graph/base.hpp\"\n#include <iostream>\n#include <ranges>\n#line\
    \ 7 \"graph/base.hpp\"\n\n#line 2 \"data_structure/simple_csr.hpp\"\n\n#line 6\
    \ \"data_structure/simple_csr.hpp\"\n\nnamespace ebi {\n\ntemplate <class E> struct\
    \ simple_csr {\n    simple_csr() = default;\n\n    simple_csr(int n, const std::vector<std::pair<int,\
    \ E>>& elements)\n        : start(n + 1, 0), elist(elements.size()) {\n      \
    \  for (auto e : elements) {\n            start[e.first + 1]++;\n        }\n \
    \       for (auto i : std::views::iota(0, n)) {\n            start[i + 1] += start[i];\n\
    \        }\n        auto counter = start;\n        for (auto [i, e] : elements)\
    \ {\n            elist[counter[i]++] = e;\n        }\n    }\n\n    simple_csr(const\
    \ std::vector<std::vector<E>>& es)\n        : start(es.size() + 1, 0) {\n    \
    \    int n = es.size();\n        for (auto i : std::views::iota(0, n)) {\n   \
    \         start[i + 1] = (int)es[i].size() + start[i];\n        }\n        elist.resize(start.back());\n\
    \        for (auto i : std::views::iota(0, n)) {\n            std::copy(es[i].begin(),\
    \ es[i].end(), elist.begin() + start[i]);\n        }\n    }\n\n    int size()\
    \ const {\n        return (int)start.size() - 1;\n    }\n\n    const auto operator[](int\
    \ i) const {\n        return std::ranges::subrange(elist.begin() + start[i],\n\
    \                                     elist.begin() + start[i + 1]);\n    }\n\
    \    auto operator[](int i) {\n        return std::ranges::subrange(elist.begin()\
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
    \ assert(prepared);\n        return edges;\n    }\n\n    const auto operator[](int\
    \ i) const {\n        assert(prepared);\n        return csr[i];\n    }\n    auto\
    \ operator[](int i) {\n        assert(prepared);\n        return csr[i];\n   \
    \ }\n\n  private:\n    int n, m = 0;\n\n    std::vector<std::pair<int, edge_type>>\
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
    \ std::vector<std::pair<int, int>> _bridge;\n};\n\n}  // namespace ebi\n#line\
    \ 4 \"graph/biconnected_components.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ T> struct biconnected_components : low_link<T> {\n  private:\n    void dfs(int\
    \ v, int par = -1) {\n        used[v] = true;\n        for (auto e : this->g[v])\
    \ {\n            int nv = e.to;\n            if (nv == par) continue;\n      \
    \      if (!used[nv] || this->ord[nv] < this->ord[v]) {\n                tmp.emplace_back(std::minmax(v,\
    \ nv));\n            }\n            if (!used[nv]) {\n                dfs(nv,\
    \ v);\n                if (this->low[nv] >= this->ord[v]) {\n                \
    \    bc.emplace_back();\n                    while (true) {\n                \
    \        auto e = tmp.back();\n                        bc.back().emplace_back(e);\n\
    \                        tmp.pop_back();\n                        if (e.first\
    \ == std::min(v, nv) &&\n                            e.second == std::max(v, nv))\
    \ {\n                            break;\n                        }\n         \
    \           }\n                }\n            }\n        }\n    }\n\n  public:\n\
    \    biconnected_components(const Graph<T> &g)\n        : low_link<T>(g), used(this->n,\
    \ false) {\n        for (int i = 0; i < this->n; i++) {\n            if (!used[i])\
    \ dfs(i);\n        }\n    }\n\n  protected:\n    std::vector<bool> used;\n   \
    \ std::vector<std::vector<std::pair<int, int>>> bc;\n    std::vector<std::pair<int,\
    \ int>> tmp;\n};\n\n}  // namespace ebi\n#line 6 \"tree/block_cut_tree.hpp\"\n\
    \nnamespace ebi {\n\ntemplate <class T> struct block_cut_tree : biconnected_components<T>\
    \ {\n  public:\n    block_cut_tree(const Graph<T> &g)\n        : biconnected_components<T>(g),\
    \ rev(this->n, -1) {\n        int cnt = 0;\n        for (auto v : this->_articulation)\
    \ {\n            rev[v] = cnt++;\n        }\n        int sz = cnt + this->bc.size();\n\
    \        tree.resize(sz);\n        std::vector<int> last(this->n, -1);\n     \
    \   for (int i = cnt; i < sz; i++) {\n            for (auto e : this->bc[i - cnt])\
    \ {\n                for (auto v : {e.first, e.second}) {\n                  \
    \  if (rev[v] != -1 && rev[v] < cnt) {\n                        if (std::exchange(last[v],\
    \ i) != i) {\n                            tree[i].emplace_back(rev[v]);\n    \
    \                        tree[rev[v]].emplace_back(i);\n                     \
    \   }\n                    } else {\n                        rev[v] = i;\n   \
    \                 }\n                }\n            }\n        }\n        groups.resize(sz);\n\
    \        for (int i = 0; i < this->n; i++) {\n            if (rev[i] < 0) {\n\
    \                rev[i] = sz++;\n                groups.emplace_back();\n    \
    \            tree.emplace_back();\n            }\n            groups[rev[i]].emplace_back(i);\n\
    \        }\n    }\n\n    std::vector<std::vector<int>> bcc() {\n        int cnt\
    \ = this->_articulation.size();\n        int sz = groups.size() - cnt;\n     \
    \   std::vector _bcc(sz, std::vector<int>());\n        for (int i = 0; i < sz;\
    \ i++) {\n            _bcc[i] = groups[cnt + i];\n            for (auto nv : tree[cnt\
    \ + i]) {\n                assert(0 <= nv && nv < cnt);\n                assert(groups[nv].size()\
    \ == 1);\n                _bcc[i].emplace_back(groups[nv][0]);\n            }\n\
    \        }\n        return _bcc;\n    }\n\n  private:\n    std::vector<int> rev;\n\
    \    std::vector<std::vector<int>> tree;\n    std::vector<std::vector<int>> groups;\n\
    };\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n\n#include \"../graph/biconnected_components.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> struct block_cut_tree : biconnected_components<T>\
    \ {\n  public:\n    block_cut_tree(const Graph<T> &g)\n        : biconnected_components<T>(g),\
    \ rev(this->n, -1) {\n        int cnt = 0;\n        for (auto v : this->_articulation)\
    \ {\n            rev[v] = cnt++;\n        }\n        int sz = cnt + this->bc.size();\n\
    \        tree.resize(sz);\n        std::vector<int> last(this->n, -1);\n     \
    \   for (int i = cnt; i < sz; i++) {\n            for (auto e : this->bc[i - cnt])\
    \ {\n                for (auto v : {e.first, e.second}) {\n                  \
    \  if (rev[v] != -1 && rev[v] < cnt) {\n                        if (std::exchange(last[v],\
    \ i) != i) {\n                            tree[i].emplace_back(rev[v]);\n    \
    \                        tree[rev[v]].emplace_back(i);\n                     \
    \   }\n                    } else {\n                        rev[v] = i;\n   \
    \                 }\n                }\n            }\n        }\n        groups.resize(sz);\n\
    \        for (int i = 0; i < this->n; i++) {\n            if (rev[i] < 0) {\n\
    \                rev[i] = sz++;\n                groups.emplace_back();\n    \
    \            tree.emplace_back();\n            }\n            groups[rev[i]].emplace_back(i);\n\
    \        }\n    }\n\n    std::vector<std::vector<int>> bcc() {\n        int cnt\
    \ = this->_articulation.size();\n        int sz = groups.size() - cnt;\n     \
    \   std::vector _bcc(sz, std::vector<int>());\n        for (int i = 0; i < sz;\
    \ i++) {\n            _bcc[i] = groups[cnt + i];\n            for (auto nv : tree[cnt\
    \ + i]) {\n                assert(0 <= nv && nv < cnt);\n                assert(groups[nv].size()\
    \ == 1);\n                _bcc[i].emplace_back(groups[nv][0]);\n            }\n\
    \        }\n        return _bcc;\n    }\n\n  private:\n    std::vector<int> rev;\n\
    \    std::vector<std::vector<int>> tree;\n    std::vector<std::vector<int>> groups;\n\
    };\n\n}  // namespace ebi"
  dependsOn:
  - graph/biconnected_components.hpp
  - graph/low_link.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: false
  path: tree/block_cut_tree.hpp
  requiredBy: []
  timestamp: '2025-03-18 03:40:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Biconnected_Components.test.cpp
documentation_of: tree/block_cut_tree.hpp
layout: document
title: Block Cut Tree
---

## 説明

二重連結成分分解をし、二重連結成分と関節点を結ぶ木（非連結グラフなら森）を作る。 $O(N + M)$
頂点番号の割り当ては、関節点は何個目の関節点か、二重連結成分は関節点の個数 + 何個目の二重連結成分かになっている。