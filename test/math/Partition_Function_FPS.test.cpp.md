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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/partition_function\"\n\n\
    #include <iostream>\n#include <vector>\n#include <numeric>\n\n#include \"../../fps/fps.hpp\"\
    \n#include \"../../fps/product_of_one_minus_xn.hpp\"\n#include \"../../modint/modint.hpp\"\
    \n#include \"../../convolution/ntt.hpp\"\n\nusing mint = ebi::modint998244353;\n\
    using FPS = ebi::FormalPowerSeries<mint, ebi::convolution>;\n\nint main() {\n\
    \    int n;\n    std::cin >> n;\n    std::vector<int> a(n);\n    std::iota(a.begin(),\
    \ a.end(), 1);\n    FPS f = ebi::product_of_one_minus_xn<mint, ebi::convolution>(a,\
    \ n + 1);\n    f = f.inv();\n    for(int i = 0; i <= n; i++) {\n        std::cout\
    \ << f[i].val() << \" \\n\"[i == n];\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/math/Partition_Function_FPS.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/Partition_Function_FPS.test.cpp
layout: document
redirect_from:
- /verify/test/math/Partition_Function_FPS.test.cpp
- /verify/test/math/Partition_Function_FPS.test.cpp.html
title: test/math/Partition_Function_FPS.test.cpp
---
