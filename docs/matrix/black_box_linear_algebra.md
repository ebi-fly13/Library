---
title: Black Box Linear Algebra
documentation_of: //matrix/black_box_linear_algebra.hpp
---

## 説明

Black Box Linear Algebraは、行列を陽に与えずに、行列 $A$ とベクトル $v$ の積の演算を行う関数（black box） $Ax$ を与えることで各種の計算を行うものである。

### matrix_minimum_poly(int n, F Ax)

$N$ 次正方行列 $A$ の最小多項式を求める。 $O(N^2)$

### det(int n, F Ax)

$N$ 次正方行列 $A$ の行列式を求める。 $A$ と ベクトル $v$ の積の計算量を $T(N)$ とすると $O(N^2 + N T(N))$ となる。