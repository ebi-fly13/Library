---
title: Dice
documentation_of: //Dice/Dice.hpp
---

## 説明

サイコロを転がします。ころころ

### roll(c)

`c` の方向に回転する。`rollc()`と同じ動作 (`c`には`NSFWRL`のいずれかが入る)

### get_index(x)

$x$ と同じ値が書いてある面のインデックスを返す。

### set(int u, int f)

上の面を $u$ 、 正面を $f$ にする。

### makeDice()

サイコロを全通り (24通り)列挙する。

### ~_val()

`~`のvalを返す。`~`にはtop, right, left, front, back, downが入る。