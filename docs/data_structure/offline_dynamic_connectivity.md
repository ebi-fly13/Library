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

### execute(f)

`f(int i)` が $i$ 番目 (1-indexed)のクエリを処理した後の uf をoffline_dynamic_connectivityが持った状態で関数が呼び出される。ここで $i$ 番目のクエリを処理し終わった状態での各種操作をすればよい。