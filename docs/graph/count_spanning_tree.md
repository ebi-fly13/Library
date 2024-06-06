---
title: Count Spanning Tree
documentation_of: //graph/count_spanning_tree.hpp
---

## 説明

与えられたグラフについて、全域木の個数を数える。頂点数を $N$ として、 $O(N^3)$ 。

### count_spanning_tree(std::vector<std::vector<int>> g)

$g[i][j] := (i, j)の辺の本数$ とする。
全域木の個数を返す。

### count_spanning_tree(Graph<T> g)

無向グラフ $g$ の全域木の個数を返す。

### count_directed_spanning_tree(std::vector<std::vector<int>> g, int root, bool in)

$g[i][j] := i から j への辺の本数$ とする。
根を $root$ としたときの有向全域木の個数を返す。 $in$ が `true` のときは、全ての辺が根の方を向いている全域木を考える。 $in$ が `false` のときは、根から全頂点に到達できる全域木を考える。

### count_directed_spanning_tree(Graph<T> g, int root, bool in)

グラフ $g$ について、根を $root$ としたときの有向全域木の個数を返す。