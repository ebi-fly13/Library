---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/inversion_number.hpp
    title: Inversion Number
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Add_Range_Sum_BIT.test.cpp
    title: test/data_structure/Point_Add_Range_Sum_BIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Static_Range_Inversion_Query.test.cpp
    title: test/data_structure/Static_Range_Inversion_Query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/segment_intersection.test.cpp
    title: test/geometry/segment_intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Inversion_Number.test.cpp
    title: test/math/Inversion_Number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/fenwick_tree.hpp\"\n\r\n#include <cassert>\r\
    \n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class T> struct fenwick_tree\
    \ {\r\n  private:\r\n    int n;\r\n    std::vector<T> data;\r\n\r\n  public:\r\
    \n    fenwick_tree(int _n) : n(_n), data(std::vector<T>(_n + 1, T(0))) {}\r\n\r\
    \n    void add(int i, T val) {\r\n        i++;\r\n        for (int x = i; x <=\
    \ n; x += x & -x) {\r\n            data[x] += val;\r\n        }\r\n    }\r\n\r\
    \n    T prefix_sum(int i) const {\r\n        assert(0 <= i && i <= n);\r\n   \
    \     T ret = 0;\r\n        for (int x = i; x > 0; x -= x & -x) {\r\n        \
    \    ret += data[x];\r\n        }\r\n        return ret;\r\n    }\r\n\r\n    T\
    \ sum(int l, int r) const {\r\n        return prefix_sum(r) - prefix_sum(l);\r\
    \n    }\r\n\r\n    T all_sum() const {\r\n        return prefix_sum(n);\r\n  \
    \  }\r\n\r\n    // prefix_sum(x) >= key \u3068\u306A\u308B\u6700\u5C0F\u306Ex\u3092\
    \u8FD4\u3059\u95A2\u6570 O(log N)\r\n    int lower_bound(T key) {\r\n        if\
    \ (key <= 0) return 0;\r\n        int x = 0;\r\n        int max = 1;\r\n     \
    \   while ((max << 1) <= n) max <<= 1;\r\n        for (int k = max; k > 0; k >>=\
    \ 1) {\r\n            if (x + k <= n && data[x + k] < key) {\r\n             \
    \   x += k;\r\n                key -= data[x];\r\n            }\r\n        }\r\
    \n        return x + 1;\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <cassert>\r\n#include <vector>\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <class T> struct fenwick_tree {\r\n  private:\r\n    int\
    \ n;\r\n    std::vector<T> data;\r\n\r\n  public:\r\n    fenwick_tree(int _n)\
    \ : n(_n), data(std::vector<T>(_n + 1, T(0))) {}\r\n\r\n    void add(int i, T\
    \ val) {\r\n        i++;\r\n        for (int x = i; x <= n; x += x & -x) {\r\n\
    \            data[x] += val;\r\n        }\r\n    }\r\n\r\n    T prefix_sum(int\
    \ i) const {\r\n        assert(0 <= i && i <= n);\r\n        T ret = 0;\r\n  \
    \      for (int x = i; x > 0; x -= x & -x) {\r\n            ret += data[x];\r\n\
    \        }\r\n        return ret;\r\n    }\r\n\r\n    T sum(int l, int r) const\
    \ {\r\n        return prefix_sum(r) - prefix_sum(l);\r\n    }\r\n\r\n    T all_sum()\
    \ const {\r\n        return prefix_sum(n);\r\n    }\r\n\r\n    // prefix_sum(x)\
    \ >= key \u3068\u306A\u308B\u6700\u5C0F\u306Ex\u3092\u8FD4\u3059\u95A2\u6570 O(log\
    \ N)\r\n    int lower_bound(T key) {\r\n        if (key <= 0) return 0;\r\n  \
    \      int x = 0;\r\n        int max = 1;\r\n        while ((max << 1) <= n) max\
    \ <<= 1;\r\n        for (int k = max; k > 0; k >>= 1) {\r\n            if (x +\
    \ k <= n && data[x + k] < key) {\r\n                x += k;\r\n              \
    \  key -= data[x];\r\n            }\r\n        }\r\n        return x + 1;\r\n\
    \    }\r\n};\r\n\r\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/fenwick_tree.hpp
  requiredBy:
  - math/inversion_number.hpp
  timestamp: '2023-09-10 00:45:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Static_Range_Inversion_Query.test.cpp
  - test/data_structure/Point_Add_Range_Sum_BIT.test.cpp
  - test/geometry/segment_intersection.test.cpp
  - test/math/Inversion_Number.test.cpp
documentation_of: data_structure/fenwick_tree.hpp
layout: document
title: fenwick tree
---

## 説明

配列 $a$ に対して、$1$ 点加算、区間和が $O(\log N)$ でできるデータ構造。

### add(int p, T x)

a[p] に $x$ を加算

### prefix_sum(int p)

sum(a[0], ..., a[p-1]) を返す。

### sum(int l, int r)

sum(a[l], ..., a[r-1]) を返す。

### lower_bound(T key)

$prefix\_sum(x) \geq key$ となる最小のxを返す関数 O(log N)