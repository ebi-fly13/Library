---
title: 便利関数
documentation_of: //graph/base.hpp
---

## 説明

グラフを取り扱う便利関数詰め合わせ。

### remove_isolated_vertex(Graph<T> g)

$g$ から孤立点を取り除いたグラフを返す。

### remove_isolated_vertex(std::vector<std::vector<int>> g)

グラフを隣接行列表現で与え、 $g$ から孤立店を取り除いたグラフを返す。