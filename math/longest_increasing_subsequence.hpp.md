---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Longest_Increasing_Subsequence.test.cpp
    title: test/math/Longest_Increasing_Subsequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/longest_increasing_subsequence.hpp\"\n\n#include <algorithm>\n\
    #include <limits>\n#include <vector>\n\nnamespace ebi {\n\ntemplate <class T>\
    \ std::vector<T> LIS(const std::vector<T> &a, bool narrowly) {\n    std::vector<T>\
    \ ret = {std::numeric_limits<T>::max()};\n    std::vector<int> used;\n    used.reserve(a.size());\n\
    \    for (auto x : a) {\n        auto itr = narrowly ? std::lower_bound(ret.begin(),\
    \ ret.end(), x)\n                            : std::upper_bound(ret.begin(), ret.end(),\
    \ x);\n        used.emplace_back(itr - ret.begin());\n        if (itr == ret.end())\n\
    \            ret.emplace_back(x);\n        else\n            *itr = x;\n    }\n\
    \    int len = ret.size();\n    int idx = len - 1;\n    T now = std::numeric_limits<T>::max();\n\
    \    std::vector<int> lis(len);\n    for (int i = int(a.size()) - 1; i >= 0; i--)\
    \ {\n        if (used[i] == idx && a[i] + int(narrowly) <= now) {\n          \
    \  now = a[i];\n            lis[idx--] = i;\n        }\n    }\n    return lis;\n\
    }\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <limits>\n#include <vector>\n\
    \nnamespace ebi {\n\ntemplate <class T> std::vector<T> LIS(const std::vector<T>\
    \ &a, bool narrowly) {\n    std::vector<T> ret = {std::numeric_limits<T>::max()};\n\
    \    std::vector<int> used;\n    used.reserve(a.size());\n    for (auto x : a)\
    \ {\n        auto itr = narrowly ? std::lower_bound(ret.begin(), ret.end(), x)\n\
    \                            : std::upper_bound(ret.begin(), ret.end(), x);\n\
    \        used.emplace_back(itr - ret.begin());\n        if (itr == ret.end())\n\
    \            ret.emplace_back(x);\n        else\n            *itr = x;\n    }\n\
    \    int len = ret.size();\n    int idx = len - 1;\n    T now = std::numeric_limits<T>::max();\n\
    \    std::vector<int> lis(len);\n    for (int i = int(a.size()) - 1; i >= 0; i--)\
    \ {\n        if (used[i] == idx && a[i] + int(narrowly) <= now) {\n          \
    \  now = a[i];\n            lis[idx--] = i;\n        }\n    }\n    return lis;\n\
    }\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: math/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2023-07-29 00:51:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Longest_Increasing_Subsequence.test.cpp
documentation_of: math/longest_increasing_subsequence.hpp
layout: document
title: LIS
---

## 説明

与えられた数列に対して、最長増加部分列となる添え字の列構築する。`narrowly` が `true` のとき狭義単調増加、 `false` のとき広義単調増加の場合に対して構築する。$O(N\log N)$