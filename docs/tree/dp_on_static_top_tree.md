---
title: DP on Static Top Tree
documentation_of: //tree/dp_on_static_top_tree.hpp
---

## 説明

$1$ 点更新・木DP計算が可能なデータ構造である。

必要な関数は以下である。

- `compress(Path p, Path c) -> Path`: path clusterをマージしてpath clusterを返す関数
- `rake(Point a, Point b) -> Point`: point clusterをマージしてpoint clusterを返す関数
- `add_edge(Path a) -> Point`: path clusterに仮想的な頂点を追加してpoint clusterを返す関数
- `add_vertex(Point a, Path v) -> Path`: point clusterに頂点 $v$ を追加してpath clusterを返す関数

### 参考文献

[AtCoder Beginner Contest 351 解説](https://atcoder.jp/contests/abc351/editorial/9868)