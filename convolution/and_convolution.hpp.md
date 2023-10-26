---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: set_function/superset_transform.hpp
    title: "Superset Transform (Zeta / M\xF6bius)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/Bitwise_And_Convolution.test.cpp
    title: test/convolution/Bitwise_And_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/and_convolution.hpp\"\n\n#include <vector>\n\
    \n#line 2 \"set_function/superset_transform.hpp\"\n\n#include <bit>\n#include\
    \ <cassert>\n#line 6 \"set_function/superset_transform.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <class T> std::vector<T> superset_zeta(const std::vector<T> &a)\
    \ {\n    int n = std::bit_width(a.size()) - 1;\n    assert((1 << n) == (int)a.size());\n\
    \    std::vector<T> ra = a;\n    for (int i = 0; i < n; i++) {\n        int w\
    \ = 1 << i;\n        for (int p = 0; p < (1 << n); p += 2 * w) {\n           \
    \ for (int s = p; s < p + w; s++) {\n                int t = s | w;\n        \
    \        ra[s] += ra[t];\n            }\n        }\n    }\n    return ra;\n}\n\
    \ntemplate <class T> std::vector<T> superset_mobius(const std::vector<T> &ra)\
    \ {\n    int n = std::bit_width(ra.size()) - 1;\n    assert((1 << n) == (int)ra.size());\n\
    \    std::vector<T> a = ra;\n    for (int i = 0; i < n; i++) {\n        int w\
    \ = 1 << i;\n        for (int p = 0; p < (1 << n); p += 2 * w) {\n           \
    \ for (int s = p; s < p + w; s++) {\n                int t = s | w;\n        \
    \        a[s] -= a[t];\n            }\n        }\n    }\n    return a;\n}\n\n\
    }  // namespace ebi\n#line 6 \"convolution/and_convolution.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <class T>\nstd::vector<T> and_convolution(const std::vector<T>\
    \ &a,\n                               const std::vector<T> &b) {\n    int n =\
    \ a.size();\n    auto ra = superset_zeta(a);\n    auto rb = superset_zeta(b);\n\
    \    for (int i = 0; i < n; i++) {\n        ra[i] *= rb[i];\n    }\n    return\
    \ superset_mobius(ra);\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <vector>\n\n#include \"../set_function/superset_transform.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T>\nstd::vector<T> and_convolution(const\
    \ std::vector<T> &a,\n                               const std::vector<T> &b)\
    \ {\n    int n = a.size();\n    auto ra = superset_zeta(a);\n    auto rb = superset_zeta(b);\n\
    \    for (int i = 0; i < n; i++) {\n        ra[i] *= rb[i];\n    }\n    return\
    \ superset_mobius(ra);\n}\n\n}  // namespace ebi"
  dependsOn:
  - set_function/superset_transform.hpp
  isVerificationFile: false
  path: convolution/and_convolution.hpp
  requiredBy: []
  timestamp: '2023-10-26 18:33:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/Bitwise_And_Convolution.test.cpp
documentation_of: convolution/and_convolution.hpp
layout: document
title: Bitwise AND Convolution
---

## 説明

長さ $2^N$ の整数列 $a$ と $b$ について、 $c_k = \sum_{i\& j=k} a_i b_j$ を求める。
$O(N 2^N)$