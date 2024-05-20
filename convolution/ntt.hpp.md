---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/internal_math.hpp
    title: math/internal_math.hpp
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/ntt.hpp\"\n\n#include <algorithm>\n#include\
    \ <array>\n#include <bit>\n#include <cassert>\n#include <vector>\n\n#line 2 \"\
    math/internal_math.hpp\"\n\n#line 4 \"math/internal_math.hpp\"\n\nnamespace ebi\
    \ {\n\nnamespace internal {\n\nconstexpr int primitive_root_constexpr(int m) {\n\
    \    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    if (m == 880803841) return 26;\n    if (m == 924844033) return 5;\n\
    \    return -1;\n}\ntemplate <int m> constexpr int primitive_root = primitive_root_constexpr(m);\n\
    \n}  // namespace internal\n\n}  // namespace ebi\n#line 2 \"modint/base.hpp\"\
    \n\n#include <concepts>\n#include <iostream>\n#include <utility>\n\nnamespace\
    \ ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n    a +\
    \ b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 11 \"\
    convolution/ntt.hpp\"\n\nnamespace ebi {\n\nnamespace internal {\n\ntemplate <Modint\
    \ mint, int g = internal::primitive_root<mint::mod()>>\nstruct ntt_info {\n  \
    \  static constexpr int rank2 =\n        std::countr_zero((unsigned int)(mint::mod()\
    \ - 1));\n\n    std::array<mint, rank2 + 1> root, inv_root;\n\n    ntt_info()\
    \ {\n        root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);\n        inv_root[rank2]\
    \ = root[rank2].inv();\n        for (int i = rank2 - 1; i >= 0; i--) {\n     \
    \       root[i] = root[i + 1] * root[i + 1];\n            inv_root[i] = inv_root[i\
    \ + 1] * inv_root[i + 1];\n        }\n    }\n};\n\ntemplate <Modint mint> void\
    \ butterfly(std::vector<mint>& a) {\n    static const ntt_info<mint> info;\n \
    \   int n = int(a.size());\n    int bit_size = std::countr_zero(a.size());\n \
    \   assert(n == 1 << bit_size);\n    for (int bit = bit_size - 1; bit >= 0; bit--)\
    \ {\n        int m = 1 << bit;\n        for (int i = 0; i < n; i += 2 * m) {\n\
    \            mint w = 1;\n            for (int j = 0; j < m; j++) {\n        \
    \        mint p1 = a[i + j];\n                mint p2 = a[i + j + m];\n      \
    \          a[i + j] = p1 + p2;\n                a[i + j + m] = (p1 - p2) * w;\n\
    \                w *= info.root[bit + 1];\n            }\n        }\n    }\n}\n\
    \ntemplate <Modint mint> void butterfly_inv(std::vector<mint>& a) {\n    static\
    \ const ntt_info<mint> info;\n    int n = int(a.size());\n    int bit_size = std::countr_zero(a.size());\n\
    \    assert(n == 1 << bit_size);\n\n    for (int bit = 0; bit < bit_size; bit++)\
    \ {\n        for (int i = 0; i < n / (1 << (bit + 1)); i++) {\n            mint\
    \ w = 1;\n            for (int j = 0; j < (1 << bit); j++) {\n               \
    \ int idx = i * (1 << (bit + 1)) + j;\n                int jdx = idx + (1 << bit);\n\
    \                mint p1 = a[idx];\n                mint p2 = a[jdx];\n      \
    \          a[idx] = p1 + w * p2;\n                a[jdx] = p1 - w * p2;\n    \
    \            w *= info.inv_root[bit + 1];\n            }\n        }\n    }\n \
    \   mint inv_n = mint(n).inv();\n    for (int i = 0; i < n; i++) {\n        a[i]\
    \ *= inv_n;\n    }\n}\n\n}  // namespace internal\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <array>\n#include <bit>\n\
    #include <cassert>\n#include <vector>\n\n#include \"../math/internal_math.hpp\"\
    \n#include \"../modint/base.hpp\"\n\nnamespace ebi {\n\nnamespace internal {\n\
    \ntemplate <Modint mint, int g = internal::primitive_root<mint::mod()>>\nstruct\
    \ ntt_info {\n    static constexpr int rank2 =\n        std::countr_zero((unsigned\
    \ int)(mint::mod() - 1));\n\n    std::array<mint, rank2 + 1> root, inv_root;\n\
    \n    ntt_info() {\n        root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);\n\
    \        inv_root[rank2] = root[rank2].inv();\n        for (int i = rank2 - 1;\
    \ i >= 0; i--) {\n            root[i] = root[i + 1] * root[i + 1];\n         \
    \   inv_root[i] = inv_root[i + 1] * inv_root[i + 1];\n        }\n    }\n};\n\n\
    template <Modint mint> void butterfly(std::vector<mint>& a) {\n    static const\
    \ ntt_info<mint> info;\n    int n = int(a.size());\n    int bit_size = std::countr_zero(a.size());\n\
    \    assert(n == 1 << bit_size);\n    for (int bit = bit_size - 1; bit >= 0; bit--)\
    \ {\n        int m = 1 << bit;\n        for (int i = 0; i < n; i += 2 * m) {\n\
    \            mint w = 1;\n            for (int j = 0; j < m; j++) {\n        \
    \        mint p1 = a[i + j];\n                mint p2 = a[i + j + m];\n      \
    \          a[i + j] = p1 + p2;\n                a[i + j + m] = (p1 - p2) * w;\n\
    \                w *= info.root[bit + 1];\n            }\n        }\n    }\n}\n\
    \ntemplate <Modint mint> void butterfly_inv(std::vector<mint>& a) {\n    static\
    \ const ntt_info<mint> info;\n    int n = int(a.size());\n    int bit_size = std::countr_zero(a.size());\n\
    \    assert(n == 1 << bit_size);\n\n    for (int bit = 0; bit < bit_size; bit++)\
    \ {\n        for (int i = 0; i < n / (1 << (bit + 1)); i++) {\n            mint\
    \ w = 1;\n            for (int j = 0; j < (1 << bit); j++) {\n               \
    \ int idx = i * (1 << (bit + 1)) + j;\n                int jdx = idx + (1 << bit);\n\
    \                mint p1 = a[idx];\n                mint p2 = a[jdx];\n      \
    \          a[idx] = p1 + w * p2;\n                a[jdx] = p1 - w * p2;\n    \
    \            w *= info.inv_root[bit + 1];\n            }\n        }\n    }\n \
    \   mint inv_n = mint(n).inv();\n    for (int i = 0; i < n; i++) {\n        a[i]\
    \ *= inv_n;\n    }\n}\n\n}  // namespace internal\n\n}  // namespace ebi"
  dependsOn:
  - math/internal_math.hpp
  - modint/base.hpp
  isVerificationFile: false
  path: convolution/ntt.hpp
  requiredBy: []
  timestamp: '2024-05-20 22:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/ntt.hpp
layout: document
title: NTT
---

## 説明

### ntt_info

NTTをするために必要なデータを格納している。

### butterfly(std::vector<mint> &a)

配列 $a$ をNTTする。
$a$ の配列の大きさは $2$ 冪でのみ動作する。

### butterfly_inv(std::vector<mint> &a)

配列 $a$ をinverse NTTする。
$a$ の配列の大きさは $2$ 冪でのみ動作する。
inverse NTT後に割る $N$ を行う。