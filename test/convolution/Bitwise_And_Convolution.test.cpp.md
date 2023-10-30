---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/and_convolution.hpp
    title: Bitwise AND Convolution
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':heavy_check_mark:'
    path: set_function/superset_transform.hpp
    title: "Superset Transform (Zeta / M\xF6bius)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"test/convolution/Bitwise_And_Convolution.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#line 2 \"convolution/and_convolution.hpp\"\
    \n\n#line 4 \"convolution/and_convolution.hpp\"\n\n#line 2 \"set_function/superset_transform.hpp\"\
    \n\n#include <bit>\n#include <cassert>\n#line 6 \"set_function/superset_transform.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> std::vector<T> superset_zeta(const std::vector<T>\
    \ &a) {\n    int n = std::bit_width(a.size()) - 1;\n    assert((1 << n) == (int)a.size());\n\
    \    std::vector<T> ra = a;\n    for (int i = 0; i < n; i++) {\n        int w\
    \ = 1 << i;\n        for (int p = 0; p < (1 << n); p += 2 * w) {\n           \
    \ for (int s = p; s < p + w; s++) {\n                int t = s | w;\n        \
    \        ra[s] += ra[t];\n            }\n        }\n    }\n    return ra;\n}\n\
    \ntemplate <class T> std::vector<T> superset_mobius(const std::vector<T> &ra)\
    \ {\n    int n = std::bit_width(ra.size()) - 1;\n    assert((1 << n) == (int)ra.size());\n\
    \    std::vector<T> a = ra;\n    for (int i = 0; i < n; i++) {\n        int w\
    \ = 1 << i;\n        for (int p = 0; p < (1 << n); p += 2 * w) {\n           \
    \ for (int s = p; s < p + w; s++) {\n                int t = s | w;\n        \
    \        a[s] -= a[t];\n            }\n        }\n    }\n    return a;\n}\n\n\
    }  // namespace ebi\n#line 6 \"convolution/and_convolution.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <class T>\nstd::vector<T> and_convolution(const std::vector<T>\
    \ &a,\n                               const std::vector<T> &b) {\n    int n =\
    \ a.size();\n    auto ra = superset_zeta(a);\n    auto rb = superset_zeta(b);\n\
    \    for (int i = 0; i < n; i++) {\n        ra[i] *= rb[i];\n    }\n    return\
    \ superset_mobius(ra);\n}\n\n}  // namespace ebi\n#line 2 \"modint/modint.hpp\"\
    \n\r\n#line 5 \"modint/modint.hpp\"\n\r\n#line 2 \"modint/base.hpp\"\n\n#include\
    \ <concepts>\n#line 5 \"modint/base.hpp\"\n#include <utility>\n\nnamespace ebi\
    \ {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n    a + b;\n\
    \    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 7 \"\
    modint/modint.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate <int m> struct static_modint\
    \ {\r\n  private:\r\n    using modint = static_modint;\r\n\r\n  public:\r\n  \
    \  static constexpr int mod() {\r\n        return m;\r\n    }\r\n\r\n    static\
    \ constexpr modint raw(int v) {\r\n        modint x;\r\n        x._v = v;\r\n\
    \        return x;\r\n    }\r\n\r\n    constexpr static_modint() : _v(0) {}\r\n\
    \r\n    constexpr static_modint(long long v) {\r\n        v %= (long long)umod();\r\
    \n        if (v < 0) v += (long long)umod();\r\n        _v = (unsigned int)v;\r\
    \n    }\r\n\r\n    constexpr unsigned int val() const {\r\n        return _v;\r\
    \n    }\r\n\r\n    constexpr unsigned int value() const {\r\n        return val();\r\
    \n    }\r\n\r\n    constexpr modint &operator++() {\r\n        _v++;\r\n     \
    \   if (_v == umod()) _v = 0;\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator--() {\r\n        if (_v == 0) _v = umod();\r\n        _v--;\r\
    \n        return *this;\r\n    }\r\n\r\n    constexpr modint operator++(int) {\r\
    \n        modint res = *this;\r\n        ++*this;\r\n        return res;\r\n \
    \   }\r\n    constexpr modint operator--(int) {\r\n        modint res = *this;\r\
    \n        --*this;\r\n        return res;\r\n    }\r\n\r\n    constexpr modint\
    \ &operator+=(const modint &rhs) {\r\n        _v += rhs._v;\r\n        if (_v\
    \ >= umod()) _v -= umod();\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator-=(const modint &rhs) {\r\n        _v -= rhs._v;\r\n       \
    \ if (_v >= umod()) _v += umod();\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator*=(const modint &rhs) {\r\n        unsigned long long x = _v;\r\
    \n        x *= rhs._v;\r\n        _v = (unsigned int)(x % (unsigned long long)umod());\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator/=(const modint\
    \ &rhs) {\r\n        return *this = *this * rhs.inv();\r\n    }\r\n\r\n    constexpr\
    \ modint operator+() const {\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint operator-() const {\r\n        return modint() - *this;\r\n    }\r\n\r\
    \n    constexpr modint pow(long long n) const {\r\n        assert(0 <= n);\r\n\
    \        modint x = *this, res = 1;\r\n        while (n) {\r\n            if (n\
    \ & 1) res *= x;\r\n            x *= x;\r\n            n >>= 1;\r\n        }\r\
    \n        return res;\r\n    }\r\n    constexpr modint inv() const {\r\n     \
    \   assert(_v);\r\n        return pow(umod() - 2);\r\n    }\r\n\r\n    friend\
    \ modint operator+(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
    \ += rhs;\r\n    }\r\n    friend modint operator-(const modint &lhs, const modint\
    \ &rhs) {\r\n        return modint(lhs) -= rhs;\r\n    }\r\n    friend modint\
    \ operator*(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
    \ *= rhs;\r\n    }\r\n\r\n    friend modint operator/(const modint &lhs, const\
    \ modint &rhs) {\r\n        return modint(lhs) /= rhs;\r\n    }\r\n    friend\
    \ bool operator==(const modint &lhs, const modint &rhs) {\r\n        return lhs.val()\
    \ == rhs.val();\r\n    }\r\n    friend bool operator!=(const modint &lhs, const\
    \ modint &rhs) {\r\n        return !(lhs == rhs);\r\n    }\r\n\r\n  private:\r\
    \n    unsigned int _v = 0;\r\n\r\n    static constexpr unsigned int umod() {\r\
    \n        return m;\r\n    }\r\n};\r\n\r\nusing modint998244353 = static_modint<998244353>;\r\
    \nusing modint1000000007 = static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n\
    #line 8 \"test/convolution/Bitwise_And_Convolution.test.cpp\"\n\nusing mint =\
    \ ebi::modint998244353;\n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<mint>\
    \ a(1 << n), b(1 << n);\n    for (int i = 0; i < (1 << n); i++) {\n        int\
    \ x;\n        std::cin >> x;\n        a[i] = x;\n    }\n    for (int i = 0; i\
    \ < (1 << n); i++) {\n        int x;\n        std::cin >> x;\n        b[i] = x;\n\
    \    }\n    auto c = ebi::and_convolution(a, b);\n    for (int i = 0; i < (1 <<\
    \ n); i++) {\n        std::cout << c[i].val() << \" \\n\"[i == (1 << n) - 1];\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../convolution/and_convolution.hpp\"\
    \n#include \"../../modint/modint.hpp\"\n\nusing mint = ebi::modint998244353;\n\
    \nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<mint> a(1 << n),\
    \ b(1 << n);\n    for (int i = 0; i < (1 << n); i++) {\n        int x;\n     \
    \   std::cin >> x;\n        a[i] = x;\n    }\n    for (int i = 0; i < (1 << n);\
    \ i++) {\n        int x;\n        std::cin >> x;\n        b[i] = x;\n    }\n \
    \   auto c = ebi::and_convolution(a, b);\n    for (int i = 0; i < (1 << n); i++)\
    \ {\n        std::cout << c[i].val() << \" \\n\"[i == (1 << n) - 1];\n    }\n}"
  dependsOn:
  - convolution/and_convolution.hpp
  - set_function/superset_transform.hpp
  - modint/modint.hpp
  - modint/base.hpp
  isVerificationFile: true
  path: test/convolution/Bitwise_And_Convolution.test.cpp
  requiredBy: []
  timestamp: '2023-10-31 00:16:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/convolution/Bitwise_And_Convolution.test.cpp
layout: document
redirect_from:
- /verify/test/convolution/Bitwise_And_Convolution.test.cpp
- /verify/test/convolution/Bitwise_And_Convolution.test.cpp.html
title: test/convolution/Bitwise_And_Convolution.test.cpp
---
