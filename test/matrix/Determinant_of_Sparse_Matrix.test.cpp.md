---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: fps/berlekamp_massey.hpp
    title: Berlekamp Massey
  - icon: ':heavy_check_mark:'
    path: fps/fps.hpp
    title: Formal Power Series
  - icon: ':heavy_check_mark:'
    path: fps/poly_mod_pow.hpp
    title: fps/poly_mod_pow.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: Graph (CSR format)
  - icon: ':heavy_check_mark:'
    path: matrix/black_box_linear_algebra.hpp
    title: Black Box Linear Algebra
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
    PROBLEM: https://judge.yosupo.jp/problem/sparse_matrix_det
    links:
    - https://judge.yosupo.jp/problem/sparse_matrix_det
  bundledCode: "#line 1 \"test/matrix/Determinant_of_Sparse_Matrix.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sparse_matrix_det\"\n\n#line 2 \"\
    matrix/black_box_linear_algebra.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \n#line 2 \"fps/berlekamp_massey.hpp\"\n\n#include <algorithm>\n#line 5 \"fps/berlekamp_massey.hpp\"\
    \n\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#include <iostream>\n\
    #include <utility>\n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint =\
    \ requires(T a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n\
    \    a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n};\n\ntemplate\
    \ <Modint mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long\
    \ long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <Modint mint>\n\
    std::ostream &operator<<(std::ostream &os, const mint &a) {\n    return os <<\
    \ a.val();\n}\n\n}  // namespace ebi\n#line 7 \"fps/berlekamp_massey.hpp\"\n\n\
    namespace ebi {\n\ntemplate <Modint mint>\nstd::vector<mint> berlekamp_massey(const\
    \ std::vector<mint> &s) {\n    std::vector<mint> C = {1}, B = {1};\n    int L\
    \ = 0, m = 1;\n    mint b = 1;\n    for (int n = 0; n < (int)s.size(); n++) {\n\
    \        mint d = s[n];\n        for (int i = 1; i <= L; i++) {\n            d\
    \ += s[n - i] * C[i];\n        }\n        if (d == 0) {\n            m++;\n  \
    \      } else if (2 * L <= n) {\n            auto T = C;\n            mint f =\
    \ d / b;\n            C.resize((int)B.size() + m);\n            for (int i = 0;\
    \ i < (int)B.size(); i++) {\n                C[i + m] -= f * B[i];\n         \
    \   }\n            L = n + 1 - L;\n            B = T;\n            b = d;\n  \
    \          m = 1;\n        } else {\n            mint f = d / b;\n           \
    \ for (int i = 0; i < (int)B.size(); i++) {\n                C[i + m] -= f * B[i];\n\
    \            }\n            m++;\n        }\n    }\n    return C;\n}\n\n}  //\
    \ namespace ebi\n#line 2 \"fps/poly_mod_pow.hpp\"\n\n#line 2 \"fps/fps.hpp\"\n\
    \n#line 5 \"fps/fps.hpp\"\n#include <optional>\n#line 7 \"fps/fps.hpp\"\n\n#line\
    \ 9 \"fps/fps.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint> struct FormalPowerSeries\
    \ : std::vector<mint> {\n  private:\n    using std::vector<mint>::vector;\n  \
    \  using std::vector<mint>::vector::operator=;\n    using FPS = FormalPowerSeries;\n\
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
    \    }\n\n    FPS &operator*=(const FPS &);\n\n    FPS &operator/=(const FPS &rhs)\
    \ noexcept {\n        int n = deg() - 1;\n        int m = rhs.deg() - 1;\n   \
    \     if (n < m) {\n            *this = {};\n            return *this;\n     \
    \   }\n        *this = (*this).rev() * rhs.rev().inv(n - m + 1);\n        (*this).resize(n\
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
    \        return g;\n    }\n\n    FPS pow(long long k, int d = -1) const {\n  \
    \      assert(k >= 0);\n        int n = deg();\n        if (d < 0) d = n;\n  \
    \      if (k == 0) {\n            FPS f(d);\n            if (d > 0) f[0] = 1;\n\
    \            return f;\n        }\n        int low = d;\n        for (int i =\
    \ n - 1; i >= 0; i--)\n            if ((*this)[i] != 0) low = i;\n        if (low\
    \ >= (d + k - 1) / k) return FPS(d, 0);\n        int offset = k * low;\n     \
    \   mint c = (*this)[low];\n        FPS g(d - offset);\n        for (int i = 0;\
    \ i < std::min(n - low, d - offset); i++) {\n            g[i] = (*this)[i + low];\n\
    \        }\n        g /= c;\n        g = g.pow_1(k);\n        return (g << offset)\
    \ * c.pow(k);\n    }\n\n    FPS pow_1(mint k, int d = -1) const {\n        assert((*this)[0]\
    \ == 1);\n        return ((*this).log(d) * k).exp(d);\n    }\n\n    FPS pow_newton(long\
    \ long k, int d = -1) const {\n        assert(k >= 0);\n        const int n =\
    \ deg();\n        if (d < 0) d = n;\n        if (k == 0) {\n            FPS f(d);\n\
    \            if (d > 0) f[0] = 1;\n            return f;\n        }\n        for\
    \ (int i = 0; i < n; i++) {\n            if ((*this)[i] != 0) {\n            \
    \    mint rev = (*this)[i].inv();\n                FPS f = (((*this * rev) >>\
    \ i).log(d) * k).exp(d);\n                f *= (*this)[i].pow(k);\n          \
    \      f = (f << (i * k)).pre(d);\n                if (f.deg() < d) f.resize(d);\n\
    \                return f;\n            }\n            if (i + 1 >= (d + k - 1)\
    \ / k) break;\n        }\n        return FPS(d);\n    }\n\n    int deg() const\
    \ {\n        return (*this).size();\n    }\n\n    void shrink() {\n        while\
    \ ((!this->empty()) && this->back() == 0) this->pop_back();\n    }\n\n    int\
    \ count_terms() const {\n        int c = 0;\n        for (int i = 0; i < deg();\
    \ i++) {\n            if ((*this)[i] != 0) c++;\n        }\n        return c;\n\
    \    }\n\n    std::optional<FPS> sqrt(int d = -1) const;\n\n    static FPS exp_x(int\
    \ n) {\n        FPS f(n);\n        mint fact = 1;\n        for (int i = 1; i <\
    \ n; i++) fact *= i;\n        f[n - 1] = fact.inv();\n        for (int i = n -\
    \ 1; i >= 0; i--) f[i - 1] = f[i] * i;\n        return f;\n    }\n\n    void fft();\n\
    \    void ifft();\n};\n\n}  // namespace ebi\n#line 5 \"fps/poly_mod_pow.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint>\nFormalPowerSeries<mint> poly_mod_pow(FormalPowerSeries<mint>\
    \ f, long long k,\n                                     const FormalPowerSeries<mint>\
    \ &g) {\n    FormalPowerSeries<mint> res = {1};\n    while (k > 0) {\n       \
    \ if (k & 1) {\n            res *= f;\n            res %= g;\n            res.shrink();\n\
    \        }\n        f *= f;\n        f %= g;\n        f.shrink();\n        k >>=\
    \ 1;\n    }\n    return res;\n}\n\n}  // namespace ebi\n#line 2 \"utility/random_number_generator.hpp\"\
    \n\r\n#line 4 \"utility/random_number_generator.hpp\"\n#include <cstdint>\r\n\
    #include <numeric>\r\n#include <random>\r\n#line 8 \"utility/random_number_generator.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\nstruct random_number_generator {\r\n    random_number_generator(int\
    \ seed = -1) {\r\n        if (seed < 0) seed = rnd();\r\n        mt.seed(seed);\r\
    \n    }\r\n\r\n    void set_seed(int seed) {\r\n        mt.seed(seed);\r\n   \
    \ }\r\n\r\n    template <class T> T get(T a, T b) {\r\n        std::uniform_int_distribution<T>\
    \ dist(a, b - 1);\r\n        return dist(mt);\r\n    }\r\n\r\n    std::vector<int>\
    \ get_permutation(int n) {\r\n        std::vector<int> p(n);\r\n        std::iota(p.begin(),\
    \ p.end(), 0);\r\n        std::shuffle(p.begin(), p.end(), mt);\r\n        return\
    \ p;\r\n    }\r\n\r\n  private:\r\n    std::mt19937_64 mt;\r\n    std::random_device\
    \ rnd;\r\n};\r\n\r\n}  // namespace ebi\n#line 10 \"matrix/black_box_linear_algebra.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint, class F>\nstd::vector<mint> matrix_minimum_poly(int\
    \ n, F Ax) {\n    static random_number_generator rng;\n    std::vector<mint> s(2\
    \ * n + 10, 0), u(n), b(n);\n    for (int i = 0; i < n; i++) {\n        u[i] =\
    \ rng.get(0, mint::mod());\n        b[i] = rng.get(0, mint::mod());\n    }\n \
    \   for (int i = 0; i < 2 * n + 10; i++) {\n        for (int j = 0; j < n; j++)\
    \ {\n            s[i] += u[j] * b[j];\n        }\n        b = Ax(b);\n    }\n\
    \    auto c = berlekamp_massey(s);\n    std::reverse(c.begin(), c.end());\n  \
    \  return c;\n}\n\ntemplate <Modint mint, class F>\nstd::vector<mint> pow(int\
    \ n, F Ax, const std::vector<mint> &b, long long k) {\n    assert(n == (int)b.size());\n\
    \    using FPS = FormalPowerSeries<mint>;\n    auto g = matrix_minimum_poly<mint>(n,\
    \ Ax);\n    auto c = poly_mod_pow<mint>({0, 1}, k, g);\n    FPS res(n, 0), Ab\
    \ = b;\n    for (int i = 0; i < (int)c.size(); i++) {\n        res += Ab * c[i];\n\
    \        Ab = FPS(Ax(Ab));\n    }\n    return res;\n}\n\ntemplate <Modint mint,\
    \ class F> mint det(int n, F Ax) {\n    static random_number_generator rng;\n\
    \    std::vector<mint> d(n);\n    mint r = 1;\n    for (int i = 0; i < n; i++)\
    \ {\n        d[i] = rng.get(1, mint::mod());\n        r *= d[i];\n    }\n    auto\
    \ ADx = [&](std::vector<mint> v) -> std::vector<mint> {\n        assert(n == (int)v.size());\n\
    \        for (int i = 0; i < n; i++) {\n            v[i] *= d[i];\n        }\n\
    \        return Ax(v);\n    };\n    auto f = matrix_minimum_poly<mint>(n, ADx);\n\
    \    mint res = ((int)f.size() == n + 1 ? f[0] : 0);\n    if (n % 2 == 1) res\
    \ = -res;\n    return res / r;\n}\n\n}  // namespace ebi\n#line 2 \"modint/modint.hpp\"\
    \n\r\n#line 5 \"modint/modint.hpp\"\n\r\n#line 7 \"modint/modint.hpp\"\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <int m> struct static_modint {\r\n  private:\r\n    using\
    \ modint = static_modint;\r\n\r\n  public:\r\n    static constexpr int mod() {\r\
    \n        return m;\r\n    }\r\n\r\n    static constexpr modint raw(int v) {\r\
    \n        modint x;\r\n        x._v = v;\r\n        return x;\r\n    }\r\n\r\n\
    \    constexpr static_modint() : _v(0) {}\r\n\r\n    template <std::signed_integral\
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
    \ :\";\n    debug_out(t...);\n}\n\n}  // namespace ebi\n#line 2 \"template/int_alias.hpp\"\
    \n\n#line 4 \"template/int_alias.hpp\"\n\nnamespace ebi {\n\nusing ld = long double;\n\
    using std::size_t;\nusing i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16\
    \ = std::int16_t;\nusing u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing\
    \ u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n\n}  // namespace ebi\n#line\
    \ 2 \"template/io.hpp\"\n\n#line 7 \"template/io.hpp\"\n\nnamespace ebi {\n\n\
    template <typename T1, typename T2>\nstd::ostream &operator<<(std::ostream &os,\
    \ const std::pair<T1, T2> &pa) {\n    return os << pa.first << \" \" << pa.second;\n\
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
    \ = default;\n\n    void add_edge(int u, int v, cost_type c) {\n        buff.emplace_back(u,\
    \ edge_type{u, v, c, m});\n        edges.emplace_back(edge_type{u, v, c, m++});\n\
    \    }\n\n    void add_undirected_edge(int u, int v, cost_type c) {\n        buff.emplace_back(u,\
    \ edge_type{u, v, c, m});\n        buff.emplace_back(v, edge_type{v, u, c, m});\n\
    \        edges.emplace_back(edge_type{u, v, c, m});\n        m++;\n    }\n\n \
    \   void read_tree(int offset = 1, bool is_weighted = false) {\n        read_graph(n\
    \ - 1, offset, false, is_weighted);\n    }\n\n    void read_parents(int offset\
    \ = 1) {\n        for (auto i : std::views::iota(1, n)) {\n            int p;\n\
    \            std::cin >> p;\n            p -= offset;\n            add_undirected_edge(p,\
    \ i, 1);\n        }\n        build();\n    }\n\n    void read_graph(int e, int\
    \ offset = 1, bool is_directed = false,\n                    bool is_weighted\
    \ = false) {\n        for (int i = 0; i < e; i++) {\n            int u, v;\n \
    \           std::cin >> u >> v;\n            u -= offset;\n            v -= offset;\n\
    \            if (is_weighted) {\n                cost_type c;\n              \
    \  std::cin >> c;\n                if (is_directed) {\n                    add_edge(u,\
    \ v, c);\n                } else {\n                    add_undirected_edge(u,\
    \ v, c);\n                }\n            } else {\n                if (is_directed)\
    \ {\n                    add_edge(u, v, 1);\n                } else {\n      \
    \              add_undirected_edge(u, v, 1);\n                }\n            }\n\
    \        }\n        build();\n    }\n\n    void build() {\n        assert(!prepared);\n\
    \        csr = simple_csr<edge_type>(n, buff);\n        buff.clear();\n      \
    \  prepared = true;\n    }\n\n    int size() const {\n        return n;\n    }\n\
    \n    int node_number() const {\n        return n;\n    }\n\n    int edge_number()\
    \ const {\n        return m;\n    }\n\n    edge_type get_edge(int i) const {\n\
    \        return edges[i];\n    }\n\n    std::vector<edge_type> get_edges() const\
    \ {\n        return edges;\n    }\n\n    const auto operator[](int i) const {\n\
    \        return csr[i];\n    }\n    auto operator[](int i) {\n        return csr[i];\n\
    \    }\n\n  private:\n    int n, m = 0;\n\n    std::vector<std::pair<int,edge_type>>\
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
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 6 \"test/matrix/Determinant_of_Sparse_Matrix.test.cpp\"\
    \n\nnamespace ebi {\n\nusing mint = modint998244353;\n\nvoid main_() {\n    int\
    \ n, k;\n    std::cin >> n >> k;\n    std::vector<std::tuple<int, int, mint>>\
    \ a(k);\n    for (auto &[i, j, c] : a) {\n        std::cin >> i >> j >> c;\n \
    \   }\n    auto Ax = [&](const std::vector<mint> &v) -> std::vector<mint> {\n\
    \        std::vector<mint> res(n, 0);\n        for (auto [i, j, c] : a) {\n  \
    \          res[i] += c * v[j];\n        }\n        return res;\n    };\n    std::cout\
    \ << det<mint>(n, Ax) << '\\n';\n}\n\n}  // namespace ebi\n\nint main() {\n  \
    \  ebi::fast_io();\n    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n\
    \        ebi::main_();\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sparse_matrix_det\"\n\n\
    #include \"../../matrix/black_box_linear_algebra.hpp\"\n#include \"../../modint/modint.hpp\"\
    \n#include \"../../template/template.hpp\"\n\nnamespace ebi {\n\nusing mint =\
    \ modint998244353;\n\nvoid main_() {\n    int n, k;\n    std::cin >> n >> k;\n\
    \    std::vector<std::tuple<int, int, mint>> a(k);\n    for (auto &[i, j, c] :\
    \ a) {\n        std::cin >> i >> j >> c;\n    }\n    auto Ax = [&](const std::vector<mint>\
    \ &v) -> std::vector<mint> {\n        std::vector<mint> res(n, 0);\n        for\
    \ (auto [i, j, c] : a) {\n            res[i] += c * v[j];\n        }\n       \
    \ return res;\n    };\n    std::cout << det<mint>(n, Ax) << '\\n';\n}\n\n}  //\
    \ namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n    // std::cin\
    \ >> t;\n    while (t--) {\n        ebi::main_();\n    }\n    return 0;\n}"
  dependsOn:
  - matrix/black_box_linear_algebra.hpp
  - fps/berlekamp_massey.hpp
  - modint/base.hpp
  - fps/poly_mod_pow.hpp
  - fps/fps.hpp
  - utility/random_number_generator.hpp
  - modint/modint.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: true
  path: test/matrix/Determinant_of_Sparse_Matrix.test.cpp
  requiredBy: []
  timestamp: '2024-08-06 16:15:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/matrix/Determinant_of_Sparse_Matrix.test.cpp
layout: document
redirect_from:
- /verify/test/matrix/Determinant_of_Sparse_Matrix.test.cpp
- /verify/test/matrix/Determinant_of_Sparse_Matrix.test.cpp.html
title: test/matrix/Determinant_of_Sparse_Matrix.test.cpp
---