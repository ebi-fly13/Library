---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: set_function/ranked_zeta.hpp
    title: set_function/ranked_zeta.hpp
  - icon: ':heavy_check_mark:'
    path: set_function/sps_exp.hpp
    title: set_function/sps_exp.hpp
  - icon: ':heavy_check_mark:'
    path: set_function/subset_convolution.hpp
    title: set_function/subset_convolution.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/exp_of_set_power_series
    links:
    - https://judge.yosupo.jp/problem/exp_of_set_power_series
  bundledCode: "#line 1 \"test/Exp_of_Set_Power_Series.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/exp_of_set_power_series\"\n\n#include <iostream>\n\
    #include <vector>\n\n#line 2 \"set_function/sps_exp.hpp\"\n\n#include <cassert>\n\
    #line 5 \"set_function/sps_exp.hpp\"\n\n#line 2 \"set_function/subset_convolution.hpp\"\
    \n\r\n/*\r\n    refernce: https://www.slideshare.net/wata_orz/ss-12131479\r\n\
    \              https://37zigen.com/subset-convolution/\r\n*/\r\n\r\n#include <array>\r\
    \n#line 11 \"set_function/subset_convolution.hpp\"\n\r\n#line 2 \"set_function/ranked_zeta.hpp\"\
    \n\n#line 6 \"set_function/ranked_zeta.hpp\"\n\n#line 2 \"utility/bit_operator.hpp\"\
    \n\nnamespace ebi {\n\nint popcnt(int x) {\n    return __builtin_popcount(x);\n\
    }\n\nint topbit(int x) {\n    return (x == 0) ? -1 : 31 - __builtin_clz(x);\n\
    }\n\nint lowbit(int x) {\n    return (x == 0) ? -1 : __builtin_ctz(x);\n}\n\n\
    }  // namespace ebi\n#line 8 \"set_function/ranked_zeta.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <class T, int LIM = 20>\nstd::vector<std::array<T, LIM + 1>> ranked_zeta(const\
    \ std::vector<T> &f) {\n    int n = topbit(f.size());\n    assert(n <= LIM);\n\
    \    assert((int)f.size() == (1 << n));\n    std::vector<std::array<T, LIM + 1>>\
    \ rf(1 << n);\n    for (int s = 0; s < (1 << n); s++) rf[s][popcnt(s)] = f[s];\n\
    \    for (int i = 0; i < n; i++) {\n        int w = 1 << i;\n        for (int\
    \ p = 0; p < (1 << n); p += 2 * w) {\n            for (int s = p; s < p + w; s++)\
    \ {\n                int t = s | (1 << i);\n                for (int d = 0; d\
    \ <= n; d++) rf[t][d] += rf[s][d];\n            }\n        }\n    }\n    return\
    \ rf;\n}\n\ntemplate <class T, int LIM = 20>\nstd::vector<T> ranked_mobius(std::vector<std::array<T,\
    \ LIM + 1>> rf) {\n    int n = topbit(rf.size());\n    assert((int)rf.size() ==\
    \ (1 << n));\n    for (int i = 0; i < n; i++) {\n        int w = 1 << i;\n   \
    \     for (int p = 0; p < (1 << n); p += 2 * w) {\n            for (int s = p;\
    \ s < p + w; s++) {\n                int t = s | (1 << i);\n                for\
    \ (int d = 0; d <= n; d++) rf[t][d] -= rf[s][d];\n            }\n        }\n \
    \   }\n    std::vector<T> f(1 << n);\n    for (int s = 0; s < (1 << n); s++) {\n\
    \        f[s] = rf[s][popcnt(s)];\n    }\n    return f;\n}\n\n}  // namespace\
    \ ebi\n#line 14 \"set_function/subset_convolution.hpp\"\n\r\nnamespace ebi {\r\
    \n\r\ntemplate <class T, int LIM = 20>\r\nstd::vector<T> subset_convolution(const\
    \ std::vector<T> &a,\r\n                                  const std::vector<T>\
    \ &b) {\r\n    auto ra = ranked_zeta<T, LIM>(a);\r\n    auto rb = ranked_zeta<T,\
    \ LIM>(b);\r\n    int n = topbit(ra.size());\r\n    for (int s = (1 << n) - 1;\
    \ s >= 0; s--) {\r\n        auto &f = ra[s];\r\n        const auto &g = rb[s];\r\
    \n        for (int d = n; d >= 0; d--) {\r\n            T x = 0;\r\n         \
    \   for (int i = 0; i <= d; i++) {\r\n                x += f[i] * g[d - i];\r\n\
    \            }\r\n            f[d] = x;\r\n        }\r\n    }\r\n    return ranked_mobius<T,\
    \ LIM>(ra);\r\n}\r\n\r\n}  // namespace ebi\n#line 8 \"set_function/sps_exp.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T, int LIM> std::vector<T> sps_exp(const\
    \ std::vector<T> &s) {\n    int n = topbit(s.size());\n    assert(n <= LIM);\n\
    \    assert((int)s.size() == (1 << n));\n    std::vector<T> fs(1 << n);\n    fs[0]\
    \ = T(1);\n    for (int i = 0; i < n; i++) {\n        std::vector<T> a = {s.begin()\
    \ + (1 << i), s.begin() + (2 << i)};\n        std::vector<T> b = {fs.begin(),\
    \ fs.begin() + (1 << i)};\n        a = subset_convolution<T, LIM>(a, b);\n   \
    \     std::copy(a.begin(), a.end(), fs.begin() + (1 << i));\n    }\n    return\
    \ fs;\n}\n\n}  // namespace ebi\n#line 2 \"utility/modint.hpp\"\n\r\n/*\r\n  \
    \  author: noshi91\r\n    reference: https://noshi91.hatenablog.com/entry/2019/03/31/174006\r\
    \n    noshi91\u306E\u30D6\u30ED\u30B0\u3067\u516C\u958B\u3055\u308C\u3066\u3044\
    \u308Bmodint\u3092\u5143\u306Binv(), pow()\u3092\u8FFD\u52A0\u3057\u305F\u3082\
    \u306E\u3067\u3059\r\n*/\r\n\r\n#include <cstdint>\r\n#line 11 \"utility/modint.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <std::uint_fast64_t Modulus> class modint\
    \ {\r\n    using u64 = std::uint_fast64_t;\r\n\r\n  public:\r\n    u64 a;\r\n\r\
    \n    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}\r\n    constexpr\
    \ u64 &value() noexcept {\r\n        return a;\r\n    }\r\n    constexpr u64 &val()\
    \ noexcept {\r\n        return a;\r\n    }\r\n    constexpr const u64 &value()\
    \ const noexcept {\r\n        return a;\r\n    }\r\n    constexpr modint operator+(const\
    \ modint rhs) const noexcept {\r\n        return modint(*this) += rhs;\r\n   \
    \ }\r\n    constexpr modint operator-(const modint rhs) const noexcept {\r\n \
    \       return modint(*this) -= rhs;\r\n    }\r\n    constexpr modint operator*(const\
    \ modint rhs) const noexcept {\r\n        return modint(*this) *= rhs;\r\n   \
    \ }\r\n    constexpr modint operator/(const modint rhs) const noexcept {\r\n \
    \       return modint(*this) /= rhs;\r\n    }\r\n    constexpr modint &operator+=(const\
    \ modint rhs) noexcept {\r\n        a += rhs.a;\r\n        if (a >= Modulus) {\r\
    \n            a -= Modulus;\r\n        }\r\n        return *this;\r\n    }\r\n\
    \    constexpr modint &operator-=(const modint rhs) noexcept {\r\n        if (a\
    \ < rhs.a) {\r\n            a += Modulus;\r\n        }\r\n        a -= rhs.a;\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator*=(const modint\
    \ rhs) noexcept {\r\n        a = a * rhs.a % Modulus;\r\n        return *this;\r\
    \n    }\r\n    constexpr modint &operator/=(modint rhs) noexcept {\r\n       \
    \ u64 exp = Modulus - 2;\r\n        while (exp) {\r\n            if (exp % 2)\
    \ {\r\n                *this *= rhs;\r\n            }\r\n            rhs *= rhs;\r\
    \n            exp /= 2;\r\n        }\r\n        return *this;\r\n    }\r\n   \
    \ constexpr modint operator-() const {\r\n        return modint() - *this;\r\n\
    \    }\r\n    bool operator==(const u64 rhs) {\r\n        return a == rhs;\r\n\
    \    }\r\n    bool operator!=(const u64 rhs) {\r\n        return a != rhs;\r\n\
    \    }\r\n    constexpr modint &operator++() {\r\n        a++;\r\n        if (a\
    \ == mod()) a = 0;\r\n        return *this;\r\n    }\r\n    constexpr modint &operator--()\
    \ {\r\n        if (a == 0) a = mod();\r\n        a--;\r\n        return *this;\r\
    \n    }\r\n\r\n    modint pow(u64 n) const noexcept {\r\n        modint res =\
    \ 1;\r\n        modint x = a;\r\n        while (n > 0) {\r\n            if (n\
    \ & 1) res *= x;\r\n            x *= x;\r\n            n >>= 1;\r\n        }\r\
    \n        return res;\r\n    }\r\n    modint inv() const {\r\n        return pow(Modulus\
    \ - 2);\r\n    }\r\n\r\n    static u64 mod() {\r\n        return Modulus;\r\n\
    \    }\r\n};\r\n\r\nusing modint998244353 = modint<998244353>;\r\nusing modint1000000007\
    \ = modint<1000000007>;\r\n\r\ntemplate <std::uint_fast64_t Modulus>\r\nstd::ostream\
    \ &operator<<(std::ostream &os, modint<Modulus> a) {\r\n    return os << a.val();\r\
    \n}\r\n\r\n}  // namespace ebi\n#line 8 \"test/Exp_of_Set_Power_Series.test.cpp\"\
    \n\nusing mint = ebi::modint998244353;\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n    std::vector<mint> b(1<<n);\n    for(int i = 0; i < (1<<n); i++) {\n\
    \        int x;\n        std::cin >> x;\n        b[i] = x;\n    }\n    auto c\
    \ = ebi::sps_exp<mint, 20>(b);\n    for(int i = 0; i < (1<<n); i++) {\n      \
    \  std::cout << c[i].val() << \" \\n\"[i == (1<<n)-1];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_set_power_series\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../set_function/sps_exp.hpp\"\
    \n#include \"../utility/modint.hpp\"\n\nusing mint = ebi::modint998244353;\n\n\
    int main() {\n    int n;\n    std::cin >> n;\n    std::vector<mint> b(1<<n);\n\
    \    for(int i = 0; i < (1<<n); i++) {\n        int x;\n        std::cin >> x;\n\
    \        b[i] = x;\n    }\n    auto c = ebi::sps_exp<mint, 20>(b);\n    for(int\
    \ i = 0; i < (1<<n); i++) {\n        std::cout << c[i].val() << \" \\n\"[i ==\
    \ (1<<n)-1];\n    }\n}"
  dependsOn:
  - set_function/sps_exp.hpp
  - set_function/subset_convolution.hpp
  - set_function/ranked_zeta.hpp
  - utility/bit_operator.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/Exp_of_Set_Power_Series.test.cpp
  requiredBy: []
  timestamp: '2023-05-16 01:22:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Exp_of_Set_Power_Series.test.cpp
layout: document
redirect_from:
- /verify/test/Exp_of_Set_Power_Series.test.cpp
- /verify/test/Exp_of_Set_Power_Series.test.cpp.html
title: test/Exp_of_Set_Power_Series.test.cpp
---
