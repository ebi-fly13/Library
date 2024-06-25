---
title: Berlekamp Massey
documentation_of: //fps/berlekamp_massey.hpp
---

## 説明

$N$ 次線形回帰数列 $a$ の母関数を $A(x)$ とする。 $A(x)$ の先頭 $2N$ 項以上を入力として与えると、以下を満たす次数 $N$ のmonicな多項式 $C(x)$ を返す。時間計算量は $O(N^2)$ である。

$$
[x^i] C(x) \times A(x) = 0 ( N \leq i )
$$