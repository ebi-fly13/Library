---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Exp_of_Formal_Power_Series.test.cpp
    title: test/Exp_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Inv_of_Formal_Power_Series.test.cpp
    title: test/Inv_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Log_of_Formal_Power_Series.test.cpp
    title: test/Log_of_Formal_Power_Series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/FormalPowerSeries.hpp\"\n\r\n#include <algorithm>\r\
    \n#include <cassert>\r\n#include <vector>\r\n\r\n#line 2 \"utility/modint.hpp\"\
    \n\r\n#line 4 \"utility/modint.hpp\"\n#include <iostream>\r\n#include <type_traits>\r\
    \n\r\nnamespace ebi {\r\n\r\nnamespace internal {\r\n\r\nstruct modint_base {};\r\
    \nstruct static_modint_base : modint_base {};\r\n\r\ntemplate <class T> using\
    \ is_modint = std::is_base_of<modint_base, T>;\r\ntemplate <class T> using is_modint_t\
    \ = std::enable_if_t<is_modint<T>::value>;\r\n\r\n}  // namespace internal\r\n\
    \r\ntemplate <int m> struct static_modint : internal::static_modint_base {\r\n\
    \  private:\r\n    using modint = static_modint;\r\n\r\n  public:\r\n    static\
    \ constexpr int mod() {\r\n        return m;\r\n    }\r\n\r\n    static modint\
    \ raw(int v) {\r\n        modint x;\r\n        x._v = v;\r\n        return x;\r\
    \n    }\r\n\r\n    static_modint() : _v(0) {}\r\n\r\n    static_modint(long long\
    \ v) {\r\n        v %= (long long)umod();\r\n        if (v < 0) v += (long long)umod();\r\
    \n        _v = (unsigned int)v;\r\n    }\r\n\r\n    unsigned int val() const {\r\
    \n        return _v;\r\n    }\r\n\r\n    unsigned int value() const {\r\n    \
    \    return val();\r\n    }\r\n\r\n    modint &operator++() {\r\n        _v++;\r\
    \n        if (_v == umod()) _v = 0;\r\n        return *this;\r\n    }\r\n    modint\
    \ &operator--() {\r\n        if (_v == 0) _v = umod();\r\n        _v--;\r\n  \
    \      return *this;\r\n    }\r\n    modint &operator+=(const modint &rhs) {\r\
    \n        _v += rhs._v;\r\n        if (_v >= umod()) _v -= umod();\r\n       \
    \ return *this;\r\n    }\r\n    modint &operator-=(const modint &rhs) {\r\n  \
    \      _v -= rhs._v;\r\n        if (_v >= umod()) _v += umod();\r\n        return\
    \ *this;\r\n    }\r\n    modint &operator*=(const modint &rhs) {\r\n        unsigned\
    \ long long x = _v;\r\n        x *= rhs._v;\r\n        _v = (unsigned int)(x %\
    \ (unsigned long long)umod());\r\n        return *this;\r\n    }\r\n    modint\
    \ &operator/=(const modint &rhs) {\r\n        return *this = *this * rhs.inv();\r\
    \n    }\r\n\r\n    modint operator+() const {\r\n        return *this;\r\n   \
    \ }\r\n    modint operator-() const {\r\n        return modint() - *this;\r\n\
    \    }\r\n\r\n    modint pow(long long n) const {\r\n        assert(0 <= n);\r\
    \n        modint x = *this, res = 1;\r\n        while (n) {\r\n            if\
    \ (n & 1) res *= x;\r\n            x *= x;\r\n            n >>= 1;\r\n       \
    \ }\r\n        return res;\r\n    }\r\n    modint inv() const {\r\n        assert(_v);\r\
    \n        return pow(umod() - 2);\r\n    }\r\n\r\n    friend modint operator+(const\
    \ modint &lhs, const modint &rhs) {\r\n        return modint(lhs) += rhs;\r\n\
    \    }\r\n    friend modint operator-(const modint &lhs, const modint &rhs) {\r\
    \n        return modint(lhs) -= rhs;\r\n    }\r\n    friend modint operator*(const\
    \ modint &lhs, const modint &rhs) {\r\n        return modint(lhs) *= rhs;\r\n\
    \    }\r\n\r\n    friend modint operator/(const modint &lhs, const modint &rhs)\
    \ {\r\n        return modint(lhs) /= rhs;\r\n    }\r\n    friend bool operator==(const\
    \ modint &lhs, const modint &rhs) {\r\n        return lhs.val() == rhs.val();\r\
    \n    }\r\n    friend bool operator!=(const modint &lhs, const modint &rhs) {\r\
    \n        return !(lhs == rhs);\r\n    }\r\n\r\n  private:\r\n    unsigned int\
    \ _v;\r\n\r\n    static constexpr unsigned int umod() {\r\n        return m;\r\
    \n    }\r\n};\r\n\r\ntemplate <int m>\r\nstd::istream &operator>>(std::istream\
    \ &os, static_modint<m> &a) {\r\n    long long x;\r\n    os >> x;\r\n    a = x;\r\
    \n    return os;\r\n}\r\ntemplate <int m>\r\nstd::ostream &operator<<(std::ostream\
    \ &os, const static_modint<m> &a) {\r\n    return os << a.val();\r\n}\r\n\r\n\
    using modint998244353 = static_modint<998244353>;\r\nusing modint1000000007 =\
    \ static_modint<1000000007>;\r\n\r\nnamespace internal {\r\n\r\ntemplate <class\
    \ T>\r\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\r\n\r\ntemplate <class T>\r\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\r\
    \n\r\n}  // namespace internal\r\n\r\n}  // namespace ebi\n#line 8 \"math/FormalPowerSeries.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class mint, std::vector<mint> (*convolution)(\r\
    \n                          const std::vector<mint> &, const std::vector<mint>\
    \ &)>\r\nstruct FormalPowerSeries : std::vector<mint> {\r\n  private:\r\n    using\
    \ std::vector<mint>::vector;\r\n    using std::vector<mint>::vector::operator=;\r\
    \n    using FPS = FormalPowerSeries;\r\n\r\n  public:\r\n    FPS operator+(const\
    \ FPS &rhs) const noexcept {\r\n        return FPS(*this) += rhs;\r\n    }\r\n\
    \    FPS operator-(const FPS &rhs) const noexcept {\r\n        return FPS(*this)\
    \ -= rhs;\r\n    }\r\n    FPS operator*(const FPS &rhs) const noexcept {\r\n \
    \       return FPS(*this) *= rhs;\r\n    }\r\n\r\n    FPS operator+(const mint\
    \ &rhs) const noexcept {\r\n        return FPS(*this) += rhs;\r\n    }\r\n\r\n\
    \    FPS operator-(const mint &rhs) const noexcept {\r\n        return FPS(*this)\
    \ -= rhs;\r\n    }\r\n\r\n    FPS operator*(const mint &rhs) const noexcept {\r\
    \n        return FPS(*this) *= rhs;\r\n    }\r\n\r\n    FPS &operator+=(const\
    \ FPS &rhs) noexcept {\r\n        if (this->size() < rhs.size()) this->resize(rhs.size());\r\
    \n        for (int i = 0; i < (int)rhs.size(); ++i) {\r\n            (*this)[i]\
    \ += rhs[i];\r\n        }\r\n        return *this;\r\n    }\r\n\r\n    FPS &operator-=(const\
    \ FPS &rhs) noexcept {\r\n        if (this->size() < rhs.size()) this->resize(rhs.size());\r\
    \n        for (int i = 0; i < (int)rhs.size(); ++i) {\r\n            (*this)[i]\
    \ -= rhs[i];\r\n        }\r\n        return *this;\r\n    }\r\n\r\n    FPS &operator*=(const\
    \ FPS &rhs) noexcept {\r\n        *this = convolution(*this, rhs);\r\n       \
    \ return *this;\r\n    }\r\n\r\n    FPS &operator+=(const mint &rhs) noexcept\
    \ {\r\n        if (this->empty()) this->resize(1);\r\n        (*this)[0] += rhs;\r\
    \n        return *this;\r\n    }\r\n\r\n    FPS &operator-=(const mint &rhs) noexcept\
    \ {\r\n        if (this->empty()) this->resize(1);\r\n        (*this)[0] -= rhs;\r\
    \n        return *this;\r\n    }\r\n\r\n    FPS &operator*=(const mint &rhs) noexcept\
    \ {\r\n        for (int i = 0; i < deg(); ++i) {\r\n            (*this)[i] *=\
    \ rhs;\r\n        }\r\n        return *this;\r\n    }\r\n\r\n    FPS operator-()\
    \ const {\r\n        FPS g(this->size());\r\n        for (int i = 0; i < (int)this->size();\
    \ i++) g[i] = -(*this)[i];\r\n        return g;\r\n    }\r\n\r\n    FPS pre(int\
    \ sz) const {\r\n        return FPS(this->begin(), this->begin() + std::min(deg(),\
    \ sz));\r\n    }\r\n\r\n    FPS differential() const {\r\n        int n = deg();\r\
    \n        FPS g(std::max(0, n - 1));\r\n        for (int i = 0; i < n - 1; i++)\
    \ {\r\n            g[i] = (*this)[i + 1] * (i + 1);\r\n        }\r\n        return\
    \ g;\r\n    }\r\n\r\n    FPS integral() const {\r\n        int n = deg();\r\n\
    \        FPS g(n + 1);\r\n        g[0] = 0;\r\n        if (n > 0) g[1] = 1;\r\n\
    \        auto mod = mint::mod();\r\n        for (int i = 2; i <= n; i++) g[i]\
    \ = (-g[mod % i]) * (mod / i);\r\n        for (int i = 0; i < n; i++) g[i + 1]\
    \ *= (*this)[i];\r\n        return g;\r\n    }\r\n\r\n    FPS inv(int d = -1)\
    \ const {\r\n        int n = 1;\r\n        if (d < 0) d = deg();\r\n        FPS\
    \ g(n);\r\n        g[0] = (*this)[0].inv();\r\n        while (n < d) {\r\n   \
    \         n <<= 1;\r\n            g = (g * 2 - g * g * this->pre(n)).pre(n);\r\
    \n        }\r\n        g.resize(d);\r\n        return g;\r\n    }\r\n\r\n    FPS\
    \ log(int d = -1) const {\r\n        assert((*this)[0].val() == 1);\r\n      \
    \  if (d < 0) d = deg();\r\n        return ((*this).differential() * (*this).inv(d)).pre(d\
    \ - 1).integral();\r\n    }\r\n\r\n    FPS exp(int d = -1) const {\r\n       \
    \ assert((*this)[0].val() == 0);\r\n        int n = 1;\r\n        if (d < 0) d\
    \ = deg();\r\n        FPS g(n);\r\n        g[0] = 1;\r\n        while (n < d)\
    \ {\r\n            n <<= 1;\r\n            g = (g * (this->pre(n) - g.log(n) +\
    \ 1)).pre(n);\r\n        }\r\n        g.resize(d);\r\n        return g;\r\n  \
    \  }\r\n\r\n    int deg() const {\r\n        return (*this).size();\r\n    }\r\
    \n\r\n    void shrink() {\r\n        while ((!this->empty()) && this->back() ==\
    \ 0) this->pop_back();\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <algorithm>\r\n#include <cassert>\r\n#include\
    \ <vector>\r\n\r\n#include \"../utility/modint.hpp\"\r\n\r\nnamespace ebi {\r\n\
    \r\ntemplate <class mint, std::vector<mint> (*convolution)(\r\n              \
    \            const std::vector<mint> &, const std::vector<mint> &)>\r\nstruct\
    \ FormalPowerSeries : std::vector<mint> {\r\n  private:\r\n    using std::vector<mint>::vector;\r\
    \n    using std::vector<mint>::vector::operator=;\r\n    using FPS = FormalPowerSeries;\r\
    \n\r\n  public:\r\n    FPS operator+(const FPS &rhs) const noexcept {\r\n    \
    \    return FPS(*this) += rhs;\r\n    }\r\n    FPS operator-(const FPS &rhs) const\
    \ noexcept {\r\n        return FPS(*this) -= rhs;\r\n    }\r\n    FPS operator*(const\
    \ FPS &rhs) const noexcept {\r\n        return FPS(*this) *= rhs;\r\n    }\r\n\
    \r\n    FPS operator+(const mint &rhs) const noexcept {\r\n        return FPS(*this)\
    \ += rhs;\r\n    }\r\n\r\n    FPS operator-(const mint &rhs) const noexcept {\r\
    \n        return FPS(*this) -= rhs;\r\n    }\r\n\r\n    FPS operator*(const mint\
    \ &rhs) const noexcept {\r\n        return FPS(*this) *= rhs;\r\n    }\r\n\r\n\
    \    FPS &operator+=(const FPS &rhs) noexcept {\r\n        if (this->size() <\
    \ rhs.size()) this->resize(rhs.size());\r\n        for (int i = 0; i < (int)rhs.size();\
    \ ++i) {\r\n            (*this)[i] += rhs[i];\r\n        }\r\n        return *this;\r\
    \n    }\r\n\r\n    FPS &operator-=(const FPS &rhs) noexcept {\r\n        if (this->size()\
    \ < rhs.size()) this->resize(rhs.size());\r\n        for (int i = 0; i < (int)rhs.size();\
    \ ++i) {\r\n            (*this)[i] -= rhs[i];\r\n        }\r\n        return *this;\r\
    \n    }\r\n\r\n    FPS &operator*=(const FPS &rhs) noexcept {\r\n        *this\
    \ = convolution(*this, rhs);\r\n        return *this;\r\n    }\r\n\r\n    FPS\
    \ &operator+=(const mint &rhs) noexcept {\r\n        if (this->empty()) this->resize(1);\r\
    \n        (*this)[0] += rhs;\r\n        return *this;\r\n    }\r\n\r\n    FPS\
    \ &operator-=(const mint &rhs) noexcept {\r\n        if (this->empty()) this->resize(1);\r\
    \n        (*this)[0] -= rhs;\r\n        return *this;\r\n    }\r\n\r\n    FPS\
    \ &operator*=(const mint &rhs) noexcept {\r\n        for (int i = 0; i < deg();\
    \ ++i) {\r\n            (*this)[i] *= rhs;\r\n        }\r\n        return *this;\r\
    \n    }\r\n\r\n    FPS operator-() const {\r\n        FPS g(this->size());\r\n\
    \        for (int i = 0; i < (int)this->size(); i++) g[i] = -(*this)[i];\r\n \
    \       return g;\r\n    }\r\n\r\n    FPS pre(int sz) const {\r\n        return\
    \ FPS(this->begin(), this->begin() + std::min(deg(), sz));\r\n    }\r\n\r\n  \
    \  FPS differential() const {\r\n        int n = deg();\r\n        FPS g(std::max(0,\
    \ n - 1));\r\n        for (int i = 0; i < n - 1; i++) {\r\n            g[i] =\
    \ (*this)[i + 1] * (i + 1);\r\n        }\r\n        return g;\r\n    }\r\n\r\n\
    \    FPS integral() const {\r\n        int n = deg();\r\n        FPS g(n + 1);\r\
    \n        g[0] = 0;\r\n        if (n > 0) g[1] = 1;\r\n        auto mod = mint::mod();\r\
    \n        for (int i = 2; i <= n; i++) g[i] = (-g[mod % i]) * (mod / i);\r\n \
    \       for (int i = 0; i < n; i++) g[i + 1] *= (*this)[i];\r\n        return\
    \ g;\r\n    }\r\n\r\n    FPS inv(int d = -1) const {\r\n        int n = 1;\r\n\
    \        if (d < 0) d = deg();\r\n        FPS g(n);\r\n        g[0] = (*this)[0].inv();\r\
    \n        while (n < d) {\r\n            n <<= 1;\r\n            g = (g * 2 -\
    \ g * g * this->pre(n)).pre(n);\r\n        }\r\n        g.resize(d);\r\n     \
    \   return g;\r\n    }\r\n\r\n    FPS log(int d = -1) const {\r\n        assert((*this)[0].val()\
    \ == 1);\r\n        if (d < 0) d = deg();\r\n        return ((*this).differential()\
    \ * (*this).inv(d)).pre(d - 1).integral();\r\n    }\r\n\r\n    FPS exp(int d =\
    \ -1) const {\r\n        assert((*this)[0].val() == 0);\r\n        int n = 1;\r\
    \n        if (d < 0) d = deg();\r\n        FPS g(n);\r\n        g[0] = 1;\r\n\
    \        while (n < d) {\r\n            n <<= 1;\r\n            g = (g * (this->pre(n)\
    \ - g.log(n) + 1)).pre(n);\r\n        }\r\n        g.resize(d);\r\n        return\
    \ g;\r\n    }\r\n\r\n    int deg() const {\r\n        return (*this).size();\r\
    \n    }\r\n\r\n    void shrink() {\r\n        while ((!this->empty()) && this->back()\
    \ == 0) this->pop_back();\r\n    }\r\n};\r\n\r\n}  // namespace ebi"
  dependsOn:
  - utility/modint.hpp
  isVerificationFile: false
  path: math/FormalPowerSeries.hpp
  requiredBy: []
  timestamp: '2023-05-24 22:16:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Inv_of_Formal_Power_Series.test.cpp
  - test/Exp_of_Formal_Power_Series.test.cpp
  - test/Log_of_Formal_Power_Series.test.cpp
documentation_of: math/FormalPowerSeries.hpp
layout: document
redirect_from:
- /library/math/FormalPowerSeries.hpp
- /library/math/FormalPowerSeries.hpp.html
title: math/FormalPowerSeries.hpp
---
