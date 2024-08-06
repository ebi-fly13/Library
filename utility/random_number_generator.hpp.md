---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/maximum_matching_size.hpp
    title: Maximum Matching Size
  - icon: ':heavy_check_mark:'
    path: matrix/black_box_linear_algebra.hpp
    title: Black Box Linear Algebra
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: Rolling Hash
  - icon: ':heavy_check_mark:'
    path: string/wildcard_pattern_matching.hpp
    title: Wildcard Pattern Matching
  - icon: ':heavy_check_mark:'
    path: tree/rooted_tree_hash.hpp
    title: Rooted Tree Hash
  - icon: ':heavy_check_mark:'
    path: utility/hash.hpp
    title: Hash structure
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2444.test.cpp
    title: test/aoj/aoj_2444.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Convolution_2D.test.cpp
    title: test/convolution/Convolution_2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Parallel_DSU_Stress_test.test.cpp
    title: test/data_structure/Range_Parallel_DSU_Stress_test.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Negative_Binomial_Coefficient.test.cpp
    title: test/math/Negative_Binomial_Coefficient.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Powers_Iota.test.cpp
    title: test/math/Sum_of_Powers_Iota.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix/Determinant_of_Sparse_Matrix.test.cpp
    title: test/matrix/Determinant_of_Sparse_Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/string/Wildcard_Pattern_Matching.test.cpp
    title: test/string/Wildcard_Pattern_Matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
    title: test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1112.test.cpp
    title: test/yuki/yuki_1112.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/random_number_generator.hpp\"\n\r\n#include <algorithm>\r\
    \n#include <cstdint>\r\n#include <numeric>\r\n#include <random>\r\n#include <vector>\r\
    \n\r\nnamespace ebi {\r\n\r\nstruct random_number_generator {\r\n    random_number_generator(int\
    \ seed = -1) {\r\n        if (seed < 0) seed = rnd();\r\n        mt.seed(seed);\r\
    \n    }\r\n\r\n    void set_seed(int seed) {\r\n        mt.seed(seed);\r\n   \
    \ }\r\n\r\n    template <class T> T get(T a, T b) {\r\n        std::uniform_int_distribution<T>\
    \ dist(a, b - 1);\r\n        return dist(mt);\r\n    }\r\n\r\n    std::vector<int>\
    \ get_permutation(int n) {\r\n        std::vector<int> p(n);\r\n        std::iota(p.begin(),\
    \ p.end(), 0);\r\n        std::shuffle(p.begin(), p.end(), mt);\r\n        return\
    \ p;\r\n    }\r\n\r\n  private:\r\n    std::mt19937_64 mt;\r\n    std::random_device\
    \ rnd;\r\n};\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <algorithm>\r\n#include <cstdint>\r\n#include\
    \ <numeric>\r\n#include <random>\r\n#include <vector>\r\n\r\nnamespace ebi {\r\
    \n\r\nstruct random_number_generator {\r\n    random_number_generator(int seed\
    \ = -1) {\r\n        if (seed < 0) seed = rnd();\r\n        mt.seed(seed);\r\n\
    \    }\r\n\r\n    void set_seed(int seed) {\r\n        mt.seed(seed);\r\n    }\r\
    \n\r\n    template <class T> T get(T a, T b) {\r\n        std::uniform_int_distribution<T>\
    \ dist(a, b - 1);\r\n        return dist(mt);\r\n    }\r\n\r\n    std::vector<int>\
    \ get_permutation(int n) {\r\n        std::vector<int> p(n);\r\n        std::iota(p.begin(),\
    \ p.end(), 0);\r\n        std::shuffle(p.begin(), p.end(), mt);\r\n        return\
    \ p;\r\n    }\r\n\r\n  private:\r\n    std::mt19937_64 mt;\r\n    std::random_device\
    \ rnd;\r\n};\r\n\r\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: utility/random_number_generator.hpp
  requiredBy:
  - string/wildcard_pattern_matching.hpp
  - string/rolling_hash.hpp
  - tree/rooted_tree_hash.hpp
  - graph/maximum_matching_size.hpp
  - matrix/black_box_linear_algebra.hpp
  - utility/hash.hpp
  timestamp: '2024-08-06 16:15:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/Convolution_2D.test.cpp
  - test/yuki/yuki_1112.test.cpp
  - test/data_structure/Range_Parallel_DSU_Stress_test.test.cpp
  - test/math/Negative_Binomial_Coefficient.test.cpp
  - test/math/Sum_of_Powers_Iota.test.cpp
  - test/string/Wildcard_Pattern_Matching.test.cpp
  - test/aoj/aoj_2444.test.cpp
  - test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
  - test/matrix/Determinant_of_Sparse_Matrix.test.cpp
documentation_of: utility/random_number_generator.hpp
layout: document
title: Random Number Generator
---

## 説明

整数の乱数生成機。

### set_seed(seed)

シードを指定する。

### get(a, b)

$[a, b)$ の範囲から一様乱数を生成する。