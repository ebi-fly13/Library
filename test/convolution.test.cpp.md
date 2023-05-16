---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/convolution.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\
    \r\n\r\n#line 2 \"convolution/convolution.hpp\"\n\r\n/*\r\n    reference: https://hcpc-hokudai.github.io/archive/math_fft_002.pdf\r\
    \n    mod 998244353 \u4E0A\u3067\u306E\u7573\u307F\u8FBC\u307F\u3092 O(N log N)\
    \ \u3067\u6C42\u3081\u308B.\r\n*/\r\n\r\n#line 2 \"utility/modint.hpp\"\n\r\n\
    #include <cassert>\r\n#include <iostream>\r\n\r\nnamespace ebi {\r\n\r\ntemplate\
    \ <int m> struct modint {\r\n  public:\r\n    static constexpr int mod() {\r\n\
    \        return m;\r\n    }\r\n\r\n    static modint raw(int v) {\r\n        modint\
    \ x;\r\n        x._v = v;\r\n        return x;\r\n    }\r\n\r\n    modint() :\
    \ _v(0) {}\r\n\r\n    modint(long long v) {\r\n        v %= (long long)umod();\r\
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
    \ &operator>>(std::istream &os, modint<m> &a) {\r\n    long long x;\r\n    os\
    \ >> x;\r\n    a = x;\r\n    return os;\r\n}\r\ntemplate <int m>\r\nstd::ostream\
    \ &operator<<(std::ostream &os, const modint<m> &a) {\r\n    return os << a.val();\r\
    \n}\r\n\r\nusing modint998244353 = modint<998244353>;\r\nusing modint1000000007\
    \ = modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 9 \"convolution/convolution.hpp\"\
    \n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\nusing mint = ebi::modint998244353;\r\
    \n\r\nnamespace internal {\r\n\r\nconst mint primitive_root = 3;\r\n\r\nvoid dft(std::vector<mint>\
    \ &f) {\r\n    int n = f.size();\r\n    if (n == 1) return;\r\n    std::vector<mint>\
    \ a(n / 2), b(n / 2);\r\n    for (int i = 0; i < n / 2; ++i) {\r\n        a[i]\
    \ = f[2 * i];\r\n        b[i] = f[2 * i + 1];\r\n    }\r\n    dft(a);\r\n    dft(b);\r\
    \n    const mint zeta = primitive_root.pow((mint::mod() - 1) / n);\r\n    mint\
    \ x = 1;\r\n    for (int i = 0; i < n; ++i) {\r\n        f[i] = a[i % (n / 2)]\
    \ + x * b[i % (n / 2)];\r\n        x *= zeta;\r\n    }\r\n}\r\n\r\nvoid inv_dft(std::vector<mint>\
    \ &f) {\r\n    int n = f.size();\r\n    if (n == 1) return;\r\n    std::vector<mint>\
    \ a(n / 2), b(n / 2);\r\n    for (int i = 0; i < n / 2; ++i) {\r\n        a[i]\
    \ = f[2 * i];\r\n        b[i] = f[2 * i + 1];\r\n    }\r\n    inv_dft(a);\r\n\
    \    inv_dft(b);\r\n    const mint inv_zeta = primitive_root.pow((mint::mod()\
    \ - 1) / n).inv();\r\n    mint x = 1;\r\n    for (int i = 0; i < n; ++i) {\r\n\
    \        f[i] = a[i % (n / 2)] + x * b[i % (n / 2)];\r\n        x *= inv_zeta;\r\
    \n    }\r\n}\r\n\r\n}  // namespace internal\r\n\r\nstd::vector<mint> convolution(const\
    \ std::vector<mint> &f,\r\n                              const std::vector<mint>\
    \ &g) {\r\n    int n = 1;\r\n    while (n < (int)f.size() + (int)g.size() - 1)\
    \ n <<= 1;\r\n    std::vector<mint> a(n, 0), b(n, 0), fg(n, 0);\r\n    std::copy(f.begin(),\
    \ f.end(), a.begin());\r\n    std::copy(g.begin(), g.end(), b.begin());\r\n  \
    \  internal::dft(a);\r\n    internal::dft(b);\r\n    for (int i = 0; i < n; ++i)\
    \ {\r\n        fg[i] = a[i] * b[i];\r\n    }\r\n    internal::inv_dft(fg);\r\n\
    \    mint in = mint(n).inv();\r\n    for (int i = 0; i < n; ++i) {\r\n       \
    \ fg[i] *= in;\r\n    }\r\n    return fg;\r\n}\r\n\r\n}  // namespace ebi\n#line\
    \ 4 \"test/convolution.test.cpp\"\n\r\n#line 6 \"test/convolution.test.cpp\"\n\
    \r\n#line 8 \"test/convolution.test.cpp\"\n\r\nusing mint = ebi::modint998244353;\r\
    \n\r\nint main() {\r\n    int n, m;\r\n    std::cin >> n >> m;\r\n    std::vector<mint>\
    \ a(n), b(m);\r\n    for (int i = 0; i < n; ++i) {\r\n        std::cin >> a[i];\r\
    \n    }\r\n    for (int i = 0; i < m; ++i) {\r\n        std::cin >> b[i];\r\n\
    \    }\r\n    auto c = ebi::convolution(a, b);\r\n    for (int i = 0; i < n +\
    \ m - 1; ++i) {\r\n        std::cout << c[i].val() << \" \";\r\n    }\r\n    std::cout\
    \ << '\\n';\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\r\n\r\
    \n#include \"../convolution/convolution.hpp\"\r\n\r\n#include <iostream>\r\n\r\
    \n#include \"../utility/modint.hpp\"\r\n\r\nusing mint = ebi::modint998244353;\r\
    \n\r\nint main() {\r\n    int n, m;\r\n    std::cin >> n >> m;\r\n    std::vector<mint>\
    \ a(n), b(m);\r\n    for (int i = 0; i < n; ++i) {\r\n        std::cin >> a[i];\r\
    \n    }\r\n    for (int i = 0; i < m; ++i) {\r\n        std::cin >> b[i];\r\n\
    \    }\r\n    auto c = ebi::convolution(a, b);\r\n    for (int i = 0; i < n +\
    \ m - 1; ++i) {\r\n        std::cout << c[i].val() << \" \";\r\n    }\r\n    std::cout\
    \ << '\\n';\r\n}"
  dependsOn:
  - convolution/convolution.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/convolution.test.cpp
  requiredBy: []
  timestamp: '2023-05-16 13:40:06+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/convolution.test.cpp
layout: document
redirect_from:
- /verify/test/convolution.test.cpp
- /verify/test/convolution.test.cpp.html
title: test/convolution.test.cpp
---
