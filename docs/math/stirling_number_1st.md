---
title: Stirling Numbers of the First Kind
documentation_of: //math/stirling_number_1st.hpp
---

## 説明

第 $1$ 種スターリング数 $S(N, K)$ を $k = 0, \dots, N$ に対して求める。分割統治とTaylor Shiftを用いて $O(N\log N)$ で求める。

$S(N, K)$ は、 $N$ 個の区別できる要素を $K$ 個のサイクルに並べる場合の数である。