---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"test/pow.test.cpp\"\n#define PROBLEM \\\r\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \r\n\r\n\r\n#include <iostream>\r\n\r\n#line 2 \"utility/modint.hpp\"\n\r\n#include\
    \ <cassert>\r\n#line 5 \"utility/modint.hpp\"\n#include <type_traits>\r\n\r\n\
    namespace ebi {\r\n\r\nnamespace internal {\r\n\r\nstruct modint_base {};\r\n\
    struct static_modint_base : modint_base {};\r\n\r\ntemplate <class T> using is_modint\
    \ = std::is_base_of<modint_base, T>;\r\ntemplate <class T> using is_modint_t =\
    \ std::enable_if_t<is_modint<T>::value>;\r\n\r\n}\r\n\r\ntemplate <int m> struct\
    \ static_modint : internal::static_modint_base {\r\nprivate:\r\n    using modint\
    \ = static_modint;\r\n  public:\r\n    static constexpr int mod() {\r\n      \
    \  return m;\r\n    }\r\n\r\n    static modint raw(int v) {\r\n        modint\
    \ x;\r\n        x._v = v;\r\n        return x;\r\n    }\r\n\r\n    static_modint()\
    \ : _v(0) {}\r\n\r\n    static_modint(long long v) {\r\n        v %= (long long)umod();\r\
    \n        if (v < 0) v += (long long)umod();\r\n        _v = (unsigned int)v;\r\
    \n    }\r\n\r\n    unsigned int val() const {\r\n        return _v;\r\n    }\r\
    \n\r\n    unsigned int value() const {\r\n        return val();\r\n    }\r\n\r\
    \n    modint &operator++() {\r\n        _v++;\r\n        if (_v == umod()) _v\
    \ = 0;\r\n        return *this;\r\n    }\r\n    modint &operator--() {\r\n   \
    \     if (_v == 0) _v = umod();\r\n        _v--;\r\n        return *this;\r\n\
    \    }\r\n    modint &operator+=(const modint &rhs) {\r\n        _v += rhs._v;\r\
    \n        if (_v >= umod()) _v -= umod();\r\n        return *this;\r\n    }\r\n\
    \    modint &operator-=(const modint &rhs) {\r\n        _v -= rhs._v;\r\n    \
    \    if (_v >= umod()) _v += umod();\r\n        return *this;\r\n    }\r\n   \
    \ modint &operator*=(const modint &rhs) {\r\n        unsigned long long x = _v;\r\
    \n        x *= rhs._v;\r\n        _v = (unsigned int)(x % (unsigned long long)umod());\r\
    \n        return *this;\r\n    }\r\n    modint &operator/=(const modint &rhs)\
    \ {\r\n        return *this = *this * rhs.inv();\r\n    }\r\n\r\n    modint operator+()\
    \ const {\r\n        return *this;\r\n    }\r\n    modint operator-() const {\r\
    \n        return modint() - *this;\r\n    }\r\n\r\n    modint pow(long long n)\
    \ const {\r\n        assert(0 <= n);\r\n        modint x = *this, res = 1;\r\n\
    \        while (n) {\r\n            if (n & 1) res *= x;\r\n            x *= x;\r\
    \n            n >>= 1;\r\n        }\r\n        return res;\r\n    }\r\n    modint\
    \ inv() const {\r\n        assert(_v);\r\n        return pow(umod() - 2);\r\n\
    \    }\r\n\r\n    friend modint operator+(const modint &lhs, const modint &rhs)\
    \ {\r\n        return modint(lhs) += rhs;\r\n    }\r\n    friend modint operator-(const\
    \ modint &lhs, const modint &rhs) {\r\n        return modint(lhs) -= rhs;\r\n\
    \    }\r\n    friend modint operator*(const modint &lhs, const modint &rhs) {\r\
    \n        return modint(lhs) *= rhs;\r\n    }\r\n\r\n    friend modint operator/(const\
    \ modint &lhs, const modint &rhs) {\r\n        return modint(lhs) /= rhs;\r\n\
    \    }\r\n    friend bool operator==(const modint &lhs, const modint &rhs) {\r\
    \n        return lhs.val() == rhs.val();\r\n    }\r\n    friend bool operator!=(const\
    \ modint &lhs, const modint &rhs) {\r\n        return !(lhs == rhs);\r\n    }\r\
    \n\r\n  private:\r\n    unsigned int _v;\r\n\r\n    static constexpr unsigned\
    \ int umod() {\r\n        return m;\r\n    }\r\n};\r\n\r\ntemplate <int m> std::istream\
    \ &operator>>(std::istream &os, static_modint<m> &a) {\r\n    long long x;\r\n\
    \    os >> x;\r\n    a = x;\r\n    return os;\r\n}\r\ntemplate <int m>\r\nstd::ostream\
    \ &operator<<(std::ostream &os, const static_modint<m> &a) {\r\n    return os\
    \ << a.val();\r\n}\r\n\r\nusing modint998244353 = static_modint<998244353>;\r\n\
    using modint1000000007 = static_modint<1000000007>;\r\n\r\nnamespace internal\
    \ {\r\n\r\ntemplate <class T>\r\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\r\n\r\ntemplate <class T>\r\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\r\
    \n\r\n}\r\n\r\n}  // namespace ebi\n#line 8 \"test/pow.test.cpp\"\n\r\nusing mint\
    \ = ebi::modint1000000007;\r\n\r\nint main() {\r\n    long long m, n;\r\n    std::cin\
    \ >> m >> n;\r\n    std::cout << mint(m).pow(n) << '\\n';\r\n}\n"
  code: "#define PROBLEM \\\r\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \r\n\r\n\r\n#include <iostream>\r\n\r\n#include \"../utility/modint.hpp\"\r\n\r\
    \nusing mint = ebi::modint1000000007;\r\n\r\nint main() {\r\n    long long m,\
    \ n;\r\n    std::cin >> m >> n;\r\n    std::cout << mint(m).pow(n) << '\\n';\r\
    \n}"
  dependsOn:
  - utility/modint.hpp
  isVerificationFile: true
  path: test/pow.test.cpp
  requiredBy: []
  timestamp: '2023-05-17 13:07:23+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/pow.test.cpp
layout: document
redirect_from:
- /verify/test/pow.test.cpp
- /verify/test/pow.test.cpp.html
title: test/pow.test.cpp
---
