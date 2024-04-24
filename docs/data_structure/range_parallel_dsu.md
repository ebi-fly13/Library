---
title: Range Parallel DSU
documentation_of: //data_structure/range_parallel_dsu.hpp
---

## 説明

### range_parallel_dsu(int n)

要素数 $n$ のdsuを作る。空間 $O(N\log{N})$

### same(int x, int y)

$x$ と $y$ が同じグループか判定。 $O(\alpha(N))$

### merge(int x, int y, int w)

$i \in [0, w)$ について $x + i$ と $y + i$ を同じグループにする。

### leader(int x)

$x$ のグループの代表を返す。 $O(\alpha(N))$

### size(int x)

$x$ のグループのサイズを返す。 $O(\alpha(N))$

### groups()

グループを列挙する。 $O(N\alpha(N))$

### count_group()

グループの個数を求める。 $O(n)$