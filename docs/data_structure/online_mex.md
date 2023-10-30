---
title: online mex
documentation_of: //data_structure/online_mex.hpp
---

## 説明

onlineで追加された値の集合のmexを計算する。

### add(x)

非負整数 $x$ を集合に追加する。 amortized $O(1)$

### mex()

集合のmexを返す。 amortized $O(1)$

### size()

追加した値の個数を返す。 $O(1)$