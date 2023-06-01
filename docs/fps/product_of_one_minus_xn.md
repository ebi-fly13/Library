---
title: $\prod (1 - x^{a_i}) \mod x^d$
documentation_of: //fps/product_of_one_minus_xn.hpp
---

## 説明

$\prod (1 - x^{a_i}) \mod x^d$ を $O(D(\log D + \log \max a))$ で求める。 $D$ は求めたい最大の次数である。中身は、$\log$ を取って $\exp$ している。