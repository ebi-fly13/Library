---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/subset_convolution.hpp
    title: Subset Convolution
  - icon: ':heavy_check_mark:'
    path: set_function/egf_composite_sps.hpp
    title: $f(a)$ (Set Power Series, f is EGF)
  - icon: ':heavy_check_mark:'
    path: set_function/exp_of_sps.hpp
    title: $\exp {a}$ (Set Power Series)
  - icon: ':heavy_check_mark:'
    path: set_function/poly_composite_sps.hpp
    title: $f(a)$ (Set Power Series, f is FPS)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/Subset_Convolution.test.cpp
    title: test/convolution/Subset_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/set_function/Exp_of_Set_Power_Series.test.cpp
    title: test/set_function/Exp_of_Set_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/set_function/Polynomial_Composite_Set_Power_Series.test.cpp
    title: test/set_function/Polynomial_Composite_Set_Power_Series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"set_function/ranked_subset_transform.hpp\"\n\n#include <array>\n\
    #include <bit>\n#include <cassert>\n#include <vector>\n\nnamespace ebi {\n\ntemplate\
    \ <class T, int LIM = 20>\nstd::vector<std::array<T, LIM + 1>> ranked_zeta(const\
    \ std::vector<T> &f) {\n    int n = std::bit_width(f.size()) - 1;\n    assert(n\
    \ <= LIM);\n    assert((int)f.size() == (1 << n));\n    std::vector<std::array<T,\
    \ LIM + 1>> rf(1 << n);\n    for (int s = 0; s < (1 << n); s++)\n        rf[s][std::popcount((unsigned\
    \ int)(s))] = f[s];\n    for (int i = 0; i < n; i++) {\n        int w = 1 << i;\n\
    \        for (int p = 0; p < (1 << n); p += 2 * w) {\n            for (int s =\
    \ p; s < p + w; s++) {\n                int t = s | (1 << i);\n              \
    \  for (int d = 0; d <= n; d++) rf[t][d] += rf[s][d];\n            }\n       \
    \ }\n    }\n    return rf;\n}\n\ntemplate <class T, int LIM = 20>\nstd::vector<T>\
    \ ranked_mobius(std::vector<std::array<T, LIM + 1>> rf) {\n    int n = std::bit_width(rf.size())\
    \ - 1;\n    assert((int)rf.size() == (1 << n));\n    for (int i = 0; i < n; i++)\
    \ {\n        int w = 1 << i;\n        for (int p = 0; p < (1 << n); p += 2 * w)\
    \ {\n            for (int s = p; s < p + w; s++) {\n                int t = s\
    \ | (1 << i);\n                for (int d = 0; d <= n; d++) rf[t][d] -= rf[s][d];\n\
    \            }\n        }\n    }\n    std::vector<T> f(1 << n);\n    for (int\
    \ s = 0; s < (1 << n); s++) {\n        f[s] = rf[s][std::popcount((unsigned int)(s))];\n\
    \    }\n    return f;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <array>\n#include <bit>\n#include <cassert>\n#include\
    \ <vector>\n\nnamespace ebi {\n\ntemplate <class T, int LIM = 20>\nstd::vector<std::array<T,\
    \ LIM + 1>> ranked_zeta(const std::vector<T> &f) {\n    int n = std::bit_width(f.size())\
    \ - 1;\n    assert(n <= LIM);\n    assert((int)f.size() == (1 << n));\n    std::vector<std::array<T,\
    \ LIM + 1>> rf(1 << n);\n    for (int s = 0; s < (1 << n); s++)\n        rf[s][std::popcount((unsigned\
    \ int)(s))] = f[s];\n    for (int i = 0; i < n; i++) {\n        int w = 1 << i;\n\
    \        for (int p = 0; p < (1 << n); p += 2 * w) {\n            for (int s =\
    \ p; s < p + w; s++) {\n                int t = s | (1 << i);\n              \
    \  for (int d = 0; d <= n; d++) rf[t][d] += rf[s][d];\n            }\n       \
    \ }\n    }\n    return rf;\n}\n\ntemplate <class T, int LIM = 20>\nstd::vector<T>\
    \ ranked_mobius(std::vector<std::array<T, LIM + 1>> rf) {\n    int n = std::bit_width(rf.size())\
    \ - 1;\n    assert((int)rf.size() == (1 << n));\n    for (int i = 0; i < n; i++)\
    \ {\n        int w = 1 << i;\n        for (int p = 0; p < (1 << n); p += 2 * w)\
    \ {\n            for (int s = p; s < p + w; s++) {\n                int t = s\
    \ | (1 << i);\n                for (int d = 0; d <= n; d++) rf[t][d] -= rf[s][d];\n\
    \            }\n        }\n    }\n    std::vector<T> f(1 << n);\n    for (int\
    \ s = 0; s < (1 << n); s++) {\n        f[s] = rf[s][std::popcount((unsigned int)(s))];\n\
    \    }\n    return f;\n}\n\n}  // namespace ebi\n"
  dependsOn: []
  isVerificationFile: false
  path: set_function/ranked_subset_transform.hpp
  requiredBy:
  - set_function/egf_composite_sps.hpp
  - set_function/poly_composite_sps.hpp
  - set_function/exp_of_sps.hpp
  - convolution/subset_convolution.hpp
  timestamp: '2023-10-31 00:17:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/set_function/Polynomial_Composite_Set_Power_Series.test.cpp
  - test/set_function/Exp_of_Set_Power_Series.test.cpp
  - test/convolution/Subset_Convolution.test.cpp
documentation_of: set_function/ranked_subset_transform.hpp
layout: document
title: Ranked Subset Transform (Zeta / Mobius)
---

## 説明

重み付きゼータ変換 / メビウス変換を行う。 $O(N^2\log N)$