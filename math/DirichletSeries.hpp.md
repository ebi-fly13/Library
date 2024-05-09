---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convolution/dirichlet_convolution.hpp
    title: Dirichlet Convolution
  - icon: ':question:'
    path: math/eratosthenes_sieve.hpp
    title: Eratosthenes Sieve
  - icon: ':x:'
    path: math/linear_sieve.hpp
    title: Linear Sieve
  - icon: ':question:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/Sum_of_Totient_Function.test.cpp
    title: test/math/Sum_of_Totient_Function.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/DirichletSeries.hpp\"\n\r\n#include <functional>\r\n\
    #include <numeric>\r\n#include <vector>\r\n\r\n#line 2 \"convolution/dirichlet_convolution.hpp\"\
    \n\n#line 4 \"convolution/dirichlet_convolution.hpp\"\n\n#line 2 \"math/eratosthenes_sieve.hpp\"\
    \n\r\n#include <cassert>\r\n#include <cstdint>\r\n#line 6 \"math/eratosthenes_sieve.hpp\"\
    \n\r\n/*\r\n    reference: https://37zigen.com/sieve-eratosthenes/\r\n*/\r\n\r\
    \nnamespace ebi {\r\n\r\nstruct eratosthenes_sieve {\r\n  private:\r\n    using\
    \ i64 = std::int_fast64_t;\r\n    int n;\r\n    std::vector<bool> table;\r\n\r\
    \n  public:\r\n    eratosthenes_sieve(int _n) : n(_n), table(std::vector<bool>(n\
    \ + 1, true)) {\r\n        table[1] = false;\r\n        for (i64 i = 2; i * i\
    \ <= n; i++) {\r\n            if (!table[i]) continue;\r\n            for (i64\
    \ j = i; i * j <= n; j++) {\r\n                table[i * j] = false;\r\n     \
    \       }\r\n        }\r\n    }\r\n\r\n    bool is_prime(int p) {\r\n        return\
    \ table[p];\r\n    }\r\n\r\n    std::vector<int> prime_table(int m = -1) {\r\n\
    \        if (m < 0) m = n;\r\n        std::vector<int> prime;\r\n        for (int\
    \ i = 2; i <= m; i++) {\r\n            if (table[i]) prime.emplace_back(i);\r\n\
    \        }\r\n        return prime;\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n\
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
    \ <class modint> std::vector<modint> pow_table(int k) {\r\n        std::vector<modint>\
    \ table(n + 1, 1);\r\n        table[0] = 0;\r\n        for (int i = 2; i <= n;\
    \ i++) {\r\n            if (sieve[i] == i) {\r\n                table[i] = modint(i).pow(k);\r\
    \n                continue;\r\n            }\r\n            table[i] = table[sieve[i]]\
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
    \ namespace ebi\n#line 9 \"math/DirichletSeries.hpp\"\n\r\nnamespace ebi {\r\n\
    \r\ntemplate <class T, int id> struct DirichletSeries {\r\n  private:\r\n    using\
    \ Self = DirichletSeries<T, id>;\r\n\r\n    void set(std::function<T(i64)> f,\
    \ std::function<T(i64)> F) {\r\n        for (int i = 1; i <= K; i++) {\r\n   \
    \         a[i] = f(i);\r\n        }\r\n        for (int i = 1; i <= L; i++) {\r\
    \n            A[i] = F(N / i);\r\n        }\r\n    }\r\n\r\n  public:\r\n    DirichletSeries()\
    \ : a(K + 1), A(L + 1) {}\r\n\r\n    DirichletSeries(std::function<T(i64)> f,\
    \ std::function<T(i64)> F,\r\n                    bool _is_multiplicative = false)\r\
    \n        : a(K + 1), A(L + 1), is_multiplicative(_is_multiplicative) {\r\n  \
    \      set(f, F);\r\n    }\r\n\r\n    Self operator+(const Self &rhs) const noexcept\
    \ {\r\n        return Self(*this) += rhs;\r\n    }\r\n    Self operator-(const\
    \ Self &rhs) const noexcept {\r\n        return Self(*this) -= rhs;\r\n    }\r\
    \n    Self operator*(const Self &rhs) const noexcept {\r\n        return Self(*this)\
    \ *= rhs;\r\n    }\r\n    Self operator/(const Self &rhs) const noexcept {\r\n\
    \        return Self(*this) /= rhs;\r\n    }\r\n\r\n    Self operator+=(const\
    \ Self &rhs) noexcept {\r\n        for (int i = 1; i <= K; i++) {\r\n        \
    \    a[i] += rhs.a[i];\r\n        }\r\n        for (int i = 1; i <= L; i++) {\r\
    \n            A[i] += rhs.A[i];\r\n        }\r\n        return *this;\r\n    }\r\
    \n\r\n    Self operator-=(const Self &rhs) noexcept {\r\n        for (int i =\
    \ 1; i <= K; i++) {\r\n            a[i] -= rhs.a[i];\r\n        }\r\n        for\
    \ (int i = 1; i <= L; i++) {\r\n            A[i] -= rhs.A[i];\r\n        }\r\n\
    \        return *this;\r\n    }\r\n\r\n    Self operator*=(const Self &rhs) noexcept\
    \ {\r\n        Self ret;\r\n        if (is_multiplicative && rhs.is_multiplicative)\
    \ {\r\n            ret.a = dirichlet_convolution_multiplicative_function(a, rhs.a);\r\
    \n            ret.is_multiplicative = true;\r\n        } else if (is_multiplicative)\
    \ {\r\n            ret.a =\r\n                dirichlet_convolution_left_is_multiplicative_function(a,\
    \ rhs.a);\r\n        } else if (rhs.is_multiplicative) {\r\n            ret.a\
    \ =\r\n                dirichlet_convolution_left_is_multiplicative_function(rhs.a,\
    \ a);\r\n        } else {\r\n            ret.a = dirichlet_convolution(a, rhs.a);\r\
    \n        }\r\n        std::vector<T> sum_a = a, sum_b = rhs.a;\r\n        for\
    \ (int i = 1; i < K; i++) {\r\n            sum_a[i + 1] += sum_a[i];\r\n     \
    \       sum_b[i + 1] += sum_b[i];\r\n        }\r\n        auto get_A = [&](i64\
    \ x) -> T {\r\n            if (x <= K) {\r\n                return sum_a[x];\r\
    \n            } else {\r\n                return A[N / x];\r\n            }\r\n\
    \        };\r\n        auto get_B = [&](i64 x) -> T {\r\n            if (x <=\
    \ K) {\r\n                return sum_b[x];\r\n            } else {\r\n       \
    \         return rhs.A[N / x];\r\n            }\r\n        };\r\n        for (i64\
    \ l = L, m = 1; l >= 1; l--) {\r\n            i64 n = N / l;\r\n            while\
    \ (m * m <= n) m++;\r\n            m--;\r\n            for (int i = 1; i <= m;\
    \ i++) {\r\n                ret.A[l] +=\r\n                    a[i] * get_B(n\
    \ / i) + (get_A(n / i) - get_A(m)) * rhs.a[i];\r\n            }\r\n        }\r\
    \n        return ret;\r\n    }\r\n\r\n    // c = a / b\r\n    Self operator/=(const\
    \ Self &b) noexcept {\r\n        Self c = *this;\r\n        T inv_a = b.a[1].inv();\r\
    \n        for (int i = 1; i <= K; i++) {\r\n            c.a[i] *= inv_a;\r\n \
    \           for (int j = 2; i * j <= K; j++) {\r\n                c.a[i * j] -=\
    \ c.a[i] * b.a[j];\r\n            }\r\n        }\r\n        std::vector<T> sum_b\
    \ = b.a, sum_c = c.a;\r\n        for (int i = 1; i < K; ++i) {\r\n           \
    \ sum_b[i + 1] += sum_b[i];\r\n            sum_c[i + 1] += sum_c[i];\r\n     \
    \   }\r\n        auto get_B = [&](i64 x) -> T {\r\n            if (x <= K) {\r\
    \n                return sum_b[x];\r\n            } else {\r\n               \
    \ return b.A[N / x];\r\n            }\r\n        };\r\n        auto get_C = [&](i64\
    \ x) -> T {\r\n            if (x <= K) {\r\n                return sum_c[x];\r\
    \n            } else {\r\n                return c.A[N / x];\r\n            }\r\
    \n        };\r\n        for (i64 l = L, m = 1; l >= 1; l--) {\r\n            i64\
    \ n = N / l;\r\n            while (m * m <= n) m++;\r\n            m--;\r\n  \
    \          for (int i = 2; i <= m; i++) {\r\n                c.A[l] -= b.a[i]\
    \ * get_C(n / i);\r\n            }\r\n\r\n            for (int i = 1; i <= m;\
    \ i++) {\r\n                c.A[l] -= c.a[i] * (get_B(n / i) - get_B(m));\r\n\
    \            }\r\n            c.A[l] *= inv_a;\r\n        }\r\n        return\
    \ *this = c;\r\n    }\r\n\r\n    Self pow(u64 n) const {\r\n        Self res;\r\
    \n        res.a[1] = 1;\r\n        res.is_multiplicative = is_multiplicative;\r\
    \n        std::fill(res.A.begin(), res.A.end(), 1);\r\n        Self x = *this;\r\
    \n        while (n > 0) {\r\n            if (n & 1) res = res * x;\r\n       \
    \     x = x * x;\r\n            n >>= 1;\r\n        }\r\n        return res;\r\
    \n    }\r\n\r\n    T get_sum() {\r\n        return A[1];\r\n    }\r\n\r\n    static\
    \ Self zeta() {\r\n        Self ret;\r\n        std::fill(ret.a.begin(), ret.a.end(),\
    \ 1);\r\n        for (int i = 1; i <= L; i++) {\r\n            ret.A[i] = N /\
    \ i;\r\n        }\r\n        ret.is_multiplicative = true;\r\n        return ret;\r\
    \n    }\r\n\r\n    static Self zeta1() {\r\n        Self ret;\r\n        ret.is_multiplicative\
    \ = true;\r\n        std::iota(ret.a.begin(), ret.a.end(), 0);\r\n        T inv2\
    \ = T(2).inv();\r\n        for (int i = 1; i <= L; i++) {\r\n            i64 n\
    \ = N / i;\r\n            ret.A[i] = T(n) * T(n + 1) * inv2;\r\n        }\r\n\
    \        return ret;\r\n    }\r\n\r\n    static Self zeta2() {\r\n        Self\
    \ ret;\r\n        ret.is_multiplicative = true;\r\n        for (int i = 1; i <=\
    \ K; i++) {\r\n            ret.a[i] = i * i;\r\n        }\r\n        T inv6 =\
    \ T(6).inv();\r\n        for (int i = 1; i <= L; i++) {\r\n            i64 n =\
    \ N / i;\r\n            ret.A[i] = T(n) * T(n + 1) * T(2 * n + 1) * inv6;\r\n\
    \        }\r\n    }\r\n\r\n    static void set_size(i64 n) {\r\n        N = n;\r\
    \n        if (N <= 10) {\r\n            K = N;\r\n            L = 1;\r\n     \
    \   } else if (N <= 5000) {\r\n            K = 1;\r\n            while (K * K\
    \ < N) K++;\r\n            L = (N + K - 1) / K;\r\n        } else {\r\n      \
    \      L = 1;\r\n            while (L * L * L / 50 < N) L++;\r\n            K\
    \ = (N + L - 1) / L;\r\n        }\r\n    }\r\n\r\n    static void set_size_multiplicative(i64\
    \ n) {\r\n        N = n;\r\n        L = 1;\r\n        while (L * L * L < N) L++;\r\
    \n        K = L * L;\r\n    }\r\n\r\n  private:\r\n    static i64 N, K, L;\r\n\
    \    static std::vector<std::pair<int, int>> prime_pow_table;\r\n    std::vector<T>\
    \ a, A;\r\n    bool is_multiplicative = false;\r\n};\r\n\r\ntemplate <class T,\
    \ int id> i64 DirichletSeries<T, id>::N = 1000000;\r\ntemplate <class T, int id>\
    \ i64 DirichletSeries<T, id>::K = 10000;\r\ntemplate <class T, int id> i64 DirichletSeries<T,\
    \ id>::L = 100;\r\ntemplate <class T, int id>\r\nstd::vector<std::pair<int, int>>\
    \ DirichletSeries<T, id>::prime_pow_table = {};\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <functional>\r\n#include <numeric>\r\n#include\
    \ <vector>\r\n\r\n#include \"../convolution/dirichlet_convolution.hpp\"\r\n#include\
    \ \"../template/int_alias.hpp\"\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class\
    \ T, int id> struct DirichletSeries {\r\n  private:\r\n    using Self = DirichletSeries<T,\
    \ id>;\r\n\r\n    void set(std::function<T(i64)> f, std::function<T(i64)> F) {\r\
    \n        for (int i = 1; i <= K; i++) {\r\n            a[i] = f(i);\r\n     \
    \   }\r\n        for (int i = 1; i <= L; i++) {\r\n            A[i] = F(N / i);\r\
    \n        }\r\n    }\r\n\r\n  public:\r\n    DirichletSeries() : a(K + 1), A(L\
    \ + 1) {}\r\n\r\n    DirichletSeries(std::function<T(i64)> f, std::function<T(i64)>\
    \ F,\r\n                    bool _is_multiplicative = false)\r\n        : a(K\
    \ + 1), A(L + 1), is_multiplicative(_is_multiplicative) {\r\n        set(f, F);\r\
    \n    }\r\n\r\n    Self operator+(const Self &rhs) const noexcept {\r\n      \
    \  return Self(*this) += rhs;\r\n    }\r\n    Self operator-(const Self &rhs)\
    \ const noexcept {\r\n        return Self(*this) -= rhs;\r\n    }\r\n    Self\
    \ operator*(const Self &rhs) const noexcept {\r\n        return Self(*this) *=\
    \ rhs;\r\n    }\r\n    Self operator/(const Self &rhs) const noexcept {\r\n  \
    \      return Self(*this) /= rhs;\r\n    }\r\n\r\n    Self operator+=(const Self\
    \ &rhs) noexcept {\r\n        for (int i = 1; i <= K; i++) {\r\n            a[i]\
    \ += rhs.a[i];\r\n        }\r\n        for (int i = 1; i <= L; i++) {\r\n    \
    \        A[i] += rhs.A[i];\r\n        }\r\n        return *this;\r\n    }\r\n\r\
    \n    Self operator-=(const Self &rhs) noexcept {\r\n        for (int i = 1; i\
    \ <= K; i++) {\r\n            a[i] -= rhs.a[i];\r\n        }\r\n        for (int\
    \ i = 1; i <= L; i++) {\r\n            A[i] -= rhs.A[i];\r\n        }\r\n    \
    \    return *this;\r\n    }\r\n\r\n    Self operator*=(const Self &rhs) noexcept\
    \ {\r\n        Self ret;\r\n        if (is_multiplicative && rhs.is_multiplicative)\
    \ {\r\n            ret.a = dirichlet_convolution_multiplicative_function(a, rhs.a);\r\
    \n            ret.is_multiplicative = true;\r\n        } else if (is_multiplicative)\
    \ {\r\n            ret.a =\r\n                dirichlet_convolution_left_is_multiplicative_function(a,\
    \ rhs.a);\r\n        } else if (rhs.is_multiplicative) {\r\n            ret.a\
    \ =\r\n                dirichlet_convolution_left_is_multiplicative_function(rhs.a,\
    \ a);\r\n        } else {\r\n            ret.a = dirichlet_convolution(a, rhs.a);\r\
    \n        }\r\n        std::vector<T> sum_a = a, sum_b = rhs.a;\r\n        for\
    \ (int i = 1; i < K; i++) {\r\n            sum_a[i + 1] += sum_a[i];\r\n     \
    \       sum_b[i + 1] += sum_b[i];\r\n        }\r\n        auto get_A = [&](i64\
    \ x) -> T {\r\n            if (x <= K) {\r\n                return sum_a[x];\r\
    \n            } else {\r\n                return A[N / x];\r\n            }\r\n\
    \        };\r\n        auto get_B = [&](i64 x) -> T {\r\n            if (x <=\
    \ K) {\r\n                return sum_b[x];\r\n            } else {\r\n       \
    \         return rhs.A[N / x];\r\n            }\r\n        };\r\n        for (i64\
    \ l = L, m = 1; l >= 1; l--) {\r\n            i64 n = N / l;\r\n            while\
    \ (m * m <= n) m++;\r\n            m--;\r\n            for (int i = 1; i <= m;\
    \ i++) {\r\n                ret.A[l] +=\r\n                    a[i] * get_B(n\
    \ / i) + (get_A(n / i) - get_A(m)) * rhs.a[i];\r\n            }\r\n        }\r\
    \n        return ret;\r\n    }\r\n\r\n    // c = a / b\r\n    Self operator/=(const\
    \ Self &b) noexcept {\r\n        Self c = *this;\r\n        T inv_a = b.a[1].inv();\r\
    \n        for (int i = 1; i <= K; i++) {\r\n            c.a[i] *= inv_a;\r\n \
    \           for (int j = 2; i * j <= K; j++) {\r\n                c.a[i * j] -=\
    \ c.a[i] * b.a[j];\r\n            }\r\n        }\r\n        std::vector<T> sum_b\
    \ = b.a, sum_c = c.a;\r\n        for (int i = 1; i < K; ++i) {\r\n           \
    \ sum_b[i + 1] += sum_b[i];\r\n            sum_c[i + 1] += sum_c[i];\r\n     \
    \   }\r\n        auto get_B = [&](i64 x) -> T {\r\n            if (x <= K) {\r\
    \n                return sum_b[x];\r\n            } else {\r\n               \
    \ return b.A[N / x];\r\n            }\r\n        };\r\n        auto get_C = [&](i64\
    \ x) -> T {\r\n            if (x <= K) {\r\n                return sum_c[x];\r\
    \n            } else {\r\n                return c.A[N / x];\r\n            }\r\
    \n        };\r\n        for (i64 l = L, m = 1; l >= 1; l--) {\r\n            i64\
    \ n = N / l;\r\n            while (m * m <= n) m++;\r\n            m--;\r\n  \
    \          for (int i = 2; i <= m; i++) {\r\n                c.A[l] -= b.a[i]\
    \ * get_C(n / i);\r\n            }\r\n\r\n            for (int i = 1; i <= m;\
    \ i++) {\r\n                c.A[l] -= c.a[i] * (get_B(n / i) - get_B(m));\r\n\
    \            }\r\n            c.A[l] *= inv_a;\r\n        }\r\n        return\
    \ *this = c;\r\n    }\r\n\r\n    Self pow(u64 n) const {\r\n        Self res;\r\
    \n        res.a[1] = 1;\r\n        res.is_multiplicative = is_multiplicative;\r\
    \n        std::fill(res.A.begin(), res.A.end(), 1);\r\n        Self x = *this;\r\
    \n        while (n > 0) {\r\n            if (n & 1) res = res * x;\r\n       \
    \     x = x * x;\r\n            n >>= 1;\r\n        }\r\n        return res;\r\
    \n    }\r\n\r\n    T get_sum() {\r\n        return A[1];\r\n    }\r\n\r\n    static\
    \ Self zeta() {\r\n        Self ret;\r\n        std::fill(ret.a.begin(), ret.a.end(),\
    \ 1);\r\n        for (int i = 1; i <= L; i++) {\r\n            ret.A[i] = N /\
    \ i;\r\n        }\r\n        ret.is_multiplicative = true;\r\n        return ret;\r\
    \n    }\r\n\r\n    static Self zeta1() {\r\n        Self ret;\r\n        ret.is_multiplicative\
    \ = true;\r\n        std::iota(ret.a.begin(), ret.a.end(), 0);\r\n        T inv2\
    \ = T(2).inv();\r\n        for (int i = 1; i <= L; i++) {\r\n            i64 n\
    \ = N / i;\r\n            ret.A[i] = T(n) * T(n + 1) * inv2;\r\n        }\r\n\
    \        return ret;\r\n    }\r\n\r\n    static Self zeta2() {\r\n        Self\
    \ ret;\r\n        ret.is_multiplicative = true;\r\n        for (int i = 1; i <=\
    \ K; i++) {\r\n            ret.a[i] = i * i;\r\n        }\r\n        T inv6 =\
    \ T(6).inv();\r\n        for (int i = 1; i <= L; i++) {\r\n            i64 n =\
    \ N / i;\r\n            ret.A[i] = T(n) * T(n + 1) * T(2 * n + 1) * inv6;\r\n\
    \        }\r\n    }\r\n\r\n    static void set_size(i64 n) {\r\n        N = n;\r\
    \n        if (N <= 10) {\r\n            K = N;\r\n            L = 1;\r\n     \
    \   } else if (N <= 5000) {\r\n            K = 1;\r\n            while (K * K\
    \ < N) K++;\r\n            L = (N + K - 1) / K;\r\n        } else {\r\n      \
    \      L = 1;\r\n            while (L * L * L / 50 < N) L++;\r\n            K\
    \ = (N + L - 1) / L;\r\n        }\r\n    }\r\n\r\n    static void set_size_multiplicative(i64\
    \ n) {\r\n        N = n;\r\n        L = 1;\r\n        while (L * L * L < N) L++;\r\
    \n        K = L * L;\r\n    }\r\n\r\n  private:\r\n    static i64 N, K, L;\r\n\
    \    static std::vector<std::pair<int, int>> prime_pow_table;\r\n    std::vector<T>\
    \ a, A;\r\n    bool is_multiplicative = false;\r\n};\r\n\r\ntemplate <class T,\
    \ int id> i64 DirichletSeries<T, id>::N = 1000000;\r\ntemplate <class T, int id>\
    \ i64 DirichletSeries<T, id>::K = 10000;\r\ntemplate <class T, int id> i64 DirichletSeries<T,\
    \ id>::L = 100;\r\ntemplate <class T, int id>\r\nstd::vector<std::pair<int, int>>\
    \ DirichletSeries<T, id>::prime_pow_table = {};\r\n\r\n}  // namespace ebi"
  dependsOn:
  - convolution/dirichlet_convolution.hpp
  - math/eratosthenes_sieve.hpp
  - math/linear_sieve.hpp
  - template/int_alias.hpp
  isVerificationFile: false
  path: math/DirichletSeries.hpp
  requiredBy: []
  timestamp: '2023-12-28 15:52:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/Sum_of_Totient_Function.test.cpp
documentation_of: math/DirichletSeries.hpp
layout: document
title: Dirichlet Series
---

## 説明

Dirichlet級数を取り扱う構造体。
$a$ に関するDirichlet級数 $D_a(s)$ は

$$D_a(s) = \sum_{n = 1}^{\infty} a_n s^{-n}$$

で表される。これを長さ $N$ で打ち切ったものについて取り扱う。

Dirichlet級数についてと実装方法について、[maspyさんの記事](https://maspypy.com/dirichlet-%e7%a9%8d%e3%81%a8%e3%80%81%e6%95%b0%e8%ab%96%e9%96%a2%e6%95%b0%e3%81%ae%e7%b4%af%e7%a9%8d%e5%92%8c)を参考にした。

### コンストラクタ

$a_i$ を返す関数 $f$ とその累積和 $A_i$ を計算する関数 $F$ を引数として渡すことで、 $a$ に関するDirichlet級数を生成する。

```set_size(n)```をすることを**忘れず**にすること。

### 和・差

$O(K + L)$

### 積

$O(K\log K + (NL)^{1/2})$

### 商

$O(K\log K + (NL)^{1/2})$

### get_sum()

$sum_{n = 1}^{N} a_n$ を返す。 $O(1)$

### pow(u64 n)

Dirichlet級数 $a$ について $a^n$ を求める。繰り返し二乗法で $\log n$ 回程度の積が実行される。

### zeta()

$\zeta(s) = \sum_{n = 1}^{\infty} s^{-n}$ のDirichlet級数を返す。

### zeta1()

$\zeta(s-1) = \sum_{n = 1}^{\infty} n \times s^{-n}$ のDirichlet級数を返す。

### set_size(i64 n)

長さを $n$ にする。

### set_size_multiplicative(i64 n)

長さを $n$ として、 $a$ が乗法的関数のとき、計算量が良くなるような分割になるようにする。