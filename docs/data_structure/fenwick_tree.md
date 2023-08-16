---
title: fenwick tree
documentation_of: //data_structure/fenwick_tree.hpp
---

## 説明

配列 $a$ に対して、$1$ 点加算、区間和が $O(\log N)$ でできるデータ構造。

### add(int p, T x)

a[p] に $x$ を加算

### prefix_sum(int p)

sum(a[0], ..., a[p-1]) を返す。

### sum(int l, int r)

sum(a[l], ..., a[r-1]) を返す。

### lower_bound(T key)

$prefix\_sum(x) \geq key$ となる最小のxを返す関数 O(log N)