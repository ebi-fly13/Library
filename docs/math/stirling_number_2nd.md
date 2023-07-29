---
title: Stirling Numbers of the Second Kind
documentation_of: //math/stirling_number_2nd.hpp
---

## 説明

第 $2$ 種スターリング数 $S(N, K)$ を $k = 0, \dots, N$ に対して求める。 $S(N, K)$ は以下のように表すことができるため、畳み込みを用いて $O(N\log N)$ で求められる。

$$
S(N, K) = \frac{1}{K!} \sum_{i = 0}^K (-1)^{K-i} \binom{k} i i^N \\
S(N, K) = \sum_{i = 0}^K \frac{(-1)^{K-i}}{(K-i)!} \frac{i^n}{i!}
$$

$S(N, K)$ は、 $N$ 個の区別できる要素を $K$ 個の空でない部分集合に分ける場合の数である。