---
title: Subset Transform (Zeta / Möbius)
documentation_of: //set_function/subset_transform.hpp
---

## 説明

$N$ 要素の集合の冪集合に値が定義されている配列 $a$ について $\zeta a$ を部分集合の累積和とする。
つまり以下の式を満たす $\zeta a$ を求めることを $\zeta$ 変換という。逆変換をメビウス変換という。

$$
\zeta a_{S} = \sum_{T \subset S} a_T
$$

いずれも、 $O(N2^N)$ で変換することができる。