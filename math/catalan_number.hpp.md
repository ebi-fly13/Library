---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/binomial.hpp
    title: Binomial Coefficient
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Catalan_Convolution.test.cpp
    title: test/math/Catalan_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/catalan_number.hpp\"\n\n#line 2 \"math/binomial.hpp\"\
    \n\n#include <bit>\n#include <cassert>\n#include <iostream>\n#include <ranges>\n\
    #include <vector>\n\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#line\
    \ 5 \"modint/base.hpp\"\n#include <utility>\n\nnamespace ebi {\n\ntemplate <class\
    \ T>\nconcept Modint = requires(T a, T b) {\n    a + b;\n    a - b;\n    a * b;\n\
    \    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long long>());\n\
    \    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 10 \"\
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
    \ - r);\n    }\n\n    static mint p(int n, int r) {\n        if (r < 0 || n <\
    \ r) return 0;\n        return f(n) * inv_f(n - r);\n    }\n\n    static mint\
    \ inv(int n) {\n        return inv_f(n) * f(n - 1);\n    }\n\n    static void\
    \ reserve(int n) {\n        extend(n + 1);\n    }\n\n  private:\n    static std::vector<mint>\
    \ fact, inv_fact;\n};\n\ntemplate <Modint mint>\nstd::vector<mint> Binomial<mint>::fact\
    \ = std::vector<mint>(2, 1);\n\ntemplate <Modint mint>\nstd::vector<mint> Binomial<mint>::inv_fact\
    \ = std::vector<mint>(2, 1);\n\n}  // namespace ebi\n#line 5 \"math/catalan_number.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint> mint catalan_number(int n) {\n \
    \   return Binomial<mint>::c(2 * n, n) * Binomial<mint>::inv(n + 1);\n}\n\n} \
    \ // namespace ebi\n"
  code: "#pragma once\n\n#include \"../math/binomial.hpp\"\n#include \"../modint/base.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint> mint catalan_number(int n) {\n \
    \   return Binomial<mint>::c(2 * n, n) * Binomial<mint>::inv(n + 1);\n}\n\n} \
    \ // namespace ebi"
  dependsOn:
  - math/binomial.hpp
  - modint/base.hpp
  isVerificationFile: false
  path: math/catalan_number.hpp
  requiredBy: []
  timestamp: '2024-02-18 14:20:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Catalan_Convolution.test.cpp
documentation_of: math/catalan_number.hpp
layout: document
title: Catalan Number
---

## 説明

$C(x)$ をカタラン数の母関数として、 $[x^n] C(x)$ を求める。