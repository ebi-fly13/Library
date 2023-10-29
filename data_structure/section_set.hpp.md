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
  bundledCode: "#line 2 \"data_structure/section_set.hpp\"\n\n#include <cassert>\n\
    #include <limits>\n#include <set>\n\nnamespace ebi {\n\ntemplate <class T> struct\
    \ section_set {\n  private:\n    std::set<std::pair<T, T>> set;\n\n  public:\n\
    \    section_set() {\n        set.insert(\n            {std::numeric_limits<T>::min(),\
    \ std::numeric_limits<T>::min()});\n        set.insert(\n            {std::numeric_limits<T>::max(),\
    \ std::numeric_limits<T>::max()});\n    }\n\n    std::set<std::pair<T, T>> sections()\
    \ const {\n        return set;\n    }\n\n    // [l, r)\u3092\u8FFD\u52A0\n   \
    \ void insert(T l, T r) {\n        auto itr =\n            std::prev(set.lower_bound({l,\
    \ std::numeric_limits<T>::min()}));\n        if (l <= itr->second) {\n       \
    \     assert(itr->first <= l);\n            l = itr->first;\n            r = std::max(r,\
    \ itr->second);\n            set.erase(itr);\n        }\n        itr = set.lower_bound({l,\
    \ std::numeric_limits<T>::min()});\n        while (itr->first <= r) {\n      \
    \      assert(l <= itr->first);\n            r = std::max(r, itr->second);\n \
    \           itr = set.erase(itr);\n        }\n        set.insert({l, r});\n  \
    \      return;\n    }\n\n    // \u96C6\u5408\u5185\u306E[l, r)\u306B\u542B\u307E\
    \u308C\u3066\u3044\u308B\u8981\u7D20\u3092\u524A\u9664\n    void erase(T l, T\
    \ r) {\n        auto itr =\n            std::prev(set.lower_bound({l, std::numeric_limits<T>::min()}));\n\
    \        if (l < itr->second) {\n            assert(itr->first < l);\n       \
    \     set.insert({itr->first, l});\n            if (r < itr->second) {\n     \
    \           set.insert({r, itr->second});\n            }\n            set.erase(itr);\n\
    \        }\n        itr = set.lower_bound({l, std::numeric_limits<T>::min()});\n\
    \        while (itr->first < r) {\n            if (itr->second <= r) {\n     \
    \           itr = set.erase(itr);\n            } else {\n                set.insert({r,\
    \ itr->second});\n                set.erase(itr);\n                break;\n  \
    \          }\n        }\n        return;\n    }\n\n    bool find(T x) const {\n\
    \        auto itr =\n            std::prev(set.upper_bound({x, std::numeric_limits<T>::max()}));\n\
    \        if (x < itr->second) {\n            assert(itr->first <= x);\n      \
    \      return true;\n        } else {\n            return false;\n        }\n\
    \    }\n\n    bool find(T l, T r) const {\n        auto itr =\n            std::prev(set.upper_bound({l,\
    \ std::numeric_limits<T>::max()}));\n        if (r <= itr->second) {\n       \
    \     assert(itr->first <= l);\n            return true;\n        } else {\n \
    \           return false;\n        }\n    }\n\n    std::pair<T, T> belong(T x)\
    \ const {\n        auto itr =\n            std::prev(set.upper_bound({x, std::numeric_limits<T>::max()}));\n\
    \        if (x <= itr->second) {\n            assert(itr->first <= x);\n     \
    \       return *itr;\n        } else {\n            return {0, 0};\n        }\n\
    \    }\n\n    std::pair<T, T> lower_bound(T l) const {\n        return *set.lower_bound({l,\
    \ std::numeric_limits<T>::min()});\n    }\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <limits>\n#include <set>\n\n\
    namespace ebi {\n\ntemplate <class T> struct section_set {\n  private:\n    std::set<std::pair<T,\
    \ T>> set;\n\n  public:\n    section_set() {\n        set.insert(\n          \
    \  {std::numeric_limits<T>::min(), std::numeric_limits<T>::min()});\n        set.insert(\n\
    \            {std::numeric_limits<T>::max(), std::numeric_limits<T>::max()});\n\
    \    }\n\n    std::set<std::pair<T, T>> sections() const {\n        return set;\n\
    \    }\n\n    // [l, r)\u3092\u8FFD\u52A0\n    void insert(T l, T r) {\n     \
    \   auto itr =\n            std::prev(set.lower_bound({l, std::numeric_limits<T>::min()}));\n\
    \        if (l <= itr->second) {\n            assert(itr->first <= l);\n     \
    \       l = itr->first;\n            r = std::max(r, itr->second);\n         \
    \   set.erase(itr);\n        }\n        itr = set.lower_bound({l, std::numeric_limits<T>::min()});\n\
    \        while (itr->first <= r) {\n            assert(l <= itr->first);\n   \
    \         r = std::max(r, itr->second);\n            itr = set.erase(itr);\n \
    \       }\n        set.insert({l, r});\n        return;\n    }\n\n    // \u96C6\
    \u5408\u5185\u306E[l, r)\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u8981\u7D20\
    \u3092\u524A\u9664\n    void erase(T l, T r) {\n        auto itr =\n         \
    \   std::prev(set.lower_bound({l, std::numeric_limits<T>::min()}));\n        if\
    \ (l < itr->second) {\n            assert(itr->first < l);\n            set.insert({itr->first,\
    \ l});\n            if (r < itr->second) {\n                set.insert({r, itr->second});\n\
    \            }\n            set.erase(itr);\n        }\n        itr = set.lower_bound({l,\
    \ std::numeric_limits<T>::min()});\n        while (itr->first < r) {\n       \
    \     if (itr->second <= r) {\n                itr = set.erase(itr);\n       \
    \     } else {\n                set.insert({r, itr->second});\n              \
    \  set.erase(itr);\n                break;\n            }\n        }\n       \
    \ return;\n    }\n\n    bool find(T x) const {\n        auto itr =\n         \
    \   std::prev(set.upper_bound({x, std::numeric_limits<T>::max()}));\n        if\
    \ (x < itr->second) {\n            assert(itr->first <= x);\n            return\
    \ true;\n        } else {\n            return false;\n        }\n    }\n\n   \
    \ bool find(T l, T r) const {\n        auto itr =\n            std::prev(set.upper_bound({l,\
    \ std::numeric_limits<T>::max()}));\n        if (r <= itr->second) {\n       \
    \     assert(itr->first <= l);\n            return true;\n        } else {\n \
    \           return false;\n        }\n    }\n\n    std::pair<T, T> belong(T x)\
    \ const {\n        auto itr =\n            std::prev(set.upper_bound({x, std::numeric_limits<T>::max()}));\n\
    \        if (x <= itr->second) {\n            assert(itr->first <= x);\n     \
    \       return *itr;\n        } else {\n            return {0, 0};\n        }\n\
    \    }\n\n    std::pair<T, T> lower_bound(T l) const {\n        return *set.lower_bound({l,\
    \ std::numeric_limits<T>::min()});\n    }\n};\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/section_set.hpp
  requiredBy: []
  timestamp: '2023-10-30 03:02:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_2152.test.cpp
documentation_of: data_structure/section_set.hpp
layout: document
title: section set
---

## 説明

区間を管理するセットである。

### insert(l, r)

$[l, r)$ を追加

### erase(l, r)

$[l, r)$ を削除

### find(x)

$x$ が含まれるか判定

### find(l, r)

$[l, r)$ が含まれるか判定

### belong(x)

$x$ の含まれる区間 $[l, r)$ を返す。 $x$ を含む区間がないならば $[0, 0)$ を返す。

### lower_bound(l)

左端が $l$ 以上の区間を返す。