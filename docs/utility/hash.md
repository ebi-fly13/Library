---
title: Hash structure
documentation_of: //utility/hash.hpp
---

## 説明

ハッシュを簡単に計算するための構造体。内部では $\mod 2^{61} - 1$ で計算している。

## pow(long long n)

ハッシュを $n$ 乗する

## get_basis

ランダムなハッシュを生成。

## get_basis_primitive

ランダムなハッシュを生成。各要素は $\mod 2^{61} - 1$ で原始根となる。