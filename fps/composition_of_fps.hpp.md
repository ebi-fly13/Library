---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/fps.hpp
    title: Formal Power Series
  _extendedRequiredBy:
  - icon: ':x:'
    path: fps/compositional_inverse_of_fps.hpp
    title: "$f(x)$ \u306E\u9006\u95A2\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
  - icon: ':x:'
    path: test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/composition_of_fps.hpp\"\n\n#include <cassert>\n#include\
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
    \ f;\n    }\n};\n\n}  // namespace ebi\n#line 7 \"fps/composition_of_fps.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class mint, std::vector<mint> (*convolution)(\n\
    \                          const std::vector<mint> &, const std::vector<mint>\
    \ &)>\nFormalPowerSeries<mint, convolution> composition_of_fps(\n    const FormalPowerSeries<mint,\
    \ convolution> &f,\n    const FormalPowerSeries<mint, convolution> &g) {\n   \
    \ using FPS = FormalPowerSeries<mint, convolution>;\n    // assert(f.deg() ==\
    \ g.deg());\n    int n = f.deg();\n    int k = 1;\n    while (k * k < n) k++;\n\
    \    std::vector<FPS> baby(k + 1);\n    baby[0] = FPS{1};\n    baby[1] = g;\n\
    \    for (int i = 2; i < k + 1; i++) {\n        baby[i] = (baby[i - 1] * g).pre(n);\n\
    \    }\n    std::vector<FPS> giant(k + 1);\n    giant[0] = FPS{1};\n    giant[1]\
    \ = baby[k];\n    for (int i = 2; i < k + 1; i++) {\n        giant[i] = (giant[i\
    \ - 1] * giant[1]).pre(n);\n    }\n    FPS h(n);\n    for (int i = 0; i < k +\
    \ 1; i++) {\n        FPS a(n);\n        for (int j = 0; j < k; j++) {\n      \
    \      if (k * i + j < n) {\n                mint coef = f[k * i + j];\n     \
    \           a += baby[j] * coef;\n            } else\n                break;\n\
    \        }\n        h += (giant[i] * a).pre(n);\n    }\n    return h;\n}\n\n}\
    \  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../fps/fps.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class mint, std::vector<mint> (*convolution)(\n\
    \                          const std::vector<mint> &, const std::vector<mint>\
    \ &)>\nFormalPowerSeries<mint, convolution> composition_of_fps(\n    const FormalPowerSeries<mint,\
    \ convolution> &f,\n    const FormalPowerSeries<mint, convolution> &g) {\n   \
    \ using FPS = FormalPowerSeries<mint, convolution>;\n    // assert(f.deg() ==\
    \ g.deg());\n    int n = f.deg();\n    int k = 1;\n    while (k * k < n) k++;\n\
    \    std::vector<FPS> baby(k + 1);\n    baby[0] = FPS{1};\n    baby[1] = g;\n\
    \    for (int i = 2; i < k + 1; i++) {\n        baby[i] = (baby[i - 1] * g).pre(n);\n\
    \    }\n    std::vector<FPS> giant(k + 1);\n    giant[0] = FPS{1};\n    giant[1]\
    \ = baby[k];\n    for (int i = 2; i < k + 1; i++) {\n        giant[i] = (giant[i\
    \ - 1] * giant[1]).pre(n);\n    }\n    FPS h(n);\n    for (int i = 0; i < k +\
    \ 1; i++) {\n        FPS a(n);\n        for (int j = 0; j < k; j++) {\n      \
    \      if (k * i + j < n) {\n                mint coef = f[k * i + j];\n     \
    \           a += baby[j] * coef;\n            } else\n                break;\n\
    \        }\n        h += (giant[i] * a).pre(n);\n    }\n    return h;\n}\n\n}\
    \  // namespace ebi"
  dependsOn:
  - fps/fps.hpp
  isVerificationFile: false
  path: fps/composition_of_fps.hpp
  requiredBy:
  - fps/compositional_inverse_of_fps.hpp
  timestamp: '2023-08-28 17:31:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
  - test/polynomial/Composition_of_Formal_Power_Series.test.cpp
documentation_of: fps/composition_of_fps.hpp
layout: document
title: $f(g(x))$
---

## 説明

形式的べき級数 $f$, $g$ について、その合成 $f(g(x))$ の先頭 $N$ 項を求める。Baby-step Giant-stepを用いることで $O(N^2)$ で計算する。