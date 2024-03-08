---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/double_ended_priority_queue.hpp
    title: Double-Ended Priority Queue
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Double-Ended_Priority_Queue.test.cpp
    title: test/data_structure/Double-Ended_Priority_Queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc218/submissions/25800862
    - https://twitter.com/maspy_stars/status/1436690222465486848
  bundledCode: "#line 2 \"data_structure/removable_priority_queue.hpp\"\n\n#include\
    \ <functional>\n#include <queue>\n#include <vector>\n\n/*\n    reference: https://twitter.com/maspy_stars/status/1436690222465486848\n\
    \    verify: https://atcoder.jp/contests/abc218/submissions/25800862\n*/\n\nnamespace\
    \ ebi {\n\ntemplate <class T, class Container = std::vector<T>,\n          class\
    \ Compare = std::less<typename Container::value_type>>\nstruct removable_priority_queue\
    \ {\n  private:\n    void update() {\n        while (!rm_que.empty() && que.top()\
    \ == rm_que.top()) {\n            que.pop();\n            rm_que.pop();\n    \
    \    }\n        return;\n    }\n\n  public:\n    removable_priority_queue() =\
    \ default;\n\n    template <class InputIterator>\n    removable_priority_queue(InputIterator\
    \ first, InputIterator last) {\n        que = std::priority_queue<T, Container,\
    \ Compare>(first, last);\n    }\n\n    bool empty() const {\n        return (size()\
    \ == 0);\n    }\n\n    int size() const {\n        return int(que.size() - rm_que.size());\n\
    \    }\n\n    T top() {\n        assert(!empty());\n        update();\n      \
    \  return que.top();\n    }\n\n    void pop() {\n        assert(!empty());\n \
    \       update();\n        que.pop();\n        return;\n    }\n\n    void push(const\
    \ T &x) {\n        que.push(x);\n        return;\n    }\n\n    template <class...\
    \ Args> void emplace(Args &&...args) {\n        que.emplace(std::forward<Args>(args)...);\n\
    \        return;\n    }\n\n    void remove(const T &x) {\n        rm_que.push(x);\n\
    \        assert(que.size() >= rm_que.size());\n        return;\n    }\n\n    template\
    \ <class... Args> void emplace_remove(Args &&...args) {\n        rm_que.emplace(std::forward<Args>(args)...);\n\
    \        assert(que.size() >= rm_que.size());\n        return;\n    }\n\n  private:\n\
    \    std::priority_queue<T, Container, Compare> que, rm_que;\n};\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <functional>\n#include <queue>\n#include <vector>\n\
    \n/*\n    reference: https://twitter.com/maspy_stars/status/1436690222465486848\n\
    \    verify: https://atcoder.jp/contests/abc218/submissions/25800862\n*/\n\nnamespace\
    \ ebi {\n\ntemplate <class T, class Container = std::vector<T>,\n          class\
    \ Compare = std::less<typename Container::value_type>>\nstruct removable_priority_queue\
    \ {\n  private:\n    void update() {\n        while (!rm_que.empty() && que.top()\
    \ == rm_que.top()) {\n            que.pop();\n            rm_que.pop();\n    \
    \    }\n        return;\n    }\n\n  public:\n    removable_priority_queue() =\
    \ default;\n\n    template <class InputIterator>\n    removable_priority_queue(InputIterator\
    \ first, InputIterator last) {\n        que = std::priority_queue<T, Container,\
    \ Compare>(first, last);\n    }\n\n    bool empty() const {\n        return (size()\
    \ == 0);\n    }\n\n    int size() const {\n        return int(que.size() - rm_que.size());\n\
    \    }\n\n    T top() {\n        assert(!empty());\n        update();\n      \
    \  return que.top();\n    }\n\n    void pop() {\n        assert(!empty());\n \
    \       update();\n        que.pop();\n        return;\n    }\n\n    void push(const\
    \ T &x) {\n        que.push(x);\n        return;\n    }\n\n    template <class...\
    \ Args> void emplace(Args &&...args) {\n        que.emplace(std::forward<Args>(args)...);\n\
    \        return;\n    }\n\n    void remove(const T &x) {\n        rm_que.push(x);\n\
    \        assert(que.size() >= rm_que.size());\n        return;\n    }\n\n    template\
    \ <class... Args> void emplace_remove(Args &&...args) {\n        rm_que.emplace(std::forward<Args>(args)...);\n\
    \        assert(que.size() >= rm_que.size());\n        return;\n    }\n\n  private:\n\
    \    std::priority_queue<T, Container, Compare> que, rm_que;\n};\n\n}  // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/removable_priority_queue.hpp
  requiredBy:
  - data_structure/double_ended_priority_queue.hpp
  timestamp: '2024-03-08 13:39:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Double-Ended_Priority_Queue.test.cpp
documentation_of: data_structure/removable_priority_queue.hpp
layout: document
title: Removable Priority Queue
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