---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: Compress
  - icon: ':heavy_check_mark:'
    path: data_structure/offline_segtree_2d.hpp
    title: offline 2D segtree
  - icon: ':question:'
    path: data_structure/segtree.hpp
    title: segtree
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
  bundledCode: "#line 1 \"test/data_structure/Point_Add_Rectangle_Sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\r\n\
    \r\n#include <cstdint>\r\n#include <iostream>\r\n\r\n#line 2 \"data_structure/compress.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace ebi\
    \ {\n\ntemplate <class T> struct compress {\n  private:\n    std::vector<T> cp;\n\
    \n  public:\n    compress() = default;\n\n    compress(std::vector<T> cp_) : cp(cp_)\
    \ {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n    }\n\
    \n    int get(const T &val) const {\n        return std::lower_bound(cp.begin(),\
    \ cp.end(), val) - cp.begin();\n    }\n\n    int size() const {\n        return\
    \ cp.size();\n    }\n\n    bool find(const T &val) const {\n        auto itr =\
    \ std::lower_bound(cp.begin(), cp.end(), val);\n        if (itr == cp.end())\n\
    \            return false;\n        else\n            return *itr == val;\n  \
    \  }\n\n    T val(int idx) const {\n        assert(0 <= idx && idx < (int)cp.size());\n\
    \        return cp[idx];\n    }\n};\n\n}  // namespace ebi\n#line 2 \"data_structure/offline_segtree_2d.hpp\"\
    \n\n#line 5 \"data_structure/offline_segtree_2d.hpp\"\n\n/*\n    reference: https://blog.hamayanhamayan.com/entry/2017/12/09/015937\n\
    */\n\n#line 2 \"data_structure/segtree.hpp\"\n\r\n#line 5 \"data_structure/segtree.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class S, S (*op)(S, S), S (*e)()> struct\
    \ segtree {\r\n  private:\r\n    int n;\r\n    int sz;\r\n    std::vector<S> data;\r\
    \n\r\n    void update(int i) {\r\n        data[i] = op(data[2 * i], data[2 * i\
    \ + 1]);\r\n    }\r\n\r\n  public:\r\n    segtree(int n_) : segtree(std::vector<S>(n_,\
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
    \ ebi\r\n#line 12 \"data_structure/offline_segtree_2d.hpp\"\n\nnamespace ebi {\n\
    \ntemplate <class S, S (*op)(S, S), S (*e)()> struct offline_segtree_2d {\n  \
    \  offline_segtree_2d() = default;\n\n    void pre_set(int i, int j) {\n     \
    \   ps.emplace_back(i, j);\n    }\n\n    void pre_set(std::pair<int, int> p) {\n\
    \        ps.emplace_back(p);\n    }\n\n    void build() {\n        for (auto [x,\
    \ y] : ps) {\n            xs.add(x);\n        }\n        xs.build();\n       \
    \ while (sz < xs.size()) sz <<= 1;\n        ys.resize(2 * sz);\n        for (auto\
    \ [x, y] : ps) {\n            int i = xs.get(x) + sz;\n            ys[i].add(y);\n\
    \            while (i > 1) {\n                i >>= 1;\n                ys[i].add(y);\n\
    \            }\n        }\n        for (int i = 0; i < 2 * sz; i++) {\n      \
    \      ys[i].build();\n            data.emplace_back(ys[i].size());\n        }\n\
    \    }\n\n    void set(int i, int j, S val) {\n        i = xs.get(i);\n      \
    \  i += sz;\n        data[i].set(ys[i].get(j), val);\n        while (i > 1) {\n\
    \            i >>= 1;\n            S res = e();\n            if (ys[2 * i].find(j))\
    \ {\n                res = op(res, data[2 * i].get(ys[2 * i].get(j)));\n     \
    \       }\n            if (ys[2 * i + 1].find(j)) {\n                res = op(res,\
    \ data[2 * i + 1].get(ys[2 * i + 1].get(j)));\n            }\n            data[i].set(ys[i].get(j),\
    \ res);\n        }\n    }\n\n    S get(int i, int j) const {\n        i = xs.get(i)\
    \ + sz;\n        return data[i].get(ys[i].get(j));\n    }\n\n    S prod(int l,\
    \ int d, int r, int u) const {\n        l = xs.get(l) + sz;\n        r = xs.get(r)\
    \ + sz;\n        S res = e();\n        while (l < r) {\n            if (l & 1)\
    \ {\n                res = op(res, data[l].prod(ys[l].get(d), ys[l].get(u)));\n\
    \                l++;\n            }\n            if (r & 1) {\n             \
    \   r--;\n                res = op(data[r].prod(ys[r].get(d), ys[r].get(u)), res);\n\
    \            }\n            l >>= 1;\n            r >>= 1;\n        }\n      \
    \  return res;\n    }\n\n  private:\n    int sz = 1;\n    std::vector<std::pair<int,\
    \ int>> ps;\n    compress<int> xs;\n    std::vector<compress<int>> ys;\n    std::vector<segtree<S,\
    \ op, e>> data;\n};\n\n}  // namespace ebi\n#line 8 \"test/data_structure/Point_Add_Rectangle_Sum.test.cpp\"\
    \n\r\nusing i64 = std::int64_t;\r\n\r\ni64 op(i64 a, i64 b) {\r\n    return a\
    \ + b;\r\n}\r\n\r\ni64 e() {\r\n    return 0;\r\n}\r\n\r\nstruct Query {\r\n \
    \   i64 x, y, w;\r\n    i64 l, d, r, u;\r\n    int flag;\r\n};\r\n\r\nint main()\
    \ {\r\n    int n, q;\r\n    std::cin >> n >> q;\r\n    std::vector<i64> x(n),\
    \ y(n), w(n);\r\n    for (int i = 0; i < n; i++) {\r\n        std::cin >> x[i]\
    \ >> y[i] >> w[i];\r\n    }\r\n    std::vector<Query> query(q);\r\n    for (int\
    \ i = 0; i < q; i++) {\r\n        std::cin >> query[i].flag;\r\n        if (query[i].flag\
    \ == 0) {\r\n            std::cin >> query[i].x >> query[i].y >> query[i].w;\r\
    \n        } else {\r\n            std::cin >> query[i].l >> query[i].d >> query[i].r\
    \ >> query[i].u;\r\n        }\r\n    }\r\n    ebi::offline_segtree_2d<i64, op,\
    \ e> seg2d;\r\n    for (int i = 0; i < n; i++) {\r\n        seg2d.pre_set(x[i],\
    \ y[i]);\r\n    }\r\n    for (int i = 0; i < q; i++) {\r\n        if (query[i].flag\
    \ == 0) {\r\n            seg2d.pre_set(query[i].x, query[i].y);\r\n        }\r\
    \n    }\r\n    seg2d.build();\r\n    for (int i = 0; i < n; i++) {\r\n       \
    \ seg2d.set(x[i], y[i], seg2d.get(x[i], y[i]) + w[i]);\r\n    }\r\n    for (int\
    \ i = 0; i < q; i++) {\r\n        if (query[i].flag == 0) {\r\n            seg2d.set(query[i].x,\
    \ query[i].y,\r\n                      seg2d.get(query[i].x, query[i].y) + query[i].w);\r\
    \n        } else {\r\n            std::cout << seg2d.prod(query[i].l, query[i].d,\
    \ query[i].r,\r\n                                    query[i].u)\r\n         \
    \             << '\\n';\r\n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \r\n\r\n#include <cstdint>\r\n#include <iostream>\r\n\r\n#include \"../../data_structure/compress.hpp\"\
    \r\n#include \"../../data_structure/offline_segtree_2d.hpp\"\r\n\r\nusing i64\
    \ = std::int64_t;\r\n\r\ni64 op(i64 a, i64 b) {\r\n    return a + b;\r\n}\r\n\r\
    \ni64 e() {\r\n    return 0;\r\n}\r\n\r\nstruct Query {\r\n    i64 x, y, w;\r\n\
    \    i64 l, d, r, u;\r\n    int flag;\r\n};\r\n\r\nint main() {\r\n    int n,\
    \ q;\r\n    std::cin >> n >> q;\r\n    std::vector<i64> x(n), y(n), w(n);\r\n\
    \    for (int i = 0; i < n; i++) {\r\n        std::cin >> x[i] >> y[i] >> w[i];\r\
    \n    }\r\n    std::vector<Query> query(q);\r\n    for (int i = 0; i < q; i++)\
    \ {\r\n        std::cin >> query[i].flag;\r\n        if (query[i].flag == 0) {\r\
    \n            std::cin >> query[i].x >> query[i].y >> query[i].w;\r\n        }\
    \ else {\r\n            std::cin >> query[i].l >> query[i].d >> query[i].r >>\
    \ query[i].u;\r\n        }\r\n    }\r\n    ebi::offline_segtree_2d<i64, op, e>\
    \ seg2d;\r\n    for (int i = 0; i < n; i++) {\r\n        seg2d.pre_set(x[i], y[i]);\r\
    \n    }\r\n    for (int i = 0; i < q; i++) {\r\n        if (query[i].flag == 0)\
    \ {\r\n            seg2d.pre_set(query[i].x, query[i].y);\r\n        }\r\n   \
    \ }\r\n    seg2d.build();\r\n    for (int i = 0; i < n; i++) {\r\n        seg2d.set(x[i],\
    \ y[i], seg2d.get(x[i], y[i]) + w[i]);\r\n    }\r\n    for (int i = 0; i < q;\
    \ i++) {\r\n        if (query[i].flag == 0) {\r\n            seg2d.set(query[i].x,\
    \ query[i].y,\r\n                      seg2d.get(query[i].x, query[i].y) + query[i].w);\r\
    \n        } else {\r\n            std::cout << seg2d.prod(query[i].l, query[i].d,\
    \ query[i].r,\r\n                                    query[i].u)\r\n         \
    \             << '\\n';\r\n        }\r\n    }\r\n}"
  dependsOn:
  - data_structure/compress.hpp
  - data_structure/offline_segtree_2d.hpp
  - data_structure/segtree.hpp
  isVerificationFile: true
  path: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
  requiredBy: []
  timestamp: '2024-06-22 00:59:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Point_Add_Rectangle_Sum.test.cpp
- /verify/test/data_structure/Point_Add_Rectangle_Sum.test.cpp.html
title: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
---
