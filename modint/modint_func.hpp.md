---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/modint_func.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#include <iostream>\n\
    \nnamespace ebi {\n\ntemplate<class T>\nconcept modint = requires (T a, T b) {\n\
    \    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n\
    \    a.mod();\n};\n\ntemplate <modint mint>\nstd::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 7 \"\
    modint/modint_func.hpp\"\n\nnamespace ebi {\n\ntemplate <modint mint> mint inv(int\
    \ n) {\n    static const int mod = mint::mod();\n    static std::vector<mint>\
    \ dat = {0, 1};\n    assert(0 <= n);\n    if (n >= mod) n -= mod;\n    while (int(dat.size())\
    \ <= n) {\n        int num = dat.size();\n        int q = (mod + num - 1) / num;\n\
    \        dat.emplace_back(dat[num * q - mod] * mint(q));\n    }\n    return dat[n];\n\
    }\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\n#include \"base.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <modint mint> mint inv(int n) {\n    static const\
    \ int mod = mint::mod();\n    static std::vector<mint> dat = {0, 1};\n    assert(0\
    \ <= n);\n    if (n >= mod) n -= mod;\n    while (int(dat.size()) <= n) {\n  \
    \      int num = dat.size();\n        int q = (mod + num - 1) / num;\n       \
    \ dat.emplace_back(dat[num * q - mod] * mint(q));\n    }\n    return dat[n];\n\
    }\n\n}  // namespace ebi"
  dependsOn:
  - modint/base.hpp
  isVerificationFile: false
  path: modint/modint_func.hpp
  requiredBy: []
  timestamp: '2023-10-26 02:17:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modint/modint_func.hpp
layout: document
redirect_from:
- /library/modint/modint_func.hpp
- /library/modint/modint_func.hpp.html
title: modint/modint_func.hpp
---
