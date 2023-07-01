---
title: Sliding Window Aggregation (Deque)
documentation_of: //data_structure/deque_aggregation.hpp
---

## 説明

半群の列$(a_0,a_1, \dots, a_{n-1})$を扱う.
詳しくは https://scrapbox.io/data-structures/Sliding_Window_Aggregation 参照

## コンストラクタ

```cpp
deque_aggregation<Semigroup, op> swag;
```
-   型```Semigroup```
-   二項演算```Semigroup op(Semigroup, Semigroup)```

を定義する必要がある.例としてスライド最小値ならば以下のようになる.

```cpp
int op(int a, int b) {
    return std::min(a,b);
}
deque_aggregation<int, op> swag;
```

## Operations

-   ```fold_all()```
    -   $op(a_0, a_1, \dots, a_{n-1})$ を計算する
    -   時間計算量 $O(1)$
-   ```push_front(Semigroup)```
    -   $x$ を先頭に追加する
    -   時間計算量 $O(1)$
-   ```push_back(Semigroup x)```
    -   $x$ を末尾に追加する
    -   時間計算量 $O(1)$
-   ```pop_front()```
    -   先頭を削除する
    -   時間計算 $O(1)$ amortized
-   ```pop_back()```
    -   末尾を削除する
    -   時間計算量 $O(1)$ amortized
-   ```empty()```
    -   空であるとき```true```を返す
    -   時間計算量 $O(1)$
-   ```size()```
    -   要素数を求める
    -   時間計算量 $O(1)$