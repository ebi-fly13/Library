---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/enumerate_primes.test.cpp
    title: test/enumerate_primes.test.cpp
  - icon: ':x:'
    path: test/eratosthenes_sieve.test.cpp
    title: test/eratosthenes_sieve.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://37zigen.com/sieve-eratosthenes/
  bundledCode: "#line 2 \"math/eratosthenes_sieve.hpp\"\n\r\n#include <vector>\r\n\
    \r\n/*\r\n    reference: https://37zigen.com/sieve-eratosthenes/\r\n*/\r\n\r\n\
    namespace ebi {\r\n\r\nstruct eratosthenes_sieve {\r\nprivate:\r\n    using i64\
    \ = std::int_fast64_t;\r\n    int n;\r\n    std::vector<bool> table;\r\npublic:\r\
    \n    eratosthenes_sieve(int n) : n(n), table(std::vector<bool>(n+1, true)) {\r\
    \n        table[1] = false;\r\n        for(i64 i = 2; i*i<=n; i++) {\r\n     \
    \       if(!table[i]) continue;\r\n            for(i64 j = i; i*j <= n; j++) {\r\
    \n                table[i*j] = false;\r\n            }\r\n        }\r\n    }\r\
    \n\r\n    bool is_prime(int p) {\r\n        return table[p];\r\n    }\r\n\r\n\
    \    template<class T>\r\n    std::vector<T> fast_zeta(const std::vector<T> &f)\
    \ {\r\n        std::vector<T> F = f;\r\n        int sz = f.size();\r\n       \
    \ assert(sz <= n+1);\r\n        for(int i = 2; i < sz; i++) {\r\n            if(!table[i])\
    \ continue;\r\n            for(int j = (sz-1)/i; j >= 1; j--) {\r\n          \
    \      F[j] += F[j * i];\r\n            }\r\n        }\r\n        return F;\r\n\
    \    }\r\n\r\n    template<class T>\r\n    std::vector<T> fast_mobius(const std::vector<T>\
    \ &F) {\r\n        std::vector<T> f = F;\r\n        int sz = F.size();\r\n   \
    \     assert(sz <= n+1);\r\n        for(int i = 2; i < sz; i++) {\r\n        \
    \    if(!table[i]) continue;\r\n            for(int j = 1; j*i < sz; j++) {\r\n\
    \                f[j] -= f[j * i];\r\n            }\r\n        }\r\n        return\
    \ f;\r\n    }\r\n\r\n    std::vector<int> prime_table(int m = -1) {\r\n      \
    \  if(m < 0) m = n;\r\n        std::vector<int> prime;\r\n        for(int i =\
    \ 2; i<=m; i++) {\r\n            if(table[i]) prime.emplace_back(i);\r\n     \
    \   }\r\n        return prime;\r\n    }\r\n};\r\n\r\n}\n"
  code: "#pragma once \r\n\r\n#include <vector>\r\n\r\n/*\r\n    reference: https://37zigen.com/sieve-eratosthenes/\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\nstruct eratosthenes_sieve {\r\nprivate:\r\n\
    \    using i64 = std::int_fast64_t;\r\n    int n;\r\n    std::vector<bool> table;\r\
    \npublic:\r\n    eratosthenes_sieve(int n) : n(n), table(std::vector<bool>(n+1,\
    \ true)) {\r\n        table[1] = false;\r\n        for(i64 i = 2; i*i<=n; i++)\
    \ {\r\n            if(!table[i]) continue;\r\n            for(i64 j = i; i*j <=\
    \ n; j++) {\r\n                table[i*j] = false;\r\n            }\r\n      \
    \  }\r\n    }\r\n\r\n    bool is_prime(int p) {\r\n        return table[p];\r\n\
    \    }\r\n\r\n    template<class T>\r\n    std::vector<T> fast_zeta(const std::vector<T>\
    \ &f) {\r\n        std::vector<T> F = f;\r\n        int sz = f.size();\r\n   \
    \     assert(sz <= n+1);\r\n        for(int i = 2; i < sz; i++) {\r\n        \
    \    if(!table[i]) continue;\r\n            for(int j = (sz-1)/i; j >= 1; j--)\
    \ {\r\n                F[j] += F[j * i];\r\n            }\r\n        }\r\n   \
    \     return F;\r\n    }\r\n\r\n    template<class T>\r\n    std::vector<T> fast_mobius(const\
    \ std::vector<T> &F) {\r\n        std::vector<T> f = F;\r\n        int sz = F.size();\r\
    \n        assert(sz <= n+1);\r\n        for(int i = 2; i < sz; i++) {\r\n    \
    \        if(!table[i]) continue;\r\n            for(int j = 1; j*i < sz; j++)\
    \ {\r\n                f[j] -= f[j * i];\r\n            }\r\n        }\r\n   \
    \     return f;\r\n    }\r\n\r\n    std::vector<int> prime_table(int m = -1) {\r\
    \n        if(m < 0) m = n;\r\n        std::vector<int> prime;\r\n        for(int\
    \ i = 2; i<=m; i++) {\r\n            if(table[i]) prime.emplace_back(i);\r\n \
    \       }\r\n        return prime;\r\n    }\r\n};\r\n\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/eratosthenes_sieve.hpp
  requiredBy: []
  timestamp: '2021-08-16 17:42:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/eratosthenes_sieve.test.cpp
  - test/enumerate_primes.test.cpp
documentation_of: math/eratosthenes_sieve.hpp
layout: document
redirect_from:
- /library/math/eratosthenes_sieve.hpp
- /library/math/eratosthenes_sieve.hpp.html
title: math/eratosthenes_sieve.hpp
---
