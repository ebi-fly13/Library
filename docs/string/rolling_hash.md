---
title: Rolling Hash
documentation_of: //string/rolling_hash.hpp
---

## 説明

文字列のハッシュを計算する。

### get_hash(int l, int r)

文字列の $[l, r)$ のハッシュを計算する。 $O(1)$

### get_hash(std::string str, int l, int r)

文字列 $str$ の $[l, r)$ のハッシュを計算する。デフォルトでは文字列全体となる。

### concat(Hash hash1, Hash hash2, int len2)

文字列 s1 のハッシュを hash1、文字列 s2 のハッシュを hash2として s1 + s2 のハッシュを計算する。len2 には s2 の長さを渡す。 $O(\log p)$