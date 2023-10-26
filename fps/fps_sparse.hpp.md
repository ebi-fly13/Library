---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/mod_inv.hpp
    title: math/mod_inv.hpp
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: fps/fps_sqrt.hpp
    title: $\sqrt{f}$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_3361.test.cpp
    title: test/aoj/aoj_3361.test.cpp
  - icon: ':x:'
    path: test/polynomial/Exp_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Exp_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':x:'
    path: test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':x:'
    path: test/polynomial/Log_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Log_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':x:'
    path: test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':x:'
    path: test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - icon: ':x:'
    path: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/fps_sparse.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \n#line 2 \"math/mod_inv.hpp\"\n\n#line 5 \"math/mod_inv.hpp\"\n\n#line 2 \"modint/base.hpp\"\
    \n\n#include <concepts>\n#include <iostream>\n#include <utility>\n\nnamespace\
    \ ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n    a +\
    \ b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 7 \"\
    math/mod_inv.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint> mint inv(int n)\
    \ {\n    static const int mod = mint::mod();\n    static std::vector<mint> dat\
    \ = {0, 1};\n    assert(0 <= n);\n    if (n >= mod) n -= mod;\n    while (int(dat.size())\
    \ <= n) {\n        int num = dat.size();\n        int q = (mod + num - 1) / num;\n\
    \        dat.emplace_back(dat[num * q - mod] * mint(q));\n    }\n    return dat[n];\n\
    }\n\n}  // namespace ebi\n#line 8 \"fps/fps_sparse.hpp\"\n\nnamespace ebi {\n\n\
    template <Modint mint>\nstd::vector<mint> mul_sparse(const std::vector<mint> &f,\n\
    \                             const std::vector<mint> &g) {\n    int n = f.size();\n\
    \    int m = g.size();\n    std::vector<std::pair<int, mint>> cf, cg;\n    for\
    \ (int i = 0; i < n; i++) {\n        if (f[i] != 0) cf.emplace_back(i, f[i]);\n\
    \    }\n    for (int i = 0; i < m; i++) {\n        if (g[i] != 0) cg.emplace_back(i,\
    \ g[i]);\n    }\n    std::vector<mint> h(n + m - 1);\n    for (auto [i, p] : cf)\
    \ {\n        for (auto [j, q] : cg) {\n            h[i + j] += p * q;\n      \
    \  }\n    }\n    return h;\n}\n\ntemplate <Modint mint>\nstd::vector<mint> inv_sparse(const\
    \ std::vector<mint> &f, int d = -1) {\n    assert(f[0] != 0);\n    if (d < 0)\
    \ {\n        d = f.size();\n    }\n    std::vector<std::pair<int, mint>> ret;\n\
    \    for (int i = 1; i < int(f.size()); i++) {\n        if (f[i] != 0) {\n   \
    \         ret.emplace_back(i, f[i]);\n        }\n    }\n    std::vector<mint>\
    \ g(d);\n    g[0] = f[0].inv();\n    for (int i = 1; i < d; i++) {\n        for\
    \ (auto [k, p] : ret) {\n            if (i - k < 0) break;\n            g[i] -=\
    \ g[i - k] * p;\n        }\n        g[i] *= g[0];\n    }\n    return g;\n}\n\n\
    template <Modint mint>\nstd::vector<mint> exp_sparse(const std::vector<mint> &f,\
    \ int d = -1) {\n    int n = f.size();\n    if (d < 0) d = n;\n    std::vector<std::pair<int,\
    \ mint>> ret;\n    for (int i = 1; i < n; i++) {\n        if (f[i] != 0) {\n \
    \           ret.emplace_back(i - 1, f[i] * i);\n        }\n    }\n    std::vector<mint>\
    \ g(d);\n    g[0] = 1;\n    for (int i = 0; i < d - 1; i++) {\n        for (auto\
    \ [k, p] : ret) {\n            if (i - k < 0) break;\n            g[i + 1] +=\
    \ g[i - k] * p;\n        }\n        g[i + 1] *= inv<mint>(i + 1);\n    }\n   \
    \ return g;\n}\n\ntemplate <Modint mint>\nstd::vector<mint> log_sparse(const std::vector<mint>\
    \ &f, int d = -1) {\n    int n = f.size();\n    if (d < 0) d = n;\n    std::vector<mint>\
    \ df(d);\n    for (int i = 0; i < std::min(d, n - 1); i++) {\n        df[i] =\
    \ f[i + 1] * (i + 1);\n    }\n    auto dg = mul_sparse(df, inv_sparse(f));\n \
    \   dg.resize(d);\n    std::vector<mint> g(d);\n    for (int i = 0; i < d - 1;\
    \ i++) {\n        g[i + 1] = dg[i] * inv<mint>(i + 1);\n    }\n    return g;\n\
    }\n\ntemplate <Modint mint>\nstd::vector<mint> pow_sparse_1(const std::vector<mint>\
    \ &f, long long k,\n                               int d = -1) {\n    int n =\
    \ f.size();\n    assert(n == 0 || f[0] == 1);\n    std::vector<std::pair<int,\
    \ mint>> ret;\n    for (int i = 1; i < n; i++) {\n        if (f[i] != 0) ret.emplace_back(i,\
    \ f[i]);\n    }\n    std::vector<mint> g(d);\n    g[0] = 1;\n    for (int i =\
    \ 0; i < d - 1; i++) {\n        for (const auto &[j, cf] : ret) {\n          \
    \  if (i + 1 - j < 0) break;\n            g[i + 1] +=\n                (mint(k)\
    \ * mint(j) - mint(i - j + 1)) * cf * g[i + 1 - j];\n        }\n        g[i +\
    \ 1] *= inv<mint>(i + 1);\n    }\n    return g;\n}\n\ntemplate <Modint mint>\n\
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
    \  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../math/mod_inv.hpp\"\
    \n#include \"../modint/base.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint>\n\
    std::vector<mint> mul_sparse(const std::vector<mint> &f,\n                   \
    \          const std::vector<mint> &g) {\n    int n = f.size();\n    int m = g.size();\n\
    \    std::vector<std::pair<int, mint>> cf, cg;\n    for (int i = 0; i < n; i++)\
    \ {\n        if (f[i] != 0) cf.emplace_back(i, f[i]);\n    }\n    for (int i =\
    \ 0; i < m; i++) {\n        if (g[i] != 0) cg.emplace_back(i, g[i]);\n    }\n\
    \    std::vector<mint> h(n + m - 1);\n    for (auto [i, p] : cf) {\n        for\
    \ (auto [j, q] : cg) {\n            h[i + j] += p * q;\n        }\n    }\n   \
    \ return h;\n}\n\ntemplate <Modint mint>\nstd::vector<mint> inv_sparse(const std::vector<mint>\
    \ &f, int d = -1) {\n    assert(f[0] != 0);\n    if (d < 0) {\n        d = f.size();\n\
    \    }\n    std::vector<std::pair<int, mint>> ret;\n    for (int i = 1; i < int(f.size());\
    \ i++) {\n        if (f[i] != 0) {\n            ret.emplace_back(i, f[i]);\n \
    \       }\n    }\n    std::vector<mint> g(d);\n    g[0] = f[0].inv();\n    for\
    \ (int i = 1; i < d; i++) {\n        for (auto [k, p] : ret) {\n            if\
    \ (i - k < 0) break;\n            g[i] -= g[i - k] * p;\n        }\n        g[i]\
    \ *= g[0];\n    }\n    return g;\n}\n\ntemplate <Modint mint>\nstd::vector<mint>\
    \ exp_sparse(const std::vector<mint> &f, int d = -1) {\n    int n = f.size();\n\
    \    if (d < 0) d = n;\n    std::vector<std::pair<int, mint>> ret;\n    for (int\
    \ i = 1; i < n; i++) {\n        if (f[i] != 0) {\n            ret.emplace_back(i\
    \ - 1, f[i] * i);\n        }\n    }\n    std::vector<mint> g(d);\n    g[0] = 1;\n\
    \    for (int i = 0; i < d - 1; i++) {\n        for (auto [k, p] : ret) {\n  \
    \          if (i - k < 0) break;\n            g[i + 1] += g[i - k] * p;\n    \
    \    }\n        g[i + 1] *= inv<mint>(i + 1);\n    }\n    return g;\n}\n\ntemplate\
    \ <Modint mint>\nstd::vector<mint> log_sparse(const std::vector<mint> &f, int\
    \ d = -1) {\n    int n = f.size();\n    if (d < 0) d = n;\n    std::vector<mint>\
    \ df(d);\n    for (int i = 0; i < std::min(d, n - 1); i++) {\n        df[i] =\
    \ f[i + 1] * (i + 1);\n    }\n    auto dg = mul_sparse(df, inv_sparse(f));\n \
    \   dg.resize(d);\n    std::vector<mint> g(d);\n    for (int i = 0; i < d - 1;\
    \ i++) {\n        g[i + 1] = dg[i] * inv<mint>(i + 1);\n    }\n    return g;\n\
    }\n\ntemplate <Modint mint>\nstd::vector<mint> pow_sparse_1(const std::vector<mint>\
    \ &f, long long k,\n                               int d = -1) {\n    int n =\
    \ f.size();\n    assert(n == 0 || f[0] == 1);\n    std::vector<std::pair<int,\
    \ mint>> ret;\n    for (int i = 1; i < n; i++) {\n        if (f[i] != 0) ret.emplace_back(i,\
    \ f[i]);\n    }\n    std::vector<mint> g(d);\n    g[0] = 1;\n    for (int i =\
    \ 0; i < d - 1; i++) {\n        for (const auto &[j, cf] : ret) {\n          \
    \  if (i + 1 - j < 0) break;\n            g[i + 1] +=\n                (mint(k)\
    \ * mint(j) - mint(i - j + 1)) * cf * g[i + 1 - j];\n        }\n        g[i +\
    \ 1] *= inv<mint>(i + 1);\n    }\n    return g;\n}\n\ntemplate <Modint mint>\n\
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
  - math/mod_inv.hpp
  - modint/base.hpp
  isVerificationFile: false
  path: fps/fps_sparse.hpp
  requiredBy:
  - fps/fps_sqrt.hpp
  timestamp: '2023-10-26 11:41:06+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/aoj_3361.test.cpp
  - test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Exp_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Log_of_Formal_Power_Series_Sparse.test.cpp
