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
  code: "#pragma once\n\n#include <vector>\n\n#include \"../fps/fps.hpp\"\n#include\
    \ \"../utility/modint_func.hpp\"\n\nnamespace ebi {\n\n// prod (1 - x^a_i) mod\
    \ x^d\ntemplate <class mint, std::vector<mint> (*convolution)(\n             \
    \             const std::vector<mint> &, const std::vector<mint> &)>\nFormalPowerSeries<mint,\
    \ convolution> product_of_one_minus_xn(std::vector<int> a,\n                 \
    \                                            int d) {\n    using FPS = FormalPowerSeries<mint,\
    \ convolution>;\n    std::vector<int> cnt(d, 0);\n    for (auto x : a)\n     \
    \   if (x < d) cnt[x]++;\n    if (cnt[0]) return FPS(d);\n    FPS log_f(d);\n\
    \    for (int x = 1; x < d; x++) {\n        for (int i = 1; x * i < d; i++) {\n\
    \            log_f[x * i] -= mint(cnt[x]) * inv<mint>(i);\n        }\n    }\n\
    \    return log_f.exp(d);\n}\n\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: fps/product_of_one_minus_xn.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/product_of_one_minus_xn.hpp
layout: document
title: $\prod (1 - x^{a_i}) \mod x^d$
---

## 説明

$\prod (1 - x^{a_i}) \mod x^d$ を $O(D(\log D + \log \max a))$ で求める。 $D$ は求めたい最大の次数である。中身は、$\log$ を取って $\exp$ している。