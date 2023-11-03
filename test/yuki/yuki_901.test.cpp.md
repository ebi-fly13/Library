---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: segtree
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
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
    path: tree/heavy_light_decomposition.hpp
    title: Heavy Light Decomposition
  - icon: ':heavy_check_mark:'
    path: tree/lca_based_auxiliary_tree.hpp
    title: LCA based Auxiliary Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/901
    links:
    - https://yukicoder.me/problems/no/901
  bundledCode: "#line 1 \"test/yuki/yuki_901.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/901\"\
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
    \ ebi\r\n#line 2 \"graph/template.hpp\"\n\r\n#line 4 \"graph/template.hpp\"\n\r\
    \nnamespace ebi {\r\n\r\ntemplate <class T> struct Edge {\r\n    int to;\r\n \
    \   T cost;\r\n    Edge(int _to, T _cost = 1) : to(_to), cost(_cost) {}\r\n};\r\
    \n\r\ntemplate <class T> struct Graph : std::vector<std::vector<Edge<T>>> {\r\n\
    \    using std::vector<std::vector<Edge<T>>>::vector;\r\n    void add_edge(int\
    \ u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if (directed) return;\r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if (directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\n#line 1 \"template/template.hpp\"\n#include <algorithm>\n#include <bit>\n\
    #include <bitset>\n#line 5 \"template/template.hpp\"\n#include <chrono>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <cstdlib>\n#include <cstring>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <limits>\n#include <map>\n#include\
    \ <memory>\n#include <numbers>\n#include <numeric>\n#include <optional>\n#include\
    \ <queue>\n#include <random>\n#include <ranges>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#include <type_traits>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#line 34 \"template/template.hpp\"\
    \n\n#define rep(i, a, n) for (int i = (int)(a); i < (int)(n); i++)\n#define rrep(i,\
    \ a, n) for (int i = ((int)(n)-1); i >= (int)(a); i--)\n#define Rep(i, a, n) for\
    \ (i64 i = (i64)(a); i < (i64)(n); i++)\n#define RRep(i, a, n) for (i64 i = ((i64)(n)-i64(1));\
    \ i >= (i64)(a); i--)\n#define all(v) (v).begin(), (v).end()\n#define rall(v)\
    \ (v).rbegin(), (v).rend()\n\n#line 2 \"template/debug_template.hpp\"\n\n#line\
    \ 4 \"template/debug_template.hpp\"\n\nnamespace ebi {\n\n#ifdef LOCAL\n#define\
    \ debug(...)                                                      \\\n    std::cerr\
    \ << \"LINE: \" << __LINE__ << \"  [\" << #__VA_ARGS__ << \"]:\", \\\n       \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\nvoid debug_out()\
    \ {\n    std::cerr << std::endl;\n}\n\ntemplate <typename Head, typename... Tail>\
    \ void debug_out(Head h, Tail... t) {\n    std::cerr << \" \" << h;\n    if (sizeof...(t)\
    \ > 0) std::cerr << \" :\";\n    debug_out(t...);\n}\n\n}  // namespace ebi\n\
    #line 2 \"template/int_alias.hpp\"\n\n#line 4 \"template/int_alias.hpp\"\n\nnamespace\
    \ ebi {\n\nusing std::size_t;\nusing i8 = std::int8_t;\nusing u8 = std::uint8_t;\n\
    using i16 = std::int16_t;\nusing u16 = std::uint16_t;\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
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
    \n\n#line 7 \"template/utility.hpp\"\n\nnamespace ebi {\n\ntemplate <class T>\
    \ inline bool chmin(T &a, T b) {\n    if (a > b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n\ntemplate <class T> inline bool chmax(T\
    \ &a, T b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\n\ntemplate <class T> T safe_ceil(T a, T b) {\n    if (a\
    \ % b == 0)\n        return a / b;\n    else if (a >= 0)\n        return (a /\
    \ b) + 1;\n    else\n        return -((-a) / b);\n}\n\ntemplate <class T> T safe_floor(T\
    \ a, T b) {\n    if (a % b == 0)\n        return a / b;\n    else if (a >= 0)\n\
    \        return a / b;\n    else\n        return -((-a) / b) - 1;\n}\n\nconstexpr\
    \ i64 LNF = std::numeric_limits<i64>::max() / 4;\n\nconstexpr int INF = std::numeric_limits<int>::max()\
    \ / 2;\n\nconst std::vector<int> dy = {1, 0, -1, 0, 1, 1, -1, -1};\nconst std::vector<int>\
    \ dx = {0, 1, 0, -1, 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 2 \"tree/heavy_light_decomposition.hpp\"\
    \n\n#line 6 \"tree/heavy_light_decomposition.hpp\"\n\nnamespace ebi {\n\nstruct\
    \ heavy_light_decomposition {\n  private:\n    void dfs_sz(int v) {\n        for\
    \ (auto &nv : g[v]) {\n            if (nv == par[v]) continue;\n            par[nv]\
    \ = v;\n            depth[nv] = depth[v] + 1;\n            dfs_sz(nv);\n     \
    \       sz[v] += sz[nv];\n            if (sz[nv] > sz[g[v][0]] || g[v][0] == par[v])\n\
    \                std::swap(nv, g[v][0]);\n        }\n    }\n\n    void dfs_hld(int\
    \ v) {\n        in[v] = num++;\n        rev[in[v]] = v;\n        for (auto nv\
    \ : g[v]) {\n            if (nv == par[v]) continue;\n            nxt[nv] = (nv\
    \ == g[v][0] ? nxt[v] : nv);\n            dfs_hld(nv);\n        }\n        out[v]\
    \ = num;\n    }\n\n    // [u, v) \u30D1\u30B9\u306E\u53D6\u5F97 (v \u306F u \u306E\
    \u7956\u5148)\n    std::vector<std::pair<int, int>> ascend(int u, int v) const\
    \ {\n        std::vector<std::pair<int, int>> res;\n        while (nxt[u] != nxt[v])\
    \ {\n            res.emplace_back(in[u], in[nxt[u]]);\n            u = par[nxt[u]];\n\
    \        }\n        if (u != v) res.emplace_back(in[u], in[v] + 1);\n        return\
    \ res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\u5F97 (u \u306F v \u306E\
    \u7956\u5148)\n    std::vector<std::pair<int, int>> descend(int u, int v) const\
    \ {\n        if (u == v) return {};\n        if (nxt[u] == nxt[v]) return {{in[u]\
    \ + 1, in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n        res.emplace_back(in[nxt[v]],\
    \ in[v]);\n        return res;\n    }\n\n  public:\n    heavy_light_decomposition(const\
    \ std::vector<std::vector<int>> &gh,\n                              int root =\
    \ 0)\n        : n((int)gh.size()),\n          g(gh),\n          sz(n, 1),\n  \
    \        in(n),\n          out(n),\n          nxt(n),\n          par(n, -1),\n\
    \          depth(n, 0),\n          rev(n) {\n        nxt[root] = root;\n     \
    \   dfs_sz(root);\n        dfs_hld(root);\n    }\n\n    int idx(int u) const {\n\
    \        return in[u];\n    }\n\n    int rev_idx(int i) const {\n        return\
    \ rev[i];\n    }\n\n    int la(int v, int k) const {\n        while (1) {\n  \
    \          int u = nxt[v];\n            if (in[u] <= in[v] - k) return rev[in[v]\
    \ - k];\n            k -= in[v] - in[u] + 1;\n            v = par[u];\n      \
    \  }\n    }\n\n    int lca(int u, int v) const {\n        while (nxt[u] != nxt[v])\
    \ {\n            if (in[u] < in[v]) std::swap(u, v);\n            u = par[nxt[u]];\n\
    \        }\n        return depth[u] < depth[v] ? u : v;\n    }\n\n    int jump(int\
    \ s, int t, int i) const {\n        if (i == 0) return s;\n        int l = lca(s,\
    \ t);\n        int d = depth[s] + depth[t] - depth[l] * 2;\n        if (d < i)\
    \ return -1;\n        if (depth[s] - depth[l] >= i) return la(s, i);\n       \
    \ i = d - i;\n        return la(t, i);\n    }\n\n    std::vector<int> path(int\
    \ s, int t) const {\n        int l = lca(s, t);\n        std::vector<int> a, b;\n\
    \        for (; s != l; s = par[s]) a.emplace_back(s);\n        for (; t != l;\
    \ t = par[t]) b.emplace_back(t);\n        a.emplace_back(l);\n        std::reverse(b.begin(),\
    \ b.end());\n        a.insert(a.end(), b.begin(), b.end());\n        return a;\n\
    \    }\n\n    int parent(int u) const {\n        return par[u];\n    }\n\n   \
    \ int distance(int u, int v) const {\n        return depth[u] + depth[v] - 2 *\
    \ depth[lca(u, v)];\n    }\n\n    int distance_from_root(int v) const {\n    \
    \    return depth[v];\n    }\n\n    bool at_path(int u, int v, int s) const {\n\
    \        return distance(u, v) == distance(u, s) + distance(s, v);\n    }\n\n\
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
    \ return rev;\n    }\n\n    std::pair<std::vector<int>, std::vector<std::vector<int>>>\n\
    \    lca_based_auxiliary_tree(std::vector<int> vs) const;\n\n  private:\n    int\
    \ n;\n    std::vector<std::vector<int>> g;\n    std::vector<int> sz, in, out,\
    \ nxt, par, depth, rev;\n\n    int num = 0;\n};\n\n}  // namespace ebi\n#line\
    \ 2 \"tree/lca_based_auxiliary_tree.hpp\"\n\n#line 8 \"tree/lca_based_auxiliary_tree.hpp\"\
    \n\n#line 10 \"tree/lca_based_auxiliary_tree.hpp\"\n\nnamespace ebi {\n\nstd::pair<std::vector<int>,\
    \ std::vector<std::vector<int>>>\nheavy_light_decomposition::lca_based_auxiliary_tree(std::vector<int>\
    \ vs) const {\n    static std::vector<int> a(n, -1), p(n, -1);\n    int k = vs.size();\n\
    \    if (k == 1) {\n        return {vs, std::vector(1, std::vector<int>())};\n\
    \    }\n    std::sort(vs.begin(), vs.end(),\n              [&](int v, int u) {\
    \ return in[v] < in[u]; });\n    std::stack<int> stack;\n    std::vector<int>\
    \ s;\n    stack.push(vs[0]);\n    for (int i : std::views::iota(1, k)) {\n   \
    \     int w = lca(vs[i - 1], vs[i]);\n        int prev = -1;\n        while (!stack.empty()\
    \ && depth[w] <= depth[stack.top()]) {\n            if (prev != -1) {\n      \
    \          s.emplace_back(prev);\n                p[prev] = stack.top();\n   \
    \         }\n            prev = stack.top();\n            stack.pop();\n     \
    \   }\n        if (prev != w) {\n            assert(prev != -1);\n           \
    \ s.emplace_back(prev);\n            p[prev] = w;\n        }\n        stack.push(w);\n\
    \        stack.push(vs[i]);\n    }\n    {\n        int prev = -1;\n        while\
    \ (!stack.empty()) {\n            int v = stack.top();\n            s.emplace_back(v);\n\
    \            if (prev != -1) p[prev] = v;\n            prev = v;\n           \
    \ stack.pop();\n        }\n    }\n    std::reverse(s.begin(), s.end());\n    int\
    \ m = s.size();\n    for (int i : std::views::iota(0, m)) {\n        a[s[i]] =\
    \ i;\n    }\n    std::vector tree(m, std::vector<int>());\n    for (auto v : s)\
    \ {\n        if (p[v] < 0) continue;\n        tree[a[p[v]]].emplace_back(a[v]);\n\
    \    }\n    for (auto v : s) {\n        a[v] = -1;\n        p[v] = -1;\n    }\n\
    \    return {s, tree};\n}\n\n}  // namespace ebi\n#line 8 \"test/yuki/yuki_901.test.cpp\"\
    \n\nnamespace ebi {\n\ni64 op(i64 a, i64 b) {\n    return a + b;\n}\n\ni64 e()\
    \ {\n    return 0;\n}\n\nvoid main_() {\n    int n;\n    std::cin >> n;\n    std::vector<std::array<int,\
    \ 3>> edges(n - 1);\n    graph g(n);\n    for (auto &[u, v, w] : edges) {\n  \
    \      std::cin >> u >> v >> w;\n        g.add_edge(u, v);\n    }\n    heavy_light_decomposition\
    \ hld(g);\n    segtree<i64, op, e> seg(n);\n    for (auto [u, v, w] : edges) {\n\
    \        if (hld.parent(v) == u) std::swap(u, v);\n        seg.set(hld.idx(u),\
    \ w);\n    }\n    auto path_sum = [&](int u, int v) -> i64 {\n        i64 sum\
    \ = 0;\n        auto f = [&](int l, int r) -> void {\n            if (l > r) std::swap(l,\
    \ r);\n            sum += seg.prod(l, r);\n        };\n        hld.path_noncommutative_query(u,\
    \ v, false, f);\n        return sum;\n    };\n    int q;\n    std::cin >> q;\n\
    \    while (q--) {\n        int k;\n        std::cin >> k;\n        std::vector<int>\
    \ vs(k);\n        for (auto &v : vs) std::cin >> v;\n        auto [ids, tree]\
    \ = hld.lca_based_auxiliary_tree(vs);\n        i64 ans = 0;\n        auto dfs\
    \ = [&](auto &&self, int v) -> void {\n            for (auto nv : tree[v]) {\n\
    \                ans += path_sum(ids[v], ids[nv]);\n                self(self,\
    \ nv);\n            }\n        };\n        dfs(dfs, 0);\n        std::cout <<\
    \ ans << '\\n';\n    }\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n\
    \    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/901\"\n\n#include \"../../data_structure/segtree.hpp\"\
    \n#include \"../../graph/template.hpp\"\n#include \"../../template/template.hpp\"\
    \n#include \"../../tree/heavy_light_decomposition.hpp\"\n#include \"../../tree/lca_based_auxiliary_tree.hpp\"\
    \n\nnamespace ebi {\n\ni64 op(i64 a, i64 b) {\n    return a + b;\n}\n\ni64 e()\
    \ {\n    return 0;\n}\n\nvoid main_() {\n    int n;\n    std::cin >> n;\n    std::vector<std::array<int,\
    \ 3>> edges(n - 1);\n    graph g(n);\n    for (auto &[u, v, w] : edges) {\n  \
    \      std::cin >> u >> v >> w;\n        g.add_edge(u, v);\n    }\n    heavy_light_decomposition\
    \ hld(g);\n    segtree<i64, op, e> seg(n);\n    for (auto [u, v, w] : edges) {\n\
    \        if (hld.parent(v) == u) std::swap(u, v);\n        seg.set(hld.idx(u),\
    \ w);\n    }\n    auto path_sum = [&](int u, int v) -> i64 {\n        i64 sum\
    \ = 0;\n        auto f = [&](int l, int r) -> void {\n            if (l > r) std::swap(l,\
    \ r);\n            sum += seg.prod(l, r);\n        };\n        hld.path_noncommutative_query(u,\
    \ v, false, f);\n        return sum;\n    };\n    int q;\n    std::cin >> q;\n\
    \    while (q--) {\n        int k;\n        std::cin >> k;\n        std::vector<int>\
    \ vs(k);\n        for (auto &v : vs) std::cin >> v;\n        auto [ids, tree]\
    \ = hld.lca_based_auxiliary_tree(vs);\n        i64 ans = 0;\n        auto dfs\
    \ = [&](auto &&self, int v) -> void {\n            for (auto nv : tree[v]) {\n\
    \                ans += path_sum(ids[v], ids[nv]);\n                self(self,\
    \ nv);\n            }\n        };\n        dfs(dfs, 0);\n        std::cout <<\
    \ ans << '\\n';\n    }\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n\
    \    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n\
    \    }\n    return 0;\n}"
  dependsOn:
  - data_structure/segtree.hpp
  - graph/template.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  - tree/heavy_light_decomposition.hpp
  - tree/lca_based_auxiliary_tree.hpp
  isVerificationFile: true
  path: test/yuki/yuki_901.test.cpp
  requiredBy: []
  timestamp: '2023-10-31 14:04:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yuki/yuki_901.test.cpp
layout: document
redirect_from:
- /verify/test/yuki/yuki_901.test.cpp
- /verify/test/yuki/yuki_901.test.cpp.html
title: test/yuki/yuki_901.test.cpp
---