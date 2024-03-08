---
title: Double-Ended Priority Queue
documentation_of: //data_structure/double_ended_priority_queue.hpp
---

## 説明

### constructor

```
double_ended_priority_queue() = default // (1)

double_ended_priority_queue(InputIterator first, InputIterator last) // (2)
```

- (1) デフォルトコンストラクタ
- (2) $[first, last)$ の要素で構築する $O(N)$

### empty()

空であるかを判定する。 $O(1)$

### size()

要素数を所得する。 $O(1)$

### push(T x)

`x` を追加。 $O(\log{N})$

### emplace(Args &&...args)

要素型 `T` のコンストラクタ引数をとり、直接構築で要素を追加する。 $O(\log{N})$

### pop_min()

最小値を取り除く。 $O(\log{N})$

### pop_max()

最大値を取り除く。 $O(\log{N})$

### get_min()

最小値を所得する。 $O(1)$

### get_max()

最大値を所得する。 $O(1)$