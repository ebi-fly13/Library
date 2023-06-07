---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/bit_operator.hpp
    title: utility/bit_operator.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/subset_convolution.hpp
    title: Subset Convolution
  - icon: ':heavy_check_mark:'
    path: set_function/sps_exp.hpp
    title: set_function/sps_exp.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Exp_of_Set_Power_Series.test.cpp
    title: test/Exp_of_Set_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/subset_convolution.test.cpp
    title: test/subset_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"set_function/ranked_zeta.hpp\"\n\n#include <array>\n#include\
    \ <cassert>\n#include <vector>\n\n#line 2 \"utility/bit_operator.hpp\"\n\nnamespace\
    \ ebi {\n\nconstexpr int bsf_constexpr(unsigned int n) {\n    int x = 0;\n   \
    \ while (!(n & (1 << x))) x++;\n    return x;\n}\n\nint bit_reverse(int n, int\
    \ bit_size) {\n    int rev_n = 0;\n    for (int i = 0; i < bit_size; i++) {\n\
    \        rev_n |= ((n >> i) & 1) << (bit_size - i - 1);\n    }\n    return rev_n;\n\
    }\n\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) < (unsigned\
    \ int)(n)) x++;\n    return x;\n}\n\nint popcnt(int x) {\n    return __builtin_popcount(x);\n\
    }\n\nint msb(int x) {\n    return (x == 0) ? -1 : 31 - __builtin_clz(x);\n}\n\n\
    int bsf(int x) {\n    return (x == 0) ? -1 : __builtin_ctz(x);\n}\n\n}  // namespace\
    \ ebi\n#line 8 \"set_function/ranked_zeta.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class T, int LIM = 20>\nstd::vector<std::array<T, LIM + 1>> ranked_zeta(const\
    \ std::vector<T> &f) {\n    int n = msb(f.size());\n    assert(n <= LIM);\n  \
    \  assert((int)f.size() == (1 << n));\n    std::vector<std::array<T, LIM + 1>>\
    \ rf(1 << n);\n    for (int s = 0; s < (1 << n); s++) rf[s][popcnt(s)] = f[s];\n\
    \    for (int i = 0; i < n; i++) {\n        int w = 1 << i;\n        for (int\
    \ p = 0; p < (1 << n); p += 2 * w) {\n            for (int s = p; s < p + w; s++)\
    \ {\n                int t = s | (1 << i);\n                for (int d = 0; d\
    \ <= n; d++) rf[t][d] += rf[s][d];\n            }\n        }\n    }\n    return\
    \ rf;\n}\n\ntemplate <class T, int LIM = 20>\nstd::vector<T> ranked_mobius(std::vector<std::array<T,\
    \ LIM + 1>> rf) {\n    int n = msb(rf.size());\n    assert((int)rf.size() == (1\
    \ << n));\n    for (int i = 0; i < n; i++) {\n        int w = 1 << i;\n      \
    \  for (int p = 0; p < (1 << n); p += 2 * w) {\n            for (int s = p; s\
    \ < p + w; s++) {\n                int t = s | (1 << i);\n                for\
    \ (int d = 0; d <= n; d++) rf[t][d] -= rf[s][d];\n            }\n        }\n \
    \   }\n    std::vector<T> f(1 << n);\n    for (int s = 0; s < (1 << n); s++) {\n\
    \        f[s] = rf[s][popcnt(s)];\n    }\n    return f;\n}\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <array>\n#include <cassert>\n#include <vector>\n\
    \n#include \"../utility/bit_operator.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ T, int LIM = 20>\nstd::vector<std::array<T, LIM + 1>> ranked_zeta(const std::vector<T>\
    \ &f) {\n    int n = msb(f.size());\n    assert(n <= LIM);\n    assert((int)f.size()\
    \ == (1 << n));\n    std::vector<std::array<T, LIM + 1>> rf(1 << n);\n    for\
    \ (int s = 0; s < (1 << n); s++) rf[s][popcnt(s)] = f[s];\n    for (int i = 0;\
    \ i < n; i++) {\n        int w = 1 << i;\n        for (int p = 0; p < (1 << n);\
    \ p += 2 * w) {\n            for (int s = p; s < p + w; s++) {\n             \
    \   int t = s | (1 << i);\n                for (int d = 0; d <= n; d++) rf[t][d]\
    \ += rf[s][d];\n            }\n        }\n    }\n    return rf;\n}\n\ntemplate\
    \ <class T, int LIM = 20>\nstd::vector<T> ranked_mobius(std::vector<std::array<T,\
    \ LIM + 1>> rf) {\n    int n = msb(rf.size());\n    assert((int)rf.size() == (1\
    \ << n));\n    for (int i = 0; i < n; i++) {\n        int w = 1 << i;\n      \
    \  for (int p = 0; p < (1 << n); p += 2 * w) {\n            for (int s = p; s\
    \ < p + w; s++) {\n                int t = s | (1 << i);\n                for\
    \ (int d = 0; d <= n; d++) rf[t][d] -= rf[s][d];\n            }\n        }\n \
    \   }\n    std::vector<T> f(1 << n);\n    for (int s = 0; s < (1 << n); s++) {\n\
    \        f[s] = rf[s][popcnt(s)];\n    }\n    return f;\n}\n\n}  // namespace\
    \ ebi\n"
  dependsOn:
  - utility/bit_operator.hpp
  isVerificationFile: false
  path: set_function/ranked_zeta.hpp
  requiredBy:
  - set_function/sps_exp.hpp
  - convolution/subset_convolution.hpp
  timestamp: '2023-05-17 17:05:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Exp_of_Set_Power_Series.test.cpp
  - test/subset_convolution.test.cpp
documentation_of: set_function/ranked_zeta.hpp
layout: document
redirect_from:
- /library/set_function/ranked_zeta.hpp
- /library/set_function/ranked_zeta.hpp.html
title: set_function/ranked_zeta.hpp
---
