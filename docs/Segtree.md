---
title: Segtree
documentation_of: //data_structure/Segtree.hpp
---

## 説明

モノイドの列$(a_0,a_1,\dots,a_{n-1})$に対して各種操作ができるデータ構造である.

-   $\mathtt{set}(p, x)$
    -   $a_p$に$x$を代入する.
    -   時間計算量$O(\log n)$
-   $\mathtt{prod}(l, r)$
    -   ```op(a[l], ..., a[r-1])```を計算する.
    -   時間計算量$O(\log n)$
-   $\mathtt{all\_ prod}()$
    -   ```op(a[0], ..., a[n-1])```を計算する.
    -   時間計算量$O(1)$
-   operator [ ] $(p)$
    -   ```a[p]```を返す.
    -   時間計算量$O(1)$