---
title: Multipoint Evaluation
documentation_of: //fps/multipoint_evaluation.hpp
---

## 説明

多項式 $f(x)$ と整数列 $p_0, p_1, \dots, p_{M-1}$ を与えて、 $f(p_i) \mod 998244353$ を全ての $p_i$ について求める。 $O(M (\log{M})^2 + N\log{N})$

$f(p_i) = f(x) \pmod{(x - p_i)}$ が成り立つことを用いて分割統治をしている。