---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/subset_convolution.hpp
    title: Subset Convolution
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':heavy_check_mark:'
    path: set_function/exp_of_sps.hpp
    title: $\exp {a}$ (Set Power Series)
  - icon: ':heavy_check_mark:'
    path: set_function/ranked_subset_transform.hpp
    title: Ranked Subset Transform (Zeta / Mobius)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/exp_of_set_power_series
    links:
    - https://judge.yosupo.jp/problem/exp_of_set_power_series
  bundledCode: "#line 1 \"test/set_function/Exp_of_Set_Power_Series.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/exp_of_set_power_series\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#line 2 \"modint/modint.hpp\"\n\r\n#include\
    \ <cassert>\r\n#line 5 \"modint/modint.hpp\"\n\r\n#line 2 \"modint/base.hpp\"\n\
    \n#include <concepts>\n#line 5 \"modint/base.hpp\"\n#include <utility>\n\nnamespace\
    \ ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n    a +\
    \ b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
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
    #line 2 \"set_function/exp_of_sps.hpp\"\n\n#line 5 \"set_function/exp_of_sps.hpp\"\
    \n\n#line 2 \"convolution/subset_convolution.hpp\"\n\r\n/*\r\n    refernce: https://www.slideshare.net/wata_orz/ss-12131479\r\
    \n              https://37zigen.com/subset-convolution/\r\n*/\r\n\r\n#include\
    \ <array>\r\n#include <bit>\r\n#line 12 \"convolution/subset_convolution.hpp\"\
    \n\r\n#line 2 \"set_function/ranked_subset_transform.hpp\"\n\n#line 7 \"set_function/ranked_subset_transform.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T, int LIM = 20>\nstd::vector<std::array<T,\
    \ LIM + 1>> ranked_zeta(const std::vector<T> &f) {\n    int n = std::bit_width(f.size())\
    \ - 1;\n    assert(n <= LIM);\n    assert((int)f.size() == (1 << n));\n    std::vector<std::array<T,\
    \ LIM + 1>> rf(1 << n);\n    for (int s = 0; s < (1 << n); s++)\n        rf[s][std::popcount((unsigned\
    \ int)(s))] = f[s];\n    for (int i = 0; i < n; i++) {\n        int w = 1 << i;\n\
    \        for (int p = 0; p < (1 << n); p += 2 * w) {\n            for (int s =\
    \ p; s < p + w; s++) {\n                int t = s | (1 << i);\n              \
    \  for (int d = 0; d <= n; d++) rf[t][d] += rf[s][d];\n            }\n       \
    \ }\n    }\n    return rf;\n}\n\ntemplate <class T, int LIM = 20>\nstd::vector<T>\
    \ ranked_mobius(std::vector<std::array<T, LIM + 1>> rf) {\n    int n = std::bit_width(rf.size())\
    \ - 1;\n    assert((int)rf.size() == (1 << n));\n    for (int i = 0; i < n; i++)\
    \ {\n        int w = 1 << i;\n        for (int p = 0; p < (1 << n); p += 2 * w)\
    \ {\n            for (int s = p; s < p + w; s++) {\n                int t = s\
    \ | (1 << i);\n                for (int d = 0; d <= n; d++) rf[t][d] -= rf[s][d];\n\
    \            }\n        }\n    }\n    std::vector<T> f(1 << n);\n    for (int\
    \ s = 0; s < (1 << n); s++) {\n        f[s] = rf[s][std::popcount((unsigned int)(s))];\n\
    \    }\n    return f;\n}\n\n}  // namespace ebi\n#line 14 \"convolution/subset_convolution.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <class T, int LIM = 20>\r\nstd::vector<T>\
    \ subset_convolution(const std::vector<T> &a,\r\n                            \
    \      const std::vector<T> &b) {\r\n    auto ra = ranked_zeta<T, LIM>(a);\r\n\
    \    auto rb = ranked_zeta<T, LIM>(b);\r\n    int n = std::bit_width(a.size())\
    \ - 1;\r\n    for (int s = (1 << n) - 1; s >= 0; s--) {\r\n        auto &f = ra[s];\r\
    \n        const auto &g = rb[s];\r\n        for (int d = n; d >= 0; d--) {\r\n\
    \            T x = 0;\r\n            for (int i = 0; i <= d; i++) {\r\n      \
    \          x += f[i] * g[d - i];\r\n            }\r\n            f[d] = x;\r\n\
    \        }\r\n    }\r\n    return ranked_mobius<T, LIM>(ra);\r\n}\r\n\r\n}  //\
    \ namespace ebi\n#line 7 \"set_function/exp_of_sps.hpp\"\n\nnamespace ebi {\n\n\
    template <class T, int LIM> std::vector<T> exp_of_sps(const std::vector<T> &a)\
    \ {\n    int n = std::bit_width(a.size()) - 1;\n    assert(n <= LIM);\n    assert((int)a.size()\
    \ == (1 << n));\n    std::vector<T> fa(1 << n);\n    fa[0] = T(1);\n    for (int\
    \ i = 0; i < n; i++) {\n        std::vector<T> s = {a.begin() + (1 << i), a.begin()\
    \ + (2 << i)};\n        std::vector<T> t = {fa.begin(), fa.begin() + (1 << i)};\n\
    \        auto c = subset_convolution<T, LIM>(s, t);\n        std::copy(c.begin(),\
    \ c.end(), fa.begin() + (1 << i));\n    }\n    return fa;\n}\n\n}  // namespace\
    \ ebi\n#line 8 \"test/set_function/Exp_of_Set_Power_Series.test.cpp\"\n\nusing\
    \ mint = ebi::modint998244353;\n\nint main() {\n    int n;\n    std::cin >> n;\n\
    \    std::vector<mint> b(1 << n);\n    for (int i = 0; i < (1 << n); i++) {\n\
    \        int x;\n        std::cin >> x;\n        b[i] = x;\n    }\n    auto c\
    \ = ebi::exp_of_sps<mint, 20>(b);\n    for (int i = 0; i < (1 << n); i++) {\n\
    \        std::cout << c[i].val() << \" \\n\"[i == (1 << n) - 1];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_set_power_series\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../modint/modint.hpp\"\
    \n#include \"../../set_function/exp_of_sps.hpp\"\n\nusing mint = ebi::modint998244353;\n\
    \nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<mint> b(1 << n);\n\
    \    for (int i = 0; i < (1 << n); i++) {\n        int x;\n        std::cin >>\
    \ x;\n        b[i] = x;\n    }\n    auto c = ebi::exp_of_sps<mint, 20>(b);\n \
    \   for (int i = 0; i < (1 << n); i++) {\n        std::cout << c[i].val() << \"\
    \ \\n\"[i == (1 << n) - 1];\n    }\n}"
  dependsOn:
  - modint/modint.hpp
  - modint/base.hpp
  - set_function/exp_of_sps.hpp
  - convolution/subset_convolution.hpp
  - set_function/ranked_subset_transform.hpp
  isVerificationFile: true
  path: test/set_function/Exp_of_Set_Power_Series.test.cpp
  requiredBy: []
  timestamp: '2023-10-31 00:17:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/set_function/Exp_of_Set_Power_Series.test.cpp
layout: document
redirect_from:
- /verify/test/set_function/Exp_of_Set_Power_Series.test.cpp
- /verify/test/set_function/Exp_of_Set_Power_Series.test.cpp.html
title: test/set_function/Exp_of_Set_Power_Series.test.cpp
---
