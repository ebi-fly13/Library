---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/internal_math.hpp
    title: math/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/arbitrary_ntt.hpp
    title: Arbitrary Convolution
  - icon: ':heavy_check_mark:'
    path: convolution/convolution_mod_2_64.hpp
    title: Convolution $\pmod{2^{64}}$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/Convolution.test.cpp
    title: test/convolution/Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Convolution_Mod_1000000007.test.cpp
    title: test/convolution/Convolution_Mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/Convolution_Mod_2_64.test.cpp
    title: test/convolution/Convolution_Mod_2_64.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Berunoulli_Number.test.cpp
    title: test/math/Berunoulli_Number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Catalan_Convolution.test.cpp
    title: test/math/Catalan_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
    title: test/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Partition_Function_FPS.test.cpp
    title: test/math/Partition_Function_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Partition_Function_Pentagonal.test.cpp
    title: test/math/Partition_Function_Pentagonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Stirling_Number_of_the_First_Kind.test.cpp
    title: test/math/Stirling_Number_of_the_First_Kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Stirling_Number_of_the_Second_Kind.test.cpp
    title: test/math/Stirling_Number_of_the_Second_Kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/Sum_of_Powers_Iota.test.cpp
    title: test/math/Sum_of_Powers_Iota.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/sharp_p_subset_sum.test.cpp
    title: test/math/sharp_p_subset_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Composition_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Division_of_Polynomials.test.cpp
    title: test/polynomial/Division_of_Polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Exp_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Exp_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Inv_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Inv_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Log_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Log_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Multipoint_Evaluation.test.cpp
    title: test/polynomial/Multipoint_Evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Polynomial_Interpolation.test.cpp
    title: test/polynomial/Polynomial_Interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Polynomial_Taylor_Shift.test.cpp
    title: test/polynomial/Polynomial_Taylor_Shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Pow_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Pow_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Product_of_Polynomial_Sequence.test.cpp
    title: test/polynomial/Product_of_Polynomial_Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Frequency_Table_of_Tree_Distance_MODE_0.test.cpp
    title: test/tree/Frequency_Table_of_Tree_Distance_MODE_0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp
    title: test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/Frequency_Table_of_Tree_Distance_MODE_2.test.cpp
    title: test/tree/Frequency_Table_of_Tree_Distance_MODE_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1145.test.cpp
    title: test/yuki/yuki_1145.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1302.test.cpp
    title: test/yuki/yuki_1302.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/yuki_1796.test.cpp
    title: test/yuki/yuki_1796.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \   assert(n == (int)std::bit_ceil(a.size()));\n\n    // bit reverse\n    for\
    \ (int i = 0, j = 1; j < n - 1; j++) {\n        for (int k = n >> 1; k > (i ^=\
    \ k); k >>= 1)\n            ;\n        if (j < i) {\n            std::swap(a[i],\
    \ a[j]);\n        }\n    }\n\n    for (int bit = 0; bit < bit_size; bit++) {\n\
    \        for (int i = 0; i < n / (1 << (bit + 1)); i++) {\n            mint zeta1\
    \ = 1;\n            mint zeta2 = info.root[1];\n            for (int j = 0; j\
    \ < (1 << bit); j++) {\n                int idx = i * (1 << (bit + 1)) + j;\n\
    \                int jdx = idx + (1 << bit);\n                mint p1 = a[idx];\n\
    \                mint p2 = a[jdx];\n                a[idx] = p1 + zeta1 * p2;\n\
    \                a[jdx] = p1 + zeta2 * p2;\n                zeta1 *= info.root[bit\
    \ + 1];\n                zeta2 *= info.root[bit + 1];\n            }\n       \
    \ }\n    }\n}\n\ntemplate <Modint mint> void butterfly_inv(std::vector<mint>&\
    \ a) {\n    static const ntt_info<mint> info;\n    int n = int(a.size());\n  \
    \  int bit_size = std::countr_zero(a.size());\n    assert(n == (int)std::bit_ceil(a.size()));\n\
    \n    // bit reverse\n    for (int i = 0, j = 1; j < n - 1; j++) {\n        for\
    \ (int k = n >> 1; k > (i ^= k); k >>= 1)\n            ;\n        if (j < i) {\n\
    \            std::swap(a[i], a[j]);\n        }\n    }\n\n    for (int bit = 0;\
    \ bit < bit_size; bit++) {\n        for (int i = 0; i < n / (1 << (bit + 1));\
    \ i++) {\n            mint zeta1 = 1;\n            mint zeta2 = info.inv_root[1];\n\
    \            for (int j = 0; j < (1 << bit); j++) {\n                int idx =\
    \ i * (1 << (bit + 1)) + j;\n                int jdx = idx + (1 << bit);\n   \
    \             mint p1 = a[idx];\n                mint p2 = a[jdx];\n         \
    \       a[idx] = p1 + zeta1 * p2;\n                a[jdx] = p1 + zeta2 * p2;\n\
    \                zeta1 *= info.inv_root[bit + 1];\n                zeta2 *= info.inv_root[bit\
    \ + 1];\n            }\n        }\n    }\n    mint inv_n = mint(n).inv();\n  \
    \  for (int i = 0; i < n; i++) {\n        a[i] *= inv_n;\n    }\n}\n\n}  // namespace\
    \ internal\n\ntemplate <Modint mint>\nstd::vector<mint> convolution_naive(const\
    \ std::vector<mint>& f,\n                                    const std::vector<mint>&\
    \ g) {\n    if (f.empty() || g.empty()) return {};\n    int n = int(f.size()),\
    \ m = int(g.size());\n    std::vector<mint> c(n + m - 1);\n    if (n < m) {\n\
    \        for (int j = 0; j < m; j++) {\n            for (int i = 0; i < n; i++)\
    \ {\n                c[i + j] += f[i] * g[j];\n            }\n        }\n    }\
    \ else {\n        for (int i = 0; i < n; i++) {\n            for (int j = 0; j\
    \ < m; j++) {\n                c[i + j] += f[i] * g[j];\n            }\n     \
    \   }\n    }\n    return c;\n}\n\ntemplate <Modint mint>\nstd::vector<mint> convolution(const\
    \ std::vector<mint>& f,\n                              const std::vector<mint>&\
    \ g) {\n    if (f.empty() || g.empty()) return {};\n    if (std::min(f.size(),\
    \ g.size()) < 60) return convolution_naive(f, g);\n    int n = std::bit_ceil(f.size()\
    \ + g.size() - 1);\n    std::vector<mint> a(n), b(n);\n    std::copy(f.begin(),\
    \ f.end(), a.begin());\n    std::copy(g.begin(), g.end(), b.begin());\n    internal::butterfly(a);\n\
    \    internal::butterfly(b);\n    for (int i = 0; i < n; i++) {\n        a[i]\
    \ *= b[i];\n    }\n    internal::butterfly_inv(a);\n    a.resize(f.size() + g.size()\
    \ - 1);\n    return a;\n}\n\n}  // namespace ebi\n"
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
    \    assert(n == (int)std::bit_ceil(a.size()));\n\n    // bit reverse\n    for\
    \ (int i = 0, j = 1; j < n - 1; j++) {\n        for (int k = n >> 1; k > (i ^=\
    \ k); k >>= 1)\n            ;\n        if (j < i) {\n            std::swap(a[i],\
    \ a[j]);\n        }\n    }\n\n    for (int bit = 0; bit < bit_size; bit++) {\n\
    \        for (int i = 0; i < n / (1 << (bit + 1)); i++) {\n            mint zeta1\
    \ = 1;\n            mint zeta2 = info.root[1];\n            for (int j = 0; j\
    \ < (1 << bit); j++) {\n                int idx = i * (1 << (bit + 1)) + j;\n\
    \                int jdx = idx + (1 << bit);\n                mint p1 = a[idx];\n\
    \                mint p2 = a[jdx];\n                a[idx] = p1 + zeta1 * p2;\n\
    \                a[jdx] = p1 + zeta2 * p2;\n                zeta1 *= info.root[bit\
    \ + 1];\n                zeta2 *= info.root[bit + 1];\n            }\n       \
    \ }\n    }\n}\n\ntemplate <Modint mint> void butterfly_inv(std::vector<mint>&\
    \ a) {\n    static const ntt_info<mint> info;\n    int n = int(a.size());\n  \
    \  int bit_size = std::countr_zero(a.size());\n    assert(n == (int)std::bit_ceil(a.size()));\n\
    \n    // bit reverse\n    for (int i = 0, j = 1; j < n - 1; j++) {\n        for\
    \ (int k = n >> 1; k > (i ^= k); k >>= 1)\n            ;\n        if (j < i) {\n\
    \            std::swap(a[i], a[j]);\n        }\n    }\n\n    for (int bit = 0;\
    \ bit < bit_size; bit++) {\n        for (int i = 0; i < n / (1 << (bit + 1));\
    \ i++) {\n            mint zeta1 = 1;\n            mint zeta2 = info.inv_root[1];\n\
    \            for (int j = 0; j < (1 << bit); j++) {\n                int idx =\
    \ i * (1 << (bit + 1)) + j;\n                int jdx = idx + (1 << bit);\n   \
    \             mint p1 = a[idx];\n                mint p2 = a[jdx];\n         \
    \       a[idx] = p1 + zeta1 * p2;\n                a[jdx] = p1 + zeta2 * p2;\n\
    \                zeta1 *= info.inv_root[bit + 1];\n                zeta2 *= info.inv_root[bit\
    \ + 1];\n            }\n        }\n    }\n    mint inv_n = mint(n).inv();\n  \
    \  for (int i = 0; i < n; i++) {\n        a[i] *= inv_n;\n    }\n}\n\n}  // namespace\
    \ internal\n\ntemplate <Modint mint>\nstd::vector<mint> convolution_naive(const\
    \ std::vector<mint>& f,\n                                    const std::vector<mint>&\
    \ g) {\n    if (f.empty() || g.empty()) return {};\n    int n = int(f.size()),\
    \ m = int(g.size());\n    std::vector<mint> c(n + m - 1);\n    if (n < m) {\n\
    \        for (int j = 0; j < m; j++) {\n            for (int i = 0; i < n; i++)\
    \ {\n                c[i + j] += f[i] * g[j];\n            }\n        }\n    }\
    \ else {\n        for (int i = 0; i < n; i++) {\n            for (int j = 0; j\
    \ < m; j++) {\n                c[i + j] += f[i] * g[j];\n            }\n     \
    \   }\n    }\n    return c;\n}\n\ntemplate <Modint mint>\nstd::vector<mint> convolution(const\
    \ std::vector<mint>& f,\n                              const std::vector<mint>&\
    \ g) {\n    if (f.empty() || g.empty()) return {};\n    if (std::min(f.size(),\
    \ g.size()) < 60) return convolution_naive(f, g);\n    int n = std::bit_ceil(f.size()\
    \ + g.size() - 1);\n    std::vector<mint> a(n), b(n);\n    std::copy(f.begin(),\
    \ f.end(), a.begin());\n    std::copy(g.begin(), g.end(), b.begin());\n    internal::butterfly(a);\n\
    \    internal::butterfly(b);\n    for (int i = 0; i < n; i++) {\n        a[i]\
    \ *= b[i];\n    }\n    internal::butterfly_inv(a);\n    a.resize(f.size() + g.size()\
    \ - 1);\n    return a;\n}\n\n}  // namespace ebi"
  dependsOn:
  - math/internal_math.hpp
  - modint/base.hpp
  isVerificationFile: false
  path: convolution/ntt.hpp
  requiredBy:
  - convolution/convolution_mod_2_64.hpp
  - convolution/arbitrary_ntt.hpp
  timestamp: '2023-10-31 00:17:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/Convolution_Mod_1000000007.test.cpp
  - test/convolution/Convolution.test.cpp
  - test/convolution/Convolution_Mod_2_64.test.cpp
  - test/yuki/yuki_1302.test.cpp
  - test/yuki/yuki_1796.test.cpp
  - test/yuki/yuki_1145.test.cpp
  - test/math/Catalan_Convolution.test.cpp
  - test/math/Partition_Function_FPS.test.cpp
  - test/math/Berunoulli_Number.test.cpp
  - test/math/Partition_Function_Pentagonal.test.cpp
  - test/math/Sum_of_Powers_Iota.test.cpp
  - test/math/Stirling_Number_of_the_First_Kind.test.cpp
  - test/math/sharp_p_subset_sum.test.cpp
  - test/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  - test/math/Stirling_Number_of_the_Second_Kind.test.cpp
  - test/polynomial/Pow_of_Formal_Power_Series.test.cpp
  - test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - test/polynomial/Polynomial_Taylor_Shift.test.cpp
  - test/polynomial/Inv_of_Formal_Power_Series.test.cpp
  - test/polynomial/Multipoint_Evaluation.test.cpp
  - test/polynomial/Polynomial_Interpolation.test.cpp
  - test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  - test/polynomial/Compositional_Inverse_of_Formal_Power_Series.test.cpp
  - test/polynomial/Log_of_Formal_Power_Series.test.cpp
  - test/polynomial/Product_of_Polynomial_Sequence.test.cpp
  - test/polynomial/Division_of_Polynomials.test.cpp
  - test/polynomial/Composition_of_Formal_Power_Series.test.cpp
  - test/polynomial/Exp_of_Formal_Power_Series.test.cpp
  - test/tree/Frequency_Table_of_Tree_Distance_MODE_2.test.cpp
  - test/tree/Frequency_Table_of_Tree_Distance_MODE_0.test.cpp
  - test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp
documentation_of: convolution/ntt.hpp
layout: document
title: NTT Convolution
---

## 説明

NTT friendlyな素数における $O(N\log N)$ 時間での畳み込み。

## ntt_info

NTTをするために必要なデータを格納している。

## butterfly(std::vector<mint> &a)

配列 $a$ をNTTする。
$a$ の配列の大きさは $2$ 冪でのみ動作する。

## butterfly_inv(std::vector<mint> &a)

配列 $a$ をinverse NTTする。
$a$ の配列の大きさは $2$ 冪でのみ動作する。
inverse NTT後に割る $N$ を行う。

## convolution(std::vector<mint> a, std::vector<mint> b)

$a$ と $b$ を畳み込み、その配列を返す。 $O(N\log N)$