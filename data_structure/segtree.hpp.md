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
  - icon: ':x:'
    path: test/vertex_set_path_compositie.test.cpp
    title: test/vertex_set_path_compositie.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/segtree.hpp\"\n\r\n#include <cassert>\r\n\
    #include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> struct segtree {\r\n  private:\r\n    int n;\r\n    int sz;\r\n\
    \    std::vector<S> data;\r\n\r\n    void update(int i) {\r\n        data[i] =\
    \ op(data[2 * i], data[2 * i + 1]);\r\n    }\r\n\r\n  public:\r\n    segtree(int\
    \ n) : segtree(std::vector<S>(n, e())) {}\r\n    segtree(const std::vector<S>\
    \ &v) : n((int)v.size()), sz(1) {\r\n        while (sz < n) sz *= 2;\r\n     \
    \   data = std::vector<S>(2 * sz, e());\r\n        for (int i = 0; i < n; i++)\
    \ {\r\n            data[sz + i] = v[i];\r\n        }\r\n        for (int i = sz\
    \ - 1; i >= 1; i--) update(i);\r\n    }\r\n\r\n    void set(int p, S x) {\r\n\
    \        assert(0 <= p && p < n);\r\n        p += sz;\r\n        data[p] = x;\r\
    \n        while (p > 1) {\r\n            p >>= 1;\r\n            update(p);\r\n\
    \        }\r\n    }\r\n\r\n    S get(int p) {\r\n        assert(0 <= p && p <\
    \ n);\r\n        return data[p + sz];\r\n    }\r\n\r\n    S prod(int l, int r)\
    \ {\r\n        assert(0 <= l && l <= r && r <= n);\r\n        S sml = e(), smr\
    \ = e();\r\n        l += sz;\r\n        r += sz;\r\n        while (l < r) {\r\n\
    \            if (l & 1) sml = op(sml, data[l++]);\r\n            if (r & 1) smr\
    \ = op(data[--r], smr);\r\n            l >>= 1;\r\n            r >>= 1;\r\n  \
    \      }\r\n        return op(sml, smr);\r\n    }\r\n\r\n    S all_prod() {\r\n\
    \        return data[1];\r\n    }\r\n\r\n    template <class F> int max_right(int\
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
    \ + p];\r\n    }\r\n};\r\n\r\n}  // namespace ebi\r\n"
  code: "#pragma once\r\n\r\n#include <cassert>\r\n#include <vector>\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <class S, S (*op)(S, S), S (*e)()> struct segtree {\r\n\
    \  private:\r\n    int n;\r\n    int sz;\r\n    std::vector<S> data;\r\n\r\n \
    \   void update(int i) {\r\n        data[i] = op(data[2 * i], data[2 * i + 1]);\r\
    \n    }\r\n\r\n  public:\r\n    segtree(int n) : segtree(std::vector<S>(n, e()))\
    \ {}\r\n    segtree(const std::vector<S> &v) : n((int)v.size()), sz(1) {\r\n \
    \       while (sz < n) sz *= 2;\r\n        data = std::vector<S>(2 * sz, e());\r\
    \n        for (int i = 0; i < n; i++) {\r\n            data[sz + i] = v[i];\r\n\
    \        }\r\n        for (int i = sz - 1; i >= 1; i--) update(i);\r\n    }\r\n\
    \r\n    void set(int p, S x) {\r\n        assert(0 <= p && p < n);\r\n       \
    \ p += sz;\r\n        data[p] = x;\r\n        while (p > 1) {\r\n            p\
    \ >>= 1;\r\n            update(p);\r\n        }\r\n    }\r\n\r\n    S get(int\
    \ p) {\r\n        assert(0 <= p && p < n);\r\n        return data[p + sz];\r\n\
    \    }\r\n\r\n    S prod(int l, int r) {\r\n        assert(0 <= l && l <= r &&\
    \ r <= n);\r\n        S sml = e(), smr = e();\r\n        l += sz;\r\n        r\
    \ += sz;\r\n        while (l < r) {\r\n            if (l & 1) sml = op(sml, data[l++]);\r\
    \n            if (r & 1) smr = op(data[--r], smr);\r\n            l >>= 1;\r\n\
    \            r >>= 1;\r\n        }\r\n        return op(sml, smr);\r\n    }\r\n\
    \r\n    S all_prod() {\r\n        return data[1];\r\n    }\r\n\r\n    template\
    \ <class F> int max_right(int l, F f) {\r\n        assert(0 <= l && l < n);\r\n\
    \        assert(f(e()));\r\n        if (l == n) return n;\r\n        l += sz;\r\
    \n        S sm = e();\r\n        do {\r\n            while (l % 2 == 0) l >>=\
    \ 1;\r\n            if (!f(op(sm, data[l]))) {\r\n                while (l < sz)\
    \ {\r\n                    l = 2 * l;\r\n                    if (f(op(sm, data[l])))\
    \ {\r\n                        sm = op(sm, data[l]);\r\n                     \
    \   l++;\r\n                    }\r\n                }\r\n                return\
    \ l - sz;\r\n            }\r\n            sm = op(sm, data[l]);\r\n          \
    \  l++;\r\n        } while ((l & -l) != l);\r\n        return n;\r\n    }\r\n\r\
    \n    template <class F> int min_left(int r, F f) {\r\n        assert(0 <= r &&\
    \ r <= n);\r\n        assert(f(e()));\r\n        if (r == 0) return 0;\r\n   \
    \     r += sz;\r\n        S sm = e();\r\n        do {\r\n            r--;\r\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\r\n            if (!f(op(data[r],\
    \ sm))) {\r\n                while (r < sz) {\r\n                    r = 2 * r\
    \ + 1;\r\n                    if (f(op(data[r], sm))) {\r\n                  \
    \      sm = op(data[r], sm);\r\n                        r--;\r\n             \
    \       }\r\n                }\r\n                return r + 1 - sz;\r\n     \
    \       }\r\n            sm = op(data[r], sm);\r\n        } while ((r & -r) !=\
    \ r);\r\n        return 0;\r\n    }\r\n\r\n    S operator[](int p) const {\r\n\
    \        return data[sz + p];\r\n    }\r\n};\r\n\r\n}  // namespace ebi\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segtree.hpp
  requiredBy:
  - data_structure/segtree_2d.hpp
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/vertex_add_path_sum.test.cpp
  - test/vertex_add_subtree_sum.test.cpp
  - test/vertex_set_path_compositie.test.cpp
  - test/point_add_rectangle_sum.test.cpp
  - test/rectangle_sum.test.cpp
  - test/aoj/aoj_1645.test.cpp
  - test/Segtree.test.cpp
