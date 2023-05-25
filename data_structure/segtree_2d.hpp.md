---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/segtree.hpp
    title: segtree
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
  bundledCode: "#line 1 \"data_structure/segtree_2d.hpp\"\n#include <algorithm>\r\n\
    #include <vector>\r\n\r\n/*\r\n    reference: https://blog.hamayanhamayan.com/entry/2017/12/09/015937\r\
    \n    verify   : http://codeforces.com/contest/893/submission/125531718\r\n*/\r\
    \n\r\n#line 2 \"data_structure/segtree.hpp\"\n\r\n#include <cassert>\r\n#line\
    \ 5 \"data_structure/segtree.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)()> struct segtree {\r\n  private:\r\n    int n;\r\n\
    \    int sz;\r\n    std::vector<S> data;\r\n\r\n    void update(int i) {\r\n \
    \       data[i] = op(data[2 * i], data[2 * i + 1]);\r\n    }\r\n\r\n  public:\r\
    \n    segtree(int n) : segtree(std::vector<S>(n, e())) {}\r\n    segtree(const\
    \ std::vector<S> &v) : n((int)v.size()), sz(1) {\r\n        while (sz < n) sz\
    \ *= 2;\r\n        data = std::vector<S>(2 * sz, e());\r\n        for (int i =\
    \ 0; i < n; i++) {\r\n            data[sz + i] = v[i];\r\n        }\r\n      \
    \  for (int i = sz - 1; i >= 1; i--) update(i);\r\n    }\r\n\r\n    void set(int\
    \ p, S x) {\r\n        assert(0 <= p && p < n);\r\n        p += sz;\r\n      \
    \  data[p] = x;\r\n        while (p > 1) {\r\n            p >>= 1;\r\n       \
    \     update(p);\r\n        }\r\n    }\r\n\r\n    S get(int p) {\r\n        assert(0\
    \ <= p && p < n);\r\n        return data[p + sz];\r\n    }\r\n\r\n    S prod(int\
    \ l, int r) {\r\n        assert(0 <= l && l <= r && r <= n);\r\n        S sml\
    \ = e(), smr = e();\r\n        l += sz;\r\n        r += sz;\r\n        while (l\
    \ < r) {\r\n            if (l & 1) sml = op(sml, data[l++]);\r\n            if\
    \ (r & 1) smr = op(data[--r], smr);\r\n            l >>= 1;\r\n            r >>=\
    \ 1;\r\n        }\r\n        return op(sml, smr);\r\n    }\r\n\r\n    S all_prod()\
    \ {\r\n        return data[1];\r\n    }\r\n\r\n    template <class F> int max_right(int\
    \ l, F f) {\r\n        assert(0 <= l && l < n);\r\n        assert(f(e()));\r\n\
    \        if (l == n) return n;\r\n        l += sz;\r\n        S sm = e();\r\n\
    \        do {\r\n            while (l % 2 == 0) l >>= 1;\r\n            if (!f(op(sm,\
    \ data[l]))) {\r\n                while (l < sz) {\r\n                    l =\
    \ 2 * l;\r\n                    if (f(op(sm, data[l]))) {\r\n                \
    \        sm = op(sm, data[l]);\r\n                        l++;\r\n           \
    \         }\r\n                }\r\n                return l - sz;\r\n       \
    \     }\r\n            sm = op(sm, data[l]);\r\n            l++;\r\n        }\
    \ while ((l & -l) != l);\r\n        return n;\r\n    }\r\n\r\n    template <class\
    \ F> int min_left(int r, F f) {\r\n        assert(0 <= r && r <= n);\r\n     \
    \   assert(f(e()));\r\n        if (r == 0) return 0;\r\n        r += sz;\r\n \
    \       S sm = e();\r\n        do {\r\n            r--;\r\n            while (r\
    \ > 1 && (r % 2)) r >>= 1;\r\n            if (!f(op(data[r], sm))) {\r\n     \
    \           while (r < sz) {\r\n                    r = 2 * r + 1;\r\n       \
    \             if (f(op(data[r], sm))) {\r\n                        sm = op(data[r],\
    \ sm);\r\n                        r--;\r\n                    }\r\n          \
    \      }\r\n                return r + 1 - sz;\r\n            }\r\n          \
    \  sm = op(data[r], sm);\r\n        } while ((r & -r) != r);\r\n        return\
    \ 0;\r\n    }\r\n\r\n    S operator[](int p) const {\r\n        return data[sz\
    \ + p];\r\n    }\r\n};\r\n\r\n}  // namespace ebi\r\n#line 10 \"data_structure/segtree_2d.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class Monoid, Monoid (*op)(Monoid, Monoid),\
    \ Monoid (*e)()>\r\nstruct segtree_2d {\r\n  private:\r\n    Monoid prod(int l,\
    \ int r, int x, int y, int nl, int nr, int k) {\r\n        if (r <= nl || nr <=\
    \ l) {\r\n            return e();\r\n        }\r\n        if (l <= nl && nr <=\
    \ r) {\r\n            int tx = std::lower_bound(data[k].begin(), data[k].end(),\
    \ x) -\r\n                     data[k].begin();\r\n            int ty = std::lower_bound(data[k].begin(),\
    \ data[k].end(), y) -\r\n                     data[k].begin();\r\n           \
    \ return seg[k].prod(tx, ty);\r\n        }\r\n        return op(prod(l, r, x,\
    \ y, nl, (nl + nr) / 2, 2 * k + 1),\r\n                  prod(l, r, x, y, (nl\
    \ + nr) / 2, nr, 2 * k + 2));\r\n    }\r\n\r\n    void pre_prod(int l, int r,\
    \ int x, int y, int nl, int nr, int k) {\r\n        if (r <= nl || nr <= l) {\r\
    \n            return;\r\n        }\r\n        if (l <= nl && nr <= r) {\r\n  \
    \          data[k].emplace_back(x);\r\n            data[k].emplace_back(y);\r\n\
    \            return;\r\n        }\r\n        pre_prod(l, r, x, y, nl, (nl + nr)\
    \ / 2, 2 * k + 1);\r\n        pre_prod(l, r, x, y, (nl + nr) / 2, nr, 2 * k +\
    \ 2);\r\n    }\r\n\r\n  public:\r\n    segtree_2d(int _n) : n(1) {\r\n       \
    \ while (n < _n) {\r\n            n <<= 1;\r\n        }\r\n        data.resize(2\
    \ * n - 1);\r\n    }\r\n\r\n    void set(int x, int y, Monoid val) {\r\n     \
    \   int k = n + x - 1;\r\n        int ty = std::lower_bound(data[k].begin(), data[k].end(),\
    \ y) -\r\n                 data[k].begin();\r\n        seg[k].set(ty, op(seg[k].get(ty),\
    \ val));\r\n        while (k > 0) {\r\n            k = (k - 1) / 2;\r\n      \
    \      ty = std::lower_bound(data[k].begin(), data[k].end(), y) -\r\n        \
    \         data[k].begin();\r\n            seg[k].set(ty, op(seg[k].get(ty), val));\r\
    \n        }\r\n    }\r\n\r\n    Monoid prod(int l, int r, int x, int y) {\r\n\
    \        return prod(l, r, x, y, 0, n, 0);\r\n    }\r\n\r\n    void build() {\r\
    \n        for (int i = 0; i < 2 * n - 1; ++i) {\r\n            std::sort(data[i].begin(),\
    \ data[i].end());\r\n            data[i].erase(std::unique(data[i].begin(), data[i].end()),\r\
    \n                          data[i].end());\r\n            seg.emplace_back(segtree<Monoid,\
    \ op, e>(int(data[i].size())));\r\n        }\r\n    }\r\n\r\n    void pre_set(int\
    \ x, int y) {\r\n        int k = n + x - 1;\r\n        data[k].emplace_back(y);\r\
    \n        while (k > 0) {\r\n            k = (k - 1) / 2;\r\n            data[k].emplace_back(y);\r\
    \n        }\r\n    }\r\n\r\n    void pre_prod(int l, int r, int x, int y) {\r\n\
    \        pre_prod(l, r, x, y, 0, n, 0);\r\n    }\r\n\r\n  private:\r\n    std::vector<std::vector<Monoid>\
    \ > data;\r\n    std::vector<segtree<Monoid, op, e> > seg;\r\n    int n;\r\n};\r\
    \n\r\n}  // namespace ebi\n"
  code: "#include <algorithm>\r\n#include <vector>\r\n\r\n/*\r\n    reference: https://blog.hamayanhamayan.com/entry/2017/12/09/015937\r\
    \n    verify   : http://codeforces.com/contest/893/submission/125531718\r\n*/\r\
    \n\r\n#include \"../data_structure/segtree.hpp\"\r\n\r\nnamespace ebi {\r\n\r\n\
    template <class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>\r\nstruct\
    \ segtree_2d {\r\n  private:\r\n    Monoid prod(int l, int r, int x, int y, int\
    \ nl, int nr, int k) {\r\n        if (r <= nl || nr <= l) {\r\n            return\
    \ e();\r\n        }\r\n        if (l <= nl && nr <= r) {\r\n            int tx\
    \ = std::lower_bound(data[k].begin(), data[k].end(), x) -\r\n                \
    \     data[k].begin();\r\n            int ty = std::lower_bound(data[k].begin(),\
    \ data[k].end(), y) -\r\n                     data[k].begin();\r\n           \
    \ return seg[k].prod(tx, ty);\r\n        }\r\n        return op(prod(l, r, x,\
    \ y, nl, (nl + nr) / 2, 2 * k + 1),\r\n                  prod(l, r, x, y, (nl\
    \ + nr) / 2, nr, 2 * k + 2));\r\n    }\r\n\r\n    void pre_prod(int l, int r,\
    \ int x, int y, int nl, int nr, int k) {\r\n        if (r <= nl || nr <= l) {\r\
    \n            return;\r\n        }\r\n        if (l <= nl && nr <= r) {\r\n  \
    \          data[k].emplace_back(x);\r\n            data[k].emplace_back(y);\r\n\
    \            return;\r\n        }\r\n        pre_prod(l, r, x, y, nl, (nl + nr)\
    \ / 2, 2 * k + 1);\r\n        pre_prod(l, r, x, y, (nl + nr) / 2, nr, 2 * k +\
    \ 2);\r\n    }\r\n\r\n  public:\r\n    segtree_2d(int _n) : n(1) {\r\n       \
    \ while (n < _n) {\r\n            n <<= 1;\r\n        }\r\n        data.resize(2\
    \ * n - 1);\r\n    }\r\n\r\n    void set(int x, int y, Monoid val) {\r\n     \
    \   int k = n + x - 1;\r\n        int ty = std::lower_bound(data[k].begin(), data[k].end(),\
    \ y) -\r\n                 data[k].begin();\r\n        seg[k].set(ty, op(seg[k].get(ty),\
    \ val));\r\n        while (k > 0) {\r\n            k = (k - 1) / 2;\r\n      \
    \      ty = std::lower_bound(data[k].begin(), data[k].end(), y) -\r\n        \
    \         data[k].begin();\r\n            seg[k].set(ty, op(seg[k].get(ty), val));\r\
    \n        }\r\n    }\r\n\r\n    Monoid prod(int l, int r, int x, int y) {\r\n\
    \        return prod(l, r, x, y, 0, n, 0);\r\n    }\r\n\r\n    void build() {\r\
    \n        for (int i = 0; i < 2 * n - 1; ++i) {\r\n            std::sort(data[i].begin(),\
    \ data[i].end());\r\n            data[i].erase(std::unique(data[i].begin(), data[i].end()),\r\
    \n                          data[i].end());\r\n            seg.emplace_back(segtree<Monoid,\
    \ op, e>(int(data[i].size())));\r\n        }\r\n    }\r\n\r\n    void pre_set(int\
    \ x, int y) {\r\n        int k = n + x - 1;\r\n        data[k].emplace_back(y);\r\
    \n        while (k > 0) {\r\n            k = (k - 1) / 2;\r\n            data[k].emplace_back(y);\r\
    \n        }\r\n    }\r\n\r\n    void pre_prod(int l, int r, int x, int y) {\r\n\
    \        pre_prod(l, r, x, y, 0, n, 0);\r\n    }\r\n\r\n  private:\r\n    std::vector<std::vector<Monoid>\
    \ > data;\r\n    std::vector<segtree<Monoid, op, e> > seg;\r\n    int n;\r\n};\r\
    \n\r\n}  // namespace ebi"
  dependsOn:
  - data_structure/segtree.hpp
  isVerificationFile: false
  path: data_structure/segtree_2d.hpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
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
