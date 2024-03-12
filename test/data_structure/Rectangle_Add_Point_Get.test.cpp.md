---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: Compress
  - icon: ':question:'
    path: data_structure/dual_segtree.hpp
    title: dual segtree
  - icon: ':heavy_check_mark:'
    path: data_structure/offline_dual_segtree_2d.hpp
    title: offline 2D dual segtree
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
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_add_point_get
    links:
    - https://judge.yosupo.jp/problem/rectangle_add_point_get
  bundledCode: "#line 1 \"test/data_structure/Rectangle_Add_Point_Get.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_add_point_get\"\n\n\
    #line 2 \"data_structure/offline_dual_segtree_2d.hpp\"\n\n#include <bit>\n#include\
    \ <utility>\n#include <vector>\n\n#line 2 \"data_structure/compress.hpp\"\n\n\
    #include <algorithm>\n#include <cassert>\n#line 6 \"data_structure/compress.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> struct compress {\n  private:\n    std::vector<T>\
    \ cp;\n\n  public:\n    compress() = default;\n\n    compress(std::vector<T> cp_)\
    \ : cp(cp_) {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n    }\n\
    \n    int get(const T &val) const {\n        return std::lower_bound(cp.begin(),\
    \ cp.end(), val) - cp.begin();\n    }\n\n    int size() const {\n        return\
    \ cp.size();\n    }\n\n    bool find(const T &val) const {\n        auto itr =\
    \ std::lower_bound(cp.begin(), cp.end(), val);\n        if (itr == cp.end())\n\
    \            return false;\n        else\n            return *itr == val;\n  \
    \  }\n\n    T val(int idx) const {\n        assert(0 <= idx && idx < (int)cp.size());\n\
    \        return cp[idx];\n    }\n};\n\n}  // namespace ebi\n#line 2 \"data_structure/dual_segtree.hpp\"\
    \n\n#line 5 \"data_structure/dual_segtree.hpp\"\n#include <ranges>\n#line 7 \"\
    data_structure/dual_segtree.hpp\"\n\nnamespace ebi {\n\ntemplate <class F, F (*merge)(F,\
    \ F), F (*id)()> struct dual_segtree {\n  private:\n    void all_apply(int i,\
    \ F f) {\n        d[i] = merge(f, d[i]);\n    }\n\n    void push(int i) {\n  \
    \      assert(i < sz);\n        all_apply(2 * i, d[i]);\n        all_apply(2 *\
    \ i + 1, d[i]);\n        d[i] = id();\n    }\n\n  public:\n    dual_segtree(int\
    \ n) : dual_segtree(std::vector<F>(n, id())) {}\n\n    dual_segtree(const std::vector<F>\
    \ &a)\n        : n(a.size()),\n          sz(std::bit_ceil(a.size())),\n      \
    \    lg2(std::countr_zero((unsigned int)(sz))) {\n        d = std::vector<F>(2\
    \ * sz, id());\n        for (int i : std::views::iota(sz, sz + n)) {\n       \
    \     d[i] = a[i - sz];\n        }\n    }\n\n    void apply(int l, int r, F f)\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return;\n\
    \n        l += sz;\n        r += sz;\n\n        for (int i : std::views::iota(1,\
    \ lg2 + 1) | std::views::reverse) {\n            if (((l >> i) << i) != l) push(l\
    \ >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\
    \n        while (l < r) {\n            if (l & 1) all_apply(l++, f);\n       \
    \     if (r & 1) all_apply(--r, f);\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n    }\n\n    F get(int p) {\n        assert(0 <= p && p < n);\n  \
    \      p += sz;\n        for (int i : std::views::iota(1, lg2 + 1) | std::views::reverse)\
    \ {\n            push(p >> i);\n        }\n        return d[p];\n    }\n\n  private:\n\
    \    int n, sz, lg2;\n    std::vector<F> d;\n};\n\n}  // namespace ebi\n#line\
    \ 9 \"data_structure/offline_dual_segtree_2d.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class F, F (*merge)(F, F), F (*id)()> struct offline_dual_segtree_2d {\n  \
    \  offline_dual_segtree_2d() = default;\n\n    void pre_set(std::pair<int, int>\
    \ p) {\n        ps.emplace_back(p);\n    }\n\n    void build() {\n        for\
    \ (auto [x, y] : ps) {\n            xs.add(x);\n        }\n        xs.build();\n\
    \        sz = std::bit_ceil((unsigned int)xs.size());\n        ys.resize(2 * sz);\n\
    \        for (auto [x, y] : ps) {\n            int i = xs.get(x) + sz;\n     \
    \       ys[i].add(y);\n            while (i > 1) {\n                i >>= 1;\n\
    \                ys[i].add(y);\n            }\n        }\n        for (auto i\
    \ : std::views::iota(0, 2 * sz)) {\n            ys[i].build();\n            seg.emplace_back(dual_segtree<F,\
    \ merge, id>(ys[i].size()));\n        }\n    }\n\n    F get(int i, int j) {\n\
    \        i = xs.get(i) + sz;\n        F x = seg[i].get(ys[i].get(j));\n      \
    \  while (i > 1) {\n            i >>= 1;\n            x = merge(x, seg[i].get(ys[i].get(j)));\n\
    \        }\n        return x;\n    }\n\n    void apply(int l, int d, int r, int\
    \ u, F f) {\n        l = xs.get(l) + sz;\n        r = xs.get(r) + sz;\n      \
    \  while (l < r) {\n            if (l & 1) {\n                seg[l].apply(ys[l].get(d),\
    \ ys[l].get(u), f);\n                l++;\n            }\n            if (r &\
    \ 1) {\n                r--;\n                seg[r].apply(ys[r].get(d), ys[r].get(u),\
    \ f);\n            }\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \    }\n\n  private:\n    int sz = 1;\n    std::vector<std::pair<int, int>> ps;\n\
    \    compress<int> xs;\n    std::vector<compress<int>> ys;\n    std::vector<dual_segtree<F,\
    \ merge, id>> seg;\n};\n\n}  // namespace ebi\n#line 1 \"template/template.hpp\"\
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
    \n\n#line 5 \"template/utility.hpp\"\n\n#line 2 \"graph/base.hpp\"\n\n#line 7\
    \ \"graph/base.hpp\"\n\n#line 2 \"data_structure/simple_csr.hpp\"\n\n#line 6 \"\
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
    \ id;\n};\n\ntemplate <class E> struct Graph {\n  private:\n    using cost_type\
    \ = E;\n    using edge_type = Edge<cost_type>;\n\n  public:\n    Graph(int n_)\
    \ : n(n_) {}\n\n    Graph() = default;\n\n    void add_edge(int u, int v, cost_type\
    \ c) {\n        edges.emplace_back(u, edge_type{u, v, c, m++});\n    }\n\n   \
    \ void read_tree(int offset = 1, bool is_weighted = false) {\n        read_graph(n\
    \ - 1, offset, false, is_weighted);\n    }\n\n    void read_parents(int offset\
    \ = 1) {\n        for (auto i : std::views::iota(1, n)) {\n            int p;\n\
    \            std::cin >> p;\n            p -= offset;\n            add_edge(p,\
    \ i, 1);\n            add_edge(i, p, 1);\n        }\n        build();\n    }\n\
    \n    void read_graph(int e, int offset = 1, bool is_directed = false,\n     \
    \               bool is_weighted = false) {\n        for (int i = 0; i < e; i++)\
    \ {\n            int u, v;\n            std::cin >> u >> v;\n            u -=\
    \ offset;\n            v -= offset;\n            if (is_weighted) {\n        \
    \        cost_type c;\n                std::cin >> c;\n                add_edge(u,\
    \ v, c);\n                if (!is_directed) {\n                    add_edge(v,\
    \ u, c);\n                }\n            } else {\n                add_edge(u,\
    \ v, 1);\n                if (!is_directed) {\n                    add_edge(v,\
    \ u, 1);\n                }\n            }\n        }\n        build();\n    }\n\
    \n    void build() {\n        assert(!prepared);\n        csr = simple_csr<edge_type>(n,\
    \ edges);\n        edges.clear();\n        prepared = true;\n    }\n\n    int\
    \ size() const {\n        return n;\n    }\n\n    const auto operator[](int i)\
    \ const {\n        return csr[i];\n    }\n    auto operator[](int i) {\n     \
    \   return csr[i];\n    }\n\n  private:\n    int n, m = 0;\n\n    std::vector<std::pair<int,\
    \ edge_type>> edges;\n    simple_csr<edge_type> csr;\n    bool prepared = false;\n\
    };\n\n}  // namespace ebi\n#line 8 \"template/utility.hpp\"\n\nnamespace ebi {\n\
    \ntemplate <class T> inline bool chmin(T &a, T b) {\n    if (a > b) {\n      \
    \  a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate <class\
    \ T> inline bool chmax(T &a, T b) {\n    if (a < b) {\n        a = b;\n      \
    \  return true;\n    }\n    return false;\n}\n\ntemplate <class T> T safe_ceil(T\
    \ a, T b) {\n    if (a % b == 0)\n        return a / b;\n    else if (a >= 0)\n\
    \        return (a / b) + 1;\n    else\n        return -((-a) / b);\n}\n\ntemplate\
    \ <class T> T safe_floor(T a, T b) {\n    if (a % b == 0)\n        return a /\
    \ b;\n    else if (a >= 0)\n        return a / b;\n    else\n        return -((-a)\
    \ / b) - 1;\n}\n\nconstexpr i64 LNF = std::numeric_limits<i64>::max() / 4;\n\n\
    constexpr int INF = std::numeric_limits<int>::max() / 2;\n\nconst std::vector<int>\
    \ dy = {1, 0, -1, 0, 1, 1, -1, -1};\nconst std::vector<int> dx = {0, 1, 0, -1,\
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 5 \"test/data_structure/Rectangle_Add_Point_Get.test.cpp\"\
    \n\nnamespace ebi {\n\ni64 merge(i64 a, i64 b) {\n    return a + b;\n}\n\ni64\
    \ id() {\n    return 0;\n}\n\nstruct Query {\n    int t;\n    int l, d, r, u;\n\
    \    i64 w;\n    int x, y;\n};\n\nvoid main_() {\n    int n, q;\n    std::cin\
    \ >> n >> q;\n    offline_dual_segtree_2d<i64, merge, id> seg;\n    std::vector<std::tuple<int,\
    \ int, int, int, i64>> s(n);\n    for (auto &[l, d, r, u, w] : s) {\n        std::cin\
    \ >> l >> d >> r >> u >> w;\n    }\n    std::vector<Query> qs(q);\n    for (auto\
    \ &[t, l, d, r, u, w, x, y] : qs) {\n        std::cin >> t;\n        if (t ==\
    \ 0) {\n            std::cin >> l >> d >> r >> u >> w;\n        } else {\n   \
    \         std::cin >> x >> y;\n            seg.pre_set({x, y});\n        }\n \
    \   }\n    seg.build();\n    for (auto [l, d, r, u, w] : s) {\n        seg.apply(l,\
    \ d, r, u, w);\n    }\n    for (auto &[t, l, d, r, u, w, x, y] : qs) {\n     \
    \   if (t == 0) {\n            seg.apply(l, d, r, u, w);\n        } else {\n \
    \           std::cout << seg.get(x, y) << '\\n';\n        }\n    }\n}\n\n}  //\
    \ namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n    // std::cin\
    \ >> t;\n    while (t--) {\n        ebi::main_();\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_add_point_get\"\
    \n\n#include \"../../data_structure/offline_dual_segtree_2d.hpp\"\n#include \"\
    ../../template/template.hpp\"\n\nnamespace ebi {\n\ni64 merge(i64 a, i64 b) {\n\
    \    return a + b;\n}\n\ni64 id() {\n    return 0;\n}\n\nstruct Query {\n    int\
    \ t;\n    int l, d, r, u;\n    i64 w;\n    int x, y;\n};\n\nvoid main_() {\n \
    \   int n, q;\n    std::cin >> n >> q;\n    offline_dual_segtree_2d<i64, merge,\
    \ id> seg;\n    std::vector<std::tuple<int, int, int, int, i64>> s(n);\n    for\
    \ (auto &[l, d, r, u, w] : s) {\n        std::cin >> l >> d >> r >> u >> w;\n\
    \    }\n    std::vector<Query> qs(q);\n    for (auto &[t, l, d, r, u, w, x, y]\
    \ : qs) {\n        std::cin >> t;\n        if (t == 0) {\n            std::cin\
    \ >> l >> d >> r >> u >> w;\n        } else {\n            std::cin >> x >> y;\n\
    \            seg.pre_set({x, y});\n        }\n    }\n    seg.build();\n    for\
    \ (auto [l, d, r, u, w] : s) {\n        seg.apply(l, d, r, u, w);\n    }\n   \
    \ for (auto &[t, l, d, r, u, w, x, y] : qs) {\n        if (t == 0) {\n       \
    \     seg.apply(l, d, r, u, w);\n        } else {\n            std::cout << seg.get(x,\
    \ y) << '\\n';\n        }\n    }\n}\n\n}  // namespace ebi\n\nint main() {\n \
    \   ebi::fast_io();\n    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n\
    \        ebi::main_();\n    }\n    return 0;\n}"
  dependsOn:
  - data_structure/offline_dual_segtree_2d.hpp
  - data_structure/compress.hpp
  - data_structure/dual_segtree.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: true
  path: test/data_structure/Rectangle_Add_Point_Get.test.cpp
  requiredBy: []
  timestamp: '2024-03-13 01:30:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Rectangle_Add_Point_Get.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Rectangle_Add_Point_Get.test.cpp
- /verify/test/data_structure/Rectangle_Add_Point_Get.test.cpp.html
title: test/data_structure/Rectangle_Add_Point_Get.test.cpp
---
