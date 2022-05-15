---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: Segtree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/point_add_rectangle_sum.test.cpp
    title: test/point_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/rectangle_sum.test.cpp
    title: test/rectangle_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://codeforces.com/contest/893/submission/125531718
    - https://blog.hamayanhamayan.com/entry/2017/12/09/015937
  bundledCode: "#line 1 \"data_structure/segtree_2d.hpp\"\n#include <vector>\r\n#include\
    \ <algorithm>\r\n\r\n/*\r\n    reference: https://blog.hamayanhamayan.com/entry/2017/12/09/015937\r\
    \n    verify   : http://codeforces.com/contest/893/submission/125531718\r\n*/\r\
    \n\r\n#line 2 \"data_structure/segtree.hpp\"\n\r\n#line 4 \"data_structure/segtree.hpp\"\
    \n#include <cassert>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class Monoid, Monoid\
    \ (*op)(Monoid, Monoid), Monoid (*e)()>\r\nstruct segtree {\r\nprivate:\r\n  \
    \  int n;\r\n    int size;\r\n    std::vector<Monoid> data;\r\npublic:\r\n   \
    \ segtree(int _n) : n(_n), size(1) {\r\n        while(size < _n) {\r\n       \
    \     size <<= 1;\r\n        }\r\n        data.assign(2*size, e());\r\n      \
    \  return;\r\n    }\r\n\r\n    segtree(const std::vector<Monoid> &v) : size(1)\
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
    \ }\r\n};\r\n\r\n} // namespace ebi\r\n#line 10 \"data_structure/segtree_2d.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate<class Monoid, Monoid (*op)(Monoid, Monoid),\
    \ Monoid (*e)()>\r\nstruct segtree_2d {\r\nprivate:\r\n    Monoid prod(int l,\
    \ int r, int x, int y, int nl, int nr, int k) {\r\n        if(r <= nl || nr <=\
    \ l) {\r\n            return e();\r\n        }\r\n        if(l <= nl && nr <=\
    \ r) {\r\n            int tx = std::lower_bound(data[k].begin(), data[k].end(),\
    \ x) - data[k].begin();\r\n            int ty = std::lower_bound(data[k].begin(),\
    \ data[k].end(), y) - data[k].begin();\r\n            return seg[k].prod(tx, ty);\r\
    \n        }\r\n        return op(prod(l, r, x, y, nl, (nl+nr)/2, 2*k + 1), prod(l,\
    \ r, x, y, (nl+nr)/2, nr, 2*k + 2));\r\n    }\r\n\r\n    void pre_prod(int l,\
    \ int r, int x, int y, int nl, int nr, int k) {\r\n        if(r <= nl || nr <=\
    \ l) {\r\n            return;\r\n        }\r\n        if(l<=nl && nr <= r) {\r\
    \n            data[k].emplace_back(x);\r\n            data[k].emplace_back(y);\r\
    \n            return;\r\n        }\r\n        pre_prod(l, r, x, y, nl, (nl+nr)/2,\
    \ 2*k + 1);\r\n        pre_prod(l, r, x, y, (nl+nr)/2, nr, 2*k + 2);\r\n    }\r\
    \npublic:\r\n    segtree_2d(int _n) : n(1) {\r\n        while(n < _n) {\r\n  \
    \          n <<= 1;\r\n        }\r\n        data.resize(2*n-1);\r\n    }\r\n\r\
    \n    void set(int x, int y, Monoid val) {\r\n        int k = n+x-1;\r\n     \
    \   int ty = std::lower_bound(data[k].begin(), data[k].end(), y) - data[k].begin();\r\
    \n        seg[k].set(ty, op(seg[k].get(ty), val));\r\n        while(k > 0) {\r\
    \n            k = (k-1)/2;\r\n            ty = std::lower_bound(data[k].begin(),\
    \ data[k].end(), y) - data[k].begin();\r\n            seg[k].set(ty, op(seg[k].get(ty),\
    \ val));\r\n        }\r\n    }\r\n\r\n    Monoid prod(int l, int r, int x, int\
    \ y) {\r\n        return prod(l, r, x, y, 0, n, 0);\r\n    }\r\n\r\n    void build()\
    \ {\r\n        for(int i = 0; i < 2*n - 1; ++i) {\r\n            std::sort(data[i].begin(),\
    \ data[i].end());\r\n            data[i].erase(std::unique(data[i].begin(), data[i].end()),\
    \ data[i].end());\r\n            seg.emplace_back(segtree<Monoid, op, e>(int(data[i].size())));\r\
    \n        }\r\n    }\r\n\r\n    void pre_set(int x, int y) {\r\n        int k\
    \ = n+x-1;\r\n        data[k].emplace_back(y);\r\n        while(k > 0) {\r\n \
    \           k = (k-1)/2;\r\n            data[k].emplace_back(y);\r\n        }\r\
    \n    }\r\n\r\n    void pre_prod(int l, int r, int x, int y) {\r\n        pre_prod(l,\
    \ r, x, y, 0, n, 0);\r\n    }\r\nprivate:\r\n    std::vector< std::vector< Monoid\
    \ > > data;\r\n    std::vector< segtree< Monoid, op, e> > seg;\r\n    int n;\r\
    \n};\r\n\r\n}\n"
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
  dependsOn:
  - data_structure/segtree.hpp
  isVerificationFile: false
  path: data_structure/segtree_2d.hpp
  requiredBy: []
  timestamp: '2021-11-15 18:01:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/point_add_rectangle_sum.test.cpp
  - test/rectangle_sum.test.cpp
documentation_of: data_structure/segtree_2d.hpp
layout: document
redirect_from:
- /library/data_structure/segtree_2d.hpp
- /library/data_structure/segtree_2d.hpp.html
title: data_structure/segtree_2d.hpp
---
