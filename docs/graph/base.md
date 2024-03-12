---
title: Graph (CSR format)
documentation_of: //graph/base.hpp
---

## 説明

CSR形式でグラフを保持する。辺を追加した後、 `build()` を実行する必要がある。

### Graph<T>(int n)

頂点数 $n$ のグラフを作る。

### add_edge(int u, int v, T c)

$u$ $v$ 間に重み $c$ の有向辺を貼る。

### read_tree(int offset, bool is_weighted)

木を標準入力から入力する。

### read_parents(int offset)

木を標準入力から入力する。根を $0$ として親を入力として受け取る。

### read_graph(int e, int offset, bool is_directed, bool is_weighted)

$m$ 辺のグラフを標準入力から入力する。

### build()

グラフを構築する。 $O(N)$

### size()

頂点数を返す。
