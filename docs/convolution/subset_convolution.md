---
title: Subset Convolution
documentation_of: //convolution/subset_convolution.hpp
---

## 説明

長さ $2^N$ の整数列 $a$ と $b$ について、 $c_k = \sum_{i\& j=0, i|j=k} a_i b_j$ を求める。
$O(N^2 2^N)$