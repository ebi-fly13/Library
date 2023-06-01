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
    path: fps/fps_sqrt.hpp
    title: $\sqrt{f}$
  - icon: ':warning:'
    path: math/combination.hpp
    title: math/combination.hpp
  - icon: ':warning:'
    path: math/lagrange_interpolation.hpp
    title: math/lagrange_interpolation.hpp
  - icon: ':heavy_check_mark:'
    path: math/mod_sqrt.hpp
    title: math/mod_sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: utility/dynamic_modint.hpp
    title: utility/dynamic_modint.hpp
  - icon: ':question:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/Bitwise_And_Convolution.test.cpp
    title: test/Bitwise_And_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Bitwise_OR_Convolution.test.cpp
    title: test/Bitwise_OR_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Bitwise_Xor_Convolution.test.cpp
    title: test/Bitwise_Xor_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Convolution_Mod_1000000007.test.cpp
    title: test/Convolution_Mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Determinant_of_Matrix.test.cpp
    title: test/Determinant_of_Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Division_of_Polynomials.test.cpp
    title: test/Division_of_Polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/DynamicSegmentTree.test.cpp
    title: test/DynamicSegmentTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Exp_of_Formal_Power_Series.test.cpp
    title: test/Exp_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Exp_of_Set_Power_Series.test.cpp
    title: test/Exp_of_Set_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ImplicitTreap.test.cpp
    title: test/ImplicitTreap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Inv_of_Formal_Power_Series.test.cpp
    title: test/Inv_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
    title: test/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LazySegtree.test.cpp
    title: test/LazySegtree.test.cpp
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
    path: test/SWAG.test.cpp
    title: test/SWAG.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Sqrt_Mod.test.cpp
    title: test/Sqrt_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Sqrt_of_Formal_Power_Series.test.cpp
    title: test/Sqrt_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Tree_Path_Composite_Sum.test.cpp
    title: test/Tree_Path_Composite_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2863.test.cpp
    title: test/aoj/aoj_2863.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution.test.cpp
    title: test/convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/pow.test.cpp
    title: test/pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/subset_convolution.test.cpp
    title: test/subset_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_set_path_compositie.test.cpp
    title: test/vertex_set_path_compositie.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 2 "utility/modint_base.hpp"


    #include <type_traits>


    namespace ebi {


    namespace internal {


    struct modint_base {};


    template <class T> using is_modint = std::is_base_of<modint_base, T>;

    template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;


    }  // namespace internal


    }  // namespace ebi

    '
  code: '#pragma once


    #include <type_traits>


    namespace ebi {


    namespace internal {


    struct modint_base {};


    template <class T> using is_modint = std::is_base_of<modint_base, T>;

    template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;


    }  // namespace internal


    }  // namespace ebi'
  dependsOn: []
  isVerificationFile: false
  path: utility/modint_base.hpp
  requiredBy:
  - convolution/ntt.hpp
  - convolution/arbitary_ntt.hpp
  - math/combination.hpp
  - math/lagrange_interpolation.hpp
  - math/mod_sqrt.hpp
  - utility/dynamic_modint.hpp
  - utility/modint.hpp
  - fps/fps_sqrt.hpp
  timestamp: '2023-05-31 02:50:45+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/SWAG.test.cpp
  - test/aoj/aoj_2863.test.cpp
  - test/Convolution_Mod_1000000007.test.cpp
  - test/vertex_set_path_compositie.test.cpp
  - test/Sqrt_Mod.test.cpp
  - test/Sqrt_of_Formal_Power_Series.test.cpp
  - test/convolution.test.cpp
  - test/Bitwise_Xor_Convolution.test.cpp
  - test/Exp_of_Set_Power_Series.test.cpp
  - test/Determinant_of_Matrix.test.cpp
  - test/Log_of_Formal_Power_Series.test.cpp
  - test/Division_of_Polynomials.test.cpp
  - test/subset_convolution.test.cpp
  - test/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  - test/Bitwise_OR_Convolution.test.cpp
  - test/Inv_of_Formal_Power_Series.test.cpp
  - test/Tree_Path_Composite_Sum.test.cpp
  - test/Bitwise_And_Convolution.test.cpp
  - test/Exp_of_Formal_Power_Series.test.cpp
  - test/Polynomial_Taylor_Shift.test.cpp
  - test/pow.test.cpp
  - test/Pow_of_Formal_Power_Series.test.cpp
  - test/DynamicSegmentTree.test.cpp
  - test/LazySegtree.test.cpp
  - test/ImplicitTreap.test.cpp
documentation_of: utility/modint_base.hpp
layout: document
redirect_from:
- /library/utility/modint_base.hpp
- /library/utility/modint_base.hpp.html
title: utility/modint_base.hpp
---
