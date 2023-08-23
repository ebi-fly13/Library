---
title: Dirichlet Series
documentation_of: //math/DirichletSeries.hpp
---

## 説明

Dirichlet級数を取り扱う構造体。
$a$ に関するDirichlet級数 $D_a(s)$ は

$$D_a(s) = \sum_{n = 1}^{\infty} a_n s^{-n}$$

で表される。これを長さ $N$ で打ち切ったものについて取り扱う。

Dirichlet級数についてと実装方法について、[maspyさんの記事](https://maspypy.com/dirichlet-%e7%a9%8d%e3%81%a8%e3%80%81%e6%95%b0%e8%ab%96%e9%96%a2%e6%95%b0%e3%81%ae%e7%b4%af%e7%a9%8d%e5%92%8c)を参考にした。

### コンストラクタ

$a_i$ を返す関数 $f$ とその累積和 $A_i$ を計算する関数 $F$ を引数として渡すことで、 $a$ に関するDirichlet級数を生成する。

```set_size(n)```をすることを**忘れず**にすること。

### 和・差

$O(K + L)$

### 積

$O(K\log K + (NL)^{1/2})$

### 商

$O(K\log K + (NL)^{1/2})$

### get_sum()

$sum_{n = 1}^{N} a_n$ を返す。 $O(1)$

### pow(u64 n)

Dirichlet級数 $a$ について $a^n$ を求める。繰り返し二乗法で $\log n$ 回程度の積が実行される。

### zeta()

$\zeta(s) = \sum_{n = 1}^{\infty} s^{-n}$ のDirichlet級数を返す。

### zeta1()

$\zeta(s-1) = \sum_{n = 1}^{\infty} n \times s^{-n}$ のDirichlet級数を返す。

### set_size(i64 n)

長さを $n$ にする。

### set_size_multiplicative(i64 n)

長さを $n$ として、 $a$ が乗法的関数のとき、計算量が良くなるような分割になるようにする。