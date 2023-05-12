---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/hadamard_transform.hpp
    title: algorithm/hadamard_transform.hpp
  - icon: ':heavy_check_mark:'
    path: algorithm/xor_convolution.hpp
    title: algorithm/xor_convolution.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"test/Bitwise_Xor_Convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\n\n#include <iostream>\n\
    #include <vector>\n\n#line 2 \"algorithm/xor_convolution.hpp\"\n\n#include <cassert>\n\
    #line 5 \"algorithm/xor_convolution.hpp\"\n\n#line 2 \"algorithm/hadamard_transform.hpp\"\
    \n\n#line 4 \"algorithm/hadamard_transform.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class T>\nstd::vector<T> hadamard_transform(std::vector<T> f, bool inverse\
    \ = false) {\n    int n = f.size();\n    for (int i = 1; i < n; i <<= 1) {\n \
    \       for (int j = 0; j < n; j++) {\n            if ((i & j) == 0) {\n     \
    \           T x = f[j], y = f[j | i];\n                f[j] = x + y;\n       \
    \         f[j | i] = x - y;\n            }\n        }\n    }\n    if (inverse)\
    \ {\n        for (auto& x : f) {\n            x /= T(n);\n        }\n    }\n \
    \   return f;\n}\n\n}  // namespace ebi\n#line 7 \"algorithm/xor_convolution.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T>\nstd::vector<T> xor_convolution(const\
    \ std::vector<T> &a,\n                               const std::vector<T> &b)\
    \ {\n    assert(a.size() == b.size());\n    auto ta = hadamard_transform(a);\n\
    \    auto tb = hadamard_transform(b);\n    for (int i = 0; i < (int)a.size();\
    \ i++) {\n        ta[i] *= tb[i];\n    }\n    return hadamard_transform(ta, true);\n\
    }\n\n}  // namespace ebi\n#line 2 \"utility/modint.hpp\"\n\r\n/*\r\n    author:\
    \ noshi91\r\n    reference: https://noshi91.hatenablog.com/entry/2019/03/31/174006\r\
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
    \n}\r\n\r\n}  // namespace ebi\n#line 8 \"test/Bitwise_Xor_Convolution.test.cpp\"\
    \n\nusing mint = ebi::modint998244353;\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n    std::vector<mint> a(1 << n), b(1 << n);\n    for (int i = 0; i <\
    \ (1 << n); i++) {\n        int val;\n        std::cin >> val;\n        a[i] =\
    \ val;\n    }\n    for (int i = 0; i < (1 << n); i++) {\n        int val;\n  \
    \      std::cin >> val;\n        b[i] = val;\n    }\n    auto c = ebi::xor_convolution(a,\
    \ b);\n    for (int i = 0; i < (1 << n); i++) {\n        std::cout << c[i].val()\
    \ << \" \\n\"[i == (1 << n) - 1];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../algorithm/xor_convolution.hpp\"\
    \n#include \"../utility/modint.hpp\"\n\nusing mint = ebi::modint998244353;\n\n\
    int main() {\n    int n;\n    std::cin >> n;\n    std::vector<mint> a(1 << n),\
    \ b(1 << n);\n    for (int i = 0; i < (1 << n); i++) {\n        int val;\n   \
    \     std::cin >> val;\n        a[i] = val;\n    }\n    for (int i = 0; i < (1\
    \ << n); i++) {\n        int val;\n        std::cin >> val;\n        b[i] = val;\n\
    \    }\n    auto c = ebi::xor_convolution(a, b);\n    for (int i = 0; i < (1 <<\
    \ n); i++) {\n        std::cout << c[i].val() << \" \\n\"[i == (1 << n) - 1];\n\
    \    }\n}\n"
  dependsOn:
  - algorithm/xor_convolution.hpp
  - algorithm/hadamard_transform.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/Bitwise_Xor_Convolution.test.cpp
  requiredBy: []
  timestamp: '2023-05-12 15:09:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Bitwise_Xor_Convolution.test.cpp
layout: document
redirect_from:
- /verify/test/Bitwise_Xor_Convolution.test.cpp
- /verify/test/Bitwise_Xor_Convolution.test.cpp.html
title: test/Bitwise_Xor_Convolution.test.cpp
---
