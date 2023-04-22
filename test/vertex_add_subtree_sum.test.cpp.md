---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: Segtree
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  - icon: ':heavy_check_mark:'
    path: tree/heavy_light_decomposition.hpp
    title: tree/heavy_light_decomposition.hpp
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
  bundledCode: "#line 1 \"test/vertex_add_subtree_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n#line 2 \"data_structure/segtree.hpp\"\
    \n\r\n#include <vector>\r\n#include <cassert>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class\
    \ Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>\r\nstruct segtree {\r\n\
    private:\r\n    int n;\r\n    int size;\r\n    std::vector<Monoid> data;\r\npublic:\r\
    \n    segtree(int _n) : n(_n), size(1) {\r\n        while(size < _n) {\r\n   \
    \         size <<= 1;\r\n        }\r\n        data.assign(2*size, e());\r\n  \
    \      return;\r\n    }\r\n\r\n    segtree(const std::vector<Monoid> &v) : size(1)\
    \ {\r\n        n = (int)v.size();\r\n        while(size < n) {\r\n           \
    \ size <<= 1;\r\n        }\r\n        data.assign(2*size, e());\r\n        std::copy(v.begin(),\
    \ v.end(), data.begin() + size);\r\n        for(int i = size-1; i > 0; i--) {\r\
    \n            data[i] = op(data[i<<1|0], data[i<<1|1]);\r\n        }\r\n     \
    \   return;\r\n    }\r\n\r\n    void set(int p, Monoid x) {\r\n        assert(0\
    \ <= p && p < n);\r\n        p += size;\r\n        data[p] = x;\r\n        while(p\
    \ > 1) {\r\n            p >>= 1;\r\n            data[p] = op(data[p<<1|0], data[p<<1|1]);\r\
    \n        }\r\n        return;\r\n    }\r\n\r\n    Monoid get(int p) const {\r\
    \n        assert(0 <= p && p < n);\r\n        return data[p+size];\r\n    }\r\n\
    \r\n    Monoid prod(int l, int r) const {\r\n        assert(0 <= l && l <= r &&\
    \ r <= n);\r\n        Monoid left = e(), right = e();\r\n        l += size;\r\n\
    \        r += size;\r\n        while(l < r) {\r\n            if(l & 1) left =\
    \ op(left, data[l++]);\r\n            if(r & 1) right = op(data[--r], right);\r\
    \n            l >>= 1;\r\n            r >>= 1;\r\n        }\r\n        return\
    \ op(left, right);\r\n    }\r\n\r\n    Monoid all_prod() const {\r\n        return\
    \ data[1];\r\n    }\r\n\r\n    Monoid operator [] (int p) const { return data[size+p];\
    \ }\r\n};\r\n\r\n} // namespace ebi\r\n#line 2 \"tree/heavy_light_decomposition.hpp\"\
    \n\n#include <iostream>\n#line 5 \"tree/heavy_light_decomposition.hpp\"\n\nnamespace\
    \ ebi {\n\nstruct heavy_light_decomposition {\n   private:\n    void dfs_sz(int\
    \ v) {\n        for (auto &nv : g[v]) {\n            if (nv == par[v]) continue;\n\
    \            par[nv] = v;\n            depth[nv] = depth[v] + 1;\n           \
    \ dfs_sz(nv);\n            sz[v] += sz[nv];\n            if (sz[nv] > sz[g[v][0]]\
    \ || g[v][0] == par[v])\n                std::swap(nv, g[v][0]);\n        }\n\
    \    }\n\n    void dfs_hld(int v) {\n        static int t = 0;\n        in[v]\
    \ = t++;\n        for (auto nv : g[v]) {\n            if (nv == par[v]) continue;\n\
    \            nxt[nv] = (nv == g[v][0] ? nxt[v] : nv);\n            dfs_hld(nv);\n\
    \        }\n        out[v] = t;\n    }\n\n    // [u, v) \u30D1\u30B9\u306E\u53D6\
    \u5F97 (v \u306F u \u306E\u7956\u5148)\n    std::vector<std::pair<int, int>> ascend(int\
    \ u, int v) const {\n        std::vector<std::pair<int, int>> res;\n        while\
    \ (nxt[u] != nxt[v]) {\n            res.emplace_back(in[u], in[nxt[u]]);\n   \
    \         u = par[nxt[u]];\n        }\n        if (u != v) res.emplace_back(in[u],\
    \ in[v] + 1);\n        return res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\
    \u5F97 (u \u306F v \u306E\u7956\u5148)\n    std::vector<std::pair<int, int>> descend(int\
    \ u, int v) const {\n        if (u == v) return {};\n        if (nxt[u] == nxt[v])\
    \ return {{in[u] + 1, in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n\
    \        res.emplace_back(in[nxt[v]], in[v]);\n        return res;\n    }\n\n\
    \   public:\n    heavy_light_decomposition(const std::vector<std::vector<int>>\
    \ &gh,\n                              int root = 0)\n        : n(gh.size()),\n\
    \          g(gh),\n          sz(n, 1),\n          in(n),\n          out(n),\n\
    \          nxt(n),\n          par(n, -1),\n          depth(n, 0) {\n        dfs_sz(root);\n\
    \        dfs_hld(root);\n    }\n\n    int idx(int u) const { return in[u]; }\n\
    \n    int lca(int u, int v) const {\n        while (nxt[u] != nxt[v]) {\n    \
    \        if (in[u] < in[v]) std::swap(u, v);\n            u = par[nxt[u]];\n \
    \       }\n        return depth[u] < depth[v] ? u : v;\n    }\n\n    int distance(int\
    \ u, int v) const {\n        return depth[u] + depth[v] - 2 * depth[lca(u, v)];\n\
    \    }\n\n    template <class F>\n    void path_noncommutative_query(int u, int\
    \ v, const F &f) const {\n        int l = lca(u, v);\n        for (auto [a, b]\
    \ : ascend(u, l)) f(a + 1, b);\n        f(in[l], in[l] + 1);\n        for (auto\
    \ [a, b] : descend(l, v)) f(a, b + 1);\n    }\n\n    template <class F>\n    void\
    \ subtree_query(int u, bool vertex, const F &f) {\n        f(in[u] + int(!vertex),\
    \ out[u]);\n    }\n\n   private:\n    int n;\n    std::vector<std::vector<int>>\
    \ g;\n    std::vector<int> sz, in, out, nxt, par, depth;\n};\n\n}  // namespace\
    \ ebi\n#line 2 \"graph/template.hpp\"\n\r\n#line 4 \"graph/template.hpp\"\n\r\n\
    namespace ebi {\r\n\r\ntemplate<class T>\r\nstruct Edge {\r\n    int to;\r\n \
    \   T cost;\r\n    Edge(int _to, T _cost=1) : to(_to), cost(_cost) { }\r\n};\r\
    \n\r\ntemplate<class T>\r\nstruct Graph : std::vector<std::vector<Edge<T>>> {\r\
    \n    using std::vector<std::vector<Edge<T>>>::vector;\r\n    void add_edge(int\
    \ u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if(directed) return; \r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if(directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n} // namespace\
    \ ebi\n#line 6 \"test/vertex_add_subtree_sum.test.cpp\"\n\n#line 9 \"test/vertex_add_subtree_sum.test.cpp\"\
    \n\nusing i64 = std::int64_t;\ni64 op(i64 a, i64 b) { return a+b; }\ni64 e() {\
    \ return 0; }\n\nint main() {\n    int n,q;\n    std::cin >> n >> q;\n    std::vector<i64>\
    \ a(n);\n    for(int i = 0; i < n; ++i) {\n        std::cin >> a[i];\n    }\n\
    \    ebi::graph g(n);\n    for(int i = 1; i < n; ++i) {\n        int p;\n    \
    \    std::cin >> p;\n        g.add_edge(p, i);\n    }\n    ebi::heavy_light_decomposition\
    \ hld(g);\n    ebi::segtree<i64, op, e> seg(n);\n    auto set = [&](int u, i64\
    \ x) {\n        int idx = hld.idx(u);\n        seg.set(idx, seg.get(idx) + x);\n\
    \    };\n    for(int i = 0; i < n; i++) set(i, a[i]);\n    i64 ans = 0;\n    auto\
    \ f = [&](int l, int r) {\n        ans = op(ans, seg.prod(l, r));\n    };\n  \
    \  while(q--) {\n        int flag;\n        std::cin >> flag;\n        if(flag\
    \ == 0) {\n            int u;\n            i64 x;\n            std::cin >> u >>\
    \ x;\n            set(u, x);\n        }\n        else {\n            int u;\n\
    \            std::cin >> u;\n            ans = e();\n            hld.subtree_query(u,\
    \ true, f);\n            std::cout << ans << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../data_structure/segtree.hpp\"\n#include \"../tree/heavy_light_decomposition.hpp\"\
    \n#include \"../graph/template.hpp\"\n\n#include <iostream>\n#include <vector>\n\
    \nusing i64 = std::int64_t;\ni64 op(i64 a, i64 b) { return a+b; }\ni64 e() { return\
    \ 0; }\n\nint main() {\n    int n,q;\n    std::cin >> n >> q;\n    std::vector<i64>\
    \ a(n);\n    for(int i = 0; i < n; ++i) {\n        std::cin >> a[i];\n    }\n\
    \    ebi::graph g(n);\n    for(int i = 1; i < n; ++i) {\n        int p;\n    \
    \    std::cin >> p;\n        g.add_edge(p, i);\n    }\n    ebi::heavy_light_decomposition\
    \ hld(g);\n    ebi::segtree<i64, op, e> seg(n);\n    auto set = [&](int u, i64\
    \ x) {\n        int idx = hld.idx(u);\n        seg.set(idx, seg.get(idx) + x);\n\
    \    };\n    for(int i = 0; i < n; i++) set(i, a[i]);\n    i64 ans = 0;\n    auto\
    \ f = [&](int l, int r) {\n        ans = op(ans, seg.prod(l, r));\n    };\n  \
    \  while(q--) {\n        int flag;\n        std::cin >> flag;\n        if(flag\
    \ == 0) {\n            int u;\n            i64 x;\n            std::cin >> u >>\
    \ x;\n            set(u, x);\n        }\n        else {\n            int u;\n\
    \            std::cin >> u;\n            ans = e();\n            hld.subtree_query(u,\
    \ true, f);\n            std::cout << ans << '\\n';\n        }\n    }\n}"
  dependsOn:
  - data_structure/segtree.hpp
  - tree/heavy_light_decomposition.hpp
  - graph/template.hpp
  isVerificationFile: true
  path: test/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2023-04-22 18:49:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_add_subtree_sum.test.cpp
- /verify/test/vertex_add_subtree_sum.test.cpp.html
title: test/vertex_add_subtree_sum.test.cpp
---
