---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Z_Algorithm.test.cpp
    title: test/Z_Algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://snuke.hatenablog.com/entry/2014/12/03/214243
  bundledCode: "#line 2 \"string/Z_Algorithm.hpp\"\n\r\n#include <string>\r\n#include\
    \ <vector>\r\n\r\n/*\r\n    reference: https://snuke.hatenablog.com/entry/2014/12/03/214243\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\nstd::vector<int> Z_Algorithm(const std::string\
    \ &s) {\r\n    int n = s.size();\r\n    std::vector<int> prefix(n);\r\n    prefix[0]\
    \ = n;\r\n    int i = 1;\r\n    int j = 0;  // s[0,j], s[i,i+j] \u304C\u3059\u3067\
    \u306B\u4E00\u81F4\u3057\u3066\u3044\u308B\u3053\u3068\u304C\u4FDD\u8A3C\u3055\
    \u308C\u3066\u3044\u308B.\r\n    while (i < n) {\r\n        while (i + j < n &&\
    \ s[j] == s[i + j]) ++j;\r\n        prefix[i] = j;\r\n        if (j == 0) {\r\n\
    \            ++i;\r\n            continue;\r\n        }\r\n        int k = 1;\r\
    \n        while (i + k < n && k + prefix[k] < j) {\r\n            prefix[i + k]\
    \ = prefix[k];\r\n            ++k;\r\n        }\r\n        i += k;\r\n       \
    \ j -= k;\r\n    }\r\n    return prefix;\r\n}\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <string>\r\n#include <vector>\r\n\r\n/*\r\n\
    \    reference: https://snuke.hatenablog.com/entry/2014/12/03/214243\r\n*/\r\n\
    \r\nnamespace ebi {\r\n\r\nstd::vector<int> Z_Algorithm(const std::string &s)\
    \ {\r\n    int n = s.size();\r\n    std::vector<int> prefix(n);\r\n    prefix[0]\
    \ = n;\r\n    int i = 1;\r\n    int j = 0;  // s[0,j], s[i,i+j] \u304C\u3059\u3067\
    \u306B\u4E00\u81F4\u3057\u3066\u3044\u308B\u3053\u3068\u304C\u4FDD\u8A3C\u3055\
    \u308C\u3066\u3044\u308B.\r\n    while (i < n) {\r\n        while (i + j < n &&\
    \ s[j] == s[i + j]) ++j;\r\n        prefix[i] = j;\r\n        if (j == 0) {\r\n\
    \            ++i;\r\n            continue;\r\n        }\r\n        int k = 1;\r\
    \n        while (i + k < n && k + prefix[k] < j) {\r\n            prefix[i + k]\
    \ = prefix[k];\r\n            ++k;\r\n        }\r\n        i += k;\r\n       \
    \ j -= k;\r\n    }\r\n    return prefix;\r\n}\r\n\r\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: string/Z_Algorithm.hpp
  requiredBy: []
  timestamp: '2023-06-06 01:19:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Z_Algorithm.test.cpp
documentation_of: string/Z_Algorithm.hpp
layout: document
redirect_from:
- /library/string/Z_Algorithm.hpp
- /library/string/Z_Algorithm.hpp.html
title: string/Z_Algorithm.hpp
---
