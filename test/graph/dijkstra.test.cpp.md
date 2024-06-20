---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: Graph (CSR format)
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: dijkstra
  - icon: ':heavy_check_mark:'
    path: template/debug_template.hpp
    title: template/debug_template.hpp
  - icon: ':heavy_check_mark:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  - icon: ':heavy_check_mark:'
    path: template/io.hpp
    title: template/io.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/utility.hpp
    title: template/utility.hpp
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
  bundledCode: "#line 1 \"test/graph/dijkstra.test.cpp\"\n#define PROBLEM \\\r\n \
    \   \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\r\n\r\
    \n#line 2 \"graph/dijkstra.hpp\"\n\r\n#include <algorithm>\r\n#include <limits>\r\
    \n#include <queue>\r\n#include <vector>\r\n\r\n#line 2 \"graph/base.hpp\"\n\n\
    #include <cassert>\n#include <iostream>\n#include <ranges>\n#line 7 \"graph/base.hpp\"\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 9 \"graph/dijkstra.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class T> std::vector<T> dijkstra(int s,\
    \ const Graph<T> &g) {\r\n    typedef std::pair<T, int> P;\r\n    int n = g.node_number();\r\
    \n    std::vector<T> d(n, std::numeric_limits<T>::max());\r\n    std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> que;\r\n    que.push(P(0, s));\r\n    d[s]\
    \ = 0;\r\n    while (!que.empty()) {\r\n        auto [ret, v] = que.top();\r\n\
    \        que.pop();\r\n        if (d[v] < ret) continue;\r\n        for (auto\
    \ e : g[v]) {\r\n            if (d[e.to] > d[v] + e.cost) {\r\n              \
    \  d[e.to] = d[v] + e.cost;\r\n                que.push(P(d[e.to], e.to));\r\n\
    \            }\r\n        }\r\n    }\r\n    return d;\r\n}\r\n\r\ntemplate <class\
    \ T> struct dijkstra_path {\r\n  public:\r\n    dijkstra_path(int s_, const Graph<T>\
    \ &g)\r\n        : s(s_),\r\n          dist(g.size(), std::numeric_limits<T>::max()),\r\
    \n          prev(g.size(), -1) {\r\n        dist[s] = 0;\r\n        using P =\
    \ std::pair<T, int>;\r\n        std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ que;\r\n        que.push(P(0, s));\r\n        while (!que.empty()) {\r\n   \
    \         auto [ret, v] = que.top();\r\n            que.pop();\r\n           \
    \ if (dist[v] < ret) continue;\r\n            for (auto e : g[v]) {\r\n      \
    \          if (dist[e.to] > dist[v] + e.cost) {\r\n                    dist[e.to]\
    \ = dist[v] + e.cost;\r\n                    prev[e.to] = v;\r\n             \
    \       que.push(P(dist[e.to], e.to));\r\n                }\r\n            }\r\
    \n        }\r\n    }\r\n\r\n    std::pair<T, std::vector<int>> shortest_path(int\
    \ v) const {\r\n        if (dist[v] == std::numeric_limits<T>::max()) return {dist[v],\
    \ {}};\r\n        std::vector<int> path;\r\n        int u = v;\r\n        while\
    \ (u != s) {\r\n            path.emplace_back(u);\r\n            u = prev[u];\r\
    \n        }\r\n        path.emplace_back(u);\r\n        std::reverse(path.begin(),\
    \ path.end());\r\n        return {dist[v], path};\r\n    }\r\n\r\n  private:\r\
    \n    int s;\r\n    std::vector<T> dist;\r\n    std::vector<int> prev;\r\n};\r\
    \n\r\n}  // namespace ebi\n#line 5 \"test/graph/dijkstra.test.cpp\"\n\r\n#line\
    \ 9 \"test/graph/dijkstra.test.cpp\"\n\r\n#line 1 \"template/template.hpp\"\n\
    #include <bits/stdc++.h>\n\n#define rep(i, a, n) for (int i = (int)(a); i < (int)(n);\
    \ i++)\n#define rrep(i, a, n) for (int i = ((int)(n)-1); i >= (int)(a); i--)\n\
    #define Rep(i, a, n) for (i64 i = (i64)(a); i < (i64)(n); i++)\n#define RRep(i,\
    \ a, n) for (i64 i = ((i64)(n)-i64(1)); i >= (i64)(a); i--)\n#define all(v) (v).begin(),\
    \ (v).end()\n#define rall(v) (v).rbegin(), (v).rend()\n\n#line 2 \"template/debug_template.hpp\"\
    \n\n#line 4 \"template/debug_template.hpp\"\n\nnamespace ebi {\n\n#ifdef LOCAL\n\
    #define debug(...)                                                      \\\n \
    \   std::cerr << \"LINE: \" << __LINE__ << \"  [\" << #__VA_ARGS__ << \"]:\",\
    \ \\\n        debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\nvoid\
    \ debug_out() {\n    std::cerr << std::endl;\n}\n\ntemplate <typename Head, typename...\
    \ Tail> void debug_out(Head h, Tail... t) {\n    std::cerr << \" \" << h;\n  \
    \  if (sizeof...(t) > 0) std::cerr << \" :\";\n    debug_out(t...);\n}\n\n}  //\
    \ namespace ebi\n#line 2 \"template/int_alias.hpp\"\n\n#line 4 \"template/int_alias.hpp\"\
    \n\nnamespace ebi {\n\nusing ld = long double;\nusing std::size_t;\nusing i8 =\
    \ std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing u16\
    \ = std::uint16_t;\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing\
    \ i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\n}  // namespace ebi\n#line 2 \"template/io.hpp\"\n\
    \n#line 5 \"template/io.hpp\"\n#include <optional>\n#line 7 \"template/io.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <typename T1, typename T2>\nstd::ostream &operator<<(std::ostream\
    \ &os, const std::pair<T1, T2> &pa) {\n    return os << pa.first << \" \" << pa.second;\n\
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
    \ dx = {0, 1, 0, -1, 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 11 \"test/graph/dijkstra.test.cpp\"\
    \n\r\nusing ebi::i64;\r\n\r\nint main() {\r\n    int v, e, r;\r\n    std::cin\
    \ >> v >> e >> r;\r\n    ebi::Graph<i64> g(v);\r\n    g.read_graph(e, 0, true,\
    \ true);\r\n    std::vector<i64> dest = ebi::dijkstra(r, g);\r\n    for (auto\
    \ di : dest) {\r\n        if (di == std::numeric_limits<i64>::max()) {\r\n   \
    \         std::cout << \"INF\" << std::endl;\r\n            continue;\r\n    \
    \    }\r\n        std::cout << di << std::endl;\r\n    }\r\n}\n"
  code: "#define PROBLEM \\\r\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \r\n\r\n#include \"../../graph/dijkstra.hpp\"\r\n\r\n#include <iostream>\r\n#include\
    \ <limits>\r\n#include <vector>\r\n\r\n#include \"../../template/template.hpp\"\
    \r\n\r\nusing ebi::i64;\r\n\r\nint main() {\r\n    int v, e, r;\r\n    std::cin\
    \ >> v >> e >> r;\r\n    ebi::Graph<i64> g(v);\r\n    g.read_graph(e, 0, true,\
    \ true);\r\n    std::vector<i64> dest = ebi::dijkstra(r, g);\r\n    for (auto\
    \ di : dest) {\r\n        if (di == std::numeric_limits<i64>::max()) {\r\n   \
    \         std::cout << \"INF\" << std::endl;\r\n            continue;\r\n    \
    \    }\r\n        std::cout << di << std::endl;\r\n    }\r\n}"
  dependsOn:
  - graph/dijkstra.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  isVerificationFile: true
  path: test/graph/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2024-06-20 20:05:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/test/graph/dijkstra.test.cpp
- /verify/test/graph/dijkstra.test.cpp.html
title: test/graph/dijkstra.test.cpp
---
