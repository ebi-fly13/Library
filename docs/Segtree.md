---
title: segtree
documentation_of: //data_structure/segtree.hpp
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