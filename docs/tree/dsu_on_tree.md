---
title: Dsu on Tree
documentation_of: //tree/dsu_on_tree.hpp
---

## 説明

全ての部分木に対してクエリを処理するアルゴリズムである。
必要な関数は以下である。

- `add(v)`
  - 頂点 $v$ を追加する。この関数は各頂点に対して $O(\log{N})$ 回実行される。
- `query(v)`
  - 頂点 $v$ の部分木のクエリを処理する。この関数は各頂点に対して $1$ 度だけ実行される。
- `clear(v)`
  - 頂点 $v$ を取り除く。この関数は各頂点に対して $O(\log{N})$ 回実行される。
- `reset()`
  - 初期状態（頂点が何も追加されていない状態）にする関数。この関数は $O(N)$ 回実行される。

`add(v)` と `reset(v)` の計算量を $O(1)$ とすると、 $O(N\log{N})$ となる。

### 参考文献

[ツリー上のマージテク亜種の話 camypaper](https://speakerdeck.com/camypaper/dsu-on-tree)