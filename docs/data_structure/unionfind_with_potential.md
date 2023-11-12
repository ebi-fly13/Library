---
title: UnionFind with potential
documentation_of: //data_structure/unionfind_with_potential.hpp
---

## 説明

ポテンシャル付きUnion Find。ここで、 $\alpha(n)$ をアッカーマン関数の逆関数とする。

### same(int x, int y)

$x$ と $y$ が同じグループか判定。 $O(\alpha(n))$

### merge(int x, int y, T p)

$x$ のグループと $y$ のグループをマージ。ポテンシャルは $potential(x) = potential(y) + p$ とする。 $O(\alpha(n))$

### leader(int x)

$x$ のグループの代表を返す。 $O(\alpha(n))$

### size(int x)

$x$ のグループのサイズを返す。 $O(\alpha(n))$

### potential(int x)

$x$ のポテンシャルを返す。 $O(\alpha(n))$

### diff(int x, int y)

$x$ と $y$ のポテンシャルの差分を返す。 $O(\alpha(n))$
