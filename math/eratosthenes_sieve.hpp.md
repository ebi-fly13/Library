---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/gcd_convolution.hpp
    title: convolution/gcd_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/lcm_convolution.hpp
    title: LCM Convolution
  - icon: ':heavy_check_mark:'
    path: math/divisor_transform.hpp
    title: Divisor Transform (Zeta / Mobius)
  - icon: ':heavy_check_mark:'
    path: math/multiple_transform.hpp
    title: Multiple Transform (Zeta / Mobius)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/Gcd_Convolution.test.cpp
    title: test/convolution/Gcd_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Lcm_Convolution.test.cpp
    title: test/convolution/Lcm_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/enumerate_primes.test.cpp
    title: test/enumerate_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/eratosthenes_sieve.test.cpp
    title: test/eratosthenes_sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://37zigen.com/sieve-eratosthenes/
  bundledCode: "#line 2 \"math/eratosthenes_sieve.hpp\"\n\r\n#include <cassert>\r\n\
    #include <cstdint>\r\n#include <vector>\r\n\r\n/*\r\n    reference: https://37zigen.com/sieve-eratosthenes/\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\nstruct eratosthenes_sieve {\r\n  private:\r\
    \n    using i64 = std::int_fast64_t;\r\n    int n;\r\n    std::vector<bool> table;\r\
    \n\r\n  public:\r\n    eratosthenes_sieve(int n) : n(n), table(std::vector<bool>(n\
    \ + 1, true)) {\r\n        table[1] = false;\r\n        for (i64 i = 2; i * i\
    \ <= n; i++) {\r\n            if (!table[i]) continue;\r\n            for (i64\
    \ j = i; i * j <= n; j++) {\r\n                table[i * j] = false;\r\n     \
    \       }\r\n        }\r\n    }\r\n\r\n    bool is_prime(int p) {\r\n        return\
    \ table[p];\r\n    }\r\n\r\n    std::vector<int> prime_table(int m = -1) {\r\n\
    \        if (m < 0) m = n;\r\n        std::vector<int> prime;\r\n        for (int\
    \ i = 2; i <= m; i++) {\r\n            if (table[i]) prime.emplace_back(i);\r\n\
    \        }\r\n        return prime;\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <cassert>\r\n#include <cstdint>\r\n#include\
    \ <vector>\r\n\r\n/*\r\n    reference: https://37zigen.com/sieve-eratosthenes/\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\nstruct eratosthenes_sieve {\r\n  private:\r\
    \n    using i64 = std::int_fast64_t;\r\n    int n;\r\n    std::vector<bool> table;\r\
    \n\r\n  public:\r\n    eratosthenes_sieve(int n) : n(n), table(std::vector<bool>(n\
    \ + 1, true)) {\r\n        table[1] = false;\r\n        for (i64 i = 2; i * i\
    \ <= n; i++) {\r\n            if (!table[i]) continue;\r\n            for (i64\
    \ j = i; i * j <= n; j++) {\r\n                table[i * j] = false;\r\n     \
    \       }\r\n        }\r\n    }\r\n\r\n    bool is_prime(int p) {\r\n        return\
    \ table[p];\r\n    }\r\n\r\n    std::vector<int> prime_table(int m = -1) {\r\n\
    \        if (m < 0) m = n;\r\n        std::vector<int> prime;\r\n        for (int\
    \ i = 2; i <= m; i++) {\r\n            if (table[i]) prime.emplace_back(i);\r\n\
    \        }\r\n        return prime;\r\n    }\r\n};\r\n\r\n}  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: math/eratosthenes_sieve.hpp
  requiredBy:
  - convolution/gcd_convolution.hpp
  - convolution/lcm_convolution.hpp
  - math/multiple_transform.hpp
  - math/divisor_transform.hpp
  timestamp: '2023-06-09 15:36:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/Lcm_Convolution.test.cpp
  - test/convolution/Gcd_Convolution.test.cpp
  - test/enumerate_primes.test.cpp
  - test/eratosthenes_sieve.test.cpp
documentation_of: math/eratosthenes_sieve.hpp
layout: document
redirect_from:
- /library/math/eratosthenes_sieve.hpp
- /library/math/eratosthenes_sieve.hpp.html
title: math/eratosthenes_sieve.hpp
---
