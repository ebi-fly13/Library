---
title: Convex Hull Trick
documentation_of: //algorithm/convex_hull_trick.hpp
---

## 説明

直線の追加 (傾きの降順で)と $x$ における最小値クエリ ( $x$ は単調増加)を処理する。

### add(a, b)

直線 $y = ax + b$ を追加。傾きが降順で与えられると仮定。

### get(x)

$\min f_i(x)$ を求める。 与えられる $x$ は単調増加であると仮定。