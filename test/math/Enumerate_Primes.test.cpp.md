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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../math/eratosthenes_sieve.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\r\n\r\
    \n#include <iostream>\r\n\r\n#include \"../math/eratosthenes_sieve.hpp\"\r\n\r\
    \nint main() {\r\n    int n, a, b;\r\n    std::cin >> n >> a >> b;\r\n    ebi::eratosthenes_sieve\
    \ sieve(n);\r\n    auto p = sieve.prime_table();\r\n    int sz = p.size();\r\n\
    \    int x = (sz - b + a - 1) / a;\r\n    std::cout << sz << \" \" << x << '\\\
    n';\r\n    for (int i = b; i < sz; i += a) {\r\n        std::cout << p[i] << \"\
    \ \";\r\n    }\r\n    std::cout << \"\\n\";\r\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/math/Enumerate_Primes.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/Enumerate_Primes.test.cpp
layout: document
redirect_from:
- /verify/test/math/Enumerate_Primes.test.cpp
- /verify/test/math/Enumerate_Primes.test.cpp.html
title: test/math/Enumerate_Primes.test.cpp
---
