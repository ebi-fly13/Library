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
    \  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../utility/modint_func.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../fps/fps.hpp\"\n#include \"../fps/fps_sparse.hpp\"\
    \n#include \"../math/mod_sqrt.hpp\"\n\nnamespace ebi {\n\ntemplate <class mint,\
    \ std::vector<mint> (*convolution)(\n                          const std::vector<mint>\
    \ &, const std::vector<mint> &)>\nstd::optional<FormalPowerSeries<mint, convolution>>\n\
    FormalPowerSeries<mint, convolution>::sqrt(int d) const {\n    using FPS = FormalPowerSeries<mint,\
    \ convolution>;\n    if (d < 0) d = deg();\n    if ((*this)[0] == 0) {\n     \
    \   for (int i = 1; i < this->deg(); i++) {\n            if ((*this)[i] != 0)\
    \ {\n                if (i & 1) return std::nullopt;\n                if (d -\
    \ i / 2 <= 0) break;\n                auto opt = ((*this) >> i).sqrt(d - i / 2);\n\
    \                if (!opt) return std::nullopt;\n                auto ret = opt.value()\
    \ << (i / 2);\n                if ((int)ret.deg() < d) ret.resize(d);\n      \
    \          return ret;\n            }\n        }\n        return FPS(d, 0);\n\
    \    }\n    auto s = mod_sqrt((*this)[0].val(), mint::mod());\n    if (!s) {\n\
    \        return std::nullopt;\n    }\n    if (this->count_terms() <= 200) {\n\
    \        mint y = s.value();\n        std::vector<mint> sqrt_f =\n           \
    \ pow_sparse_1(*this / (*this)[0], mint(2).inv().val(), d);\n        FPS g(d);\n\
    \        for (int i = 0; i < d; i++) g[i] = sqrt_f[i] * y;\n        return g;\n\
    \    }\n    int n = 1;\n    FPS g(n);\n    g[0] = s.value();\n    mint inv_two\
    \ = mint(2).inv();\n    while (n < d) {\n        n <<= 1;\n        g = (g + this->pre(n)\
    \ * g.inv(n)).pre(n) * inv_two;\n    }\n    g.resize(d);\n    return g;\n}\n\n\
    }  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: fps/fps_sqrt.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/fps_sqrt.hpp
layout: document
title: $\sqrt{f}$
---

## 説明

形式的べき級数 $f$ について $\sqrt{f}$ が存在するなら求める。存在しない場合は `std::nullopt`を返す。
疎な場合は非負の要素数を $M$ として $O(NM)$。密な場合は $O(N\log N)$