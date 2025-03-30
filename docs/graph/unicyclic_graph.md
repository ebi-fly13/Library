---
title: Unicyclic Graph
documentation_of: //graph/unicyclic_graph.hpp
---

## 説明

Unicyclic graph（別名: なもりグラフ）を扱う。サイクルの辺を $1$ 辺取り除いて木にして管理する。

### get_tree()

サイクルの辺を $1$ 辺取り除いた木を返す。

### get_cycle()

サイクルの頂点番号の列を返す。取り除いた辺の両端が配列の先頭と末尾になっており、配列内の頂点は取り除いた端点のパスに登場する順序になっている。つまり、サイクルから $1$ 辺取り除いて切り開いた配列である。

### get_root()

取り除いた辺の一方の頂点番号を返す。

### get_remove_edge_id()

元のunicyclic graphにおける削除した辺の番号を返す。

### get_cycle_root(v)

頂点 $v$ に最も近いサイクル内の頂点番号を返す。

### distance(hld, u, v)

頂点 $u$, $v$ 間の距離を返す。HLDはサイクルから $1$ 辺取り除いた木のHLDである。

### is_in_cycle(v)

頂点 $v$ がサイクル内にあるか判定する。