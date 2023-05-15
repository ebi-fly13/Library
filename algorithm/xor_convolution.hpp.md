---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/hadamard_transform.hpp
    title: algorithm/hadamard_transform.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Bitwise_Xor_Convolution.test.cpp
    title: test/Bitwise_Xor_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/xor_convolution.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n#line 2 \"algorithm/hadamard_transform.hpp\"\n\n#line 4 \"\
    algorithm/hadamard_transform.hpp\"\n\nnamespace ebi {\n\ntemplate <class T>\n\
    std::vector<T> hadamard_transform(std::vector<T> f, bool inverse = false) {\n\
    \    int n = f.size();\n    for (int i = 1; i < n; i <<= 1) {\n        for (int\
    \ j = 0; j < n; j++) {\n            if ((i & j) == 0) {\n                T x =\
    \ f[j], y = f[j | i];\n                f[j] = x + y;\n                f[j | i]\
    \ = x - y;\n            }\n        }\n    }\n    if (inverse) {\n        for (auto&\
    \ x : f) {\n            x /= T(n);\n        }\n    }\n    return f;\n}\n\n}  //\
    \ namespace ebi\n#line 7 \"algorithm/xor_convolution.hpp\"\n\nnamespace ebi {\n\
    \ntemplate <class T>\nstd::vector<T> xor_convolution(const std::vector<T> &a,\n\
    \                               const std::vector<T> &b) {\n    assert(a.size()\
    \ == b.size());\n    auto ta = hadamard_transform(a);\n    auto tb = hadamard_transform(b);\n\
    \    for (int i = 0; i < (int)a.size(); i++) {\n        ta[i] *= tb[i];\n    }\n\
    \    return hadamard_transform(ta, true);\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../algorithm/hadamard_transform.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T>\nstd::vector<T> xor_convolution(const\
    \ std::vector<T> &a,\n                               const std::vector<T> &b)\
    \ {\n    assert(a.size() == b.size());\n    auto ta = hadamard_transform(a);\n\
    \    auto tb = hadamard_transform(b);\n    for (int i = 0; i < (int)a.size();\
    \ i++) {\n        ta[i] *= tb[i];\n    }\n    return hadamard_transform(ta, true);\n\
    }\n\n}  // namespace ebi"
  dependsOn:
  - algorithm/hadamard_transform.hpp
  isVerificationFile: false
  path: algorithm/xor_convolution.hpp
  requiredBy: []
  timestamp: '2023-05-12 15:09:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Bitwise_Xor_Convolution.test.cpp
documentation_of: algorithm/xor_convolution.hpp
layout: document
redirect_from:
- /library/algorithm/xor_convolution.hpp
- /library/algorithm/xor_convolution.hpp.html
title: algorithm/xor_convolution.hpp
---