documentation_of: fps/fps_sparse.hpp
layout: document
title: Formal Power Series (Sparse)
---

## 説明

疎な形式的べき級数に対する処理を集めたもの。

### mul_sparse(std::vector<mint> f, std::vector<mint> g)

ナイーブな多項式積。$f$ の非ゼロの項を $N$ 個、$g$ の非ゼロの項を $M$ 個として $O(NM)$。

### inv_sparse(std::vector<mint> f, int d)

$f^{-1} \mod x^d$ を求める。$f$ の非ゼロの項を $M$ 個として $O(NM)$

### exp_sparse(std::vector<mint> f, int d)

$\exp(f) \mod x^d$ を求める。$f$ の非ゼロの項を $M$ 個として $O(NM)$

### log_sparse(std::vector<mint> f, int d)

$\log{f} \mod x^d$ を求める。$f$ の非ゼロの項を $M$ 個として $O(NM)$

### pow_sparse(std::vector<mint> f, long long k, int d)

$f^k \mod x^d$ を求める。$k$ は非負整数のみ正常に動作する。$f$ の非ゼロの項を $M$ 個として $O(NM)$

### pow_sparse_1(std::vector<mint> f, long long k, int d)

$[x^0]f = 1$ であるような $f$ に対して $f^k \mod x^d$ を求める。 $k$ が負でも有理数でも動作する。 $f$ の非ゼロの項を $M$ 個として $O(NM)$