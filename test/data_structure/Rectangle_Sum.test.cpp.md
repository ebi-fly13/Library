---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: data_structure/compress.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/offline_segtree_2d.hpp
    title: data_structure/offline_segtree_2d.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: segtree
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
  bundledCode: "#line 1 \"test/data_structure/Rectangle_Sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/rectangle_sum\"\r\n\r\n#include <cstdint>\r\
    \n#include <iostream>\r\n\r\n#line 2 \"data_structure/compress.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace ebi {\n\ntemplate\
    \ <class T> struct compress {\n  private:\n    std::vector<T> cp;\n    bool flag\
    \ = false;\n\n  public:\n    compress() = default;\n\n    compress(std::vector<T>\
    \ cp) : cp(cp) {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \        flag = true;\n    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n\
    \        flag = false;\n    }\n\n    int get(const T &val) {\n        if (flag\
    \ == false) build();\n        return std::lower_bound(cp.begin(), cp.end(), val)\
    \ - cp.begin();\n    }\n\n    int size() const {\n        return cp.size();\n\
    \    }\n\n    T val(int idx) const {\n        assert(0 <= idx && idx < (int)cp.size());\n\
    \        return cp[idx];\n    }\n};\n\n}  // namespace ebi\n#line 3 \"data_structure/offline_segtree_2d.hpp\"\
    \n\n/*\n    reference: https://blog.hamayanhamayan.com/entry/2017/12/09/015937\n\
    \    verify   : http://codeforces.com/contest/893/submission/125531718\n*/\n\n\
    #line 2 \"data_structure/segtree.hpp\"\n\r\n#line 5 \"data_structure/segtree.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class S, S (*op)(S, S), S (*e)()> struct\
    \ segtree {\r\n  private:\r\n    int n;\r\n    int sz;\r\n    std::vector<S> data;\r\
    \n\r\n    void update(int i) {\r\n        data[i] = op(data[2 * i], data[2 * i\
    \ + 1]);\r\n    }\r\n\r\n  public:\r\n    segtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\r\n    segtree(const std::vector<S> &v) : n((int)v.size()), sz(1) {\r\
    \n        while (sz < n) sz *= 2;\r\n        data = std::vector<S>(2 * sz, e());\r\
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
    \ ebi\r\n#line 10 \"data_structure/offline_segtree_2d.hpp\"\n\nnamespace ebi {\n\
    \ntemplate <class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>\nstruct\
    \ offline_segtree_2d {\n  private:\n    Monoid prod(int l, int r, int x, int y,\
    \ int nl, int nr, int k) {\n        if (r <= nl || nr <= l) {\n            return\
    \ e();\n        }\n        if (l <= nl && nr <= r) {\n            int tx = std::lower_bound(data[k].begin(),\
    \ data[k].end(), x) -\n                     data[k].begin();\n            int\
    \ ty = std::lower_bound(data[k].begin(), data[k].end(), y) -\n               \
    \      data[k].begin();\n            return seg[k].prod(tx, ty);\n        }\n\
    \        return op(prod(l, r, x, y, nl, (nl + nr) / 2, 2 * k + 1),\n         \
    \         prod(l, r, x, y, (nl + nr) / 2, nr, 2 * k + 2));\n    }\n\n    void\
    \ pre_prod(int l, int r, int x, int y, int nl, int nr, int k) {\n        if (r\
    \ <= nl || nr <= l) {\n            return;\n        }\n        if (l <= nl &&\
    \ nr <= r) {\n            data[k].emplace_back(x);\n            data[k].emplace_back(y);\n\
    \            return;\n        }\n        pre_prod(l, r, x, y, nl, (nl + nr) /\
    \ 2, 2 * k + 1);\n        pre_prod(l, r, x, y, (nl + nr) / 2, nr, 2 * k + 2);\n\
    \    }\n\n  public:\n    offline_segtree_2d(int _n) : n(1) {\n        while (n\
    \ < _n) {\n            n <<= 1;\n        }\n        data.resize(2 * n - 1);\n\
    \    }\n\n    void add(int x, int y, Monoid val) {\n        int k = n + x - 1;\n\
    \        int ty = std::lower_bound(data[k].begin(), data[k].end(), y) -\n    \
    \             data[k].begin();\n        seg[k].set(ty, op(seg[k].get(ty), val));\n\
    \        while (k > 0) {\n            k = (k - 1) / 2;\n            ty = std::lower_bound(data[k].begin(),\
    \ data[k].end(), y) -\n                 data[k].begin();\n            seg[k].set(ty,\
    \ op(seg[k].get(ty), val));\n        }\n    }\n\n    Monoid prod(int l, int r,\
    \ int x, int y) {\n        return prod(l, r, x, y, 0, n, 0);\n    }\n\n    void\
    \ build() {\n        for (int i = 0; i < 2 * n - 1; ++i) {\n            std::sort(data[i].begin(),\
    \ data[i].end());\n            data[i].erase(std::unique(data[i].begin(), data[i].end()),\n\
    \                          data[i].end());\n            seg.emplace_back(segtree<Monoid,\
    \ op, e>(int(data[i].size())));\n        }\n    }\n\n    void pre_set(int x, int\
    \ y) {\n        int k = n + x - 1;\n        data[k].emplace_back(y);\n       \
    \ while (k > 0) {\n            k = (k - 1) / 2;\n            data[k].emplace_back(y);\n\
    \        }\n    }\n\n    void pre_prod(int l, int r, int x, int y) {\n       \
    \ pre_prod(l, r, x, y, 0, n, 0);\n    }\n\n  private:\n    std::vector<std::vector<Monoid>\
    \ > data;\n    std::vector<segtree<Monoid, op, e> > seg;\n    int n;\n};\n\n}\
    \  // namespace ebi\n#line 8 \"test/data_structure/Rectangle_Sum.test.cpp\"\n\r\
    \nusing i64 = std::int64_t;\r\n\r\ni64 op(i64 a, i64 b) {\r\n    return a + b;\r\
    \n}\r\n\r\ni64 e() {\r\n    return 0;\r\n}\r\n\r\nint main() {\r\n    int n, q;\r\
    \n    std::cin >> n >> q;\r\n    ebi::compress<i64> cp;\r\n    std::vector<i64>\
    \ x(n), y(n), w(n);\r\n    for (int i = 0; i < n; i++) {\r\n        std::cin >>\
    \ x[i] >> y[i] >> w[i];\r\n        cp.add(x[i]);\r\n    }\r\n    cp.build();\r\
    \n    ebi::offline_segtree_2d<i64, op, e> seg(cp.size());\r\n    for (int i =\
    \ 0; i < n; i++) {\r\n        seg.pre_set(cp.get(x[i]), y[i]);\r\n    }\r\n  \
    \  seg.build();\r\n    for (int i = 0; i < n; i++) {\r\n        seg.add(cp.get(x[i]),\
    \ y[i], w[i]);\r\n    }\r\n    while (q--) {\r\n        i64 l, d, r, u;\r\n  \
    \      std::cin >> l >> d >> r >> u;\r\n        std::cout << seg.prod(cp.get(l),\
    \ cp.get(r), d, u) << std::endl;\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\r\n\r\n\
    #include <cstdint>\r\n#include <iostream>\r\n\r\n#include \"../../data_structure/compress.hpp\"\
    \r\n#include \"../../data_structure/offline_segtree_2d.hpp\"\r\n\r\nusing i64\
    \ = std::int64_t;\r\n\r\ni64 op(i64 a, i64 b) {\r\n    return a + b;\r\n}\r\n\r\
    \ni64 e() {\r\n    return 0;\r\n}\r\n\r\nint main() {\r\n    int n, q;\r\n   \
    \ std::cin >> n >> q;\r\n    ebi::compress<i64> cp;\r\n    std::vector<i64> x(n),\
    \ y(n), w(n);\r\n    for (int i = 0; i < n; i++) {\r\n        std::cin >> x[i]\
    \ >> y[i] >> w[i];\r\n        cp.add(x[i]);\r\n    }\r\n    cp.build();\r\n  \
    \  ebi::offline_segtree_2d<i64, op, e> seg(cp.size());\r\n    for (int i = 0;\
    \ i < n; i++) {\r\n        seg.pre_set(cp.get(x[i]), y[i]);\r\n    }\r\n    seg.build();\r\
    \n    for (int i = 0; i < n; i++) {\r\n        seg.add(cp.get(x[i]), y[i], w[i]);\r\
    \n    }\r\n    while (q--) {\r\n        i64 l, d, r, u;\r\n        std::cin >>\
    \ l >> d >> r >> u;\r\n        std::cout << seg.prod(cp.get(l), cp.get(r), d,\
    \ u) << std::endl;\r\n    }\r\n}"
  dependsOn:
  - data_structure/compress.hpp
  - data_structure/offline_segtree_2d.hpp
  - data_structure/segtree.hpp
  isVerificationFile: true
  path: test/data_structure/Rectangle_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-06-26 02:49:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Rectangle_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Rectangle_Sum.test.cpp
- /verify/test/data_structure/Rectangle_Sum.test.cpp.html
title: test/data_structure/Rectangle_Sum.test.cpp
---
