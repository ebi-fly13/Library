---
title: Centroid Decomposition
documentation_of: //tree/centroid_decomposition.hpp
---

## 説明

重心分解を行い、重心分解後の各木に対して関数 $f$ を適用する。下記のように使用する。ここで `MODE` の値によって指定した MODE で実行される。

```
centroid_decomposition<MODE>(tree, f)
```

### 共通の仕様

重心分解後の木は $par$ で与えられ、頂点 $v$ の親が $par[v]$ となっている。また、重心分解後の頂点 $v$ の元の木の頂点番号は $vs[v]$ となっている。

### MODE 0

通常の重心分解をする。下記のような関数 $f$ を重心分解後の木について適用する。

```
f(const std::vector<int> &par, const std::vector<int> &vs, const std::vector<int> &index_ptr)
```

重心、重心の部分木をそれぞれ異なる色で塗る。ここで、重心の色は $0$ である。
色 $c$ の頂点数は $(index\\_ptr[c+1] - index\\_ptr[c])$ 個であり、頂点番号は $index\\_ptr[c]$ から $index\\_ptr[c+1]$ となっている。

### MODE 1

$\frac{1}{3}$ 重心分解を行う。下記のような関数 $f$ を重心分解後の木について適用する。パスの長さが $1$ のものについては処理しないため別途処理が必要。

```
f(const std::vector<int> &par, const std::vector<int> &vs, int n0, int n1)
```

重心の部分木を $2$ 色に塗り分ける。ここで、頂点 $0$ が重心、 $[1, 1 + n0)$ が色 $0$ 、 $[1 + n0, 1 + n0 + n2)$ が色 $1$ となっている。

辺の本数がだいたい $\frac{1}{2}$ になるように分割しているため、再帰の深さが $log{N}$ 回程度となる。一方で、各頂点の表れる回数は抑えられていないため注意。（スターグラフなど）

### MODE 2

$\frac{1}{3}$ 重心分解を行う。下記のような関数 $f$ を重心分解後の木について適用する。

```
f(const std::vector<int> &par, const std::vector<int> &vs, const std::vector<int> &color)
```

頂点には $virtual$ 属性と $real$ 属性があり、 $color[v] = -1$ のとき頂点 $v$ は $virtual$ 属性である。頂点は $2$ 色で塗られており、 $color$ に色が格納されている。

各頂点の $real$ 属性で表れる回数が $\log{N}$ 回程度となる。始点を固定した場合のパスの処理などで活用できる。なお、 $virtual$ 属性で表れる回数は抑えられていないため注意。

## reference

- [重心分解・1/3重心分解のお絵描き](https://maspypy.com/%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%83%bb1-3%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%81%ae%e3%81%8a%e7%b5%b5%e6%8f%8f%e3%81%8d)
- [Theoretically Faster HLD and Centroid Decomposition](https://codeforces.com/blog/entry/104997)