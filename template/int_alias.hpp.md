---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: convolution/dirichlet_convolution.hpp
    title: Dirichlet Convolution
  - icon: ':warning:'
    path: convolution/online_convolution.hpp
    title: Online Convolution
  - icon: ':heavy_check_mark:'
    path: data_structure/WaveletMatrix.hpp
    title: Wavelet Matrix
  - icon: ':heavy_check_mark:'
    path: data_structure/bitVector.hpp
    title: data_structure/bitVector.hpp
  - icon: ':x:'
    path: math/DirichletSeries.hpp
    title: Dirichlet Series
  - icon: ':heavy_check_mark:'
    path: math/inversion_number.hpp
    title: Inversion Number
  - icon: ':x:'
    path: math/linear_sieve.hpp
    title: Linear Sieve
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/utility.hpp
    title: template/utility.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2450.test.cpp
    title: test/aoj/aoj_2450.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
    title: test/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Line_Add_Get_Min.test.cpp
    title: test/data_structure/Line_Add_Get_Min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Point_Add_Range_Sum_BIT.test.cpp
    title: test/data_structure/Point_Add_Range_Sum_BIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/data_structure/Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Kth_Smallest.test.cpp
    title: test/data_structure/Range_Kth_Smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Segment_Add_Get_Min.test.cpp
    title: test/data_structure/Segment_Add_Get_Min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Static_Range_Frequency.test.cpp
    title: test/data_structure/Static_Range_Frequency.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra.test.cpp
    title: test/graph/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/fibonacci_heap.test.cpp
    title: test/graph/fibonacci_heap.test.cpp
  - icon: ':x:'
    path: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
    title: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Inversion_Number.test.cpp
    title: test/math/Inversion_Number.test.cpp
  - icon: ':x:'
    path: test/math/Sum_of_Totient_Function.test.cpp
    title: test/math/Sum_of_Totient_Function.test.cpp
  - icon: ':x:'
    path: test/polynomial/Multipoint_Evaluation.test.cpp
    title: test/polynomial/Multipoint_Evaluation.test.cpp
  - icon: ':x:'
    path: test/polynomial/Polynomial_Interpolation.test.cpp
    title: test/polynomial/Polynomial_Interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Tree_Diameter.test.cpp
    title: test/tree/Tree_Diameter.test.cpp
  - icon: ':x:'
    path: test/yuki/yuki_1145.test.cpp
    title: test/yuki/yuki_1145.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_2439.test.cpp
    title: test/yuki/yuki_2439.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 2 "template/int_alias.hpp"


    #include <cstdint>


    namespace ebi {


    using std::size_t;

    using i8 = std::int8_t;

    using u8 = std::uint8_t;

    using i16 = std::int16_t;

    using u16 = std::uint16_t;

    using i32 = std::int32_t;

    using u32 = std::uint32_t;

    using i64 = std::int64_t;

    using u64 = std::uint64_t;

    using i128 = __int128_t;

    using u128 = __uint128_t;


    }

    '
  code: '#pragma once


    #include <cstdint>


    namespace ebi {


    using std::size_t;

    using i8 = std::int8_t;

    using u8 = std::uint8_t;

    using i16 = std::int16_t;

    using u16 = std::uint16_t;

    using i32 = std::int32_t;

    using u32 = std::uint32_t;

    using i64 = std::int64_t;

    using u64 = std::uint64_t;

    using i128 = __int128_t;

    using u128 = __uint128_t;


    }'
  dependsOn: []
  isVerificationFile: false
  path: template/int_alias.hpp
  requiredBy:
  - convolution/dirichlet_convolution.hpp
  - convolution/online_convolution.hpp
  - template/utility.hpp
  - template/template.hpp
  - math/linear_sieve.hpp
  - math/DirichletSeries.hpp
  - math/inversion_number.hpp
  - data_structure/bitVector.hpp
  - data_structure/WaveletMatrix.hpp
  timestamp: '2023-08-11 00:25:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/graph/dijkstra.test.cpp
  - test/graph/fibonacci_heap.test.cpp
  - test/polynomial/Polynomial_Interpolation.test.cpp
  - test/polynomial/Multipoint_Evaluation.test.cpp
  - test/tree/Tree_Diameter.test.cpp
  - test/yuki/yuki_2439.test.cpp
  - test/yuki/yuki_1145.test.cpp
  - test/aoj/aoj_2450.test.cpp
  - test/math/Inversion_Number.test.cpp
  - test/math/Sum_of_Totient_Function.test.cpp
  - test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - test/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  - test/data_structure/Point_Add_Range_Sum_BIT.test.cpp
  - test/data_structure/Range_Affine_Range_Sum.test.cpp
  - test/data_structure/Line_Add_Get_Min.test.cpp
  - test/data_structure/Static_Range_Frequency.test.cpp
  - test/data_structure/Segment_Add_Get_Min.test.cpp
  - test/data_structure/Range_Kth_Smallest.test.cpp
documentation_of: template/int_alias.hpp
layout: document
redirect_from:
- /library/template/int_alias.hpp
- /library/template/int_alias.hpp.html
title: template/int_alias.hpp
---
