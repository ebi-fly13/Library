---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2152.test.cpp
    title: test/aoj/aoj_2152.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/section_set.hpp\"\n\n#include <set>\n#include\
    \ <cassert>\n#include <limits>\n\nnamespace ebi {\n\ntemplate<class T>\nstruct\
    \ section_set {\nprivate:\n    std::set<std::pair<T,T>> set;\npublic:\n    section_set()\
    \ {\n        set.insert({std::numeric_limits<T>::min(), std::numeric_limits<T>::min()});\n\
    \        set.insert({std::numeric_limits<T>::max(), std::numeric_limits<T>::max()});\n\
    \    }\n\n    // [l, r)\u3092\u8FFD\u52A0\n    void insert(T l, T r) {\n     \
    \   auto itr = std::prev(set.lower_bound({l, std::numeric_limits<T>::min()}));\n\
    \        if(l <= itr->second) {\n            assert(itr->first <= l);\n      \
    \      l = itr->first;\n            r = std::max(r, itr->second);\n          \
    \  set.erase(itr);\n        }\n        itr = set.lower_bound({l, -1});\n     \
    \   while(itr->first <= r) {\n            assert(l <= itr->first);\n         \
    \   r = std::max(r, itr->second);\n            itr = set.erase(itr);\n       \
    \ }\n        set.insert({l, r});\n        return;\n    }\n\n    // \u96C6\u5408\
    \u5185\u306E[l, r)\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u8981\u7D20\u3092\
    \u524A\u9664\n    void erase(T l, T r) {\n        auto itr = std::prev(set.lower_bound({l,\
    \ std::numeric_limits<T>::min()}));\n        if(l < itr->second) {\n         \
    \   assert(itr->first < l);\n            set.insert({itr->first ,l});\n      \
    \      if(r < itr->second) {\n                set.insert({r, itr->second});\n\
    \            }\n            set.erase(itr);\n        }\n        itr = set.lower_bound({l,\
    \ std::numeric_limits<T>::min()});\n        while(itr->first < r) {\n        \
    \    if(itr->second <= r) {\n                itr = set.erase(itr);\n         \
    \   }\n            else {\n                set.insert({r, itr->second});\n   \
    \             set.erase(itr);\n                break;\n            }\n       \
    \ }\n        return;\n    }\n\n    bool find(T x) const {\n        auto itr =\
    \ std::prev(set.upper_bound({x, std::numeric_limits<T>::max()}));\n        if(x\
    \ < itr->second) {\n            assert(itr->first <= x);\n            return true;\n\
    \        }\n        else {\n            return false;\n        }\n    }\n\n  \
    \  bool find(T l, T r) const {\n        auto itr = std::prev(set.upper_bound({l,\
    \ std::numeric_limits<T>::max()}));\n        if(r <= itr->second) {\n        \
    \    assert(itr->first <= l);\n            return true;\n        }\n        else\
    \ {\n            return false;\n        }\n    }\n\n    std::pair<T,T> belong(T\
    \ x) const {\n        auto itr = std::prev(set.upper_bound({x, std::numeric_limits<T>::max()}));\n\
    \        if(x <= itr->second) {\n            assert(itr->first <= x);\n      \
    \      return *itr;\n        }\n        else {\n            return {0, 0};\n \
    \       }\n    }\n\n    std::pair<T,T> lower_bound(T l) const {\n        return\
    \ *set.lower_bound({l, -1});\n    }\n};\n\n}\n"
  code: "#pragma once\n\n#include <set>\n#include <cassert>\n#include <limits>\n\n\
    namespace ebi {\n\ntemplate<class T>\nstruct section_set {\nprivate:\n    std::set<std::pair<T,T>>\
    \ set;\npublic:\n    section_set() {\n        set.insert({std::numeric_limits<T>::min(),\
    \ std::numeric_limits<T>::min()});\n        set.insert({std::numeric_limits<T>::max(),\
    \ std::numeric_limits<T>::max()});\n    }\n\n    // [l, r)\u3092\u8FFD\u52A0\n\
    \    void insert(T l, T r) {\n        auto itr = std::prev(set.lower_bound({l,\
    \ std::numeric_limits<T>::min()}));\n        if(l <= itr->second) {\n        \
    \    assert(itr->first <= l);\n            l = itr->first;\n            r = std::max(r,\
    \ itr->second);\n            set.erase(itr);\n        }\n        itr = set.lower_bound({l,\
    \ -1});\n        while(itr->first <= r) {\n            assert(l <= itr->first);\n\
    \            r = std::max(r, itr->second);\n            itr = set.erase(itr);\n\
    \        }\n        set.insert({l, r});\n        return;\n    }\n\n    // \u96C6\
    \u5408\u5185\u306E[l, r)\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u8981\u7D20\
    \u3092\u524A\u9664\n    void erase(T l, T r) {\n        auto itr = std::prev(set.lower_bound({l,\
    \ std::numeric_limits<T>::min()}));\n        if(l < itr->second) {\n         \
    \   assert(itr->first < l);\n            set.insert({itr->first ,l});\n      \
    \      if(r < itr->second) {\n                set.insert({r, itr->second});\n\
    \            }\n            set.erase(itr);\n        }\n        itr = set.lower_bound({l,\
    \ std::numeric_limits<T>::min()});\n        while(itr->first < r) {\n        \
    \    if(itr->second <= r) {\n                itr = set.erase(itr);\n         \
    \   }\n            else {\n                set.insert({r, itr->second});\n   \
    \             set.erase(itr);\n                break;\n            }\n       \
    \ }\n        return;\n    }\n\n    bool find(T x) const {\n        auto itr =\
    \ std::prev(set.upper_bound({x, std::numeric_limits<T>::max()}));\n        if(x\
    \ < itr->second) {\n            assert(itr->first <= x);\n            return true;\n\
    \        }\n        else {\n            return false;\n        }\n    }\n\n  \
    \  bool find(T l, T r) const {\n        auto itr = std::prev(set.upper_bound({l,\
    \ std::numeric_limits<T>::max()}));\n        if(r <= itr->second) {\n        \
    \    assert(itr->first <= l);\n            return true;\n        }\n        else\
    \ {\n            return false;\n        }\n    }\n\n    std::pair<T,T> belong(T\
    \ x) const {\n        auto itr = std::prev(set.upper_bound({x, std::numeric_limits<T>::max()}));\n\
    \        if(x <= itr->second) {\n            assert(itr->first <= x);\n      \
    \      return *itr;\n        }\n        else {\n            return {0, 0};\n \
    \       }\n    }\n\n    std::pair<T,T> lower_bound(T l) const {\n        return\
    \ *set.lower_bound({l, -1});\n    }\n};\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/section_set.hpp
  requiredBy: []
  timestamp: '2021-11-07 13:38:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_2152.test.cpp
documentation_of: data_structure/section_set.hpp
layout: document
redirect_from:
- /library/data_structure/section_set.hpp
- /library/data_structure/section_set.hpp.html
title: data_structure/section_set.hpp
---
