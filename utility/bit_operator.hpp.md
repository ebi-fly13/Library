---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: set_function/ranked_zeta.hpp
    title: set_function/ranked_zeta.hpp
  - icon: ':heavy_check_mark:'
    path: set_function/sps_exp.hpp
    title: set_function/sps_exp.hpp
  - icon: ':heavy_check_mark:'
    path: set_function/subset_convolution.hpp
    title: set_function/subset_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Exp_of_Set_Power_Series.test.cpp
    title: test/Exp_of_Set_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/subset_convolution.test.cpp
    title: test/subset_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - set_function/subset_convolution.hpp
  - set_function/sps_exp.hpp
  - set_function/ranked_zeta.hpp
  timestamp: '2023-05-15 17:34:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
