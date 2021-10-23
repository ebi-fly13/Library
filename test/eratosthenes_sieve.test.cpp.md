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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"test/eratosthenes_sieve.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \r\n\r\n#include <iostream>\r\n\r\n#line 2 \"math/eratosthenes_sieve.hpp\"\n\r\
    \n#include <vector>\r\n#include <cassert>\r\n\r\n/*\r\n    reference: https://37zigen.com/sieve-eratosthenes/\r\
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
    \       }\r\n        return prime;\r\n    }\r\n};\r\n\r\n}\n#line 6 \"test/eratosthenes_sieve.test.cpp\"\
    \n\r\nint main() {\r\n    int n;\r\n    std::cin >> n;\r\n    ebi::eratosthenes_sieve\
    \ sieve(1e8);\r\n    int ans = 0;\r\n    for(int i = 0; i<n; i++) {\r\n      \
    \  int p;\r\n        std::cin >> p;\r\n        if(sieve.is_prime(p)) ans++;\r\n\
    \    }\r\n    std::cout << ans << '\\n';\r\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \r\n\r\n#include <iostream>\r\n\r\n#include \"../math/eratosthenes_sieve.hpp\"\
    \r\n\r\nint main() {\r\n    int n;\r\n    std::cin >> n;\r\n    ebi::eratosthenes_sieve\
    \ sieve(1e8);\r\n    int ans = 0;\r\n    for(int i = 0; i<n; i++) {\r\n      \
    \  int p;\r\n        std::cin >> p;\r\n        if(sieve.is_prime(p)) ans++;\r\n\
    \    }\r\n    std::cout << ans << '\\n';\r\n}"
  dependsOn:
  - math/eratosthenes_sieve.hpp
  isVerificationFile: true
  path: test/eratosthenes_sieve.test.cpp
  requiredBy: []
  timestamp: '2021-08-16 18:05:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/eratosthenes_sieve.test.cpp
layout: document
redirect_from:
- /verify/test/eratosthenes_sieve.test.cpp
- /verify/test/eratosthenes_sieve.test.cpp.html
title: test/eratosthenes_sieve.test.cpp
---