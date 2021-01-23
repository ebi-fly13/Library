---
title: fibonacci_heap
documentation_of: //data_structure/fibonacci_heap.hpp
---

## 説明

heapと呼ばれるデータ構造の一つである.
dijkstraの計算量を$O(M + N\log N)$にするなどで活用される.詳しくはreference参照.

## コンストラクタ

```cpp
fibonacci_heap<K, T, op> heap;
```

-   全順序集合```K```
-   値の型```T```
-   比較関数```bool op(K, K)```

最小heapならば以下のようになる.

```cpp
bool op(int a, int b) {
    return a<=b;
}

fibonacci_heap<int, int, op> heap;
```

計算量$O(1)$

## Operator
-   ```heap.push(K k, T val)```
    -   heapに優先度$k$の値$val$をpushしそのポインタを返す.
    -   時間計算量$O(1)$
-   ```heap.pop()```
    -   heapの優先度最小の値をheapから取り除く.
    -   償却計算量$O(\log n)$
-   ```heap.top()```
    -   優先度最小の値を返す.
    -   時間計算量$O(1)$
-   ```prioritize(node_ptr e, K k)```
    -   ```node_ptr = internal::fibheap_node<K, T>*```である.
    -   ポインタ$e$を指す要素の優先度を$k$にする.ただし優先度はもとの優先度より小さくなければならない.
    -   時間計算量$O(1)$
