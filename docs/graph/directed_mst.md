---
title: Directed MST
documentation_of: //graph/directed_mst.hpp
---

## 説明

根と有向グラフを与えて、有向最小全域木を構築する。返り値 $(x, p)$ について、 $x$ は木の重みの総和、 $p_{i}$ は頂点 $i$ の親である。 $p_{root} = root$ である。 $O(M\log {N})$