---
title: Enumerate Monge d-edge shortest path
documentation_of: //algorithm/enumerate_monge_d_edge_shortest_path.hpp
---

## 説明

辺の重みがMongeであるようなグラフに対して $0$ からスタートして、 $N-1$ へちょうど $d$ 辺使った場合の最短路の値を $d = 1, 2, \dots, N-1$ について求める。 $O(N^2 \log N)$