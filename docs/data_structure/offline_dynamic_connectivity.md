---
title: Offline Dynamic Connectivity
documentation_of: //data_structure/offline_dynamic_connectivity.hpp
---

## 説明

クエリがオフラインで与えられる場合の辺削除可能dsu。

### コンストラクタ

頂点数 $N$ と、辺に関するクエリ $queries$ を与える。

```
offline_dynamic_connectivity uf(n, queries)
```

### set(int t)

$t$ 個のクエリを処理した後のUnionFindの状態にする。 $O(\log N)$

与える $t$ が広義単調増加である場合は、全体で $O(N)$ となる。

### same(int u, int v)

$u$ と $v$ が同じグループにあるかを判定。 $O(\log N)$

### leader(int u)

$u$ のグループの代表を返す。 $O(\log N)$

### size(int u)

$u$ の属するグループのサイズを返す。 $O(\log N)$

### count_group()

グループの数を返す。 $O(N)$