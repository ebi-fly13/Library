---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/pow.hpp
    title: math/pow.hpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.hpp
    title: utility/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"test/pow.test.cpp\"\n#define PROBLEM \\\r\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \r\n\r\n#line 2 \"math/pow.hpp\"\n\r\n#line 2 \"utility/int_alias.hpp\"\n\r\n\
    #include <cstddef>\r\n#include <cstdint>\r\n\r\nusing i32 = std::int32_t;\r\n\
    using i64 = std::int64_t;\r\nusing u16 = std::uint16_t;\r\nusing u32 = std::uint32_t;\r\
    \nusing u64 = std::uint64_t;\r\nusing usize = std::size_t;\n#line 4 \"math/pow.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class T> T pow(T x, u64 n, u64 mod = -1)\
    \ {\r\n    T res = 1;\r\n    if (mod > 0) {\r\n        while (n > 0) {\r\n   \
    \         if (n & 1) {\r\n                res *= x;\r\n                res %=\
    \ mod;\r\n            }\r\n            x = x * x;\r\n            x %= mod;\r\n\
    \            n >>= 1;\r\n        }\r\n        return res;\r\n    }\r\n    while\
    \ (n > 0) {\r\n        if (n & 1) {\r\n            res *= x;\r\n        }\r\n\
    \        x = x * x;\r\n        n >>= 1;\r\n    }\r\n    return res;\r\n}\r\n\r\
    \n}  // namespace ebi\n#line 5 \"test/pow.test.cpp\"\n\r\n#include <iostream>\r\
    \n\r\n#line 9 \"test/pow.test.cpp\"\n\r\nint main() {\r\n    u64 m, n;\r\n   \
    \ std::cin >> m >> n;\r\n    std::cout << ebi::pow(m, n, 1e9 + 7) << '\\n';\r\n\
    }\n"
  code: "#define PROBLEM \\\r\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \r\n\r\n#include \"../math/pow.hpp\"\r\n\r\n#include <iostream>\r\n\r\n#include\
    \ \"../utility/int_alias.hpp\"\r\n\r\nint main() {\r\n    u64 m, n;\r\n    std::cin\
    \ >> m >> n;\r\n    std::cout << ebi::pow(m, n, 1e9 + 7) << '\\n';\r\n}"
  dependsOn:
  - math/pow.hpp
  - utility/int_alias.hpp
  isVerificationFile: true
  path: test/pow.test.cpp
  requiredBy: []
  timestamp: '2023-05-08 18:41:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/pow.test.cpp
layout: document
redirect_from:
- /verify/test/pow.test.cpp
- /verify/test/pow.test.cpp.html
title: test/pow.test.cpp
---
