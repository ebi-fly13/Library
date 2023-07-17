---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/compress.hpp
    title: data_structure/compress.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
    title: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
  - icon: ':x:'
    path: test/data_structure/Rectangle_Sum_Segtree.test.cpp
    title: test/data_structure/Rectangle_Sum_Segtree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - http://codeforces.com/contest/893/submission/125531718
    - https://blog.hamayanhamayan.com/entry/2017/12/09/015937
  bundledCode: "#line 2 \"data_structure/offline_segtree_2d.hpp\"\n\n#include <algorithm>\n\
    #include <vector>\n\n/*\n    reference: https://blog.hamayanhamayan.com/entry/2017/12/09/015937\n\
    \    verify   : http://codeforces.com/contest/893/submission/125531718\n*/\n\n\
    #line 2 \"data_structure/compress.hpp\"\n\n#line 4 \"data_structure/compress.hpp\"\
    \n#include <cassert>\n#line 6 \"data_structure/compress.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <class T> struct compress {\n  private:\n    std::vector<T> cp;\n\
    \n  public:\n    compress() = default;\n\n    compress(std::vector<T> cp) : cp(cp)\
    \ {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n    }\n\
    \n    int get(const T &val) const {\n        return std::lower_bound(cp.begin(),\
    \ cp.end(), val) - cp.begin();\n    }\n\n    int size() const {\n        return\
    \ cp.size();\n    }\n\n    bool find(const T& val) const {\n        auto itr =\
    \ std::lower_bound(cp.begin(), cp.end(), val);\n        if(itr == cp.end()) return\
    \ false;\n        else return *itr == val;\n    }\n\n    T val(int idx) const\
    \ {\n        assert(0 <= idx && idx < (int)cp.size());\n        return cp[idx];\n\
    \    }\n};\n\n}  // namespace ebi\n#line 12 \"data_structure/offline_segtree_2d.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class S, S (*op)(S, S), S (*e)(), class data_structure>\n\
    struct offline_segtree_2d {\n    offline_segtree_2d() = default;\n\n    void pre_set(std::pair<int,\
    \ int> p) {\n        ps.emplace_back(p);\n    }\n\n    void build() {\n      \
    \  for (auto [x, y] : ps) {\n            xs.add(x);\n        }\n        xs.build();\n\
    \        while (sz < xs.size()) sz <<= 1;\n        ys.resize(2 * sz);\n      \
    \  for (auto [x, y] : ps) {\n            int i = xs.get(x) + sz;\n           \
    \ ys[i].add(y);\n            while (i > 1) {\n                i >>= 1;\n     \
    \           ys[i].add(y);\n            }\n        }\n        for (int i = 0; i\
    \ < 2 * sz; i++) {\n            ys[i].build();\n            data.emplace_back(data_structure(ys[i].size()));\n\
    \        }\n    }\n\n    void set(int i, int j, S val) {\n        i = xs.get(i);\n\
    \        i += sz;\n        data[i].set(ys[i].get(j), val);\n        while (i >\
    \ 1) {\n            i >>= 1;\n            S res = e();\n            if (ys[2 *\
    \ i].find(j)) {\n                res = op(res, data[2 * i].get(ys[2 * i].get(j)));\n\
    \            }\n            if (ys[2 * i + 1].find(j)) {\n                res\
    \ = op(res, data[2 * i + 1].get(ys[2 * i + 1].get(j)));\n            }\n     \
    \       data[i].set(ys[i].get(j), res);\n        }\n    }\n\n    S get(int i,\
    \ int j) const {\n        i = xs.get(i) + sz;\n        return data[i].get(ys[i].get(j));\n\
    \    }\n\n    S prod(int l, int d, int r, int u) const {\n        l = xs.get(l)\
    \ + sz;\n        r = xs.get(r) + sz;\n        S res = e();\n        while (l <\
    \ r) {\n            if (l & 1) {\n                res = op(res, data[l].prod(ys[l].get(d),\
    \ ys[l].get(u)));\n                l++;\n            }\n            if (r & 1)\
    \ {\n                r--;\n                res = op(data[r].prod(ys[r].get(d),\
    \ ys[r].get(u)), res);\n            }\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n        return res;\n    }\n\n  private:\n    int sz = 1;\n \
    \   std::vector<std::pair<int, int>> ps;\n    compress<int> xs;\n    std::vector<compress<int>>\
    \ ys;\n    std::vector<data_structure> data;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\n/*\n    reference:\
    \ https://blog.hamayanhamayan.com/entry/2017/12/09/015937\n    verify   : http://codeforces.com/contest/893/submission/125531718\n\
    */\n\n#include \"../data_structure/compress.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)(), class data_structure>\nstruct offline_segtree_2d\
    \ {\n    offline_segtree_2d() = default;\n\n    void pre_set(std::pair<int, int>\
    \ p) {\n        ps.emplace_back(p);\n    }\n\n    void build() {\n        for\
    \ (auto [x, y] : ps) {\n            xs.add(x);\n        }\n        xs.build();\n\
    \        while (sz < xs.size()) sz <<= 1;\n        ys.resize(2 * sz);\n      \
    \  for (auto [x, y] : ps) {\n            int i = xs.get(x) + sz;\n           \
    \ ys[i].add(y);\n            while (i > 1) {\n                i >>= 1;\n     \
    \           ys[i].add(y);\n            }\n        }\n        for (int i = 0; i\
    \ < 2 * sz; i++) {\n            ys[i].build();\n            data.emplace_back(data_structure(ys[i].size()));\n\
    \        }\n    }\n\n    void set(int i, int j, S val) {\n        i = xs.get(i);\n\
    \        i += sz;\n        data[i].set(ys[i].get(j), val);\n        while (i >\
    \ 1) {\n            i >>= 1;\n            S res = e();\n            if (ys[2 *\
    \ i].find(j)) {\n                res = op(res, data[2 * i].get(ys[2 * i].get(j)));\n\
    \            }\n            if (ys[2 * i + 1].find(j)) {\n                res\
    \ = op(res, data[2 * i + 1].get(ys[2 * i + 1].get(j)));\n            }\n     \
    \       data[i].set(ys[i].get(j), res);\n        }\n    }\n\n    S get(int i,\
    \ int j) const {\n        i = xs.get(i) + sz;\n        return data[i].get(ys[i].get(j));\n\
    \    }\n\n    S prod(int l, int d, int r, int u) const {\n        l = xs.get(l)\
    \ + sz;\n        r = xs.get(r) + sz;\n        S res = e();\n        while (l <\
    \ r) {\n            if (l & 1) {\n                res = op(res, data[l].prod(ys[l].get(d),\
    \ ys[l].get(u)));\n                l++;\n            }\n            if (r & 1)\
    \ {\n                r--;\n                res = op(data[r].prod(ys[r].get(d),\
    \ ys[r].get(u)), res);\n            }\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n        return res;\n    }\n\n  private:\n    int sz = 1;\n \
    \   std::vector<std::pair<int, int>> ps;\n    compress<int> xs;\n    std::vector<compress<int>>\
    \ ys;\n    std::vector<data_structure> data;\n};\n\n}  // namespace ebi"
  dependsOn:
  - data_structure/compress.hpp
  isVerificationFile: false
  path: data_structure/offline_segtree_2d.hpp
  requiredBy: []
  timestamp: '2023-06-26 12:08:21+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/data_structure/Point_Add_Rectangle_Sum.test.cpp
  - test/data_structure/Rectangle_Sum_Segtree.test.cpp
documentation_of: data_structure/offline_segtree_2d.hpp
layout: document
title: offline 2D segtree
---

## 説明

可換モノイドについて、1点更新、長方形領域クエリを行えるデータ構造。クエリ先読みにより、必要な部分だけ作ることでメモリ使用量を減らして点の座標が$10^9$とかでも使える。

```
segtree_2d<S, op, e, data_structure> seg2d(h, w)
```

とすることで $h \times w$ の単位元で初期化された長方形を作る。
`S, op, e`は可換モノイド、`data_structure`には以下を要求する

- `void set(int i, S x)`
- `S get(i)`
- `S prod(l, r)`

これを満たすデータ構造ならなんでもok (segtree、fenwick treeなどなど)

### pre_set(i, j)

$(i,j)$ を追加する。

### build()

クエリ先読み後（pre_set後）、セグ木を構築する。

### set(i, j, x)

$(i, j)$ を $x$ に更新する。O(\log H)

### get(i, j, x)

$(i, j)$ の値を返す。 $O(1)$

### prod(l, d, r, u)

$[l, r) \times [d, u)$ の領域に対してクエリを処理する $O(\log H \log W)$