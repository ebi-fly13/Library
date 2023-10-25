---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../utility/modint_func.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/sqrt_of_formal_power_series_sparse\"\
    \n\n#include \"../../convolution/ntt.hpp\"\n#include \"../../fps/fps.hpp\"\n#include\
    \ \"../../fps/fps_sqrt.hpp\"\n#include \"../../modint/modint.hpp\"\n\nusing namespace\
    \ ebi;\n\nusing mint = modint998244353;\nusing FPS = FormalPowerSeries<mint, convolution>;\n\
    \nint main() {\n    int n, k;\n    std::cin >> n >> k;\n    FPS f(n);\n    for\
    \ (int i = 0; i < k; i++) {\n        int idx, a;\n        std::cin >> idx >> a;\n\
    \        f[idx] = a;\n    }\n    auto opt = f.sqrt(n);\n    if (!opt) {\n    \
    \    std::cout << \"-1\\n\";\n        return 0;\n    }\n    auto g = opt.value();\n\
    \    for (int i = 0; i < n; i++) {\n        std::cout << g[i].val() << \" \\n\"\
    [i == n - 1];\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
layout: document
redirect_from:
- /verify/test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
- /verify/test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp.html
title: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
---
