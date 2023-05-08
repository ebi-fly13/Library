---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/geometry/segment_intersection.test.cpp
    title: test/geometry/segment_intersection.test.cpp
  - icon: ':x:'
    path: test/point_add_rectangle_sum.test.cpp
    title: test/point_add_rectangle_sum.test.cpp
  - icon: ':x:'
    path: test/rectangle_sum.test.cpp
    title: test/rectangle_sum.test.cpp
  - icon: ':x:'
    path: test/static_range_inversion_query.test.cpp
    title: test/static_range_inversion_query.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/compress.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\nnamespace ebi {\n\ntemplate <class T>\
    \ struct compress {\n  private:\n    std::vector<T> cp;\n    bool flag = false;\n\
    \n  public:\n    compress() = default;\n\n    compress(std::vector<T> cp) : cp(cp)\
    \ {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \        flag = true;\n    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n\
    \        flag = false;\n    }\n\n    int get(const T &val) {\n        if (flag\
    \ == false) build();\n        return std::lower_bound(cp.begin(), cp.end(), val)\
    \ - cp.begin();\n    }\n\n    int size() const {\n        return cp.size();\n\
    \    }\n\n    T val(int idx) const {\n        assert(0 <= idx && idx < (int)cp.size());\n\
    \        return cp[idx];\n    }\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \nnamespace ebi {\n\ntemplate <class T> struct compress {\n  private:\n    std::vector<T>\
    \ cp;\n    bool flag = false;\n\n  public:\n    compress() = default;\n\n    compress(std::vector<T>\
    \ cp) : cp(cp) {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \        flag = true;\n    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n\
    \        flag = false;\n    }\n\n    int get(const T &val) {\n        if (flag\
    \ == false) build();\n        return std::lower_bound(cp.begin(), cp.end(), val)\
    \ - cp.begin();\n    }\n\n    int size() const {\n        return cp.size();\n\
    \    }\n\n    T val(int idx) const {\n        assert(0 <= idx && idx < (int)cp.size());\n\
    \        return cp[idx];\n    }\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/compress.hpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/static_range_inversion_query.test.cpp
  - test/point_add_rectangle_sum.test.cpp
  - test/geometry/segment_intersection.test.cpp
  - test/rectangle_sum.test.cpp
documentation_of: data_structure/compress.hpp
layout: document
redirect_from:
- /library/data_structure/compress.hpp
- /library/data_structure/compress.hpp.html
title: data_structure/compress.hpp
---
