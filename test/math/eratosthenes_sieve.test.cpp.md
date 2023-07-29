---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/eratosthenes_sieve.hpp
    title: Eratosthenes Sieve
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
  bundledCode: "#line 1 \"test/math/eratosthenes_sieve.test.cpp\"\n#define PROBLEM\
    \ \\\r\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \r\n\r\n#line 2 \"math/eratosthenes_sieve.hpp\"\n\r\n#include <cassert>\r\n#include\
    \ <cstdint>\r\n#include <vector>\r\n\r\n/*\r\n    reference: https://37zigen.com/sieve-eratosthenes/\r\
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
    \        }\r\n        return prime;\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n\
    #line 5 \"test/math/eratosthenes_sieve.test.cpp\"\n\r\n#include <iostream>\r\n\
    \r\nint main() {\r\n    int n;\r\n    std::cin >> n;\r\n    ebi::eratosthenes_sieve\
    \ sieve(1e8);\r\n    int ans = 0;\r\n    for (int i = 0; i < n; i++) {\r\n   \
    \     int p;\r\n        std::cin >> p;\r\n        if (sieve.is_prime(p)) ans++;\r\
    \n    }\r\n    std::cout << ans << '\\n';\r\n}\n"
  code: "#define PROBLEM \\\r\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \r\n\r\n#include \"../../math/eratosthenes_sieve.hpp\"\r\n\r\n#include <iostream>\r\
    \n\r\nint main() {\r\n    int n;\r\n    std::cin >> n;\r\n    ebi::eratosthenes_sieve\
    \ sieve(1e8);\r\n    int ans = 0;\r\n    for (int i = 0; i < n; i++) {\r\n   \
    \     int p;\r\n        std::cin >> p;\r\n        if (sieve.is_prime(p)) ans++;\r\
    \n    }\r\n    std::cout << ans << '\\n';\r\n}"
  dependsOn:
  - math/eratosthenes_sieve.hpp
  isVerificationFile: true
  path: test/math/eratosthenes_sieve.test.cpp
  requiredBy: []
  timestamp: '2023-07-17 14:12:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/eratosthenes_sieve.test.cpp
layout: document
redirect_from:
- /verify/test/math/eratosthenes_sieve.test.cpp
- /verify/test/math/eratosthenes_sieve.test.cpp.html
title: test/math/eratosthenes_sieve.test.cpp
---
