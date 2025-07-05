---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/dynamic_dual_segtree.hpp
    title: dynamic dual segtree
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: Graph (CSR format)
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n\
    \n#line 2 \"data_structure/dynamic_dual_segtree.hpp\"\n\n#include <bit>\n#include\
    \ <cassert>\n#include <memory>\n\nnamespace ebi {\n\ntemplate <class F, F (*merge)(F,\
    \ F), F (*id)()> struct dynamice_dual_segtree {\n  private:\n    struct Node;\n\
    \    using node_ptr = std::shared_ptr<Node>;\n    struct Node {\n        node_ptr\
    \ lch = nullptr, rch = nullptr;\n        F f = id();\n    };\n\n    void all_apply(node_ptr\
    \ node, F f) {\n        node->f = merge(f, node->f);\n    }\n\n    void push(node_ptr\
    \ node) {\n        if (node->lch == nullptr) {\n            node->lch = std::make_shared<Node>();\n\
    \        }\n        node->lch->f = merge(node->f, node->lch->f);\n        if (node->rch\
    \ == nullptr) {\n            node->rch = std::make_shared<Node>();\n        }\n\
    \        node->rch->f = merge(node->f, node->rch->f);\n        node->f = id();\n\
    \    }\n\n    void _apply(node_ptr node, int l, int r, int tl, int tr, F f) {\n\
    \        if (tr <= l || r <= tl) return;\n        if (tl <= l && r <= tr) {\n\
    \            all_apply(node, f);\n            return;\n        }\n        push(node);\n\
    \        _apply(node->lch, l, (l + r) / 2, tl, tr, f);\n        _apply(node->rch,\
    \ (l + r) / 2, r, tl, tr, f);\n    }\n\n  public:\n    dynamice_dual_segtree(int\
    \ n_)\n        : n(n_),\n          sz(std::bit_ceil((unsigned int)(n))),\n   \
    \       lg2(std::countr_zero((unsigned int)(sz))),\n          root(std::make_shared<Node>())\
    \ {}\n\n    void apply(int l, int r, F f) {\n        assert(0 <= l && l <= r &&\
    \ r <= n);\n        if (l == r) return;\n        _apply(root, 0, sz, l, r, f);\n\
    \    }\n\n    void set(int p, F f) {\n        assert(0 <= p && p < n);\n     \
    \   node_ptr node = root;\n        int l = 0, r = sz;\n        for (int i = 0;\
    \ i < lg2; i++) {\n            push(node);\n            int m = (l + r) / 2;\n\
    \            if (p < m) {\n                r = m;\n                node = node->lch;\n\
    \            } else {\n                l = m;\n                node = node->rch;\n\
    \            }\n        }\n        node->f = f;\n    }\n\n    F get(int p) {\n\
    \        assert(0 <= p && p < n);\n        node_ptr node = root;\n        int\
    \ l = 0, r = sz;\n        for (int i = 0; i < lg2; i++) {\n            push(node);\n\
    \            int m = (l + r) / 2;\n            if (p < m) {\n                r\
    \ = m;\n                node = node->lch;\n            } else {\n            \
    \    l = m;\n                node = node->rch;\n            }\n        }\n   \
    \     return node->f;\n    }\n\n  private:\n    int n, sz, lg2;\n    node_ptr\
    \ root;\n};\n\n}  // namespace ebi\n#line 2 \"modint/modint.hpp\"\n\r\n#line 4\
    \ \"modint/modint.hpp\"\n#include <iostream>\r\n\r\n#line 2 \"modint/base.hpp\"\
    \n\n#include <concepts>\n#line 5 \"modint/base.hpp\"\n#include <utility>\n\nnamespace\
    \ ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n    a +\
    \ b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 7 \"\
    modint/modint.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate <int m> struct static_modint\
    \ {\r\n  private:\r\n    using modint = static_modint;\r\n\r\n  public:\r\n  \
    \  static constexpr int mod() {\r\n        return m;\r\n    }\r\n\r\n    static\
    \ constexpr modint raw(int v) {\r\n        modint x;\r\n        x._v = v;\r\n\
    \        return x;\r\n    }\r\n\r\n    constexpr static_modint() : _v(0) {}\r\n\
    \r\n    template <std::signed_integral T> constexpr static_modint(T v) {\r\n \
    \       long long x = (long long)(v % (long long)(umod()));\r\n        if (x <\
    \ 0) x += umod();\r\n        _v = (unsigned int)(x);\r\n    }\r\n\r\n    template\
    \ <std::unsigned_integral T> constexpr static_modint(T v) {\r\n        _v = (unsigned\
    \ int)(v % umod());\r\n    }\r\n\r\n    constexpr unsigned int val() const {\r\
    \n        return _v;\r\n    }\r\n\r\n    constexpr unsigned int value() const\
    \ {\r\n        return val();\r\n    }\r\n\r\n    constexpr modint &operator++()\
    \ {\r\n        _v++;\r\n        if (_v == umod()) _v = 0;\r\n        return *this;\r\
    \n    }\r\n    constexpr modint &operator--() {\r\n        if (_v == 0) _v = umod();\r\
    \n        _v--;\r\n        return *this;\r\n    }\r\n\r\n    constexpr modint\
    \ operator++(int) {\r\n        modint res = *this;\r\n        ++*this;\r\n   \
    \     return res;\r\n    }\r\n    constexpr modint operator--(int) {\r\n     \
    \   modint res = *this;\r\n        --*this;\r\n        return res;\r\n    }\r\n\
    \r\n    constexpr modint &operator+=(const modint &rhs) {\r\n        _v += rhs._v;\r\
    \n        if (_v >= umod()) _v -= umod();\r\n        return *this;\r\n    }\r\n\
    \    constexpr modint &operator-=(const modint &rhs) {\r\n        _v -= rhs._v;\r\
    \n        if (_v >= umod()) _v += umod();\r\n        return *this;\r\n    }\r\n\
    \    constexpr modint &operator*=(const modint &rhs) {\r\n        unsigned long\
    \ long x = _v;\r\n        x *= rhs._v;\r\n        _v = (unsigned int)(x % (unsigned\
    \ long long)umod());\r\n        return *this;\r\n    }\r\n    constexpr modint\
    \ &operator/=(const modint &rhs) {\r\n        return *this = *this * rhs.inv();\r\
    \n    }\r\n\r\n    constexpr modint operator+() const {\r\n        return *this;\r\
    \n    }\r\n    constexpr modint operator-() const {\r\n        return modint()\
    \ - *this;\r\n    }\r\n\r\n    constexpr modint pow(long long n) const {\r\n \
    \       assert(0 <= n);\r\n        modint x = *this, res = 1;\r\n        while\
    \ (n) {\r\n            if (n & 1) res *= x;\r\n            x *= x;\r\n       \
    \     n >>= 1;\r\n        }\r\n        return res;\r\n    }\r\n    constexpr modint\
    \ inv() const {\r\n        assert(_v);\r\n        return pow(umod() - 2);\r\n\
    \    }\r\n\r\n    friend modint operator+(const modint &lhs, const modint &rhs)\
    \ {\r\n        return modint(lhs) += rhs;\r\n    }\r\n    friend modint operator-(const\
    \ modint &lhs, const modint &rhs) {\r\n        return modint(lhs) -= rhs;\r\n\
    \    }\r\n    friend modint operator*(const modint &lhs, const modint &rhs) {\r\
    \n        return modint(lhs) *= rhs;\r\n    }\r\n\r\n    friend modint operator/(const\
    \ modint &lhs, const modint &rhs) {\r\n        return modint(lhs) /= rhs;\r\n\
    \    }\r\n    friend bool operator==(const modint &lhs, const modint &rhs) {\r\
    \n        return lhs.val() == rhs.val();\r\n    }\r\n    friend bool operator!=(const\
    \ modint &lhs, const modint &rhs) {\r\n        return !(lhs == rhs);\r\n    }\r\
    \n\r\n  private:\r\n    unsigned int _v = 0;\r\n\r\n    static constexpr unsigned\
    \ int umod() {\r\n        return m;\r\n    }\r\n};\r\n\r\nusing modint998244353\
    \ = static_modint<998244353>;\r\nusing modint1000000007 = static_modint<1000000007>;\r\
    \n\r\n}  // namespace ebi\n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n\
    \n#define rep(i, a, n) for (int i = (int)(a); i < (int)(n); i++)\n#define rrep(i,\
    \ a, n) for (int i = ((int)(n)-1); i >= (int)(a); i--)\n#define Rep(i, a, n) for\
    \ (i64 i = (i64)(a); i < (i64)(n); i++)\n#define RRep(i, a, n) for (i64 i = ((i64)(n)-i64(1));\
    \ i >= (i64)(a); i--)\n#define all(v) (v).begin(), (v).end()\n#define rall(v)\
    \ (v).rbegin(), (v).rend()\n\n#line 2 \"template/int_alias.hpp\"\n\n#line 4 \"\
    template/int_alias.hpp\"\n\nnamespace ebi {\n\nusing ld = long double;\nusing\
    \ std::size_t;\nusing i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 =\
    \ std::int16_t;\nusing u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing\
    \ u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n\n}  // namespace ebi\n#line\
    \ 2 \"template/io.hpp\"\n\n#line 5 \"template/io.hpp\"\n#include <optional>\n\
    #line 7 \"template/io.hpp\"\n\n#line 9 \"template/io.hpp\"\n\nnamespace ebi {\n\
    \ntemplate <typename T1, typename T2>\nstd::ostream &operator<<(std::ostream &os,\
    \ const std::pair<T1, T2> &pa) {\n    return os << pa.first << \" \" << pa.second;\n\
    }\n\ntemplate <typename T1, typename T2>\nstd::istream &operator>>(std::istream\
    \ &os, std::pair<T1, T2> &pa) {\n    return os >> pa.first >> pa.second;\n}\n\n\
    template <typename T>\nstd::ostream &operator<<(std::ostream &os, const std::vector<T>\
    \ &vec) {\n    for (std::size_t i = 0; i < vec.size(); i++)\n        os << vec[i]\
    \ << (i + 1 == vec.size() ? \"\" : \" \");\n    return os;\n}\n\ntemplate <typename\
    \ T>\nstd::istream &operator>>(std::istream &os, std::vector<T> &vec) {\n    for\
    \ (T &e : vec) std::cin >> e;\n    return os;\n}\n\ntemplate <typename T>\nstd::ostream\
    \ &operator<<(std::ostream &os, const std::optional<T> &opt) {\n    if (opt) {\n\
    \        os << opt.value();\n    } else {\n        os << \"invalid value\";\n\
    \    }\n    return os;\n}\n\nvoid fast_io() {\n    std::cout << std::fixed <<\
    \ std::setprecision(15);\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    }\n\n}  // namespace ebi\n#line 2 \"template/utility.hpp\"\n\n#line 5 \"template/utility.hpp\"\
    \n\n#line 2 \"graph/base.hpp\"\n\n#line 5 \"graph/base.hpp\"\n#include <ranges>\n\
    #line 7 \"graph/base.hpp\"\n\n#line 2 \"data_structure/simple_csr.hpp\"\n\n#line\
    \ 6 \"data_structure/simple_csr.hpp\"\n\nnamespace ebi {\n\ntemplate <class E>\
    \ struct simple_csr {\n    simple_csr() = default;\n\n    simple_csr(int n, const\
    \ std::vector<std::pair<int, E>>& elements)\n        : start(n + 1, 0), elist(elements.size())\
    \ {\n        for (auto e : elements) {\n            start[e.first + 1]++;\n  \
    \      }\n        for (auto i : std::views::iota(0, n)) {\n            start[i\
    \ + 1] += start[i];\n        }\n        auto counter = start;\n        for (auto\
    \ [i, e] : elements) {\n            elist[counter[i]++] = e;\n        }\n    }\n\
    \n    simple_csr(const std::vector<std::vector<E>>& es)\n        : start(es.size()\
    \ + 1, 0) {\n        int n = es.size();\n        for (auto i : std::views::iota(0,\
    \ n)) {\n            start[i + 1] = (int)es[i].size() + start[i];\n        }\n\
    \        elist.resize(start.back());\n        for (auto i : std::views::iota(0,\
    \ n)) {\n            std::copy(es[i].begin(), es[i].end(), elist.begin() + start[i]);\n\
    \        }\n    }\n\n    int size() const {\n        return (int)start.size()\
    \ - 1;\n    }\n\n    const auto operator[](int i) const {\n        return std::ranges::subrange(elist.begin()\
    \ + start[i],\n                                     elist.begin() + start[i +\
    \ 1]);\n    }\n    auto operator[](int i) {\n        return std::ranges::subrange(elist.begin()\
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
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 2 \"template/debug_template.hpp\"\
    \n\n#line 4 \"template/debug_template.hpp\"\n\nnamespace ebi {\n\n#ifdef LOCAL\n\
    #define debug(...)                                                      \\\n \
    \   std::cerr << \"LINE: \" << __LINE__ << \"  [\" << #__VA_ARGS__ << \"]:\",\
    \ \\\n        debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\nvoid\
    \ debug_out() {\n    std::cerr << std::endl;\n}\n\ntemplate <typename Head, typename...\
    \ Tail> void debug_out(Head h, Tail... t) {\n    std::cerr << \" \" << h;\n  \
    \  if (sizeof...(t) > 0) std::cerr << \" :\";\n    debug_out(t...);\n}\n\n}  //\
    \ namespace ebi\n#line 6 \"test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp\"\
    \n\nnamespace ebi {\n\nusing mint = modint998244353;\n\nstruct F {\n    mint a,\
    \ b;\n};\n\nF merge(F a, F b) {\n    return {a.a * b.a, a.b + a.a * b.b};\n}\n\
    \nF id() {\n    return {1, 0};\n}\n\nvoid main_() {\n    int n, q;\n    std::cin\
    \ >> n >> q;\n    dynamice_dual_segtree<F, merge, id> seg(1'000'000'000);\n  \
    \  rep(i, 0, n) {\n        int a;\n        std::cin >> a;\n        seg.set(i,\
    \ {0, a});\n    }\n    while (q--) {\n        int t;\n        std::cin >> t;\n\
    \        if (t == 0) {\n            int l, r, b, c;\n            std::cin >> l\
    \ >> r >> b >> c;\n            seg.apply(l, r, {b, c});\n        } else {\n  \
    \          int i;\n            std::cin >> i;\n            std::cout << seg.get(i).b\
    \ << '\\n';\n        }\n    }\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n\
    \    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include \"../../data_structure/dynamic_dual_segtree.hpp\"\n#include \"../../modint/modint.hpp\"\
    \n#include \"../../template/template.hpp\"\n\nnamespace ebi {\n\nusing mint =\
    \ modint998244353;\n\nstruct F {\n    mint a, b;\n};\n\nF merge(F a, F b) {\n\
    \    return {a.a * b.a, a.b + a.a * b.b};\n}\n\nF id() {\n    return {1, 0};\n\
    }\n\nvoid main_() {\n    int n, q;\n    std::cin >> n >> q;\n    dynamice_dual_segtree<F,\
    \ merge, id> seg(1'000'000'000);\n    rep(i, 0, n) {\n        int a;\n       \
    \ std::cin >> a;\n        seg.set(i, {0, a});\n    }\n    while (q--) {\n    \
    \    int t;\n        std::cin >> t;\n        if (t == 0) {\n            int l,\
    \ r, b, c;\n            std::cin >> l >> r >> b >> c;\n            seg.apply(l,\
    \ r, {b, c});\n        } else {\n            int i;\n            std::cin >> i;\n\
    \            std::cout << seg.get(i).b << '\\n';\n        }\n    }\n}\n\n}  //\
    \ namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n    // std::cin\
    \ >> t;\n    while (t--) {\n        ebi::main_();\n    }\n    return 0;\n}"
  dependsOn:
  - data_structure/dynamic_dual_segtree.hpp
  - modint/modint.hpp
  - modint/base.hpp
  - template/template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  - template/debug_template.hpp
  isVerificationFile: true
  path: test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp
  requiredBy: []
  timestamp: '2025-07-06 00:36:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp
- /verify/test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp.html
title: test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp
---
