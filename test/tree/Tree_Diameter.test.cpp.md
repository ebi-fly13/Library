---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':question:'
    path: graph/base.hpp
    title: Graph (CSR format)
  - icon: ':question:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  - icon: ':heavy_check_mark:'
    path: tree/tree_diameter.hpp
    title: Tree Diameter
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/tree/Tree_Diameter.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\
    \n\n#line 2 \"tree/tree_diameter.hpp\"\n\n#include <algorithm>\n#include <vector>\n\
    \n#line 2 \"graph/base.hpp\"\n\n#include <cassert>\n#include <iostream>\n#include\
    \ <ranges>\n#line 7 \"graph/base.hpp\"\n\n#line 2 \"data_structure/simple_csr.hpp\"\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 7 \"tree/tree_diameter.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T>\nstd::pair<T, std::vector<int>> tree_diameter(const\
    \ Graph<T> &g) {\n    int n = g.size();\n    std::vector<T> dp(n);\n    std::vector<int>\
    \ par(n, -1);\n    dp[0] = 0;\n    auto dfs = [&](auto &&self, int v) -> void\
    \ {\n        for (const auto e : g[v]) {\n            if (e.to == par[v]) continue;\n\
    \            par[e.to] = v;\n            dp[e.to] = dp[v] + e.cost;\n        \
    \    self(self, e.to);\n        }\n    };\n    dfs(dfs, 0);\n    int u = std::max_element(dp.begin(),\
    \ dp.end()) - dp.begin();\n    par[u] = -1;\n    dp[u] = 0;\n    dfs(dfs, u);\n\
    \    int v = std::max_element(dp.begin(), dp.end()) - dp.begin();\n    std::vector<int>\
    \ path;\n    while (u != v) {\n        path.emplace_back(v);\n        v = par[v];\n\
    \    }\n    path.emplace_back(u);\n    return {dp[*path.begin()], path};\n}\n\n\
    }  // namespace ebi\n#line 4 \"test/tree/Tree_Diameter.test.cpp\"\n\n#line 6 \"\
    test/tree/Tree_Diameter.test.cpp\"\n\n#line 2 \"template/int_alias.hpp\"\n\n#include\
    \ <cstdint>\n\nnamespace ebi {\n\nusing ld = long double;\nusing std::size_t;\n\
    using i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\n\
    using u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\n}  // namespace ebi\n#line 9 \"test/tree/Tree_Diameter.test.cpp\"\
    \n\nusing ebi::i64;\n\nint main() {\n    int n;\n    std::cin >> n;\n    ebi::Graph<i64>\
    \ g(n);\n    g.read_tree(0, true);\n    auto [x, path] = ebi::tree_diameter(g);\n\
    \    std::cout << x << \" \" << path.size() << '\\n';\n    for (auto v : path)\
    \ {\n        std::cout << v << \" \";\n    }\n    std::cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ \"../../tree/tree_diameter.hpp\"\n\n#include <iostream>\n\n#include \"../../graph/base.hpp\"\
    \n#include \"../../template/int_alias.hpp\"\n\nusing ebi::i64;\n\nint main() {\n\
    \    int n;\n    std::cin >> n;\n    ebi::Graph<i64> g(n);\n    g.read_tree(0,\
    \ true);\n    auto [x, path] = ebi::tree_diameter(g);\n    std::cout << x << \"\
    \ \" << path.size() << '\\n';\n    for (auto v : path) {\n        std::cout <<\
    \ v << \" \";\n    }\n    std::cout << '\\n';\n}"
  dependsOn:
  - tree/tree_diameter.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  - template/int_alias.hpp
  isVerificationFile: true
  path: test/tree/Tree_Diameter.test.cpp
  requiredBy: []
  timestamp: '2025-03-18 01:14:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/Tree_Diameter.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Tree_Diameter.test.cpp
- /verify/test/tree/Tree_Diameter.test.cpp.html
title: test/tree/Tree_Diameter.test.cpp
---
