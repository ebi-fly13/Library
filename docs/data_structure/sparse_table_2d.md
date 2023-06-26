---
title: 2D sparse table
documentation_of: //data_structure/sparse_table_2d.hpp
---

## 説明

長方形領域のmax, minなどが行えるデータ構造。スパーステーブルに乗る構造なら乗る。
構築 $O(HW\log H \log W)$ / クエリ $O(1)$

### prod(l, d, r, u)

$[l, r) \times [d, u)$ の長方形に対してクエリを答える。 $O(1)$