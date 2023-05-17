---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/internal_math.hpp\"\n\nnamespace ebi {\n\nnamespace\
    \ internal {\n\nconstexpr int primitive_root_constexpr(int m) {\n    if (m ==\
    \ 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049) return\
    \ 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return 3;\n\
    }\ntemplate <int m> constexpr int primitive_root = primitive_root_constexpr(m);\n\
    \n}\n\n}\n"
  code: "#pragma once\n\nnamespace ebi {\n\nnamespace internal {\n\nconstexpr int\
    \ primitive_root_constexpr(int m) {\n    if (m == 2) return 1;\n    if (m == 167772161)\
    \ return 3;\n    if (m == 469762049) return 3;\n    if (m == 754974721) return\
    \ 11;\n    if (m == 998244353) return 3;\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n}\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/internal_math.hpp
  requiredBy: []
  timestamp: '2023-05-17 13:07:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/internal_math.hpp
layout: document
redirect_from:
- /library/math/internal_math.hpp
- /library/math/internal_math.hpp.html
title: math/internal_math.hpp
---
