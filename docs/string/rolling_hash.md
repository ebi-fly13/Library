---
title: Rolling Hash
documentation_of: //string/rolling_hash.hpp
---

## 説明

文字列のハッシュを計算する。

### get_prefix_hash(r)

$[0, r)$ のハッシュを計算する。 $O(1)$

### get_hash(int l, int r)

文字列の $[l, r)$ のハッシュを計算する。 $O(1)$

### get_hash(int l, int r)

文字列の $[l, r)$ のハッシュを計算する。

### operator+(rolling_hash S, rolling_hash T)

$S$, $T$ の扱っている文字列に対するローリングハッシュ構造体を計算する。計算量は $T$ のサイズを $N$ として $O(N)$