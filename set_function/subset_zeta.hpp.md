---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/bit_operator.hpp
    title: utility/bit_operator.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/or_convolution.hpp
    title: Bitwise OR Convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Bitwise_OR_Convolution.test.cpp
    title: test/Bitwise_OR_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"set_function/subset_zeta.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\n#line 2 \"utility/bit_operator.hpp\"\n\nnamespace ebi {\n\nconstexpr\
    \ int bsf_constexpr(unsigned int n) {\n    int x = 0;\n    while (!(n & (1 <<\
    \ x))) x++;\n    return x;\n}\n\nint bit_reverse(int n, int bit_size) {\n    int\
    \ rev_n = 0;\n    for (int i = 0; i < bit_size; i++) {\n        rev_n |= ((n >>\
    \ i) & 1) << (bit_size - i - 1);\n    }\n    return rev_n;\n}\n\nint ceil_pow2(int\
    \ n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n)) x++;\n    return\
    \ x;\n}\n\nint popcnt(int x) {\n    return __builtin_popcount(x);\n}\n\nint msb(int\
    \ x) {\n    return (x == 0) ? -1 : 31 - __builtin_clz(x);\n}\n\nint bsf(int x)\
    \ {\n    return (x == 0) ? -1 : __builtin_ctz(x);\n}\n\n}  // namespace ebi\n\
    #line 7 \"set_function/subset_zeta.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ T> std::vector<T> subset_zeta(const std::vector<T> &a) {\n    int n = msb(a.size());\n\
    \    assert((1 << n) == (int)a.size());\n    std::vector<T> ra = a;\n    for (int\
    \ i = 0; i < n; i++) {\n        int w = 1 << i;\n        for (int p = 0; p < (1\
    \ << n); p += 2 * w) {\n            for (int s = p; s < p + w; s++) {\n      \
    \          int t = s | w;\n                ra[t] += ra[s];\n            }\n  \
    \      }\n    }\n    return ra;\n}\n\ntemplate <class T> std::vector<T> subset_mobius(const\
    \ std::vector<T> &ra) {\n    int n = msb(ra.size());\n    assert((1 << n) == (int)ra.size());\n\
    \    std::vector<T> a = ra;\n    for (int i = 0; i < n; i++) {\n        int w\
    \ = 1 << i;\n        for (int p = 0; p < (1 << n); p += 2 * w) {\n           \
    \ for (int s = p; s < p + w; s++) {\n                int t = s | w;\n        \
    \        a[t] -= a[s];\n            }\n        }\n    }\n    return a;\n}\n\n\
    }  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../utility/bit_operator.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> std::vector<T> subset_zeta(const std::vector<T>\
    \ &a) {\n    int n = msb(a.size());\n    assert((1 << n) == (int)a.size());\n\
    \    std::vector<T> ra = a;\n    for (int i = 0; i < n; i++) {\n        int w\
    \ = 1 << i;\n        for (int p = 0; p < (1 << n); p += 2 * w) {\n           \
    \ for (int s = p; s < p + w; s++) {\n                int t = s | w;\n        \
    \        ra[t] += ra[s];\n            }\n        }\n    }\n    return ra;\n}\n\
    \ntemplate <class T> std::vector<T> subset_mobius(const std::vector<T> &ra) {\n\
    \    int n = msb(ra.size());\n    assert((1 << n) == (int)ra.size());\n    std::vector<T>\
    \ a = ra;\n    for (int i = 0; i < n; i++) {\n        int w = 1 << i;\n      \
    \  for (int p = 0; p < (1 << n); p += 2 * w) {\n            for (int s = p; s\
    \ < p + w; s++) {\n                int t = s | w;\n                a[t] -= a[s];\n\
    \            }\n        }\n    }\n    return a;\n}\n\n}  // namespace ebi"
  dependsOn:
  - utility/bit_operator.hpp
  isVerificationFile: false
  path: set_function/subset_zeta.hpp
  requiredBy:
  - convolution/or_convolution.hpp
  timestamp: '2023-06-01 22:59:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Bitwise_OR_Convolution.test.cpp
documentation_of: set_function/subset_zeta.hpp
layout: document
redirect_from:
- /library/set_function/subset_zeta.hpp
- /library/set_function/subset_zeta.hpp.html
title: set_function/subset_zeta.hpp
---
