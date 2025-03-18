---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/binomial.hpp
    title: Binomial Coefficient
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Shift_of_Sampling_Points_of_Polynomial.test.cpp
    title: test/polynomial/Shift_of_Sampling_Points_of_Polynomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/shift_of_sampling_points_of_poly.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n#line 2 \"math/binomial.hpp\"\n\n#include <bit>\n#line 5\
    \ \"math/binomial.hpp\"\n#include <cstdint>\n#include <iostream>\n#include <ranges>\n\
    #line 9 \"math/binomial.hpp\"\n\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n\
    #line 5 \"modint/base.hpp\"\n#include <utility>\n\nnamespace ebi {\n\ntemplate\
    \ <class T>\nconcept Modint = requires(T a, T b) {\n    a + b;\n    a - b;\n \
    \   a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 11 \"\
    math/binomial.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint> struct Binomial\
    \ {\n  private:\n    static void extend(int len = -1) {\n        int sz = (int)fact.size();\n\
    \        if (len < 0)\n            len = 2 * sz;\n        else if (len <= sz)\n\
    \            return;\n        else\n            len = std::max(2 * sz, (int)std::bit_ceil(std::uint32_t(len)));\n\
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
    \    }\n\n    static mint catalan_number(int n) {\n        return c(2 * n, n)\
    \ * inv(n + 1);\n    }\n\n    static mint inv(int n) {\n        return inv_f(n)\
    \ * f(n - 1);\n    }\n\n    static void reserve(int n) {\n        extend(n + 1);\n\
    \    }\n\n  private:\n    static std::vector<mint> fact, inv_fact;\n};\n\ntemplate\
    \ <Modint mint>\nstd::vector<mint> Binomial<mint>::fact = std::vector<mint>(2,\
    \ 1);\n\ntemplate <Modint mint>\nstd::vector<mint> Binomial<mint>::inv_fact =\
    \ std::vector<mint>(2, 1);\n\n}  // namespace ebi\n#line 8 \"fps/shift_of_sampling_points_of_poly.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint,\n          std::vector<mint> (*convolution)(const\
    \ std::vector<mint> &,\n                                           const std::vector<mint>\
    \ &)>\nstd::vector<mint> shift_of_sampling_points_of_poly(std::vector<mint> f,\
    \ int c,\n                                                   int m) {\n    int\
    \ n = (int)f.size();\n    Binomial<mint> binom(std::max(n, m));\n    {\n     \
    \   std::vector<mint> g(n);\n        for (int i = 0; i < n; i++) {\n         \
    \   f[i] *= binom.inv_f(i);\n            g[i] = i % 2 == 0 ? binom.inv_f(i) :\
    \ -binom.inv_f(i);\n        }\n        f = convolution(f, g);\n        f.resize(n);\n\
    \    }\n    {\n        mint cc = 1;\n        std::vector<mint> g(n);\n       \
    \ for (int i = 0; i < n; i++) {\n            f[i] *= binom.f(i);\n        }\n\
    \        for (int i = n - 1; i >= 0; i--) {\n            g[i] = cc * binom.inv_f(n\
    \ - 1 - i);\n            cc *= c - (n - 1 - i);\n        }\n        auto fg =\
    \ convolution(f, g);\n        for (int i = 0; i < n; i++) {\n            f[i]\
    \ = fg[n - 1 + i] * binom.inv_f(i);\n        }\n    }\n    {\n        std::vector<mint>\
    \ g(m);\n        for (int i = 0; i < m; i++) {\n            g[i] = binom.inv_f(i);\n\
    \        }\n        f = convolution(f, g);\n        f.resize(m);\n        for\
    \ (int i = 0; i < m; i++) {\n            f[i] *= binom.f(i);\n        }\n    }\n\
    \    return f;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../math/binomial.hpp\"\
    \n#include \"../modint/base.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint,\n\
    \          std::vector<mint> (*convolution)(const std::vector<mint> &,\n     \
    \                                      const std::vector<mint> &)>\nstd::vector<mint>\
    \ shift_of_sampling_points_of_poly(std::vector<mint> f, int c,\n             \
    \                                      int m) {\n    int n = (int)f.size();\n\
    \    Binomial<mint> binom(std::max(n, m));\n    {\n        std::vector<mint> g(n);\n\
    \        for (int i = 0; i < n; i++) {\n            f[i] *= binom.inv_f(i);\n\
    \            g[i] = i % 2 == 0 ? binom.inv_f(i) : -binom.inv_f(i);\n        }\n\
    \        f = convolution(f, g);\n        f.resize(n);\n    }\n    {\n        mint\
    \ cc = 1;\n        std::vector<mint> g(n);\n        for (int i = 0; i < n; i++)\
    \ {\n            f[i] *= binom.f(i);\n        }\n        for (int i = n - 1; i\
    \ >= 0; i--) {\n            g[i] = cc * binom.inv_f(n - 1 - i);\n            cc\
    \ *= c - (n - 1 - i);\n        }\n        auto fg = convolution(f, g);\n     \
    \   for (int i = 0; i < n; i++) {\n            f[i] = fg[n - 1 + i] * binom.inv_f(i);\n\
    \        }\n    }\n    {\n        std::vector<mint> g(m);\n        for (int i\
    \ = 0; i < m; i++) {\n            g[i] = binom.inv_f(i);\n        }\n        f\
    \ = convolution(f, g);\n        f.resize(m);\n        for (int i = 0; i < m; i++)\
    \ {\n            f[i] *= binom.f(i);\n        }\n    }\n    return f;\n}\n\n}\
    \  // namespace ebi"
  dependsOn:
  - math/binomial.hpp
  - modint/base.hpp
  isVerificationFile: false
  path: fps/shift_of_sampling_points_of_poly.hpp
  requiredBy: []
  timestamp: '2024-07-27 23:45:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/polynomial/Shift_of_Sampling_Points_of_Polynomial.test.cpp
documentation_of: fps/shift_of_sampling_points_of_poly.hpp
layout: document
title: Shift of Sampling Points of Polynomial
---

## 説明

$N$ 次未満の多項式 $f(x)$ の標本点 $f(0), f(1), \dots, f(N-1)$ を与えて、 $i = 0,1,\dots,M-1$ に対して $f(c + i)$ を求める。 $O((N+M)\log{(N+M)})$