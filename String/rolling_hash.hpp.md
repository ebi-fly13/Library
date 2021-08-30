---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/random_number_generator_64.hpp
    title: utility/random_number_generator_64.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/aoj_2444.test.cpp
    title: test/aoj/aoj_2444.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
  bundledCode: "#line 2 \"String/rolling_hash.hpp\"\n\r\n#include <vector>\r\n#include\
    \ <cstdint>\r\n\r\n#line 2 \"utility/random_number_generator_64.hpp\"\n\r\n#line\
    \ 4 \"utility/random_number_generator_64.hpp\"\n#include <random>\r\n\r\nnamespace\
    \ ebi {\r\n\r\nstruct random_number_generator_64 {\r\nprivate:\r\n    using u64\
    \ = std::uint64_t;\r\n    std::random_device rnd;\r\n    std::mt19937_64 mt;\r\
    \npublic:\r\n    random_number_generator_64() : mt(rnd()) { }\r\n\r\n    u64 get(u64\
    \ a, u64 b) {\r\n        std::uniform_int_distribution<u64> dist(a, b-1);\r\n\
    \        return dist(mt);\r\n    }\r\n};\r\n\r\n}\n#line 7 \"String/rolling_hash.hpp\"\
    \n\r\n/*\r\n    reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\ntemplate<int n>\r\nstruct rolling_hash {\r\n\
    private:\r\n    using u64 = std::uint64_t;\r\n    const u64 mod = (1UL<<61) -\
    \ 1;\r\n    const u64 MASK31 = (1UL<<31) - 1;\r\n    const u64 MASK30 = (1UL<<30)\
    \ - 1;\r\n    const u64 h = 100;\r\n    const u64 buffer = mod * 4;\r\n\r\n  \
    \  u64 safe_mul(const u64 &a, const u64 &b) const {\r\n        u64 au = a>>31,\
    \ ad = a&MASK31;\r\n        u64 bu = b>>31, bd = b&MASK31;\r\n        u64 mid\
    \ = ad*bu + au*bd;\r\n        u64 midu = mid>>30;\r\n        u64 midd = mid&MASK30;\r\
    \n        return (au * bu * 2 + midu + (midd << 31) + ad * bd);\r\n    }\r\n\r\
    \n    u64 safe_mod(const u64 &a) const {\r\n        u64 au = a >> 61;\r\n    \
    \    u64 ad = a & mod;\r\n        u64 res = au + ad;\r\n        if(res >= mod)\
    \ res -= mod;\r\n        return res;\r\n    }\r\npublic:\r\n    rolling_hash(const\
    \ std::string &_s) : s(_s), sz(_s.size()) {\r\n        base_pow.resize(n);\r\n\
    \        hash.resize(n);\r\n        for(int i = 0; i < n; ++i) {\r\n         \
    \   base_pow[i].reserve(sz+1);\r\n            base_pow[i].emplace_back(1);\r\n\
    \            hash[i].reserve(sz+1);\r\n            hash[i].emplace_back(0);\r\n\
    \            for(const auto &c: s) {\r\n                hash[i].emplace_back(safe_mod(safe_mul(hash[i].back(),\
    \ base[i]) + c + h));\r\n                base_pow[i].emplace_back(safe_mod(safe_mul(base_pow[i].back(),\
    \ base[i])));\r\n            }\r\n        }\r\n    }\r\n\r\n    // [l, r)\r\n\
    \    std::vector<u64> get_hash(int l, int r) const {\r\n        std::vector<u64>\
    \ ret(n);\r\n        for(int i = 0; i < n; ++i) {\r\n            ret[i] = safe_mod(hash[i][r]\
    \ + buffer - safe_mul(hash[i][l], base_pow[i][r-l]));\r\n        }\r\n       \
    \ return ret;\r\n    }\r\n\r\n    std::vector<u64> get_hash(const std::string\
    \ &str, int l = 0, int r = -1) const {\r\n        if(r < 0) r = int(str.size());\r\
    \n        std::vector<u64> res(n, 0);\r\n        for(int i = 0; i < n; ++i) {\r\
    \n            for(int j = l; j < r; ++j) {\r\n                res[i] = safe_mod(safe_mul(res[i],\
    \ base[i]) + s[i] + h);\r\n            }\r\n        }\r\n        return res;\r\
    \n    }\r\n\r\n    static void set_base() {\r\n        random_number_generator_64\
    \ rnd;\r\n        base.resize(n);\r\n        for(int i = 0; i < n; ++i) {\r\n\
    \            base[i] = rnd.get(0, (1UL<<61) - 1);\r\n        }\r\n    }\r\nprivate:\r\
    \n    std::string s;\r\n    size_t sz;\r\n    std::vector<std::vector<u64>> base_pow;\r\
    \n    std::vector<std::vector<u64>> hash;\r\npublic:\r\n    static std::vector<u64>\
    \ base;\r\n};\r\n\r\ntemplate<int n>\r\nstd::vector<std::uint64_t> rolling_hash<n>::base\
    \ = {12345, 10000000};\r\n\r\n}\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n#include <cstdint>\r\n\r\n#include\
    \ \"utility/random_number_generator_64.hpp\"\r\n\r\n/*\r\n    reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\ntemplate<int n>\r\nstruct rolling_hash {\r\n\
    private:\r\n    using u64 = std::uint64_t;\r\n    const u64 mod = (1UL<<61) -\
    \ 1;\r\n    const u64 MASK31 = (1UL<<31) - 1;\r\n    const u64 MASK30 = (1UL<<30)\
    \ - 1;\r\n    const u64 h = 100;\r\n    const u64 buffer = mod * 4;\r\n\r\n  \
    \  u64 safe_mul(const u64 &a, const u64 &b) const {\r\n        u64 au = a>>31,\
    \ ad = a&MASK31;\r\n        u64 bu = b>>31, bd = b&MASK31;\r\n        u64 mid\
    \ = ad*bu + au*bd;\r\n        u64 midu = mid>>30;\r\n        u64 midd = mid&MASK30;\r\
    \n        return (au * bu * 2 + midu + (midd << 31) + ad * bd);\r\n    }\r\n\r\
    \n    u64 safe_mod(const u64 &a) const {\r\n        u64 au = a >> 61;\r\n    \
    \    u64 ad = a & mod;\r\n        u64 res = au + ad;\r\n        if(res >= mod)\
    \ res -= mod;\r\n        return res;\r\n    }\r\npublic:\r\n    rolling_hash(const\
    \ std::string &_s) : s(_s), sz(_s.size()) {\r\n        base_pow.resize(n);\r\n\
    \        hash.resize(n);\r\n        for(int i = 0; i < n; ++i) {\r\n         \
    \   base_pow[i].reserve(sz+1);\r\n            base_pow[i].emplace_back(1);\r\n\
    \            hash[i].reserve(sz+1);\r\n            hash[i].emplace_back(0);\r\n\
    \            for(const auto &c: s) {\r\n                hash[i].emplace_back(safe_mod(safe_mul(hash[i].back(),\
    \ base[i]) + c + h));\r\n                base_pow[i].emplace_back(safe_mod(safe_mul(base_pow[i].back(),\
    \ base[i])));\r\n            }\r\n        }\r\n    }\r\n\r\n    // [l, r)\r\n\
    \    std::vector<u64> get_hash(int l, int r) const {\r\n        std::vector<u64>\
    \ ret(n);\r\n        for(int i = 0; i < n; ++i) {\r\n            ret[i] = safe_mod(hash[i][r]\
    \ + buffer - safe_mul(hash[i][l], base_pow[i][r-l]));\r\n        }\r\n       \
    \ return ret;\r\n    }\r\n\r\n    std::vector<u64> get_hash(const std::string\
    \ &str, int l = 0, int r = -1) const {\r\n        if(r < 0) r = int(str.size());\r\
    \n        std::vector<u64> res(n, 0);\r\n        for(int i = 0; i < n; ++i) {\r\
    \n            for(int j = l; j < r; ++j) {\r\n                res[i] = safe_mod(safe_mul(res[i],\
    \ base[i]) + s[i] + h);\r\n            }\r\n        }\r\n        return res;\r\
    \n    }\r\n\r\n    static void set_base() {\r\n        random_number_generator_64\
    \ rnd;\r\n        base.resize(n);\r\n        for(int i = 0; i < n; ++i) {\r\n\
    \            base[i] = rnd.get(0, (1UL<<61) - 1);\r\n        }\r\n    }\r\nprivate:\r\
    \n    std::string s;\r\n    size_t sz;\r\n    std::vector<std::vector<u64>> base_pow;\r\
    \n    std::vector<std::vector<u64>> hash;\r\npublic:\r\n    static std::vector<u64>\
    \ base;\r\n};\r\n\r\ntemplate<int n>\r\nstd::vector<std::uint64_t> rolling_hash<n>::base\
    \ = {12345, 10000000};\r\n\r\n}"
  dependsOn:
  - utility/random_number_generator_64.hpp
  isVerificationFile: false
  path: String/rolling_hash.hpp
  requiredBy: []
  timestamp: '2021-08-30 17:55:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/aoj_2444.test.cpp
documentation_of: String/rolling_hash.hpp
layout: document
redirect_from:
- /library/String/rolling_hash.hpp
- /library/String/rolling_hash.hpp.html
title: String/rolling_hash.hpp
---
