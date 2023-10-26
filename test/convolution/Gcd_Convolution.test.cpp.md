---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/gcd_convolution.hpp
    title: GCD Convolution
  - icon: ':question:'
    path: math/eratosthenes_sieve.hpp
    title: Eratosthenes Sieve
  - icon: ':heavy_check_mark:'
    path: math/multiple_transform.hpp
    title: "Multiple Transform (Zeta / M\xF6bius)"
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/gcd_convolution
    links:
    - https://judge.yosupo.jp/problem/gcd_convolution
  bundledCode: "#line 1 \"test/convolution/Gcd_Convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/gcd_convolution\"\n\n#line 2 \"convolution/gcd_convolution.hpp\"\
    \n\n#line 2 \"math/multiple_transform.hpp\"\n\n#include <vector>\n\n#line 2 \"\
    math/eratosthenes_sieve.hpp\"\n\r\n#include <cassert>\r\n#include <cstdint>\r\n\
    #line 6 \"math/eratosthenes_sieve.hpp\"\n\r\n/*\r\n    reference: https://37zigen.com/sieve-eratosthenes/\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\nstruct eratosthenes_sieve {\r\n  private:\r\
    \n    using i64 = std::int_fast64_t;\r\n    int n;\r\n    std::vector<bool> table;\r\
    \n\r\n  public:\r\n    eratosthenes_sieve(int _n) : n(_n), table(std::vector<bool>(n\
    \ + 1, true)) {\r\n        table[1] = false;\r\n        for (i64 i = 2; i * i\
    \ <= n; i++) {\r\n            if (!table[i]) continue;\r\n            for (i64\
    \ j = i; i * j <= n; j++) {\r\n                table[i * j] = false;\r\n     \
    \       }\r\n        }\r\n    }\r\n\r\n    bool is_prime(int p) {\r\n        return\
    \ table[p];\r\n    }\r\n\r\n    std::vector<int> prime_table(int m = -1) {\r\n\
    \        if (m < 0) m = n;\r\n        std::vector<int> prime;\r\n        for (int\
    \ i = 2; i <= m; i++) {\r\n            if (table[i]) prime.emplace_back(i);\r\n\
    \        }\r\n        return prime;\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n\
    #line 6 \"math/multiple_transform.hpp\"\n\nnamespace ebi {\n\nstruct multiple_transform\
    \ {\n    multiple_transform() = default;\n\n    template <class mint>\n    static\
    \ std::vector<mint> zeta_transform(const std::vector<mint> &f) {\n        int\
    \ n = f.size() - 1;\n        auto F = f;\n        if (m < n) {\n            while\
    \ (m < n) m <<= 1;\n            eratosthenes_sieve sieve(m);\n            primes\
    \ = sieve.prime_table();\n        }\n        for (const auto &p : primes) {\n\
    \            if (n < p) break;\n            for (int i = n / p; i > 0; i--) F[i]\
    \ += F[i * p];\n        }\n        return F;\n    }\n\n    template <class mint>\n\
    \    static std::vector<mint> mobius_transform(const std::vector<mint> &F) {\n\
    \        int n = F.size() - 1;\n        auto f = F;\n        if (m < n) {\n  \
    \          while (m < n) m <<= 1;\n            eratosthenes_sieve sieve(m);\n\
    \            primes = sieve.prime_table();\n        }\n        for (const auto\
    \ &p : primes) {\n            if (n < p) break;\n            for (int i = 1; i\
    \ * p <= n; i++) f[i] -= f[i * p];\n        }\n        return f;\n    }\n\n  private:\n\
    \    static int m;\n    static std::vector<int> primes;\n};\n\nint multiple_transform::m\
    \ = 4;\nstd::vector<int> multiple_transform::primes = {2, 3};\n\n}  // namespace\
    \ ebi\n#line 4 \"convolution/gcd_convolution.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class mint>\nstd::vector<mint> gcd_convolution(const std::vector<mint> &a,\n\
    \                                  const std::vector<mint> &b) {\n    int n =\
    \ a.size();\n    assert(a.size() == b.size());\n    auto ra = multiple_transform::zeta_transform(a);\n\
    \    auto rb = multiple_transform::zeta_transform(b);\n    for (int i = 0; i <\
    \ n; i++) {\n        ra[i] *= rb[i];\n    }\n    return multiple_transform::mobius_transform(ra);\n\
    }\n\n}  // namespace ebi\n#line 4 \"test/convolution/Gcd_Convolution.test.cpp\"\
    \n\n#include <iostream>\n#line 7 \"test/convolution/Gcd_Convolution.test.cpp\"\
    \n\n#line 2 \"modint/modint.hpp\"\n\r\n#line 5 \"modint/modint.hpp\"\n\r\n#line\
    \ 2 \"modint/base.hpp\"\n\n#include <concepts>\n#line 5 \"modint/base.hpp\"\n\
    #include <utility>\n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint =\
    \ requires(T a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n\
    \    a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n};\n\ntemplate\
    \ <Modint mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long\
    \ long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <Modint mint>\n\
    std::ostream &operator<<(std::ostream &os, const mint &a) {\n    return os <<\
    \ a.val();\n}\n\n}  // namespace ebi\n#line 7 \"modint/modint.hpp\"\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <int m> struct static_modint {\r\n  private:\r\n    using\
    \ modint = static_modint;\r\n\r\n  public:\r\n    static constexpr int mod() {\r\
    \n        return m;\r\n    }\r\n\r\n    static constexpr modint raw(int v) {\r\
    \n        modint x;\r\n        x._v = v;\r\n        return x;\r\n    }\r\n\r\n\
    \    constexpr static_modint() : _v(0) {}\r\n\r\n    constexpr static_modint(long\
    \ long v) {\r\n        v %= (long long)umod();\r\n        if (v < 0) v += (long\
    \ long)umod();\r\n        _v = (unsigned int)v;\r\n    }\r\n\r\n    constexpr\
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
    \ m;\r\n    }\r\n};\r\n\r\ntemplate <int m>\r\nstd::istream &operator>>(std::istream\
    \ &os, static_modint<m> &a) {\r\n    long long x;\r\n    os >> x;\r\n    a = x;\r\
    \n    return os;\r\n}\r\ntemplate <int m>\r\nstd::ostream &operator<<(std::ostream\
    \ &os, const static_modint<m> &a) {\r\n    return os << a.val();\r\n}\r\n\r\n\
    using modint998244353 = static_modint<998244353>;\r\nusing modint1000000007 =\
    \ static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 9 \"test/convolution/Gcd_Convolution.test.cpp\"\
    \n\nusing mint = ebi::modint998244353;\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n    std::vector<mint> a(n + 1), b(n + 1);\n    for (int i = 1; i <= n;\
    \ i++) {\n        std::cin >> a[i];\n    }\n    for (int i = 1; i <= n; i++) {\n\
    \        std::cin >> b[i];\n    }\n    auto c = ebi::gcd_convolution(a, b);\n\
    \    for (int i = 1; i <= n; i++) {\n        std::cout << c[i].val() << \" \\\
    n\"[i == n];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n\n#include\
    \ \"../../convolution/gcd_convolution.hpp\"\n\n#include <iostream>\n#include <vector>\n\
    \n#include \"../../modint/modint.hpp\"\n\nusing mint = ebi::modint998244353;\n\
    \nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<mint> a(n + 1),\
    \ b(n + 1);\n    for (int i = 1; i <= n; i++) {\n        std::cin >> a[i];\n \
    \   }\n    for (int i = 1; i <= n; i++) {\n        std::cin >> b[i];\n    }\n\
    \    auto c = ebi::gcd_convolution(a, b);\n    for (int i = 1; i <= n; i++) {\n\
    \        std::cout << c[i].val() << \" \\n\"[i == n];\n    }\n}"
  dependsOn:
  - convolution/gcd_convolution.hpp
  - math/multiple_transform.hpp
  - math/eratosthenes_sieve.hpp
  - modint/modint.hpp
  - modint/base.hpp
  isVerificationFile: true
  path: test/convolution/Gcd_Convolution.test.cpp
  requiredBy: []
  timestamp: '2023-10-26 11:41:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/convolution/Gcd_Convolution.test.cpp
layout: document
redirect_from:
- /verify/test/convolution/Gcd_Convolution.test.cpp
- /verify/test/convolution/Gcd_Convolution.test.cpp.html
title: test/convolution/Gcd_Convolution.test.cpp
---
