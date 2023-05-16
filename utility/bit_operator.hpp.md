---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: convolution/subset_convolution.hpp
    title: convolution/subset_convolution.hpp
  - icon: ':question:'
    path: set_function/ranked_zeta.hpp
    title: set_function/ranked_zeta.hpp
  - icon: ':heavy_check_mark:'
    path: set_function/sps_exp.hpp
    title: set_function/sps_exp.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Exp_of_Set_Power_Series.test.cpp
    title: test/Exp_of_Set_Power_Series.test.cpp
  - icon: ':x:'
    path: test/subset_convolution.test.cpp
    title: test/subset_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/bit_operator.hpp\"\n\nnamespace ebi {\n\nint popcnt(int\
    \ x) {\n    return __builtin_popcount(x);\n}\n\nint topbit(int x) {\n    return\
    \ (x == 0) ? -1 : 31 - __builtin_clz(x);\n}\n\nint lowbit(int x) {\n    return\
    \ (x == 0) ? -1 : __builtin_ctz(x);\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\nnamespace ebi {\n\nint popcnt(int x) {\n    return __builtin_popcount(x);\n\
    }\n\nint topbit(int x) {\n    return (x == 0) ? -1 : 31 - __builtin_clz(x);\n\
    }\n\nint lowbit(int x) {\n    return (x == 0) ? -1 : __builtin_ctz(x);\n}\n\n\
    }  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: utility/bit_operator.hpp
  requiredBy:
  - convolution/subset_convolution.hpp
  - set_function/sps_exp.hpp
  - set_function/ranked_zeta.hpp
  timestamp: '2023-05-15 17:34:24+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/Exp_of_Set_Power_Series.test.cpp
  - test/subset_convolution.test.cpp
documentation_of: utility/bit_operator.hpp
layout: document
redirect_from:
- /library/utility/bit_operator.hpp
- /library/utility/bit_operator.hpp.html
title: utility/bit_operator.hpp
---
