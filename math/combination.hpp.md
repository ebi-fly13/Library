---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  - icon: ':heavy_check_mark:'
    path: utility/modint_base.hpp
    title: utility/modint_base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/combination.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \n#line 2 \"utility/modint.hpp\"\n\r\n#line 4 \"utility/modint.hpp\"\n#include\
    \ <iostream>\r\n#include <type_traits>\r\n\r\n#line 2 \"utility/modint_base.hpp\"\
    \n\n#line 4 \"utility/modint_base.hpp\"\n\nnamespace ebi {\n\nnamespace internal\
    \ {\n\nstruct modint_base {};\n\ntemplate <class T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace ebi\n#line 8 \"utility/modint.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\nnamespace internal {\r\n\r\nstruct static_modint_base\
    \ : modint_base {};\r\n\r\ntemplate <class T>\r\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\r\n\r\ntemplate <class T>\r\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\r\
    \n\r\n}  // namespace internal\r\n\r\ntemplate <int m> struct static_modint :\
    \ internal::static_modint_base {\r\n  private:\r\n    using modint = static_modint;\r\
    \n\r\n  public:\r\n    static constexpr int mod() {\r\n        return m;\r\n \
    \   }\r\n\r\n    static constexpr modint raw(int v) {\r\n        modint x;\r\n\
    \        x._v = v;\r\n        return x;\r\n    }\r\n\r\n    constexpr static_modint()\
    \ : _v(0) {}\r\n\r\n    constexpr static_modint(long long v) {\r\n        v %=\
    \ (long long)umod();\r\n        if (v < 0) v += (long long)umod();\r\n       \
    \ _v = (unsigned int)v;\r\n    }\r\n\r\n    constexpr unsigned int val() const\
    \ {\r\n        return _v;\r\n    }\r\n\r\n    constexpr unsigned int value() const\
    \ {\r\n        return val();\r\n    }\r\n\r\n    constexpr modint &operator++()\
    \ {\r\n        _v++;\r\n        if (_v == umod()) _v = 0;\r\n        return *this;\r\
    \n    }\r\n    constexpr modint &operator--() {\r\n        if (_v == 0) _v = umod();\r\
    \n        _v--;\r\n        return *this;\r\n    }\r\n    constexpr modint &operator+=(const\
    \ modint &rhs) {\r\n        _v += rhs._v;\r\n        if (_v >= umod()) _v -= umod();\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator-=(const modint\
    \ &rhs) {\r\n        _v -= rhs._v;\r\n        if (_v >= umod()) _v += umod();\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator*=(const modint\
    \ &rhs) {\r\n        unsigned long long x = _v;\r\n        x *= rhs._v;\r\n  \
    \      _v = (unsigned int)(x % (unsigned long long)umod());\r\n        return\
    \ *this;\r\n    }\r\n    constexpr modint &operator/=(const modint &rhs) {\r\n\
    \        return *this = *this * rhs.inv();\r\n    }\r\n\r\n    constexpr modint\
    \ operator+() const {\r\n        return *this;\r\n    }\r\n    constexpr modint\
    \ operator-() const {\r\n        return modint() - *this;\r\n    }\r\n\r\n   \
    \ constexpr modint pow(long long n) const {\r\n        assert(0 <= n);\r\n   \
    \     modint x = *this, res = 1;\r\n        while (n) {\r\n            if (n &\
    \ 1) res *= x;\r\n            x *= x;\r\n            n >>= 1;\r\n        }\r\n\
    \        return res;\r\n    }\r\n    constexpr modint inv() const {\r\n      \
    \  assert(_v);\r\n        return pow(umod() - 2);\r\n    }\r\n\r\n    friend modint\
    \ operator+(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
    \ += rhs;\r\n    }\r\n    friend modint operator-(const modint &lhs, const modint\
    \ &rhs) {\r\n        return modint(lhs) -= rhs;\r\n    }\r\n    friend modint\
    \ operator*(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
    \ *= rhs;\r\n    }\r\n\r\n    friend modint operator/(const modint &lhs, const\
    \ modint &rhs) {\r\n        return modint(lhs) /= rhs;\r\n    }\r\n    friend\
    \ bool operator==(const modint &lhs, const modint &rhs) {\r\n        return lhs.val()\
    \ == rhs.val();\r\n    }\r\n    friend bool operator!=(const modint &lhs, const\
    \ modint &rhs) {\r\n        return !(lhs == rhs);\r\n    }\r\n\r\n  private:\r\
    \n    unsigned int _v = 0;\r\n\r\n    static constexpr unsigned int umod() {\r\
    \n        return m;\r\n    }\r\n};\r\n\r\ntemplate <int m>\r\nstd::istream &operator>>(std::istream\
    \ &os, static_modint<m> &a) {\r\n    long long x;\r\n    os >> x;\r\n    a = x;\r\
    \n    return os;\r\n}\r\ntemplate <int m>\r\nstd::ostream &operator<<(std::ostream\
    \ &os, const static_modint<m> &a) {\r\n    return os << a.val();\r\n}\r\n\r\n\
    using modint998244353 = static_modint<998244353>;\r\nusing modint1000000007 =\
    \ static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 7 \"math/combination.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class mint, internal::is_modint_t<mint>* = nullptr>\n\
    struct combination {\n    combination(int n) : m(n), fact(n + 1), inv_fact(n +\
    \ 1) {\n        fact[0] = 1;\n        for (int i = 1; i <= n; i++) {\n       \
    \     fact[i] = fact[i - 1] * i;\n        }\n        inv_fact[n] = fact[n].inv();\n\
    \        for (int i = n; i > 0; i--) {\n            inv_fact[i - 1] = inv_fact[i]\
    \ * i;\n        }\n    }\n\n    mint operator()(int n, int k) const {\n      \
    \  assert(n <= m);\n        if (k < 0 || n < k) return 0;\n        return fact[n]\
    \ * inv_fact[k] * inv_fact[n - k];\n    }\n\n    mint f(int n) const {\n     \
    \   assert(n <= m);\n        if (n < 0) return 0;\n        return fact[n];\n \
    \   }\n\n    mint inv_f(int n) const {\n        assert(n <= m);\n        if (n\
    \ < 0) return 0;\n        return inv_fact[n];\n    }\n\n    mint inv(int n) const\
    \ {\n        assert(n <= m);\n        return inv_fact[n] * fact[n-1];\n    }\n\
    \n  private:\n    int m;\n    std::vector<mint> fact, inv_fact;\n};\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../utility/modint.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class mint, internal::is_modint_t<mint>* = nullptr>\n\
    struct combination {\n    combination(int n) : m(n), fact(n + 1), inv_fact(n +\
    \ 1) {\n        fact[0] = 1;\n        for (int i = 1; i <= n; i++) {\n       \
    \     fact[i] = fact[i - 1] * i;\n        }\n        inv_fact[n] = fact[n].inv();\n\
    \        for (int i = n; i > 0; i--) {\n            inv_fact[i - 1] = inv_fact[i]\
    \ * i;\n        }\n    }\n\n    mint operator()(int n, int k) const {\n      \
    \  assert(n <= m);\n        if (k < 0 || n < k) return 0;\n        return fact[n]\
    \ * inv_fact[k] * inv_fact[n - k];\n    }\n\n    mint f(int n) const {\n     \
    \   assert(n <= m);\n        if (n < 0) return 0;\n        return fact[n];\n \
    \   }\n\n    mint inv_f(int n) const {\n        assert(n <= m);\n        if (n\
    \ < 0) return 0;\n        return inv_fact[n];\n    }\n\n    mint inv(int n) const\
    \ {\n        assert(n <= m);\n        return inv_fact[n] * fact[n-1];\n    }\n\
    \n  private:\n    int m;\n    std::vector<mint> fact, inv_fact;\n};\n\n}  // namespace\
    \ ebi"
  dependsOn:
  - utility/modint.hpp
  - utility/modint_base.hpp
  isVerificationFile: false
  path: math/combination.hpp
  requiredBy: []
  timestamp: '2023-05-31 02:50:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination.hpp
layout: document
redirect_from:
- /library/math/combination.hpp
- /library/math/combination.hpp.html
title: math/combination.hpp
---