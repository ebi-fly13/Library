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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../template/graph_template.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\r\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \r\n\r\n#include \"../../graph/dijkstra.hpp\"\r\n\r\n#include <iostream>\r\n#include\
    \ <limits>\r\n#include <vector>\r\n\r\n#include \"../../template/graph_template.hpp\"\
    \r\n#include \"../../template/int_alias.hpp\"\r\n\r\nusing ebi::i64;\r\n\r\nint\
    \ main() {\r\n    int v, e, r;\r\n    std::cin >> v >> e >> r;\r\n    ebi::Graph<i64>\
    \ g(v);\r\n    while (e--) {\r\n        int s, t;\r\n        i64 d;\r\n      \
    \  std::cin >> s >> t >> d;\r\n        g[s].emplace_back(t, d);\r\n    }\r\n \
    \   std::vector<i64> dest = ebi::dijkstra(r, v, g);\r\n    for (auto di : dest)\
    \ {\r\n        if (di == std::numeric_limits<i64>::max()) {\r\n            std::cout\
    \ << \"INF\" << std::endl;\r\n            continue;\r\n        }\r\n        std::cout\
    \ << di << std::endl;\r\n    }\r\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/dijkstra.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/test/graph/dijkstra.test.cpp
- /verify/test/graph/dijkstra.test.cpp.html
title: test/graph/dijkstra.test.cpp
---
