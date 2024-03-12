---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1796.test.cpp
    title: test/yuki/yuki_1796.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/middle_product.hpp\"\n\n#include <algorithm>\n#include\
    \ <bit>\n#include <cassert>\n#include <ranges>\n#include <vector>\n\n#line 2 \"\
    modint/base.hpp\"\n\n#include <concepts>\n#include <iostream>\n#include <utility>\n\
    \nnamespace ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n\
    \    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n\
    \    a.pow(std::declval<long long>());\n    T::mod();\n};\n\ntemplate <Modint\
    \ mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long long x;\n\
    \    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <Modint mint>\nstd::ostream\
    \ &operator<<(std::ostream &os, const mint &a) {\n    return os << a.val();\n\
    }\n\n}  // namespace ebi\n#line 10 \"fps/middle_product.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <Modint mint,\n          std::vector<mint> (*convolution)(const\
    \ std::vector<mint> &,\n                                           const std::vector<mint>\
    \ &)>\nstd::vector<mint> middle_product(const std::vector<mint> &a,\n        \
    \                         const std::vector<mint> &b) {\n    assert(a.size() >=\
    \ b.size());\n    if (std::min(a.size() - b.size() + 1, b.size()) <= 60) {\n \
    \       return middle_product_naive<mint>(a, b);\n    }\n    auto rb = b;\n  \
    \  std::reverse(rb.begin(), rb.end());\n    std::vector<mint> c = convolution(a,\
    \ rb);\n    c.resize(a.size());\n    c.erase(c.begin(), c.begin() + b.size() -\
    \ 1);\n    return c;\n}\n\ntemplate <Modint mint>\nstd::vector<mint> middle_product_naive(const\
    \ std::vector<mint> &a,\n                                       const std::vector<mint>\
    \ &b) {\n    int n = (int)a.size();\n    int m = (int)b.size();\n    assert(n\
    \ >= m);\n    std::vector<mint> c(n - m + 1, 0);\n    for (int i : std::views::iota(0,\
    \ n - m + 1)) {\n        for (int j : std::views::iota(0, m)) {\n            c[i]\
    \ += b[j] * a[i + j];\n        }\n    }\n    return c;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <bit>\n#include <cassert>\n\
    #include <ranges>\n#include <vector>\n\n#include \"../modint/base.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <Modint mint,\n          std::vector<mint> (*convolution)(const\
    \ std::vector<mint> &,\n                                           const std::vector<mint>\
    \ &)>\nstd::vector<mint> middle_product(const std::vector<mint> &a,\n        \
    \                         const std::vector<mint> &b) {\n    assert(a.size() >=\
    \ b.size());\n    if (std::min(a.size() - b.size() + 1, b.size()) <= 60) {\n \
    \       return middle_product_naive<mint>(a, b);\n    }\n    auto rb = b;\n  \
    \  std::reverse(rb.begin(), rb.end());\n    std::vector<mint> c = convolution(a,\
    \ rb);\n    c.resize(a.size());\n    c.erase(c.begin(), c.begin() + b.size() -\
    \ 1);\n    return c;\n}\n\ntemplate <Modint mint>\nstd::vector<mint> middle_product_naive(const\
    \ std::vector<mint> &a,\n                                       const std::vector<mint>\
    \ &b) {\n    int n = (int)a.size();\n    int m = (int)b.size();\n    assert(n\
    \ >= m);\n    std::vector<mint> c(n - m + 1, 0);\n    for (int i : std::views::iota(0,\
    \ n - m + 1)) {\n        for (int j : std::views::iota(0, m)) {\n            c[i]\
    \ += b[j] * a[i + j];\n        }\n    }\n    return c;\n}\n\n}  // namespace ebi"
  dependsOn:
  - modint/base.hpp
  isVerificationFile: false
  path: fps/middle_product.hpp
  requiredBy: []
  timestamp: '2024-01-05 02:16:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki/yuki_1796.test.cpp
documentation_of: fps/middle_product.hpp
layout: document
title: $[x^i]c = \sum_{j} [x^{i+j}]a [x^j]b$
---

## 説明

$N$ 次多項式 $a$ と $M$ 時多項式 $b$ について $[x^i]c = \sum_{j} [x^{i+j}]a [x^j]b$ となる $N-M$ 次多項式 $c$ を求める。 $O(N\log N)$