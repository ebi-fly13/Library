---
title: Convolution 2D
documentation_of: //convolution/convolution_2d.hpp
---

## 説明

二次元配列 $a$ と $b$ について

$c[i][j] = \sum_{i = 0}^{H_1} \sum_{j = 0}^{W_1} \sum_{k = 0}^{H_2} \sum_{l = 0}^{W_2} a[i][j] \times b[k][l]$

### convolution_2d(std::vector<std::vector<mint>> a, std::vector<std::vector<mint>> b)

NTT friendlyな素数における畳み込み。
$O((H_1 + H_2)(W_1 + W_2)\log{(H_1 + H_2)(W_1 + W_2)})$

二次元配列 $a$ と $b$ を畳み込み、その配列を返す。

### convolution_2d_naive(std::vector<std::vector<mint>> a, std::vector<std::vector<mint>> b)

愚直に畳み込む。