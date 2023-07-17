---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../utility/int_alias.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\r\n\
    \r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"../../data_structure/WaveletMatrix.hpp\"\
    \r\n#include \"../utility/int_alias.hpp\"\r\n\r\nint main() {\r\n    int n, q;\r\
    \n    std::cin >> n >> q;\r\n    std::vector<i64> a(n);\r\n    for (int i = 0;\
    \ i < n; i++) {\r\n        std::cin >> a[i];\r\n    }\r\n    ebi::WaveletMatrix<i64>\
    \ wm(a);\r\n    while (q--) {\r\n        int l, r, k;\r\n        std::cin >> l\
    \ >> r >> k;\r\n        std::cout << wm.quantile(l, r, k + 1) << std::endl;\r\n\
    \    }\r\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/data_structure/Range_Kth_Smallest.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data_structure/Range_Kth_Smallest.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Range_Kth_Smallest.test.cpp
- /verify/test/data_structure/Range_Kth_Smallest.test.cpp.html
title: test/data_structure/Range_Kth_Smallest.test.cpp
---
