---
title: Linear Sieve
documentation_of: //math/linear_sieve.hpp
---

## 説明

線形篩。線形で、 $[1, N]$ の整数の最小の素因数を求める。

### prime_table()

$[1, N]$ に含まれる素数を列挙する。 $O(N)$

### factorize(int n)

$n$ を素因数分解する。 $O(\log N)$

### divisors(int n)

$n$ の約数を列挙する。

### fast_zeta(std::vector<T> f)

$f$ を約数に関してゼータ変換（Multiple）する。 $O(N\log \log N)$

### fast_mobius(std::vector<T> F)

$F$ を約数に関してメビウス変換（Multiple）する。 $O(N\log \log N)$

### pow_table(int k)

$[1, N]$ に含まれる $i$ に対して $i^k$ を計算する。 $O(N \frac{\log k}{\log N})$

### inv_table()

$[1, N]$ に含まれる $i$ に対して $i^{-1} \mod m$ を計算する。 $O(N \frac{\log m}{\log N})$
