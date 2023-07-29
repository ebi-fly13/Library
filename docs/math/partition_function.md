---
title: Partition Function
documentation_of: //math/partition_function.hpp
---

## 説明

分割数の母関数を求める。五角数定理を用いると求める母関数は以下のようなる。

$$
f = \frac{1}{1 + \sum_k (-1)^k (x^{k(3k + 1) / 2} + x^{k(3k-1)/2})}
$$

この母関数の先頭 $N+1$ 項は $O(N\log N)$ で計算できる。