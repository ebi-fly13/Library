---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/dirichlet_convolution.hpp
    title: Dirichlet Convolution
  - icon: ':heavy_check_mark:'
    path: math/DirichletSeries.hpp
    title: Dirichlet Series
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Totient_Function.test.cpp
    title: test/math/Sum_of_Totient_Function.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://37zigen.com/linear-sieve/
    - https://atcoder.jp/contests/abc162/submissions/25095562
  bundledCode: "#line 2 \"math/linear_sieve.hpp\"\n\r\n#line 2 \"template/int_alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace ebi {\n\nusing std::size_t;\nusing i8 = std::int8_t;\n\
    using u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing u16 = std::uint16_t;\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    \n}\n#line 4 \"math/linear_sieve.hpp\"\n\r\n/*\r\n    reference: https://37zigen.com/linear-sieve/\r\
    \n    verify:    https://atcoder.jp/contests/abc162/submissions/25095562\r\n*/\r\
    \n\r\n#include <vector>\r\n#include <cassert>\r\n\r\nnamespace ebi {\r\n\r\nstruct\
    \ linear_sieve {\r\n  private:\r\n    using u64 = std::uint64_t;\r\n    int n;\r\
    \n    std::vector<int> sieve;\r\n    std::vector<int> prime;\r\n\r\n  public:\r\
    \n    linear_sieve(int _n) : n(_n), sieve(std::vector<int>(_n + 1, -1)) {\r\n\
    \        for (int i = 2; i <= n; i++) {\r\n            if (sieve[i] < 0) {\r\n\
    \                sieve[i] = i;\r\n                prime.emplace_back(i);\r\n \
    \           }\r\n            for (auto p : prime) {\r\n                if (u64(p)\
    \ * u64(i) > u64(n) || p > sieve[i]) break;\r\n                sieve[p * i] =\
    \ p;\r\n            }\r\n        }\r\n    }\r\n\r\n    std::vector<int> prime_table()\
    \ const {\r\n        return prime;\r\n    }\r\n\r\n    std::vector<std::pair<int,int>>\
    \ prime_power_table(int m) const {\r\n        assert(m <= n);\r\n        std::vector<std::pair<int,int>>\
    \ table(m+1, {1, 1});\r\n        for(int i = 2; i <= m; i++) {\r\n           \
    \ int p = sieve[i];\r\n            table[i] = {p, p};\r\n            if(sieve[i\
    \ / p] == p) {\r\n                table[i] = table[i / p];\r\n               \
    \ table[i].second *= p;\r\n            }\r\n        }\r\n        return table;\r\
    \n    }\r\n\r\n    std::vector<std::pair<int, int>> factorize(int x) {\r\n   \
    \     assert(x <= n);\r\n        std::vector<std::pair<int, int>> res;\r\n   \
    \     while (x > 1) {\r\n            int p = sieve[x];\r\n            int exp\
    \ = 0;\r\n            if (p < 0) {\r\n                res.emplace_back(x, 1);\r\
    \n                break;\r\n            }\r\n            while (sieve[x] == p)\
    \ {\r\n                x /= p;\r\n                exp++;\r\n            }\r\n\
    \            res.emplace_back(p, exp);\r\n        }\r\n        return res;\r\n\
    \    }\r\n\r\n    std::vector<int> divisors(int x) {\r\n        assert(x <= n);\r\
    \n        std::vector<int> res;\r\n        res.emplace_back(1);\r\n        auto\
    \ pf = factorize(x);\r\n        for (auto p : pf) {\r\n            int sz = (int)res.size();\r\
    \n            for (int i = 0; i < sz; i++) {\r\n                int ret = 1;\r\
    \n                for (int j = 0; j < p.second; j++) {\r\n                   \
    \ ret *= p.first;\r\n                    res.emplace_back(res[i] * ret);\r\n \
    \               }\r\n            }\r\n        }\r\n        return res;\r\n   \
    \ }\r\n\r\n    template <class T> std::vector<T> fast_zeta(const std::vector<T>\
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
  code: "#pragma once\r\n\r\n#include \"../template/int_alias.hpp\"\r\n\r\n/*\r\n\
    \    reference: https://37zigen.com/linear-sieve/\r\n    verify:    https://atcoder.jp/contests/abc162/submissions/25095562\r\
    \n*/\r\n\r\n#include <vector>\r\n#include <cassert>\r\n\r\nnamespace ebi {\r\n\
    \r\nstruct linear_sieve {\r\n  private:\r\n    using u64 = std::uint64_t;\r\n\
    \    int n;\r\n    std::vector<int> sieve;\r\n    std::vector<int> prime;\r\n\r\
    \n  public:\r\n    linear_sieve(int _n) : n(_n), sieve(std::vector<int>(_n + 1,\
    \ -1)) {\r\n        for (int i = 2; i <= n; i++) {\r\n            if (sieve[i]\
    \ < 0) {\r\n                sieve[i] = i;\r\n                prime.emplace_back(i);\r\
    \n            }\r\n            for (auto p : prime) {\r\n                if (u64(p)\
    \ * u64(i) > u64(n) || p > sieve[i]) break;\r\n                sieve[p * i] =\
    \ p;\r\n            }\r\n        }\r\n    }\r\n\r\n    std::vector<int> prime_table()\
    \ const {\r\n        return prime;\r\n    }\r\n\r\n    std::vector<std::pair<int,int>>\
    \ prime_power_table(int m) const {\r\n        assert(m <= n);\r\n        std::vector<std::pair<int,int>>\
    \ table(m+1, {1, 1});\r\n        for(int i = 2; i <= m; i++) {\r\n           \
    \ int p = sieve[i];\r\n            table[i] = {p, p};\r\n            if(sieve[i\
    \ / p] == p) {\r\n                table[i] = table[i / p];\r\n               \
    \ table[i].second *= p;\r\n            }\r\n        }\r\n        return table;\r\
    \n    }\r\n\r\n    std::vector<std::pair<int, int>> factorize(int x) {\r\n   \
    \     assert(x <= n);\r\n        std::vector<std::pair<int, int>> res;\r\n   \
    \     while (x > 1) {\r\n            int p = sieve[x];\r\n            int exp\
    \ = 0;\r\n            if (p < 0) {\r\n                res.emplace_back(x, 1);\r\
    \n                break;\r\n            }\r\n            while (sieve[x] == p)\
    \ {\r\n                x /= p;\r\n                exp++;\r\n            }\r\n\
    \            res.emplace_back(p, exp);\r\n        }\r\n        return res;\r\n\
    \    }\r\n\r\n    std::vector<int> divisors(int x) {\r\n        assert(x <= n);\r\
    \n        std::vector<int> res;\r\n        res.emplace_back(1);\r\n        auto\
    \ pf = factorize(x);\r\n        for (auto p : pf) {\r\n            int sz = (int)res.size();\r\
    \n            for (int i = 0; i < sz; i++) {\r\n                int ret = 1;\r\
    \n                for (int j = 0; j < p.second; j++) {\r\n                   \
    \ ret *= p.first;\r\n                    res.emplace_back(res[i] * ret);\r\n \
    \               }\r\n            }\r\n        }\r\n        return res;\r\n   \
    \ }\r\n\r\n    template <class T> std::vector<T> fast_zeta(const std::vector<T>\
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
  - template/int_alias.hpp
  isVerificationFile: false
  path: math/linear_sieve.hpp
  requiredBy:
  - convolution/dirichlet_convolution.hpp
  - math/DirichletSeries.hpp
  timestamp: '2023-08-23 17:33:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Sum_of_Totient_Function.test.cpp
documentation_of: math/linear_sieve.hpp
layout: document
title: Linear Sieve
---

## 説明

線形篩。線形で、 $[1, N]$ の整数の最小の素因数を求める。

### prime_table()

$[1, N]$ に含まれる素数を列挙する。 $O(N)$

### factorize(int n)

$n$ を素因数分解する。 $O(\log N)$

### divisors(int n)

$n$ の約数を列挙する。

### fast_zeta(std::vector<T> f)

$f$ を約数に関してゼータ変換（Multiple）する。 $O(N\log \log N)$

### fast_mobius(std::vector<T> F)

$F$ を約数に関してメビウス変換（Multiple）する。 $O(N\log \log N)$

### pow_table(int k)

$[1, N]$ に含まれる $i$ に対して $i^k$ を計算する。 $O(N \frac{\log k}{\log N})$

### inv_table()

$[1, N]$ に含まれる $i$ に対して $i^{-1} \mod m$ を計算する。 $O(N \frac{\log m}{\log N})$
