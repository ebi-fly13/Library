---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/segment_intersection.test.cpp
    title: test/geometry/segment_intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/static_range_inversion_query.test.cpp
    title: test/static_range_inversion_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/compress.hpp\"\n\n#include <vector>\n#include\
    \ <algorithm>\n\nnamespace ebi {\n\ntemplate<class T>\nstruct compress {\nprivate:\n\
    \    std::vector<T> cp;\n    bool flag = false;\npublic:\n    compress() = default;\n\
    \n    compress(std::vector<T> cp) : cp(cp) {\n        build();\n    }\n\n    void\
    \ build() {\n        std::sort(cp.begin(), cp.end());\n        cp.erase(std::unique(cp.begin(),\
    \ cp.end()), cp.end());\n        flag = true;\n    }\n\n    void add(const T &val)\
    \ {\n        cp.emplace_back(val);\n        flag = false;\n    }\n\n    int get(const\
    \ T &val) {\n        if(flag == false) build();\n        return std::lower_bound(cp.begin(),\
    \ cp.end(), val) - cp.begin();\n    }\n\n    int size() const {\n        return\
    \ cp.size();\n    }\n};\n\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n\nnamespace ebi\
    \ {\n\ntemplate<class T>\nstruct compress {\nprivate:\n    std::vector<T> cp;\n\
    \    bool flag = false;\npublic:\n    compress() = default;\n\n    compress(std::vector<T>\
    \ cp) : cp(cp) {\n        build();\n    }\n\n    void build() {\n        std::sort(cp.begin(),\
    \ cp.end());\n        cp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\
    \        flag = true;\n    }\n\n    void add(const T &val) {\n        cp.emplace_back(val);\n\
    \        flag = false;\n    }\n\n    int get(const T &val) {\n        if(flag\
    \ == false) build();\n        return std::lower_bound(cp.begin(), cp.end(), val)\
    \ - cp.begin();\n    }\n\n    int size() const {\n        return cp.size();\n\
    \    }\n};\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/compress.hpp
  requiredBy: []
  timestamp: '2021-08-17 18:06:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/segment_intersection.test.cpp
  - test/static_range_inversion_query.test.cpp
documentation_of: data_structure/compress.hpp
layout: document
redirect_from:
- /library/data_structure/compress.hpp
- /library/data_structure/compress.hpp.html
title: data_structure/compress.hpp
---
