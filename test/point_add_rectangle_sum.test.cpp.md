---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: data_structure/compress.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: Segtree
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree_2d.hpp
    title: data_structure/segtree_2d.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/point_add_rectangle_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\r\n\r\n#include\
    \ <iostream>\r\n#include <cstdint>\r\n\r\n#line 2 \"data_structure/compress.hpp\"\
    \n\n#include <vector>\n#include <algorithm>\n\nnamespace ebi {\n\ntemplate<class\
    \ T>\nstruct compress {\nprivate:\n    std::vector<T> cp;\n    bool flag = false;\n\
    public:\n    compress() = default;\n\n    compress(std::vector<T> cp) : cp(cp)\
    \ {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \        flag = true;\n    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n\
    \        flag = false;\n    }\n\n    int get(const T &val) {\n        if(flag\
    \ == false) build();\n        return std::lower_bound(cp.begin(), cp.end(), val)\
    \ - cp.begin();\n    }\n\n    int size() const {\n        return cp.size();\n\
    \    }\n};\n\n}\n#line 3 \"data_structure/segtree_2d.hpp\"\n\r\n/*\r\n    reference:\
    \ https://blog.hamayanhamayan.com/entry/2017/12/09/015937\r\n    verify   : http://codeforces.com/contest/893/submission/125531718\r\
    \n*/\r\n\r\n#line 2 \"data_structure/segtree.hpp\"\n\r\n#line 4 \"data_structure/segtree.hpp\"\
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
    \n};\r\n\r\n}\n#line 8 \"test/point_add_rectangle_sum.test.cpp\"\n\r\nusing i64\
    \ = std::int64_t;\r\n\r\ni64 op(i64 a, i64 b) {\r\n    return a+b;\r\n}\r\n\r\n\
    i64 e() {\r\n    return 0;\r\n}\r\n\r\nstruct Query {\r\n    i64 x,y,w;\r\n  \
    \  i64 l,d,r,u;\r\n    int flag;\r\n};\r\n\r\nint main() {\r\n    int n,q;\r\n\
    \    std::cin >> n >> q;\r\n    ebi::compress<i64> cp;\r\n    std::vector<i64>\
    \ x(n), y(n), w(n);\r\n    for(int i = 0; i < n; i++) {\r\n        std::cin >>\
    \ x[i] >> y[i] >> w[i];\r\n        cp.add(x[i]);\r\n    }\r\n    std::vector<Query>\
    \ query(q);\r\n    for(int i = 0; i < q; i++) {\r\n        std::cin >> query[i].flag;\r\
    \n        if(query[i].flag == 0) {\r\n            std::cin >> query[i].x >> query[i].y\
    \ >> query[i].w;\r\n            cp.add(query[i].x);\r\n        }\r\n        else\
    \ {\r\n            std::cin >> query[i].l >> query[i].d >> query[i].r >> query[i].u;\r\
    \n        }\r\n    }\r\n    cp.build();\r\n    ebi::segtree_2d<i64, op, e> seg(cp.size());\r\
    \n    for(int i = 0; i < n; i++) {\r\n        seg.pre_set(cp.get(x[i]), y[i]);\r\
    \n    }\r\n    for(int i = 0; i < q; i++) {\r\n        if(query[i].flag == 0)\
    \ {\r\n            seg.pre_set(cp.get(query[i].x), query[i].y);\r\n        }\r\
    \n    }\r\n    seg.build();\r\n    for(int i = 0; i < n; i++) {\r\n        seg.set(cp.get(x[i]),\
    \ y[i], w[i]);\r\n    }\r\n    for(int i = 0; i < q; i++) {\r\n        if(query[i].flag\
    \ == 0) {\r\n            seg.set(cp.get(query[i].x), query[i].y, query[i].w);\r\
    \n        }\r\n        else {\r\n            std::cout << seg.prod(cp.get(query[i].l),\
    \ cp.get(query[i].r), query[i].d, query[i].u) << '\\n';\r\n        }\r\n    }\r\
    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \r\n\r\n#include <iostream>\r\n#include <cstdint>\r\n\r\n#include \"../data_structure/compress.hpp\"\
    \r\n#include \"../data_structure/segtree_2d.hpp\"\r\n\r\nusing i64 = std::int64_t;\r\
    \n\r\ni64 op(i64 a, i64 b) {\r\n    return a+b;\r\n}\r\n\r\ni64 e() {\r\n    return\
    \ 0;\r\n}\r\n\r\nstruct Query {\r\n    i64 x,y,w;\r\n    i64 l,d,r,u;\r\n    int\
    \ flag;\r\n};\r\n\r\nint main() {\r\n    int n,q;\r\n    std::cin >> n >> q;\r\
    \n    ebi::compress<i64> cp;\r\n    std::vector<i64> x(n), y(n), w(n);\r\n   \
    \ for(int i = 0; i < n; i++) {\r\n        std::cin >> x[i] >> y[i] >> w[i];\r\n\
    \        cp.add(x[i]);\r\n    }\r\n    std::vector<Query> query(q);\r\n    for(int\
    \ i = 0; i < q; i++) {\r\n        std::cin >> query[i].flag;\r\n        if(query[i].flag\
    \ == 0) {\r\n            std::cin >> query[i].x >> query[i].y >> query[i].w;\r\
    \n            cp.add(query[i].x);\r\n        }\r\n        else {\r\n         \
    \   std::cin >> query[i].l >> query[i].d >> query[i].r >> query[i].u;\r\n    \
    \    }\r\n    }\r\n    cp.build();\r\n    ebi::segtree_2d<i64, op, e> seg(cp.size());\r\
    \n    for(int i = 0; i < n; i++) {\r\n        seg.pre_set(cp.get(x[i]), y[i]);\r\
    \n    }\r\n    for(int i = 0; i < q; i++) {\r\n        if(query[i].flag == 0)\
    \ {\r\n            seg.pre_set(cp.get(query[i].x), query[i].y);\r\n        }\r\
    \n    }\r\n    seg.build();\r\n    for(int i = 0; i < n; i++) {\r\n        seg.set(cp.get(x[i]),\
    \ y[i], w[i]);\r\n    }\r\n    for(int i = 0; i < q; i++) {\r\n        if(query[i].flag\
    \ == 0) {\r\n            seg.set(cp.get(query[i].x), query[i].y, query[i].w);\r\
    \n        }\r\n        else {\r\n            std::cout << seg.prod(cp.get(query[i].l),\
    \ cp.get(query[i].r), query[i].d, query[i].u) << '\\n';\r\n        }\r\n    }\r\
    \n}"
  dependsOn:
  - data_structure/compress.hpp
  - data_structure/segtree_2d.hpp
  - data_structure/segtree.hpp
  isVerificationFile: true
  path: test/point_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2021-11-15 18:01:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/point_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/point_add_rectangle_sum.test.cpp
- /verify/test/point_add_rectangle_sum.test.cpp.html
title: test/point_add_rectangle_sum.test.cpp
---
