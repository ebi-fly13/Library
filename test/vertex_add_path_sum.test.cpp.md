---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/heavy_light_decomposition.hpp
    title: data_structure/heavy_light_decomposition.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: Segtree
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/vertex_add_path_sum.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#line 2 \"data_structure/heavy_light_decomposition.hpp\"\
    \n\n#line 2 \"data_structure/segtree.hpp\"\n\r\n#include <vector>\r\n#include\
    \ <cassert>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class Monoid, Monoid (*op)(Monoid,\
    \ Monoid), Monoid (*e)()>\r\nstruct segtree {\r\nprivate:\r\n    int n;\r\n  \
    \  int size;\r\n    std::vector<Monoid> data;\r\npublic:\r\n    segtree(int _n)\
    \ : n(_n), size(1) {\r\n        while(size < _n) {\r\n            size <<= 1;\r\
    \n        }\r\n        data.assign(2*size, e());\r\n        return;\r\n    }\r\
    \n\r\n    segtree(const std::vector<Monoid> &v) : size(1) {\r\n        n = (int)v.size();\r\
    \n        while(size < n) {\r\n            size <<= 1;\r\n        }\r\n      \
    \  data.assign(2*size, e());\r\n        std::copy(v.begin(), v.end(), data.begin()\
    \ + size);\r\n        for(int i = size-1; i > 0; i--) {\r\n            data[i]\
    \ = op(data[i<<1|0], data[i<<1|1]);\r\n        }\r\n        return;\r\n    }\r\
    \n\r\n    void set(int p, Monoid x) {\r\n        assert(0 <= p && p < n);\r\n\
    \        p += size;\r\n        data[p] = x;\r\n        while(p > 1) {\r\n    \
    \        p >>= 1;\r\n            data[p] = op(data[p<<1|0], data[p<<1|1]);\r\n\
    \        }\r\n        return;\r\n    }\r\n\r\n    Monoid get(int p) const {\r\n\
    \        assert(0 <= p && p < n);\r\n        return data[p+size];\r\n    }\r\n\
    \r\n    Monoid prod(int l, int r) const {\r\n        assert(0 <= l && l <= r &&\
    \ r <= n);\r\n        Monoid left = e(), right = e();\r\n        l += size;\r\n\
    \        r += size;\r\n        while(l < r) {\r\n            if(l & 1) left =\
    \ op(left, data[l++]);\r\n            if(r & 1) right = op(data[--r], right);\r\
    \n            l >>= 1;\r\n            r >>= 1;\r\n        }\r\n        return\
    \ op(left, right);\r\n    }\r\n\r\n    Monoid all_prod() const {\r\n        return\
    \ data[1];\r\n    }\r\n\r\n    Monoid operator [] (int p) const { return data[size+p];\
    \ }\r\n};\r\n\r\n} // namespace ebi\r\n#line 2 \"graph/template.hpp\"\n\r\n#line\
    \ 4 \"graph/template.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate<class T>\r\nstruct\
    \ Edge {\r\n    int to;\r\n    T cost;\r\n    Edge(int _to, T _cost=1) : to(_to),\
    \ cost(_cost) { }\r\n};\r\n\r\ntemplate<class T>\r\nstruct Graph : std::vector<std::vector<Edge<T>>>\
    \ {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\n    void add_edge(int\
    \ u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if(directed) return; \r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if(directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n} // namespace\
    \ ebi\n#line 5 \"data_structure/heavy_light_decomposition.hpp\"\n\n#line 7 \"\
    data_structure/heavy_light_decomposition.hpp\"\n\n/*\n    reference: https://codeforces.com/blog/entry/53170\n\
    */\n\nnamespace ebi {\n\ntemplate<class Monoid, Monoid (*op)(Monoid, Monoid),\
    \ Monoid (*e)()>\nstruct heavy_light_decomposition {\nprivate:\n    int n, t =\
    \ 0;\n    std::vector<int> sz, in, out, nxt, up;\n    graph g;\n    segtree<Monoid,\
    \ op, e> seg_l, seg_r;\n\n    void dfs_sz(int v = 0) {\n        sz[v] = 1;\n \
    \       for(auto &u : g[v]) if(u != up[v]) {\n            up[u] = v;\n       \
    \     dfs_sz(u);\n            sz[v] += sz[u];\n            if(sz[u] > sz[g[v][0]]\
    \ || g[v][0] == up[v]) std::swap(g[v][0], u);\n        }\n    }\n\n    void dfs_hld(int\
    \ v = 0) {\n        in[v] = t++;\n        for(const auto &u: g[v]) if(u != up[v])\
    \ {\n            nxt[u] = (u == g[v][0]) ? nxt[v] : u;\n            sz[u] = (u\
    \ == g[v][0]) ? sz[v] : sz[v]+1;\n            dfs_hld(u);\n        }\n       \
    \ out[v] = t;\n    }\npublic:\n    heavy_light_decomposition(int _n) : n(_n),\
    \ sz(_n, 0), in(_n, 0), out(_n, 0), nxt(_n, 0), up(_n, -1), g(_n), seg_l(_n),\
    \ seg_r(_n) { }\n\n    void add_edge(int v, int u) {\n        g[v].emplace_back(u);\n\
    \        g[u].emplace_back(v);\n    }\n\n    void build(int root = 0) {\n    \
    \    dfs_sz(root);\n        sz.assign(n, 0);\n        dfs_hld(root);\n    }\n\n\
    \    int lca(int u, int v) {\n        while(nxt[u] != nxt[v]) {\n            if(sz[u]\
    \ > sz[v]) {\n                u = up[nxt[u]];\n            }\n            else\
    \ {\n                v = up[nxt[v]];\n            }\n        }\n        return\
    \ (in[u] < in[v]) ? u : v;\n    }\n\n    void set(const std::vector<Monoid> &a)\
    \ {\n        for(int i = 0; i < n; ++i) {\n            seg_l.set(in[i], a[i]);\n\
    \            seg_r.set(n-1-in[i], a[i]);\n        }\n    }\n\n    void set(int\
    \ i, Monoid x) {\n        seg_l.set(in[i], x);\n        seg_r.set(n-1-in[i], x);\n\
    \    }\n\n    Monoid get(int i) {\n        return seg_l.get(in[i]);\n    }\n\n\
    \    Monoid path_prod(int u, int v) {\n        Monoid sum_u = e(), sum_v = e();\n\
    \        while(nxt[u] != nxt[v]) {\n            if(sz[u] > sz[v]) {\n        \
    \        sum_u = op(sum_u, seg_r.prod(n-1-in[u], n-in[nxt[u]]));\n           \
    \     u = up[nxt[u]];\n            }\n            else {\n                sum_v\
    \ = op(seg_l.prod(in[nxt[v]], in[v]+1), sum_v);\n                v = up[nxt[v]];\n\
    \            }\n        }\n        if(in[u] < in[v]) {\n            sum_v = op(seg_l.prod(in[u],\
    \ in[v]+1), sum_v);\n        }\n        else {\n            sum_u = op(sum_u,\
    \ seg_r.prod(n-1-in[u], n-in[v]));\n        }\n        return op(sum_u, sum_v);\n\
    \    }\n\n    Monoid subtree_prod(int u) {\n        return seg_l.prod(in[u], out[u]);\n\
    \    }\n};\n\n}\n#line 4 \"test/vertex_add_path_sum.test.cpp\"\n\n#include <iostream>\n\
    #line 7 \"test/vertex_add_path_sum.test.cpp\"\n\nusing i64 = std::int64_t;\ni64\
    \ op(i64 a, i64 b) { return a+b; }\ni64 e() { return 0; }\n\nint main() {\n  \
    \  int n,q;\n    std::cin >> n >> q;\n    std::vector<i64> a(n);\n    for(int\
    \ i = 0; i < n; ++i) {\n        std::cin >> a[i];\n    }\n    ebi::heavy_light_decomposition<i64,\
    \ op, e> hld(n);\n    for(int i = 0; i < n-1; ++i) {\n        int u,v;\n     \
    \   std::cin >> u >> v;\n        hld.add_edge(u,v);\n    }\n    hld.build();\n\
    \    hld.set(a);\n    while(q--) {\n        int flag;\n        std::cin >> flag;\n\
    \        if(flag == 0) {\n            int p;\n            i64 x;\n           \
    \ std::cin >> p >> x;\n            hld.set(p, hld.get(p) + x);\n        }\n  \
    \      else {\n            int u,v;\n            std::cin >> u >> v;\n       \
    \     std::cout << hld.path_prod(u, v) << std::endl;\n        }   \n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../data_structure/heavy_light_decomposition.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n\nusing i64 = std::int64_t;\ni64 op(i64 a, i64 b) { return\
    \ a+b; }\ni64 e() { return 0; }\n\nint main() {\n    int n,q;\n    std::cin >>\
    \ n >> q;\n    std::vector<i64> a(n);\n    for(int i = 0; i < n; ++i) {\n    \
    \    std::cin >> a[i];\n    }\n    ebi::heavy_light_decomposition<i64, op, e>\
    \ hld(n);\n    for(int i = 0; i < n-1; ++i) {\n        int u,v;\n        std::cin\
    \ >> u >> v;\n        hld.add_edge(u,v);\n    }\n    hld.build();\n    hld.set(a);\n\
    \    while(q--) {\n        int flag;\n        std::cin >> flag;\n        if(flag\
    \ == 0) {\n            int p;\n            i64 x;\n            std::cin >> p >>\
    \ x;\n            hld.set(p, hld.get(p) + x);\n        }\n        else {\n   \
    \         int u,v;\n            std::cin >> u >> v;\n            std::cout <<\
    \ hld.path_prod(u, v) << std::endl;\n        }   \n    }\n}"
  dependsOn:
  - data_structure/heavy_light_decomposition.hpp
  - data_structure/segtree.hpp
  - graph/template.hpp
  isVerificationFile: true
  path: test/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2021-11-15 18:01:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_add_path_sum.test.cpp
- /verify/test/vertex_add_path_sum.test.cpp.html
title: test/vertex_add_path_sum.test.cpp
---
