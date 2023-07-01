---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/data_structure/Queue_Operate_All_Composite.cpp
    title: test/data_structure/Queue_Operate_All_Composite.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://scrapbox.io/data-structures/Sliding_Window_Aggregation
  bundledCode: "#line 2 \"data_structure/queue_aggregation.hpp\"\n\r\n/*\r\n    reference:\
    \ https://scrapbox.io/data-structures/Sliding_Window_Aggregation\r\n*/\r\n\r\n\
    #include <cassert>\r\n#include <stack>\r\n\r\nnamespace ebi {\r\n\r\ntemplate\
    \ <class Semigroup, Semigroup (*op)(Semigroup, Semigroup)>\r\nstruct queue_aggregation\
    \ {\r\n  private:\r\n    struct Node {\r\n        Semigroup val;\r\n        Semigroup\
    \ fold;\r\n    };\r\n\r\n    void move() {\r\n        assert(!back.empty());\r\
    \n        Node p = back.top();\r\n        back.pop();\r\n        front.push({p.val,\
    \ p.val});\r\n        while (!back.empty()) {\r\n            Semigroup x = back.top().val;\r\
    \n            back.pop();\r\n            front.push({x, op(x, front.top().fold)});\r\
    \n        }\r\n    }\r\n\r\n  public:\r\n    queue_aggregation() {}\r\n\r\n  \
    \  int size() {\r\n        return front.size() + back.size();\r\n    }\r\n\r\n\
    \    bool empty() {\r\n        return size() == 0;\r\n    }\r\n\r\n    void push(Semigroup\
    \ x) {\r\n        Node node = {x, x};\r\n        if (!back.empty()) {\r\n    \
    \        node.fold = op(back.top().fold, x);\r\n        }\r\n        back.push(node);\r\
    \n    }\r\n\r\n    void pop() {\r\n        assert(!empty());\r\n        if (front.empty())\
    \ {\r\n            move();\r\n        }\r\n        front.pop();\r\n    }\r\n\r\
    \n    Semigroup fold_all() {\r\n        assert(!empty());\r\n        if (front.empty())\
    \ {\r\n            return back.top().fold;\r\n        } else if (back.empty())\
    \ {\r\n            return front.top().fold;\r\n        } else {\r\n          \
    \  return op(front.top().fold, back.top().fold);\r\n        }\r\n    }\r\n\r\n\
    \  private:\r\n    std::stack<Node> front, back;\r\n};\r\n\r\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\r\n\r\n/*\r\n    reference: https://scrapbox.io/data-structures/Sliding_Window_Aggregation\r\
    \n*/\r\n\r\n#include <cassert>\r\n#include <stack>\r\n\r\nnamespace ebi {\r\n\r\
    \ntemplate <class Semigroup, Semigroup (*op)(Semigroup, Semigroup)>\r\nstruct\
    \ queue_aggregation {\r\n  private:\r\n    struct Node {\r\n        Semigroup\
    \ val;\r\n        Semigroup fold;\r\n    };\r\n\r\n    void move() {\r\n     \
    \   assert(!back.empty());\r\n        Node p = back.top();\r\n        back.pop();\r\
    \n        front.push({p.val, p.val});\r\n        while (!back.empty()) {\r\n \
    \           Semigroup x = back.top().val;\r\n            back.pop();\r\n     \
    \       front.push({x, op(x, front.top().fold)});\r\n        }\r\n    }\r\n\r\n\
    \  public:\r\n    queue_aggregation() {}\r\n\r\n    int size() {\r\n        return\
    \ front.size() + back.size();\r\n    }\r\n\r\n    bool empty() {\r\n        return\
    \ size() == 0;\r\n    }\r\n\r\n    void push(Semigroup x) {\r\n        Node node\
    \ = {x, x};\r\n        if (!back.empty()) {\r\n            node.fold = op(back.top().fold,\
    \ x);\r\n        }\r\n        back.push(node);\r\n    }\r\n\r\n    void pop()\
    \ {\r\n        assert(!empty());\r\n        if (front.empty()) {\r\n         \
    \   move();\r\n        }\r\n        front.pop();\r\n    }\r\n\r\n    Semigroup\
    \ fold_all() {\r\n        assert(!empty());\r\n        if (front.empty()) {\r\n\
    \            return back.top().fold;\r\n        } else if (back.empty()) {\r\n\
    \            return front.top().fold;\r\n        } else {\r\n            return\
    \ op(front.top().fold, back.top().fold);\r\n        }\r\n    }\r\n\r\n  private:\r\
    \n    std::stack<Node> front, back;\r\n};\r\n\r\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/queue_aggregation.hpp
  requiredBy:
  - test/data_structure/Queue_Operate_All_Composite.cpp
  timestamp: '2023-07-01 16:57:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/queue_aggregation.hpp
layout: document
title: Sliding Window Aggregation (Queue)
---

## 説明

半群の列$(a_0,a_1, \dots, a_{n-1})$を扱う.
詳しくは https://scrapbox.io/data-structures/Sliding_Window_Aggregation 参照

## コンストラクタ

```cpp
queue_aggregation<Semigroup, op> swag;
```
-   型```Semigroup```
-   二項演算```Semigroup op(Semigroup, Semigroup)```

を定義する必要がある.例としてスライド最小値ならば以下のようになる.

```cpp
int op(int a, int b) {
    return std::min(a,b);
}
queue_aggregation<int, op> swag;
```

## Operations

-   ```fold_all()```
    -   $op(a_0, a_1, \dots, a_{n-1})$ を計算する
    -   時間計算量$O(1)$
-   ```push(Semigroup x)```
    -   $x$ を末尾に追加する
    -   時間計算量 $O(1)$
-   ```pop()```
    -   先頭を削除する
    -   時間計算量 $O(1)$ amortized
-   ```empty()```
    -   空であるとき```true```を返す
    -   時間計算量 $O(1)$
-   ```size()```
    -   要素数を求める
    -   時間計算量 $O(1)$