---
title: lazy segtree
documentation_of: //data_structure/lazy_segtree.hpp
---

## 説明

モノイドの列$(a_0,a_1,\dots,a_{n-1})$に対して各種区間操作ができるデータ構造である。インターフェースはすべてACLと同様。

### コンストラクタ

`lazy_segtree<S, op, e, F, mapping, composition, id>(int n)`
`lazy_segtree<S, op, e, F, mapping, composition, id>(const std::vector<S> &v)`

-   型 `S`
-   二項演算 `S op(S, S)`
-   単位元 `S e()`
-   写像の型 `F`
-   $f(x)$ を返す関数 `S mapping(F f, S x)`
-   $f(g)$ を返す関数 `F composition(F f, F g)`
-   $id(x) = x$ となる $id$ を返す関数 `F id()`

に対する遅延セグ木を構築する。要素数を渡す場合、 `std::vector<S>(n, e())` に対して遅延セグ木を構築する。Range add Range Sumの場合次のようになる。計算量 $O(n)$

```cpp
struct S {
    long long value;
    int size;
};
using F = long long;

S op(S a, S b) { return {a.value+b.value, a.size+b.size}; }
S e() { return {0, 0}; }
S mapping(F f, S x) { return {x.value + f*x.size, x.size}; }
F composition(F f, F g) { return f+g; }
F id() { return 0; }

lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
```

### get(int p)

v[p] を返す。

### set(int p, S x)

v[p] = x とする。

### prod(int l, int r)

op(v[l], ..., a[r-1]) を返す。

### all_prod()

op(v[0], ..., v[n-1]) を返す。

### apply(int p, F f)

v[p] に、写像 $f$ を作用させる。

### apply(int l, int r, F f)

v[l], ... v[r-1] に、写像 $f$ を作用させる。

### max_right(int l, F f)

セグ木上の二分探索。$[l, r)$ が f を満たすような最大の $r$ を返す。

### min_left(int r, F f)

セグ木上の二分探索。$[l, r)$ が f を満たすような最小の $l$ を返す。