---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: convolution/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: math/FormalPowerSeries.hpp
    title: math/FormalPowerSeries.hpp
  - icon: ':warning:'
    path: math/lagrange_interpolation.hpp
    title: math/lagrange_interpolation.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Bitwise_Xor_Convolution.test.cpp
    title: test/Bitwise_Xor_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Determinant_of_Matrix.test.cpp
    title: test/Determinant_of_Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/DynamicSegmentTree.test.cpp
    title: test/DynamicSegmentTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Exp_of_Formal_Power_Series.test.cpp
    title: test/Exp_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Exp_of_Set_Power_Series.test.cpp
    title: test/Exp_of_Set_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ImplicitTreap.test.cpp
    title: test/ImplicitTreap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Inv_of_Formal_Power_Series.test.cpp
    title: test/Inv_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
    title: test/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LazySegtree.test.cpp
    title: test/LazySegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Log_of_Formal_Power_Series.test.cpp
    title: test/Log_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/SWAG.test.cpp
    title: test/SWAG.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Tree_Path_Composite_Sum.test.cpp
    title: test/Tree_Path_Composite_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2863.test.cpp
    title: test/aoj/aoj_2863.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution.test.cpp
    title: test/convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/pow.test.cpp
    title: test/pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/subset_convolution.test.cpp
    title: test/subset_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/vertex_set_path_compositie.test.cpp
    title: test/vertex_set_path_compositie.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/modint.hpp\"\n\r\n#include <cassert>\r\n#include\
    \ <iostream>\r\n#include <type_traits>\r\n\r\nnamespace ebi {\r\n\r\nnamespace\
    \ internal {\r\n\r\nstruct modint_base {};\r\nstruct static_modint_base : modint_base\
    \ {};\r\n\r\ntemplate <class T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\r\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\r\
    \n\r\n}  // namespace internal\r\n\r\ntemplate <int m> struct static_modint :\
    \ internal::static_modint_base {\r\n  private:\r\n    using modint = static_modint;\r\
    \n\r\n  public:\r\n    static constexpr int mod() {\r\n        return m;\r\n \
    \   }\r\n\r\n    static modint raw(int v) {\r\n        modint x;\r\n        x._v\
    \ = v;\r\n        return x;\r\n    }\r\n\r\n    static_modint() : _v(0) {}\r\n\
    \r\n    static_modint(long long v) {\r\n        v %= (long long)umod();\r\n  \
    \      if (v < 0) v += (long long)umod();\r\n        _v = (unsigned int)v;\r\n\
    \    }\r\n\r\n    unsigned int val() const {\r\n        return _v;\r\n    }\r\n\
    \r\n    unsigned int value() const {\r\n        return val();\r\n    }\r\n\r\n\
    \    modint &operator++() {\r\n        _v++;\r\n        if (_v == umod()) _v =\
    \ 0;\r\n        return *this;\r\n    }\r\n    modint &operator--() {\r\n     \
    \   if (_v == 0) _v = umod();\r\n        _v--;\r\n        return *this;\r\n  \
    \  }\r\n    modint &operator+=(const modint &rhs) {\r\n        _v += rhs._v;\r\
    \n        if (_v >= umod()) _v -= umod();\r\n        return *this;\r\n    }\r\n\
    \    modint &operator-=(const modint &rhs) {\r\n        _v -= rhs._v;\r\n    \
    \    if (_v >= umod()) _v += umod();\r\n        return *this;\r\n    }\r\n   \
    \ modint &operator*=(const modint &rhs) {\r\n        unsigned long long x = _v;\r\
    \n        x *= rhs._v;\r\n        _v = (unsigned int)(x % (unsigned long long)umod());\r\
    \n        return *this;\r\n    }\r\n    modint &operator/=(const modint &rhs)\
    \ {\r\n        return *this = *this * rhs.inv();\r\n    }\r\n\r\n    modint operator+()\
    \ const {\r\n        return *this;\r\n    }\r\n    modint operator-() const {\r\
    \n        return modint() - *this;\r\n    }\r\n\r\n    modint pow(long long n)\
    \ const {\r\n        assert(0 <= n);\r\n        modint x = *this, res = 1;\r\n\
    \        while (n) {\r\n            if (n & 1) res *= x;\r\n            x *= x;\r\
    \n            n >>= 1;\r\n        }\r\n        return res;\r\n    }\r\n    modint\
    \ inv() const {\r\n        assert(_v);\r\n        return pow(umod() - 2);\r\n\
    \    }\r\n\r\n    friend modint operator+(const modint &lhs, const modint &rhs)\
    \ {\r\n        return modint(lhs) += rhs;\r\n    }\r\n    friend modint operator-(const\
    \ modint &lhs, const modint &rhs) {\r\n        return modint(lhs) -= rhs;\r\n\
    \    }\r\n    friend modint operator*(const modint &lhs, const modint &rhs) {\r\
    \n        return modint(lhs) *= rhs;\r\n    }\r\n\r\n    friend modint operator/(const\
    \ modint &lhs, const modint &rhs) {\r\n        return modint(lhs) /= rhs;\r\n\
    \    }\r\n    friend bool operator==(const modint &lhs, const modint &rhs) {\r\
    \n        return lhs.val() == rhs.val();\r\n    }\r\n    friend bool operator!=(const\
    \ modint &lhs, const modint &rhs) {\r\n        return !(lhs == rhs);\r\n    }\r\
    \n\r\n  private:\r\n    unsigned int _v;\r\n\r\n    static constexpr unsigned\
    \ int umod() {\r\n        return m;\r\n    }\r\n};\r\n\r\ntemplate <int m>\r\n\
    std::istream &operator>>(std::istream &os, static_modint<m> &a) {\r\n    long\
    \ long x;\r\n    os >> x;\r\n    a = x;\r\n    return os;\r\n}\r\ntemplate <int\
    \ m>\r\nstd::ostream &operator<<(std::ostream &os, const static_modint<m> &a)\
    \ {\r\n    return os << a.val();\r\n}\r\n\r\nusing modint998244353 = static_modint<998244353>;\r\
    \nusing modint1000000007 = static_modint<1000000007>;\r\n\r\nnamespace internal\
    \ {\r\n\r\ntemplate <class T>\r\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\r\n\r\ntemplate <class T>\r\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\r\
    \n\r\n}  // namespace internal\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <cassert>\r\n#include <iostream>\r\n#include\
    \ <type_traits>\r\n\r\nnamespace ebi {\r\n\r\nnamespace internal {\r\n\r\nstruct\
    \ modint_base {};\r\nstruct static_modint_base : modint_base {};\r\n\r\ntemplate\
    \ <class T> using is_modint = std::is_base_of<modint_base, T>;\r\ntemplate <class\
    \ T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\r\n\r\n}  // namespace\
    \ internal\r\n\r\ntemplate <int m> struct static_modint : internal::static_modint_base\
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
    \n\r\n}  // namespace internal\r\n\r\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: utility/modint.hpp
  requiredBy:
  - convolution/ntt.hpp
  - math/FormalPowerSeries.hpp
  - math/lagrange_interpolation.hpp
  timestamp: '2023-05-17 13:24:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Determinant_of_Matrix.test.cpp
  - test/vertex_set_path_compositie.test.cpp
  - test/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  - test/Inv_of_Formal_Power_Series.test.cpp
  - test/Exp_of_Formal_Power_Series.test.cpp
  - test/pow.test.cpp
  - test/Exp_of_Set_Power_Series.test.cpp
  - test/aoj/aoj_2863.test.cpp
  - test/Tree_Path_Composite_Sum.test.cpp
  - test/ImplicitTreap.test.cpp
  - test/LazySegtree.test.cpp
  - test/Log_of_Formal_Power_Series.test.cpp
  - test/DynamicSegmentTree.test.cpp
  - test/SWAG.test.cpp
  - test/subset_convolution.test.cpp
  - test/convolution.test.cpp
  - test/Bitwise_Xor_Convolution.test.cpp
documentation_of: utility/modint.hpp
layout: document
redirect_from:
- /library/utility/modint.hpp
- /library/utility/modint.hpp.html
title: utility/modint.hpp
---
