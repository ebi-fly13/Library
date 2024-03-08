---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/template.hpp
    title: graph/template.hpp
  - icon: ':question:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  - icon: ':x:'
    path: tree/tree_diameter.hpp
    title: Tree Diameter
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/tree/Tree_Diameter.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\
    \n\n#line 2 \"tree/tree_diameter.hpp\"\n\n#include <algorithm>\n#include <vector>\n\
    \n#line 2 \"graph/template.hpp\"\n\r\n#line 4 \"graph/template.hpp\"\n#include\
    \ <iostream>\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class T> struct Edge {\r\n\
    \    int to;\r\n    T cost;\r\n    Edge(int _to, T _cost = 1) : to(_to), cost(_cost)\
    \ {}\r\n};\r\n\r\ntemplate <class T> struct Graph : std::vector<std::vector<Edge<T>>>\
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
    \ ebi\n#line 7 \"tree/tree_diameter.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ T>\nstd::pair<T, std::vector<int>> tree_diameter(const Graph<T> &g) {\n    int\
    \ n = g.size();\n    std::vector<T> dp(n);\n    std::vector<int> par(n, -1);\n\
    \    dp[0] = 0;\n    auto dfs = [&](auto &&self, int v) -> void {\n        for\
    \ (const auto &[nv, cost] : g[v]) {\n            if (nv == par[v]) continue;\n\
    \            par[nv] = v;\n            dp[nv] = dp[v] + cost;\n            self(self,\
    \ nv);\n        }\n    };\n    dfs(dfs, 0);\n    int u = std::max_element(dp.begin(),\
    \ dp.end()) - dp.begin();\n    par[u] = -1;\n    dp[u] = 0;\n    dfs(dfs, u);\n\
    \    int v = std::max_element(dp.begin(), dp.end()) - dp.begin();\n    std::vector<int>\
    \ path;\n    while (u != v) {\n        path.emplace_back(v);\n        v = par[v];\n\
    \    }\n    path.emplace_back(u);\n    return {dp[*path.begin()], path};\n}\n\n\
    std::pair<int, std::vector<int>> tree_diameter(const graph &g) {\n    int n =\
    \ g.size();\n    std::vector<int> dp(n);\n    std::vector<int> par(n, -1);\n \
    \   dp[0] = 0;\n    auto dfs = [&](auto &&self, int v) -> void {\n        for\
    \ (const auto &nv : g[v]) {\n            if (nv == par[v]) continue;\n       \
    \     par[nv] = v;\n            dp[nv] = dp[v] + 1;\n            self(self, nv);\n\
    \        }\n    };\n    dfs(dfs, 0);\n    int u = std::max_element(dp.begin(),\
    \ dp.end()) - dp.begin();\n    par[u] = -1;\n    dp[u] = 0;\n    dfs(dfs, u);\n\
    \    int v = std::max_element(dp.begin(), dp.end()) - dp.begin();\n    std::vector<int>\
    \ path;\n    while (u != v) {\n        path.emplace_back(v);\n        v = par[v];\n\
    \    }\n    path.emplace_back(u);\n    return {dp[*path.begin()], path};\n}\n\n\
    }  // namespace ebi\n#line 4 \"test/tree/Tree_Diameter.test.cpp\"\n\n#line 6 \"\
    test/tree/Tree_Diameter.test.cpp\"\n\n#line 2 \"template/int_alias.hpp\"\n\n#include\
    \ <cstdint>\n\nnamespace ebi {\n\nusing ld = long double;\nusing std::size_t;\n\
    using i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\n\
    using u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\n}  // namespace ebi\n#line 9 \"test/tree/Tree_Diameter.test.cpp\"\
    \n\nusing ebi::i64;\n\nint main() {\n    int n;\n    std::cin >> n;\n    ebi::Graph<i64>\
    \ g(n);\n    for (int i = 0; i < n - 1; i++) {\n        int a, b;\n        i64\
    \ c;\n        std::cin >> a >> b >> c;\n        g.add_edge(a, b, c);\n    }\n\
    \    auto [x, path] = ebi::tree_diameter(g);\n    std::cout << x << \" \" << path.size()\
    \ << '\\n';\n    for (auto v : path) {\n        std::cout << v << \" \";\n   \
    \ }\n    std::cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ \"../../tree/tree_diameter.hpp\"\n\n#include <iostream>\n\n#include \"../../graph/template.hpp\"\
    \n#include \"../../template/int_alias.hpp\"\n\nusing ebi::i64;\n\nint main() {\n\
    \    int n;\n    std::cin >> n;\n    ebi::Graph<i64> g(n);\n    for (int i = 0;\
    \ i < n - 1; i++) {\n        int a, b;\n        i64 c;\n        std::cin >> a\
    \ >> b >> c;\n        g.add_edge(a, b, c);\n    }\n    auto [x, path] = ebi::tree_diameter(g);\n\
    \    std::cout << x << \" \" << path.size() << '\\n';\n    for (auto v : path)\
    \ {\n        std::cout << v << \" \";\n    }\n    std::cout << '\\n';\n}"
  dependsOn:
  - tree/tree_diameter.hpp
  - graph/template.hpp
  - template/int_alias.hpp
  isVerificationFile: true
  path: test/tree/Tree_Diameter.test.cpp
  requiredBy: []
  timestamp: '2024-03-08 14:06:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/tree/Tree_Diameter.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Tree_Diameter.test.cpp
- /verify/test/tree/Tree_Diameter.test.cpp.html
title: test/tree/Tree_Diameter.test.cpp
---
