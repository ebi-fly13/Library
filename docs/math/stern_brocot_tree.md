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

有理数を引数とし true / false を返す単調な関数 $f$ について、 $f(\frac{p}{q}) = true$ を満たす最大の $\frac{p}{q}$ を返す。 $max\\_value$ は精度を表し、誤差は $\frac{1}{max\\_value}$ で抑えられる。 $f(0) = false$ の場合は $\frac{0}{1}$ を、 $f(\infty) = true$ の場合は $\frac{1}{0}$ を返す。

### nearest_fraction(i64 max, Fraction f)

有理数 $f$ について $l < f < r$ を満たす最大の有理数 $l$ と最小の有理数 $r$ を返す。

出題例: [ABC333-G](https://atcoder.jp/contests/abc333/tasks/abc333_g)

### [best_rational_within_an_interval](https://en.wikipedia.org/wiki/Continued_fraction#Best_rational_within_an_interval)(Fraction l, Fraction r)

有理数開区間 $(l, r)$ に含まれており、分母が最小であるもののうち分子が最小であるような有理数を返す。

出題例: [GCJ2019 Round 2](https://github.com/google/coding-competitions-archive/blob/main/codejam/2019/round_2/new_elements_part_2/statement.pdf)

### lca_based_an_auxiliary_tree_euler_tour_order(std::vector<Fraction> fs)

有理数を $k$ 個与え、それらに対応するノードとそれらのLCAからなる補助的な木を構築する。返り値として、補助的な木のノードに対応する有理数とその親の組をeuler tour順で返す。根の親は $-1$ としている。

出題例: [ABC273-Ex](https://atcoder.jp/contests/abc273/tasks/abc273_h)

### in_subtree(Fraction f, Fraction g)

有理数 $g$ に対応するノードの部分木に有理数 $f$ が存在するか判定。つまり、 $f \in range(g)$ を判定。

### depth(Fraction f)

有理数 $f$ の根からのパスの長さを返す。

### val(std::pair<Fraction, Fraction> f)

ノード $f$ の値を有理数で返す。 $O(1)$

### print_path(std::vector\<i64\> path)

Stern-Brocot Treeの根からのパスを以下のようなフォーマットで出力する。

```
k c_0 n_0 c_1 n_1 ... c_{k-1} n_{k-1}
```

$c_i$ は `L` または `R` であり $n_i$ は $c_i$ が連続して並ぶ回数とする。
