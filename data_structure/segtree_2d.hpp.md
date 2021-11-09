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
    - http://codeforces.com/contest/893/submission/125531718
    - https://blog.hamayanhamayan.com/entry/2017/12/09/015937
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../data_structure/segtree.hpp:\
    \ line -1: no such header\n"
  code: "#include <vector>\r\n#include <algorithm>\r\n\r\n/*\r\n    reference: https://blog.hamayanhamayan.com/entry/2017/12/09/015937\r\
    \n    verify   : http://codeforces.com/contest/893/submission/125531718\r\n*/\r\
    \n\r\n#include \"../data_structure/segtree.hpp\"\r\n\r\nnamespace ebi {\r\n\r\n\
    template<class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>\r\nstruct\
    \ segtree_2d {\r\nprivate:\r\n    Monoid prod(int l, int r, int x, int y, int\
    \ nl, int nr, int k) {\r\n        if(r <= nl || nr <= l) {\r\n            return\
    \ e();\r\n        }\r\n        if(l <= nl && nr <= r) {\r\n            int tx\
    \ = std::lower_bound(data[k].begin(), data[k].end(), x) - data[k].begin();\r\n\
    \            int ty = std::lower_bound(data[k].begin(), data[k].end(), y) - data[k].begin();\r\
    \n            return seg[k].prod(tx, ty);\r\n        }\r\n        return op(prod(l,\
    \ r, x, y, nl, (nl+nr)/2, 2*k + 1), prod(l, r, x, y, (nl+nr)/2, nr, 2*k + 2));\r\
    \n    }\r\n\r\n    void pre_prod(int l, int r, int x, int y, int nl, int nr, int\
    \ k) {\r\n        if(r <= nl || nr <= l) {\r\n            return;\r\n        }\r\
    \n        if(l<=nl && nr <= r) {\r\n            data[k].emplace_back(x);\r\n \
    \           data[k].emplace_back(y);\r\n            return;\r\n        }\r\n \
    \       pre_prod(l, r, x, y, nl, (nl+nr)/2, 2*k + 1);\r\n        pre_prod(l, r,\
    \ x, y, (nl+nr)/2, nr, 2*k + 2);\r\n    }\r\npublic:\r\n    segtree_2d(int _n)\
    \ : n(1) {\r\n        while(n < _n) {\r\n            n <<= 1;\r\n        }\r\n\
    \        data.resize(2*n-1);\r\n    }\r\n\r\n    void set(int x, int y, Monoid\
    \ val) {\r\n        int k = n+x-1;\r\n        int ty = std::lower_bound(data[k].begin(),\
    \ data[k].end(), y) - data[k].begin();\r\n        seg[k].set(ty, op(seg[k].get(ty),\
    \ val));\r\n        while(k > 0) {\r\n            k = (k-1)/2;\r\n           \
    \ ty = std::lower_bound(data[k].begin(), data[k].end(), y) - data[k].begin();\r\
    \n            seg[k].set(ty, op(seg[k].get(ty), val));\r\n        }\r\n    }\r\
    \n\r\n    Monoid prod(int l, int r, int x, int y) {\r\n        return prod(l,\
    \ r, x, y, 0, n, 0);\r\n    }\r\n\r\n    void build() {\r\n        for(int i =\
    \ 0; i < 2*n - 1; ++i) {\r\n            std::sort(data[i].begin(), data[i].end());\r\
    \n            data[i].erase(std::unique(data[i].begin(), data[i].end()), data[i].end());\r\
    \n            seg.emplace_back(segtree<Monoid, op, e>(int(data[i].size())));\r\
    \n        }\r\n    }\r\n\r\n    void pre_set(int x, int y) {\r\n        int k\
    \ = n+x-1;\r\n        data[k].emplace_back(y);\r\n        while(k > 0) {\r\n \
    \           k = (k-1)/2;\r\n            data[k].emplace_back(y);\r\n        }\r\
    \n    }\r\n\r\n    void pre_prod(int l, int r, int x, int y) {\r\n        pre_prod(l,\
    \ r, x, y, 0, n, 0);\r\n    }\r\nprivate:\r\n    std::vector< std::vector< Monoid\
    \ > > data;\r\n    std::vector< segtree< Monoid, op, e> > seg;\r\n    int n;\r\
    \n};\r\n\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segtree_2d.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/segtree_2d.hpp
layout: document
redirect_from:
- /library/data_structure/segtree_2d.hpp
- /library/data_structure/segtree_2d.hpp.html
title: data_structure/segtree_2d.hpp
---
