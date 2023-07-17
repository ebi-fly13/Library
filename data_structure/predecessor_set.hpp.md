---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Predecessor_Problem.test.cpp
    title: test/data_structure/Predecessor_Problem.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/predecessor_set.hpp\"\n\n#include <set>\n\
    \nnamespace ebi {\n\nstruct predecessor_set {\n  public:\n    predecessor_set()\
    \ = default;\n\n    void insert(int k) {\n        set.insert(k);\n    }\n\n  \
    \  void erase(int k) {\n        set.erase(k);\n    }\n\n    bool find(int k) const\
    \ {\n        return set.find(k) != set.end();\n    }\n\n    int find_next(int\
    \ k) const {\n        auto itr = set.lower_bound(k);\n        return itr == set.end()\
    \ ? -1 : *itr;\n    }\n\n    int find_prev(int k) const {\n        auto itr =\
    \ set.upper_bound(k);\n        return itr == set.begin() ? -1 : *(--itr);\n  \
    \  }\n\n  private:\n    std::set<int> set;\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <set>\n\nnamespace ebi {\n\nstruct predecessor_set\
    \ {\n  public:\n    predecessor_set() = default;\n\n    void insert(int k) {\n\
    \        set.insert(k);\n    }\n\n    void erase(int k) {\n        set.erase(k);\n\
    \    }\n\n    bool find(int k) const {\n        return set.find(k) != set.end();\n\
    \    }\n\n    int find_next(int k) const {\n        auto itr = set.lower_bound(k);\n\
    \        return itr == set.end() ? -1 : *itr;\n    }\n\n    int find_prev(int\
    \ k) const {\n        auto itr = set.upper_bound(k);\n        return itr == set.begin()\
    \ ? -1 : *(--itr);\n    }\n\n  private:\n    std::set<int> set;\n};\n\n}  // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/predecessor_set.hpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/Predecessor_Problem.test.cpp
documentation_of: data_structure/predecessor_set.hpp
layout: document
redirect_from:
- /library/data_structure/predecessor_set.hpp
- /library/data_structure/predecessor_set.hpp.html
title: data_structure/predecessor_set.hpp
---
