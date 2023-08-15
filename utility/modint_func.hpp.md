---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/composition_of_fps.hpp
    title: $f(g(x))$
  - icon: ':heavy_check_mark:'
    path: fps/compositional_inverse_of_fps.hpp
    title: "$f(x)$ \u306E\u9006\u95A2\u6570"
  - icon: ':question:'
    path: fps/fps.hpp
    title: Formal Power Series
  - icon: ':question:'
    path: fps/fps_sparse.hpp
    title: Formal Power Series (Sparse)
  - icon: ':x:'
    path: fps/fps_sqrt.hpp
    title: $\sqrt{f}$
  - icon: ':x:'
    path: fps/product_of_one_minus_xn.hpp
    title: $\prod (1 - x^{a_i}) \mod x^d$
  - icon: ':x:'
    path: fps/product_of_one_plus_xn.hpp
    title: $\prod (1 + x^{a_i}) \mod x^d$
  - icon: ':question:'
    path: fps/taylor_shift.hpp
    title: $f(x + c)$
  - icon: ':heavy_check_mark:'
    path: math/bernoulli_number.hpp
    title: Bernoulli Number
  - icon: ':heavy_check_mark:'
    path: math/partition_function.hpp
    title: Partition Function
  - icon: ':heavy_check_mark:'
    path: math/stirling_number_1st.hpp
    title: Stirling Numbers of the First Kind
  - icon: ':heavy_check_mark:'
    path: math/stirling_number_2nd.hpp
    title: Stirling Numbers of the Second Kind
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_3361.test.cpp
    title: test/aoj/aoj_3361.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Berunoulli_Number.test.cpp
    title: test/math/Berunoulli_Number.test.cpp
  - icon: ':x:'
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
  - icon: ':x:'
    path: test/math/sharp_p_subset_sum.test.cpp
    title: test/math/sharp_p_subset_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
  - icon: ':x:'
    path: test/polynomial/Division_of_Polynomials.test.cpp
    title: test/polynomial/Division_of_Polynomials.test.cpp
  - icon: ':x:'
    path: test/polynomial/Exp_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Exp_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Exp_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Exp_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':x:'
    path: test/polynomial/Inv_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Inv_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':x:'
    path: test/polynomial/Log_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Log_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Log_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Log_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':x:'
    path: test/polynomial/Polynomial_Taylor_Shift.test.cpp
    title: test/polynomial/Polynomial_Taylor_Shift.test.cpp
  - icon: ':x:'
    path: test/polynomial/Pow_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Pow_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':x:'
    path: test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - icon: ':x:'
    path: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':x:'
    path: test/yuki/yuki_1302.test.cpp
    title: test/yuki/yuki_1302.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/modint_func.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n\nnamespace ebi {\n\ntemplate <class mint> mint inv(int n) {\n  \
    \  static const int mod = mint::mod();\n    static std::vector<mint> dat = {0,\
    \ 1};\n    assert(0 <= n);\n    if (n >= mod) n -= mod;\n    while (int(dat.size())\
    \ <= n) {\n        int num = dat.size();\n        int q = (mod + num - 1) / num;\n\
    \        dat.emplace_back(dat[num * q - mod] * mint(q));\n    }\n    return dat[n];\n\
    }\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\nnamespace ebi {\n\
    \ntemplate <class mint> mint inv(int n) {\n    static const int mod = mint::mod();\n\
    \    static std::vector<mint> dat = {0, 1};\n    assert(0 <= n);\n    if (n >=\
    \ mod) n -= mod;\n    while (int(dat.size()) <= n) {\n        int num = dat.size();\n\
    \        int q = (mod + num - 1) / num;\n        dat.emplace_back(dat[num * q\
    \ - mod] * mint(q));\n    }\n    return dat[n];\n}\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: utility/modint_func.hpp
  requiredBy:
  - math/stirling_number_1st.hpp
  - math/bernoulli_number.hpp
  - math/stirling_number_2nd.hpp
  - math/partition_function.hpp
  - fps/product_of_one_plus_xn.hpp
  - fps/fps.hpp
  - fps/composition_of_fps.hpp
  - fps/fps_sqrt.hpp
  - fps/product_of_one_minus_xn.hpp
  - fps/compositional_inverse_of_fps.hpp
  - fps/taylor_shift.hpp
  - fps/fps_sparse.hpp
  timestamp: '2023-06-08 01:58:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yuki/yuki_1302.test.cpp
  - test/math/Stirling_Number_of_the_First_Kind.test.cpp
  - test/math/Partition_Function_FPS.test.cpp
  - test/math/Berunoulli_Number.test.cpp
  - test/math/sharp_p_subset_sum.test.cpp
  - test/math/Partition_Function_Pentagonal.test.cpp
  - test/math/Stirling_Number_of_the_Second_Kind.test.cpp
  - test/polynomial/Pow_of_Formal_Power_Series.test.cpp
  - test/polynomial/Polynomial_Taylor_Shift.test.cpp
  - test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Exp_of_Formal_Power_Series.test.cpp
  - test/polynomial/Log_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Division_of_Polynomials.test.cpp
  - test/polynomial/Log_of_Formal_Power_Series.test.cpp
  - test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
  - test/polynomial/Inv_of_Formal_Power_Series.test.cpp
  - test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - test/polynomial/Exp_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Composition_of_Formal_Power_Series.test.cpp
  - test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  - test/aoj/aoj_3361.test.cpp
documentation_of: utility/modint_func.hpp
layout: document
redirect_from:
- /library/utility/modint_func.hpp
- /library/utility/modint_func.hpp.html
title: utility/modint_func.hpp
---
