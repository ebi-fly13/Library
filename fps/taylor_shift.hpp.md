---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/fps.hpp
    title: Formal Power Series
  - icon: ':heavy_check_mark:'
    path: math/binomial.hpp
    title: Binomial Coefficient
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/stirling_number_1st.hpp
    title: Stirling Numbers of the First Kind
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Stirling_Number_of_the_First_Kind.test.cpp
    title: test/math/Stirling_Number_of_the_First_Kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Polynomial_Taylor_Shift.test.cpp
    title: test/polynomial/Polynomial_Taylor_Shift.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/taylor_shift.hpp\"\n\n#line 2 \"fps/fps.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <optional>\n#include <vector>\n\n\
    #line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#include <iostream>\n#include\
    \ <utility>\n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint = requires(T\
    \ a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n  \
    \  a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n};\n\ntemplate\
    \ <Modint mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long\
    \ long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <Modint mint>\n\
    std::ostream &operator<<(std::ostream &os, const mint &a) {\n    return os <<\
    \ a.val();\n}\n\n}  // namespace ebi\n#line 9 \"fps/fps.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <Modint mint> struct FormalPowerSeries : std::vector<mint> {\n\
    \  private:\n    using std::vector<mint>::vector;\n    using std::vector<mint>::vector::operator=;\n\
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
    \ * i;\n        return f;\n    }\n\n    void fft();\n    void ifft();\n};\n\n\
    }  // namespace ebi\n#line 2 \"math/binomial.hpp\"\n\n#include <bit>\n#line 5\
    \ \"math/binomial.hpp\"\n#include <cstdint>\n#line 7 \"math/binomial.hpp\"\n#include\
    \ <ranges>\n#line 9 \"math/binomial.hpp\"\n\n#line 11 \"math/binomial.hpp\"\n\n\
    namespace ebi {\n\ntemplate <Modint mint> struct Binomial {\n  private:\n    static\
    \ void extend(int len = -1) {\n        int sz = (int)fact.size();\n        if\
    \ (len < 0)\n            len = 2 * sz;\n        else if (len <= sz)\n        \
    \    return;\n        else\n            len = std::max(2 * sz, (int)std::bit_ceil(std::uint32_t(len)));\n\
    \        len = std::min(len, mint::mod());\n        assert(sz <= len);\n     \
    \   fact.resize(len);\n        inv_fact.resize(len);\n        for (int i : std::views::iota(sz,\
    \ len)) {\n            fact[i] = fact[i - 1] * i;\n        }\n        inv_fact[len\
    \ - 1] = fact[len - 1].inv();\n        for (int i : std::views::iota(sz, len)\
    \ | std::views::reverse) {\n            inv_fact[i - 1] = inv_fact[i] * i;\n \
    \       }\n    }\n\n  public:\n    Binomial() = default;\n\n    Binomial(int n)\
    \ {\n        extend(n + 1);\n    }\n\n    static mint f(int n) {\n        if (n\
    \ >= (int)fact.size()) [[unlikely]] {\n            extend(n + 1);\n        }\n\
    \        return fact[n];\n    }\n\n    static mint inv_f(int n) {\n        if\
    \ (n >= (int)fact.size()) [[unlikely]] {\n            extend(n + 1);\n       \
    \ }\n        return inv_fact[n];\n    }\n\n    static mint c(int n, int r) {\n\
    \        if (r < 0 || n < r) return 0;\n        return f(n) * inv_f(r) * inv_f(n\
    \ - r);\n    }\n\n    static mint neg_c(int k, int d) {\n        assert(d > 0);\n\
    \        return c(k + d - 1, d - 1);\n    }\n\n    static mint p(int n, int r)\
    \ {\n        if (r < 0 || n < r) return 0;\n        return f(n) * inv_f(n - r);\n\
    \    }\n\n    static mint inv(int n) {\n        return inv_f(n) * f(n - 1);\n\
    \    }\n\n    static void reserve(int n) {\n        extend(n + 1);\n    }\n\n\
    \  private:\n    static std::vector<mint> fact, inv_fact;\n};\n\ntemplate <Modint\
    \ mint>\nstd::vector<mint> Binomial<mint>::fact = std::vector<mint>(2, 1);\n\n\
    template <Modint mint>\nstd::vector<mint> Binomial<mint>::inv_fact = std::vector<mint>(2,\
    \ 1);\n\n}  // namespace ebi\n#line 6 \"fps/taylor_shift.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <Modint mint>\nFormalPowerSeries<mint> taylor_shift(FormalPowerSeries<mint>\
    \ f, mint a) {\n    int d = f.deg();\n    Binomial<mint>::reserve(d);\n    for\
    \ (int i = 0; i < d; i++) f[i] *= Binomial<mint>::f(i);\n    std::reverse(f.begin(),\
    \ f.end());\n    FormalPowerSeries<mint> g(d, 1);\n    mint pow_a = a;\n    for\
    \ (int i = 1; i < d; i++) {\n        g[i] = pow_a * Binomial<mint>::inv_f(i);\n\
    \        pow_a *= a;\n    }\n    f = (f * g).pre(d);\n    std::reverse(f.begin(),\
    \ f.end());\n    for (int i = 0; i < d; i++) f[i] *= Binomial<mint>::inv_f(i);\n\
    \    return f;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include \"../fps/fps.hpp\"\n#include \"../math/binomial.hpp\"\
    \n#include \"../modint/base.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint>\n\
    FormalPowerSeries<mint> taylor_shift(FormalPowerSeries<mint> f, mint a) {\n  \
    \  int d = f.deg();\n    Binomial<mint>::reserve(d);\n    for (int i = 0; i <\
    \ d; i++) f[i] *= Binomial<mint>::f(i);\n    std::reverse(f.begin(), f.end());\n\
    \    FormalPowerSeries<mint> g(d, 1);\n    mint pow_a = a;\n    for (int i = 1;\
    \ i < d; i++) {\n        g[i] = pow_a * Binomial<mint>::inv_f(i);\n        pow_a\
    \ *= a;\n    }\n    f = (f * g).pre(d);\n    std::reverse(f.begin(), f.end());\n\
    \    for (int i = 0; i < d; i++) f[i] *= Binomial<mint>::inv_f(i);\n    return\
    \ f;\n}\n\n}  // namespace ebi"
  dependsOn:
  - fps/fps.hpp
  - modint/base.hpp
  - math/binomial.hpp
  isVerificationFile: false
  path: fps/taylor_shift.hpp
  requiredBy:
  - math/stirling_number_1st.hpp
  timestamp: '2024-05-24 14:53:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Stirling_Number_of_the_First_Kind.test.cpp
  - test/polynomial/Polynomial_Taylor_Shift.test.cpp
documentation_of: fps/taylor_shift.hpp
layout: document
title: $f(x + c)$
---

## 説明

形式的べき級数 $f(x)$ に対して、 $f(x + c)$ を求める。
$O(N \log N)$