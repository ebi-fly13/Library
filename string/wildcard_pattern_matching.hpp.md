---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/Wildcard_Pattern_Matching.test.cpp
    title: test/string/Wildcard_Pattern_Matching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/wildcard_pattern_matching.hpp\"\n\n#include <atcoder/convolution>\n\
    #include <cassert>\n#include <string>\n#include <vector>\n\nnamespace ebi {\n\n\
    template <char base = 'a', char wildcard = '*'>\nstd::vector<bool> wildcard_pattern_matching(const\
    \ std::string &s,\n                                            const std::string\
    \ &t) {\n    int n = s.size(), m = t.size();\n    if (n < m) return std::vector<bool>(n,\
    \ false);\n    std::vector<long long> s1(n), s2(n), s3(n);\n    for (int i = 0;\
    \ i < n; i++) {\n        if (s[i] == wildcard) continue;\n        s1[i] = s[i]\
    \ - base + 1;\n        s2[i] = s1[i] * s1[i];\n        s3[i] = s2[i] * s1[i];\n\
    \    }\n    std::vector<long long> t1(m), t2(m), t3(m);\n    for (int i = 0; i\
    \ < m; i++) {\n        if (t[m - 1 - i] == wildcard) continue;\n        t1[i]\
    \ = t[m - 1 - i] - base + 1;\n        t2[i] = t1[i] * t1[i];\n        t3[i] =\
    \ t2[i] * t1[i];\n    }\n    auto s3t1 = atcoder::convolution_ll(s3, t1),\n  \
    \       s2t2 = atcoder::convolution_ll(s2, t2),\n         s1t3 = atcoder::convolution_ll(s1,\
    \ t3);\n    std::vector<bool> res(n - m + 1);\n    for (int i = 0; i < n - m +\
    \ 1; i++) {\n        long long val = s3t1[i + m - 1] - 2 * s2t2[i + m - 1] + s1t3[i\
    \ + m - 1];\n        res[i] = (val == 0);\n    }\n    return res;\n}\n\n}  //\
    \ namespace ebi\n"
  code: "#pragma once\n\n#include <atcoder/convolution>\n#include <cassert>\n#include\
    \ <string>\n#include <vector>\n\nnamespace ebi {\n\ntemplate <char base = 'a',\
    \ char wildcard = '*'>\nstd::vector<bool> wildcard_pattern_matching(const std::string\
    \ &s,\n                                            const std::string &t) {\n \
    \   int n = s.size(), m = t.size();\n    if (n < m) return std::vector<bool>(n,\
    \ false);\n    std::vector<long long> s1(n), s2(n), s3(n);\n    for (int i = 0;\
    \ i < n; i++) {\n        if (s[i] == wildcard) continue;\n        s1[i] = s[i]\
    \ - base + 1;\n        s2[i] = s1[i] * s1[i];\n        s3[i] = s2[i] * s1[i];\n\
    \    }\n    std::vector<long long> t1(m), t2(m), t3(m);\n    for (int i = 0; i\
    \ < m; i++) {\n        if (t[m - 1 - i] == wildcard) continue;\n        t1[i]\
    \ = t[m - 1 - i] - base + 1;\n        t2[i] = t1[i] * t1[i];\n        t3[i] =\
    \ t2[i] * t1[i];\n    }\n    auto s3t1 = atcoder::convolution_ll(s3, t1),\n  \
    \       s2t2 = atcoder::convolution_ll(s2, t2),\n         s1t3 = atcoder::convolution_ll(s1,\
    \ t3);\n    std::vector<bool> res(n - m + 1);\n    for (int i = 0; i < n - m +\
    \ 1; i++) {\n        long long val = s3t1[i + m - 1] - 2 * s2t2[i + m - 1] + s1t3[i\
    \ + m - 1];\n        res[i] = (val == 0);\n    }\n    return res;\n}\n\n}  //\
    \ namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: string/wildcard_pattern_matching.hpp
  requiredBy: []
  timestamp: '2024-05-09 21:53:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/Wildcard_Pattern_Matching.test.cpp
documentation_of: string/wildcard_pattern_matching.hpp
layout: document
title: Wildcard Pattern Matching
---

## 説明

ワイルドカード付きパターンマッチングを行う。 $O((|S|+|T|)\log{(|S| + |T|)})$