---
title: Area of Union of Rectangles
documentation_of: //data_structure/area_of_union_of_rectangles.hpp
---

## 説明

複数の長方形の和集合の面積を求める。長方形の個数を $N$ として $O(N\log{N})$

### add_rectangle(l, d, r, u)

長方形 $\{(x, y): l \leq x \leq r, d \leq y \leq u\}$ を追加する。

### run()

長方形の和集合の面積を求める。