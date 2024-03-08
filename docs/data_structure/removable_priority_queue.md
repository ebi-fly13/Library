---
title: Removable Priority Queue
documentation_of: //data_structure/removable_priority_queue.hpp
---

## 説明

### constructor

```
removable_priority_queue() = default // (1)

removable_priority_queue(InputIterator first, InputIterator last) // (2)
```

- (1) デフォルトコンストラクタ
- (2) $[first, last)$ の要素で構築する $O(N)$

### empty()

空であるかを判定する。 $O(1)$

### size()

要素数を所得する。 $O(1)$

### top()

優先度最大の要素を所得。 ならし $O(\log{N})$

### pop()

優先度最大の要素を取り除く。 ならし $O(\log{N})$

### push(T x)

`x` を追加。 $O(\log{N})$

### emplace(Args &&...args)

要素型 `T` のコンストラクタ引数をとり、直接構築で要素を追加する。 $O(\log{N})$

### remove(T x)

`x` を取り除く。 $O(\log {N})$

### emplace_remove(Args &&...args)

要素型 `T` のコンストラクタ引数をとり、直接構築で要素を削除する。 $O(\log{N})$