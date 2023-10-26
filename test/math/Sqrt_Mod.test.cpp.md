---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_sqrt.hpp
    title: Mod Sqrt
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':heavy_check_mark:'
    path: modint/dynamic_modint.hpp
    title: modint/dynamic_modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"test/math/Sqrt_Mod.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\
    \n\n#include <iostream>\n\n#line 2 \"math/mod_sqrt.hpp\"\n\n#include <cstdint>\n\
    #include <optional>\n\n#line 2 \"modint/dynamic_modint.hpp\"\n\n#include <cassert>\n\
    \n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#line 5 \"modint/base.hpp\"\
    \n#include <utility>\n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint\
    \ = requires(T a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n   \
    \ a.inv();\n    a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n\
    };\n\ntemplate <Modint mint> std::istream &operator>>(std::istream &os, mint &a)\
    \ {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate\
    \ <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const mint &a) {\n\
    \    return os << a.val();\n}\n\n}  // namespace ebi\n#line 6 \"modint/dynamic_modint.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <int id> struct dynamic_modint {\n  private:\n\
    \    using modint = dynamic_modint;\n\n  public:\n    static void set_mod(int\
    \ p) {\n        assert(1 <= p);\n        m = p;\n    }\n\n    static int mod()\
    \ {\n        return m;\n    }\n\n    modint raw(int v) {\n        modint x;\n\
    \        x._v = v;\n        return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n\
    \n    dynamic_modint(long long v) {\n        v %= (long long)umod();\n       \
    \ if (v < 0) v += (long long)umod();\n        _v = (unsigned int)v;\n    }\n\n\
    \    unsigned int val() const {\n        return _v;\n    }\n\n    unsigned int\
    \ value() const {\n        return val();\n    }\n\n    modint &operator++() {\n\
    \        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n   \
    \ }\n    modint &operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    modint &operator+=(const modint &rhs) {\n \
    \       _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n        return\
    \ *this;\n    }\n    modint &operator-=(const modint &rhs) {\n        _v -= rhs._v;\n\
    \        if (_v >= umod()) _v += umod();\n        return *this;\n    }\n    modint\
    \ &operator*=(const modint &rhs) {\n        unsigned long long x = _v;\n     \
    \   x *= rhs._v;\n        _v = (unsigned int)(x % (unsigned long long)umod());\n\
    \        return *this;\n    }\n    modint &operator/=(const modint &rhs) {\n \
    \       return *this = *this * rhs.inv();\n    }\n\n    modint operator+() const\
    \ {\n        return *this;\n    }\n    modint operator-() const {\n        return\
    \ modint() - *this;\n    }\n\n    modint pow(long long n) const {\n        assert(0\
    \ <= n);\n        modint x = *this, res = 1;\n        while (n) {\n          \
    \  if (n & 1) res *= x;\n            x *= x;\n            n >>= 1;\n        }\n\
    \        return res;\n    }\n    modint inv() const {\n        assert(_v);\n \
    \       return pow(umod() - 2);\n    }\n\n    friend modint operator+(const modint\
    \ &lhs, const modint &rhs) {\n        return modint(lhs) += rhs;\n    }\n    friend\
    \ modint operator-(const modint &lhs, const modint &rhs) {\n        return modint(lhs)\
    \ -= rhs;\n    }\n    friend modint operator*(const modint &lhs, const modint\
    \ &rhs) {\n        return modint(lhs) *= rhs;\n    }\n\n    friend modint operator/(const\
    \ modint &lhs, const modint &rhs) {\n        return modint(lhs) /= rhs;\n    }\n\
    \    friend bool operator==(const modint &lhs, const modint &rhs) {\n        return\
    \ lhs.val() == rhs.val();\n    }\n    friend bool operator!=(const modint &lhs,\
    \ const modint &rhs) {\n        return !(lhs == rhs);\n    }\n\n  private:\n \
    \   unsigned int _v = 0;\n    static int m;\n\n    static unsigned int umod()\
    \ {\n        return m;\n    }\n};\n\ntemplate <int id> int dynamic_modint<id>::m\
    \ = 998244353;\n\n}  // namespace ebi\n#line 7 \"math/mod_sqrt.hpp\"\n\nnamespace\
    \ ebi {\n\nstd::optional<std::int64_t> mod_sqrt(const std::int64_t &a,\n     \
    \                                const std::int64_t &p) {\n    if (a == 0 || a\
    \ == 1) return a;\n    using mint = dynamic_modint<100>;\n    mint::set_mod(p);\n\
    \    if (mint(a).pow((p - 1) >> 1) != 1) return std::nullopt;\n    mint b = 1;\n\
    \    while (b.pow((p - 1) >> 1) == 1) b += 1;\n    std::int64_t m = p - 1, e =\
    \ 0;\n    while (m % 2 == 0) m >>= 1, e++;\n    mint x = mint(a).pow((m - 1) >>\
    \ 1);\n    mint y = mint(a) * x * x;\n    x *= a;\n    mint z = b.pow(m);\n  \
    \  while (y != 1) {\n        std::int64_t j = 0;\n        mint t = y;\n      \
    \  while (t != 1) {\n            j++;\n            t *= t;\n        }\n      \
    \  z = z.pow(1ll << (e - j - 1));\n        x *= z;\n        z *= z;\n        y\
    \ *= z;\n        e = j;\n    }\n    return x.val();\n}\n\n}  // namespace ebi\n\
    #line 6 \"test/math/Sqrt_Mod.test.cpp\"\n\nint main() {\n    int t;\n    std::cin\
    \ >> t;\n    while (t--) {\n        int y, p;\n        std::cin >> y >> p;\n \
    \       auto x = ebi::mod_sqrt(y, p);\n        if (x) {\n            std::cout\
    \ << x.value() << '\\n';\n        } else {\n            std::cout << \"-1\\n\"\
    ;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n\n#include\
    \ <iostream>\n\n#include \"../../math/mod_sqrt.hpp\"\n\nint main() {\n    int\
    \ t;\n    std::cin >> t;\n    while (t--) {\n        int y, p;\n        std::cin\
    \ >> y >> p;\n        auto x = ebi::mod_sqrt(y, p);\n        if (x) {\n      \
    \      std::cout << x.value() << '\\n';\n        } else {\n            std::cout\
    \ << \"-1\\n\";\n        }\n    }\n}"
  dependsOn:
  - math/mod_sqrt.hpp
  - modint/dynamic_modint.hpp
  - modint/base.hpp
  isVerificationFile: true
  path: test/math/Sqrt_Mod.test.cpp
  requiredBy: []
  timestamp: '2023-10-26 11:41:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/Sqrt_Mod.test.cpp
layout: document
redirect_from:
- /verify/test/math/Sqrt_Mod.test.cpp
- /verify/test/math/Sqrt_Mod.test.cpp.html
title: test/math/Sqrt_Mod.test.cpp
---
