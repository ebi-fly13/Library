---
title: Formal Power Series (Sparse)
documentation_of: //fps/fps_sparse.hpp
---

## inv_sparse(std::vector<mint> f, int d)

$f^{-1} \mod x^d$ を求める。$f$ の非ゼロの項を $M$ 個として $O(NM)$

## exp_sparse(std::vector<mint> f, int d)

$\exp(f) \mod x^d$ を求める。$f$ の非ゼロの項を $M$ 個として $O(NM)$

## pow_sparse(std::vector<mint> f, long long k, int d)

$f^k \mod x^d$ を求める。$f$ の非ゼロの項を $M$ 個として $O(NM)$

## pow_sparse_1(std::vector<mint> f, long long k, int d)

$[x^0]f = 1$ であるような $f$ に対して $f^k \mod x^d$ を求める。 $k$ が負でも動作する。 $f$ の非ゼロの項を $M$ 個として $O(NM)$