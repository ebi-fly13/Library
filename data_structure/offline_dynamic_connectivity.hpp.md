---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/undo_unionfind.hpp
    title: data_structure/undo_unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/aoj_2235.test.cpp
    title: test/aoj/aoj_2235.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/offline_dynamic_connectivity.hpp\"\n\n#include\
    \ <array>\n#include <bit>\n#include <map>\n#include <vector>\n\n#line 2 \"data_structure/undo_unionfind.hpp\"\
    \n\n#include <cassert>\n#include <stack>\n#line 6 \"data_structure/undo_unionfind.hpp\"\
    \n\nnamespace ebi {\n\nstruct undo_unionfind {\n  private:\n    std::stack<std::pair<int,\
    \ int> > stack;\n\n  public:\n    std::vector<int> par;\n\n    undo_unionfind(int\
    \ n = 0) : par(n, -1) {}\n\n    bool same(int x, int y) {\n        return leader(x)\
    \ == leader(y);\n    }\n\n    bool merge(int x, int y) {\n        x = leader(x);\n\
    \        y = leader(y);\n        stack.push({x, par[x]});\n        stack.push({y,\
    \ par[y]});\n        if (x == y) return false;\n        if (par[x] > par[y]) std::swap(x,\
    \ y);\n        par[x] += par[y];\n        par[y] = x;\n        return true;\n\
    \    }\n\n    int leader(int x) {\n        if (par[x] < 0)\n            return\
    \ x;\n        else\n            return leader(par[x]);\n    }\n\n    int size(int\
    \ x) {\n        return -par[leader(x)];\n    }\n\n    int count_group() {\n  \
    \      int c = 0;\n        for (int i = 0; i < int(par.size()); i++) {\n     \
    \       if (par[i] < 0) c++;\n        }\n        return c;\n    }\n\n    void\
    \ undo() {\n        assert(!stack.empty());\n        par[stack.top().first] =\
    \ stack.top().second;\n        stack.pop();\n        par[stack.top().first] =\
    \ stack.top().second;\n        stack.pop();\n        return;\n    }\n};\n\n} \
    \ // namespace ebi\n#line 9 \"data_structure/offline_dynamic_connectivity.hpp\"\
    \n\nnamespace ebi {\n\nstruct offline_dynamic_connective {\n  private:\n    void\
    \ add_query(int l, int r, std::pair<int, int> edge) {\n        assert(0 <= l &&\
    \ l <= r && r <= m);\n        l += sz;\n        r += sz;\n        while (l < r)\
    \ {\n            if (l & 1) seg[l++].emplace_back(edge);\n            if (r &\
    \ 1) seg[--r].emplace_back(edge);\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n    }\n\n  public:\n    offline_dynamic_connective(int n, std::vector<std::array<int,\
    \ 3>> queries)\n        : n(n) {\n        m = queries.size() + 1;\n        log2\
    \ = std::bit_ceil(queries.size() + 1);\n        sz = 1 << log2;\n        seg.resize(2\
    \ * sz);\n        std::map<std::pair<int, int>, int> cnt, appear;\n        for\
    \ (int i = 0; i < (int)queries.size(); i++) {\n            auto [t, u, v] = queries[i];\n\
    \            if (u > v) std::swap(u, v);\n            if (t == 0) {\n        \
    \        if (cnt[{u, v}]++ == 0) {\n                    appear[{u, v}] = i + 1;\n\
    \                }\n            } else if (t == 1) {\n                int c =\
    \ --cnt[{u, v}];\n                assert(c >= 0);\n                if (c == 0)\
    \ {\n                    add_query(appear[{u, v}], i + 1, {u, v});\n         \
    \       }\n            } else\n                assert(0);\n        }\n       \
    \ for (auto [edge, c] : cnt) {\n            if (c == 0) continue;\n          \
    \  add_query(appear[edge], m, edge);\n        }\n    }\n\n    template <class\
    \ F> void execute(F f) {\n        uf = undo_unionfind(n);\n        auto dfs =\
    \ [&](auto &&self, int now) -> void {\n            for (auto edge : seg[now])\
    \ uf.merge(edge.first, edge.second);\n            if (sz <= now) {\n         \
    \       if (now - sz < m) f(now - sz);\n            } else {\n               \
    \ self(self, 2 * now);\n                self(self, 2 * now + 1);\n           \
    \ }\n            for (int i = 0; i < (int)seg[now].size(); i++) uf.undo();\n \
    \       };\n        dfs(dfs, 1);\n    }\n\n    bool is_same(int u, int v) {\n\
    \        return uf.same(u, v);\n    }\n\n    int leader(int x) {\n        return\
    \ uf.leader(x);\n    }\n\n  private:\n    int n, m;\n    int log2, sz;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> seg;\n    undo_unionfind uf;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <array>\n#include <bit>\n#include <map>\n#include\
    \ <vector>\n\n#include \"../data_structure/undo_unionfind.hpp\"\n\nnamespace ebi\
    \ {\n\nstruct offline_dynamic_connective {\n  private:\n    void add_query(int\
    \ l, int r, std::pair<int, int> edge) {\n        assert(0 <= l && l <= r && r\
    \ <= m);\n        l += sz;\n        r += sz;\n        while (l < r) {\n      \
    \      if (l & 1) seg[l++].emplace_back(edge);\n            if (r & 1) seg[--r].emplace_back(edge);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n    }\n\n  public:\n \
    \   offline_dynamic_connective(int n, std::vector<std::array<int, 3>> queries)\n\
    \        : n(n) {\n        m = queries.size() + 1;\n        log2 = std::bit_ceil(queries.size()\
    \ + 1);\n        sz = 1 << log2;\n        seg.resize(2 * sz);\n        std::map<std::pair<int,\
    \ int>, int> cnt, appear;\n        for (int i = 0; i < (int)queries.size(); i++)\
    \ {\n            auto [t, u, v] = queries[i];\n            if (u > v) std::swap(u,\
    \ v);\n            if (t == 0) {\n                if (cnt[{u, v}]++ == 0) {\n\
    \                    appear[{u, v}] = i + 1;\n                }\n            }\
    \ else if (t == 1) {\n                int c = --cnt[{u, v}];\n               \
    \ assert(c >= 0);\n                if (c == 0) {\n                    add_query(appear[{u,\
    \ v}], i + 1, {u, v});\n                }\n            } else\n              \
    \  assert(0);\n        }\n        for (auto [edge, c] : cnt) {\n            if\
    \ (c == 0) continue;\n            add_query(appear[edge], m, edge);\n        }\n\
    \    }\n\n    template <class F> void execute(F f) {\n        uf = undo_unionfind(n);\n\
    \        auto dfs = [&](auto &&self, int now) -> void {\n            for (auto\
    \ edge : seg[now]) uf.merge(edge.first, edge.second);\n            if (sz <= now)\
    \ {\n                if (now - sz < m) f(now - sz);\n            } else {\n  \
    \              self(self, 2 * now);\n                self(self, 2 * now + 1);\n\
    \            }\n            for (int i = 0; i < (int)seg[now].size(); i++) uf.undo();\n\
    \        };\n        dfs(dfs, 1);\n    }\n\n    bool is_same(int u, int v) {\n\
    \        return uf.same(u, v);\n    }\n\n    int leader(int x) {\n        return\
    \ uf.leader(x);\n    }\n\n  private:\n    int n, m;\n    int log2, sz;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> seg;\n    undo_unionfind uf;\n};\n\n}  // namespace ebi"
  dependsOn:
  - data_structure/undo_unionfind.hpp
  isVerificationFile: false
  path: data_structure/offline_dynamic_connectivity.hpp
  requiredBy: []
  timestamp: '2023-10-26 02:37:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/aoj_2235.test.cpp
documentation_of: data_structure/offline_dynamic_connectivity.hpp
layout: document
title: Offline Dynamic Connectivity
---

## 説明

クエリがオフラインで与えられる場合の辺削除可能dsu。

### コンストラクタ

頂点数 $N$ と、辺に関するクエリ $queries$ を与える。

```
offline_dynamic_connectivity uf(n, queries)
```

### execute(f)

`f(int i)` が $i$ 番目 (1-indexed)のクエリを処理した後の uf をoffline_dynamic_connectivityが持った状態で関数が呼び出される。ここで $i$ 番目のクエリを処理し終わった状態での各種操作をすればよい。