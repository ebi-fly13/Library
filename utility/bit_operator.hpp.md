---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/and_convolution.hpp
    title: Bitwise AND Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/or_convolution.hpp
    title: Bitwise OR Convolution
  - icon: ':question:'
    path: convolution/subset_convolution.hpp
    title: Subset Convolution
  - icon: ':x:'
    path: math/stirling_number_1st.hpp
    title: Stirling Numbers of the First Kind
  - icon: ':x:'
    path: math/stirling_number_2nd.hpp
    title: Stirling Numbers of the Second Kind
  - icon: ':x:'
    path: set_function/egf_composite_sps.hpp
    title: $f(a)$ (Set Power Series, f is EGF)
  - icon: ':x:'
    path: set_function/exp_of_sps.hpp
    title: $\exp {a}$ (Set Power Series)
  - icon: ':x:'
    path: set_function/poly_composite_sps.hpp
    title: $f(a)$ (Set Power Series, f is FPS)
  - icon: ':question:'
    path: set_function/ranked_subset_transform.hpp
    title: Ranked Subset Transform (Zeta / Mobius)
  - icon: ':heavy_check_mark:'
    path: set_function/subset_transform.hpp
    title: "Subset Transform (Zeta / M\xF6bius)"
  - icon: ':heavy_check_mark:'
    path: set_function/superset_transform.hpp
    title: "Superset Transform (Zeta / M\xF6bius)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/Bitwise_And_Convolution.test.cpp
    title: test/convolution/Bitwise_And_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Bitwise_OR_Convolution.test.cpp
    title: test/convolution/Bitwise_OR_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Subset_Convolution.test.cpp
    title: test/convolution/Subset_Convolution.test.cpp
  - icon: ':x:'
    path: test/math/Stirling_Number_of_the_First_Kind.test.cpp
    title: test/math/Stirling_Number_of_the_First_Kind.test.cpp
  - icon: ':x:'
    path: test/math/Stirling_Number_of_the_Second_Kind.test.cpp
    title: test/math/Stirling_Number_of_the_Second_Kind.test.cpp
  - icon: ':x:'
    path: test/set_function/Exp_of_Set_Power_Series.test.cpp
    title: test/set_function/Exp_of_Set_Power_Series.test.cpp
  - icon: ':x:'
    path: test/set_function/Polynomial_Composite_Set_Power_Series.test.cpp
    title: test/set_function/Polynomial_Composite_Set_Power_Series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/bit_operator.hpp\"\n\n#include <bit>\n#include <cstdint>\n\
    \nnamespace ebi {\n\nint bit_reverse(int n, int bit_size) {\n    int rev_n = 0;\n\
    \    for (int i = 0; i < bit_size; i++) {\n        rev_n |= ((n >> i) & 1) <<\
    \ (bit_size - i - 1);\n    }\n    return rev_n;\n}\n\nint msb(int x) {\n    return\
    \ (x == 0) ? -1 : 31 - std::countl_zero(std::uint32_t(x));\n}\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <bit>\n#include <cstdint>\n\nnamespace ebi {\n\n\
    int bit_reverse(int n, int bit_size) {\n    int rev_n = 0;\n    for (int i = 0;\
    \ i < bit_size; i++) {\n        rev_n |= ((n >> i) & 1) << (bit_size - i - 1);\n\
    \    }\n    return rev_n;\n}\n\nint msb(int x) {\n    return (x == 0) ? -1 : 31\
    \ - std::countl_zero(std::uint32_t(x));\n}\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: utility/bit_operator.hpp
  requiredBy:
  - convolution/or_convolution.hpp
  - convolution/and_convolution.hpp
  - convolution/subset_convolution.hpp
  - set_function/subset_transform.hpp
  - set_function/exp_of_sps.hpp
  - set_function/ranked_subset_transform.hpp
  - set_function/poly_composite_sps.hpp
  - set_function/egf_composite_sps.hpp
  - set_function/superset_transform.hpp
  - math/stirling_number_1st.hpp
  - math/stirling_number_2nd.hpp
  timestamp: '2023-10-26 02:17:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/convolution/Subset_Convolution.test.cpp
  - test/convolution/Bitwise_And_Convolution.test.cpp
  - test/convolution/Bitwise_OR_Convolution.test.cpp
  - test/set_function/Exp_of_Set_Power_Series.test.cpp
  - test/set_function/Polynomial_Composite_Set_Power_Series.test.cpp
  - test/math/Stirling_Number_of_the_First_Kind.test.cpp
  - test/math/Stirling_Number_of_the_Second_Kind.test.cpp
documentation_of: utility/bit_operator.hpp
layout: document
redirect_from:
- /library/utility/bit_operator.hpp
- /library/utility/bit_operator.hpp.html
title: utility/bit_operator.hpp
---
