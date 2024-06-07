---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fibonacci_heap.hpp
    title: fibonacci heap
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: Graph (CSR format)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/fibonacci_heap.test.cpp
    title: test/graph/fibonacci_heap.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dijkstra_fibheap.hpp\"\n\r\n#include <limits>\r\n\
    #include <vector>\r\n\r\n#line 2 \"data_structure/fibonacci_heap.hpp\"\n\r\n/*\r\
    \n    reference:\r\n   http://web.stanford.edu/class/archive/cs/cs166/cs166.1186/lectures/09/Slides09.pdf\r\
    \n               https://rsk0315.hatenablog.com/entry/2019/10/29/151823\r\n  \
    \             https://en.wikipedia.org/wiki/Fibonacci_heap\r\n*/\r\n\r\n#include\
    \ <cassert>\r\n#include <queue>\r\n#line 13 \"data_structure/fibonacci_heap.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\nnamespace internal {\r\n\r\ntemplate <class K, class\
    \ T> struct fibheap_node {\r\n    fibheap_node *par, *prev, *next, *chr;\r\n \
    \   int sz = 0;\r\n    bool damaged = 0;\r\n    K ord;\r\n    T val;\r\n    fibheap_node(K\
    \ k, T val)\r\n        : par(nullptr),\r\n          prev(this),\r\n          next(this),\r\
    \n          chr(nullptr),\r\n          ord(k),\r\n          val(val) {}\r\n\r\n\
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
    \n    }\r\n};\r\n\r\n}  // namespace ebi\r\n#line 2 \"graph/base.hpp\"\n\n#line\
    \ 4 \"graph/base.hpp\"\n#include <iostream>\n#include <ranges>\n#line 7 \"graph/base.hpp\"\
    \n\n#line 2 \"data_structure/simple_csr.hpp\"\n\n#line 4 \"data_structure/simple_csr.hpp\"\
    \n#include <utility>\n#line 6 \"data_structure/simple_csr.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <class E> struct simple_csr {\n    simple_csr() = default;\n\n\
    \    simple_csr(int n, const std::vector<std::pair<int, E>>& elements)\n     \
    \   : start(n + 1, 0), elist(elements.size()) {\n        for (auto e : elements)\
    \ {\n            start[e.first + 1]++;\n        }\n        for (auto i : std::views::iota(0,\
    \ n)) {\n            start[i + 1] += start[i];\n        }\n        auto counter\
    \ = start;\n        for (auto [i, e] : elements) {\n            elist[counter[i]++]\
    \ = e;\n        }\n    }\n\n    simple_csr(const std::vector<std::vector<E>>&\
    \ es)\n        : start(es.size() + 1, 0) {\n        int n = es.size();\n     \
    \   for (auto i : std::views::iota(0, n)) {\n            start[i + 1] = (int)es[i].size()\
    \ + start[i];\n        }\n        elist.resize(start.back());\n        for (auto\
    \ i : std::views::iota(0, n)) {\n            std::copy(es[i].begin(), es[i].end(),\
    \ elist.begin() + start[i]);\n        }\n    }\n\n    int size() const {\n   \
    \     return (int)start.size() - 1;\n    }\n\n    const auto operator[](int i)\
    \ const {\n        return std::ranges::subrange(elist.begin() + start[i],\n  \
    \                                   elist.begin() + start[i + 1]);\n    }\n  \
    \  auto operator[](int i) {\n        return std::ranges::subrange(elist.begin()\
    \ + start[i],\n                                     elist.begin() + start[i +\
    \ 1]);\n    }\n\n    const auto operator()(int i, int l, int r) const {\n    \
    \    return std::ranges::subrange(elist.begin() + start[i] + l,\n            \
    \                         elist.begin() + start[i + 1] + r);\n    }\n    auto\
    \ operator()(int i, int l, int r) {\n        return std::ranges::subrange(elist.begin()\
    \ + start[i] + l,\n                                     elist.begin() + start[i\
    \ + 1] + r);\n    }\n\n  private:\n    std::vector<int> start;\n    std::vector<E>\
    \ elist;\n};\n\n}  // namespace ebi\n#line 9 \"graph/base.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <class T> struct Edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n};\n\ntemplate <class E> struct Graph {\n    using cost_type = E;\n   \
    \ using edge_type = Edge<cost_type>;\n\n    Graph(int n_) : n(n_) {}\n\n    Graph()\
    \ = default;\n\n    void add_edge(int u, int v, cost_type c) {\n        buff.emplace_back(u,\
    \ edge_type{u, v, c, m});\n        edges.emplace_back(edge_type{u, v, c, m++});\n\
    \    }\n\n    void add_undirected_edge(int u, int v, cost_type c) {\n        buff.emplace_back(u,\
    \ edge_type{u, v, c, m});\n        buff.emplace_back(v, edge_type{v, u, c, m});\n\
    \        edges.emplace_back(edge_type{u, v, c, m});\n        m++;\n    }\n\n \
    \   void read_tree(int offset = 1, bool is_weighted = false) {\n        read_graph(n\
    \ - 1, offset, false, is_weighted);\n    }\n\n    void read_parents(int offset\
    \ = 1) {\n        for (auto i : std::views::iota(1, n)) {\n            int p;\n\
    \            std::cin >> p;\n            p -= offset;\n            add_undirected_edge(p,\
    \ i, 1);\n        }\n        build();\n    }\n\n    void read_graph(int e, int\
    \ offset = 1, bool is_directed = false,\n                    bool is_weighted\
    \ = false) {\n        for (int i = 0; i < e; i++) {\n            int u, v;\n \
    \           std::cin >> u >> v;\n            u -= offset;\n            v -= offset;\n\
    \            if (is_weighted) {\n                cost_type c;\n              \
    \  std::cin >> c;\n                if (is_directed) {\n                    add_edge(u,\
    \ v, c);\n                } else {\n                    add_undirected_edge(u,\
    \ v, c);\n                }\n            } else {\n                if (is_directed)\
    \ {\n                    add_edge(u, v, 1);\n                } else {\n      \
    \              add_undirected_edge(u, v, 1);\n                }\n            }\n\
    \        }\n        build();\n    }\n\n    void build() {\n        assert(!prepared);\n\
    \        csr = simple_csr<edge_type>(n, buff);\n        buff.clear();\n      \
    \  prepared = true;\n    }\n\n    int size() const {\n        return n;\n    }\n\
    \n    int node_number() const {\n        return n;\n    }\n\n    int edge_number()\
    \ const {\n        return m;\n    }\n\n    edge_type get_edge(int i) const {\n\
    \        return edges[i];\n    }\n\n    std::vector<edge_type> get_edges() const\
    \ {\n        return edges;\n    }\n\n    const auto operator[](int i) const {\n\
    \        return csr[i];\n    }\n    auto operator[](int i) {\n        return csr[i];\n\
    \    }\n\n  private:\n    int n, m = 0;\n\n    std::vector<std::pair<int,edge_type>>\
    \ buff;\n\n    std::vector<edge_type> edges;\n    simple_csr<edge_type> csr;\n\
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 8 \"graph/dijkstra_fibheap.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class T> bool op(T a, T b) {\r\n    return\
    \ a <= b;\r\n}\r\n\r\ntemplate <class T>\r\nstd::vector<T> dijkstra_fibheap(int\
    \ s, int n, const Graph<T> &g) {\r\n    std::vector<T> d(n, std::numeric_limits<T>::max());\r\
    \n    fibonacci_heap<T, int, op> que;\r\n    d[s] = 0;\r\n    std::vector<internal::fibheap_node<T,\
    \ int> *> p(n, nullptr);\r\n    p[s] = que.push(0, s);\r\n    while (!que.empty())\
    \ {\r\n        que.is_valid();\r\n        int v = que.top();\r\n        que.pop();\r\
    \n        for (auto e : g[v]) {\r\n            if (d[e.to] > d[v] + e.cost) {\r\
    \n                d[e.to] = d[v] + e.cost;\r\n                if (p[e.to] == nullptr)\
    \ {\r\n                    p[e.to] = que.push(d[e.to], e.to);\r\n            \
    \        continue;\r\n                }\r\n                que.prioritize(p[e.to],\
    \ d[e.to]);\r\n            }\r\n        }\r\n    }\r\n    return d;\r\n}\r\n\r\
    \n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <limits>\r\n#include <vector>\r\n\r\n#include\
    \ \"../data_structure/fibonacci_heap.hpp\"\r\n#include \"../graph/base.hpp\"\r\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class T> bool op(T a, T b) {\r\n    return\
    \ a <= b;\r\n}\r\n\r\ntemplate <class T>\r\nstd::vector<T> dijkstra_fibheap(int\
    \ s, int n, const Graph<T> &g) {\r\n    std::vector<T> d(n, std::numeric_limits<T>::max());\r\
    \n    fibonacci_heap<T, int, op> que;\r\n    d[s] = 0;\r\n    std::vector<internal::fibheap_node<T,\
    \ int> *> p(n, nullptr);\r\n    p[s] = que.push(0, s);\r\n    while (!que.empty())\
    \ {\r\n        que.is_valid();\r\n        int v = que.top();\r\n        que.pop();\r\
    \n        for (auto e : g[v]) {\r\n            if (d[e.to] > d[v] + e.cost) {\r\
    \n                d[e.to] = d[v] + e.cost;\r\n                if (p[e.to] == nullptr)\
    \ {\r\n                    p[e.to] = que.push(d[e.to], e.to);\r\n            \
    \        continue;\r\n                }\r\n                que.prioritize(p[e.to],\
    \ d[e.to]);\r\n            }\r\n        }\r\n    }\r\n    return d;\r\n}\r\n\r\
    \n}  // namespace ebi"
  dependsOn:
  - data_structure/fibonacci_heap.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: false
  path: graph/dijkstra_fibheap.hpp
  requiredBy: []
  timestamp: '2024-03-13 15:52:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/fibonacci_heap.test.cpp
documentation_of: graph/dijkstra_fibheap.hpp
layout: document
redirect_from:
- /library/graph/dijkstra_fibheap.hpp
- /library/graph/dijkstra_fibheap.hpp.html
title: graph/dijkstra_fibheap.hpp
---
