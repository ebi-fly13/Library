---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree/Cartesian_Tree.test.cpp
    title: test/tree/Cartesian_Tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/cartesian_tree.hpp\"\n\n#include <ranges>\n#include\
    \ <vector>\n\nnamespace ebi {\n\ntemplate <class T> std::vector<int> cartesian_tree(const\
    \ std::vector<T> &a) {\n    int n = a.size();\n    std::vector<int> par(n, -1);\n\
    \    std::vector<int> stack;\n    stack.reserve(n);\n    for (int i : std::views::iota(0,\
    \ n)) {\n        int prev = -1;\n        while (!stack.empty() && a[i] < a[stack.back()])\
    \ {\n            prev = stack.back();\n            stack.pop_back();\n       \
    \ }\n        if (prev != -1) {\n            par[prev] = i;\n        }\n      \
    \  if (!stack.empty()) {\n            par[i] = stack.back();\n        }\n    \
    \    stack.push_back(i);\n    }\n    return par;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <ranges>\n#include <vector>\n\nnamespace ebi {\n\
    \ntemplate <class T> std::vector<int> cartesian_tree(const std::vector<T> &a)\
    \ {\n    int n = a.size();\n    std::vector<int> par(n, -1);\n    std::vector<int>\
    \ stack;\n    stack.reserve(n);\n    for (int i : std::views::iota(0, n)) {\n\
    \        int prev = -1;\n        while (!stack.empty() && a[i] < a[stack.back()])\
    \ {\n            prev = stack.back();\n            stack.pop_back();\n       \
    \ }\n        if (prev != -1) {\n            par[prev] = i;\n        }\n      \
    \  if (!stack.empty()) {\n            par[i] = stack.back();\n        }\n    \
    \    stack.push_back(i);\n    }\n    return par;\n}\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: tree/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2023-10-30 22:46:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree/Cartesian_Tree.test.cpp
documentation_of: tree/cartesian_tree.hpp
layout: document
title: Cartesian Tree
---

## 説明

数列 $a$ を与え、最も小さい要素が根であるCartesian Treeを構築する。返り値の配列 $p$ について、 $p_i$ には親のインデックスが格納されている。根には $-1$ が入っている。 $O(N)$