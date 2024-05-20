---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convolution/convolution.hpp
    title: Convolution
  - icon: ':x:'
    path: math/bostan_mori_algorithm.hpp
    title: Bostan-Mori Algorithm
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
    links:
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
  bundledCode: "#line 1 \"test/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"convolution/convolution.hpp\"\
    \n\n#include <algorithm>\n#include <bit>\n#line 6 \"convolution/convolution.hpp\"\
    \n\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#line 5 \"modint/base.hpp\"\
    \n#include <utility>\n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint\
    \ = requires(T a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n   \
    \ a.inv();\n    a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n\
    };\n\ntemplate <Modint mint> std::istream &operator>>(std::istream &os, mint &a)\
    \ {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate\
    \ <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const mint &a) {\n\
    \    return os << a.val();\n}\n\n}  // namespace ebi\n#line 9 \"convolution/convolution.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint>\nstd::vector<mint> convolution_naive(const\
    \ std::vector<mint>& f,\n                                    const std::vector<mint>&\
    \ g) {\n    if (f.empty() || g.empty()) return {};\n    int n = int(f.size()),\
    \ m = int(g.size());\n    std::vector<mint> c(n + m - 1);\n    if (n < m) {\n\
    \        for (int j = 0; j < m; j++) {\n            for (int i = 0; i < n; i++)\
    \ {\n                c[i + j] += f[i] * g[j];\n            }\n        }\n    }\
    \ else {\n        for (int i = 0; i < n; i++) {\n            for (int j = 0; j\
    \ < m; j++) {\n                c[i + j] += f[i] * g[j];\n            }\n     \
    \   }\n    }\n    return c;\n}\n\ntemplate <Modint mint>\nstd::vector<mint> convolution(const\
    \ std::vector<mint>& f,\n                              const std::vector<mint>&\
    \ g) {\n    if (f.empty() || g.empty()) return {};\n    if (std::min(f.size(),\
    \ g.size()) < 60) return convolution_naive(f, g);\n    int n = std::bit_ceil(f.size()\
    \ + g.size() - 1);\n    std::vector<mint> a(n), b(n);\n    std::copy(f.begin(),\
    \ f.end(), a.begin());\n    std::copy(g.begin(), g.end(), b.begin());\n    internal::butterfly(a);\n\
    \    internal::butterfly(b);\n    for (int i = 0; i < n; i++) {\n        a[i]\
    \ *= b[i];\n    }\n    internal::butterfly_inv(a);\n    a.resize(f.size() + g.size()\
    \ - 1);\n    return a;\n}\n\n}  // namespace ebi\n#line 2 \"math/bostan_mori_algorithm.hpp\"\
    \n\n#include <cstdint>\n#line 5 \"math/bostan_mori_algorithm.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <class T, std::vector<T> (*convolution)(const std::vector<T>\
    \ &,\n                                                 const std::vector<T> &)>\n\
    T bostan_mori_algorithm(std::int64_t n, std::vector<T> p, std::vector<T> q) {\n\
    \    while (n > 0) {\n        auto q_neg = q;\n        for (int i = 1; i < (int)q_neg.size();\
    \ i += 2) q_neg[i] = -q_neg[i];\n        p = convolution(p, q_neg);\n        q\
    \ = convolution(q, q_neg);\n        for (int i = (n & 1LL); i < (int)p.size();\
    \ i += 2) p[i >> 1] = p[i];\n        p.resize(((int)p.size() + 1 - (n & 1LL))\
    \ / 2);\n        for (int i = 0; i < (int)q.size(); i += 2) q[i >> 1] = q[i];\n\
    \        q.resize(((int)q.size() + 1) / 2);\n        n >>= 1;\n    }\n    return\
    \ p[0] / q[0];\n}\n\ntemplate <class T, std::vector<T> (*convolution)(const std::vector<T>\
    \ &,\n                                                 const std::vector<T> &)>\n\
    T kitamasa(std::int64_t n, std::vector<T> a, std::vector<T> c) {\n    if (n <\
    \ (int)a.size()) return a[n];\n    const int d = c.size();\n    for (auto &val\
    \ : c) val = -val;\n    c.insert(c.begin(), 1);\n    auto p = convolution(a, c);\n\
    \    p.resize(d);\n    return bostan_mori_algorithm<T, convolution>(n, p, c);\n\
    }\n\n}  // namespace ebi\n#line 2 \"modint/modint.hpp\"\n\r\n#include <cassert>\r\
    \n#line 5 \"modint/modint.hpp\"\n\r\n#line 7 \"modint/modint.hpp\"\n\r\nnamespace\
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
    \ m;\r\n    }\r\n};\r\n\r\nusing modint998244353 = static_modint<998244353>;\r\
    \nusing modint1000000007 = static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n\
    #line 10 \"test/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp\"\n\nusing\
    \ mint = ebi::modint998244353;\n\nint main() {\n    int d;\n    long long k;\n\
    \    std::cin >> d >> k;\n    std::vector<mint> a(d), c(d);\n    for (int i =\
    \ 0; i < d; i++) {\n        int val;\n        std::cin >> val;\n        a[i] =\
    \ val;\n    }\n    for (int i = 0; i < d; i++) {\n        int val;\n        std::cin\
    \ >> val;\n        c[i] = val;\n    }\n    std::cout << ebi::kitamasa<mint, ebi::convolution>(k,\
    \ a, c).val() << '\\n';\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../convolution/convolution.hpp\"\
    \n#include \"../../math/bostan_mori_algorithm.hpp\"\n#include \"../../modint/modint.hpp\"\
    \n\nusing mint = ebi::modint998244353;\n\nint main() {\n    int d;\n    long long\
    \ k;\n    std::cin >> d >> k;\n    std::vector<mint> a(d), c(d);\n    for (int\
    \ i = 0; i < d; i++) {\n        int val;\n        std::cin >> val;\n        a[i]\
    \ = val;\n    }\n    for (int i = 0; i < d; i++) {\n        int val;\n       \
    \ std::cin >> val;\n        c[i] = val;\n    }\n    std::cout << ebi::kitamasa<mint,\
    \ ebi::convolution>(k, a, c).val() << '\\n';\n}"
  dependsOn:
  - convolution/convolution.hpp
  - modint/base.hpp
  - math/bostan_mori_algorithm.hpp
  - modint/modint.hpp
  isVerificationFile: true
  path: test/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  requiredBy: []
  timestamp: '2024-05-20 22:28:31+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
layout: document
redirect_from:
- /verify/test/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
- /verify/test/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp.html
title: test/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
---
