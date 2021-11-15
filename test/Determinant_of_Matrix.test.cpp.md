---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Matrix/SquareMatrix.hpp
    title: Matrix/SquareMatrix.hpp
  - icon: ':heavy_check_mark:'
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
    \ {\r\n\r\ntemplate<class Field>\r\nstruct SquareMatrix {\r\nprivate:\r\n    using\
    \ Self = SquareMatrix<Field>;\r\n    using size_t = std::size_t;\r\n    using\
    \ u64 = std::uint_fast64_t;\r\npublic:\r\n    SquareMatrix(Field val = 0) : mat(std::vector(N,\
    \ std::vector<Field>(N, val))) { }\r\n\r\n    Self operator+(Self &rhs) const\
    \ noexcept {\r\n        return Self(*this) += rhs;\r\n    }\r\n\r\n    Self operator-(Self\
    \ &rhs) const noexcept {\r\n        return Self(*this) -= rhs;\r\n    }\r\n\r\n\
    \    Self operator*(Self &rhs) const noexcept {\r\n        return Self(*this)\
    \ *= rhs;\r\n    }\r\n\r\n    Self &operator+=(Self &rhs) noexcept {\r\n     \
    \   for(size_t i =  0; i < N; ++i) {\r\n            for(size_t j = 0; j < N; ++j)\
    \ {\r\n                mat[i][j] += rhs[i][j];\r\n            }\r\n        }\r\
    \n        return *this;\r\n    }\r\n\r\n    Self &operator-=(Self &rhs) noexcept\
    \ {\r\n        for(size_t i =  0; i < N; ++i) {\r\n            for(size_t j =\
    \ 0; j < N; ++j) {\r\n                mat[i][j] -= rhs[i][j];\r\n            }\r\
    \n        }\r\n        return *this;\r\n    }\r\n\r\n    Self &operator*=(Self\
    \ &rhs) noexcept {\r\n        Self ret;\r\n        for(size_t i = 0; i < N; ++i)\
    \ {\r\n            for(size_t j = 0; j < N; ++j) {\r\n                for(size_t\
    \ k = 0; k < N; ++k) {\r\n                    ret[i][j] += mat[i][k]*rhs[k][j];\r\
    \n                }\r\n            }\r\n        }\r\n        return *this = ret;\r\
    \n    }\r\n\r\n    Self pow(u64 n) const {\r\n        Self res;\r\n        for(size_t\
    \ i = 0; i < N;  ++i) {\r\n            res[i][i] = 1;\r\n        }\r\n       \
    \ Self x = *this;\r\n        while(n > 0) {\r\n            if(n & 1) res *= x;\r\
    \n            x *= x;\r\n            n >>= 1;\r\n        }\r\n        return res;\r\
    \n    }\r\n\r\n    Field det() const {\r\n        Self res = *this;\r\n      \
    \  Field d = 1;\r\n        for(size_t i = 0; i < N; ++i) {\r\n            if(res[i][i]\
    \ == 0) {\r\n                int flag = -1;\r\n                for(size_t j =\
    \ i+1; j < N; ++j) {\r\n                    if(res[j][i] != 0) {\r\n         \
    \               flag = j;\r\n                        break;\r\n              \
    \      }\r\n                }\r\n                if(flag < 0) {\r\n          \
    \          return 0;\r\n                }\r\n                std::swap(res[i],\
    \ res[flag]);\r\n                d = -d;\r\n            }\r\n            Field\
    \ inv = res[i][i].inv();\r\n            for(size_t j = i+1; j < N; ++j) {\r\n\
    \                Field fac = res[j][i]*inv;\r\n                for(size_t k =\
    \ i; k < N; ++k) {\r\n                    res[j][k] -= fac * res[i][k];\r\n  \
    \              }\r\n            }\r\n            d *= res[i][i];\r\n        }\r\
    \n        return d;\r\n    }\r\n\r\n    static Self identity() {\r\n        Self\
    \ res;\r\n        for(size_t i = 0; i < N; ++i) {\r\n            res[i][i] = 1;\r\
    \n        }\r\n        return res;\r\n    }\r\n\r\n    std::vector<Field> &operator\
    \ [] (size_t i) { return mat[i]; }\r\n\r\n    static void set_size(size_t n) {\r\
    \n        N = n;\r\n    }\r\n\r\nprivate:\r\n    std::vector<std::vector<Field>>\
    \ mat;\r\n    static size_t N;\r\n};\r\n\r\ntemplate<class Field>\r\nsize_t SquareMatrix<Field>::N\
    \ = 0;\r\n\r\n}\n#line 2 \"utility/modint.hpp\"\n\r\n/*\r\n    author: noshi91\r\
    \n    reference: https://noshi91.hatenablog.com/entry/2019/03/31/174006\r\n  \
    \  noshi91\u306E\u30D6\u30ED\u30B0\u3067\u516C\u958B\u3055\u308C\u3066\u3044\u308B\
    modint\u3092\u5143\u306Binv(), pow()\u3092\u8FFD\u52A0\u3057\u305F\u3082\u306E\
    \u3067\u3059\r\n*/\r\n\r\n#include <cstdint>\r\n#line 11 \"utility/modint.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate<std::uint_fast64_t Modulus>\r\nclass modint\
    \ {\r\n  using u64 = std::uint_fast64_t;\r\n\r\npublic:\r\n    u64 a;\r\n\r\n\
    \    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}\r\n    constexpr\
    \ u64 &value() noexcept { return a; }\r\n    constexpr u64 &val() noexcept { return\
    \ a; }\r\n    constexpr const u64 &value() const noexcept { return a; }\r\n  \
    \  constexpr modint operator+(const modint rhs) const noexcept {\r\n        return\
    \ modint(*this) += rhs;\r\n    }\r\n    constexpr modint operator-(const modint\
    \ rhs) const noexcept {\r\n        return modint(*this) -= rhs;\r\n    }\r\n \
    \   constexpr modint operator*(const modint rhs) const noexcept {\r\n        return\
    \ modint(*this) *= rhs;\r\n    }\r\n    constexpr modint operator/(const modint\
    \ rhs) const noexcept {\r\n        return modint(*this) /= rhs;\r\n    }\r\n \
    \   constexpr modint &operator+=(const modint rhs) noexcept {\r\n        a +=\
    \ rhs.a;\r\n        if (a >= Modulus) {\r\n            a -= Modulus;\r\n     \
    \   }\r\n        return *this;\r\n    }\r\n    constexpr modint &operator-=(const\
    \ modint rhs) noexcept {\r\n        if (a < rhs.a) {\r\n        a += Modulus;\r\
    \n        }\r\n        a -= rhs.a;\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator*=(const modint rhs) noexcept {\r\n        a = a * rhs.a % Modulus;\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator/=(modint rhs)\
    \ noexcept {\r\n        u64 exp = Modulus - 2;\r\n        while (exp) {\r\n  \
    \      if (exp % 2) {\r\n            *this *= rhs;\r\n        }\r\n        rhs\
    \ *= rhs;\r\n        exp /= 2;\r\n        }\r\n        return *this;\r\n    }\r\
    \n    constexpr modint operator-() const { return modint() - *this; }\r\n    bool\
    \ operator==(const u64 rhs) {\r\n        return a == rhs;\r\n    }\r\n    bool\
    \ operator!=(const u64 rhs) {\r\n        return a != rhs;\r\n    }\r\n    constexpr\
    \ modint& operator++() {\r\n        a++;\r\n        if( a == mod() ) a = 0;\r\n\
    \        return *this;\r\n    }\r\n    constexpr modint& operator--() {\r\n  \
    \      if( a == 0 ) a = mod();\r\n        a--;\r\n        return *this;\r\n  \
    \  }\r\n\r\n    modint pow(u64 n) const noexcept {\r\n        modint res = 1;\r\
    \n        modint x = a;\r\n        while(n>0){\r\n            if(n&1) res *= x;\r\
    \n            x *= x;\r\n            n >>=1;\r\n        }\r\n        return res;\r\
    \n    }\r\n    modint inv() const {\r\n        return pow(Modulus-2);\r\n    }\r\
    \n\r\n    static u64 mod() {\r\n        return Modulus;\r\n    }\r\n};\r\n\r\n\
    using modint998244353 = modint<998244353>;\r\nusing modint1000000007 = modint<1000000007>;\r\
    \n\r\ntemplate<std::uint_fast64_t Modulus>\r\nstd::ostream& operator<<(std::ostream&\
    \ os, modint<Modulus> a){\r\n    return os << a.val();\r\n}\r\n\r\n} // namespace\
    \ ebi\n#line 7 \"test/Determinant_of_Matrix.test.cpp\"\n\r\nusing Matrix = ebi::SquareMatrix<ebi::modint998244353>;\r\
    \n\r\nint main(){\r\n    int n;\r\n    std::cin >> n;\r\n    Matrix::set_size(n);\r\
    \n    Matrix a;\r\n    for(int i = 0; i < n; ++i) {\r\n        for(int j = 0;\
    \ j < n; ++j) {\r\n            int val;\r\n            std::cin >> val;\r\n  \
    \          a[i][j] = val;\r\n        }\r\n    }\r\n    std::cout << a.det().val()\
    \ << std::endl;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\r\n\r\n#include\
    \ <iostream>\r\n\r\n#include \"../Matrix/SquareMatrix.hpp\"\r\n#include \"../utility/modint.hpp\"\
    \r\n\r\nusing Matrix = ebi::SquareMatrix<ebi::modint998244353>;\r\n\r\nint main(){\r\
    \n    int n;\r\n    std::cin >> n;\r\n    Matrix::set_size(n);\r\n    Matrix a;\r\
    \n    for(int i = 0; i < n; ++i) {\r\n        for(int j = 0; j < n; ++j) {\r\n\
    \            int val;\r\n            std::cin >> val;\r\n            a[i][j] =\
    \ val;\r\n        }\r\n    }\r\n    std::cout << a.det().val() << std::endl;\r\
    \n}"
  dependsOn:
  - Matrix/SquareMatrix.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/Determinant_of_Matrix.test.cpp
  requiredBy: []
  timestamp: '2021-04-25 12:46:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Determinant_of_Matrix.test.cpp
layout: document
redirect_from:
- /verify/test/Determinant_of_Matrix.test.cpp
- /verify/test/Determinant_of_Matrix.test.cpp.html
title: test/Determinant_of_Matrix.test.cpp
---
