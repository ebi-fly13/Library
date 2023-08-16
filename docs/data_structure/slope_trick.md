---
title: Slope Trick
documentation_of: //data_structure/slope_trick.hpp
---

## 説明

区分線形凸関数 $f$ を管理するデータ構造。

### min()

最小値を返す。 $O(1)$

### argmin()

最小値となる $x$ 座標の範囲 $[l, r]$ を返す。 $O(1)$

### add_all(T a)

全ての $x$ に対して $a$ を加算する。 $O(1)$

### add_x_minus_a(T a)

$(x-a)_+ = \max(0, x - a)$ を加算する。 $O(\log N)$

### add_a_minus_x(T a)

$(a-x)_+ = \max(0, a-x)$ を加算する。 $O(\log N)$

### add_abs(T a)

$|x - a|$ を加算する。 $O(\log N)$

### sliding_window_minimum(T a, T b)

$a \leq b$ として、

$$
g(x) = \min_{y \in [x-b, x-a]} f(y)
$$

で定まる $g$ を計算し $f$ とする。 $O(1)$

### shift(T a)

$g = f(x-a)$ となる $g$ を計算し $f$ とする。 $O(1)$

### merge(Self st)

Slope Trickをマージする。Weighted union ruleで、サイズの大きいほうにマージする。

### right_cumulative_min()

右側累積和を取る。つまり、

$$g(x) = \min_{y \geq x} f(y)$$

となる $g$ を計算し、 $f = g$ とする。 $O(1)$

### left_cumulative_min()

累積和を取る。つまり、

$$g(x) = \min_{y \leq x} f(y)$$ 

となる $g$ を計算し、 $f = g$ とする。 $O(1)$