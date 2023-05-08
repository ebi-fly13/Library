---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algorithm/convolution.hpp
    title: algorithm/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: math/FormalPowerSeries.hpp
    title: math/FormalPowerSeries.hpp
  - icon: ':question:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/log_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/log_of_formal_power_series
  bundledCode: "#line 1 \"test/Log_of_Formal_Power_Series.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/log_of_formal_power_series\"\r\n\r\n#include\
    \ <iostream>\r\n\r\n#line 2 \"math/FormalPowerSeries.hpp\"\n\r\n#line 2 \"algorithm/convolution.hpp\"\
    \n\r\n/*\r\n    reference: https://hcpc-hokudai.github.io/archive/math_fft_002.pdf\r\
    \n    mod 998244353 \u4E0A\u3067\u306E\u7573\u307F\u8FBC\u307F\u3092 O(N log N)\
    \ \u3067\u6C42\u3081\u308B.\r\n*/\r\n\r\n#line 2 \"utility/modint.hpp\"\n\r\n\
    /*\r\n    author: noshi91\r\n    reference: https://noshi91.hatenablog.com/entry/2019/03/31/174006\r\
    \n    noshi91\u306E\u30D6\u30ED\u30B0\u3067\u516C\u958B\u3055\u308C\u3066\u3044\
    \u308Bmodint\u3092\u5143\u306Binv(), pow()\u3092\u8FFD\u52A0\u3057\u305F\u3082\
    \u306E\u3067\u3059\r\n*/\r\n\r\n#include <cstdint>\r\n#line 11 \"utility/modint.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate<std::uint_fast64_t Modulus>\r\nclass modint\
    \ {\r\n  using u64 = std::uint_fast64_t;\r\n\r\npublic:\r\n    u64 a;\r\n\r\n\
    \    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}\r\n    constexpr\
    \ u64 &value() noexcept { return a; }\r\n    constexpr u64 &val() noexcept { return\
    \ a; }\r\n    constexpr const u64 &value() const noexcept { return a; }\r\n  \
    \  constexpr modint operator+(const modint rhs) const noexcept {\r\n        return\
    \ modint(*this) += rhs;\r\n    }\r\n    constexpr modint operator-(const modint\
    \ rhs) const noexcept {\r\n        return modint(*this) -= rhs;\r\n    }\r\n \
    \   constexpr modint operator*(const modint rhs) const noexcept {\r\n        return\
    \ modint(*this) *= rhs;\r\n    }\r\n    constexpr modint operator/(const modint\
    \ rhs) const noexcept {\r\n        return modint(*this) /= rhs;\r\n    }\r\n \
    \   constexpr modint &operator+=(const modint rhs) noexcept {\r\n        a +=\
    \ rhs.a;\r\n        if (a >= Modulus) {\r\n            a -= Modulus;\r\n     \
    \   }\r\n        return *this;\r\n    }\r\n    constexpr modint &operator-=(const\
    \ modint rhs) noexcept {\r\n        if (a < rhs.a) {\r\n        a += Modulus;\r\
    \n        }\r\n        a -= rhs.a;\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator*=(const modint rhs) noexcept {\r\n        a = a * rhs.a % Modulus;\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator/=(modint rhs)\
    \ noexcept {\r\n        u64 exp = Modulus - 2;\r\n        while (exp) {\r\n  \
    \      if (exp % 2) {\r\n            *this *= rhs;\r\n        }\r\n        rhs\
    \ *= rhs;\r\n        exp /= 2;\r\n        }\r\n        return *this;\r\n    }\r\
    \n    constexpr modint operator-() const { return modint() - *this; }\r\n    bool\
    \ operator==(const u64 rhs) {\r\n        return a == rhs;\r\n    }\r\n    bool\
    \ operator!=(const u64 rhs) {\r\n        return a != rhs;\r\n    }\r\n    constexpr\
    \ modint& operator++() {\r\n        a++;\r\n        if( a == mod() ) a = 0;\r\n\
    \        return *this;\r\n    }\r\n    constexpr modint& operator--() {\r\n  \
    \      if( a == 0 ) a = mod();\r\n        a--;\r\n        return *this;\r\n  \
    \  }\r\n\r\n    modint pow(u64 n) const noexcept {\r\n        modint res = 1;\r\
    \n        modint x = a;\r\n        while(n>0){\r\n            if(n&1) res *= x;\r\
    \n            x *= x;\r\n            n >>=1;\r\n        }\r\n        return res;\r\
    \n    }\r\n    modint inv() const {\r\n        return pow(Modulus-2);\r\n    }\r\
    \n\r\n    static u64 mod() {\r\n        return Modulus;\r\n    }\r\n};\r\n\r\n\
    using modint998244353 = modint<998244353>;\r\nusing modint1000000007 = modint<1000000007>;\r\
    \n\r\ntemplate<std::uint_fast64_t Modulus>\r\nstd::ostream& operator<<(std::ostream&\
    \ os, modint<Modulus> a){\r\n    return os << a.val();\r\n}\r\n\r\n} // namespace\
    \ ebi\n#line 9 \"algorithm/convolution.hpp\"\n\r\n#include <vector>\r\n\r\nnamespace\
    \ ebi {\r\n\r\nusing mint = ebi::modint998244353;\r\n\r\nnamespace internal {\r\
    \n\r\nconstexpr mint primitive_root = 3;\r\n\r\nvoid dft(std::vector<mint> &f)\
    \ {\r\n    int n = f.size();\r\n    if(n==1) return;\r\n    std::vector<mint>\
    \ a(n/2), b(n/2);\r\n    for(int i = 0; i<n/2; ++i) {\r\n        a[i] = f[2*i];\r\
    \n        b[i] = f[2*i+1];\r\n    }\r\n    dft(a);\r\n    dft(b);\r\n    const\
    \ mint zeta = primitive_root.pow((mint::mod()-1)/n);\r\n    mint x = 1;\r\n  \
    \  for(int i = 0; i<n; ++i) {\r\n        f[i] = a[i%(n/2)] + x*b[i%(n/2)];\r\n\
    \        x *= zeta;\r\n    }\r\n}\r\n\r\nvoid inv_dft(std::vector<mint> &f) {\r\
    \n    int n = f.size();\r\n    if(n==1) return;\r\n    std::vector<mint> a(n/2),\
    \ b(n/2);\r\n    for(int i = 0; i<n/2; ++i) {\r\n        a[i] = f[2*i];\r\n  \
    \      b[i] = f[2*i+1];\r\n    }\r\n    inv_dft(a);\r\n    inv_dft(b);\r\n   \
    \ const mint inv_zeta = primitive_root.pow((mint::mod()-1)/n).inv();\r\n    mint\
    \ x = 1;\r\n    for(int i = 0; i<n; ++i) {\r\n        f[i] = a[i%(n/2)] + x*b[i%(n/2)];\r\
    \n        x *= inv_zeta;\r\n    }\r\n}\r\n\r\n} // namespace internal\r\n\r\n\
    std::vector<mint> convolution(const std::vector<mint> &f, const std::vector<mint>\
    \ &g) {\r\n    int n = 1;\r\n    while(n < (int)f.size() + (int)g.size() - 1)\
    \ n <<= 1;\r\n    std::vector<mint> a(n,0), b(n,0), fg(n,0);\r\n    std::copy(f.begin(),\
    \ f.end(), a.begin());\r\n    std::copy(g.begin(), g.end(), b.begin());\r\n  \
    \  internal::dft(a);\r\n    internal::dft(b);\r\n    for(int i = 0; i<n; ++i)\
    \ {\r\n        fg[i] = a[i]*b[i];\r\n    }\r\n    internal::inv_dft(fg);\r\n \
    \   mint in = mint(n).inv();\r\n    for(int i = 0; i<n; ++i) {\r\n        fg[i]\
    \ *= in;\r\n    }\r\n    return fg;\r\n}\r\n\r\n} // namespace ebi\n#line 5 \"\
    math/FormalPowerSeries.hpp\"\n\r\n#line 7 \"math/FormalPowerSeries.hpp\"\n#include\
    \ <algorithm>\r\n#include <cassert>\r\n\r\n/*\r\n    reference: https://opt-cp.com/fps-fast-algorithms/\r\
    \n*/\r\n\r\nnamespace ebi {\r\n\r\nusing mint = modint998244353;\r\n\r\nstruct\
    \ FormalPowerSeries : std::vector<mint> {\r\nprivate:\r\n    using std::vector<mint>::vector;\r\
    \n    using std::vector<mint>::vector::operator=;\r\n    using FPS = FormalPowerSeries;\r\
    \npublic:\r\n    FPS operator+(const FPS &rhs) const noexcept {\r\n        return\
    \ FPS(*this) += rhs;\r\n    }\r\n    FPS operator-(const FPS &rhs) const noexcept\
    \ {\r\n        return FPS(*this) -= rhs;\r\n    }\r\n    FPS operator*(const FPS\
    \ &rhs) const noexcept {\r\n        return FPS(*this) *= rhs;\r\n    }\r\n   \
    \ FPS operator/(const FPS &rhs) const noexcept {\r\n        return FPS(*this)\
    \ /= rhs;\r\n    }\r\n\r\n    FPS &operator+=(const FPS &rhs) noexcept {\r\n \
    \       int sz = std::min(deg(), rhs.deg());\r\n        for(int i = 0; i< sz;\
    \ ++i) {\r\n            (*this)[i] += rhs[i];\r\n        }\r\n        return *this;\r\
    \n    }\r\n\r\n    FPS &operator-=(const FPS &rhs) noexcept {\r\n        int sz\
    \ = std::min(deg(), rhs.deg());\r\n        for(int i = 0; i< sz; ++i) {\r\n  \
    \          (*this)[i] -= rhs[i];\r\n        }\r\n        return *this;\r\n   \
    \ }\r\n\r\n    FPS &operator*=(const FPS &rhs) noexcept {\r\n        int n = deg();\r\
    \n        *this = convolution(*this, rhs);\r\n        (*this).resize(n);\r\n \
    \       return *this;\r\n    }\r\n\r\n    FPS &operator/=(const FPS &rhs) noexcept\
    \ {\r\n        *this *= rhs.inv();\r\n        return *this;\r\n    }\r\n\r\n \
    \   FPS &operator*=(const mint rhs) noexcept {\r\n        for(int i = 0; i<deg();\
    \ ++i) {\r\n            (*this)[i] *= rhs;\r\n        }\r\n        return *this;\r\
    \n    }\r\n\r\n    FPS inv() const {\r\n        int n = 1, sz = deg();\r\n   \
    \     FPS g(n);\r\n        g[0] = (*this)[0].inv();\r\n        while(n < sz) {\r\
    \n            n <<= 1;\r\n            FPS f((*this).begin(), (*this).begin()+std::min(sz,\
    \ n));\r\n            f.resize(n);\r\n            g.resize(n);\r\n           \
    \ FPS h = f*g;\r\n            h.erase(h.begin(), h.begin()+n/2);\r\n         \
    \   h.resize(n);\r\n            h = h*g;\r\n            for(int i = 0; i<n/2;\
    \ i++) {\r\n                g[i+n/2] -= h[i];\r\n            }\r\n        }\r\n\
    \        g.resize(sz);\r\n        return g;\r\n    }\r\n\r\n    FPS exp() {\r\n\
    \        assert((*this)[0].val() == 0);\r\n        int n = 1, sz = deg();\r\n\
    \        FPS g(n);\r\n        g[0] = 1;\r\n        while(n < sz) {\r\n       \
    \     n <<= 1;\r\n            FPS f((*this).begin(), (*this).begin()+std::min(sz,\
    \ n));\r\n            f.resize(n);\r\n            g.resize(n);\r\n           \
    \ g = g*(f-g.log()) + g;\r\n        }\r\n        return g;\r\n    }\r\n\r\n  \
    \  FPS differential() {\r\n        int n = deg();\r\n        FPS g(n);\r\n   \
    \     for(int i = 0; i<n-1; i++) {\r\n            g[i] = (*this)[i+1]*(i+1);\r\
    \n        }\r\n        g[n-1] = 0;\r\n        return g;\r\n    }\r\n\r\n    FPS\
    \ integral() {\r\n        int n = deg();\r\n        FPS g(n+1);\r\n        g[0]\
    \ = 0;\r\n        for(int i = 0; i<n; i++) {\r\n            g[i+1] = (*this)[i]/(mint(i+1));\r\
    \n        }\r\n        return g;\r\n    }\r\n\r\n    FPS log() {\r\n        assert((*this)[0].val()\
    \ == 1);\r\n        FPS g = (*this).differential()/(*this);\r\n        return\
    \ g.integral();\r\n    }\r\n\r\n    int deg() const {\r\n        return (*this).size();\r\
    \n    }\r\n};\r\n\r\n} // namespace ebi\n#line 6 \"test/Log_of_Formal_Power_Series.test.cpp\"\
    \n\r\nint main() {\r\n    int n;\r\n    std::cin >> n;\r\n    ebi::FormalPowerSeries\
    \ a(n);\r\n    for (int i = 0; i < n; ++i) {\r\n        int val;\r\n        std::cin\
    \ >> val;\r\n        a[i] = val;\r\n    }\r\n    ebi::FormalPowerSeries b = a.log();\r\
    \n    for (int i = 0; i < n; ++i) {\r\n        std::cout << b[i].val() << \" \"\
    ;\r\n    }\r\n    std::cout << std::endl;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/log_of_formal_power_series\"\
    \r\n\r\n#include <iostream>\r\n\r\n#include \"../math/FormalPowerSeries.hpp\"\r\
    \n\r\nint main() {\r\n    int n;\r\n    std::cin >> n;\r\n    ebi::FormalPowerSeries\
    \ a(n);\r\n    for (int i = 0; i < n; ++i) {\r\n        int val;\r\n        std::cin\
    \ >> val;\r\n        a[i] = val;\r\n    }\r\n    ebi::FormalPowerSeries b = a.log();\r\
    \n    for (int i = 0; i < n; ++i) {\r\n        std::cout << b[i].val() << \" \"\
    ;\r\n    }\r\n    std::cout << std::endl;\r\n}"
  dependsOn:
  - math/FormalPowerSeries.hpp
  - algorithm/convolution.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/Log_of_Formal_Power_Series.test.cpp
  requiredBy: []
  timestamp: '2023-05-08 05:33:08+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Log_of_Formal_Power_Series.test.cpp
layout: document
redirect_from:
- /verify/test/Log_of_Formal_Power_Series.test.cpp
- /verify/test/Log_of_Formal_Power_Series.test.cpp.html
title: test/Log_of_Formal_Power_Series.test.cpp
---
