---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_1068_1.test.cpp
    title: test/aoj/aoj_1068_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/segtree_2d.hpp\"\n\r\n#include <cassert>\r\
    \n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)(), class data_structure>\r\nstruct segtree_2d {\r\n  private:\r\n\
    \  public:\r\n    segtree_2d(int h, int w) : h(h), w(w), sz(1) {\r\n        while\
    \ (sz < h) sz <<= 1;\r\n        data = std::vector<data_structure>(2 * sz, data_structure(w));\r\
    \n    }\r\n\r\n    void set(int i, int j, S x) {\r\n        assert(0 <= i && i\
    \ < h && 0 <= j && j < w);\r\n        i += sz;\r\n        data[i].set(j, x);\r\
    \n        while (i > 1) {\r\n            i >>= 1;\r\n            S val = op(data[2\
    \ * i].get(j), data[2 * i + 1].get(j));\r\n            data[i].set(j, val);\r\n\
    \        }\r\n    }\r\n\r\n    S get(int i, int j) const {\r\n        assert(0\
    \ <= i && i < h && 0 <= j && j < w);\r\n        return data[i + sz].get(j);\r\n\
    \    }\r\n\r\n    S prod(int l, int d, int r, int u) const {\r\n        assert(0\
    \ <= l && l <= r && r <= h);\r\n        assert(0 <= d && d <= u && u <= w);\r\n\
    \        l += sz;\r\n        r += sz;\r\n        S res = e();\r\n        while\
    \ (l < r) {\r\n            if (l & 1) res = op(res, data[l++].prod(d, u));\r\n\
    \            if (r & 1) res = op(data[--r].prod(d, u), res);\r\n            l\
    \ >>= 1;\r\n            r >>= 1;\r\n        }\r\n        return res;\r\n    }\r\
    \n\r\n  private:\r\n    int h, w;\r\n    int sz;\r\n    std::vector<data_structure>\
    \ data;\r\n};\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <cassert>\r\n#include <vector>\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <class S, S (*op)(S, S), S (*e)(), class data_structure>\r\
    \nstruct segtree_2d {\r\n  private:\r\n  public:\r\n    segtree_2d(int h, int\
    \ w) : h(h), w(w), sz(1) {\r\n        while (sz < h) sz <<= 1;\r\n        data\
    \ = std::vector<data_structure>(2 * sz, data_structure(w));\r\n    }\r\n\r\n \
    \   void set(int i, int j, S x) {\r\n        assert(0 <= i && i < h && 0 <= j\
    \ && j < w);\r\n        i += sz;\r\n        data[i].set(j, x);\r\n        while\
    \ (i > 1) {\r\n            i >>= 1;\r\n            S val = op(data[2 * i].get(j),\
    \ data[2 * i + 1].get(j));\r\n            data[i].set(j, val);\r\n        }\r\n\
    \    }\r\n\r\n    S get(int i, int j) const {\r\n        assert(0 <= i && i <\
    \ h && 0 <= j && j < w);\r\n        return data[i + sz].get(j);\r\n    }\r\n\r\
    \n    S prod(int l, int d, int r, int u) const {\r\n        assert(0 <= l && l\
    \ <= r && r <= h);\r\n        assert(0 <= d && d <= u && u <= w);\r\n        l\
    \ += sz;\r\n        r += sz;\r\n        S res = e();\r\n        while (l < r)\
    \ {\r\n            if (l & 1) res = op(res, data[l++].prod(d, u));\r\n       \
    \     if (r & 1) res = op(data[--r].prod(d, u), res);\r\n            l >>= 1;\r\
    \n            r >>= 1;\r\n        }\r\n        return res;\r\n    }\r\n\r\n  private:\r\
    \n    int h, w;\r\n    int sz;\r\n    std::vector<data_structure> data;\r\n};\r\
    \n\r\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segtree_2d.hpp
  requiredBy: []
  timestamp: '2023-06-26 02:49:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_1068_1.test.cpp
documentation_of: data_structure/segtree_2d.hpp
layout: document
title: 2D segtree
---

## 説明

可換モノイドについて、1点更新、長方形領域クエリを行えるデータ構造。

```
segtree_2d<S, op, e, data_structure> seg2d(h, w)
```

とすることで $h \times w$ の単位元で初期化された長方形を作る。
`S, op, e`は可換モノイド、`data_structure`には以下を要求する

- `void set(int i, S x)`
- `S get(i)`
- `S prod(l, r)`

これを満たすデータ構造ならなんでもok (segtree、fenwick treeなどなど)

### set(i, j, x)

$(i, j)$ を $x$ に更新する。O(\log H)

### get(i, j, x)

$(i, j)$ の値を返す。 $O(1)$

### prod(l, d, r, u)

$[l, r) \times [d, u)$ の領域に対してクエリを処理する $O(\log H \log W)$