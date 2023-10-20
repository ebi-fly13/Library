---
title: Heavy Light Decomposition
documentation_of: //tree/heavy_light_decomposition.hpp
---

## 説明

木をHLDする。パスクエリ、部分木クエリを処理することができる。

### コンストラクタ

`HeavyLightDecomposition(std::vector<std::vector<int>> g, int root = 0)`

木グラフ g と root ノード番号を与えてHLDする。デフォルトで root は頂点 0

### idx(int u)

頂点 $u$ のDFS行きがけ順の番号を返す。このidxの位置にデータ構造のインデックスを対応させればパスクエリや部分木クエリを処理することができる。具体的には使い方を参照。

### la(int v, int k)

頂点 $v$ から $k$ だけ親方向に上った頂点を返す。 $O(\log N)$ 

### lca(int u, int v)

頂点 $u$, $v$ のLCAを返す。 $O(\log N)$

### jump(int s, int t, int k)

頂点 $s$ から $t$ の方向に $k$ だけ移動した頂点を返す。 $O(\log N)$

### path(int s, int t)

頂点 $s$, $t$ の単純パスを返す。

### parent(int u)

頂点 $u$ の親を返す。 $u$ が根である場合は、 $-1$ を返す。

### distance(int u, int v)

頂点 $u$, $v$ の距離を返す。 $O(\log N)$

### at_path(int u, int v, int s)

$u-v$ パスに $s$ が含まれるか判定。 $O(\log N)$

### path_noncommutative_query(int u, int v, bool vertex, const F &f)

パス $u-v$ にクエリ`f`を適用する。非可換。vertexがtrueのとき、頂点に属性がある。vertexがfalseのとき、辺に属性がある。親-子間の辺属性は子のidxに持つ。

### max_path(int u, int v, bool vertex, F binary_search)

パス $u-v$ に含まれる頂点で、 $u-m$ での値が `true` を返す最大のパスとなる $m$ を二分探索で求める。
`binary_search` という関数を引数に渡すが、これは `path_noncommutative_query` で渡す `f` と同じ引数を取り、返り値をデータ構造の二分探索した後の `id` とする。
計算量はデータ構造に対する二分探索の計算量を $O(\log N)$ とすると $O((\log N)^2)$

### subtree_query(int u, bool vertex, const F &f)

頂点 $u$ の部分木にクエリ`f`を適用する。vertexがtrueのとき、根頂点である $u$ にもクエリを適用する。

## 使い方

```
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    rep(i,0,m) {
        int u,v;
        std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    lib::HeavyLightDecomposition hld(g);
    segtree<S, op, e> seg1(n) 
    segtree<S, op_rev, e> seg2(n);
    auto set = [&](int u, S x) {
        int idx = hld.idx(u);
        seg1.set(idx, x);
        seg2.set(idx, x);
    };
    S ans = e();
    auto f = [&](int l, int r) {
        if(l <= r) ans = op(ans, seg1.prod(l, r));
        else ans = op(ans, seg2.prod(r, l)); 
    };
    int u,v;
    std::cin >> u >> v;
    ans = e();
    hld.path_noncommutative_query(u, v, true, f);
    std::cout << ans << '\n';
}
```
