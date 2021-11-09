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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../data_structure/segtree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\r\n\r\n\
    #include <iostream>\r\n#include <cstdint>\r\n\r\n#include \"../data_structure/compress.hpp\"\
    \r\n#include \"../data_structure/segtree_2d.hpp\"\r\n\r\nusing i64 = std::int64_t;\r\
    \n\r\ni64 op(i64 a, i64 b) {\r\n    return a+b;\r\n}\r\n\r\ni64 e() {\r\n    return\
    \ 0;\r\n}\r\n\r\nint main() {\r\n    int n,q;\r\n    std::cin >> n >> q;\r\n \
    \   ebi::compress<i64> cp;\r\n    std::vector<i64> x(n), y(n), w(n);\r\n    for(int\
    \ i = 0; i < n; i++) {\r\n        std::cin >> x[i] >> y[i] >> w[i];\r\n      \
    \  cp.add(x[i]);\r\n    }\r\n    cp.build();\r\n    ebi::segtree_2d<i64, op, e>\
    \ seg(cp.size());\r\n    for(int i = 0; i < n; i++) {\r\n        seg.pre_set(cp.get(x[i]),\
    \ y[i]);\r\n    }\r\n    seg.build();\r\n    for(int i = 0; i < n; i++) {\r\n\
    \        seg.set(cp.get(x[i]), y[i], w[i]);\r\n    }\r\n    while(q--) {\r\n \
    \       i64 l,d,r,u;\r\n        std::cin >> l >> d >> r >> u;\r\n        std::cout\
    \ << seg.prod(cp.get(l),cp.get(r),d,u) << std::endl;\r\n    }\r\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/rectangle_sum.test.cpp
- /verify/test/rectangle_sum.test.cpp.html
title: test/rectangle_sum.test.cpp
---
