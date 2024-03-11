---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bellman_ford.hpp
    title: Bellman-Ford
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"test/aoj/aoj_grl_1_b.test.cpp\"\n#define PROBLEM \\\n  \
    \  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\n\n#line\
    \ 2 \"graph/bellman_ford.hpp\"\n\n#include <cassert>\n#include <limits>\n#include\
    \ <ranges>\n#include <tuple>\n#include <utility>\n#include <vector>\n\n#line 2\
    \ \"graph/template.hpp\"\n\r\n#line 4 \"graph/template.hpp\"\n#include <iostream>\r\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class T> struct Edge {\r\n    int to;\r\
    \n    T cost;\r\n    Edge(int _to, T _cost = 1) : to(_to), cost(_cost) {}\r\n\
    };\r\n\r\ntemplate <class T> struct Graph : std::vector<std::vector<Edge<T>>>\
    \ {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\n    void add_edge(int\
    \ u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if (directed) return;\r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if (directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n\r\n    void read_tree(int\
    \ offset = 1) {\r\n        read_graph((int)size()-1, offset);\r\n    }\r\n\r\n\
    \    void read_graph(int m, int offset = 1, bool directed = false) {\r\n     \
    \   for(int i = 0; i < m; i++) {\r\n            int u,v;\r\n            std::cin\
    \ >> u >> v;\r\n            u -= offset;\r\n            v -= offset;\r\n     \
    \       add_edge(u, v, directed);\r\n        }\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\n#line 11 \"graph/bellman_ford.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ T> std::vector<T> bellman_ford(int s, const Graph<T> &g) {\n    int n = (int)g.size();\n\
    \    assert(0 <= s && s < n);\n    std::vector<T> dist(n, std::numeric_limits<T>::max());\n\
    \    dist[s] = 0;\n    std::vector<std::tuple<int, int, T>> edges;\n    for (auto\
    \ from : std::views::iota(0, n)) {\n        for (auto [to, cost] : g[from]) {\n\
    \            edges.emplace_back(from, to, cost);\n        }\n    }\n    for (auto\
    \ i : std::views::iota(0, n)) {\n        for (auto [from, to, cost] : edges) {\n\
    \            if (dist[from] == std::numeric_limits<T>::max()) continue;\n    \
    \        if (dist[from] + cost < dist[to]) {\n                dist[to] = dist[from]\
    \ + cost;\n                if (i == n - 1) {\n                    return {};\n\
    \                }\n            }\n        }\n    }\n    return dist;\n}\n\n}\
    \  // namespace ebi\n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n\
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
    \ dx = {0, 1, 0, -1, 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 6 \"test/aoj/aoj_grl_1_b.test.cpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    int v, e, r;\n    std::cin >> v >>\
    \ e >> r;\n    Graph<i64> g(v);\n    rep(i, 0, e) {\n        int s, t;\n     \
    \   i64 d;\n        std::cin >> s >> t >> d;\n        g.add_edge(s, t, d, true);\n\
    \    }\n    auto d = bellman_ford(r, g);\n    if (d.empty()) {\n        std::cout\
    \ << \"NEGATIVE CYCLE\\n\";\n    } else {\n        for (auto c : d) {\n      \
    \      if (c == std::numeric_limits<i64>::max()) {\n                std::cout\
    \ << \"INF\\n\";\n            } else {\n                std::cout << c << '\\\
    n';\n            }\n        }\n    }\n}\n\n}  // namespace ebi\n\nint main() {\n\
    \    ebi::fast_io();\n    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n\
    \        ebi::main_();\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include \"../../graph/bellman_ford.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    int v, e, r;\n    std::cin >> v >>\
    \ e >> r;\n    Graph<i64> g(v);\n    rep(i, 0, e) {\n        int s, t;\n     \
    \   i64 d;\n        std::cin >> s >> t >> d;\n        g.add_edge(s, t, d, true);\n\
    \    }\n    auto d = bellman_ford(r, g);\n    if (d.empty()) {\n        std::cout\
    \ << \"NEGATIVE CYCLE\\n\";\n    } else {\n        for (auto c : d) {\n      \
    \      if (c == std::numeric_limits<i64>::max()) {\n                std::cout\
    \ << \"INF\\n\";\n            } else {\n                std::cout << c << '\\\
    n';\n            }\n        }\n    }\n}\n\n}  // namespace ebi\n\nint main() {\n\
    \    ebi::fast_io();\n    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n\
    \        ebi::main_();\n    }\n    return 0;\n}"
  dependsOn:
  - graph/bellman_ford.hpp
  - graph/template.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  isVerificationFile: true
  path: test/aoj/aoj_grl_1_b.test.cpp
  requiredBy: []
  timestamp: '2024-03-11 15:33:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/aoj_grl_1_b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/aoj_grl_1_b.test.cpp
- /verify/test/aoj/aoj_grl_1_b.test.cpp.html
title: test/aoj/aoj_grl_1_b.test.cpp
---
