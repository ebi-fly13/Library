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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../Matrix/SquareMatrix.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\r\n\r\n#include\
    \ <iostream>\r\n\r\n#include \"../Matrix/SquareMatrix.hpp\"\r\n#include \"../utility/modint.hpp\"\
    \r\n\r\nusing Matrix = ebi::SquareMatrix<ebi::modint998244353>;\r\n\r\nint main()\
    \ {\r\n    int n;\r\n    std::cin >> n;\r\n    Matrix::set_size(n);\r\n    Matrix\
    \ a;\r\n    for (int i = 0; i < n; ++i) {\r\n        for (int j = 0; j < n; ++j)\
    \ {\r\n            int val;\r\n            std::cin >> val;\r\n            a[i][j]\
    \ = val;\r\n        }\r\n    }\r\n    std::cout << a.det().val() << std::endl;\r\
    \n}"
  dependsOn: []
  isVerificationFile: true
  path: test/Determinant_of_Matrix.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/Determinant_of_Matrix.test.cpp
layout: document
redirect_from:
- /verify/test/Determinant_of_Matrix.test.cpp
- /verify/test/Determinant_of_Matrix.test.cpp.html
title: test/Determinant_of_Matrix.test.cpp
---
