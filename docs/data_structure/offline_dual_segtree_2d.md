---
title: offline 2D dual segtree
documentation_of: //data_structure/offline_dual_segtree_2d.hpp
---

## 説明

可換モノイドについて、長方形クエリ、 $1$ 点所得を行えるデータ構造。クエリ先読みにより、必要な部分だけ作ることでメモリ使用量を減らして点の座標が$10^9$とかでも使える。

### pre_set(i, j)

所得クエリで用いる点 $(i,j)$ を追加する。

### build()

クエリ先読み後（pre_set後）、セグ木を構築する。

### apply(l,d,r,u,f)

$[l, r) \times [d, u)$ の長方形に $f$ を作用させる。

### get(i, j)

$(i, j)$ の値を所得する。