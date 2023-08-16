---
title: Compress
documentation_of: //data_structure/compress.hpp
---

## 説明

### build()

座圧を実行する。 $O(N\log N)$

### add(T val)

valを座圧の対象にする。 $O(1)$

### get(T val)

valを座圧した後の値を返す。 $O(\log N)$

### size()

座圧後の要素数を返す。 $O(1)$

### find(T val)

valが座圧対象であるか判定。 $O(\log N)$

### val(int idx)

座圧後の値がidxのものの座圧前の値を返す。 $O(1)$