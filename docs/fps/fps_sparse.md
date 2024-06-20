---
title: Formal Power Series (Sparse)
documentation_of: //fps/fps_sparse.hpp
---

## 説明

疎な形式的べき級数に対する処理を集めたもの。

### mul_sparse(std::vector<mint> f, std::vector<mint> g)

ナイーブな多項式積。$f$ の非ゼロの項を $N$ 個、$g$ の非ゼロの項を $M$ 個として $O(NM)$。

### inv_sparse(std::vector<mint> f, int d)

$f^{-1} \mod x^d$ を求める。$f$ の非ゼロの項を $N$ 個として $O(ND)$

### exp_sparse(std::vector<mint> f, int d)

$\exp(f) \mod x^d$ を求める。$f$ の非ゼロの項を $N$ 個として $O(ND)$

### log_sparse(std::vector<mint> f, int d)

$\log{f} \mod x^d$ を求める。$f$ の非ゼロの項を $N$ 個として $O(ND)$

### pow_sparse(std::vector<mint> f, long long k, int d)

$f^k \mod x^d$ を求める。$k$ は非負整数のみ正常に動作する。$f$ の非ゼロの項を $N$ 個として $O(ND)$

### pow_sparse_1(std::vector<mint> f, long long k, int d)

$[x^0]f = 1$ であるような $f$ に対して $f^k \mod x^d$ を求める。 $k$ が負でも有理数でも動作する。 $f$ の非ゼロの項を $M$ 個として $O(ND)$