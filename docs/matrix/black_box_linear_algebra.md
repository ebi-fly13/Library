---
title: Black Box Linear Algebra
documentation_of: //matrix/black_box_linear_algebra.hpp
---

## 説明

Black Box Linear Algebraは、行列を陽に与えずに、行列 $A$ とベクトル $v$ の積の演算を行う関数（black box） $Ax$ を与えることで各種の計算を行うものである。以下、 $A$ と ベクトル $v$ の積の計算量を $T(N)$ とする。

### matrix_minimum_poly(int n, F Ax)

$N$ 次正方行列 $A$ の最小多項式を求める。 $O(N^2)$

### pow(int n, F Ax, std::vector<mint> b, long long k)

$A^k b$ を求める。多項式乗算の計算量を $M(N)$ とすると、 $O(N^2 + M(N)\log{k} + N T(N))$

### det(int n, F Ax)

$N$ 次正方行列 $A$ の行列式を求める。 $O(N^2 + N T(N))$ 