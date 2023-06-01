---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/subset_convolution.hpp
    title: Subset Convolution
  - icon: ':heavy_check_mark:'
    path: set_function/ranked_zeta.hpp
    title: set_function/ranked_zeta.hpp
  - icon: ':heavy_check_mark:'
    path: utility/bit_operator.hpp
    title: utility/bit_operator.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Exp_of_Set_Power_Series.test.cpp
    title: test/Exp_of_Set_Power_Series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"set_function/sps_exp.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\n#line 2 \"convolution/subset_convolution.hpp\"\n\r\n/*\r\n    refernce:\
    \ https://www.slideshare.net/wata_orz/ss-12131479\r\n              https://37zigen.com/subset-convolution/\r\
    \n*/\r\n\r\n#include <array>\r\n#line 11 \"convolution/subset_convolution.hpp\"\
    \n\r\n#line 2 \"set_function/ranked_zeta.hpp\"\n\n#line 6 \"set_function/ranked_zeta.hpp\"\
    \n\n#line 2 \"utility/bit_operator.hpp\"\n\nnamespace ebi {\n\nconstexpr int bsf_constexpr(unsigned\
    \ int n) {\n    int x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n\
    }\n\nint bit_reverse(int n, int bit_size) {\n    int rev_n = 0;\n    for (int\
    \ i = 0; i < bit_size; i++) {\n        rev_n |= ((n >> i) & 1) << (bit_size -\
    \ i - 1);\n    }\n    return rev_n;\n}\n\nint ceil_pow2(int n) {\n    int x =\
    \ 0;\n    while ((1U << x) < (unsigned int)(n)) x++;\n    return x;\n}\n\nint\
    \ popcnt(int x) {\n    return __builtin_popcount(x);\n}\n\nint msb(int x) {\n\
    \    return (x == 0) ? -1 : 31 - __builtin_clz(x);\n}\n\nint bsf(int x) {\n  \
    \  return (x == 0) ? -1 : __builtin_ctz(x);\n}\n\n}  // namespace ebi\n#line 8\
    \ \"set_function/ranked_zeta.hpp\"\n\nnamespace ebi {\n\ntemplate <class T, int\
    \ LIM = 20>\nstd::vector<std::array<T, LIM + 1>> ranked_zeta(const std::vector<T>\
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
    \ ebi\n#line 14 \"convolution/subset_convolution.hpp\"\n\r\nnamespace ebi {\r\n\
    \r\ntemplate <class T, int LIM = 20>\r\nstd::vector<T> subset_convolution(const\
    \ std::vector<T> &a,\r\n                                  const std::vector<T>\
    \ &b) {\r\n    auto ra = ranked_zeta<T, LIM>(a);\r\n    auto rb = ranked_zeta<T,\
    \ LIM>(b);\r\n    int n = msb(ra.size());\r\n    for (int s = (1 << n) - 1; s\
    \ >= 0; s--) {\r\n        auto &f = ra[s];\r\n        const auto &g = rb[s];\r\
    \n        for (int d = n; d >= 0; d--) {\r\n            T x = 0;\r\n         \
    \   for (int i = 0; i <= d; i++) {\r\n                x += f[i] * g[d - i];\r\n\
    \            }\r\n            f[d] = x;\r\n        }\r\n    }\r\n    return ranked_mobius<T,\
    \ LIM>(ra);\r\n}\r\n\r\n}  // namespace ebi\n#line 8 \"set_function/sps_exp.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T, int LIM> std::vector<T> sps_exp(const\
    \ std::vector<T> &s) {\n    int n = msb(s.size());\n    assert(n <= LIM);\n  \
    \  assert((int)s.size() == (1 << n));\n    std::vector<T> fs(1 << n);\n    fs[0]\
    \ = T(1);\n    for (int i = 0; i < n; i++) {\n        std::vector<T> a = {s.begin()\
    \ + (1 << i), s.begin() + (2 << i)};\n        std::vector<T> b = {fs.begin(),\
    \ fs.begin() + (1 << i)};\n        a = subset_convolution<T, LIM>(a, b);\n   \
    \     std::copy(a.begin(), a.end(), fs.begin() + (1 << i));\n    }\n    return\
    \ fs;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../convolution/subset_convolution.hpp\"\
    \n#include \"../utility/bit_operator.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ T, int LIM> std::vector<T> sps_exp(const std::vector<T> &s) {\n    int n = msb(s.size());\n\
    \    assert(n <= LIM);\n    assert((int)s.size() == (1 << n));\n    std::vector<T>\
    \ fs(1 << n);\n    fs[0] = T(1);\n    for (int i = 0; i < n; i++) {\n        std::vector<T>\
    \ a = {s.begin() + (1 << i), s.begin() + (2 << i)};\n        std::vector<T> b\
    \ = {fs.begin(), fs.begin() + (1 << i)};\n        a = subset_convolution<T, LIM>(a,\
    \ b);\n        std::copy(a.begin(), a.end(), fs.begin() + (1 << i));\n    }\n\
    \    return fs;\n}\n\n}  // namespace ebi"
  dependsOn:
  - convolution/subset_convolution.hpp
  - set_function/ranked_zeta.hpp
  - utility/bit_operator.hpp
  isVerificationFile: false
  path: set_function/sps_exp.hpp
  requiredBy: []
  timestamp: '2023-05-17 17:05:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Exp_of_Set_Power_Series.test.cpp
documentation_of: set_function/sps_exp.hpp
layout: document
redirect_from:
- /library/set_function/sps_exp.hpp
- /library/set_function/sps_exp.hpp.html
title: set_function/sps_exp.hpp
---