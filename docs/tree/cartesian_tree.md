---
title: Cartesian Tree
documentation_of: //tree/cartesian_tree.hpp
---

## 説明

数列 $a$ を与え、最も小さい要素が根であるCartesian Treeを構築する。返り値の配列 $p$ について、 $p_i$ には親のインデックスが格納されている。根には $-1$ が入っている。`Compare` に `std::greater` を与えることで最も大きい要素が根であるCartesian Treeを構築できる。 $O(N)$