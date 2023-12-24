---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2235.test.cpp
    title: test/aoj/aoj_2235.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2450.test.cpp
    title: test/aoj/aoj_2450.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_3086.test.cpp
    title: test/aoj/aoj_3086.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Min_Plus_Convolution_Convex_and_Arbitary.test.cpp
    title: test/convolution/Min_Plus_Convolution_Convex_and_Arbitary.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Affine_Point_Get.test.cpp
    title: test/data_structure/Range_Affine_Point_Get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp
    title: test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/data_structure/Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
    title: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Totient_Function.test.cpp
    title: test/math/Sum_of_Totient_Function.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Multipoint_Evaluation.test.cpp
    title: test/polynomial/Multipoint_Evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Polynomial_Interpolation.test.cpp
    title: test/polynomial/Polynomial_Interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Cartesian_Tree.test.cpp
    title: test/tree/Cartesian_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1077.test.cpp
    title: test/yuki/yuki_1077.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1145.test.cpp
    title: test/yuki/yuki_1145.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_2439.test.cpp
    title: test/yuki/yuki_2439.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_901.test.cpp
    title: test/yuki/yuki_901.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_901_2.test.cpp
    title: test/yuki/yuki_901_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_952.test.cpp
    title: test/yuki/yuki_952.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/debug_template.hpp\"\n\n#include <iostream>\n\n\
    namespace ebi {\n\n#ifdef LOCAL\n#define debug(...)                          \
    \                            \\\n    std::cerr << \"LINE: \" << __LINE__ << \"\
    \  [\" << #__VA_ARGS__ << \"]:\", \\\n        debug_out(__VA_ARGS__)\n#else\n\
    #define debug(...)\n#endif\n\nvoid debug_out() {\n    std::cerr << std::endl;\n\
    }\n\ntemplate <typename Head, typename... Tail> void debug_out(Head h, Tail...\
    \ t) {\n    std::cerr << \" \" << h;\n    if (sizeof...(t) > 0) std::cerr << \"\
    \ :\";\n    debug_out(t...);\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <iostream>\n\nnamespace ebi {\n\n#ifdef LOCAL\n\
    #define debug(...)                                                      \\\n \
    \   std::cerr << \"LINE: \" << __LINE__ << \"  [\" << #__VA_ARGS__ << \"]:\",\
    \ \\\n        debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\nvoid\
    \ debug_out() {\n    std::cerr << std::endl;\n}\n\ntemplate <typename Head, typename...\
    \ Tail> void debug_out(Head h, Tail... t) {\n    std::cerr << \" \" << h;\n  \
    \  if (sizeof...(t) > 0) std::cerr << \" :\";\n    debug_out(t...);\n}\n\n}  //\
    \ namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: template/debug_template.hpp
  requiredBy:
  - template/template.hpp
  timestamp: '2023-10-26 02:38:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Sum_of_Totient_Function.test.cpp
  - test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - test/convolution/Min_Plus_Convolution_Convex_and_Arbitary.test.cpp
  - test/data_structure/Range_Affine_Range_Sum.test.cpp
  - test/data_structure/Range_Affine_Point_Get_Dynamic_Segtree.test.cpp
  - test/data_structure/Range_Affine_Point_Get.test.cpp
  - test/aoj/aoj_3086.test.cpp
  - test/aoj/aoj_2235.test.cpp
  - test/aoj/aoj_2450.test.cpp
  - test/polynomial/Polynomial_Interpolation.test.cpp
  - test/polynomial/Multipoint_Evaluation.test.cpp
  - test/tree/Cartesian_Tree.test.cpp
  - test/yuki/yuki_1077.test.cpp
  - test/yuki/yuki_1145.test.cpp
  - test/yuki/yuki_952.test.cpp
  - test/yuki/yuki_901_2.test.cpp
  - test/yuki/yuki_2439.test.cpp
  - test/yuki/yuki_901.test.cpp
documentation_of: template/debug_template.hpp
layout: document
redirect_from:
- /library/template/debug_template.hpp
- /library/template/debug_template.hpp.html
title: template/debug_template.hpp
---
