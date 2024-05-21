---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/eratosthenes_sieve.hpp
    title: Eratosthenes Sieve
  - icon: ':question:'
    path: math/linear_sieve.hpp
    title: Linear Sieve
  - icon: ':question:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  _extendedRequiredBy:
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
    links: []
  bundledCode: "#line 2 \"convolution/dirichlet_convolution.hpp\"\n\n#include <vector>\n\
    \n#line 2 \"math/eratosthenes_sieve.hpp\"\n\r\n#include <cassert>\r\n#include\
    \ <cstdint>\r\n#line 6 \"math/eratosthenes_sieve.hpp\"\n\r\n/*\r\n    reference:\
    \ https://37zigen.com/sieve-eratosthenes/\r\n*/\r\n\r\nnamespace ebi {\r\n\r\n\
    struct eratosthenes_sieve {\r\n  private:\r\n    using i64 = std::int_fast64_t;\r\
    \n    int n;\r\n    std::vector<bool> table;\r\n\r\n  public:\r\n    eratosthenes_sieve(int\
    \ _n) : n(_n), table(std::vector<bool>(n + 1, true)) {\r\n        table[1] = false;\r\
    \n        for (i64 i = 2; i * i <= n; i++) {\r\n            if (!table[i]) continue;\r\
    \n            for (i64 j = i; i * j <= n; j++) {\r\n                table[i *\
    \ j] = false;\r\n            }\r\n        }\r\n    }\r\n\r\n    bool is_prime(int\
    \ p) {\r\n        return table[p];\r\n    }\r\n\r\n    std::vector<int> prime_table(int\
    \ m = -1) {\r\n        if (m < 0) m = n;\r\n        std::vector<int> prime;\r\n\
    \        for (int i = 2; i <= m; i++) {\r\n            if (table[i]) prime.emplace_back(i);\r\
    \n        }\r\n        return prime;\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n\
    #line 2 \"math/linear_sieve.hpp\"\n\r\n#line 2 \"template/int_alias.hpp\"\n\n\
    #line 4 \"template/int_alias.hpp\"\n\nnamespace ebi {\n\nusing ld = long double;\n\
    using std::size_t;\nusing i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16\
    \ = std::int16_t;\nusing u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing\
    \ u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n\n}  // namespace ebi\n#line\
    \ 4 \"math/linear_sieve.hpp\"\n\r\n/*\r\n    reference: https://37zigen.com/linear-sieve/\r\
    \n    verify:    https://atcoder.jp/contests/abc162/submissions/25095562\r\n*/\r\
    \n\r\n#line 12 \"math/linear_sieve.hpp\"\n\r\nnamespace ebi {\r\n\r\nstruct linear_sieve\
    \ {\r\n  private:\r\n    using u64 = std::uint64_t;\r\n    int n;\r\n    std::vector<int>\
    \ sieve;\r\n    std::vector<int> prime;\r\n\r\n  public:\r\n    linear_sieve(int\
    \ _n) : n(_n), sieve(std::vector<int>(_n + 1, -1)) {\r\n        for (int i = 2;\
    \ i <= n; i++) {\r\n            if (sieve[i] < 0) {\r\n                sieve[i]\
    \ = i;\r\n                prime.emplace_back(i);\r\n            }\r\n        \
    \    for (auto p : prime) {\r\n                if (u64(p) * u64(i) > u64(n) ||\
    \ p > sieve[i]) break;\r\n                sieve[p * i] = p;\r\n            }\r\
    \n        }\r\n    }\r\n\r\n    std::vector<int> prime_table() const {\r\n   \
    \     return prime;\r\n    }\r\n\r\n    std::vector<std::pair<int, int>> prime_power_table(int\
    \ m) const {\r\n        assert(m <= n);\r\n        std::vector<std::pair<int,\
    \ int>> table(m + 1, {1, 1});\r\n        for (int i = 2; i <= m; i++) {\r\n  \
    \          int p = sieve[i];\r\n            table[i] = {p, p};\r\n           \
    \ if (sieve[i / p] == p) {\r\n                table[i] = table[i / p];\r\n   \
    \             table[i].second *= p;\r\n            }\r\n        }\r\n        return\
    \ table;\r\n    }\r\n\r\n    std::vector<std::pair<int, int>> factorize(int x)\
    \ {\r\n        assert(x <= n);\r\n        std::vector<std::pair<int, int>> res;\r\
    \n        while (x > 1) {\r\n            int p = sieve[x];\r\n            int\
    \ exp = 0;\r\n            if (p < 0) {\r\n                res.emplace_back(x,\
    \ 1);\r\n                break;\r\n            }\r\n            while (sieve[x]\
    \ == p) {\r\n                x /= p;\r\n                exp++;\r\n           \
    \ }\r\n            res.emplace_back(p, exp);\r\n        }\r\n        return res;\r\
    \n    }\r\n\r\n    std::vector<int> divisors(int x) {\r\n        assert(x <= n);\r\
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
    \ <class modint> std::vector<modint> pow_table(int m, int k) {\r\n        assert(m\
    \ <= n && k >= 0);\r\n        std::vector<modint> table(m + 1, 1);\r\n       \
    \ table[0] = (k == 0);\r\n        for (int i = 2; i <= m; i++) {\r\n         \
    \   if (sieve[i] == i) {\r\n                table[i] = modint(i).pow(k);\r\n \
    \               continue;\r\n            }\r\n            table[i] = table[sieve[i]]\
    \ * table[i / sieve[i]];\r\n        }\r\n        return table;\r\n    }\r\n\r\n\
    \    template <class modint> std::vector<modint> inv_table() {\r\n        return\
    \ pow_table(modint::mod() - 2);\r\n    }\r\n};\r\n\r\n}  // namespace ebi\r\n\
    #line 7 \"convolution/dirichlet_convolution.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class T>\nstd::vector<T> dirichlet_convolution(const std::vector<T> &a,\n \
    \                                    const std::vector<T> &b) {\n    assert(a.size()\
    \ == b.size());\n    int n = a.size() - 1;\n    std::vector<T> c(n + 1, 0);\n\
    \    for (int i = 1; i <= n; i++) {\n        for (int j = 1; i * j <= n; j++)\
    \ {\n            c[i * j] += a[i] * b[j];\n        }\n    }\n    return c;\n}\n\
    \ntemplate <class T>\nstd::vector<T> dirichlet_convolution_left_is_multiplicative_function(\n\
    \    const std::vector<T> &a, const std::vector<T> &b) {\n    assert(a.size()\
    \ == b.size());\n    int n = a.size() - 1;\n    static int m = 1;\n    static\
    \ std::vector<int> primes;\n    if (m < n) {\n        while (m < n) m <<= 1;\n\
    \        eratosthenes_sieve sieve(m);\n        primes = sieve.prime_table();\n\
    \    }\n    std::vector<T> c = b;\n    for (auto p : primes) {\n        if (p\
    \ > n) break;\n        for (int i = n / p; i >= 1; i--) {\n            int s =\
    \ p * i;\n            int pk = p, j = i;\n            while (1) {\n          \
    \      c[s] += a[pk] * c[j];\n                if (j % p != 0) break;\n       \
    \         pk *= p;\n                j /= p;\n            }\n        }\n    }\n\
    \    return c;\n}\n\ntemplate <class T>\nstd::vector<T> dirichlet_convolution_multiplicative_function(\n\
    \    const std::vector<T> &a, const std::vector<T> &b) {\n    assert(a.size()\
    \ == b.size());\n    int n = a.size() - 1;\n    static int m = 1;\n    static\
    \ std::vector<std::pair<int, int>> prime_pow_table;\n    if (m < n) {\n      \
    \  while (m < n) m <<= 1;\n        linear_sieve sieve(m);\n        prime_pow_table\
    \ = sieve.prime_power_table(m);\n    }\n    std::vector<T> c(n + 1, 0);\n    c[1]\
    \ = a[1] * b[1];\n    for (int i = 2; i <= n; i++) {\n        auto [p, pk] = prime_pow_table[i];\n\
    \        if (pk == i) {\n            for (int j = 1; j <= i; j *= p) {\n     \
    \           c[i] += a[j] * b[i / j];\n            }\n        } else {\n      \
    \      c[i] = c[i / pk] * c[pk];\n        }\n    }\n    return c;\n}\n\n}  //\
    \ namespace ebi\n"
  code: "#pragma once\n\n#include <vector>\n\n#include \"../math/eratosthenes_sieve.hpp\"\
    \n#include \"../math/linear_sieve.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ T>\nstd::vector<T> dirichlet_convolution(const std::vector<T> &a,\n        \
    \                             const std::vector<T> &b) {\n    assert(a.size()\
    \ == b.size());\n    int n = a.size() - 1;\n    std::vector<T> c(n + 1, 0);\n\
    \    for (int i = 1; i <= n; i++) {\n        for (int j = 1; i * j <= n; j++)\
    \ {\n            c[i * j] += a[i] * b[j];\n        }\n    }\n    return c;\n}\n\
    \ntemplate <class T>\nstd::vector<T> dirichlet_convolution_left_is_multiplicative_function(\n\
    \    const std::vector<T> &a, const std::vector<T> &b) {\n    assert(a.size()\
    \ == b.size());\n    int n = a.size() - 1;\n    static int m = 1;\n    static\
    \ std::vector<int> primes;\n    if (m < n) {\n        while (m < n) m <<= 1;\n\
    \        eratosthenes_sieve sieve(m);\n        primes = sieve.prime_table();\n\
    \    }\n    std::vector<T> c = b;\n    for (auto p : primes) {\n        if (p\
    \ > n) break;\n        for (int i = n / p; i >= 1; i--) {\n            int s =\
    \ p * i;\n            int pk = p, j = i;\n            while (1) {\n          \
    \      c[s] += a[pk] * c[j];\n                if (j % p != 0) break;\n       \
    \         pk *= p;\n                j /= p;\n            }\n        }\n    }\n\
    \    return c;\n}\n\ntemplate <class T>\nstd::vector<T> dirichlet_convolution_multiplicative_function(\n\
    \    const std::vector<T> &a, const std::vector<T> &b) {\n    assert(a.size()\
    \ == b.size());\n    int n = a.size() - 1;\n    static int m = 1;\n    static\
    \ std::vector<std::pair<int, int>> prime_pow_table;\n    if (m < n) {\n      \
    \  while (m < n) m <<= 1;\n        linear_sieve sieve(m);\n        prime_pow_table\
    \ = sieve.prime_power_table(m);\n    }\n    std::vector<T> c(n + 1, 0);\n    c[1]\
    \ = a[1] * b[1];\n    for (int i = 2; i <= n; i++) {\n        auto [p, pk] = prime_pow_table[i];\n\
    \        if (pk == i) {\n            for (int j = 1; j <= i; j *= p) {\n     \
    \           c[i] += a[j] * b[i / j];\n            }\n        } else {\n      \
    \      c[i] = c[i / pk] * c[pk];\n        }\n    }\n    return c;\n}\n\n}  //\
    \ namespace ebi"
  dependsOn:
  - math/eratosthenes_sieve.hpp
  - math/linear_sieve.hpp
  - template/int_alias.hpp
  isVerificationFile: false
  path: convolution/dirichlet_convolution.hpp
  requiredBy:
  - math/DirichletSeries.hpp
  timestamp: '2024-05-11 16:30:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Sum_of_Totient_Function.test.cpp
documentation_of: convolution/dirichlet_convolution.hpp
layout: document
title: Dirichlet Convolution
---

## 説明

$a,b$ を与えて、 Dirichlet積 $c = a \times b$ を求める。

### 通常のDirichlet積

```dirichlet_convolution(a, b)```を用いる。
愚直にDirichlet積を求める。 $O(N\log N)$

### $a$ が乗法的関数のとき

```dirichlet_convolution_left_is_multiplicative_function(a, b)```

$a$ が乗法的関数であるとき、高速にDirichlet積を求めることができる。 $O(N\log \log N)$

### $a, b$ が乗法的関数のとき

```dirichlet_convolution_multiplicative_function(a, b)```を用いる。
$a, b$ が共に乗法的関数であるとき、さらに高速にDirichlet積を求めることができる。 $O(N)$