---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Determinant_of_Matrix.test.cpp
    title: test/Determinant_of_Matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Matrix/SquareMatrix.hpp\"\n\r\n#include <vector>\r\n\r\n\
    namespace ebi {\r\n\r\ntemplate<class Field>\r\nstruct SquareMatrix {\r\nprivate:\r\
    \n    using Self = SquareMatrix<Field>;\r\n    using size_t = std::size_t;\r\n\
    \    using u64 = std::uint_fast64_t;\r\npublic:\r\n    SquareMatrix(Field val\
    \ = 0) : mat(std::vector(N, std::vector<Field>(N, val))) { }\r\n\r\n    Self operator+(const\
    \ Self &rhs) const noexcept {\r\n        return Self(*this) += rhs;\r\n    }\r\
    \n\r\n    Self operator-(const Self &rhs) const noexcept {\r\n        return Self(*this)\
    \ -= rhs;\r\n    }\r\n\r\n    Self operator*(const Self &rhs) const noexcept {\r\
    \n        return Self(*this) *= rhs;\r\n    }\r\n\r\n    Self &operator+=(const\
    \ Self &rhs) noexcept {\r\n        for(size_t i =  0; i < N; ++i) {\r\n      \
    \      for(size_t j = 0; j < N; ++j) {\r\n                mat[i][j] += rhs[i][j];\r\
    \n            }\r\n        }\r\n        return *this;\r\n    }\r\n\r\n    Self\
    \ &operator-=(const Self &rhs) noexcept {\r\n        for(size_t i =  0; i < N;\
    \ ++i) {\r\n            for(size_t j = 0; j < N; ++j) {\r\n                mat[i][j]\
    \ -= rhs[i][j];\r\n            }\r\n        }\r\n        return *this;\r\n   \
    \ }\r\n\r\n    Self &operator*=(const Self &rhs) noexcept {\r\n        Self ret;\r\
    \n        for(size_t i = 0; i < N; ++i) {\r\n            for(size_t j = 0; j <\
    \ N; ++j) {\r\n                for(size_t k = 0; k < N; ++k) {\r\n           \
    \         ret[i][j] += mat[i][k]*rhs[k][j];\r\n                }\r\n         \
    \   }\r\n        }\r\n        return *this = ret;\r\n    }\r\n\r\n    Self pow(u64\
    \ n) {\r\n        Self res;\r\n        for(size_t i = 0; i < N;  ++i) {\r\n  \
    \          res[i][i] = 1;\r\n        }\r\n        Self x = *this;\r\n        while(n\
    \ > 0) {\r\n            if(n & 1) res *= x;\r\n            x *= x;\r\n       \
    \     n >>= 1;\r\n        }\r\n        return res;\r\n    }\r\n\r\n    Field det()\
    \ {\r\n        Self res = *this;\r\n        Field d = 1;\r\n        for(size_t\
    \ i = 0; i < N; ++i) {\r\n            if(res[i][i].val() == 0) {\r\n         \
    \       int flag = -1;\r\n                for(size_t j = i+1; j < N; ++j) {\r\n\
    \                    if(res[j][i].val() != 0) {\r\n                        flag\
    \ = j;\r\n                        break;\r\n                    }\r\n        \
    \        }\r\n                if(flag < 0) {\r\n                    return 0;\r\
    \n                }\r\n                std::swap(res[i], res[flag]);\r\n     \
    \           d = Field(0)-d;\r\n            }\r\n            Field inv = res[i][i].inv();\r\
    \n            for(size_t j = i+1; j < N; ++j) {\r\n                Field fac =\
    \ res[j][i]*inv;\r\n                for(size_t k = i; k < N; ++k) {\r\n      \
    \              res[j][k] -= fac * res[i][k];\r\n                }\r\n        \
    \    }\r\n            d *= res[i][i];\r\n        }\r\n        return d;\r\n  \
    \  }\r\n\r\n    static Self identity(size_t N) {\r\n        Self res;\r\n    \
    \    for(size_t i = 0; i < N; ++i) {\r\n            res[i][i] = 1;\r\n       \
    \ }\r\n        return res;\r\n    }\r\n\r\n    std::vector<Field> &operator []\
    \ (size_t i) { return mat[i]; }\r\n\r\n    static void set_size(size_t n) {\r\n\
    \        N = n;\r\n    }\r\n\r\nprivate:\r\n    std::vector<std::vector<Field>>\
    \ mat;\r\n    static size_t N;\r\n};\r\n\r\ntemplate<class Field>\r\nsize_t SquareMatrix<Field>::N\
    \ = 0;\r\n\r\n}\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class\
    \ Field>\r\nstruct SquareMatrix {\r\nprivate:\r\n    using Self = SquareMatrix<Field>;\r\
    \n    using size_t = std::size_t;\r\n    using u64 = std::uint_fast64_t;\r\npublic:\r\
    \n    SquareMatrix(Field val = 0) : mat(std::vector(N, std::vector<Field>(N, val)))\
    \ { }\r\n\r\n    Self operator+(const Self &rhs) const noexcept {\r\n        return\
    \ Self(*this) += rhs;\r\n    }\r\n\r\n    Self operator-(const Self &rhs) const\
    \ noexcept {\r\n        return Self(*this) -= rhs;\r\n    }\r\n\r\n    Self operator*(const\
    \ Self &rhs) const noexcept {\r\n        return Self(*this) *= rhs;\r\n    }\r\
    \n\r\n    Self &operator+=(const Self &rhs) noexcept {\r\n        for(size_t i\
    \ =  0; i < N; ++i) {\r\n            for(size_t j = 0; j < N; ++j) {\r\n     \
    \           mat[i][j] += rhs[i][j];\r\n            }\r\n        }\r\n        return\
    \ *this;\r\n    }\r\n\r\n    Self &operator-=(const Self &rhs) noexcept {\r\n\
    \        for(size_t i =  0; i < N; ++i) {\r\n            for(size_t j = 0; j <\
    \ N; ++j) {\r\n                mat[i][j] -= rhs[i][j];\r\n            }\r\n  \
    \      }\r\n        return *this;\r\n    }\r\n\r\n    Self &operator*=(const Self\
    \ &rhs) noexcept {\r\n        Self ret;\r\n        for(size_t i = 0; i < N; ++i)\
    \ {\r\n            for(size_t j = 0; j < N; ++j) {\r\n                for(size_t\
    \ k = 0; k < N; ++k) {\r\n                    ret[i][j] += mat[i][k]*rhs[k][j];\r\
    \n                }\r\n            }\r\n        }\r\n        return *this = ret;\r\
    \n    }\r\n\r\n    Self pow(u64 n) {\r\n        Self res;\r\n        for(size_t\
    \ i = 0; i < N;  ++i) {\r\n            res[i][i] = 1;\r\n        }\r\n       \
    \ Self x = *this;\r\n        while(n > 0) {\r\n            if(n & 1) res *= x;\r\
    \n            x *= x;\r\n            n >>= 1;\r\n        }\r\n        return res;\r\
    \n    }\r\n\r\n    Field det() {\r\n        Self res = *this;\r\n        Field\
    \ d = 1;\r\n        for(size_t i = 0; i < N; ++i) {\r\n            if(res[i][i].val()\
    \ == 0) {\r\n                int flag = -1;\r\n                for(size_t j =\
    \ i+1; j < N; ++j) {\r\n                    if(res[j][i].val() != 0) {\r\n   \
    \                     flag = j;\r\n                        break;\r\n        \
    \            }\r\n                }\r\n                if(flag < 0) {\r\n    \
    \                return 0;\r\n                }\r\n                std::swap(res[i],\
    \ res[flag]);\r\n                d = Field(0)-d;\r\n            }\r\n        \
    \    Field inv = res[i][i].inv();\r\n            for(size_t j = i+1; j < N; ++j)\
    \ {\r\n                Field fac = res[j][i]*inv;\r\n                for(size_t\
    \ k = i; k < N; ++k) {\r\n                    res[j][k] -= fac * res[i][k];\r\n\
    \                }\r\n            }\r\n            d *= res[i][i];\r\n       \
    \ }\r\n        return d;\r\n    }\r\n\r\n    static Self identity(size_t N) {\r\
    \n        Self res;\r\n        for(size_t i = 0; i < N; ++i) {\r\n           \
    \ res[i][i] = 1;\r\n        }\r\n        return res;\r\n    }\r\n\r\n    std::vector<Field>\
    \ &operator [] (size_t i) { return mat[i]; }\r\n\r\n    static void set_size(size_t\
    \ n) {\r\n        N = n;\r\n    }\r\n\r\nprivate:\r\n    std::vector<std::vector<Field>>\
    \ mat;\r\n    static size_t N;\r\n};\r\n\r\ntemplate<class Field>\r\nsize_t SquareMatrix<Field>::N\
    \ = 0;\r\n\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: Matrix/SquareMatrix.hpp
  requiredBy: []
  timestamp: '2021-04-04 16:33:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Determinant_of_Matrix.test.cpp
documentation_of: Matrix/SquareMatrix.hpp
layout: document
redirect_from:
- /library/Matrix/SquareMatrix.hpp
- /library/Matrix/SquareMatrix.hpp.html
title: Matrix/SquareMatrix.hpp
---
