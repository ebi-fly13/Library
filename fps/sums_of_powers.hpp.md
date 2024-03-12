---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/fps.hpp
    title: Formal Power Series
  - icon: ':heavy_check_mark:'
    path: fps/product_of_fps.hpp
    title: $\prod_{i=0}^n f_i$
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1145.test.cpp
    title: test/yuki/yuki_1145.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/sums_of_powers.hpp\"\n\n#line 2 \"fps/fps.hpp\"\n\n\
    #include <algorithm>\n#include <cassert>\n#include <optional>\n#include <vector>\n\
    \n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#include <iostream>\n#include\
    \ <utility>\n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint = requires(T\
    \ a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n  \
    \  a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n};\n\ntemplate\
    \ <Modint mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long\
    \ long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <Modint mint>\n\
    std::ostream &operator<<(std::ostream &os, const mint &a) {\n    return os <<\
    \ a.val();\n}\n\n}  // namespace ebi\n#line 9 \"fps/fps.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <Modint mint,\n          std::vector<mint> (*convolution)(const\
    \ std::vector<mint> &,\n                                           const std::vector<mint>\
    \ &)>\nstruct FormalPowerSeries : std::vector<mint> {\n  private:\n    using std::vector<mint>::vector;\n\
    \    using std::vector<mint>::vector::operator=;\n    using FPS = FormalPowerSeries;\n\
    \n  public:\n    FormalPowerSeries(const std::vector<mint> &a) {\n        *this\
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
    \ f;\n    }\n};\n\n}  // namespace ebi\n#line 2 \"fps/product_of_fps.hpp\"\n\n\
    #include <deque>\n#line 5 \"fps/product_of_fps.hpp\"\n\n#line 7 \"fps/product_of_fps.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint,\n          std::vector<mint> (*convolution)(const\
    \ std::vector<mint> &,\n                                           const std::vector<mint>\
    \ &)>\nstd::vector<mint> product_of_fps(const std::vector<std::vector<mint>> &fs)\
    \ {\n    if (fs.empty()) return {1};\n    std::deque<std::vector<mint>> deque;\n\
    \    for (auto &f : fs) deque.push_back(f);\n    while (deque.size() > 1) {\n\
    \        auto f = deque.front();\n        deque.pop_front();\n        auto g =\
    \ deque.front();\n        deque.pop_front();\n        deque.push_back(convolution(f,\
    \ g));\n    }\n    return deque.front();\n}\n\n}  // namespace ebi\n#line 6 \"\
    fps/sums_of_powers.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint,\n      \
    \    std::vector<mint> (*convolution)(const std::vector<mint> &,\n           \
    \                                const std::vector<mint> &)>\nFormalPowerSeries<mint,\
    \ convolution> sums_of_powers(const std::vector<int> &a,\n                   \
    \                                 int d) {\n    using FPS = FormalPowerSeries<mint,\
    \ convolution>;\n    int n = a.size();\n    std::vector fs(n, std::vector<mint>(2,\
    \ 1));\n    for (int i = 0; i < n; i++) {\n        fs[i][1] = -a[i];\n    }\n\
    \    FPS g = product_of_fps<mint, convolution>(fs);\n    return (-g.log(d + 1).differential()\
    \ << 1) + n;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include \"../fps/fps.hpp\"\n#include \"../fps/product_of_fps.hpp\"\
    \n#include \"../modint/base.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint,\n\
    \          std::vector<mint> (*convolution)(const std::vector<mint> &,\n     \
    \                                      const std::vector<mint> &)>\nFormalPowerSeries<mint,\
    \ convolution> sums_of_powers(const std::vector<int> &a,\n                   \
    \                                 int d) {\n    using FPS = FormalPowerSeries<mint,\
    \ convolution>;\n    int n = a.size();\n    std::vector fs(n, std::vector<mint>(2,\
    \ 1));\n    for (int i = 0; i < n; i++) {\n        fs[i][1] = -a[i];\n    }\n\
    \    FPS g = product_of_fps<mint, convolution>(fs);\n    return (-g.log(d + 1).differential()\
    \ << 1) + n;\n}\n\n}  // namespace ebi"
  dependsOn:
  - fps/fps.hpp
  - modint/base.hpp
  - fps/product_of_fps.hpp
  isVerificationFile: false
  path: fps/sums_of_powers.hpp
  requiredBy: []
  timestamp: '2024-03-12 18:21:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki/yuki_1145.test.cpp
documentation_of: fps/sums_of_powers.hpp
layout: document
title: $\sum_i (\sum_n A_n^i) x^i$
---

## 説明

$A_1, \dots, A_N$ が与えられたとき、 $\sum_i (\sum_n A_n^i) x^i$ を $i = d$ まで列挙する。 $O(N(\log N)^2 + D\log D)$

求める形式的べき級数は

$$\sum_i (\sum_n A_n^i) x^i = \sum_n \frac{1}{1-A_nx}$$

である。定数項は $len(A)$ であるので、非定数項を求められればよい。

$$\sum_{i = 1}^{\infty} (\sum_n A_n^i) x^i = \sum_n A_nx \frac{1}{1-A_nx}$$

であるので、 $x$ で割った後に積分すると

$$\int \sum_n A_n \frac{1}{1-A_nx} dx = - \sum_n \log(1 - A_nx)$$

となる。ここで

$$- \sum_n \log(1 - A_nx) = - \log \prod_n (1-A_nx)$$

であるので

$$\sum_i (\sum_n A_n^i) x^i = len(A) + x(-\log \prod_n (1-A_nx))^{\prime}$$

となる。計算量は多項式の総積が $O(N(\log N)^2)$ 、 形式的べき級数の $\log$ が $O(D\log D)$ 、形式的べき級数の微分が $O(D)$ より $O(N(\log N)^2 + D\log D)$ となる。