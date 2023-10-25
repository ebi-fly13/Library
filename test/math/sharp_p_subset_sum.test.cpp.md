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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sharp_p_subset_sum\"\n\n\
    #include <iostream>\n#include <vector>\n\n#include \"../../convolution/ntt.hpp\"\
    \n#include \"../../fps/product_of_one_plus_xn.hpp\"\n#include \"../../modint/modint.hpp\"\
    \n\nusing mint = ebi::modint998244353;\n\nint main() {\n    int n, t;\n    std::cin\
    \ >> n >> t;\n    std::vector<int> s(n);\n    for (int i = 0; i < n; i++) {\n\
    \        std::cin >> s[i];\n    }\n    auto p = ebi::product_of_one_plus_xn<mint,\
    \ ebi::convolution>(s, t + 1);\n    for (int i = 1; i <= t; i++) {\n        std::cout\
    \ << p[i] << \" \\n\"[i == t];\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/math/sharp_p_subset_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/sharp_p_subset_sum.test.cpp
layout: document
redirect_from:
- /verify/test/math/sharp_p_subset_sum.test.cpp
- /verify/test/math/sharp_p_subset_sum.test.cpp.html
title: test/math/sharp_p_subset_sum.test.cpp
---
