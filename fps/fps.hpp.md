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
  - icon: ':heavy_check_mark:'
    path: test/Pow_of_Formal_Power_Series.test.cpp
    title: test/Pow_of_Formal_Power_Series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/fps.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n\n#line 2 \"utility/modint.hpp\"\n\r\n#line 4 \"utility/modint.hpp\"\
    \n#include <iostream>\r\n#include <type_traits>\r\n\r\nnamespace ebi {\r\n\r\n\
    namespace internal {\r\n\r\nstruct modint_base {};\r\nstruct static_modint_base\
    \ : modint_base {};\r\n\r\ntemplate <class T> using is_modint = std::is_base_of<modint_base,\
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
    \n\r\n}  // namespace internal\r\n\r\n}  // namespace ebi\n#line 8 \"fps/fps.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class mint, std::vector<mint> (*convolution)(\n\
    \                          const std::vector<mint> &, const std::vector<mint>\
    \ &)>\nstruct FPS : std::vector<mint> {\n  private:\n    using std::vector<mint>::vector;\n\
    \    using std::vector<mint>::vector::operator=;\n\n  public:\n    FPS operator+(const\
    \ FPS &rhs) const noexcept {\n        return FPS(*this) += rhs;\n    }\n    FPS\
    \ operator-(const FPS &rhs) const noexcept {\n        return FPS(*this) -= rhs;\n\
    \    }\n    FPS operator*(const FPS &rhs) const noexcept {\n        return FPS(*this)\
    \ *= rhs;\n    }\n\n    FPS operator+(const mint &rhs) const noexcept {\n    \
    \    return FPS(*this) += rhs;\n    }\n\n    FPS operator-(const mint &rhs) const\
    \ noexcept {\n        return FPS(*this) -= rhs;\n    }\n\n    FPS operator*(const\
    \ mint &rhs) const noexcept {\n        return FPS(*this) *= rhs;\n    }\n\n  \
    \  FPS &operator+=(const FPS &rhs) noexcept {\n        if (this->size() < rhs.size())\
    \ this->resize(rhs.size());\n        for (int i = 0; i < (int)rhs.size(); ++i)\
    \ {\n            (*this)[i] += rhs[i];\n        }\n        return *this;\n   \
    \ }\n\n    FPS &operator-=(const FPS &rhs) noexcept {\n        if (this->size()\
    \ < rhs.size()) this->resize(rhs.size());\n        for (int i = 0; i < (int)rhs.size();\
    \ ++i) {\n            (*this)[i] -= rhs[i];\n        }\n        return *this;\n\
    \    }\n\n    FPS &operator*=(const FPS &rhs) noexcept {\n        *this = convolution(*this,\
    \ rhs);\n        return *this;\n    }\n\n    FPS &operator+=(const mint &rhs)\
    \ noexcept {\n        if (this->empty()) this->resize(1);\n        (*this)[0]\
    \ += rhs;\n        return *this;\n    }\n\n    FPS &operator-=(const mint &rhs)\
    \ noexcept {\n        if (this->empty()) this->resize(1);\n        (*this)[0]\
    \ -= rhs;\n        return *this;\n    }\n\n    FPS &operator*=(const mint &rhs)\
    \ noexcept {\n        for (int i = 0; i < deg(); ++i) {\n            (*this)[i]\
    \ *= rhs;\n        }\n        return *this;\n    }\n\n    FPS operator>>(int d)\
    \ const {\n        if (deg() <= d) return {};\n        FPS f = *this;\n      \
    \  f.erase(f.begin(), f.begin() + d);\n        return f;\n    }\n\n    FPS operator<<(int\
    \ d) const {\n        FPS f = *this;\n        f.insert(f.begin(), d, 0);\n   \
    \     return f;\n    }\n\n    FPS operator-() const {\n        FPS g(this->size());\n\
    \        for (int i = 0; i < (int)this->size(); i++) g[i] = -(*this)[i];\n   \
    \     return g;\n    }\n\n    FPS pre(int sz) const {\n        return FPS(this->begin(),\
    \ this->begin() + std::min(deg(), sz));\n    }\n\n    FPS differential() const\
    \ {\n        int n = deg();\n        FPS g(std::max(0, n - 1));\n        for (int\
    \ i = 0; i < n - 1; i++) {\n            g[i] = (*this)[i + 1] * (i + 1);\n   \
    \     }\n        return g;\n    }\n\n    FPS integral() const {\n        int n\
    \ = deg();\n        FPS g(n + 1);\n        g[0] = 0;\n        if (n > 0) g[1]\
    \ = 1;\n        auto mod = mint::mod();\n        for (int i = 2; i <= n; i++)\
    \ g[i] = (-g[mod % i]) * (mod / i);\n        for (int i = 0; i < n; i++) g[i +\
    \ 1] *= (*this)[i];\n        return g;\n    }\n\n    FPS inv(int d = -1) const\
    \ {\n        int n = 1;\n        if (d < 0) d = deg();\n        FPS g(n);\n  \
    \      g[0] = (*this)[0].inv();\n        while (n < d) {\n            n <<= 1;\n\
    \            g = (g * 2 - g * g * this->pre(n)).pre(n);\n        }\n        g.resize(d);\n\
    \        return g;\n    }\n\n    FPS log(int d = -1) const {\n        assert((*this)[0].val()\
    \ == 1);\n        if (d < 0) d = deg();\n        return ((*this).differential()\
    \ * (*this).inv(d)).pre(d - 1).integral();\n    }\n\n    FPS exp(int d = -1) const\
    \ {\n        assert((*this)[0].val() == 0);\n        int n = 1;\n        if (d\
    \ < 0) d = deg();\n        FPS g(n);\n        g[0] = 1;\n        while (n < d)\
    \ {\n            n <<= 1;\n            g = (g * (this->pre(n) - g.log(n) + 1)).pre(n);\n\
    \        }\n        g.resize(d);\n        return g;\n    }\n\n    FPS pow(int64_t\
    \ k, int d = -1) const {\n        const int n = deg();\n        if (d < 0) d =\
    \ n;\n        if (k == 0) {\n            FPS f(d);\n            if (d > 0) f[0]\
    \ = 1;\n            return f;\n        }\n        for (int i = 0; i < n; i++)\
    \ {\n            if ((*this)[i] != 0) {\n                mint rev = (*this)[i].inv();\n\
    \                FPS f = (((*this * rev) >> i).log(d) * k).exp(d);\n         \
    \       f *= (*this)[i].pow(k);\n                f = (f << (i * k)).pre(d);\n\
    \                if (f.deg() < d) f.resize(d);\n                return f;\n  \
    \          }\n            if (i + 1 >= (d + k - 1) / k) break;\n        }\n  \
    \      return FPS(d);\n    }\n\n    int deg() const {\n        return (*this).size();\n\
    \    }\n\n    void shrink() {\n        while ((!this->empty()) && this->back()\
    \ == 0) this->pop_back();\n    }\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \n#include \"../utility/modint.hpp\"\n\nnamespace ebi {\n\ntemplate <class mint,\
    \ std::vector<mint> (*convolution)(\n                          const std::vector<mint>\
    \ &, const std::vector<mint> &)>\nstruct FPS : std::vector<mint> {\n  private:\n\
    \    using std::vector<mint>::vector;\n    using std::vector<mint>::vector::operator=;\n\
    \n  public:\n    FPS operator+(const FPS &rhs) const noexcept {\n        return\
    \ FPS(*this) += rhs;\n    }\n    FPS operator-(const FPS &rhs) const noexcept\
    \ {\n        return FPS(*this) -= rhs;\n    }\n    FPS operator*(const FPS &rhs)\
    \ const noexcept {\n        return FPS(*this) *= rhs;\n    }\n\n    FPS operator+(const\
    \ mint &rhs) const noexcept {\n        return FPS(*this) += rhs;\n    }\n\n  \
    \  FPS operator-(const mint &rhs) const noexcept {\n        return FPS(*this)\
    \ -= rhs;\n    }\n\n    FPS operator*(const mint &rhs) const noexcept {\n    \
    \    return FPS(*this) *= rhs;\n    }\n\n    FPS &operator+=(const FPS &rhs) noexcept\
    \ {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n      \
    \  for (int i = 0; i < (int)rhs.size(); ++i) {\n            (*this)[i] += rhs[i];\n\
    \        }\n        return *this;\n    }\n\n    FPS &operator-=(const FPS &rhs)\
    \ noexcept {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n\
    \        for (int i = 0; i < (int)rhs.size(); ++i) {\n            (*this)[i] -=\
    \ rhs[i];\n        }\n        return *this;\n    }\n\n    FPS &operator*=(const\
    \ FPS &rhs) noexcept {\n        *this = convolution(*this, rhs);\n        return\
    \ *this;\n    }\n\n    FPS &operator+=(const mint &rhs) noexcept {\n        if\
    \ (this->empty()) this->resize(1);\n        (*this)[0] += rhs;\n        return\
    \ *this;\n    }\n\n    FPS &operator-=(const mint &rhs) noexcept {\n        if\
    \ (this->empty()) this->resize(1);\n        (*this)[0] -= rhs;\n        return\
    \ *this;\n    }\n\n    FPS &operator*=(const mint &rhs) noexcept {\n        for\
    \ (int i = 0; i < deg(); ++i) {\n            (*this)[i] *= rhs;\n        }\n \
    \       return *this;\n    }\n\n    FPS operator>>(int d) const {\n        if\
    \ (deg() <= d) return {};\n        FPS f = *this;\n        f.erase(f.begin(),\
    \ f.begin() + d);\n        return f;\n    }\n\n    FPS operator<<(int d) const\
    \ {\n        FPS f = *this;\n        f.insert(f.begin(), d, 0);\n        return\
    \ f;\n    }\n\n    FPS operator-() const {\n        FPS g(this->size());\n   \
    \     for (int i = 0; i < (int)this->size(); i++) g[i] = -(*this)[i];\n      \
    \  return g;\n    }\n\n    FPS pre(int sz) const {\n        return FPS(this->begin(),\
    \ this->begin() + std::min(deg(), sz));\n    }\n\n    FPS differential() const\
    \ {\n        int n = deg();\n        FPS g(std::max(0, n - 1));\n        for (int\
    \ i = 0; i < n - 1; i++) {\n            g[i] = (*this)[i + 1] * (i + 1);\n   \
    \     }\n        return g;\n    }\n\n    FPS integral() const {\n        int n\
    \ = deg();\n        FPS g(n + 1);\n        g[0] = 0;\n        if (n > 0) g[1]\
    \ = 1;\n        auto mod = mint::mod();\n        for (int i = 2; i <= n; i++)\
    \ g[i] = (-g[mod % i]) * (mod / i);\n        for (int i = 0; i < n; i++) g[i +\
    \ 1] *= (*this)[i];\n        return g;\n    }\n\n    FPS inv(int d = -1) const\
    \ {\n        int n = 1;\n        if (d < 0) d = deg();\n        FPS g(n);\n  \
    \      g[0] = (*this)[0].inv();\n        while (n < d) {\n            n <<= 1;\n\
    \            g = (g * 2 - g * g * this->pre(n)).pre(n);\n        }\n        g.resize(d);\n\
    \        return g;\n    }\n\n    FPS log(int d = -1) const {\n        assert((*this)[0].val()\
    \ == 1);\n        if (d < 0) d = deg();\n        return ((*this).differential()\
    \ * (*this).inv(d)).pre(d - 1).integral();\n    }\n\n    FPS exp(int d = -1) const\
    \ {\n        assert((*this)[0].val() == 0);\n        int n = 1;\n        if (d\
    \ < 0) d = deg();\n        FPS g(n);\n        g[0] = 1;\n        while (n < d)\
    \ {\n            n <<= 1;\n            g = (g * (this->pre(n) - g.log(n) + 1)).pre(n);\n\
    \        }\n        g.resize(d);\n        return g;\n    }\n\n    FPS pow(int64_t\
    \ k, int d = -1) const {\n        const int n = deg();\n        if (d < 0) d =\
    \ n;\n        if (k == 0) {\n            FPS f(d);\n            if (d > 0) f[0]\
    \ = 1;\n            return f;\n        }\n        for (int i = 0; i < n; i++)\
    \ {\n            if ((*this)[i] != 0) {\n                mint rev = (*this)[i].inv();\n\
    \                FPS f = (((*this * rev) >> i).log(d) * k).exp(d);\n         \
    \       f *= (*this)[i].pow(k);\n                f = (f << (i * k)).pre(d);\n\
    \                if (f.deg() < d) f.resize(d);\n                return f;\n  \
    \          }\n            if (i + 1 >= (d + k - 1) / k) break;\n        }\n  \
    \      return FPS(d);\n    }\n\n    int deg() const {\n        return (*this).size();\n\
    \    }\n\n    void shrink() {\n        while ((!this->empty()) && this->back()\
    \ == 0) this->pop_back();\n    }\n};\n\n}  // namespace ebi"
  dependsOn:
  - utility/modint.hpp
  isVerificationFile: false
  path: fps/fps.hpp
  requiredBy: []
  timestamp: '2023-05-25 01:04:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Inv_of_Formal_Power_Series.test.cpp
  - test/Pow_of_Formal_Power_Series.test.cpp
  - test/Exp_of_Formal_Power_Series.test.cpp
  - test/Log_of_Formal_Power_Series.test.cpp
documentation_of: fps/fps.hpp
layout: document
redirect_from:
- /library/fps/fps.hpp
- /library/fps/fps.hpp.html
title: fps/fps.hpp
---
