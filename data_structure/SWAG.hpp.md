---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/SWAG.test.cpp
    title: test/SWAG.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://scrapbox.io/data-structures/Sliding_Window_Aggregation
  bundledCode: "#line 2 \"data_structure/SWAG.hpp\"\n\r\n/*\r\n    reference: https://scrapbox.io/data-structures/Sliding_Window_Aggregation\r\
    \n*/\r\n\r\n#include <cassert>\r\n#include <stack>\r\n\r\nnamespace ebi {\r\n\r\
    \ntemplate <class Semigroup, Semigroup (*op)(Semigroup, Semigroup)> struct SWAG\
    \ {\r\n  private:\r\n    struct Node {\r\n        Semigroup value;\r\n       \
    \ Semigroup fold;\r\n        Node(Semigroup value, Semigroup fold) : value(value),\
    \ fold(fold) {}\r\n    };\r\n\r\n    void move() {\r\n        assert(!back.empty());\r\
    \n        Node p = back.top();\r\n        back.pop();\r\n        front.push(Node(p.value,\
    \ p.value));\r\n        while (!back.empty()) {\r\n            Node p = back.top();\r\
    \n            back.pop();\r\n            p.fold = op(p.value, front.top().fold);\r\
    \n            front.push(p);\r\n        }\r\n    }\r\n\r\n    std::stack<Node>\
    \ front, back;\r\n\r\n  public:\r\n    SWAG() {}\r\n\r\n    int size() {\r\n \
    \       return front.size() + back.size();\r\n    }\r\n\r\n    bool empty() {\r\
    \n        if (size() == 0) return true;\r\n        return false;\r\n    }\r\n\r\
    \n    void push(Semigroup x) {\r\n        Node node(x, x);\r\n        if (back.size()\
    \ != 0) {\r\n            Node p = back.top();\r\n            node.fold = op(p.fold,\
    \ node.fold);\r\n        }\r\n        back.push(node);\r\n    }\r\n\r\n    void\
    \ pop() {\r\n        assert(!empty());\r\n        if (front.empty()) {\r\n   \
    \         move();\r\n        }\r\n        front.pop();\r\n    }\r\n\r\n    Semigroup\
    \ fold_all() {\r\n        assert(!empty());\r\n        if (front.empty()) {\r\n\
    \            return back.top().fold;\r\n        } else if (back.empty()) {\r\n\
    \            return front.top().fold;\r\n        } else {\r\n            return\
    \ op(front.top().fold, back.top().fold);\r\n        }\r\n    }\r\n};\r\n\r\n}\
    \  // namespace ebi\n"
  code: "#pragma once\r\n\r\n/*\r\n    reference: https://scrapbox.io/data-structures/Sliding_Window_Aggregation\r\
    \n*/\r\n\r\n#include <cassert>\r\n#include <stack>\r\n\r\nnamespace ebi {\r\n\r\
    \ntemplate <class Semigroup, Semigroup (*op)(Semigroup, Semigroup)> struct SWAG\
    \ {\r\n  private:\r\n    struct Node {\r\n        Semigroup value;\r\n       \
    \ Semigroup fold;\r\n        Node(Semigroup value, Semigroup fold) : value(value),\
    \ fold(fold) {}\r\n    };\r\n\r\n    void move() {\r\n        assert(!back.empty());\r\
    \n        Node p = back.top();\r\n        back.pop();\r\n        front.push(Node(p.value,\
    \ p.value));\r\n        while (!back.empty()) {\r\n            Node p = back.top();\r\
    \n            back.pop();\r\n            p.fold = op(p.value, front.top().fold);\r\
    \n            front.push(p);\r\n        }\r\n    }\r\n\r\n    std::stack<Node>\
    \ front, back;\r\n\r\n  public:\r\n    SWAG() {}\r\n\r\n    int size() {\r\n \
    \       return front.size() + back.size();\r\n    }\r\n\r\n    bool empty() {\r\
    \n        if (size() == 0) return true;\r\n        return false;\r\n    }\r\n\r\
    \n    void push(Semigroup x) {\r\n        Node node(x, x);\r\n        if (back.size()\
    \ != 0) {\r\n            Node p = back.top();\r\n            node.fold = op(p.fold,\
    \ node.fold);\r\n        }\r\n        back.push(node);\r\n    }\r\n\r\n    void\
    \ pop() {\r\n        assert(!empty());\r\n        if (front.empty()) {\r\n   \
    \         move();\r\n        }\r\n        front.pop();\r\n    }\r\n\r\n    Semigroup\
    \ fold_all() {\r\n        assert(!empty());\r\n        if (front.empty()) {\r\n\
    \            return back.top().fold;\r\n        } else if (back.empty()) {\r\n\
    \            return front.top().fold;\r\n        } else {\r\n            return\
    \ op(front.top().fold, back.top().fold);\r\n        }\r\n    }\r\n};\r\n\r\n}\
    \  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/SWAG.hpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/SWAG.test.cpp
documentation_of: data_structure/SWAG.hpp
layout: document
title: Sliding Window Aggregation
---

## 説明

半群の列$(a_0,a_1, \dots, a_{n-1})$を扱う.
詳しくは https://scrapbox.io/data-structures/Sliding_Window_Aggregation 参照

## コンストラクタ

```cpp
SWAG<Semigroup, op> swag;
```
-   型```Semigroup```
-   二項演算```Semigroup op(Semigroup, Semigroup)```

を定義する必要がある.例としてスライド最小値ならば以下のようになる.

```cpp
int op(int a, int b) {
    return std::min(a,b);
}
SWAG<int, op> swag;
```

## Operations

-   ```swag.fold_all()```
    -   $op(a_0, a_1, \dots, a_{n-1})$を計算する.
    -   時間計算量$O(1)$
-   ```swag.push(Semigroup x)```
    -   $x$を末尾に追加する.
    -   時間計算量$O(1)$
-   ```swag.pop()```
    -   $a_0$を削除する.
    -   時間計算量$O(1)$amortized
-   ```swag.empty()```
    -   空であるとき```true```を返す.
    -   時間計算量$O(1)$
-   ```swag.size()```
    -   要素数を求める.
    -   時間計算量$O(1)$