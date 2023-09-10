---
title: Complement Graph BFS
documentation_of: //graph/complement_graph_bfs.hpp
---

## 説明

頂点 $s$ から始めて、 $h$ の補グラフをBFSする。頂点数を $N$ 、辺の本数を $M$ 、`func`の計算量を $F$ として計算量は $O(NF + M)$ である。

インターフェースは以下である。ここで、 `func(v, u)` はBFSの際に頂点 $v$ から $u$ に遷移するときに呼ばれる関数である。

```
void complement_graph_bfs(int s, std::vector<std::vector<int>> h, F func)
```
