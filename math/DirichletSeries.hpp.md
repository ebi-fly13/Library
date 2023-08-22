---
data:
  _extendedDependsOn:
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
    #include <vector>\r\n\r\n#line 2 \"template/int_alias.hpp\"\n\n#include <cstdint>\n\
    \nnamespace ebi {\n\nusing std::size_t;\nusing i8 = std::int8_t;\nusing u8 = std::uint8_t;\n\
    using i16 = std::int16_t;\nusing u16 = std::uint16_t;\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n\n}\n#line 7 \"math/DirichletSeries.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class T, int id> struct DirichletSeries\
    \ {\r\n  private:\r\n    using Self = DirichletSeries<T, id>;\r\n\r\n    void\
    \ set(std::function<T(i64)> f, std::function<T(i64)> F) {\r\n        for (int\
    \ i = 1; i <= K; i++) {\r\n            a[i] = f(i);\r\n        }\r\n        for\
    \ (int i = 1; i <= L; i++) {\r\n            A[i] = F(N / i);\r\n        }\r\n\
    \    }\r\n\r\n  public:\r\n    DirichletSeries() : a(K + 1), A(L + 1) {}\r\n\r\
    \n    DirichletSeries(std::function<T(i64)> f, std::function<T(i64)> F)\r\n  \
    \      : a(K + 1), A(L + 1) {\r\n        set(f, F);\r\n    }\r\n\r\n    Self operator+(const\
    \ Self &rhs) const noexcept {\r\n        return Self(*this) += rhs;\r\n    }\r\
    \n    Self operator-(const Self &rhs) const noexcept {\r\n        return Self(*this)\
    \ -= rhs;\r\n    }\r\n    Self operator*(const Self &rhs) const noexcept {\r\n\
    \        return Self(*this) *= rhs;\r\n    }\r\n    Self operator/(const Self\
    \ &rhs) const noexcept {\r\n        return Self(*this) /= rhs;\r\n    }\r\n\r\n\
    \    Self operator+=(const Self &rhs) noexcept {\r\n        for (int i = 1; i\
    \ <= K; i++) {\r\n            a[i] += rhs.a[i];\r\n        }\r\n        for (int\
    \ i = 1; i <= L; i++) {\r\n            A[i] += rhs.A[i];\r\n        }\r\n    \
    \    return *this;\r\n    }\r\n\r\n    Self operator-=(const Self &rhs) noexcept\
    \ {\r\n        for (int i = 1; i <= K; i++) {\r\n            a[i] -= rhs.a[i];\r\
    \n        }\r\n        for (int i = 1; i <= L; i++) {\r\n            A[i] -= rhs.A[i];\r\
    \n        }\r\n        return *this;\r\n    }\r\n\r\n    Self operator*=(const\
    \ Self &rhs) noexcept {\r\n        Self ret;\r\n        for (int i = 1; i <= K;\
    \ ++i) {\r\n            for (int j = 1; i * j <= K; ++j) {\r\n               \
    \ ret.a[i * j] += a[i] * rhs.a[j];\r\n            }\r\n        }\r\n        std::vector<T>\
    \ sum_a = a, sum_b = rhs.a;\r\n        for (int i = 1; i < K; ++i) {\r\n     \
    \       sum_a[i + 1] += sum_a[i];\r\n            sum_b[i + 1] += sum_b[i];\r\n\
    \        }\r\n        auto get_A = [&](i64 x) -> T {\r\n            if (x <= K)\
    \ {\r\n                return sum_a[x];\r\n            } else {\r\n          \
    \      return A[N / x];\r\n            }\r\n        };\r\n        auto get_B =\
    \ [&](i64 x) -> T {\r\n            if (x <= K) {\r\n                return sum_b[x];\r\
    \n            } else {\r\n                return rhs.A[N / x];\r\n           \
    \ }\r\n        };\r\n        for (i64 l = L, m = 1; l <= L; ++l) {\r\n       \
    \     i64 n = N / l;\r\n            while (m * m <= n) m++;\r\n            m--;\r\
    \n            for (int i = 1; i <= m; ++i) {\r\n                ret.A[l] +=\r\n\
    \                    a[i] * get_B(n / i) + rhs.a[i] * (get_A(n / i) - get_A(m));\r\
    \n            }\r\n        }\r\n        return *this = ret;\r\n    }\r\n\r\n \
    \   // c = a / b\r\n    Self operator/=(const Self &b) noexcept {\r\n        Self\
    \ c = *this;\r\n        T inv_a = b.a[1].inv();\r\n        for (int i = 1; i <=\
    \ K; i++) {\r\n            c.a[i] *= inv_a;\r\n            for (int j = 2; i *\
    \ j <= K; j++) {\r\n                c.a[i * j] -= c.a[i] * b.a[j];\r\n       \
    \     }\r\n        }\r\n        std::vector<T> sum_b = b.a, sum_c = c.a;\r\n \
    \       for (int i = 1; i < K; ++i) {\r\n            sum_b[i + 1] += sum_b[i];\r\
    \n            sum_c[i + 1] += sum_c[i];\r\n        }\r\n        auto get_B = [&](i64\
    \ x) -> T {\r\n            if (x <= K) {\r\n                return sum_b[x];\r\
    \n            } else {\r\n                return b.A[N / x];\r\n            }\r\
    \n        };\r\n        auto get_C = [&](i64 x) -> T {\r\n            if (x <=\
    \ K) {\r\n                return sum_c[x];\r\n            } else {\r\n       \
    \         return c.A[N / x];\r\n            }\r\n        };\r\n        for (i64\
    \ l = L, m = 1; l >= 1; l--) {\r\n            i64 n = N / l;\r\n            while\
    \ (m * m <= n) m++;\r\n            m--;\r\n            for (int i = 2; i <= m;\
    \ i++) {\r\n                c.A[l] -= b.a[i] * get_C(n / i);\r\n            }\r\
    \n\r\n            for (int i = 1; i <= m; i++) {\r\n                c.A[l] -=\
    \ c.a[i] * (get_B(n / i) - get_B(m));\r\n            }\r\n            c.A[l] *=\
    \ inv_a;\r\n        }\r\n        return *this = c;\r\n    }\r\n\r\n    Self pow(u64\
    \ n) const {\r\n        Self res;\r\n        res.a[1] = 1;\r\n        std::fill(res.A.begin(),\
    \ res.A.end(), 1);\r\n        Self x = *this;\r\n        while (n > 0) {\r\n \
    \           if (n & 1) res = res * x;\r\n            x = x * x;\r\n          \
    \  n >>= 1;\r\n        }\r\n        return res;\r\n    }\r\n\r\n    T get_sum()\
    \ {\r\n        return A[1];\r\n    }\r\n\r\n    static Self zeta() {\r\n     \
    \   Self ret;\r\n        std::fill(ret.a.begin(), ret.a.end(), 1);\r\n       \
    \ for (int i = 1; i <= L; i++) {\r\n            ret.A[i] = N / i;\r\n        }\r\
    \n        return ret;\r\n    }\r\n\r\n    static Self zeta1() {\r\n        Self\
    \ ret;\r\n        std::iota(ret.a.begin(), ret.a.end(), 0);\r\n        T inv2\
    \ = T(2).inv();\r\n        for (int i = 1; i <= L; i++) {\r\n            i64 n\
    \ = N / i;\r\n            ret.A[i] = T(n) * T(n + 1) * inv2;\r\n        }\r\n\
    \        return ret;\r\n    }\r\n\r\n    static void set_size(i64 n) {\r\n   \
    \     N = n;\r\n        if (N <= 10) {\r\n            K = N;\r\n            L\
    \ = 1;\r\n        } else if (N <= 1000) {\r\n            K = 1;\r\n          \
    \  while (K * K < N) K++;\r\n            L = (N + K - 1) / K;\r\n        } else\
    \ {\r\n            L = 1;\r\n            while (L * L * L / 50 < N) L++;\r\n \
    \           K = (N + L - 1) / L;\r\n        }\r\n    }\r\n\r\n  private:\r\n \
    \   static i64 N, K, L;\r\n    std::vector<T> a, A;\r\n};\r\n\r\ntemplate <class\
    \ T, int id> i64 DirichletSeries<T, id>::N = 1000000;\r\ntemplate <class T, int\
    \ id> i64 DirichletSeries<T, id>::K = 10000;\r\ntemplate <class T, int id> i64\
    \ DirichletSeries<T, id>::L = 100;\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <functional>\r\n#include <vector>\r\n\r\n#include\
    \ \"../template/int_alias.hpp\"\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class\
    \ T, int id> struct DirichletSeries {\r\n  private:\r\n    using Self = DirichletSeries<T,\
    \ id>;\r\n\r\n    void set(std::function<T(i64)> f, std::function<T(i64)> F) {\r\
    \n        for (int i = 1; i <= K; i++) {\r\n            a[i] = f(i);\r\n     \
    \   }\r\n        for (int i = 1; i <= L; i++) {\r\n            A[i] = F(N / i);\r\
    \n        }\r\n    }\r\n\r\n  public:\r\n    DirichletSeries() : a(K + 1), A(L\
    \ + 1) {}\r\n\r\n    DirichletSeries(std::function<T(i64)> f, std::function<T(i64)>\
    \ F)\r\n        : a(K + 1), A(L + 1) {\r\n        set(f, F);\r\n    }\r\n\r\n\
    \    Self operator+(const Self &rhs) const noexcept {\r\n        return Self(*this)\
    \ += rhs;\r\n    }\r\n    Self operator-(const Self &rhs) const noexcept {\r\n\
    \        return Self(*this) -= rhs;\r\n    }\r\n    Self operator*(const Self\
    \ &rhs) const noexcept {\r\n        return Self(*this) *= rhs;\r\n    }\r\n  \
    \  Self operator/(const Self &rhs) const noexcept {\r\n        return Self(*this)\
    \ /= rhs;\r\n    }\r\n\r\n    Self operator+=(const Self &rhs) noexcept {\r\n\
    \        for (int i = 1; i <= K; i++) {\r\n            a[i] += rhs.a[i];\r\n \
    \       }\r\n        for (int i = 1; i <= L; i++) {\r\n            A[i] += rhs.A[i];\r\
    \n        }\r\n        return *this;\r\n    }\r\n\r\n    Self operator-=(const\
    \ Self &rhs) noexcept {\r\n        for (int i = 1; i <= K; i++) {\r\n        \
    \    a[i] -= rhs.a[i];\r\n        }\r\n        for (int i = 1; i <= L; i++) {\r\
    \n            A[i] -= rhs.A[i];\r\n        }\r\n        return *this;\r\n    }\r\
    \n\r\n    Self operator*=(const Self &rhs) noexcept {\r\n        Self ret;\r\n\
    \        for (int i = 1; i <= K; ++i) {\r\n            for (int j = 1; i * j <=\
    \ K; ++j) {\r\n                ret.a[i * j] += a[i] * rhs.a[j];\r\n          \
    \  }\r\n        }\r\n        std::vector<T> sum_a = a, sum_b = rhs.a;\r\n    \
    \    for (int i = 1; i < K; ++i) {\r\n            sum_a[i + 1] += sum_a[i];\r\n\
    \            sum_b[i + 1] += sum_b[i];\r\n        }\r\n        auto get_A = [&](i64\
    \ x) -> T {\r\n            if (x <= K) {\r\n                return sum_a[x];\r\
    \n            } else {\r\n                return A[N / x];\r\n            }\r\n\
    \        };\r\n        auto get_B = [&](i64 x) -> T {\r\n            if (x <=\
    \ K) {\r\n                return sum_b[x];\r\n            } else {\r\n       \
    \         return rhs.A[N / x];\r\n            }\r\n        };\r\n        for (i64\
    \ l = L, m = 1; l <= L; ++l) {\r\n            i64 n = N / l;\r\n            while\
    \ (m * m <= n) m++;\r\n            m--;\r\n            for (int i = 1; i <= m;\
    \ ++i) {\r\n                ret.A[l] +=\r\n                    a[i] * get_B(n\
    \ / i) + rhs.a[i] * (get_A(n / i) - get_A(m));\r\n            }\r\n        }\r\
    \n        return *this = ret;\r\n    }\r\n\r\n    // c = a / b\r\n    Self operator/=(const\
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
    \n        res.a[1] = 1;\r\n        std::fill(res.A.begin(), res.A.end(), 1);\r\
    \n        Self x = *this;\r\n        while (n > 0) {\r\n            if (n & 1)\
    \ res = res * x;\r\n            x = x * x;\r\n            n >>= 1;\r\n       \
    \ }\r\n        return res;\r\n    }\r\n\r\n    T get_sum() {\r\n        return\
    \ A[1];\r\n    }\r\n\r\n    static Self zeta() {\r\n        Self ret;\r\n    \
    \    std::fill(ret.a.begin(), ret.a.end(), 1);\r\n        for (int i = 1; i <=\
    \ L; i++) {\r\n            ret.A[i] = N / i;\r\n        }\r\n        return ret;\r\
    \n    }\r\n\r\n    static Self zeta1() {\r\n        Self ret;\r\n        std::iota(ret.a.begin(),\
    \ ret.a.end(), 0);\r\n        T inv2 = T(2).inv();\r\n        for (int i = 1;\
    \ i <= L; i++) {\r\n            i64 n = N / i;\r\n            ret.A[i] = T(n)\
    \ * T(n + 1) * inv2;\r\n        }\r\n        return ret;\r\n    }\r\n\r\n    static\
    \ void set_size(i64 n) {\r\n        N = n;\r\n        if (N <= 10) {\r\n     \
    \       K = N;\r\n            L = 1;\r\n        } else if (N <= 1000) {\r\n  \
    \          K = 1;\r\n            while (K * K < N) K++;\r\n            L = (N\
    \ + K - 1) / K;\r\n        } else {\r\n            L = 1;\r\n            while\
    \ (L * L * L / 50 < N) L++;\r\n            K = (N + L - 1) / L;\r\n        }\r\
    \n    }\r\n\r\n  private:\r\n    static i64 N, K, L;\r\n    std::vector<T> a,\
    \ A;\r\n};\r\n\r\ntemplate <class T, int id> i64 DirichletSeries<T, id>::N = 1000000;\r\
    \ntemplate <class T, int id> i64 DirichletSeries<T, id>::K = 10000;\r\ntemplate\
    \ <class T, int id> i64 DirichletSeries<T, id>::L = 100;\r\n\r\n}  // namespace\
    \ ebi"
  dependsOn:
  - template/int_alias.hpp
  isVerificationFile: false
  path: math/DirichletSeries.hpp
  requiredBy: []
  timestamp: '2023-08-23 03:27:38+09:00'
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
