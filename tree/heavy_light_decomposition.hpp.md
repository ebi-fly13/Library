---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: Graph (CSR format)
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/dsu_on_tree.hpp
    title: Dsu on Tree
  - icon: ':heavy_check_mark:'
    path: tree/lca_based_auxiliary_tree.hpp
    title: LCA based Auxiliary Tree
  - icon: ':heavy_check_mark:'
    path: tree/rerooting.hpp
    title: Rerooting DP
  - icon: ':heavy_check_mark:'
    path: tree/subtree_hash.hpp
    title: Subtree Hash
  - icon: ':heavy_check_mark:'
    path: tree/tree_hash.hpp
    title: Tree Hash
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2450.test.cpp
    title: test/aoj/aoj_2450.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2821.test.cpp
    title: test/aoj/aoj_2821.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2995.test.cpp
    title: test/aoj/aoj_2995.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Vertex_Add_Path_Sum.test.cpp
    title: test/data_structure/Vertex_Add_Path_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Vertex_Add_Subtree_Sum.test.cpp
    title: test/data_structure/Vertex_Add_Subtree_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Vertex_Set_Path_Compositie.test.cpp
    title: test/data_structure/Vertex_Set_Path_Compositie.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Jump_on_Tree_HLD.test.cpp
    title: test/tree/Jump_on_Tree_HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
    title: test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Tree_Path_Composite_Sum.test.cpp
    title: test/tree/Tree_Path_Composite_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Vertex_Add_Subtree_Sum_Dsu_on_Tree.test.cpp
    title: test/tree/Vertex_Add_Subtree_Sum_Dsu_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_2439.test.cpp
    title: test/yuki/yuki_2439.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_901.test.cpp
    title: test/yuki/yuki_901.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_901_2.test.cpp
    title: test/yuki/yuki_901_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/heavy_light_decomposition.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\n#line 2 \"graph/base.hpp\"\n\n#line 4\
    \ \"graph/base.hpp\"\n#include <iostream>\n#include <ranges>\n#line 7 \"graph/base.hpp\"\
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
    \ assert(prepared);\n        return edges;\n    }\n\n    const auto operator[](int\
    \ i) const {\n        assert(prepared);\n        return csr[i];\n    }\n    auto\
    \ operator[](int i) {\n        assert(prepared);\n        return csr[i];\n   \
    \ }\n\n  private:\n    int n, m = 0;\n\n    std::vector<std::pair<int, edge_type>>\
    \ buff;\n\n    std::vector<edge_type> edges;\n    simple_csr<edge_type> csr;\n\
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 8 \"tree/heavy_light_decomposition.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> struct heavy_light_decomposition {\n\
    \  private:\n    void dfs_sz(int v) {\n        for (auto &e : g[v]) {\n      \
    \      if (e.to == par[v]) continue;\n            par[e.to] = v;\n           \
    \ depth_[e.to] = depth_[v] + 1;\n            dist[e.to] = dist[v] + e.cost;\n\
    \            dfs_sz(e.to);\n            sz[v] += sz[e.to];\n            if (sz[e.to]\
    \ > sz[g[v][0].to] || g[v][0].to == par[v])\n                std::swap(e, g[v][0]);\n\
    \        }\n    }\n\n    void dfs_hld(int v) {\n        in[v] = num++;\n     \
    \   rev[in[v]] = v;\n        for (auto e : g[v]) {\n            if (e.to == par[v])\
    \ continue;\n            nxt[e.to] = (e.to == g[v][0].to ? nxt[v] : e.to);\n \
    \           dfs_hld(e.to);\n        }\n        out[v] = num;\n    }\n\n    //\
    \ [u, v) \u30D1\u30B9\u306E\u53D6\u5F97 (v \u306F u \u306E\u7956\u5148)\n    std::vector<std::pair<int,\
    \ int>> ascend(int u, int v) const {\n        std::vector<std::pair<int, int>>\
    \ res;\n        while (nxt[u] != nxt[v]) {\n            res.emplace_back(in[u],\
    \ in[nxt[u]]);\n            u = par[nxt[u]];\n        }\n        if (u != v) res.emplace_back(in[u],\
    \ in[v] + 1);\n        return res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\
    \u5F97 (u \u306F v \u306E\u7956\u5148)\n    std::vector<std::pair<int, int>> descend(int\
    \ u, int v) const {\n        if (u == v) return {};\n        if (nxt[u] == nxt[v])\
    \ return {{in[u] + 1, in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n\
    \        res.emplace_back(in[nxt[v]], in[v]);\n        return res;\n    }\n\n\
    \  public:\n    heavy_light_decomposition(const Graph<T> &gh, int root_ = 0)\n\
    \        : n(gh.size()),\n          root(root_),\n          g(gh),\n         \
    \ sz(n, 1),\n          in(n),\n          out(n),\n          nxt(n),\n        \
    \  par(n, -1),\n          depth_(n, 0),\n          rev(n),\n          dist(n,\
    \ 0) {\n        nxt[root] = root;\n        dfs_sz(root);\n        dfs_hld(root);\n\
    \    }\n\n    int idx(int u) const {\n        return in[u];\n    }\n\n    int\
    \ rev_idx(int i) const {\n        return rev[i];\n    }\n\n    int la(int v, int\
    \ k) const {\n        while (1) {\n            int u = nxt[v];\n            if\
    \ (in[u] <= in[v] - k) return rev[in[v] - k];\n            k -= in[v] - in[u]\
    \ + 1;\n            v = par[u];\n        }\n    }\n\n    int lca(int u, int v)\
    \ const {\n        while (nxt[u] != nxt[v]) {\n            if (in[u] < in[v])\
    \ std::swap(u, v);\n            u = par[nxt[u]];\n        }\n        return depth_[u]\
    \ < depth_[v] ? u : v;\n    }\n\n    int jump(int s, int t, int i) const {\n \
    \       if (i == 0) return s;\n        int l = lca(s, t);\n        int d = depth_[s]\
    \ + depth_[t] - depth_[l] * 2;\n        if (d < i) return -1;\n        if (depth_[s]\
    \ - depth_[l] >= i) return la(s, i);\n        i = d - i;\n        return la(t,\
    \ i);\n    }\n\n    std::vector<int> path(int s, int t) const {\n        int l\
    \ = lca(s, t);\n        std::vector<int> a, b;\n        for (; s != l; s = par[s])\
    \ a.emplace_back(s);\n        for (; t != l; t = par[t]) b.emplace_back(t);\n\
    \        a.emplace_back(l);\n        std::reverse(b.begin(), b.end());\n     \
    \   a.insert(a.end(), b.begin(), b.end());\n        return a;\n    }\n\n    int\
    \ root_of_heavy_path(int u) const {\n        return nxt[u];\n    }\n\n    int\
    \ parent(int u) const {\n        return par[u];\n    }\n\n    T distance(int u,\
    \ int v) const {\n        return dist[u] + dist[v] - 2 * dist[lca(u, v)];\n  \
    \  }\n\n    T distance_from_root(int v) const {\n        return dist[v];\n   \
    \ }\n\n    T depth(int v) const {\n        return depth_[v];\n    }\n\n    bool\
    \ at_path(int u, int v, int s) const {\n        return distance(u, v) == distance(u,\
    \ s) + distance(s, v);\n    }\n\n    std::pair<int, int> subtree_section(int v)\
    \ const {\n        return {in[v], out[v]};\n    }\n\n    bool is_subtree(int u,\
    \ int v) const {\n        return in[u] <= in[v] && in[v] < out[u];\n    }\n\n\
    \    template <class F>\n    void path_noncommutative_query(int u, int v, bool\
    \ vertex,\n                                   const F &f) const {\n        int\
    \ l = lca(u, v);\n        for (auto [a, b] : ascend(u, l)) f(a + 1, b);\n    \
    \    if (vertex) f(in[l], in[l] + 1);\n        for (auto [a, b] : descend(l, v))\
    \ f(a, b + 1);\n    }\n\n    std::vector<std::pair<int, int>> path_sections(int\
    \ u, int v,\n                                                   bool vertex) const\
    \ {\n        int l = lca(u, v);\n        std::vector<std::pair<int, int>> sections;\n\
    \        for (auto [a, b] : ascend(u, l)) sections.emplace_back(a + 1, b);\n \
    \       if (vertex) sections.emplace_back(in[l], in[l] + 1);\n        for (auto\
    \ [a, b] : descend(l, v)) sections.emplace_back(a, b + 1);\n        return sections;\n\
    \    }\n\n    template <class F>\n    int max_path(int u, int v, bool vertex,\
    \ F binary_search) const {\n        int prev = -1;\n        int l = lca(u, v);\n\
    \        for (auto [a, b] : ascend(u, l)) {\n            a++;\n            int\
    \ m = binary_search(a, b);\n            if (m == b) {\n                prev =\
    \ rev[b];\n            } else {\n                return (m == a ? prev : rev[m]);\n\
    \            }\n        }\n        if (vertex) {\n            int m = binary_search(in[l],\
    \ in[l] + 1);\n            if (m == in[l]) {\n                return prev;\n \
    \           } else {\n                prev = l;\n            }\n        }\n  \
    \      for (auto [a, b] : descend(l, v)) {\n            b++;\n            int\
    \ m = binary_search(a, b);\n            if (m == b) {\n                prev =\
    \ rev[b - 1];\n            } else {\n                return m == a ? prev : rev[m\
    \ - 1];\n            }\n        }\n        return v;\n    }\n\n    template <class\
    \ F> void subtree_query(int u, bool vertex, const F &f) {\n        f(in[u] + int(!vertex),\
    \ out[u]);\n    }\n\n    const std::vector<int> &dfs_order() const {\n       \
    \ return rev;\n    }\n\n    template <class ADD, class QUERY, class CLEAR, class\
    \ RESET>\n    void dsu_on_tree(const ADD &add, const QUERY &query, const CLEAR\
    \ &clear,\n                     const RESET &reset) const;\n\n    std::vector<std::pair<int,\
    \ int>> lca_based_auxiliary_tree_dfs_order(\n        std::vector<int> vs) const;\n\
    \n    std::pair<std::vector<int>, Graph<T>> lca_based_auxiliary_tree(\n      \
    \  std::vector<int> vs) const;\n\n  private:\n    int n, root;\n    Graph<T> g;\n\
    \    std::vector<int> sz, in, out, nxt, par, depth_, rev;\n    std::vector<T>\
    \ dist;\n\n    int num = 0;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \n#include \"../graph/base.hpp\"\n\nnamespace ebi {\n\ntemplate <class T> struct\
    \ heavy_light_decomposition {\n  private:\n    void dfs_sz(int v) {\n        for\
    \ (auto &e : g[v]) {\n            if (e.to == par[v]) continue;\n            par[e.to]\
    \ = v;\n            depth_[e.to] = depth_[v] + 1;\n            dist[e.to] = dist[v]\
    \ + e.cost;\n            dfs_sz(e.to);\n            sz[v] += sz[e.to];\n     \
    \       if (sz[e.to] > sz[g[v][0].to] || g[v][0].to == par[v])\n             \
    \   std::swap(e, g[v][0]);\n        }\n    }\n\n    void dfs_hld(int v) {\n  \
    \      in[v] = num++;\n        rev[in[v]] = v;\n        for (auto e : g[v]) {\n\
    \            if (e.to == par[v]) continue;\n            nxt[e.to] = (e.to == g[v][0].to\
    \ ? nxt[v] : e.to);\n            dfs_hld(e.to);\n        }\n        out[v] = num;\n\
    \    }\n\n    // [u, v) \u30D1\u30B9\u306E\u53D6\u5F97 (v \u306F u \u306E\u7956\
    \u5148)\n    std::vector<std::pair<int, int>> ascend(int u, int v) const {\n \
    \       std::vector<std::pair<int, int>> res;\n        while (nxt[u] != nxt[v])\
    \ {\n            res.emplace_back(in[u], in[nxt[u]]);\n            u = par[nxt[u]];\n\
    \        }\n        if (u != v) res.emplace_back(in[u], in[v] + 1);\n        return\
    \ res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\u5F97 (u \u306F v \u306E\
    \u7956\u5148)\n    std::vector<std::pair<int, int>> descend(int u, int v) const\
    \ {\n        if (u == v) return {};\n        if (nxt[u] == nxt[v]) return {{in[u]\
    \ + 1, in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n        res.emplace_back(in[nxt[v]],\
    \ in[v]);\n        return res;\n    }\n\n  public:\n    heavy_light_decomposition(const\
    \ Graph<T> &gh, int root_ = 0)\n        : n(gh.size()),\n          root(root_),\n\
    \          g(gh),\n          sz(n, 1),\n          in(n),\n          out(n),\n\
    \          nxt(n),\n          par(n, -1),\n          depth_(n, 0),\n         \
    \ rev(n),\n          dist(n, 0) {\n        nxt[root] = root;\n        dfs_sz(root);\n\
    \        dfs_hld(root);\n    }\n\n    int idx(int u) const {\n        return in[u];\n\
    \    }\n\n    int rev_idx(int i) const {\n        return rev[i];\n    }\n\n  \
    \  int la(int v, int k) const {\n        while (1) {\n            int u = nxt[v];\n\
    \            if (in[u] <= in[v] - k) return rev[in[v] - k];\n            k -=\
    \ in[v] - in[u] + 1;\n            v = par[u];\n        }\n    }\n\n    int lca(int\
    \ u, int v) const {\n        while (nxt[u] != nxt[v]) {\n            if (in[u]\
    \ < in[v]) std::swap(u, v);\n            u = par[nxt[u]];\n        }\n       \
    \ return depth_[u] < depth_[v] ? u : v;\n    }\n\n    int jump(int s, int t, int\
    \ i) const {\n        if (i == 0) return s;\n        int l = lca(s, t);\n    \
    \    int d = depth_[s] + depth_[t] - depth_[l] * 2;\n        if (d < i) return\
    \ -1;\n        if (depth_[s] - depth_[l] >= i) return la(s, i);\n        i = d\
    \ - i;\n        return la(t, i);\n    }\n\n    std::vector<int> path(int s, int\
    \ t) const {\n        int l = lca(s, t);\n        std::vector<int> a, b;\n   \
    \     for (; s != l; s = par[s]) a.emplace_back(s);\n        for (; t != l; t\
    \ = par[t]) b.emplace_back(t);\n        a.emplace_back(l);\n        std::reverse(b.begin(),\
    \ b.end());\n        a.insert(a.end(), b.begin(), b.end());\n        return a;\n\
    \    }\n\n    int root_of_heavy_path(int u) const {\n        return nxt[u];\n\
    \    }\n\n    int parent(int u) const {\n        return par[u];\n    }\n\n   \
    \ T distance(int u, int v) const {\n        return dist[u] + dist[v] - 2 * dist[lca(u,\
    \ v)];\n    }\n\n    T distance_from_root(int v) const {\n        return dist[v];\n\
    \    }\n\n    T depth(int v) const {\n        return depth_[v];\n    }\n\n   \
    \ bool at_path(int u, int v, int s) const {\n        return distance(u, v) ==\
    \ distance(u, s) + distance(s, v);\n    }\n\n    std::pair<int, int> subtree_section(int\
    \ v) const {\n        return {in[v], out[v]};\n    }\n\n    bool is_subtree(int\
    \ u, int v) const {\n        return in[u] <= in[v] && in[v] < out[u];\n    }\n\
    \n    template <class F>\n    void path_noncommutative_query(int u, int v, bool\
    \ vertex,\n                                   const F &f) const {\n        int\
    \ l = lca(u, v);\n        for (auto [a, b] : ascend(u, l)) f(a + 1, b);\n    \
    \    if (vertex) f(in[l], in[l] + 1);\n        for (auto [a, b] : descend(l, v))\
    \ f(a, b + 1);\n    }\n\n    std::vector<std::pair<int, int>> path_sections(int\
    \ u, int v,\n                                                   bool vertex) const\
    \ {\n        int l = lca(u, v);\n        std::vector<std::pair<int, int>> sections;\n\
    \        for (auto [a, b] : ascend(u, l)) sections.emplace_back(a + 1, b);\n \
    \       if (vertex) sections.emplace_back(in[l], in[l] + 1);\n        for (auto\
    \ [a, b] : descend(l, v)) sections.emplace_back(a, b + 1);\n        return sections;\n\
    \    }\n\n    template <class F>\n    int max_path(int u, int v, bool vertex,\
    \ F binary_search) const {\n        int prev = -1;\n        int l = lca(u, v);\n\
    \        for (auto [a, b] : ascend(u, l)) {\n            a++;\n            int\
    \ m = binary_search(a, b);\n            if (m == b) {\n                prev =\
    \ rev[b];\n            } else {\n                return (m == a ? prev : rev[m]);\n\
    \            }\n        }\n        if (vertex) {\n            int m = binary_search(in[l],\
    \ in[l] + 1);\n            if (m == in[l]) {\n                return prev;\n \
    \           } else {\n                prev = l;\n            }\n        }\n  \
    \      for (auto [a, b] : descend(l, v)) {\n            b++;\n            int\
    \ m = binary_search(a, b);\n            if (m == b) {\n                prev =\
    \ rev[b - 1];\n            } else {\n                return m == a ? prev : rev[m\
    \ - 1];\n            }\n        }\n        return v;\n    }\n\n    template <class\
    \ F> void subtree_query(int u, bool vertex, const F &f) {\n        f(in[u] + int(!vertex),\
    \ out[u]);\n    }\n\n    const std::vector<int> &dfs_order() const {\n       \
    \ return rev;\n    }\n\n    template <class ADD, class QUERY, class CLEAR, class\
    \ RESET>\n    void dsu_on_tree(const ADD &add, const QUERY &query, const CLEAR\
    \ &clear,\n                     const RESET &reset) const;\n\n    std::vector<std::pair<int,\
    \ int>> lca_based_auxiliary_tree_dfs_order(\n        std::vector<int> vs) const;\n\
    \n    std::pair<std::vector<int>, Graph<T>> lca_based_auxiliary_tree(\n      \
    \  std::vector<int> vs) const;\n\n  private:\n    int n, root;\n    Graph<T> g;\n\
    \    std::vector<int> sz, in, out, nxt, par, depth_, rev;\n    std::vector<T>\
    \ dist;\n\n    int num = 0;\n};\n\n}  // namespace ebi\n"
  dependsOn:
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: false
  path: tree/heavy_light_decomposition.hpp
  requiredBy:
  - tree/rerooting.hpp
  - tree/lca_based_auxiliary_tree.hpp
  - tree/dsu_on_tree.hpp
  - tree/subtree_hash.hpp
  - tree/tree_hash.hpp
  timestamp: '2025-03-18 03:40:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Vertex_Add_Subtree_Sum_Dsu_on_Tree.test.cpp
  - test/tree/Jump_on_Tree_HLD.test.cpp
  - test/tree/Tree_Path_Composite_Sum.test.cpp
  - test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
  - test/aoj/aoj_2450.test.cpp
  - test/aoj/aoj_2821.test.cpp
  - test/aoj/aoj_2995.test.cpp
  - test/data_structure/Vertex_Add_Subtree_Sum.test.cpp
  - test/data_structure/Vertex_Add_Path_Sum.test.cpp
  - test/data_structure/Vertex_Set_Path_Compositie.test.cpp
  - test/yuki/yuki_901_2.test.cpp
  - test/yuki/yuki_2439.test.cpp
  - test/yuki/yuki_901.test.cpp
