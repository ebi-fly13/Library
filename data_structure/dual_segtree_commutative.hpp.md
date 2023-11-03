---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Add_Query.test.cpp
    title: test/data_structure/Range_Add_Query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/dual_segtree_commutative.hpp\"\n\r\n#include\
    \ <cassert>\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class\
    \ Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>\r\nstruct DualSegtree {\r\
    \n  public:\r\n    DualSegtree(int n) : n(n) {\r\n        size = 1;\r\n      \
    \  while (size < n) size <<= 1;\r\n        data.assign(2 * size, e());\r\n   \
    \ }\r\n\r\n    DualSegtree(const std::vector<Monoid> &vec) : n(vec.size()) {\r\
    \n        size = 1;\r\n        while (size < n) size <<= 1;\r\n        data.assign(2\
    \ * size, e());\r\n        std::copy(vec.begin(), vec.end(), data.begin() + size);\r\
    \n    }\r\n\r\n    Monoid get(int idx) const {\r\n        assert(0 <= idx && idx\
    \ < n);\r\n        idx += size;\r\n        Monoid val = e();\r\n        while\
    \ (idx > 0) {\r\n            val = op(val, data[idx]);\r\n            idx >>=\
    \ 1;\r\n        }\r\n        return val;\r\n    }\r\n\r\n    void apply(int l,\
    \ int r, Monoid x) {\r\n        assert(0 <= l && l <= r && r <= n);\r\n      \
    \  l += size;\r\n        r += size;\r\n        while (l < r) {\r\n           \
    \ if (l & 1) {\r\n                data[l] = op(data[l], x);\r\n              \
    \  l++;\r\n            }\r\n            if (r & 1) {\r\n                r--;\r\
    \n                data[r] = op(data[r], x);\r\n            }\r\n            l\
    \ >>= 1;\r\n            r >>= 1;\r\n        }\r\n        return;\r\n    }\r\n\r\
    \n  private:\r\n    std::vector<Monoid> data;\r\n    int n;\r\n    int size;\r\
    \n};\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <cassert>\r\n#include <vector>\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>\r\
    \nstruct DualSegtree {\r\n  public:\r\n    DualSegtree(int n) : n(n) {\r\n   \
    \     size = 1;\r\n        while (size < n) size <<= 1;\r\n        data.assign(2\
    \ * size, e());\r\n    }\r\n\r\n    DualSegtree(const std::vector<Monoid> &vec)\
    \ : n(vec.size()) {\r\n        size = 1;\r\n        while (size < n) size <<=\
    \ 1;\r\n        data.assign(2 * size, e());\r\n        std::copy(vec.begin(),\
    \ vec.end(), data.begin() + size);\r\n    }\r\n\r\n    Monoid get(int idx) const\
    \ {\r\n        assert(0 <= idx && idx < n);\r\n        idx += size;\r\n      \
    \  Monoid val = e();\r\n        while (idx > 0) {\r\n            val = op(val,\
    \ data[idx]);\r\n            idx >>= 1;\r\n        }\r\n        return val;\r\n\
    \    }\r\n\r\n    void apply(int l, int r, Monoid x) {\r\n        assert(0 <=\
    \ l && l <= r && r <= n);\r\n        l += size;\r\n        r += size;\r\n    \
    \    while (l < r) {\r\n            if (l & 1) {\r\n                data[l] =\
    \ op(data[l], x);\r\n                l++;\r\n            }\r\n            if (r\
    \ & 1) {\r\n                r--;\r\n                data[r] = op(data[r], x);\r\
    \n            }\r\n            l >>= 1;\r\n            r >>= 1;\r\n        }\r\
    \n        return;\r\n    }\r\n\r\n  private:\r\n    std::vector<Monoid> data;\r\
    \n    int n;\r\n    int size;\r\n};\r\n\r\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/dual_segtree_commutative.hpp
  requiredBy: []
  timestamp: '2023-10-26 13:46:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Range_Add_Query.test.cpp
documentation_of: data_structure/dual_segtree_commutative.hpp
layout: document
title: dual segtree (commutative)
---

## 説明

モノイドの列$(a_0,a_1,\dots,a_{n-1})$に対して区間操作、 $1$ 点取得ができるデータ構造である。区間操作は可換な演算のみ使用できる。