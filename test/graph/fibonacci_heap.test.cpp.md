---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fibonacci_heap.hpp
    title: fibonacci heap
  - icon: ':question:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':question:'
    path: graph/base.hpp
    title: Graph (CSR format)
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra_fibheap.hpp
    title: graph/dijkstra_fibheap.hpp
  - icon: ':question:'
    path: template/debug_template.hpp
    title: template/debug_template.hpp
  - icon: ':question:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  - icon: ':question:'
    path: template/io.hpp
    title: template/io.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/utility.hpp
    title: template/utility.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"test/graph/fibonacci_heap.test.cpp\"\n#define PROBLEM \\\
    \r\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\r\
    \n\r\n#line 2 \"graph/dijkstra_fibheap.hpp\"\n\r\n#include <limits>\r\n#include\
    \ <vector>\r\n\r\n#line 2 \"data_structure/fibonacci_heap.hpp\"\n\r\n/*\r\n  \
    \  reference:\r\n   http://web.stanford.edu/class/archive/cs/cs166/cs166.1186/lectures/09/Slides09.pdf\r\
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
    \ = default;\n\n    void add_edge(int u, int v, cost_type c) {\n        assert(!prepared\
    \ && u < n && v < n);\n        buff.emplace_back(u, edge_type{u, v, c, m});\n\
    \        edges.emplace_back(edge_type{u, v, c, m++});\n    }\n\n    void add_undirected_edge(int\
    \ u, int v, cost_type c) {\n        assert(!prepared && u < n && v < n);\n   \
    \     buff.emplace_back(u, edge_type{u, v, c, m});\n        buff.emplace_back(v,\
    \ edge_type{v, u, c, m});\n        edges.emplace_back(edge_type{u, v, c, m});\n\
    \        m++;\n    }\n\n    void read_tree(int offset = 1, bool is_weighted =\
    \ false) {\n        read_graph(n - 1, offset, false, is_weighted);\n    }\n\n\
    \    void read_parents(int offset = 1) {\n        for (auto i : std::views::iota(1,\
    \ n)) {\n            int p;\n            std::cin >> p;\n            p -= offset;\n\
    \            add_undirected_edge(p, i, 1);\n        }\n        build();\n    }\n\
    \n    void read_graph(int e, int offset = 1, bool is_directed = false,\n     \
    \               bool is_weighted = false) {\n        for (int i = 0; i < e; i++)\
    \ {\n            int u, v;\n            std::cin >> u >> v;\n            u -=\
    \ offset;\n            v -= offset;\n            if (is_weighted) {\n        \
    \        cost_type c;\n                std::cin >> c;\n                if (is_directed)\
    \ {\n                    add_edge(u, v, c);\n                } else {\n      \
    \              add_undirected_edge(u, v, c);\n                }\n            }\
    \ else {\n                if (is_directed) {\n                    add_edge(u,\
    \ v, 1);\n                } else {\n                    add_undirected_edge(u,\
    \ v, 1);\n                }\n            }\n        }\n        build();\n    }\n\
    \n    void build() {\n        assert(!prepared);\n        csr = simple_csr<edge_type>(n,\
    \ buff);\n        buff.clear();\n        prepared = true;\n    }\n\n    int size()\
    \ const {\n        return n;\n    }\n\n    int node_number() const {\n       \
    \ return n;\n    }\n\n    int edge_number() const {\n        return m;\n    }\n\
    \n    edge_type get_edge(int i) const {\n        assert(prepared);\n        return\
    \ edges[i];\n    }\n\n    std::vector<edge_type> get_edges() const {\n       \
    \ assert(prepared);\n        return edges;\n    }\n\n    const auto operator[](int\
    \ i) const {\n        assert(prepared);\n        return csr[i];\n    }\n    auto\
    \ operator[](int i) {\n        assert(prepared);\n        return csr[i];\n   \
    \ }\n\n  private:\n    int n, m = 0;\n\n    std::vector<std::pair<int, edge_type>>\
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
    \n}  // namespace ebi\n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n\
    \n#define rep(i, a, n) for (int i = (int)(a); i < (int)(n); i++)\n#define rrep(i,\
    \ a, n) for (int i = ((int)(n)-1); i >= (int)(a); i--)\n#define Rep(i, a, n) for\
    \ (i64 i = (i64)(a); i < (i64)(n); i++)\n#define RRep(i, a, n) for (i64 i = ((i64)(n)-i64(1));\
    \ i >= (i64)(a); i--)\n#define all(v) (v).begin(), (v).end()\n#define rall(v)\
    \ (v).rbegin(), (v).rend()\n\n#line 2 \"template/debug_template.hpp\"\n\n#line\
    \ 4 \"template/debug_template.hpp\"\n\nnamespace ebi {\n\n#ifdef LOCAL\n#define\
    \ debug(...)                                                      \\\n    std::cerr\
    \ << \"LINE: \" << __LINE__ << \"  [\" << #__VA_ARGS__ << \"]:\", \\\n       \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\nvoid debug_out()\
    \ {\n    std::cerr << std::endl;\n}\n\ntemplate <typename Head, typename... Tail>\
    \ void debug_out(Head h, Tail... t) {\n    std::cerr << \" \" << h;\n    if (sizeof...(t)\
    \ > 0) std::cerr << \" :\";\n    debug_out(t...);\n}\n\n}  // namespace ebi\n\
    #line 2 \"template/int_alias.hpp\"\n\n#line 4 \"template/int_alias.hpp\"\n\nnamespace\
    \ ebi {\n\nusing ld = long double;\nusing std::size_t;\nusing i8 = std::int8_t;\n\
    using u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing u16 = std::uint16_t;\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    \n}  // namespace ebi\n#line 2 \"template/io.hpp\"\n\n#line 5 \"template/io.hpp\"\
    \n#include <optional>\n#line 7 \"template/io.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <typename T1, typename T2>\nstd::ostream &operator<<(std::ostream &os, const\
    \ std::pair<T1, T2> &pa) {\n    return os << pa.first << \" \" << pa.second;\n\
    }\n\ntemplate <typename T1, typename T2>\nstd::istream &operator>>(std::istream\
    \ &os, std::pair<T1, T2> &pa) {\n    return os >> pa.first >> pa.second;\n}\n\n\
    template <typename T>\nstd::ostream &operator<<(std::ostream &os, const std::vector<T>\
    \ &vec) {\n    for (std::size_t i = 0; i < vec.size(); i++)\n        os << vec[i]\
    \ << (i + 1 == vec.size() ? \"\" : \" \");\n    return os;\n}\n\ntemplate <typename\
    \ T>\nstd::istream &operator>>(std::istream &os, std::vector<T> &vec) {\n    for\
    \ (T &e : vec) std::cin >> e;\n    return os;\n}\n\ntemplate <typename T>\nstd::ostream\
    \ &operator<<(std::ostream &os, const std::optional<T> &opt) {\n    if (opt) {\n\
    \        os << opt.value();\n    } else {\n        os << \"invalid value\";\n\
    \    }\n    return os;\n}\n\nvoid fast_io() {\n    std::cout << std::fixed <<\
    \ std::setprecision(15);\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    }\n\n}  // namespace ebi\n#line 2 \"template/utility.hpp\"\n\n#line 5 \"template/utility.hpp\"\
    \n\n#line 8 \"template/utility.hpp\"\n\nnamespace ebi {\n\ntemplate <class T>\
    \ inline bool chmin(T &a, T b) {\n    if (a > b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n\ntemplate <class T> inline bool chmax(T\
    \ &a, T b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\n\ntemplate <class T> T safe_ceil(T a, T b) {\n    if (a\
    \ % b == 0)\n        return a / b;\n    else if (a >= 0)\n        return (a /\
    \ b) + 1;\n    else\n        return -((-a) / b);\n}\n\ntemplate <class T> T safe_floor(T\
    \ a, T b) {\n    if (a % b == 0)\n        return a / b;\n    else if (a >= 0)\n\
    \        return a / b;\n    else\n        return -((-a) / b) - 1;\n}\n\nconstexpr\
    \ i64 LNF = std::numeric_limits<i64>::max() / 4;\n\nconstexpr int INF = std::numeric_limits<int>::max()\
    \ / 2;\n\nconst std::vector<int> dy = {1, 0, -1, 0, 1, 1, -1, -1};\nconst std::vector<int>\
    \ dx = {0, 1, 0, -1, 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 6 \"test/graph/fibonacci_heap.test.cpp\"\
    \n\r\nnamespace ebi {\r\n\r\nvoid main_() {\r\n    int n, m, r;\r\n    std::cin\
    \ >> n >> m >> r;\r\n    ebi::Graph<i64> g(n);\r\n    g.read_graph(m, 0, true,\
    \ true);\r\n    auto dist = dijkstra_fibheap(r, n, g);\r\n    for (int i = 0;\
    \ i < n; i++) {\r\n        if (dist[i] == std::numeric_limits<i64>::max()) {\r\
    \n            std::cout << \"INF\" << std::endl;\r\n            continue;\r\n\
    \        }\r\n        std::cout << dist[i] << std::endl;\r\n    }\r\n}\r\n\r\n\
    }  // namespace ebi\r\n\r\nint main() {\r\n    ebi::fast_io();\r\n    int t =\
    \ 1;\r\n    // std::cin >> t;\r\n    while (t--) {\r\n        ebi::main_();\r\n\
    \    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \\\r\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \r\n\r\n#include \"../../graph/dijkstra_fibheap.hpp\"\r\n#include \"../../template/template.hpp\"\
    \r\n\r\nnamespace ebi {\r\n\r\nvoid main_() {\r\n    int n, m, r;\r\n    std::cin\
    \ >> n >> m >> r;\r\n    ebi::Graph<i64> g(n);\r\n    g.read_graph(m, 0, true,\
    \ true);\r\n    auto dist = dijkstra_fibheap(r, n, g);\r\n    for (int i = 0;\
    \ i < n; i++) {\r\n        if (dist[i] == std::numeric_limits<i64>::max()) {\r\
    \n            std::cout << \"INF\" << std::endl;\r\n            continue;\r\n\
    \        }\r\n        std::cout << dist[i] << std::endl;\r\n    }\r\n}\r\n\r\n\
    }  // namespace ebi\r\n\r\nint main() {\r\n    ebi::fast_io();\r\n    int t =\
    \ 1;\r\n    // std::cin >> t;\r\n    while (t--) {\r\n        ebi::main_();\r\n\
    \    }\r\n    return 0;\r\n}"
  dependsOn:
  - graph/dijkstra_fibheap.hpp
  - data_structure/fibonacci_heap.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  isVerificationFile: true
  path: test/graph/fibonacci_heap.test.cpp
  requiredBy: []
  timestamp: '2025-03-18 03:40:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/fibonacci_heap.test.cpp
layout: document
redirect_from:
- /verify/test/graph/fibonacci_heap.test.cpp
- /verify/test/graph/fibonacci_heap.test.cpp.html
title: test/graph/fibonacci_heap.test.cpp
---
