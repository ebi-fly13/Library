---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/subset_convolution.hpp
    title: convolution/subset_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: set_function/ranked_zeta.hpp
    title: set_function/ranked_zeta.hpp
  - icon: ':heavy_check_mark:'
    path: utility/bit_operator.hpp
    title: utility/bit_operator.hpp
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/subset_convolution
    links:
    - https://judge.yosupo.jp/problem/subset_convolution
  bundledCode: "#line 1 \"test/subset_convolution.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\
    \r\n\r\n#line 2 \"convolution/subset_convolution.hpp\"\n\r\n/*\r\n    refernce:\
    \ https://www.slideshare.net/wata_orz/ss-12131479\r\n              https://37zigen.com/subset-convolution/\r\
    \n*/\r\n\r\n#include <array>\r\n#include <cassert>\r\n#include <vector>\r\n\r\n\
    #line 2 \"set_function/ranked_zeta.hpp\"\n\n#line 6 \"set_function/ranked_zeta.hpp\"\
    \n\n#line 2 \"utility/bit_operator.hpp\"\n\nnamespace ebi {\n\nint popcnt(int\
    \ x) {\n    return __builtin_popcount(x);\n}\n\nint topbit(int x) {\n    return\
    \ (x == 0) ? -1 : 31 - __builtin_clz(x);\n}\n\nint lowbit(int x) {\n    return\
    \ (x == 0) ? -1 : __builtin_ctz(x);\n}\n\n}  // namespace ebi\n#line 8 \"set_function/ranked_zeta.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T, int LIM = 20>\nstd::vector<std::array<T,\
    \ LIM + 1>> ranked_zeta(const std::vector<T> &f) {\n    int n = topbit(f.size());\n\
    \    assert(n <= LIM);\n    assert((int)f.size() == (1 << n));\n    std::vector<std::array<T,\
    \ LIM + 1>> rf(1 << n);\n    for (int s = 0; s < (1 << n); s++) rf[s][popcnt(s)]\
    \ = f[s];\n    for (int i = 0; i < n; i++) {\n        int w = 1 << i;\n      \
    \  for (int p = 0; p < (1 << n); p += 2 * w) {\n            for (int s = p; s\
    \ < p + w; s++) {\n                int t = s | (1 << i);\n                for\
    \ (int d = 0; d <= n; d++) rf[t][d] += rf[s][d];\n            }\n        }\n \
    \   }\n    return rf;\n}\n\ntemplate <class T, int LIM = 20>\nstd::vector<T> ranked_mobius(std::vector<std::array<T,\
    \ LIM + 1>> rf) {\n    int n = topbit(rf.size());\n    assert((int)rf.size() ==\
    \ (1 << n));\n    for (int i = 0; i < n; i++) {\n        int w = 1 << i;\n   \
    \     for (int p = 0; p < (1 << n); p += 2 * w) {\n            for (int s = p;\
    \ s < p + w; s++) {\n                int t = s | (1 << i);\n                for\
    \ (int d = 0; d <= n; d++) rf[t][d] -= rf[s][d];\n            }\n        }\n \
    \   }\n    std::vector<T> f(1 << n);\n    for (int s = 0; s < (1 << n); s++) {\n\
    \        f[s] = rf[s][popcnt(s)];\n    }\n    return f;\n}\n\n}  // namespace\
    \ ebi\n#line 14 \"convolution/subset_convolution.hpp\"\n\r\nnamespace ebi {\r\n\
    \r\ntemplate <class T, int LIM = 20>\r\nstd::vector<T> subset_convolution(const\
    \ std::vector<T> &a,\r\n                                  const std::vector<T>\
    \ &b) {\r\n    auto ra = ranked_zeta<T, LIM>(a);\r\n    auto rb = ranked_zeta<T,\
    \ LIM>(b);\r\n    int n = topbit(ra.size());\r\n    for (int s = (1 << n) - 1;\
    \ s >= 0; s--) {\r\n        auto &f = ra[s];\r\n        const auto &g = rb[s];\r\
    \n        for (int d = n; d >= 0; d--) {\r\n            T x = 0;\r\n         \
    \   for (int i = 0; i <= d; i++) {\r\n                x += f[i] * g[d - i];\r\n\
    \            }\r\n            f[d] = x;\r\n        }\r\n    }\r\n    return ranked_mobius<T,\
    \ LIM>(ra);\r\n}\r\n\r\n}  // namespace ebi\n#line 4 \"test/subset_convolution.test.cpp\"\
    \n\r\n#include <iostream>\r\n#line 7 \"test/subset_convolution.test.cpp\"\n\r\n\
    #line 2 \"utility/modint.hpp\"\n\r\n#line 5 \"utility/modint.hpp\"\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <int m> struct modint {\r\n  public:\r\n    static constexpr\
    \ int mod() {\r\n        return m;\r\n    }\r\n\r\n    static modint raw(int v)\
    \ {\r\n        modint x;\r\n        x._v = v;\r\n        return x;\r\n    }\r\n\
    \r\n    modint() : _v(0) {}\r\n\r\n    modint(long long v) {\r\n        v %= (long\
    \ long)umod();\r\n        if (v < 0) v += (long long)umod();\r\n        _v = (unsigned\
    \ int)v;\r\n    }\r\n\r\n    unsigned int val() const {\r\n        return _v;\r\
    \n    }\r\n\r\n    unsigned int value() const {\r\n        return val();\r\n \
    \   }\r\n\r\n    modint &operator++() {\r\n        _v++;\r\n        if (_v ==\
    \ umod()) _v = 0;\r\n        return *this;\r\n    }\r\n    modint &operator--()\
    \ {\r\n        if (_v == 0) _v = umod();\r\n        _v--;\r\n        return *this;\r\
    \n    }\r\n    modint &operator+=(const modint &rhs) {\r\n        _v += rhs._v;\r\
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
    \ &operator>>(std::istream &os, modint<m> &a) {\r\n    long long x;\r\n    os\
    \ >> x;\r\n    a = x;\r\n    return os;\r\n}\r\ntemplate <int m>\r\nstd::ostream\
    \ &operator<<(std::ostream &os, const modint<m> &a) {\r\n    return os << a.val();\r\
    \n}\r\n\r\nusing modint998244353 = modint<998244353>;\r\nusing modint1000000007\
    \ = modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 9 \"test/subset_convolution.test.cpp\"\
    \n\r\nusing mint = ebi::modint998244353;\r\n\r\nint main() {\r\n    int n;\r\n\
    \    std::cin >> n;\r\n    std::vector<mint> a(1 << n), b(1 << n);\r\n    for\
    \ (int i = 0; i < (1 << n); i++) {\r\n        std::cin >> a[i];\r\n    }\r\n \
    \   for (int i = 0; i < (1 << n); i++) {\r\n        std::cin >> b[i];\r\n    }\r\
    \n    auto c = ebi::subset_convolution<mint, 20>(a, b);\r\n    for (int i = 0;\
    \ i < (1 << n); i++) {\r\n        std::cout << c[i] << ((i == (1 << n) - 1) ?\
    \ \"\\n\" : \" \");\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\r\n\
    \r\n#include \"../convolution/subset_convolution.hpp\"\r\n\r\n#include <iostream>\r\
    \n#include <vector>\r\n\r\n#include \"../utility/modint.hpp\"\r\n\r\nusing mint\
    \ = ebi::modint998244353;\r\n\r\nint main() {\r\n    int n;\r\n    std::cin >>\
    \ n;\r\n    std::vector<mint> a(1 << n), b(1 << n);\r\n    for (int i = 0; i <\
    \ (1 << n); i++) {\r\n        std::cin >> a[i];\r\n    }\r\n    for (int i = 0;\
    \ i < (1 << n); i++) {\r\n        std::cin >> b[i];\r\n    }\r\n    auto c = ebi::subset_convolution<mint,\
    \ 20>(a, b);\r\n    for (int i = 0; i < (1 << n); i++) {\r\n        std::cout\
    \ << c[i] << ((i == (1 << n) - 1) ? \"\\n\" : \" \");\r\n    }\r\n}"
  dependsOn:
  - convolution/subset_convolution.hpp
  - set_function/ranked_zeta.hpp
  - utility/bit_operator.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/subset_convolution.test.cpp
  requiredBy: []
  timestamp: '2023-05-16 13:56:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/subset_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/subset_convolution.test.cpp
- /verify/test/subset_convolution.test.cpp.html
title: test/subset_convolution.test.cpp
---
