---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/subset_convolution.hpp
    title: Subset Convolution
  - icon: ':question:'
    path: set_function/ranked_subset_transform.hpp
    title: Ranked Subset Transform (Zeta / Mobius)
  - icon: ':question:'
    path: utility/bit_operator.hpp
    title: utility/bit_operator.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: set_function/poly_composite_sps.hpp
    title: $f(a)$ (Set Power Series, f is FPS)
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/set_function/Polynomial_Composite_Set_Power_Series.test.cpp
    title: test/set_function/Polynomial_Composite_Set_Power_Series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"set_function/egf_composite_sps.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n#line 2 \"convolution/subset_convolution.hpp\"\n\r\n/*\r\n\
    \    refernce: https://www.slideshare.net/wata_orz/ss-12131479\r\n           \
    \   https://37zigen.com/subset-convolution/\r\n*/\r\n\r\n#include <array>\r\n\
    #line 11 \"convolution/subset_convolution.hpp\"\n\r\n#line 2 \"set_function/ranked_subset_transform.hpp\"\
    \n\n#line 6 \"set_function/ranked_subset_transform.hpp\"\n\n#line 2 \"utility/bit_operator.hpp\"\
    \n\nnamespace ebi {\n\nconstexpr int bsf_constexpr(unsigned int n) {\n    int\
    \ x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n}\n\nint bit_reverse(int\
    \ n, int bit_size) {\n    int rev_n = 0;\n    for (int i = 0; i < bit_size; i++)\
    \ {\n        rev_n |= ((n >> i) & 1) << (bit_size - i - 1);\n    }\n    return\
    \ rev_n;\n}\n\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) <\
    \ (unsigned int)(n)) x++;\n    return x;\n}\n\nint popcnt(int x) {\n    return\
    \ __builtin_popcount(x);\n}\n\nint msb(int x) {\n    return (x == 0) ? -1 : 31\
    \ - __builtin_clz(x);\n}\n\nint bsf(int x) {\n    return (x == 0) ? -1 : __builtin_ctz(x);\n\
    }\n\n}  // namespace ebi\n#line 8 \"set_function/ranked_subset_transform.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T, int LIM = 20>\nstd::vector<std::array<T,\
    \ LIM + 1>> ranked_zeta(const std::vector<T> &f) {\n    int n = msb(f.size());\n\
    \    assert(n <= LIM);\n    assert((int)f.size() == (1 << n));\n    std::vector<std::array<T,\
    \ LIM + 1>> rf(1 << n);\n    for (int s = 0; s < (1 << n); s++) rf[s][popcnt(s)]\
    \ = f[s];\n    for (int i = 0; i < n; i++) {\n        int w = 1 << i;\n      \
    \  for (int p = 0; p < (1 << n); p += 2 * w) {\n            for (int s = p; s\
    \ < p + w; s++) {\n                int t = s | (1 << i);\n                for\
    \ (int d = 0; d <= n; d++) rf[t][d] += rf[s][d];\n            }\n        }\n \
    \   }\n    return rf;\n}\n\ntemplate <class T, int LIM = 20>\nstd::vector<T> ranked_mobius(std::vector<std::array<T,\
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
    \ LIM>(ra);\r\n}\r\n\r\n}  // namespace ebi\n#line 8 \"set_function/egf_composite_sps.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T, int LIM>\nstd::vector<T> egf_composite_sps(const\
    \ std::vector<T> &a, std::vector<T> egf) {\n    int n = msb(a.size());\n    assert(n\
    \ <= LIM);\n    assert((int)a.size() == (1 << n) && a[0] == T(0));\n    if ((int)egf.size()\
    \ > n) egf.resize(n + 1);\n    int d = egf.size() - 1;\n    std::vector<T> f(1\
    \ << n);\n    f[0] = egf[d];\n    for (int k = d - 1; k >= 0; k--) {\n       \
    \ std::vector<T> fk(1 << n);\n        fk[0] = egf[k];\n        for (int i = 0;\
    \ i < n - k; i++) {\n            std::vector<T> s = {a.begin() + (1 << i), a.begin()\
    \ + (2 << i)};\n            std::vector<T> t = {f.begin(), f.begin() + (1 << i)};\n\
    \            auto c = subset_convolution<T, LIM>(s, t);\n            std::copy(c.begin(),\
    \ c.end(), fk.begin() + (1 << i));\n        }\n        f = fk;\n    }\n    return\
    \ f;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../convolution/subset_convolution.hpp\"\
    \n#include \"../utility/bit_operator.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ T, int LIM>\nstd::vector<T> egf_composite_sps(const std::vector<T> &a, std::vector<T>\
    \ egf) {\n    int n = msb(a.size());\n    assert(n <= LIM);\n    assert((int)a.size()\
    \ == (1 << n) && a[0] == T(0));\n    if ((int)egf.size() > n) egf.resize(n + 1);\n\
    \    int d = egf.size() - 1;\n    std::vector<T> f(1 << n);\n    f[0] = egf[d];\n\
    \    for (int k = d - 1; k >= 0; k--) {\n        std::vector<T> fk(1 << n);\n\
    \        fk[0] = egf[k];\n        for (int i = 0; i < n - k; i++) {\n        \
    \    std::vector<T> s = {a.begin() + (1 << i), a.begin() + (2 << i)};\n      \
    \      std::vector<T> t = {f.begin(), f.begin() + (1 << i)};\n            auto\
    \ c = subset_convolution<T, LIM>(s, t);\n            std::copy(c.begin(), c.end(),\
    \ fk.begin() + (1 << i));\n        }\n        f = fk;\n    }\n    return f;\n\
    }\n\n}  // namespace ebi"
  dependsOn:
  - convolution/subset_convolution.hpp
  - set_function/ranked_subset_transform.hpp
  - utility/bit_operator.hpp
  isVerificationFile: false
  path: set_function/egf_composite_sps.hpp
  requiredBy:
  - set_function/poly_composite_sps.hpp
  timestamp: '2023-07-15 15:32:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/set_function/Polynomial_Composite_Set_Power_Series.test.cpp
documentation_of: set_function/egf_composite_sps.hpp
layout: document
title: $f(a)$ (Set Power Series, f is EGF)
---

## 説明

$f$ を指数型母関数 (EGF)として、 集合べき級数 $a$ を $f(x)$ に代入する。つまり、$f(a)$ を求める。 $O(N^2 \log N)$