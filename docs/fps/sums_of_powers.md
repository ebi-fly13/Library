---
title: $\sum_i (\sum_n A_n^i) x^i$
documentation_of: //fps/sums_of_powers.hpp
---

## 説明

$A_1, \dots, A_N$ が与えられたとき、 $\sum_i (\sum_n A_n^i) x^i$ を $i = d$ まで列挙する。 $O(N(\log N)^2 + D\log D)$

求める形式的べき級数は

$$\sum_i (\sum_n A_n^i) x^i = \sum_n \frac{1}{1-A_nx}$$

である。定数項は $len(A)$ であるので、非定数項を求められればよい。

$$\sum_{i = 1}^{\infty} (\sum_n A_n^i) x^i = \sum_n A_nx \frac{1}{1-A_nx}$$

であるので、 $x$ で割った後に積分すると

$$\int \sum_n A_n \frac{1}{1-A_nx} dx = - \sum_n \log(1 - A_nx)$$

となる。ここで

$$- \sum_n \log(1 - A_nx) = - \log \prod_n (1-A_nx)$$

であるので

$$\sum_i (\sum_n A_n^i) x^i = len(A) + x(-\log \prod_n (1-A_nx))^{\prime}$$

となる。計算量は多項式の総積が $O(N(\log N)^2)$ 、 形式的べき級数の $\log$ が $O(D\log D)$ 、形式的べき級数の微分が $O(D)$ より $O(N(\log N)^2 + D\log D)$ となる。