---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: matrix/black_box_linear_algebra.hpp
    title: Black Box Linear Algebra
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Find_Linear_Recurrence.test.cpp
    title: test/math/Find_Linear_Recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix/Determinant_of_Sparse_Matrix.test.cpp
    title: test/matrix/Determinant_of_Sparse_Matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/berlekamp_massey.hpp\"\n\n#include <algorithm>\n#include\
    \ <vector>\n\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#include <iostream>\n\
    #include <utility>\n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint =\
    \ requires(T a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n\
    \    a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n};\n\ntemplate\
    \ <Modint mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long\
    \ long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <Modint mint>\n\
    std::ostream &operator<<(std::ostream &os, const mint &a) {\n    return os <<\
    \ a.val();\n}\n\n}  // namespace ebi\n#line 7 \"fps/berlekamp_massey.hpp\"\n\n\
    namespace ebi {\n\ntemplate <Modint mint>\nstd::vector<mint> berlekamp_massey(const\
    \ std::vector<mint> &s) {\n    std::vector<mint> C = {1}, B = {1};\n    int L\
    \ = 0, m = 1;\n    mint b = 1;\n    for (int n = 0; n < (int)s.size(); n++) {\n\
    \        mint d = s[n];\n        for (int i = 1; i <= L; i++) {\n            d\
    \ += s[n - i] * C[i];\n        }\n        if (d == 0) {\n            m++;\n  \
    \      } else if (2 * L <= n) {\n            auto T = C;\n            mint f =\
    \ d / b;\n            C.resize((int)B.size() + m);\n            for (int i = 0;\
    \ i < (int)B.size(); i++) {\n                C[i + m] -= f * B[i];\n         \
    \   }\n            L = n + 1 - L;\n            B = T;\n            b = d;\n  \
    \          m = 1;\n        } else {\n            mint f = d / b;\n           \
    \ for (int i = 0; i < (int)B.size(); i++) {\n                C[i + m] -= f * B[i];\n\
    \            }\n            m++;\n        }\n    }\n    return C;\n}\n\n}  //\
    \ namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\n#include \"../modint/base.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint>\nstd::vector<mint> berlekamp_massey(const\
    \ std::vector<mint> &s) {\n    std::vector<mint> C = {1}, B = {1};\n    int L\
    \ = 0, m = 1;\n    mint b = 1;\n    for (int n = 0; n < (int)s.size(); n++) {\n\
    \        mint d = s[n];\n        for (int i = 1; i <= L; i++) {\n            d\
    \ += s[n - i] * C[i];\n        }\n        if (d == 0) {\n            m++;\n  \
    \      } else if (2 * L <= n) {\n            auto T = C;\n            mint f =\
    \ d / b;\n            C.resize((int)B.size() + m);\n            for (int i = 0;\
    \ i < (int)B.size(); i++) {\n                C[i + m] -= f * B[i];\n         \
    \   }\n            L = n + 1 - L;\n            B = T;\n            b = d;\n  \
    \          m = 1;\n        } else {\n            mint f = d / b;\n           \
    \ for (int i = 0; i < (int)B.size(); i++) {\n                C[i + m] -= f * B[i];\n\
    \            }\n            m++;\n        }\n    }\n    return C;\n}\n\n}  //\
    \ namespace ebi"
  dependsOn:
  - modint/base.hpp
  isVerificationFile: false
  path: fps/berlekamp_massey.hpp
  requiredBy:
  - matrix/black_box_linear_algebra.hpp
  timestamp: '2024-06-25 15:37:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Find_Linear_Recurrence.test.cpp
  - test/matrix/Determinant_of_Sparse_Matrix.test.cpp
documentation_of: fps/berlekamp_massey.hpp
layout: document
title: Berlekamp Massey
---

## 説明

$N$ 次線形回帰数列 $a$ の母関数を $A(x)$ とする。 $A(x)$ の先頭 $2N$ 項以上を入力として与えると、以下を満たす次数 $N$ のmonicな多項式 $C(x)$ を返す。時間計算量は $O(N^2)$ である。

$$
[x^i] C(x) \times A(x) = 0 ( N \leq i )
$$