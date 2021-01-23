---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fibonacci_heap.hpp
    title: fibonacci_heap
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra_fibheap.hpp
    title: graph/dijkstra_fibheap.hpp
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.hpp
    title: utility/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"test/fibonacci_heap.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \r\n\r\n#line 2 \"graph/template.hpp\"\n\r\n#include <vector>\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate<class T>\r\nstruct Edge {\r\n    int to;\r\n    T cost;\r\
    \n    Edge(int to, T cost=1) : to(to), cost(cost) { }\r\n};\r\n\r\ntemplate<class\
    \ T>\r\nusing Graph = std::vector<std::vector<Edge<T>>>;\r\n\r\nusing graph =\
    \ std::vector<std::vector<int>>;\r\n\r\n} // namespace ebi\n#line 2 \"graph/dijkstra_fibheap.hpp\"\
    \n\r\n#line 2 \"data_structure/fibonacci_heap.hpp\"\n\r\n/*\r\n    reference:\
    \ http://web.stanford.edu/class/archive/cs/cs166/cs166.1186/lectures/09/Slides09.pdf\r\
    \n               https://rsk0315.hatenablog.com/entry/2019/10/29/151823\r\n  \
    \             https://en.wikipedia.org/wiki/Fibonacci_heap\r\n*/\r\n\r\n#include\
    \ <cassert>\r\n#line 11 \"data_structure/fibonacci_heap.hpp\"\n#include <queue>\r\
    \n\r\nnamespace ebi {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class K, class\
    \ T>\r\nstruct fibheap_node {\r\n    fibheap_node *par, *prev, *next, *chr;\r\n\
    \    int sz = 0;\r\n    bool damaged = 0;\r\n    K ord;\r\n    T val;\r\n    fibheap_node(K\
    \ k, T val) : par(nullptr), prev(this), next(this), chr(nullptr), ord(k), val(val)\
    \ { }\r\n\r\n    void emplace_back(fibheap_node *e) {\r\n        if(e == nullptr)\
    \ return;\r\n        prev->next = e;\r\n        e->prev->next = this;\r\n    \
    \    std::swap(e->prev, prev);\r\n    }\r\n\r\n    void cut_par() {\r\n      \
    \  if(par == nullptr) return;\r\n        par->sz--;\r\n        if(par->sz == 0)\
    \ {\r\n            par->chr = nullptr;\r\n        }\r\n        if(par->chr ==\
    \ this) {\r\n            par->chr = next;\r\n        }\r\n        cut();\r\n \
    \       par = nullptr;\r\n    }\r\n\r\n    void cut() {\r\n        next->prev\
    \ = prev;\r\n        prev->next = next;\r\n        next = prev = this;\r\n   \
    \ }\r\n\r\n    int size() const {\r\n        return sz;\r\n    }\r\n};\r\n\r\n\
    }\r\n\r\ntemplate<class K, class T, bool (*op)(K, K)>\r\nstruct fibonacci_heap\
    \ {\r\nprivate:\r\n    using Node = internal::fibheap_node<K, T>;\r\n    using\
    \ node_ptr = Node*;\r\n\r\n    node_ptr min = nullptr;\r\n    node_ptr roots =\
    \ nullptr;\r\n\r\n    int sz = 0;\r\n\r\n    void update(node_ptr a) {\r\n   \
    \     assert(a != nullptr);\r\n        if(!min || op(a->ord, min->ord)) {\r\n\
    \            min = a;\r\n        }\r\n    }\r\n\r\n    void merge(node_ptr a,\
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
    \n#line 5 \"graph/dijkstra_fibheap.hpp\"\n\r\n#line 7 \"graph/dijkstra_fibheap.hpp\"\
    \n#include <limits>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class T>\r\nbool op(T\
    \ a, T b) {\r\n    return a<=b;\r\n}\r\n\r\ntemplate<class T>\r\nstd::vector<T>\
    \ dijkstra(int s, int n, const Graph<T> &g){\r\n    std::vector<T> d(n, std::numeric_limits<T>::max());\r\
    \n    fibonacci_heap<T, int, op> que;\r\n    d[s] = 0;\r\n    std::vector<internal::fibheap_node<T,int>*>\
    \ p(n, nullptr);\r\n    p[s] = que.push(0, s);\r\n    while(!que.empty()){\r\n\
    \        que.is_valid();\r\n        int v = que.top();\r\n        //debug(v, d[v]);\r\
    \n        que.pop();\r\n        for(auto e: g[v]){\r\n            if(d[e.to]>d[v]+e.cost){\r\
    \n                d[e.to] = d[v]+e.cost;\r\n                if(p[e.to] == nullptr)\
    \ {\r\n                    p[e.to] = que.push(d[e.to], e.to);\r\n            \
    \        continue;\r\n                }\r\n                que.prioritize(p[e.to]\
    \ ,d[e.to]);\r\n            }\r\n        }\r\n    }\r\n    return d;\r\n}\r\n\r\
    \n} // namespace ebi\n#line 2 \"utility/int_alias.hpp\"\n\r\n#include <cstddef>\r\
    \n#include <cstdint>\r\n\r\nusing i32 = std::int32_t;\r\nusing i64 = std::int64_t;\r\
    \nusing u16 = std::uint16_t;\r\nusing u32 = std::uint32_t;\r\nusing u64 = std::uint64_t;\r\
    \nusing usize = std::size_t;\n#line 6 \"test/fibonacci_heap.test.cpp\"\n\r\n#include\
    \ <iostream>\r\n\r\nint main() {\r\n    int n,m,r;\r\n    std::cin >> n >> m >>\
    \ r;\r\n    ebi::Graph<i64> g(n);\r\n    while(m--) {\r\n        int s,t; i64\
    \ d;\r\n        std::cin >> s >> t >> d;\r\n        g[s].emplace_back(t, d);\r\
    \n    }\r\n    auto dist = ebi::dijkstra(r, n, g);\r\n    for(int i = 0; i<n;\
    \ i++) {\r\n        if(dist[i] == std::numeric_limits<i64>::max()) {\r\n     \
    \       std::cout << \"INF\" << std::endl;\r\n            continue;\r\n      \
    \  }\r\n        std::cout << dist[i] << std::endl;\r\n    }\r\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \r\n\r\n#include \"../graph/template.hpp\"\r\n#include \"../graph/dijkstra_fibheap.hpp\"\
    \r\n#include \"../utility/int_alias.hpp\"\r\n\r\n#include <iostream>\r\n\r\nint\
    \ main() {\r\n    int n,m,r;\r\n    std::cin >> n >> m >> r;\r\n    ebi::Graph<i64>\
    \ g(n);\r\n    while(m--) {\r\n        int s,t; i64 d;\r\n        std::cin >>\
    \ s >> t >> d;\r\n        g[s].emplace_back(t, d);\r\n    }\r\n    auto dist =\
    \ ebi::dijkstra(r, n, g);\r\n    for(int i = 0; i<n; i++) {\r\n        if(dist[i]\
    \ == std::numeric_limits<i64>::max()) {\r\n            std::cout << \"INF\" <<\
    \ std::endl;\r\n            continue;\r\n        }\r\n        std::cout << dist[i]\
    \ << std::endl;\r\n    }\r\n}"
  dependsOn:
  - graph/template.hpp
  - graph/dijkstra_fibheap.hpp
  - data_structure/fibonacci_heap.hpp
  - utility/int_alias.hpp
  isVerificationFile: true
  path: test/fibonacci_heap.test.cpp
  requiredBy: []
  timestamp: '2021-01-23 01:34:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/fibonacci_heap.test.cpp
layout: document
redirect_from:
- /verify/test/fibonacci_heap.test.cpp
- /verify/test/fibonacci_heap.test.cpp.html
title: test/fibonacci_heap.test.cpp
---
