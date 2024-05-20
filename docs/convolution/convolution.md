---
title: Convolution
documentation_of: //convolution/convolution.hpp
---

## 説明

$a$ と $b$ を畳み込み、その配列を返す。

### convolution_naive(std::vector<mint> a, std::vector<mint> b)

愚直に畳み込む。
$O(N^2)$

### convolution(std::vector<mint> a, std::vector<mint> b)

NTT friendlyな素数における $O(N\log N)$ 時間での畳み込み。
$O(N\log N)$