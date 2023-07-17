---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../data_structure/segtree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../data_structure/segtree.hpp\"\
    \n#include \"../tree/heavy_light_decomposition.hpp\"\n#include \"../utility/modint.hpp\"\
    \n\nusing mint = ebi::modint998244353;\n\nusing i64 = std::int64_t;\n\nstruct\
    \ S {\n    mint c, d;\n};\n\nS op(S a, S b) {\n    return {b.c * a.c, b.c * a.d\
    \ + b.d};\n}\n\nS e() {\n    return {1, 0};\n}\n\nint main() {\n    int n, q;\n\
    \    std::cin >> n >> q;\n    std::vector g(n, std::vector<int>());\n    std::vector<S>\
    \ fx(n);\n    for (int i = 0; i < n; i++) {\n        int a, b;\n        std::cin\
    \ >> a >> b;\n        fx[i] = {a, b};\n    }\n    for (int i = 0; i < n - 1; i++)\
    \ {\n        int u, v;\n        std::cin >> u >> v;\n        g[u].emplace_back(v);\n\
    \        g[v].emplace_back(u);\n    }\n    ebi::heavy_light_decomposition hld(g);\n\
    \    ebi::segtree<S, op, e> seg1(n);\n    ebi::segtree<S, op, e> seg2(n);\n  \
    \  for (int i = 0; i < n; i++) {\n        int idx = hld.idx(i);\n        seg1.set(idx,\
    \ fx[i]);\n        seg2.set(n - 1 - idx, fx[i]);\n    }\n    S ans = e();\n  \
    \  auto f = [&](int l, int r) -> void {\n        if (l <= r) {\n            ans\
    \ = op(ans, seg1.prod(l, r));\n        } else {\n            ans = op(ans, seg2.prod(n\
    \ - l, n - r));\n        }\n    };\n    while (q--) {\n        int t;\n      \
    \  std::cin >> t;\n        if (t == 0) {\n            int p, c, d;\n         \
    \   std::cin >> p >> c >> d;\n            int idx = hld.idx(p);\n            seg1.set(idx,\
    \ {c, d});\n            seg2.set(n - 1 - idx, {c, d});\n        } else {\n   \
    \         int u, v, x;\n            std::cin >> u >> v >> x;\n            ans\
    \ = e();\n            hld.path_noncommutative_query(u, v, true, f);\n        \
    \    std::cout << (ans.c * x + ans.d).val() << '\\n';\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/data_structure/Vertex_Set_Path_Compositie.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data_structure/Vertex_Set_Path_Compositie.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Vertex_Set_Path_Compositie.test.cpp
- /verify/test/data_structure/Vertex_Set_Path_Compositie.test.cpp.html
title: test/data_structure/Vertex_Set_Path_Compositie.test.cpp
---
