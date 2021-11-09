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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"../data_structure/heavy_light_decomposition.hpp\"\n#include \"\
    ../utility/modint.hpp\"\n\n#include <iostream>\n#include <vector>\n\nusing mint\
    \ = ebi::modint998244353;\n\nusing i64 = std::int64_t;\n\nstruct F {\n    mint\
    \ a,b;\n    F(mint a, mint b) : a(a), b(b) { }\n};\n\nF op(F f1, F f2) {\n   \
    \ return F(f2.a*f1.a, f2.a*f1.b+f2.b);\n}\n\nF e() {\n    return F(1,0);\n}\n\n\
    int main() {\n    int n,q;\n    std::cin >> n >> q;\n    std::vector<F> f(n, F(1,0));\n\
    \    for(int i = 0; i < n; ++i) {\n        int a,b;\n        std::cin >> a >>\
    \ b;\n        f[i] = F(a,b);\n    }\n    ebi::heavy_light_decomposition<F, op,\
    \ e> hld(n);\n    for(int i = 0; i < n-1; ++i) {\n        int u,v;\n        std::cin\
    \ >> u >> v;\n        hld.add_edge(u,v);\n    }\n    hld.build();\n    hld.set(f);\n\
    \    while(q--) {\n        int flag;\n        std::cin >> flag;\n        if(flag\
    \ == 0) {\n            int p;\n            int c, d;\n            std::cin >>\
    \ p >> c >> d;\n            hld.set(p, F(c,d));\n        }\n        else {\n \
    \           int u,v;\n            i64 x;\n            std::cin >> u >> v >> x;\n\
    \            F f_px = hld.path_prod(u, v);\n            std::cout << (f_px.a *\
    \ x + f_px.b).val() << std::endl;\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/vertex_set_path_compositie.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/vertex_set_path_compositie.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_set_path_compositie.test.cpp
- /verify/test/vertex_set_path_compositie.test.cpp.html
title: test/vertex_set_path_compositie.test.cpp
---
