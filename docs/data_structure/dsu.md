---
title: DSU
documentation_of: //data_structure/dsu.hpp
---

## 説明

$2$ つのグループを同じグループにする、 $2$ つの要素が同じグループか判定、が可能なデータ構造。ここで、 $\alpha(N)$ をアッカーマン関数の逆関数とする。

### dsu(int n)

$N$ 要素のdsuを構築する。 $O(N)$

### same(int x, int y)

$x$ と $y$ が同じグループか判定。 $O(\alpha(N))$

### merge(int x, int y)

$x$ のグループと $y$ のグループをマージ。 $O(\alpha(N))$

### leader(int x)

$x$ のグループの代表を返す。 $O(\alpha(N))$

### size(int x)

$x$ のグループのサイズを返す。 $O(\alpha(N))$

### count_group()

グループの個数を求める。 $O(n)$

### clear()

初期状態にする。 $O(N)$