---
title: Rerooting DP
documentation_of: //tree/rerooting.hpp
---

## 説明

抽象化全方位木DPライブラリ。各頂点を根としたときの木DPを求める。$O(N)$

### 使用方法

```
rerooting_dp dp(tree, e, merge, put_edge, put_root)
```

- DPの値の型 `V`
- DPの単位元 `e`
- 辺を追加したDP同士をマージする関数 `V merge(V a, V b)`
- 辺 `i` を根に付与する関数 `V put_edge(Edge edge, V x)`
- 頂点 $v$ を根として追加する関数 `V put_root(int v, V x)`

を渡して使用する。

### get(int v)

頂点 $v$ を根としたDPの値を返す。

### get(int v, int root)

頂点 $root$ を根としたときの頂点 $v$ の部分木のDPの値を返す。

### get_full_dp()

各頂点を根としたときのDPの配列を返す。