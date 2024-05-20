---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convolution/arbitrary_ntt.hpp
    title: Arbitrary Convolution
  - icon: ':x:'
    path: convolution/convolution.hpp
    title: Convolution
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#line 1 \"test/convolution/Convolution_Mod_1000000007.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"convolution/arbitrary_ntt.hpp\"\
    \n\n#include <cstdint>\n#line 5 \"convolution/arbitrary_ntt.hpp\"\n\n#line 2 \"\
    convolution/convolution.hpp\"\n\n#include <algorithm>\n#include <bit>\n#line 6\
    \ \"convolution/convolution.hpp\"\n\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n\
    #line 5 \"modint/base.hpp\"\n#include <utility>\n\nnamespace ebi {\n\ntemplate\
    \ <class T>\nconcept Modint = requires(T a, T b) {\n    a + b;\n    a - b;\n \
    \   a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 9 \"\
    convolution/convolution.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint>\nstd::vector<mint>\
    \ convolution_naive(const std::vector<mint>& f,\n                            \
    \        const std::vector<mint>& g) {\n    if (f.empty() || g.empty()) return\
    \ {};\n    int n = int(f.size()), m = int(g.size());\n    std::vector<mint> c(n\
    \ + m - 1);\n    if (n < m) {\n        for (int j = 0; j < m; j++) {\n       \
    \     for (int i = 0; i < n; i++) {\n                c[i + j] += f[i] * g[j];\n\
    \            }\n        }\n    } else {\n        for (int i = 0; i < n; i++) {\n\
    \            for (int j = 0; j < m; j++) {\n                c[i + j] += f[i] *\
    \ g[j];\n            }\n        }\n    }\n    return c;\n}\n\ntemplate <Modint\
    \ mint>\nstd::vector<mint> convolution(const std::vector<mint>& f,\n         \
    \                     const std::vector<mint>& g) {\n    if (f.empty() || g.empty())\
    \ return {};\n    if (std::min(f.size(), g.size()) < 60) return convolution_naive(f,\
    \ g);\n    int n = std::bit_ceil(f.size() + g.size() - 1);\n    std::vector<mint>\
    \ a(n), b(n);\n    std::copy(f.begin(), f.end(), a.begin());\n    std::copy(g.begin(),\
    \ g.end(), b.begin());\n    internal::butterfly(a);\n    internal::butterfly(b);\n\
    \    for (int i = 0; i < n; i++) {\n        a[i] *= b[i];\n    }\n    internal::butterfly_inv(a);\n\
    \    a.resize(f.size() + g.size() - 1);\n    return a;\n}\n\n}  // namespace ebi\n\
    #line 2 \"modint/modint.hpp\"\n\r\n#include <cassert>\r\n#line 5 \"modint/modint.hpp\"\
    \n\r\n#line 7 \"modint/modint.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate <int\
    \ m> struct static_modint {\r\n  private:\r\n    using modint = static_modint;\r\
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
    \n        _v--;\r\n        return *this;\r\n    }\r\n\r\n    constexpr modint\
    \ operator++(int) {\r\n        modint res = *this;\r\n        ++*this;\r\n   \
    \     return res;\r\n    }\r\n    constexpr modint operator--(int) {\r\n     \
    \   modint res = *this;\r\n        --*this;\r\n        return res;\r\n    }\r\n\
    \r\n    constexpr modint &operator+=(const modint &rhs) {\r\n        _v += rhs._v;\r\
    \n        if (_v >= umod()) _v -= umod();\r\n        return *this;\r\n    }\r\n\
    \    constexpr modint &operator-=(const modint &rhs) {\r\n        _v -= rhs._v;\r\
    \n        if (_v >= umod()) _v += umod();\r\n        return *this;\r\n    }\r\n\
    \    constexpr modint &operator*=(const modint &rhs) {\r\n        unsigned long\
    \ long x = _v;\r\n        x *= rhs._v;\r\n        _v = (unsigned int)(x % (unsigned\
    \ long long)umod());\r\n        return *this;\r\n    }\r\n    constexpr modint\
    \ &operator/=(const modint &rhs) {\r\n        return *this = *this * rhs.inv();\r\
    \n    }\r\n\r\n    constexpr modint operator+() const {\r\n        return *this;\r\
    \n    }\r\n    constexpr modint operator-() const {\r\n        return modint()\
    \ - *this;\r\n    }\r\n\r\n    constexpr modint pow(long long n) const {\r\n \
    \       assert(0 <= n);\r\n        modint x = *this, res = 1;\r\n        while\
    \ (n) {\r\n            if (n & 1) res *= x;\r\n            x *= x;\r\n       \
    \     n >>= 1;\r\n        }\r\n        return res;\r\n    }\r\n    constexpr modint\
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
    \n\r\n  private:\r\n    unsigned int _v = 0;\r\n\r\n    static constexpr unsigned\
    \ int umod() {\r\n        return m;\r\n    }\r\n};\r\n\r\nusing modint998244353\
    \ = static_modint<998244353>;\r\nusing modint1000000007 = static_modint<1000000007>;\r\
    \n\r\n}  // namespace ebi\n#line 9 \"convolution/arbitrary_ntt.hpp\"\n\nnamespace\
    \ ebi {\n\nnamespace internal {\n\ntemplate <class T, Modint mint>\nstd::vector<mint>\
    \ multiply(const std::vector<T>& f, const std::vector<T>& g) {\n    std::vector<mint>\
    \ a, b;\n    a.reserve(f.size());\n    b.reserve(g.size());\n    for (auto x :\
    \ f) a.emplace_back(x.val());\n    for (auto x : g) b.emplace_back(x.val());\n\
    \    return convolution<mint>(a, b);\n}\n\n}  // namespace internal\n\ntemplate\
    \ <Modint mint>\nstd::vector<mint> arbitary_convolution(const std::vector<mint>&\
    \ f,\n                                       const std::vector<mint>& g) {\n \
    \   if (f.empty() || g.empty()) return {};\n    using i32 = std::int32_t;\n  \
    \  using i64 = std::int64_t;\n    static constexpr i32 m0 = 167772161;  // 2^25\n\
    \    static constexpr i32 m1 = 469762049;  // 2^26\n    static constexpr i32 m2\
    \ = 754974721;  // 2^24\n    using mint0 = static_modint<m0>;\n    using mint1\
    \ = static_modint<m1>;\n    using mint2 = static_modint<m2>;\n    static constexpr\
    \ i32 inv01 = mint1(m0).inv().val();\n    static constexpr i32 inv02 = mint2(m0).inv().val();\n\
    \    static constexpr i32 inv12 = mint2(m1).inv().val();\n    static constexpr\
    \ i32 inv02inv12 = i64(inv02) * inv12 % m2;\n    static constexpr i64 w1 = m0;\n\
    \    static constexpr i64 w2 = i64(m0) * m1;\n\n    const i32 mod = mint::mod();\n\
    \n    auto d0 = internal::multiply<mint, mint0>(f, g);\n    auto d1 = internal::multiply<mint,\
    \ mint1>(f, g);\n    auto d2 = internal::multiply<mint, mint2>(f, g);\n\n    int\
    \ n = d0.size();\n    std::vector<mint> res(n);\n    const int W1 = w1 % mod;\n\
    \    const int W2 = w2 % mod;\n\n    for (int i = 0; i < n; i++) {\n        i32\
    \ n1 = d1[i].val(), n2 = d2[i].val(), a = d0[i].val();\n        i32 b = i64(n1\
    \ + m1 - a) * inv01 % m1;\n        i32 c = (i64(n2 + m2 - a) * inv02inv12 + i64(m2\
    \ - b) * inv12) % m2;\n        res[i] = (i64(a) + i64(b) * W1 + i64(c) * W2) %\
    \ mod;\n    }\n    return res;\n}\n\n}  // namespace ebi\n#line 8 \"test/convolution/Convolution_Mod_1000000007.test.cpp\"\
    \n\nusing mint = ebi::modint1000000007;\n\nint main() {\n    int n, m;\n    std::cin\
    \ >> n >> m;\n    std::vector<mint> a(n), b(m);\n    for (int i = 0; i < n; i++)\
    \ std::cin >> a[i];\n    for (int i = 0; i < m; i++) std::cin >> b[i];\n    auto\
    \ c = ebi::arbitary_convolution<mint>(a, b);\n    for (int i = 0; i < n + m -\
    \ 1; i++) {\n        std::cout << c[i].val() << \" \\n\"[i == n + m - 2];\n  \
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../convolution/arbitrary_ntt.hpp\"\
    \n#include \"../../modint/modint.hpp\"\n\nusing mint = ebi::modint1000000007;\n\
    \nint main() {\n    int n, m;\n    std::cin >> n >> m;\n    std::vector<mint>\
    \ a(n), b(m);\n    for (int i = 0; i < n; i++) std::cin >> a[i];\n    for (int\
    \ i = 0; i < m; i++) std::cin >> b[i];\n    auto c = ebi::arbitary_convolution<mint>(a,\
    \ b);\n    for (int i = 0; i < n + m - 1; i++) {\n        std::cout << c[i].val()\
    \ << \" \\n\"[i == n + m - 2];\n    }\n}"
  dependsOn:
  - convolution/arbitrary_ntt.hpp
  - convolution/convolution.hpp
  - modint/base.hpp
  - modint/modint.hpp
  isVerificationFile: true
  path: test/convolution/Convolution_Mod_1000000007.test.cpp
  requiredBy: []
  timestamp: '2024-05-20 22:28:31+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/convolution/Convolution_Mod_1000000007.test.cpp
layout: document
redirect_from:
- /verify/test/convolution/Convolution_Mod_1000000007.test.cpp
- /verify/test/convolution/Convolution_Mod_1000000007.test.cpp.html
title: test/convolution/Convolution_Mod_1000000007.test.cpp
---
