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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../data_structure/heavy_light_decomposition.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n\nusing i64 = std::int64_t;\ni64 op(i64 a, i64 b) { return\
    \ a+b; }\ni64 e() { return 0; }\n\nint main() {\n    int n,q;\n    std::cin >>\
    \ n >> q;\n    std::vector<i64> a(n);\n    for(int i = 0; i < n; ++i) {\n    \
    \    std::cin >> a[i];\n    }\n    ebi::heavy_light_decomposition<i64, op, e>\
    \ hld(n);\n    for(int i = 0; i < n-1; ++i) {\n        int u,v;\n        std::cin\
    \ >> u >> v;\n        hld.add_edge(u,v);\n    }\n    hld.build();\n    hld.set(a);\n\
    \    while(q--) {\n        int flag;\n        std::cin >> flag;\n        if(flag\
    \ == 0) {\n            int p;\n            i64 x;\n            std::cin >> p >>\
    \ x;\n            hld.set(p, hld.get(p) + x);\n        }\n        else {\n   \
    \         int u,v;\n            std::cin >> u >> v;\n            std::cout <<\
    \ hld.path_prod(u, v) << std::endl;\n        }   \n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_add_path_sum.test.cpp
- /verify/test/vertex_add_path_sum.test.cpp.html
title: test/vertex_add_path_sum.test.cpp
---
