---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../utility/modint_func.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../utility/modint_func.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class mint>\nstd::vector<mint> mul_sparse(const\
    \ std::vector<mint> &f,\n                             const std::vector<mint>\
    \ &g) {\n    int n = f.size();\n    int m = g.size();\n    std::vector<std::pair<int,\
    \ mint>> cf, cg;\n    for (int i = 0; i < n; i++) {\n        if (f[i] != 0) cf.emplace_back(i,\
    \ f[i]);\n    }\n    for (int i = 0; i < m; i++) {\n        if (g[i] != 0) cg.emplace_back(i,\
    \ g[i]);\n    }\n    std::vector<mint> h(n + m - 1);\n    for (auto [i, p] : cf)\
    \ {\n        for (auto [j, q] : cg) {\n            h[i + j] += p * q;\n      \
    \  }\n    }\n    return h;\n}\n\ntemplate <class mint>\nstd::vector<mint> inv_sparse(const\
    \ std::vector<mint> &f, int d = -1) {\n    assert(f[0] != 0);\n    if (d < 0)\
    \ {\n        d = f.size();\n    }\n    std::vector<std::pair<int, mint>> ret;\n\
    \    for (int i = 1; i < int(f.size()); i++) {\n        if (f[i] != 0) {\n   \
    \         ret.emplace_back(i, f[i]);\n        }\n    }\n    std::vector<mint>\
    \ g(d);\n    g[0] = f[0].inv();\n    for (int i = 1; i < d; i++) {\n        for\
    \ (auto [k, p] : ret) {\n            if (i - k < 0) break;\n            g[i] -=\
    \ g[i - k] * p;\n        }\n        g[i] *= g[0];\n    }\n    return g;\n}\n\n\
    template <class mint>\nstd::vector<mint> exp_sparse(const std::vector<mint> &f,\
    \ int d = -1) {\n    int n = f.size();\n    if (d < 0) d = n;\n    std::vector<std::pair<int,\
    \ mint>> ret;\n    for (int i = 1; i < n; i++) {\n        if (f[i] != 0) {\n \
    \           ret.emplace_back(i - 1, f[i] * i);\n        }\n    }\n    std::vector<mint>\
    \ g(d);\n    g[0] = 1;\n    for (int i = 0; i < d - 1; i++) {\n        for (auto\
    \ [k, p] : ret) {\n            if (i - k < 0) break;\n            g[i + 1] +=\
    \ g[i - k] * p;\n        }\n        g[i + 1] *= inv<mint>(i + 1);\n    }\n   \
    \ return g;\n}\n\ntemplate <class mint>\nstd::vector<mint> log_sparse(const std::vector<mint>\
    \ &f, int d = -1) {\n    int n = f.size();\n    if (d < 0) d = n;\n    std::vector<mint>\
    \ df(d);\n    for (int i = 0; i < std::min(d, n - 1); i++) {\n        df[i] =\
    \ f[i + 1] * (i + 1);\n    }\n    auto dg = mul_sparse(df, inv_sparse(f));\n \
    \   dg.resize(d);\n    std::vector<mint> g(d);\n    for (int i = 0; i < d - 1;\
    \ i++) {\n        g[i + 1] = dg[i] * inv<mint>(i + 1);\n    }\n    return g;\n\
    }\n\ntemplate <class mint>\nstd::vector<mint> pow_sparse_1(const std::vector<mint>\
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
  dependsOn: []
  isVerificationFile: false
  path: fps/fps_sparse.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
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