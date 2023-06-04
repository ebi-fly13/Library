---
title: Bostan-Mori Algorithm 
documentation_of: //math/bostan_mori_algorithm.hpp
---

## 説明

$P(x)$ を高々 $d-1$ 次の多項式、 $Q(x)$ を $d$ 次の多項式とし、 $[x^0]Q(x) = 1$ とする。

$[x^N] \frac{P(x)}{Q(x)}$

を求める。$d$ 次の多項式積を $M(d)$ でできるとすると、計算量は $O(M(d) \log N)$ となる。

### bostan_mori_algorithm(std::int64_t n, std::vector<T> p, std::vector<T> q)

$[x^N] \frac{P(x)}{Q(x)}$ を求める。

### kitamasa(std::int64_t n, std::vector<T> a, std::vector<T> c) 

$a$ を 数列の先頭 $d$ 項として、線形漸化式 $a_i = \sum_{j = 1}^d c_j a_{i-j}$ を満たす数列の第 $n$ 項を求める。 $O(M(d) \log N)$