---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/monotone_minima.hpp
    title: Monotone Minima
  - icon: ':heavy_check_mark:'
    path: convolution/min_plus_convolution.hpp
    title: Min Plus Convolution
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
    links:
    - https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
  bundledCode: "#line 1 \"test/convolution/Min_Plus_Convolution_Convex_and_Arbitary.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
    \n\n#line 2 \"convolution/min_plus_convolution.hpp\"\n\n#include <cassert>\n#include\
    \ <limits>\n#include <vector>\n\n#line 2 \"algorithm/monotone_minima.hpp\"\n\n\
    #include <functional>\n#include <utility>\n#line 6 \"algorithm/monotone_minima.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class F,\n          class T = decltype(std::declval<F>()(std::declval<int>(),\n\
    \                                               std::declval<int>())),\n     \
    \     class Compare = std::less<T>>\nstd::pair<std::vector<int>, std::vector<T>>\
    \ monotone_minima(\n    int n, int m, F f, const Compare &compare = Compare())\
    \ {\n    std::vector<int> argmin(n);\n    std::vector<T> min_val(n);\n    auto\
    \ dfs = [&](auto &&self, int top, int bottom, int left,\n                   int\
    \ right) -> void {\n        if (top > bottom) return;\n        int mid = (top\
    \ + bottom) >> 1;\n        argmin[mid] = left;\n        min_val[mid] = f(mid,\
    \ left);\n        for (int i = left + 1; i <= right; i++) {\n            T val\
    \ = f(mid, i);\n            if (min_val[mid] == val || compare(val, min_val[mid]))\
    \ {\n                argmin[mid] = i;\n                min_val[mid] = val;\n \
    \           }\n        }\n        self(self, top, mid - 1, left, argmin[mid]);\n\
    \        self(self, mid + 1, bottom, argmin[mid], right);\n    };\n    dfs(dfs,\
    \ 0, n - 1, 0, m - 1);\n    return {argmin, min_val};\n}\n\ntemplate <class T,\
    \ class F, class Compare = std::less<T>>\nstd::pair<std::vector<int>, std::vector<T>>\
    \ slide_monotone_minima(\n    int n, int m, F f, const Compare &compare = Compare())\
    \ {\n    std::vector<int> argmin(n);\n    std::vector<T> min_val(n);\n    auto\
    \ dfs = [&](auto &&self, int top, int bottom, int left, int right,\n         \
    \          int depth) -> void {\n        if (top > bottom) return;\n        int\
    \ mid = (top + bottom) >> 1;\n        argmin[mid] = left;\n        min_val[mid]\
    \ = f(mid, left, depth);\n        for (int i = left + 1; i <= right; i++) {\n\
    \            T val = f(mid, i, depth);\n            if (min_val[mid] == val ||\
    \ compare(val, min_val[mid])) {\n                argmin[mid] = i;\n          \
    \      min_val[mid] = val;\n            }\n        }\n        self(self, top,\
    \ mid - 1, left, argmin[mid], depth + 1);\n        self(self, mid + 1, bottom,\
    \ argmin[mid], right, depth + 1);\n    };\n    dfs(dfs, 0, n - 1, 0, m - 1, 0);\n\
    \    return {argmin, min_val};\n}\n\n}  // namespace ebi\n#line 8 \"convolution/min_plus_convolution.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T>\nstd::vector<T> min_plus_convolution_convex_and_arbitary(\n\
    \    const std::vector<T> &a, const std::vector<T> &b) {\n    int n = (int)a.size();\n\
    \    int m = (int)b.size();\n    for (int i = 0; i < n - 2; i++) {\n        assert(a[i\
    \ + 1] - a[i] <= a[i + 2] - a[i + 1]);\n    }\n    auto f = [&](int i, int j)\
    \ -> T {\n        if (i - j < 0 || i - j >= n) return std::numeric_limits<T>::max();\n\
    \        return a[i - j] + b[j];\n    };\n    auto [argmin, min_val] = monotone_minima(n\
    \ + m - 1, m, f);\n    return min_val;\n}\n\n}  // namespace ebi\n#line 1 \"template/template.hpp\"\
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
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 6 \"test/convolution/Min_Plus_Convolution_Convex_and_Arbitary.test.cpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    int n, m;\n    std::cin >> n >> m;\n\
    \    std::vector<int> a(n), b(m);\n    std::cin >> a >> b;\n    auto c = min_plus_convolution_convex_and_arbitary(a,\
    \ b);\n    std::cout << c << '\\n';\n}\n\n}  // namespace ebi\n\nint main() {\n\
    \    ebi::fast_io();\n    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n\
    \        ebi::main_();\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
    \n\n#include \"../../convolution/min_plus_convolution.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    int n, m;\n    std::cin >> n >> m;\n\
    \    std::vector<int> a(n), b(m);\n    std::cin >> a >> b;\n    auto c = min_plus_convolution_convex_and_arbitary(a,\
    \ b);\n    std::cout << c << '\\n';\n}\n\n}  // namespace ebi\n\nint main() {\n\
    \    ebi::fast_io();\n    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n\
    \        ebi::main_();\n    }\n    return 0;\n}"
  dependsOn:
  - convolution/min_plus_convolution.hpp
  - algorithm/monotone_minima.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: true
  path: test/convolution/Min_Plus_Convolution_Convex_and_Arbitary.test.cpp
  requiredBy: []
  timestamp: '2025-03-18 01:14:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/convolution/Min_Plus_Convolution_Convex_and_Arbitary.test.cpp
layout: document
redirect_from:
- /verify/test/convolution/Min_Plus_Convolution_Convex_and_Arbitary.test.cpp
- /verify/test/convolution/Min_Plus_Convolution_Convex_and_Arbitary.test.cpp.html
title: test/convolution/Min_Plus_Convolution_Convex_and_Arbitary.test.cpp
---
