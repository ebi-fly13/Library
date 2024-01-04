---
title: Contour Query on Tree
documentation_of: //tree/contour_query_on_tree.hpp
---

## 説明

頂点 $v$ と距離が $[l, r)$ である頂点に対するクエリを処理するための構造体。構築 $O(N\log{N})$

### できること

- [1点更新区間取得](https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree)
- [1点取得区間更新](https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree)

### できないこと

- 区間更新区間所得

頂点 $v$ への作用が頂点 $v$ に関わるインデックスすべてに対して行わないといけないため。 $1$ 点更新ならば、更新すべきノードが $O(\log{N})$ であるため可能。 $1$ 点取得ならば、所得の際に頂点 $v$ に関わるインデックスをなめることで可能。

### get_contour_from_vertex(int v, int l, int r)

頂点 $v$ と距離が $[l, r)$ であるような頂点の属する区間を返す。 $O(\log{N})$

距離が $0$ であるよう場合は含まれないので別途処理が必要。

### get_vertex(int v)

頂点 $v$ に関わるインデックスを返す。 $O(\log{N})$