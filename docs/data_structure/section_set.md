---
title: section set
documentation_of: //data_structure/section_set.hpp
---

## 説明

区間を管理するセットである。

### insert(l, r)

$[l, r)$ を追加

### erase(l, r)

$[l, r)$ を削除

### find(x)

$x$ が含まれるか判定

### find(l, r)

$[l, r)$ が含まれるか判定

### belong(x)

$x$ の含まれる区間 $[l, r)$ を返す。 $x$ を含む区間がないならば $[0, 0)$ を返す。

### lower_bound(l)

左端が $l$ 以上の区間を返す。