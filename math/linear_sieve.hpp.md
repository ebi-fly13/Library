---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.hpp
    title: utility/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://37zigen.com/linear-sieve/
    - https://atcoder.jp/contests/abc162/submissions/25095562
  bundledCode: "#line 2 \"math/linear_sieve.hpp\"\n\r\n#line 2 \"utility/int_alias.hpp\"\
    \n\r\n#include <cstddef>\r\n#include <cstdint>\r\n\r\nusing std::size_t;\r\nusing\
    \ i8 = std::int8_t;\r\nusing u8 = std::uint8_t;\r\nusing i16 = std::int16_t;\r\
    \nusing u16 = std::uint16_t;\r\nusing i32 = std::int32_t;\r\nusing u32 = std::uint32_t;\r\
    \nusing i64 = std::int64_t;\r\nusing u64 = std::uint64_t;\r\nusing i128 = __int128_t;\r\
    \nusing u128 = __uint128_t;\n#line 4 \"math/linear_sieve.hpp\"\n\r\n/*\r\n   \
    \ reference: https://37zigen.com/linear-sieve/\r\n    verify:    https://atcoder.jp/contests/abc162/submissions/25095562\r\
    \n*/\r\n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\nstruct linear_sieve\
    \ {\r\n  private:\r\n    using u64 = std::uint64_t;\r\n    int n;\r\n    std::vector<int>\
    \ sieve;\r\n    std::vector<int> prime;\r\n\r\n  public:\r\n    linear_sieve(int\
    \ _n) : n(_n), sieve(std::vector<int>(_n + 1, -1)) {\r\n        for (int i = 2;\
    \ i <= n; i++) {\r\n            if (sieve[i] < 0) {\r\n                sieve[i]\
    \ = i;\r\n                prime.emplace_back(i);\r\n            }\r\n        \
    \    for (auto p : prime) {\r\n                if (u64(p) * u64(i) > u64(n) ||\
    \ p > sieve[i]) break;\r\n                sieve[p * i] = p;\r\n            }\r\
    \n        }\r\n    }\r\n\r\n    std::vector<int> prime_table() {\r\n        return\
    \ prime;\r\n    }\r\n\r\n    std::vector<std::pair<int, int>> factorize(int n)\
    \ {\r\n        std::vector<std::pair<int, int>> res;\r\n        while (n > 1)\
    \ {\r\n            int p = sieve[n];\r\n            int exp = 0;\r\n         \
    \   if (p < 0) {\r\n                res.emplace_back(n, 1);\r\n              \
    \  break;\r\n            }\r\n            while (sieve[n] == p) {\r\n        \
    \        n /= p;\r\n                exp++;\r\n            }\r\n            res.emplace_back(p,\
    \ exp);\r\n        }\r\n        return res;\r\n    }\r\n\r\n    std::vector<int>\
    \ divisors(int n) {\r\n        std::vector<int> res;\r\n        res.emplace_back(1);\r\
    \n        auto pf = factorize(n);\r\n        for (auto p : pf) {\r\n         \
    \   int sz = res.size();\r\n            for (int i = 0; i < sz; i++) {\r\n   \
    \             int ret = 1;\r\n                for (int j = 0; j < p.second; j++)\
    \ {\r\n                    ret *= p.first;\r\n                    res.emplace_back(res[i]\
    \ * ret);\r\n                }\r\n            }\r\n        }\r\n        return\
    \ res;\r\n    }\r\n\r\n    template <class T> std::vector<T> fast_zeta(const std::vector<T>\
    \ &f) {\r\n        std::vector<T> F = f;\r\n        int sz = f.size();\r\n   \
    \     assert(sz <= n + 1);\r\n        for (int i = 2; i < sz; i++) {\r\n     \
    \       if (sieve[i] != i) continue;\r\n            for (int j = (sz - 1) / i;\
    \ j >= 1; j--) {\r\n                F[j] += F[j * i];\r\n            }\r\n   \
    \     }\r\n        return F;\r\n    }\r\n\r\n    template <class T> std::vector<T>\
    \ fast_mobius(const std::vector<T> &F) {\r\n        std::vector<T> f = F;\r\n\
    \        int sz = F.size();\r\n        assert(sz <= n + 1);\r\n        for (int\
    \ i = 2; i < sz; i++) {\r\n            if (sieve[i] != i) continue;\r\n      \
    \      for (int j = 1; j * i < sz; j++) {\r\n                f[j] -= f[j * i];\r\
    \n            }\r\n        }\r\n        return f;\r\n    }\r\n\r\n    template\
    \ <class modint> std::vector<modint> pow_table(int k) {\r\n        std::vector<modint>\
    \ table(n + 1, 1);\r\n        table[0] = 0;\r\n        for (int i = 2; i <= n;\
    \ i++) {\r\n            if (sieve[i] == i) {\r\n                table[i] = modint(i).pow(k);\r\
    \n                continue;\r\n            }\r\n            table[i] = table[sieve[i]]\
    \ * table[i / sieve[i]];\r\n        }\r\n        return table;\r\n    }\r\n\r\n\
    \    template <class modint> std::vector<modint> inv_table() {\r\n        return\
    \ pow_table(modint::mod() - 2);\r\n    }\r\n};\r\n\r\n}  // namespace ebi\r\n"
  code: "#pragma once\r\n\r\n#include \"../utility/int_alias.hpp\"\r\n\r\n/*\r\n \
    \   reference: https://37zigen.com/linear-sieve/\r\n    verify:    https://atcoder.jp/contests/abc162/submissions/25095562\r\
    \n*/\r\n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\nstruct linear_sieve\
    \ {\r\n  private:\r\n    using u64 = std::uint64_t;\r\n    int n;\r\n    std::vector<int>\
    \ sieve;\r\n    std::vector<int> prime;\r\n\r\n  public:\r\n    linear_sieve(int\
    \ _n) : n(_n), sieve(std::vector<int>(_n + 1, -1)) {\r\n        for (int i = 2;\
    \ i <= n; i++) {\r\n            if (sieve[i] < 0) {\r\n                sieve[i]\
    \ = i;\r\n                prime.emplace_back(i);\r\n            }\r\n        \
    \    for (auto p : prime) {\r\n                if (u64(p) * u64(i) > u64(n) ||\
    \ p > sieve[i]) break;\r\n                sieve[p * i] = p;\r\n            }\r\
    \n        }\r\n    }\r\n\r\n    std::vector<int> prime_table() {\r\n        return\
    \ prime;\r\n    }\r\n\r\n    std::vector<std::pair<int, int>> factorize(int n)\
    \ {\r\n        std::vector<std::pair<int, int>> res;\r\n        while (n > 1)\
    \ {\r\n            int p = sieve[n];\r\n            int exp = 0;\r\n         \
    \   if (p < 0) {\r\n                res.emplace_back(n, 1);\r\n              \
    \  break;\r\n            }\r\n            while (sieve[n] == p) {\r\n        \
    \        n /= p;\r\n                exp++;\r\n            }\r\n            res.emplace_back(p,\
    \ exp);\r\n        }\r\n        return res;\r\n    }\r\n\r\n    std::vector<int>\
    \ divisors(int n) {\r\n        std::vector<int> res;\r\n        res.emplace_back(1);\r\
    \n        auto pf = factorize(n);\r\n        for (auto p : pf) {\r\n         \
    \   int sz = res.size();\r\n            for (int i = 0; i < sz; i++) {\r\n   \
    \             int ret = 1;\r\n                for (int j = 0; j < p.second; j++)\
    \ {\r\n                    ret *= p.first;\r\n                    res.emplace_back(res[i]\
    \ * ret);\r\n                }\r\n            }\r\n        }\r\n        return\
    \ res;\r\n    }\r\n\r\n    template <class T> std::vector<T> fast_zeta(const std::vector<T>\
    \ &f) {\r\n        std::vector<T> F = f;\r\n        int sz = f.size();\r\n   \
    \     assert(sz <= n + 1);\r\n        for (int i = 2; i < sz; i++) {\r\n     \
    \       if (sieve[i] != i) continue;\r\n            for (int j = (sz - 1) / i;\
    \ j >= 1; j--) {\r\n                F[j] += F[j * i];\r\n            }\r\n   \
    \     }\r\n        return F;\r\n    }\r\n\r\n    template <class T> std::vector<T>\
    \ fast_mobius(const std::vector<T> &F) {\r\n        std::vector<T> f = F;\r\n\
    \        int sz = F.size();\r\n        assert(sz <= n + 1);\r\n        for (int\
    \ i = 2; i < sz; i++) {\r\n            if (sieve[i] != i) continue;\r\n      \
    \      for (int j = 1; j * i < sz; j++) {\r\n                f[j] -= f[j * i];\r\
    \n            }\r\n        }\r\n        return f;\r\n    }\r\n\r\n    template\
    \ <class modint> std::vector<modint> pow_table(int k) {\r\n        std::vector<modint>\
    \ table(n + 1, 1);\r\n        table[0] = 0;\r\n        for (int i = 2; i <= n;\
    \ i++) {\r\n            if (sieve[i] == i) {\r\n                table[i] = modint(i).pow(k);\r\
    \n                continue;\r\n            }\r\n            table[i] = table[sieve[i]]\
    \ * table[i / sieve[i]];\r\n        }\r\n        return table;\r\n    }\r\n\r\n\
    \    template <class modint> std::vector<modint> inv_table() {\r\n        return\
    \ pow_table(modint::mod() - 2);\r\n    }\r\n};\r\n\r\n}  // namespace ebi\r\n"
  dependsOn:
  - utility/int_alias.hpp
  isVerificationFile: false
  path: math/linear_sieve.hpp
  requiredBy: []
  timestamp: '2023-06-19 12:46:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/linear_sieve.hpp
layout: document
redirect_from:
- /library/math/linear_sieve.hpp
- /library/math/linear_sieve.hpp.html
title: math/linear_sieve.hpp
---
