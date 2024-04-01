---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/or_convolution.hpp
    title: Bitwise OR Convolution
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: Graph (CSR format)
  - icon: ':heavy_check_mark:'
    path: set_function/subset_transform.hpp
    title: "Subset Transform (Zeta / M\xF6bius)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/chromatic_number.hpp\"\n\n#include <cassert>\n#include\
    \ <ranges>\n#include <vector>\n\n#line 2 \"convolution/or_convolution.hpp\"\n\n\
    #line 2 \"set_function/subset_transform.hpp\"\n\n#include <bit>\n#line 6 \"set_function/subset_transform.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> std::vector<T> subset_zeta(const std::vector<T>\
    \ &a) {\n    int n = std::bit_width(a.size()) - 1;\n    assert((1 << n) == (int)a.size());\n\
    \    std::vector<T> ra = a;\n    for (int i = 0; i < n; i++) {\n        int w\
    \ = 1 << i;\n        for (int p = 0; p < (1 << n); p += 2 * w) {\n           \
    \ for (int s = p; s < p + w; s++) {\n                int t = s | w;\n        \
    \        ra[t] += ra[s];\n            }\n        }\n    }\n    return ra;\n}\n\
    \ntemplate <class T> std::vector<T> subset_mobius(const std::vector<T> &ra) {\n\
    \    int n = std::bit_width(ra.size()) - 1;\n    assert((1 << n) == (int)ra.size());\n\
    \    std::vector<T> a = ra;\n    for (int i = 0; i < n; i++) {\n        int w\
    \ = 1 << i;\n        for (int p = 0; p < (1 << n); p += 2 * w) {\n           \
    \ for (int s = p; s < p + w; s++) {\n                int t = s | w;\n        \
    \        a[t] -= a[s];\n            }\n        }\n    }\n    return a;\n}\n\n\
    }  // namespace ebi\n#line 4 \"convolution/or_convolution.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <class T>\nstd::vector<T> or_convolution(const std::vector<T>\
    \ &a,\n                              const std::vector<T> &b) {\n    int n = a.size();\n\
    \    auto ra = subset_zeta(a);\n    auto rb = subset_zeta(b);\n    for (int i\
    \ = 0; i < n; i++) {\n        ra[i] *= rb[i];\n    }\n    return subset_mobius(ra);\n\
    }\n\n}  // namespace ebi\n#line 2 \"graph/base.hpp\"\n\n#line 4 \"graph/base.hpp\"\
    \n#include <iostream>\n#line 7 \"graph/base.hpp\"\n\n#line 2 \"data_structure/simple_csr.hpp\"\
    \n\n#line 4 \"data_structure/simple_csr.hpp\"\n#include <utility>\n#line 6 \"\
    data_structure/simple_csr.hpp\"\n\nnamespace ebi {\n\ntemplate <class E> struct\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 9 \"graph/chromatic_number.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> int chromatic_number(const Graph<T>\
    \ &g) {\n    int n = g.node_number();\n    std::vector<int> es(n, 0);\n    for\
    \ (auto e : g.get_edges()) {\n        es[e.from] |= 1 << e.to;\n    }\n    std::vector<int>\
    \ dp1(1 << n, 1);\n    for (int s : std::views::iota(0, 1 << n)) {\n        for\
    \ (int v : std::views::iota(0, n)) {\n            if (((s >> v) & 1) && (s & es[v]))\
    \ {\n                dp1[s] = 0;\n            }\n        }\n    }\n    if (dp1.back()\
    \ == 1) return 1;\n    auto now = dp1;\n    for (int k : std::views::iota(2, n\
    \ + 1)) {\n        int sz = now.size();\n        now = or_convolution(dp1, now);\n\
    \        if (now.back() > 0) {\n            return k;\n        }\n        for\
    \ (int i : std::views::iota(0, sz / 2)) {\n            now[i] = now[i + sz / 2]\
    \ > 0;\n        }\n        now.resize(sz / 2);\n        dp1.resize(sz / 2);\n\
    \    }\n    assert(0);\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <ranges>\n#include <vector>\n\
    \n#include \"../convolution/or_convolution.hpp\"\n#include \"../graph/base.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> int chromatic_number(const Graph<T>\
    \ &g) {\n    int n = g.node_number();\n    std::vector<int> es(n, 0);\n    for\
    \ (auto e : g.get_edges()) {\n        es[e.from] |= 1 << e.to;\n    }\n    std::vector<int>\
    \ dp1(1 << n, 1);\n    for (int s : std::views::iota(0, 1 << n)) {\n        for\
    \ (int v : std::views::iota(0, n)) {\n            if (((s >> v) & 1) && (s & es[v]))\
    \ {\n                dp1[s] = 0;\n            }\n        }\n    }\n    if (dp1.back()\
    \ == 1) return 1;\n    auto now = dp1;\n    for (int k : std::views::iota(2, n\
    \ + 1)) {\n        int sz = now.size();\n        now = or_convolution(dp1, now);\n\
    \        if (now.back() > 0) {\n            return k;\n        }\n        for\
    \ (int i : std::views::iota(0, sz / 2)) {\n            now[i] = now[i + sz / 2]\
    \ > 0;\n        }\n        now.resize(sz / 2);\n        dp1.resize(sz / 2);\n\
    \    }\n    assert(0);\n}\n\n}  // namespace ebi"
  dependsOn:
  - convolution/or_convolution.hpp
  - set_function/subset_transform.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: false
  path: graph/chromatic_number.hpp
  requiredBy: []
  timestamp: '2024-04-02 00:37:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/chromatic_number.hpp
layout: document
title: "Chromatic Number (\u5F69\u8272\u6570)"
---

## 説明

グラフの彩色数を求める。 $O(2^N N)$

高速化はほとんど行っていないため、より高速な実装が欲しい場合は [Nachiaさんの記事](https://www.mathenachia.blog/chromatic-fast/) を見てください。