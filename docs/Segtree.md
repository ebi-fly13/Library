---
title: Segtree
documentation_of: //data_structure/Segtree.hpp
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