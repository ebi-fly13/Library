---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/segtree.hpp
    title: segtree
  - icon: ':question:'
    path: graph/template.hpp
    title: graph/template.hpp
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
  bundledCode: "#line 1 \"test/data_structure/Vertex_Add_Subtree_Sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n\
    #include <iostream>\n#include <vector>\n\n#line 2 \"data_structure/segtree.hpp\"\
    \n\r\n#include <cassert>\r\n#line 5 \"data_structure/segtree.hpp\"\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <class S, S (*op)(S, S), S (*e)()> struct segtree {\r\n\
    \  private:\r\n    int n;\r\n    int sz;\r\n    std::vector<S> data;\r\n\r\n \
    \   void update(int i) {\r\n        data[i] = op(data[2 * i], data[2 * i + 1]);\r\
    \n    }\r\n\r\n  public:\r\n    segtree(int n) : segtree(std::vector<S>(n, e()))\
    \ {}\r\n    segtree(const std::vector<S> &v) : n((int)v.size()), sz(1) {\r\n \
    \       while (sz < n) sz *= 2;\r\n        data = std::vector<S>(2 * sz, e());\r\
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
    \ ebi\n#line 2 \"tree/heavy_light_decomposition.hpp\"\n\n#include <algorithm>\n\
    #line 6 \"tree/heavy_light_decomposition.hpp\"\n\nnamespace ebi {\n\nstruct heavy_light_decomposition\
    \ {\n  private:\n    void dfs_sz(int v) {\n        for (auto &nv : g[v]) {\n \
    \           if (nv == par[v]) continue;\n            par[nv] = v;\n          \
    \  depth[nv] = depth[v] + 1;\n            dfs_sz(nv);\n            sz[v] += sz[nv];\n\
    \            if (sz[nv] > sz[g[v][0]] || g[v][0] == par[v])\n                std::swap(nv,\
    \ g[v][0]);\n        }\n    }\n\n    void dfs_hld(int v) {\n        static int\
    \ t = 0;\n        in[v] = t++;\n        rev[in[v]] = v;\n        for (auto nv\
    \ : g[v]) {\n            if (nv == par[v]) continue;\n            nxt[nv] = (nv\
    \ == g[v][0] ? nxt[v] : nv);\n            dfs_hld(nv);\n        }\n        out[v]\
    \ = t;\n    }\n\n    // [u, v) \u30D1\u30B9\u306E\u53D6\u5F97 (v \u306F u \u306E\
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
    \ 0)\n        : n(gh.size()),\n          g(gh),\n          sz(n, 1),\n       \
    \   in(n),\n          out(n),\n          nxt(n),\n          par(n, -1),\n    \
    \      depth(n, 0),\n          rev(n) {\n        dfs_sz(root);\n        dfs_hld(root);\n\
    \    }\n\n    int idx(int u) const {\n        return in[u];\n    }\n\n    int\
    \ la(int v, int k) const {\n        while (1) {\n            int u = nxt[v];\n\
    \            if (in[u] <= in[v] - k) return rev[in[v] - k];\n            k -=\
    \ in[v] - in[u] + 1;\n            v = par[u];\n        }\n    }\n\n    int lca(int\
    \ u, int v) const {\n        while (nxt[u] != nxt[v]) {\n            if (in[u]\
    \ < in[v]) std::swap(u, v);\n            u = par[nxt[u]];\n        }\n       \
    \ return depth[u] < depth[v] ? u : v;\n    }\n\n    int jump(int s, int t, int\
    \ i) const {\n        if (i == 0) return s;\n        int l = lca(s, t);\n    \
    \    int d = depth[s] + depth[t] - depth[l] * 2;\n        if (d < i) return -1;\n\
    \        if (depth[s] - depth[l] >= i) return la(s, i);\n        i = d - i;\n\
    \        return la(t, i);\n    }\n\n    std::vector<int> path(int s, int t) const\
    \ {\n        int l = lca(s, t);\n        std::vector<int> a, b;\n        for (;\
    \ s != l; s = par[s]) a.emplace_back(s);\n        for (; t != l; t = par[t]) b.emplace_back(t);\n\
    \        a.emplace_back(l);\n        std::reverse(b.begin(), b.end());\n     \
    \   a.insert(a.end(), b.begin(), b.end());\n        return a;\n    }\n\n    int\
    \ distance(int u, int v) const {\n        return depth[u] + depth[v] - 2 * depth[lca(u,\
    \ v)];\n    }\n\n    int distance_from_root(int v) const {\n        return depth[v];\n\
    \    }\n\n    bool at_path(int u, int v, int s) const {\n        return distance(u,\
    \ v) == distance(u, s) + distance(s, v);\n    }\n\n    template <class F>\n  \
    \  void path_noncommutative_query(int u, int v, bool vertex,\n               \
    \                    const F &f) const {\n        int l = lca(u, v);\n       \
    \ for (auto [a, b] : ascend(u, l)) f(a + 1, b);\n        if (vertex) f(in[l],\
    \ in[l] + 1);\n        for (auto [a, b] : descend(l, v)) f(a, b + 1);\n    }\n\
    \n    template <class F> void subtree_query(int u, bool vertex, const F &f) {\n\
    \        f(in[u] + int(!vertex), out[u]);\n    }\n\n  private:\n    int n;\n \
    \   std::vector<std::vector<int>> g;\n    std::vector<int> sz, in, out, nxt, par,\
    \ depth, rev;\n};\n\n}  // namespace ebi\n#line 9 \"test/data_structure/Vertex_Add_Subtree_Sum.test.cpp\"\
    \n\nusing i64 = std::int64_t;\ni64 op(i64 a, i64 b) {\n    return a + b;\n}\n\
    i64 e() {\n    return 0;\n}\n\nint main() {\n    int n, q;\n    std::cin >> n\
    \ >> q;\n    std::vector<i64> a(n);\n    for (int i = 0; i < n; ++i) {\n     \
    \   std::cin >> a[i];\n    }\n    ebi::graph g(n);\n    for (int i = 1; i < n;\
    \ ++i) {\n        int p;\n        std::cin >> p;\n        g.add_edge(p, i);\n\
    \    }\n    ebi::heavy_light_decomposition hld(g);\n    ebi::segtree<i64, op,\
    \ e> seg(n);\n    auto set = [&](int u, i64 x) {\n        int idx = hld.idx(u);\n\
    \        seg.set(idx, seg.get(idx) + x);\n    };\n    for (int i = 0; i < n; i++)\
    \ set(i, a[i]);\n    i64 ans = 0;\n    auto f = [&](int l, int r) { ans = op(ans,\
    \ seg.prod(l, r)); };\n    while (q--) {\n        int flag;\n        std::cin\
    \ >> flag;\n        if (flag == 0) {\n            int u;\n            i64 x;\n\
    \            std::cin >> u >> x;\n            set(u, x);\n        } else {\n \
    \           int u;\n            std::cin >> u;\n            ans = e();\n     \
    \       hld.subtree_query(u, true, f);\n            std::cout << ans << '\\n';\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../data_structure/segtree.hpp\"\
    \n#include \"../../graph/template.hpp\"\n#include \"../../tree/heavy_light_decomposition.hpp\"\
    \n\nusing i64 = std::int64_t;\ni64 op(i64 a, i64 b) {\n    return a + b;\n}\n\
    i64 e() {\n    return 0;\n}\n\nint main() {\n    int n, q;\n    std::cin >> n\
    \ >> q;\n    std::vector<i64> a(n);\n    for (int i = 0; i < n; ++i) {\n     \
    \   std::cin >> a[i];\n    }\n    ebi::graph g(n);\n    for (int i = 1; i < n;\
    \ ++i) {\n        int p;\n        std::cin >> p;\n        g.add_edge(p, i);\n\
    \    }\n    ebi::heavy_light_decomposition hld(g);\n    ebi::segtree<i64, op,\
    \ e> seg(n);\n    auto set = [&](int u, i64 x) {\n        int idx = hld.idx(u);\n\
    \        seg.set(idx, seg.get(idx) + x);\n    };\n    for (int i = 0; i < n; i++)\
    \ set(i, a[i]);\n    i64 ans = 0;\n    auto f = [&](int l, int r) { ans = op(ans,\
    \ seg.prod(l, r)); };\n    while (q--) {\n        int flag;\n        std::cin\
    \ >> flag;\n        if (flag == 0) {\n            int u;\n            i64 x;\n\
    \            std::cin >> u >> x;\n            set(u, x);\n        } else {\n \
    \           int u;\n            std::cin >> u;\n            ans = e();\n     \
    \       hld.subtree_query(u, true, f);\n            std::cout << ans << '\\n';\n\
    \        }\n    }\n}"
  dependsOn:
  - data_structure/segtree.hpp
  - graph/template.hpp
  - tree/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: test/data_structure/Vertex_Add_Subtree_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-08-10 12:11:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Vertex_Add_Subtree_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Vertex_Add_Subtree_Sum.test.cpp
- /verify/test/data_structure/Vertex_Add_Subtree_Sum.test.cpp.html
title: test/data_structure/Vertex_Add_Subtree_Sum.test.cpp
---
