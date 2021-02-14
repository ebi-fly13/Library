---
title: isp
documentation_of: //geometry/isp.hpp
---

# 説明

点の進行方向を求める関数.

- ```int isp(point a, point b, point c)```
    - 左に曲がる場合:$+1$ 
    - 右に曲がる場合:$-1$
    - c-a-bの順に並ぶ:$-2$
    - a-b-cの順に並ぶ:$+2$
    - a-c-bの順に並ぶ:$0$