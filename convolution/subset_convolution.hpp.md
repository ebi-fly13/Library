---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: set_function/ranked_subset_transform.hpp
    title: Ranked Subset Transform (Zeta / Mobius)
  _extendedRequiredBy:
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
    links:
    - https://37zigen.com/subset-convolution/
    - https://www.slideshare.net/wata_orz/ss-12131479
  bundledCode: "#line 2 \"convolution/subset_convolution.hpp\"\n\r\n/*\r\n    refernce:\
    \ https://www.slideshare.net/wata_orz/ss-12131479\r\n              https://37zigen.com/subset-convolution/\r\
    \n*/\r\n\r\n#include <array>\r\n#include <bit>\r\n#include <cassert>\r\n#include\
    \ <vector>\r\n\r\n#line 2 \"set_function/ranked_subset_transform.hpp\"\n\n#line\
    \ 7 \"set_function/ranked_subset_transform.hpp\"\n\nnamespace ebi {\n\ntemplate\
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
    \    }\n    return f;\n}\n\n}  // namespace ebi\n#line 14 \"convolution/subset_convolution.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class T, int LIM = 20>\r\nstd::vector<T>\
    \ subset_convolution(const std::vector<T> &a,\r\n                            \
    \      const std::vector<T> &b) {\r\n    auto ra = ranked_zeta<T, LIM>(a);\r\n\
    \    auto rb = ranked_zeta<T, LIM>(b);\r\n    int n = std::bit_width(a.size())\
    \ - 1;\r\n    for (int s = (1 << n) - 1; s >= 0; s--) {\r\n        auto &f = ra[s];\r\
    \n        const auto &g = rb[s];\r\n        for (int d = n; d >= 0; d--) {\r\n\
    \            T x = 0;\r\n            for (int i = 0; i <= d; i++) {\r\n      \
    \          x += f[i] * g[d - i];\r\n            }\r\n            f[d] = x;\r\n\
    \        }\r\n    }\r\n    return ranked_mobius<T, LIM>(ra);\r\n}\r\n\r\n}  //\
    \ namespace ebi\n"
  code: "#pragma once\r\n\r\n/*\r\n    refernce: https://www.slideshare.net/wata_orz/ss-12131479\r\
    \n              https://37zigen.com/subset-convolution/\r\n*/\r\n\r\n#include\
    \ <array>\r\n#include <bit>\r\n#include <cassert>\r\n#include <vector>\r\n\r\n\
    #include \"../set_function/ranked_subset_transform.hpp\"\r\n\r\nnamespace ebi\
    \ {\r\n\r\ntemplate <class T, int LIM = 20>\r\nstd::vector<T> subset_convolution(const\
    \ std::vector<T> &a,\r\n                                  const std::vector<T>\
    \ &b) {\r\n    auto ra = ranked_zeta<T, LIM>(a);\r\n    auto rb = ranked_zeta<T,\
    \ LIM>(b);\r\n    int n = std::bit_width(a.size()) - 1;\r\n    for (int s = (1\
    \ << n) - 1; s >= 0; s--) {\r\n        auto &f = ra[s];\r\n        const auto\
    \ &g = rb[s];\r\n        for (int d = n; d >= 0; d--) {\r\n            T x = 0;\r\
    \n            for (int i = 0; i <= d; i++) {\r\n                x += f[i] * g[d\
    \ - i];\r\n            }\r\n            f[d] = x;\r\n        }\r\n    }\r\n  \
    \  return ranked_mobius<T, LIM>(ra);\r\n}\r\n\r\n}  // namespace ebi"
  dependsOn:
  - set_function/ranked_subset_transform.hpp
  isVerificationFile: false
  path: convolution/subset_convolution.hpp
  requiredBy:
  - set_function/egf_composite_sps.hpp
  - set_function/poly_composite_sps.hpp
  - set_function/exp_of_sps.hpp
  timestamp: '2023-10-31 00:17:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/Subset_Convolution.test.cpp
  - test/set_function/Exp_of_Set_Power_Series.test.cpp
  - test/set_function/Polynomial_Composite_Set_Power_Series.test.cpp
documentation_of: convolution/subset_convolution.hpp
layout: document
title: Subset Convolution
---

## 説明

長さ $2^N$ の整数列 $a$ と $b$ について、 $c_k = \sum_{i\& j=0, i|j=k} a_i b_j$ を求める。
$O(N^2 2^N)$