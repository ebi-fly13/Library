---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: utility/random_number_generator_64.hpp
    title: utility/random_number_generator_64.hpp
  - icon: ':x:'
    path: utility/safe_mod.hpp
    title: utility/safe_mod.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/aoj_2444.test.cpp
    title: test/aoj/aoj_2444.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
  bundledCode: "#line 2 \"String/rolling_hash.hpp\"\n\r\n#include <cassert>\r\n#include\
    \ <cstdint>\r\n#include <vector>\r\n\r\n#line 2 \"utility/random_number_generator_64.hpp\"\
    \n\r\n#line 4 \"utility/random_number_generator_64.hpp\"\n#include <random>\r\n\
    \r\nnamespace ebi {\r\n\r\nstruct random_number_generator_64 {\r\nprivate:\r\n\
    \    using u64 = std::uint64_t;\r\n    std::random_device rnd;\r\n    std::mt19937_64\
    \ mt;\r\npublic:\r\n    random_number_generator_64() : mt(rnd()) { }\r\n\r\n \
    \   u64 get(u64 a, u64 b) {\r\n        std::uniform_int_distribution<u64> dist(a,\
    \ b-1);\r\n        return dist(mt);\r\n    }\r\n};\r\n\r\n}\n#line 1 \"utility/safe_mod.hpp\"\
    \n\n#line 3 \"utility/safe_mod.hpp\"\n\nnamespace ebi {\n\nusing u64 = std::uint64_t;\n\
    const u64 mod = (1ull << 61) - 1;\nconst u64 MASK31 = (1ull << 31) - 1;\nconst\
    \ u64 MASK30 = (1ull << 30) - 1;\n\nu64 safe_mul(const u64 &a, const u64 &b) {\n\
    \    u64 au = a >> 31, ad = a & MASK31;\n    u64 bu = b >> 31, bd = b & MASK31;\n\
    \    u64 mid = ad * bu + au * bd;\n    u64 midu = mid >> 30;\n    u64 midd = mid\
    \ & MASK30;\n    return (au * bu * 2 + midu + (midd << 31) + ad * bd);\n}\n\n\
    u64 safe_mod(const u64 &a) {\n    u64 au = a >> 61;\n    u64 ad = a & mod;\n \
    \   u64 res = au + ad;\n    if (res >= mod) res -= mod;\n    return res;\n}\n\n\
    }  // namespace ebi\n#line 9 \"String/rolling_hash.hpp\"\n\r\n/*\r\n    reference:\
    \ https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\r\n*/\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <int n>\r\nstruct rolling_hash {\r\n   private:\r\n  \
    \  using u64 = std::uint64_t;\r\n    const u64 h = 100;\r\n    const u64 buffer\
    \ = mod * 4;\r\n\r\n   public:\r\n    rolling_hash(const std::string &s) : sz(s.size())\
    \ {\r\n        assert(int(base.size()) == n && n > 0);\r\n        base_pow.resize(n);\r\
    \n        hash.resize(n);\r\n        for (int i = 0; i < n; ++i) {\r\n       \
    \     base_pow[i].reserve(sz + 1);\r\n            base_pow[i].emplace_back(1);\r\
    \n            hash[i].reserve(sz + 1);\r\n            hash[i].emplace_back(0);\r\
    \n            for (const auto &c : s) {\r\n                hash[i].emplace_back(\r\
    \n                    safe_mod(safe_mul(hash[i].back(), base[i]) + c + h));\r\n\
    \                base_pow[i].emplace_back(\r\n                    safe_mod(safe_mul(base_pow[i].back(),\
    \ base[i])));\r\n            }\r\n        }\r\n    }\r\n\r\n    // [l, r)\r\n\
    \    std::vector<u64> get_hash(int l, int r) const {\r\n        std::vector<u64>\
    \ ret(n);\r\n        for (int i = 0; i < n; ++i) {\r\n            ret[i] = safe_mod(hash[i][r]\
    \ + buffer -\r\n                              safe_mul(hash[i][l], base_pow[i][r\
    \ - l]));\r\n        }\r\n        return ret;\r\n    }\r\n\r\n    std::vector<u64>\
    \ get_hash(const std::string &str, int l = 0,\r\n                            \
    \  int r = -1) const {\r\n        if (r < 0) r = int(str.size());\r\n        std::vector<u64>\
    \ res(n, 0);\r\n        for (int i = 0; i < n; ++i) {\r\n            for (int\
    \ j = l; j < r; ++j) {\r\n                res[i] = safe_mod(safe_mul(res[i], base[i])\
    \ + str[i] + h);\r\n            }\r\n        }\r\n        return res;\r\n    }\r\
    \n\r\n    static void set_base() {\r\n        random_number_generator_64 rnd;\r\
    \n        base.resize(n);\r\n        for (int i = 0; i < n; ++i) {\r\n       \
    \     base[i] = rnd.get(0, (1UL << 61) - 1);\r\n        }\r\n    }\r\n\r\n   private:\r\
    \n    size_t sz;\r\n    std::vector<std::vector<u64>> base_pow;\r\n    std::vector<std::vector<u64>>\
    \ hash;\r\n\r\n   public:\r\n    static std::vector<u64> base;\r\n};\r\n\r\ntemplate\
    \ <int n>\r\nstd::vector<std::uint64_t> rolling_hash<n>::base{12345, 10000000};\r\
    \n\r\n}  // namespace ebi\r\n"
  code: "#pragma once\r\n\r\n#include <cassert>\r\n#include <cstdint>\r\n#include\
    \ <vector>\r\n\r\n#include \"../utility/random_number_generator_64.hpp\"\r\n#include\
    \ \"../utility/safe_mod.hpp\"\r\n\r\n/*\r\n    reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\ntemplate <int n>\r\nstruct rolling_hash {\r\
    \n   private:\r\n    using u64 = std::uint64_t;\r\n    const u64 h = 100;\r\n\
    \    const u64 buffer = mod * 4;\r\n\r\n   public:\r\n    rolling_hash(const std::string\
    \ &s) : sz(s.size()) {\r\n        assert(int(base.size()) == n && n > 0);\r\n\
    \        base_pow.resize(n);\r\n        hash.resize(n);\r\n        for (int i\
    \ = 0; i < n; ++i) {\r\n            base_pow[i].reserve(sz + 1);\r\n         \
    \   base_pow[i].emplace_back(1);\r\n            hash[i].reserve(sz + 1);\r\n \
    \           hash[i].emplace_back(0);\r\n            for (const auto &c : s) {\r\
    \n                hash[i].emplace_back(\r\n                    safe_mod(safe_mul(hash[i].back(),\
    \ base[i]) + c + h));\r\n                base_pow[i].emplace_back(\r\n       \
    \             safe_mod(safe_mul(base_pow[i].back(), base[i])));\r\n          \
    \  }\r\n        }\r\n    }\r\n\r\n    // [l, r)\r\n    std::vector<u64> get_hash(int\
    \ l, int r) const {\r\n        std::vector<u64> ret(n);\r\n        for (int i\
    \ = 0; i < n; ++i) {\r\n            ret[i] = safe_mod(hash[i][r] + buffer -\r\n\
    \                              safe_mul(hash[i][l], base_pow[i][r - l]));\r\n\
    \        }\r\n        return ret;\r\n    }\r\n\r\n    std::vector<u64> get_hash(const\
    \ std::string &str, int l = 0,\r\n                              int r = -1) const\
    \ {\r\n        if (r < 0) r = int(str.size());\r\n        std::vector<u64> res(n,\
    \ 0);\r\n        for (int i = 0; i < n; ++i) {\r\n            for (int j = l;\
    \ j < r; ++j) {\r\n                res[i] = safe_mod(safe_mul(res[i], base[i])\
    \ + str[i] + h);\r\n            }\r\n        }\r\n        return res;\r\n    }\r\
    \n\r\n    static void set_base() {\r\n        random_number_generator_64 rnd;\r\
    \n        base.resize(n);\r\n        for (int i = 0; i < n; ++i) {\r\n       \
    \     base[i] = rnd.get(0, (1UL << 61) - 1);\r\n        }\r\n    }\r\n\r\n   private:\r\
    \n    size_t sz;\r\n    std::vector<std::vector<u64>> base_pow;\r\n    std::vector<std::vector<u64>>\
    \ hash;\r\n\r\n   public:\r\n    static std::vector<u64> base;\r\n};\r\n\r\ntemplate\
    \ <int n>\r\nstd::vector<std::uint64_t> rolling_hash<n>::base{12345, 10000000};\r\
    \n\r\n}  // namespace ebi\r\n"
  dependsOn:
  - utility/random_number_generator_64.hpp
  - utility/safe_mod.hpp
  isVerificationFile: false
  path: String/rolling_hash.hpp
  requiredBy: []
  timestamp: '2023-04-19 18:25:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/aoj_2444.test.cpp
documentation_of: String/rolling_hash.hpp
layout: document
redirect_from:
- /library/String/rolling_hash.hpp
- /library/String/rolling_hash.hpp.html
title: String/rolling_hash.hpp
---