documentation_of: data_structure/segtree.hpp
layout: document
title: segtree
---

## 説明

モノイドの列$(a_0,a_1,\dots,a_{n-1})$に対して各種操作ができるデータ構造である。

## コンストラクタ

```cpp
(1) Segtree<S, op, e> seg(int n)
(2) Segtree<S, op, e> seg(std::vector<S> v)
```
-   型 ```S```
-   二項演算 ```S op(S, S)```
-   単位元 ```S e()```

を定義する必要がある.例としてRange Sum Queryならば以下のようになる。

```cpp
int op(int a, int b) { 
    return a+b; 
}

int e() { 
    return 0; 
}

segtree<int, op, e> seg(n);
```

計算量$O(n)$

## Operator
-   ```seg.get(int p)```
    -   a[p]を返す
-   ```seg.set(int p)```
    -   $a_p$に$x$を代入する
    -   時間計算量$O(\log n)$
-   ```seg.prod(int l, int r)```
    -   ```op(a[l], ..., a[r-1])```を計算する
    -   時間計算量$O(\log n)$
-   ```seg.all_prod()```
    -   ```op(a[0], ..., a[n-1])```を計算する
    -   時間計算量$O(1)$
-   ```seg.max_right(int l, F f)```
    -   セグ木上の二分探索。$[l, r)$ が f を満たすような最大の $r$ を返す。
-   ```seg.min_left(int r, F f)```
    - セグ木上の二分探索。$[l, r)$ が f を満たすような最小の $l$ を返す。