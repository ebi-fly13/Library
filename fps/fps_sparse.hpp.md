---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/fps_sparse.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \nnamespace ebi {\n\ntemplate <class mint>\nstd::vector<mint> inv_sparse(const\
    \ std::vector<mint> &f, int d = -1) {\n    assert(f[0] != 0);\n    if (d < 0)\
    \ {\n        d = f.size();\n    }\n    std::vector<std::pair<int, mint>> ret;\n\
    \    for (int i = 1; i < int(f.size()); i++) {\n        if (f[i] != 0) {\n   \
    \         ret.emplace_back(i, f[i]);\n        }\n    }\n    std::vector<mint>\
    \ g(d);\n    g[0] = f[0].inv();\n    for (int i = 1; i < d; i++) {\n        for\
    \ (auto [k, p] : ret) {\n            if (i - k < 0) break;\n            g[i] -=\
    \ g[i - k] * p;\n        }\n        g[i] *= g[0];\n    }\n    return g;\n}\n\n\
    }  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\nnamespace ebi {\n\
    \ntemplate <class mint>\nstd::vector<mint> inv_sparse(const std::vector<mint>\
    \ &f, int d = -1) {\n    assert(f[0] != 0);\n    if (d < 0) {\n        d = f.size();\n\
    \    }\n    std::vector<std::pair<int, mint>> ret;\n    for (int i = 1; i < int(f.size());\
    \ i++) {\n        if (f[i] != 0) {\n            ret.emplace_back(i, f[i]);\n \
    \       }\n    }\n    std::vector<mint> g(d);\n    g[0] = f[0].inv();\n    for\
    \ (int i = 1; i < d; i++) {\n        for (auto [k, p] : ret) {\n            if\
    \ (i - k < 0) break;\n            g[i] -= g[i - k] * p;\n        }\n        g[i]\
    \ *= g[0];\n    }\n    return g;\n}\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: fps/fps_sparse.hpp
  requiredBy: []
  timestamp: '2023-06-07 20:56:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
documentation_of: fps/fps_sparse.hpp
layout: document
title: $Formal Power Series (Sparse)$
---

## inv(std::vector<mint> f, int d)

$f^{-1} \mod x^d$ を求める。$f$ の非ゼロの項を $M$ 個として $O(NM)$