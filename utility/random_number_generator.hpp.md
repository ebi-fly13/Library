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
  - utility/hash.hpp
  - tree/rooted_tree_hash.hpp
  - string/rolling_hash.hpp
  timestamp: '2023-12-26 02:24:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_2444.test.cpp
  - test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
documentation_of: utility/random_number_generator.hpp
layout: document
redirect_from:
- /library/utility/random_number_generator.hpp
- /library/utility/random_number_generator.hpp.html
title: utility/random_number_generator.hpp
---