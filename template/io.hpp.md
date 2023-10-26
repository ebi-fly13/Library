---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2450.test.cpp
    title: test/aoj/aoj_2450.test.cpp
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
  - icon: ':x:'
    path: test/yuki/yuki_1145.test.cpp
    title: test/yuki/yuki_1145.test.cpp
  - icon: ':x:'
    path: test/yuki/yuki_2439.test.cpp
    title: test/yuki/yuki_2439.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/io.hpp\"\n\n#include <iomanip>\n#include <iostream>\n\
    #include <optional>\n#include <vector>\n\nnamespace ebi {\n\ntemplate <typename\
    \ T1, typename T2>\nstd::ostream &operator<<(std::ostream &os, const std::pair<T1,\
    \ T2> &pa) {\n    return os << pa.first << \" \" << pa.second;\n}\n\ntemplate\
    \ <typename T1, typename T2>\nstd::istream &operator>>(std::istream &os, std::pair<T1,\
    \ T2> &pa) {\n    return os >> pa.first >> pa.second;\n}\n\ntemplate <typename\
    \ T>\nstd::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {\n\
    \    for (std::size_t i = 0; i < vec.size(); i++)\n        os << vec[i] << (i\
    \ + 1 == vec.size() ? \"\" : \" \");\n    return os;\n}\n\ntemplate <typename\
    \ T>\nstd::istream &operator>>(std::istream &os, std::vector<T> &vec) {\n    for\
    \ (T &e : vec) std::cin >> e;\n    return os;\n}\n\ntemplate <typename T>\nstd::ostream\
    \ &operator<<(std::ostream &os, const std::optional<T> &opt) {\n    if (opt) {\n\
    \        os << opt.value();\n    } else {\n        os << \"invalid value\";\n\
    \    }\n    return os;\n}\n\nvoid fast_io() {\n    std::cout << std::fixed <<\
    \ std::setprecision(15);\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    }\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <iomanip>\n#include <iostream>\n#include <optional>\n\
    #include <vector>\n\nnamespace ebi {\n\ntemplate <typename T1, typename T2>\n\
    std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &pa) {\n  \
    \  return os << pa.first << \" \" << pa.second;\n}\n\ntemplate <typename T1, typename\
    \ T2>\nstd::istream &operator>>(std::istream &os, std::pair<T1, T2> &pa) {\n \
    \   return os >> pa.first >> pa.second;\n}\n\ntemplate <typename T>\nstd::ostream\
    \ &operator<<(std::ostream &os, const std::vector<T> &vec) {\n    for (std::size_t\
    \ i = 0; i < vec.size(); i++)\n        os << vec[i] << (i + 1 == vec.size() ?\
    \ \"\" : \" \");\n    return os;\n}\n\ntemplate <typename T>\nstd::istream &operator>>(std::istream\
    \ &os, std::vector<T> &vec) {\n    for (T &e : vec) std::cin >> e;\n    return\
    \ os;\n}\n\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream &os,\
    \ const std::optional<T> &opt) {\n    if (opt) {\n        os << opt.value();\n\
    \    } else {\n        os << \"invalid value\";\n    }\n    return os;\n}\n\n\
    void fast_io() {\n    std::cout << std::fixed << std::setprecision(15);\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n}\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: template/io.hpp
  requiredBy:
  - template/template.hpp
  timestamp: '2023-08-27 22:59:16+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/polynomial/Polynomial_Interpolation.test.cpp
  - test/polynomial/Multipoint_Evaluation.test.cpp
  - test/yuki/yuki_2439.test.cpp
  - test/yuki/yuki_1145.test.cpp
  - test/aoj/aoj_2450.test.cpp
  - test/math/Sum_of_Totient_Function.test.cpp
  - test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - test/data_structure/Range_Affine_Range_Sum.test.cpp
documentation_of: template/io.hpp
layout: document
redirect_from:
- /library/template/io.hpp
- /library/template/io.hpp.html
title: template/io.hpp
---
