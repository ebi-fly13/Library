---
title: Bitwise XOR Convolution
documentation_of: //convolution/xor_convolution.hpp
---

## 説明

長さ $2^N$ の整数列 $a$ と $b$ について、 $c_k = \sum_{i\oplus j=k} a_i b_j$ を求める。
$O(N 2^N)$