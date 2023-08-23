---
title: Dirichlet Convolution
documentation_of: //convolution/dirichlet_convolution.hpp
---

## 説明

$a,b$ を与えて、 Dirichlet積 $c = a \times b$ を求める。

### 通常のDirichlet積

```dirichlet_convolution(a, b)```を用いる。
愚直にDirichlet積を求める。 $O(N\log N)$

### $a$ が乗法的関数のとき

```dirichlet_convolution_left_is_multiplicative_function(a, b)```

$a$ が乗法的関数であるとき、高速にDirichlet積を求めることができる。 $O(N\log \log N)$

### $a, b$ が乗法的関数のとき

```dirichlet_convolution_multiplicative_function(a, b)```を用いる。
$a, b$ が共に乗法的関数であるとき、さらに高速にDirichlet積を求めることができる。 $O(N)$