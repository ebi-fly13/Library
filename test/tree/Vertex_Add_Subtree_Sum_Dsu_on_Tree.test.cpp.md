---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: fenwick tree
  - icon: ':question:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':question:'
    path: graph/base.hpp
    title: Graph (CSR format)
  - icon: ':question:'
    path: template/debug_template.hpp
    title: template/debug_template.hpp
  - icon: ':question:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  - icon: ':question:'
    path: template/io.hpp
    title: template/io.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/utility.hpp
    title: template/utility.hpp
  - icon: ':question:'
    path: tree/dsu_on_tree.hpp
    title: tree/dsu_on_tree.hpp
  - icon: ':question:'
    path: tree/heavy_light_decomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/tree/Vertex_Add_Subtree_Sum_Dsu_on_Tree.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n\
    #line 2 \"data_structure/fenwick_tree.hpp\"\n\r\n#include <cassert>\r\n#include\
    \ <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class T> struct fenwick_tree\
    \ {\r\n  private:\r\n    int n;\r\n    std::vector<T> data;\r\n\r\n  public:\r\
    \n    fenwick_tree(int _n) : n(_n), data(std::vector<T>(_n + 1, T(0))) {}\r\n\r\
    \n    void add(int i, T val) {\r\n        i++;\r\n        for (int x = i; x <=\
    \ n; x += x & -x) {\r\n            data[x] += val;\r\n        }\r\n    }\r\n\r\
    \n    T prefix_sum(int i) const {\r\n        assert(0 <= i && i <= n);\r\n   \
    \     T ret = 0;\r\n        for (int x = i; x > 0; x -= x & -x) {\r\n        \
    \    ret += data[x];\r\n        }\r\n        return ret;\r\n    }\r\n\r\n    T\
    \ sum(int l, int r) const {\r\n        return prefix_sum(r) - prefix_sum(l);\r\
    \n    }\r\n\r\n    T all_sum() const {\r\n        return prefix_sum(n);\r\n  \
    \  }\r\n\r\n    // prefix_sum(x) >= key \u3068\u306A\u308B\u6700\u5C0F\u306Ex\u3092\
    \u8FD4\u3059\u95A2\u6570 O(log N)\r\n    int lower_bound(T key) {\r\n        if\
    \ (key <= 0) return 0;\r\n        int x = 0;\r\n        int max = 1;\r\n     \
    \   while ((max << 1) <= n) max <<= 1;\r\n        for (int k = max; k > 0; k >>=\
    \ 1) {\r\n            if (x + k <= n && data[x + k] < key) {\r\n             \
    \   x += k;\r\n                key -= data[x];\r\n            }\r\n        }\r\
    \n        return x + 1;\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n#line 1 \"\
    template/template.hpp\"\n#include <bits/stdc++.h>\n\n#define rep(i, a, n) for\
    \ (int i = (int)(a); i < (int)(n); i++)\n#define rrep(i, a, n) for (int i = ((int)(n)-1);\
    \ i >= (int)(a); i--)\n#define Rep(i, a, n) for (i64 i = (i64)(a); i < (i64)(n);\
    \ i++)\n#define RRep(i, a, n) for (i64 i = ((i64)(n)-i64(1)); i >= (i64)(a); i--)\n\
    #define all(v) (v).begin(), (v).end()\n#define rall(v) (v).rbegin(), (v).rend()\n\
    \n#line 2 \"template/debug_template.hpp\"\n\n#line 4 \"template/debug_template.hpp\"\
    \n\nnamespace ebi {\n\n#ifdef LOCAL\n#define debug(...)                      \
    \                                \\\n    std::cerr << \"LINE: \" << __LINE__ <<\
    \ \"  [\" << #__VA_ARGS__ << \"]:\", \\\n        debug_out(__VA_ARGS__)\n#else\n\
    #define debug(...)\n#endif\n\nvoid debug_out() {\n    std::cerr << std::endl;\n\
    }\n\ntemplate <typename Head, typename... Tail> void debug_out(Head h, Tail...\
    \ t) {\n    std::cerr << \" \" << h;\n    if (sizeof...(t) > 0) std::cerr << \"\
    \ :\";\n    debug_out(t...);\n}\n\n}  // namespace ebi\n#line 2 \"template/int_alias.hpp\"\
    \n\n#line 4 \"template/int_alias.hpp\"\n\nnamespace ebi {\n\nusing ld = long double;\n\
    using std::size_t;\nusing i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16\
    \ = std::int16_t;\nusing u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing\
    \ u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n\n}  // namespace ebi\n#line\
    \ 2 \"template/io.hpp\"\n\n#line 5 \"template/io.hpp\"\n#include <optional>\n\
    #line 7 \"template/io.hpp\"\n\nnamespace ebi {\n\ntemplate <typename T1, typename\
    \ T2>\nstd::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &pa)\
    \ {\n    return os << pa.first << \" \" << pa.second;\n}\n\ntemplate <typename\
    \ T1, typename T2>\nstd::istream &operator>>(std::istream &os, std::pair<T1, T2>\
    \ &pa) {\n    return os >> pa.first >> pa.second;\n}\n\ntemplate <typename T>\n\
    std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {\n    for\
    \ (std::size_t i = 0; i < vec.size(); i++)\n        os << vec[i] << (i + 1 ==\
    \ vec.size() ? \"\" : \" \");\n    return os;\n}\n\ntemplate <typename T>\nstd::istream\
    \ &operator>>(std::istream &os, std::vector<T> &vec) {\n    for (T &e : vec) std::cin\
    \ >> e;\n    return os;\n}\n\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream\
    \ &os, const std::optional<T> &opt) {\n    if (opt) {\n        os << opt.value();\n\
    \    } else {\n        os << \"invalid value\";\n    }\n    return os;\n}\n\n\
    void fast_io() {\n    std::cout << std::fixed << std::setprecision(15);\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n}\n\n}  // namespace ebi\n#line 2 \"template/utility.hpp\"\
    \n\n#line 5 \"template/utility.hpp\"\n\n#line 2 \"graph/base.hpp\"\n\n#line 5\
    \ \"graph/base.hpp\"\n#include <ranges>\n#line 7 \"graph/base.hpp\"\n\n#line 2\
    \ \"data_structure/simple_csr.hpp\"\n\n#line 6 \"data_structure/simple_csr.hpp\"\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 8 \"template/utility.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> inline bool chmin(T &a, T b) {\n   \
    \ if (a > b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\n\ntemplate <class T> inline bool chmax(T &a, T b) {\n    if (a < b) {\n   \
    \     a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate <class\
    \ T> T safe_ceil(T a, T b) {\n    if (a % b == 0)\n        return a / b;\n   \
    \ else if (a >= 0)\n        return (a / b) + 1;\n    else\n        return -((-a)\
    \ / b);\n}\n\ntemplate <class T> T safe_floor(T a, T b) {\n    if (a % b == 0)\n\
    \        return a / b;\n    else if (a >= 0)\n        return a / b;\n    else\n\
    \        return -((-a) / b) - 1;\n}\n\nconstexpr i64 LNF = std::numeric_limits<i64>::max()\
    \ / 4;\n\nconstexpr int INF = std::numeric_limits<int>::max() / 2;\n\nconst std::vector<int>\
    \ dy = {1, 0, -1, 0, 1, 1, -1, -1};\nconst std::vector<int> dx = {0, 1, 0, -1,\
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 2 \"tree/dsu_on_tree.hpp\"\n\n\
    #line 2 \"tree/heavy_light_decomposition.hpp\"\n\n#line 6 \"tree/heavy_light_decomposition.hpp\"\
    \n\n#line 8 \"tree/heavy_light_decomposition.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class T> struct heavy_light_decomposition {\n  private:\n    void dfs_sz(int\
    \ v) {\n        for (auto &e : g[v]) {\n            if (e.to == par[v]) continue;\n\
    \            par[e.to] = v;\n            depth_[e.to] = depth_[v] + 1;\n     \
    \       dist[e.to] = dist[v] + e.cost;\n            dfs_sz(e.to);\n          \
    \  sz[v] += sz[e.to];\n            if (sz[e.to] > sz[g[v][0].to] || g[v][0].to\
    \ == par[v])\n                std::swap(e, g[v][0]);\n        }\n    }\n\n   \
    \ void dfs_hld(int v) {\n        in[v] = num++;\n        rev[in[v]] = v;\n   \
    \     for (auto e : g[v]) {\n            if (e.to == par[v]) continue;\n     \
    \       nxt[e.to] = (e.to == g[v][0].to ? nxt[v] : e.to);\n            dfs_hld(e.to);\n\
    \        }\n        out[v] = num;\n    }\n\n    // [u, v) \u30D1\u30B9\u306E\u53D6\
    \u5F97 (v \u306F u \u306E\u7956\u5148)\n    std::vector<std::pair<int, int>> ascend(int\
    \ u, int v) const {\n        std::vector<std::pair<int, int>> res;\n        while\
    \ (nxt[u] != nxt[v]) {\n            res.emplace_back(in[u], in[nxt[u]]);\n   \
    \         u = par[nxt[u]];\n        }\n        if (u != v) res.emplace_back(in[u],\
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
    \ dist;\n\n    int num = 0;\n};\n\n}  // namespace ebi\n#line 4 \"tree/dsu_on_tree.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T>\ntemplate <class ADD, class QUERY, class\
    \ CLEAR, class RESET>\nvoid heavy_light_decomposition<T>::dsu_on_tree(const ADD\
    \ &add,\n                                               const QUERY &query,\n\
    \                                               const CLEAR &clear,\n        \
    \                                       const RESET &reset) const {\n    auto\
    \ dfs = [&](auto &&self, int v) -> void {\n        for (auto e : g[v].next())\
    \ {\n            if (e.to == parent(v)) continue;\n            self(self, e.to);\n\
    \        }\n        if (sz[v] != 1) {\n            self(self, g[v][0].to);\n \
    \           for (int i = out[g[v][0].to]; i < out[v]; i++) {\n               \
    \ add(rev[i]);\n            }\n        }\n        add(v);\n        query(v);\n\
    \        if (nxt[v] == v) {\n            for (int i = in[v]; i < out[v]; i++)\
    \ {\n                clear(rev[i]);\n            }\n            reset();\n   \
    \     }\n        return;\n    };\n    dfs(dfs, root);\n    return;\n}\n\n}  //\
    \ namespace ebi\n#line 7 \"test/tree/Vertex_Add_Subtree_Sum_Dsu_on_Tree.test.cpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    int n, q;\n    std::cin >> n >> q;\n\
    \    std::vector<i64> a(n);\n    std::cin >> a;\n    Graph<int> g(n);\n    g.read_parents(0);\n\
    \    std::vector<std::tuple<int, int, i64>> qs(q);\n    std::vector q1(n, std::vector<int>()),\
    \ q2(n, std::vector<int>());\n    for (int i = 0; auto &[t, u, x] : qs) {\n  \
    \      std::cin >> t >> u;\n        if (t == 0) {\n            q1[u].emplace_back(i);\n\
    \            std::cin >> x;\n        } else {\n            q2[u].emplace_back(i);\n\
    \        }\n        i++;\n    }\n    i64 sum = 0;\n    std::vector<i64> ans(q,\
    \ -1);\n    fenwick_tree<i64> fw(q);\n    auto add = [&](int v) -> void {\n  \
    \      sum += a[v];\n        for (auto i : q1[v]) {\n            i64 x = std::get<2>(qs[i]);\n\
    \            fw.add(i, x);\n        }\n    };\n    auto query = [&](int v) ->\
    \ void {\n        for (auto i : q2[v]) {\n            ans[i] = sum + fw.prefix_sum(i);\n\
    \        }\n    };\n    auto clear = [&](int v) -> void {\n        sum -= a[v];\n\
    \        for (auto i : q1[v]) {\n            i64 x = std::get<2>(qs[i]);\n   \
    \         fw.add(i, -x);\n        }\n    };\n    auto reset = [&]() -> void {\n\
    \n    };\n    heavy_light_decomposition hld(g);\n    hld.dsu_on_tree(add, query,\
    \ clear, reset);\n    rep(i, 0, q) {\n        if (ans[i] == -1) continue;\n  \
    \      std::cout << ans[i] << '\\n';\n    }\n}\n\n}  // namespace ebi\n\nint main()\
    \ {\n    ebi::fast_io();\n    int t = 1;\n    // std::cin >> t;\n    while (t--)\
    \ {\n        ebi::main_();\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../../data_structure/fenwick_tree.hpp\"\n#include \"../../template/template.hpp\"\
    \n#include \"../../tree/dsu_on_tree.hpp\"\n#include \"../../tree/heavy_light_decomposition.hpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    int n, q;\n    std::cin >> n >> q;\n\
    \    std::vector<i64> a(n);\n    std::cin >> a;\n    Graph<int> g(n);\n    g.read_parents(0);\n\
    \    std::vector<std::tuple<int, int, i64>> qs(q);\n    std::vector q1(n, std::vector<int>()),\
    \ q2(n, std::vector<int>());\n    for (int i = 0; auto &[t, u, x] : qs) {\n  \
    \      std::cin >> t >> u;\n        if (t == 0) {\n            q1[u].emplace_back(i);\n\
    \            std::cin >> x;\n        } else {\n            q2[u].emplace_back(i);\n\
    \        }\n        i++;\n    }\n    i64 sum = 0;\n    std::vector<i64> ans(q,\
    \ -1);\n    fenwick_tree<i64> fw(q);\n    auto add = [&](int v) -> void {\n  \
    \      sum += a[v];\n        for (auto i : q1[v]) {\n            i64 x = std::get<2>(qs[i]);\n\
    \            fw.add(i, x);\n        }\n    };\n    auto query = [&](int v) ->\
    \ void {\n        for (auto i : q2[v]) {\n            ans[i] = sum + fw.prefix_sum(i);\n\
    \        }\n    };\n    auto clear = [&](int v) -> void {\n        sum -= a[v];\n\
    \        for (auto i : q1[v]) {\n            i64 x = std::get<2>(qs[i]);\n   \
    \         fw.add(i, -x);\n        }\n    };\n    auto reset = [&]() -> void {\n\
    \n    };\n    heavy_light_decomposition hld(g);\n    hld.dsu_on_tree(add, query,\
    \ clear, reset);\n    rep(i, 0, q) {\n        if (ans[i] == -1) continue;\n  \
    \      std::cout << ans[i] << '\\n';\n    }\n}\n\n}  // namespace ebi\n\nint main()\
    \ {\n    ebi::fast_io();\n    int t = 1;\n    // std::cin >> t;\n    while (t--)\
    \ {\n        ebi::main_();\n    }\n    return 0;\n}"
  dependsOn:
  - data_structure/fenwick_tree.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  - tree/dsu_on_tree.hpp
  - tree/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: test/tree/Vertex_Add_Subtree_Sum_Dsu_on_Tree.test.cpp
  requiredBy: []
  timestamp: '2024-06-18 15:22:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/Vertex_Add_Subtree_Sum_Dsu_on_Tree.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Vertex_Add_Subtree_Sum_Dsu_on_Tree.test.cpp
- /verify/test/tree/Vertex_Add_Subtree_Sum_Dsu_on_Tree.test.cpp.html
title: test/tree/Vertex_Add_Subtree_Sum_Dsu_on_Tree.test.cpp
---
