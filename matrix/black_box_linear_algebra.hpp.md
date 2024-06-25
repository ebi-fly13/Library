---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/berlekamp_massey.hpp
    title: Berlekamp Massey
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':heavy_check_mark:'
    path: utility/random_number_generator.hpp
    title: Random Number Generator
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/matrix/Determinant_of_Sparse_Matrix.test.cpp
    title: test/matrix/Determinant_of_Sparse_Matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"matrix/black_box_linear_algebra.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n#line 2 \"fps/berlekamp_massey.hpp\"\n\n#include <algorithm>\n\
    #line 5 \"fps/berlekamp_massey.hpp\"\n\n#line 2 \"modint/base.hpp\"\n\n#include\
    \ <concepts>\n#include <iostream>\n#include <utility>\n\nnamespace ebi {\n\ntemplate\
    \ <class T>\nconcept Modint = requires(T a, T b) {\n    a + b;\n    a - b;\n \
    \   a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 7 \"\
    fps/berlekamp_massey.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint>\nstd::vector<mint>\
    \ berlekamp_massey(const std::vector<mint> &s) {\n    std::vector<mint> C = {1},\
    \ B = {1};\n    int L = 0, m = 1;\n    mint b = 1;\n    for (int n = 0; n < (int)s.size();\
    \ n++) {\n        mint d = s[n];\n        for (int i = 1; i <= L; i++) {\n   \
    \         d += s[n - i] * C[i];\n        }\n        if (d == 0) {\n          \
    \  m++;\n        } else if (2 * L <= n) {\n            auto T = C;\n         \
    \   mint f = d / b;\n            C.resize((int)B.size() + m);\n            for\
    \ (int i = 0; i < (int)B.size(); i++) {\n                C[i + m] -= f * B[i];\n\
    \            }\n            L = n + 1 - L;\n            B = T;\n            b\
    \ = d;\n            m = 1;\n        } else {\n            mint f = d / b;\n  \
    \          for (int i = 0; i < (int)B.size(); i++) {\n                C[i + m]\
    \ -= f * B[i];\n            }\n            m++;\n        }\n    }\n    return\
    \ C;\n}\n\n}  // namespace ebi\n#line 2 \"utility/random_number_generator.hpp\"\
    \n\r\n#include <cstdint>\r\n#include <random>\r\n\r\nnamespace ebi {\r\n\r\nstruct\
    \ random_number_generator {\r\n    random_number_generator(int seed = -1) {\r\n\
    \        if (seed < 0) seed = rnd();\r\n        mt.seed(seed);\r\n    }\r\n\r\n\
    \    void set_seed(int seed) {\r\n        mt.seed(seed);\r\n    }\r\n\r\n    template\
    \ <class T> T get(T a, T b) {\r\n        std::uniform_int_distribution<T> dist(a,\
    \ b - 1);\r\n        return dist(mt);\r\n    }\r\n\r\n  private:\r\n    std::mt19937_64\
    \ mt;\r\n    std::random_device rnd;\r\n};\r\n\r\n}  // namespace ebi\n#line 9\
    \ \"matrix/black_box_linear_algebra.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint\
    \ mint, class F>\nstd::vector<mint> matrix_minimum_poly(int n, F Ax) {\n    static\
    \ random_number_generator rng;\n    std::vector<mint> s(2 * n + 10, 0), u(n),\
    \ b(n);\n    for (int i = 0; i < n; i++) {\n        u[i] = rng.get(0, mint::mod());\n\
    \        b[i] = rng.get(0, mint::mod());\n    }\n    for (int i = 0; i < 2 * n\
    \ + 10; i++) {\n        for (int j = 0; j < n; j++) {\n            s[i] += u[j]\
    \ * b[j];\n        }\n        b = Ax(b);\n    }\n    auto c = berlekamp_massey(s);\n\
    \    std::reverse(c.begin(), c.end());\n    return c;\n}\n\ntemplate <Modint mint,\
    \ class F> mint det(int n, F Ax) {\n    static random_number_generator rng;\n\
    \    std::vector<mint> d(n);\n    mint r = 1;\n    for (int i = 0; i < n; i++)\
    \ {\n        d[i] = rng.get(1, mint::mod());\n        r *= d[i];\n    }\n    auto\
    \ ADx = [&](std::vector<mint> v) -> std::vector<mint> {\n        assert(n == (int)v.size());\n\
    \        for (int i = 0; i < n; i++) {\n            v[i] *= d[i];\n        }\n\
    \        return Ax(v);\n    };\n    auto f = matrix_minimum_poly<mint>(n, ADx);\n\
    \    mint res = ((int)f.size() == n + 1 ? f[0] : 0);\n    if (n % 2 == 1) res\
    \ = -res;\n    return res / r;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../fps/berlekamp_massey.hpp\"\
    \n#include \"../modint/base.hpp\"\n#include \"../utility/random_number_generator.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint, class F>\nstd::vector<mint> matrix_minimum_poly(int\
    \ n, F Ax) {\n    static random_number_generator rng;\n    std::vector<mint> s(2\
    \ * n + 10, 0), u(n), b(n);\n    for (int i = 0; i < n; i++) {\n        u[i] =\
    \ rng.get(0, mint::mod());\n        b[i] = rng.get(0, mint::mod());\n    }\n \
    \   for (int i = 0; i < 2 * n + 10; i++) {\n        for (int j = 0; j < n; j++)\
    \ {\n            s[i] += u[j] * b[j];\n        }\n        b = Ax(b);\n    }\n\
    \    auto c = berlekamp_massey(s);\n    std::reverse(c.begin(), c.end());\n  \
    \  return c;\n}\n\ntemplate <Modint mint, class F> mint det(int n, F Ax) {\n \
    \   static random_number_generator rng;\n    std::vector<mint> d(n);\n    mint\
    \ r = 1;\n    for (int i = 0; i < n; i++) {\n        d[i] = rng.get(1, mint::mod());\n\
    \        r *= d[i];\n    }\n    auto ADx = [&](std::vector<mint> v) -> std::vector<mint>\
    \ {\n        assert(n == (int)v.size());\n        for (int i = 0; i < n; i++)\
    \ {\n            v[i] *= d[i];\n        }\n        return Ax(v);\n    };\n   \
    \ auto f = matrix_minimum_poly<mint>(n, ADx);\n    mint res = ((int)f.size() ==\
    \ n + 1 ? f[0] : 0);\n    if (n % 2 == 1) res = -res;\n    return res / r;\n}\n\
    \n}  // namespace ebi"
  dependsOn:
  - fps/berlekamp_massey.hpp
  - modint/base.hpp
  - utility/random_number_generator.hpp
  isVerificationFile: false
  path: matrix/black_box_linear_algebra.hpp
  requiredBy: []
  timestamp: '2024-06-25 15:42:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/matrix/Determinant_of_Sparse_Matrix.test.cpp
documentation_of: matrix/black_box_linear_algebra.hpp
layout: document
title: Black Box Linear Algebra
---

## 説明

Black Box Linear Algebraは、行列を陽に与えずに、行列 $A$ とベクトル $v$ の積の演算を行う関数（black box） $Ax$ を与えることで各種の計算を行うものである。

### matrix_minimum_poly(int n, F Ax)

$N$ 次正方行列 $A$ の最小多項式を求める。 $O(N^2)$

### det(int n, F Ax)

$N$ 次正方行列 $A$ の行列式を求める。 $A$ と ベクトル $v$ の積の計算量を $T(N)$ とすると $O(N^2 + N T(N))$ となる。