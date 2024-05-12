---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/binomial.hpp
    title: Binomial Coefficient
  - icon: ':heavy_check_mark:'
    path: math/lagrange_interpolation.hpp
    title: Lagrange Interpolation
  - icon: ':heavy_check_mark:'
    path: math/linear_sieve.hpp
    title: Linear Sieve
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':heavy_check_mark:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Exponential_Times_Polynomial.test.cpp
    title: test/math/Sum_of_Exponential_Times_Polynomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/sum_of_exp_times_poly.hpp\"\n\n#include <vector>\n\n\
    #line 2 \"math/binomial.hpp\"\n\n#include <bit>\n#include <cassert>\n#include\
    \ <iostream>\n#include <ranges>\n#line 8 \"math/binomial.hpp\"\n\n#line 2 \"modint/base.hpp\"\
    \n\n#include <concepts>\n#line 5 \"modint/base.hpp\"\n#include <utility>\n\nnamespace\
    \ ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n    a +\
    \ b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 10 \"\
    math/binomial.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint> struct Binomial\
    \ {\n  private:\n    static void extend(int len = -1) {\n        int sz = (int)fact.size();\n\
    \        if (len < 0)\n            len = 2 * sz;\n        else if (len <= sz)\n\
    \            return;\n        else\n            len = std::max(2 * sz, (int)std::bit_ceil(std::uint32_t(len)));\n\
    \        len = std::min(len, mint::mod());\n        assert(sz <= len);\n     \
    \   fact.resize(len);\n        inv_fact.resize(len);\n        for (int i : std::views::iota(sz,\
    \ len)) {\n            fact[i] = fact[i - 1] * i;\n        }\n        inv_fact[len\
    \ - 1] = fact[len - 1].inv();\n        for (int i : std::views::iota(sz, len)\
    \ | std::views::reverse) {\n            inv_fact[i - 1] = inv_fact[i] * i;\n \
    \       }\n    }\n\n  public:\n    Binomial() = default;\n\n    Binomial(int n)\
    \ {\n        extend(n + 1);\n    }\n\n    static mint f(int n) {\n        if (n\
    \ >= (int)fact.size()) [[unlikely]] {\n            extend(n + 1);\n        }\n\
    \        return fact[n];\n    }\n\n    static mint inv_f(int n) {\n        if\
    \ (n >= (int)fact.size()) [[unlikely]] {\n            extend(n + 1);\n       \
    \ }\n        return inv_fact[n];\n    }\n\n    static mint c(int n, int r) {\n\
    \        if (r < 0 || n < r) return 0;\n        return f(n) * inv_f(r) * inv_f(n\
    \ - r);\n    }\n\n    static mint neg_c(int k, int d) {\n        assert(d > 0);\n\
    \        return c(k + d - 1, d - 1);\n    }\n\n    static mint p(int n, int r)\
    \ {\n        if (r < 0 || n < r) return 0;\n        return f(n) * inv_f(n - r);\n\
    \    }\n\n    static mint inv(int n) {\n        return inv_f(n) * f(n - 1);\n\
    \    }\n\n    static void reserve(int n) {\n        extend(n + 1);\n    }\n\n\
    \  private:\n    static std::vector<mint> fact, inv_fact;\n};\n\ntemplate <Modint\
    \ mint>\nstd::vector<mint> Binomial<mint>::fact = std::vector<mint>(2, 1);\n\n\
    template <Modint mint>\nstd::vector<mint> Binomial<mint>::inv_fact = std::vector<mint>(2,\
    \ 1);\n\n}  // namespace ebi\n#line 2 \"math/lagrange_interpolation.hpp\"\n\n\
    #line 4 \"math/lagrange_interpolation.hpp\"\n\n/*\n    reference: https://atcoder.jp/contests/abc208/editorial/2195\n\
    \    verify: https://atcoder.jp/contests/abc208/tasks/abc208_f\n*/\n\nnamespace\
    \ ebi {\n\ntemplate <class mint>\nmint lagrange_interpolation(const std::vector<mint>\
    \ &f, long long n) {\n    const int d = int(f.size()) - 1;  // N\u306Ed\u6B21\u4EE5\
    \u4E0B\u306E\u591A\u9805\u5F0F\n    mint fact = 1;\n    std::vector<mint> inv_fact(d\
    \ + 1);\n    for (int i = 1; i < d + 1; ++i) {\n        fact *= i;\n    }\n  \
    \  inv_fact[d] = fact.inv();\n    for (int i = d; i > 0; i--) {\n        inv_fact[i\
    \ - 1] = inv_fact[i] * i;\n    }\n    std::vector<mint> l(d + 1), r(d + 1);\n\
    \    l[0] = 1;\n    for (int i = 0; i < d; ++i) {\n        l[i + 1] = l[i] * (n\
    \ - i);\n    }\n    r[d] = 1;\n    for (int i = d; i > 0; --i) {\n        r[i\
    \ - 1] = r[i] * (n - i);\n    }\n    mint res = 0;\n    for (int i = 0; i < d\
    \ + 1; ++i) {\n        res += mint((d - i) % 2 == 1 ? -1 : 1) * f[i] * l[i] *\
    \ r[i] *\n               inv_fact[i] * inv_fact[d - i];\n    }\n    return res;\n\
    }\n\n}  // namespace ebi\n#line 2 \"math/linear_sieve.hpp\"\n\r\n#line 2 \"template/int_alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace ebi {\n\nusing ld = long double;\nusing std::size_t;\n\
    using i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\n\
    using u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\n}  // namespace ebi\n#line 4 \"math/linear_sieve.hpp\"\
    \n\r\n/*\r\n    reference: https://37zigen.com/linear-sieve/\r\n    verify:  \
    \  https://atcoder.jp/contests/abc162/submissions/25095562\r\n*/\r\n\r\n#line\
    \ 12 \"math/linear_sieve.hpp\"\n\r\nnamespace ebi {\r\n\r\nstruct linear_sieve\
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
    #line 10 \"math/sum_of_exp_times_poly.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint\
    \ mint>\nmint sum_of_exp_times_poly(const std::vector<mint> &f, mint a, i64 n)\
    \ {\n    if (n == 0) return 0;\n    if (a == 0) return f[0];\n    if (a == 1)\
    \ {\n        std::vector<mint> g(f.size() + 1, 0);\n        for (int i = 1; i\
    \ < (int)g.size(); i++) {\n            g[i] = g[i - 1] + f[i - 1];\n        }\n\
    \        return lagrange_interpolation(g, n);\n    }\n    int k = (int)f.size()\
    \ - 1;\n    Binomial<mint> binom(k + 1);\n    std::vector<mint> g(k + 1, 0);\n\
    \    {\n        mint pow_a = 1;\n        for (int i = 0; i < k + 1; i++) {\n \
    \           g[i] = f[i] * pow_a;\n            pow_a *= a;\n        }\n       \
    \ for (int i = 0; i < k; i++) {\n            g[i + 1] += g[i];\n        }\n  \
    \  }\n    mint c = 0;\n    {\n        mint pow_neg_a = 1;\n        for (int i\
    \ = 0; i < k + 1; i++) {\n            c += binom.c(k + 1, i) * g[k - i] * pow_neg_a;\n\
    \            pow_neg_a *= -a;\n        }\n    }\n    c /= (1 - a).pow(k + 1);\n\
    \n    {\n        mint inv_a_pow = 1, inv_a = a.inv();\n        for (int i = 0;\
    \ i < k + 1; i++) {\n            g[i] = (-c + g[i]) * inv_a_pow;\n           \
    \ inv_a_pow *= inv_a;\n        }\n    }\n    mint tn = lagrange_interpolation(g,\
    \ n - 1);\n    return tn * a.pow(n - 1) + c;\n}\n\ntemplate <Modint mint> mint\
    \ sum_of_exp2(mint r, int d, i64 n) {\n    linear_sieve sieve(d);\n    auto f\
    \ = sieve.pow_table<mint>(d, d);\n    return sum_of_exp_times_poly(f, r, n);\n\
    }\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <vector>\n\n#include \"../math/binomial.hpp\"\n\
    #include \"../math/lagrange_interpolation.hpp\"\n#include \"../math/linear_sieve.hpp\"\
    \n#include \"../modint/base.hpp\"\n#include \"../template/int_alias.hpp\"\n\n\
    namespace ebi {\n\ntemplate <Modint mint>\nmint sum_of_exp_times_poly(const std::vector<mint>\
    \ &f, mint a, i64 n) {\n    if (n == 0) return 0;\n    if (a == 0) return f[0];\n\
    \    if (a == 1) {\n        std::vector<mint> g(f.size() + 1, 0);\n        for\
    \ (int i = 1; i < (int)g.size(); i++) {\n            g[i] = g[i - 1] + f[i - 1];\n\
    \        }\n        return lagrange_interpolation(g, n);\n    }\n    int k = (int)f.size()\
    \ - 1;\n    Binomial<mint> binom(k + 1);\n    std::vector<mint> g(k + 1, 0);\n\
    \    {\n        mint pow_a = 1;\n        for (int i = 0; i < k + 1; i++) {\n \
    \           g[i] = f[i] * pow_a;\n            pow_a *= a;\n        }\n       \
    \ for (int i = 0; i < k; i++) {\n            g[i + 1] += g[i];\n        }\n  \
    \  }\n    mint c = 0;\n    {\n        mint pow_neg_a = 1;\n        for (int i\
    \ = 0; i < k + 1; i++) {\n            c += binom.c(k + 1, i) * g[k - i] * pow_neg_a;\n\
    \            pow_neg_a *= -a;\n        }\n    }\n    c /= (1 - a).pow(k + 1);\n\
    \n    {\n        mint inv_a_pow = 1, inv_a = a.inv();\n        for (int i = 0;\
    \ i < k + 1; i++) {\n            g[i] = (-c + g[i]) * inv_a_pow;\n           \
    \ inv_a_pow *= inv_a;\n        }\n    }\n    mint tn = lagrange_interpolation(g,\
    \ n - 1);\n    return tn * a.pow(n - 1) + c;\n}\n\ntemplate <Modint mint> mint\
    \ sum_of_exp2(mint r, int d, i64 n) {\n    linear_sieve sieve(d);\n    auto f\
    \ = sieve.pow_table<mint>(d, d);\n    return sum_of_exp_times_poly(f, r, n);\n\
    }\n\n}  // namespace ebi"
  dependsOn:
  - math/binomial.hpp
  - modint/base.hpp
  - math/lagrange_interpolation.hpp
  - math/linear_sieve.hpp
  - template/int_alias.hpp
  isVerificationFile: false
  path: math/sum_of_exp_times_poly.hpp
  requiredBy: []
  timestamp: '2024-05-12 15:07:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/Sum_of_Exponential_Times_Polynomial.test.cpp
documentation_of: math/sum_of_exp_times_poly.hpp
layout: document
title: $\sum_{i = 0}^{n-1} a^i f(i)$
---

## 説明

$K$ 次多項式 $f(n)$ について、 $f(0), f(1), \dots, f(k)$ が与えられる。 
$\sum_{i = 0}^{n-1} a^i f(i)$ を $O(K + \log{mod})$ で求める。

### sum_of_exp_times_poly(f, a, n)

$K$ 次多項式 $f(n)$ の $f(0), f(1), \dots, f(k)$ と $a, n$ を与えて $\sum_{i = 0}^{n-1} a^i f(i)$ を求める。

### sum_of_exp2(r, d, n)

$f(n) = n^k$ について求める。つまり、 $\sum_{i = 0}^{n-1} r^i i^d$ を求める。

