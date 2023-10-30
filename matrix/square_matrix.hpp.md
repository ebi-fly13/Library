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
  bundledCode: "#line 2 \"matrix/square_matrix.hpp\"\n\r\n#include <vector>\r\n\r\n\
    namespace ebi {\r\n\r\ntemplate <class Field, int id> struct square_matrix {\r\
    \n  private:\r\n    using Self = square_matrix<Field, id>;\r\n\r\n  public:\r\n\
    \    square_matrix(Field val = 0)\r\n        : mat(std::vector(N, std::vector<Field>(N,\
    \ val))) {}\r\n\r\n    Self operator+(Self &rhs) const noexcept {\r\n        return\
    \ Self(*this) += rhs;\r\n    }\r\n\r\n    Self operator-(Self &rhs) const noexcept\
    \ {\r\n        return Self(*this) -= rhs;\r\n    }\r\n\r\n    Self operator*(Self\
    \ &rhs) const noexcept {\r\n        return Self(*this) *= rhs;\r\n    }\r\n\r\n\
    \    Self &operator+=(Self &rhs) noexcept {\r\n        for (int i = 0; i < N;\
    \ ++i) {\r\n            for (int j = 0; j < N; ++j) {\r\n                mat[i][j]\
    \ += rhs[i][j];\r\n            }\r\n        }\r\n        return *this;\r\n   \
    \ }\r\n\r\n    Self &operator-=(Self &rhs) noexcept {\r\n        for (int i =\
    \ 0; i < N; ++i) {\r\n            for (int j = 0; j < N; ++j) {\r\n          \
    \      mat[i][j] -= rhs[i][j];\r\n            }\r\n        }\r\n        return\
    \ *this;\r\n    }\r\n\r\n    Self &operator*=(Self &rhs) noexcept {\r\n      \
    \  Self ret;\r\n        for (int i = 0; i < N; ++i) {\r\n            for (int\
    \ j = 0; j < N; ++j) {\r\n                for (int k = 0; k < N; ++k) {\r\n  \
    \                  ret[i][j] += mat[i][k] * rhs[k][j];\r\n                }\r\n\
    \            }\r\n        }\r\n        return *this = ret;\r\n    }\r\n\r\n  \
    \  Self pow(long long n) const {\r\n        Self res;\r\n        for (int i =\
    \ 0; i < N; ++i) {\r\n            res[i][i] = 1;\r\n        }\r\n        Self\
    \ x = *this;\r\n        while (n > 0) {\r\n            if (n & 1) res *= x;\r\n\
    \            x *= x;\r\n            n >>= 1;\r\n        }\r\n        return res;\r\
    \n    }\r\n\r\n    Field det() const {\r\n        Self res = *this;\r\n      \
    \  Field d = 1;\r\n        for (int i = 0; i < N; ++i) {\r\n            if (res[i][i]\
    \ == 0) {\r\n                int flag = -1;\r\n                for (int j = i\
    \ + 1; j < N; ++j) {\r\n                    if (res[j][i] != 0) {\r\n        \
    \                flag = j;\r\n                        break;\r\n             \
    \       }\r\n                }\r\n                if (flag < 0) {\r\n        \
    \            return 0;\r\n                }\r\n                std::swap(res[i],\
    \ res[flag]);\r\n                d = -d;\r\n            }\r\n            Field\
    \ inv = res[i][i].inv();\r\n            for (int j = i + 1; j < N; ++j) {\r\n\
    \                Field fac = res[j][i] * inv;\r\n                for (int k =\
    \ i; k < N; ++k) {\r\n                    res[j][k] -= fac * res[i][k];\r\n  \
    \              }\r\n            }\r\n            d *= res[i][i];\r\n        }\r\
    \n        return d;\r\n    }\r\n\r\n    static Self identity() {\r\n        Self\
    \ res;\r\n        for (int i = 0; i < N; ++i) {\r\n            res[i][i] = 1;\r\
    \n        }\r\n        return res;\r\n    }\r\n\r\n    std::vector<Field> &operator[](int\
    \ i) {\r\n        return mat[i];\r\n    }\r\n\r\n    static void set_size(int\
    \ n) {\r\n        N = n;\r\n    }\r\n\r\n  private:\r\n    std::vector<std::vector<Field>>\
    \ mat;\r\n    static int N;\r\n};\r\n\r\ntemplate <class Field, int id> int square_matrix<Field,\
    \ id>::N = 0;\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate\
    \ <class Field, int id> struct square_matrix {\r\n  private:\r\n    using Self\
    \ = square_matrix<Field, id>;\r\n\r\n  public:\r\n    square_matrix(Field val\
    \ = 0)\r\n        : mat(std::vector(N, std::vector<Field>(N, val))) {}\r\n\r\n\
    \    Self operator+(Self &rhs) const noexcept {\r\n        return Self(*this)\
    \ += rhs;\r\n    }\r\n\r\n    Self operator-(Self &rhs) const noexcept {\r\n \
    \       return Self(*this) -= rhs;\r\n    }\r\n\r\n    Self operator*(Self &rhs)\
    \ const noexcept {\r\n        return Self(*this) *= rhs;\r\n    }\r\n\r\n    Self\
    \ &operator+=(Self &rhs) noexcept {\r\n        for (int i = 0; i < N; ++i) {\r\
    \n            for (int j = 0; j < N; ++j) {\r\n                mat[i][j] += rhs[i][j];\r\
    \n            }\r\n        }\r\n        return *this;\r\n    }\r\n\r\n    Self\
    \ &operator-=(Self &rhs) noexcept {\r\n        for (int i = 0; i < N; ++i) {\r\
    \n            for (int j = 0; j < N; ++j) {\r\n                mat[i][j] -= rhs[i][j];\r\
    \n            }\r\n        }\r\n        return *this;\r\n    }\r\n\r\n    Self\
    \ &operator*=(Self &rhs) noexcept {\r\n        Self ret;\r\n        for (int i\
    \ = 0; i < N; ++i) {\r\n            for (int j = 0; j < N; ++j) {\r\n        \
    \        for (int k = 0; k < N; ++k) {\r\n                    ret[i][j] += mat[i][k]\
    \ * rhs[k][j];\r\n                }\r\n            }\r\n        }\r\n        return\
    \ *this = ret;\r\n    }\r\n\r\n    Self pow(long long n) const {\r\n        Self\
    \ res;\r\n        for (int i = 0; i < N; ++i) {\r\n            res[i][i] = 1;\r\
    \n        }\r\n        Self x = *this;\r\n        while (n > 0) {\r\n        \
    \    if (n & 1) res *= x;\r\n            x *= x;\r\n            n >>= 1;\r\n \
    \       }\r\n        return res;\r\n    }\r\n\r\n    Field det() const {\r\n \
    \       Self res = *this;\r\n        Field d = 1;\r\n        for (int i = 0; i\
    \ < N; ++i) {\r\n            if (res[i][i] == 0) {\r\n                int flag\
    \ = -1;\r\n                for (int j = i + 1; j < N; ++j) {\r\n             \
    \       if (res[j][i] != 0) {\r\n                        flag = j;\r\n       \
    \                 break;\r\n                    }\r\n                }\r\n   \
    \             if (flag < 0) {\r\n                    return 0;\r\n           \
    \     }\r\n                std::swap(res[i], res[flag]);\r\n                d\
    \ = -d;\r\n            }\r\n            Field inv = res[i][i].inv();\r\n     \
    \       for (int j = i + 1; j < N; ++j) {\r\n                Field fac = res[j][i]\
    \ * inv;\r\n                for (int k = i; k < N; ++k) {\r\n                \
    \    res[j][k] -= fac * res[i][k];\r\n                }\r\n            }\r\n \
    \           d *= res[i][i];\r\n        }\r\n        return d;\r\n    }\r\n\r\n\
    \    static Self identity() {\r\n        Self res;\r\n        for (int i = 0;\
    \ i < N; ++i) {\r\n            res[i][i] = 1;\r\n        }\r\n        return res;\r\
    \n    }\r\n\r\n    std::vector<Field> &operator[](int i) {\r\n        return mat[i];\r\
    \n    }\r\n\r\n    static void set_size(int n) {\r\n        N = n;\r\n    }\r\n\
    \r\n  private:\r\n    std::vector<std::vector<Field>> mat;\r\n    static int N;\r\
    \n};\r\n\r\ntemplate <class Field, int id> int square_matrix<Field, id>::N = 0;\r\
    \n\r\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: matrix/square_matrix.hpp
  requiredBy: []
  timestamp: '2023-06-17 18:04:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/square_matrix.hpp
layout: document
redirect_from:
- /library/matrix/square_matrix.hpp
- /library/matrix/square_matrix.hpp.html
title: matrix/square_matrix.hpp
---
