---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Tree_Path_Composite_Sum.test.cpp
    title: test/Tree_Path_Composite_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Tree_Path_Composite_Sum.test.cpp
    title: test/tree/Tree_Path_Composite_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/rerooting.hpp\"\n\n#include <vector>\n#include <utility>\n\
    #include <cassert>\n\nnamespace ebi {\n\ntemplate <class V, class E, E (*e)(),\
    \ E (*merge)(E, E), E (*put_edge)(int, V),\n          V (*put_root)(int, E)>\n\
    struct rerooting {\n  private:\n    V dfs_sub(int v, int par = -1) {\n       \
    \ E ret = e();\n        for (auto &edge : g[v]) {\n            if (edge.first\
    \ == par && g[v].back().first != par)\n                std::swap(g[v].back(),\
    \ edge);\n            auto [nv, index] = edge;\n            if (nv == par) continue;\n\
    \            E val = put_edge(index, dfs_sub(nv, v));\n            outs[v].emplace_back(val);\n\
    \            ret = merge(ret, val);\n        }\n        sub[v] = put_root(v, ret);\n\
    \        return sub[v];\n    }\n\n    void dfs_all(int v, int par = -1, E rev\
    \ = e()) {\n        int sz = outs[v].size();\n        std::vector<E> lcum(sz +\
    \ 1, e()), rcum(sz + 1, e());\n        for (int i = 0; i < sz; i++) {\n      \
    \      lcum[i + 1] = merge(lcum[i], outs[v][i]);\n            rcum[sz - i - 1]\
    \ = merge(rcum[sz - i], outs[v][sz - i - 1]);\n        }\n        for (int i =\
    \ 0; i < sz; i++) {\n            auto [nv, index] = g[v][i];\n            E ret\
    \ = put_edge(\n                index, put_root(v, merge(merge(lcum[i], rcum[i\
    \ + 1]), rev)));\n            dfs_all(nv, v, ret);\n        }\n        dp[v] =\
    \ put_root(v, merge(lcum[sz], rev));\n    }\n\n  public:\n    rerooting(int n,\
    \ const std::vector<std::pair<int, int>> &edges)\n        : n(n), g(n), sub(n),\
    \ dp(n), outs(n) {\n        for (int i = 0; i < (int)edges.size(); i++) {\n  \
    \          auto [u, v] = edges[i];\n            g[u].emplace_back(v, i);\n   \
    \         if ((int)edges.size() == n - 1) g[v].emplace_back(u, i);\n        }\n\
    \        assert((int)edges.size() == n - 1 || (int)edges.size() == 2 * (n - 1));\n\
    \n        dfs_sub(0);\n        dfs_all(0);\n    }\n\n    V get(int v) const {\n\
    \        return dp[v];\n    }\n\n  private:\n    int n;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> g;\n    std::vector<V> sub;\n    std::vector<V> dp;\n    std::vector<std::vector<E>>\
    \ outs;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <vector>\n#include <utility>\n#include <cassert>\n\
    \nnamespace ebi {\n\ntemplate <class V, class E, E (*e)(), E (*merge)(E, E), E\
    \ (*put_edge)(int, V),\n          V (*put_root)(int, E)>\nstruct rerooting {\n\
    \  private:\n    V dfs_sub(int v, int par = -1) {\n        E ret = e();\n    \
    \    for (auto &edge : g[v]) {\n            if (edge.first == par && g[v].back().first\
    \ != par)\n                std::swap(g[v].back(), edge);\n            auto [nv,\
    \ index] = edge;\n            if (nv == par) continue;\n            E val = put_edge(index,\
    \ dfs_sub(nv, v));\n            outs[v].emplace_back(val);\n            ret =\
    \ merge(ret, val);\n        }\n        sub[v] = put_root(v, ret);\n        return\
    \ sub[v];\n    }\n\n    void dfs_all(int v, int par = -1, E rev = e()) {\n   \
    \     int sz = outs[v].size();\n        std::vector<E> lcum(sz + 1, e()), rcum(sz\
    \ + 1, e());\n        for (int i = 0; i < sz; i++) {\n            lcum[i + 1]\
    \ = merge(lcum[i], outs[v][i]);\n            rcum[sz - i - 1] = merge(rcum[sz\
    \ - i], outs[v][sz - i - 1]);\n        }\n        for (int i = 0; i < sz; i++)\
    \ {\n            auto [nv, index] = g[v][i];\n            E ret = put_edge(\n\
    \                index, put_root(v, merge(merge(lcum[i], rcum[i + 1]), rev)));\n\
    \            dfs_all(nv, v, ret);\n        }\n        dp[v] = put_root(v, merge(lcum[sz],\
    \ rev));\n    }\n\n  public:\n    rerooting(int n, const std::vector<std::pair<int,\
    \ int>> &edges)\n        : n(n), g(n), sub(n), dp(n), outs(n) {\n        for (int\
    \ i = 0; i < (int)edges.size(); i++) {\n            auto [u, v] = edges[i];\n\
    \            g[u].emplace_back(v, i);\n            if ((int)edges.size() == n\
    \ - 1) g[v].emplace_back(u, i);\n        }\n        assert((int)edges.size() ==\
    \ n - 1 || (int)edges.size() == 2 * (n - 1));\n\n        dfs_sub(0);\n       \
    \ dfs_all(0);\n    }\n\n    V get(int v) const {\n        return dp[v];\n    }\n\
    \n  private:\n    int n;\n    std::vector<std::vector<std::pair<int, int>>> g;\n\
    \    std::vector<V> sub;\n    std::vector<V> dp;\n    std::vector<std::vector<E>>\
    \ outs;\n};\n\n}  // namespace ebi\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/rerooting.hpp
  requiredBy: []
  timestamp: '2023-05-11 19:12:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Tree_Path_Composite_Sum.test.cpp
  - test/tree/Tree_Path_Composite_Sum.test.cpp
documentation_of: tree/rerooting.hpp
layout: document
title: rerooting
---

## 説明

抽象化全方位木DPライブラリ。各頂点を根としたときの木DPを求める。$O(N)$

### コンストラクタ

```
rerooting<V, E, e, merge, put_edge, put_root> dp(int n, std::vector<std::pair<int,int>> edges);
```

- DPの値の型 `V`
- 可換モノイドの型 `E`
- `E` の単位元を返す関数 `E e()`
- `E` の演算子 `E merge(E s, E t)`
- 辺 `i` を根に付与する関数 `E put_edge(int index, V x)`
- 頂点 $v$ を根として追加する関数 `V put_root(int v, E x)`

をテンプレートとして用いている。