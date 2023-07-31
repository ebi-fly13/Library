---
title: $f(x)$ の逆関数
documentation_of: //fps/compositional_inverse_of_fps.hpp
---

## 説明

形式的べき級数 $f$ について、その逆関数を求める。ニュートン法を用いると、形式的べき級数の合成がボトルネックとなり $O(N^2)$ となる。

$$
g_{2n} = g_{n} - \frac{f(g_{n}) - x}{f^{\prime}(g_{n})} \mod x^{2n}
$$