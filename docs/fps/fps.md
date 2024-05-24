---
title: Formal Power Series
documentation_of: //fps/fps.hpp
---

## 説明

形式的べき級数 $f$ を管理し、各種操作を行う構造体。`std::vector`を継承している。

### テンプレート引数

- `mint`
形式的べき級数の係数の型。modintを想定している。

- `std::vector<mint> convolution(const std::vector<mint> &, const std::vector<mint> &)`
配列`std::vector<mint>`の畳み込み`covolution`。
愚直 $O(N^2)$ 、NTTを用いると $O(N\log N)$ となる。
以下畳み込みの計算量を $O(N\log N)$ として計算量を記述する。

### コンストラクタ

`std::vector` と同一。

### 和・差

$O(N)$

### 積

NTTを用いると $O(N\log N)$

### 割り算・余り

$f, g$ を多項式として、 $f = q * g + r$ となる多項式 $q$ を商、 $r$ を余りとする。
$O(N\log N)$

### deg()

$f$ の最大次数 $+1$ を返す。

### pre(int sz)

多項式の前 $sz$ 項を所得する。

### rev()

多項式を反転させる。つまり $n = deg()$ として $f(x^{-1}) * x^{n-1}$ を計算する。
$O(N)$

### differantial()

形式的べき級数 $f$ を微分したものを返す。
$O(N)$

### integral()

形式的べき級数 $f$ を積分したものを返す。
$O(N)$

### inv(int d)

形式的べき級数 $f$ の逆元を $\mod x^d$ で求める。
$O(N \log N)$

### log(int d)

形式的べき級数 $f$ の $\log$ を $\mod x^d$ で求める。
$O(N\log N)$

### exp(int d)

形式的べき級数 $f$ の $\exp$ を $\mod x^d$ で求める。
$O(N\log N)$

### pow(long long k, int d)

非負整数 $k$ について、形式的べき級数 $f$ について $f^k \pmod{x^d}$ を求める。愚直だと $O(N\log N \log K)$ だが、$\log$ を取って $k$ を掛けて $\exp$ を取ることで求める。
$O(N\log N)$

### pow_1(mint k, int d)

非零の有理数 $k$ 、 $[x^0] f = 1$ であるFPSについて、 $f^k \pmod{x^d}$ を求める。

### sqrt(int d)

形式的べき級数 $f$ について $\sqrt{f}$ が存在するなら求める。存在しない場合は `std::nullopt`を返す。
$O(N\log N)$

### shrink()

末尾の不要なゼロを削除する。

### exp_x(int n)

$\exp{x} \mod x^n$ を返す。 $O(N)$