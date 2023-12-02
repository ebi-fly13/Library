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
  bundledCode: "#line 2 \"utility/random_number_generator_64.hpp\"\n\r\n#include <cstdint>\r\
    \n#include <random>\r\n\r\nnamespace ebi {\r\n\r\nstruct random_number_generator_64\
    \ {\r\n  private:\r\n    using u64 = std::uint64_t;\r\n    std::random_device\
    \ rnd;\r\n    std::mt19937_64 mt;\r\n\r\n  public:\r\n    random_number_generator_64()\
    \ : mt(rnd()) {}\r\n\r\n    u64 get(u64 a, u64 b) {\r\n        std::uniform_int_distribution<u64>\
    \ dist(a, b - 1);\r\n        return dist(mt);\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\r\n\r\n#include <cstdint>\r\n#include <random>\r\n\r\nnamespace\
    \ ebi {\r\n\r\nstruct random_number_generator_64 {\r\n  private:\r\n    using\
    \ u64 = std::uint64_t;\r\n    std::random_device rnd;\r\n    std::mt19937_64 mt;\r\
    \n\r\n  public:\r\n    random_number_generator_64() : mt(rnd()) {}\r\n\r\n   \
    \ u64 get(u64 a, u64 b) {\r\n        std::uniform_int_distribution<u64> dist(a,\
    \ b - 1);\r\n        return dist(mt);\r\n    }\r\n};\r\n\r\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: utility/random_number_generator_64.hpp
  requiredBy:
  - tree/rooted_tree_hash.hpp
  - string/rolling_hash.hpp
  - utility/hash.hpp
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/Rooted_Tree_Isomorphism_Classification.test.cpp
  - test/aoj/aoj_2444.test.cpp
documentation_of: utility/random_number_generator_64.hpp
layout: document
redirect_from:
- /library/utility/random_number_generator_64.hpp
- /library/utility/random_number_generator_64.hpp.html
title: utility/random_number_generator_64.hpp
---