documentation_of: tree/heavy_light_decomposition.hpp
layout: document
title: Heavy Light Decomposition
---

## 説明

木をHLDする。パスクエリ、部分木クエリを処理することができる。

### コンストラクタ

`HeavyLightDecomposition(std::vector<std::vector<int>> g, int root = 0)`

木グラフ g と root ノード番号を与えてHLDする。デフォルトで root は頂点 0

### idx(int u)

頂点 $u$ のDFS行きがけ順の番号を返す。このidxの位置にデータ構造のインデックスを対応させればパスクエリや部分木クエリを処理することができる。具体的には使い方を参照。

### la(int v, int k)

頂点 $v$ から $k$ だけ親方向に上った頂点を返す。 $O(\log N)$ 

### lca(int u, int v)

頂点 $u$, $v$ のLCAを返す。 $O(\log N)$

### jump(int s, int t, int k)

頂点 $s$ から $t$ の方向に $k$ だけ移動した頂点を返す。 $O(\log N)$

### path(int s, int t)

頂点 $s$, $t$ の単純パスを返す。

### parent(int u)

頂点 $u$ の親を返す。 $u$ が根である場合は、 $-1$ を返す。

### distance(int u, int v)

頂点 $u$, $v$ の距離を返す。 $O(\log N)$

