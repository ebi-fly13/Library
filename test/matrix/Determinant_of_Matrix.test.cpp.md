---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: matrix/square_matrix.hpp
    title: matrix/square_matrix.hpp
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/matrix/Determinant_of_Matrix.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/matrix_det\"\r\n\r\n#include <iostream>\r\n\
    \r\n#line 2 \"matrix/square_matrix.hpp\"\n\r\n#include <vector>\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <class Field, int id> struct square_matrix {\r\n  private:\r\
    \n    using Self = square_matrix<Field, id>;\r\n\r\n  public:\r\n    square_matrix(Field\
    \ val = 0)\r\n        : mat(std::vector(N, std::vector<Field>(N, val))) {}\r\n\
    \r\n    Self operator+(Self &rhs) const noexcept {\r\n        return Self(*this)\
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
    \n\r\n}  // namespace ebi\n#line 2 \"modint/modint.hpp\"\n\r\n#include <cassert>\r\
    \n#line 5 \"modint/modint.hpp\"\n\r\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n\
    #line 5 \"modint/base.hpp\"\n#include <utility>\n\nnamespace ebi {\n\ntemplate\
    \ <class T>\nconcept Modint = requires(T a, T b) {\n    a + b;\n    a - b;\n \
    \   a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 7 \"\
    modint/modint.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate <int m> struct static_modint\
    \ {\r\n  private:\r\n    using modint = static_modint;\r\n\r\n  public:\r\n  \
    \  static constexpr int mod() {\r\n        return m;\r\n    }\r\n\r\n    static\
    \ constexpr modint raw(int v) {\r\n        modint x;\r\n        x._v = v;\r\n\
    \        return x;\r\n    }\r\n\r\n    constexpr static_modint() : _v(0) {}\r\n\
    \r\n    constexpr static_modint(long long v) {\r\n        v %= (long long)umod();\r\
    \n        if (v < 0) v += (long long)umod();\r\n        _v = (unsigned int)v;\r\
    \n    }\r\n\r\n    constexpr unsigned int val() const {\r\n        return _v;\r\
    \n    }\r\n\r\n    constexpr unsigned int value() const {\r\n        return val();\r\
    \n    }\r\n\r\n    constexpr modint &operator++() {\r\n        _v++;\r\n     \
    \   if (_v == umod()) _v = 0;\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator--() {\r\n        if (_v == 0) _v = umod();\r\n        _v--;\r\
    \n        return *this;\r\n    }\r\n\r\n    constexpr modint operator++(int) {\r\
    \n        modint res = *this;\r\n        ++*this;\r\n        return res;\r\n \
    \   }\r\n    constexpr modint operator--(int) {\r\n        modint res = *this;\r\
    \n        --*this;\r\n        return res;\r\n    }\r\n\r\n    constexpr modint\
    \ &operator+=(const modint &rhs) {\r\n        _v += rhs._v;\r\n        if (_v\
    \ >= umod()) _v -= umod();\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator-=(const modint &rhs) {\r\n        _v -= rhs._v;\r\n       \
    \ if (_v >= umod()) _v += umod();\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator*=(const modint &rhs) {\r\n        unsigned long long x = _v;\r\
    \n        x *= rhs._v;\r\n        _v = (unsigned int)(x % (unsigned long long)umod());\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator/=(const modint\
    \ &rhs) {\r\n        return *this = *this * rhs.inv();\r\n    }\r\n\r\n    constexpr\
    \ modint operator+() const {\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint operator-() const {\r\n        return modint() - *this;\r\n    }\r\n\r\
    \n    constexpr modint pow(long long n) const {\r\n        assert(0 <= n);\r\n\
    \        modint x = *this, res = 1;\r\n        while (n) {\r\n            if (n\
    \ & 1) res *= x;\r\n            x *= x;\r\n            n >>= 1;\r\n        }\r\
    \n        return res;\r\n    }\r\n    constexpr modint inv() const {\r\n     \
    \   assert(_v);\r\n        return pow(umod() - 2);\r\n    }\r\n\r\n    friend\
    \ modint operator+(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
    \ += rhs;\r\n    }\r\n    friend modint operator-(const modint &lhs, const modint\
    \ &rhs) {\r\n        return modint(lhs) -= rhs;\r\n    }\r\n    friend modint\
    \ operator*(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
    \ *= rhs;\r\n    }\r\n\r\n    friend modint operator/(const modint &lhs, const\
    \ modint &rhs) {\r\n        return modint(lhs) /= rhs;\r\n    }\r\n    friend\
    \ bool operator==(const modint &lhs, const modint &rhs) {\r\n        return lhs.val()\
    \ == rhs.val();\r\n    }\r\n    friend bool operator!=(const modint &lhs, const\
    \ modint &rhs) {\r\n        return !(lhs == rhs);\r\n    }\r\n\r\n  private:\r\
    \n    unsigned int _v = 0;\r\n\r\n    static constexpr unsigned int umod() {\r\
    \n        return m;\r\n    }\r\n};\r\n\r\nusing modint998244353 = static_modint<998244353>;\r\
    \nusing modint1000000007 = static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n\
    #line 7 \"test/matrix/Determinant_of_Matrix.test.cpp\"\n\r\nusing Matrix = ebi::square_matrix<ebi::modint998244353,\
    \ 0>;\r\n\r\nint main() {\r\n    int n;\r\n    std::cin >> n;\r\n    Matrix::set_size(n);\r\
    \n    Matrix a;\r\n    for (int i = 0; i < n; ++i) {\r\n        for (int j = 0;\
    \ j < n; ++j) {\r\n            int val;\r\n            std::cin >> val;\r\n  \
    \          a[i][j] = val;\r\n        }\r\n    }\r\n    std::cout << a.det().val()\
    \ << std::endl;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\r\n\r\n#include\
    \ <iostream>\r\n\r\n#include \"../../matrix/square_matrix.hpp\"\r\n#include \"\
    ../../modint/modint.hpp\"\r\n\r\nusing Matrix = ebi::square_matrix<ebi::modint998244353,\
    \ 0>;\r\n\r\nint main() {\r\n    int n;\r\n    std::cin >> n;\r\n    Matrix::set_size(n);\r\
    \n    Matrix a;\r\n    for (int i = 0; i < n; ++i) {\r\n        for (int j = 0;\
    \ j < n; ++j) {\r\n            int val;\r\n            std::cin >> val;\r\n  \
    \          a[i][j] = val;\r\n        }\r\n    }\r\n    std::cout << a.det().val()\
    \ << std::endl;\r\n}"
  dependsOn:
  - matrix/square_matrix.hpp
  - modint/modint.hpp
  - modint/base.hpp
  isVerificationFile: true
  path: test/matrix/Determinant_of_Matrix.test.cpp
  requiredBy: []
  timestamp: '2024-01-28 16:55:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/matrix/Determinant_of_Matrix.test.cpp
layout: document
redirect_from:
- /verify/test/matrix/Determinant_of_Matrix.test.cpp
- /verify/test/matrix/Determinant_of_Matrix.test.cpp.html
title: test/matrix/Determinant_of_Matrix.test.cpp
---
