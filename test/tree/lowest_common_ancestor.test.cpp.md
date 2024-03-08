---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  - icon: ':heavy_check_mark:'
    path: tree/lowest_common_ancestor.hpp
    title: Lowest Common Ancestor
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/tree/lowest_common_ancestor.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\r\n\r\n#line 2 \"tree/lowest_common_ancestor.hpp\"\
    \n\r\n#include <vector>\r\n\r\n#line 2 \"data_structure/sparse_table.hpp\"\n\r\
    \n#line 4 \"data_structure/sparse_table.hpp\"\n\r\n/*\r\n    reference: https://scrapbox.io/data-structures/Sparse_Table\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class Band, Band (*op)(Band, Band)>\
    \ struct sparse_table {\r\n  public:\r\n    sparse_table() = default;\r\n\r\n\
    \    sparse_table(const std::vector<Band> &a) : n(a.size()) {\r\n        table\
    \ = std::vector(std::__lg(n) + 1, std::vector<Band>(n));\r\n        for (int i\
    \ = 0; i < n; i++) {\r\n            table[0][i] = a[i];\r\n        }\r\n     \
    \   for (int k = 1; (1 << k) <= n; k++) {\r\n            for (int i = 0; i + (1\
    \ << k) <= n; i++) {\r\n                table[k][i] =\r\n                    op(table[k\
    \ - 1][i], table[k - 1][i + (1 << (k - 1))]);\r\n            }\r\n        }\r\n\
    \    }\r\n\r\n    void build(const std::vector<Band> &a) {\r\n        n = (int)a.size();\r\
    \n        table = std::vector(std::__lg(n) + 1, std::vector<Band>(n));\r\n   \
    \     for (int i = 0; i < n; i++) {\r\n            table[0][i] = a[i];\r\n   \
    \     }\r\n        for (int k = 1; (1 << k) <= n; k++) {\r\n            for (int\
    \ i = 0; i + (1 << k) <= n; i++) {\r\n                table[k][i] =\r\n      \
    \              op(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);\r\n    \
    \        }\r\n        }\r\n    }\r\n\r\n    // [l, r)\r\n    Band fold(int l,\
    \ int r) {\r\n        int k = std::__lg(r - l);\r\n        return op(table[k][l],\
    \ table[k][r - (1 << k)]);\r\n    }\r\n\r\n  private:\r\n    int n;\r\n    std::vector<std::vector<Band>>\
    \ table;\r\n};\r\n\r\n}  // namespace ebi\n#line 6 \"tree/lowest_common_ancestor.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\nnamespace internal_lca {\r\nstd::pair<int, int> op(std::pair<int,\
    \ int> a, std::pair<int, int> b) {\r\n    return a.second < b.second ? a : b;\r\
    \n}\r\n}  // namespace internal_lca\r\n\r\nstruct lowest_common_ancestor {\r\n\
    \  public:\r\n    lowest_common_ancestor(const std::vector<std::vector<int>> &gh,\r\
    \n                           int root = 0)\r\n        : n(gh.size()), id(n), depth(n)\
    \ {\r\n        auto dfs = [&](auto &&self, int v, int par = -1, int d = 0) ->\
    \ void {\r\n            id[v] = int(vs.size());\r\n            depth[v] = d;\r\
    \n            vs.emplace_back(v, d);\r\n            for (const auto &nv : gh[v])\r\
    \n                if (nv != par) {\r\n                    self(self, nv, v, d\
    \ + 1);\r\n                    vs.emplace_back(v, d);\r\n                }\r\n\
    \        };\r\n        dfs(dfs, root);\r\n        st.build(vs);\r\n    }\r\n\r\
    \n    int lca(int u, int v) {\r\n        int l = id[u], r = id[v];\r\n       \
    \ if (r < l) std::swap(l, r);\r\n        return st.fold(l, r + 1).first;\r\n \
    \   }\r\n\r\n    int distance(int u, int v) {\r\n        int w = lca(u, v);\r\n\
    \        return depth[u] + depth[v] - 2 * depth[w];\r\n    }\r\n\r\n  private:\r\
    \n    int n;\r\n    std::vector<int> id, depth;\r\n    std::vector<std::pair<int,\
    \ int>> vs;\r\n    sparse_table<std::pair<int, int>, internal_lca::op> st;\r\n\
    };\r\n\r\n}  // namespace ebi\n#line 4 \"test/tree/lowest_common_ancestor.test.cpp\"\
    \n\r\n#include <iostream>\r\n\r\n#line 2 \"graph/template.hpp\"\n\r\n#line 5 \"\
    graph/template.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate <class T> struct Edge\
    \ {\r\n    int to;\r\n    T cost;\r\n    Edge(int _to, T _cost = 1) : to(_to),\
    \ cost(_cost) {}\r\n};\r\n\r\ntemplate <class T> struct Graph : std::vector<std::vector<Edge<T>>>\
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
    \ ebi\n#line 8 \"test/tree/lowest_common_ancestor.test.cpp\"\n\r\nint main() {\r\
    \n    int n, q;\r\n    std::cin >> n >> q;\r\n    ebi::graph g(n);\r\n    for\
    \ (int i = 1; i < n; i++) {\r\n        int p;\r\n        std::cin >> p;\r\n  \
    \      g.add_edge(p, i);\r\n    }\r\n    ebi::lowest_common_ancestor lca(g);\r\
    \n    while (q--) {\r\n        int u, v;\r\n        std::cin >> u >> v;\r\n  \
    \      std::cout << lca.lca(u, v) << '\\n';\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\r\n\r\n#include \"\
    ../../tree/lowest_common_ancestor.hpp\"\r\n\r\n#include <iostream>\r\n\r\n#include\
    \ \"../../graph/template.hpp\"\r\n\r\nint main() {\r\n    int n, q;\r\n    std::cin\
    \ >> n >> q;\r\n    ebi::graph g(n);\r\n    for (int i = 1; i < n; i++) {\r\n\
    \        int p;\r\n        std::cin >> p;\r\n        g.add_edge(p, i);\r\n   \
    \ }\r\n    ebi::lowest_common_ancestor lca(g);\r\n    while (q--) {\r\n      \
    \  int u, v;\r\n        std::cin >> u >> v;\r\n        std::cout << lca.lca(u,\
    \ v) << '\\n';\r\n    }\r\n}"
  dependsOn:
  - tree/lowest_common_ancestor.hpp
  - data_structure/sparse_table.hpp
  - graph/template.hpp
  isVerificationFile: true
  path: test/tree/lowest_common_ancestor.test.cpp
  requiredBy: []
  timestamp: '2024-03-08 14:06:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/lowest_common_ancestor.test.cpp
layout: document
redirect_from:
- /verify/test/tree/lowest_common_ancestor.test.cpp
- /verify/test/tree/lowest_common_ancestor.test.cpp.html
title: test/tree/lowest_common_ancestor.test.cpp
---
