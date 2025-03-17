---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/berlekamp_massey.hpp
    title: Berlekamp Massey
  - icon: ':heavy_check_mark:'
    path: fps/fps.hpp
    title: Formal Power Series
  - icon: ':heavy_check_mark:'
    path: fps/poly_mod_pow.hpp
    title: fps/poly_mod_pow.hpp
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':heavy_check_mark:'
    path: utility/random_number_generator.hpp
    title: Random Number Generator
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/matrix/Determinant_of_Sparse_Matrix.test.cpp
    title: test/matrix/Determinant_of_Sparse_Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1112.test.cpp
    title: test/yuki/yuki_1112.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"matrix/black_box_linear_algebra.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n#line 2 \"fps/berlekamp_massey.hpp\"\n\n#include <algorithm>\n\
    #line 5 \"fps/berlekamp_massey.hpp\"\n\n#line 2 \"modint/base.hpp\"\n\n#include\
    \ <concepts>\n#include <iostream>\n#include <utility>\n\nnamespace ebi {\n\ntemplate\
    \ <class T>\nconcept Modint = requires(T a, T b) {\n    a + b;\n    a - b;\n \
    \   a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 7 \"\
    fps/berlekamp_massey.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint>\nstd::vector<mint>\
    \ berlekamp_massey(const std::vector<mint> &s) {\n    std::vector<mint> C = {1},\
    \ B = {1};\n    int L = 0, m = 1;\n    mint b = 1;\n    for (int n = 0; n < (int)s.size();\
    \ n++) {\n        mint d = s[n];\n        for (int i = 1; i <= L; i++) {\n   \
    \         d += s[n - i] * C[i];\n        }\n        if (d == 0) {\n          \
    \  m++;\n        } else if (2 * L <= n) {\n            auto T = C;\n         \
    \   mint f = d / b;\n            C.resize((int)B.size() + m);\n            for\
    \ (int i = 0; i < (int)B.size(); i++) {\n                C[i + m] -= f * B[i];\n\
    \            }\n            L = n + 1 - L;\n            B = T;\n            b\
    \ = d;\n            m = 1;\n        } else {\n            mint f = d / b;\n  \
    \          for (int i = 0; i < (int)B.size(); i++) {\n                C[i + m]\
    \ -= f * B[i];\n            }\n            m++;\n        }\n    }\n    return\
    \ C;\n}\n\n}  // namespace ebi\n#line 2 \"fps/poly_mod_pow.hpp\"\n\n#line 2 \"\
    fps/fps.hpp\"\n\n#line 5 \"fps/fps.hpp\"\n#include <optional>\n#line 7 \"fps/fps.hpp\"\
    \n\n#line 9 \"fps/fps.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint> struct\
    \ FormalPowerSeries : std::vector<mint> {\n  private:\n    using std::vector<mint>::vector;\n\
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
    \    void ifft();\n};\n\n}  // namespace ebi\n#line 5 \"fps/poly_mod_pow.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint>\nFormalPowerSeries<mint> poly_mod_pow(FormalPowerSeries<mint>\
    \ f, long long k,\n                                     const FormalPowerSeries<mint>\
    \ &g) {\n    FormalPowerSeries<mint> res = {1};\n    while (k > 0) {\n       \
    \ if (k & 1) {\n            res *= f;\n            res %= g;\n            res.shrink();\n\
    \        }\n        f *= f;\n        f %= g;\n        f.shrink();\n        k >>=\
    \ 1;\n    }\n    return res;\n}\n\n}  // namespace ebi\n#line 2 \"utility/random_number_generator.hpp\"\
    \n\r\n#line 4 \"utility/random_number_generator.hpp\"\n#include <cstdint>\r\n\
    #include <numeric>\r\n#include <random>\r\n#line 8 \"utility/random_number_generator.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\nstruct random_number_generator {\r\n    random_number_generator(int\
    \ seed = -1) {\r\n        if (seed < 0) seed = rnd();\r\n        mt.seed(seed);\r\
    \n    }\r\n\r\n    void set_seed(int seed) {\r\n        mt.seed(seed);\r\n   \
    \ }\r\n\r\n    template <class T> T get(T a, T b) {\r\n        std::uniform_int_distribution<T>\
    \ dist(a, b - 1);\r\n        return dist(mt);\r\n    }\r\n\r\n    std::vector<int>\
    \ get_permutation(int n) {\r\n        std::vector<int> p(n);\r\n        std::iota(p.begin(),\
    \ p.end(), 0);\r\n        std::shuffle(p.begin(), p.end(), mt);\r\n        return\
    \ p;\r\n    }\r\n\r\n  private:\r\n    std::mt19937_64 mt;\r\n    std::random_device\
    \ rnd;\r\n};\r\n\r\n}  // namespace ebi\n#line 10 \"matrix/black_box_linear_algebra.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint, class F>\nstd::vector<mint> matrix_minimum_poly(int\
    \ n, F Ax) {\n    static random_number_generator rng;\n    std::vector<mint> s(2\
    \ * n + 10, 0), u(n), b(n);\n    for (int i = 0; i < n; i++) {\n        u[i] =\
    \ rng.get(0, mint::mod());\n        b[i] = rng.get(0, mint::mod());\n    }\n \
    \   for (int i = 0; i < 2 * n + 10; i++) {\n        for (int j = 0; j < n; j++)\
    \ {\n            s[i] += u[j] * b[j];\n        }\n        b = Ax(b);\n    }\n\
    \    auto c = berlekamp_massey(s);\n    std::reverse(c.begin(), c.end());\n  \
    \  return c;\n}\n\ntemplate <Modint mint, class F>\nstd::vector<mint> pow(int\
    \ n, F Ax, const std::vector<mint> &b, long long k) {\n    assert(n == (int)b.size());\n\
    \    using FPS = FormalPowerSeries<mint>;\n    auto g = matrix_minimum_poly<mint>(n,\
    \ Ax);\n    auto c = poly_mod_pow<mint>({0, 1}, k, g);\n    FPS res(n, 0), Ab\
    \ = b;\n    for (int i = 0; i < (int)c.size(); i++) {\n        res += Ab * c[i];\n\
    \        Ab = FPS(Ax(Ab));\n    }\n    return res;\n}\n\ntemplate <Modint mint,\
    \ class F> mint det(int n, F Ax) {\n    static random_number_generator rng;\n\
    \    std::vector<mint> d(n);\n    mint r = 1;\n    for (int i = 0; i < n; i++)\
    \ {\n        d[i] = rng.get(1, mint::mod());\n        r *= d[i];\n    }\n    auto\
    \ ADx = [&](std::vector<mint> v) -> std::vector<mint> {\n        assert(n == (int)v.size());\n\
    \        for (int i = 0; i < n; i++) {\n            v[i] *= d[i];\n        }\n\
    \        return Ax(v);\n    };\n    auto f = matrix_minimum_poly<mint>(n, ADx);\n\
    \    mint res = ((int)f.size() == n + 1 ? f[0] : 0);\n    if (n % 2 == 1) res\
    \ = -res;\n    return res / r;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../fps/berlekamp_massey.hpp\"\
    \n#include \"../fps/poly_mod_pow.hpp\"\n#include \"../modint/base.hpp\"\n#include\
    \ \"../utility/random_number_generator.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint\
    \ mint, class F>\nstd::vector<mint> matrix_minimum_poly(int n, F Ax) {\n    static\
    \ random_number_generator rng;\n    std::vector<mint> s(2 * n + 10, 0), u(n),\
    \ b(n);\n    for (int i = 0; i < n; i++) {\n        u[i] = rng.get(0, mint::mod());\n\
    \        b[i] = rng.get(0, mint::mod());\n    }\n    for (int i = 0; i < 2 * n\
    \ + 10; i++) {\n        for (int j = 0; j < n; j++) {\n            s[i] += u[j]\
    \ * b[j];\n        }\n        b = Ax(b);\n    }\n    auto c = berlekamp_massey(s);\n\
    \    std::reverse(c.begin(), c.end());\n    return c;\n}\n\ntemplate <Modint mint,\
    \ class F>\nstd::vector<mint> pow(int n, F Ax, const std::vector<mint> &b, long\
    \ long k) {\n    assert(n == (int)b.size());\n    using FPS = FormalPowerSeries<mint>;\n\
    \    auto g = matrix_minimum_poly<mint>(n, Ax);\n    auto c = poly_mod_pow<mint>({0,\
    \ 1}, k, g);\n    FPS res(n, 0), Ab = b;\n    for (int i = 0; i < (int)c.size();\
    \ i++) {\n        res += Ab * c[i];\n        Ab = FPS(Ax(Ab));\n    }\n    return\
    \ res;\n}\n\ntemplate <Modint mint, class F> mint det(int n, F Ax) {\n    static\
    \ random_number_generator rng;\n    std::vector<mint> d(n);\n    mint r = 1;\n\
    \    for (int i = 0; i < n; i++) {\n        d[i] = rng.get(1, mint::mod());\n\
    \        r *= d[i];\n    }\n    auto ADx = [&](std::vector<mint> v) -> std::vector<mint>\
    \ {\n        assert(n == (int)v.size());\n        for (int i = 0; i < n; i++)\
    \ {\n            v[i] *= d[i];\n        }\n        return Ax(v);\n    };\n   \
    \ auto f = matrix_minimum_poly<mint>(n, ADx);\n    mint res = ((int)f.size() ==\
    \ n + 1 ? f[0] : 0);\n    if (n % 2 == 1) res = -res;\n    return res / r;\n}\n\
    \n}  // namespace ebi"
  dependsOn:
  - fps/berlekamp_massey.hpp
  - modint/base.hpp
  - fps/poly_mod_pow.hpp
  - fps/fps.hpp
  - utility/random_number_generator.hpp
  isVerificationFile: false
  path: matrix/black_box_linear_algebra.hpp
  requiredBy: []
  timestamp: '2024-08-06 16:15:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/matrix/Determinant_of_Sparse_Matrix.test.cpp
  - test/yuki/yuki_1112.test.cpp
documentation_of: matrix/black_box_linear_algebra.hpp
layout: document
title: Black Box Linear Algebra
---

## 説明

Black Box Linear Algebraは、行列を陽に与えずに、行列 $A$ とベクトル $v$ の積の演算を行う関数（black box） $Ax$ を与えることで各種の計算を行うものである。以下、 $A$ と ベクトル $v$ の積の計算量を $T(N)$ とする。

### matrix_minimum_poly(int n, F Ax)

$N$ 次正方行列 $A$ の最小多項式を求める。 $O(N^2)$

### pow(int n, F Ax, std::vector<mint> b, long long k)

$A^k b$ を求める。多項式乗算の計算量を $M(N)$ とすると、 $O(N^2 + M(N)\log{k} + N T(N))$

### det(int n, F Ax)

$N$ 次正方行列 $A$ の行列式を求める。 $O(N^2 + N T(N))$ 