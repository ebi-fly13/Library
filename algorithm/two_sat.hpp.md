---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':question:'
    path: graph/base.hpp
    title: Graph (CSR format)
  - icon: ':heavy_check_mark:'
    path: graph/scc_graph.hpp
    title: graph/scc_graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/algorithm/Two_Sat.test.cpp
    title: test/algorithm/Two_Sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/two_sat.hpp\"\n\n#include <cassert>\n\n#line 2\
    \ \"graph/scc_graph.hpp\"\n\r\n#include <algorithm>\r\n#include <vector>\r\n\r\
    \n#line 2 \"data_structure/simple_csr.hpp\"\n\n#include <ranges>\n#include <utility>\n\
    #line 6 \"data_structure/simple_csr.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
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
    \ elist;\n};\n\n}  // namespace ebi\n#line 2 \"graph/base.hpp\"\n\n#line 4 \"\
    graph/base.hpp\"\n#include <iostream>\n#line 7 \"graph/base.hpp\"\n\n#line 9 \"\
    graph/base.hpp\"\n\nnamespace ebi {\n\ntemplate <class T> struct Edge {\n    int\
    \ from, to;\n    T cost;\n    int id;\n};\n\ntemplate <class E> struct Graph {\n\
    \  private:\n    using cost_type = E;\n    using edge_type = Edge<cost_type>;\n\
    \n  public:\n    Graph(int n_) : n(n_) {}\n\n    Graph() = default;\n\n    void\
    \ add_edge(int u, int v, cost_type c) {\n        edges.emplace_back(u, edge_type{u,\
    \ v, c, m++});\n    }\n\n    void add_undirected_edge(int u, int v, cost_type\
    \ c) {\n        edges.emplace_back(u, edge_type{u, v, c, m});\n        edges.emplace_back(v,\
    \ edge_type{v, u, c, m});\n        m++;\n    }\n\n    void read_tree(int offset\
    \ = 1, bool is_weighted = false) {\n        read_graph(n - 1, offset, false, is_weighted);\n\
    \    }\n\n    void read_parents(int offset = 1) {\n        for (auto i : std::views::iota(1,\
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
    };\n\n}  // namespace ebi\n#line 8 \"graph/scc_graph.hpp\"\n\r\nnamespace ebi\
    \ {\r\n\r\nstruct scc_graph {\r\n  private:\r\n    std::vector<std::pair<int,\
    \ int>> edges, redges;\r\n    simple_csr<int> g, rg;\r\n    int n, k;\r\n\r\n\
    \    std::vector<int> vs, cmp;\r\n    std::vector<bool> seen;\r\n\r\n    void\
    \ dfs(int v) {\r\n        seen[v] = true;\r\n        for (auto &nv : g[v]) {\r\
    \n            if (!seen[nv]) dfs(nv);\r\n        }\r\n        vs.emplace_back(v);\r\
    \n    }\r\n\r\n    void rdfs(int v) {\r\n        cmp[v] = k;\r\n        for (auto\
    \ nv : rg[v]) {\r\n            if (cmp[nv] < 0) {\r\n                rdfs(nv);\r\
    \n            }\r\n        }\r\n    }\r\n\r\n  public:\r\n    scc_graph(int n_)\
    \ : n(n_) {}\r\n\r\n    void add_edge(int from, int to) {\r\n        edges.emplace_back(from,\
    \ to);\r\n        redges.emplace_back(to, from);\r\n    }\r\n\r\n    std::vector<std::vector<int>>\
    \ scc() {\r\n        g = simple_csr<int>(n, edges);\r\n        rg = simple_csr<int>(n,\
    \ redges);\r\n        edges.clear();\r\n        redges.clear();\r\n        seen.assign(n,\
    \ false);\r\n        for (int i = 0; i < n; i++) {\r\n            if (!seen[i])\
    \ {\r\n                dfs(i);\r\n            }\r\n        }\r\n        std::reverse(vs.begin(),\
    \ vs.end());\r\n        cmp.assign(n, -1);\r\n        k = 0;\r\n        for (auto\
    \ &v : vs) {\r\n            if (cmp[v] < 0) {\r\n                rdfs(v);\r\n\
    \                k++;\r\n            }\r\n        }\r\n        std::vector<std::vector<int>>\
    \ res(k);\r\n        for (int i = 0; i < n; i++) {\r\n            res[cmp[i]].emplace_back(i);\r\
    \n        }\r\n        return res;\r\n    }\r\n\r\n    std::vector<int> scc_id()\
    \ {\r\n        return cmp;\r\n    }\r\n\r\n    bool same(int u, int v) {\r\n \
    \       return cmp[u] == cmp[v];\r\n    }\r\n\r\n    Graph<int> create_graph()\
    \ {\r\n        std::vector<std::pair<int, int>> es;\r\n        for (int i = 0;\
    \ i < n; i++) {\r\n            int v = cmp[i];\r\n            for (auto to : g[i])\
    \ {\r\n                int nv = cmp[to];\r\n                if (v == nv) continue;\r\
    \n                es.emplace_back(v, nv);\r\n            }\r\n        }\r\n  \
    \      std::sort(es.begin(), es.end());\r\n        es.erase(std::unique(es.begin(),\
    \ es.end()), es.end());\r\n        Graph<int> t(k);\r\n        for (auto [v, nv]\
    \ : es) {\r\n            t.add_edge(v, nv, 1);\r\n        }\r\n        t.build();\r\
    \n        return t;\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n#line 6 \"algorithm/two_sat.hpp\"\
    \n\nnamespace ebi {\n\nstruct two_sat {\n  public:\n    two_sat(int _n) : n(_n),\
    \ scc(2 * n) {}\n\n    void add_clause(int p, bool _p, int q, bool _q) {\n   \
    \     assert(0 <= p && p < n);\n        assert(0 <= q && q < n);\n        scc.add_edge(2\
    \ * p + (_p ? 1 : 0), 2 * q + (_q ? 0 : 1));\n        scc.add_edge(2 * q + (_q\
    \ ? 1 : 0), 2 * p + (_p ? 0 : 1));\n    }\n\n    bool satisfiable() {\n      \
    \  scc.scc();\n        std::vector<int> id = scc.scc_id();\n        _answer.resize(n);\n\
    \        for (int i = 0; i < n; i++) {\n            if (id[2 * i] == id[2 * i\
    \ + 1]) {\n                return false;\n            }\n            _answer[i]\
    \ = id[2 * i] > id[2 * i + 1];\n        }\n        return true;\n    }\n\n   \
    \ std::vector<bool> answer() {\n        return _answer;\n    }\n\n  private:\n\
    \    int n;\n    scc_graph scc;\n    std::vector<bool> _answer;\n};\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <cassert>\n\n#include \"../graph/scc_graph.hpp\"\
    \n\nnamespace ebi {\n\nstruct two_sat {\n  public:\n    two_sat(int _n) : n(_n),\
    \ scc(2 * n) {}\n\n    void add_clause(int p, bool _p, int q, bool _q) {\n   \
    \     assert(0 <= p && p < n);\n        assert(0 <= q && q < n);\n        scc.add_edge(2\
    \ * p + (_p ? 1 : 0), 2 * q + (_q ? 0 : 1));\n        scc.add_edge(2 * q + (_q\
    \ ? 1 : 0), 2 * p + (_p ? 0 : 1));\n    }\n\n    bool satisfiable() {\n      \
    \  scc.scc();\n        std::vector<int> id = scc.scc_id();\n        _answer.resize(n);\n\
    \        for (int i = 0; i < n; i++) {\n            if (id[2 * i] == id[2 * i\
    \ + 1]) {\n                return false;\n            }\n            _answer[i]\
    \ = id[2 * i] > id[2 * i + 1];\n        }\n        return true;\n    }\n\n   \
    \ std::vector<bool> answer() {\n        return _answer;\n    }\n\n  private:\n\
    \    int n;\n    scc_graph scc;\n    std::vector<bool> _answer;\n};\n\n}  // namespace\
    \ ebi"
  dependsOn:
  - graph/scc_graph.hpp
  - data_structure/simple_csr.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: algorithm/two_sat.hpp
  requiredBy: []
  timestamp: '2024-03-13 01:44:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/algorithm/Two_Sat.test.cpp
documentation_of: algorithm/two_sat.hpp
layout: document
redirect_from:
- /library/algorithm/two_sat.hpp
- /library/algorithm/two_sat.hpp.html
title: algorithm/two_sat.hpp
---
