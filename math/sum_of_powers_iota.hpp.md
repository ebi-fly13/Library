---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/lagrange_interpolation.hpp
    title: Lagrange Interpolation
  - icon: ':heavy_check_mark:'
    path: math/linear_sieve.hpp
    title: Linear Sieve
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':heavy_check_mark:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Powers_Iota.test.cpp
    title: test/math/Sum_of_Powers_Iota.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_2747.test.cpp
    title: test/yuki/yuki_2747.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/sum_of_powers_iota.hpp\"\n\n#include <cassert>\n\n\
    #line 2 \"math/lagrange_interpolation.hpp\"\n\n#include <vector>\n\n/*\n    reference:\
    \ https://atcoder.jp/contests/abc208/editorial/2195\n    verify: https://atcoder.jp/contests/abc208/tasks/abc208_f\n\
    */\n\nnamespace ebi {\n\ntemplate <class mint>\nmint lagrange_interpolation(const\
    \ std::vector<mint> &f, long long n) {\n    const int d = int(f.size()) - 1; \
    \ // N\u306Ed\u6B21\u4EE5\u4E0B\u306E\u591A\u9805\u5F0F\n    mint fact = 1;\n\
    \    std::vector<mint> inv_fact(d + 1);\n    for (int i = 1; i < d + 1; ++i) {\n\
    \        fact *= i;\n    }\n    inv_fact[d] = fact.inv();\n    for (int i = d;\
    \ i > 0; i--) {\n        inv_fact[i - 1] = inv_fact[i] * i;\n    }\n    std::vector<mint>\
    \ l(d + 1), r(d + 1);\n    l[0] = 1;\n    for (int i = 0; i < d; ++i) {\n    \
    \    l[i + 1] = l[i] * (n - i);\n    }\n    r[d] = 1;\n    for (int i = d; i >\
    \ 0; --i) {\n        r[i - 1] = r[i] * (n - i);\n    }\n    mint res = 0;\n  \
    \  for (int i = 0; i < d + 1; ++i) {\n        res += mint((d - i) % 2 == 1 ? -1\
    \ : 1) * f[i] * l[i] * r[i] *\n               inv_fact[i] * inv_fact[d - i];\n\
    \    }\n    return res;\n}\n\n}  // namespace ebi\n#line 2 \"math/linear_sieve.hpp\"\
    \n\r\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#include <iostream>\n\
    #include <utility>\n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint =\
    \ requires(T a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n\
    \    a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n};\n\ntemplate\
    \ <Modint mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long\
    \ long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <Modint mint>\n\
    std::ostream &operator<<(std::ostream &os, const mint &a) {\n    return os <<\
    \ a.val();\n}\n\n}  // namespace ebi\n#line 2 \"template/int_alias.hpp\"\n\n#include\
    \ <cstdint>\n\nnamespace ebi {\n\nusing ld = long double;\nusing std::size_t;\n\
    using i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\n\
    using u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\n}  // namespace ebi\n#line 5 \"math/linear_sieve.hpp\"\
    \n\r\n/*\r\n    reference: https://37zigen.com/linear-sieve/\r\n    verify:  \
    \  https://atcoder.jp/contests/abc162/submissions/25095562\r\n*/\r\n\r\n#line\
    \ 13 \"math/linear_sieve.hpp\"\n\r\nnamespace ebi {\r\n\r\nstruct linear_sieve\
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
    \ <Modint mint> std::vector<mint> pow_table(int m, int k) {\r\n        assert(m\
    \ <= n && k >= 0);\r\n        std::vector<mint> table(m + 1, 1);\r\n        table[0]\
    \ = (k == 0);\r\n        for (int i = 2; i <= m; i++) {\r\n            if (sieve[i]\
    \ == i) {\r\n                table[i] = mint(i).pow(k);\r\n                continue;\r\
    \n            }\r\n            table[i] = table[sieve[i]] * table[i / sieve[i]];\r\
    \n        }\r\n        return table;\r\n    }\r\n\r\n    template <Modint mint>\
    \ std::vector<mint> inv_table() {\r\n        return pow_table(mint::mod() - 2);\r\
    \n    }\r\n};\r\n\r\n}  // namespace ebi\r\n#line 8 \"math/sum_of_powers_iota.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint> mint sum_of_powers_iota(long long\
    \ n, int k) {\n    assert(n > 0 && k >= 0);\n    linear_sieve sieve(k + 1);\n\
    \    auto pow_table = sieve.pow_table<mint>(k + 1, k);\n    for (int i = 0; i\
    \ < k + 1; i++) {\n        pow_table[i + 1] += pow_table[i];\n    }\n    return\
    \ lagrange_interpolation(pow_table, n - 1);\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n\n#include \"../math/lagrange_interpolation.hpp\"\
    \n#include \"../math/linear_sieve.hpp\"\n#include \"../modint/base.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <Modint mint> mint sum_of_powers_iota(long long n, int k)\
    \ {\n    assert(n > 0 && k >= 0);\n    linear_sieve sieve(k + 1);\n    auto pow_table\
    \ = sieve.pow_table<mint>(k + 1, k);\n    for (int i = 0; i < k + 1; i++) {\n\
    \        pow_table[i + 1] += pow_table[i];\n    }\n    return lagrange_interpolation(pow_table,\
    \ n - 1);\n}\n\n}  // namespace ebi"
  dependsOn:
  - math/lagrange_interpolation.hpp
  - math/linear_sieve.hpp
  - modint/base.hpp
  - template/int_alias.hpp
  isVerificationFile: false
  path: math/sum_of_powers_iota.hpp
  requiredBy: []
  timestamp: '2024-05-21 15:55:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Sum_of_Powers_Iota.test.cpp
  - test/yuki/yuki_2747.test.cpp
documentation_of: math/sum_of_powers_iota.hpp
layout: document
title: $\sum_{i = 0}^{n-1} i^k$
---

## 説明

$\sum_{i = 0}^{n-1} i ^ k$ を $O(k)$ で求める。