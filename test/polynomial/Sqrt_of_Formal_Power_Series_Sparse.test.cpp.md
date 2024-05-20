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
    path: fps/fps.hpp
    title: Formal Power Series
  - icon: ':heavy_check_mark:'
    path: fps/fps_sparse.hpp
    title: Formal Power Series (Sparse)
  - icon: ':heavy_check_mark:'
    path: fps/fps_sqrt.hpp
    title: $\sqrt{f}$
  - icon: ':heavy_check_mark:'
    path: math/internal_math.hpp
    title: math/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: math/mod_inv.hpp
    title: Mod Inv
  - icon: ':heavy_check_mark:'
    path: math/mod_sqrt.hpp
    title: Mod Sqrt
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':heavy_check_mark:'
    path: modint/dynamic_modint.hpp
    title: modint/dynamic_modint.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_of_formal_power_series_sparse
    links:
    - https://judge.yosupo.jp/problem/sqrt_of_formal_power_series_sparse
  bundledCode: "#line 1 \"test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/sqrt_of_formal_power_series_sparse\"\
    \n\n#line 2 \"convolution/convolution.hpp\"\n\n#include <algorithm>\n#include\
    \ <bit>\n#include <vector>\n\n#line 2 \"convolution/ntt.hpp\"\n\n#line 4 \"convolution/ntt.hpp\"\
    \n#include <array>\n#line 6 \"convolution/ntt.hpp\"\n#include <cassert>\n#line\
    \ 8 \"convolution/ntt.hpp\"\n\n#line 2 \"math/internal_math.hpp\"\n\n#line 4 \"\
    math/internal_math.hpp\"\n\nnamespace ebi {\n\nnamespace internal {\n\nconstexpr\
    \ int primitive_root_constexpr(int m) {\n    if (m == 2) return 1;\n    if (m\
    \ == 167772161) return 3;\n    if (m == 469762049) return 3;\n    if (m == 754974721)\
    \ return 11;\n    if (m == 998244353) return 3;\n    if (m == 880803841) return\
    \ 26;\n    if (m == 924844033) return 5;\n    return -1;\n}\ntemplate <int m>\
    \ constexpr int primitive_root = primitive_root_constexpr(m);\n\n}  // namespace\
    \ internal\n\n}  // namespace ebi\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n\
    #include <iostream>\n#include <utility>\n\nnamespace ebi {\n\ntemplate <class\
    \ T>\nconcept Modint = requires(T a, T b) {\n    a + b;\n    a - b;\n    a * b;\n\
    \    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long long>());\n\
    \    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
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
    \ *= inv_n;\n    }\n}\n\n}  // namespace internal\n\n}  // namespace ebi\n#line\
    \ 9 \"convolution/convolution.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint>\n\
    std::vector<mint> convolution_naive(const std::vector<mint>& f,\n            \
    \                        const std::vector<mint>& g) {\n    if (f.empty() || g.empty())\
    \ return {};\n    int n = int(f.size()), m = int(g.size());\n    std::vector<mint>\
    \ c(n + m - 1);\n    if (n < m) {\n        for (int j = 0; j < m; j++) {\n   \
    \         for (int i = 0; i < n; i++) {\n                c[i + j] += f[i] * g[j];\n\
    \            }\n        }\n    } else {\n        for (int i = 0; i < n; i++) {\n\
    \            for (int j = 0; j < m; j++) {\n                c[i + j] += f[i] *\
    \ g[j];\n            }\n        }\n    }\n    return c;\n}\n\ntemplate <Modint\
    \ mint>\nstd::vector<mint> convolution(const std::vector<mint>& f,\n         \
    \                     const std::vector<mint>& g) {\n    if (f.empty() || g.empty())\
    \ return {};\n    if (std::min(f.size(), g.size()) < 60) return convolution_naive(f,\
    \ g);\n    int n = std::bit_ceil(f.size() + g.size() - 1);\n    std::vector<mint>\
    \ a(n), b(n);\n    std::copy(f.begin(), f.end(), a.begin());\n    std::copy(g.begin(),\
    \ g.end(), b.begin());\n    internal::butterfly(a);\n    internal::butterfly(b);\n\
    \    for (int i = 0; i < n; i++) {\n        a[i] *= b[i];\n    }\n    internal::butterfly_inv(a);\n\
    \    a.resize(f.size() + g.size() - 1);\n    return a;\n}\n\n}  // namespace ebi\n\
    #line 2 \"fps/fps.hpp\"\n\n#line 5 \"fps/fps.hpp\"\n#include <optional>\n#line\
    \ 7 \"fps/fps.hpp\"\n\n#line 9 \"fps/fps.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <Modint mint,\n          std::vector<mint> (*convolution)(const std::vector<mint>\
    \ &,\n                                           const std::vector<mint> &)>\n\
    struct FormalPowerSeries : std::vector<mint> {\n  private:\n    using std::vector<mint>::vector;\n\
    \    using std::vector<mint>::vector::operator=;\n    using FPS = FormalPowerSeries;\n\
    \n  public:\n    FormalPowerSeries(const std::vector<mint> &a) {\n        *this\
    \ = a;\n    }\n\n    FPS operator+(const FPS &rhs) const noexcept {\n        return\
    \ FPS(*this) += rhs;\n    }\n    FPS operator-(const FPS &rhs) const noexcept\
    \ {\n        return FPS(*this) -= rhs;\n    }\n    FPS operator*(const FPS &rhs)\
    \ const noexcept {\n        return FPS(*this) *= rhs;\n    }\n    FPS operator/(const\
    \ FPS &rhs) const noexcept {\n        return FPS(*this) /= rhs;\n    }\n    FPS\
    \ operator%(const FPS &rhs) const noexcept {\n        return FPS(*this) %= rhs;\n\
    \    }\n\n    FPS operator+(const mint &rhs) const noexcept {\n        return\
    \ FPS(*this) += rhs;\n    }\n    FPS operator-(const mint &rhs) const noexcept\
    \ {\n        return FPS(*this) -= rhs;\n    }\n    FPS operator*(const mint &rhs)\
    \ const noexcept {\n        return FPS(*this) *= rhs;\n    }\n    FPS operator/(const\
    \ mint &rhs) const noexcept {\n        return FPS(*this) /= rhs;\n    }\n\n  \
    \  FPS &operator+=(const FPS &rhs) noexcept {\n        if (this->size() < rhs.size())\
    \ this->resize(rhs.size());\n        for (int i = 0; i < (int)rhs.size(); ++i)\
    \ {\n            (*this)[i] += rhs[i];\n        }\n        return *this;\n   \
    \ }\n\n    FPS &operator-=(const FPS &rhs) noexcept {\n        if (this->size()\
    \ < rhs.size()) this->resize(rhs.size());\n        for (int i = 0; i < (int)rhs.size();\
    \ ++i) {\n            (*this)[i] -= rhs[i];\n        }\n        return *this;\n\
    \    }\n\n    FPS &operator*=(const FPS &rhs) noexcept {\n        *this = convolution(*this,\
    \ rhs);\n        return *this;\n    }\n\n    FPS &operator/=(const FPS &rhs) noexcept\
    \ {\n        int n = deg() - 1;\n        int m = rhs.deg() - 1;\n        if (n\
    \ < m) {\n            *this = {};\n            return *this;\n        }\n    \
    \    *this = (*this).rev() * rhs.rev().inv(n - m + 1);\n        (*this).resize(n\
    \ - m + 1);\n        std::reverse((*this).begin(), (*this).end());\n        return\
    \ *this;\n    }\n\n    FPS &operator%=(const FPS &rhs) noexcept {\n        *this\
    \ -= *this / rhs * rhs;\n        shrink();\n        return *this;\n    }\n\n \
    \   FPS &operator+=(const mint &rhs) noexcept {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] += rhs;\n        return *this;\n    }\n\n    FPS &operator-=(const\
    \ mint &rhs) noexcept {\n        if (this->empty()) this->resize(1);\n       \
    \ (*this)[0] -= rhs;\n        return *this;\n    }\n\n    FPS &operator*=(const\
    \ mint &rhs) noexcept {\n        for (int i = 0; i < deg(); ++i) {\n         \
    \   (*this)[i] *= rhs;\n        }\n        return *this;\n    }\n    FPS &operator/=(const\
    \ mint &rhs) noexcept {\n        mint inv_rhs = rhs.inv();\n        for (int i\
    \ = 0; i < deg(); ++i) {\n            (*this)[i] *= inv_rhs;\n        }\n    \
    \    return *this;\n    }\n\n    FPS operator>>(int d) const {\n        if (deg()\
    \ <= d) return {};\n        FPS f = *this;\n        f.erase(f.begin(), f.begin()\
    \ + d);\n        return f;\n    }\n\n    FPS operator<<(int d) const {\n     \
    \   FPS f = *this;\n        f.insert(f.begin(), d, 0);\n        return f;\n  \
    \  }\n\n    FPS operator-() const {\n        FPS g(this->size());\n        for\
    \ (int i = 0; i < (int)this->size(); i++) g[i] = -(*this)[i];\n        return\
    \ g;\n    }\n\n    FPS pre(int sz) const {\n        return FPS(this->begin(),\
    \ this->begin() + std::min(deg(), sz));\n    }\n\n    FPS rev() const {\n    \
    \    auto f = *this;\n        std::reverse(f.begin(), f.end());\n        return\
    \ f;\n    }\n\n    FPS differential() const {\n        int n = deg();\n      \
    \  FPS g(std::max(0, n - 1));\n        for (int i = 0; i < n - 1; i++) {\n   \
    \         g[i] = (*this)[i + 1] * (i + 1);\n        }\n        return g;\n   \
    \ }\n\n    FPS integral() const {\n        int n = deg();\n        FPS g(n + 1);\n\
    \        g[0] = 0;\n        if (n > 0) g[1] = 1;\n        auto mod = mint::mod();\n\
    \        for (int i = 2; i <= n; i++) g[i] = (-g[mod % i]) * (mod / i);\n    \
    \    for (int i = 0; i < n; i++) g[i + 1] *= (*this)[i];\n        return g;\n\
    \    }\n\n    FPS inv(int d = -1) const {\n        int n = 1;\n        if (d <\
    \ 0) d = deg();\n        FPS g(n);\n        g[0] = (*this)[0].inv();\n       \
    \ while (n < d) {\n            n <<= 1;\n            g = (g * 2 - g * g * this->pre(n)).pre(n);\n\
    \        }\n        g.resize(d);\n        return g;\n    }\n\n    FPS log(int\
    \ d = -1) const {\n        assert((*this)[0].val() == 1);\n        if (d < 0)\
    \ d = deg();\n        return ((*this).differential() * (*this).inv(d)).pre(d -\
    \ 1).integral();\n    }\n\n    FPS exp(int d = -1) const {\n        assert((*this)[0].val()\
    \ == 0);\n        int n = 1;\n        if (d < 0) d = deg();\n        FPS g(n);\n\
    \        g[0] = 1;\n        while (n < d) {\n            n <<= 1;\n          \
    \  g = (g * (this->pre(n) - g.log(n) + 1)).pre(n);\n        }\n        g.resize(d);\n\
    \        return g;\n    }\n\n    FPS pow(int64_t k, int d = -1) const {\n    \
    \    const int n = deg();\n        if (d < 0) d = n;\n        if (k == 0) {\n\
    \            FPS f(d);\n            if (d > 0) f[0] = 1;\n            return f;\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            if ((*this)[i]\
    \ != 0) {\n                mint rev = (*this)[i].inv();\n                FPS f\
    \ = (((*this * rev) >> i).log(d) * k).exp(d);\n                f *= (*this)[i].pow(k);\n\
    \                f = (f << (i * k)).pre(d);\n                if (f.deg() < d)\
    \ f.resize(d);\n                return f;\n            }\n            if (i +\
    \ 1 >= (d + k - 1) / k) break;\n        }\n        return FPS(d);\n    }\n\n \
    \   int deg() const {\n        return (*this).size();\n    }\n\n    void shrink()\
    \ {\n        while ((!this->empty()) && this->back() == 0) this->pop_back();\n\
    \    }\n\n    int count_terms() const {\n        int c = 0;\n        for (int\
    \ i = 0; i < deg(); i++) {\n            if ((*this)[i] != 0) c++;\n        }\n\
    \        return c;\n    }\n\n    std::optional<FPS> sqrt(int d = -1) const;\n\n\
    \    static FPS exp_x(int n) {\n        FPS f(n);\n        mint fact = 1;\n  \
    \      for (int i = 1; i < n; i++) fact *= i;\n        f[n - 1] = fact.inv();\n\
    \        for (int i = n - 1; i >= 0; i--) f[i - 1] = f[i] * i;\n        return\
    \ f;\n    }\n};\n\n}  // namespace ebi\n#line 2 \"fps/fps_sqrt.hpp\"\n\n#line\
    \ 2 \"fps/fps_sparse.hpp\"\n\n#line 5 \"fps/fps_sparse.hpp\"\n\n#line 2 \"math/mod_inv.hpp\"\
    \n\n#line 5 \"math/mod_inv.hpp\"\n\n#line 7 \"math/mod_inv.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <Modint mint> mint inv(int n) {\n    static const int mod\
    \ = mint::mod();\n    static std::vector<mint> dat = {0, 1};\n    assert(0 <=\
    \ n);\n    if (n >= mod) n -= mod;\n    while (int(dat.size()) <= n) {\n     \
    \   int num = dat.size();\n        int q = (mod + num - 1) / num;\n        dat.emplace_back(dat[num\
    \ * q - mod] * mint(q));\n    }\n    return dat[n];\n}\n\n}  // namespace ebi\n\
    #line 8 \"fps/fps_sparse.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint>\n\
    std::vector<mint> mul_sparse(const std::vector<mint> &f,\n                   \
    \          const std::vector<mint> &g) {\n    int n = f.size();\n    int m = g.size();\n\
    \    std::vector<std::pair<int, mint>> cf, cg;\n    for (int i = 0; i < n; i++)\
    \ {\n        if (f[i] != 0) cf.emplace_back(i, f[i]);\n    }\n    for (int i =\
    \ 0; i < m; i++) {\n        if (g[i] != 0) cg.emplace_back(i, g[i]);\n    }\n\
    \    std::vector<mint> h(n + m - 1);\n    for (auto [i, p] : cf) {\n        for\
    \ (auto [j, q] : cg) {\n            h[i + j] += p * q;\n        }\n    }\n   \
    \ return h;\n}\n\ntemplate <Modint mint>\nstd::vector<mint> inv_sparse(const std::vector<mint>\
    \ &f, int d = -1) {\n    assert(f[0] != 0);\n    if (d < 0) {\n        d = f.size();\n\
    \    }\n    std::vector<std::pair<int, mint>> ret;\n    for (int i = 1; i < int(f.size());\
    \ i++) {\n        if (f[i] != 0) {\n            ret.emplace_back(i, f[i]);\n \
    \       }\n    }\n    std::vector<mint> g(d);\n    g[0] = f[0].inv();\n    for\
    \ (int i = 1; i < d; i++) {\n        for (auto [k, p] : ret) {\n            if\
    \ (i - k < 0) break;\n            g[i] -= g[i - k] * p;\n        }\n        g[i]\
    \ *= g[0];\n    }\n    return g;\n}\n\ntemplate <Modint mint>\nstd::vector<mint>\
    \ exp_sparse(const std::vector<mint> &f, int d = -1) {\n    int n = f.size();\n\
    \    if (d < 0) d = n;\n    std::vector<std::pair<int, mint>> ret;\n    for (int\
    \ i = 1; i < n; i++) {\n        if (f[i] != 0) {\n            ret.emplace_back(i\
    \ - 1, f[i] * i);\n        }\n    }\n    std::vector<mint> g(d);\n    g[0] = 1;\n\
    \    for (int i = 0; i < d - 1; i++) {\n        for (auto [k, p] : ret) {\n  \
    \          if (i - k < 0) break;\n            g[i + 1] += g[i - k] * p;\n    \
    \    }\n        g[i + 1] *= inv<mint>(i + 1);\n    }\n    return g;\n}\n\ntemplate\
    \ <Modint mint>\nstd::vector<mint> log_sparse(const std::vector<mint> &f, int\
    \ d = -1) {\n    int n = f.size();\n    if (d < 0) d = n;\n    std::vector<mint>\
    \ df(d);\n    for (int i = 0; i < std::min(d, n - 1); i++) {\n        df[i] =\
    \ f[i + 1] * (i + 1);\n    }\n    auto dg = mul_sparse(df, inv_sparse(f));\n \
    \   dg.resize(d);\n    std::vector<mint> g(d);\n    for (int i = 0; i < d - 1;\
    \ i++) {\n        g[i + 1] = dg[i] * inv<mint>(i + 1);\n    }\n    return g;\n\
    }\n\ntemplate <Modint mint>\nstd::vector<mint> pow_sparse_1(const std::vector<mint>\
    \ &f, long long k,\n                               int d = -1) {\n    int n =\
    \ f.size();\n    assert(n == 0 || f[0] == 1);\n    std::vector<std::pair<int,\
    \ mint>> ret;\n    for (int i = 1; i < n; i++) {\n        if (f[i] != 0) ret.emplace_back(i,\
    \ f[i]);\n    }\n    std::vector<mint> g(d);\n    g[0] = 1;\n    for (int i =\
    \ 0; i < d - 1; i++) {\n        for (const auto &[j, cf] : ret) {\n          \
    \  if (i + 1 - j < 0) break;\n            g[i + 1] +=\n                (mint(k)\
    \ * mint(j) - mint(i - j + 1)) * cf * g[i + 1 - j];\n        }\n        g[i +\
    \ 1] *= inv<mint>(i + 1);\n    }\n    return g;\n}\n\ntemplate <Modint mint>\n\
    std::vector<mint> pow_sparse(const std::vector<mint> &f, long long k,\n      \
    \                       int d = -1) {\n    int n = f.size();\n    if (d < 0) d\
    \ = n;\n    assert(k >= 0);\n    if (k == 0) {\n        std::vector<mint> g(d);\n\
    \        if (d > 0) g[0] = 1;\n        return g;\n    }\n    for (int i = 0; i\
    \ < n; i++) {\n        if (f[i] != 0) {\n            mint rev = f[i].inv();\n\
    \            std::vector<mint> f2(n - i);\n            for (int j = i; j < n;\
    \ j++) {\n                f2[j - i] = f[j] * rev;\n            }\n           \
    \ f2 = pow_sparse_1(f2, k, d);\n            mint fk = f[i].pow(k);\n         \
    \   std::vector<mint> g(d);\n            for (int j = 0; j < int(f2.size()); j++)\
    \ {\n                if (j + i * k >= d) break;\n                g[j + i * k]\
    \ = f2[j] * fk;\n            }\n            return g;\n        }\n        if (i\
    \ >= (d + k - 1) / k) break;\n    }\n    return std::vector<mint>(d);\n}\n\n}\
    \  // namespace ebi\n#line 2 \"math/mod_sqrt.hpp\"\n\n#include <cstdint>\n#line\
    \ 5 \"math/mod_sqrt.hpp\"\n\n#line 2 \"modint/dynamic_modint.hpp\"\n\n#line 4\
    \ \"modint/dynamic_modint.hpp\"\n\n#line 6 \"modint/dynamic_modint.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <int id> struct dynamic_modint {\n  private:\n    using modint\
    \ = dynamic_modint;\n\n  public:\n    static void set_mod(int p) {\n        assert(1\
    \ <= p);\n        m = p;\n    }\n\n    static int mod() {\n        return m;\n\
    \    }\n\n    modint raw(int v) {\n        modint x;\n        x._v = v;\n    \
    \    return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n\n    dynamic_modint(long\
    \ long v) {\n        v %= (long long)umod();\n        if (v < 0) v += (long long)umod();\n\
    \        _v = (unsigned int)v;\n    }\n\n    unsigned int val() const {\n    \
    \    return _v;\n    }\n\n    unsigned int value() const {\n        return val();\n\
    \    }\n\n    modint &operator++() {\n        _v++;\n        if (_v == umod())\
    \ _v = 0;\n        return *this;\n    }\n    modint &operator--() {\n        if\
    \ (_v == 0) _v = umod();\n        _v--;\n        return *this;\n    }\n    modint\
    \ &operator+=(const modint &rhs) {\n        _v += rhs._v;\n        if (_v >= umod())\
    \ _v -= umod();\n        return *this;\n    }\n    modint &operator-=(const modint\
    \ &rhs) {\n        _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n  \
    \      return *this;\n    }\n    modint &operator*=(const modint &rhs) {\n   \
    \     unsigned long long x = _v;\n        x *= rhs._v;\n        _v = (unsigned\
    \ int)(x % (unsigned long long)umod());\n        return *this;\n    }\n    modint\
    \ &operator/=(const modint &rhs) {\n        return *this = *this * rhs.inv();\n\
    \    }\n\n    modint operator+() const {\n        return *this;\n    }\n    modint\
    \ operator-() const {\n        return modint() - *this;\n    }\n\n    modint pow(long\
    \ long n) const {\n        assert(0 <= n);\n        modint x = *this, res = 1;\n\
    \        while (n) {\n            if (n & 1) res *= x;\n            x *= x;\n\
    \            n >>= 1;\n        }\n        return res;\n    }\n    modint inv()\
    \ const {\n        assert(_v);\n        return pow(umod() - 2);\n    }\n\n   \
    \ friend modint operator+(const modint &lhs, const modint &rhs) {\n        return\
    \ modint(lhs) += rhs;\n    }\n    friend modint operator-(const modint &lhs, const\
    \ modint &rhs) {\n        return modint(lhs) -= rhs;\n    }\n    friend modint\
    \ operator*(const modint &lhs, const modint &rhs) {\n        return modint(lhs)\
    \ *= rhs;\n    }\n\n    friend modint operator/(const modint &lhs, const modint\
    \ &rhs) {\n        return modint(lhs) /= rhs;\n    }\n    friend bool operator==(const\
    \ modint &lhs, const modint &rhs) {\n        return lhs.val() == rhs.val();\n\
    \    }\n    friend bool operator!=(const modint &lhs, const modint &rhs) {\n \
    \       return !(lhs == rhs);\n    }\n\n  private:\n    unsigned int _v = 0;\n\
    \    static int m;\n\n    static unsigned int umod() {\n        return m;\n  \
    \  }\n};\n\ntemplate <int id> int dynamic_modint<id>::m = 998244353;\n\n}  //\
    \ namespace ebi\n#line 7 \"math/mod_sqrt.hpp\"\n\nnamespace ebi {\n\nstd::optional<std::int64_t>\
    \ mod_sqrt(const std::int64_t &a,\n                                     const\
    \ std::int64_t &p) {\n    if (a == 0 || a == 1) return a;\n    using mint = dynamic_modint<100>;\n\
    \    mint::set_mod(p);\n    if (mint(a).pow((p - 1) >> 1) != 1) return std::nullopt;\n\
    \    mint b = 1;\n    while (b.pow((p - 1) >> 1) == 1) b += 1;\n    std::int64_t\
    \ m = p - 1, e = 0;\n    while (m % 2 == 0) m >>= 1, e++;\n    mint x = mint(a).pow((m\
    \ - 1) >> 1);\n    mint y = mint(a) * x * x;\n    x *= a;\n    mint z = b.pow(m);\n\
    \    while (y != 1) {\n        std::int64_t j = 0;\n        mint t = y;\n    \
    \    while (t != 1) {\n            j++;\n            t *= t;\n        }\n    \
    \    z = z.pow(1ll << (e - j - 1));\n        x *= z;\n        z *= z;\n      \
    \  y *= z;\n        e = j;\n    }\n    return x.val();\n}\n\n}  // namespace ebi\n\
    #line 7 \"fps/fps_sqrt.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint,\n  \
    \        std::vector<mint> (*convolution)(const std::vector<mint> &,\n       \
    \                                    const std::vector<mint> &)>\nstd::optional<FormalPowerSeries<mint,\
    \ convolution>>\nFormalPowerSeries<mint, convolution>::sqrt(int d) const {\n \
    \   using FPS = FormalPowerSeries<mint, convolution>;\n    if (d < 0) d = deg();\n\
    \    if ((*this)[0] == 0) {\n        for (int i = 1; i < this->deg(); i++) {\n\
    \            if ((*this)[i] != 0) {\n                if (i & 1) return std::nullopt;\n\
    \                if (d - i / 2 <= 0) break;\n                auto opt = ((*this)\
    \ >> i).sqrt(d - i / 2);\n                if (!opt) return std::nullopt;\n   \
    \             auto ret = opt.value() << (i / 2);\n                if ((int)ret.deg()\
    \ < d) ret.resize(d);\n                return ret;\n            }\n        }\n\
    \        return FPS(d, 0);\n    }\n    auto s = mod_sqrt((*this)[0].val(), mint::mod());\n\
    \    if (!s) {\n        return std::nullopt;\n    }\n    if (this->count_terms()\
    \ <= 200) {\n        mint y = s.value();\n        std::vector<mint> sqrt_f =\n\
    \            pow_sparse_1(*this / (*this)[0], mint(2).inv().val(), d);\n     \
    \   FPS g(d);\n        for (int i = 0; i < d; i++) g[i] = sqrt_f[i] * y;\n   \
    \     return g;\n    }\n    int n = 1;\n    FPS g(n);\n    g[0] = s.value();\n\
    \    mint inv_two = mint(2).inv();\n    while (n < d) {\n        n <<= 1;\n  \
    \      g = (g + this->pre(n) * g.inv(n)).pre(n) * inv_two;\n    }\n    g.resize(d);\n\
    \    return g;\n}\n\n}  // namespace ebi\n#line 2 \"modint/modint.hpp\"\n\r\n\
    #line 5 \"modint/modint.hpp\"\n\r\n#line 7 \"modint/modint.hpp\"\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <int m> struct static_modint {\r\n  private:\r\n    using\
    \ modint = static_modint;\r\n\r\n  public:\r\n    static constexpr int mod() {\r\
    \n        return m;\r\n    }\r\n\r\n    static constexpr modint raw(int v) {\r\
    \n        modint x;\r\n        x._v = v;\r\n        return x;\r\n    }\r\n\r\n\
    \    constexpr static_modint() : _v(0) {}\r\n\r\n    constexpr static_modint(long\
    \ long v) {\r\n        v %= (long long)umod();\r\n        if (v < 0) v += (long\
    \ long)umod();\r\n        _v = (unsigned int)v;\r\n    }\r\n\r\n    constexpr\
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
    #line 8 \"test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp\"\n\nusing\
    \ namespace ebi;\n\nusing mint = modint998244353;\nusing FPS = FormalPowerSeries<mint,\
    \ convolution>;\n\nint main() {\n    int n, k;\n    std::cin >> n >> k;\n    FPS\
    \ f(n);\n    for (int i = 0; i < k; i++) {\n        int idx, a;\n        std::cin\
    \ >> idx >> a;\n        f[idx] = a;\n    }\n    auto opt = f.sqrt(n);\n    if\
    \ (!opt) {\n        std::cout << \"-1\\n\";\n        return 0;\n    }\n    auto\
    \ g = opt.value();\n    for (int i = 0; i < n; i++) {\n        std::cout << g[i].val()\
    \ << \" \\n\"[i == n - 1];\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/sqrt_of_formal_power_series_sparse\"\
    \n\n#include \"../../convolution/convolution.hpp\"\n#include \"../../fps/fps.hpp\"\
    \n#include \"../../fps/fps_sqrt.hpp\"\n#include \"../../modint/modint.hpp\"\n\n\
    using namespace ebi;\n\nusing mint = modint998244353;\nusing FPS = FormalPowerSeries<mint,\
    \ convolution>;\n\nint main() {\n    int n, k;\n    std::cin >> n >> k;\n    FPS\
    \ f(n);\n    for (int i = 0; i < k; i++) {\n        int idx, a;\n        std::cin\
    \ >> idx >> a;\n        f[idx] = a;\n    }\n    auto opt = f.sqrt(n);\n    if\
    \ (!opt) {\n        std::cout << \"-1\\n\";\n        return 0;\n    }\n    auto\
    \ g = opt.value();\n    for (int i = 0; i < n; i++) {\n        std::cout << g[i].val()\
    \ << \" \\n\"[i == n - 1];\n    }\n}"
  dependsOn:
  - convolution/convolution.hpp
  - convolution/ntt.hpp
  - math/internal_math.hpp
  - modint/base.hpp
  - fps/fps.hpp
  - fps/fps_sqrt.hpp
  - fps/fps_sparse.hpp
  - math/mod_inv.hpp
  - math/mod_sqrt.hpp
  - modint/dynamic_modint.hpp
  - modint/modint.hpp
  isVerificationFile: true
  path: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  requiredBy: []
  timestamp: '2024-05-20 22:50:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
layout: document
redirect_from:
- /verify/test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
- /verify/test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp.html
title: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
---
