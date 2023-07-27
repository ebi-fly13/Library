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
    \ {\n        assert(_front.empty());\n        int sz = _back.size();\n       \
    \ std::stack<Semigroup> buff;\n        for (int i = 0; i < sz / 2; i++) {\n  \
    \          buff.push(_back.top().val);\n            _back.pop();\n        }\n\
    \        while (!_back.empty()) {\n            Semigroup x = _back.top().val;\n\
    \            _back.pop();\n            push_front(x);\n        }\n        while\
    \ (!buff.empty()) {\n            Semigroup x = buff.top();\n            buff.pop();\n\
    \            push_back(x);\n        }\n    }\n\n    void move_back() {\n     \
    \   assert(_back.empty());\n        int sz = _front.size();\n        std::stack<Semigroup>\
    \ buff;\n        for (int i = 0; i < sz / 2; i++) {\n            buff.push(_front.top().val);\n\
    \            _front.pop();\n        }\n        while (!_front.empty()) {\n   \
    \         Semigroup x = _front.top().val;\n            _front.pop();\n       \
    \     push_back(x);\n        }\n        while (!buff.empty()) {\n            Semigroup\
    \ x = buff.top();\n            buff.pop();\n            push_front(x);\n     \
    \   }\n    }\n\n  public:\n    deque_aggregation() = default;\n\n    int size()\
    \ const {\n        return _front.size() + _back.size();\n    }\n\n    bool empty()\
    \ const {\n        return size() == 0;\n    }\n\n    Semigroup front() {\n   \
    \     assert(!empty());\n        if (_front.empty()) move_front();\n        return\
    \ _front.top().val;\n    }\n\n    Semigroup back() {\n        assert(!empty());\n\
    \        if (_back.empty()) move_back();\n        return _back.top().val;\n  \
    \  }\n\n    void push_front(Semigroup x) {\n        Node node = {x, x};\n    \
    \    if (!_front.empty()) {\n            node.fold = op(x, _front.top().fold);\n\
    \        }\n        _front.push(node);\n    }\n\n    void push_back(Semigroup\
    \ x) {\n        Node node = {x, x};\n        if (!_back.empty()) {\n         \
    \   node.fold = op(_back.top().fold, x);\n        }\n        _back.push(node);\n\
    \    }\n\n    void pop_back() {\n        assert(!empty());\n        if (_back.empty())\
    \ move_back();\n        _back.pop();\n    }\n\n    void pop_front() {\n      \
    \  assert(!empty());\n        if (_front.empty()) move_front();\n        _front.pop();\n\
    \    }\n\n    Semigroup fold_all() {\n        assert(!empty());\n        if (_front.empty())\
    \ {\n            return _back.top().fold;\n        } else if (_back.empty()) {\n\
    \            return _front.top().fold;\n        } else {\n            return op(_front.top().fold,\
    \ _back.top().fold);\n        }\n    }\n\n  private:\n    std::stack<Node> _front,\
    \ _back;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <stack>\n\nnamespace ebi {\n\
    \ntemplate <class Semigroup, Semigroup (*op)(Semigroup, Semigroup)>\nstruct deque_aggregation\
    \ {\n  private:\n    struct Node {\n        Semigroup val;\n        Semigroup\
    \ fold;\n    };\n\n    void move_front() {\n        assert(_front.empty());\n\
    \        int sz = _back.size();\n        std::stack<Semigroup> buff;\n       \
    \ for (int i = 0; i < sz / 2; i++) {\n            buff.push(_back.top().val);\n\
    \            _back.pop();\n        }\n        while (!_back.empty()) {\n     \
    \       Semigroup x = _back.top().val;\n            _back.pop();\n           \
    \ push_front(x);\n        }\n        while (!buff.empty()) {\n            Semigroup\
    \ x = buff.top();\n            buff.pop();\n            push_back(x);\n      \
    \  }\n    }\n\n    void move_back() {\n        assert(_back.empty());\n      \
    \  int sz = _front.size();\n        std::stack<Semigroup> buff;\n        for (int\
    \ i = 0; i < sz / 2; i++) {\n            buff.push(_front.top().val);\n      \
    \      _front.pop();\n        }\n        while (!_front.empty()) {\n         \
    \   Semigroup x = _front.top().val;\n            _front.pop();\n            push_back(x);\n\
    \        }\n        while (!buff.empty()) {\n            Semigroup x = buff.top();\n\
    \            buff.pop();\n            push_front(x);\n        }\n    }\n\n  public:\n\
    \    deque_aggregation() = default;\n\n    int size() const {\n        return\
    \ _front.size() + _back.size();\n    }\n\n    bool empty() const {\n        return\
    \ size() == 0;\n    }\n\n    Semigroup front() {\n        assert(!empty());\n\
    \        if (_front.empty()) move_front();\n        return _front.top().val;\n\
    \    }\n\n    Semigroup back() {\n        assert(!empty());\n        if (_back.empty())\
    \ move_back();\n        return _back.top().val;\n    }\n\n    void push_front(Semigroup\
    \ x) {\n        Node node = {x, x};\n        if (!_front.empty()) {\n        \
    \    node.fold = op(x, _front.top().fold);\n        }\n        _front.push(node);\n\
    \    }\n\n    void push_back(Semigroup x) {\n        Node node = {x, x};\n   \
    \     if (!_back.empty()) {\n            node.fold = op(_back.top().fold, x);\n\
    \        }\n        _back.push(node);\n    }\n\n    void pop_back() {\n      \
    \  assert(!empty());\n        if (_back.empty()) move_back();\n        _back.pop();\n\
    \    }\n\n    void pop_front() {\n        assert(!empty());\n        if (_front.empty())\
    \ move_front();\n        _front.pop();\n    }\n\n    Semigroup fold_all() {\n\
    \        assert(!empty());\n        if (_front.empty()) {\n            return\
    \ _back.top().fold;\n        } else if (_back.empty()) {\n            return _front.top().fold;\n\
    \        } else {\n            return op(_front.top().fold, _back.top().fold);\n\
    \        }\n    }\n\n  private:\n    std::stack<Node> _front, _back;\n};\n\n}\
    \  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/deque_aggregation.hpp
  requiredBy: []
  timestamp: '2023-07-27 13:02:25+09:00'
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