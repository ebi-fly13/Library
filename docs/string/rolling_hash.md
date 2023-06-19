---
title: Rolling Hash
documentation_of: //string/rolling_hash.hpp
---

## 説明

文字列のハッシュを計算する。`rolling_hash<2>::set_base()`を事前に行い、baseをセットする必要あり。

### prefix_hash(r)

$[0, r)$ のハッシュを計算する。 $O(1)$

### get_hash(int l, int r)

文字列の $[l, r)$ のハッシュを計算する。 $O(1)$

### get_hash(std::string str, int l, int r)

文字列 $str$ の $[l, r)$ のハッシュを計算する。デフォルトでは文字列全体となる。

### size()

文字列のサイズを返す。

### concat(Self lhs, Self rhs)

lhs + rhs の文字列に対してハッシュを計算する。 $O(1)$

### operator+(Self S, Self T)

S + T の文字列に対するローリングハッシュ構造体を計算する。計算量 $O(|T|)$