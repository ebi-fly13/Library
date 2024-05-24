---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/composition_of_fps.hpp
    title: $f(g(x))$
  - icon: ':heavy_check_mark:'
    path: fps/fps.hpp
    title: Formal Power Series
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/compositional_inverse_of_fps_old.hpp\"\n\n#include <cassert>\n\
    \n#line 2 \"fps/composition_of_fps.hpp\"\n\n#line 4 \"fps/composition_of_fps.hpp\"\
    \n#include <vector>\n\n#line 2 \"fps/fps.hpp\"\n\n#include <algorithm>\n#line\
    \ 5 \"fps/fps.hpp\"\n#include <optional>\n#line 7 \"fps/fps.hpp\"\n\n#line 2 \"\
    modint/base.hpp\"\n\n#include <concepts>\n#include <iostream>\n#include <utility>\n\
    \nnamespace ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n\
    \    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n\
    \    a.pow(std::declval<long long>());\n    T::mod();\n};\n\ntemplate <Modint\
    \ mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long long x;\n\
    \    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <Modint mint>\nstd::ostream\
    \ &operator<<(std::ostream &os, const mint &a) {\n    return os << a.val();\n\
    }\n\n}  // namespace ebi\n#line 9 \"fps/fps.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <Modint mint> struct FormalPowerSeries : std::vector<mint> {\n  private:\n \
    \   using std::vector<mint>::vector;\n    using std::vector<mint>::vector::operator=;\n\
    \    using FPS = FormalPowerSeries;\n\n  public:\n    FormalPowerSeries(const\
    \ std::vector<mint> &a) {\n        *this = a;\n    }\n\n    FPS operator+(const\
    \ FPS &rhs) const noexcept {\n        return FPS(*this) += rhs;\n    }\n    FPS\
    \ operator-(const FPS &rhs) const noexcept {\n        return FPS(*this) -= rhs;\n\
    \    }\n    FPS operator*(const FPS &rhs) const noexcept {\n        return FPS(*this)\
    \ *= rhs;\n    }\n    FPS operator/(const FPS &rhs) const noexcept {\n       \
    \ return FPS(*this) /= rhs;\n    }\n    FPS operator%(const FPS &rhs) const noexcept\
    \ {\n        return FPS(*this) %= rhs;\n    }\n\n    FPS operator+(const mint\
    \ &rhs) const noexcept {\n        return FPS(*this) += rhs;\n    }\n    FPS operator-(const\
    \ mint &rhs) const noexcept {\n        return FPS(*this) -= rhs;\n    }\n    FPS\
    \ operator*(const mint &rhs) const noexcept {\n        return FPS(*this) *= rhs;\n\
    \    }\n    FPS operator/(const mint &rhs) const noexcept {\n        return FPS(*this)\
    \ /= rhs;\n    }\n\n    FPS &operator+=(const FPS &rhs) noexcept {\n        if\
    \ (this->size() < rhs.size()) this->resize(rhs.size());\n        for (int i =\
    \ 0; i < (int)rhs.size(); ++i) {\n            (*this)[i] += rhs[i];\n        }\n\
    \        return *this;\n    }\n\n    FPS &operator-=(const FPS &rhs) noexcept\
    \ {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n      \
    \  for (int i = 0; i < (int)rhs.size(); ++i) {\n            (*this)[i] -= rhs[i];\n\
    \        }\n        return *this;\n    }\n\n    FPS &operator*=(const FPS &);\n\
    \n    FPS &operator/=(const FPS &rhs) noexcept {\n        int n = deg() - 1;\n\
    \        int m = rhs.deg() - 1;\n        if (n < m) {\n            *this = {};\n\
    \            return *this;\n        }\n        *this = (*this).rev() * rhs.rev().inv(n\
    \ - m + 1);\n        (*this).resize(n - m + 1);\n        std::reverse((*this).begin(),\
    \ (*this).end());\n        return *this;\n    }\n\n    FPS &operator%=(const FPS\
    \ &rhs) noexcept {\n        *this -= *this / rhs * rhs;\n        shrink();\n \
    \       return *this;\n    }\n\n    FPS &operator+=(const mint &rhs) noexcept\
    \ {\n        if (this->empty()) this->resize(1);\n        (*this)[0] += rhs;\n\
    \        return *this;\n    }\n\n    FPS &operator-=(const mint &rhs) noexcept\
    \ {\n        if (this->empty()) this->resize(1);\n        (*this)[0] -= rhs;\n\
    \        return *this;\n    }\n\n    FPS &operator*=(const mint &rhs) noexcept\
    \ {\n        for (int i = 0; i < deg(); ++i) {\n            (*this)[i] *= rhs;\n\
    \        }\n        return *this;\n    }\n    FPS &operator/=(const mint &rhs)\
    \ noexcept {\n        mint inv_rhs = rhs.inv();\n        for (int i = 0; i < deg();\
    \ ++i) {\n            (*this)[i] *= inv_rhs;\n        }\n        return *this;\n\
    \    }\n\n    FPS operator>>(int d) const {\n        if (deg() <= d) return {};\n\
    \        FPS f = *this;\n        f.erase(f.begin(), f.begin() + d);\n        return\
    \ f;\n    }\n\n    FPS operator<<(int d) const {\n        FPS f = *this;\n   \
    \     f.insert(f.begin(), d, 0);\n        return f;\n    }\n\n    FPS operator-()\
    \ const {\n        FPS g(this->size());\n        for (int i = 0; i < (int)this->size();\
    \ i++) g[i] = -(*this)[i];\n        return g;\n    }\n\n    FPS pre(int sz) const\
    \ {\n        return FPS(this->begin(), this->begin() + std::min(deg(), sz));\n\
    \    }\n\n    FPS rev() const {\n        auto f = *this;\n        std::reverse(f.begin(),\
    \ f.end());\n        return f;\n    }\n\n    FPS differential() const {\n    \
    \    int n = deg();\n        FPS g(std::max(0, n - 1));\n        for (int i =\
    \ 0; i < n - 1; i++) {\n            g[i] = (*this)[i + 1] * (i + 1);\n       \
    \ }\n        return g;\n    }\n\n    FPS integral() const {\n        int n = deg();\n\
    \        FPS g(n + 1);\n        g[0] = 0;\n        if (n > 0) g[1] = 1;\n    \
    \    auto mod = mint::mod();\n        for (int i = 2; i <= n; i++) g[i] = (-g[mod\
    \ % i]) * (mod / i);\n        for (int i = 0; i < n; i++) g[i + 1] *= (*this)[i];\n\
    \        return g;\n    }\n\n    FPS inv(int d = -1) const {\n        int n =\
    \ 1;\n        if (d < 0) d = deg();\n        FPS g(n);\n        g[0] = (*this)[0].inv();\n\
    \        while (n < d) {\n            n <<= 1;\n            g = (g * 2 - g * g\
    \ * this->pre(n)).pre(n);\n        }\n        g.resize(d);\n        return g;\n\
    \    }\n\n    FPS log(int d = -1) const {\n        assert((*this)[0].val() ==\
    \ 1);\n        if (d < 0) d = deg();\n        return ((*this).differential() *\
    \ (*this).inv(d)).pre(d - 1).integral();\n    }\n\n    FPS exp(int d = -1) const\
    \ {\n        assert((*this)[0].val() == 0);\n        int n = 1;\n        if (d\
    \ < 0) d = deg();\n        FPS g(n);\n        g[0] = 1;\n        while (n < d)\
    \ {\n            n <<= 1;\n            g = (g * (this->pre(n) - g.log(n) + 1)).pre(n);\n\
    \        }\n        g.resize(d);\n        return g;\n    }\n\n    FPS pow(long\
    \ long k, int d = -1) const {\n        assert(k >= 0);\n        int n = deg();\n\
    \        if (d < 0) d = n;\n        if (k == 0) {\n            FPS f(d);\n   \
    \         if (d > 0) f[0] = 1;\n            return f;\n        }\n        int\
    \ low = d;\n        for (int i = n - 1; i >= 0; i--)\n            if ((*this)[i]\
    \ != 0) low = i;\n        if (low >= (d + k - 1) / k) return FPS(d, 0);\n    \
    \    int offset = k * low;\n        mint c = (*this)[low];\n        FPS g(d -\
    \ offset);\n        for (int i = 0; i < std::min(n - low, d - offset); i++) {\n\
    \            g[i] = (*this)[i + low];\n        }\n        g /= c;\n        g =\
    \ g.pow_1(k);\n        return (g << offset) * c.pow(k);\n    }\n\n    FPS pow_1(mint\
    \ k, int d = -1) const {\n        assert((*this)[0] == 1);\n        return ((*this).log(d)\
    \ * k).exp(d);\n    }\n\n    FPS pow_newton(long long k, int d = -1) const {\n\
    \        assert(k >= 0);\n        const int n = deg();\n        if (d < 0) d =\
    \ n;\n        if (k == 0) {\n            FPS f(d);\n            if (d > 0) f[0]\
    \ = 1;\n            return f;\n        }\n        for (int i = 0; i < n; i++)\
    \ {\n            if ((*this)[i] != 0) {\n                mint rev = (*this)[i].inv();\n\
    \                FPS f = (((*this * rev) >> i).log(d) * k).exp(d);\n         \
    \       f *= (*this)[i].pow(k);\n                f = (f << (i * k)).pre(d);\n\
    \                if (f.deg() < d) f.resize(d);\n                return f;\n  \
    \          }\n            if (i + 1 >= (d + k - 1) / k) break;\n        }\n  \
    \      return FPS(d);\n    }\n\n    int deg() const {\n        return (*this).size();\n\
    \    }\n\n    void shrink() {\n        while ((!this->empty()) && this->back()\
    \ == 0) this->pop_back();\n    }\n\n    int count_terms() const {\n        int\
    \ c = 0;\n        for (int i = 0; i < deg(); i++) {\n            if ((*this)[i]\
    \ != 0) c++;\n        }\n        return c;\n    }\n\n    std::optional<FPS> sqrt(int\
    \ d = -1) const;\n\n    static FPS exp_x(int n) {\n        FPS f(n);\n       \
    \ mint fact = 1;\n        for (int i = 1; i < n; i++) fact *= i;\n        f[n\
    \ - 1] = fact.inv();\n        for (int i = n - 1; i >= 0; i--) f[i - 1] = f[i]\
    \ * i;\n        return f;\n    }\n};\n\n}  // namespace ebi\n#line 8 \"fps/composition_of_fps.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint>\nFormalPowerSeries<mint> composition_of_fps(const\
    \ FormalPowerSeries<mint> &f,\n                                           const\
    \ FormalPowerSeries<mint> &g) {\n    using FPS = FormalPowerSeries<mint>;\n  \
    \  // assert(f.deg() == g.deg());\n    int n = f.deg();\n    int k = 1;\n    while\
    \ (k * k < n) k++;\n    std::vector<FPS> baby(k + 1);\n    baby[0] = FPS{1};\n\
    \    baby[1] = g;\n    for (int i = 2; i < k + 1; i++) {\n        baby[i] = (baby[i\
    \ - 1] * g).pre(n);\n    }\n    std::vector<FPS> giant(k + 1);\n    giant[0] =\
    \ FPS{1};\n    giant[1] = baby[k];\n    for (int i = 2; i < k + 1; i++) {\n  \
    \      giant[i] = (giant[i - 1] * giant[1]).pre(n);\n    }\n    FPS h(n);\n  \
    \  for (int i = 0; i < k + 1; i++) {\n        FPS a(n);\n        for (int j =\
    \ 0; j < k; j++) {\n            if (k * i + j < n) {\n                mint coef\
    \ = f[k * i + j];\n                a += baby[j] * coef;\n            } else\n\
    \                break;\n        }\n        h += (giant[i] * a).pre(n);\n    }\n\
    \    return h;\n}\n\n}  // namespace ebi\n#line 8 \"fps/compositional_inverse_of_fps_old.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint>\nFormalPowerSeries<mint> compositional_inverse_of_fps(FormalPowerSeries<mint>\
    \ f,\n                                                     int d = -1) {\n   \
    \ using FPS = FormalPowerSeries<mint>;\n    if (d < 0) d = f.deg();\n    assert((int)f.size()\
    \ >= 2 && f[0] == 0 && f[1] != 0);\n    FPS df = f.differential();\n    FPS g\
    \ = {0, f[1].inv()};\n    for (int n = 2; n < d; n <<= 1) {\n        g.resize(2\
    \ * n);\n        if (f.deg() < 2 * n) f.resize(2 * n);\n        if (df.deg() <\
    \ 2 * n) df.resize(2 * n);\n        FPS fg = composition_of_fps(f.pre(2 * n),\
    \ g);\n        FPS fdg = composition_of_fps(df.pre(2 * n), g);\n        g -= ((fg\
    \ - FPS{0, 1}) * fdg.inv(2 * n)).pre(2 * n);\n    }\n    g.resize(d);\n    return\
    \ g;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n\n#include \"../fps/composition_of_fps.hpp\"\
    \n#include \"../fps/fps.hpp\"\n#include \"../modint/base.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <Modint mint>\nFormalPowerSeries<mint> compositional_inverse_of_fps(FormalPowerSeries<mint>\
    \ f,\n                                                     int d = -1) {\n   \
    \ using FPS = FormalPowerSeries<mint>;\n    if (d < 0) d = f.deg();\n    assert((int)f.size()\
    \ >= 2 && f[0] == 0 && f[1] != 0);\n    FPS df = f.differential();\n    FPS g\
    \ = {0, f[1].inv()};\n    for (int n = 2; n < d; n <<= 1) {\n        g.resize(2\
    \ * n);\n        if (f.deg() < 2 * n) f.resize(2 * n);\n        if (df.deg() <\
    \ 2 * n) df.resize(2 * n);\n        FPS fg = composition_of_fps(f.pre(2 * n),\
    \ g);\n        FPS fdg = composition_of_fps(df.pre(2 * n), g);\n        g -= ((fg\
    \ - FPS{0, 1}) * fdg.inv(2 * n)).pre(2 * n);\n    }\n    g.resize(d);\n    return\
    \ g;\n}\n\n}  // namespace ebi"
  dependsOn:
  - fps/composition_of_fps.hpp
  - fps/fps.hpp
  - modint/base.hpp
  isVerificationFile: false
  path: fps/compositional_inverse_of_fps_old.hpp
  requiredBy: []
  timestamp: '2024-05-24 14:32:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
documentation_of: fps/compositional_inverse_of_fps_old.hpp
layout: document
title: "$f(x)$ \u306E\u9006\u95A2\u6570 ( $O(N^2)$ )"
---

## 説明

形式的べき級数 $f$ について、その逆関数を求める。ニュートン法を用いると、形式的べき級数の合成がボトルネックとなり $O(N^2)$ となる。

$$
g_{2n} = g_{n} - \frac{f(g_{n}) - x}{f^{\prime}(g_{n})} \mod x^{2n}
$$