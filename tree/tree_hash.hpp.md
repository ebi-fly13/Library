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
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint61.hpp
    title: modint/modint61.hpp
  - icon: ':heavy_check_mark:'
    path: tree/centroid.hpp
    title: tree/centroid.hpp
  - icon: ':question:'
    path: tree/heavy_light_decomposition.hpp
    title: Heavy Light Decomposition
  - icon: ':heavy_check_mark:'
    path: tree/rerooting.hpp
    title: Rerooting DP
  - icon: ':heavy_check_mark:'
    path: tree/subtree_hash.hpp
    title: Subtree Hash
  - icon: ':heavy_check_mark:'
    path: utility/random_number_generator.hpp
    title: Random Number Generator
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2821.test.cpp
    title: test/aoj/aoj_2821.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/tree_hash.hpp\"\n\n#include <cassert>\n\n#line 2 \"\
    graph/base.hpp\"\n\n#line 4 \"graph/base.hpp\"\n#include <iostream>\n#include\
    \ <ranges>\n#include <vector>\n\n#line 2 \"data_structure/simple_csr.hpp\"\n\n\
    #line 4 \"data_structure/simple_csr.hpp\"\n#include <utility>\n#line 6 \"data_structure/simple_csr.hpp\"\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 2 \"tree/centroid.hpp\"\
    \n\n#line 4 \"tree/centroid.hpp\"\n\nnamespace ebi {\n\ntemplate <class T> std::vector<int>\
    \ get_centroid(const Graph<T> &tree) {\n    int n = tree.node_number();\n    std::vector<int>\
    \ sz(n, 1);\n    std::vector<int> centroid;\n    auto dfs = [&](auto &&self, int\
    \ v, int par = -1) -> void {\n        bool is_centroid = true;\n        for (auto\
    \ e : tree[v]) {\n            if (e.to == par) continue;\n            self(self,\
    \ e.to, v);\n            if (sz[e.to] > n / 2) is_centroid = false;\n        \
    \    sz[v] += sz[e.to];\n        }\n        if (n - sz[v] > n / 2) is_centroid\
    \ = false;\n        if (is_centroid) centroid.emplace_back(v);\n    };\n    dfs(dfs,\
    \ 0);\n    return centroid;\n}\n\n}  // namespace ebi\n#line 2 \"tree/subtree_hash.hpp\"\
    \n\n#line 4 \"tree/subtree_hash.hpp\"\n\n#line 2 \"modint/modint61.hpp\"\n\n#line\
    \ 4 \"modint/modint61.hpp\"\n#include <cstdint>\n#line 6 \"modint/modint61.hpp\"\
    \n\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#line 6 \"modint/base.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b)\
    \ {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n\
    \    a.pow(std::declval<long long>());\n    T::mod();\n};\n\ntemplate <Modint\
    \ mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long long x;\n\
    \    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <Modint mint>\nstd::ostream\
    \ &operator<<(std::ostream &os, const mint &a) {\n    return os << a.val();\n\
    }\n\n}  // namespace ebi\n#line 8 \"modint/modint61.hpp\"\n\nnamespace ebi {\n\
    \nstruct modint61 {\n  private:\n    using mint = modint61;\n    using u64 = std::uint64_t;\n\
    \    constexpr static u64 m = (1ull << 61) - 1;\n    constexpr static u64 MASK31\
    \ = (1ull << 31) - 1;\n    constexpr static u64 MASK30 = (1ull << 30) - 1;\n\n\
    \  public:\n    constexpr static u64 mod() {\n        return m;\n    }\n\n   \
    \ constexpr modint61() : _v(0) {}\n\n    constexpr modint61(long long v) {\n \
    \       v %= (long long)umod();\n        if (v < 0) v += (long long)umod();\n\
    \        _v = u64(v);\n    }\n\n    constexpr u64 val() const {\n        return\
    \ _v;\n    }\n\n    constexpr u64 value() const {\n        return val();\n   \
    \ }\n\n    constexpr mint &operator++() {\n        _v++;\n        if (_v == umod())\
    \ _v = 0;\n        return *this;\n    }\n\n    constexpr mint &operator--() {\n\
    \        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n   \
    \ }\n\n    constexpr mint &operator+=(const mint &rhs) {\n        _v += rhs._v;\n\
    \        _v = safe_mod(_v);\n        return *this;\n    }\n\n    constexpr mint\
    \ &operator-=(const mint &rhs) {\n        if (_v < rhs._v) _v += umod();\n   \
    \     assert(_v >= rhs._v);\n        _v -= rhs._v;\n        return *this;\n  \
    \  }\n\n    constexpr mint &operator*=(const mint &rhs) {\n        u64 au = _v\
    \ >> 31, ad = _v & MASK31;\n        u64 bu = rhs._v >> 31, bd = rhs._v & MASK31;\n\
    \        u64 mid = ad * bu + au * bd;\n        u64 midu = mid >> 30;\n       \
    \ u64 midd = mid & MASK30;\n        _v = (au * bu * 2 + midu + (midd << 31) +\
    \ ad * bd);\n        _v = safe_mod(_v);\n        return *this;\n    }\n\n    constexpr\
    \ mint &operator/=(const mint &rhs) {\n        return *this *= rhs.inv();\n  \
    \  }\n\n    constexpr mint pow(long long n) const {\n        assert(0 <= n);\n\
    \        mint x = *this, res = 1;\n        while (n) {\n            if (n & 1)\
    \ res *= x;\n            x *= x;\n            n >>= 1;\n        }\n        return\
    \ res;\n    }\n\n    constexpr mint inv() const {\n        assert(_v);\n     \
    \   return pow(umod() - 2);\n    }\n\n    friend mint operator+(const mint &lhs,\
    \ const mint &rhs) {\n        return mint(lhs) += rhs;\n    }\n    friend mint\
    \ operator-(const mint &lhs, const mint &rhs) {\n        return mint(lhs) -= rhs;\n\
    \    }\n    friend mint operator*(const mint &lhs, const mint &rhs) {\n      \
    \  return mint(lhs) *= rhs;\n    }\n    friend mint operator/(const mint &lhs,\
    \ const mint &rhs) {\n        return mint(lhs) /= rhs;\n    }\n    friend bool\
    \ operator==(const mint &lhs, const mint &rhs) {\n        return lhs.val() ==\
    \ rhs.val();\n    }\n    friend bool operator!=(const mint &lhs, const mint &rhs)\
    \ {\n        return !(lhs == rhs);\n    }\n    friend bool operator<(const mint\
    \ &lhs, const mint &rhs) {\n        return lhs._v < rhs._v;\n    }\n    friend\
    \ bool operator>(const mint &lhs, const mint &rhs) {\n        return rhs < lhs;\n\
    \    }\n\n  private:\n    u64 _v = 0;\n\n    constexpr static u64 umod() {\n \
    \       return m;\n    }\n\n    constexpr u64 safe_mod(const u64 &a) {\n     \
    \   u64 au = a >> 61;\n        u64 ad = a & umod();\n        u64 res = au + ad;\n\
    \        if (res >= umod()) res -= umod();\n        return res;\n    }\n};\n\n\
    }  // namespace ebi\n#line 2 \"tree/rerooting.hpp\"\n\n#line 6 \"tree/rerooting.hpp\"\
    \n\n#line 2 \"tree/heavy_light_decomposition.hpp\"\n\n#include <algorithm>\n#line\
    \ 6 \"tree/heavy_light_decomposition.hpp\"\n\n#line 8 \"tree/heavy_light_decomposition.hpp\"\
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
    \ dist;\n\n    int num = 0;\n};\n\n}  // namespace ebi\n#line 9 \"tree/rerooting.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T, class V> struct rerooting_dp {\n   \
    \ template <class MERGE, class PUT_EDGE, class PUT_ROOT>\n    rerooting_dp(const\
    \ Graph<T> &tree, const V e, const MERGE &merge,\n                 const PUT_EDGE\
    \ &put_edge, const PUT_ROOT &put_root)\n        : n(tree.node_number()),\n   \
    \       hld(tree),\n          full_tree_dp(n, e),\n          child_dp(n, e),\n\
    \          parent_dp(n, e) {\n        auto dfs_sub = [&](auto &&self, int v, int\
    \ par = -1) -> void {\n            for (const auto &edge : tree[v]) {\n      \
    \          if (edge.to == par) continue;\n                self(self, edge.to,\
    \ v);\n                child_dp[v] =\n                    merge(child_dp[v], put_edge(edge,\
    \ child_dp[edge.to]));\n            }\n            child_dp[v] = put_root(v, child_dp[v]);\n\
    \        };\n        dfs_sub(dfs_sub, 0);\n        auto dfs_all = [&](auto &&self,\
    \ int v, int par = -1) -> void {\n            std::vector<int> ch;\n         \
    \   std::vector<V> dp;\n            V ret = e;\n            for (const auto &edge\
    \ : tree[v]) {\n                if (edge.to == par) {\n                    ret\
    \ = put_edge(edge, parent_dp[v]);\n                } else {\n                \
    \    ch.emplace_back(edge.to);\n                    dp.emplace_back(put_edge(edge,\
    \ child_dp[edge.to]));\n                }\n            }\n            int sz =\
    \ (int)ch.size();\n            if (ch.empty()) {\n                full_tree_dp[v]\
    \ = put_root(v, ret);\n                return;\n            }\n            std::vector<V>\
    \ lcum(sz, ret);\n            for (int i = 0; i < sz - 1; i++) {\n           \
    \     lcum[i + 1] = merge(lcum[i], dp[i]);\n            }\n            V rcum\
    \ = e;\n            for (int i = sz - 1; i >= 0; i--) {\n                parent_dp[ch[i]]\
    \ = put_root(v, merge(lcum[i], rcum));\n                rcum = merge(rcum, dp[i]);\n\
    \            }\n            for (int i = 0; i < sz; i++) {\n                self(self,\
    \ ch[i], v);\n            }\n            full_tree_dp[v] = put_root(v, merge(rcum,\
    \ ret));\n        };\n        dfs_all(dfs_all, 0);\n    }\n\n    V get(int v)\
    \ const {\n        return get(v, v);\n    }\n\n    V get(int v, int root) const\
    \ {\n        if (root == v) return full_tree_dp[v];\n        if (!hld.is_subtree(v,\
    \ root)) {\n            return child_dp[v];\n        }\n        return parent_dp[hld.jump(v,\
    \ root, 1)];\n    }\n\n    std::vector<V> get_full_dp() const {\n        return\
    \ full_tree_dp;\n    }\n\n  private:\n    int n;\n    heavy_light_decomposition<T>\
    \ hld;\n    std::vector<V> full_tree_dp;\n    std::vector<V> child_dp;\n    std::vector<V>\
    \ parent_dp;\n};\n\n}  // namespace ebi\n#line 2 \"utility/random_number_generator.hpp\"\
    \n\r\n#line 5 \"utility/random_number_generator.hpp\"\n#include <numeric>\r\n\
    #include <random>\r\n#line 8 \"utility/random_number_generator.hpp\"\n\r\nnamespace\
    \ ebi {\r\n\r\nstruct random_number_generator {\r\n    random_number_generator(int\
    \ seed = -1) {\r\n        if (seed < 0) seed = rnd();\r\n        mt.seed(seed);\r\
    \n    }\r\n\r\n    void set_seed(int seed) {\r\n        mt.seed(seed);\r\n   \
    \ }\r\n\r\n    template <class T> T get(T a, T b) {\r\n        std::uniform_int_distribution<T>\
    \ dist(a, b - 1);\r\n        return dist(mt);\r\n    }\r\n\r\n    std::vector<int>\
    \ get_permutation(int n) {\r\n        std::vector<int> p(n);\r\n        std::iota(p.begin(),\
    \ p.end(), 0);\r\n        std::shuffle(p.begin(), p.end(), mt);\r\n        return\
    \ p;\r\n    }\r\n\r\n  private:\r\n    std::mt19937_64 mt;\r\n    std::random_device\
    \ rnd;\r\n};\r\n\r\n}  // namespace ebi\n#line 9 \"tree/subtree_hash.hpp\"\n\n\
    namespace ebi {\n\ntemplate <class T> struct subtree_hash {\n  private:\n    using\
    \ V = std::pair<int, modint61>;\n\n    static modint61 hash_base(int k) {\n  \
    \      static std::vector<modint61> r;\n        static random_number_generator\
    \ rng;\n        while ((int)r.size() <= k) {\n            r.emplace_back(rng.get<std::uint64_t>(0,\
    \ modint61::mod()));\n        }\n        return r[k];\n    }\n\n    static auto\
    \ merge() {\n        return [&](V a, V b) -> V {\n            return {std::max(a.first,\
    \ b.first), a.second * b.second};\n        };\n    }\n\n    static auto put_edge()\
    \ {\n        return [&](Graph<T>::edge_type, V a) -> V {\n            return {a.first\
    \ + 1, a.second};\n        };\n    }\n\n    static auto put_root() {\n       \
    \ return [&](int, V a) -> V {\n            return {a.first, a.second + hash_base(a.first)};\n\
    \        };\n    }\n\n  public:\n    subtree_hash(const Graph<T> &tree)\n    \
    \    : dp(tree, V{0, 1}, merge(), put_edge(), put_root()) {}\n\n    modint61 get(int\
    \ v) const {\n        return dp.get(v).second;\n    }\n\n    modint61 get(int\
    \ v, int root) {\n        return dp.get(v, root).second;\n    }\n\n  private:\n\
    \    rerooting_dp<T, V> dp;\n};\n\n}  // namespace ebi\n#line 8 \"tree/tree_hash.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> std::vector<modint61> tree_hash(const\
    \ Graph<T> &tree) {\n    subtree_hash hash(tree);\n    auto centroid = get_centroid(tree);\n\
    \    if (centroid.size() == 1) centroid.emplace_back(centroid[0]);\n    assert(centroid.size()\
    \ == 2);\n    std::vector<modint61> hs;\n    for (auto c : centroid) {\n     \
    \   hs.emplace_back(hash.get(c));\n    }\n    if (hs[0] > hs[1]) std::swap(hs[0],\
    \ hs[1]);\n    return hs;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n\n#include \"../graph/base.hpp\"\n#include\
    \ \"../tree/centroid.hpp\"\n#include \"../tree/subtree_hash.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <class T> std::vector<modint61> tree_hash(const Graph<T> &tree)\
    \ {\n    subtree_hash hash(tree);\n    auto centroid = get_centroid(tree);\n \
    \   if (centroid.size() == 1) centroid.emplace_back(centroid[0]);\n    assert(centroid.size()\
    \ == 2);\n    std::vector<modint61> hs;\n    for (auto c : centroid) {\n     \
    \   hs.emplace_back(hash.get(c));\n    }\n    if (hs[0] > hs[1]) std::swap(hs[0],\
    \ hs[1]);\n    return hs;\n}\n\n}  // namespace ebi"
  dependsOn:
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  - tree/centroid.hpp
  - tree/subtree_hash.hpp
  - modint/modint61.hpp
  - modint/base.hpp
  - tree/rerooting.hpp
  - tree/heavy_light_decomposition.hpp
  - utility/random_number_generator.hpp
  isVerificationFile: false
  path: tree/tree_hash.hpp
  requiredBy: []
  timestamp: '2025-03-18 01:14:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_2821.test.cpp
documentation_of: tree/tree_hash.hpp
layout: document
redirect_from:
- /library/tree/tree_hash.hpp
- /library/tree/tree_hash.hpp.html
title: tree/tree_hash.hpp
---
