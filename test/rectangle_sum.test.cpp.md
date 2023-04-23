---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: data_structure/compress.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: segtree
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
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/rectangle_sum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\
    \r\n\r\n#include <iostream>\r\n#include <cstdint>\r\n\r\n#line 2 \"data_structure/compress.hpp\"\
    \n\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\nnamespace ebi\
    \ {\n\ntemplate<class T>\nstruct compress {\nprivate:\n    std::vector<T> cp;\n\
    \    bool flag = false;\npublic:\n    compress() = default;\n\n    compress(std::vector<T>\
    \ cp) : cp(cp) {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \        flag = true;\n    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n\
    \        flag = false;\n    }\n\n    int get(const T &val) {\n        if(flag\
    \ == false) build();\n        return std::lower_bound(cp.begin(), cp.end(), val)\
    \ - cp.begin();\n    }\n\n    int size() const {\n        return cp.size();\n\
    \    }\n\n    T val(int idx) const {\n        assert(0 <= idx && idx < (int)cp.size());\n\
    \        return cp[idx];\n    }\n};\n\n}\n#line 3 \"data_structure/segtree_2d.hpp\"\
    \n\r\n/*\r\n    reference: https://blog.hamayanhamayan.com/entry/2017/12/09/015937\r\
    \n    verify   : http://codeforces.com/contest/893/submission/125531718\r\n*/\r\
    \n\r\n#line 2 \"data_structure/segtree.hpp\"\n\r\n#line 5 \"data_structure/segtree.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class S, S (*op)(S, S), S (*e)()>\r\nstruct\
    \ segtree {\r\n   private:\r\n    int n;\r\n    int sz;\r\n    std::vector<S>\
    \ data;\r\n\r\n    void update(int i) { data[i] = op(data[2 * i], data[2 * i +\
    \ 1]); }\r\n\r\n   public:\r\n    segtree(int n) : segtree(std::vector<S>(n, e()))\
    \ {}\r\n    segtree(const std::vector<S> &v) : n((int)v.size()), sz(1) {\r\n \
    \       while (sz < n) sz *= 2;\r\n        data = std::vector<S>(2 * sz, e());\r\
    \n        for(int i = 0; i < n; i++) { data[sz + i] = v[i]; }\r\n        for(int\
    \ i = sz-1; i >= 1; i--) update(i);\r\n    }\r\n\r\n    void set(int p, S x) {\r\
    \n        assert(0 <= p && p < n);\r\n        p += sz;\r\n        data[p] = x;\r\
    \n        while (p > 1) {\r\n            p >>= 1;\r\n            update(p);\r\n\
    \        }\r\n    }\r\n\r\n    S get(int p) {\r\n        assert(0 <= p && p <\
    \ n);\r\n        return data[p + sz];\r\n    }\r\n\r\n    S prod(int l, int r)\
    \ {\r\n        assert(0 <= l && l <= r && r <= n);\r\n        S sml = e(), smr\
    \ = e();\r\n        l += sz;\r\n        r += sz;\r\n        while (l < r) {\r\n\
    \            if (l & 1) sml = op(sml, data[l++]);\r\n            if (r & 1) smr\
    \ = op(data[--r], smr);\r\n            l >>= 1;\r\n            r >>= 1;\r\n  \
    \      }\r\n        return op(sml, smr);\r\n    }\r\n\r\n    S all_prod() { return\
    \ data[1]; }\r\n\r\n    template <class F>\r\n    int max_right(int l, F f) {\r\
    \n        assert(0 <= l && l < n);\r\n        assert(f(e()));\r\n        if (l\
    \ == n) return n;\r\n        l += sz;\r\n        S sm = e();\r\n        do {\r\
    \n            while (l % 2 == 0) l >>= 1;\r\n            if (!f(op(sm, data[l])))\
    \ {\r\n                while (l < sz) {\r\n                    l = 2 * l;\r\n\
    \                    if (f(op(sm, data[l]))) {\r\n                        sm =\
    \ op(sm, data[l]);\r\n                        l++;\r\n                    }\r\n\
    \                }\r\n                return l - sz;\r\n            }\r\n    \
    \        sm = op(sm, data[l]);\r\n            l++;\r\n        } while ((l & -l)\
    \ != l);\r\n        return n;\r\n    }\r\n\r\n    template <class F>\r\n    int\
    \ min_left(int r, F f) {\r\n        assert(0 <= r && r <= n);\r\n        assert(f(e()));\r\
    \n        if (r == 0) return 0;\r\n        r += sz;\r\n        S sm = e();\r\n\
    \        do {\r\n            r--;\r\n            while (r > 1 && (r % 2)) r >>=\
    \ 1;\r\n            if (!f(op(data[r], sm))) {\r\n                while (r < sz)\
    \ {\r\n                    r = 2 * r + 1;\r\n                    if (f(op(data[r],\
    \ sm))) {\r\n                        sm = op(data[r], sm);\r\n               \
    \         r--;\r\n                    }\r\n                }\r\n             \
    \   return r + 1 - sz;\r\n            }\r\n            sm = op(data[r], sm);\r\
    \n        } while ((r & -r) != r);\r\n        return 0;\r\n    }\r\n\r\n    S\
    \ operator [] (int p) const { return data[sz+p]; }\r\n};\r\n\r\n} // namespace\
    \ ebi\r\n#line 10 \"data_structure/segtree_2d.hpp\"\n\r\nnamespace ebi {\r\n\r\
    \ntemplate<class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>\r\nstruct\
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
    \n};\r\n\r\n}\n#line 8 \"test/rectangle_sum.test.cpp\"\n\r\nusing i64 = std::int64_t;\r\
    \n\r\ni64 op(i64 a, i64 b) {\r\n    return a+b;\r\n}\r\n\r\ni64 e() {\r\n    return\
    \ 0;\r\n}\r\n\r\nint main() {\r\n    int n,q;\r\n    std::cin >> n >> q;\r\n \
    \   ebi::compress<i64> cp;\r\n    std::vector<i64> x(n), y(n), w(n);\r\n    for(int\
    \ i = 0; i < n; i++) {\r\n        std::cin >> x[i] >> y[i] >> w[i];\r\n      \
    \  cp.add(x[i]);\r\n    }\r\n    cp.build();\r\n    ebi::segtree_2d<i64, op, e>\
    \ seg(cp.size());\r\n    for(int i = 0; i < n; i++) {\r\n        seg.pre_set(cp.get(x[i]),\
    \ y[i]);\r\n    }\r\n    seg.build();\r\n    for(int i = 0; i < n; i++) {\r\n\
    \        seg.set(cp.get(x[i]), y[i], w[i]);\r\n    }\r\n    while(q--) {\r\n \
    \       i64 l,d,r,u;\r\n        std::cin >> l >> d >> r >> u;\r\n        std::cout\
    \ << seg.prod(cp.get(l),cp.get(r),d,u) << std::endl;\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\r\n\r\n\
    #include <iostream>\r\n#include <cstdint>\r\n\r\n#include \"../data_structure/compress.hpp\"\
    \r\n#include \"../data_structure/segtree_2d.hpp\"\r\n\r\nusing i64 = std::int64_t;\r\
    \n\r\ni64 op(i64 a, i64 b) {\r\n    return a+b;\r\n}\r\n\r\ni64 e() {\r\n    return\
    \ 0;\r\n}\r\n\r\nint main() {\r\n    int n,q;\r\n    std::cin >> n >> q;\r\n \
    \   ebi::compress<i64> cp;\r\n    std::vector<i64> x(n), y(n), w(n);\r\n    for(int\
    \ i = 0; i < n; i++) {\r\n        std::cin >> x[i] >> y[i] >> w[i];\r\n      \
    \  cp.add(x[i]);\r\n    }\r\n    cp.build();\r\n    ebi::segtree_2d<i64, op, e>\
    \ seg(cp.size());\r\n    for(int i = 0; i < n; i++) {\r\n        seg.pre_set(cp.get(x[i]),\
    \ y[i]);\r\n    }\r\n    seg.build();\r\n    for(int i = 0; i < n; i++) {\r\n\
    \        seg.set(cp.get(x[i]), y[i], w[i]);\r\n    }\r\n    while(q--) {\r\n \
    \       i64 l,d,r,u;\r\n        std::cin >> l >> d >> r >> u;\r\n        std::cout\
    \ << seg.prod(cp.get(l),cp.get(r),d,u) << std::endl;\r\n    }\r\n}"
  dependsOn:
  - data_structure/compress.hpp
  - data_structure/segtree_2d.hpp
  - data_structure/segtree.hpp
  isVerificationFile: true
  path: test/rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2023-04-23 15:36:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/rectangle_sum.test.cpp
- /verify/test/rectangle_sum.test.cpp.html
title: test/rectangle_sum.test.cpp
---
