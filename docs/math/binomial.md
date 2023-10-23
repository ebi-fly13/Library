---
title: Binomial Coefficient
documentation_of: //math/binomial.hpp
---

## 説明

組み合わせを求める構造体。クエリの最大値を $N$ として、前計算 $O(N)$ クエリ $O(1)$ である。

### c(int n, int r)

$\binom{n}{r}$ を求める。

### p(int n, int r)

$n$ この中から $r$ 個選び、それを一列に並べる組み合わせを返す。

### f(int n)

$n!$ を求める。

### inv_f(int n)

$(n!)^{-1}$ を求める。

### inv(int n)

$n^{-1}$ を求める。

## reserve(int n)

処理できるクエリの最大値を $n$ にする。
