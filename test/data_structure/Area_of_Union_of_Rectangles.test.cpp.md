---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/area_of_union_of_rectangles.hpp
    title: Area of Union of Rectangles
  - icon: ':question:'
    path: data_structure/compress.hpp
    title: Compress
  - icon: ':question:'
    path: data_structure/lazy_segtree.hpp
    title: lazy segtree
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
    PROBLEM: https://judge.yosupo.jp/problem/area_of_union_of_rectangles
    links:
    - https://judge.yosupo.jp/problem/area_of_union_of_rectangles
  bundledCode: "#line 1 \"test/data_structure/Area_of_Union_of_Rectangles.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\
    \n\n#line 2 \"data_structure/area_of_union_of_rectangles.hpp\"\n\n#include <cassert>\n\
    #include <limits>\n#include <vector>\n\n#line 2 \"data_structure/compress.hpp\"\
    \n\n#include <algorithm>\n#line 6 \"data_structure/compress.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <class T> struct compress {\n  private:\n    std::vector<T>\
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
    \        return cp[idx];\n    }\n};\n\n}  // namespace ebi\n#line 2 \"data_structure/lazy_segtree.hpp\"\
    \n\r\n/*\r\n    reference:\r\n   https://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html\r\
    \n*/\r\n\r\n#include <bit>\r\n#line 10 \"data_structure/lazy_segtree.hpp\"\n#include\
    \ <cstdint>\r\n#include <ranges>\r\n#line 13 \"data_structure/lazy_segtree.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class S, S (*op)(S, S), S (*e)(), class\
    \ F, S (*mapping)(F, S),\r\n          F (*composition)(F, F), F (*id)()>\r\nstruct\
    \ lazy_segtree {\r\n  private:\r\n    void update(int i) {\r\n        data[i]\
    \ = op(data[2 * i], data[2 * i + 1]);\r\n    }\r\n\r\n    void all_apply(int k,\
    \ F f) {\r\n        data[k] = mapping(f, data[k]);\r\n        if (k < sz) lazy[k]\
    \ = composition(f, lazy[k]);\r\n    }\r\n\r\n    void push(int i) {\r\n      \
    \  all_apply(2 * i, lazy[i]);\r\n        all_apply(2 * i + 1, lazy[i]);\r\n  \
    \      lazy[i] = id();\r\n    }\r\n\r\n  public:\r\n    lazy_segtree(int n_) :\
    \ lazy_segtree(std::vector<S>(n_, e())) {}\r\n    lazy_segtree(const std::vector<S>\
    \ &a)\r\n        : n(a.size()),\r\n          sz(std::bit_ceil(a.size())),\r\n\
    \          lg2(std::countr_zero(std::uint32_t(sz))) {\r\n        data = std::vector<S>(2\
    \ * sz, e());\r\n        lazy = std::vector<F>(sz, id());\r\n        for (int\
    \ i : std::views::iota(0, n)) {\r\n            data[sz + i] = a[i];\r\n      \
    \  }\r\n        for (int i : std::views::iota(1, sz) | std::views::reverse) {\r\
    \n            update(i);\r\n        }\r\n    }\r\n\r\n    void set(int p, S x)\
    \ {\r\n        assert(0 <= p && p < n);\r\n        p += sz;\r\n        for (int\
    \ i = lg2; i >= 1; i--) push(p >> i);\r\n        data[p] = x;\r\n        for (int\
    \ i = 1; i <= lg2; i++) update(p >> i);\r\n    }\r\n\r\n    S get(int p) {\r\n\
    \        assert(0 <= p && p < n);\r\n        p += sz;\r\n        for (int i =\
    \ lg2; i >= 1; i--) push(p >> i);\r\n        return data[p];\r\n    }\r\n\r\n\
    \    S prod(int l, int r) {\r\n        assert(0 <= l && l <= r && r <= n);\r\n\
    \        if (l == r) return e();\r\n\r\n        l += sz;\r\n        r += sz;\r\
    \n\r\n        for (int i = lg2; i >= 1; i--) {\r\n            if (((l >> i) <<\
    \ i) != l) push(l >> i);\r\n            if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\r\n        }\r\n\r\n        S sml = e(), smr = e();\r\n        while\
    \ (l < r) {\r\n            if (l & 1) sml = op(sml, data[l++]);\r\n          \
    \  if (r & 1) smr = op(data[--r], smr);\r\n            l >>= 1;\r\n          \
    \  r >>= 1;\r\n        }\r\n\r\n        return op(sml, smr);\r\n    }\r\n\r\n\
    \    S all_prod() const {\r\n        return data[1];\r\n    }\r\n\r\n    void\
    \ apply(int p, F f) {\r\n        assert(0 <= p && p < n);\r\n        p += sz;\r\
    \n        for (int i = lg2; i >= 1; i--) push(p >> i);\r\n        data[p] = mapping(f,\
    \ data[p]);\r\n        for (int i = 1; i <= lg2; i++) update(p >> i);\r\n    }\r\
    \n\r\n    void apply(int l, int r, F f) {\r\n        assert(0 <= l && l <= r &&\
    \ r <= n);\r\n        l += sz;\r\n        r += sz;\r\n        for (int i = lg2;\
    \ i >= 1; i--) {\r\n            if (((l >> i) << i) != l) push(l >> i);\r\n  \
    \          if (((r >> i) << i) != r) push((r - 1) >> i);\r\n        }\r\n\r\n\
    \        {\r\n            int memo_l = l, memo_r = r;\r\n            while (l\
    \ < r) {\r\n                if (l & 1) all_apply(l++, f);\r\n                if\
    \ (r & 1) all_apply(--r, f);\r\n                l >>= 1;\r\n                r\
    \ >>= 1;\r\n            }\r\n            l = memo_l;\r\n            r = memo_r;\r\
    \n        }\r\n\r\n        for (int i = 1; i <= lg2; i++) {\r\n            if\
    \ (((l >> i) << i) != l) update(l >> i);\r\n            if (((r >> i) << i) !=\
    \ r) update((r - 1) >> i);\r\n        }\r\n    }\r\n\r\n    template <class G>\
    \ int max_right(int l, G g) {\r\n        assert(0 <= l && l <= n);\r\n       \
    \ assert(g(e()));\r\n        if (l == n) return n;\r\n        l += sz;\r\n   \
    \     for (int i = lg2; i >= 1; i--) push(l >> i);\r\n        S sm = e();\r\n\
    \        do {\r\n            while (l % 2 == 0) l >>= 1;\r\n            if (!g(op(sm,\
    \ data[l]))) {\r\n                while (l < sz) {\r\n                    push(l);\r\
    \n                    l = l << 1;\r\n                    if (g(op(sm, data[l])))\
    \ {\r\n                        sm = op(sm, data[l]);\r\n                     \
    \   l++;\r\n                    }\r\n                }\r\n                return\
    \ l - sz;\r\n            }\r\n            sm = op(sm, data[l]);\r\n          \
    \  l++;\r\n        } while ((l & -l) != l);\r\n        return n;\r\n    }\r\n\r\
    \n    template <class G> int min_left(int r, G g) {\r\n        assert(0 <= r &&\
    \ r <= n);\r\n        assert(g(e()));\r\n        if (r == 0) return 0;\r\n   \
    \     r += sz;\r\n        for (int i = lg2; i >= 1; i--) push((r - 1) >> i);\r\
    \n        S sm = e();\r\n        do {\r\n            r--;\r\n            while\
    \ (r > 1 && r % 2) r >>= 1;\r\n            if (!g(op(data[r], sm))) {\r\n    \
    \            while (r < sz) {\r\n                    push(r);\r\n            \
    \        r = (r << 1) + 1;\r\n                    if (g(op(data[r], sm))) {\r\n\
    \                        sm = op(data[r], sm);\r\n                        r--;\r\
    \n                    }\r\n                }\r\n                return r + 1 -\
    \ sz;\r\n            }\r\n            sm = op(data[r], sm);\r\n        } while\
    \ ((r & -r) != r);\r\n        return 0;\r\n    }\r\n\r\n  private:\r\n    int\
    \ n, sz, lg2;\r\n    std::vector<S> data;\r\n    std::vector<F> lazy;\r\n};\r\n\
    \r\n}  // namespace ebi\r\n#line 2 \"template/int_alias.hpp\"\n\n#line 4 \"template/int_alias.hpp\"\
    \n\nnamespace ebi {\n\nusing ld = long double;\nusing std::size_t;\nusing i8 =\
    \ std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing u16\
    \ = std::uint16_t;\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing\
    \ i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\n}  // namespace ebi\n#line 10 \"data_structure/area_of_union_of_rectangles.hpp\"\
    \n\nnamespace ebi {\n\nstruct area_of_union_of_rectangles {\n  private:\n    using\
    \ S = std::pair<int, i64>;\n\n    static S op(S a, S b) {\n        if (a.first\
    \ == b.first)\n            return {a.first, a.second + b.second};\n        else\
    \ if (a.first < b.first)\n            return a;\n        else\n            return\
    \ b;\n    }\n\n    static S e() {\n        return {std::numeric_limits<int>::max(),\
    \ 0};\n    }\n\n    static S mapping(int f, S x) {\n        return {x.first +\
    \ f, x.second};\n    }\n\n    static int composition(int f, int g) {\n       \
    \ return f + g;\n    }\n\n    static int id() {\n        return 0;\n    }\n\n\
    \  public:\n    area_of_union_of_rectangles() = default;\n\n    void add_rectangle(i64\
    \ l, i64 d, i64 r, i64 u) {\n        qs.push_back({l, d, r, u});\n        cp_x.add(l);\n\
    \        cp_x.add(r);\n        cp_y.add(d);\n        cp_y.add(u);\n    }\n\n \
    \   i64 run() {\n        assert(is_first);\n        is_first = false;\n      \
    \  cp_x.build();\n        cp_y.build();\n        int n = cp_x.size(), m = cp_y.size();\n\
    \        lazy_segtree<S, op, e, int, mapping, composition, id> seg(\n        \
    \    [&]() -> std::vector<S> {\n                std::vector<S> data(m - 1);\n\
    \                for (int i = 0; i < m - 1; i++) {\n                    data[i]\
    \ = {0, cp_y.val(i + 1) - cp_y.val(i)};\n                }\n                return\
    \ data;\n            }());\n        std::vector table(n,\n                   \
    \       std::vector(2, std::vector<std::pair<i64, i64>>()));\n        for (auto\
    \ [l, d, r, u] : qs) {\n            int x = cp_y.get(d);\n            int y =\
    \ cp_y.get(u);\n            table[cp_x.get(l)][0].emplace_back(x, y);\n      \
    \      table[cp_x.get(r)][1].emplace_back(x, y);\n        }\n        i64 ans =\
    \ 0;\n        for (int i = 0; i < n - 1; i++) {\n            i64 wy = cp_y.val(m\
    \ - 1) - cp_y.val(0);\n            i64 wx = cp_x.val(i + 1) - cp_x.val(i);\n \
    \           for (auto [d, u] : table[i][0]) {\n                seg.apply(d, u,\
    \ 1);\n            }\n            for (auto [d, u] : table[i][1]) {\n        \
    \        seg.apply(d, u, -1);\n            }\n            auto [min, cnt] = seg.all_prod();\n\
    \            if (min == 0) wy -= cnt;\n            ans += wx * wy;\n        }\n\
    \        return ans;\n    }\n\n  private:\n    bool is_first = true;\n    std::vector<std::array<i64,\
    \ 4>> qs;\n    compress<i64> cp_x, cp_y;\n};\n\n}  // namespace ebi\n#line 4 \"\
    test/data_structure/Area_of_Union_of_Rectangles.test.cpp\"\n\n#line 1 \"template/template.hpp\"\
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
    \ :\";\n    debug_out(t...);\n}\n\n}  // namespace ebi\n#line 2 \"template/io.hpp\"\
    \n\n#line 5 \"template/io.hpp\"\n#include <optional>\n#line 7 \"template/io.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <typename T1, typename T2>\nstd::ostream &operator<<(std::ostream\
    \ &os, const std::pair<T1, T2> &pa) {\n    return os << pa.first << \" \" << pa.second;\n\
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
    \n\n#line 2 \"graph/base.hpp\"\n\n#line 7 \"graph/base.hpp\"\n\n#line 2 \"data_structure/simple_csr.hpp\"\
    \n\n#line 6 \"data_structure/simple_csr.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ E> struct simple_csr {\n    simple_csr() = default;\n\n    simple_csr(int n,\
    \ const std::vector<std::pair<int, E>>& elements)\n        : start(n + 1, 0),\
    \ elist(elements.size()) {\n        for (auto e : elements) {\n            start[e.first\
    \ + 1]++;\n        }\n        for (auto i : std::views::iota(0, n)) {\n      \
    \      start[i + 1] += start[i];\n        }\n        auto counter = start;\n \
    \       for (auto [i, e] : elements) {\n            elist[counter[i]++] = e;\n\
    \        }\n    }\n\n    simple_csr(const std::vector<std::vector<E>>& es)\n \
    \       : start(es.size() + 1, 0) {\n        int n = es.size();\n        for (auto\
    \ i : std::views::iota(0, n)) {\n            start[i + 1] = (int)es[i].size()\
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
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 6 \"test/data_structure/Area_of_Union_of_Rectangles.test.cpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    int n;\n    std::cin >> n;\n    area_of_union_of_rectangles\
    \ solver;\n    rep(i, 0, n) {\n        i64 l, d, r, u;\n        std::cin >> l\
    \ >> d >> r >> u;\n        solver.add_rectangle(l, d, r, u);\n    }\n    std::cout\
    \ << solver.run() << '\\n';\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n\
    \    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\
    \n\n#include \"../../data_structure/area_of_union_of_rectangles.hpp\"\n\n#include\
    \ \"../../template/template.hpp\"\n\nnamespace ebi {\n\nvoid main_() {\n    int\
    \ n;\n    std::cin >> n;\n    area_of_union_of_rectangles solver;\n    rep(i,\
    \ 0, n) {\n        i64 l, d, r, u;\n        std::cin >> l >> d >> r >> u;\n  \
    \      solver.add_rectangle(l, d, r, u);\n    }\n    std::cout << solver.run()\
    \ << '\\n';\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n \
    \   int t = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n\
    \    }\n    return 0;\n}"
  dependsOn:
  - data_structure/area_of_union_of_rectangles.hpp
  - data_structure/compress.hpp
  - data_structure/lazy_segtree.hpp
  - template/int_alias.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/io.hpp
  - template/utility.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: true
  path: test/data_structure/Area_of_Union_of_Rectangles.test.cpp
  requiredBy: []
  timestamp: '2024-04-25 16:41:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Area_of_Union_of_Rectangles.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Area_of_Union_of_Rectangles.test.cpp
- /verify/test/data_structure/Area_of_Union_of_Rectangles.test.cpp.html
title: test/data_structure/Area_of_Union_of_Rectangles.test.cpp
---
