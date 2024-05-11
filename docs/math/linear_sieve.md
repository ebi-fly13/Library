---
title: Linear Sieve
documentation_of: //math/linear_sieve.hpp
---

## 説明

線形篩。線形で、 $[1, N]$ の整数の最小の素因数を求める。

### prime_table()

$[1, N]$ に含まれる素数を列挙する。 $O(N)$

### prime_power_table(int m)

$i \in [1, M]$ について、 $i$ の最小素因数を $p$ と $p^k \mid i$ となる最大の $p^k$ を列挙する。 $O(M)$

### factorize(int n)

$n$ を素因数分解する。 $O(\log N)$

### divisors(int n)

$n$ の約数を列挙する。

### fast_zeta(std::vector<T> f)

$f$ を約数に関してゼータ変換（Multiple）する。 $O(N\log \log N)$

### fast_mobius(std::vector<T> F)

$F$ を約数に関してメビウス変換（Multiple）する。 $O(N\log \log N)$

### pow_table(int m, int k)

$[1, M]$ に含まれる $i$ に対して $i^k$ を計算する。 $O(M \frac{\log k}{\log M})$

### inv_table()

$[1, N]$ に含まれる $i$ に対して $i^{-1} \mod m$ を計算する。 $O(N \frac{\log m}{\log N})$
