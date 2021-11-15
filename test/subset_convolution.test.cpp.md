---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/subset_convolution.hpp
    title: algorithm/subset_convolution.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/subset_convolution
    links:
    - https://judge.yosupo.jp/problem/subset_convolution
  bundledCode: "#line 1 \"test/subset_convolution.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#line 2 \"utility/modint.hpp\"\
    \n\r\n/*\r\n    author: noshi91\r\n    reference: https://noshi91.hatenablog.com/entry/2019/03/31/174006\r\
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
    \ ebi\n#line 2 \"algorithm/subset_convolution.hpp\"\n\r\n/*\r\n    refernce: https://www.slideshare.net/wata_orz/ss-12131479\r\
    \n              https://37zigen.com/subset-convolution/\r\n*/\r\n\r\n#line 9 \"\
    algorithm/subset_convolution.hpp\"\n\r\nnamespace ebi {\r\n\r\nnamespace internal\
    \ {\r\n\r\ntemplate<class T>\r\nstd::vector<T> mul(const std::vector<T> &a, const\
    \ std::vector<T> &b) {\r\n    int n = a.size();\r\n    std::vector<T> c(n,0);\r\
    \n    for(int i = 0; i<n; i++) {\r\n        for(int j = 0; j<n; j++) {\r\n   \
    \         if(i+j>=n) break;\r\n            c[i+j] += a[i]*b[j];\r\n        }\r\
    \n    }\r\n    return c;\r\n}\r\n\r\n} // namespace internal\r\n\r\ntemplate<class\
    \ T>\r\nstd::vector<T> subset_convolution(const std::vector<T> &a, const std::vector<T>\
    \ &b, int n) {\r\n    std::vector f(1<<n, std::vector<T>(n+1,0)), g(1<<n, std::vector<T>(n+1,0));\r\
    \n    for(int S = 0; S < (1<<n); ++S) {\r\n        f[S][0] = a[S];\r\n       \
    \ g[S][0] = b[S];\r\n    }\r\n    for(int i = n-1; i>=0; --i) {\r\n        int\
    \ V = 1<<i;\r\n        for(int S = V; S < (1<<n); ++S) {\r\n            S |= V;\r\
    \n            for(int j = n; j>=0; --j) {\r\n                f[S][j] = f[S^V][j]\
    \ + (j > 0 ? f[S][j-1] : 0);\r\n                g[S][j] = g[S^V][j] + (j > 0 ?\
    \ g[S][j-1] : 0);\r\n            }\r\n        }\r\n    }\r\n    std::vector fg(1<<n,\
    \ std::vector<T>());\r\n    for(int S = 0; S < (1<<n); ++S) {\r\n        fg[S]\
    \ = internal::mul(f[S], g[S]);\r\n    }\r\n    for(int i = 0; i<n; ++i) {\r\n\
    \        int V = 1<<i;\r\n        for(int S = V; S < (1<<n); ++S) {\r\n      \
    \      S |= V;\r\n            for(int j = n; j>=0; --j) {\r\n                fg[S][j]\
    \ -= fg[S^V][j];\r\n            }\r\n        }\r\n    }\r\n    std::vector<T>\
    \ h(1<<n);\r\n    for(int S = 0; S < (1<<n); ++S) {\r\n        h[S] = fg[S][__builtin_popcount(S)];\r\
    \n    }\r\n    return h;\r\n}\r\n\r\n} // namespace ebi\n#line 8 \"test/subset_convolution.test.cpp\"\
    \n\r\nusing mint = ebi::modint998244353;\r\n\r\nint main() {\r\n    int n;\r\n\
    \    std::cin >> n;\r\n    std::vector<mint> a(1<<n), b(1<<n);\r\n    for(int\
    \ i = 0; i<(1<<n); i++) {\r\n        int val;\r\n        std::cin >> val;\r\n\
    \        a[i] = val;\r\n    }\r\n    for(int i = 0; i<(1<<n); i++) {\r\n     \
    \   int val;\r\n        std::cin >> val;\r\n        b[i] = val;\r\n    }\r\n \
    \   auto c = ebi::subset_convolution(a, b, n);\r\n    for(int i = 0; i < (1<<n);\
    \ i++) {\r\n        std::cout << c[i].val() << ((i == (1<<n)-1) ? \"\\n\" : \"\
    \ \");\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\r\n\
    \r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"../utility/modint.hpp\"\
    \r\n#include \"../algorithm/subset_convolution.hpp\"\r\n\r\nusing mint = ebi::modint998244353;\r\
    \n\r\nint main() {\r\n    int n;\r\n    std::cin >> n;\r\n    std::vector<mint>\
    \ a(1<<n), b(1<<n);\r\n    for(int i = 0; i<(1<<n); i++) {\r\n        int val;\r\
    \n        std::cin >> val;\r\n        a[i] = val;\r\n    }\r\n    for(int i =\
    \ 0; i<(1<<n); i++) {\r\n        int val;\r\n        std::cin >> val;\r\n    \
    \    b[i] = val;\r\n    }\r\n    auto c = ebi::subset_convolution(a, b, n);\r\n\
    \    for(int i = 0; i < (1<<n); i++) {\r\n        std::cout << c[i].val() << ((i\
    \ == (1<<n)-1) ? \"\\n\" : \" \");\r\n    }\r\n}"
  dependsOn:
  - utility/modint.hpp
  - algorithm/subset_convolution.hpp
  isVerificationFile: true
  path: test/subset_convolution.test.cpp
  requiredBy: []
  timestamp: '2021-04-04 17:12:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/subset_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/subset_convolution.test.cpp
- /verify/test/subset_convolution.test.cpp.html
title: test/subset_convolution.test.cpp
---
