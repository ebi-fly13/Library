---
title: Online Convolution
documentation_of: //convolution/online_convolution.hpp
---

## 説明

$c = a \times b$ とする。 $a_i, b_i$ を与えて、 $c_i$ を返すという操作を $i = 0$ からオンラインで処理する。最終的な $c$ の長さを $N$ とすると、計算量は $O(N(\log N)^2)$ となる。

ACLに依存しているため使用するときは注意。
