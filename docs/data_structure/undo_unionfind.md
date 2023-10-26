---
title: Undo Union Find
documentation_of: //data_structure/undo_unionfind.hpp
---

## 説明

ロールバック可能なUnion Find。

### same(int x, int y)

$x$ と $y$ が同じグループか判定。 $O(\log N)$

### merge(int x, int y)

$x$ のグループと $y$ のグループをマージ。 $O(\log N)$

### leader(int x)

$x$ のグループの代表を返す。 $O(\log N)$

### size(int x)

$x$ のグループのサイズを返す。 $O(\log N)$

### count_group()

グループの個数を返す。 $O(N)$

### undo()

$1$ つ前の処理をしてない状態にロールバックする。 $O(1)$
