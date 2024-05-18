---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: Rolling Hash
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
    path: test/data_structure/Range_Parallel_DSU.test.cpp
    title: test/data_structure/Range_Parallel_DSU.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Negative_Binomial_Coefficient.test.cpp
    title: test/math/Negative_Binomial_Coefficient.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Powers_Iota.test.cpp
    title: test/math/Sum_of_Powers_Iota.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
    title: test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/random_number_generator.hpp\"\n\r\n#include <cstdint>\r\
    \n#include <random>\r\n\r\nnamespace ebi {\r\n\r\nstruct random_number_generator\
    \ {\r\n    random_number_generator(int seed = -1) {\r\n        if (seed < 0) seed\
    \ = rnd();\r\n        mt.seed(seed);\r\n    }\r\n\r\n    void set_seed(int seed)\
    \ {\r\n        mt.seed(seed);\r\n    }\r\n\r\n    template <class T> T get(T a,\
    \ T b) {\r\n        std::uniform_int_distribution<T> dist(a, b - 1);\r\n     \
    \   return dist(mt);\r\n    }\r\n\r\n  private:\r\n    std::mt19937_64 mt;\r\n\
    \    std::random_device rnd;\r\n};\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <cstdint>\r\n#include <random>\r\n\r\nnamespace\
    \ ebi {\r\n\r\nstruct random_number_generator {\r\n    random_number_generator(int\
    \ seed = -1) {\r\n        if (seed < 0) seed = rnd();\r\n        mt.seed(seed);\r\
    \n    }\r\n\r\n    void set_seed(int seed) {\r\n        mt.seed(seed);\r\n   \
    \ }\r\n\r\n    template <class T> T get(T a, T b) {\r\n        std::uniform_int_distribution<T>\
    \ dist(a, b - 1);\r\n        return dist(mt);\r\n    }\r\n\r\n  private:\r\n \
    \   std::mt19937_64 mt;\r\n    std::random_device rnd;\r\n};\r\n\r\n}  // namespace\
    \ ebi"
  dependsOn: []
  isVerificationFile: false
  path: utility/random_number_generator.hpp
  requiredBy:
  - string/rolling_hash.hpp
  - utility/hash.hpp
  - tree/rooted_tree_hash.hpp
  timestamp: '2023-12-26 02:24:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_2444.test.cpp
  - test/data_structure/Range_Parallel_DSU.test.cpp
  - test/math/Negative_Binomial_Coefficient.test.cpp
  - test/math/Sum_of_Powers_Iota.test.cpp
  - test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
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