---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Matrix/SquareMatrix.hpp
    title: Matrix/SquareMatrix.hpp
  - icon: ':question:'
    path: utility/modint.hpp
    title: utility/modint.hpp
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
  bundledCode: "#line 1 \"test/Determinant_of_Matrix.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/matrix_det\"\r\n\r\n#include <iostream>\r\n\r\n\
    #line 2 \"Matrix/SquareMatrix.hpp\"\n\r\n#include <vector>\r\n\r\nnamespace ebi\
    \ {\r\n\r\ntemplate <class Field> struct SquareMatrix {\r\n  private:\r\n    using\
    \ Self = SquareMatrix<Field>;\r\n    using size_t = std::size_t;\r\n    using\
    \ u64 = std::uint_fast64_t;\r\n\r\n  public:\r\n    SquareMatrix(Field val = 0)\r\
    \n        : mat(std::vector(N, std::vector<Field>(N, val))) {}\r\n\r\n    Self\
    \ operator+(Self &rhs) const noexcept {\r\n        return Self(*this) += rhs;\r\
    \n    }\r\n\r\n    Self operator-(Self &rhs) const noexcept {\r\n        return\
    \ Self(*this) -= rhs;\r\n    }\r\n\r\n    Self operator*(Self &rhs) const noexcept\
    \ {\r\n        return Self(*this) *= rhs;\r\n    }\r\n\r\n    Self &operator+=(Self\
    \ &rhs) noexcept {\r\n        for (size_t i = 0; i < N; ++i) {\r\n           \
    \ for (size_t j = 0; j < N; ++j) {\r\n                mat[i][j] += rhs[i][j];\r\
    \n            }\r\n        }\r\n        return *this;\r\n    }\r\n\r\n    Self\
    \ &operator-=(Self &rhs) noexcept {\r\n        for (size_t i = 0; i < N; ++i)\
    \ {\r\n            for (size_t j = 0; j < N; ++j) {\r\n                mat[i][j]\
    \ -= rhs[i][j];\r\n            }\r\n        }\r\n        return *this;\r\n   \
    \ }\r\n\r\n    Self &operator*=(Self &rhs) noexcept {\r\n        Self ret;\r\n\
    \        for (size_t i = 0; i < N; ++i) {\r\n            for (size_t j = 0; j\
    \ < N; ++j) {\r\n                for (size_t k = 0; k < N; ++k) {\r\n        \
    \            ret[i][j] += mat[i][k] * rhs[k][j];\r\n                }\r\n    \
    \        }\r\n        }\r\n        return *this = ret;\r\n    }\r\n\r\n    Self\
    \ pow(u64 n) const {\r\n        Self res;\r\n        for (size_t i = 0; i < N;\
    \ ++i) {\r\n            res[i][i] = 1;\r\n        }\r\n        Self x = *this;\r\
    \n        while (n > 0) {\r\n            if (n & 1) res *= x;\r\n            x\
    \ *= x;\r\n            n >>= 1;\r\n        }\r\n        return res;\r\n    }\r\
    \n\r\n    Field det() const {\r\n        Self res = *this;\r\n        Field d\
    \ = 1;\r\n        for (size_t i = 0; i < N; ++i) {\r\n            if (res[i][i]\
    \ == 0) {\r\n                int flag = -1;\r\n                for (size_t j =\
    \ i + 1; j < N; ++j) {\r\n                    if (res[j][i] != 0) {\r\n      \
    \                  flag = j;\r\n                        break;\r\n           \
    \         }\r\n                }\r\n                if (flag < 0) {\r\n      \
    \              return 0;\r\n                }\r\n                std::swap(res[i],\
    \ res[flag]);\r\n                d = -d;\r\n            }\r\n            Field\
    \ inv = res[i][i].inv();\r\n            for (size_t j = i + 1; j < N; ++j) {\r\
    \n                Field fac = res[j][i] * inv;\r\n                for (size_t\
    \ k = i; k < N; ++k) {\r\n                    res[j][k] -= fac * res[i][k];\r\n\
    \                }\r\n            }\r\n            d *= res[i][i];\r\n       \
    \ }\r\n        return d;\r\n    }\r\n\r\n    static Self identity() {\r\n    \
    \    Self res;\r\n        for (size_t i = 0; i < N; ++i) {\r\n            res[i][i]\
    \ = 1;\r\n        }\r\n        return res;\r\n    }\r\n\r\n    std::vector<Field>\
    \ &operator[](size_t i) {\r\n        return mat[i];\r\n    }\r\n\r\n    static\
    \ void set_size(size_t n) {\r\n        N = n;\r\n    }\r\n\r\n  private:\r\n \
    \   std::vector<std::vector<Field>> mat;\r\n    static size_t N;\r\n};\r\n\r\n\
    template <class Field> size_t SquareMatrix<Field>::N = 0;\r\n\r\n}  // namespace\
    \ ebi\n#line 2 \"utility/modint.hpp\"\n\r\n#include <cassert>\r\n#line 5 \"utility/modint.hpp\"\
    \n#include <type_traits>\r\n\r\nnamespace ebi {\r\n\r\nnamespace internal {\r\n\
    \r\nstruct modint_base {};\r\nstruct static_modint_base : modint_base {};\r\n\r\
    \ntemplate <class T> using is_modint = std::is_base_of<modint_base, T>;\r\ntemplate\
    \ <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\r\n\r\n\
    }  // namespace internal\r\n\r\ntemplate <int m> struct static_modint : internal::static_modint_base\
    \ {\r\n  private:\r\n    using modint = static_modint;\r\n\r\n  public:\r\n  \
    \  static constexpr int mod() {\r\n        return m;\r\n    }\r\n\r\n    static\
    \ modint raw(int v) {\r\n        modint x;\r\n        x._v = v;\r\n        return\
    \ x;\r\n    }\r\n\r\n    static_modint() : _v(0) {}\r\n\r\n    static_modint(long\
    \ long v) {\r\n        v %= (long long)umod();\r\n        if (v < 0) v += (long\
    \ long)umod();\r\n        _v = (unsigned int)v;\r\n    }\r\n\r\n    unsigned int\
    \ val() const {\r\n        return _v;\r\n    }\r\n\r\n    unsigned int value()\
    \ const {\r\n        return val();\r\n    }\r\n\r\n    modint &operator++() {\r\
    \n        _v++;\r\n        if (_v == umod()) _v = 0;\r\n        return *this;\r\
    \n    }\r\n    modint &operator--() {\r\n        if (_v == 0) _v = umod();\r\n\
    \        _v--;\r\n        return *this;\r\n    }\r\n    modint &operator+=(const\
    \ modint &rhs) {\r\n        _v += rhs._v;\r\n        if (_v >= umod()) _v -= umod();\r\
    \n        return *this;\r\n    }\r\n    modint &operator-=(const modint &rhs)\
    \ {\r\n        _v -= rhs._v;\r\n        if (_v >= umod()) _v += umod();\r\n  \
    \      return *this;\r\n    }\r\n    modint &operator*=(const modint &rhs) {\r\
    \n        unsigned long long x = _v;\r\n        x *= rhs._v;\r\n        _v = (unsigned\
    \ int)(x % (unsigned long long)umod());\r\n        return *this;\r\n    }\r\n\
    \    modint &operator/=(const modint &rhs) {\r\n        return *this = *this *\
    \ rhs.inv();\r\n    }\r\n\r\n    modint operator+() const {\r\n        return\
    \ *this;\r\n    }\r\n    modint operator-() const {\r\n        return modint()\
    \ - *this;\r\n    }\r\n\r\n    modint pow(long long n) const {\r\n        assert(0\
    \ <= n);\r\n        modint x = *this, res = 1;\r\n        while (n) {\r\n    \
    \        if (n & 1) res *= x;\r\n            x *= x;\r\n            n >>= 1;\r\
    \n        }\r\n        return res;\r\n    }\r\n    modint inv() const {\r\n  \
    \      assert(_v);\r\n        return pow(umod() - 2);\r\n    }\r\n\r\n    friend\
    \ modint operator+(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
    \ += rhs;\r\n    }\r\n    friend modint operator-(const modint &lhs, const modint\
    \ &rhs) {\r\n        return modint(lhs) -= rhs;\r\n    }\r\n    friend modint\
    \ operator*(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
    \ *= rhs;\r\n    }\r\n\r\n    friend modint operator/(const modint &lhs, const\
    \ modint &rhs) {\r\n        return modint(lhs) /= rhs;\r\n    }\r\n    friend\
    \ bool operator==(const modint &lhs, const modint &rhs) {\r\n        return lhs.val()\
    \ == rhs.val();\r\n    }\r\n    friend bool operator!=(const modint &lhs, const\
    \ modint &rhs) {\r\n        return !(lhs == rhs);\r\n    }\r\n\r\n  private:\r\
    \n    unsigned int _v;\r\n\r\n    static constexpr unsigned int umod() {\r\n \
    \       return m;\r\n    }\r\n};\r\n\r\ntemplate <int m>\r\nstd::istream &operator>>(std::istream\
    \ &os, static_modint<m> &a) {\r\n    long long x;\r\n    os >> x;\r\n    a = x;\r\
    \n    return os;\r\n}\r\ntemplate <int m>\r\nstd::ostream &operator<<(std::ostream\
    \ &os, const static_modint<m> &a) {\r\n    return os << a.val();\r\n}\r\n\r\n\
    using modint998244353 = static_modint<998244353>;\r\nusing modint1000000007 =\
    \ static_modint<1000000007>;\r\n\r\nnamespace internal {\r\n\r\ntemplate <class\
    \ T>\r\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\r\n\r\ntemplate <class T>\r\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\r\
    \n\r\n}  // namespace internal\r\n\r\n}  // namespace ebi\n#line 7 \"test/Determinant_of_Matrix.test.cpp\"\
    \n\r\nusing Matrix = ebi::SquareMatrix<ebi::modint998244353>;\r\n\r\nint main()\
    \ {\r\n    int n;\r\n    std::cin >> n;\r\n    Matrix::set_size(n);\r\n    Matrix\
    \ a;\r\n    for (int i = 0; i < n; ++i) {\r\n        for (int j = 0; j < n; ++j)\
    \ {\r\n            int val;\r\n            std::cin >> val;\r\n            a[i][j]\
    \ = val;\r\n        }\r\n    }\r\n    std::cout << a.det().val() << std::endl;\r\
    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\r\n\r\n#include\
    \ <iostream>\r\n\r\n#include \"../Matrix/SquareMatrix.hpp\"\r\n#include \"../utility/modint.hpp\"\
    \r\n\r\nusing Matrix = ebi::SquareMatrix<ebi::modint998244353>;\r\n\r\nint main()\
    \ {\r\n    int n;\r\n    std::cin >> n;\r\n    Matrix::set_size(n);\r\n    Matrix\
    \ a;\r\n    for (int i = 0; i < n; ++i) {\r\n        for (int j = 0; j < n; ++j)\
    \ {\r\n            int val;\r\n            std::cin >> val;\r\n            a[i][j]\
    \ = val;\r\n        }\r\n    }\r\n    std::cout << a.det().val() << std::endl;\r\
    \n}"
  dependsOn:
  - Matrix/SquareMatrix.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/Determinant_of_Matrix.test.cpp
  requiredBy: []
  timestamp: '2023-05-17 13:24:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Determinant_of_Matrix.test.cpp
layout: document
redirect_from:
- /verify/test/Determinant_of_Matrix.test.cpp
- /verify/test/Determinant_of_Matrix.test.cpp.html
title: test/Determinant_of_Matrix.test.cpp
---