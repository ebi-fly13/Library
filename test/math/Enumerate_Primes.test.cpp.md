---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/eratosthenes_sieve.hpp
    title: Eratosthenes Sieve
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
  bundledCode: "#line 1 \"test/math/Enumerate_Primes.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/enumerate_primes\"\r\n\r\n#include <iostream>\r\
    \n\r\n#line 2 \"math/eratosthenes_sieve.hpp\"\n\r\n#include <cassert>\r\n#include\
    \ <cstdint>\r\n#include <vector>\r\n\r\n/*\r\n    reference: https://37zigen.com/sieve-eratosthenes/\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\nstruct eratosthenes_sieve {\r\n  private:\r\
    \n    using i64 = std::int_fast64_t;\r\n    int n;\r\n    std::vector<bool> table;\r\
    \n\r\n  public:\r\n    eratosthenes_sieve(int _n) : n(_n), table(std::vector<bool>(n\
    \ + 1, true)) {\r\n        table[1] = false;\r\n        for (i64 i = 2; i * i\
    \ <= n; i++) {\r\n            if (!table[i]) continue;\r\n            for (i64\
    \ j = i; i * j <= n; j++) {\r\n                table[i * j] = false;\r\n     \
    \       }\r\n        }\r\n    }\r\n\r\n    bool is_prime(int p) {\r\n        return\
    \ table[p];\r\n    }\r\n\r\n    std::vector<int> prime_table(int m = -1) {\r\n\
    \        if (m < 0) m = n;\r\n        std::vector<int> prime;\r\n        for (int\
    \ i = 2; i <= m; i++) {\r\n            if (table[i]) prime.emplace_back(i);\r\n\
    \        }\r\n        return prime;\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n\
    #line 6 \"test/math/Enumerate_Primes.test.cpp\"\n\r\nint main() {\r\n    int n,\
    \ a, b;\r\n    std::cin >> n >> a >> b;\r\n    ebi::eratosthenes_sieve sieve(n);\r\
    \n    auto p = sieve.prime_table();\r\n    int sz = p.size();\r\n    int x = (sz\
    \ - b + a - 1) / a;\r\n    std::cout << sz << \" \" << x << '\\n';\r\n    for\
    \ (int i = b; i < sz; i += a) {\r\n        std::cout << p[i] << \" \";\r\n   \
    \ }\r\n    std::cout << \"\\n\";\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\r\n\r\
    \n#include <iostream>\r\n\r\n#include \"../../math/eratosthenes_sieve.hpp\"\r\n\
    \r\nint main() {\r\n    int n, a, b;\r\n    std::cin >> n >> a >> b;\r\n    ebi::eratosthenes_sieve\
    \ sieve(n);\r\n    auto p = sieve.prime_table();\r\n    int sz = p.size();\r\n\
    \    int x = (sz - b + a - 1) / a;\r\n    std::cout << sz << \" \" << x << '\\\
    n';\r\n    for (int i = b; i < sz; i += a) {\r\n        std::cout << p[i] << \"\
    \ \";\r\n    }\r\n    std::cout << \"\\n\";\r\n}"
  dependsOn:
  - math/eratosthenes_sieve.hpp
  isVerificationFile: true
  path: test/math/Enumerate_Primes.test.cpp
  requiredBy: []
  timestamp: '2023-08-23 17:33:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/Enumerate_Primes.test.cpp
layout: document
redirect_from:
- /verify/test/math/Enumerate_Primes.test.cpp
- /verify/test/math/Enumerate_Primes.test.cpp.html
title: test/math/Enumerate_Primes.test.cpp
---
