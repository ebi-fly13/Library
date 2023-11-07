---
title: Min Plus Convolution
documentation_of: //convolution/min_plus_convolution.hpp
---

## 説明

長さ$N$ の凸な整数列 $a$ と 長さ $M$ の整数列 $b$ について、 $c_k = \min_{i + j = k} (a_i + b_j)$ となる長さ $N+M-1$ の整数列を求める。 $O(N + M\log N)$

ここで、凸な数列とは $0 \leq i < N-2$ に対して $a_{i + 1} - a_i \leq a_{i + 2} - a_{i + 1}$ が成り立つことをいう。