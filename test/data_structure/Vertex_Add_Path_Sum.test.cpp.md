---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: segtree
  - icon: ':question:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':question:'
    path: graph/base.hpp
    title: Graph (CSR format)
  - icon: ':heavy_check_mark:'
    path: tree/heavy_light_decomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/data_structure/Vertex_Add_Path_Sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#line 2 \"data_structure/segtree.hpp\"\n\r\n\
    #include <cassert>\r\n#line 5 \"data_structure/segtree.hpp\"\n\r\nnamespace ebi\
    \ {\r\n\r\ntemplate <class S, S (*op)(S, S), S (*e)()> struct segtree {\r\n  private:\r\
    \n    int n;\r\n    int sz;\r\n    std::vector<S> data;\r\n\r\n    void update(int\
    \ i) {\r\n        data[i] = op(data[2 * i], data[2 * i + 1]);\r\n    }\r\n\r\n\
    \  public:\r\n    segtree(int n_) : segtree(std::vector<S>(n_, e())) {}\r\n  \
    \  segtree(const std::vector<S> &v) : n((int)v.size()), sz(1) {\r\n        while\
    \ (sz < n) sz *= 2;\r\n        data = std::vector<S>(2 * sz, e());\r\n       \
    \ for (int i = 0; i < n; i++) {\r\n            data[sz + i] = v[i];\r\n      \
    \  }\r\n        for (int i = sz - 1; i >= 1; i--) update(i);\r\n    }\r\n\r\n\
    \    void set(int p, S x) {\r\n        assert(0 <= p && p < n);\r\n        p +=\
    \ sz;\r\n        data[p] = x;\r\n        while (p > 1) {\r\n            p >>=\
    \ 1;\r\n            update(p);\r\n        }\r\n    }\r\n\r\n    S get(int p) const\
    \ {\r\n        assert(0 <= p && p < n);\r\n        return data[p + sz];\r\n  \
    \  }\r\n\r\n    S prod(int l, int r) const {\r\n        assert(0 <= l && l <=\
    \ r && r <= n);\r\n        S sml = e(), smr = e();\r\n        l += sz;\r\n   \
    \     r += sz;\r\n        while (l < r) {\r\n            if (l & 1) sml = op(sml,\
    \ data[l++]);\r\n            if (r & 1) smr = op(data[--r], smr);\r\n        \
    \    l >>= 1;\r\n            r >>= 1;\r\n        }\r\n        return op(sml, smr);\r\
    \n    }\r\n\r\n    S all_prod() const {\r\n        return data[1];\r\n    }\r\n\
    \r\n    template <class F> int max_right(int l, F f) const {\r\n        assert(0\
    \ <= l && l < n);\r\n        assert(f(e()));\r\n        if (l == n) return n;\r\
    \n        l += sz;\r\n        S sm = e();\r\n        do {\r\n            while\
    \ (l % 2 == 0) l >>= 1;\r\n            if (!f(op(sm, data[l]))) {\r\n        \
    \        while (l < sz) {\r\n                    l = 2 * l;\r\n              \
    \      if (f(op(sm, data[l]))) {\r\n                        sm = op(sm, data[l]);\r\
    \n                        l++;\r\n                    }\r\n                }\r\
    \n                return l - sz;\r\n            }\r\n            sm = op(sm, data[l]);\r\
    \n            l++;\r\n        } while ((l & -l) != l);\r\n        return n;\r\n\
    \    }\r\n\r\n    template <class F> int min_left(int r, F f) const {\r\n    \
    \    assert(0 <= r && r <= n);\r\n        assert(f(e()));\r\n        if (r ==\
    \ 0) return 0;\r\n        r += sz;\r\n        S sm = e();\r\n        do {\r\n\
    \            r--;\r\n            while (r > 1 && (r % 2)) r >>= 1;\r\n       \
    \     if (!f(op(data[r], sm))) {\r\n                while (r < sz) {\r\n     \
    \               r = 2 * r + 1;\r\n                    if (f(op(data[r], sm)))\
    \ {\r\n                        sm = op(data[r], sm);\r\n                     \
    \   r--;\r\n                    }\r\n                }\r\n                return\
    \ r + 1 - sz;\r\n            }\r\n            sm = op(data[r], sm);\r\n      \
    \  } while ((r & -r) != r);\r\n        return 0;\r\n    }\r\n\r\n    S operator[](int\
    \ p) const {\r\n        return data[sz + p];\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\r\n#line 2 \"graph/base.hpp\"\n\n#line 5 \"graph/base.hpp\"\n#include <ranges>\n\
    #line 7 \"graph/base.hpp\"\n\n#line 2 \"data_structure/simple_csr.hpp\"\n\n#line\
    \ 4 \"data_structure/simple_csr.hpp\"\n#include <utility>\n#line 6 \"data_structure/simple_csr.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class E> struct simple_csr {\n    simple_csr()\
    \ = default;\n\n    simple_csr(int n, const std::vector<std::pair<int, E>>& elements)\n\
    \        : start(n + 1, 0), elist(elements.size()) {\n        for (auto e : elements)\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 2 \"tree/heavy_light_decomposition.hpp\"\
    \n\n#include <algorithm>\n#line 6 \"tree/heavy_light_decomposition.hpp\"\n\n#line\
    \ 8 \"tree/heavy_light_decomposition.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ T> struct heavy_light_decomposition {\n  private:\n    void dfs_sz(int v, Graph<T>\
    \ &g) {\n        for (auto &e : g[v]) {\n            if (e.to == par[v]) continue;\n\
    \            par[e.to] = v;\n            depth_[e.to] = depth_[v] + 1;\n     \
    \       dist[e.to] = dist[v] + e.cost;\n            dfs_sz(e.to, g);\n       \
    \     sz[v] += sz[e.to];\n            if (sz[e.to] > sz[g[v][0].to] || g[v][0].to\
    \ == par[v])\n                std::swap(e, g[v][0]);\n        }\n    }\n\n   \
    \ void dfs_hld(int v, const Graph<T> &g) {\n        in[v] = num++;\n        rev[in[v]]\
    \ = v;\n        for (auto e : g[v]) {\n            if (e.to == par[v]) continue;\n\
    \            nxt[e.to] = (e.to == g[v][0].to ? nxt[v] : e.to);\n            dfs_hld(e.to,\
    \ g);\n        }\n        out[v] = num;\n    }\n\n    // [u, v) \u30D1\u30B9\u306E\
    \u53D6\u5F97 (v \u306F u \u306E\u7956\u5148)\n    std::vector<std::pair<int, int>>\
    \ ascend(int u, int v) const {\n        std::vector<std::pair<int, int>> res;\n\
    \        while (nxt[u] != nxt[v]) {\n            res.emplace_back(in[u], in[nxt[u]]);\n\
    \            u = par[nxt[u]];\n        }\n        if (u != v) res.emplace_back(in[u],\
    \ in[v] + 1);\n        return res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\
    \u5F97 (u \u306F v \u306E\u7956\u5148)\n    std::vector<std::pair<int, int>> descend(int\
    \ u, int v) const {\n        if (u == v) return {};\n        if (nxt[u] == nxt[v])\
    \ return {{in[u] + 1, in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n\
    \        res.emplace_back(in[nxt[v]], in[v]);\n        return res;\n    }\n\n\
    \  public:\n    heavy_light_decomposition(Graph<T> gh, int root = 0)\n       \
    \ : n(gh.size()),\n          sz(n, 1),\n          in(n),\n          out(n),\n\
    \          nxt(n),\n          par(n, -1),\n          depth_(n, 0),\n         \
    \ rev(n),\n          dist(n, 0) {\n        nxt[root] = root;\n        dfs_sz(root,\
    \ gh);\n        dfs_hld(root, gh);\n    }\n\n    int idx(int u) const {\n    \
    \    return in[u];\n    }\n\n    int rev_idx(int i) const {\n        return rev[i];\n\
    \    }\n\n    int la(int v, int k) const {\n        while (1) {\n            int\
    \ u = nxt[v];\n            if (in[u] <= in[v] - k) return rev[in[v] - k];\n  \
    \          k -= in[v] - in[u] + 1;\n            v = par[u];\n        }\n    }\n\
    \n    int lca(int u, int v) const {\n        while (nxt[u] != nxt[v]) {\n    \
    \        if (in[u] < in[v]) std::swap(u, v);\n            u = par[nxt[u]];\n \
    \       }\n        return depth_[u] < depth_[v] ? u : v;\n    }\n\n    int jump(int\
    \ s, int t, int i) const {\n        if (i == 0) return s;\n        int l = lca(s,\
    \ t);\n        int d = depth_[s] + depth_[t] - depth_[l] * 2;\n        if (d <\
    \ i) return -1;\n        if (depth_[s] - depth_[l] >= i) return la(s, i);\n  \
    \      i = d - i;\n        return la(t, i);\n    }\n\n    std::vector<int> path(int\
    \ s, int t) const {\n        int l = lca(s, t);\n        std::vector<int> a, b;\n\
    \        for (; s != l; s = par[s]) a.emplace_back(s);\n        for (; t != l;\
    \ t = par[t]) b.emplace_back(t);\n        a.emplace_back(l);\n        std::reverse(b.begin(),\
    \ b.end());\n        a.insert(a.end(), b.begin(), b.end());\n        return a;\n\
    \    }\n\n    int parent(int u) const {\n        return par[u];\n    }\n\n   \
    \ T distance(int u, int v) const {\n        return dist[u] + dist[v] - 2 * dist[lca(u,\
    \ v)];\n    }\n\n    T distance_from_root(int v) const {\n        return dist[v];\n\
    \    }\n\n    T depth(int v) const {\n        return depth_[v];\n    }\n\n   \
    \ bool at_path(int u, int v, int s) const {\n        return distance(u, v) ==\
    \ distance(u, s) + distance(s, v);\n    }\n\n    template <class F>\n    void\
    \ path_noncommutative_query(int u, int v, bool vertex,\n                     \
    \              const F &f) const {\n        int l = lca(u, v);\n        for (auto\
    \ [a, b] : ascend(u, l)) f(a + 1, b);\n        if (vertex) f(in[l], in[l] + 1);\n\
    \        for (auto [a, b] : descend(l, v)) f(a, b + 1);\n    }\n\n    std::vector<std::pair<int,\
    \ int>> path_sections(int u, int v,\n                                        \
    \           bool vertex) const {\n        int l = lca(u, v);\n        std::vector<std::pair<int,\
    \ int>> sections;\n        for (auto [a, b] : ascend(u, l)) sections.emplace_back(a\
    \ + 1, b);\n        if (vertex) sections.emplace_back(in[l], in[l] + 1);\n   \
    \     for (auto [a, b] : descend(l, v)) sections.emplace_back(a, b + 1);\n   \
    \     return sections;\n    }\n\n    template <class F>\n    int max_path(int\
    \ u, int v, bool vertex, F binary_search) const {\n        int prev = -1;\n  \
    \      int l = lca(u, v);\n        for (auto [a, b] : ascend(u, l)) {\n      \
    \      a++;\n            int m = binary_search(a, b);\n            if (m == b)\
    \ {\n                prev = rev[b];\n            } else {\n                return\
    \ (m == a ? prev : rev[m]);\n            }\n        }\n        if (vertex) {\n\
    \            int m = binary_search(in[l], in[l] + 1);\n            if (m == in[l])\
    \ {\n                return prev;\n            } else {\n                prev\
    \ = l;\n            }\n        }\n        for (auto [a, b] : descend(l, v)) {\n\
    \            b++;\n            int m = binary_search(a, b);\n            if (m\
    \ == b) {\n                prev = rev[b - 1];\n            } else {\n        \
    \        return m == a ? prev : rev[m - 1];\n            }\n        }\n      \
    \  return v;\n    }\n\n    template <class F> void subtree_query(int u, bool vertex,\
    \ const F &f) {\n        f(in[u] + int(!vertex), out[u]);\n    }\n\n    const\
    \ std::vector<int> &dfs_order() const {\n        return rev;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> lca_based_auxiliary_tree_dfs_order(\n        std::vector<int> vs) const;\n\
    \n    std::pair<std::vector<int>, Graph<T>> lca_based_auxiliary_tree(\n      \
    \  std::vector<int> vs) const;\n\n  private:\n    int n;\n    std::vector<int>\
    \ sz, in, out, nxt, par, depth_, rev;\n    std::vector<T> dist;\n\n    int num\
    \ = 0;\n};\n\n}  // namespace ebi\n#line 9 \"test/data_structure/Vertex_Add_Path_Sum.test.cpp\"\
    \n\nusing i64 = std::int64_t;\ni64 op(i64 a, i64 b) {\n    return a + b;\n}\n\
    i64 e() {\n    return 0;\n}\n\nint main() {\n    int n, q;\n    std::cin >> n\
    \ >> q;\n    std::vector<i64> a(n);\n    for (int i = 0; i < n; ++i) {\n     \
    \   std::cin >> a[i];\n    }\n    ebi::Graph<int> g(n);\n    g.read_tree(0);\n\
    \    ebi::heavy_light_decomposition hld(g);\n    ebi::segtree<i64, op, e> seg(n);\n\
    \    i64 ans = e();\n    auto set = [&](int u, i64 x) {\n        int idx = hld.idx(u);\n\
    \        seg.set(idx, seg.get(idx) + x);\n    };\n    auto f = [&](int l, int\
    \ r) {\n        if (l <= r)\n            ans = op(ans, seg.prod(l, r));\n    \
    \    else\n            ans = op(ans, seg.prod(r, l));\n    };\n    for (int i\
    \ = 0; i < n; i++) {\n        set(i, a[i]);\n    }\n    while (q--) {\n      \
    \  int flag;\n        std::cin >> flag;\n        if (flag == 0) {\n          \
    \  int p;\n            i64 x;\n            std::cin >> p >> x;\n            set(p,\
    \ x);\n        } else {\n            int u, v;\n            std::cin >> u >> v;\n\
    \            ans = e();\n            hld.path_noncommutative_query(u, v, true,\
    \ f);\n            std::cout << ans << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include <iostream>\n#include <vector>\n\n#include \"../../data_structure/segtree.hpp\"\
    \n#include \"../../graph/base.hpp\"\n#include \"../../tree/heavy_light_decomposition.hpp\"\
    \n\nusing i64 = std::int64_t;\ni64 op(i64 a, i64 b) {\n    return a + b;\n}\n\
    i64 e() {\n    return 0;\n}\n\nint main() {\n    int n, q;\n    std::cin >> n\
    \ >> q;\n    std::vector<i64> a(n);\n    for (int i = 0; i < n; ++i) {\n     \
    \   std::cin >> a[i];\n    }\n    ebi::Graph<int> g(n);\n    g.read_tree(0);\n\
    \    ebi::heavy_light_decomposition hld(g);\n    ebi::segtree<i64, op, e> seg(n);\n\
    \    i64 ans = e();\n    auto set = [&](int u, i64 x) {\n        int idx = hld.idx(u);\n\
    \        seg.set(idx, seg.get(idx) + x);\n    };\n    auto f = [&](int l, int\
    \ r) {\n        if (l <= r)\n            ans = op(ans, seg.prod(l, r));\n    \
    \    else\n            ans = op(ans, seg.prod(r, l));\n    };\n    for (int i\
    \ = 0; i < n; i++) {\n        set(i, a[i]);\n    }\n    while (q--) {\n      \
    \  int flag;\n        std::cin >> flag;\n        if (flag == 0) {\n          \
    \  int p;\n            i64 x;\n            std::cin >> p >> x;\n            set(p,\
    \ x);\n        } else {\n            int u, v;\n            std::cin >> u >> v;\n\
    \            ans = e();\n            hld.path_noncommutative_query(u, v, true,\
    \ f);\n            std::cout << ans << '\\n';\n        }\n    }\n}"
  dependsOn:
  - data_structure/segtree.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  - tree/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: test/data_structure/Vertex_Add_Path_Sum.test.cpp
  requiredBy: []
  timestamp: '2024-03-13 15:52:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Vertex_Add_Path_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Vertex_Add_Path_Sum.test.cpp
- /verify/test/data_structure/Vertex_Add_Path_Sum.test.cpp.html
title: test/data_structure/Vertex_Add_Path_Sum.test.cpp
---
