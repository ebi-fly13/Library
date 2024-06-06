---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: "\u4FBF\u5229\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':heavy_check_mark:'
    path: template/debug_template.hpp
    title: template/debug_template.hpp
  - icon: ':heavy_check_mark:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  - icon: ':heavy_check_mark:'
    path: template/io.hpp
    title: template/io.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/utility.hpp
    title: template/utility.hpp
  - icon: ':heavy_check_mark:'
    path: tree/dp_on_static_top_tree.hpp
    title: DP on Static Top Tree
  - icon: ':heavy_check_mark:'
    path: tree/static_top_tree.hpp
    title: Static Top Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
    links:
    - https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
  bundledCode: "#line 1 \"test/tree/Point_Set_Tree_Path_Composition_Sum_Fixed_Root.test.cpp\"\
    \n#define PROBLEM                        \\\n    \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n\n#line 2 \"modint/modint.hpp\"\n\r\n#include <cassert>\r\n#include <iostream>\r\
    \n\r\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#line 5 \"modint/base.hpp\"\
    \n#include <utility>\n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint\
    \ = requires(T a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n   \
    \ a.inv();\n    a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n\
    };\n\ntemplate <Modint mint> std::istream &operator>>(std::istream &os, mint &a)\
    \ {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate\
    \ <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const mint &a) {\n\
    \    return os << a.val();\n}\n\n}  // namespace ebi\n#line 7 \"modint/modint.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <int m> struct static_modint {\r\n  private:\r\
    \n    using modint = static_modint;\r\n\r\n  public:\r\n    static constexpr int\
    \ mod() {\r\n        return m;\r\n    }\r\n\r\n    static constexpr modint raw(int\
    \ v) {\r\n        modint x;\r\n        x._v = v;\r\n        return x;\r\n    }\r\
    \n\r\n    constexpr static_modint() : _v(0) {}\r\n\r\n    template <std::signed_integral\
    \ T> constexpr static_modint(T v) {\r\n        long long x = (long long)(v % (long\
    \ long)(umod()));\r\n        if (x < 0) x += umod();\r\n        _v = (unsigned\
    \ int)(x);\r\n    }\r\n\r\n    template <std::unsigned_integral T> constexpr static_modint(T\
    \ v) {\r\n        _v = (unsigned int)(v % umod());\r\n    }\r\n\r\n    constexpr\
    \ unsigned int val() const {\r\n        return _v;\r\n    }\r\n\r\n    constexpr\
    \ unsigned int value() const {\r\n        return val();\r\n    }\r\n\r\n    constexpr\
    \ modint &operator++() {\r\n        _v++;\r\n        if (_v == umod()) _v = 0;\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator--() {\r\n \
    \       if (_v == 0) _v = umod();\r\n        _v--;\r\n        return *this;\r\n\
    \    }\r\n\r\n    constexpr modint operator++(int) {\r\n        modint res = *this;\r\
    \n        ++*this;\r\n        return res;\r\n    }\r\n    constexpr modint operator--(int)\
    \ {\r\n        modint res = *this;\r\n        --*this;\r\n        return res;\r\
    \n    }\r\n\r\n    constexpr modint &operator+=(const modint &rhs) {\r\n     \
    \   _v += rhs._v;\r\n        if (_v >= umod()) _v -= umod();\r\n        return\
    \ *this;\r\n    }\r\n    constexpr modint &operator-=(const modint &rhs) {\r\n\
    \        _v -= rhs._v;\r\n        if (_v >= umod()) _v += umod();\r\n        return\
    \ *this;\r\n    }\r\n    constexpr modint &operator*=(const modint &rhs) {\r\n\
    \        unsigned long long x = _v;\r\n        x *= rhs._v;\r\n        _v = (unsigned\
    \ int)(x % (unsigned long long)umod());\r\n        return *this;\r\n    }\r\n\
    \    constexpr modint &operator/=(const modint &rhs) {\r\n        return *this\
    \ = *this * rhs.inv();\r\n    }\r\n\r\n    constexpr modint operator+() const\
    \ {\r\n        return *this;\r\n    }\r\n    constexpr modint operator-() const\
    \ {\r\n        return modint() - *this;\r\n    }\r\n\r\n    constexpr modint pow(long\
    \ long n) const {\r\n        assert(0 <= n);\r\n        modint x = *this, res\
    \ = 1;\r\n        while (n) {\r\n            if (n & 1) res *= x;\r\n        \
    \    x *= x;\r\n            n >>= 1;\r\n        }\r\n        return res;\r\n \
    \   }\r\n    constexpr modint inv() const {\r\n        assert(_v);\r\n       \
    \ return pow(umod() - 2);\r\n    }\r\n\r\n    friend modint operator+(const modint\
    \ &lhs, const modint &rhs) {\r\n        return modint(lhs) += rhs;\r\n    }\r\n\
    \    friend modint operator-(const modint &lhs, const modint &rhs) {\r\n     \
    \   return modint(lhs) -= rhs;\r\n    }\r\n    friend modint operator*(const modint\
    \ &lhs, const modint &rhs) {\r\n        return modint(lhs) *= rhs;\r\n    }\r\n\
    \r\n    friend modint operator/(const modint &lhs, const modint &rhs) {\r\n  \
    \      return modint(lhs) /= rhs;\r\n    }\r\n    friend bool operator==(const\
    \ modint &lhs, const modint &rhs) {\r\n        return lhs.val() == rhs.val();\r\
    \n    }\r\n    friend bool operator!=(const modint &lhs, const modint &rhs) {\r\
    \n        return !(lhs == rhs);\r\n    }\r\n\r\n  private:\r\n    unsigned int\
    \ _v = 0;\r\n\r\n    static constexpr unsigned int umod() {\r\n        return\
    \ m;\r\n    }\r\n};\r\n\r\nusing modint998244353 = static_modint<998244353>;\r\
    \nusing modint1000000007 = static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n\
    #line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ a, n) for (int i = (int)(a); i < (int)(n); i++)\n#define rrep(i, a, n) for (int\
    \ i = ((int)(n)-1); i >= (int)(a); i--)\n#define Rep(i, a, n) for (i64 i = (i64)(a);\
    \ i < (i64)(n); i++)\n#define RRep(i, a, n) for (i64 i = ((i64)(n)-i64(1)); i\
    \ >= (i64)(a); i--)\n#define all(v) (v).begin(), (v).end()\n#define rall(v) (v).rbegin(),\
    \ (v).rend()\n\n#line 2 \"template/debug_template.hpp\"\n\n#line 4 \"template/debug_template.hpp\"\
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
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 2 \"tree/dp_on_static_top_tree.hpp\"\
    \n\n#line 2 \"tree/static_top_tree.hpp\"\n\n#line 4 \"tree/static_top_tree.hpp\"\
    \n\nnamespace ebi {\n\nenum Type { Vertex, Compress, Rake, AddEdge, AddVertex\
    \ };\n\ntemplate <class T> struct static_top_tree {\n  private:\n    struct Node\
    \ {\n        int par = -1, lch = -1, rch = -1;\n        Type ty = Type::Vertex;\n\
    \    };\n\n    void dfs_sz(int v) {\n        for (auto &e : g[v]) {\n        \
    \    if (e.to == par[v]) continue;\n            par[e.to] = v;\n            dfs_sz(e.to);\n\
    \            sz[v] += sz[e.to];\n            if (sz[e.to] > sz[g[v][0].to] ||\
    \ g[v][0].to == par[v]) {\n                std::swap(e, g[v][0]);\n          \
    \  }\n        }\n    }\n\n    int new_node(int k, int l, int r, Type t) {\n  \
    \      if (k == -1) {\n            k = (int)stt.size();\n            stt.emplace_back(-1,\
    \ l, r, t);\n        } else {\n            stt[k].lch = l;\n            stt[k].rch\
    \ = r;\n            stt[k].ty = t;\n        }\n        if (l != -1) stt[l].par\
    \ = k;\n        if (r != -1) stt[r].par = k;\n        return k;\n    }\n\n   \
    \ std::pair<int, int> merge(const std::vector<std::pair<int, int>> &a,\n     \
    \                         Type t) {\n        if (a.size() == 1) {\n          \
    \  return a[0];\n        }\n        int sum = 0;\n        for (auto [v_, s] :\
    \ a) sum += s;\n        std::vector<std::pair<int, int>> b, c;\n        for (auto\
    \ [i, s] : a) {\n            if (sum > s)\n                b.emplace_back(i, s);\n\
    \            else\n                c.emplace_back(i, s);\n            sum -= 2\
    \ * s;\n        }\n        auto [i, si] = merge(b, t);\n        auto [j, sj] =\
    \ merge(c, t);\n        return {new_node(-1, i, j, t), si + sj};\n    }\n\n  \
    \  std::pair<int, int> compress(int v) {\n        std::vector<std::pair<int, int>>\
    \ path{add_vertex(v)};\n        while (g[v][0].to != par[v]) {\n            path.emplace_back(add_vertex(v\
    \ = g[v][0].to));\n        }\n        return merge(path, Type::Compress);\n  \
    \  }\n\n    std::pair<int, int> rake(int v) {\n        std::vector<std::pair<int,\
    \ int>> ch;\n        for (int i = 1; i < (int)g[v].size(); i++) {\n          \
    \  if (g[v][i].to == par[v]) continue;\n            ch.emplace_back(add_edge(g[v][i].to));\n\
    \        }\n        return ch.empty() ? std::pair<int, int>{-1, 0} : merge(ch,\
    \ Type::Rake);\n    }\n\n    std::pair<int, int> add_edge(int v) {\n        auto\
    \ [i, si] = compress(v);\n        return {new_node(-1, i, -1, Type::AddEdge),\
    \ si};\n    }\n\n    std::pair<int, int> add_vertex(int v) {\n        auto [i,\
    \ si] = rake(v);\n        return {new_node(v, i, -1, i == -1 ? Type::Vertex :\
    \ Type::AddVertex),\n                si + 1};\n    }\n\n  public:\n    static_top_tree(Graph<T>\
    \ g_, int root = 0)\n        : n(g_.size()), g(g_), par(n, -1), sz(n, 1), stt(n)\
    \ {\n        if (n == 1) {\n            stt_root = 0;\n            return;\n \
    \       }\n        dfs_sz(root);\n        stt_root = compress(root).first;\n \
    \   }\n\n    int node_num() const {\n        return (int)stt.size();\n    }\n\n\
    \    int parent(int v) const {\n        return stt[v].par;\n    }\n\n    std::pair<int,\
    \ int> child(int v) const {\n        return {stt[v].lch, stt[v].rch};\n    }\n\
    \n    int left_child(int v) const {\n        return stt[v].lch;\n    }\n\n   \
    \ int right_child(int v) const {\n        return stt[v].rch;\n    }\n\n    Type\
    \ type(int v) const {\n        return stt[v].ty;\n    }\n\n    int root() const\
    \ {\n        return stt_root;\n    }\n\n  private:\n    int n;\n    Graph<T> g;\n\
    \    std::vector<int> par, sz;\n    std::vector<Node> stt;\n    int stt_root;\n\
    };\n\n}  // namespace ebi\n#line 4 \"tree/dp_on_static_top_tree.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <class T, class Path, class Point, class Compress, class Rake,\n\
    \          class Add_edge, class Add_vertex>\nstruct dp_on_static_top_tree {\n\
    \  private:\n    void dfs(int v) {\n        auto [lch, rch] = stt.child(v);\n\
    \        if (lch != -1) dfs(lch);\n        if (rch != -1) dfs(rch);\n        update_(v);\n\
    \    }\n\n    void update_(int v) {\n        if (stt.type(v) == Type::Vertex)\
    \ {\n            path[v] = vertex[v];\n        } else if (stt.type(v) == Type::Compress)\
    \ {\n            path[v] =\n                compress(path[stt.left_child(v)],\
    \ path[stt.right_child(v)]);\n        } else if (stt.type(v) == Type::Rake) {\n\
    \            point[v] =\n                rake(point[stt.left_child(v)], point[stt.right_child(v)]);\n\
    \        } else if (stt.type(v) == Type::AddEdge) {\n            point[v] = add_edge(path[stt.left_child(v)]);\n\
    \        } else if (stt.type(v) == Type::AddVertex) {\n            path[v] = add_vertex(point[stt.left_child(v)],\
    \ vertex[v]);\n        }\n    }\n\n    void update(int v) {\n        while (v\
    \ != -1) {\n            update_(v);\n            v = stt.parent(v);\n        }\n\
    \    }\n\n  public:\n    dp_on_static_top_tree(const Graph<T> &g, int root,\n\
    \                          const std::vector<Path> &vertex_,\n               \
    \           const Compress &compress_, const Rake &rake_,\n                  \
    \        const Add_edge &add_edge_,\n                          const Add_vertex\
    \ &add_vertex_)\n        : stt(g, root),\n          n(stt.node_num()),\n     \
    \     path(n),\n          point(n),\n          vertex(vertex_),\n          compress(compress_),\n\
    \          rake(rake_),\n          add_edge(add_edge_),\n          add_vertex(add_vertex_)\
    \ {\n        dfs(stt.root());\n    }\n\n    Path get() const {\n        return\
    \ path[stt.root()];\n    }\n\n    void set(int v, Path x) {\n        vertex[v]\
    \ = x;\n        update(v);\n    }\n\n  private:\n    static_top_tree<T> stt;\n\
    \n    int n;\n    std::vector<Path> path;\n    std::vector<Point> point;\n   \
    \ std::vector<Path> vertex;\n    const Compress compress;\n    const Rake rake;\n\
    \    const Add_edge add_edge;\n    const Add_vertex add_vertex;\n};\n\n}  // namespace\
    \ ebi\n#line 7 \"test/tree/Point_Set_Tree_Path_Composition_Sum_Fixed_Root.test.cpp\"\
    \n\nnamespace ebi {\n\nusing mint = modint998244353;\n\nstruct Path {\n    mint\
    \ a, b, s, c;\n};\n\nstruct Point {\n    mint s, c;\n};\n\nvoid main_() {\n  \
    \  int n, q;\n    std::cin >> n >> q;\n    Graph<int> g(2 * n - 1);\n    std::vector<Path>\
    \ a(2 * n - 1);\n    rep(i, 0, n) {\n        int x;\n        std::cin >> x;\n\
    \        a[i] = {1, 0, x, 1};\n    }\n    rep(i, 0, n - 1) {\n        int u, v,\
    \ b, c;\n        std::cin >> u >> v >> b >> c;\n        g.add_undirected_edge(u,\
    \ i + n, 1);\n        g.add_undirected_edge(v, i + n, 1);\n        a[i + n] =\
    \ {b, c, 0, 0};\n    }\n    g.build();\n    auto compress = [&](Path p, Path c)\
    \ -> Path {\n        return {p.a * c.a, p.b + p.a * c.b, p.s + p.a * c.s + p.b\
    \ * c.c,\n                p.c + c.c};\n    };\n    auto rake = [&](Point a, Point\
    \ b) -> Point {\n        return {a.s + b.s, a.c + b.c};\n    };\n    auto add_edge\
    \ = [&](Path a) -> Point { return {a.s, a.c}; };\n    auto add_vertex = [&](Point\
    \ a, Path v) -> Path {\n        return {v.a, v.b, v.s + v.a * a.s + v.b * a.c,\
    \ a.c + v.c};\n    };\n    dp_on_static_top_tree<int, Path, Point, decltype(compress),\
    \ decltype(rake),\n                          decltype(add_edge), decltype(add_vertex)>\n\
    \        dp(g, 0, a, compress, rake, add_edge, add_vertex);\n    while (q--) {\n\
    \        int t;\n        std::cin >> t;\n        if (t == 0) {\n            int\
    \ w, x;\n            std::cin >> w >> x;\n            dp.set(w, {1, 0, x, 1});\n\
    \        } else {\n            int e, y, z;\n            std::cin >> e >> y >>\
    \ z;\n            dp.set(e + n, {y, z, 0, 0});\n        }\n        std::cout <<\
    \ dp.get().s << '\\n';\n    }\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n\
    \    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM                        \\\n    \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n\n#include \"../../modint/modint.hpp\"\n#include \"../../template/template.hpp\"\
    \n#include \"../../tree/dp_on_static_top_tree.hpp\"\n\nnamespace ebi {\n\nusing\
    \ mint = modint998244353;\n\nstruct Path {\n    mint a, b, s, c;\n};\n\nstruct\
    \ Point {\n    mint s, c;\n};\n\nvoid main_() {\n    int n, q;\n    std::cin >>\
    \ n >> q;\n    Graph<int> g(2 * n - 1);\n    std::vector<Path> a(2 * n - 1);\n\
    \    rep(i, 0, n) {\n        int x;\n        std::cin >> x;\n        a[i] = {1,\
    \ 0, x, 1};\n    }\n    rep(i, 0, n - 1) {\n        int u, v, b, c;\n        std::cin\
    \ >> u >> v >> b >> c;\n        g.add_undirected_edge(u, i + n, 1);\n        g.add_undirected_edge(v,\
    \ i + n, 1);\n        a[i + n] = {b, c, 0, 0};\n    }\n    g.build();\n    auto\
    \ compress = [&](Path p, Path c) -> Path {\n        return {p.a * c.a, p.b + p.a\
    \ * c.b, p.s + p.a * c.s + p.b * c.c,\n                p.c + c.c};\n    };\n \
    \   auto rake = [&](Point a, Point b) -> Point {\n        return {a.s + b.s, a.c\
    \ + b.c};\n    };\n    auto add_edge = [&](Path a) -> Point { return {a.s, a.c};\
    \ };\n    auto add_vertex = [&](Point a, Path v) -> Path {\n        return {v.a,\
    \ v.b, v.s + v.a * a.s + v.b * a.c, a.c + v.c};\n    };\n    dp_on_static_top_tree<int,\
    \ Path, Point, decltype(compress), decltype(rake),\n                         \
    \ decltype(add_edge), decltype(add_vertex)>\n        dp(g, 0, a, compress, rake,\
    \ add_edge, add_vertex);\n    while (q--) {\n        int t;\n        std::cin\
    \ >> t;\n        if (t == 0) {\n            int w, x;\n            std::cin >>\
    \ w >> x;\n            dp.set(w, {1, 0, x, 1});\n        } else {\n          \
    \  int e, y, z;\n            std::cin >> e >> y >> z;\n            dp.set(e +\
    \ n, {y, z, 0, 0});\n        }\n        std::cout << dp.get().s << '\\n';\n  \
    \  }\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t\
    \ = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n    }\n\
    \    return 0;\n}"
  dependsOn:
  - modint/modint.hpp
  - modint/base.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  - tree/dp_on_static_top_tree.hpp
  - tree/static_top_tree.hpp
  isVerificationFile: true
  path: test/tree/Point_Set_Tree_Path_Composition_Sum_Fixed_Root.test.cpp
  requiredBy: []
  timestamp: '2024-05-23 21:58:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/Point_Set_Tree_Path_Composition_Sum_Fixed_Root.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Point_Set_Tree_Path_Composition_Sum_Fixed_Root.test.cpp
- /verify/test/tree/Point_Set_Tree_Path_Composition_Sum_Fixed_Root.test.cpp.html
title: test/tree/Point_Set_Tree_Path_Composition_Sum_Fixed_Root.test.cpp
---
