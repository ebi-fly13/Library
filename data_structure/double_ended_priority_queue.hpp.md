---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/removable_priority_queue.hpp
    title: Removable Priority Queue
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Double-Ended_Priority_Queue.test.cpp
    title: test/data_structure/Double-Ended_Priority_Queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/double_ended_priority_queue.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\n#line 2 \"data_structure/removable_priority_queue.hpp\"\
    \n\n#include <functional>\n#include <queue>\n#line 6 \"data_structure/removable_priority_queue.hpp\"\
    \n\n/*\n    reference: https://twitter.com/maspy_stars/status/1436690222465486848\n\
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
    \ ebi\n#line 7 \"data_structure/double_ended_priority_queue.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <class T> struct double_ended_priority_queue {\n  public:\n\
    \    double_ended_priority_queue() = default;\n\n    template <class InputIterator>\n\
    \    double_ended_priority_queue(InputIterator first, InputIterator last) {\n\
    \        min = removable_priority_queue<T, std::vector<T>, std::greater<T>>(\n\
    \            first, last);\n        max = removable_priority_queue<T>(first, last);\n\
    \    }\n\n    bool empty() const {\n        return min.empty() && max.empty();\n\
    \    }\n\n    int size() const {\n        assert(min.size() == max.size());\n\
    \        return min.size();\n    }\n\n    void push(T x) {\n        min.push(x);\n\
    \        max.push(x);\n    }\n\n    template <class... Args> void emplace(Args\
    \ &&...args) {\n        min.emplace(std::forward<Args>(args)...);\n        max.emplace(std::forward<Args>(args)...);\n\
    \        return;\n    }\n\n    void pop_min() {\n        T x = min.top();\n  \
    \      min.pop();\n        max.remove(x);\n    }\n\n    void pop_max() {\n   \
    \     T x = max.top();\n        max.pop();\n        min.remove(x);\n    }\n\n\
    \    T get_min() {\n        assert(!min.empty());\n        return min.top();\n\
    \    }\n\n    T get_max() {\n        assert(!max.empty());\n        return max.top();\n\
    \    }\n\n  private:\n    removable_priority_queue<T, std::vector<T>, std::greater<T>>\
    \ min;\n    removable_priority_queue<T> max;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../data_structure/removable_priority_queue.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> struct double_ended_priority_queue {\n\
    \  public:\n    double_ended_priority_queue() = default;\n\n    template <class\
    \ InputIterator>\n    double_ended_priority_queue(InputIterator first, InputIterator\
    \ last) {\n        min = removable_priority_queue<T, std::vector<T>, std::greater<T>>(\n\
    \            first, last);\n        max = removable_priority_queue<T>(first, last);\n\
    \    }\n\n    bool empty() const {\n        return min.empty() && max.empty();\n\
    \    }\n\n    int size() const {\n        assert(min.size() == max.size());\n\
    \        return min.size();\n    }\n\n    void push(T x) {\n        min.push(x);\n\
    \        max.push(x);\n    }\n\n    template <class... Args> void emplace(Args\
    \ &&...args) {\n        min.emplace(std::forward<Args>(args)...);\n        max.emplace(std::forward<Args>(args)...);\n\
    \        return;\n    }\n\n    void pop_min() {\n        T x = min.top();\n  \
    \      min.pop();\n        max.remove(x);\n    }\n\n    void pop_max() {\n   \
    \     T x = max.top();\n        max.pop();\n        min.remove(x);\n    }\n\n\
    \    T get_min() {\n        assert(!min.empty());\n        return min.top();\n\
    \    }\n\n    T get_max() {\n        assert(!max.empty());\n        return max.top();\n\
    \    }\n\n  private:\n    removable_priority_queue<T, std::vector<T>, std::greater<T>>\
    \ min;\n    removable_priority_queue<T> max;\n};\n\n}  // namespace ebi"
  dependsOn:
  - data_structure/removable_priority_queue.hpp
  isVerificationFile: false
  path: data_structure/double_ended_priority_queue.hpp
  requiredBy: []
  timestamp: '2024-03-08 13:39:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Double-Ended_Priority_Queue.test.cpp
documentation_of: data_structure/double_ended_priority_queue.hpp
layout: document
title: Double-Ended Priority Queue
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