---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../data_structure/segtree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\
    \n\r\n#include \"../data_structure/segtree.hpp\"\r\n\r\n#include <iostream>\r\n\
    #include <cstdint>\r\n\r\nusing i64 = std::int64_t;\r\n\r\ni64 op(i64 a, i64 b)\
    \ { return a+b; }\r\ni64 e() { return (i64)0; }\r\n\r\nint main(){\r\n    int\
    \ n,q; std::cin >> n >> q;\r\n    std::vector<i64> a(n);\r\n    for(int i = 0;\
    \ i<n; i++){\r\n        std::cin >> a[i];\r\n    }\r\n    ebi::segtree<i64, op,\
    \ e> seg(a);\r\n    while(q--){\r\n        int t;\r\n        std::cin >> t;\r\n\
    \        if(t==0){\r\n            int p; i64 x; std::cin >> p >> x;\r\n      \
    \      seg.set(p,seg[p]+x);\r\n        }\r\n        else{\r\n            int l,r;\
    \ std::cin >> l >> r;\r\n            std::cout << seg.prod(l,r) << std::endl;\r\
    \n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/Segtree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/Segtree.test.cpp
layout: document
redirect_from:
- /verify/test/Segtree.test.cpp
- /verify/test/Segtree.test.cpp.html
title: test/Segtree.test.cpp
---
