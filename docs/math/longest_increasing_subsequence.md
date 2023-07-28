---
title: LIS
documentation_of: //math/longest_increasing_subsequence.hpp
---

## 説明

与えられた数列に対して、最長増加部分列となる添え字の列構築する。`narrowly` が `true` のとき狭義単調増加、 `false` のとき広義単調増加の場合に対して構築する。$O(N\log N)$