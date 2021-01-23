---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra_fibheap.hpp
    title: graph/dijkstra_fibheap.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/fibonacci_heap.test.cpp
    title: test/fibonacci_heap.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://web.stanford.edu/class/archive/cs/cs166/cs166.1186/lectures/09/Slides09.pdf
    - https://en.wikipedia.org/wiki/Fibonacci_heap
    - https://rsk0315.hatenablog.com/entry/2019/10/29/151823
  bundledCode: "#line 2 \"data_structure/fibonacci_heap.hpp\"\n\r\n/*\r\n    reference:\
    \ http://web.stanford.edu/class/archive/cs/cs166/cs166.1186/lectures/09/Slides09.pdf\r\
    \n               https://rsk0315.hatenablog.com/entry/2019/10/29/151823\r\n  \
    \             https://en.wikipedia.org/wiki/Fibonacci_heap\r\n*/\r\n\r\n#include\
    \ <cassert>\r\n#include <vector>\r\n#include <queue>\r\n\r\nnamespace ebi {\r\n\
    \r\nnamespace internal {\r\n\r\ntemplate<class K, class T>\r\nstruct fibheap_node\
    \ {\r\n    fibheap_node *par, *prev, *next, *chr;\r\n    int sz = 0;\r\n    bool\
    \ damaged = 0;\r\n    K ord;\r\n    T val;\r\n    fibheap_node(K k, T val) : par(nullptr),\
    \ prev(this), next(this), chr(nullptr), ord(k), val(val) { }\r\n\r\n    void emplace_back(fibheap_node\
    \ *e) {\r\n        if(e == nullptr) return;\r\n        prev->next = e;\r\n   \
    \     e->prev->next = this;\r\n        std::swap(e->prev, prev);\r\n    }\r\n\r\
    \n    void cut_par() {\r\n        if(par == nullptr) return;\r\n        par->sz--;\r\
    \n        if(par->sz == 0) {\r\n            par->chr = nullptr;\r\n        }\r\
    \n        if(par->chr == this) {\r\n            par->chr = next;\r\n        }\r\
    \n        cut();\r\n        par = nullptr;\r\n    }\r\n\r\n    void cut() {\r\n\
    \        next->prev = prev;\r\n        prev->next = next;\r\n        next = prev\
    \ = this;\r\n    }\r\n\r\n    int size() const {\r\n        return sz;\r\n   \
    \ }\r\n};\r\n\r\n}\r\n\r\ntemplate<class K, class T, bool (*op)(K, K)>\r\nstruct\
    \ fibonacci_heap {\r\nprivate:\r\n    using Node = internal::fibheap_node<K, T>;\r\
    \n    using node_ptr = Node*;\r\n\r\n    node_ptr min = nullptr;\r\n    node_ptr\
    \ roots = nullptr;\r\n\r\n    int sz = 0;\r\n\r\n    void update(node_ptr a) {\r\
    \n        assert(a != nullptr);\r\n        if(!min || op(a->ord, min->ord)) {\r\
    \n            min = a;\r\n        }\r\n    }\r\n\r\n    void merge(node_ptr a,\
    \ node_ptr b) {\r\n        assert(a && b);\r\n        assert(op(a->ord, b->ord));\r\
    \n        a->sz++;\r\n        b->par = a;\r\n        if(a->chr == nullptr) a->chr\
    \ = b;\r\n        else a->chr->emplace_back(b);\r\n    }\r\n\r\n    int log2ceil(int\
    \ m) {\r\n        int n = 1;\r\n        while((1<<n)<m) {\r\n            n++;\r\
    \n        }\r\n        return n;\r\n    }\r\n\r\npublic:\r\n    node_ptr push(K\
    \ k, T val) {\r\n        node_ptr a = new Node(k,val);\r\n        sz++;\r\n  \
    \      update(a);\r\n        if(roots == nullptr) {\r\n            roots = a;\r\
    \n            return a;\r\n        }\r\n        roots->emplace_back(a);\r\n  \
    \      is_valid();\r\n        return a;\r\n    }\r\n\r\n    void pop() {\r\n \
    \       assert(sz > 0);\r\n        roots->emplace_back(min->chr);\r\n        if(roots\
    \ == min) {\r\n            roots = roots->next;\r\n            assert(roots->prev\
    \ == min);\r\n        }\r\n        min->cut();\r\n        delete min;\r\n    \
    \    min = nullptr;\r\n        sz--;\r\n        if(sz==0) {\r\n            roots\
    \ = nullptr;\r\n            return;\r\n        }\r\n        int n = log2ceil(size())\
    \ + 5;\r\n        std::vector<std::queue<node_ptr>> que(n);\r\n        que[roots->size()].push(roots);\r\
    \n        roots->par = nullptr;\r\n        for(node_ptr ptr = roots->next; ptr\
    \ != roots; ptr = ptr->next) {\r\n            update(ptr);\r\n            ptr->par\
    \ = nullptr;\r\n            que[ptr->size()].push(ptr);\r\n        }\r\n     \
    \   roots = nullptr;\r\n        for(int i = 0; i<n; i++) {\r\n            while(que[i].size()\
    \ > 1) {\r\n                node_ptr first = que[i].front(); que[i].pop();\r\n\
    \                node_ptr second = que[i].front(); que[i].pop();\r\n         \
    \       first->cut();\r\n                second->cut();\r\n                if(!op(first->ord,\
    \ second->ord)) std::swap(first, second);\r\n                merge(first, second);\r\
    \n                assert(first->sz == i+1);\r\n                que[first->size()].push(first);\r\
    \n            }\r\n            if(que[i].size()==1) {\r\n                node_ptr\
    \ ptr = que[i].front(); que[i].pop();\r\n                update(ptr);\r\n    \
    \            ptr->cut();\r\n                if(roots == nullptr) {\r\n       \
    \             roots = ptr;\r\n                    continue;\r\n              \
    \  }\r\n                roots->emplace_back(ptr);\r\n            }\r\n       \
    \ }\r\n    }\r\n\r\n    T top() const {\r\n        return min->val;\r\n    }\r\
    \n\r\n    void prioritize(node_ptr e, K k) {\r\n        assert(e && op(k, e->ord));\r\
    \n        e->ord = k;\r\n        update(e);\r\n        if(e->par == nullptr ||\
    \ op(e->par->ord, e->ord)) return;\r\n        if(e->par->damaged && e->par->par\
    \ != nullptr) {\r\n            e->par->cut_par();\r\n            roots->emplace_back(e->par);\r\
    \n        }\r\n        e->par->damaged = true;\r\n        e->cut_par();\r\n  \
    \      roots->emplace_back(e);\r\n    }\r\n\r\n    int size() const {\r\n    \
    \    return sz;\r\n    }\r\n\r\n    bool empty() const {\r\n        return sz==0;\r\
    \n    }\r\n\r\n    void is_valid() const {\r\n        K k = roots->ord;\r\n  \
    \      for(node_ptr ptr = roots->next; ptr != roots; ptr = ptr->next) {\r\n  \
    \          if(op(ptr->ord, k)) {\r\n                k = ptr->ord;\r\n        \
    \    }\r\n        }\r\n        assert(k == min->ord);\r\n    }\r\n};\r\n\r\n}\r\
    \n"
  code: "#pragma once\r\n\r\n/*\r\n    reference: http://web.stanford.edu/class/archive/cs/cs166/cs166.1186/lectures/09/Slides09.pdf\r\
    \n               https://rsk0315.hatenablog.com/entry/2019/10/29/151823\r\n  \
    \             https://en.wikipedia.org/wiki/Fibonacci_heap\r\n*/\r\n\r\n#include\
    \ <cassert>\r\n#include <vector>\r\n#include <queue>\r\n\r\nnamespace ebi {\r\n\
    \r\nnamespace internal {\r\n\r\ntemplate<class K, class T>\r\nstruct fibheap_node\
    \ {\r\n    fibheap_node *par, *prev, *next, *chr;\r\n    int sz = 0;\r\n    bool\
    \ damaged = 0;\r\n    K ord;\r\n    T val;\r\n    fibheap_node(K k, T val) : par(nullptr),\
    \ prev(this), next(this), chr(nullptr), ord(k), val(val) { }\r\n\r\n    void emplace_back(fibheap_node\
    \ *e) {\r\n        if(e == nullptr) return;\r\n        prev->next = e;\r\n   \
    \     e->prev->next = this;\r\n        std::swap(e->prev, prev);\r\n    }\r\n\r\
    \n    void cut_par() {\r\n        if(par == nullptr) return;\r\n        par->sz--;\r\
    \n        if(par->sz == 0) {\r\n            par->chr = nullptr;\r\n        }\r\
    \n        if(par->chr == this) {\r\n            par->chr = next;\r\n        }\r\
    \n        cut();\r\n        par = nullptr;\r\n    }\r\n\r\n    void cut() {\r\n\
    \        next->prev = prev;\r\n        prev->next = next;\r\n        next = prev\
    \ = this;\r\n    }\r\n\r\n    int size() const {\r\n        return sz;\r\n   \
    \ }\r\n};\r\n\r\n}\r\n\r\ntemplate<class K, class T, bool (*op)(K, K)>\r\nstruct\
    \ fibonacci_heap {\r\nprivate:\r\n    using Node = internal::fibheap_node<K, T>;\r\
    \n    using node_ptr = Node*;\r\n\r\n    node_ptr min = nullptr;\r\n    node_ptr\
    \ roots = nullptr;\r\n\r\n    int sz = 0;\r\n\r\n    void update(node_ptr a) {\r\
    \n        assert(a != nullptr);\r\n        if(!min || op(a->ord, min->ord)) {\r\
    \n            min = a;\r\n        }\r\n    }\r\n\r\n    void merge(node_ptr a,\
    \ node_ptr b) {\r\n        assert(a && b);\r\n        assert(op(a->ord, b->ord));\r\
    \n        a->sz++;\r\n        b->par = a;\r\n        if(a->chr == nullptr) a->chr\
    \ = b;\r\n        else a->chr->emplace_back(b);\r\n    }\r\n\r\n    int log2ceil(int\
    \ m) {\r\n        int n = 1;\r\n        while((1<<n)<m) {\r\n            n++;\r\
    \n        }\r\n        return n;\r\n    }\r\n\r\npublic:\r\n    node_ptr push(K\
    \ k, T val) {\r\n        node_ptr a = new Node(k,val);\r\n        sz++;\r\n  \
    \      update(a);\r\n        if(roots == nullptr) {\r\n            roots = a;\r\
    \n            return a;\r\n        }\r\n        roots->emplace_back(a);\r\n  \
    \      is_valid();\r\n        return a;\r\n    }\r\n\r\n    void pop() {\r\n \
    \       assert(sz > 0);\r\n        roots->emplace_back(min->chr);\r\n        if(roots\
    \ == min) {\r\n            roots = roots->next;\r\n            assert(roots->prev\
    \ == min);\r\n        }\r\n        min->cut();\r\n        delete min;\r\n    \
    \    min = nullptr;\r\n        sz--;\r\n        if(sz==0) {\r\n            roots\
    \ = nullptr;\r\n            return;\r\n        }\r\n        int n = log2ceil(size())\
    \ + 5;\r\n        std::vector<std::queue<node_ptr>> que(n);\r\n        que[roots->size()].push(roots);\r\
    \n        roots->par = nullptr;\r\n        for(node_ptr ptr = roots->next; ptr\
    \ != roots; ptr = ptr->next) {\r\n            update(ptr);\r\n            ptr->par\
    \ = nullptr;\r\n            que[ptr->size()].push(ptr);\r\n        }\r\n     \
    \   roots = nullptr;\r\n        for(int i = 0; i<n; i++) {\r\n            while(que[i].size()\
    \ > 1) {\r\n                node_ptr first = que[i].front(); que[i].pop();\r\n\
    \                node_ptr second = que[i].front(); que[i].pop();\r\n         \
    \       first->cut();\r\n                second->cut();\r\n                if(!op(first->ord,\
    \ second->ord)) std::swap(first, second);\r\n                merge(first, second);\r\
    \n                assert(first->sz == i+1);\r\n                que[first->size()].push(first);\r\
    \n            }\r\n            if(que[i].size()==1) {\r\n                node_ptr\
    \ ptr = que[i].front(); que[i].pop();\r\n                update(ptr);\r\n    \
    \            ptr->cut();\r\n                if(roots == nullptr) {\r\n       \
    \             roots = ptr;\r\n                    continue;\r\n              \
    \  }\r\n                roots->emplace_back(ptr);\r\n            }\r\n       \
    \ }\r\n    }\r\n\r\n    T top() const {\r\n        return min->val;\r\n    }\r\
    \n\r\n    void prioritize(node_ptr e, K k) {\r\n        assert(e && op(k, e->ord));\r\
    \n        e->ord = k;\r\n        update(e);\r\n        if(e->par == nullptr ||\
    \ op(e->par->ord, e->ord)) return;\r\n        if(e->par->damaged && e->par->par\
    \ != nullptr) {\r\n            e->par->cut_par();\r\n            roots->emplace_back(e->par);\r\
    \n        }\r\n        e->par->damaged = true;\r\n        e->cut_par();\r\n  \
    \      roots->emplace_back(e);\r\n    }\r\n\r\n    int size() const {\r\n    \
    \    return sz;\r\n    }\r\n\r\n    bool empty() const {\r\n        return sz==0;\r\
    \n    }\r\n\r\n    void is_valid() const {\r\n        K k = roots->ord;\r\n  \
    \      for(node_ptr ptr = roots->next; ptr != roots; ptr = ptr->next) {\r\n  \
    \          if(op(ptr->ord, k)) {\r\n                k = ptr->ord;\r\n        \
    \    }\r\n        }\r\n        assert(k == min->ord);\r\n    }\r\n};\r\n\r\n}\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/fibonacci_heap.hpp
  requiredBy:
  - graph/dijkstra_fibheap.hpp
  timestamp: '2021-01-23 01:34:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fibonacci_heap.test.cpp
documentation_of: data_structure/fibonacci_heap.hpp
layout: document
title: fibonacci_heap
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
-    ```heap.pop()```
    -   heapの優先度最小の値をheapから取り除く.
    -   償却計算量$O(\log n)$
-   ```heap.top()```
    -   優先度最小の値を返す.
    -   時間計算量$O(1)$
-   ```prioritize(node_ptr e, K k)```
    -   ```node_ptr = internal::fibheap_node<K, T>*```である.
    -   ポインタ$e$を指す要素の優先度を$k$にする.ただし優先度はもとの優先度より小さくなければならない.
    -   時間計算量$O(1)$
