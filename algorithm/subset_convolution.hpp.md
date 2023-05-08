---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/subset_convolution.test.cpp
    title: test/subset_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://37zigen.com/subset-convolution/
    - https://www.slideshare.net/wata_orz/ss-12131479
  bundledCode: "#line 2 \"algorithm/subset_convolution.hpp\"\n\r\n/*\r\n    refernce:\
    \ https://www.slideshare.net/wata_orz/ss-12131479\r\n              https://37zigen.com/subset-convolution/\r\
    \n*/\r\n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\nnamespace internal\
    \ {\r\n\r\ntemplate<class T>\r\nstd::vector<T> mul(const std::vector<T> &a, const\
    \ std::vector<T> &b) {\r\n    int n = a.size();\r\n    std::vector<T> c(n,0);\r\
    \n    for(int i = 0; i<n; i++) {\r\n        for(int j = 0; j<n; j++) {\r\n   \
    \         if(i+j>=n) break;\r\n            c[i+j] += a[i]*b[j];\r\n        }\r\
    \n    }\r\n    return c;\r\n}\r\n\r\n} // namespace internal\r\n\r\ntemplate<class\
    \ T>\r\nstd::vector<T> subset_convolution(const std::vector<T> &a, const std::vector<T>\
    \ &b, int n) {\r\n    std::vector f(1<<n, std::vector<T>(n+1,0)), g(1<<n, std::vector<T>(n+1,0));\r\
    \n    for(int S = 0; S < (1<<n); ++S) {\r\n        f[S][0] = a[S];\r\n       \
    \ g[S][0] = b[S];\r\n    }\r\n    for(int i = n-1; i>=0; --i) {\r\n        int\
    \ V = 1<<i;\r\n        for(int S = V; S < (1<<n); ++S) {\r\n            S |= V;\r\
    \n            for(int j = n; j>=0; --j) {\r\n                f[S][j] = f[S^V][j]\
    \ + (j > 0 ? f[S][j-1] : 0);\r\n                g[S][j] = g[S^V][j] + (j > 0 ?\
    \ g[S][j-1] : 0);\r\n            }\r\n        }\r\n    }\r\n    std::vector fg(1<<n,\
    \ std::vector<T>());\r\n    for(int S = 0; S < (1<<n); ++S) {\r\n        fg[S]\
    \ = internal::mul(f[S], g[S]);\r\n    }\r\n    for(int i = 0; i<n; ++i) {\r\n\
    \        int V = 1<<i;\r\n        for(int S = V; S < (1<<n); ++S) {\r\n      \
    \      S |= V;\r\n            for(int j = n; j>=0; --j) {\r\n                fg[S][j]\
    \ -= fg[S^V][j];\r\n            }\r\n        }\r\n    }\r\n    std::vector<T>\
    \ h(1<<n);\r\n    for(int S = 0; S < (1<<n); ++S) {\r\n        h[S] = fg[S][__builtin_popcount(S)];\r\
    \n    }\r\n    return h;\r\n}\r\n\r\n} // namespace ebi\n"
  code: "#pragma once\r\n\r\n/*\r\n    refernce: https://www.slideshare.net/wata_orz/ss-12131479\r\
    \n              https://37zigen.com/subset-convolution/\r\n*/\r\n\r\n#include\
    \ <vector>\r\n\r\nnamespace ebi {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class\
    \ T>\r\nstd::vector<T> mul(const std::vector<T> &a, const std::vector<T> &b) {\r\
    \n    int n = a.size();\r\n    std::vector<T> c(n,0);\r\n    for(int i = 0; i<n;\
    \ i++) {\r\n        for(int j = 0; j<n; j++) {\r\n            if(i+j>=n) break;\r\
    \n            c[i+j] += a[i]*b[j];\r\n        }\r\n    }\r\n    return c;\r\n\
    }\r\n\r\n} // namespace internal\r\n\r\ntemplate<class T>\r\nstd::vector<T> subset_convolution(const\
    \ std::vector<T> &a, const std::vector<T> &b, int n) {\r\n    std::vector f(1<<n,\
    \ std::vector<T>(n+1,0)), g(1<<n, std::vector<T>(n+1,0));\r\n    for(int S = 0;\
    \ S < (1<<n); ++S) {\r\n        f[S][0] = a[S];\r\n        g[S][0] = b[S];\r\n\
    \    }\r\n    for(int i = n-1; i>=0; --i) {\r\n        int V = 1<<i;\r\n     \
    \   for(int S = V; S < (1<<n); ++S) {\r\n            S |= V;\r\n            for(int\
    \ j = n; j>=0; --j) {\r\n                f[S][j] = f[S^V][j] + (j > 0 ? f[S][j-1]\
    \ : 0);\r\n                g[S][j] = g[S^V][j] + (j > 0 ? g[S][j-1] : 0);\r\n\
    \            }\r\n        }\r\n    }\r\n    std::vector fg(1<<n, std::vector<T>());\r\
    \n    for(int S = 0; S < (1<<n); ++S) {\r\n        fg[S] = internal::mul(f[S],\
    \ g[S]);\r\n    }\r\n    for(int i = 0; i<n; ++i) {\r\n        int V = 1<<i;\r\
    \n        for(int S = V; S < (1<<n); ++S) {\r\n            S |= V;\r\n       \
    \     for(int j = n; j>=0; --j) {\r\n                fg[S][j] -= fg[S^V][j];\r\
    \n            }\r\n        }\r\n    }\r\n    std::vector<T> h(1<<n);\r\n    for(int\
    \ S = 0; S < (1<<n); ++S) {\r\n        h[S] = fg[S][__builtin_popcount(S)];\r\n\
    \    }\r\n    return h;\r\n}\r\n\r\n} // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/subset_convolution.hpp
  requiredBy: []
  timestamp: '2021-03-25 14:59:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/subset_convolution.test.cpp
documentation_of: algorithm/subset_convolution.hpp
layout: document
redirect_from:
- /library/algorithm/subset_convolution.hpp
- /library/algorithm/subset_convolution.hpp.html
title: algorithm/subset_convolution.hpp
---
