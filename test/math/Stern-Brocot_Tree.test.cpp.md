---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: Graph (CSR format)
  - icon: ':heavy_check_mark:'
    path: math/stern_brocot_tree.hpp
    title: Stern-Brocot Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/stern_brocot_tree
    links:
    - https://judge.yosupo.jp/problem/stern_brocot_tree
  bundledCode: "#line 1 \"test/math/Stern-Brocot_Tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\n\n#line 2 \"math/stern_brocot_tree.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <concepts>\n#include <cstdint>\n\
    #include <iostream>\n#include <optional>\n#include <vector>\n\n/*\nreference:\
    \ https://miscalc.hatenablog.com/entry/2023/12/22/213007\n           https://rsk0315.hatenablog.com/entry/2023/04/17/022705\n\
    \           https://atcoder.jp/contests/abc294/editorial/6017\n*/\n\nnamespace\
    \ ebi {\n\nstruct stern_brocot_tree {\n  private:\n    using value_type = std::int64_t;\n\
    \    using T = value_type;\n    using Fraction = std::pair<T, T>;\n\n    static\
    \ Fraction add(const Fraction &lhs, const Fraction &rhs) {\n        return {lhs.first\
    \ + rhs.first, lhs.second + rhs.second};\n    }\n\n    static Fraction mul(const\
    \ T k, const Fraction &a) {\n        return {k * a.first, k * a.second};\n   \
    \ }\n\n    static bool compare(Fraction a, Fraction b) {\n        return __int128_t(a.first)\
    \ * b.second < __int128_t(a.second) * b.first;\n    }\n\n    static void euler_tour_order(std::vector<Fraction>\
    \ &fs) {\n        std::sort(fs.begin(), fs.end(), [&](Fraction a, Fraction b)\
    \ -> bool {\n            if (a == b) return false;\n            if (in_subtree(a,\
    \ b)) return false;\n            if (in_subtree(b, a)) return true;\n        \
    \    return compare(a, b);\n        });\n    }\n\n  public:\n    stern_brocot_tree()\
    \ = default;\n\n    static std::vector<T> encode_path(const Fraction &f) {\n \
    \       auto [x, y] = f;\n        std::vector<T> path;\n        while (x != y)\
    \ {\n            T m = (x - 1) / y;\n            path.emplace_back(m);\n     \
    \       x -= m * y;\n            std::swap(x, y);\n        }\n        return path;\n\
    \    }\n\n    static std::pair<Fraction, Fraction> decode_path(\n        const\
    \ std::vector<T> &path) {\n        T lx = 0, ly = 1, rx = 1, ry = 0;\n       \
    \ for (bool is_right = true; auto n : path) {\n            if (is_right) {\n \
    \               lx += rx * n;\n                ly += ry * n;\n            } else\
    \ {\n                rx += lx * n;\n                ry += ly * n;\n          \
    \  }\n            is_right = !is_right;\n        }\n        return {{lx, ly},\
    \ {rx, ry}};\n    }\n\n    static std::pair<Fraction, Fraction> decode_path(\n\
    \        const std::vector<std::pair<char, T>> &path) {\n        if (path.empty())\
    \ {\n            return {{0, 1}, {1, 0}};\n        }\n        std::vector<T> p;\n\
    \        bool is_right = true;\n        if (path[0].first == 'L') {\n        \
    \    p.emplace_back(0);\n            is_right = !is_right;\n        }\n      \
    \  for (auto [c, n] : path) {\n            assert(c == (is_right ? 'R' : 'L'));\n\
    \            p.emplace_back(n);\n            is_right = !is_right;\n        }\n\
    \        return decode_path(p);\n    }\n\n    static Fraction lca(Fraction f,\
    \ Fraction g) {\n        auto path_f = encode_path(f);\n        auto path_g =\
    \ encode_path(g);\n        std::vector<T> path_h;\n        for (int i = 0; i <\
    \ (int)std::min(path_f.size(), path_g.size()); i++) {\n            T k = std::min(path_f[i],\
    \ path_g[i]);\n            path_h.emplace_back(k);\n            if (path_f[i]\
    \ != path_g[i]) {\n                break;\n            }\n        }\n        return\
    \ val(decode_path(path_h));\n    }\n\n    static std::optional<Fraction> ancestor(T\
    \ k, Fraction f) {\n        std::vector<T> path;\n        for (auto n : encode_path(f))\
    \ {\n            T m = std::min(k, n);\n            path.emplace_back(m);\n  \
    \          k -= m;\n            if (k == 0) break;\n        }\n        if (k >\
    \ 0) return std::nullopt;\n        return val(decode_path(path));\n    }\n\n \
    \   static std::pair<Fraction, Fraction> range(Fraction f) {\n        return decode_path(encode_path(f));\n\
    \    }\n\n    template <class F> static Fraction binary_search(const T max_value,\
    \ F f) {\n        Fraction l = {0, 1}, r = {1, 0};\n        while (true) {\n \
    \           Fraction now = val({l, r});\n            bool flag = f(now);\n   \
    \         Fraction from = flag ? l : r;\n            Fraction to = flag ? r :\
    \ l;\n            T ok = 1, ng = 2;\n            while (f(add(from, mul(ng, to)))\
    \ == flag) {\n                ok <<= 1;\n                ng <<= 1;\n         \
    \       auto nxt = add(from, mul(ok, to));\n                if (nxt.first > max_value\
    \ || nxt.second > max_value) return to;\n            }\n            while (ng\
    \ - ok > 1) {\n                T mid = (ok + ng) >> 1;\n                if (f(add(from,\
    \ mul(mid, to))) == flag) {\n                    ok = mid;\n                }\
    \ else {\n                    ng = mid;\n                }\n            }\n  \
    \          (flag ? l : r) = add(from, mul(ok, to));\n        }\n        assert(0);\n\
    \        return l;\n    }\n\n    static std::pair<Fraction, Fraction> nearest_fraction(T\
    \ max, Fraction f) {\n        Fraction l = {0, 1}, r = {1, 0};\n        for (bool\
    \ is_right = true; auto n : encode_path(f)) {\n            Fraction nl = l, nr\
    \ = r;\n            if (is_right) {\n                nl = add(l, mul(n, r));\n\
    \            } else {\n                nr = add(r, mul(n, l));\n            }\n\
    \            if (std::max(nl.second, nr.second) > max) {\n                nl =\
    \ l, nr = r;\n                if (is_right) {\n                    T x = (max\
    \ - l.second) / r.second;\n                    nl.first += r.first * x;\n    \
    \                nl.second += r.second * x;\n                } else {\n      \
    \              T x = (max - r.second) / l.second;\n                    nr.first\
    \ += l.first * x;\n                    nr.second += l.second * x;\n          \
    \      }\n                std::swap(l, nl);\n                std::swap(r, nr);\n\
    \                break;\n            }\n            std::swap(l, nl);\n      \
    \      std::swap(r, nr);\n            is_right = !is_right;\n        }\n     \
    \   return {l, r};\n    }\n\n    static Fraction best_rational_within_an_interval(Fraction\
    \ l, Fraction r) {\n        Fraction m = lca(l, r);\n        if (l == m) {\n \
    \           Fraction rch = childs(l).second;\n            if (rch == r) {\n  \
    \              return childs(r).first;\n            } else {\n               \
    \ return rch;\n            }\n        } else if (r == m) {\n            Fraction\
    \ lch = childs(r).first;\n            if (lch == l) {\n                return\
    \ childs(l).second;\n            } else {\n                return lch;\n     \
    \       }\n        } else {\n            return m;\n        }\n    }\n\n    static\
    \ std::vector<std::pair<Fraction, int>>\n    lca_based_auxiliary_tree_euler_tour_order(std::vector<Fraction>\
    \ fs) {\n        if (fs.empty()) return {};\n        euler_tour_order(fs);\n \
    \       fs.erase(std::unique(fs.begin(), fs.end()), fs.end());\n        int n\
    \ = (int)fs.size();\n        for (int i = 0; i < n - 1; i++) {\n            fs.emplace_back(lca(fs[i],\
    \ fs[i + 1]));\n        }\n        euler_tour_order(fs);\n        fs.erase(std::unique(fs.begin(),\
    \ fs.end()), fs.end());\n        n = (int)fs.size();\n        std::vector<std::pair<Fraction,\
    \ int>> tree(n);\n        std::vector<int> stack = {0};\n        tree[0] = {fs[0],\
    \ -1};\n        for (int i = 1; i < n; i++) {\n            while (!in_subtree(fs[i],\
    \ fs[stack.back()])) {\n                stack.pop_back();\n            }\n   \
    \         tree[i] = {fs[i], stack.back()};\n            stack.emplace_back(i);\n\
    \        }\n        return tree;\n    }\n\n    static std::pair<Fraction, Fraction>\
    \ childs(Fraction f) {\n        auto [l, r] = range(f);\n        return {add(l,\
    \ f), add(f, r)};\n    }\n\n    static bool in_subtree(Fraction f, Fraction g)\
    \ {\n        auto [l, r] = range(g);\n        return compare(l, f) && compare(f,\
    \ r);\n    }\n\n    static T depth(Fraction f) {\n        T d = 0;\n        for\
    \ (auto n : encode_path(f)) d += n;\n        return d;\n    }\n\n    static Fraction\
    \ val(const std::pair<Fraction, Fraction> &f) {\n        return add(f.first, f.second);\n\
    \    }\n\n    static void print_path(const std::vector<T> &path) {\n        if\
    \ (path.empty()) {\n            std::cout << \"0\\n\";\n            return;\n\
    \        }\n        int k = (int)path.size() - int(path[0] == 0);\n        std::cout\
    \ << k;\n        for (bool is_right = true; auto c : path) {\n            if (c\
    \ > 0) {\n                std::cout << \" \" << (is_right ? 'R' : 'L') << \" \"\
    \ << c;\n            }\n            is_right = !is_right;\n        }\n       \
    \ std::cout << '\\n';\n        return;\n    }\n};\n\n}  // namespace ebi\n#line\
    \ 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n\n#define rep(i, a, n)\
    \ for (int i = (int)(a); i < (int)(n); i++)\n#define rrep(i, a, n) for (int i\
    \ = ((int)(n)-1); i >= (int)(a); i--)\n#define Rep(i, a, n) for (i64 i = (i64)(a);\
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
    \ 2 \"template/io.hpp\"\n\n#line 7 \"template/io.hpp\"\n\nnamespace ebi {\n\n\
    template <typename T1, typename T2>\nstd::ostream &operator<<(std::ostream &os,\
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
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 5 \"test/math/Stern-Brocot_Tree.test.cpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    std::string type;\n    std::cin >>\
    \ type;\n    if (type == \"ENCODE_PATH\") {\n        i64 a, b;\n        std::cin\
    \ >> a >> b;\n        auto path = stern_brocot_tree::encode_path({a, b});\n  \
    \      stern_brocot_tree::print_path(path);\n    } else if (type == \"DECODE_PATH\"\
    ) {\n        int k;\n        std::cin >> k;\n        std::vector<std::pair<char,\
    \ i64>> path(k);\n        for (auto &[c, n] : path) {\n            std::cin >>\
    \ c >> n;\n        }\n        auto lr = stern_brocot_tree::decode_path(path);\n\
    \        auto f = stern_brocot_tree::val(lr);\n        std::cout << f << '\\n';\n\
    \    } else if (type == \"LCA\") {\n        i64 a, b, c, d;\n        std::cin\
    \ >> a >> b >> c >> d;\n        std::cout << stern_brocot_tree::lca({a, b}, {c,\
    \ d}) << '\\n';\n    } else if (type == \"ANCESTOR\") {\n        i64 k, a, b;\n\
    \        std::cin >> k >> a >> b;\n        auto f = stern_brocot_tree::ancestor(k,\
    \ {a, b});\n        if (f) {\n            std::cout << f.value() << '\\n';\n \
    \       } else {\n            std::cout << \"-1\\n\";\n        }\n    } else if\
    \ (type == \"RANGE\") {\n        i64 a, b;\n        std::cin >> a >> b;\n    \
    \    std::cout << stern_brocot_tree::range({a, b}) << '\\n';\n    }\n}\n\n}  //\
    \ namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n    std::cin\
    \ >> t;\n    while (t--) {\n        ebi::main_();\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\n\n\
    #include \"../../math/stern_brocot_tree.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    std::string type;\n    std::cin >>\
    \ type;\n    if (type == \"ENCODE_PATH\") {\n        i64 a, b;\n        std::cin\
    \ >> a >> b;\n        auto path = stern_brocot_tree::encode_path({a, b});\n  \
    \      stern_brocot_tree::print_path(path);\n    } else if (type == \"DECODE_PATH\"\
    ) {\n        int k;\n        std::cin >> k;\n        std::vector<std::pair<char,\
    \ i64>> path(k);\n        for (auto &[c, n] : path) {\n            std::cin >>\
    \ c >> n;\n        }\n        auto lr = stern_brocot_tree::decode_path(path);\n\
    \        auto f = stern_brocot_tree::val(lr);\n        std::cout << f << '\\n';\n\
    \    } else if (type == \"LCA\") {\n        i64 a, b, c, d;\n        std::cin\
    \ >> a >> b >> c >> d;\n        std::cout << stern_brocot_tree::lca({a, b}, {c,\
    \ d}) << '\\n';\n    } else if (type == \"ANCESTOR\") {\n        i64 k, a, b;\n\
    \        std::cin >> k >> a >> b;\n        auto f = stern_brocot_tree::ancestor(k,\
    \ {a, b});\n        if (f) {\n            std::cout << f.value() << '\\n';\n \
    \       } else {\n            std::cout << \"-1\\n\";\n        }\n    } else if\
    \ (type == \"RANGE\") {\n        i64 a, b;\n        std::cin >> a >> b;\n    \
    \    std::cout << stern_brocot_tree::range({a, b}) << '\\n';\n    }\n}\n\n}  //\
    \ namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n    std::cin\
    \ >> t;\n    while (t--) {\n        ebi::main_();\n    }\n    return 0;\n}"
  dependsOn:
  - math/stern_brocot_tree.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: true
  path: test/math/Stern-Brocot_Tree.test.cpp
  requiredBy: []
  timestamp: '2024-03-13 15:52:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/Stern-Brocot_Tree.test.cpp
layout: document
redirect_from:
- /verify/test/math/Stern-Brocot_Tree.test.cpp
- /verify/test/math/Stern-Brocot_Tree.test.cpp.html
title: test/math/Stern-Brocot_Tree.test.cpp
---