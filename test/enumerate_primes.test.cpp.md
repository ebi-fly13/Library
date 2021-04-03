---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/eratosthenes_sieve.hpp
    title: math/eratosthenes_sieve.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/enumerate_primes.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\
    \r\n\r\n#include <iostream>\r\n\r\n#line 2 \"math/eratosthenes_sieve.hpp\"\n\r\
    \n#include <vector>\r\n\r\n/*\r\n    reference: https://37zigen.com/sieve-eratosthenes/\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\nstruct eratosthenes_sieve {\r\nprivate:\r\n\
    \    using i64 = std::int_fast64_t;\r\n    int n;\r\n    std::vector<bool> table;\r\
    \npublic:\r\n    eratosthenes_sieve(int n) : n(n), table(std::vector<bool>(n+1,\
    \ true)) {\r\n        for(i64 i = 2; i*i<=n; i++) {\r\n            if(!table[i])\
    \ continue;\r\n            for(i64 j = i; i*j <= n; j++) {\r\n               \
    \ table[i*j] = false;\r\n            }\r\n        }\r\n    }\r\n\r\n    bool is_prime(int\
    \ p) {\r\n        return table[p];\r\n    }\r\n\r\n    std::vector<int> prime_table(int\
    \ m = -1) {\r\n        if(m < 0) m = n;\r\n        std::vector<int> prime;\r\n\
    \        for(int i = 2; i<=m; i++) {\r\n            if(table[i]) prime.emplace_back(i);\r\
    \n        }\r\n        return prime;\r\n    }\r\n};\r\n\r\n}\n#line 6 \"test/enumerate_primes.test.cpp\"\
    \n\r\nint main() {\r\n    int n,a,b;\r\n    std::cin >> n >> a >> b;\r\n    ebi::eratosthenes_sieve\
    \ sieve(n);\r\n    auto p = sieve.prime_table();\r\n    int sz = p.size();\r\n\
    \    int x = (sz-b+a-1)/a;\r\n    std::cout << sz << \" \" << x << '\\n';\r\n\
    \    for(int i = b; i<sz; i += a) {\r\n        std::cout << p[i] << \" \";\r\n\
    \    }\r\n    std::cout << \"\\n\";\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\r\n\r\
    \n#include <iostream>\r\n\r\n#include \"../math/eratosthenes_sieve.hpp\"\r\n\r\
    \nint main() {\r\n    int n,a,b;\r\n    std::cin >> n >> a >> b;\r\n    ebi::eratosthenes_sieve\
    \ sieve(n);\r\n    auto p = sieve.prime_table();\r\n    int sz = p.size();\r\n\
    \    int x = (sz-b+a-1)/a;\r\n    std::cout << sz << \" \" << x << '\\n';\r\n\
    \    for(int i = b; i<sz; i += a) {\r\n        std::cout << p[i] << \" \";\r\n\
    \    }\r\n    std::cout << \"\\n\";\r\n}"
  dependsOn:
  - math/eratosthenes_sieve.hpp
  isVerificationFile: true
  path: test/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2021-03-24 16:36:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/test/enumerate_primes.test.cpp
- /verify/test/enumerate_primes.test.cpp.html
title: test/enumerate_primes.test.cpp
---