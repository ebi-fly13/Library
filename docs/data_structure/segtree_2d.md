---
title: 2D segtree
documentation_of: //data_structure/segtree_2d.hpp
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