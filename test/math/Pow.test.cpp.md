---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':x:'
    path: modint/montgomery_modint.hpp
    title: modint/montgomery_modint.hpp
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
  bundledCode: "#line 1 \"test/math/Pow.test.cpp\"\n#define PROBLEM \\\r\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \r\n\r\n#include <iostream>\r\n\r\n#line 2 \"modint/montgomery_modint.hpp\"\n\n\
    #include <cstdint>\n#line 5 \"modint/montgomery_modint.hpp\"\n\n#line 2 \"modint/base.hpp\"\
    \n\n#include <concepts>\n#line 5 \"modint/base.hpp\"\n#include <utility>\n\nnamespace\
    \ ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n    a +\
    \ b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 7 \"\
    modint/montgomery_modint.hpp\"\n\nnamespace ebi {\n\ntemplate <int m> struct montgomery_modint\
    \ {\n  private:\n    using modint = montgomery_modint;\n    using i32 = std::int32_t;\n\
    \    using u32 = std::uint32_t;\n    using i64 = std::int64_t;\n    using u64\
    \ = std::uint64_t;\n\n    static constexpr u32 umod() {\n        return m;\n \
    \   }\n\n    static constexpr u32 get_r() {\n        u32 ret = umod();\n     \
    \   for (i32 i = 0; i < 4; i++) ret *= 2 - umod() * ret;\n        return ret;\n\
    \    }\n\n    static constexpr u32 r = get_r();\n    static constexpr u32 n2 =\
    \ -u64(umod()) % umod();\n\n    static constexpr u32 reduce(const u64 &b) {\n\
    \        return u32(b >> 32) + umod() - u32((u64(u32(b) * r) * umod()) >> 32);\n\
    \    }\n\n    static constexpr u32 one = reduce(i64(1 + umod()) * n2);\n\n   \
    \ static_assert(r * umod() == 1, \"invalid, r * mod != 1\");\n    static_assert(umod()\
    \ < (1 << 30), \"invalid, mod >= 2 ^ 30\");\n    static_assert((umod() & 1) ==\
    \ 1, \"invalid, mod % 2 == 0\");\n\n  public:\n    static constexpr int mod()\
    \ {\n        return m;\n    }\n\n    constexpr montgomery_modint() : _v(0) {}\n\
    \n    constexpr montgomery_modint(i64 v)\n        : _v(reduce((v % i64(umod())\
    \ + i64(umod())) * n2)) {}\n\n    constexpr modint &operator+=(const modint &rhs)\
    \ {\n        if (i32(_v += rhs._v - 2 * umod()) < 0) _v += 2 * umod();\n     \
    \   return *this;\n    }\n\n    constexpr modint &operator-=(const modint &rhs)\
    \ {\n        if (i32(_v -= rhs._v) < 0) _v += 2 * umod();\n        return *this;\n\
    \    }\n\n    constexpr modint &operator*=(const modint &rhs) {\n        _v =\
    \ reduce(u64(_v) * rhs._v);\n        return *this;\n    }\n\n    constexpr modint\
    \ &operator/=(const modint &rhs) {\n        *this *= rhs.inv();\n        return\
    \ *this;\n    }\n\n    constexpr modint &operator++() {\n        if (i32(_v +=\
    \ one - 2 * umod()) < 0) _v += 2 * umod();\n        return *this;\n    }\n\n \
    \   constexpr modint &operator--() {\n        if (i32(_v -= one) < 0) _v += 2\
    \ * umod();\n        return *this;\n    }\n\n    constexpr modint operator++(int)\
    \ {\n        modint res = *this;\n        ++*this;\n        return res;\n    }\n\
    \n    constexpr modint operator--(int) {\n        modint res = *this;\n      \
    \  --*this;\n        return res;\n    }\n\n    constexpr modint operator+() const\
    \ {\n        return *this;\n    }\n\n    constexpr modint operator-() const {\n\
    \        return modint() - *this;\n    }\n\n    friend modint operator+(const\
    \ modint &lhs, const modint &rhs) {\n        return modint(lhs) += rhs;\n    }\n\
    \    friend modint operator-(const modint &lhs, const modint &rhs) {\n       \
    \ return modint(lhs) -= rhs;\n    }\n    friend modint operator*(const modint\
    \ &lhs, const modint &rhs) {\n        return modint(lhs) *= rhs;\n    }\n    friend\
    \ modint operator/(const modint &lhs, const modint &rhs) {\n        return modint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const modint &lhs, const modint &rhs)\
    \ {\n        return (lhs._v >= umod() ? lhs._v - umod() : lhs._v) ==\n       \
    \        (rhs._v >= umod() ? rhs._v - umod() : rhs._v);\n    }\n    friend bool\
    \ operator!=(const modint &lhs, const modint &rhs) {\n        return !(lhs ==\
    \ rhs);\n    }\n\n    constexpr modint pow(long long n) const {\n        modint\
    \ x = *this, res = 1;\n        while (n) {\n            if (n & 1) res *= x;\n\
    \            x *= x;\n            n >>= 1;\n        }\n        return res;\n \
    \   }\n\n    constexpr modint inv() const {\n        return pow(umod() - 2);\n\
    \    }\n\n    constexpr u32 val() const {\n        u32 ret = reduce(i64(_v));\n\
    \        return ret >= umod() ? ret - umod() : ret;\n    }\n\n  private:\n   \
    \ u32 _v = 0;\n};\n\ntemplate <int m>\nstd::istream &operator>>(std::istream &os,\
    \ montgomery_modint<m> &a) {\n    long long x;\n    os >> x;\n    a = x;\n   \
    \ return os;\n}\ntemplate <int m>\nstd::ostream &operator<<(std::ostream &os,\
    \ const montgomery_modint<m> &a) {\n    return os << a.val();\n}\n\nusing montgomery_modint998244353\
    \ = montgomery_modint<998244353>;\nusing montgomery_modint1000000007 = montgomery_modint<1'000'000'007>;\n\
    \n}  // namespace ebi\n#line 7 \"test/math/Pow.test.cpp\"\n\r\nusing mint = ebi::montgomery_modint1000000007;\r\
    \n\r\nint main() {\r\n    long long m, n;\r\n    std::cin >> m >> n;\r\n    std::cout\
    \ << mint(m).pow(n) << '\\n';\r\n}\n"
  code: "#define PROBLEM \\\r\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \r\n\r\n#include <iostream>\r\n\r\n#include \"../../modint/montgomery_modint.hpp\"\
    \r\n\r\nusing mint = ebi::montgomery_modint1000000007;\r\n\r\nint main() {\r\n\
    \    long long m, n;\r\n    std::cin >> m >> n;\r\n    std::cout << mint(m).pow(n)\
    \ << '\\n';\r\n}"
  dependsOn:
  - modint/montgomery_modint.hpp
  - modint/base.hpp
  isVerificationFile: true
  path: test/math/Pow.test.cpp
  requiredBy: []
  timestamp: '2023-10-26 11:41:06+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/Pow.test.cpp
layout: document
redirect_from:
- /verify/test/math/Pow.test.cpp
- /verify/test/math/Pow.test.cpp.html
title: test/math/Pow.test.cpp
---
