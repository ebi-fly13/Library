---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/ntt.hpp
    title: NTT Convolution
  - icon: ':x:'
    path: fps/fps.hpp
    title: Formal Power Series
  - icon: ':x:'
    path: fps/multipoint_evaluation.hpp
    title: Multipoint Evaluation
  - icon: ':question:'
    path: math/internal_math.hpp
    title: math/internal_math.hpp
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':question:'
    path: template/debug_template.hpp
    title: template/debug_template.hpp
  - icon: ':question:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
  - icon: ':question:'
    path: template/io.hpp
    title: template/io.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/utility.hpp
    title: template/utility.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/multipoint_evaluation
    links:
    - https://judge.yosupo.jp/problem/multipoint_evaluation
  bundledCode: "#line 1 \"test/polynomial/Multipoint_Evaluation.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/multipoint_evaluation\"\n\n#line 2\
    \ \"fps/multipoint_evaluation.hpp\"\n\n#line 2 \"fps/fps.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <optional>\n#include <vector>\n\n#line 2 \"modint/base.hpp\"\
    \n\n#include <concepts>\n#include <iostream>\n#include <utility>\n\nnamespace\
    \ ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n    a +\
    \ b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 9 \"\
    fps/fps.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint,\n          std::vector<mint>\
    \ (*convolution)(const std::vector<mint> &,\n                                \
    \           const std::vector<mint> &)>\nstruct FormalPowerSeries : std::vector<mint>\
    \ {\n  private:\n    using std::vector<mint>::vector;\n    using std::vector<mint>::vector::operator=;\n\
    \    using FPS = FormalPowerSeries;\n\n  public:\n    FormalPowerSeries(const\
    \ std::vector<mint> &a) {\n        *this = a;\n    }\n\n    FPS operator+(const\
    \ FPS &rhs) const noexcept {\n        return FPS(*this) += rhs;\n    }\n    FPS\
    \ operator-(const FPS &rhs) const noexcept {\n        return FPS(*this) -= rhs;\n\
    \    }\n    FPS operator*(const FPS &rhs) const noexcept {\n        return FPS(*this)\
    \ *= rhs;\n    }\n    FPS operator/(const FPS &rhs) const noexcept {\n       \
    \ return FPS(*this) /= rhs;\n    }\n    FPS operator%(const FPS &rhs) const noexcept\
    \ {\n        return FPS(*this) %= rhs;\n    }\n\n    FPS operator+(const mint\
    \ &rhs) const noexcept {\n        return FPS(*this) += rhs;\n    }\n    FPS operator-(const\
    \ mint &rhs) const noexcept {\n        return FPS(*this) -= rhs;\n    }\n    FPS\
    \ operator*(const mint &rhs) const noexcept {\n        return FPS(*this) *= rhs;\n\
    \    }\n    FPS operator/(const mint &rhs) const noexcept {\n        return FPS(*this)\
    \ /= rhs;\n    }\n\n    FPS &operator+=(const FPS &rhs) noexcept {\n        if\
    \ (this->size() < rhs.size()) this->resize(rhs.size());\n        for (int i =\
    \ 0; i < (int)rhs.size(); ++i) {\n            (*this)[i] += rhs[i];\n        }\n\
    \        return *this;\n    }\n\n    FPS &operator-=(const FPS &rhs) noexcept\
    \ {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n      \
    \  for (int i = 0; i < (int)rhs.size(); ++i) {\n            (*this)[i] -= rhs[i];\n\
    \        }\n        return *this;\n    }\n\n    FPS &operator*=(const FPS &rhs)\
    \ noexcept {\n        *this = convolution(*this, rhs);\n        return *this;\n\
    \    }\n\n    FPS &operator/=(const FPS &rhs) noexcept {\n        int n = deg()\
    \ - 1;\n        int m = rhs.deg() - 1;\n        if (n < m) {\n            *this\
    \ = {};\n            return *this;\n        }\n        *this = (*this).rev() *\
    \ rhs.rev().inv(n - m + 1);\n        (*this).resize(n - m + 1);\n        std::reverse((*this).begin(),\
    \ (*this).end());\n        return *this;\n    }\n\n    FPS &operator%=(const FPS\
    \ &rhs) noexcept {\n        *this -= *this / rhs * rhs;\n        shrink();\n \
    \       return *this;\n    }\n\n    FPS &operator+=(const mint &rhs) noexcept\
    \ {\n        if (this->empty()) this->resize(1);\n        (*this)[0] += rhs;\n\
    \        return *this;\n    }\n\n    FPS &operator-=(const mint &rhs) noexcept\
    \ {\n        if (this->empty()) this->resize(1);\n        (*this)[0] -= rhs;\n\
    \        return *this;\n    }\n\n    FPS &operator*=(const mint &rhs) noexcept\
    \ {\n        for (int i = 0; i < deg(); ++i) {\n            (*this)[i] *= rhs;\n\
    \        }\n        return *this;\n    }\n    FPS &operator/=(const mint &rhs)\
    \ noexcept {\n        mint inv_rhs = rhs.inv();\n        for (int i = 0; i < deg();\
    \ ++i) {\n            (*this)[i] *= inv_rhs;\n        }\n        return *this;\n\
    \    }\n\n    FPS operator>>(int d) const {\n        if (deg() <= d) return {};\n\
    \        FPS f = *this;\n        f.erase(f.begin(), f.begin() + d);\n        return\
    \ f;\n    }\n\n    FPS operator<<(int d) const {\n        FPS f = *this;\n   \
    \     f.insert(f.begin(), d, 0);\n        return f;\n    }\n\n    FPS operator-()\
    \ const {\n        FPS g(this->size());\n        for (int i = 0; i < (int)this->size();\
    \ i++) g[i] = -(*this)[i];\n        return g;\n    }\n\n    FPS pre(int sz) const\
    \ {\n        return FPS(this->begin(), this->begin() + std::min(deg(), sz));\n\
    \    }\n\n    FPS rev() const {\n        auto f = *this;\n        std::reverse(f.begin(),\
    \ f.end());\n        return f;\n    }\n\n    FPS differential() const {\n    \
    \    int n = deg();\n        FPS g(std::max(0, n - 1));\n        for (int i =\
    \ 0; i < n - 1; i++) {\n            g[i] = (*this)[i + 1] * (i + 1);\n       \
    \ }\n        return g;\n    }\n\n    FPS integral() const {\n        int n = deg();\n\
    \        FPS g(n + 1);\n        g[0] = 0;\n        if (n > 0) g[1] = 1;\n    \
    \    auto mod = mint::mod();\n        for (int i = 2; i <= n; i++) g[i] = (-g[mod\
    \ % i]) * (mod / i);\n        for (int i = 0; i < n; i++) g[i + 1] *= (*this)[i];\n\
    \        return g;\n    }\n\n    FPS inv(int d = -1) const {\n        int n =\
    \ 1;\n        if (d < 0) d = deg();\n        FPS g(n);\n        g[0] = (*this)[0].inv();\n\
    \        while (n < d) {\n            n <<= 1;\n            g = (g * 2 - g * g\
    \ * this->pre(n)).pre(n);\n        }\n        g.resize(d);\n        return g;\n\
    \    }\n\n    FPS log(int d = -1) const {\n        assert((*this)[0].val() ==\
    \ 1);\n        if (d < 0) d = deg();\n        return ((*this).differential() *\
    \ (*this).inv(d)).pre(d - 1).integral();\n    }\n\n    FPS exp(int d = -1) const\
    \ {\n        assert((*this)[0].val() == 0);\n        int n = 1;\n        if (d\
    \ < 0) d = deg();\n        FPS g(n);\n        g[0] = 1;\n        while (n < d)\
    \ {\n            n <<= 1;\n            g = (g * (this->pre(n) - g.log(n) + 1)).pre(n);\n\
    \        }\n        g.resize(d);\n        return g;\n    }\n\n    FPS pow(int64_t\
    \ k, int d = -1) const {\n        const int n = deg();\n        if (d < 0) d =\
    \ n;\n        if (k == 0) {\n            FPS f(d);\n            if (d > 0) f[0]\
    \ = 1;\n            return f;\n        }\n        for (int i = 0; i < n; i++)\
    \ {\n            if ((*this)[i] != 0) {\n                mint rev = (*this)[i].inv();\n\
    \                FPS f = (((*this * rev) >> i).log(d) * k).exp(d);\n         \
    \       f *= (*this)[i].pow(k);\n                f = (f << (i * k)).pre(d);\n\
    \                if (f.deg() < d) f.resize(d);\n                return f;\n  \
    \          }\n            if (i + 1 >= (d + k - 1) / k) break;\n        }\n  \
    \      return FPS(d);\n    }\n\n    int deg() const {\n        return (*this).size();\n\
    \    }\n\n    void shrink() {\n        while ((!this->empty()) && this->back()\
    \ == 0) this->pop_back();\n    }\n\n    int count_terms() const {\n        int\
    \ c = 0;\n        for (int i = 0; i < deg(); i++) {\n            if ((*this)[i]\
    \ != 0) c++;\n        }\n        return c;\n    }\n\n    std::optional<FPS> sqrt(int\
    \ d = -1) const;\n\n    static FPS exp_x(int n) {\n        FPS f(n);\n       \
    \ mint fact = 1;\n        for (int i = 1; i < n; i++) fact *= i;\n        f[n\
    \ - 1] = fact.inv();\n        for (int i = n - 1; i >= 0; i--) f[i - 1] = f[i]\
    \ * i;\n        return f;\n    }\n};\n\n}  // namespace ebi\n#line 5 \"fps/multipoint_evaluation.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint,\n          std::vector<mint> (*convolution)(const\
    \ std::vector<mint> &,\n                                           const std::vector<mint>\
    \ &)>\nstd::vector<mint> multipoint_evaluation(\n    const FormalPowerSeries<mint,\
    \ convolution> &f, const std::vector<mint> &p) {\n    using FPS = FormalPowerSeries<mint,\
    \ convolution>;\n    int m = 1;\n    while (m < (int)p.size()) m <<= 1;\n    std::vector<FPS>\
    \ subproduct_tree(2 * m, {1});\n    for (int i = 0; i < (int)p.size(); i++) {\n\
    \        subproduct_tree[i + m] = FPS{-p[i], 1};\n    }\n    for (int i = m -\
    \ 1; i >= 1; i--) {\n        subproduct_tree[i] =\n            subproduct_tree[2\
    \ * i] * subproduct_tree[2 * i + 1];\n    }\n    std::vector<FPS> subremainder_tree(2\
    \ * m);\n    subremainder_tree[1] = f % subproduct_tree[1];\n    for (int i =\
    \ 2; i < m + (int)p.size(); i++) {\n        if (subremainder_tree[i / 2].empty())\
    \ continue;\n        subremainder_tree[i] = subremainder_tree[i / 2] % subproduct_tree[i];\n\
    \    }\n    std::vector<mint> fp(p.size());\n    for (int i = 0; i < (int)p.size();\
    \ i++) {\n        if (subremainder_tree[i + m].empty())\n            fp[i] = 0;\n\
    \        else\n            fp[i] = subremainder_tree[i + m][0];\n    }\n    return\
    \ fp;\n}\n\n}  // namespace ebi\n#line 4 \"test/polynomial/Multipoint_Evaluation.test.cpp\"\
    \n\n#line 2 \"convolution/ntt.hpp\"\n\n#line 4 \"convolution/ntt.hpp\"\n#include\
    \ <array>\n#include <bit>\n#line 8 \"convolution/ntt.hpp\"\n\n#line 2 \"math/internal_math.hpp\"\
    \n\n#line 4 \"math/internal_math.hpp\"\n\nnamespace ebi {\n\nnamespace internal\
    \ {\n\nconstexpr int primitive_root_constexpr(int m) {\n    if (m == 2) return\
    \ 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049) return 3;\n \
    \   if (m == 754974721) return 11;\n    if (m == 998244353) return 3;\n    if\
    \ (m == 880803841) return 26;\n    if (m == 924844033) return 5;\n    return -1;\n\
    }\ntemplate <int m> constexpr int primitive_root = primitive_root_constexpr(m);\n\
    \n}  // namespace internal\n\n}  // namespace ebi\n#line 11 \"convolution/ntt.hpp\"\
    \n\nnamespace ebi {\n\nnamespace internal {\n\ntemplate <Modint mint, int g =\
    \ internal::primitive_root<mint::mod()>>\nstruct ntt_info {\n    static constexpr\
    \ int rank2 =\n        std::countr_zero((unsigned int)(mint::mod() - 1));\n\n\
    \    std::array<mint, rank2 + 1> root, inv_root;\n\n    ntt_info() {\n       \
    \ root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);\n        inv_root[rank2]\
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
    \ - 1);\n    return a;\n}\n\n}  // namespace ebi\n#line 2 \"modint/modint.hpp\"\
    \n\r\n#line 5 \"modint/modint.hpp\"\n\r\n#line 7 \"modint/modint.hpp\"\n\r\nnamespace\
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
    #line 3 \"template/template.hpp\"\n#include <bitset>\n#line 5 \"template/template.hpp\"\
    \n#include <chrono>\n#include <climits>\n#include <cmath>\n#include <complex>\n\
    #include <cstddef>\n#include <cstdint>\n#include <cstdlib>\n#include <cstring>\n\
    #include <functional>\n#include <iomanip>\n#line 16 \"template/template.hpp\"\n\
    #include <limits>\n#include <map>\n#include <memory>\n#include <numbers>\n#include\
    \ <numeric>\n#line 22 \"template/template.hpp\"\n#include <queue>\n#include <random>\n\
    #include <ranges>\n#include <set>\n#include <stack>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n\
    #line 34 \"template/template.hpp\"\n\n#define rep(i, a, n) for (int i = (int)(a);\
    \ i < (int)(n); i++)\n#define rrep(i, a, n) for (int i = ((int)(n)-1); i >= (int)(a);\
    \ i--)\n#define Rep(i, a, n) for (i64 i = (i64)(a); i < (i64)(n); i++)\n#define\
    \ RRep(i, a, n) for (i64 i = ((i64)(n)-i64(1)); i >= (i64)(a); i--)\n#define all(v)\
    \ (v).begin(), (v).end()\n#define rall(v) (v).rbegin(), (v).rend()\n\n#line 2\
    \ \"template/debug_template.hpp\"\n\n#line 4 \"template/debug_template.hpp\"\n\
    \nnamespace ebi {\n\n#ifdef LOCAL\n#define debug(...)                        \
    \                              \\\n    std::cerr << \"LINE: \" << __LINE__ <<\
    \ \"  [\" << #__VA_ARGS__ << \"]:\", \\\n        debug_out(__VA_ARGS__)\n#else\n\
    #define debug(...)\n#endif\n\nvoid debug_out() {\n    std::cerr << std::endl;\n\
    }\n\ntemplate <typename Head, typename... Tail> void debug_out(Head h, Tail...\
    \ t) {\n    std::cerr << \" \" << h;\n    if (sizeof...(t) > 0) std::cerr << \"\
    \ :\";\n    debug_out(t...);\n}\n\n}  // namespace ebi\n#line 2 \"template/int_alias.hpp\"\
    \n\n#line 4 \"template/int_alias.hpp\"\n\nnamespace ebi {\n\nusing std::size_t;\n\
    using i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\n\
    using u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\n}  // namespace ebi\n#line 2 \"template/io.hpp\"\n\
    \n#line 7 \"template/io.hpp\"\n\nnamespace ebi {\n\ntemplate <typename T1, typename\
    \ T2>\nstd::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &pa)\
    \ {\n    return os << pa.first << \" \" << pa.second;\n}\n\ntemplate <typename\
    \ T1, typename T2>\nstd::istream &operator>>(std::istream &os, std::pair<T1, T2>\
    \ &pa) {\n    return os >> pa.first >> pa.second;\n}\n\ntemplate <typename T>\n\
    std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {\n    for\
    \ (std::size_t i = 0; i < vec.size(); i++)\n        os << vec[i] << (i + 1 ==\
    \ vec.size() ? \"\" : \" \");\n    return os;\n}\n\ntemplate <typename T>\nstd::istream\
    \ &operator>>(std::istream &os, std::vector<T> &vec) {\n    for (T &e : vec) std::cin\
    \ >> e;\n    return os;\n}\n\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream\
    \ &os, const std::optional<T> &opt) {\n    if (opt) {\n        os << opt.value();\n\
    \    } else {\n        os << \"invalid value\";\n    }\n    return os;\n}\n\n\
    void fast_io() {\n    std::cout << std::fixed << std::setprecision(15);\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n}\n\n}  // namespace ebi\n#line 2 \"template/utility.hpp\"\
    \n\n#line 5 \"template/utility.hpp\"\n\n#line 7 \"template/utility.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <class T> inline bool chmin(T &a, T b) {\n    if (a > b) {\n\
    \        a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate\
    \ <class T> inline bool chmax(T &a, T b) {\n    if (a < b) {\n        a = b;\n\
    \        return true;\n    }\n    return false;\n}\n\ntemplate <class T> T safe_ceil(T\
    \ a, T b) {\n    if (a % b == 0)\n        return a / b;\n    else if (a >= 0)\n\
    \        return (a / b) + 1;\n    else\n        return -((-a) / b);\n}\n\ntemplate\
    \ <class T> T safe_floor(T a, T b) {\n    if (a % b == 0)\n        return a /\
    \ b;\n    else if (a >= 0)\n        return a / b;\n    else\n        return -((-a)\
    \ / b) - 1;\n}\n\nconstexpr i64 LNF = std::numeric_limits<i64>::max() / 4;\n\n\
    constexpr int INF = std::numeric_limits<int>::max() / 2;\n\nconst std::vector<int>\
    \ dy = {1, 0, -1, 0, 1, 1, -1, -1};\nconst std::vector<int> dx = {0, 1, 0, -1,\
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 9 \"test/polynomial/Multipoint_Evaluation.test.cpp\"\
    \n\nnamespace ebi {\n\nusing mint = modint998244353;\nusing FPS = FormalPowerSeries<mint,\
    \ convolution>;\n\nvoid main_() {\n    int n, m;\n    std::cin >> n >> m;\n  \
    \  FPS f(n);\n    std::cin >> f;\n    std::vector<mint> p(m);\n    std::cin >>\
    \ p;\n    auto fp = multipoint_evaluation<mint, convolution>(f, p);\n    std::cout\
    \ << fp << '\\n';\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n\
    \    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/multipoint_evaluation\"\
    \n\n#include \"../../fps/multipoint_evaluation.hpp\"\n\n#include \"../../convolution/ntt.hpp\"\
    \n#include \"../../fps/fps.hpp\"\n#include \"../../modint/modint.hpp\"\n#include\
    \ \"../../template/template.hpp\"\n\nnamespace ebi {\n\nusing mint = modint998244353;\n\
    using FPS = FormalPowerSeries<mint, convolution>;\n\nvoid main_() {\n    int n,\
    \ m;\n    std::cin >> n >> m;\n    FPS f(n);\n    std::cin >> f;\n    std::vector<mint>\
    \ p(m);\n    std::cin >> p;\n    auto fp = multipoint_evaluation<mint, convolution>(f,\
    \ p);\n    std::cout << fp << '\\n';\n}\n\n}  // namespace ebi\n\nint main() {\n\
    \    ebi::fast_io();\n    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n\
    \        ebi::main_();\n    }\n    return 0;\n}"
  dependsOn:
  - fps/multipoint_evaluation.hpp
  - fps/fps.hpp
  - modint/base.hpp
  - convolution/ntt.hpp
  - math/internal_math.hpp
  - modint/modint.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  isVerificationFile: true
  path: test/polynomial/Multipoint_Evaluation.test.cpp
  requiredBy: []
  timestamp: '2023-10-31 00:17:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/polynomial/Multipoint_Evaluation.test.cpp
layout: document
redirect_from:
- /verify/test/polynomial/Multipoint_Evaluation.test.cpp
- /verify/test/polynomial/Multipoint_Evaluation.test.cpp.html
title: test/polynomial/Multipoint_Evaluation.test.cpp
---
