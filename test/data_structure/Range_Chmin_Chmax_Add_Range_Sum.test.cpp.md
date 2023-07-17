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
  code: "#define PROBLEM \\\r\n    \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"../../data_structure/SegmentTreeBeats.hpp\"\
    \r\n#include \"../utility/int_alias.hpp\"\r\n\r\nusing S = i64;\r\n\r\nint main()\
    \ {\r\n    int n, q;\r\n    std::cin >> n >> q;\r\n    std::vector<i64> a(n);\r\
    \n    for (int i = 0; i < n; i++) {\r\n        std::cin >> a[i];\r\n    }\r\n\
    \    ebi::SegmentTreeBeats<S> seg(a);\r\n    while (q--) {\r\n        int t;\r\
    \n        std::cin >> t;\r\n        if (t == 0) {\r\n            int l, r;\r\n\
    \            i64 b;\r\n            std::cin >> l >> r >> b;\r\n            seg.apply_chmin(l,\
    \ r, b);\r\n        } else if (t == 1) {\r\n            int l, r;\r\n        \
    \    i64 b;\r\n            std::cin >> l >> r >> b;\r\n            seg.apply_chmax(l,\
    \ r, b);\r\n        } else if (t == 2) {\r\n            int l, r;\r\n        \
    \    i64 b;\r\n            std::cin >> l >> r >> b;\r\n            seg.apply(l,\
    \ r, b);\r\n        } else {\r\n            int l, r;\r\n            std::cin\
    \ >> l >> r;\r\n            std::cout << seg.prod(l, r) << std::endl;\r\n    \
    \    }\r\n    }\r\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/data_structure/Range_Chmin_Chmax_Add_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data_structure/Range_Chmin_Chmax_Add_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Range_Chmin_Chmax_Add_Range_Sum.test.cpp
- /verify/test/data_structure/Range_Chmin_Chmax_Add_Range_Sum.test.cpp.html
title: test/data_structure/Range_Chmin_Chmax_Add_Range_Sum.test.cpp
---
