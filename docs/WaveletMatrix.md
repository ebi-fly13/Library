---
title: WaveletMatrix
documentation_of: //data_structure/WaveletMatrix.hpp
---

## 説明

整数列$(a_0, a_1, \dots, a_{n-1})$を扱う静的なデータ構造である.

## コンストラクタ

```cpp
WaveletMatrix<T> wm(std::vector<T> v);
```

-   整数型$T$
-   制数列$(a_0, a_1, \dots, a_{n-1})$

を用いる.

## Operator

-   ```wm.access(int i)```
    -   $a_i$を返す
    -   時間計算量$O(\log \sigma)$
-   ```wm.rank(int r, T x)```
    -   $[0,r)$に含まれる$x$の数を返す.
    -   時間計算量$O(\log \sigma)$
-   ```wm.select(T x, int k)```
    -   整数列$(a_0, a_1, \dots, a_{n-1})$に対して$x$が$k$番目に現れる$index$を返す
    -   時間計算量$O(\log \sigma)$
-   ```wm.quantile(int l, int r, int k)```
    -   $[l,r)$に含まれる要素について$k$番目に小さい値を返す
    -   時間計算量$O(\log \sigma)$