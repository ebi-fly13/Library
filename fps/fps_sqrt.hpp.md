---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/fps.hpp
    title: Formal Power Series
  - icon: ':heavy_check_mark:'
    path: fps/fps_sparse.hpp
    title: Formal Power Series (Sparse)
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
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
    title: test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
    title: test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/fps_sqrt.hpp\"\n\n#line 2 \"fps/fps.hpp\"\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <optional>\n#include <vector>\n\n\
    #line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#include <iostream>\n#include\
    \ <utility>\n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint = requires(T\
    \ a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n  \
    \  a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n};\n\ntemplate\
    \ <Modint mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long\
    \ long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <Modint mint>\n\
    std::ostream &operator<<(std::ostream &os, const mint &a) {\n    return os <<\
    \ a.val();\n}\n\n}  // namespace ebi\n#line 9 \"fps/fps.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <Modint mint> struct FormalPowerSeries : std::vector<mint> {\n\
    \  private:\n    using std::vector<mint>::vector;\n    using std::vector<mint>::vector::operator=;\n\
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
    \        }\n        return *this;\n    }\n\n    FPS &operator*=(const FPS &);\n\
    \n    FPS &operator/=(const FPS &rhs) noexcept {\n        int n = deg() - 1;\n\
    \        int m = rhs.deg() - 1;\n        if (n < m) {\n            *this = {};\n\
    \            return *this;\n        }\n        *this = (*this).rev() * rhs.rev().inv(n\
    \ - m + 1);\n        (*this).resize(n - m + 1);\n        std::reverse((*this).begin(),\
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
    \        }\n        g.resize(d);\n        return g;\n    }\n\n    FPS pow(long\
    \ long k, int d = -1) const {\n        assert(k >= 0);\n        int n = deg();\n\
    \        if (d < 0) d = n;\n        if (k == 0) {\n            FPS f(d);\n   \
    \         if (d > 0) f[0] = 1;\n            return f;\n        }\n        int\
    \ low = d;\n        for (int i = n - 1; i >= 0; i--)\n            if ((*this)[i]\
    \ != 0) low = i;\n        if (low >= (d + k - 1) / k) return FPS(d, 0);\n    \
    \    int offset = k * low;\n        mint c = (*this)[low];\n        FPS g(d -\
    \ offset);\n        for (int i = 0; i < std::min(n - low, d - offset); i++) {\n\
    \            g[i] = (*this)[i + low];\n        }\n        g /= c;\n        g =\
    \ g.pow_1(k);\n        return (g << offset) * c.pow(k);\n    }\n\n    FPS pow_1(mint\
    \ k, int d = -1) const {\n        assert((*this)[0] == 1);\n        return ((*this).log(d)\
    \ * k).exp(d);\n    }\n\n    FPS pow_newton(long long k, int d = -1) const {\n\
    \        assert(k >= 0);\n        const int n = deg();\n        if (d < 0) d =\
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
    \ * i;\n        return f;\n    }\n\n    void fft();\n    void ifft();\n};\n\n\
    }  // namespace ebi\n#line 2 \"fps/fps_sparse.hpp\"\n\n#line 5 \"fps/fps_sparse.hpp\"\
    \n\n#line 2 \"math/mod_inv.hpp\"\n\n#line 5 \"math/mod_inv.hpp\"\n\n#line 7 \"\
    math/mod_inv.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint> mint inv(int n)\
    \ {\n    static const int mod = mint::mod();\n    static std::vector<mint> dat\
    \ = {0, 1};\n    assert(0 <= n);\n    if (n >= mod) n -= mod;\n    while (int(dat.size())\
    \ <= n) {\n        int num = dat.size();\n        int q = (mod + num - 1) / num;\n\
    \        dat.emplace_back(dat[num * q - mod] * mint(q));\n    }\n    return dat[n];\n\
    }\n\n}  // namespace ebi\n#line 8 \"fps/fps_sparse.hpp\"\n\nnamespace ebi {\n\n\
    template <Modint mint>\nstd::vector<mint> mul_sparse(const std::vector<mint> &f,\n\
    \                             const std::vector<mint> &g) {\n    int n = f.size();\n\
    \    int m = g.size();\n    std::vector<std::pair<int, mint>> cf, cg;\n    for\
    \ (int i = 0; i < n; i++) {\n        if (f[i] != 0) cf.emplace_back(i, f[i]);\n\
    \    }\n    for (int i = 0; i < m; i++) {\n        if (g[i] != 0) cg.emplace_back(i,\
    \ g[i]);\n    }\n    std::vector<mint> h(n + m - 1);\n    for (auto [i, p] : cf)\
    \ {\n        for (auto [j, q] : cg) {\n            h[i + j] += p * q;\n      \
    \  }\n    }\n    return h;\n}\n\ntemplate <Modint mint>\nstd::vector<mint> inv_sparse(const\
    \ std::vector<mint> &f, int d = -1) {\n    assert(f[0] != 0);\n    if (d < 0)\
    \ {\n        d = f.size();\n    }\n    std::vector<std::pair<int, mint>> ret;\n\
    \    for (int i = 1; i < int(f.size()); i++) {\n        if (f[i] != 0) {\n   \
    \         ret.emplace_back(i, f[i]);\n        }\n    }\n    std::vector<mint>\
    \ g(d);\n    g[0] = f[0].inv();\n    for (int i = 1; i < d; i++) {\n        for\
    \ (auto [k, p] : ret) {\n            if (i - k < 0) break;\n            g[i] -=\
    \ g[i - k] * p;\n        }\n        g[i] *= g[0];\n    }\n    return g;\n}\n\n\
    template <Modint mint>\nstd::vector<mint> exp_sparse(const std::vector<mint> &f,\
    \ int d = -1) {\n    int n = f.size();\n    if (d < 0) d = n;\n    std::vector<std::pair<int,\
    \ mint>> ret;\n    for (int i = 1; i < n; i++) {\n        if (f[i] != 0) {\n \
    \           ret.emplace_back(i - 1, f[i] * i);\n        }\n    }\n    std::vector<mint>\
    \ g(d);\n    g[0] = 1;\n    for (int i = 0; i < d - 1; i++) {\n        for (auto\
    \ [k, p] : ret) {\n            if (i - k < 0) break;\n            g[i + 1] +=\
    \ g[i - k] * p;\n        }\n        g[i + 1] *= inv<mint>(i + 1);\n    }\n   \
    \ return g;\n}\n\ntemplate <Modint mint>\nstd::vector<mint> log_sparse(const std::vector<mint>\
    \ &f, int d = -1) {\n    int n = f.size();\n    if (d < 0) d = n;\n    std::vector<mint>\
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
    #line 7 \"fps/fps_sqrt.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint>\nstd::optional<FormalPowerSeries<mint>>\
    \ FormalPowerSeries<mint>::sqrt(\n    int d) const {\n    using FPS = FormalPowerSeries<mint>;\n\
    \    if (d < 0) d = deg();\n    if ((*this)[0] == 0) {\n        for (int i = 1;\
    \ i < this->deg(); i++) {\n            if ((*this)[i] != 0) {\n              \
    \  if (i & 1) return std::nullopt;\n                if (d - i / 2 <= 0) break;\n\
    \                auto opt = ((*this) >> i).sqrt(d - i / 2);\n                if\
    \ (!opt) return std::nullopt;\n                auto ret = opt.value() << (i /\
    \ 2);\n                if ((int)ret.deg() < d) ret.resize(d);\n              \
    \  return ret;\n            }\n        }\n        return FPS(d, 0);\n    }\n \
    \   auto s = mod_sqrt((*this)[0].val(), mint::mod());\n    if (!s) {\n       \
    \ return std::nullopt;\n    }\n    if (this->count_terms() <= 200) {\n       \
    \ mint y = s.value();\n        std::vector<mint> sqrt_f =\n            pow_sparse_1(*this\
    \ / (*this)[0], mint(2).inv().val(), d);\n        FPS g(d);\n        for (int\
    \ i = 0; i < d; i++) g[i] = sqrt_f[i] * y;\n        return g;\n    }\n    int\
    \ n = 1;\n    FPS g(n);\n    g[0] = s.value();\n    mint inv_two = mint(2).inv();\n\
    \    while (n < d) {\n        n <<= 1;\n        g = (g + this->pre(n) * g.inv(n)).pre(n)\
    \ * inv_two;\n    }\n    g.resize(d);\n    return g;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include \"../fps/fps.hpp\"\n#include \"../fps/fps_sparse.hpp\"\
    \n#include \"../math/mod_sqrt.hpp\"\n#include \"../modint/base.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <Modint mint>\nstd::optional<FormalPowerSeries<mint>> FormalPowerSeries<mint>::sqrt(\n\
    \    int d) const {\n    using FPS = FormalPowerSeries<mint>;\n    if (d < 0)\
    \ d = deg();\n    if ((*this)[0] == 0) {\n        for (int i = 1; i < this->deg();\
    \ i++) {\n            if ((*this)[i] != 0) {\n                if (i & 1) return\
    \ std::nullopt;\n                if (d - i / 2 <= 0) break;\n                auto\
    \ opt = ((*this) >> i).sqrt(d - i / 2);\n                if (!opt) return std::nullopt;\n\
    \                auto ret = opt.value() << (i / 2);\n                if ((int)ret.deg()\
    \ < d) ret.resize(d);\n                return ret;\n            }\n        }\n\
    \        return FPS(d, 0);\n    }\n    auto s = mod_sqrt((*this)[0].val(), mint::mod());\n\
    \    if (!s) {\n        return std::nullopt;\n    }\n    if (this->count_terms()\
    \ <= 200) {\n        mint y = s.value();\n        std::vector<mint> sqrt_f =\n\
    \            pow_sparse_1(*this / (*this)[0], mint(2).inv().val(), d);\n     \
    \   FPS g(d);\n        for (int i = 0; i < d; i++) g[i] = sqrt_f[i] * y;\n   \
    \     return g;\n    }\n    int n = 1;\n    FPS g(n);\n    g[0] = s.value();\n\
    \    mint inv_two = mint(2).inv();\n    while (n < d) {\n        n <<= 1;\n  \
    \      g = (g + this->pre(n) * g.inv(n)).pre(n) * inv_two;\n    }\n    g.resize(d);\n\
    \    return g;\n}\n\n}  // namespace ebi"
  dependsOn:
  - fps/fps.hpp
  - modint/base.hpp
  - fps/fps_sparse.hpp
  - math/mod_inv.hpp
  - math/mod_sqrt.hpp
  - modint/dynamic_modint.hpp
  isVerificationFile: false
  path: fps/fps_sqrt.hpp
  requiredBy: []
  timestamp: '2024-05-24 14:53:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - test/polynomial/Sqrt_of_Formal_Power_Series_Sparse.test.cpp
documentation_of: fps/fps_sqrt.hpp
layout: document
title: $\sqrt{f}$
---

## 説明

形式的べき級数 $f$ について $\sqrt{f}$ が存在するなら求める。存在しない場合は `std::nullopt`を返す。
疎な場合は非負の要素数を $M$ として $O(NM)$。密な場合は $O(N\log N)$