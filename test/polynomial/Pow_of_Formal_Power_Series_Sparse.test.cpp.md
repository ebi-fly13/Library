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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../utility/modint_func.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../fps/fps_sparse.hpp\"\
    \n#include \"../../modint/modint.hpp\"\n\nusing mint = ebi::modint998244353;\n\
    \nint main() {\n    int n, k;\n    long long m;\n    std::cin >> n >> k >> m;\n\
    \    std::vector<mint> f(n);\n    for (int i = 0; i < k; i++) {\n        int idx,\
    \ a;\n        std::cin >> idx >> a;\n        f[idx] = a;\n    }\n    auto g =\
    \ ebi::pow_sparse(f, m, n);\n    for (int i = 0; i < n; i++) {\n        std::cout\
    \ << g[i].val() << \" \\n\"[i == n - 1];\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
layout: document
redirect_from:
- /verify/test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
- /verify/test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp.html
title: test/polynomial/Pow_of_Formal_Power_Series_Sparse.test.cpp
---
