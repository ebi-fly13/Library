---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/xor_convolution.hpp
    title: algorithm/xor_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Bitwise_Xor_Convolution.test.cpp
    title: test/Bitwise_Xor_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/hadamard_transform.hpp\"\n\n#include <vector>\n\
    \nnamespace ebi {\n\ntemplate <class T>\nstd::vector<T> hadamard_transform(std::vector<T>\
    \ f, bool inverse = false) {\n    int n = f.size();\n    for (int i = 1; i < n;\
    \ i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((i & j) ==\
    \ 0) {\n                T x = f[j], y = f[j | i];\n                f[j] = x +\
    \ y;\n                f[j | i] = x - y;\n            }\n        }\n    }\n   \
    \ if (inverse) {\n        for (auto& x : f) {\n            x /= T(n);\n      \
    \  }\n    }\n    return f;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace ebi {\n\ntemplate <class T>\n\
    std::vector<T> hadamard_transform(std::vector<T> f, bool inverse = false) {\n\
    \    int n = f.size();\n    for (int i = 1; i < n; i <<= 1) {\n        for (int\
    \ j = 0; j < n; j++) {\n            if ((i & j) == 0) {\n                T x =\
    \ f[j], y = f[j | i];\n                f[j] = x + y;\n                f[j | i]\
    \ = x - y;\n            }\n        }\n    }\n    if (inverse) {\n        for (auto&\
    \ x : f) {\n            x /= T(n);\n        }\n    }\n    return f;\n}\n\n}  //\
    \ namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/hadamard_transform.hpp
  requiredBy:
  - algorithm/xor_convolution.hpp
  timestamp: '2023-05-12 15:09:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Bitwise_Xor_Convolution.test.cpp
documentation_of: algorithm/hadamard_transform.hpp
layout: document
redirect_from:
- /library/algorithm/hadamard_transform.hpp
- /library/algorithm/hadamard_transform.hpp.html
title: algorithm/hadamard_transform.hpp
---