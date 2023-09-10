---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/complement_graph_bfs.hpp\"\n\n#include <numeric>\n\
    #include <queue>\n#include <vector>\n\nnamespace ebi {\n\ntemplate <class F>\n\
    void complement_graph_bfs(int s, const std::vector<std::vector<int>> &h,\n   \
    \                       const F &func) {\n    const int n = h.size();\n    std::vector<int>\
    \ not_visit;\n    not_visit.reserve(n - 1);\n    for (int i = 0; i < n; i++)\n\
    \        if (i != s) not_visit.emplace_back(i);\n    std::vector<bool> f(n, false);\n\
    \    std::queue<int> que;\n    que.push(s);\n    while (!que.empty()) {\n    \
    \    int v = que.front();\n        que.pop();\n        for (auto nv : h[v]) {\n\
    \            f[nv] = true;\n        }\n        std::vector<int> L;\n        for\
    \ (auto u : not_visit) {\n            if (f[u])\n                L.emplace_back(u);\n\
    \            else {\n                que.push(u);\n                func(v, u);\n\
    \            }\n        }\n        for (auto nv : h[v]) {\n            f[nv] =\
    \ false;\n        }\n        not_visit = L;\n    }\n    return;\n}\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <numeric>\n#include <queue>\n#include <vector>\n\
    \nnamespace ebi {\n\ntemplate <class F>\nvoid complement_graph_bfs(int s, const\
    \ std::vector<std::vector<int>> &h,\n                          const F &func)\
    \ {\n    const int n = h.size();\n    std::vector<int> not_visit;\n    not_visit.reserve(n\
    \ - 1);\n    for (int i = 0; i < n; i++)\n        if (i != s) not_visit.emplace_back(i);\n\
    \    std::vector<bool> f(n, false);\n    std::queue<int> que;\n    que.push(s);\n\
    \    while (!que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \        for (auto nv : h[v]) {\n            f[nv] = true;\n        }\n      \
    \  std::vector<int> L;\n        for (auto u : not_visit) {\n            if (f[u])\n\
    \                L.emplace_back(u);\n            else {\n                que.push(u);\n\
    \                func(v, u);\n            }\n        }\n        for (auto nv :\
    \ h[v]) {\n            f[nv] = false;\n        }\n        not_visit = L;\n   \
    \ }\n    return;\n}\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: graph/complement_graph_bfs.hpp
  requiredBy: []
  timestamp: '2023-09-10 17:50:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/complement_graph_bfs.hpp
layout: document
title: Complement Graph BFS
---

## 説明

頂点 $s$ から始めて、 $h$ の補グラフをBFSする。頂点数を $N$ 、辺の本数を $M$ 、`func`の計算量を $F$ として計算量は $O(NF + M)$ である。

インターフェースは以下である。ここで、 `func(v, u)` はBFSの際に頂点 $v$ から $u$ に遷移するときに呼ばれる関数である。

```
void complement_graph_bfs(int s, std::vector<std::vector<int>> h, F func)
```
