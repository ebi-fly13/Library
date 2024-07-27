---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/or_convolution.hpp
    title: Bitwise OR Convolution
  - icon: ':heavy_check_mark:'
    path: graph/chromatic_number.hpp
    title: "Chromatic Number (\u5F69\u8272\u6570)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/Bitwise_OR_Convolution.test.cpp
    title: test/convolution/Bitwise_OR_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Chromatic_Number.test.cpp
    title: test/graph/Chromatic_Number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"set_function/subset_transform.hpp\"\n\n#include <bit>\n\
    #include <cassert>\n#include <vector>\n\nnamespace ebi {\n\ntemplate <class T>\
    \ std::vector<T> subset_zeta(const std::vector<T> &a) {\n    int n = std::bit_width(a.size())\
    \ - 1;\n    assert((1 << n) == (int)a.size());\n    std::vector<T> ra = a;\n \
    \   for (int i = 0; i < n; i++) {\n        int w = 1 << i;\n        for (int p\
    \ = 0; p < (1 << n); p += 2 * w) {\n            for (int s = p; s < p + w; s++)\
    \ {\n                int t = s | w;\n                ra[t] += ra[s];\n       \
    \     }\n        }\n    }\n    return ra;\n}\n\ntemplate <class T> std::vector<T>\
    \ subset_mobius(const std::vector<T> &ra) {\n    int n = std::bit_width(ra.size())\
    \ - 1;\n    assert((1 << n) == (int)ra.size());\n    std::vector<T> a = ra;\n\
    \    for (int i = 0; i < n; i++) {\n        int w = 1 << i;\n        for (int\
    \ p = 0; p < (1 << n); p += 2 * w) {\n            for (int s = p; s < p + w; s++)\
    \ {\n                int t = s | w;\n                a[t] -= a[s];\n         \
    \   }\n        }\n    }\n    return a;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <bit>\n#include <cassert>\n#include <vector>\n\n\
    namespace ebi {\n\ntemplate <class T> std::vector<T> subset_zeta(const std::vector<T>\
    \ &a) {\n    int n = std::bit_width(a.size()) - 1;\n    assert((1 << n) == (int)a.size());\n\
    \    std::vector<T> ra = a;\n    for (int i = 0; i < n; i++) {\n        int w\
    \ = 1 << i;\n        for (int p = 0; p < (1 << n); p += 2 * w) {\n           \
    \ for (int s = p; s < p + w; s++) {\n                int t = s | w;\n        \
    \        ra[t] += ra[s];\n            }\n        }\n    }\n    return ra;\n}\n\
    \ntemplate <class T> std::vector<T> subset_mobius(const std::vector<T> &ra) {\n\
    \    int n = std::bit_width(ra.size()) - 1;\n    assert((1 << n) == (int)ra.size());\n\
    \    std::vector<T> a = ra;\n    for (int i = 0; i < n; i++) {\n        int w\
    \ = 1 << i;\n        for (int p = 0; p < (1 << n); p += 2 * w) {\n           \
    \ for (int s = p; s < p + w; s++) {\n                int t = s | w;\n        \
    \        a[t] -= a[s];\n            }\n        }\n    }\n    return a;\n}\n\n\
    }  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: set_function/subset_transform.hpp
  requiredBy:
  - graph/chromatic_number.hpp
  - convolution/or_convolution.hpp
  timestamp: '2023-10-26 18:43:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Chromatic_Number.test.cpp
  - test/convolution/Bitwise_OR_Convolution.test.cpp
documentation_of: set_function/subset_transform.hpp
layout: document
title: "Subset Transform (Zeta / M\xF6bius)"
---

## 説明

$N$ 要素の集合の冪集合に値が定義されている配列 $a$ について $\zeta a$ を部分集合の累積和とする。
つまり以下の式を満たす $\zeta a$ を求めることを $\zeta$ 変換という。逆変換をメビウス変換という。

$$
\zeta a_{S} = \sum_{T \subset S} a_T
$$

いずれも、 $O(N2^N)$ で変換することができる。