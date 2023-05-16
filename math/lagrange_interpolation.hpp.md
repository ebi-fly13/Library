---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc208/editorial/2195
    - https://atcoder.jp/contests/abc208/tasks/abc208_f
  bundledCode: "#line 2 \"math/lagrange_interpolation.hpp\"\n\n#include <vector>\n\
    \n#line 2 \"utility/modint.hpp\"\n\r\n#include <cassert>\r\n#include <iostream>\r\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <int m> struct modint {\r\n  public:\r\n\
    \    static constexpr int mod() {\r\n        return m;\r\n    }\r\n\r\n    static\
    \ modint raw(int v) {\r\n        modint x;\r\n        x._v = v;\r\n        return\
    \ x;\r\n    }\r\n\r\n    modint() : _v(0) {}\r\n\r\n    modint(long long v) {\r\
    \n        v %= (long long)umod();\r\n        if (v < 0) v += (long long)umod();\r\
    \n        _v = (unsigned int)v;\r\n    }\r\n\r\n    unsigned int val() const {\r\
    \n        return _v;\r\n    }\r\n\r\n    unsigned int value() const {\r\n    \
    \    return val();\r\n    }\r\n\r\n    modint &operator++() {\r\n        _v++;\r\
    \n        if (_v == umod()) _v = 0;\r\n        return *this;\r\n    }\r\n    modint\
    \ &operator--() {\r\n        if (_v == 0) _v = umod();\r\n        _v--;\r\n  \
    \      return *this;\r\n    }\r\n    modint &operator+=(const modint &rhs) {\r\
    \n        _v += rhs._v;\r\n        if (_v >= umod()) _v -= umod();\r\n       \
    \ return *this;\r\n    }\r\n    modint &operator-=(const modint &rhs) {\r\n  \
    \      _v -= rhs._v;\r\n        if (_v >= umod()) _v += umod();\r\n        return\
    \ *this;\r\n    }\r\n    modint &operator*=(const modint &rhs) {\r\n        unsigned\
    \ long long x = _v;\r\n        x *= rhs._v;\r\n        _v = (unsigned int)(x %\
    \ (unsigned long long)umod());\r\n        return *this;\r\n    }\r\n    modint\
    \ &operator/=(const modint &rhs) {\r\n        return *this = *this * rhs.inv();\r\
    \n    }\r\n\r\n    modint operator+() const {\r\n        return *this;\r\n   \
    \ }\r\n    modint operator-() const {\r\n        return modint() - *this;\r\n\
    \    }\r\n\r\n    modint pow(long long n) const {\r\n        assert(0 <= n);\r\
    \n        modint x = *this, res = 1;\r\n        while (n) {\r\n            if\
    \ (n & 1) res *= x;\r\n            x *= x;\r\n            n >>= 1;\r\n       \
    \ }\r\n        return res;\r\n    }\r\n    modint inv() const {\r\n        assert(_v);\r\
    \n        return pow(umod() - 2);\r\n    }\r\n\r\n    friend modint operator+(const\
    \ modint &lhs, const modint &rhs) {\r\n        return modint(lhs) += rhs;\r\n\
    \    }\r\n    friend modint operator-(const modint &lhs, const modint &rhs) {\r\
    \n        return modint(lhs) -= rhs;\r\n    }\r\n    friend modint operator*(const\
    \ modint &lhs, const modint &rhs) {\r\n        return modint(lhs) *= rhs;\r\n\
    \    }\r\n\r\n    friend modint operator/(const modint &lhs, const modint &rhs)\
    \ {\r\n        return modint(lhs) /= rhs;\r\n    }\r\n    friend bool operator==(const\
    \ modint &lhs, const modint &rhs) {\r\n        return lhs.val() == rhs.val();\r\
    \n    }\r\n    friend bool operator!=(const modint &lhs, const modint &rhs) {\r\
    \n        return !(lhs == rhs);\r\n    }\r\n\r\n  private:\r\n    unsigned int\
    \ _v;\r\n\r\n    static constexpr unsigned int umod() {\r\n        return m;\r\
    \n    }\r\n};\r\n\r\ntemplate <int m> std::istream &operator>>(std::istream &os,\
    \ modint<m> &a) {\r\n    long long x;\r\n    os >> x;\r\n    a = x;\r\n    return\
    \ os;\r\n}\r\ntemplate <int m>\r\nstd::ostream &operator<<(std::ostream &os, const\
    \ modint<m> &a) {\r\n    return os << a.val();\r\n}\r\n\r\nusing modint998244353\
    \ = modint<998244353>;\r\nusing modint1000000007 = modint<1000000007>;\r\n\r\n\
    }  // namespace ebi\n#line 6 \"math/lagrange_interpolation.hpp\"\n\n/*\n    reference:\
    \ https://atcoder.jp/contests/abc208/editorial/2195\n    verify: https://atcoder.jp/contests/abc208/tasks/abc208_f\n\
    */\n\nnamespace ebi {\n\nusing mint = modint1000000007;\nusing i64 = long long;\n\
    \nmint lagrange_interpolation(const std::vector<mint> &f, i64 n) {\n    const\
    \ int d = int(f.size()) - 1;  // N\u306Ed\u6B21\u4EE5\u4E0B\u306E\u591A\u9805\u5F0F\
    \n    mint fact = 1;\n    std::vector<mint> inv_fact(d + 1);\n    for (int i =\
    \ 1; i < d + 1; ++i) {\n        fact *= i;\n    }\n    inv_fact[d] = fact.inv();\n\
    \    for (int i = d; i > 0; i--) {\n        inv_fact[i - 1] = inv_fact[i] * i;\n\
    \    }\n    std::vector<mint> l(d + 1), r(d + 1);\n    l[0] = 1;\n    for (int\
    \ i = 0; i < d; ++i) {\n        l[i + 1] = l[i] * (n - i);\n    }\n    r[d] =\
    \ 1;\n    for (int i = d; i > 0; --i) {\n        r[i - 1] = r[i] * (n - i);\n\
    \    }\n    mint res = 0;\n    for (int i = 0; i < d + 1; ++i) {\n        res\
    \ += mint((d - i) % 2 == 1 ? -1 : 1) * f[i] * l[i] * r[i] *\n               inv_fact[i]\
    \ * inv_fact[d - i];\n    }\n    return res;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <vector>\n\n#include \"../utility/modint.hpp\"\n\
    \n/*\n    reference: https://atcoder.jp/contests/abc208/editorial/2195\n    verify:\
    \ https://atcoder.jp/contests/abc208/tasks/abc208_f\n*/\n\nnamespace ebi {\n\n\
    using mint = modint1000000007;\nusing i64 = long long;\n\nmint lagrange_interpolation(const\
    \ std::vector<mint> &f, i64 n) {\n    const int d = int(f.size()) - 1;  // N\u306E\
    d\u6B21\u4EE5\u4E0B\u306E\u591A\u9805\u5F0F\n    mint fact = 1;\n    std::vector<mint>\
    \ inv_fact(d + 1);\n    for (int i = 1; i < d + 1; ++i) {\n        fact *= i;\n\
    \    }\n    inv_fact[d] = fact.inv();\n    for (int i = d; i > 0; i--) {\n   \
    \     inv_fact[i - 1] = inv_fact[i] * i;\n    }\n    std::vector<mint> l(d + 1),\
    \ r(d + 1);\n    l[0] = 1;\n    for (int i = 0; i < d; ++i) {\n        l[i + 1]\
    \ = l[i] * (n - i);\n    }\n    r[d] = 1;\n    for (int i = d; i > 0; --i) {\n\
    \        r[i - 1] = r[i] * (n - i);\n    }\n    mint res = 0;\n    for (int i\
    \ = 0; i < d + 1; ++i) {\n        res += mint((d - i) % 2 == 1 ? -1 : 1) * f[i]\
    \ * l[i] * r[i] *\n               inv_fact[i] * inv_fact[d - i];\n    }\n    return\
    \ res;\n}\n\n}  // namespace ebi"
  dependsOn:
  - utility/modint.hpp
  isVerificationFile: false
  path: math/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2023-05-16 13:16:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/lagrange_interpolation.hpp
layout: document
redirect_from:
- /library/math/lagrange_interpolation.hpp
- /library/math/lagrange_interpolation.hpp.html
title: math/lagrange_interpolation.hpp
---
