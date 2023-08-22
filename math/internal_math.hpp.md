---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/arbitrary_ntt.hpp
    title: Arbitrary Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/convolution_mod_2_64.hpp
    title: Convolution ($\mod 2^{64}$)
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: NTT Convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/Convolution.test.cpp
    title: test/convolution/Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Convolution_Mod_1000000007.test.cpp
    title: test/convolution/Convolution_Mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Convolution_Mod_2_64.test.cpp
    title: test/convolution/Convolution_Mod_2_64.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Berunoulli_Number.test.cpp
    title: test/math/Berunoulli_Number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
    title: test/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Partition_Function_FPS.test.cpp
    title: test/math/Partition_Function_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Partition_Function_Pentagonal.test.cpp
    title: test/math/Partition_Function_Pentagonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Stirling_Number_of_the_First_Kind.test.cpp
    title: test/math/Stirling_Number_of_the_First_Kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Stirling_Number_of_the_Second_Kind.test.cpp
    title: test/math/Stirling_Number_of_the_Second_Kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/sharp_p_subset_sum.test.cpp
    title: test/math/sharp_p_subset_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Division_of_Polynomials.test.cpp
    title: test/polynomial/Division_of_Polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Exp_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Exp_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Inv_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Inv_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Log_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Log_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Polynomial_Taylor_Shift.test.cpp
    title: test/polynomial/Polynomial_Taylor_Shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Pow_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Pow_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Product_of_Polynomial_Sequence.test.cpp
    title: test/polynomial/Product_of_Polynomial_Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Frequency_Table_of_Tree_Distance.test.cpp
    title: test/tree/Frequency_Table_of_Tree_Distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1302.test.cpp
    title: test/yuki/yuki_1302.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/internal_math.hpp\"\n\n#include <cassert>\n\nnamespace\
    \ ebi {\n\nnamespace internal {\n\nconstexpr int primitive_root_constexpr(int\
    \ m) {\n    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m\
    \ == 469762049) return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353)\
    \ return 3;\n    if (m == 880803841) return 26;\n    return -1;\n}\ntemplate <int\
    \ m> constexpr int primitive_root = primitive_root_constexpr(m);\n\n}  // namespace\
    \ internal\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n\nnamespace ebi {\n\nnamespace internal\
    \ {\n\nconstexpr int primitive_root_constexpr(int m) {\n    if (m == 2) return\
    \ 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049) return 3;\n \
    \   if (m == 754974721) return 11;\n    if (m == 998244353) return 3;\n    if\
    \ (m == 880803841) return 26;\n    return -1;\n}\ntemplate <int m> constexpr int\
    \ primitive_root = primitive_root_constexpr(m);\n\n}  // namespace internal\n\n\
    }  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: math/internal_math.hpp
  requiredBy:
  - convolution/arbitrary_ntt.hpp
  - convolution/convolution_mod_2_64.hpp
  - convolution/ntt.hpp
  timestamp: '2023-07-29 16:06:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Frequency_Table_of_Tree_Distance.test.cpp
  - test/polynomial/Pow_of_Formal_Power_Series.test.cpp
  - test/polynomial/Composition_of_Formal_Power_Series.test.cpp
  - test/polynomial/Log_of_Formal_Power_Series.test.cpp
  - test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
  - test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Inv_of_Formal_Power_Series.test.cpp
  - test/polynomial/Exp_of_Formal_Power_Series.test.cpp
  - test/polynomial/Polynomial_Taylor_Shift.test.cpp
  - test/polynomial/Division_of_Polynomials.test.cpp
  - test/polynomial/Product_of_Polynomial_Sequence.test.cpp
  - test/yuki/yuki_1302.test.cpp
  - test/math/Stirling_Number_of_the_Second_Kind.test.cpp
  - test/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  - test/math/sharp_p_subset_sum.test.cpp
  - test/math/Partition_Function_Pentagonal.test.cpp
  - test/math/Stirling_Number_of_the_First_Kind.test.cpp
  - test/math/Partition_Function_FPS.test.cpp
  - test/math/Berunoulli_Number.test.cpp
  - test/convolution/Convolution.test.cpp
  - test/convolution/Convolution_Mod_2_64.test.cpp
  - test/convolution/Convolution_Mod_1000000007.test.cpp
documentation_of: math/internal_math.hpp
layout: document
redirect_from:
- /library/math/internal_math.hpp
- /library/math/internal_math.hpp.html
title: math/internal_math.hpp
---
