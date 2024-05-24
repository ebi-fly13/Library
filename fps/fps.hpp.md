---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/composition_of_fps.hpp
    title: $f(g(x))$
  - icon: ':heavy_check_mark:'
    path: fps/compositional_inverse_of_fps.hpp
    title: "$f(x)$ \u306E\u9006\u95A2\u6570 ( $O(N\\log^2{N})$ )"
  - icon: ':heavy_check_mark:'
    path: fps/compositional_inverse_of_fps_old.hpp
    title: "$f(x)$ \u306E\u9006\u95A2\u6570 ( $O(N^2)$ )"
  - icon: ':heavy_check_mark:'
    path: fps/fps_sqrt.hpp
    title: $\sqrt{f}$
  - icon: ':heavy_check_mark:'
    path: fps/multipoint_evaluation.hpp
    title: Multipoint Evaluation
  - icon: ':heavy_check_mark:'
    path: fps/ntt_friendly_fps.hpp
    title: fps/ntt_friendly_fps.hpp
  - icon: ':heavy_check_mark:'
    path: fps/polynomial_interpolation.hpp
    title: Polynomial Interpolation
  - icon: ':heavy_check_mark:'
    path: fps/power_projection_of_fps.hpp
    title: fps/power_projection_of_fps.hpp
  - icon: ':heavy_check_mark:'
    path: fps/product_of_fps.hpp
    title: $\prod f_i$
  - icon: ':heavy_check_mark:'
    path: fps/product_of_one_minus_xn.hpp
    title: $\prod (1 - x^{a_i}) \mod x^d$
  - icon: ':heavy_check_mark:'
    path: fps/product_of_one_plus_xn.hpp
    title: $\prod (1 + x^{a_i}) \mod x^d$
  - icon: ':heavy_check_mark:'
    path: fps/sum_of_rational_fps.hpp
    title: $\sum \frac{f_i}{g_i}$
  - icon: ':heavy_check_mark:'
    path: fps/taylor_shift.hpp
    title: $f(x + c)$
  - icon: ':heavy_check_mark:'
    path: math/bernoulli_number.hpp
    title: Bernoulli Number
  - icon: ':heavy_check_mark:'
    path: math/partition_function.hpp
    title: Partition Function
  - icon: ':heavy_check_mark:'
    path: math/stirling_number_1st.hpp
    title: Stirling Numbers of the First Kind
  - icon: ':heavy_check_mark:'
    path: math/stirling_number_2nd.hpp
    title: Stirling Numbers of the Second Kind
  - icon: ':heavy_check_mark:'
    path: math/sums_of_powers.hpp
    title: "$\\sum_n A_n^i$ \u306E $i = 0, 1,\\dots, k$ \u306E\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: math/sums_of_powers_iota.hpp
    title: "$\\sum_{i = 0}^{n-1} i^k$ \u306E $k$ \u306B\u95A2\u3059\u308B\u5217\u6319"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Berunoulli_Number.test.cpp
    title: test/math/Berunoulli_Number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Partition_Function_FPS.test.cpp
    title: test/math/Partition_Function_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Partition_Function_Pentagonal.test.cpp
    title: test/math/Partition_Function_Pentagonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Sharp_P_Subset_Sum.test.cpp
    title: test/math/Sharp_P_Subset_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Stirling_Number_of_the_First_Kind.test.cpp
    title: test/math/Stirling_Number_of_the_First_Kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Stirling_Number_of_the_Second_Kind.test.cpp
    title: test/math/Stirling_Number_of_the_Second_Kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Powers_Iota.test.cpp
    title: test/math/Sum_of_Powers_Iota.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Compositional_Inverse_of_Formal_Power_Series_Large.test.cpp
    title: test/polynomial/Compositional_Inverse_of_Formal_Power_Series_Large.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Division_of_Polynomials.test.cpp
    title: test/polynomial/Division_of_Polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Exp_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Exp_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Inv_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Inv_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Log_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Log_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Multipoint_Evaluation.test.cpp
    title: test/polynomial/Multipoint_Evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Polynomial_Interpolation.test.cpp
    title: test/polynomial/Polynomial_Interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Polynomial_Taylor_Shift.test.cpp
    title: test/polynomial/Polynomial_Taylor_Shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Pow_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Pow_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Product_of_Polynomial_Sequence.test.cpp
    title: test/polynomial/Product_of_Polynomial_Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1145.test.cpp
    title: test/yuki/yuki_1145.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1302.test.cpp
    title: test/yuki/yuki_1302.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1857.test.cpp
    title: test/yuki/yuki_1857.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/fps.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <optional>\n#include <vector>\n\n#line 2 \"modint/base.hpp\"\n\n#include\
    \ <concepts>\n#include <iostream>\n#include <utility>\n\nnamespace ebi {\n\ntemplate\
    \ <class T>\nconcept Modint = requires(T a, T b) {\n    a + b;\n    a - b;\n \
    \   a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 9 \"\
    fps/fps.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint> struct FormalPowerSeries\
    \ : std::vector<mint> {\n  private:\n    using std::vector<mint>::vector;\n  \
    \  using std::vector<mint>::vector::operator=;\n    using FPS = FormalPowerSeries;\n\
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
    \    }\n\n    FPS &operator*=(const FPS &);\n\n    FPS &operator/=(const FPS &rhs)\
    \ noexcept {\n        int n = deg() - 1;\n        int m = rhs.deg() - 1;\n   \
    \     if (n < m) {\n            *this = {};\n            return *this;\n     \
    \   }\n        *this = (*this).rev() * rhs.rev().inv(n - m + 1);\n        (*this).resize(n\
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
    \        return g;\n    }\n\n    FPS pow(long long k, int d = -1) const {\n  \
    \      assert(k >= 0);\n        int n = deg();\n        if (d < 0) d = n;\n  \
    \      if (k == 0) {\n            FPS f(d);\n            if (d > 0) f[0] = 1;\n\
    \            return f;\n        }\n        int low = d;\n        for (int i =\
    \ n - 1; i >= 0; i--)\n            if ((*this)[i] != 0) low = i;\n        if (low\
    \ >= (d + k - 1) / k) return FPS(d, 0);\n        int offset = k * low;\n     \
    \   mint c = (*this)[low];\n        FPS g(d - offset);\n        for (int i = 0;\
    \ i < std::min(n - low, d - offset); i++) {\n            g[i] = (*this)[i + low];\n\
    \        }\n        g /= c;\n        g = g.pow_1(k);\n        return (g << offset)\
    \ * c.pow(k);\n    }\n\n    FPS pow_1(mint k, int d = -1) const {\n        assert((*this)[0]\
    \ == 1);\n        return ((*this).log(d) * k).exp(d);\n    }\n\n    FPS pow_newton(long\
    \ long k, int d = -1) const {\n        assert(k >= 0);\n        const int n =\
    \ deg();\n        if (d < 0) d = n;\n        if (k == 0) {\n            FPS f(d);\n\
    \            if (d > 0) f[0] = 1;\n            return f;\n        }\n        for\
    \ (int i = 0; i < n; i++) {\n            if ((*this)[i] != 0) {\n            \
    \    mint rev = (*this)[i].inv();\n                FPS f = (((*this * rev) >>\
    \ i).log(d) * k).exp(d);\n                f *= (*this)[i].pow(k);\n          \
    \      f = (f << (i * k)).pre(d);\n                if (f.deg() < d) f.resize(d);\n\
    \                return f;\n            }\n            if (i + 1 >= (d + k - 1)\
    \ / k) break;\n        }\n        return FPS(d);\n    }\n\n    int deg() const\
    \ {\n        return (*this).size();\n    }\n\n    void shrink() {\n        while\
    \ ((!this->empty()) && this->back() == 0) this->pop_back();\n    }\n\n    int\
    \ count_terms() const {\n        int c = 0;\n        for (int i = 0; i < deg();\
    \ i++) {\n            if ((*this)[i] != 0) c++;\n        }\n        return c;\n\
    \    }\n\n    std::optional<FPS> sqrt(int d = -1) const;\n\n    static FPS exp_x(int\
    \ n) {\n        FPS f(n);\n        mint fact = 1;\n        for (int i = 1; i <\
    \ n; i++) fact *= i;\n        f[n - 1] = fact.inv();\n        for (int i = n -\
    \ 1; i >= 0; i--) f[i - 1] = f[i] * i;\n        return f;\n    }\n\n    void fft();\n\
    \    void ifft();\n};\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <optional>\n\
    #include <vector>\n\n#include \"../modint/base.hpp\"\n\nnamespace ebi {\n\ntemplate\
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
    \ * i;\n        return f;\n    }\n\n    void fft();\n    void ifft();\n};\n\n\
    }  // namespace ebi"
  dependsOn:
  - modint/base.hpp
  isVerificationFile: false
  path: fps/fps.hpp
  requiredBy:
  - fps/product_of_one_plus_xn.hpp
  - fps/product_of_one_minus_xn.hpp
  - fps/ntt_friendly_fps.hpp
  - fps/product_of_fps.hpp
  - fps/composition_of_fps.hpp
  - fps/fps_sqrt.hpp
  - fps/power_projection_of_fps.hpp
  - fps/polynomial_interpolation.hpp
  - fps/taylor_shift.hpp
  - fps/multipoint_evaluation.hpp
  - fps/compositional_inverse_of_fps.hpp
  - fps/compositional_inverse_of_fps_old.hpp
  - fps/sum_of_rational_fps.hpp
  - math/sums_of_powers_iota.hpp
  - math/stirling_number_1st.hpp
  - math/bernoulli_number.hpp
  - math/sums_of_powers.hpp
  - math/stirling_number_2nd.hpp
  - math/partition_function.hpp
  timestamp: '2024-05-24 14:53:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki/yuki_1857.test.cpp
  - test/yuki/yuki_1145.test.cpp
  - test/yuki/yuki_1302.test.cpp
  - test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - test/polynomial/Product_of_Polynomial_Sequence.test.cpp
  - test/polynomial/Log_of_Formal_Power_Series.test.cpp
  - test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
  - test/polynomial/Inv_of_Formal_Power_Series.test.cpp
  - test/polynomial/Composition_of_Formal_Power_Series.test.cpp
  - test/polynomial/Polynomial_Taylor_Shift.test.cpp
  - test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Division_of_Polynomials.test.cpp
  - test/polynomial/Pow_of_Formal_Power_Series.test.cpp
  - test/polynomial/Polynomial_Interpolation.test.cpp
  - test/polynomial/Exp_of_Formal_Power_Series.test.cpp
  - test/polynomial/Multipoint_Evaluation.test.cpp
  - test/polynomial/Compositional_Inverse_of_Formal_Power_Series_Large.test.cpp
  - test/math/Sharp_P_Subset_Sum.test.cpp
  - test/math/Berunoulli_Number.test.cpp
  - test/math/Partition_Function_FPS.test.cpp
  - test/math/Stirling_Number_of_the_Second_Kind.test.cpp
  - test/math/Stirling_Number_of_the_First_Kind.test.cpp
  - test/math/Partition_Function_Pentagonal.test.cpp
  - test/math/Sum_of_Powers_Iota.test.cpp
