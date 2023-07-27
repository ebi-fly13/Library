---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/divisor_transform.hpp
    title: "Divisor Transform (Zeta / M\xF6bius)"
  - icon: ':heavy_check_mark:'
    path: math/eratosthenes_sieve.hpp
    title: math/eratosthenes_sieve.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/Lcm_Convolution.test.cpp
    title: test/convolution/Lcm_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/lcm_convolution.hpp\"\n\n#line 2 \"math/divisor_transform.hpp\"\
    \n\n#include <vector>\n\n#line 2 \"math/eratosthenes_sieve.hpp\"\n\r\n#include\
    \ <cassert>\r\n#include <cstdint>\r\n#line 6 \"math/eratosthenes_sieve.hpp\"\n\
    \r\n/*\r\n    reference: https://37zigen.com/sieve-eratosthenes/\r\n*/\r\n\r\n\
    namespace ebi {\r\n\r\nstruct eratosthenes_sieve {\r\n  private:\r\n    using\
    \ i64 = std::int_fast64_t;\r\n    int n;\r\n    std::vector<bool> table;\r\n\r\
    \n  public:\r\n    eratosthenes_sieve(int n) : n(n), table(std::vector<bool>(n\
    \ + 1, true)) {\r\n        table[1] = false;\r\n        for (i64 i = 2; i * i\
    \ <= n; i++) {\r\n            if (!table[i]) continue;\r\n            for (i64\
    \ j = i; i * j <= n; j++) {\r\n                table[i * j] = false;\r\n     \
    \       }\r\n        }\r\n    }\r\n\r\n    bool is_prime(int p) {\r\n        return\
    \ table[p];\r\n    }\r\n\r\n    std::vector<int> prime_table(int m = -1) {\r\n\
    \        if (m < 0) m = n;\r\n        std::vector<int> prime;\r\n        for (int\
    \ i = 2; i <= m; i++) {\r\n            if (table[i]) prime.emplace_back(i);\r\n\
    \        }\r\n        return prime;\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n\
    #line 6 \"math/divisor_transform.hpp\"\n\nnamespace ebi {\n\nstruct divisor_transform\
    \ {\n    divisor_transform() = default;\n\n    template <class mint>\n    static\
    \ std::vector<mint> zeta_transform(const std::vector<mint> &f) {\n        int\
    \ n = f.size() - 1;\n        auto F = f;\n        if (m < n) {\n            while\
    \ (m < n) m <<= 1;\n            eratosthenes_sieve sieve(m);\n            primes\
    \ = sieve.prime_table();\n        }\n        for (const auto &p : primes) {\n\
    \            for (int i = 1; i * p <= n; i++) F[p * i] += F[i];\n        }\n \
    \       return F;\n    }\n\n    template <class mint>\n    static std::vector<mint>\
    \ mobius_transform(const std::vector<mint> &F) {\n        int n = F.size() - 1;\n\
    \        auto f = F;\n        if (m < n) {\n            while (m < n) m <<= 1;\n\
    \            eratosthenes_sieve sieve(m);\n            primes = sieve.prime_table();\n\
    \        }\n        for (const auto &p : primes) {\n            for (int i = n\
    \ / p; i > 0; i--) f[p * i] -= f[i];\n        }\n        return f;\n    }\n\n\
    \  private:\n    static int m;\n    static std::vector<int> primes;\n};\n\nint\
    \ divisor_transform::m = 4;\nstd::vector<int> divisor_transform::primes = {2,\
    \ 3};\n\n}  // namespace ebi\n#line 4 \"convolution/lcm_convolution.hpp\"\n\n\
    namespace ebi {\n\ntemplate <class mint>\nstd::vector<mint> lcm_convolution(const\
    \ std::vector<mint> &a,\n                                  const std::vector<mint>\
    \ &b) {\n    int n = a.size();\n    assert(a.size() == b.size());\n    auto ra\
    \ = divisor_transform::zeta_transform(a);\n    auto rb = divisor_transform::zeta_transform(b);\n\
    \    for (int i = 0; i < n; i++) {\n        ra[i] *= rb[i];\n    }\n    return\
    \ divisor_transform::mobius_transform(ra);\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include \"../math/divisor_transform.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <class mint>\nstd::vector<mint> lcm_convolution(const std::vector<mint>\
    \ &a,\n                                  const std::vector<mint> &b) {\n    int\
    \ n = a.size();\n    assert(a.size() == b.size());\n    auto ra = divisor_transform::zeta_transform(a);\n\
    \    auto rb = divisor_transform::zeta_transform(b);\n    for (int i = 0; i <\
    \ n; i++) {\n        ra[i] *= rb[i];\n    }\n    return divisor_transform::mobius_transform(ra);\n\
    }\n\n}  // namespace ebi"
  dependsOn:
  - math/divisor_transform.hpp
  - math/eratosthenes_sieve.hpp
  isVerificationFile: false
  path: convolution/lcm_convolution.hpp
  requiredBy: []
  timestamp: '2023-06-09 15:36:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/Lcm_Convolution.test.cpp
documentation_of: convolution/lcm_convolution.hpp
layout: document
title: LCM Convolution
---

## 説明

長さ$N+1$ の整数列 $a$, $b$ について、 $c_k = \sum_{lcm(i, j) = k} a_i b_j$ を $O(N\log \log N)$ で計算する。