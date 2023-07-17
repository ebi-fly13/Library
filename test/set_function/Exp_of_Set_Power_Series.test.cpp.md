---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/subset_convolution.hpp
    title: Subset Convolution
  - icon: ':x:'
    path: set_function/exp_of_sps.hpp
    title: $\exp {a}$ (Set Power Series)
  - icon: ':question:'
    path: set_function/ranked_subset_transform.hpp
    title: Ranked Subset Transform (Zeta / Mobius)
  - icon: ':question:'
    path: utility/bit_operator.hpp
    title: utility/bit_operator.hpp
  - icon: ':question:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  - icon: ':question:'
    path: utility/modint_base.hpp
    title: utility/modint_base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/exp_of_set_power_series
    links:
    - https://judge.yosupo.jp/problem/exp_of_set_power_series
  bundledCode: "#line 1 \"test/set_function/Exp_of_Set_Power_Series.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/exp_of_set_power_series\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#line 2 \"set_function/exp_of_sps.hpp\"\n\n\
    #include <cassert>\n#line 5 \"set_function/exp_of_sps.hpp\"\n\n#line 2 \"convolution/subset_convolution.hpp\"\
    \n\r\n/*\r\n    refernce: https://www.slideshare.net/wata_orz/ss-12131479\r\n\
    \              https://37zigen.com/subset-convolution/\r\n*/\r\n\r\n#include <array>\r\
    \n#line 11 \"convolution/subset_convolution.hpp\"\n\r\n#line 2 \"set_function/ranked_subset_transform.hpp\"\
    \n\n#line 6 \"set_function/ranked_subset_transform.hpp\"\n\n#line 2 \"utility/bit_operator.hpp\"\
    \n\nnamespace ebi {\n\nconstexpr int bsf_constexpr(unsigned int n) {\n    int\
    \ x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n}\n\nint bit_reverse(int\
    \ n, int bit_size) {\n    int rev_n = 0;\n    for (int i = 0; i < bit_size; i++)\
    \ {\n        rev_n |= ((n >> i) & 1) << (bit_size - i - 1);\n    }\n    return\
    \ rev_n;\n}\n\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) <\
    \ (unsigned int)(n)) x++;\n    return x;\n}\n\nint popcnt(int x) {\n    return\
    \ __builtin_popcount(x);\n}\n\nint msb(int x) {\n    return (x == 0) ? -1 : 31\
    \ - __builtin_clz(x);\n}\n\nint bsf(int x) {\n    return (x == 0) ? -1 : __builtin_ctz(x);\n\
    }\n\n}  // namespace ebi\n#line 8 \"set_function/ranked_subset_transform.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T, int LIM = 20>\nstd::vector<std::array<T,\
    \ LIM + 1>> ranked_zeta(const std::vector<T> &f) {\n    int n = msb(f.size());\n\
    \    assert(n <= LIM);\n    assert((int)f.size() == (1 << n));\n    std::vector<std::array<T,\
    \ LIM + 1>> rf(1 << n);\n    for (int s = 0; s < (1 << n); s++) rf[s][popcnt(s)]\
    \ = f[s];\n    for (int i = 0; i < n; i++) {\n        int w = 1 << i;\n      \
    \  for (int p = 0; p < (1 << n); p += 2 * w) {\n            for (int s = p; s\
    \ < p + w; s++) {\n                int t = s | (1 << i);\n                for\
    \ (int d = 0; d <= n; d++) rf[t][d] += rf[s][d];\n            }\n        }\n \
    \   }\n    return rf;\n}\n\ntemplate <class T, int LIM = 20>\nstd::vector<T> ranked_mobius(std::vector<std::array<T,\
    \ LIM + 1>> rf) {\n    int n = msb(rf.size());\n    assert((int)rf.size() == (1\
    \ << n));\n    for (int i = 0; i < n; i++) {\n        int w = 1 << i;\n      \
    \  for (int p = 0; p < (1 << n); p += 2 * w) {\n            for (int s = p; s\
    \ < p + w; s++) {\n                int t = s | (1 << i);\n                for\
    \ (int d = 0; d <= n; d++) rf[t][d] -= rf[s][d];\n            }\n        }\n \
    \   }\n    std::vector<T> f(1 << n);\n    for (int s = 0; s < (1 << n); s++) {\n\
    \        f[s] = rf[s][popcnt(s)];\n    }\n    return f;\n}\n\n}  // namespace\
    \ ebi\n#line 14 \"convolution/subset_convolution.hpp\"\n\r\nnamespace ebi {\r\n\
    \r\ntemplate <class T, int LIM = 20>\r\nstd::vector<T> subset_convolution(const\
    \ std::vector<T> &a,\r\n                                  const std::vector<T>\
    \ &b) {\r\n    auto ra = ranked_zeta<T, LIM>(a);\r\n    auto rb = ranked_zeta<T,\
    \ LIM>(b);\r\n    int n = msb(ra.size());\r\n    for (int s = (1 << n) - 1; s\
    \ >= 0; s--) {\r\n        auto &f = ra[s];\r\n        const auto &g = rb[s];\r\
    \n        for (int d = n; d >= 0; d--) {\r\n            T x = 0;\r\n         \
    \   for (int i = 0; i <= d; i++) {\r\n                x += f[i] * g[d - i];\r\n\
    \            }\r\n            f[d] = x;\r\n        }\r\n    }\r\n    return ranked_mobius<T,\
    \ LIM>(ra);\r\n}\r\n\r\n}  // namespace ebi\n#line 8 \"set_function/exp_of_sps.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T, int LIM> std::vector<T> exp_of_sps(const\
    \ std::vector<T> &a) {\n    int n = msb(a.size());\n    assert(n <= LIM);\n  \
    \  assert((int)a.size() == (1 << n));\n    std::vector<T> fa(1 << n);\n    fa[0]\
    \ = T(1);\n    for (int i = 0; i < n; i++) {\n        std::vector<T> s = {a.begin()\
    \ + (1 << i), a.begin() + (2 << i)};\n        std::vector<T> t = {fa.begin(),\
    \ fa.begin() + (1 << i)};\n        auto c = subset_convolution<T, LIM>(s, t);\n\
    \        std::copy(c.begin(), c.end(), fa.begin() + (1 << i));\n    }\n    return\
    \ fa;\n}\n\n}  // namespace ebi\n#line 2 \"utility/modint.hpp\"\n\r\n#line 5 \"\
    utility/modint.hpp\"\n#include <type_traits>\r\n\r\n#line 2 \"utility/modint_base.hpp\"\
    \n\n#line 4 \"utility/modint_base.hpp\"\n\nnamespace ebi {\n\nnamespace internal\
    \ {\n\nstruct modint_base {};\n\ntemplate <class T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \nstruct static_modint_base : modint_base {};\n\ntemplate <class T>\nusing is_static_modint\
    \ = std::is_base_of<internal::static_modint_base, T>;\n\ntemplate <class T>\n\
    using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\n}\
    \  // namespace internal\n\n}  // namespace ebi\n#line 8 \"utility/modint.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <int m> struct static_modint : internal::static_modint_base\
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
    \n        return *this;\r\n    }\r\n    constexpr modint &operator+=(const modint\
    \ &rhs) {\r\n        _v += rhs._v;\r\n        if (_v >= umod()) _v -= umod();\r\
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
    \ static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 8 \"test/set_function/Exp_of_Set_Power_Series.test.cpp\"\
    \n\nusing mint = ebi::modint998244353;\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n    std::vector<mint> b(1 << n);\n    for (int i = 0; i < (1 << n); i++)\
    \ {\n        int x;\n        std::cin >> x;\n        b[i] = x;\n    }\n    auto\
    \ c = ebi::exp_of_sps<mint, 20>(b);\n    for (int i = 0; i < (1 << n); i++) {\n\
    \        std::cout << c[i].val() << \" \\n\"[i == (1 << n) - 1];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_set_power_series\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../set_function/exp_of_sps.hpp\"\
    \n#include \"../../utility/modint.hpp\"\n\nusing mint = ebi::modint998244353;\n\
    \nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<mint> b(1 << n);\n\
    \    for (int i = 0; i < (1 << n); i++) {\n        int x;\n        std::cin >>\
    \ x;\n        b[i] = x;\n    }\n    auto c = ebi::exp_of_sps<mint, 20>(b);\n \
    \   for (int i = 0; i < (1 << n); i++) {\n        std::cout << c[i].val() << \"\
    \ \\n\"[i == (1 << n) - 1];\n    }\n}"
  dependsOn:
  - set_function/exp_of_sps.hpp
  - convolution/subset_convolution.hpp
  - set_function/ranked_subset_transform.hpp
  - utility/bit_operator.hpp
  - utility/modint.hpp
  - utility/modint_base.hpp
  isVerificationFile: true
  path: test/set_function/Exp_of_Set_Power_Series.test.cpp
  requiredBy: []
  timestamp: '2023-07-17 11:19:29+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/set_function/Exp_of_Set_Power_Series.test.cpp
layout: document
redirect_from:
- /verify/test/set_function/Exp_of_Set_Power_Series.test.cpp
- /verify/test/set_function/Exp_of_Set_Power_Series.test.cpp.html
title: test/set_function/Exp_of_Set_Power_Series.test.cpp
---
