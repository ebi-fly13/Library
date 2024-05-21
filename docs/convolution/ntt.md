---
title: NTT
documentation_of: //convolution/ntt.hpp
---

## 説明

### ntt_info

NTTをするために必要なデータを格納している。

### fft4(std::vector<mint> &a)

配列 $a$ を基数 $4$ のNTTする。
$a$ の配列の大きさは $2$ 冪でのみ動作する。

### ifft4(std::vector<mint> &a)

配列 $a$ を基数 $4$ のinverse NTTする。
$a$ の配列の大きさは $2$ 冪でのみ動作する。