---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/heavy_light_decomposition.hpp
    title: data_structure/heavy_light_decomposition.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree_2d.hpp
    title: data_structure/segtree_2d.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Segtree.test.cpp
    title: test/Segtree.test.cpp
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
  bundledCode: "#line 2 \"data_structure/Segtree.hpp\"\n\r\n#include <vector>\r\n\r\
    \nnamespace ebi {\r\n\r\ntemplate<class Monoid, Monoid (*op)(Monoid, Monoid),\
    \ Monoid (*e)()>\r\nstruct Segtree {\r\nprivate:\r\n    std::vector<Monoid> data;\r\
    \n    int n;\r\npublic:\r\n    Segtree(int _n) : n(1) {\r\n        while(n<_n){\r\
    \n            n <<= 1;\r\n        }\r\n        data.assign(2*n-1, e());\r\n  \
    \  }\r\n\r\n    Segtree(std::vector<Monoid> v) : n(1) {\r\n        int _n = v.size();\r\
    \n        while(n<_n){\r\n            n <<= 1;\r\n        }\r\n        data.assign(2*n-1,\
    \ e());\r\n        for(int i = 0; i<_n; i++){\r\n            data[n+i-1] = v[i];\r\
    \n        }\r\n        for(int i = n-2; i>=0; i--){\r\n            data[i] = op(data[2*i+1],\
    \ data[2*i+2]);\r\n        }\r\n    }\r\n\r\n    void set(int p, Monoid x){\r\n\
    \        int k = n+p-1;\r\n        data[k] = x;\r\n        while(k>0){\r\n   \
    \         k = (k-1)/2;\r\n            data[k] = op(data[2*k+1], data[2*k+2]);\r\
    \n        }\r\n    }\r\n\r\n    Monoid prod(int tl, int tr, int l=0, int r=-1,\
    \ int index=0){\r\n        if(r<0) r = n;\r\n        if(tr<=l || r<=tl){\r\n \
    \           return e();\r\n        }\r\n        if(tl<=l && r<=tr){\r\n      \
    \      return data[index];\r\n        }\r\n        return op(prod(tl, tr, l, (l+r)/2,\
    \ 2*index+1), prod(tl, tr, (l+r)/2, r, 2*index+2));\r\n    }\r\n\r\n    Monoid\
    \ all_prod() { return data[0]; }\r\n\r\n    Monoid get(int p) { return data[n+p-1];\
    \ }\r\n\r\n    Monoid operator [] (int p) { return data[n+p-1]; }\r\n};\r\n\r\n\
    } // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class\
    \ Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>\r\nstruct Segtree {\r\n\
    private:\r\n    std::vector<Monoid> data;\r\n    int n;\r\npublic:\r\n    Segtree(int\
    \ _n) : n(1) {\r\n        while(n<_n){\r\n            n <<= 1;\r\n        }\r\n\
    \        data.assign(2*n-1, e());\r\n    }\r\n\r\n    Segtree(std::vector<Monoid>\
    \ v) : n(1) {\r\n        int _n = v.size();\r\n        while(n<_n){\r\n      \
    \      n <<= 1;\r\n        }\r\n        data.assign(2*n-1, e());\r\n        for(int\
    \ i = 0; i<_n; i++){\r\n            data[n+i-1] = v[i];\r\n        }\r\n     \
    \   for(int i = n-2; i>=0; i--){\r\n            data[i] = op(data[2*i+1], data[2*i+2]);\r\
    \n        }\r\n    }\r\n\r\n    void set(int p, Monoid x){\r\n        int k =\
    \ n+p-1;\r\n        data[k] = x;\r\n        while(k>0){\r\n            k = (k-1)/2;\r\
    \n            data[k] = op(data[2*k+1], data[2*k+2]);\r\n        }\r\n    }\r\n\
    \r\n    Monoid prod(int tl, int tr, int l=0, int r=-1, int index=0){\r\n     \
    \   if(r<0) r = n;\r\n        if(tr<=l || r<=tl){\r\n            return e();\r\
    \n        }\r\n        if(tl<=l && r<=tr){\r\n            return data[index];\r\
    \n        }\r\n        return op(prod(tl, tr, l, (l+r)/2, 2*index+1), prod(tl,\
    \ tr, (l+r)/2, r, 2*index+2));\r\n    }\r\n\r\n    Monoid all_prod() { return\
    \ data[0]; }\r\n\r\n    Monoid get(int p) { return data[n+p-1]; }\r\n\r\n    Monoid\
    \ operator [] (int p) { return data[n+p-1]; }\r\n};\r\n\r\n} // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/Segtree.hpp
  requiredBy:
  - data_structure/segtree_2d.hpp
  - data_structure/heavy_light_decomposition.hpp
  timestamp: '2021-05-03 16:11:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/vertex_add_path_sum.test.cpp
  - test/Segtree.test.cpp
  - test/point_add_rectangle_sum.test.cpp
  - test/vertex_add_subtree_sum.test.cpp
  - test/rectangle_sum.test.cpp
  - test/vertex_set_path_compositie.test.cpp
documentation_of: data_structure/Segtree.hpp
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