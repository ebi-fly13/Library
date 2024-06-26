---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../convolution/arbitrary_ntt.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../convolution/arbitrary_ntt.hpp\"\
    \n#include \"../../modint/modint.hpp\"\n\nusing mint = ebi::modint1000000007;\n\
    \nint main() {\n    int n, m;\n    std::cin >> n >> m;\n    std::vector<mint>\
    \ a(n), b(m);\n    for (int i = 0; i < n; i++) std::cin >> a[i];\n    for (int\
    \ i = 0; i < m; i++) std::cin >> b[i];\n    auto c = ebi::arbitary_convolution<mint>(a,\
    \ b);\n    for (int i = 0; i < n + m - 1; i++) {\n        std::cout << c[i].val()\
    \ << \" \\n\"[i == n + m - 2];\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/convolution/Convolution_Mod_1000000007.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/convolution/Convolution_Mod_1000000007.test.cpp
layout: document
redirect_from:
- /verify/test/convolution/Convolution_Mod_1000000007.test.cpp
- /verify/test/convolution/Convolution_Mod_1000000007.test.cpp.html
title: test/convolution/Convolution_Mod_1000000007.test.cpp
---
