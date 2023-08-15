---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/fps.hpp
    title: Formal Power Series
  - icon: ':question:'
    path: fps/fps_sparse.hpp
    title: Formal Power Series (Sparse)
  - icon: ':question:'
    path: utility/modint_func.hpp
    title: utility/modint_func.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/Partition_Function_FPS.test.cpp
    title: test/math/Partition_Function_FPS.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/product_of_one_minus_xn.hpp\"\n\n#include <vector>\n\
    \n#line 2 \"fps/fps.hpp\"\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <optional>\n#line 7 \"fps/fps.hpp\"\n\n#line 2 \"fps/fps_sparse.hpp\"\n\n#line\
    \ 5 \"fps/fps_sparse.hpp\"\n\n#line 2 \"utility/modint_func.hpp\"\n\n#line 5 \"\
    utility/modint_func.hpp\"\n\nnamespace ebi {\n\ntemplate <class mint> mint inv(int\
    \ n) {\n    static const int mod = mint::mod();\n    static std::vector<mint>\
    \ dat = {0, 1};\n    assert(0 <= n);\n    if (n >= mod) n -= mod;\n    while (int(dat.size())\
    \ <= n) {\n        int num = dat.size();\n        int q = (mod + num - 1) / num;\n\
    \        dat.emplace_back(dat[num * q - mod] * mint(q));\n    }\n    return dat[n];\n\
    }\n\n}  // namespace ebi\n#line 7 \"fps/fps_sparse.hpp\"\n\nnamespace ebi {\n\n\
    template <class mint>\nstd::vector<mint> mul_sparse(const std::vector<mint> &f,\n\
    \                             const std::vector<mint> &g) {\n    int n = f.size();\n\
    \    int m = g.size();\n    std::vector<std::pair<int, mint>> cf, cg;\n    for\
    \ (int i = 0; i < n; i++) {\n        if (f[i] != 0) cf.emplace_back(i, f[i]);\n\
    \    }\n    for (int i = 0; i < m; i++) {\n        if (g[i] != 0) cg.emplace_back(i,\
    \ g[i]);\n    }\n    std::vector<mint> h(n + m - 1);\n    for (auto [i, p] : cf)\
    \ {\n        for (auto [j, q] : cg) {\n            h[i + j] += p * q;\n      \
    \  }\n    }\n    return h;\n}\n\ntemplate <class mint>\nstd::vector<mint> inv_sparse(const\
    \ std::vector<mint> &f, int d = -1) {\n    assert(f[0] != 0);\n    if (d < 0)\
    \ {\n        d = f.size();\n    }\n    std::vector<std::pair<int, mint>> ret;\n\
    \    for (int i = 1; i < int(f.size()); i++) {\n        if (f[i] != 0) {\n   \
    \         ret.emplace_back(i, f[i]);\n        }\n    }\n    std::vector<mint>\
    \ g(d);\n    g[0] = f[0].inv();\n    for (int i = 1; i < d; i++) {\n        for\
    \ (auto [k, p] : ret) {\n            if (i - k < 0) break;\n            g[i] -=\
    \ g[i - k] * p;\n        }\n        g[i] *= g[0];\n    }\n    return g;\n}\n\n\
    template <class mint>\nstd::vector<mint> exp_sparse(const std::vector<mint> &f,\
    \ int d = -1) {\n    int n = f.size();\n    if (d < 0) d = n;\n    std::vector<std::pair<int,\
    \ mint>> ret;\n    for (int i = 1; i < n; i++) {\n        if (f[i] != 0) {\n \
    \           ret.emplace_back(i - 1, f[i] * i);\n        }\n    }\n    std::vector<mint>\
    \ g(d);\n    g[0] = 1;\n    for (int i = 0; i < d - 1; i++) {\n        for (auto\
    \ [k, p] : ret) {\n            if (i - k < 0) break;\n            g[i + 1] +=\
    \ g[i - k] * p;\n        }\n        g[i + 1] *= inv<mint>(i + 1);\n    }\n   \
    \ return g;\n}\n\ntemplate <class mint>\nstd::vector<mint> log_sparse(const std::vector<mint>\
    \ &f, int d = -1) {\n    int n = f.size();\n    if (d < 0) d = n;\n    std::vector<mint>\
    \ df(d);\n    for (int i = 0; i < std::min(d, n - 1); i++) {\n        df[i] =\
    \ f[i + 1] * (i + 1);\n    }\n    auto dg = mul_sparse(df, inv_sparse(f));\n \
    \   dg.resize(d);\n    std::vector<mint> g(d);\n    for (int i = 0; i < d - 1;\
    \ i++) {\n        g[i + 1] = dg[i] * inv<mint>(i + 1);\n    }\n    return g;\n\
    }\n\ntemplate <class mint>\nstd::vector<mint> pow_sparse_1(const std::vector<mint>\
    \ &f, long long k,\n                               int d = -1) {\n    int n =\
    \ f.size();\n    assert(n == 0 || f[0] == 1);\n    std::vector<std::pair<int,\
    \ mint>> ret;\n    for (int i = 1; i < n; i++) {\n        if (f[i] != 0) ret.emplace_back(i,\
    \ f[i]);\n    }\n    std::vector<mint> g(d);\n    g[0] = 1;\n    for (int i =\
    \ 0; i < d - 1; i++) {\n        for (const auto &[j, cf] : ret) {\n          \
    \  if (i + 1 - j < 0) break;\n            g[i + 1] +=\n                (mint(k)\
    \ * mint(j) - mint(i - j + 1)) * cf * g[i + 1 - j];\n        }\n        g[i +\
    \ 1] *= inv<mint>(i + 1);\n    }\n    return g;\n}\n\ntemplate <class mint>\n\
    std::vector<mint> pow_sparse(const std::vector<mint> &f, long long k,\n      \
    \                       int d = -1) {\n    int n = f.size();\n    if (d < 0) d\
    \ = n;\n    assert(k >= 0);\n    if (k == 0) {\n        std::vector<mint> g(d);\n\
    \        if (d > 0) g[0] = 1;\n        return g;\n    }\n    for (int i = 0; i\
    \ < n; i++) {\n        if (f[i] != 0) {\n            mint rev = f[i].inv();\n\
    \            std::vector<mint> f2(n - i);\n            for (int j = i; j < n;\
    \ j++) {\n                f2[j - i] = f[j] * rev;\n            }\n           \
    \ f2 = pow_sparse_1(f2, k, d);\n            mint fk = f[i].pow(k);\n         \
    \   std::vector<mint> g(d);\n            for (int j = 0; j < int(f2.size()); j++)\
    \ {\n                if (j + i * k >= d) break;\n                g[j + i * k]\
    \ = f2[j] * fk;\n            }\n            return g;\n        }\n        if (i\
    \ >= (d + k - 1) / k) break;\n    }\n    return std::vector<mint>(d);\n}\n\n}\
    \  // namespace ebi\n#line 9 \"fps/fps.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ mint, std::vector<mint> (*convolution)(\n                          const std::vector<mint>\
    \ &, const std::vector<mint> &)>\nstruct FormalPowerSeries : std::vector<mint>\
    \ {\n  private:\n    using std::vector<mint>::vector;\n    using std::vector<mint>::vector::operator=;\n\
    \    using FPS = FormalPowerSeries;\n\n  public:\n    FPS operator+(const FPS\
    \ &rhs) const noexcept {\n        return FPS(*this) += rhs;\n    }\n    FPS operator-(const\
    \ FPS &rhs) const noexcept {\n        return FPS(*this) -= rhs;\n    }\n    FPS\
    \ operator*(const FPS &rhs) const noexcept {\n        return FPS(*this) *= rhs;\n\
    \    }\n    FPS operator/(const FPS &rhs) const noexcept {\n        return FPS(*this)\
    \ /= rhs;\n    }\n    FPS operator%(const FPS &rhs) const noexcept {\n       \
    \ return FPS(*this) %= rhs;\n    }\n\n    FPS operator+(const mint &rhs) const\
    \ noexcept {\n        return FPS(*this) += rhs;\n    }\n    FPS operator-(const\
    \ mint &rhs) const noexcept {\n        return FPS(*this) -= rhs;\n    }\n    FPS\
    \ operator*(const mint &rhs) const noexcept {\n        return FPS(*this) *= rhs;\n\
    \    }\n    FPS operator/(const mint &rhs) const noexcept {\n        return FPS(*this)\
    \ /= rhs;\n    }\n\n    FPS &operator+=(const FPS &rhs) noexcept {\n        if\
    \ (this->size() < rhs.size()) this->resize(rhs.size());\n        for (int i =\
    \ 0; i < (int)rhs.size(); ++i) {\n            (*this)[i] += rhs[i];\n        }\n\
    \        return *this;\n    }\n\n    FPS &operator-=(const FPS &rhs) noexcept\
    \ {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n      \
    \  for (int i = 0; i < (int)rhs.size(); ++i) {\n            (*this)[i] -= rhs[i];\n\
    \        }\n        return *this;\n    }\n\n    FPS &operator*=(const FPS &rhs)\
    \ noexcept {\n        *this = convolution(*this, rhs);\n        return *this;\n\
    \    }\n\n    FPS &operator/=(const FPS &rhs) noexcept {\n        int n = deg()\
    \ - 1;\n        int m = rhs.deg() - 1;\n        if (n < m) {\n            *this\
    \ = {};\n            return *this;\n        }\n        *this = (*this).rev() *\
    \ rhs.rev().inv(n - m + 1);\n        (*this).resize(n - m + 1);\n        std::reverse((*this).begin(),\
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
    \ 1;\n        if (d < 0) d = deg();\n        if (count_terms() < 300) {\n    \
    \        FPS res;\n            res = inv_sparse(*this, d);\n            return\
    \ res;\n        }\n        FPS g(n);\n        g[0] = (*this)[0].inv();\n     \
    \   while (n < d) {\n            n <<= 1;\n            g = (g * 2 - g * g * this->pre(n)).pre(n);\n\
    \        }\n        g.resize(d);\n        return g;\n    }\n\n    FPS log(int\
    \ d = -1) const {\n        assert((*this)[0].val() == 1);\n        if (d < 0)\
    \ d = deg();\n        if (count_terms() < 300) {\n            FPS res;\n     \
    \       res = log_sparse(*this, d);\n            return res;\n        }\n    \
    \    return ((*this).differential() * (*this).inv(d)).pre(d - 1).integral();\n\
    \    }\n\n    FPS exp(int d = -1) const {\n        assert((*this)[0].val() ==\
    \ 0);\n        int n = 1;\n        if (d < 0) d = deg();\n        if (count_terms()\
    \ < 300) {\n            FPS res;\n            res = exp_sparse(*this, d);\n  \
    \          return res;\n        }\n        FPS g(n);\n        g[0] = 1;\n    \
    \    while (n < d) {\n            n <<= 1;\n            g = (g * (this->pre(n)\
    \ - g.log(n) + 1)).pre(n);\n        }\n        g.resize(d);\n        return g;\n\
    \    }\n\n    FPS pow(int64_t k, int d = -1) const {\n        const int n = deg();\n\
    \        if (d < 0) d = n;\n        if (k == 0) {\n            FPS f(d);\n   \
    \         if (d > 0) f[0] = 1;\n            return f;\n        }\n        if (count_terms()\
    \ < 300) {\n            FPS res;\n            res = pow_sparse(*this, d);\n  \
    \          return res;\n        }\n        for (int i = 0; i < n; i++) {\n   \
    \         if ((*this)[i] != 0) {\n                mint rev = (*this)[i].inv();\n\
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
    \ * i;\n        return f;\n    }\n};\n\n}  // namespace ebi\n#line 7 \"fps/product_of_one_minus_xn.hpp\"\
    \n\nnamespace ebi {\n\n// prod (1 - x^a_i) mod x^d\ntemplate <class mint, std::vector<mint>\
    \ (*convolution)(\n                          const std::vector<mint> &, const\
    \ std::vector<mint> &)>\nFormalPowerSeries<mint, convolution> product_of_one_minus_xn(std::vector<int>\
    \ a,\n                                                             int d) {\n\
    \    using FPS = FormalPowerSeries<mint, convolution>;\n    std::vector<int> cnt(d,\
    \ 0);\n    for (auto x : a)\n        if (x < d) cnt[x]++;\n    if (cnt[0]) return\
    \ FPS(d);\n    FPS log_f(d);\n    for (int x = 1; x < d; x++) {\n        for (int\
    \ i = 1; x * i < d; i++) {\n            log_f[x * i] -= mint(cnt[x]) * inv<mint>(i);\n\
    \        }\n    }\n    return log_f.exp(d);\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <vector>\n\n#include \"../fps/fps.hpp\"\n#include\
    \ \"../utility/modint_func.hpp\"\n\nnamespace ebi {\n\n// prod (1 - x^a_i) mod\
    \ x^d\ntemplate <class mint, std::vector<mint> (*convolution)(\n             \
    \             const std::vector<mint> &, const std::vector<mint> &)>\nFormalPowerSeries<mint,\
    \ convolution> product_of_one_minus_xn(std::vector<int> a,\n                 \
    \                                            int d) {\n    using FPS = FormalPowerSeries<mint,\
    \ convolution>;\n    std::vector<int> cnt(d, 0);\n    for (auto x : a)\n     \
    \   if (x < d) cnt[x]++;\n    if (cnt[0]) return FPS(d);\n    FPS log_f(d);\n\
    \    for (int x = 1; x < d; x++) {\n        for (int i = 1; x * i < d; i++) {\n\
    \            log_f[x * i] -= mint(cnt[x]) * inv<mint>(i);\n        }\n    }\n\
    \    return log_f.exp(d);\n}\n\n}  // namespace ebi"
  dependsOn:
  - fps/fps.hpp
  - fps/fps_sparse.hpp
  - utility/modint_func.hpp
  isVerificationFile: false
  path: fps/product_of_one_minus_xn.hpp
  requiredBy: []
  timestamp: '2023-08-15 20:19:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/Partition_Function_FPS.test.cpp
documentation_of: fps/product_of_one_minus_xn.hpp
layout: document
title: $\prod (1 - x^{a_i}) \mod x^d$
---

## 説明

$\prod (1 - x^{a_i}) \mod x^d$ を $O(D(\log D + \log \max a))$ で求める。 $D$ は求めたい最大の次数である。中身は、$\log$ を取って $\exp$ している。