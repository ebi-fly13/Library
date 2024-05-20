---
title: NTT
documentation_of: //convolution/ntt.hpp
---

## 説明

### ntt_info

NTTをするために必要なデータを格納している。

### butterfly(std::vector<mint> &a)

配列 $a$ をNTTする。
$a$ の配列の大きさは $2$ 冪でのみ動作する。

### butterfly_inv(std::vector<mint> &a)

配列 $a$ をinverse NTTする。
$a$ の配列の大きさは $2$ 冪でのみ動作する。
inverse NTT後に割る $N$ を行う。