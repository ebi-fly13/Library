---
title: rerooting
documentation_of: //tree/rerooting.hpp
---

## 説明

抽象化全方位木DPライブラリ。各頂点を根としたときの木DPを求める。$O(N)$

### コンストラクタ

```
rerooting<V, E, e, merge, put_edge, put_root> dp(int n, std::vector<std::pair<int,int>> edges);
```

- DPの値の型 `V`
- 可換モノイドの型 `E`
- `E` の単位元を返す関数 `E e()`
- `E` の演算子 `E merge(E s, E t)`
- 辺 `i` を根に付与する関数 `E put_edge(int index, V x)`
- 頂点 $v$ を根として追加する関数 `V put_root(int v, E x)`

をテンプレートとして用いている。