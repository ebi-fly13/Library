---
title: GCD Convolution
documentation_of: //convolution/GCD_convolution.hpp
---

## 説明

長さ$N+1$ の整数列 $a$, $b$ について、 $c_k = \sum_{gcd(i, j) = k} a_i b_j$ を $O(N\log \log N)$ で計算する。