### at_path(int u, int v, int s)

$u-v$ パスに $s$ が含まれるか判定。 $O(\log N)$

### root_of_heavy_path(int u)

$u$ の属するheavy pathの最も親に近いものを返す。 $O(1)$

### path_noncommutative_query(int u, int v, bool vertex, const F &f)

パス $u-v$ にクエリ`f`を適用する。非可換。vertexがtrueのとき、頂点に属性がある。vertexがfalseのとき、辺に属性がある。親-子間の辺属性は子のidxに持つ。

### max_path(int u, int v, bool vertex, F binary_search)

パス $u-v$ に含まれる頂点で、 $u-m$ での値が `true` を返す最大のパスとなる $m$ を二分探索で求める。
`binary_search` という関数を引数に渡すが、これは `path_noncommutative_query` で渡す `f` と同じ引数を取り、返り値をデータ構造の二分探索した後の `id` とする。
計算量はデータ構造に対する二分探索の計算量を $O(\log N)$ とすると $O((\log N)^2)$

### subtree_query(int u, bool vertex, const F &f)

頂点 $u$ の部分木にクエリ`f`を適用する。vertexがtrueのとき、根頂点である $u$ にもクエリを適用する。

## 使い方

```
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    rep(i,0,m) {
        int u,v;
        std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    lib::HeavyLightDecomposition hld(g);
    segtree<S, op, e> seg1(n) 
    segtree<S, op_rev, e> seg2(n);
    auto set = [&](int u, S x) {
        int idx = hld.idx(u);
        seg1.set(idx, x);
        seg2.set(idx, x);
    };
    S ans = e();
    auto f = [&](int l, int r) {
        if(l <= r) ans = op(ans, seg1.prod(l, r));
        else ans = op(ans, seg2.prod(r, l)); 
    };
    int u,v;
    std::cin >> u >> v;
    ans = e();
    hld.path_noncommutative_query(u, v, true, f);
    std::cout << ans << '\n';
}
```
