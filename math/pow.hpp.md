---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.hpp
    title: utility/int_alias.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/linear_sieve.hpp
    title: math/linear_sieve.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/pow.test.cpp
    title: test/pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/pow.hpp\"\n\r\n#line 2 \"utility/int_alias.hpp\"\n\r\
    \n#include <cstddef>\r\n#include <cstdint>\r\n\r\nusing i32 = std::int32_t;\r\n\
    using i64 = std::int64_t;\r\nusing u16 = std::uint16_t;\r\nusing u32 = std::uint32_t;\r\
    \nusing u64 = std::uint64_t;\r\nusing usize = std::size_t;\n#line 4 \"math/pow.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class T> T pow(T x, u64 n, u64 mod = -1)\
    \ {\r\n    T res = 1;\r\n    if (mod > 0) {\r\n        while (n > 0) {\r\n   \
    \         if (n & 1) {\r\n                res *= x;\r\n                res %=\
    \ mod;\r\n            }\r\n            x = x * x;\r\n            x %= mod;\r\n\
    \            n >>= 1;\r\n        }\r\n        return res;\r\n    }\r\n    while\
    \ (n > 0) {\r\n        if (n & 1) {\r\n            res *= x;\r\n        }\r\n\
    \        x = x * x;\r\n        n >>= 1;\r\n    }\r\n    return res;\r\n}\r\n\r\
    \n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include \"../utility/int_alias.hpp\"\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <class T> T pow(T x, u64 n, u64 mod = -1) {\r\n    T res\
    \ = 1;\r\n    if (mod > 0) {\r\n        while (n > 0) {\r\n            if (n &\
    \ 1) {\r\n                res *= x;\r\n                res %= mod;\r\n       \
    \     }\r\n            x = x * x;\r\n            x %= mod;\r\n            n >>=\
    \ 1;\r\n        }\r\n        return res;\r\n    }\r\n    while (n > 0) {\r\n \
    \       if (n & 1) {\r\n            res *= x;\r\n        }\r\n        x = x *\
    \ x;\r\n        n >>= 1;\r\n    }\r\n    return res;\r\n}\r\n\r\n}  // namespace\
    \ ebi"
  dependsOn:
  - utility/int_alias.hpp
  isVerificationFile: false
  path: math/pow.hpp
  requiredBy:
  - math/linear_sieve.hpp
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/pow.test.cpp
documentation_of: math/pow.hpp
layout: document
redirect_from:
- /library/math/pow.hpp
- /library/math/pow.hpp.html
title: math/pow.hpp
---
