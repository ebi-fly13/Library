---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/53170
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../data_structure/segtree.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../data_structure/segtree.hpp\"\n#include \"../graph/template.hpp\"\
    \n\n#include <vector>\n\n/*\n    reference: https://codeforces.com/blog/entry/53170\n\
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
    \    }\n};\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/heavy_light_decomposition.hpp
layout: document
redirect_from:
- /library/data_structure/heavy_light_decomposition.hpp
- /library/data_structure/heavy_light_decomposition.hpp.html
title: data_structure/heavy_light_decomposition.hpp
---
