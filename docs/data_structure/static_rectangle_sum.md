---
title: Static Rectangle Sum
documentation_of: //data_structure/static_rectangle_sum.hpp
---

## 説明

2次元平面に値があり、長方形内に含まれる値の和を求めるクエリを静的に処理する。点の個数を $N$ 、クエリの個数を $Q$ としたとき、計算量は $O((N + Q)\log{N})$

### add_point(x, y, val)

$(x, y)$ に値 $val$ を加える。

### add_query(l, d, r, u)

$[l, r) \times [d, u)$ の長方形内に含まれる値の和を求めるクエリを追加する。

### run()

クエリを処理して、クエリを追加した順で処理結果を返す。
