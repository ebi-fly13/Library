---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: convolution/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: math/internal_math.hpp
    title: math/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: utility/bit_operator.hpp
    title: utility/bit_operator.hpp
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Exp_of_Formal_Power_Series.test.cpp
    title: test/Exp_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Inv_of_Formal_Power_Series.test.cpp
    title: test/Inv_of_Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Log_of_Formal_Power_Series.test.cpp
    title: test/Log_of_Formal_Power_Series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://opt-cp.com/fps-fast-algorithms/
  bundledCode: "#line 2 \"math/FormalPowerSeries.hpp\"\n\r\n#line 2 \"convolution/ntt.hpp\"\
    \n\n#include <array>\n#include <type_traits>\n#include <vector>\n\n#line 2 \"\
    math/internal_math.hpp\"\n\nnamespace ebi {\n\nnamespace internal {\n\nconstexpr\
    \ int primitive_root_constexpr(int m) {\n    if (m == 2) return 1;\n    if (m\
    \ == 167772161) return 3;\n    if (m == 469762049) return 3;\n    if (m == 754974721)\
    \ return 11;\n    if (m == 998244353) return 3;\n}\ntemplate <int m> constexpr\
    \ int primitive_root = primitive_root_constexpr(m);\n\n}  // namespace internal\n\
    \n}  // namespace ebi\n#line 2 \"utility/bit_operator.hpp\"\n\nnamespace ebi {\n\
    \nconstexpr int bsf_constexpr(unsigned int n) {\n    int x = 0;\n    while (!(n\
    \ & (1 << x))) x++;\n    return x;\n}\n\nint bit_reverse(int n, int bit_size)\
    \ {\n    int rev_n = 0;\n    for (int i = 0; i < bit_size; i++) {\n        rev_n\
    \ |= ((n >> i) & 1) << (bit_size - i - 1);\n    }\n    return rev_n;\n}\n\nint\
    \ ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n))\
    \ x++;\n    return x;\n}\n\nint popcnt(int x) {\n    return __builtin_popcount(x);\n\
    }\n\nint msb(int x) {\n    return (x == 0) ? -1 : 31 - __builtin_clz(x);\n}\n\n\
    int bsf(int x) {\n    return (x == 0) ? -1 : __builtin_ctz(x);\n}\n\n}  // namespace\
    \ ebi\n#line 2 \"utility/modint.hpp\"\n\r\n#include <cassert>\r\n#include <iostream>\r\
    \n#line 6 \"utility/modint.hpp\"\n\r\nnamespace ebi {\r\n\r\nnamespace internal\
    \ {\r\n\r\nstruct modint_base {};\r\nstruct static_modint_base : modint_base {};\r\
    \n\r\ntemplate <class T> using is_modint = std::is_base_of<modint_base, T>;\r\n\
    template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\r\
    \n\r\n}  // namespace internal\r\n\r\ntemplate <int m> struct static_modint :\
    \ internal::static_modint_base {\r\n  private:\r\n    using modint = static_modint;\r\
    \n\r\n  public:\r\n    static constexpr int mod() {\r\n        return m;\r\n \
    \   }\r\n\r\n    static modint raw(int v) {\r\n        modint x;\r\n        x._v\
    \ = v;\r\n        return x;\r\n    }\r\n\r\n    static_modint() : _v(0) {}\r\n\
    \r\n    static_modint(long long v) {\r\n        v %= (long long)umod();\r\n  \
    \      if (v < 0) v += (long long)umod();\r\n        _v = (unsigned int)v;\r\n\
    \    }\r\n\r\n    unsigned int val() const {\r\n        return _v;\r\n    }\r\n\
    \r\n    unsigned int value() const {\r\n        return val();\r\n    }\r\n\r\n\
    \    modint &operator++() {\r\n        _v++;\r\n        if (_v == umod()) _v =\
    \ 0;\r\n        return *this;\r\n    }\r\n    modint &operator--() {\r\n     \
    \   if (_v == 0) _v = umod();\r\n        _v--;\r\n        return *this;\r\n  \
    \  }\r\n    modint &operator+=(const modint &rhs) {\r\n        _v += rhs._v;\r\
    \n        if (_v >= umod()) _v -= umod();\r\n        return *this;\r\n    }\r\n\
    \    modint &operator-=(const modint &rhs) {\r\n        _v -= rhs._v;\r\n    \
    \    if (_v >= umod()) _v += umod();\r\n        return *this;\r\n    }\r\n   \
    \ modint &operator*=(const modint &rhs) {\r\n        unsigned long long x = _v;\r\
    \n        x *= rhs._v;\r\n        _v = (unsigned int)(x % (unsigned long long)umod());\r\
    \n        return *this;\r\n    }\r\n    modint &operator/=(const modint &rhs)\
    \ {\r\n        return *this = *this * rhs.inv();\r\n    }\r\n\r\n    modint operator+()\
    \ const {\r\n        return *this;\r\n    }\r\n    modint operator-() const {\r\
    \n        return modint() - *this;\r\n    }\r\n\r\n    modint pow(long long n)\
    \ const {\r\n        assert(0 <= n);\r\n        modint x = *this, res = 1;\r\n\
    \        while (n) {\r\n            if (n & 1) res *= x;\r\n            x *= x;\r\
    \n            n >>= 1;\r\n        }\r\n        return res;\r\n    }\r\n    modint\
    \ inv() const {\r\n        assert(_v);\r\n        return pow(umod() - 2);\r\n\
    \    }\r\n\r\n    friend modint operator+(const modint &lhs, const modint &rhs)\
    \ {\r\n        return modint(lhs) += rhs;\r\n    }\r\n    friend modint operator-(const\
    \ modint &lhs, const modint &rhs) {\r\n        return modint(lhs) -= rhs;\r\n\
    \    }\r\n    friend modint operator*(const modint &lhs, const modint &rhs) {\r\
    \n        return modint(lhs) *= rhs;\r\n    }\r\n\r\n    friend modint operator/(const\
    \ modint &lhs, const modint &rhs) {\r\n        return modint(lhs) /= rhs;\r\n\
    \    }\r\n    friend bool operator==(const modint &lhs, const modint &rhs) {\r\
    \n        return lhs.val() == rhs.val();\r\n    }\r\n    friend bool operator!=(const\
    \ modint &lhs, const modint &rhs) {\r\n        return !(lhs == rhs);\r\n    }\r\
    \n\r\n  private:\r\n    unsigned int _v;\r\n\r\n    static constexpr unsigned\
    \ int umod() {\r\n        return m;\r\n    }\r\n};\r\n\r\ntemplate <int m>\r\n\
    std::istream &operator>>(std::istream &os, static_modint<m> &a) {\r\n    long\
    \ long x;\r\n    os >> x;\r\n    a = x;\r\n    return os;\r\n}\r\ntemplate <int\
    \ m>\r\nstd::ostream &operator<<(std::ostream &os, const static_modint<m> &a)\
    \ {\r\n    return os << a.val();\r\n}\r\n\r\nusing modint998244353 = static_modint<998244353>;\r\
    \nusing modint1000000007 = static_modint<1000000007>;\r\n\r\nnamespace internal\
    \ {\r\n\r\ntemplate <class T>\r\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\r\n\r\ntemplate <class T>\r\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\r\
    \n\r\n}  // namespace internal\r\n\r\n}  // namespace ebi\n#line 10 \"convolution/ntt.hpp\"\
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
    \ {\n        a[i] *= inv_n;\n    }\n}\n\n}  // namespace internal\n\n#line 101\
    \ \"convolution/ntt.hpp\"\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstd::vector<mint> convolution(const std::vector<mint>& f,\n    \
    \                          const std::vector<mint>& g) {\n    int n = 1 << ceil_pow2(f.size()\
    \ + g.size() - 1);\n    std::vector<mint> a(n), b(n);\n    std::copy(f.begin(),\
    \ f.end(), a.begin());\n    std::copy(g.begin(), g.end(), b.begin());\n    internal::butterfly(a);\n\
    \    internal::butterfly(b);\n    for (int i = 0; i < n; i++) {\n        a[i]\
    \ *= b[i];\n    }\n    internal::butterfly_inv(a);\n    a.resize(f.size() + g.size()\
    \ - 1);\n    return a;\n}\n\n}  // namespace ebi\n#line 5 \"math/FormalPowerSeries.hpp\"\
    \n\r\n#include <algorithm>\r\n#line 9 \"math/FormalPowerSeries.hpp\"\n\r\n/*\r\
    \n    reference: https://opt-cp.com/fps-fast-algorithms/\r\n*/\r\n\r\nnamespace\
    \ ebi {\r\n\r\nusing mint = modint998244353;\r\n\r\nstruct FormalPowerSeries :\
    \ std::vector<mint> {\r\n  private:\r\n    using std::vector<mint>::vector;\r\n\
    \    using std::vector<mint>::vector::operator=;\r\n    using FPS = FormalPowerSeries;\r\
    \n\r\n  public:\r\n    FPS operator+(const FPS &rhs) const noexcept {\r\n    \
    \    return FPS(*this) += rhs;\r\n    }\r\n    FPS operator-(const FPS &rhs) const\
    \ noexcept {\r\n        return FPS(*this) -= rhs;\r\n    }\r\n    FPS operator*(const\
    \ FPS &rhs) const noexcept {\r\n        return FPS(*this) *= rhs;\r\n    }\r\n\
    \    FPS operator/(const FPS &rhs) const noexcept {\r\n        return FPS(*this)\
    \ /= rhs;\r\n    }\r\n\r\n    FPS &operator+=(const FPS &rhs) noexcept {\r\n \
    \       int sz = std::min(deg(), rhs.deg());\r\n        for (int i = 0; i < sz;\
    \ ++i) {\r\n            (*this)[i] += rhs[i];\r\n        }\r\n        return *this;\r\
    \n    }\r\n\r\n    FPS &operator-=(const FPS &rhs) noexcept {\r\n        int sz\
    \ = std::min(deg(), rhs.deg());\r\n        for (int i = 0; i < sz; ++i) {\r\n\
    \            (*this)[i] -= rhs[i];\r\n        }\r\n        return *this;\r\n \
    \   }\r\n\r\n    FPS &operator*=(const FPS &rhs) noexcept {\r\n        int n =\
    \ deg();\r\n        *this = convolution(*this, rhs);\r\n        (*this).resize(n);\r\
    \n        return *this;\r\n    }\r\n\r\n    FPS &operator/=(const FPS &rhs) noexcept\
    \ {\r\n        *this *= rhs.inv();\r\n        return *this;\r\n    }\r\n\r\n \
    \   FPS &operator*=(const mint rhs) noexcept {\r\n        for (int i = 0; i <\
    \ deg(); ++i) {\r\n            (*this)[i] *= rhs;\r\n        }\r\n        return\
    \ *this;\r\n    }\r\n\r\n    FPS inv() const {\r\n        int n = 1, sz = deg();\r\
    \n        FPS g(n);\r\n        g[0] = (*this)[0].inv();\r\n        while (n <\
    \ sz) {\r\n            n <<= 1;\r\n            FPS f((*this).begin(), (*this).begin()\
    \ + std::min(sz, n));\r\n            f.resize(n);\r\n            g.resize(n);\r\
    \n            FPS h = f * g;\r\n            h.erase(h.begin(), h.begin() + n /\
    \ 2);\r\n            h.resize(n);\r\n            h = h * g;\r\n            for\
    \ (int i = 0; i < n / 2; i++) {\r\n                g[i + n / 2] -= h[i];\r\n \
    \           }\r\n        }\r\n        g.resize(sz);\r\n        return g;\r\n \
    \   }\r\n\r\n    FPS exp() {\r\n        assert((*this)[0].val() == 0);\r\n   \
    \     int n = 1, sz = deg();\r\n        FPS g(n);\r\n        g[0] = 1;\r\n   \
    \     while (n < sz) {\r\n            n <<= 1;\r\n            FPS f((*this).begin(),\
    \ (*this).begin() + std::min(sz, n));\r\n            f.resize(n);\r\n        \
    \    g.resize(n);\r\n            g = g * (f - g.log()) + g;\r\n        }\r\n \
    \       return g;\r\n    }\r\n\r\n    FPS differential() {\r\n        int n =\
    \ deg();\r\n        FPS g(n);\r\n        for (int i = 0; i < n - 1; i++) {\r\n\
    \            g[i] = (*this)[i + 1] * (i + 1);\r\n        }\r\n        g[n - 1]\
    \ = 0;\r\n        return g;\r\n    }\r\n\r\n    FPS integral() {\r\n        int\
    \ n = deg();\r\n        FPS g(n + 1);\r\n        g[0] = 0;\r\n        for (int\
    \ i = 0; i < n; i++) {\r\n            g[i + 1] = (*this)[i] / (mint(i + 1));\r\
    \n        }\r\n        return g;\r\n    }\r\n\r\n    FPS log() {\r\n        assert((*this)[0].val()\
    \ == 1);\r\n        FPS g = (*this).differential() / (*this);\r\n        return\
    \ g.integral();\r\n    }\r\n\r\n    int deg() const {\r\n        return (*this).size();\r\
    \n    }\r\n};\r\n\r\n}  // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include \"../convolution/ntt.hpp\"\r\n#include \"../utility/modint.hpp\"\
    \r\n\r\n#include <algorithm>\r\n#include <cassert>\r\n#include <vector>\r\n\r\n\
    /*\r\n    reference: https://opt-cp.com/fps-fast-algorithms/\r\n*/\r\n\r\nnamespace\
    \ ebi {\r\n\r\nusing mint = modint998244353;\r\n\r\nstruct FormalPowerSeries :\
    \ std::vector<mint> {\r\n  private:\r\n    using std::vector<mint>::vector;\r\n\
    \    using std::vector<mint>::vector::operator=;\r\n    using FPS = FormalPowerSeries;\r\
    \n\r\n  public:\r\n    FPS operator+(const FPS &rhs) const noexcept {\r\n    \
    \    return FPS(*this) += rhs;\r\n    }\r\n    FPS operator-(const FPS &rhs) const\
    \ noexcept {\r\n        return FPS(*this) -= rhs;\r\n    }\r\n    FPS operator*(const\
    \ FPS &rhs) const noexcept {\r\n        return FPS(*this) *= rhs;\r\n    }\r\n\
    \    FPS operator/(const FPS &rhs) const noexcept {\r\n        return FPS(*this)\
    \ /= rhs;\r\n    }\r\n\r\n    FPS &operator+=(const FPS &rhs) noexcept {\r\n \
    \       int sz = std::min(deg(), rhs.deg());\r\n        for (int i = 0; i < sz;\
    \ ++i) {\r\n            (*this)[i] += rhs[i];\r\n        }\r\n        return *this;\r\
    \n    }\r\n\r\n    FPS &operator-=(const FPS &rhs) noexcept {\r\n        int sz\
    \ = std::min(deg(), rhs.deg());\r\n        for (int i = 0; i < sz; ++i) {\r\n\
    \            (*this)[i] -= rhs[i];\r\n        }\r\n        return *this;\r\n \
    \   }\r\n\r\n    FPS &operator*=(const FPS &rhs) noexcept {\r\n        int n =\
    \ deg();\r\n        *this = convolution(*this, rhs);\r\n        (*this).resize(n);\r\
    \n        return *this;\r\n    }\r\n\r\n    FPS &operator/=(const FPS &rhs) noexcept\
    \ {\r\n        *this *= rhs.inv();\r\n        return *this;\r\n    }\r\n\r\n \
    \   FPS &operator*=(const mint rhs) noexcept {\r\n        for (int i = 0; i <\
    \ deg(); ++i) {\r\n            (*this)[i] *= rhs;\r\n        }\r\n        return\
    \ *this;\r\n    }\r\n\r\n    FPS inv() const {\r\n        int n = 1, sz = deg();\r\
    \n        FPS g(n);\r\n        g[0] = (*this)[0].inv();\r\n        while (n <\
    \ sz) {\r\n            n <<= 1;\r\n            FPS f((*this).begin(), (*this).begin()\
    \ + std::min(sz, n));\r\n            f.resize(n);\r\n            g.resize(n);\r\
    \n            FPS h = f * g;\r\n            h.erase(h.begin(), h.begin() + n /\
    \ 2);\r\n            h.resize(n);\r\n            h = h * g;\r\n            for\
    \ (int i = 0; i < n / 2; i++) {\r\n                g[i + n / 2] -= h[i];\r\n \
    \           }\r\n        }\r\n        g.resize(sz);\r\n        return g;\r\n \
    \   }\r\n\r\n    FPS exp() {\r\n        assert((*this)[0].val() == 0);\r\n   \
    \     int n = 1, sz = deg();\r\n        FPS g(n);\r\n        g[0] = 1;\r\n   \
    \     while (n < sz) {\r\n            n <<= 1;\r\n            FPS f((*this).begin(),\
    \ (*this).begin() + std::min(sz, n));\r\n            f.resize(n);\r\n        \
    \    g.resize(n);\r\n            g = g * (f - g.log()) + g;\r\n        }\r\n \
    \       return g;\r\n    }\r\n\r\n    FPS differential() {\r\n        int n =\
    \ deg();\r\n        FPS g(n);\r\n        for (int i = 0; i < n - 1; i++) {\r\n\
    \            g[i] = (*this)[i + 1] * (i + 1);\r\n        }\r\n        g[n - 1]\
    \ = 0;\r\n        return g;\r\n    }\r\n\r\n    FPS integral() {\r\n        int\
    \ n = deg();\r\n        FPS g(n + 1);\r\n        g[0] = 0;\r\n        for (int\
    \ i = 0; i < n; i++) {\r\n            g[i + 1] = (*this)[i] / (mint(i + 1));\r\
    \n        }\r\n        return g;\r\n    }\r\n\r\n    FPS log() {\r\n        assert((*this)[0].val()\
    \ == 1);\r\n        FPS g = (*this).differential() / (*this);\r\n        return\
    \ g.integral();\r\n    }\r\n\r\n    int deg() const {\r\n        return (*this).size();\r\
    \n    }\r\n};\r\n\r\n}  // namespace ebi"
  dependsOn:
  - convolution/ntt.hpp
  - math/internal_math.hpp
  - utility/bit_operator.hpp
  - utility/modint.hpp
  isVerificationFile: false
  path: math/FormalPowerSeries.hpp
  requiredBy: []
  timestamp: '2023-05-17 22:42:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Inv_of_Formal_Power_Series.test.cpp
  - test/Exp_of_Formal_Power_Series.test.cpp
  - test/Log_of_Formal_Power_Series.test.cpp
documentation_of: math/FormalPowerSeries.hpp
layout: document
redirect_from:
- /library/math/FormalPowerSeries.hpp
- /library/math/FormalPowerSeries.hpp.html
title: math/FormalPowerSeries.hpp
---
