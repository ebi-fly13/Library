---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
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
    links:
    - https://opt-cp.com/fps-fast-algorithms/
  bundledCode: "#line 2 \"math/FormalPowerSeries.hpp\"\n\r\n#line 2 \"convolution/convolution.hpp\"\
    \n\r\n/*\r\n    reference: https://hcpc-hokudai.github.io/archive/math_fft_002.pdf\r\
    \n    mod 998244353 \u4E0A\u3067\u306E\u7573\u307F\u8FBC\u307F\u3092 O(N log N)\
    \ \u3067\u6C42\u3081\u308B.\r\n*/\r\n\r\n#line 2 \"utility/modint.hpp\"\n\r\n\
    #include <cassert>\r\n#include <iostream>\r\n\r\nnamespace ebi {\r\n\r\ntemplate\
    \ <int m> struct modint {\r\n  public:\r\n    static constexpr int mod() {\r\n\
    \        return m;\r\n    }\r\n\r\n    static modint raw(int v) {\r\n        modint\
    \ x;\r\n        x._v = v;\r\n        return x;\r\n    }\r\n\r\n    modint() :\
    \ _v(0) {}\r\n\r\n    modint(long long v) {\r\n        v %= (long long)umod();\r\
    \n        if (v < 0) v += (long long)umod();\r\n        _v = (unsigned int)v;\r\
    \n    }\r\n\r\n    unsigned int val() const {\r\n        return _v;\r\n    }\r\
    \n\r\n    unsigned int value() const {\r\n        return val();\r\n    }\r\n\r\
    \n    modint &operator++() {\r\n        _v++;\r\n        if (_v == umod()) _v\
    \ = 0;\r\n        return *this;\r\n    }\r\n    modint &operator--() {\r\n   \
    \     if (_v == 0) _v = umod();\r\n        _v--;\r\n        return *this;\r\n\
    \    }\r\n    modint &operator+=(const modint &rhs) {\r\n        _v += rhs._v;\r\
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
    \ int umod() {\r\n        return m;\r\n    }\r\n};\r\n\r\ntemplate <int m> std::istream\
    \ &operator>>(std::istream &os, modint<m> &a) {\r\n    long long x;\r\n    os\
    \ >> x;\r\n    a = x;\r\n    return os;\r\n}\r\ntemplate <int m>\r\nstd::ostream\
    \ &operator<<(std::ostream &os, const modint<m> &a) {\r\n    return os << a.val();\r\
    \n}\r\n\r\nusing modint998244353 = modint<998244353>;\r\nusing modint1000000007\
    \ = modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 9 \"convolution/convolution.hpp\"\
    \n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\nusing mint = ebi::modint998244353;\r\
    \n\r\nnamespace internal {\r\n\r\nconst mint primitive_root = 3;\r\n\r\nvoid dft(std::vector<mint>\
    \ &f) {\r\n    int n = f.size();\r\n    if (n == 1) return;\r\n    std::vector<mint>\
    \ a(n / 2), b(n / 2);\r\n    for (int i = 0; i < n / 2; ++i) {\r\n        a[i]\
    \ = f[2 * i];\r\n        b[i] = f[2 * i + 1];\r\n    }\r\n    dft(a);\r\n    dft(b);\r\
    \n    const mint zeta = primitive_root.pow((mint::mod() - 1) / n);\r\n    mint\
    \ x = 1;\r\n    for (int i = 0; i < n; ++i) {\r\n        f[i] = a[i % (n / 2)]\
    \ + x * b[i % (n / 2)];\r\n        x *= zeta;\r\n    }\r\n}\r\n\r\nvoid inv_dft(std::vector<mint>\
    \ &f) {\r\n    int n = f.size();\r\n    if (n == 1) return;\r\n    std::vector<mint>\
    \ a(n / 2), b(n / 2);\r\n    for (int i = 0; i < n / 2; ++i) {\r\n        a[i]\
    \ = f[2 * i];\r\n        b[i] = f[2 * i + 1];\r\n    }\r\n    inv_dft(a);\r\n\
    \    inv_dft(b);\r\n    const mint inv_zeta = primitive_root.pow((mint::mod()\
    \ - 1) / n).inv();\r\n    mint x = 1;\r\n    for (int i = 0; i < n; ++i) {\r\n\
    \        f[i] = a[i % (n / 2)] + x * b[i % (n / 2)];\r\n        x *= inv_zeta;\r\
    \n    }\r\n}\r\n\r\n}  // namespace internal\r\n\r\nstd::vector<mint> convolution(const\
    \ std::vector<mint> &f,\r\n                              const std::vector<mint>\
    \ &g) {\r\n    int n = 1;\r\n    while (n < (int)f.size() + (int)g.size() - 1)\
    \ n <<= 1;\r\n    std::vector<mint> a(n, 0), b(n, 0), fg(n, 0);\r\n    std::copy(f.begin(),\
    \ f.end(), a.begin());\r\n    std::copy(g.begin(), g.end(), b.begin());\r\n  \
    \  internal::dft(a);\r\n    internal::dft(b);\r\n    for (int i = 0; i < n; ++i)\
    \ {\r\n        fg[i] = a[i] * b[i];\r\n    }\r\n    internal::inv_dft(fg);\r\n\
    \    mint in = mint(n).inv();\r\n    for (int i = 0; i < n; ++i) {\r\n       \
    \ fg[i] *= in;\r\n    }\r\n    return fg;\r\n}\r\n\r\n}  // namespace ebi\n#line\
    \ 5 \"math/FormalPowerSeries.hpp\"\n\r\n#include <algorithm>\r\n#line 9 \"math/FormalPowerSeries.hpp\"\
    \n\r\n/*\r\n    reference: https://opt-cp.com/fps-fast-algorithms/\r\n*/\r\n\r\
    \nnamespace ebi {\r\n\r\nusing mint = modint998244353;\r\n\r\nstruct FormalPowerSeries\
    \ : std::vector<mint> {\r\n  private:\r\n    using std::vector<mint>::vector;\r\
    \n    using std::vector<mint>::vector::operator=;\r\n    using FPS = FormalPowerSeries;\r\
    \n\r\n  public:\r\n    FPS operator+(const FPS &rhs) const noexcept {\r\n    \
    \    return FPS(*this) += rhs;\r\n    }\r\n    FPS operator-(const FPS &rhs) const\
    \ noexcept {\r\n        return FPS(*this) -= rhs;\r\n    }\r\n    FPS operator*(const\
    \ FPS &rhs) const noexcept {\r\n        return FPS(*this) *= rhs;\r\n    }\r\n\
    \    FPS operator/(const FPS &rhs) const noexcept {\r\n        return FPS(*this)\
    \ /= rhs;\r\n    }\r\n\r\n    FPS &operator+=(const FPS &rhs) noexcept {\r\n \
    \       int sz = std::min(deg(), rhs.deg());\r\n        for (int i = 0; i < sz;\
    \ ++i) {\r\n            (*this)[i] += rhs[i];\r\n        }\r\n        return *this;\r\
    \n    }\r\n\r\n    FPS &operator-=(const FPS &rhs) noexcept {\r\n        int sz\
    \ = std::min(deg(), rhs.deg());\r\n        for (int i = 0; i < sz; ++i) {\r\n\
    \            (*this)[i] -= rhs[i];\r\n        }\r\n        return *this;\r\n \
    \   }\r\n\r\n    FPS &operator*=(const FPS &rhs) noexcept {\r\n        int n =\
    \ deg();\r\n        *this = convolution(*this, rhs);\r\n        (*this).resize(n);\r\
    \n        return *this;\r\n    }\r\n\r\n    FPS &operator/=(const FPS &rhs) noexcept\
    \ {\r\n        *this *= rhs.inv();\r\n        return *this;\r\n    }\r\n\r\n \
    \   FPS &operator*=(const mint rhs) noexcept {\r\n        for (int i = 0; i <\
    \ deg(); ++i) {\r\n            (*this)[i] *= rhs;\r\n        }\r\n        return\
    \ *this;\r\n    }\r\n\r\n    FPS inv() const {\r\n        int n = 1, sz = deg();\r\
    \n        FPS g(n);\r\n        g[0] = (*this)[0].inv();\r\n        while (n <\
    \ sz) {\r\n            n <<= 1;\r\n            FPS f((*this).begin(), (*this).begin()\
    \ + std::min(sz, n));\r\n            f.resize(n);\r\n            g.resize(n);\r\
    \n            FPS h = f * g;\r\n            h.erase(h.begin(), h.begin() + n /\
    \ 2);\r\n            h.resize(n);\r\n            h = h * g;\r\n            for\
    \ (int i = 0; i < n / 2; i++) {\r\n                g[i + n / 2] -= h[i];\r\n \
    \           }\r\n        }\r\n        g.resize(sz);\r\n        return g;\r\n \
    \   }\r\n\r\n    FPS exp() {\r\n        assert((*this)[0].val() == 0);\r\n   \
    \     int n = 1, sz = deg();\r\n        FPS g(n);\r\n        g[0] = 1;\r\n   \
    \     while (n < sz) {\r\n            n <<= 1;\r\n            FPS f((*this).begin(),\
    \ (*this).begin() + std::min(sz, n));\r\n            f.resize(n);\r\n        \
    \    g.resize(n);\r\n            g = g * (f - g.log()) + g;\r\n        }\r\n \
    \       return g;\r\n    }\r\n\r\n    FPS differential() {\r\n        int n =\
    \ deg();\r\n        FPS g(n);\r\n        for (int i = 0; i < n - 1; i++) {\r\n\
    \            g[i] = (*this)[i + 1] * (i + 1);\r\n        }\r\n        g[n - 1]\
    \ = 0;\r\n        return g;\r\n    }\r\n\r\n    FPS integral() {\r\n        int\
    \ n = deg();\r\n        FPS g(n + 1);\r\n        g[0] = 0;\r\n        for (int\
    \ i = 0; i < n; i++) {\r\n            g[i + 1] = (*this)[i] / (mint(i + 1));\r\
    \n        }\r\n        return g;\r\n    }\r\n\r\n    FPS log() {\r\n        assert((*this)[0].val()\
    \ == 1);\r\n        FPS g = (*this).differential() / (*this);\r\n        return\
    \ g.integral();\r\n    }\r\n\r\n    int deg() const {\r\n        return (*this).size();\r\
    \n    }\r\n};\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include \"../convolution/convolution.hpp\"\r\n#include\
    \ \"../utility/modint.hpp\"\r\n\r\n#include <algorithm>\r\n#include <cassert>\r\
    \n#include <vector>\r\n\r\n/*\r\n    reference: https://opt-cp.com/fps-fast-algorithms/\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\nusing mint = modint998244353;\r\n\r\nstruct\
    \ FormalPowerSeries : std::vector<mint> {\r\n  private:\r\n    using std::vector<mint>::vector;\r\
    \n    using std::vector<mint>::vector::operator=;\r\n    using FPS = FormalPowerSeries;\r\
    \n\r\n  public:\r\n    FPS operator+(const FPS &rhs) const noexcept {\r\n    \
    \    return FPS(*this) += rhs;\r\n    }\r\n    FPS operator-(const FPS &rhs) const\
    \ noexcept {\r\n        return FPS(*this) -= rhs;\r\n    }\r\n    FPS operator*(const\
    \ FPS &rhs) const noexcept {\r\n        return FPS(*this) *= rhs;\r\n    }\r\n\
    \    FPS operator/(const FPS &rhs) const noexcept {\r\n        return FPS(*this)\
    \ /= rhs;\r\n    }\r\n\r\n    FPS &operator+=(const FPS &rhs) noexcept {\r\n \
    \       int sz = std::min(deg(), rhs.deg());\r\n        for (int i = 0; i < sz;\
    \ ++i) {\r\n            (*this)[i] += rhs[i];\r\n        }\r\n        return *this;\r\
    \n    }\r\n\r\n    FPS &operator-=(const FPS &rhs) noexcept {\r\n        int sz\
    \ = std::min(deg(), rhs.deg());\r\n        for (int i = 0; i < sz; ++i) {\r\n\
    \            (*this)[i] -= rhs[i];\r\n        }\r\n        return *this;\r\n \
    \   }\r\n\r\n    FPS &operator*=(const FPS &rhs) noexcept {\r\n        int n =\
    \ deg();\r\n        *this = convolution(*this, rhs);\r\n        (*this).resize(n);\r\
    \n        return *this;\r\n    }\r\n\r\n    FPS &operator/=(const FPS &rhs) noexcept\
    \ {\r\n        *this *= rhs.inv();\r\n        return *this;\r\n    }\r\n\r\n \
    \   FPS &operator*=(const mint rhs) noexcept {\r\n        for (int i = 0; i <\
    \ deg(); ++i) {\r\n            (*this)[i] *= rhs;\r\n        }\r\n        return\
    \ *this;\r\n    }\r\n\r\n    FPS inv() const {\r\n        int n = 1, sz = deg();\r\
    \n        FPS g(n);\r\n        g[0] = (*this)[0].inv();\r\n        while (n <\
    \ sz) {\r\n            n <<= 1;\r\n            FPS f((*this).begin(), (*this).begin()\
    \ + std::min(sz, n));\r\n            f.resize(n);\r\n            g.resize(n);\r\
    \n            FPS h = f * g;\r\n            h.erase(h.begin(), h.begin() + n /\
    \ 2);\r\n            h.resize(n);\r\n            h = h * g;\r\n            for\
    \ (int i = 0; i < n / 2; i++) {\r\n                g[i + n / 2] -= h[i];\r\n \
    \           }\r\n        }\r\n        g.resize(sz);\r\n        return g;\r\n \
    \   }\r\n\r\n    FPS exp() {\r\n        assert((*this)[0].val() == 0);\r\n   \
    \     int n = 1, sz = deg();\r\n        FPS g(n);\r\n        g[0] = 1;\r\n   \
    \     while (n < sz) {\r\n            n <<= 1;\r\n            FPS f((*this).begin(),\
    \ (*this).begin() + std::min(sz, n));\r\n            f.resize(n);\r\n        \
    \    g.resize(n);\r\n            g = g * (f - g.log()) + g;\r\n        }\r\n \
    \       return g;\r\n    }\r\n\r\n    FPS differential() {\r\n        int n =\
    \ deg();\r\n        FPS g(n);\r\n        for (int i = 0; i < n - 1; i++) {\r\n\
    \            g[i] = (*this)[i + 1] * (i + 1);\r\n        }\r\n        g[n - 1]\
    \ = 0;\r\n        return g;\r\n    }\r\n\r\n    FPS integral() {\r\n        int\
    \ n = deg();\r\n        FPS g(n + 1);\r\n        g[0] = 0;\r\n        for (int\
    \ i = 0; i < n; i++) {\r\n            g[i + 1] = (*this)[i] / (mint(i + 1));\r\
    \n        }\r\n        return g;\r\n    }\r\n\r\n    FPS log() {\r\n        assert((*this)[0].val()\
    \ == 1);\r\n        FPS g = (*this).differential() / (*this);\r\n        return\
    \ g.integral();\r\n    }\r\n\r\n    int deg() const {\r\n        return (*this).size();\r\
    \n    }\r\n};\r\n\r\n}  // namespace ebi"
  dependsOn:
  - convolution/convolution.hpp
  - utility/modint.hpp
  isVerificationFile: false
  path: math/FormalPowerSeries.hpp
  requiredBy: []
  timestamp: '2023-05-16 13:40:06+09:00'
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
