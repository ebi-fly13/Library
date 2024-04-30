---
title: Static Top Tree
documentation_of: //tree/static_top_tree.hpp
---

## 説明

Static Top Treeを構成する。 $O(N)$

Static Top Treeの各ノードには次のタイプがある。

- `Vertex`: 頂点属性
- `Compress`: path clusterをマージしている属性
- `Rake`: point clusterをマージしている属性
- `AddEdge`: point clusterを作成している属性
- `AddVertex`: point clusterに頂点を追加してpath clusterにしている属性

### 参考文献

[AtCoder Beginner Contest 351 解説](https://atcoder.jp/contests/abc351/editorial/9868)