---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/compress.hpp
    title: Compress
  - icon: ':heavy_check_mark:'
    path: data_structure/dual_segtree.hpp
    title: dual segtree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Rectangle_Add_Point_Get.test.cpp
    title: test/data_structure/Rectangle_Add_Point_Get.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/offline_dual_segtree_2d.hpp\"\n\n#include\
    \ <bit>\n#include <utility>\n#include <vector>\n\n#line 2 \"data_structure/compress.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#line 6 \"data_structure/compress.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> struct compress {\n  private:\n    std::vector<T>\
    \ cp;\n\n  public:\n    compress() = default;\n\n    compress(std::vector<T> cp_)\
    \ : cp(cp_) {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n    }\n\
    \n    int get(const T &val) const {\n        return std::lower_bound(cp.begin(),\
    \ cp.end(), val) - cp.begin();\n    }\n\n    int size() const {\n        return\
    \ cp.size();\n    }\n\n    bool find(const T &val) const {\n        auto itr =\
    \ std::lower_bound(cp.begin(), cp.end(), val);\n        if (itr == cp.end())\n\
    \            return false;\n        else\n            return *itr == val;\n  \
    \  }\n\n    T val(int idx) const {\n        assert(0 <= idx && idx < (int)cp.size());\n\
    \        return cp[idx];\n    }\n};\n\n}  // namespace ebi\n#line 2 \"data_structure/dual_segtree.hpp\"\
    \n\n#line 5 \"data_structure/dual_segtree.hpp\"\n#include <ranges>\n#line 7 \"\
    data_structure/dual_segtree.hpp\"\n\nnamespace ebi {\n\ntemplate <class F, F (*merge)(F,\
    \ F), F (*id)()> struct dual_segtree {\n  private:\n    void all_apply(int i,\
    \ F f) {\n        d[i] = merge(f, d[i]);\n    }\n\n    void push(int i) {\n  \
    \      assert(i < sz);\n        all_apply(2 * i, d[i]);\n        all_apply(2 *\
    \ i + 1, d[i]);\n        d[i] = id();\n    }\n\n  public:\n    dual_segtree(int\
    \ n) : dual_segtree(std::vector<F>(n, id())) {}\n\n    dual_segtree(const std::vector<F>\
    \ &a)\n        : n(a.size()),\n          sz(std::bit_ceil(a.size())),\n      \
    \    lg2(std::countr_zero((unsigned int)(sz))) {\n        d = std::vector<F>(2\
    \ * sz, id());\n        for (int i : std::views::iota(sz, sz + n)) {\n       \
    \     d[i] = a[i - sz];\n        }\n    }\n\n    void apply(int l, int r, F f)\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return;\n\
    \n        l += sz;\n        r += sz;\n\n        for (int i : std::views::iota(1,\
    \ lg2 + 1) | std::views::reverse) {\n            if (((l >> i) << i) != l) push(l\
    \ >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\
    \n        while (l < r) {\n            if (l & 1) all_apply(l++, f);\n       \
    \     if (r & 1) all_apply(--r, f);\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n    }\n\n    F get(int p) {\n        assert(0 <= p && p < n);\n  \
    \      p += sz;\n        for (int i : std::views::iota(1, lg2 + 1) | std::views::reverse)\
    \ {\n            push(p >> i);\n        }\n        return d[p];\n    }\n\n  private:\n\
    \    int n, sz, lg2;\n    std::vector<F> d;\n};\n\n}  // namespace ebi\n#line\
    \ 9 \"data_structure/offline_dual_segtree_2d.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class F, F (*merge)(F, F), F (*id)()> struct offline_dual_segtree_2d {\n  \
    \  offline_dual_segtree_2d() = default;\n\n    void pre_set(std::pair<int, int>\
    \ p) {\n        ps.emplace_back(p);\n    }\n\n    void build() {\n        for\
    \ (auto [x, y] : ps) {\n            xs.add(x);\n        }\n        xs.build();\n\
    \        sz = std::bit_ceil((unsigned int)xs.size());\n        ys.resize(2 * sz);\n\
    \        for (auto [x, y] : ps) {\n            int i = xs.get(x) + sz;\n     \
    \       ys[i].add(y);\n            while (i > 1) {\n                i >>= 1;\n\
    \                ys[i].add(y);\n            }\n        }\n        for (auto i\
    \ : std::views::iota(0, 2 * sz)) {\n            ys[i].build();\n            seg.emplace_back(dual_segtree<F,\
    \ merge, id>(ys[i].size()));\n        }\n    }\n\n    F get(int i, int j) {\n\
    \        i = xs.get(i) + sz;\n        F x = seg[i].get(ys[i].get(j));\n      \
    \  while (i > 1) {\n            i >>= 1;\n            x = merge(x, seg[i].get(ys[i].get(j)));\n\
    \        }\n        return x;\n    }\n\n    void apply(int l, int d, int r, int\
    \ u, F f) {\n        l = xs.get(l) + sz;\n        r = xs.get(r) + sz;\n      \
    \  while (l < r) {\n            if (l & 1) {\n                seg[l].apply(ys[l].get(d),\
    \ ys[l].get(u), f);\n                l++;\n            }\n            if (r &\
    \ 1) {\n                r--;\n                seg[r].apply(ys[r].get(d), ys[r].get(u),\
    \ f);\n            }\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \    }\n\n  private:\n    int sz = 1;\n    std::vector<std::pair<int, int>> ps;\n\
    \    compress<int> xs;\n    std::vector<compress<int>> ys;\n    std::vector<dual_segtree<F,\
    \ merge, id>> seg;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <bit>\n#include <utility>\n#include <vector>\n\n\
    #include \"../data_structure/compress.hpp\"\n#include \"../data_structure/dual_segtree.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class F, F (*merge)(F, F), F (*id)()> struct\
    \ offline_dual_segtree_2d {\n    offline_dual_segtree_2d() = default;\n\n    void\
    \ pre_set(std::pair<int, int> p) {\n        ps.emplace_back(p);\n    }\n\n   \
    \ void build() {\n        for (auto [x, y] : ps) {\n            xs.add(x);\n \
    \       }\n        xs.build();\n        sz = std::bit_ceil((unsigned int)xs.size());\n\
    \        ys.resize(2 * sz);\n        for (auto [x, y] : ps) {\n            int\
    \ i = xs.get(x) + sz;\n            ys[i].add(y);\n            while (i > 1) {\n\
    \                i >>= 1;\n                ys[i].add(y);\n            }\n    \
    \    }\n        for (auto i : std::views::iota(0, 2 * sz)) {\n            ys[i].build();\n\
    \            seg.emplace_back(dual_segtree<F, merge, id>(ys[i].size()));\n   \
    \     }\n    }\n\n    F get(int i, int j) {\n        i = xs.get(i) + sz;\n   \
    \     F x = seg[i].get(ys[i].get(j));\n        while (i > 1) {\n            i\
    \ >>= 1;\n            x = merge(x, seg[i].get(ys[i].get(j)));\n        }\n   \
    \     return x;\n    }\n\n    void apply(int l, int d, int r, int u, F f) {\n\
    \        l = xs.get(l) + sz;\n        r = xs.get(r) + sz;\n        while (l <\
    \ r) {\n            if (l & 1) {\n                seg[l].apply(ys[l].get(d), ys[l].get(u),\
    \ f);\n                l++;\n            }\n            if (r & 1) {\n       \
    \         r--;\n                seg[r].apply(ys[r].get(d), ys[r].get(u), f);\n\
    \            }\n            l >>= 1;\n            r >>= 1;\n        }\n    }\n\
    \n  private:\n    int sz = 1;\n    std::vector<std::pair<int, int>> ps;\n    compress<int>\
    \ xs;\n    std::vector<compress<int>> ys;\n    std::vector<dual_segtree<F, merge,\
    \ id>> seg;\n};\n\n}  // namespace ebi"
  dependsOn:
  - data_structure/compress.hpp
  - data_structure/dual_segtree.hpp
  isVerificationFile: false
  path: data_structure/offline_dual_segtree_2d.hpp
  requiredBy: []
  timestamp: '2024-02-26 00:01:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Rectangle_Add_Point_Get.test.cpp
documentation_of: data_structure/offline_dual_segtree_2d.hpp
layout: document
title: offline 2D dual segtree
---

## 説明

可換モノイドについて、長方形クエリ、 $1$ 点所得を行えるデータ構造。クエリ先読みにより、必要な部分だけ作ることでメモリ使用量を減らして点の座標が$10^9$とかでも使える。

### pre_set(i, j)

所得クエリで用いる点 $(i,j)$ を追加する。

### build()

クエリ先読み後（pre_set後）、セグ木を構築する。

### apply(l,d,r,u,f)

$[l, r) \times [d, u)$ の長方形に $f$ を作用させる。

### get(i, j)

$(i, j)$ の値を所得する。