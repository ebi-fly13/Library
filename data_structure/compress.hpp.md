---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: data_structure/offline_segtree_2d.hpp
    title: offline 2D segtree
  - icon: ':heavy_check_mark:'
    path: math/inversion_number.hpp
    title: math/inversion_number.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
    title: test/data_structure/Point_Add_Rectangle_Sum.test.cpp
  - icon: ':x:'
    path: test/data_structure/Rectangle_Sum.test.cpp
    title: test/data_structure/Rectangle_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/segment_intersection.test.cpp
    title: test/geometry/segment_intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/inversion_number.test.cpp
    title: test/math/inversion_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/static_range_inversion_query.test.cpp
    title: test/static_range_inversion_query.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \    }\n\n    bool find(const T& val) const {\n        auto itr = std::lower_bound(cp.begin(),\
    \ cp.end(), val);\n        if(itr == cp.end()) return false;\n        else return\
    \ *itr == val;\n    }\n\n    T val(int idx) const {\n        assert(0 <= idx &&\
    \ idx < (int)cp.size());\n        return cp[idx];\n    }\n};\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \nnamespace ebi {\n\ntemplate <class T> struct compress {\n  private:\n    std::vector<T>\
    \ cp;\n\n  public:\n    compress() = default;\n\n    compress(std::vector<T> cp)\
    \ : cp(cp) {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n    }\n\
    \n    int get(const T &val) const {\n        return std::lower_bound(cp.begin(),\
    \ cp.end(), val) - cp.begin();\n    }\n\n    int size() const {\n        return\
    \ cp.size();\n    }\n\n    bool find(const T& val) const {\n        auto itr =\
    \ std::lower_bound(cp.begin(), cp.end(), val);\n        if(itr == cp.end()) return\
    \ false;\n        else return *itr == val;\n    }\n\n    T val(int idx) const\
    \ {\n        assert(0 <= idx && idx < (int)cp.size());\n        return cp[idx];\n\
    \    }\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/compress.hpp
  requiredBy:
  - math/inversion_number.hpp
  - data_structure/offline_segtree_2d.hpp
  timestamp: '2023-06-26 12:08:21+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/geometry/segment_intersection.test.cpp
  - test/math/inversion_number.test.cpp
  - test/data_structure/Rectangle_Sum.test.cpp
  - test/data_structure/Point_Add_Rectangle_Sum.test.cpp
  - test/static_range_inversion_query.test.cpp
documentation_of: data_structure/compress.hpp
layout: document
redirect_from:
- /library/data_structure/compress.hpp
- /library/data_structure/compress.hpp.html
title: data_structure/compress.hpp
---
