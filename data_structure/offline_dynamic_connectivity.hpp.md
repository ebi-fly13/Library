---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/undo_unionfind.hpp
    title: Undo Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2235.test.cpp
    title: test/aoj/aoj_2235.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/offline_dynamic_connectivity.hpp\"\n\n#include\
    \ <array>\n#include <bit>\n#include <cassert>\n#include <map>\n#include <ranges>\n\
    #include <utility>\n#include <vector>\n\n#line 2 \"data_structure/undo_unionfind.hpp\"\
    \n\n#line 4 \"data_structure/undo_unionfind.hpp\"\n#include <stack>\n#line 6 \"\
    data_structure/undo_unionfind.hpp\"\n\nnamespace ebi {\n\nstruct undo_unionfind\
    \ {\n  private:\n    std::stack<std::pair<int, int> > stack;\n\n  public:\n  \
    \  std::vector<int> par;\n\n    undo_unionfind(int n = 0) : par(n, -1) {}\n\n\
    \    bool same(int x, int y) const {\n        return leader(x) == leader(y);\n\
    \    }\n\n    bool merge(int x, int y) {\n        x = leader(x);\n        y =\
    \ leader(y);\n        stack.push({x, par[x]});\n        stack.push({y, par[y]});\n\
    \        if (x == y) return false;\n        if (par[x] > par[y]) std::swap(x,\
    \ y);\n        par[x] += par[y];\n        par[y] = x;\n        return true;\n\
    \    }\n\n    int leader(int x) const {\n        if (par[x] < 0)\n           \
    \ return x;\n        else\n            return leader(par[x]);\n    }\n\n    int\
    \ size(int x) const {\n        return -par[leader(x)];\n    }\n\n    int count_group()\
    \ const {\n        int c = 0;\n        for (int i = 0; i < int(par.size()); i++)\
    \ {\n            if (par[i] < 0) c++;\n        }\n        return c;\n    }\n\n\
    \    void undo() {\n        assert(!stack.empty());\n        par[stack.top().first]\
    \ = stack.top().second;\n        stack.pop();\n        par[stack.top().first]\
    \ = stack.top().second;\n        stack.pop();\n        return;\n    }\n};\n\n\
    }  // namespace ebi\n#line 12 \"data_structure/offline_dynamic_connectivity.hpp\"\
    \n\nnamespace ebi {\n\nstruct offline_dynamic_connective {\n  private:\n    void\
    \ add_query(int l, int r, std::pair<int, int> edge) {\n        assert(0 <= l &&\
    \ l <= r && r <= m);\n        l += sz;\n        r += sz;\n        while (l < r)\
    \ {\n            if (l & 1) seg[l++].emplace_back(edge);\n            if (r &\
    \ 1) seg[--r].emplace_back(edge);\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n    }\n\n    void add_block(int i) {\n        for (auto [u, v] : seg[i])\
    \ {\n            uf.merge(u, v);\n        }\n    }\n\n    void del_block(int i)\
    \ {\n        int cnt = seg[i].size();\n        while (cnt--) {\n            uf.undo();\n\
    \        }\n    }\n\n  public:\n    offline_dynamic_connective(int n_, std::vector<std::array<int,\
    \ 3>> queries)\n        : n(n_),\n          m(queries.size() + 1),\n         \
    \ sz(std::bit_ceil(uint(m))),\n          lg2(std::countr_zero(uint(sz))) {\n \
    \       seg.resize(2 * sz);\n        std::map<std::pair<int, int>, int> cnt, appear;\n\
    \        for (int i = 0; i < (int)queries.size(); i++) {\n            auto [t,\
    \ u, v] = queries[i];\n            if (u > v) std::swap(u, v);\n            if\
    \ (t == 0) {\n                if (cnt[{u, v}]++ == 0) {\n                    appear[{u,\
    \ v}] = i + 1;\n                }\n            } else if (t == 1) {\n        \
    \        int c = --cnt[{u, v}];\n                assert(c >= 0);\n           \
    \     if (c == 0) {\n                    add_query(appear[{u, v}], i + 1, {u,\
    \ v});\n                }\n            } else\n                assert(0);\n  \
    \      }\n\n        for (auto [edge, c] : cnt) {\n            if (c == 0) continue;\n\
    \            add_query(appear[edge], m, edge);\n        }\n\n        uf = undo_unionfind(n);\n\
    \        for (int i : std::views::iota(0, lg2)) {\n            add_block(1 <<\
    \ i);\n        }\n        now = sz;\n    }\n\n    void set(int t) {\n        assert(0\
    \ <= t && t < m);\n        t += sz;\n        if (now == t) return;\n        int\
    \ k = 32 - std::countl_zero(uint(now ^ t));\n        for (int i = 0; i < k; i++)\
    \ {\n            del_block(now);\n            now >>= 1;\n        }\n        for\
    \ (int i : std::views::iota(0, k) | std::views::reverse) {\n            now <<=\
    \ 1;\n            if ((t >> i) & 1) now++;\n            add_block(now);\n    \
    \    }\n        assert(now == t);\n    }\n\n    bool same(int u, int v) const\
    \ {\n        return uf.same(u, v);\n    }\n\n    int leader(int u) const {\n \
    \       return uf.leader(u);\n    }\n\n    int size(int u) const {\n        return\
    \ uf.size(u);\n    }\n\n    int count_group() const {\n        return uf.count_group();\n\
    \    }\n\n  private:\n    int n, m;\n    int sz, lg2;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> seg;\n    int now;\n    undo_unionfind uf;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <array>\n#include <bit>\n#include <cassert>\n#include\
    \ <map>\n#include <ranges>\n#include <utility>\n#include <vector>\n\n#include\
    \ \"../data_structure/undo_unionfind.hpp\"\n\nnamespace ebi {\n\nstruct offline_dynamic_connective\
    \ {\n  private:\n    void add_query(int l, int r, std::pair<int, int> edge) {\n\
    \        assert(0 <= l && l <= r && r <= m);\n        l += sz;\n        r += sz;\n\
    \        while (l < r) {\n            if (l & 1) seg[l++].emplace_back(edge);\n\
    \            if (r & 1) seg[--r].emplace_back(edge);\n            l >>= 1;\n \
    \           r >>= 1;\n        }\n    }\n\n    void add_block(int i) {\n      \
    \  for (auto [u, v] : seg[i]) {\n            uf.merge(u, v);\n        }\n    }\n\
    \n    void del_block(int i) {\n        int cnt = seg[i].size();\n        while\
    \ (cnt--) {\n            uf.undo();\n        }\n    }\n\n  public:\n    offline_dynamic_connective(int\
    \ n_, std::vector<std::array<int, 3>> queries)\n        : n(n_),\n          m(queries.size()\
    \ + 1),\n          sz(std::bit_ceil(uint(m))),\n          lg2(std::countr_zero(uint(sz)))\
    \ {\n        seg.resize(2 * sz);\n        std::map<std::pair<int, int>, int> cnt,\
    \ appear;\n        for (int i = 0; i < (int)queries.size(); i++) {\n         \
    \   auto [t, u, v] = queries[i];\n            if (u > v) std::swap(u, v);\n  \
    \          if (t == 0) {\n                if (cnt[{u, v}]++ == 0) {\n        \
    \            appear[{u, v}] = i + 1;\n                }\n            } else if\
    \ (t == 1) {\n                int c = --cnt[{u, v}];\n                assert(c\
    \ >= 0);\n                if (c == 0) {\n                    add_query(appear[{u,\
    \ v}], i + 1, {u, v});\n                }\n            } else\n              \
    \  assert(0);\n        }\n\n        for (auto [edge, c] : cnt) {\n           \
    \ if (c == 0) continue;\n            add_query(appear[edge], m, edge);\n     \
    \   }\n\n        uf = undo_unionfind(n);\n        for (int i : std::views::iota(0,\
    \ lg2)) {\n            add_block(1 << i);\n        }\n        now = sz;\n    }\n\
    \n    void set(int t) {\n        assert(0 <= t && t < m);\n        t += sz;\n\
    \        if (now == t) return;\n        int k = 32 - std::countl_zero(uint(now\
    \ ^ t));\n        for (int i = 0; i < k; i++) {\n            del_block(now);\n\
    \            now >>= 1;\n        }\n        for (int i : std::views::iota(0, k)\
    \ | std::views::reverse) {\n            now <<= 1;\n            if ((t >> i) &\
    \ 1) now++;\n            add_block(now);\n        }\n        assert(now == t);\n\
    \    }\n\n    bool same(int u, int v) const {\n        return uf.same(u, v);\n\
    \    }\n\n    int leader(int u) const {\n        return uf.leader(u);\n    }\n\
    \n    int size(int u) const {\n        return uf.size(u);\n    }\n\n    int count_group()\
    \ const {\n        return uf.count_group();\n    }\n\n  private:\n    int n, m;\n\
    \    int sz, lg2;\n    std::vector<std::vector<std::pair<int, int>>> seg;\n  \
    \  int now;\n    undo_unionfind uf;\n};\n\n}  // namespace ebi"
  dependsOn:
  - data_structure/undo_unionfind.hpp
  isVerificationFile: false
  path: data_structure/offline_dynamic_connectivity.hpp
  requiredBy: []
  timestamp: '2023-10-26 16:27:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
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

### set(int t)

$t$ 個のクエリを処理した後のUnionFindの状態にする。 $O(\log N)$

与える $t$ が広義単調増加である場合は、全体で $O(N)$ となる。

### same(int u, int v)

$u$ と $v$ が同じグループにあるかを判定。 $O(\log N)$

### leader(int u)

$u$ のグループの代表を返す。 $O(\log N)$

### size(int u)

$u$ の属するグループのサイズを返す。 $O(\log N)$

### count_group()

グループの数を返す。 $O(N)$