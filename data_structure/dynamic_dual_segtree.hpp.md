---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp
    title: test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/dynamic_dual_segtree.hpp\"\n\n#include <bit>\n\
    #include <cassert>\n#include <memory>\n\nnamespace ebi {\n\ntemplate <class F,\
    \ F (*merge)(F, F), F (*id)()> struct dynamice_dual_segtree {\n  private:\n  \
    \  struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n    struct Node\
    \ {\n        node_ptr lch = nullptr, rch = nullptr;\n        F f = id();\n   \
    \ };\n\n    void all_apply(node_ptr node, F f) {\n        node->f = merge(f, node->f);\n\
    \    }\n\n    void push(node_ptr node) {\n        if (node->lch == nullptr) {\n\
    \            node->lch = std::make_shared<Node>();\n        }\n        node->lch->f\
    \ = merge(node->f, node->lch->f);\n        if (node->rch == nullptr) {\n     \
    \       node->rch = std::make_shared<Node>();\n        }\n        node->rch->f\
    \ = merge(node->f, node->rch->f);\n        node->f = id();\n    }\n\n    void\
    \ _apply(node_ptr node, int l, int r, int tl, int tr, F f) {\n        if (tr <=\
    \ l || r <= tl) return;\n        if (tl <= l && r <= tr) {\n            all_apply(node,\
    \ f);\n            return;\n        }\n        push(node);\n        _apply(node->lch,\
    \ l, (l + r) / 2, tl, tr, f);\n        _apply(node->rch, (l + r) / 2, r, tl, tr,\
    \ f);\n    }\n\n  public:\n    dynamice_dual_segtree(int n_)\n        : n(n_),\n\
    \          sz(std::bit_ceil(uint(n))),\n          lg2(std::countr_zero(uint(sz))),\n\
    \          root(std::make_shared<Node>()) {}\n\n    void apply(int l, int r, F\
    \ f) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return;\n\
    \        _apply(root, 0, sz, l, r, f);\n    }\n\n    void set(int p, F f) {\n\
    \        assert(0 <= p && p < n);\n        node_ptr node = root;\n        int\
    \ l = 0, r = sz;\n        for (int i = 0; i < lg2; i++) {\n            push(node);\n\
    \            int m = (l + r) / 2;\n            if (p < m) {\n                r\
    \ = m;\n                node = node->lch;\n            } else {\n            \
    \    l = m;\n                node = node->rch;\n            }\n        }\n   \
    \     node->f = f;\n    }\n\n    F get(int p) {\n        assert(0 <= p && p <\
    \ n);\n        node_ptr node = root;\n        int l = 0, r = sz;\n        for\
    \ (int i = 0; i < lg2; i++) {\n            push(node);\n            int m = (l\
    \ + r) / 2;\n            if (p < m) {\n                r = m;\n              \
    \  node = node->lch;\n            } else {\n                l = m;\n         \
    \       node = node->rch;\n            }\n        }\n        return node->f;\n\
    \    }\n\n  private:\n    int n, sz, lg2;\n    node_ptr root;\n};\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <bit>\n#include <cassert>\n#include <memory>\n\n\
    namespace ebi {\n\ntemplate <class F, F (*merge)(F, F), F (*id)()> struct dynamice_dual_segtree\
    \ {\n  private:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \    struct Node {\n        node_ptr lch = nullptr, rch = nullptr;\n        F\
    \ f = id();\n    };\n\n    void all_apply(node_ptr node, F f) {\n        node->f\
    \ = merge(f, node->f);\n    }\n\n    void push(node_ptr node) {\n        if (node->lch\
    \ == nullptr) {\n            node->lch = std::make_shared<Node>();\n        }\n\
    \        node->lch->f = merge(node->f, node->lch->f);\n        if (node->rch ==\
    \ nullptr) {\n            node->rch = std::make_shared<Node>();\n        }\n \
    \       node->rch->f = merge(node->f, node->rch->f);\n        node->f = id();\n\
    \    }\n\n    void _apply(node_ptr node, int l, int r, int tl, int tr, F f) {\n\
    \        if (tr <= l || r <= tl) return;\n        if (tl <= l && r <= tr) {\n\
    \            all_apply(node, f);\n            return;\n        }\n        push(node);\n\
    \        _apply(node->lch, l, (l + r) / 2, tl, tr, f);\n        _apply(node->rch,\
    \ (l + r) / 2, r, tl, tr, f);\n    }\n\n  public:\n    dynamice_dual_segtree(int\
    \ n_)\n        : n(n_),\n          sz(std::bit_ceil(uint(n))),\n          lg2(std::countr_zero(uint(sz))),\n\
    \          root(std::make_shared<Node>()) {}\n\n    void apply(int l, int r, F\
    \ f) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return;\n\
    \        _apply(root, 0, sz, l, r, f);\n    }\n\n    void set(int p, F f) {\n\
    \        assert(0 <= p && p < n);\n        node_ptr node = root;\n        int\
    \ l = 0, r = sz;\n        for (int i = 0; i < lg2; i++) {\n            push(node);\n\
    \            int m = (l + r) / 2;\n            if (p < m) {\n                r\
    \ = m;\n                node = node->lch;\n            } else {\n            \
    \    l = m;\n                node = node->rch;\n            }\n        }\n   \
    \     node->f = f;\n    }\n\n    F get(int p) {\n        assert(0 <= p && p <\
    \ n);\n        node_ptr node = root;\n        int l = 0, r = sz;\n        for\
    \ (int i = 0; i < lg2; i++) {\n            push(node);\n            int m = (l\
    \ + r) / 2;\n            if (p < m) {\n                r = m;\n              \
    \  node = node->lch;\n            } else {\n                l = m;\n         \
    \       node = node->rch;\n            }\n        }\n        return node->f;\n\
    \    }\n\n  private:\n    int n, sz, lg2;\n    node_ptr root;\n};\n\n}  // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/dynamic_dual_segtree.hpp
  requiredBy: []
  timestamp: '2023-10-30 02:43:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp
documentation_of: data_structure/dynamic_dual_segtree.hpp
layout: document
title: dynamic dual segtree
---

## 説明

モノイドの列$(a_0,a_1,\dots,a_{n-1})$に対して区間操作、 $1$ 点取得ができるデータ構造である。必要になった部分だけ作るため、 $n \leq 10^9$ などでも動作する。
