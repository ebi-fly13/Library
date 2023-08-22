---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/convolution_mod_2_64.hpp
    title: Convolution ($\mod 2^{64}$)
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: NTT Convolution
  - icon: ':heavy_check_mark:'
    path: math/internal_math.hpp
    title: math/internal_math.hpp
  - icon: ':heavy_check_mark:'
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_2_64
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_2_64
  bundledCode: "#line 1 \"test/convolution/Convolution_Mod_2_64.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_2_64\"\n\n#include\
    \ <cstdint>\n#include <iostream>\n#include <vector>\n\n#line 2 \"convolution/convolution_mod_2_64.hpp\"\
    \n\n#line 5 \"convolution/convolution_mod_2_64.hpp\"\n\n#line 2 \"convolution/ntt.hpp\"\
    \n\n#include <algorithm>\n#include <array>\n#include <cassert>\n#include <type_traits>\n\
    #line 8 \"convolution/ntt.hpp\"\n\n#line 2 \"math/internal_math.hpp\"\n\n#line\
    \ 4 \"math/internal_math.hpp\"\n\nnamespace ebi {\n\nnamespace internal {\n\n\
    constexpr int primitive_root_constexpr(int m) {\n    if (m == 2) return 1;\n \
    \   if (m == 167772161) return 3;\n    if (m == 469762049) return 3;\n    if (m\
    \ == 754974721) return 11;\n    if (m == 998244353) return 3;\n    if (m == 880803841)\
    \ return 26;\n    return -1;\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n}  // namespace internal\n\n}  // namespace\
    \ ebi\n#line 2 \"utility/bit_operator.hpp\"\n\nnamespace ebi {\n\nconstexpr int\
    \ bsf_constexpr(unsigned int n) {\n    int x = 0;\n    while (!(n & (1 << x)))\
    \ x++;\n    return x;\n}\n\nint bit_reverse(int n, int bit_size) {\n    int rev_n\
    \ = 0;\n    for (int i = 0; i < bit_size; i++) {\n        rev_n |= ((n >> i) &\
    \ 1) << (bit_size - i - 1);\n    }\n    return rev_n;\n}\n\nint ceil_pow2(int\
    \ n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n)) x++;\n    return\
    \ x;\n}\n\nint popcnt(int x) {\n    return __builtin_popcount(x);\n}\n\nint msb(int\
    \ x) {\n    return (x == 0) ? -1 : 31 - __builtin_clz(x);\n}\n\nint bsf(int x)\
    \ {\n    return (x == 0) ? -1 : __builtin_ctz(x);\n}\n\n}  // namespace ebi\n\
    #line 2 \"utility/modint_base.hpp\"\n\n#line 4 \"utility/modint_base.hpp\"\n\n\
    namespace ebi {\n\nnamespace internal {\n\nstruct modint_base {};\n\ntemplate\
    \ <class T> using is_modint = std::is_base_of<modint_base, T>;\ntemplate <class\
    \ T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\nstruct static_modint_base\
    \ : modint_base {};\n\ntemplate <class T>\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\ntemplate <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace ebi\n#line 12 \"convolution/ntt.hpp\"\
    \n\nnamespace ebi {\n\nnamespace internal {\n\ntemplate <class mint, int g = internal::primitive_root<mint::mod()>,\n\
    \          internal::is_static_modint_t<mint>* = nullptr>\nstruct ntt_info {\n\
    \    static constexpr int rank2 = bsf_constexpr(mint::mod() - 1);\n\n    std::array<mint,\
    \ rank2 + 1> root, inv_root;\n\n    ntt_info() {\n        root[rank2] = mint(g).pow((mint::mod()\
    \ - 1) >> rank2);\n        inv_root[rank2] = root[rank2].inv();\n        for (int\
    \ i = rank2 - 1; i >= 0; i--) {\n            root[i] = root[i + 1] * root[i +\
    \ 1];\n            inv_root[i] = inv_root[i + 1] * inv_root[i + 1];\n        }\n\
    \    }\n};\n\ntemplate <class mint, internal::is_static_modint_t<mint>* = nullptr>\n\
    void butterfly(std::vector<mint>& a) {\n    static const ntt_info<mint> info;\n\
    \    int n = int(a.size());\n    int bit_size = bsf(n);\n    assert(n == 1 <<\
    \ ceil_pow2(n));\n    // bit reverse\n    for (int i = 0; i < n; i++) {\n    \
    \    int rev = bit_reverse(i, bit_size);\n        if (i < rev) {\n           \
    \ std::swap(a[i], a[rev]);\n        }\n    }\n\n    for (int bit = 0; bit < bit_size;\
    \ bit++) {\n        for (int i = 0; i < n / (1 << (bit + 1)); i++) {\n       \
    \     mint zeta1 = 1;\n            mint zeta2 = info.root[1];\n            for\
    \ (int j = 0; j < (1 << bit); j++) {\n                int idx = i * (1 << (bit\
    \ + 1)) + j;\n                int jdx = idx + (1 << bit);\n                mint\
    \ p1 = a[idx];\n                mint p2 = a[jdx];\n                a[idx] = p1\
    \ + zeta1 * p2;\n                a[jdx] = p1 + zeta2 * p2;\n                zeta1\
    \ *= info.root[bit + 1];\n                zeta2 *= info.root[bit + 1];\n     \
    \       }\n        }\n    }\n}\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nvoid butterfly_inv(std::vector<mint>& a) {\n    static const ntt_info<mint>\
    \ info;\n    int n = int(a.size());\n    int bit_size = bsf(n);\n    assert(n\
    \ == 1 << ceil_pow2(n));\n    // bit reverse\n    for (int i = 0; i < n; i++)\
    \ {\n        int rev = bit_reverse(i, bit_size);\n        if (i < rev) std::swap(a[i],\
    \ a[rev]);\n    }\n\n    for (int bit = 0; bit < bit_size; bit++) {\n        for\
    \ (int i = 0; i < n / (1 << (bit + 1)); i++) {\n            mint zeta1 = 1;\n\
    \            mint zeta2 = info.inv_root[1];\n            for (int j = 0; j < (1\
    \ << bit); j++) {\n                int idx = i * (1 << (bit + 1)) + j;\n     \
    \           int jdx = idx + (1 << bit);\n                mint p1 = a[idx];\n \
    \               mint p2 = a[jdx];\n                a[idx] = p1 + zeta1 * p2;\n\
    \                a[jdx] = p1 + zeta2 * p2;\n                zeta1 *= info.inv_root[bit\
    \ + 1];\n                zeta2 *= info.inv_root[bit + 1];\n            }\n   \
    \     }\n    }\n    mint inv_n = mint(n).inv();\n    for (int i = 0; i < n; i++)\
    \ {\n        a[i] *= inv_n;\n    }\n}\n\n}  // namespace internal\n\ntemplate\
    \ <class mint, internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint>\
    \ convolution_naive(const std::vector<mint>& f,\n                            \
    \        const std::vector<mint>& g) {\n    if (f.empty() || g.empty()) return\
    \ {};\n    int n = int(f.size()), m = int(g.size());\n    std::vector<mint> c(n\
    \ + m - 1);\n    if (n < m) {\n        for (int j = 0; j < m; j++) {\n       \
    \     for (int i = 0; i < n; i++) {\n                c[i + j] += f[i] * g[j];\n\
    \            }\n        }\n    } else {\n        for (int i = 0; i < n; i++) {\n\
    \            for (int j = 0; j < m; j++) {\n                c[i + j] += f[i] *\
    \ g[j];\n            }\n        }\n    }\n    return c;\n}\n\ntemplate <class\
    \ mint, internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution(const\
    \ std::vector<mint>& f,\n                              const std::vector<mint>&\
    \ g) {\n    if (f.empty() || g.empty()) return {};\n    if (std::min(f.size(),\
    \ g.size()) < 60) return convolution_naive(f, g);\n    int n = 1 << ceil_pow2(f.size()\
    \ + g.size() - 1);\n    std::vector<mint> a(n), b(n);\n    std::copy(f.begin(),\
    \ f.end(), a.begin());\n    std::copy(g.begin(), g.end(), b.begin());\n    internal::butterfly(a);\n\
    \    internal::butterfly(b);\n    for (int i = 0; i < n; i++) {\n        a[i]\
    \ *= b[i];\n    }\n    internal::butterfly_inv(a);\n    a.resize(f.size() + g.size()\
    \ - 1);\n    return a;\n}\n\n}  // namespace ebi\n#line 2 \"utility/modint.hpp\"\
    \n\r\n#line 6 \"utility/modint.hpp\"\n\r\n#line 8 \"utility/modint.hpp\"\n\r\n\
    namespace ebi {\r\n\r\ntemplate <int m> struct static_modint : internal::static_modint_base\
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
    \n        return m;\r\n    }\r\n};\r\n\r\ntemplate <int m>\r\nstd::istream &operator>>(std::istream\
    \ &os, static_modint<m> &a) {\r\n    long long x;\r\n    os >> x;\r\n    a = x;\r\
    \n    return os;\r\n}\r\ntemplate <int m>\r\nstd::ostream &operator<<(std::ostream\
    \ &os, const static_modint<m> &a) {\r\n    return os << a.val();\r\n}\r\n\r\n\
    using modint998244353 = static_modint<998244353>;\r\nusing modint1000000007 =\
    \ static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 9 \"convolution/convolution_mod_2_64.hpp\"\
    \n\nnamespace ebi {\n\nnamespace internal {\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstd::vector<mint> multiply_uint64_t(const std::vector<std::uint64_t>&\
    \ f,\n                                    const std::vector<std::uint64_t>& g)\
    \ {\n    std::vector<mint> a, b;\n    a.reserve(f.size());\n    b.reserve(g.size());\n\
    \    for (auto x : f) a.emplace_back(x % mint::mod());\n    for (auto x : g) b.emplace_back(x\
    \ % mint::mod());\n    return convolution<mint>(a, b);\n}\n\n}  // namespace internal\n\
    \nstd::vector<std::uint64_t> convolution_mod_2_64(\n    const std::vector<std::uint64_t>&\
    \ f, const std::vector<std::uint64_t>& g) {\n    if (f.empty() || g.empty()) return\
    \ {};\n    using i32 = std::int32_t;\n    using i64 = std::int64_t;\n    using\
    \ u64 = std::uint64_t;\n    static constexpr i32 m0 = 998244353;\n    static constexpr\
    \ i32 m1 = 754974721;\n    static constexpr i32 m2 = 167772161;\n    static constexpr\
    \ i32 m3 = 469762049;\n    static constexpr i32 m4 = 880803841;\n    using mint0\
    \ = static_modint<m0>;\n    using mint1 = static_modint<m1>;\n    using mint2\
    \ = static_modint<m2>;\n    using mint3 = static_modint<m3>;\n    using mint4\
    \ = static_modint<m4>;\n\n    auto d0 = internal::multiply_uint64_t<mint0>(f,\
    \ g);\n    auto d1 = internal::multiply_uint64_t<mint1>(f, g);\n    auto d2 =\
    \ internal::multiply_uint64_t<mint2>(f, g);\n    auto d3 = internal::multiply_uint64_t<mint3>(f,\
    \ g);\n    auto d4 = internal::multiply_uint64_t<mint4>(f, g);\n\n    static const\
    \ mint1 inv10 = mint1(m0).inv();\n    static const mint2 inv21 = mint2(m1).inv(),\
    \ inv20 = inv21 / mint2(m0);\n    static const mint3 inv32 = mint3(m2).inv(),\
    \ inv31 = inv32 / mint3(m1),\n                       inv30 = inv31 / mint3(m0);\n\
    \    static const mint4 inv43 = mint4(m3).inv(), inv42 = inv43 / mint4(m2),\n\
    \                       inv41 = inv42 / mint4(m1), inv40 = inv41 / mint4(m0);\n\
    \    int n = d0.size();\n    std::vector<u64> res(n);\n    for (int i = 0; i <\
    \ n; i++) {\n        i64 x0 = d0[i].val();\n        i64 x1 = ((d1[i] - x0) * inv10).val();\n\
    \        i64 x2 = (((d2[i] - x0)) * inv20 - mint2(x1) * inv21).val();\n      \
    \  i64 x3 = ((d3[i] - x0) * inv30 - mint3(x1) * inv31 - mint3(x2) * inv32)\n \
    \                    .val();\n        i64 x4 = ((d4[i] - x0) * inv40 - mint4(x1)\
    \ * inv41 - mint4(x2) * inv42 -\n                  mint4(x3) * inv43)\n      \
    \               .val();\n        res[i] = x0 + m0 * (x1 + m1 * (x2 + m2 * (x3\
    \ + m3 * (u64(x4)))));\n    }\n    return res;\n}\n\n}  // namespace ebi\n#line\
    \ 8 \"test/convolution/Convolution_Mod_2_64.test.cpp\"\n\nusing u64 = std::uint64_t;\n\
    \nint main() {\n    int n, m;\n    std::cin >> n >> m;\n    std::vector<u64> a(n),\
    \ b(m);\n    for (int i = 0; i < n; i++) std::cin >> a[i];\n    for (int i = 0;\
    \ i < m; i++) std::cin >> b[i];\n    auto c = ebi::convolution_mod_2_64(a, b);\n\
    \    for (int i = 0; i < n + m - 1; i++)\n        std::cout << c[i] << \" \\n\"\
    [i == n + m - 2];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_2_64\"\n\
    \n#include <cstdint>\n#include <iostream>\n#include <vector>\n\n#include \"../../convolution/convolution_mod_2_64.hpp\"\
    \n\nusing u64 = std::uint64_t;\n\nint main() {\n    int n, m;\n    std::cin >>\
    \ n >> m;\n    std::vector<u64> a(n), b(m);\n    for (int i = 0; i < n; i++) std::cin\
    \ >> a[i];\n    for (int i = 0; i < m; i++) std::cin >> b[i];\n    auto c = ebi::convolution_mod_2_64(a,\
    \ b);\n    for (int i = 0; i < n + m - 1; i++)\n        std::cout << c[i] << \"\
    \ \\n\"[i == n + m - 2];\n}"
  dependsOn:
  - convolution/convolution_mod_2_64.hpp
  - convolution/ntt.hpp
  - math/internal_math.hpp
  - utility/bit_operator.hpp
  - utility/modint_base.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/convolution/Convolution_Mod_2_64.test.cpp
  requiredBy: []
  timestamp: '2023-08-16 10:56:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/convolution/Convolution_Mod_2_64.test.cpp
layout: document
redirect_from:
- /verify/test/convolution/Convolution_Mod_2_64.test.cpp
- /verify/test/convolution/Convolution_Mod_2_64.test.cpp.html
title: test/convolution/Convolution_Mod_2_64.test.cpp
---
