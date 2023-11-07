---
title: Monotone Minima
documentation_of: //algorithm/monotone_minima.hpp
---

## 説明

Monotoneな行列の各行の行最小値を求める。 $O(N + M\log N)$

### monotone_minima(n, m, f, compare)

$n \times m$ の行列に対してmonotone minimaを行う。 $f(i, j)$ は行列の $(i, j)$ 成分を返す。また、`compare`は比較関数を与える。デフォルトはminである。

### slide_monotone_minima(n, m, f, compare)

$n \times m$ の行列に対してmonotone minimaを行う。 $f(i, j, depth)$ は行列の $(i, j)$ 成分を返す。ここで、再帰の深さ毎にカーソルを持つことでスライドでの行列成分のアクセスを可能にする。また、`compare`は比較関数を与える。デフォルトはminである。