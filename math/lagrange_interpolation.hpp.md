---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \n#line 2 \"utility/modint.hpp\"\n\r\n/*\r\n    author: noshi91\r\n    reference:\
    \ https://noshi91.hatenablog.com/entry/2019/03/31/174006\r\n    noshi91\u306E\u30D6\
    \u30ED\u30B0\u3067\u516C\u958B\u3055\u308C\u3066\u3044\u308Bmodint\u3092\u5143\
    \u306Binv(), pow()\u3092\u8FFD\u52A0\u3057\u305F\u3082\u306E\u3067\u3059\r\n*/\r\
    \n\r\n#include <cstdint>\r\n#include <iostream>\r\n\r\nnamespace ebi {\r\n\r\n\
    template<std::uint_fast64_t Modulus>\r\nclass modint {\r\n  using u64 = std::uint_fast64_t;\r\
    \n\r\npublic:\r\n    u64 a;\r\n\r\n    constexpr modint(const u64 x = 0) noexcept\
    \ : a(x % Modulus) {}\r\n    constexpr u64 &value() noexcept { return a; }\r\n\
    \    constexpr u64 &val() noexcept { return a; }\r\n    constexpr const u64 &value()\
    \ const noexcept { return a; }\r\n    constexpr modint operator+(const modint\
    \ rhs) const noexcept {\r\n        return modint(*this) += rhs;\r\n    }\r\n \
    \   constexpr modint operator-(const modint rhs) const noexcept {\r\n        return\
    \ modint(*this) -= rhs;\r\n    }\r\n    constexpr modint operator*(const modint\
    \ rhs) const noexcept {\r\n        return modint(*this) *= rhs;\r\n    }\r\n \
    \   constexpr modint operator/(const modint rhs) const noexcept {\r\n        return\
    \ modint(*this) /= rhs;\r\n    }\r\n    constexpr modint &operator+=(const modint\
    \ rhs) noexcept {\r\n        a += rhs.a;\r\n        if (a >= Modulus) {\r\n  \
    \          a -= Modulus;\r\n        }\r\n        return *this;\r\n    }\r\n  \
    \  constexpr modint &operator-=(const modint rhs) noexcept {\r\n        if (a\
    \ < rhs.a) {\r\n        a += Modulus;\r\n        }\r\n        a -= rhs.a;\r\n\
    \        return *this;\r\n    }\r\n    constexpr modint &operator*=(const modint\
    \ rhs) noexcept {\r\n        a = a * rhs.a % Modulus;\r\n        return *this;\r\
    \n    }\r\n    constexpr modint &operator/=(modint rhs) noexcept {\r\n       \
    \ u64 exp = Modulus - 2;\r\n        while (exp) {\r\n        if (exp % 2) {\r\n\
    \            *this *= rhs;\r\n        }\r\n        rhs *= rhs;\r\n        exp\
    \ /= 2;\r\n        }\r\n        return *this;\r\n    }\r\n    constexpr modint\
    \ operator-() const { return modint() - *this; }\r\n    bool operator==(const\
    \ u64 rhs) {\r\n        return a == rhs;\r\n    }\r\n    bool operator!=(const\
    \ u64 rhs) {\r\n        return a != rhs;\r\n    }\r\n    constexpr modint& operator++()\
    \ {\r\n        a++;\r\n        if( a == mod() ) a = 0;\r\n        return *this;\r\
    \n    }\r\n    constexpr modint& operator--() {\r\n        if( a == 0 ) a = mod();\r\
    \n        a--;\r\n        return *this;\r\n    }\r\n\r\n    modint pow(u64 n)\
    \ const noexcept {\r\n        modint res = 1;\r\n        modint x = a;\r\n   \
    \     while(n>0){\r\n            if(n&1) res *= x;\r\n            x *= x;\r\n\
    \            n >>=1;\r\n        }\r\n        return res;\r\n    }\r\n    modint\
    \ inv() const {\r\n        return pow(Modulus-2);\r\n    }\r\n\r\n    static u64\
    \ mod() {\r\n        return Modulus;\r\n    }\r\n};\r\n\r\nusing modint998244353\
    \ = modint<998244353>;\r\nusing modint1000000007 = modint<1000000007>;\r\n\r\n\
    template<std::uint_fast64_t Modulus>\r\nstd::ostream& operator<<(std::ostream&\
    \ os, modint<Modulus> a){\r\n    return os << a.val();\r\n}\r\n\r\n} // namespace\
    \ ebi\n#line 6 \"math/lagrange_interpolation.hpp\"\n\n/*\n    reference: https://atcoder.jp/contests/abc208/editorial/2195\n\
    \    verify: https://atcoder.jp/contests/abc208/tasks/abc208_f\n*/\n\nnamespace\
    \ ebi {\n\nusing mint = modint1000000007;\nusing i64 = long long;\n\nmint lagrange_interpolation(const\
    \ std::vector<mint> &f, i64 n) {\n    const int d = int(f.size()) - 1; // N\u306E\
    d\u6B21\u4EE5\u4E0B\u306E\u591A\u9805\u5F0F\n    mint fact = 1;\n    std::vector<mint>\
    \ inv_fact(d+1);\n    for(int i = 1; i < d+1; ++i) {\n        fact *= i;\n   \
    \ }\n    inv_fact[d] = fact.inv();\n    for(int i = d; i > 0; i--) {\n       \
    \ inv_fact[i-1] = inv_fact[i] * i;\n    }\n    std::vector<mint> l(d+1), r(d+1);\n\
    \    l[0] = 1;\n    for(int i = 0; i < d; ++i) {\n        l[i+1] = l[i] * (n-i);\n\
    \    }\n    r[d] = 1;\n    for(int i = d; i > 0; --i) {\n        r[i-1] = r[i]\
    \ * (n-i);\n    }\n    mint res = 0;\n    for(int i = 0; i < d+1; ++i) {\n   \
    \     res += mint((d-i)%2 == 1 ? -1: 1) * f[i] * l[i] * r[i] * inv_fact[i] * inv_fact[d-i];\n\
    \    }\n    return res;\n}\n\n}\n"
  code: "#pragma once\n\n#include <vector>\n\n#include \"../utility/modint.hpp\"\n\
    \n/*\n    reference: https://atcoder.jp/contests/abc208/editorial/2195\n    verify:\
    \ https://atcoder.jp/contests/abc208/tasks/abc208_f\n*/\n\nnamespace ebi {\n\n\
    using mint = modint1000000007;\nusing i64 = long long;\n\nmint lagrange_interpolation(const\
    \ std::vector<mint> &f, i64 n) {\n    const int d = int(f.size()) - 1; // N\u306E\
    d\u6B21\u4EE5\u4E0B\u306E\u591A\u9805\u5F0F\n    mint fact = 1;\n    std::vector<mint>\
    \ inv_fact(d+1);\n    for(int i = 1; i < d+1; ++i) {\n        fact *= i;\n   \
    \ }\n    inv_fact[d] = fact.inv();\n    for(int i = d; i > 0; i--) {\n       \
    \ inv_fact[i-1] = inv_fact[i] * i;\n    }\n    std::vector<mint> l(d+1), r(d+1);\n\
    \    l[0] = 1;\n    for(int i = 0; i < d; ++i) {\n        l[i+1] = l[i] * (n-i);\n\
    \    }\n    r[d] = 1;\n    for(int i = d; i > 0; --i) {\n        r[i-1] = r[i]\
    \ * (n-i);\n    }\n    mint res = 0;\n    for(int i = 0; i < d+1; ++i) {\n   \
    \     res += mint((d-i)%2 == 1 ? -1: 1) * f[i] * l[i] * r[i] * inv_fact[i] * inv_fact[d-i];\n\
    \    }\n    return res;\n}\n\n}"
  dependsOn:
  - utility/modint.hpp
  isVerificationFile: false
  path: math/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2023-05-08 14:32:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/lagrange_interpolation.hpp
layout: document
redirect_from:
- /library/math/lagrange_interpolation.hpp
- /library/math/lagrange_interpolation.hpp.html
title: math/lagrange_interpolation.hpp
---
