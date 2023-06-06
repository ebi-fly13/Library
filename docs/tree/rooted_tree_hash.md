---
title: Rooted Tree Hash
documentation_of: //tree/rooted_tree_hash.hpp
---

## 説明

根付き木のハッシュを計算する。木の同型判定に活用できる。

## subtree_hash(graph g, int root)

根を root として各部分木のハッシュを計算する。 $O(N)$

## basis()

各深さに割り当てられたランダムな値を返す。