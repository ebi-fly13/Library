---
title: $\sum_{i = 0}^{n-1} a^i f(i)$
documentation_of: //math/sum_of_exp_times_poly.hpp
---

## 説明

$K$ 次多項式 $f(n)$ について、 $f(0), f(1), \dots, f(k)$ が与えられる。 
$\sum_{i = 0}^{n-1} a^i f(i)$ を $O(K + \log{mod})$ で求める。

### sum_of_exp_times_poly(f, a, n)

$K$ 次多項式 $f(n)$ の $f(0), f(1), \dots, f(k)$ と $a, n$ を与えて $\sum_{i = 0}^{n-1} a^i f(i)$ を求める。

### sum_of_exp2(r, d, n)

$f(n) = n^k$ について求める。つまり、 $\sum_{i = 0}^{n-1} r^i i^d$ を求める。

