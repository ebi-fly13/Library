---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/Z_Algorithm.hpp
    title: String/Z_Algorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/Z_Algorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \r\n\r\n#line 2 \"String/Z_Algorithm.hpp\"\n\r\n#include <string>\r\n#include\
    \ <vector>\r\n\r\n/*\r\n    reference: https://snuke.hatenablog.com/entry/2014/12/03/214243\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\nstd::vector<int> Z_Algorithm(const std::string\
    \ &s) {\r\n    int n = s.size();\r\n    std::vector<int> prefix(n);\r\n    prefix[0]\
    \ = n;\r\n    int i = 1;\r\n    int j = 0; // s[0,j], s[i,i+j] \u304C\u3059\u3067\
    \u306B\u4E00\u81F4\u3057\u3066\u3044\u308B\u3053\u3068\u304C\u4FDD\u8A3C\u3055\
    \u308C\u3066\u3044\u308B.\r\n    while(i<n) {\r\n        while(i+j<n && s[j]==s[i+j])\
    \ ++j;\r\n        prefix[i] = j;\r\n        if(j == 0){\r\n            ++i;\r\n\
    \            continue;\r\n        }\r\n        int k = 1;\r\n        while(i+k<n\
    \ && k+prefix[k]<j) {\r\n            prefix[i+k] = prefix[k];\r\n            ++k;\r\
    \n        }\r\n        i += k;\r\n        j -= k;\r\n    }\r\n    return prefix;\r\
    \n}\r\n\r\n} // namespace ebi\n#line 4 \"test/Z_Algorithm.test.cpp\"\n\r\n#include\
    \ <iostream>\r\n#line 7 \"test/Z_Algorithm.test.cpp\"\n\r\nint main(){\r\n   \
    \ std::string s;\r\n    std::cin >> s;\r\n    auto A = ebi::Z_Algorithm(s);\r\n\
    \    std::cout << A[0];\r\n    for(int i = 1; i<s.size(); i++){\r\n        std::cout\
    \ << \" \" << A[i];\r\n    }\r\n    std::cout << std::endl;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\r\n\r\n#include\
    \ \"../String/Z_Algorithm.hpp\"\r\n\r\n#include <iostream>\r\n#include <vector>\r\
    \n\r\nint main(){\r\n    std::string s;\r\n    std::cin >> s;\r\n    auto A =\
    \ ebi::Z_Algorithm(s);\r\n    std::cout << A[0];\r\n    for(int i = 1; i<s.size();\
    \ i++){\r\n        std::cout << \" \" << A[i];\r\n    }\r\n    std::cout << std::endl;\r\
    \n}"
  dependsOn:
  - String/Z_Algorithm.hpp
  isVerificationFile: true
  path: test/Z_Algorithm.test.cpp
  requiredBy: []
  timestamp: '2021-01-18 10:56:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Z_Algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/Z_Algorithm.test.cpp
- /verify/test/Z_Algorithm.test.cpp.html
title: test/Z_Algorithm.test.cpp
---
