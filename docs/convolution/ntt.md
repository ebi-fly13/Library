---
title: NTT Convolution
documentation_of: //convolution/ntt.hpp
---

## 説明

NTT friendlyな素数における $O(N\log N)$ 時間での畳み込み。

## ntt_info

NTTをするために必要なデータを格納している。

## butterfly(std::vector<mint> &a)

配列 $a$ をNTTする。
$a$ の配列の大きさは $2$ 冪でのみ動作する。

## butterfly_inv(std::vector<mint> &a)

配列 $a$ をinverse NTTする。
$a$ の配列の大きさは $2$ 冪でのみ動作する。
inverse NTT後に割る $N$ を行う。

## convolution(std::vector<mint> a, std::vector<mint> b)

$a$ と $b$ を畳み込み、その配列を返す。 $O(N\log N)$