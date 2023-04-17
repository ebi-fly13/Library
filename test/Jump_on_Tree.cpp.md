---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: data_structure/sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  - icon: ':warning:'
    path: tree/level_ancestor.hpp
    title: tree/level_ancestor.hpp
  - icon: ':heavy_check_mark:'
    path: tree/lowest_common_ancestor.hpp
    title: tree/lowest_common_ancestor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/jump_on_tree
  bundledCode: "#line 1 \"test/Jump_on_Tree.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\
    \r\n\r\n#line 2 \"tree/level_ancestor.hpp\"\n\r\n#include <vector>\r\n#include\
    \ <algorithm>\r\n#include <cassert>\r\n\r\nnamespace ebi {\r\n\r\nstruct level_ancestor\
    \ {\r\nprivate:\r\n    int n;\r\n    std::vector<int> in;\r\n    std::vector<int>\
    \ inv_in;\r\n    std::vector<int> depths;\r\n    std::vector<std::vector<int>>\
    \ s;\r\npublic:\r\n    level_ancestor(const std::vector<std::vector<int>> &gh,\
    \ int root = 0) : n(gh.size()), in(n), inv_in(n), depths(n) {\r\n        int cnt\
    \ = 0;\r\n        int max = 0;\r\n        auto dfs = [&](auto &&self, int v, int\
    \ par = -1) -> void {\r\n            inv_in[cnt] = v;\r\n            in[v] = cnt++;\r\
    \n            max = std::max(max, depths[v]);\r\n            for(auto nv: gh[v])\
    \ if(nv != par) {\r\n                depths[nv] = depths[v] + 1;\r\n         \
    \       self(self, nv, v);\r\n            }\r\n        };\r\n        dfs(dfs,\
    \ root);\r\n        s.resize(max+1);\r\n        for(int i = 0; i < n; i++) {\r\
    \n            int u = inv_in[i];\r\n            s[depths[u]].emplace_back(i);\r\
    \n        }\r\n    }\r\n\r\n    int query(int u, int k) const {\r\n        int\
    \ m = depths[u] - k;\r\n        assert(m >= 0);\r\n        return inv_in[*std::prev(std::upper_bound(s[m].begin(),\
    \ s[m].end(), in[u]))];\r\n    }\r\n\r\n    int depth(int u) const {\r\n     \
    \   return depths[u];\r\n    }\r\n};\r\n\r\n}\n#line 2 \"tree/lowest_common_ancestor.hpp\"\
    \n\r\n#line 4 \"tree/lowest_common_ancestor.hpp\"\n\r\n#line 2 \"data_structure/sparse_table.hpp\"\
    \n\r\n#line 4 \"data_structure/sparse_table.hpp\"\n\r\n/*\r\n    reference: https://scrapbox.io/data-structures/Sparse_Table\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class Band, Band (*op)(Band, Band)>\r\
    \nstruct sparse_table {\r\npublic:\r\n    sparse_table() = default;\r\n\r\n  \
    \  sparse_table(const std::vector<Band> &a) : n(a.size()) {\r\n        table =\
    \ std::vector(std::__lg(n) + 1, std::vector<Band>(n));\r\n        for(int i =\
    \ 0; i < n; i++) {\r\n            table[0][i] = a[i];\r\n        }\r\n       \
    \ for(int k = 1; (1<<k) <= n; k++) {\r\n            for(int i = 0; i + (1<<k)\
    \ <= n; i++) {\r\n                table[k][i] = op(table[k-1][i], table[k-1][i\
    \ + (1<<(k-1))]);\r\n            }\r\n        }\r\n    }\r\n\r\n    void build(const\
    \ std::vector<Band> &a) {\r\n        n = (int)a.size();\r\n        table = std::vector(std::__lg(n)\
    \ + 1, std::vector<Band>(n));\r\n        for(int i = 0; i < n; i++) {\r\n    \
    \        table[0][i] = a[i];\r\n        }\r\n        for(int k = 1; (1<<k) <=\
    \ n; k++) {\r\n            for(int i = 0; i + (1<<k) <= n; i++) {\r\n        \
    \        table[k][i] = op(table[k-1][i], table[k-1][i + (1<<(k-1))]);\r\n    \
    \        }\r\n        }\r\n    }\r\n\r\n    // [l, r)\r\n    Band fold(int l,\
    \ int r) {\r\n        int k = std::__lg(r-l);\r\n        return op(table[k][l],\
    \ table[k][r-(1<<k)]);\r\n    }\r\nprivate:\r\n    int n;\r\n    std::vector<std::vector<Band>>\
    \ table;\r\n};\r\n\r\n}\n#line 6 \"tree/lowest_common_ancestor.hpp\"\n\r\nnamespace\
    \ ebi {\r\n\r\nnamespace internal_lca {\r\n    std::pair<int,int> op(std::pair<int,int>\
    \ a, std::pair<int,int> b) {\r\n        return a.second < b.second ? a : b;\r\n\
    \    }\r\n}\r\n\r\nstruct lowest_common_ancestor {\r\npublic:\r\n    lowest_common_ancestor(const\
    \ std::vector<std::vector<int>> &gh, int root = 0) : n(gh.size()), id(n), depth(n)\
    \  {\r\n        auto dfs = [&](auto &&self, int v, int par = -1, int d = 0) ->\
    \ void {\r\n            id[v] = int(vs.size());\r\n            depth[v] = d;\r\
    \n            vs.emplace_back(v, d);\r\n            for(const auto &nv: gh[v])\
    \ if(nv != par) {\r\n                self(self, nv, v, d+1);\r\n             \
    \   vs.emplace_back(v, d);\r\n            }\r\n        };\r\n        dfs(dfs,\
    \ root);\r\n        st.build(vs);\r\n    }\r\n\r\n    int lca(int u, int v) {\r\
    \n        int l = id[u], r = id[v];\r\n        if(r < l) std::swap(l, r);\r\n\
    \        return st.fold(l, r+1).first;\r\n    }\r\n\r\n    int distance(int u,\
    \ int v) {\r\n        int w = lca(u, v);\r\n        return depth[u] + depth[v]\
    \ - 2 * depth[w];\r\n    }\r\n\r\nprivate:\r\n    int n;\r\n    std::vector<int>\
    \ id, depth;\r\n    std::vector<std::pair<int,int>> vs;\r\n    sparse_table<std::pair<int,int>,\
    \ internal_lca::op> st;\r\n};\r\n\r\n}\n#line 2 \"graph/template.hpp\"\n\r\n#line\
    \ 4 \"graph/template.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate<class T>\r\nstruct\
    \ Edge {\r\n    int to;\r\n    T cost;\r\n    Edge(int _to, T _cost=1) : to(_to),\
    \ cost(_cost) { }\r\n};\r\n\r\ntemplate<class T>\r\nstruct Graph : std::vector<std::vector<Edge<T>>>\
    \ {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\n    void add_edge(int\
    \ u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if(directed) return; \r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if(directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n} // namespace\
    \ ebi\n#line 6 \"test/Jump_on_Tree.cpp\"\n\r\n#include <iostream>\r\n\r\nint main()\
    \ {\r\n    int n,q;\r\n    std::cin >> n >> q;\r\n    ebi::graph g(n);\r\n   \
    \ for(int i = 0; i < n-1; i++) {\r\n        int a,b;\r\n        std::cin >> a\
    \ >> b;\r\n        g.add_edge(a, b);\r\n    }\r\n    ebi::level_ancestor la(g);\r\
    \n    ebi::lowest_common_ancestor lca(g);\r\n    while(q--) {\r\n        int s,t,i;\r\
    \n        std::cin >> s >> t >> i;\r\n        int d = lca.distance(s, t);\r\n\
    \        if(i > d) {\r\n            std::cout << \"-1\\n\";\r\n            continue;\r\
    \n        }\r\n        int m = lca.lca(s, t);\r\n        int ans;\r\n        if(i\
    \ <= lca.distance(m, s)) {\r\n            ans = la.query(s, i);\r\n        }\r\
    \n        else {\r\n            i = d - i;\r\n            assert(i <= lca.distance(m,\
    \ t));\r\n            ans = la.query(t, i);\r\n        }\r\n        std::cout\
    \ << ans << std::endl;\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\r\n\r\n\
    #include \"tree/level_ancestor.hpp\"\r\n#include \"tree/lowest_common_ancestor.hpp\"\
    \r\n#include \"graph/template.hpp\"\r\n\r\n#include <iostream>\r\n\r\nint main()\
    \ {\r\n    int n,q;\r\n    std::cin >> n >> q;\r\n    ebi::graph g(n);\r\n   \
    \ for(int i = 0; i < n-1; i++) {\r\n        int a,b;\r\n        std::cin >> a\
    \ >> b;\r\n        g.add_edge(a, b);\r\n    }\r\n    ebi::level_ancestor la(g);\r\
    \n    ebi::lowest_common_ancestor lca(g);\r\n    while(q--) {\r\n        int s,t,i;\r\
    \n        std::cin >> s >> t >> i;\r\n        int d = lca.distance(s, t);\r\n\
    \        if(i > d) {\r\n            std::cout << \"-1\\n\";\r\n            continue;\r\
    \n        }\r\n        int m = lca.lca(s, t);\r\n        int ans;\r\n        if(i\
    \ <= lca.distance(m, s)) {\r\n            ans = la.query(s, i);\r\n        }\r\
    \n        else {\r\n            i = d - i;\r\n            assert(i <= lca.distance(m,\
    \ t));\r\n            ans = la.query(t, i);\r\n        }\r\n        std::cout\
    \ << ans << std::endl;\r\n    }\r\n}"
  dependsOn:
  - tree/level_ancestor.hpp
  - tree/lowest_common_ancestor.hpp
  - data_structure/sparse_table.hpp
  - graph/template.hpp
  isVerificationFile: false
  path: test/Jump_on_Tree.cpp
  requiredBy: []
  timestamp: '2023-04-17 16:38:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/Jump_on_Tree.cpp
layout: document
redirect_from:
- /library/test/Jump_on_Tree.cpp
- /library/test/Jump_on_Tree.cpp.html
title: test/Jump_on_Tree.cpp
---
