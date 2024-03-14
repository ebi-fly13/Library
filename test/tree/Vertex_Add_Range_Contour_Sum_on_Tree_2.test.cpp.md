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
  - icon: ':heavy_check_mark:'
    path: tree/centroid_decomposition.hpp
    title: Centroid Decomposition
  - icon: ':heavy_check_mark:'
    path: tree/contour_query_on_weighted_tree.hpp
    title: Contour Query on Tree (Weighted)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree
    links:
    - https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree
  bundledCode: "#line 1 \"test/tree/Vertex_Add_Range_Contour_Sum_on_Tree_2.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree\"\
    \n\n#line 2 \"data_structure/segtree.hpp\"\n\r\n#include <cassert>\r\n#include\
    \ <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class S, S (*op)(S, S), S (*e)()>\
    \ struct segtree {\r\n  private:\r\n    int n;\r\n    int sz;\r\n    std::vector<S>\
    \ data;\r\n\r\n    void update(int i) {\r\n        data[i] = op(data[2 * i], data[2\
    \ * i + 1]);\r\n    }\r\n\r\n  public:\r\n    segtree(int n_) : segtree(std::vector<S>(n_,\
    \ e())) {}\r\n    segtree(const std::vector<S> &v) : n((int)v.size()), sz(1) {\r\
    \n        while (sz < n) sz *= 2;\r\n        data = std::vector<S>(2 * sz, e());\r\
    \n        for (int i = 0; i < n; i++) {\r\n            data[sz + i] = v[i];\r\n\
    \        }\r\n        for (int i = sz - 1; i >= 1; i--) update(i);\r\n    }\r\n\
    \r\n    void set(int p, S x) {\r\n        assert(0 <= p && p < n);\r\n       \
    \ p += sz;\r\n        data[p] = x;\r\n        while (p > 1) {\r\n            p\
    \ >>= 1;\r\n            update(p);\r\n        }\r\n    }\r\n\r\n    S get(int\
    \ p) const {\r\n        assert(0 <= p && p < n);\r\n        return data[p + sz];\r\
    \n    }\r\n\r\n    S prod(int l, int r) const {\r\n        assert(0 <= l && l\
    \ <= r && r <= n);\r\n        S sml = e(), smr = e();\r\n        l += sz;\r\n\
    \        r += sz;\r\n        while (l < r) {\r\n            if (l & 1) sml = op(sml,\
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
    \ ebi\r\n#line 2 \"graph/base.hpp\"\n\n#line 4 \"graph/base.hpp\"\n#include <iostream>\n\
    #include <ranges>\n#line 7 \"graph/base.hpp\"\n\n#line 2 \"data_structure/simple_csr.hpp\"\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 1 \"template/template.hpp\"\
    \n#include <bits/stdc++.h>\n\n#define rep(i, a, n) for (int i = (int)(a); i <\
    \ (int)(n); i++)\n#define rrep(i, a, n) for (int i = ((int)(n)-1); i >= (int)(a);\
    \ i--)\n#define Rep(i, a, n) for (i64 i = (i64)(a); i < (i64)(n); i++)\n#define\
    \ RRep(i, a, n) for (i64 i = ((i64)(n)-i64(1)); i >= (i64)(a); i--)\n#define all(v)\
    \ (v).begin(), (v).end()\n#define rall(v) (v).rbegin(), (v).rend()\n\n#line 2\
    \ \"template/debug_template.hpp\"\n\n#line 4 \"template/debug_template.hpp\"\n\
    \nnamespace ebi {\n\n#ifdef LOCAL\n#define debug(...)                        \
    \                              \\\n    std::cerr << \"LINE: \" << __LINE__ <<\
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
    \n\n#line 5 \"template/utility.hpp\"\n\n#line 8 \"template/utility.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <class T> inline bool chmin(T &a, T b) {\n    if (a > b) {\n\
    \        a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate\
    \ <class T> inline bool chmax(T &a, T b) {\n    if (a < b) {\n        a = b;\n\
    \        return true;\n    }\n    return false;\n}\n\ntemplate <class T> T safe_ceil(T\
    \ a, T b) {\n    if (a % b == 0)\n        return a / b;\n    else if (a >= 0)\n\
    \        return (a / b) + 1;\n    else\n        return -((-a) / b);\n}\n\ntemplate\
    \ <class T> T safe_floor(T a, T b) {\n    if (a % b == 0)\n        return a /\
    \ b;\n    else if (a >= 0)\n        return a / b;\n    else\n        return -((-a)\
    \ / b) - 1;\n}\n\nconstexpr i64 LNF = std::numeric_limits<i64>::max() / 4;\n\n\
    constexpr int INF = std::numeric_limits<int>::max() / 2;\n\nconst std::vector<int>\
    \ dy = {1, 0, -1, 0, 1, 1, -1, -1};\nconst std::vector<int> dx = {0, 1, 0, -1,\
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 2 \"tree/contour_query_on_weighted_tree.hpp\"\
    \n\n#line 7 \"tree/contour_query_on_weighted_tree.hpp\"\n\n#line 2 \"tree/centroid_decomposition.hpp\"\
    \n\n#line 7 \"tree/centroid_decomposition.hpp\"\n\nnamespace ebi {\n\nnamespace\
    \ internal {\n\ntemplate <class F>\nvoid centroid_decomposition_dfs_naive(const\
    \ std::vector<int> &par,\n                                      const std::vector<int>\
    \ &original_vs,\n                                      F f) {\n    const int n\
    \ = (int)par.size();\n    assert(par.size() == original_vs.size());\n    int center\
    \ = -1;\n    std::vector<int> sz(n, 1);\n    for (const int v : std::views::iota(0,\
    \ n) | std::views::reverse) {\n        if (sz[v] >= (n + 1) / 2) {\n         \
    \   center = v;\n            break;\n        }\n        sz[par[v]] += sz[v];\n\
    \    }\n    std::vector<int> color(n, -1);\n    std::vector<int> vs = {center};\n\
    \    color[center] = 0;\n    int c = 1;\n    for (const int v : std::views::iota(1,\
    \ n)) {\n        if (par[v] == center) {\n            vs.emplace_back(v);\n  \
    \          color[v] = c++;\n        }\n    }\n    if (center > 0) {\n        for\
    \ (int v = par[center]; v != -1; v = par[v]) {\n            vs.emplace_back(v);\n\
    \            color[v] = c;\n        }\n        c++;\n    }\n    for (const int\
    \ v : std::views::iota(0, n)) {\n        if (color[v] == -1) {\n            vs.emplace_back(v);\n\
    \            color[v] = color[par[v]];\n        }\n    }\n    std::vector<int>\
    \ index_ptr(c + 1, 0);\n    for (const int v : std::views::iota(0, n)) {\n   \
    \     index_ptr[color[v] + 1]++;\n    }\n    for (const int i : std::views::iota(0,\
    \ c)) {\n        index_ptr[i + 1] += index_ptr[i];\n    }\n    auto counter =\
    \ index_ptr;\n    std::vector<int> ord(n);\n    for (auto v : vs) {\n        ord[counter[color[v]]++]\
    \ = v;\n    }\n    std::vector<int> relabel(n);\n    for (const int v : std::views::iota(0,\
    \ n)) {\n        relabel[ord[v]] = v;\n    }\n    std::vector<int> original_vs2(n);\n\
    \    for (const int v : std::views::iota(0, n)) {\n        original_vs2[relabel[v]]\
    \ = original_vs[v];\n    }\n    std::vector<int> relabel_par(n, -1);\n    for\
    \ (int v : std::views::iota(1, n)) {\n        int a = relabel[v];\n        int\
    \ b = relabel[par[v]];\n        if (a > b) std::swap(a, b);\n        relabel_par[b]\
    \ = a;\n    }\n    f(relabel_par, original_vs2, index_ptr);\n    for (const int\
    \ i : std::views::iota(1, c)) {\n        int l = index_ptr[i], r = index_ptr[i\
    \ + 1];\n        std::vector<int> par1(r - l, -1);\n        std::vector<int> original_vs1(r\
    \ - l, -1);\n        for (int v : std::views::iota(l, r)) {\n            par1[v\
    \ - l] = (relabel_par[v] == 0 ? -1 : relabel_par[v] - l);\n            original_vs1[v\
    \ - l] = original_vs2[v];\n        }\n        centroid_decomposition_dfs_naive(par1,\
    \ original_vs1, f);\n    }\n    return;\n}\n\ntemplate <class F>\nvoid one_third_centroid_decomposition(const\
    \ std::vector<int> &par,\n                                      const std::vector<int>\
    \ &original_vs,\n                                      F f) {\n    const int n\
    \ = (int)par.size();\n    assert(n > 1);\n    if (n == 2) return;\n    int center\
    \ = -1;\n    std::vector<int> sz(n, 1);\n\n    for (const int v : std::views::iota(0,\
    \ n) | std::views::reverse) {\n        if (sz[v] >= (n + 1) / 2) {\n         \
    \   center = v;\n            break;\n        }\n        sz[par[v]] += sz[v];\n\
    \    }\n\n    std::vector<int> color(n, -1);\n    std::vector<int> ord(n, -1);\n\
    \    ord[center] = 0;\n    int t = 1;\n    int red = n - sz[center];\n    for\
    \ (int v = par[center]; v != -1; v = par[v]) {\n        ord[v] = t++;\n      \
    \  color[v] = 0;\n    }\n    for (const int v : std::views::iota(1, n)) {\n  \
    \      if (par[v] == center && 3 * (red + sz[v]) <= 2 * (n - 1)) {\n         \
    \   red += sz[v];\n            ord[v] = t++;\n            color[v] = 0;\n    \
    \    }\n    }\n    for (const int v : std::views::iota(1, n)) {\n        if (v\
    \ != center && color[v] == -1 && color[par[v]] == 0) {\n            ord[v] = t++;\n\
    \            color[v] = 0;\n        }\n    }\n    const int n0 = t - 1;\n    for\
    \ (const int v : std::views::iota(1, n)) {\n        if (v != center && color[v]\
    \ == -1) {\n            ord[v] = t++;\n            color[v] = 1;\n        }\n\
    \    }\n    assert(t == n);\n    const int n1 = n - 1 - n0;\n    std::vector<int>\
    \ par0(n0 + 1, -1), par1(n1 + 1, -1), par2(n, -1);\n    std::vector<int> original_vs0(n0\
    \ + 1), original_vs1(n1 + 1),\n        original_vs2(n);\n    for (const int i\
    \ : std::views::iota(0, n)) {\n        int v = ord[i];\n        original_vs2[v]\
    \ = original_vs[i];\n        if (color[i] != 1) {\n            original_vs0[v]\
    \ = original_vs[i];\n        }\n        if (color[i] != 0) {\n            int\
    \ idx = std::max(v - n0, 0);\n            original_vs1[idx] = original_vs[i];\n\
    \        }\n    }\n    for (const int v : std::views::iota(1, n)) {\n        int\
    \ a = ord[v], b = ord[par[v]];\n        if (a > b) std::swap(a, b);\n        par2[b]\
    \ = a;\n        if (color[v] != 1 && color[par[v]] != 1) {\n            par0[b]\
    \ = a;\n        }\n        if (color[v] != 0 && color[par[v]] != 0) {\n      \
    \      par1[b - n0] = std::max(a - n0, 0);\n        }\n    }\n    f(par2, original_vs2,\
    \ n0, n1);\n    one_third_centroid_decomposition(par0, original_vs0, f);\n   \
    \ one_third_centroid_decomposition(par1, original_vs1, f);\n    return;\n}\n\n\
    template <class F>\nvoid one_third_centroid_decomposition_virtual_real(\n    const\
    \ std::vector<int> &par, const std::vector<int> &original_vs,\n    const std::vector<int>\
    \ &is_real, F f) {\n    const int n = (int)par.size();\n    assert(n > 1);\n \
    \   if (n == 2) {\n        if (is_real[0] && is_real[1]) {\n            f(par,\
    \ original_vs, {0, 1});\n        }\n        return;\n    }\n    int center = -1;\n\
    \    std::vector<int> sz(n, 1);\n\n    for (const int v : std::views::iota(0,\
    \ n) | std::views::reverse) {\n        if (sz[v] >= (n + 1) / 2) {\n         \
    \   center = v;\n            break;\n        }\n        sz[par[v]] += sz[v];\n\
    \    }\n\n    std::vector<int> color(n, -1);\n    std::vector<int> ord(n, -1);\n\
    \    ord[center] = 0;\n    int t = 1;\n    int red = n - sz[center];\n    for\
    \ (int v = par[center]; v != -1; v = par[v]) {\n        ord[v] = t++;\n      \
    \  color[v] = 0;\n    }\n    for (const int v : std::views::iota(1, n)) {\n  \
    \      if (par[v] == center && 3 * (red + sz[v]) <= 2 * (n - 1)) {\n         \
    \   red += sz[v];\n            ord[v] = t++;\n            color[v] = 0;\n    \
    \    }\n    }\n    for (const int v : std::views::iota(1, n)) {\n        if (v\
    \ != center && color[v] == -1 && color[par[v]] == 0) {\n            ord[v] = t++;\n\
    \            color[v] = 0;\n        }\n    }\n    const int n0 = t - 1;\n    for\
    \ (const int v : std::views::iota(1, n)) {\n        if (v != center && color[v]\
    \ == -1) {\n            ord[v] = t++;\n            color[v] = 1;\n        }\n\
    \    }\n    assert(t == n);\n    const int n1 = n - 1 - n0;\n    std::vector<int>\
    \ par0(n0 + 1, -1), par1(n1 + 1, -1), par2(n, -1);\n    std::vector<int> original_vs0(n0\
    \ + 1), original_vs1(n1 + 1),\n        original_vs2(n);\n    std::vector<int>\
    \ is_real0(n0 + 1), is_real1(n1 + 1), is_real2(n);\n    for (const int i : std::views::iota(0,\
    \ n)) {\n        int v = ord[i];\n        original_vs2[v] = original_vs[i];\n\
    \        is_real2[v] = is_real[i];\n        if (color[i] != 1) {\n           \
    \ original_vs0[v] = original_vs[i];\n            is_real0[v] = is_real[i];\n \
    \       }\n        if (color[i] != 0) {\n            int idx = std::max(v - n0,\
    \ 0);\n            original_vs1[idx] = original_vs[i];\n            is_real1[idx]\
    \ = is_real[i];\n        }\n    }\n    for (const int v : std::views::iota(1,\
    \ n)) {\n        int a = ord[v], b = ord[par[v]];\n        if (a > b) std::swap(a,\
    \ b);\n        par2[b] = a;\n        if (color[v] != 1 && color[par[v]] != 1)\
    \ {\n            par0[b] = a;\n        }\n        if (color[v] != 0 && color[par[v]]\
    \ != 0) {\n            par1[b - n0] = std::max(a - n0, 0);\n        }\n    }\n\
    \    if (is_real[center]) {\n        color.assign(n, -1);\n        color[0] =\
    \ 0;\n        for (const int v : std::views::iota(1, n)) {\n            if (is_real2[v])\
    \ color[v] = 1;\n        }\n        f(par2, original_vs2, color);\n        is_real0[0]\
    \ = is_real1[0] = is_real2[0] = 0;\n    }\n    color.assign(n, -1);\n    for (const\
    \ int v : std::views::iota(1, n)) {\n        if (is_real2[v]) {\n            color[v]\
    \ = int(v > n0);\n        }\n    }\n    f(par2, original_vs2, color);\n    one_third_centroid_decomposition_virtual_real(par0,\
    \ original_vs0, is_real0,\n                                                  f);\n\
    \    one_third_centroid_decomposition_virtual_real(par1, original_vs1, is_real1,\n\
    \                                                  f);\n    return;\n}\n\n}  //\
    \ namespace internal\n\ntemplate <int MODE, class T, class F>\nvoid centroid_decomposition(const\
    \ Graph<T> &tree, F f) {\n    int n = (int)tree.size();\n    if (n == 1) return;\n\
    \    std::vector<int> bfs_order(n), par(n, -1);\n    bfs_order[0] = 0;\n    int\
    \ l = 0, r = 1;\n    while (l < r) {\n        int v = bfs_order[l++];\n      \
    \  for (auto e : tree[v]) {\n            int nv = e.to;\n            if (nv ==\
    \ par[v]) continue;\n            bfs_order[r++] = nv;\n            par[nv] = v;\n\
    \        }\n    }\n    assert(l == n && r == n);\n    {\n        std::vector<int>\
    \ relabel(n);\n        for (int i : std::views::iota(0, n)) {\n            relabel[bfs_order[i]]\
    \ = i;\n        }\n        std::vector<int> relabel_par(n, -1);\n        for (int\
    \ i : std::views::iota(1, n)) {\n            relabel_par[relabel[i]] = relabel[par[i]];\n\
    \        }\n        std::swap(par, relabel_par);\n    }\n    static_assert(MODE\
    \ == 0 || MODE == 1 || MODE == 2);\n    if constexpr (MODE == 0) {\n        internal::centroid_decomposition_dfs_naive(par,\
    \ bfs_order, f);\n    } else if constexpr (MODE == 1) {\n        internal::one_third_centroid_decomposition(par,\
    \ bfs_order, f);\n    } else {\n        internal::one_third_centroid_decomposition_virtual_real(\n\
    \            par, bfs_order, std::vector<int>(n, 1), f);\n    }\n}\n\n}  // namespace\
    \ ebi\n#line 10 \"tree/contour_query_on_weighted_tree.hpp\"\n\nnamespace ebi {\n\
    \ntemplate <class T> struct contour_query_on_weighted_tree {\n    contour_query_on_weighted_tree(const\
    \ Graph<T> &tree) : n(int(tree.size())) {\n        int t = 0;\n        labels.resize(n);\n\
    \        range = {0};\n        std::vector<int> rev(n, -1);\n        auto f =\
    \ [&](const std::vector<int> &par, const std::vector<int> &vs,\n             \
    \        const std::vector<int> &color) -> void {\n            int sz = (int)par.size();\n\
    \            std::vector<T> depth(sz, -1);\n            depth[0] = 0;\n      \
    \      for (int i : std::views::iota(0, sz)) {\n                rev[vs[i]] = i;\n\
    \            }\n            for (int i : std::views::iota(0, sz)) {\n        \
    \        int v = vs[i];\n                for (auto e : tree[v]) {\n          \
    \          if (rev[e.to] == -1) continue;\n                    depth[rev[e.to]]\
    \ = depth[rev[v]] + e.cost;\n                }\n                rev[v] = -1;\n\
    \            }\n            std::vector<int> red, blue;\n            for (const\
    \ int v : std::views::iota(0, sz)) {\n                if (color[v] == 0) {\n \
    \                   red.emplace_back(v);\n                } else if (color[v]\
    \ == 1) {\n                    blue.emplace_back(v);\n                } else {\n\
    \                    assert(color[v] == -1);\n                }\n            }\n\
    \            if (red.empty() || blue.empty()) return;\n\n            auto update\
    \ = [&](std::vector<int> &s) -> void {\n                std::sort(s.begin(), s.end(),\
    \ [&](int i, int j) -> bool {\n                    return depth[i] < depth[j];\n\
    \                });\n                for (int i = 0; const int v : s) {\n   \
    \                 dist.emplace_back(depth[v]);\n                    labels[vs[v]].emplace_back(t,\
    \ i, depth[v]);\n                    i++;\n                }\n               \
    \ range.emplace_back(dist.size());\n                t++;\n            };\n   \
    \         update(red);\n            update(blue);\n        };\n        centroid_decomposition<2>(tree,\
    \ f);\n    }\n\n    std::size_t size() {\n        return dist.size();\n    }\n\
    \n    // [0, k)\n    std::vector<std::pair<std::size_t, std::size_t>>\n    get_range_less_than_k_from_v(int\
    \ v, T k) const {\n        std::vector<std::pair<std::size_t, std::size_t>> res;\n\
    \        for (auto [t, i, d] : labels[v]) {\n            t ^= 1;\n           \
    \ std::size_t id_l = range[t];\n            std::size_t id_r =\n             \
    \   std::lower_bound(dist.begin() + range[t],\n                              \
    \   dist.begin() + range[t + 1], k - d) -\n                dist.begin();\n   \
    \         res.emplace_back(id_l, id_r);\n        }\n        return res;\n    }\n\
    \n    // [k, infty)\n    std::vector<std::pair<std::size_t, std::size_t>> get_range_k_or_more_from_v(\n\
    \        int v, T k) const {\n        std::vector<std::pair<std::size_t, std::size_t>>\
    \ res;\n        for (auto [t, i, d] : labels[v]) {\n            t ^= 1;\n    \
    \        std::size_t id_l =\n                std::lower_bound(dist.begin() + range[t],\n\
    \                                 dist.begin() + range[t + 1], k - d) -\n    \
    \            dist.begin();\n            std::size_t id_r = range[t + 1];\n   \
    \         res.emplace_back(id_l, id_r);\n        }\n        return res;\n    }\n\
    \n    // [l, r)\n    std::vector<std::pair<std::size_t, std::size_t>> get_contour_from_vertex(\n\
    \        int v, T l, T r) const {\n        std::vector<std::pair<std::size_t,\
    \ std::size_t>> res;\n        for (auto [t, i, d] : labels[v]) {\n           \
    \ t ^= 1;\n            std::size_t id_l =\n                std::lower_bound(dist.begin()\
    \ + range[t],\n                                 dist.begin() + range[t + 1], l\
    \ - d) -\n                dist.begin();\n            std::size_t id_r =\n    \
    \            std::lower_bound(dist.begin() + range[t],\n                     \
    \            dist.begin() + range[t + 1], r - d) -\n                dist.begin();\n\
    \            res.emplace_back(id_l, id_r);\n        }\n        return res;\n \
    \   }\n\n    std::vector<std::size_t> get_vertex(int v) const {\n        assert(0\
    \ <= v && v < n);\n        std::vector<std::size_t> res;\n        for (auto [t,\
    \ i, _] : labels[v]) {\n            res.emplace_back(range[t] + i);\n        }\n\
    \        return res;\n    }\n\n    std::pair<int, int> sub_range(int i) const\
    \ {\n        return {range[i], range[i + 1]};\n    }\n\n  private:\n    int n;\n\
    \    std::vector<T> dist;\n    std::vector<int> range;\n    std::vector<std::vector<std::tuple<int,\
    \ int, T>>> labels;\n};\n\n}  // namespace ebi\n#line 8 \"test/tree/Vertex_Add_Range_Contour_Sum_on_Tree_2.test.cpp\"\
    \n\nnamespace ebi {\n\ni64 op(i64 a, i64 b) {\n    return a + b;\n}\n\ni64 e()\
    \ {\n    return 0;\n}\n\nvoid main_() {\n    int n, q;\n    std::cin >> n >> q;\n\
    \    std::vector<i64> a(n);\n    std::cin >> a;\n    Graph<int> g(n);\n    g.read_tree(0);\n\
    \    contour_query_on_weighted_tree cq(g);\n    std::vector<i64> data(cq.size(),\
    \ 0);\n    rep(v, 0, n) {\n        for (auto i : cq.get_vertex(v)) {\n       \
    \     data[i] += a[v];\n        }\n    }\n    segtree<i64, op, e> seg(data);\n\
    \    while (q--) {\n        int type;\n        std::cin >> type;\n        if (type\
    \ == 0) {\n            int p;\n            i64 x;\n            std::cin >> p >>\
    \ x;\n            a[p] += x;\n            for (auto i : cq.get_vertex(p)) {\n\
    \                seg.set(i, seg.get(i) + x);\n            }\n        } else {\n\
    \            int p, l, r;\n            std::cin >> p >> l >> r;\n            i64\
    \ ans = 0;\n            if (l == 0) ans += a[p];\n            for (auto [il, ir]\
    \ : cq.get_contour_from_vertex(p, l, r)) {\n                ans += seg.prod(il,\
    \ ir);\n            }\n            std::cout << ans << '\\n';\n        }\n   \
    \ }\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t\
    \ = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n    }\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree\"\
    \n\n#include \"../../data_structure/segtree.hpp\"\n#include \"../../graph/base.hpp\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../tree/contour_query_on_weighted_tree.hpp\"\
    \n\nnamespace ebi {\n\ni64 op(i64 a, i64 b) {\n    return a + b;\n}\n\ni64 e()\
    \ {\n    return 0;\n}\n\nvoid main_() {\n    int n, q;\n    std::cin >> n >> q;\n\
    \    std::vector<i64> a(n);\n    std::cin >> a;\n    Graph<int> g(n);\n    g.read_tree(0);\n\
    \    contour_query_on_weighted_tree cq(g);\n    std::vector<i64> data(cq.size(),\
    \ 0);\n    rep(v, 0, n) {\n        for (auto i : cq.get_vertex(v)) {\n       \
    \     data[i] += a[v];\n        }\n    }\n    segtree<i64, op, e> seg(data);\n\
    \    while (q--) {\n        int type;\n        std::cin >> type;\n        if (type\
    \ == 0) {\n            int p;\n            i64 x;\n            std::cin >> p >>\
    \ x;\n            a[p] += x;\n            for (auto i : cq.get_vertex(p)) {\n\
    \                seg.set(i, seg.get(i) + x);\n            }\n        } else {\n\
    \            int p, l, r;\n            std::cin >> p >> l >> r;\n            i64\
    \ ans = 0;\n            if (l == 0) ans += a[p];\n            for (auto [il, ir]\
    \ : cq.get_contour_from_vertex(p, l, r)) {\n                ans += seg.prod(il,\
    \ ir);\n            }\n            std::cout << ans << '\\n';\n        }\n   \
    \ }\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t\
    \ = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n    }\n\
    \    return 0;\n}"
  dependsOn:
  - data_structure/segtree.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  - tree/contour_query_on_weighted_tree.hpp
  - tree/centroid_decomposition.hpp
  isVerificationFile: true
  path: test/tree/Vertex_Add_Range_Contour_Sum_on_Tree_2.test.cpp
  requiredBy: []
  timestamp: '2024-03-13 15:52:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/Vertex_Add_Range_Contour_Sum_on_Tree_2.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Vertex_Add_Range_Contour_Sum_on_Tree_2.test.cpp
- /verify/test/tree/Vertex_Add_Range_Contour_Sum_on_Tree_2.test.cpp.html
title: test/tree/Vertex_Add_Range_Contour_Sum_on_Tree_2.test.cpp
---
