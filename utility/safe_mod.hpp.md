---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: String/rolling_hash.hpp
    title: String/rolling_hash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2444.test.cpp
    title: test/aoj/aoj_2444.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/safe_mod.hpp\"\n\n#include <cstdint>\n\nnamespace\
    \ ebi {\n\nusing u64 = std::uint64_t;\nconst u64 mod = (1ull << 61) - 1;\nconst\
    \ u64 MASK31 = (1ull << 31) - 1;\nconst u64 MASK30 = (1ull << 30) - 1;\n\nu64\
    \ safe_mul(const u64 &a, const u64 &b) {\n    u64 au = a >> 31, ad = a & MASK31;\n\
    \    u64 bu = b >> 31, bd = b & MASK31;\n    u64 mid = ad * bu + au * bd;\n  \
    \  u64 midu = mid >> 30;\n    u64 midd = mid & MASK30;\n    return (au * bu *\
    \ 2 + midu + (midd << 31) + ad * bd);\n}\n\nu64 safe_mod(const u64 &a) {\n   \
    \ u64 au = a >> 61;\n    u64 ad = a & mod;\n    u64 res = au + ad;\n    if (res\
    \ >= mod) res -= mod;\n    return res;\n}\n\n}  // namespace ebi\n"
  code: "\n#include <cstdint>\n\nnamespace ebi {\n\nusing u64 = std::uint64_t;\nconst\
    \ u64 mod = (1ull << 61) - 1;\nconst u64 MASK31 = (1ull << 31) - 1;\nconst u64\
    \ MASK30 = (1ull << 30) - 1;\n\nu64 safe_mul(const u64 &a, const u64 &b) {\n \
    \   u64 au = a >> 31, ad = a & MASK31;\n    u64 bu = b >> 31, bd = b & MASK31;\n\
    \    u64 mid = ad * bu + au * bd;\n    u64 midu = mid >> 30;\n    u64 midd = mid\
    \ & MASK30;\n    return (au * bu * 2 + midu + (midd << 31) + ad * bd);\n}\n\n\
    u64 safe_mod(const u64 &a) {\n    u64 au = a >> 61;\n    u64 ad = a & mod;\n \
    \   u64 res = au + ad;\n    if (res >= mod) res -= mod;\n    return res;\n}\n\n\
    }  // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: utility/safe_mod.hpp
  requiredBy:
  - String/rolling_hash.hpp
  timestamp: '2023-04-19 18:25:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_2444.test.cpp
documentation_of: utility/safe_mod.hpp
layout: document
redirect_from:
- /library/utility/safe_mod.hpp
- /library/utility/safe_mod.hpp.html
title: utility/safe_mod.hpp
---
