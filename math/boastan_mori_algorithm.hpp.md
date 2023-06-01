---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
    title: test/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/boastan_mori_algorithm.hpp\"\n\n#include <cstdint>\n\
    #include <vector>\n\nnamespace ebi {\n\ntemplate <class T, std::vector<T> (*convolution)(const\
    \ std::vector<T> &,\n                                                 const std::vector<T>\
    \ &)>\nT bostan_mori_algorithm(std::int64_t n, std::vector<T> p, std::vector<T>\
    \ q) {\n    while (n > 0) {\n        auto q_neg = q;\n        for (int i = 1;\
    \ i < (int)q_neg.size(); i += 2) q_neg[i] = -q_neg[i];\n        p = convolution(p,\
    \ q_neg);\n        q = convolution(q, q_neg);\n        for (int i = (n & 1LL);\
    \ i < (int)p.size(); i += 2) p[i >> 1] = p[i];\n        p.resize(((int)p.size()\
    \ + 1 - (n & 1LL)) / 2);\n        for (int i = 0; i < (int)q.size(); i += 2) q[i\
    \ >> 1] = q[i];\n        q.resize(((int)q.size() + 1) / 2);\n        n >>= 1;\n\
    \    }\n    return p[0] / q[0];\n}\n\ntemplate <class T, std::vector<T> (*convolution)(const\
    \ std::vector<T> &,\n                                                 const std::vector<T>\
    \ &)>\nT kitamasa(std::int64_t n, std::vector<T> a, std::vector<T> c) {\n    if\
    \ (n < (int)a.size()) return a[n];\n    const int d = c.size();\n    for (auto\
    \ &val : c) val = -val;\n    c.insert(c.begin(), 1);\n    auto p = convolution(a,\
    \ c);\n    p.resize(d);\n    return bostan_mori_algorithm<T, convolution>(n, p,\
    \ c);\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cstdint>\n#include <vector>\n\nnamespace ebi {\n\
    \ntemplate <class T, std::vector<T> (*convolution)(const std::vector<T> &,\n \
    \                                                const std::vector<T> &)>\nT bostan_mori_algorithm(std::int64_t\
    \ n, std::vector<T> p, std::vector<T> q) {\n    while (n > 0) {\n        auto\
    \ q_neg = q;\n        for (int i = 1; i < (int)q_neg.size(); i += 2) q_neg[i]\
    \ = -q_neg[i];\n        p = convolution(p, q_neg);\n        q = convolution(q,\
    \ q_neg);\n        for (int i = (n & 1LL); i < (int)p.size(); i += 2) p[i >> 1]\
    \ = p[i];\n        p.resize(((int)p.size() + 1 - (n & 1LL)) / 2);\n        for\
    \ (int i = 0; i < (int)q.size(); i += 2) q[i >> 1] = q[i];\n        q.resize(((int)q.size()\
    \ + 1) / 2);\n        n >>= 1;\n    }\n    return p[0] / q[0];\n}\n\ntemplate\
    \ <class T, std::vector<T> (*convolution)(const std::vector<T> &,\n          \
    \                                       const std::vector<T> &)>\nT kitamasa(std::int64_t\
    \ n, std::vector<T> a, std::vector<T> c) {\n    if (n < (int)a.size()) return\
    \ a[n];\n    const int d = c.size();\n    for (auto &val : c) val = -val;\n  \
    \  c.insert(c.begin(), 1);\n    auto p = convolution(a, c);\n    p.resize(d);\n\
    \    return bostan_mori_algorithm<T, convolution>(n, p, c);\n}\n\n}  // namespace\
    \ ebi\n"
  dependsOn: []
  isVerificationFile: false
  path: math/boastan_mori_algorithm.hpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
documentation_of: math/boastan_mori_algorithm.hpp
layout: document
redirect_from:
- /library/math/boastan_mori_algorithm.hpp
- /library/math/boastan_mori_algorithm.hpp.html
title: math/boastan_mori_algorithm.hpp
---