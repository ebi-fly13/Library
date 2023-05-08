---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/fibonacci_heap.hpp
    title: fibonacci_heap
  - icon: ':question:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/fibonacci_heap.test.cpp
    title: test/fibonacci_heap.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dijkstra_fibheap.hpp\"\n\r\n#line 2 \"data_structure/fibonacci_heap.hpp\"\
    \n\r\n/*\r\n    reference:\r\n   http://web.stanford.edu/class/archive/cs/cs166/cs166.1186/lectures/09/Slides09.pdf\r\
    \n               https://rsk0315.hatenablog.com/entry/2019/10/29/151823\r\n  \
    \             https://en.wikipedia.org/wiki/Fibonacci_heap\r\n*/\r\n\r\n#include\
    \ <cassert>\r\n#include <queue>\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\
    \r\nnamespace internal {\r\n\r\ntemplate <class K, class T> struct fibheap_node\
    \ {\r\n    fibheap_node *par, *prev, *next, *chr;\r\n    int sz = 0;\r\n    bool\
    \ damaged = 0;\r\n    K ord;\r\n    T val;\r\n    fibheap_node(K k, T val)\r\n\
    \        : par(nullptr),\r\n          prev(this),\r\n          next(this),\r\n\
    \          chr(nullptr),\r\n          ord(k),\r\n          val(val) {}\r\n\r\n\
    \    void emplace_back(fibheap_node *e) {\r\n        if (e == nullptr) return;\r\
    \n        prev->next = e;\r\n        e->prev->next = this;\r\n        std::swap(e->prev,\
    \ prev);\r\n    }\r\n\r\n    void cut_par() {\r\n        if (par == nullptr) return;\r\
    \n        par->sz--;\r\n        if (par->sz == 0) {\r\n            par->chr =\
    \ nullptr;\r\n        }\r\n        if (par->chr == this) {\r\n            par->chr\
    \ = next;\r\n        }\r\n        cut();\r\n        par = nullptr;\r\n    }\r\n\
    \r\n    void cut() {\r\n        next->prev = prev;\r\n        prev->next = next;\r\
    \n        next = prev = this;\r\n    }\r\n\r\n    int size() const {\r\n     \
    \   return sz;\r\n    }\r\n};\r\n\r\n}  // namespace internal\r\n\r\ntemplate\
    \ <class K, class T, bool (*op)(K, K)> struct fibonacci_heap {\r\n  private:\r\
    \n    using Node = internal::fibheap_node<K, T>;\r\n    using node_ptr = Node\
    \ *;\r\n\r\n    node_ptr min = nullptr;\r\n    node_ptr roots = nullptr;\r\n\r\
    \n    int sz = 0;\r\n\r\n    void update(node_ptr a) {\r\n        assert(a !=\
    \ nullptr);\r\n        if (!min || op(a->ord, min->ord)) {\r\n            min\
    \ = a;\r\n        }\r\n    }\r\n\r\n    void merge(node_ptr a, node_ptr b) {\r\
    \n        assert(a && b);\r\n        assert(op(a->ord, b->ord));\r\n        a->sz++;\r\
    \n        b->par = a;\r\n        if (a->chr == nullptr)\r\n            a->chr\
    \ = b;\r\n        else\r\n            a->chr->emplace_back(b);\r\n    }\r\n\r\n\
    \    int log2ceil(int m) {\r\n        int n = 1;\r\n        while ((1 << n) <\
    \ m) {\r\n            n++;\r\n        }\r\n        return n;\r\n    }\r\n\r\n\
    \  public:\r\n    node_ptr push(K k, T val) {\r\n        node_ptr a = new Node(k,\
    \ val);\r\n        sz++;\r\n        update(a);\r\n        if (roots == nullptr)\
    \ {\r\n            roots = a;\r\n            return a;\r\n        }\r\n      \
    \  roots->emplace_back(a);\r\n        is_valid();\r\n        return a;\r\n   \
    \ }\r\n\r\n    void pop() {\r\n        assert(sz > 0);\r\n        roots->emplace_back(min->chr);\r\
    \n        if (roots == min) {\r\n            roots = roots->next;\r\n        \
    \    assert(roots->prev == min);\r\n        }\r\n        min->cut();\r\n     \
    \   delete min;\r\n        min = nullptr;\r\n        sz--;\r\n        if (sz ==\
    \ 0) {\r\n            roots = nullptr;\r\n            return;\r\n        }\r\n\
    \        int n = log2ceil(size()) + 5;\r\n        std::vector<std::queue<node_ptr>>\
    \ que(n);\r\n        que[roots->size()].push(roots);\r\n        roots->par = nullptr;\r\
    \n        for (node_ptr ptr = roots->next; ptr != roots; ptr = ptr->next) {\r\n\
    \            update(ptr);\r\n            ptr->par = nullptr;\r\n            que[ptr->size()].push(ptr);\r\
    \n        }\r\n        roots = nullptr;\r\n        for (int i = 0; i < n; i++)\
    \ {\r\n            while (que[i].size() > 1) {\r\n                node_ptr first\
    \ = que[i].front();\r\n                que[i].pop();\r\n                node_ptr\
    \ second = que[i].front();\r\n                que[i].pop();\r\n              \
    \  first->cut();\r\n                second->cut();\r\n                if (!op(first->ord,\
    \ second->ord)) std::swap(first, second);\r\n                merge(first, second);\r\
    \n                assert(first->sz == i + 1);\r\n                que[first->size()].push(first);\r\
    \n            }\r\n            if (que[i].size() == 1) {\r\n                node_ptr\
    \ ptr = que[i].front();\r\n                que[i].pop();\r\n                update(ptr);\r\
    \n                ptr->cut();\r\n                if (roots == nullptr) {\r\n \
    \                   roots = ptr;\r\n                    continue;\r\n        \
    \        }\r\n                roots->emplace_back(ptr);\r\n            }\r\n \
    \       }\r\n    }\r\n\r\n    T top() const {\r\n        return min->val;\r\n\
    \    }\r\n\r\n    void prioritize(node_ptr e, K k) {\r\n        assert(e && op(k,\
    \ e->ord));\r\n        e->ord = k;\r\n        update(e);\r\n        if (e->par\
    \ == nullptr || op(e->par->ord, e->ord)) return;\r\n        if (e->par->damaged\
    \ && e->par->par != nullptr) {\r\n            e->par->cut_par();\r\n         \
    \   roots->emplace_back(e->par);\r\n        }\r\n        e->par->damaged = true;\r\
    \n        e->cut_par();\r\n        roots->emplace_back(e);\r\n    }\r\n\r\n  \
    \  int size() const {\r\n        return sz;\r\n    }\r\n\r\n    bool empty() const\
    \ {\r\n        return sz == 0;\r\n    }\r\n\r\n    void is_valid() const {\r\n\
    \        K k = roots->ord;\r\n        for (node_ptr ptr = roots->next; ptr !=\
    \ roots; ptr = ptr->next) {\r\n            if (op(ptr->ord, k)) {\r\n        \
    \        k = ptr->ord;\r\n            }\r\n        }\r\n        assert(k == min->ord);\r\
    \n    }\r\n};\r\n\r\n}  // namespace ebi\r\n#line 2 \"graph/template.hpp\"\n\r\
    \n#line 4 \"graph/template.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate <class T>\
    \ struct Edge {\r\n    int to;\r\n    T cost;\r\n    Edge(int _to, T _cost = 1)\
    \ : to(_to), cost(_cost) {}\r\n};\r\n\r\ntemplate <class T> struct Graph : std::vector<std::vector<Edge<T>>>\
    \ {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\n    void add_edge(int\
    \ u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if (directed) return;\r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if (directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\n#line 5 \"graph/dijkstra_fibheap.hpp\"\n\r\n#include <limits>\r\n#line\
    \ 8 \"graph/dijkstra_fibheap.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate <class\
    \ T> bool op(T a, T b) {\r\n    return a <= b;\r\n}\r\n\r\ntemplate <class T>\
    \ std::vector<T> dijkstra(int s, int n, const Graph<T> &g) {\r\n    std::vector<T>\
    \ d(n, std::numeric_limits<T>::max());\r\n    fibonacci_heap<T, int, op> que;\r\
    \n    d[s] = 0;\r\n    std::vector<internal::fibheap_node<T, int> *> p(n, nullptr);\r\
    \n    p[s] = que.push(0, s);\r\n    while (!que.empty()) {\r\n        que.is_valid();\r\
    \n        int v = que.top();\r\n        // debug(v, d[v]);\r\n        que.pop();\r\
    \n        for (auto e : g[v]) {\r\n            if (d[e.to] > d[v] + e.cost) {\r\
    \n                d[e.to] = d[v] + e.cost;\r\n                if (p[e.to] == nullptr)\
    \ {\r\n                    p[e.to] = que.push(d[e.to], e.to);\r\n            \
    \        continue;\r\n                }\r\n                que.prioritize(p[e.to],\
    \ d[e.to]);\r\n            }\r\n        }\r\n    }\r\n    return d;\r\n}\r\n\r\
    \n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include \"../data_structure/fibonacci_heap.hpp\"\r\n\
    #include \"../graph/template.hpp\"\r\n\r\n#include <limits>\r\n#include <vector>\r\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class T> bool op(T a, T b) {\r\n    return\
    \ a <= b;\r\n}\r\n\r\ntemplate <class T> std::vector<T> dijkstra(int s, int n,\
    \ const Graph<T> &g) {\r\n    std::vector<T> d(n, std::numeric_limits<T>::max());\r\
    \n    fibonacci_heap<T, int, op> que;\r\n    d[s] = 0;\r\n    std::vector<internal::fibheap_node<T,\
    \ int> *> p(n, nullptr);\r\n    p[s] = que.push(0, s);\r\n    while (!que.empty())\
    \ {\r\n        que.is_valid();\r\n        int v = que.top();\r\n        // debug(v,\
    \ d[v]);\r\n        que.pop();\r\n        for (auto e : g[v]) {\r\n          \
    \  if (d[e.to] > d[v] + e.cost) {\r\n                d[e.to] = d[v] + e.cost;\r\
    \n                if (p[e.to] == nullptr) {\r\n                    p[e.to] = que.push(d[e.to],\
    \ e.to);\r\n                    continue;\r\n                }\r\n           \
    \     que.prioritize(p[e.to], d[e.to]);\r\n            }\r\n        }\r\n    }\r\
    \n    return d;\r\n}\r\n\r\n}  // namespace ebi"
  dependsOn:
  - data_structure/fibonacci_heap.hpp
  - graph/template.hpp
  isVerificationFile: false
  path: graph/dijkstra_fibheap.hpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/fibonacci_heap.test.cpp
documentation_of: graph/dijkstra_fibheap.hpp
layout: document
redirect_from:
- /library/graph/dijkstra_fibheap.hpp
- /library/graph/dijkstra_fibheap.hpp.html
title: graph/dijkstra_fibheap.hpp
---
