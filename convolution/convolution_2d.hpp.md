---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: NTT
  - icon: ':heavy_check_mark:'
    path: math/internal_math.hpp
    title: math/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':heavy_check_mark:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/Convolution_2D.test.cpp
    title: test/convolution/Convolution_2D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/convolution_2d.hpp\"\n\n#include <vector>\n\n\
    #line 2 \"convolution/convolution.hpp\"\n\n#include <algorithm>\n#include <bit>\n\
    #line 6 \"convolution/convolution.hpp\"\n\n#line 2 \"convolution/ntt.hpp\"\n\n\
    #line 4 \"convolution/ntt.hpp\"\n#include <array>\n#line 6 \"convolution/ntt.hpp\"\
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
    \ namespace ebi\n"
  code: "#pragma once\n\n#include <vector>\n\n#include \"../convolution/convolution.hpp\"\
    \n#include \"../modint/base.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint>\n\
    std::vector<std::vector<mint>> convolution_2d(\n    const std::vector<std::vector<mint>>\
    \ &a,\n    const std::vector<std::vector<mint>> &b) {\n    if (a.empty() || b.empty())\
    \ return {};\n    int h1 = (int)a.size(), w1 = (int)a[0].size();\n    int h2 =\
    \ (int)b.size(), w2 = (int)b[0].size();\n    int h = h1 + h2 - 1, w = w1 + w2\
    \ - 1;\n    std::vector<mint> f(h1 * w, 0), g(h2 * w, 0);\n    for (int i = 0;\
    \ i < h1; i++) {\n        std::copy(a[i].begin(), a[i].end(), f.begin() + i *\
    \ w);\n    }\n    for (int i = 0; i < h2; i++) {\n        std::copy(b[i].begin(),\
    \ b[i].end(), g.begin() + i * w);\n    }\n    auto fg = convolution(f, g);\n \
    \   std::vector c(h, std::vector<mint>(w, 0));\n    for (int i = 0; i < h; i++)\
    \ {\n        std::copy(fg.begin() + i * w, fg.begin() + (i + 1) * w, c[i].begin());\n\
    \    }\n    return c;\n}\n\ntemplate <Modint mint>\nstd::vector<std::vector<mint>>\
    \ convolution_2d_naive(\n    const std::vector<std::vector<mint>> &a,\n    const\
    \ std::vector<std::vector<mint>> &b) {\n    int h1 = (int)a.size(), w1 = (int)a[0].size();\n\
    \    int h2 = (int)b.size(), w2 = (int)b[0].size();\n    int h = h1 + h2 - 1,\
    \ w = w1 + w2 - 1;\n    std::vector c(h, std::vector<mint>(w, 0));\n    for (int\
    \ i = 0; i < h1; i++) {\n        for (int j = 0; j < w1; j++) {\n            for\
    \ (int k = 0; k < h2; k++) {\n                for (int l = 0; l < w2; l++) {\n\
    \                    c[i + k][j + l] += a[i][j] * b[k][l];\n                }\n\
    \            }\n        }\n    }\n    return c;\n}\n\n}  // namespace ebi"
  dependsOn:
  - convolution/convolution.hpp
  - convolution/ntt.hpp
  - math/internal_math.hpp
  - modint/base.hpp
  - template/int_alias.hpp
  isVerificationFile: false
  path: convolution/convolution_2d.hpp
  requiredBy: []
  timestamp: '2024-05-23 21:35:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/Convolution_2D.test.cpp
documentation_of: convolution/convolution_2d.hpp
layout: document
title: Convolution 2D
---

## 説明

二次元配列 $a$ と $b$ について

$c[i][j] = \sum_{i = 0}^{H_1} \sum_{j = 0}^{W_1} \sum_{k = 0}^{H_2} \sum_{l = 0}^{W_2} a[i][j] \times b[k][l]$

### convolution_2d(std::vector<std::vector<mint>> a, std::vector<std::vector<mint>> b)

NTT friendlyな素数における畳み込み。
$O((H_1 + H_2)(W_1 + W_2)\log{(H_1 + H_2)(W_1 + W_2)})$

二次元配列 $a$ と $b$ を畳み込み、その配列を返す。

### convolution_2d_naive(std::vector<std::vector<mint>> a, std::vector<std::vector<mint>> b)

愚直に畳み込む。