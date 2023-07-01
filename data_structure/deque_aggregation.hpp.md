---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Deque_Operate_All_Composite.test.cpp
    title: test/data_structure/Deque_Operate_All_Composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/deque_aggregation.hpp\"\n\n#include <cassert>\n\
    #include <stack>\n\nnamespace ebi {\n\ntemplate <class Semigroup, Semigroup (*op)(Semigroup,\
    \ Semigroup)>\nstruct deque_aggregation {\n  private:\n    struct Node {\n   \
    \     Semigroup val;\n        Semigroup fold;\n    };\n\n    void move_front()\
    \ {\n        assert(front.empty());\n        int sz = back.size();\n        std::stack<Semigroup>\
    \ buff;\n        for (int i = 0; i < sz / 2; i++) {\n            buff.push(back.top().val);\n\
    \            back.pop();\n        }\n        while (!back.empty()) {\n       \
    \     Semigroup x = back.top().val;\n            back.pop();\n            push_front(x);\n\
    \        }\n        while (!buff.empty()) {\n            Semigroup x = buff.top();\n\
    \            buff.pop();\n            push_back(x);\n        }\n    }\n\n    void\
    \ move_back() {\n        assert(back.empty());\n        int sz = front.size();\n\
    \        std::stack<Semigroup> buff;\n        for (int i = 0; i < sz / 2; i++)\
    \ {\n            buff.push(front.top().val);\n            front.pop();\n     \
    \   }\n        while (!front.empty()) {\n            Semigroup x = front.top().val;\n\
    \            front.pop();\n            push_back(x);\n        }\n        while\
    \ (!buff.empty()) {\n            Semigroup x = buff.top();\n            buff.pop();\n\
    \            push_front(x);\n        }\n    }\n\n  public:\n    deque_aggregation()\
    \ = default;\n\n    int size() const {\n        return front.size() + back.size();\n\
    \    }\n\n    bool empty() const {\n        return size() == 0;\n    }\n\n   \
    \ void push_front(Semigroup x) {\n        Node node = {x, x};\n        if (!front.empty())\
    \ {\n            node.fold = op(x, front.top().fold);\n        }\n        front.push(node);\n\
    \    }\n\n    void push_back(Semigroup x) {\n        Node node = {x, x};\n   \
    \     if (!back.empty()) {\n            node.fold = op(back.top().fold, x);\n\
    \        }\n        back.push(node);\n    }\n\n    void pop_back() {\n       \
    \ assert(!empty());\n        if (back.empty()) move_back();\n        back.pop();\n\
    \    }\n\n    void pop_front() {\n        assert(!empty());\n        if (front.empty())\
    \ move_front();\n        front.pop();\n    }\n\n    Semigroup fold_all() {\n \
    \       assert(!empty());\n        if (front.empty()) {\n            return back.top().fold;\n\
    \        } else if (back.empty()) {\n            return front.top().fold;\n  \
    \      } else {\n            return op(front.top().fold, back.top().fold);\n \
    \       }\n    }\n\n  private:\n    std::stack<Node> front, back;\n};\n\n}  //\
    \ namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <stack>\n\nnamespace ebi {\n\
    \ntemplate <class Semigroup, Semigroup (*op)(Semigroup, Semigroup)>\nstruct deque_aggregation\
    \ {\n  private:\n    struct Node {\n        Semigroup val;\n        Semigroup\
    \ fold;\n    };\n\n    void move_front() {\n        assert(front.empty());\n \
    \       int sz = back.size();\n        std::stack<Semigroup> buff;\n        for\
    \ (int i = 0; i < sz / 2; i++) {\n            buff.push(back.top().val);\n   \
    \         back.pop();\n        }\n        while (!back.empty()) {\n          \
    \  Semigroup x = back.top().val;\n            back.pop();\n            push_front(x);\n\
    \        }\n        while (!buff.empty()) {\n            Semigroup x = buff.top();\n\
    \            buff.pop();\n            push_back(x);\n        }\n    }\n\n    void\
    \ move_back() {\n        assert(back.empty());\n        int sz = front.size();\n\
    \        std::stack<Semigroup> buff;\n        for (int i = 0; i < sz / 2; i++)\
    \ {\n            buff.push(front.top().val);\n            front.pop();\n     \
    \   }\n        while (!front.empty()) {\n            Semigroup x = front.top().val;\n\
    \            front.pop();\n            push_back(x);\n        }\n        while\
    \ (!buff.empty()) {\n            Semigroup x = buff.top();\n            buff.pop();\n\
    \            push_front(x);\n        }\n    }\n\n  public:\n    deque_aggregation()\
    \ = default;\n\n    int size() const {\n        return front.size() + back.size();\n\
    \    }\n\n    bool empty() const {\n        return size() == 0;\n    }\n\n   \
    \ void push_front(Semigroup x) {\n        Node node = {x, x};\n        if (!front.empty())\
    \ {\n            node.fold = op(x, front.top().fold);\n        }\n        front.push(node);\n\
    \    }\n\n    void push_back(Semigroup x) {\n        Node node = {x, x};\n   \
    \     if (!back.empty()) {\n            node.fold = op(back.top().fold, x);\n\
    \        }\n        back.push(node);\n    }\n\n    void pop_back() {\n       \
    \ assert(!empty());\n        if (back.empty()) move_back();\n        back.pop();\n\
    \    }\n\n    void pop_front() {\n        assert(!empty());\n        if (front.empty())\
    \ move_front();\n        front.pop();\n    }\n\n    Semigroup fold_all() {\n \
    \       assert(!empty());\n        if (front.empty()) {\n            return back.top().fold;\n\
    \        } else if (back.empty()) {\n            return front.top().fold;\n  \
    \      } else {\n            return op(front.top().fold, back.top().fold);\n \
    \       }\n    }\n\n  private:\n    std::stack<Node> front, back;\n};\n\n}  //\
    \ namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/deque_aggregation.hpp
  requiredBy: []
  timestamp: '2023-07-01 16:57:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Deque_Operate_All_Composite.test.cpp
documentation_of: data_structure/deque_aggregation.hpp
layout: document
title: Sliding Window Aggregation (Deque)
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