---
title: LCM Convolution
documentation_of: //convolution/lcm_convolution.hpp
---

## 説明

長さ$N+1$ の整数列 $a$, $b$ について、 $c_k = \sum_{lcm(i, j) = k} a_i b_j$ を $O(N\log \log N)$ で計算する。