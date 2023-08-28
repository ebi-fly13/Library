---
title: Combination
documentation_of: //math/combination.hpp
---

## 説明

組み合わせを求める構造体。クエリの最大値を $N$ として、前計算 $O(N)$ クエリ $O(1)$ である。

### operator()(int n, int k)

$\binom{n}{k}$ を求める。

### f(int n)

$n!$ を求める。

### inv_f(int n)

$(n!)^{-1}$ を求める。

### inv(int n)

$n^{-1}$ を求める。