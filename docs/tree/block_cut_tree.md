---
title: Block Cut Tree
documentation_of: //tree/block_cut_tree.hpp
---

## 説明

二重連結成分分解をし、二重連結成分と関節点を結ぶ木（非連結グラフなら森）を作る。 $O(N + M)$
頂点番号の割り当ては、関節点は何個目の関節点か、二重連結成分は関節点の個数 + 何個目の二重連結成分かになっている。