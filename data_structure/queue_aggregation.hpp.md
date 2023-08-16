---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/data_structure/Queue_Operate_All_Composite.test.cpp
    title: test/data_structure/Queue_Operate_All_Composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://scrapbox.io/data-structures/Sliding_Window_Aggregation
  bundledCode: "#line 2 \"data_structure/queue_aggregation.hpp\"\n\r\n/*\r\n    reference:\
    \ https://scrapbox.io/data-structures/Sliding_Window_Aggregation\r\n*/\r\n\r\n\
    #include <cassert>\r\n#include <stack>\r\n\r\nnamespace ebi {\r\n\r\ntemplate\
    \ <class Semigroup, Semigroup (*op)(Semigroup, Semigroup)>\r\nstruct queue_aggregation\
    \ {\r\n  private:\r\n    struct Node {\r\n        Semigroup val;\r\n        Semigroup\
    \ fold;\r\n    };\r\n\r\n    void move() {\r\n        assert(!_back.empty());\r\
    \n        Node p = _back.top();\r\n        _back.pop();\r\n        _front.push({p.val,\
    \ p.val});\r\n        while (!_back.empty()) {\r\n            Semigroup x = _back.top().val;\r\
    \n            _back.pop();\r\n            _front.push({x, op(x, _front.top().fold)});\r\
    \n        }\r\n    }\r\n\r\n  public:\r\n    queue_aggregation() {}\r\n\r\n  \
    \  int size() {\r\n        return _front.size() + _back.size();\r\n    }\r\n\r\
    \n    bool empty() {\r\n        return size() == 0;\r\n    }\r\n\r\n    void push(Semigroup\
    \ x) {\r\n        Node node = {x, x};\r\n        if (!_back.empty()) {\r\n   \
    \         node.fold = op(_back.top().fold, x);\r\n        }\r\n        _back.push(node);\r\
    \n    }\r\n\r\n    Semigroup front() {\r\n        assert(!empty());\r\n      \
    \  if (_front.empty()) {\r\n            move();\r\n        }\r\n        return\
    \ _front.top().val;\r\n    }\r\n\r\n    void pop() {\r\n        assert(!empty());\r\
    \n        if (_front.empty()) {\r\n            move();\r\n        }\r\n      \
    \  _front.pop();\r\n    }\r\n\r\n    Semigroup fold_all() {\r\n        assert(!empty());\r\
    \n        if (_front.empty()) {\r\n            return _back.top().fold;\r\n  \
    \      } else if (_back.empty()) {\r\n            return _front.top().fold;\r\n\
    \        } else {\r\n            return op(_front.top().fold, _back.top().fold);\r\
    \n        }\r\n    }\r\n\r\n  private:\r\n    std::stack<Node> _front, _back;\r\
    \n};\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n/*\r\n    reference: https://scrapbox.io/data-structures/Sliding_Window_Aggregation\r\
    \n*/\r\n\r\n#include <cassert>\r\n#include <stack>\r\n\r\nnamespace ebi {\r\n\r\
    \ntemplate <class Semigroup, Semigroup (*op)(Semigroup, Semigroup)>\r\nstruct\
    \ queue_aggregation {\r\n  private:\r\n    struct Node {\r\n        Semigroup\
    \ val;\r\n        Semigroup fold;\r\n    };\r\n\r\n    void move() {\r\n     \
    \   assert(!_back.empty());\r\n        Node p = _back.top();\r\n        _back.pop();\r\
    \n        _front.push({p.val, p.val});\r\n        while (!_back.empty()) {\r\n\
    \            Semigroup x = _back.top().val;\r\n            _back.pop();\r\n  \
    \          _front.push({x, op(x, _front.top().fold)});\r\n        }\r\n    }\r\
    \n\r\n  public:\r\n    queue_aggregation() {}\r\n\r\n    int size() {\r\n    \
    \    return _front.size() + _back.size();\r\n    }\r\n\r\n    bool empty() {\r\
    \n        return size() == 0;\r\n    }\r\n\r\n    void push(Semigroup x) {\r\n\
    \        Node node = {x, x};\r\n        if (!_back.empty()) {\r\n            node.fold\
    \ = op(_back.top().fold, x);\r\n        }\r\n        _back.push(node);\r\n   \
    \ }\r\n\r\n    Semigroup front() {\r\n        assert(!empty());\r\n        if\
    \ (_front.empty()) {\r\n            move();\r\n        }\r\n        return _front.top().val;\r\
    \n    }\r\n\r\n    void pop() {\r\n        assert(!empty());\r\n        if (_front.empty())\
    \ {\r\n            move();\r\n        }\r\n        _front.pop();\r\n    }\r\n\r\
    \n    Semigroup fold_all() {\r\n        assert(!empty());\r\n        if (_front.empty())\
    \ {\r\n            return _back.top().fold;\r\n        } else if (_back.empty())\
    \ {\r\n            return _front.top().fold;\r\n        } else {\r\n         \
    \   return op(_front.top().fold, _back.top().fold);\r\n        }\r\n    }\r\n\r\
    \n  private:\r\n    std::stack<Node> _front, _back;\r\n};\r\n\r\n}  // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/queue_aggregation.hpp
  requiredBy: []
  timestamp: '2023-07-27 13:02:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/data_structure/Queue_Operate_All_Composite.test.cpp
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
-   ```front()```
    - 　先頭要素を返す
    -   時間計算量 $O(1)$ amortized
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