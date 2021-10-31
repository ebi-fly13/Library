---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/Segtree.hpp
    title: Segtree
  - icon: ':heavy_check_mark:'
    path: data_structure/heavy_light_decomposition.hpp
    title: data_structure/heavy_light_decomposition.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/vertex_add_subtree_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n#line 2 \"data_structure/heavy_light_decomposition.hpp\"\
    \n\n#line 2 \"data_structure/Segtree.hpp\"\n\r\n#include <vector>\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate<class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>\r\
    \nstruct Segtree {\r\nprivate:\r\n    std::vector<Monoid> data;\r\n    int n;\r\
    \npublic:\r\n    Segtree(int _n) : n(1) {\r\n        while(n<_n){\r\n        \
    \    n <<= 1;\r\n        }\r\n        data.assign(2*n-1, e());\r\n    }\r\n\r\n\
    \    Segtree(std::vector<Monoid> v) : n(1) {\r\n        int _n = v.size();\r\n\
    \        while(n<_n){\r\n            n <<= 1;\r\n        }\r\n        data.assign(2*n-1,\
    \ e());\r\n        for(int i = 0; i<_n; i++){\r\n            data[n+i-1] = v[i];\r\
    \n        }\r\n        for(int i = n-2; i>=0; i--){\r\n            data[i] = op(data[2*i+1],\
    \ data[2*i+2]);\r\n        }\r\n    }\r\n\r\n    void set(int p, Monoid x){\r\n\
    \        int k = n+p-1;\r\n        data[k] = x;\r\n        while(k>0){\r\n   \
    \         k = (k-1)/2;\r\n            data[k] = op(data[2*k+1], data[2*k+2]);\r\
    \n        }\r\n    }\r\n\r\n    Monoid prod(int tl, int tr, int l=0, int r=-1,\
    \ int index=0){\r\n        if(r<0) r = n;\r\n        if(tr<=l || r<=tl){\r\n \
    \           return e();\r\n        }\r\n        if(tl<=l && r<=tr){\r\n      \
    \      return data[index];\r\n        }\r\n        return op(prod(tl, tr, l, (l+r)/2,\
    \ 2*index+1), prod(tl, tr, (l+r)/2, r, 2*index+2));\r\n    }\r\n\r\n    Monoid\
    \ all_prod() { return data[0]; }\r\n\r\n    Monoid get(int p) { return data[n+p-1];\
    \ }\r\n\r\n    Monoid operator [] (int p) { return data[n+p-1]; }\r\n};\r\n\r\n\
    } // namespace ebi\n#line 2 \"graph/template.hpp\"\n\r\n#line 4 \"graph/template.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate<class T>\r\nstruct Edge {\r\n    int to;\r\
    \n    T cost;\r\n    Edge(int _to, T _cost=1) : to(_to), cost(_cost) { }\r\n};\r\
    \n\r\ntemplate<class T>\r\nstruct Graph : std::vector<std::vector<Edge<T>>> {\r\
    \n    using std::vector<std::vector<Edge<T>>>::vector;\r\n    void add_edge(int\
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
    \ 0;\n    std::vector<int> sz, in, out, nxt, up;\n    graph g;\n    Segtree<Monoid,\
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
    \    }\n};\n\n}\n#line 4 \"test/vertex_add_subtree_sum.test.cpp\"\n\n#include\
    \ <iostream>\n#line 7 \"test/vertex_add_subtree_sum.test.cpp\"\n\nusing i64 =\
    \ std::int64_t;\ni64 op(i64 a, i64 b) { return a+b; }\ni64 e() { return 0; }\n\
    \nint main() {\n    int n,q;\n    std::cin >> n >> q;\n    std::vector<i64> a(n);\n\
    \    for(int i = 0; i < n; ++i) {\n        std::cin >> a[i];\n    }\n    ebi::heavy_light_decomposition<i64,\
    \ op, e> hld(n);\n    for(int i = 1; i < n; ++i) {\n        int p;\n        std::cin\
    \ >> p;\n        hld.add_edge(i, p);\n    }\n    hld.build();\n    hld.set(a);\n\
    \    while(q--) {\n        int flag;\n        std::cin >> flag;\n        if(flag\
    \ == 0) {\n            int u;\n            i64 x;\n            std::cin >> u >>\
    \ x;\n            hld.set(u, hld.get(u) + x);\n        }\n        else {\n   \
    \         int u;\n            std::cin >> u;\n            std::cout << hld.subtree_prod(u)\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../data_structure/heavy_light_decomposition.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n\nusing i64 = std::int64_t;\ni64 op(i64 a, i64 b) { return\
    \ a+b; }\ni64 e() { return 0; }\n\nint main() {\n    int n,q;\n    std::cin >>\
    \ n >> q;\n    std::vector<i64> a(n);\n    for(int i = 0; i < n; ++i) {\n    \
    \    std::cin >> a[i];\n    }\n    ebi::heavy_light_decomposition<i64, op, e>\
    \ hld(n);\n    for(int i = 1; i < n; ++i) {\n        int p;\n        std::cin\
    \ >> p;\n        hld.add_edge(i, p);\n    }\n    hld.build();\n    hld.set(a);\n\
    \    while(q--) {\n        int flag;\n        std::cin >> flag;\n        if(flag\
    \ == 0) {\n            int u;\n            i64 x;\n            std::cin >> u >>\
    \ x;\n            hld.set(u, hld.get(u) + x);\n        }\n        else {\n   \
    \         int u;\n            std::cin >> u;\n            std::cout << hld.subtree_prod(u)\
    \ << '\\n';\n        }\n    }\n}"
  dependsOn:
  - data_structure/heavy_light_decomposition.hpp
  - data_structure/Segtree.hpp
  - graph/template.hpp
  isVerificationFile: true
  path: test/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2021-10-31 15:43:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_add_subtree_sum.test.cpp
- /verify/test/vertex_add_subtree_sum.test.cpp.html
title: test/vertex_add_subtree_sum.test.cpp
---
