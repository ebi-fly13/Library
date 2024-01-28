---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/offline_segtree_2d.hpp
    title: offline 2D segtree
  - icon: ':heavy_check_mark:'
    path: data_structure/static_rectangle_sum.hpp
    title: Static Rectangle Sum
  - icon: ':heavy_check_mark:'
    path: math/inversion_number.hpp
    title: Inversion Number
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
    title: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Rectangle_Sum_Segtree.test.cpp
    title: test/data_structure/Rectangle_Sum_Segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Static_Range_Inversion_Query.test.cpp
    title: test/data_structure/Static_Range_Inversion_Query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Static_Rectangle_Sum.test.cpp
    title: test/data_structure/Static_Rectangle_Sum.test.cpp
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
  bundledCode: "#line 2 \"data_structure/compress.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\nnamespace ebi {\n\ntemplate <class T>\
    \ struct compress {\n  private:\n    std::vector<T> cp;\n\n  public:\n    compress()\
    \ = default;\n\n    compress(std::vector<T> cp) : cp(cp) {\n        build();\n\
    \    }\n\n    void build() {\n        std::sort(cp.begin(), cp.end());\n     \
    \   cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n    }\n\n    void\
    \ add(const T &val) {\n        cp.emplace_back(val);\n    }\n\n    int get(const\
    \ T &val) const {\n        return std::lower_bound(cp.begin(), cp.end(), val)\
    \ - cp.begin();\n    }\n\n    int size() const {\n        return cp.size();\n\
    \    }\n\n    bool find(const T &val) const {\n        auto itr = std::lower_bound(cp.begin(),\
    \ cp.end(), val);\n        if (itr == cp.end())\n            return false;\n \
    \       else\n            return *itr == val;\n    }\n\n    T val(int idx) const\
    \ {\n        assert(0 <= idx && idx < (int)cp.size());\n        return cp[idx];\n\
    \    }\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \nnamespace ebi {\n\ntemplate <class T> struct compress {\n  private:\n    std::vector<T>\
    \ cp;\n\n  public:\n    compress() = default;\n\n    compress(std::vector<T> cp)\
    \ : cp(cp) {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n    }\n\
    \n    int get(const T &val) const {\n        return std::lower_bound(cp.begin(),\
    \ cp.end(), val) - cp.begin();\n    }\n\n    int size() const {\n        return\
    \ cp.size();\n    }\n\n    bool find(const T &val) const {\n        auto itr =\
    \ std::lower_bound(cp.begin(), cp.end(), val);\n        if (itr == cp.end())\n\
    \            return false;\n        else\n            return *itr == val;\n  \
    \  }\n\n    T val(int idx) const {\n        assert(0 <= idx && idx < (int)cp.size());\n\
    \        return cp[idx];\n    }\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/compress.hpp
  requiredBy:
  - data_structure/static_rectangle_sum.hpp
  - data_structure/offline_segtree_2d.hpp
  - math/inversion_number.hpp
  timestamp: '2023-10-26 02:38:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Rectangle_Sum_Segtree.test.cpp
  - test/data_structure/Static_Rectangle_Sum.test.cpp
  - test/data_structure/Point_Add_Rectangle_Sum.test.cpp
  - test/data_structure/Static_Range_Inversion_Query.test.cpp
  - test/math/Inversion_Number.test.cpp
  - test/geometry/segment_intersection.test.cpp
documentation_of: data_structure/compress.hpp
layout: document
title: Compress
---

## 説明

### build()

座圧を実行する。 $O(N\log N)$

### add(T val)

valを座圧の対象にする。 $O(1)$

### get(T val)

valを座圧した後の値を返す。 $O(\log N)$

### size()

座圧後の要素数を返す。 $O(1)$

### find(T val)

valが座圧対象であるか判定。 $O(\log N)$

### val(int idx)

座圧後の値がidxのものの座圧前の値を返す。 $O(1)$