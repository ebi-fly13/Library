---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/double_ended_priority_queue.hpp
    title: Double-Ended Priority Queue
  - icon: ':heavy_check_mark:'
    path: data_structure/removable_priority_queue.hpp
    title: Removable Priority Queue
  - icon: ':question:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':question:'
    path: graph/base.hpp
    title: Graph (CSR format)
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
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"test/data_structure/Double-Ended_Priority_Queue.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#line 2 \"data_structure/double_ended_priority_queue.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n#line 2 \"data_structure/removable_priority_queue.hpp\"\n\
    \n#include <functional>\n#include <queue>\n#line 6 \"data_structure/removable_priority_queue.hpp\"\
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
    \ min;\n    removable_priority_queue<T> max;\n};\n\n}  // namespace ebi\n#line\
    \ 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n\n#define rep(i, a, n)\
    \ for (int i = (int)(a); i < (int)(n); i++)\n#define rrep(i, a, n) for (int i\
    \ = ((int)(n)-1); i >= (int)(a); i--)\n#define Rep(i, a, n) for (i64 i = (i64)(a);\
    \ i < (i64)(n); i++)\n#define RRep(i, a, n) for (i64 i = ((i64)(n)-i64(1)); i\
    \ >= (i64)(a); i--)\n#define all(v) (v).begin(), (v).end()\n#define rall(v) (v).rbegin(),\
    \ (v).rend()\n\n#line 2 \"template/debug_template.hpp\"\n\n#line 4 \"template/debug_template.hpp\"\
    \n\nnamespace ebi {\n\n#ifdef LOCAL\n#define debug(...)                      \
    \                                \\\n    std::cerr << \"LINE: \" << __LINE__ <<\
    \ \"  [\" << #__VA_ARGS__ << \"]:\", \\\n        debug_out(__VA_ARGS__)\n#else\n\
    #define debug(...)\n#endif\n\nvoid debug_out() {\n    std::cerr << std::endl;\n\
    }\n\ntemplate <typename Head, typename... Tail> void debug_out(Head h, Tail...\
    \ t) {\n    std::cerr << \" \" << h;\n    if (sizeof...(t) > 0) std::cerr << \"\
    \ :\";\n    debug_out(t...);\n}\n\n}  // namespace ebi\n#line 2 \"template/int_alias.hpp\"\
    \n\n#line 4 \"template/int_alias.hpp\"\n\nnamespace ebi {\n\nusing ld = long double;\n\
    using std::size_t;\nusing i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16\
    \ = std::int16_t;\nusing u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing\
    \ u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n\n}  // namespace ebi\n#line\
    \ 2 \"template/io.hpp\"\n\n#line 5 \"template/io.hpp\"\n#include <optional>\n\
    #line 7 \"template/io.hpp\"\n\nnamespace ebi {\n\ntemplate <typename T1, typename\
    \ T2>\nstd::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &pa)\
    \ {\n    return os << pa.first << \" \" << pa.second;\n}\n\ntemplate <typename\
    \ T1, typename T2>\nstd::istream &operator>>(std::istream &os, std::pair<T1, T2>\
    \ &pa) {\n    return os >> pa.first >> pa.second;\n}\n\ntemplate <typename T>\n\
    std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {\n    for\
    \ (std::size_t i = 0; i < vec.size(); i++)\n        os << vec[i] << (i + 1 ==\
    \ vec.size() ? \"\" : \" \");\n    return os;\n}\n\ntemplate <typename T>\nstd::istream\
    \ &operator>>(std::istream &os, std::vector<T> &vec) {\n    for (T &e : vec) std::cin\
    \ >> e;\n    return os;\n}\n\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream\
    \ &os, const std::optional<T> &opt) {\n    if (opt) {\n        os << opt.value();\n\
    \    } else {\n        os << \"invalid value\";\n    }\n    return os;\n}\n\n\
    void fast_io() {\n    std::cout << std::fixed << std::setprecision(15);\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n}\n\n}  // namespace ebi\n#line 2 \"template/utility.hpp\"\
    \n\n#line 5 \"template/utility.hpp\"\n\n#line 2 \"graph/base.hpp\"\n\n#line 5\
    \ \"graph/base.hpp\"\n#include <ranges>\n#line 7 \"graph/base.hpp\"\n\n#line 2\
    \ \"data_structure/simple_csr.hpp\"\n\n#line 6 \"data_structure/simple_csr.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class E> struct simple_csr {\n    simple_csr()\
    \ = default;\n\n    simple_csr(int n, const std::vector<std::pair<int, E>>& elements)\n\
    \        : start(n + 1, 0), elist(elements.size()) {\n        for (auto e : elements)\
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
    \ assert(!prepared);\n        return edges;\n    }\n\n    const auto operator[](int\
    \ i) const {\n        assert(prepared);\n        return csr[i];\n    }\n    auto\
    \ operator[](int i) {\n        assert(prepared);\n        return csr[i];\n   \
    \ }\n\n  private:\n    int n, m = 0;\n\n    std::vector<std::pair<int, edge_type>>\
    \ buff;\n\n    std::vector<edge_type> edges;\n    simple_csr<edge_type> csr;\n\
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 8 \"template/utility.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> inline bool chmin(T &a, T b) {\n   \
    \ if (a > b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\n\ntemplate <class T> inline bool chmax(T &a, T b) {\n    if (a < b) {\n   \
    \     a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate <class\
    \ T> T safe_ceil(T a, T b) {\n    if (a % b == 0)\n        return a / b;\n   \
    \ else if (a >= 0)\n        return (a / b) + 1;\n    else\n        return -((-a)\
    \ / b);\n}\n\ntemplate <class T> T safe_floor(T a, T b) {\n    if (a % b == 0)\n\
    \        return a / b;\n    else if (a >= 0)\n        return a / b;\n    else\n\
    \        return -((-a) / b) - 1;\n}\n\nconstexpr i64 LNF = std::numeric_limits<i64>::max()\
    \ / 4;\n\nconstexpr int INF = std::numeric_limits<int>::max() / 2;\n\nconst std::vector<int>\
    \ dy = {1, 0, -1, 0, 1, 1, -1, -1};\nconst std::vector<int> dx = {0, 1, 0, -1,\
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 5 \"test/data_structure/Double-Ended_Priority_Queue.test.cpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    int n, q;\n    std::cin >> n >> q;\n\
    \    std::vector<int> s(n);\n    std::cin >> s;\n    double_ended_priority_queue<int>\
    \ que(s.begin(), s.end());\n    while (q--) {\n        int t;\n        std::cin\
    \ >> t;\n        if (t == 0) {\n            int x;\n            std::cin >> x;\n\
    \            que.push(x);\n        } else if (t == 1) {\n            std::cout\
    \ << que.get_min() << '\\n';\n            que.pop_min();\n        } else {\n \
    \           std::cout << que.get_max() << '\\n';\n            que.pop_max();\n\
    \        }\n    }\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n\
    \    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include \"../../data_structure/double_ended_priority_queue.hpp\"\n#include\
    \ \"../../template/template.hpp\"\n\nnamespace ebi {\n\nvoid main_() {\n    int\
    \ n, q;\n    std::cin >> n >> q;\n    std::vector<int> s(n);\n    std::cin >>\
    \ s;\n    double_ended_priority_queue<int> que(s.begin(), s.end());\n    while\
    \ (q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0) {\n   \
    \         int x;\n            std::cin >> x;\n            que.push(x);\n     \
    \   } else if (t == 1) {\n            std::cout << que.get_min() << '\\n';\n \
    \           que.pop_min();\n        } else {\n            std::cout << que.get_max()\
    \ << '\\n';\n            que.pop_max();\n        }\n    }\n}\n\n}  // namespace\
    \ ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n    // std::cin >>\
    \ t;\n    while (t--) {\n        ebi::main_();\n    }\n    return 0;\n}"
  dependsOn:
  - data_structure/double_ended_priority_queue.hpp
  - data_structure/removable_priority_queue.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: true
  path: test/data_structure/Double-Ended_Priority_Queue.test.cpp
  requiredBy: []
  timestamp: '2025-03-18 01:14:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Double-Ended_Priority_Queue.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Double-Ended_Priority_Queue.test.cpp
- /verify/test/data_structure/Double-Ended_Priority_Queue.test.cpp.html
title: test/data_structure/Double-Ended_Priority_Queue.test.cpp
---
