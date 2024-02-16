---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Affine_Point_Get.test.cpp
    title: test/data_structure/Range_Affine_Point_Get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Vertex_Get_Range_Contour_Add_on_Tree.test.cpp
    title: test/tree/Vertex_Get_Range_Contour_Add_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1038.test.cpp
    title: test/yuki/yuki_1038.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/dual_segtree.hpp\"\n\n#include <bit>\n#include\
    \ <cassert>\n#include <ranges>\n#include <vector>\n\nnamespace ebi {\n\ntemplate\
    \ <class F, F (*merge)(F, F), F (*id)()> struct dual_segtree {\n  private:\n \
    \   void all_apply(int i, F f) {\n        d[i] = merge(f, d[i]);\n    }\n\n  \
    \  void push(int i) {\n        assert(i < sz);\n        all_apply(2 * i, d[i]);\n\
    \        all_apply(2 * i + 1, d[i]);\n        d[i] = id();\n    }\n\n  public:\n\
    \    dual_segtree(int n) : dual_segtree(std::vector<F>(n, id())) {}\n\n    dual_segtree(const\
    \ std::vector<F> &a)\n        : n(a.size()),\n          sz(std::bit_ceil(a.size())),\n\
    \          lg2(std::countr_zero((unsigned int)(sz))) {\n        d = std::vector<F>(2\
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
    \    int n, sz, lg2;\n    std::vector<F> d;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <bit>\n#include <cassert>\n#include <ranges>\n#include\
    \ <vector>\n\nnamespace ebi {\n\ntemplate <class F, F (*merge)(F, F), F (*id)()>\
    \ struct dual_segtree {\n  private:\n    void all_apply(int i, F f) {\n      \
    \  d[i] = merge(f, d[i]);\n    }\n\n    void push(int i) {\n        assert(i <\
    \ sz);\n        all_apply(2 * i, d[i]);\n        all_apply(2 * i + 1, d[i]);\n\
    \        d[i] = id();\n    }\n\n  public:\n    dual_segtree(int n) : dual_segtree(std::vector<F>(n,\
    \ id())) {}\n\n    dual_segtree(const std::vector<F> &a)\n        : n(a.size()),\n\
    \          sz(std::bit_ceil(a.size())),\n          lg2(std::countr_zero((unsigned\
    \ int)(sz))) {\n        d = std::vector<F>(2 * sz, id());\n        for (int i\
    \ : std::views::iota(sz, sz + n)) {\n            d[i] = a[i - sz];\n        }\n\
    \    }\n\n    void apply(int l, int r, F f) {\n        assert(0 <= l && l <= r\
    \ && r <= n);\n        if (l == r) return;\n\n        l += sz;\n        r += sz;\n\
    \n        for (int i : std::views::iota(1, lg2 + 1) | std::views::reverse) {\n\
    \            if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i)\
    \ << i) != r) push((r - 1) >> i);\n        }\n\n        while (l < r) {\n    \
    \        if (l & 1) all_apply(l++, f);\n            if (r & 1) all_apply(--r,\
    \ f);\n            l >>= 1;\n            r >>= 1;\n        }\n    }\n\n    F get(int\
    \ p) {\n        assert(0 <= p && p < n);\n        p += sz;\n        for (int i\
    \ : std::views::iota(1, lg2 + 1) | std::views::reverse) {\n            push(p\
    \ >> i);\n        }\n        return d[p];\n    }\n\n  private:\n    int n, sz,\
    \ lg2;\n    std::vector<F> d;\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/dual_segtree.hpp
  requiredBy: []
  timestamp: '2023-10-31 00:17:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Range_Affine_Point_Get.test.cpp
  - test/yuki/yuki_1038.test.cpp
  - test/tree/Vertex_Get_Range_Contour_Add_on_Tree.test.cpp
documentation_of: data_structure/dual_segtree.hpp
layout: document
title: dual segtree
---

## 説明

モノイドの列$(a_0,a_1,\dots,a_{n-1})$に対して区間操作、 $1$ 点取得ができるデータ構造である。