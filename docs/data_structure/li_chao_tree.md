---
title: Li Chao Tree
documentation_of: //data_structure/li_chao_tree.hpp
---

## 説明

直線追加、線分追加、 $x$ における最小値を処理するデータ構造。 以下、 $N$ は処理する $x$ 座標の個数。

### add(a, b)

直線 $y = ax + b$ を追加。 $O(\log N)$

### add_segment(a, b, l, r)

$x$ 座標の区間 $[l, r)$ に、線分 $y = ax + b$ を追加する。 $O((\log N)^2)$

### min(x)

$x$ における最小値を返す。 $O(\log N)$