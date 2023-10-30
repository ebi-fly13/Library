---
title: partially persistent unionfind
documentation_of: //data_structure/partially_persistent_unionfind.hpp
---

## 説明

### find(t, v)

時刻 $t$ での $v$ の親を返す。 $O(\log N)$

### merge(a, b)

$a$ と $b$ のグループをマージする。 $O(\log N)$

### same(t, a, b)

時刻 $t$ で $a$ と $b$ が同じグループに属するか判定する。 $O(\log N)$