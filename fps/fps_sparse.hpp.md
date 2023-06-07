---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: utility/modint_func.hpp
    title: modint function
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/fps_sparse.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \n#line 2 \"utility/modint_func.hpp\"\n\n#line 5 \"utility/modint_func.hpp\"\n\
    \nnamespace ebi {\n\ntemplate <class mint> mint inv(int n) {\n    static const\
    \ int mod = mint::mod();\n    static std::vector<mint> dat = {0, 1};\n    assert(0\
    \ <= n);\n    if (n >= mod) n -= mod;\n    while (int(dat.size()) <= n) {\n  \
    \      int num = dat.size();\n        int q = (mod + num - 1) / num;\n       \
    \ dat.emplace_back(dat[num * q - mod] * mint(q));\n    }\n    return dat[n];\n\
    }\n\n}  // namespace ebi\n#line 7 \"fps/fps_sparse.hpp\"\n\nnamespace ebi {\n\n\
    template <class mint>\nstd::vector<mint> inv_sparse(const std::vector<mint> &f,\
    \ int d = -1) {\n    assert(f[0] != 0);\n    if (d < 0) {\n        d = f.size();\n\
    \    }\n    std::vector<std::pair<int, mint>> ret;\n    for (int i = 1; i < int(f.size());\
    \ i++) {\n        if (f[i] != 0) {\n            ret.emplace_back(i, f[i]);\n \
    \       }\n    }\n    std::vector<mint> g(d);\n    g[0] = f[0].inv();\n    for\
    \ (int i = 1; i < d; i++) {\n        for (auto [k, p] : ret) {\n            if\
    \ (i - k < 0) break;\n            g[i] -= g[i - k] * p;\n        }\n        g[i]\
    \ *= g[0];\n    }\n    return g;\n}\n\ntemplate <class mint>\nstd::vector<mint>\
    \ pow_sparse_1(const std::vector<mint> &f, long long k,\n                    \
    \           int d = -1) {\n    int n = f.size();\n    assert(n == 0 || f[0] ==\
    \ 1);\n    std::vector<std::pair<int, mint>> ret;\n    for (int i = 1; i < n;\
    \ i++) {\n        if (f[i] != 0) ret.emplace_back(i, f[i]);\n    }\n    std::vector<mint>\
    \ g(d);\n    g[0] = 1;\n    for (int i = 0; i < d - 1; i++) {\n        for (const\
    \ auto &[j, cf] : ret) {\n            if (i + 1 - j < 0) break;\n            g[i\
    \ + 1] +=\n                (mint(k) * mint(j) - mint(i - j + 1)) * cf * g[i +\
    \ 1 - j];\n        }\n        g[i + 1] *= inv<mint>(i + 1);\n    }\n    return\
    \ g;\n}\n\ntemplate <class mint>\nstd::vector<mint> pow_sparse(const std::vector<mint>\
    \ &f, long long k,\n                             int d = -1) {\n    int n = f.size();\n\
    \    if (d < 0) d = n;\n    assert(k >= 0);\n    if (k == 0) {\n        std::vector<mint>\
    \ g(d);\n        if (d > 0) g[0] = 1;\n        return g;\n    }\n    for (int\
    \ i = 0; i < n; i++) {\n        if (f[i] != 0) {\n            mint rev = f[i].inv();\n\
    \            std::vector<mint> f2(n - i);\n            for (int j = i; j < n;\
    \ j++) {\n                f2[j - i] = f[j] * rev;\n            }\n           \
    \ f2 = pow_sparse_1(f2, k, d);\n            mint fk = f[i].pow(k);\n         \
    \   std::vector<mint> g(d);\n            for (int j = 0; j < int(f2.size()); j++)\
    \ {\n                if (j + i * k >= d) break;\n                g[j + i * k]\
    \ = f2[j] * fk;\n            }\n            return g;\n        }\n        if (i\
    \ >= (d + k - 1) / k) break;\n    }\n    return std::vector<mint>(d);\n}\n\n}\
    \  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../utility/modint_func.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class mint>\nstd::vector<mint> inv_sparse(const\
    \ std::vector<mint> &f, int d = -1) {\n    assert(f[0] != 0);\n    if (d < 0)\
    \ {\n        d = f.size();\n    }\n    std::vector<std::pair<int, mint>> ret;\n\
    \    for (int i = 1; i < int(f.size()); i++) {\n        if (f[i] != 0) {\n   \
    \         ret.emplace_back(i, f[i]);\n        }\n    }\n    std::vector<mint>\
    \ g(d);\n    g[0] = f[0].inv();\n    for (int i = 1; i < d; i++) {\n        for\
    \ (auto [k, p] : ret) {\n            if (i - k < 0) break;\n            g[i] -=\
    \ g[i - k] * p;\n        }\n        g[i] *= g[0];\n    }\n    return g;\n}\n\n\
    template <class mint>\nstd::vector<mint> pow_sparse_1(const std::vector<mint>\
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
    \  // namespace ebi"
  dependsOn:
  - utility/modint_func.hpp
  isVerificationFile: false
  path: fps/fps_sparse.hpp
  requiredBy: []
  timestamp: '2023-06-08 01:58:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
documentation_of: fps/fps_sparse.hpp
layout: document
title: Formal Power Series (Sparse)
---

## inv_sparse(std::vector<mint> f, int d)

$f^{-1} \mod x^d$ を求める。$f$ の非ゼロの項を $M$ 個として $O(NM)$

## pow_sparse(std::vector<mint> f, long long k, int d)

$f^k \mod x^d$ を求める。$f$ の非ゼロの項を $M$ 個として $O(NM)$

## pow_sparse_1(std::vector<mint> f, long long k, int d)

$[x^0]f = 1$ であるような $f$ に対して $f^k \mod x^d$ を求める。$k$ が負でも動作する。$f$ の非ゼロの項を $M$ 個として $O(NM)$