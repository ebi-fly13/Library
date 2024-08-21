---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/fps_sqrt.hpp
    title: $\sqrt{f}$
  - icon: ':heavy_check_mark:'
    path: math/mod_sqrt.hpp
    title: Mod Sqrt
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
    title: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Sqrt_Mod.test.cpp
    title: test/math/Sqrt_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix/Determinant_of_Matrix_Arbitrary_Mod.test.cpp
    title: test/matrix/Determinant_of_Matrix_Arbitrary_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/dynamic_modint.hpp\"\n\n#include <cassert>\n\n#line\
    \ 2 \"modint/base.hpp\"\n\n#include <concepts>\n#include <iostream>\n#include\
    \ <utility>\n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint = requires(T\
    \ a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n  \
    \  a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n};\n\ntemplate\
    \ <Modint mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long\
    \ long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <Modint mint>\n\
    std::ostream &operator<<(std::ostream &os, const mint &a) {\n    return os <<\
    \ a.val();\n}\n\n}  // namespace ebi\n#line 6 \"modint/dynamic_modint.hpp\"\n\n\
    namespace ebi {\n\ntemplate <int id> struct dynamic_modint {\n  private:\n   \
    \ using modint = dynamic_modint;\n\n  public:\n    static void set_mod(int p)\
    \ {\n        assert(1 <= p);\n        m = p;\n    }\n\n    static int mod() {\n\
    \        return m;\n    }\n\n    modint raw(int v) {\n        modint x;\n    \
    \    x._v = v;\n        return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n\n\
    \    dynamic_modint(long long v) {\n        v %= (long long)umod();\n        if\
    \ (v < 0) v += (long long)umod();\n        _v = (unsigned int)v;\n    }\n\n  \
    \  unsigned int val() const {\n        return _v;\n    }\n\n    unsigned int value()\
    \ const {\n        return val();\n    }\n\n    modint &operator++() {\n      \
    \  _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n    }\n  \
    \  modint &operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    modint &operator+=(const modint &rhs) {\n \
    \       _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n        return\
    \ *this;\n    }\n    modint &operator-=(const modint &rhs) {\n        _v -= rhs._v;\n\
    \        if (_v >= umod()) _v += umod();\n        return *this;\n    }\n    modint\
    \ &operator*=(const modint &rhs) {\n        unsigned long long x = _v;\n     \
    \   x *= rhs._v;\n        _v = (unsigned int)(x % (unsigned long long)umod());\n\
    \        return *this;\n    }\n    modint &operator/=(const modint &rhs) {\n \
    \       return *this = *this * rhs.inv();\n    }\n\n    modint operator+() const\
    \ {\n        return *this;\n    }\n    modint operator-() const {\n        return\
    \ modint() - *this;\n    }\n\n    modint pow(long long n) const {\n        assert(0\
    \ <= n);\n        modint x = *this, res = 1;\n        while (n) {\n          \
    \  if (n & 1) res *= x;\n            x *= x;\n            n >>= 1;\n        }\n\
    \        return res;\n    }\n    modint inv() const {\n        assert(_v);\n \
    \       return pow(umod() - 2);\n    }\n\n    friend modint operator+(const modint\
    \ &lhs, const modint &rhs) {\n        return modint(lhs) += rhs;\n    }\n    friend\
    \ modint operator-(const modint &lhs, const modint &rhs) {\n        return modint(lhs)\
    \ -= rhs;\n    }\n    friend modint operator*(const modint &lhs, const modint\
    \ &rhs) {\n        return modint(lhs) *= rhs;\n    }\n\n    friend modint operator/(const\
    \ modint &lhs, const modint &rhs) {\n        return modint(lhs) /= rhs;\n    }\n\
    \    friend bool operator==(const modint &lhs, const modint &rhs) {\n        return\
    \ lhs.val() == rhs.val();\n    }\n    friend bool operator!=(const modint &lhs,\
    \ const modint &rhs) {\n        return !(lhs == rhs);\n    }\n\n  private:\n \
    \   unsigned int _v = 0;\n    static int m;\n\n    static unsigned int umod()\
    \ {\n        return m;\n    }\n};\n\ntemplate <int id> int dynamic_modint<id>::m\
    \ = 998244353;\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n\n#include \"base.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <int id> struct dynamic_modint {\n  private:\n    using modint\
    \ = dynamic_modint;\n\n  public:\n    static void set_mod(int p) {\n        assert(1\
    \ <= p);\n        m = p;\n    }\n\n    static int mod() {\n        return m;\n\
    \    }\n\n    modint raw(int v) {\n        modint x;\n        x._v = v;\n    \
    \    return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n\n    dynamic_modint(long\
    \ long v) {\n        v %= (long long)umod();\n        if (v < 0) v += (long long)umod();\n\
    \        _v = (unsigned int)v;\n    }\n\n    unsigned int val() const {\n    \
    \    return _v;\n    }\n\n    unsigned int value() const {\n        return val();\n\
    \    }\n\n    modint &operator++() {\n        _v++;\n        if (_v == umod())\
    \ _v = 0;\n        return *this;\n    }\n    modint &operator--() {\n        if\
    \ (_v == 0) _v = umod();\n        _v--;\n        return *this;\n    }\n    modint\
    \ &operator+=(const modint &rhs) {\n        _v += rhs._v;\n        if (_v >= umod())\
    \ _v -= umod();\n        return *this;\n    }\n    modint &operator-=(const modint\
    \ &rhs) {\n        _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n  \
    \      return *this;\n    }\n    modint &operator*=(const modint &rhs) {\n   \
    \     unsigned long long x = _v;\n        x *= rhs._v;\n        _v = (unsigned\
    \ int)(x % (unsigned long long)umod());\n        return *this;\n    }\n    modint\
    \ &operator/=(const modint &rhs) {\n        return *this = *this * rhs.inv();\n\
    \    }\n\n    modint operator+() const {\n        return *this;\n    }\n    modint\
    \ operator-() const {\n        return modint() - *this;\n    }\n\n    modint pow(long\
    \ long n) const {\n        assert(0 <= n);\n        modint x = *this, res = 1;\n\
    \        while (n) {\n            if (n & 1) res *= x;\n            x *= x;\n\
    \            n >>= 1;\n        }\n        return res;\n    }\n    modint inv()\
    \ const {\n        assert(_v);\n        return pow(umod() - 2);\n    }\n\n   \
    \ friend modint operator+(const modint &lhs, const modint &rhs) {\n        return\
    \ modint(lhs) += rhs;\n    }\n    friend modint operator-(const modint &lhs, const\
    \ modint &rhs) {\n        return modint(lhs) -= rhs;\n    }\n    friend modint\
    \ operator*(const modint &lhs, const modint &rhs) {\n        return modint(lhs)\
    \ *= rhs;\n    }\n\n    friend modint operator/(const modint &lhs, const modint\
    \ &rhs) {\n        return modint(lhs) /= rhs;\n    }\n    friend bool operator==(const\
    \ modint &lhs, const modint &rhs) {\n        return lhs.val() == rhs.val();\n\
    \    }\n    friend bool operator!=(const modint &lhs, const modint &rhs) {\n \
    \       return !(lhs == rhs);\n    }\n\n  private:\n    unsigned int _v = 0;\n\
    \    static int m;\n\n    static unsigned int umod() {\n        return m;\n  \
    \  }\n};\n\ntemplate <int id> int dynamic_modint<id>::m = 998244353;\n\n}  //\
    \ namespace ebi"
  dependsOn:
  - modint/base.hpp
  isVerificationFile: false
  path: modint/dynamic_modint.hpp
  requiredBy:
  - math/mod_sqrt.hpp
  - fps/fps_sqrt.hpp
  timestamp: '2023-10-26 11:41:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  - test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  - test/math/Sqrt_Mod.test.cpp
  - test/matrix/Determinant_of_Matrix_Arbitrary_Mod.test.cpp
documentation_of: modint/dynamic_modint.hpp
layout: document
redirect_from:
- /library/modint/dynamic_modint.hpp
- /library/modint/dynamic_modint.hpp.html
title: modint/dynamic_modint.hpp
---
