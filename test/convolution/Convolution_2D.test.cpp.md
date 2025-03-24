---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/convolution_2d.hpp
    title: Convolution 2D
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: NTT
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: Graph (CSR format)
  - icon: ':heavy_check_mark:'
    path: math/internal_math.hpp
    title: math/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':heavy_check_mark:'
    path: template/debug_template.hpp
    title: template/debug_template.hpp
  - icon: ':heavy_check_mark:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  - icon: ':heavy_check_mark:'
    path: template/io.hpp
    title: template/io.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/utility.hpp
    title: template/utility.hpp
  - icon: ':heavy_check_mark:'
    path: utility/random_number_generator.hpp
    title: Random Number Generator
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/convolution/Convolution_2D.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"convolution/convolution_2d.hpp\"\
    \n\n#include <vector>\n\n#line 2 \"convolution/convolution.hpp\"\n\n#include <algorithm>\n\
    #include <bit>\n#line 6 \"convolution/convolution.hpp\"\n\n#line 2 \"convolution/ntt.hpp\"\
    \n\n#line 4 \"convolution/ntt.hpp\"\n#include <array>\n#line 6 \"convolution/ntt.hpp\"\
    \n#include <cassert>\n#line 8 \"convolution/ntt.hpp\"\n\n#line 2 \"math/internal_math.hpp\"\
    \n\n#line 4 \"math/internal_math.hpp\"\n\nnamespace ebi {\n\nnamespace internal\
    \ {\n\nconstexpr int primitive_root_constexpr(int m) {\n    if (m == 2) return\
    \ 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049) return 3;\n \
    \   if (m == 754974721) return 11;\n    if (m == 998244353) return 3;\n    if\
    \ (m == 880803841) return 26;\n    if (m == 924844033) return 5;\n    return -1;\n\
    }\ntemplate <int m> constexpr int primitive_root = primitive_root_constexpr(m);\n\
    \n}  // namespace internal\n\n}  // namespace ebi\n#line 2 \"modint/base.hpp\"\
    \n\n#include <concepts>\n#include <iostream>\n#include <utility>\n\nnamespace\
    \ ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n    a +\
    \ b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 2 \"\
    template/int_alias.hpp\"\n\n#include <cstdint>\n\nnamespace ebi {\n\nusing ld\
    \ = long double;\nusing std::size_t;\nusing i8 = std::int8_t;\nusing u8 = std::uint8_t;\n\
    using i16 = std::int16_t;\nusing u16 = std::uint16_t;\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n\n}  // namespace ebi\n#line\
    \ 12 \"convolution/ntt.hpp\"\n\nnamespace ebi {\n\nnamespace internal {\n\ntemplate\
    \ <Modint mint, int g = internal::primitive_root<mint::mod()>>\nstruct ntt_info\
    \ {\n    static constexpr int rank2 =\n        std::countr_zero((unsigned int)(mint::mod()\
    \ - 1));\n\n    std::array<mint, rank2 + 1> root, inv_root;\n\n    ntt_info()\
    \ {\n        root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);\n        inv_root[rank2]\
    \ = root[rank2].inv();\n        for (int i = rank2 - 1; i >= 0; i--) {\n     \
    \       root[i] = root[i + 1] * root[i + 1];\n            inv_root[i] = inv_root[i\
    \ + 1] * inv_root[i + 1];\n        }\n    }\n};\n\ntemplate <Modint mint> void\
    \ fft2(std::vector<mint>& a) {\n    static const ntt_info<mint> info;\n    int\
    \ n = int(a.size());\n    int bit_size = std::countr_zero(a.size());\n    assert(n\
    \ == 1 << bit_size);\n    for (int bit = bit_size - 1; bit >= 0; bit--) {\n  \
    \      int m = 1 << bit;\n        for (int i = 0; i < n; i += 2 * m) {\n     \
    \       mint w = 1;\n            for (int j = 0; j < m; j++) {\n             \
    \   mint p1 = a[i + j];\n                mint p2 = a[i + j + m];\n           \
    \     a[i + j] = p1 + p2;\n                a[i + j + m] = (p1 - p2) * w;\n   \
    \             w *= info.root[bit + 1];\n            }\n        }\n    }\n}\n\n\
    template <Modint mint> void ifft2(std::vector<mint>& a) {\n    static const ntt_info<mint>\
    \ info;\n    int n = int(a.size());\n    int bit_size = std::countr_zero(a.size());\n\
    \    assert(n == 1 << bit_size);\n\n    for (int bit = 0; bit < bit_size; bit++)\
    \ {\n        for (int i = 0; i < n / (1 << (bit + 1)); i++) {\n            mint\
    \ w = 1;\n            for (int j = 0; j < (1 << bit); j++) {\n               \
    \ int idx = i * (1 << (bit + 1)) + j;\n                int jdx = idx + (1 << bit);\n\
    \                mint p1 = a[idx];\n                mint p2 = w * a[jdx];\n  \
    \              a[idx] = p1 + p2;\n                a[jdx] = p1 - p2;\n        \
    \        w *= info.inv_root[bit + 1];\n            }\n        }\n    }\n}\n\n\
    template <Modint mint> void fft4(std::vector<mint>& a) {\n    static const ntt_info<mint>\
    \ info;\n    const u32 mod = mint::mod();\n    const u64 iw = info.root[2].val();\n\
    \    int n = int(a.size());\n    int bit_size = std::countr_zero(a.size());\n\
    \    assert(n == 1 << bit_size);\n    int len = bit_size;\n    while (len > 0)\
    \ {\n        if (len == 1) {\n            for (int i = 0; i < n; i += 2) {\n \
    \               mint p0 = a[i];\n                mint p1 = a[i + 1];\n       \
    \         a[i] = p0 + p1;\n                a[i + 1] = p0 - p1;\n            }\n\
    \            len--;\n        } else {\n            int m = 1 << (len - 2);\n \
    \           u64 w1 = 1, w2 = 1, w3 = 1, iw1 = iw, iw3 = iw;\n            for (int\
    \ i = 0; i < m; i++) {\n                for (int j = 0; j < n; j += 4 * m) {\n\
    \                    int i0 = i + j, i1 = i0 + m, i2 = i1 + m, i3 = i2 + m;\n\
    \                    u32 a0 = a[i0].val();\n                    u32 a1 = a[i1].val();\n\
    \                    u32 a2 = a[i2].val();\n                    u32 a3 = a[i3].val();\n\
    \                    u32 a0_plus_a2 = a0 + a2;\n                    u32 a1_plus_a3\
    \ = a1 + a3;\n                    u32 a0_minus_a2 = a0 + mod - a2;\n         \
    \           u32 a1_minus_a3 = a1 + mod - a3;\n                    a[i0] = a0_plus_a2\
    \ + a1_plus_a3;\n                    a[i1] = a0_minus_a2 * w1 + a1_minus_a3 *\
    \ iw1;\n                    a[i2] = (a0_plus_a2 + 2 * mod - a1_plus_a3) * w2;\n\
    \                    a[i3] = a0_minus_a2 * w3 + (2 * mod - a1_minus_a3) * iw3;\n\
    \                }\n                w1 = w1 * info.root[len].val() % mod;\n  \
    \              w2 = w1 * w1 % mod;\n                w3 = w2 * w1 % mod;\n    \
    \            iw1 = iw * w1 % mod;\n                iw3 = iw * w3 % mod;\n    \
    \        }\n            len -= 2;\n        }\n    }\n}\n\ntemplate <Modint mint>\
    \ void ifft4(std::vector<mint>& a) {\n    static const ntt_info<mint> info;\n\
    \    const u32 mod = mint::mod();\n    const u64 mod2 = u64(mod) * mod;\n    const\
    \ u64 iw = info.inv_root[2].val();\n    int n = int(a.size());\n    int bit_size\
    \ = std::countr_zero(a.size());\n    assert(n == 1 << bit_size);\n    int len\
    \ = (bit_size & 1 ? 1 : 2);\n    while (len <= bit_size) {\n        if (len ==\
    \ 1) {\n            for (int i = 0; i < n; i += 2) {\n                mint a0\
    \ = a[i];\n                mint a1 = a[i + 1];\n                a[i] = a0 + a1;\n\
    \                a[i + 1] = a0 - a1;\n            }\n        } else {\n      \
    \      int m = 1 << (len - 2);\n            u64 w1 = 1, w2 = 1, w3 = 1, iw1 =\
    \ iw, iw3 = iw;\n            for (int i = 0; i < m; i++) {\n                for\
    \ (int j = 0; j < n; j += 4 * m) {\n                    int i0 = i + j, i1 = i0\
    \ + m, i2 = i1 + m, i3 = i2 + m;\n                    u64 a0 = a[i0].val();\n\
    \                    u64 a1 = w1 * a[i1].val();\n                    u64 a2 =\
    \ w2 * a[i2].val();\n                    u64 a3 = w3 * a[i3].val();\n        \
    \            u64 b1 = iw1 * a[i1].val();\n                    u64 b3 = iw3 * a[i3].val();\n\
    \                    u64 a0_plus_a2 = a0 + a2;\n                    u64 a1_plus_a3\
    \ = a1 + a3;\n                    u64 a0_minus_a2 = a0 + mod2 - a2;\n        \
    \            u64 b1_minus_b3 = b1 + mod2 - b3;\n                    a[i0] = a0_plus_a2\
    \ + a1_plus_a3;\n                    a[i1] = a0_minus_a2 + b1_minus_b3;\n    \
    \                a[i2] = a0_plus_a2 + mod2 * 2 - a1_plus_a3;\n               \
    \     a[i3] = a0_minus_a2 + mod2 * 2 - b1_minus_b3;\n                }\n     \
    \           w1 = w1 * info.inv_root[len].val() % mod;\n                w2 = w1\
    \ * w1 % mod;\n                w3 = w2 * w1 % mod;\n                iw1 = iw *\
    \ w1 % mod;\n                iw3 = iw * w3 % mod;\n            }\n        }\n\
    \        len += 2;\n    }\n}\n\n}  // namespace internal\n\n}  // namespace ebi\n\
    #line 9 \"convolution/convolution.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint\
    \ mint>\nstd::vector<mint> convolution_naive(const std::vector<mint>& f,\n   \
    \                                 const std::vector<mint>& g) {\n    if (f.empty()\
    \ || g.empty()) return {};\n    int n = int(f.size()), m = int(g.size());\n  \
    \  std::vector<mint> c(n + m - 1);\n    if (n < m) {\n        for (int j = 0;\
    \ j < m; j++) {\n            for (int i = 0; i < n; i++) {\n                c[i\
    \ + j] += f[i] * g[j];\n            }\n        }\n    } else {\n        for (int\
    \ i = 0; i < n; i++) {\n            for (int j = 0; j < m; j++) {\n          \
    \      c[i + j] += f[i] * g[j];\n            }\n        }\n    }\n    return c;\n\
    }\n\ntemplate <Modint mint>\nstd::vector<mint> convolution(const std::vector<mint>&\
    \ f,\n                              const std::vector<mint>& g) {\n    if (f.empty()\
    \ || g.empty()) return {};\n    if (std::min(f.size(), g.size()) < 60) return\
    \ convolution_naive(f, g);\n    int n = (int)std::bit_ceil(f.size() + g.size()\
    \ - 1);\n    std::vector<mint> a(n), b(n);\n    std::copy(f.begin(), f.end(),\
    \ a.begin());\n    std::copy(g.begin(), g.end(), b.begin());\n    internal::fft4(a);\n\
    \    internal::fft4(b);\n    for (int i = 0; i < n; i++) {\n        a[i] *= b[i];\n\
    \    }\n    internal::ifft4(a);\n    a.resize(f.size() + g.size() - 1);\n    mint\
    \ inv_n = mint(n).inv();\n    for (auto& x : a) x *= inv_n;\n    return a;\n}\n\
    \n}  // namespace ebi\n#line 7 \"convolution/convolution_2d.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <Modint mint>\nstd::vector<std::vector<mint>> convolution_2d(\n\
    \    const std::vector<std::vector<mint>> &a,\n    const std::vector<std::vector<mint>>\
    \ &b) {\n    if (a.empty() || b.empty()) return {};\n    int h1 = (int)a.size(),\
    \ w1 = (int)a[0].size();\n    int h2 = (int)b.size(), w2 = (int)b[0].size();\n\
    \    int h = h1 + h2 - 1, w = w1 + w2 - 1;\n    std::vector<mint> f(h1 * w, 0),\
    \ g(h2 * w, 0);\n    for (int i = 0; i < h1; i++) {\n        std::copy(a[i].begin(),\
    \ a[i].end(), f.begin() + i * w);\n    }\n    for (int i = 0; i < h2; i++) {\n\
    \        std::copy(b[i].begin(), b[i].end(), g.begin() + i * w);\n    }\n    auto\
    \ fg = convolution(f, g);\n    std::vector c(h, std::vector<mint>(w, 0));\n  \
    \  for (int i = 0; i < h; i++) {\n        std::copy(fg.begin() + i * w, fg.begin()\
    \ + (i + 1) * w, c[i].begin());\n    }\n    return c;\n}\n\ntemplate <Modint mint>\n\
    std::vector<std::vector<mint>> convolution_2d_naive(\n    const std::vector<std::vector<mint>>\
    \ &a,\n    const std::vector<std::vector<mint>> &b) {\n    int h1 = (int)a.size(),\
    \ w1 = (int)a[0].size();\n    int h2 = (int)b.size(), w2 = (int)b[0].size();\n\
    \    int h = h1 + h2 - 1, w = w1 + w2 - 1;\n    std::vector c(h, std::vector<mint>(w,\
    \ 0));\n    for (int i = 0; i < h1; i++) {\n        for (int j = 0; j < w1; j++)\
    \ {\n            for (int k = 0; k < h2; k++) {\n                for (int l =\
    \ 0; l < w2; l++) {\n                    c[i + k][j + l] += a[i][j] * b[k][l];\n\
    \                }\n            }\n        }\n    }\n    return c;\n}\n\n}  //\
    \ namespace ebi\n#line 4 \"test/convolution/Convolution_2D.test.cpp\"\n\n#line\
    \ 2 \"modint/modint.hpp\"\n\r\n#line 5 \"modint/modint.hpp\"\n\r\n#line 7 \"modint/modint.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <int m> struct static_modint {\r\n  private:\r\
    \n    using modint = static_modint;\r\n\r\n  public:\r\n    static constexpr int\
    \ mod() {\r\n        return m;\r\n    }\r\n\r\n    static constexpr modint raw(int\
    \ v) {\r\n        modint x;\r\n        x._v = v;\r\n        return x;\r\n    }\r\
    \n\r\n    constexpr static_modint() : _v(0) {}\r\n\r\n    template <std::signed_integral\
    \ T> constexpr static_modint(T v) {\r\n        long long x = (long long)(v % (long\
    \ long)(umod()));\r\n        if (x < 0) x += umod();\r\n        _v = (unsigned\
    \ int)(x);\r\n    }\r\n\r\n    template <std::unsigned_integral T> constexpr static_modint(T\
    \ v) {\r\n        _v = (unsigned int)(v % umod());\r\n    }\r\n\r\n    constexpr\
    \ unsigned int val() const {\r\n        return _v;\r\n    }\r\n\r\n    constexpr\
    \ unsigned int value() const {\r\n        return val();\r\n    }\r\n\r\n    constexpr\
    \ modint &operator++() {\r\n        _v++;\r\n        if (_v == umod()) _v = 0;\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator--() {\r\n \
    \       if (_v == 0) _v = umod();\r\n        _v--;\r\n        return *this;\r\n\
    \    }\r\n\r\n    constexpr modint operator++(int) {\r\n        modint res = *this;\r\
    \n        ++*this;\r\n        return res;\r\n    }\r\n    constexpr modint operator--(int)\
    \ {\r\n        modint res = *this;\r\n        --*this;\r\n        return res;\r\
    \n    }\r\n\r\n    constexpr modint &operator+=(const modint &rhs) {\r\n     \
    \   _v += rhs._v;\r\n        if (_v >= umod()) _v -= umod();\r\n        return\
    \ *this;\r\n    }\r\n    constexpr modint &operator-=(const modint &rhs) {\r\n\
    \        _v -= rhs._v;\r\n        if (_v >= umod()) _v += umod();\r\n        return\
    \ *this;\r\n    }\r\n    constexpr modint &operator*=(const modint &rhs) {\r\n\
    \        unsigned long long x = _v;\r\n        x *= rhs._v;\r\n        _v = (unsigned\
    \ int)(x % (unsigned long long)umod());\r\n        return *this;\r\n    }\r\n\
    \    constexpr modint &operator/=(const modint &rhs) {\r\n        return *this\
    \ = *this * rhs.inv();\r\n    }\r\n\r\n    constexpr modint operator+() const\
    \ {\r\n        return *this;\r\n    }\r\n    constexpr modint operator-() const\
    \ {\r\n        return modint() - *this;\r\n    }\r\n\r\n    constexpr modint pow(long\
    \ long n) const {\r\n        assert(0 <= n);\r\n        modint x = *this, res\
    \ = 1;\r\n        while (n) {\r\n            if (n & 1) res *= x;\r\n        \
    \    x *= x;\r\n            n >>= 1;\r\n        }\r\n        return res;\r\n \
    \   }\r\n    constexpr modint inv() const {\r\n        assert(_v);\r\n       \
    \ return pow(umod() - 2);\r\n    }\r\n\r\n    friend modint operator+(const modint\
    \ &lhs, const modint &rhs) {\r\n        return modint(lhs) += rhs;\r\n    }\r\n\
    \    friend modint operator-(const modint &lhs, const modint &rhs) {\r\n     \
    \   return modint(lhs) -= rhs;\r\n    }\r\n    friend modint operator*(const modint\
    \ &lhs, const modint &rhs) {\r\n        return modint(lhs) *= rhs;\r\n    }\r\n\
    \r\n    friend modint operator/(const modint &lhs, const modint &rhs) {\r\n  \
    \      return modint(lhs) /= rhs;\r\n    }\r\n    friend bool operator==(const\
    \ modint &lhs, const modint &rhs) {\r\n        return lhs.val() == rhs.val();\r\
    \n    }\r\n    friend bool operator!=(const modint &lhs, const modint &rhs) {\r\
    \n        return !(lhs == rhs);\r\n    }\r\n\r\n  private:\r\n    unsigned int\
    \ _v = 0;\r\n\r\n    static constexpr unsigned int umod() {\r\n        return\
    \ m;\r\n    }\r\n};\r\n\r\nusing modint998244353 = static_modint<998244353>;\r\
    \nusing modint1000000007 = static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n\
    #line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n\n#define rep(i,\
    \ a, n) for (int i = (int)(a); i < (int)(n); i++)\n#define rrep(i, a, n) for (int\
    \ i = ((int)(n)-1); i >= (int)(a); i--)\n#define Rep(i, a, n) for (i64 i = (i64)(a);\
    \ i < (i64)(n); i++)\n#define RRep(i, a, n) for (i64 i = ((i64)(n)-i64(1)); i\
    \ >= (i64)(a); i--)\n#define all(v) (v).begin(), (v).end()\n#define rall(v) (v).rbegin(),\
    \ (v).rend()\n\n#line 2 \"template/debug_template.hpp\"\n\n#line 4 \"template/debug_template.hpp\"\
    \n\nnamespace ebi {\n\n#ifdef LOCAL\n#define debug(...)                      \
    \                                \\\n    std::cerr << \"LINE: \" << __LINE__ <<\
    \ \"  [\" << #__VA_ARGS__ << \"]:\", \\\n        debug_out(__VA_ARGS__)\n#else\n\
    #define debug(...)\n#endif\n\nvoid debug_out() {\n    std::cerr << std::endl;\n\
    }\n\ntemplate <typename Head, typename... Tail> void debug_out(Head h, Tail...\
    \ t) {\n    std::cerr << \" \" << h;\n    if (sizeof...(t) > 0) std::cerr << \"\
    \ :\";\n    debug_out(t...);\n}\n\n}  // namespace ebi\n#line 2 \"template/io.hpp\"\
    \n\n#line 5 \"template/io.hpp\"\n#include <optional>\n#line 7 \"template/io.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <typename T1, typename T2>\nstd::ostream &operator<<(std::ostream\
    \ &os, const std::pair<T1, T2> &pa) {\n    return os << pa.first << \" \" << pa.second;\n\
    }\n\ntemplate <typename T1, typename T2>\nstd::istream &operator>>(std::istream\
    \ &os, std::pair<T1, T2> &pa) {\n    return os >> pa.first >> pa.second;\n}\n\n\
    template <typename T>\nstd::ostream &operator<<(std::ostream &os, const std::vector<T>\
    \ &vec) {\n    for (std::size_t i = 0; i < vec.size(); i++)\n        os << vec[i]\
    \ << (i + 1 == vec.size() ? \"\" : \" \");\n    return os;\n}\n\ntemplate <typename\
    \ T>\nstd::istream &operator>>(std::istream &os, std::vector<T> &vec) {\n    for\
    \ (T &e : vec) std::cin >> e;\n    return os;\n}\n\ntemplate <typename T>\nstd::ostream\
    \ &operator<<(std::ostream &os, const std::optional<T> &opt) {\n    if (opt) {\n\
    \        os << opt.value();\n    } else {\n        os << \"invalid value\";\n\
    \    }\n    return os;\n}\n\nvoid fast_io() {\n    std::cout << std::fixed <<\
    \ std::setprecision(15);\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    }\n\n}  // namespace ebi\n#line 2 \"template/utility.hpp\"\n\n#line 5 \"template/utility.hpp\"\
    \n\n#line 2 \"graph/base.hpp\"\n\n#line 5 \"graph/base.hpp\"\n#include <ranges>\n\
    #line 7 \"graph/base.hpp\"\n\n#line 2 \"data_structure/simple_csr.hpp\"\n\n#line\
    \ 6 \"data_structure/simple_csr.hpp\"\n\nnamespace ebi {\n\ntemplate <class E>\
    \ struct simple_csr {\n    simple_csr() = default;\n\n    simple_csr(int n, const\
    \ std::vector<std::pair<int, E>>& elements)\n        : start(n + 1, 0), elist(elements.size())\
    \ {\n        for (auto e : elements) {\n            start[e.first + 1]++;\n  \
    \      }\n        for (auto i : std::views::iota(0, n)) {\n            start[i\
    \ + 1] += start[i];\n        }\n        auto counter = start;\n        for (auto\
    \ [i, e] : elements) {\n            elist[counter[i]++] = e;\n        }\n    }\n\
    \n    simple_csr(const std::vector<std::vector<E>>& es)\n        : start(es.size()\
    \ + 1, 0) {\n        int n = es.size();\n        for (auto i : std::views::iota(0,\
    \ n)) {\n            start[i + 1] = (int)es[i].size() + start[i];\n        }\n\
    \        elist.resize(start.back());\n        for (auto i : std::views::iota(0,\
    \ n)) {\n            std::copy(es[i].begin(), es[i].end(), elist.begin() + start[i]);\n\
    \        }\n    }\n\n    int size() const {\n        return (int)start.size()\
    \ - 1;\n    }\n\n    const auto operator[](int i) const {\n        return std::ranges::subrange(elist.begin()\
    \ + start[i],\n                                     elist.begin() + start[i +\
    \ 1]);\n    }\n    auto operator[](int i) {\n        return std::ranges::subrange(elist.begin()\
    \ + start[i],\n                                     elist.begin() + start[i +\
    \ 1]);\n    }\n\n    const auto operator()(int i, int l, int r) const {\n    \
    \    return std::ranges::subrange(elist.begin() + start[i] + l,\n            \
    \                         elist.begin() + start[i + 1] + r);\n    }\n    auto\
    \ operator()(int i, int l, int r) {\n        return std::ranges::subrange(elist.begin()\
    \ + start[i] + l,\n                                     elist.begin() + start[i\
    \ + 1] + r);\n    }\n\n  private:\n    std::vector<int> start;\n    std::vector<E>\
    \ elist;\n};\n\n}  // namespace ebi\n#line 9 \"graph/base.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <class T> struct Edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n};\n\ntemplate <class E> struct Graph {\n    using cost_type = E;\n   \
    \ using edge_type = Edge<cost_type>;\n\n    Graph(int n_) : n(n_) {}\n\n    Graph()\
    \ = default;\n\n    void add_edge(int u, int v, cost_type c) {\n        assert(!prepared\
    \ && u < n && v < n);\n        buff.emplace_back(u, edge_type{u, v, c, m});\n\
    \        edges.emplace_back(edge_type{u, v, c, m++});\n    }\n\n    void add_undirected_edge(int\
    \ u, int v, cost_type c) {\n        assert(!prepared && u < n && v < n);\n   \
    \     buff.emplace_back(u, edge_type{u, v, c, m});\n        buff.emplace_back(v,\
    \ edge_type{v, u, c, m});\n        edges.emplace_back(edge_type{u, v, c, m});\n\
    \        m++;\n    }\n\n    void read_tree(int offset = 1, bool is_weighted =\
    \ false) {\n        read_graph(n - 1, offset, false, is_weighted);\n    }\n\n\
    \    void read_parents(int offset = 1) {\n        for (auto i : std::views::iota(1,\
    \ n)) {\n            int p;\n            std::cin >> p;\n            p -= offset;\n\
    \            add_undirected_edge(p, i, 1);\n        }\n        build();\n    }\n\
    \n    void read_graph(int e, int offset = 1, bool is_directed = false,\n     \
    \               bool is_weighted = false) {\n        for (int i = 0; i < e; i++)\
    \ {\n            int u, v;\n            std::cin >> u >> v;\n            u -=\
    \ offset;\n            v -= offset;\n            if (is_weighted) {\n        \
    \        cost_type c;\n                std::cin >> c;\n                if (is_directed)\
    \ {\n                    add_edge(u, v, c);\n                } else {\n      \
    \              add_undirected_edge(u, v, c);\n                }\n            }\
    \ else {\n                if (is_directed) {\n                    add_edge(u,\
    \ v, 1);\n                } else {\n                    add_undirected_edge(u,\
    \ v, 1);\n                }\n            }\n        }\n        build();\n    }\n\
    \n    void build() {\n        assert(!prepared);\n        csr = simple_csr<edge_type>(n,\
    \ buff);\n        buff.clear();\n        prepared = true;\n    }\n\n    int size()\
    \ const {\n        return n;\n    }\n\n    int node_number() const {\n       \
    \ return n;\n    }\n\n    int edge_number() const {\n        return m;\n    }\n\
    \n    edge_type get_edge(int i) const {\n        assert(prepared);\n        return\
    \ edges[i];\n    }\n\n    std::vector<edge_type> get_edges() const {\n       \
    \ assert(prepared);\n        return edges;\n    }\n\n    const auto operator[](int\
    \ i) const {\n        assert(prepared);\n        return csr[i];\n    }\n    auto\
    \ operator[](int i) {\n        assert(prepared);\n        return csr[i];\n   \
    \ }\n\n  private:\n    int n, m = 0;\n\n    std::vector<std::pair<int, edge_type>>\
    \ buff;\n\n    std::vector<edge_type> edges;\n    simple_csr<edge_type> csr;\n\
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 8 \"template/utility.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T> inline bool chmin(T &a, T b) {\n   \
    \ if (a > b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\n\ntemplate <class T> inline bool chmax(T &a, T b) {\n    if (a < b) {\n   \
    \     a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate <class\
    \ T> T safe_ceil(T a, T b) {\n    if (a % b == 0)\n        return a / b;\n   \
    \ else if (a >= 0)\n        return (a / b) + 1;\n    else\n        return -((-a)\
    \ / b);\n}\n\ntemplate <class T> T safe_floor(T a, T b) {\n    if (a % b == 0)\n\
    \        return a / b;\n    else if (a >= 0)\n        return a / b;\n    else\n\
    \        return -((-a) / b) - 1;\n}\n\nconstexpr i64 LNF = std::numeric_limits<i64>::max()\
    \ / 4;\n\nconstexpr int INF = std::numeric_limits<int>::max() / 2;\n\nconst std::vector<int>\
    \ dy = {1, 0, -1, 0, 1, 1, -1, -1};\nconst std::vector<int> dx = {0, 1, 0, -1,\
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 2 \"utility/random_number_generator.hpp\"\
    \n\r\n#line 8 \"utility/random_number_generator.hpp\"\n\r\nnamespace ebi {\r\n\
    \r\nstruct random_number_generator {\r\n    random_number_generator(int seed =\
    \ -1) {\r\n        if (seed < 0) seed = rnd();\r\n        mt.seed(seed);\r\n \
    \   }\r\n\r\n    void set_seed(int seed) {\r\n        mt.seed(seed);\r\n    }\r\
    \n\r\n    template <class T> T get(T a, T b) {\r\n        std::uniform_int_distribution<T>\
    \ dist(a, b - 1);\r\n        return dist(mt);\r\n    }\r\n\r\n    std::vector<int>\
    \ get_permutation(int n) {\r\n        std::vector<int> p(n);\r\n        std::iota(p.begin(),\
    \ p.end(), 0);\r\n        std::shuffle(p.begin(), p.end(), mt);\r\n        return\
    \ p;\r\n    }\r\n\r\n  private:\r\n    std::mt19937_64 mt;\r\n    std::random_device\
    \ rnd;\r\n};\r\n\r\n}  // namespace ebi\n#line 8 \"test/convolution/Convolution_2D.test.cpp\"\
    \n\nnamespace ebi {\n\nusing mint = modint998244353;\n\nvoid main_() {\n    random_number_generator\
    \ rng;\n    int h1 = rng.get(30, 60);\n    int w1 = rng.get(30, 60);\n    int\
    \ h2 = rng.get(30, 60);\n    int w2 = rng.get(30, 60);\n    std::vector a(h1,\
    \ std::vector<mint>(w1));\n    std::vector b(h2, std::vector<mint>(w2));\n   \
    \ rep(i, 0, h1) rep(j, 0, w1) {\n        a[i][j] = rng.get(0, mint::mod());\n\
    \    }\n    rep(i, 0, h2) rep(j, 0, w2) {\n        b[i][j] = rng.get(0, mint::mod());\n\
    \    }\n    assert(convolution_2d(a, b) == convolution_2d_naive(a, b));\n}\n\n\
    }  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 10;\n  \
    \  // std::cin >> t;\n    int a, b;\n    std::cin >> a >> b;\n    std::cout <<\
    \ a + b << '\\n';\n    while (t--) {\n        ebi::main_();\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../convolution/convolution_2d.hpp\"\n\n#include \"../../modint/modint.hpp\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../utility/random_number_generator.hpp\"\
    \n\nnamespace ebi {\n\nusing mint = modint998244353;\n\nvoid main_() {\n    random_number_generator\
    \ rng;\n    int h1 = rng.get(30, 60);\n    int w1 = rng.get(30, 60);\n    int\
    \ h2 = rng.get(30, 60);\n    int w2 = rng.get(30, 60);\n    std::vector a(h1,\
    \ std::vector<mint>(w1));\n    std::vector b(h2, std::vector<mint>(w2));\n   \
    \ rep(i, 0, h1) rep(j, 0, w1) {\n        a[i][j] = rng.get(0, mint::mod());\n\
    \    }\n    rep(i, 0, h2) rep(j, 0, w2) {\n        b[i][j] = rng.get(0, mint::mod());\n\
    \    }\n    assert(convolution_2d(a, b) == convolution_2d_naive(a, b));\n}\n\n\
    }  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 10;\n  \
    \  // std::cin >> t;\n    int a, b;\n    std::cin >> a >> b;\n    std::cout <<\
    \ a + b << '\\n';\n    while (t--) {\n        ebi::main_();\n    }\n    return\
    \ 0;\n}"
  dependsOn:
  - convolution/convolution_2d.hpp
  - convolution/convolution.hpp
  - convolution/ntt.hpp
  - math/internal_math.hpp
  - modint/base.hpp
  - template/int_alias.hpp
  - modint/modint.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/io.hpp
  - template/utility.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  - utility/random_number_generator.hpp
  isVerificationFile: true
  path: test/convolution/Convolution_2D.test.cpp
  requiredBy: []
  timestamp: '2025-03-18 03:40:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/convolution/Convolution_2D.test.cpp
layout: document
redirect_from:
- /verify/test/convolution/Convolution_2D.test.cpp
- /verify/test/convolution/Convolution_2D.test.cpp.html
title: test/convolution/Convolution_2D.test.cpp
---
