---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/arbitary_ntt.hpp
    title: convolution/arbitary_ntt.hpp
  - icon: ':question:'
    path: convolution/ntt.hpp
    title: convolution/ntt.hpp
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
    path: test/Inv_of_Formal_Power_Series.test.cpp
    title: test/Inv_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
    title: test/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  - icon: ':x:'
    path: test/Log_of_Formal_Power_Series.test.cpp
    title: test/Log_of_Formal_Power_Series.test.cpp
  - icon: ':x:'
    path: test/Polynomial_Taylor_Shift.test.cpp
    title: test/Polynomial_Taylor_Shift.test.cpp
  - icon: ':x:'
    path: test/Pow_of_Formal_Power_Series.test.cpp
    title: test/Pow_of_Formal_Power_Series.test.cpp
  - icon: ':x:'
    path: test/convolution.test.cpp
    title: test/convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/internal_math.hpp\"\n\nnamespace ebi {\n\nnamespace\
    \ internal {\n\nconstexpr int primitive_root_constexpr(int m) {\n    if (m ==\
    \ 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049) return\
    \ 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return 3;\n\
    }\ntemplate <int m> constexpr int primitive_root = primitive_root_constexpr(m);\n\
    \n}  // namespace internal\n\n}  // namespace ebi\n"
  code: "#pragma once\n\nnamespace ebi {\n\nnamespace internal {\n\nconstexpr int\
    \ primitive_root_constexpr(int m) {\n    if (m == 2) return 1;\n    if (m == 167772161)\
    \ return 3;\n    if (m == 469762049) return 3;\n    if (m == 754974721) return\
    \ 11;\n    if (m == 998244353) return 3;\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n}  // namespace internal\n\n}  // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: math/internal_math.hpp
  requiredBy:
  - convolution/ntt.hpp
  - convolution/arbitary_ntt.hpp
  timestamp: '2023-05-17 13:24:36+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  - test/Inv_of_Formal_Power_Series.test.cpp
  - test/Pow_of_Formal_Power_Series.test.cpp
  - test/Exp_of_Formal_Power_Series.test.cpp
  - test/Convolution_Mod_1000000007.test.cpp
  - test/Polynomial_Taylor_Shift.test.cpp
  - test/Log_of_Formal_Power_Series.test.cpp
  - test/Division_of_Polynomials.test.cpp
  - test/convolution.test.cpp
documentation_of: math/internal_math.hpp
layout: document
redirect_from:
- /library/math/internal_math.hpp
- /library/math/internal_math.hpp.html
title: math/internal_math.hpp
---
