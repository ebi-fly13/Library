---
title: UnionFind with potential
documentation_of: //data_structure/unionfind_with_potential.hpp
---

## 説明

ポテンシャル付きUnionFind。ここで、 $\alpha(N)$ をアッカーマン関数の逆関数とする。

### same(int x, int y)

$x$ と $y$ が同じグループか判定。 $O(\alpha(N))$

### merge(int x, int y, T p)

$x$ のグループと $y$ のグループをマージ。ポテンシャルは $potential(x) = potential(y) + p$ とする。 $O(\alpha(N))$

### leader(int x)

$x$ のグループの代表を返す。 $O(\alpha(N))$

### size(int x)

$x$ のグループのサイズを返す。 $O(\alpha(N))$

### potential(int x)

$x$ のポテンシャルを返す。 $O(\alpha(N))$

### diff(int x, int y)

$x$ と $y$ のポテンシャルの差分を返す。 $O(\alpha(N))$
