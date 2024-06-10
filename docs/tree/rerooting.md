---
title: Rerooting DP
documentation_of: //tree/rerooting.hpp
---

## 説明

抽象化全方位木DPライブラリ。各頂点を根としたときの木DPを求める。$O(N)$

### 使用方法

```
auto dp = rerooting<V, E>(g, e, merge, put_edge, put_root);
```

- DPの値の型 `V`
- 可換モノイドの型 `E`
- `E` の単位元を返す関数 `E e()`
- `E` の演算子 `E merge(E s, E t)`
- 辺 `i` を根に付与する関数 `E put_edge(T edge, V x)`
- 頂点 $v$ を根として追加する関数 `V put_root(int v, E x)`

を渡して使用する。