documentation_of: fps/fps.hpp
layout: document
title: Formal Power Series
---

## 説明

形式的べき級数 $f$ を管理し、各種操作を行う構造体。`std::vector`を継承している。

### テンプレート引数

- `mint`
形式的べき級数の係数の型。modintを想定している。

- `std::vector<mint> convolution(const std::vector<mint> &, const std::vector<mint> &)`
配列`std::vector<mint>`の畳み込み`covolution`。
愚直 $O(N^2)$ 、NTTを用いると $O(N\log N)$ となる。
以下畳み込みの計算量を $O(N\log N)$ として計算量を記述する。

### コンストラクタ

`std::vector` と同一。

### 和・差

$O(N)$

### 積

NTTを用いると $O(N\log N)$

### 割り算・余り

$f, g$ を多項式として、 $f = q * g + r$ となる多項式 $q$ を商、 $r$ を余りとする。
$O(N\log N)$

### deg()

$f$ の最大次数 $+1$ を返す。

### pre(int sz)

多項式の前 $sz$ 項を所得する。

### rev()

多項式を反転させる。つまり $n = deg()$ として $f(x^{-1}) * x^{n-1}$ を計算する。
$O(N)$

### differantial()

形式的べき級数 $f$ を微分したものを返す。
$O(N)$

### integral()

形式的べき級数 $f$ を積分したものを返す。
$O(N)$

### inv(int d)

形式的べき級数 $f$ の逆元を $\mod x^d$ で求める。
$O(N \log N)$

### log(int d)

形式的べき級数 $f$ の $\log$ を $\mod x^d$ で求める。
$O(N\log N)$

### exp(int d)

形式的べき級数 $f$ の $\exp$ を $\mod x^d$ で求める。
$O(N\log N)$

### pow(long long k, int d)

非負整数 $k$ について、形式的べき級数 $f$ について $f^k \pmod{x^d}$ を求める。愚直だと $O(N\log N \log K)$ だが、$\log$ を取って $k$ を掛けて $\exp$ を取ることで求める。
$O(N\log N)$

### pow_1(mint k, int d)

非零の有理数 $k$ 、 $[x^0] f = 1$ であるFPSについて、 $f^k \pmod{x^d}$ を求める。

### sqrt(int d)

形式的べき級数 $f$ について $\sqrt{f}$ が存在するなら求める。存在しない場合は `std::nullopt`を返す。
$O(N\log N)$

### shrink()

末尾の不要なゼロを削除する。

### exp_x(int n)

$\exp{x} \mod x^n$ を返す。 $O(N)$