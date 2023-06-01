---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/arbitary_ntt.hpp
    title: convolution/arbitary_ntt.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: convolution/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/subset_convolution.hpp
    title: convolution/subset_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: set_function/ranked_zeta.hpp
    title: set_function/ranked_zeta.hpp
  - icon: ':heavy_check_mark:'
    path: set_function/sps_exp.hpp
    title: set_function/sps_exp.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Convolution_Mod_1000000007.test.cpp
    title: test/Convolution_Mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Division_of_Polynomials.test.cpp
    title: test/Division_of_Polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Exp_of_Formal_Power_Series.test.cpp
    title: test/Exp_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Exp_of_Set_Power_Series.test.cpp
    title: test/Exp_of_Set_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Inv_of_Formal_Power_Series.test.cpp
    title: test/Inv_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
    title: test/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Log_of_Formal_Power_Series.test.cpp
    title: test/Log_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Polynomial_Taylor_Shift.test.cpp
    title: test/Polynomial_Taylor_Shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Pow_of_Formal_Power_Series.test.cpp
    title: test/Pow_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Sqrt_of_Formal_Power_Series.test.cpp
    title: test/Sqrt_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution.test.cpp
    title: test/convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/subset_convolution.test.cpp
    title: test/subset_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/bit_operator.hpp\"\n\nnamespace ebi {\n\nconstexpr\
    \ int bsf_constexpr(unsigned int n) {\n    int x = 0;\n    while (!(n & (1 <<\
    \ x))) x++;\n    return x;\n}\n\nint bit_reverse(int n, int bit_size) {\n    int\
    \ rev_n = 0;\n    for (int i = 0; i < bit_size; i++) {\n        rev_n |= ((n >>\
    \ i) & 1) << (bit_size - i - 1);\n    }\n    return rev_n;\n}\n\nint ceil_pow2(int\
    \ n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n)) x++;\n    return\
    \ x;\n}\n\nint popcnt(int x) {\n    return __builtin_popcount(x);\n}\n\nint msb(int\
    \ x) {\n    return (x == 0) ? -1 : 31 - __builtin_clz(x);\n}\n\nint bsf(int x)\
    \ {\n    return (x == 0) ? -1 : __builtin_ctz(x);\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\nnamespace ebi {\n\nconstexpr int bsf_constexpr(unsigned int\
    \ n) {\n    int x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n}\n\n\
    int bit_reverse(int n, int bit_size) {\n    int rev_n = 0;\n    for (int i = 0;\
    \ i < bit_size; i++) {\n        rev_n |= ((n >> i) & 1) << (bit_size - i - 1);\n\
    \    }\n    return rev_n;\n}\n\nint ceil_pow2(int n) {\n    int x = 0;\n    while\
    \ ((1U << x) < (unsigned int)(n)) x++;\n    return x;\n}\n\nint popcnt(int x)\
    \ {\n    return __builtin_popcount(x);\n}\n\nint msb(int x) {\n    return (x ==\
    \ 0) ? -1 : 31 - __builtin_clz(x);\n}\n\nint bsf(int x) {\n    return (x == 0)\
    \ ? -1 : __builtin_ctz(x);\n}\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: utility/bit_operator.hpp
  requiredBy:
  - convolution/subset_convolution.hpp
  - convolution/ntt.hpp
  - convolution/arbitary_ntt.hpp
  - set_function/sps_exp.hpp
  - set_function/ranked_zeta.hpp
  timestamp: '2023-05-17 17:05:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  - test/Inv_of_Formal_Power_Series.test.cpp
  - test/Pow_of_Formal_Power_Series.test.cpp
  - test/Exp_of_Formal_Power_Series.test.cpp
  - test/Exp_of_Set_Power_Series.test.cpp
  - test/Convolution_Mod_1000000007.test.cpp
  - test/Polynomial_Taylor_Shift.test.cpp
  - test/Sqrt_of_Formal_Power_Series.test.cpp
  - test/Log_of_Formal_Power_Series.test.cpp
  - test/subset_convolution.test.cpp
  - test/Division_of_Polynomials.test.cpp
  - test/convolution.test.cpp
documentation_of: utility/bit_operator.hpp
layout: document
redirect_from:
- /library/utility/bit_operator.hpp
- /library/utility/bit_operator.hpp.html
title: utility/bit_operator.hpp
---
