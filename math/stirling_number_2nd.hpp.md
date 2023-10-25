---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/fps.hpp
    title: Formal Power Series
  - icon: ':question:'
    path: utility/bit_operator.hpp
    title: utility/bit_operator.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/Stirling_Number_of_the_Second_Kind.test.cpp
    title: test/math/Stirling_Number_of_the_Second_Kind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/stirling_number_2nd.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\n#line 2 \"fps/fps.hpp\"\n\n#include <algorithm>\n#line 5 \"fps/fps.hpp\"\
    \n#include <optional>\n#line 7 \"fps/fps.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class mint, std::vector<mint> (*convolution)(\n                          const\
    \ std::vector<mint> &, const std::vector<mint> &)>\nstruct FormalPowerSeries :\
    \ std::vector<mint> {\n  private:\n    using std::vector<mint>::vector;\n    using\
    \ std::vector<mint>::vector::operator=;\n    using FPS = FormalPowerSeries;\n\n\
    \  public:\n    FormalPowerSeries(const std::vector<mint> &a) {\n        *this\
    \ = a;\n    }\n\n    FPS operator+(const FPS &rhs) const noexcept {\n        return\
    \ FPS(*this) += rhs;\n    }\n    FPS operator-(const FPS &rhs) const noexcept\
    \ {\n        return FPS(*this) -= rhs;\n    }\n    FPS operator*(const FPS &rhs)\
    \ const noexcept {\n        return FPS(*this) *= rhs;\n    }\n    FPS operator/(const\
    \ FPS &rhs) const noexcept {\n        return FPS(*this) /= rhs;\n    }\n    FPS\
    \ operator%(const FPS &rhs) const noexcept {\n        return FPS(*this) %= rhs;\n\
    \    }\n\n    FPS operator+(const mint &rhs) const noexcept {\n        return\
    \ FPS(*this) += rhs;\n    }\n    FPS operator-(const mint &rhs) const noexcept\
    \ {\n        return FPS(*this) -= rhs;\n    }\n    FPS operator*(const mint &rhs)\
    \ const noexcept {\n        return FPS(*this) *= rhs;\n    }\n    FPS operator/(const\
    \ mint &rhs) const noexcept {\n        return FPS(*this) /= rhs;\n    }\n\n  \
    \  FPS &operator+=(const FPS &rhs) noexcept {\n        if (this->size() < rhs.size())\
    \ this->resize(rhs.size());\n        for (int i = 0; i < (int)rhs.size(); ++i)\
    \ {\n            (*this)[i] += rhs[i];\n        }\n        return *this;\n   \
    \ }\n\n    FPS &operator-=(const FPS &rhs) noexcept {\n        if (this->size()\
    \ < rhs.size()) this->resize(rhs.size());\n        for (int i = 0; i < (int)rhs.size();\
    \ ++i) {\n            (*this)[i] -= rhs[i];\n        }\n        return *this;\n\
    \    }\n\n    FPS &operator*=(const FPS &rhs) noexcept {\n        *this = convolution(*this,\
    \ rhs);\n        return *this;\n    }\n\n    FPS &operator/=(const FPS &rhs) noexcept\
    \ {\n        int n = deg() - 1;\n        int m = rhs.deg() - 1;\n        if (n\
    \ < m) {\n            *this = {};\n            return *this;\n        }\n    \
    \    *this = (*this).rev() * rhs.rev().inv(n - m + 1);\n        (*this).resize(n\
    \ - m + 1);\n        std::reverse((*this).begin(), (*this).end());\n        return\
    \ *this;\n    }\n\n    FPS &operator%=(const FPS &rhs) noexcept {\n        *this\
    \ -= *this / rhs * rhs;\n        shrink();\n        return *this;\n    }\n\n \
    \   FPS &operator+=(const mint &rhs) noexcept {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] += rhs;\n        return *this;\n    }\n\n    FPS &operator-=(const\
    \ mint &rhs) noexcept {\n        if (this->empty()) this->resize(1);\n       \
    \ (*this)[0] -= rhs;\n        return *this;\n    }\n\n    FPS &operator*=(const\
    \ mint &rhs) noexcept {\n        for (int i = 0; i < deg(); ++i) {\n         \
    \   (*this)[i] *= rhs;\n        }\n        return *this;\n    }\n    FPS &operator/=(const\
    \ mint &rhs) noexcept {\n        mint inv_rhs = rhs.inv();\n        for (int i\
    \ = 0; i < deg(); ++i) {\n            (*this)[i] *= inv_rhs;\n        }\n    \
    \    return *this;\n    }\n\n    FPS operator>>(int d) const {\n        if (deg()\
    \ <= d) return {};\n        FPS f = *this;\n        f.erase(f.begin(), f.begin()\
    \ + d);\n        return f;\n    }\n\n    FPS operator<<(int d) const {\n     \
    \   FPS f = *this;\n        f.insert(f.begin(), d, 0);\n        return f;\n  \
    \  }\n\n    FPS operator-() const {\n        FPS g(this->size());\n        for\
    \ (int i = 0; i < (int)this->size(); i++) g[i] = -(*this)[i];\n        return\
    \ g;\n    }\n\n    FPS pre(int sz) const {\n        return FPS(this->begin(),\
    \ this->begin() + std::min(deg(), sz));\n    }\n\n    FPS rev() const {\n    \
    \    auto f = *this;\n        std::reverse(f.begin(), f.end());\n        return\
    \ f;\n    }\n\n    FPS differential() const {\n        int n = deg();\n      \
    \  FPS g(std::max(0, n - 1));\n        for (int i = 0; i < n - 1; i++) {\n   \
    \         g[i] = (*this)[i + 1] * (i + 1);\n        }\n        return g;\n   \
    \ }\n\n    FPS integral() const {\n        int n = deg();\n        FPS g(n + 1);\n\
    \        g[0] = 0;\n        if (n > 0) g[1] = 1;\n        auto mod = mint::mod();\n\
    \        for (int i = 2; i <= n; i++) g[i] = (-g[mod % i]) * (mod / i);\n    \
    \    for (int i = 0; i < n; i++) g[i + 1] *= (*this)[i];\n        return g;\n\
    \    }\n\n    FPS inv(int d = -1) const {\n        int n = 1;\n        if (d <\
    \ 0) d = deg();\n        FPS g(n);\n        g[0] = (*this)[0].inv();\n       \
    \ while (n < d) {\n            n <<= 1;\n            g = (g * 2 - g * g * this->pre(n)).pre(n);\n\
    \        }\n        g.resize(d);\n        return g;\n    }\n\n    FPS log(int\
    \ d = -1) const {\n        assert((*this)[0].val() == 1);\n        if (d < 0)\
    \ d = deg();\n        return ((*this).differential() * (*this).inv(d)).pre(d -\
    \ 1).integral();\n    }\n\n    FPS exp(int d = -1) const {\n        assert((*this)[0].val()\
    \ == 0);\n        int n = 1;\n        if (d < 0) d = deg();\n        FPS g(n);\n\
    \        g[0] = 1;\n        while (n < d) {\n            n <<= 1;\n          \
    \  g = (g * (this->pre(n) - g.log(n) + 1)).pre(n);\n        }\n        g.resize(d);\n\
    \        return g;\n    }\n\n    FPS pow(int64_t k, int d = -1) const {\n    \
    \    const int n = deg();\n        if (d < 0) d = n;\n        if (k == 0) {\n\
    \            FPS f(d);\n            if (d > 0) f[0] = 1;\n            return f;\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            if ((*this)[i]\
    \ != 0) {\n                mint rev = (*this)[i].inv();\n                FPS f\
    \ = (((*this * rev) >> i).log(d) * k).exp(d);\n                f *= (*this)[i].pow(k);\n\
    \                f = (f << (i * k)).pre(d);\n                if (f.deg() < d)\
    \ f.resize(d);\n                return f;\n            }\n            if (i +\
    \ 1 >= (d + k - 1) / k) break;\n        }\n        return FPS(d);\n    }\n\n \
    \   int deg() const {\n        return (*this).size();\n    }\n\n    void shrink()\
    \ {\n        while ((!this->empty()) && this->back() == 0) this->pop_back();\n\
    \    }\n\n    int count_terms() const {\n        int c = 0;\n        for (int\
    \ i = 0; i < deg(); i++) {\n            if ((*this)[i] != 0) c++;\n        }\n\
    \        return c;\n    }\n\n    std::optional<FPS> sqrt(int d = -1) const;\n\n\
    \    static FPS exp_x(int n) {\n        FPS f(n);\n        mint fact = 1;\n  \
    \      for (int i = 1; i < n; i++) fact *= i;\n        f[n - 1] = fact.inv();\n\
    \        for (int i = n - 1; i >= 0; i--) f[i - 1] = f[i] * i;\n        return\
    \ f;\n    }\n};\n\n}  // namespace ebi\n#line 2 \"utility/bit_operator.hpp\"\n\
    \n#include <bit>\n#include <cstdint>\n\nnamespace ebi {\n\nint bit_reverse(int\
    \ n, int bit_size) {\n    int rev_n = 0;\n    for (int i = 0; i < bit_size; i++)\
    \ {\n        rev_n |= ((n >> i) & 1) << (bit_size - i - 1);\n    }\n    return\
    \ rev_n;\n}\n\nint msb(int x) {\n    return (x == 0) ? -1 : 31 - std::countl_zero(std::uint32_t(x));\n\
    }\n\n}  // namespace ebi\n#line 8 \"math/stirling_number_2nd.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <class mint, std::vector<mint> (*convolution)(\n         \
    \                 const std::vector<mint> &, const std::vector<mint> &)>\nFormalPowerSeries<mint,\
    \ convolution> stirling_number_2nd(int n) {\n    using FPS = FormalPowerSeries<mint,\
    \ convolution>;\n    assert(n >= 0);\n    FPS f(n + 1), g(n + 1);\n    std::vector<mint>\
    \ fact(n + 1, 1);\n    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;\n\
    \    std::vector<mint> inv_fact(n + 1);\n    inv_fact[n] = fact[n].inv();\n  \
    \  for (int i = n; i > 0; i--) {\n        inv_fact[i - 1] = inv_fact[i] * i;\n\
    \    }\n    for (int i = 0; i <= n; i++) {\n        f[i] = mint(i).pow(n) * inv_fact[i];\n\
    \        g[i] = (i & 1) ? -inv_fact[i] : inv_fact[i];\n    }\n    return (f *\
    \ g).pre(n + 1);\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../fps/fps.hpp\"\
    \n#include \"../utility/bit_operator.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ mint, std::vector<mint> (*convolution)(\n                          const std::vector<mint>\
    \ &, const std::vector<mint> &)>\nFormalPowerSeries<mint, convolution> stirling_number_2nd(int\
    \ n) {\n    using FPS = FormalPowerSeries<mint, convolution>;\n    assert(n >=\
    \ 0);\n    FPS f(n + 1), g(n + 1);\n    std::vector<mint> fact(n + 1, 1);\n  \
    \  for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;\n    std::vector<mint>\
    \ inv_fact(n + 1);\n    inv_fact[n] = fact[n].inv();\n    for (int i = n; i >\
    \ 0; i--) {\n        inv_fact[i - 1] = inv_fact[i] * i;\n    }\n    for (int i\
    \ = 0; i <= n; i++) {\n        f[i] = mint(i).pow(n) * inv_fact[i];\n        g[i]\
    \ = (i & 1) ? -inv_fact[i] : inv_fact[i];\n    }\n    return (f * g).pre(n + 1);\n\
    }\n\n}  // namespace ebi"
  dependsOn:
  - fps/fps.hpp
  - utility/bit_operator.hpp
  isVerificationFile: false
  path: math/stirling_number_2nd.hpp
  requiredBy: []
  timestamp: '2023-10-26 02:17:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/Stirling_Number_of_the_Second_Kind.test.cpp
documentation_of: math/stirling_number_2nd.hpp
layout: document
title: Stirling Numbers of the Second Kind
---

## 説明

第 $2$ 種スターリング数 $S(N, K)$ を $k = 0, \dots, N$ に対して求める。 $S(N, K)$ は以下のように表すことができるため、畳み込みを用いて $O(N\log N)$ で求められる。

$$
S(N, K) = \frac{1}{K!} \sum_{i = 0}^K (-1)^{K-i} \binom{k} i i^N \\
S(N, K) = \sum_{i = 0}^K \frac{(-1)^{K-i}}{(K-i)!} \frac{i^n}{i!}
$$

$S(N, K)$ は、 $N$ 個の区別できる要素を $K$ 個の空でない部分集合に分ける場合の数である。