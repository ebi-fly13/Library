---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: set_function/superset_transform.hpp
    title: "Superset Transform (Zeta / M\xF6bius)"
  - icon: ':question:'
    path: utility/bit_operator.hpp
    title: utility/bit_operator.hpp
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
    \n#line 2 \"set_function/superset_transform.hpp\"\n\n#include <cassert>\n#line\
    \ 5 \"set_function/superset_transform.hpp\"\n\n#line 2 \"utility/bit_operator.hpp\"\
    \n\nnamespace ebi {\n\nconstexpr int bsf_constexpr(unsigned int n) {\n    int\
    \ x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n}\n\nint bit_reverse(int\
    \ n, int bit_size) {\n    int rev_n = 0;\n    for (int i = 0; i < bit_size; i++)\
    \ {\n        rev_n |= ((n >> i) & 1) << (bit_size - i - 1);\n    }\n    return\
    \ rev_n;\n}\n\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) <\
    \ (unsigned int)(n)) x++;\n    return x;\n}\n\nint popcnt(int x) {\n    return\
    \ __builtin_popcount(x);\n}\n\nint msb(int x) {\n    return (x == 0) ? -1 : 31\
    \ - __builtin_clz(x);\n}\n\nint bsf(int x) {\n    return (x == 0) ? -1 : __builtin_ctz(x);\n\
    }\n\n}  // namespace ebi\n#line 7 \"set_function/superset_transform.hpp\"\n\n\
    namespace ebi {\n\ntemplate <class T> std::vector<T> superset_zeta(const std::vector<T>\
    \ &a) {\n    int n = msb(a.size());\n    assert((1 << n) == (int)a.size());\n\
    \    std::vector<T> ra = a;\n    for (int i = 0; i < n; i++) {\n        int w\
    \ = 1 << i;\n        for (int p = 0; p < (1 << n); p += 2 * w) {\n           \
    \ for (int s = p; s < p + w; s++) {\n                int t = s | w;\n        \
    \        ra[s] += ra[t];\n            }\n        }\n    }\n    return ra;\n}\n\
    \ntemplate <class T> std::vector<T> superset_mobius(const std::vector<T> &ra)\
    \ {\n    int n = msb(ra.size());\n    assert((1 << n) == (int)ra.size());\n  \
    \  std::vector<T> a = ra;\n    for (int i = 0; i < n; i++) {\n        int w =\
    \ 1 << i;\n        for (int p = 0; p < (1 << n); p += 2 * w) {\n            for\
    \ (int s = p; s < p + w; s++) {\n                int t = s | w;\n            \
    \    a[s] -= a[t];\n            }\n        }\n    }\n    return a;\n}\n\n}  //\
    \ namespace ebi\n#line 6 \"convolution/and_convolution.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <class T>\nstd::vector<T> and_convolution(const std::vector<T>\
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
  - utility/bit_operator.hpp
  isVerificationFile: false
  path: convolution/and_convolution.hpp
  requiredBy: []
  timestamp: '2023-06-19 14:38:20+09:00'
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