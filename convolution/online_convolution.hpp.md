---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/online_convolution.hpp\"\n\n#include <atcoder/convolution>\n\
    #include <atcoder/modint>\n#include <bit>\n#include <vector>\n\n#line 2 \"template/int_alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace ebi {\n\nusing std::size_t;\nusing i8 = std::int8_t;\n\
    using u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing u16 = std::uint16_t;\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    \n}  // namespace ebi\n#line 9 \"convolution/online_convolution.hpp\"\n\nnamespace\
    \ ebi {\n\nstruct online_convolution {\n  private:\n    using mint = atcoder::modint998244353;\n\
    \n  public:\n    online_convolution() = default;\n\n    mint add(int idx, mint\
    \ ai, mint bi) {\n        assert(p == idx);\n        a.emplace_back(ai);\n   \
    \     b.emplace_back(bi);\n        int z = std::countr_zero(u32(p + 2)), w = 1\
    \ << z;\n        if (p + 2 == w) {\n            auto a0 = a;\n            a0.resize(2\
    \ * w);\n            atcoder::internal::butterfly(a0);\n            fa.emplace_back(a0.begin(),\
    \ a0.begin() + w);\n            auto b0 = b;\n            b0.resize(2 * w);\n\
    \            atcoder::internal::butterfly(b0);\n            fb.emplace_back(b0.begin(),\
    \ b0.begin() + w);\n            for (int i = 0; i < 2 * w; i++) a0[i] *= b0[i];\n\
    \            atcoder::internal::butterfly_inv(a0);\n            mint inv_len =\
    \ mint(2 * w).inv();\n            c.resize(2 * p + 2);\n            for (int i\
    \ = 0; i < p + 1; i++) c[p + i] += a0[p + i] * inv_len;\n        } else {\n  \
    \          std::vector<mint> a0 = {a.end() - w, a.end()};\n            a0.resize(2\
    \ * w);\n            atcoder::internal::butterfly(a0);\n            std::vector<mint>\
    \ b0 = {b.end() - w, b.end()};\n            b0.resize(2 * w);\n            atcoder::internal::butterfly(b0);\n\
    \            for (int i = 0; i < 2 * w; i++) {\n                a0[i] = a0[i]\
    \ * fb[z][i] + fa[z][i] * b0[i];\n            }\n            atcoder::internal::butterfly_inv(a0);\n\
    \            mint inv_len = mint(2 * w).inv();\n            for (int i = 0; i\
    \ < w; i++) c[p + i] += a0[w - 1 + i] * inv_len;\n        }\n        return c[p++];\n\
    \    }\n\n    mint operator[](int i) const {\n        assert(0 <= i && i < p);\n\
    \        return c[i];\n    }\n\n  private:\n    int p = 0;\n    std::vector<mint>\
    \ a, b, c;\n    std::vector<std::vector<mint>> fa, fb;\n};\n\n}  // namespace\
    \ ebi\n"
  code: "#pragma once\n\n#include <atcoder/convolution>\n#include <atcoder/modint>\n\
    #include <bit>\n#include <vector>\n\n#include \"../template/int_alias.hpp\"\n\n\
    namespace ebi {\n\nstruct online_convolution {\n  private:\n    using mint = atcoder::modint998244353;\n\
    \n  public:\n    online_convolution() = default;\n\n    mint add(int idx, mint\
    \ ai, mint bi) {\n        assert(p == idx);\n        a.emplace_back(ai);\n   \
    \     b.emplace_back(bi);\n        int z = std::countr_zero(u32(p + 2)), w = 1\
    \ << z;\n        if (p + 2 == w) {\n            auto a0 = a;\n            a0.resize(2\
    \ * w);\n            atcoder::internal::butterfly(a0);\n            fa.emplace_back(a0.begin(),\
    \ a0.begin() + w);\n            auto b0 = b;\n            b0.resize(2 * w);\n\
    \            atcoder::internal::butterfly(b0);\n            fb.emplace_back(b0.begin(),\
    \ b0.begin() + w);\n            for (int i = 0; i < 2 * w; i++) a0[i] *= b0[i];\n\
    \            atcoder::internal::butterfly_inv(a0);\n            mint inv_len =\
    \ mint(2 * w).inv();\n            c.resize(2 * p + 2);\n            for (int i\
    \ = 0; i < p + 1; i++) c[p + i] += a0[p + i] * inv_len;\n        } else {\n  \
    \          std::vector<mint> a0 = {a.end() - w, a.end()};\n            a0.resize(2\
    \ * w);\n            atcoder::internal::butterfly(a0);\n            std::vector<mint>\
    \ b0 = {b.end() - w, b.end()};\n            b0.resize(2 * w);\n            atcoder::internal::butterfly(b0);\n\
    \            for (int i = 0; i < 2 * w; i++) {\n                a0[i] = a0[i]\
    \ * fb[z][i] + fa[z][i] * b0[i];\n            }\n            atcoder::internal::butterfly_inv(a0);\n\
    \            mint inv_len = mint(2 * w).inv();\n            for (int i = 0; i\
    \ < w; i++) c[p + i] += a0[w - 1 + i] * inv_len;\n        }\n        return c[p++];\n\
    \    }\n\n    mint operator[](int i) const {\n        assert(0 <= i && i < p);\n\
    \        return c[i];\n    }\n\n  private:\n    int p = 0;\n    std::vector<mint>\
    \ a, b, c;\n    std::vector<std::vector<mint>> fa, fb;\n};\n\n}  // namespace\
    \ ebi"
  dependsOn:
  - template/int_alias.hpp
  isVerificationFile: false
  path: convolution/online_convolution.hpp
  requiredBy: []
  timestamp: '2023-10-26 02:38:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/online_convolution.hpp
layout: document
title: Online Convolution
---

## 説明

$c = a \times b$ とする。 $a_i, b_i$ を与えて、 $c_i$ を返すという操作を $i = 0$ からオンラインで処理する。最終的な $c$ の長さを $N$ とすると、計算量は $O(N(\log N)^2)$ となる。

ACLに依存しているため使用するときは注意。
