---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree_2d.hpp
    title: data_structure/segtree_2d.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Segtree.test.cpp
    title: test/Segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_1645.test.cpp
    title: test/aoj/aoj_1645.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/point_add_rectangle_sum.test.cpp
    title: test/point_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/rectangle_sum.test.cpp
    title: test/rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_add_path_sum.test.cpp
    title: test/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_add_subtree_sum.test.cpp
    title: test/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_set_path_compositie.test.cpp
    title: test/vertex_set_path_compositie.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/segtree.hpp\"\n\r\n#include <vector>\r\n\
    #include <cassert>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class Monoid, Monoid\
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
    \ }\r\n};\r\n\r\n} // namespace ebi\r\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n#include <cassert>\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate<class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>\r\
    \nstruct segtree {\r\nprivate:\r\n    int n;\r\n    int size;\r\n    std::vector<Monoid>\
    \ data;\r\npublic:\r\n    segtree(int _n) : n(_n), size(1) {\r\n        while(size\
    \ < _n) {\r\n            size <<= 1;\r\n        }\r\n        data.assign(2*size,\
    \ e());\r\n        return;\r\n    }\r\n\r\n    segtree(const std::vector<Monoid>\
    \ &v) : size(1) {\r\n        n = (int)v.size();\r\n        while(size < n) {\r\
    \n            size <<= 1;\r\n        }\r\n        data.assign(2*size, e());\r\n\
    \        std::copy(v.begin(), v.end(), data.begin() + size);\r\n        for(int\
    \ i = size-1; i > 0; i--) {\r\n            data[i] = op(data[i<<1|0], data[i<<1|1]);\r\
    \n        }\r\n        return;\r\n    }\r\n\r\n    void set(int p, Monoid x) {\r\
    \n        assert(0 <= p && p < n);\r\n        p += size;\r\n        data[p] =\
    \ x;\r\n        while(p > 1) {\r\n            p >>= 1;\r\n            data[p]\
    \ = op(data[p<<1|0], data[p<<1|1]);\r\n        }\r\n        return;\r\n    }\r\
    \n\r\n    Monoid get(int p) const {\r\n        assert(0 <= p && p < n);\r\n  \
    \      return data[p+size];\r\n    }\r\n\r\n    Monoid prod(int l, int r) const\
    \ {\r\n        assert(0 <= l && l <= r && r <= n);\r\n        Monoid left = e(),\
    \ right = e();\r\n        l += size;\r\n        r += size;\r\n        while(l\
    \ < r) {\r\n            if(l & 1) left = op(left, data[l++]);\r\n            if(r\
    \ & 1) right = op(data[--r], right);\r\n            l >>= 1;\r\n            r\
    \ >>= 1;\r\n        }\r\n        return op(left, right);\r\n    }\r\n\r\n    Monoid\
    \ all_prod() const {\r\n        return data[1];\r\n    }\r\n\r\n    Monoid operator\
    \ [] (int p) const { return data[size+p]; }\r\n};\r\n\r\n} // namespace ebi\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segtree.hpp
  requiredBy:
  - data_structure/segtree_2d.hpp
  timestamp: '2021-11-15 18:01:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Segtree.test.cpp
  - test/vertex_add_path_sum.test.cpp
  - test/rectangle_sum.test.cpp
  - test/point_add_rectangle_sum.test.cpp
  - test/vertex_set_path_compositie.test.cpp
  - test/aoj/aoj_1645.test.cpp
  - test/vertex_add_subtree_sum.test.cpp
documentation_of: data_structure/segtree.hpp
layout: document
title: Segtree
---

## 説明

モノイドの列$(a_0,a_1,\dots,a_{n-1})$に対して各種操作ができるデータ構造である.

## コンストラクタ

```cpp
(1) Segtree<Monoid, op, e> seg(int n)
(2) Segtree<Monoid, op, e> seg(std::vector<Monoid> v)
```
-   型 ```Monoid```
-   二項演算 ```Monoid op(Monoid, Monoid)```
-   単位元 ```Monoid e()```

を定義する必要がある.例としてRange Sum Queryならば以下のようになる.

```cpp
int op(int a, int b) { 
    return a+b; 
}

int e() { 
    return 0; 
}

Segtree<int, op, e> seg(n);
```

計算量$O(n)$

## Operator
-   ```seg.set(int p, Monoid x)```
    -   $a_p$に$x$を代入する.
    -   時間計算量$O(\log n)$
-   ```seg.prod(int l, int r)```
    -   ```op(a[l], ..., a[r-1])```を計算する.
    -   時間計算量$O(\log n)$
-   ```seg.all_prod()```
    -   ```op(a[0], ..., a[n-1])```を計算する.
    -   時間計算量$O(1)$
-   ```seg[int p]```
    -   ```a[p]```を返す.
    -   時間計算量$O(1)$
