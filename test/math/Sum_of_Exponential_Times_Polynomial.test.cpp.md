---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':question:'
    path: graph/base.hpp
    title: Graph (CSR format)
  - icon: ':question:'
    path: math/binomial.hpp
    title: Binomial Coefficient
  - icon: ':heavy_check_mark:'
    path: math/lagrange_interpolation.hpp
    title: Lagrange Interpolation
  - icon: ':heavy_check_mark:'
    path: math/linear_sieve.hpp
    title: Linear Sieve
  - icon: ':heavy_check_mark:'
    path: math/sum_of_exp_times_poly.hpp
    title: $\sum_{i = 0}^{n-1} a^i f(i)$
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':question:'
    path: template/debug_template.hpp
    title: template/debug_template.hpp
  - icon: ':question:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  - icon: ':question:'
    path: template/io.hpp
    title: template/io.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/utility.hpp
    title: template/utility.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial
    links:
    - https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial
  bundledCode: "#line 1 \"test/math/Sum_of_Exponential_Times_Polynomial.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial\"\
    \n\n#line 2 \"math/sum_of_exp_times_poly.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\n#line 2 \"math/binomial.hpp\"\n\n#include <bit>\n#line 5 \"math/binomial.hpp\"\
    \n#include <cstdint>\n#include <iostream>\n#include <ranges>\n#line 9 \"math/binomial.hpp\"\
    \n\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#line 5 \"modint/base.hpp\"\
    \n#include <utility>\n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint\
    \ = requires(T a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n   \
    \ a.inv();\n    a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n\
    };\n\ntemplate <Modint mint> std::istream &operator>>(std::istream &os, mint &a)\
    \ {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate\
    \ <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const mint &a) {\n\
    \    return os << a.val();\n}\n\n}  // namespace ebi\n#line 11 \"math/binomial.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint> struct Binomial {\n  private:\n\
    \    static void extend(int len = -1) {\n        int sz = (int)fact.size();\n\
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
    \    }\n\n    static mint catalan_number(int n) {\n        return c(2 * n, n)\
    \ * inv(n + 1);\n    }\n\n    static mint inv(int n) {\n        return inv_f(n)\
    \ * f(n - 1);\n    }\n\n    static void reserve(int n) {\n        extend(n + 1);\n\
    \    }\n\n  private:\n    static std::vector<mint> fact, inv_fact;\n};\n\ntemplate\
    \ <Modint mint>\nstd::vector<mint> Binomial<mint>::fact = std::vector<mint>(2,\
    \ 1);\n\ntemplate <Modint mint>\nstd::vector<mint> Binomial<mint>::inv_fact =\
    \ std::vector<mint>(2, 1);\n\n}  // namespace ebi\n#line 2 \"math/lagrange_interpolation.hpp\"\
    \n\n#line 4 \"math/lagrange_interpolation.hpp\"\n\n/*\n    reference: https://atcoder.jp/contests/abc208/editorial/2195\n\
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
    \n\n#line 4 \"template/int_alias.hpp\"\n\nnamespace ebi {\n\nusing ld = long double;\n\
    using std::size_t;\nusing i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16\
    \ = std::int16_t;\nusing u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing\
    \ u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n\n}  // namespace ebi\n#line\
    \ 5 \"math/linear_sieve.hpp\"\n\r\n/*\r\n    reference: https://37zigen.com/linear-sieve/\r\
    \n    verify:    https://atcoder.jp/contests/abc162/submissions/25095562\r\n*/\r\
    \n\r\n#line 13 \"math/linear_sieve.hpp\"\n\r\nnamespace ebi {\r\n\r\nstruct linear_sieve\
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
    \n    }\r\n};\r\n\r\n}  // namespace ebi\r\n#line 11 \"math/sum_of_exp_times_poly.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint>\nmint sum_of_exp_times_poly(const\
    \ std::vector<mint> &f, mint a, i64 n) {\n    if (n == 0) return 0;\n    if (a\
    \ == 0) return f[0];\n    if (a == 1) {\n        std::vector<mint> g(f.size()\
    \ + 1, 0);\n        for (int i = 1; i < (int)g.size(); i++) {\n            g[i]\
    \ = g[i - 1] + f[i - 1];\n        }\n        return lagrange_interpolation(g,\
    \ n);\n    }\n    int k = (int)f.size() - 1;\n    Binomial<mint> binom(k + 1);\n\
    \    std::vector<mint> g(k + 1, 0);\n    {\n        mint pow_a = 1;\n        for\
    \ (int i = 0; i < k + 1; i++) {\n            g[i] = f[i] * pow_a;\n          \
    \  pow_a *= a;\n        }\n        for (int i = 0; i < k; i++) {\n           \
    \ g[i + 1] += g[i];\n        }\n    }\n    mint c = 0;\n    {\n        mint pow_neg_a\
    \ = 1;\n        for (int i = 0; i < k + 1; i++) {\n            c += binom.c(k\
    \ + 1, i) * g[k - i] * pow_neg_a;\n            pow_neg_a *= -a;\n        }\n \
    \   }\n    c /= (1 - a).pow(k + 1);\n\n    {\n        mint inv_a_pow = 1, inv_a\
    \ = a.inv();\n        for (int i = 0; i < k + 1; i++) {\n            g[i] = (-c\
    \ + g[i]) * inv_a_pow;\n            inv_a_pow *= inv_a;\n        }\n    }\n  \
    \  mint tn = lagrange_interpolation(g, n - 1);\n    return tn * a.pow(n - 1) +\
    \ c;\n}\n\ntemplate <Modint mint>\nmint sum_of_exp_times_poly_limit(const std::vector<mint>\
    \ &f, mint a) {\n    assert(a != 1);\n    if (a == 0) return f[0];\n    int k\
    \ = (int)f.size() - 1;\n    Binomial<mint> binom(k + 1);\n    std::vector<mint>\
    \ g(k + 1, 0);\n    {\n        mint pow_a = 1;\n        for (int i = 0; i < k\
    \ + 1; i++) {\n            g[i] = f[i] * pow_a;\n            pow_a *= a;\n   \
    \     }\n        for (int i = 0; i < k; i++) {\n            g[i + 1] += g[i];\n\
    \        }\n    }\n    mint c = 0;\n    {\n        mint pow_neg_a = 1;\n     \
    \   for (int i = 0; i < k + 1; i++) {\n            c += binom.c(k + 1, i) * g[k\
    \ - i] * pow_neg_a;\n            pow_neg_a *= -a;\n        }\n    }\n    c /=\
    \ (1 - a).pow(k + 1);\n    return c;\n}\n\ntemplate <Modint mint> mint sum_of_exp2(mint\
    \ r, int d, i64 n) {\n    linear_sieve sieve(d);\n    auto f = sieve.pow_table<mint>(d,\
    \ d);\n    return sum_of_exp_times_poly(f, r, n);\n}\n\ntemplate <Modint mint>\
    \ mint sum_of_exp2_limit(mint r, int d) {\n    linear_sieve sieve(d);\n    auto\
    \ f = sieve.pow_table<mint>(d, d);\n    return sum_of_exp_times_poly_limit(f,\
    \ r);\n}\n\n}  // namespace ebi\n#line 2 \"modint/modint.hpp\"\n\r\n#line 5 \"\
    modint/modint.hpp\"\n\r\n#line 7 \"modint/modint.hpp\"\n\r\nnamespace ebi {\r\n\
    \r\ntemplate <int m> struct static_modint {\r\n  private:\r\n    using modint\
    \ = static_modint;\r\n\r\n  public:\r\n    static constexpr int mod() {\r\n  \
    \      return m;\r\n    }\r\n\r\n    static constexpr modint raw(int v) {\r\n\
    \        modint x;\r\n        x._v = v;\r\n        return x;\r\n    }\r\n\r\n\
    \    constexpr static_modint() : _v(0) {}\r\n\r\n    template <std::signed_integral\
    \ T> constexpr static_modint(T v) {\r\n        long long x = (long long)(v % (long\
    \ long)(umod()));\r\n        if (x < 0) x += umod();\r\n        _v = (unsigned\
    \ int)(x);\r\n    }\r\n\r\n    template <std::unsigned_integral T> constexpr static_modint(T\
    \ v) {\r\n        _v = (unsigned int)(v % umod());\r\n    }\r\n\r\n    constexpr\
    \ unsigned int val() const {\r\n        return _v;\r\n    }\r\n\r\n    constexpr\
    \ unsigned int value() const {\r\n        return val();\r\n    }\r\n\r\n    constexpr\
    \ modint &operator++() {\r\n        _v++;\r\n        if (_v == umod()) _v = 0;\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator--() {\r\n \
    \       if (_v == 0) _v = umod();\r\n        _v--;\r\n        return *this;\r\n\
    \    }\r\n\r\n    constexpr modint operator++(int) {\r\n        modint res = *this;\r\
    \n        ++*this;\r\n        return res;\r\n    }\r\n    constexpr modint operator--(int)\
    \ {\r\n        modint res = *this;\r\n        --*this;\r\n        return res;\r\
    \n    }\r\n\r\n    constexpr modint &operator+=(const modint &rhs) {\r\n     \
    \   _v += rhs._v;\r\n        if (_v >= umod()) _v -= umod();\r\n        return\
    \ *this;\r\n    }\r\n    constexpr modint &operator-=(const modint &rhs) {\r\n\
    \        _v -= rhs._v;\r\n        if (_v >= umod()) _v += umod();\r\n        return\
    \ *this;\r\n    }\r\n    constexpr modint &operator*=(const modint &rhs) {\r\n\
    \        unsigned long long x = _v;\r\n        x *= rhs._v;\r\n        _v = (unsigned\
    \ int)(x % (unsigned long long)umod());\r\n        return *this;\r\n    }\r\n\
    \    constexpr modint &operator/=(const modint &rhs) {\r\n        return *this\
    \ = *this * rhs.inv();\r\n    }\r\n\r\n    constexpr modint operator+() const\
    \ {\r\n        return *this;\r\n    }\r\n    constexpr modint operator-() const\
    \ {\r\n        return modint() - *this;\r\n    }\r\n\r\n    constexpr modint pow(long\
    \ long n) const {\r\n        assert(0 <= n);\r\n        modint x = *this, res\
    \ = 1;\r\n        while (n) {\r\n            if (n & 1) res *= x;\r\n        \
    \    x *= x;\r\n            n >>= 1;\r\n        }\r\n        return res;\r\n \
    \   }\r\n    constexpr modint inv() const {\r\n        assert(_v);\r\n       \
    \ return pow(umod() - 2);\r\n    }\r\n\r\n    friend modint operator+(const modint\
    \ &lhs, const modint &rhs) {\r\n        return modint(lhs) += rhs;\r\n    }\r\n\
    \    friend modint operator-(const modint &lhs, const modint &rhs) {\r\n     \
    \   return modint(lhs) -= rhs;\r\n    }\r\n    friend modint operator*(const modint\
    \ &lhs, const modint &rhs) {\r\n        return modint(lhs) *= rhs;\r\n    }\r\n\
    \r\n    friend modint operator/(const modint &lhs, const modint &rhs) {\r\n  \
    \      return modint(lhs) /= rhs;\r\n    }\r\n    friend bool operator==(const\
    \ modint &lhs, const modint &rhs) {\r\n        return lhs.val() == rhs.val();\r\
    \n    }\r\n    friend bool operator!=(const modint &lhs, const modint &rhs) {\r\
    \n        return !(lhs == rhs);\r\n    }\r\n\r\n  private:\r\n    unsigned int\
    \ _v = 0;\r\n\r\n    static constexpr unsigned int umod() {\r\n        return\
    \ m;\r\n    }\r\n};\r\n\r\nusing modint998244353 = static_modint<998244353>;\r\
    \nusing modint1000000007 = static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n\
    #line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ a, n) for (int i = (int)(a); i < (int)(n); i++)\n#define rrep(i, a, n) for (int\
    \ i = ((int)(n)-1); i >= (int)(a); i--)\n#define Rep(i, a, n) for (i64 i = (i64)(a);\
    \ i < (i64)(n); i++)\n#define RRep(i, a, n) for (i64 i = ((i64)(n)-i64(1)); i\
    \ >= (i64)(a); i--)\n#define all(v) (v).begin(), (v).end()\n#define rall(v) (v).rbegin(),\
    \ (v).rend()\n\n#line 2 \"template/debug_template.hpp\"\n\n#line 4 \"template/debug_template.hpp\"\
    \n\nnamespace ebi {\n\n#ifdef LOCAL\n#define debug(...)                      \
    \                                \\\n    std::cerr << \"LINE: \" << __LINE__ <<\
    \ \"  [\" << #__VA_ARGS__ << \"]:\", \\\n        debug_out(__VA_ARGS__)\n#else\n\
    #define debug(...)\n#endif\n\nvoid debug_out() {\n    std::cerr << std::endl;\n\
    }\n\ntemplate <typename Head, typename... Tail> void debug_out(Head h, Tail...\
    \ t) {\n    std::cerr << \" \" << h;\n    if (sizeof...(t) > 0) std::cerr << \"\
    \ :\";\n    debug_out(t...);\n}\n\n}  // namespace ebi\n#line 2 \"template/io.hpp\"\
    \n\n#line 5 \"template/io.hpp\"\n#include <optional>\n#line 7 \"template/io.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <typename T1, typename T2>\nstd::ostream &operator<<(std::ostream\
    \ &os, const std::pair<T1, T2> &pa) {\n    return os << pa.first << \" \" << pa.second;\n\
    }\n\ntemplate <typename T1, typename T2>\nstd::istream &operator>>(std::istream\
    \ &os, std::pair<T1, T2> &pa) {\n    return os >> pa.first >> pa.second;\n}\n\n\
    template <typename T>\nstd::ostream &operator<<(std::ostream &os, const std::vector<T>\
    \ &vec) {\n    for (std::size_t i = 0; i < vec.size(); i++)\n        os << vec[i]\
    \ << (i + 1 == vec.size() ? \"\" : \" \");\n    return os;\n}\n\ntemplate <typename\
    \ T>\nstd::istream &operator>>(std::istream &os, std::vector<T> &vec) {\n    for\
    \ (T &e : vec) std::cin >> e;\n    return os;\n}\n\ntemplate <typename T>\nstd::ostream\
    \ &operator<<(std::ostream &os, const std::optional<T> &opt) {\n    if (opt) {\n\
    \        os << opt.value();\n    } else {\n        os << \"invalid value\";\n\
    \    }\n    return os;\n}\n\nvoid fast_io() {\n    std::cout << std::fixed <<\
    \ std::setprecision(15);\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    }\n\n}  // namespace ebi\n#line 2 \"template/utility.hpp\"\n\n#line 5 \"template/utility.hpp\"\
    \n\n#line 2 \"graph/base.hpp\"\n\n#line 7 \"graph/base.hpp\"\n\n#line 2 \"data_structure/simple_csr.hpp\"\
    \n\n#line 6 \"data_structure/simple_csr.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ E> struct simple_csr {\n    simple_csr() = default;\n\n    simple_csr(int n,\
    \ const std::vector<std::pair<int, E>>& elements)\n        : start(n + 1, 0),\
    \ elist(elements.size()) {\n        for (auto e : elements) {\n            start[e.first\
    \ + 1]++;\n        }\n        for (auto i : std::views::iota(0, n)) {\n      \
    \      start[i + 1] += start[i];\n        }\n        auto counter = start;\n \
    \       for (auto [i, e] : elements) {\n            elist[counter[i]++] = e;\n\
    \        }\n    }\n\n    simple_csr(const std::vector<std::vector<E>>& es)\n \
    \       : start(es.size() + 1, 0) {\n        int n = es.size();\n        for (auto\
    \ i : std::views::iota(0, n)) {\n            start[i + 1] = (int)es[i].size()\
    \ + start[i];\n        }\n        elist.resize(start.back());\n        for (auto\
    \ i : std::views::iota(0, n)) {\n            std::copy(es[i].begin(), es[i].end(),\
    \ elist.begin() + start[i]);\n        }\n    }\n\n    int size() const {\n   \
    \     return (int)start.size() - 1;\n    }\n\n    const auto operator[](int i)\
    \ const {\n        return std::ranges::subrange(elist.begin() + start[i],\n  \
    \                                   elist.begin() + start[i + 1]);\n    }\n  \
    \  auto operator[](int i) {\n        return std::ranges::subrange(elist.begin()\
    \ + start[i],\n                                     elist.begin() + start[i +\
    \ 1]);\n    }\n\n    const auto operator()(int i, int l, int r) const {\n    \
    \    return std::ranges::subrange(elist.begin() + start[i] + l,\n            \
    \                         elist.begin() + start[i + 1] + r);\n    }\n    auto\
    \ operator()(int i, int l, int r) {\n        return std::ranges::subrange(elist.begin()\
    \ + start[i] + l,\n                                     elist.begin() + start[i\
    \ + 1] + r);\n    }\n\n  private:\n    std::vector<int> start;\n    std::vector<E>\
    \ elist;\n};\n\n}  // namespace ebi\n#line 9 \"graph/base.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <class T> struct Edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n};\n\ntemplate <class E> struct Graph {\n    using cost_type = E;\n   \
    \ using edge_type = Edge<cost_type>;\n\n    Graph(int n_) : n(n_) {}\n\n    Graph()\
    \ = default;\n\n    void add_edge(int u, int v, cost_type c) {\n        assert(!prepared\
    \ && u < n && v < n);\n        buff.emplace_back(u, edge_type{u, v, c, m});\n\
    \        edges.emplace_back(edge_type{u, v, c, m++});\n    }\n\n    void add_undirected_edge(int\
    \ u, int v, cost_type c) {\n        assert(!prepared && u < n && v < n);\n   \
    \     buff.emplace_back(u, edge_type{u, v, c, m});\n        buff.emplace_back(v,\
    \ edge_type{v, u, c, m});\n        edges.emplace_back(edge_type{u, v, c, m});\n\
    \        m++;\n    }\n\n    void read_tree(int offset = 1, bool is_weighted =\
    \ false) {\n        read_graph(n - 1, offset, false, is_weighted);\n    }\n\n\
    \    void read_parents(int offset = 1) {\n        for (auto i : std::views::iota(1,\
    \ n)) {\n            int p;\n            std::cin >> p;\n            p -= offset;\n\
    \            add_undirected_edge(p, i, 1);\n        }\n        build();\n    }\n\
    \n    void read_graph(int e, int offset = 1, bool is_directed = false,\n     \
    \               bool is_weighted = false) {\n        for (int i = 0; i < e; i++)\
    \ {\n            int u, v;\n            std::cin >> u >> v;\n            u -=\
    \ offset;\n            v -= offset;\n            if (is_weighted) {\n        \
    \        cost_type c;\n                std::cin >> c;\n                if (is_directed)\
    \ {\n                    add_edge(u, v, c);\n                } else {\n      \
    \              add_undirected_edge(u, v, c);\n                }\n            }\
    \ else {\n                if (is_directed) {\n                    add_edge(u,\
    \ v, 1);\n                } else {\n                    add_undirected_edge(u,\
    \ v, 1);\n                }\n            }\n        }\n        build();\n    }\n\
    \n    void build() {\n        assert(!prepared);\n        csr = simple_csr<edge_type>(n,\
    \ buff);\n        buff.clear();\n        prepared = true;\n    }\n\n    int size()\
    \ const {\n        return n;\n    }\n\n    int node_number() const {\n       \
    \ return n;\n    }\n\n    int edge_number() const {\n        return m;\n    }\n\
    \n    edge_type get_edge(int i) const {\n        assert(prepared);\n        return\
    \ edges[i];\n    }\n\n    std::vector<edge_type> get_edges() const {\n       \
    \ assert(!prepared);\n        return edges;\n    }\n\n    const auto operator[](int\
    \ i) const {\n        assert(prepared);\n        return csr[i];\n    }\n    auto\
    \ operator[](int i) {\n        assert(prepared);\n        return csr[i];\n   \
    \ }\n\n  private:\n    int n, m = 0;\n\n    std::vector<std::pair<int, edge_type>>\
    \ buff;\n\n    std::vector<edge_type> edges;\n    simple_csr<edge_type> csr;\n\
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 8 \"template/utility.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> inline bool chmin(T &a, T b) {\n   \
    \ if (a > b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\n\ntemplate <class T> inline bool chmax(T &a, T b) {\n    if (a < b) {\n   \
    \     a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate <class\
    \ T> T safe_ceil(T a, T b) {\n    if (a % b == 0)\n        return a / b;\n   \
    \ else if (a >= 0)\n        return (a / b) + 1;\n    else\n        return -((-a)\
    \ / b);\n}\n\ntemplate <class T> T safe_floor(T a, T b) {\n    if (a % b == 0)\n\
    \        return a / b;\n    else if (a >= 0)\n        return a / b;\n    else\n\
    \        return -((-a) / b) - 1;\n}\n\nconstexpr i64 LNF = std::numeric_limits<i64>::max()\
    \ / 4;\n\nconstexpr int INF = std::numeric_limits<int>::max() / 2;\n\nconst std::vector<int>\
    \ dy = {1, 0, -1, 0, 1, 1, -1, -1};\nconst std::vector<int> dx = {0, 1, 0, -1,\
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 7 \"test/math/Sum_of_Exponential_Times_Polynomial.test.cpp\"\
    \n\nnamespace ebi {\n\nusing mint = modint998244353;\n\nvoid main_() {\n    i64\
    \ r, d, n;\n    std::cin >> r >> d >> n;\n    std::cout << sum_of_exp2<mint>(r,\
    \ d, n) << '\\n';\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n\
    \    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial\"\
    \n\n#include \"../../math/sum_of_exp_times_poly.hpp\"\n#include \"../../modint/modint.hpp\"\
    \n#include \"../../template/template.hpp\"\n\nnamespace ebi {\n\nusing mint =\
    \ modint998244353;\n\nvoid main_() {\n    i64 r, d, n;\n    std::cin >> r >> d\
    \ >> n;\n    std::cout << sum_of_exp2<mint>(r, d, n) << '\\n';\n}\n\n}  // namespace\
    \ ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n    // std::cin >>\
    \ t;\n    while (t--) {\n        ebi::main_();\n    }\n    return 0;\n}"
  dependsOn:
  - math/sum_of_exp_times_poly.hpp
  - math/binomial.hpp
  - modint/base.hpp
  - math/lagrange_interpolation.hpp
  - math/linear_sieve.hpp
  - template/int_alias.hpp
  - modint/modint.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/io.hpp
  - template/utility.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: true
  path: test/math/Sum_of_Exponential_Times_Polynomial.test.cpp
  requiredBy: []
  timestamp: '2025-03-18 01:14:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/Sum_of_Exponential_Times_Polynomial.test.cpp
layout: document
redirect_from:
- /verify/test/math/Sum_of_Exponential_Times_Polynomial.test.cpp
- /verify/test/math/Sum_of_Exponential_Times_Polynomial.test.cpp.html
title: test/math/Sum_of_Exponential_Times_Polynomial.test.cpp
---
