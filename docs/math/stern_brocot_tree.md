---
title: Stern-Brocot Tree
documentation_of: //math/stern_brocot_tree.hpp
---

## 説明

Stern-Brocot Treeに対する各種操作を行う。断りがない場合、時間計算量は対数時間である。

ここで、Stern-Brocot Treeの各ノードは有理数 $l, r$ を持つ。任意の正の有理数 $a$ について、Stern-Brocot Treeのノードが一対一対応する。ノードの値を、対応する有理数のこととする。 $l = \frac{p}{q}, r = \frac{r}{s}$ とするとノードの値 $f$ は $f = \frac{p + r}{q + s}$ となる。また、あるノード $f$ を根とする部分木のノードに対応する値は開区間 $(f.l, f.r)$ に含まれる。

`Fraction` は有理数の型であり内部で `using Fraction = std::pair<i64,i64>` されている。

### encode_path(Fraction f)

有理数 $f = \frac{x}{y}$ のStern-Brocot Tree上のパスを返す。パスは `std::vector<i64>` に格納され、右左右左...という順に進む回数が格納されている。

$x, y$ は互いに素な正の整数とする。

### decode_path(std::vector\<i64\> path)

Stern-Brocot Tree上の根からのパスを渡し、パスの先のノードの持つ有理数 $l, r$ を返す。

### decode_path(std::vector<std::pair<char, i64>> path)

Stern-Brocot Treeの根から、右と左どちらに進むかと何回進むかのペアで表現されたパスを渡し、パスの先のノードを返す。

### lca(Fraction f, Fraction g)

有理数 $f, g$ を渡し、Stern-Brocot Tree上のLCAとなるノードの値を返す。

### ancestor(i64 k, Fraction f)

Stern-Brocot Tree の根から有理数 $f$ までのパス上のノードであり、深さ $k$ のノードの値を返す。

### range(Fraction f)

Stern-Brocot Tree の上の有理数 $f$ と対応するノードの持つ有理数 $(l, r)$ を返す。

### binary_search(i64 max_value, F f)

有理数を引数とし true / false を返す単調な関数 $f$ について、 $f(\frac{p}{q}) = true$ かつ $p < max\_value$ かつ $q < max\_value$ を満たす最大の $\frac{p}{q}$ を返す。

### val(std::pair<Fraction, Fraction> f)

ノード $f$ の値を有理数で返す。 $O(1)$

### print_path(std::vector\<i64\> path)

Stern-Brocot Treeの根からのパスを以下のようなフォーマットで出力する。

```
k c_0 n_0 c_1 n_1 ... c_{k-1} n_{k-1}
```

$c_i$ は `L` または `R` であり $n_i$ は $c_i$ が連続して並ぶ回数とする。