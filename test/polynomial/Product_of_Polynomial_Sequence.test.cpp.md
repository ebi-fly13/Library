---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/ntt.hpp
    title: NTT Convolution
  - icon: ':heavy_check_mark:'
    path: fps/product_of_fps.hpp
    title: $\prod_{i=0}^n f_i$
  - icon: ':question:'
    path: math/internal_math.hpp
    title: math/internal_math.hpp
  - icon: ':question:'
    path: utility/bit_operator.hpp
    title: utility/bit_operator.hpp
  - icon: ':question:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  - icon: ':question:'
    path: utility/modint_base.hpp
    title: utility/modint_base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/product_of_polynomial_sequence
    links:
    - https://judge.yosupo.jp/problem/product_of_polynomial_sequence
  bundledCode: "#line 1 \"test/polynomial/Product_of_Polynomial_Sequence.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/product_of_polynomial_sequence\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"convolution/ntt.hpp\"\n\
    \n#include <algorithm>\n#include <array>\n#include <cassert>\n#include <type_traits>\n\
    #line 8 \"convolution/ntt.hpp\"\n\n#line 2 \"math/internal_math.hpp\"\n\n#line\
    \ 4 \"math/internal_math.hpp\"\n\nnamespace ebi {\n\nnamespace internal {\n\n\
    constexpr int primitive_root_constexpr(int m) {\n    if (m == 2) return 1;\n \
    \   if (m == 167772161) return 3;\n    if (m == 469762049) return 3;\n    if (m\
    \ == 754974721) return 11;\n    if (m == 998244353) return 3;\n    if (m == 880803841)\
    \ return 26;\n    return -1;\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n}  // namespace internal\n\n}  // namespace\
    \ ebi\n#line 2 \"utility/bit_operator.hpp\"\n\nnamespace ebi {\n\nconstexpr int\
    \ bsf_constexpr(unsigned int n) {\n    int x = 0;\n    while (!(n & (1 << x)))\
    \ x++;\n    return x;\n}\n\nint bit_reverse(int n, int bit_size) {\n    int rev_n\
    \ = 0;\n    for (int i = 0; i < bit_size; i++) {\n        rev_n |= ((n >> i) &\
    \ 1) << (bit_size - i - 1);\n    }\n    return rev_n;\n}\n\nint ceil_pow2(int\
    \ n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n)) x++;\n    return\
    \ x;\n}\n\nint popcnt(int x) {\n    return __builtin_popcount(x);\n}\n\nint msb(int\
    \ x) {\n    return (x == 0) ? -1 : 31 - __builtin_clz(x);\n}\n\nint bsf(int x)\
    \ {\n    return (x == 0) ? -1 : __builtin_ctz(x);\n}\n\n}  // namespace ebi\n\
    #line 2 \"utility/modint_base.hpp\"\n\n#line 4 \"utility/modint_base.hpp\"\n\n\
    namespace ebi {\n\nnamespace internal {\n\nstruct modint_base {};\n\ntemplate\
    \ <class T> using is_modint = std::is_base_of<modint_base, T>;\ntemplate <class\
    \ T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\nstruct static_modint_base\
    \ : modint_base {};\n\ntemplate <class T>\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\ntemplate <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace ebi\n#line 12 \"convolution/ntt.hpp\"\
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
    \ {\n        a[i] *= inv_n;\n    }\n}\n\n}  // namespace internal\n\ntemplate\
    \ <class mint, internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint>\
    \ convolution_naive(const std::vector<mint>& f,\n                            \
    \        const std::vector<mint>& g) {\n    if (f.empty() || g.empty()) return\
    \ {};\n    int n = int(f.size()), m = int(g.size());\n    std::vector<mint> c(n\
    \ + m - 1);\n    if (n < m) {\n        for (int j = 0; j < m; j++) {\n       \
    \     for (int i = 0; i < n; i++) {\n                c[i + j] += f[i] * g[j];\n\
    \            }\n        }\n    } else {\n        for (int i = 0; i < n; i++) {\n\
    \            for (int j = 0; j < m; j++) {\n                c[i + j] += f[i] *\
    \ g[j];\n            }\n        }\n    }\n    return c;\n}\n\ntemplate <class\
    \ mint, internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution(const\
    \ std::vector<mint>& f,\n                              const std::vector<mint>&\
    \ g) {\n    if (f.empty() || g.empty()) return {};\n    if (std::min(f.size(),\
    \ g.size()) < 60) return convolution_naive(f, g);\n    int n = 1 << ceil_pow2(f.size()\
    \ + g.size() - 1);\n    std::vector<mint> a(n), b(n);\n    std::copy(f.begin(),\
    \ f.end(), a.begin());\n    std::copy(g.begin(), g.end(), b.begin());\n    internal::butterfly(a);\n\
    \    internal::butterfly(b);\n    for (int i = 0; i < n; i++) {\n        a[i]\
    \ *= b[i];\n    }\n    internal::butterfly_inv(a);\n    a.resize(f.size() + g.size()\
    \ - 1);\n    return a;\n}\n\n}  // namespace ebi\n#line 2 \"fps/product_of_fps.hpp\"\
    \n\n#include <deque>\n#line 5 \"fps/product_of_fps.hpp\"\n\nnamespace ebi {\n\n\
    template <class mint, std::vector<mint> (*convolution)(\n                    \
    \      const std::vector<mint> &, const std::vector<mint> &)>\nstd::vector<mint>\
    \ product_of_fps(const std::vector<std::vector<mint>> &fs) {\n    if (fs.empty())\
    \ return {1};\n    std::deque<std::vector<mint>> deque;\n    for (auto &f : fs)\
    \ deque.push_back(f);\n    while (deque.size() > 1) {\n        auto f = deque.front();\n\
    \        deque.pop_front();\n        auto g = deque.front();\n        deque.pop_front();\n\
    \        deque.push_back(convolution(f, g));\n    }\n    return deque.front();\n\
    }\n\n}  // namespace ebi\n#line 2 \"utility/modint.hpp\"\n\r\n#line 6 \"utility/modint.hpp\"\
    \n\r\n#line 8 \"utility/modint.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate <int\
    \ m> struct static_modint : internal::static_modint_base {\r\n  private:\r\n \
    \   using modint = static_modint;\r\n\r\n  public:\r\n    static constexpr int\
    \ mod() {\r\n        return m;\r\n    }\r\n\r\n    static constexpr modint raw(int\
    \ v) {\r\n        modint x;\r\n        x._v = v;\r\n        return x;\r\n    }\r\
    \n\r\n    constexpr static_modint() : _v(0) {}\r\n\r\n    constexpr static_modint(long\
    \ long v) {\r\n        v %= (long long)umod();\r\n        if (v < 0) v += (long\
    \ long)umod();\r\n        _v = (unsigned int)v;\r\n    }\r\n\r\n    constexpr\
    \ unsigned int val() const {\r\n        return _v;\r\n    }\r\n\r\n    constexpr\
    \ unsigned int value() const {\r\n        return val();\r\n    }\r\n\r\n    constexpr\
    \ modint &operator++() {\r\n        _v++;\r\n        if (_v == umod()) _v = 0;\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator--() {\r\n \
    \       if (_v == 0) _v = umod();\r\n        _v--;\r\n        return *this;\r\n\
    \    }\r\n    constexpr modint &operator+=(const modint &rhs) {\r\n        _v\
    \ += rhs._v;\r\n        if (_v >= umod()) _v -= umod();\r\n        return *this;\r\
    \n    }\r\n    constexpr modint &operator-=(const modint &rhs) {\r\n        _v\
    \ -= rhs._v;\r\n        if (_v >= umod()) _v += umod();\r\n        return *this;\r\
    \n    }\r\n    constexpr modint &operator*=(const modint &rhs) {\r\n        unsigned\
    \ long long x = _v;\r\n        x *= rhs._v;\r\n        _v = (unsigned int)(x %\
    \ (unsigned long long)umod());\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator/=(const modint &rhs) {\r\n        return *this = *this * rhs.inv();\r\
    \n    }\r\n\r\n    constexpr modint operator+() const {\r\n        return *this;\r\
    \n    }\r\n    constexpr modint operator-() const {\r\n        return modint()\
    \ - *this;\r\n    }\r\n\r\n    constexpr modint pow(long long n) const {\r\n \
    \       assert(0 <= n);\r\n        modint x = *this, res = 1;\r\n        while\
    \ (n) {\r\n            if (n & 1) res *= x;\r\n            x *= x;\r\n       \
    \     n >>= 1;\r\n        }\r\n        return res;\r\n    }\r\n    constexpr modint\
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
    \n\r\n  private:\r\n    unsigned int _v = 0;\r\n\r\n    static constexpr unsigned\
    \ int umod() {\r\n        return m;\r\n    }\r\n};\r\n\r\ntemplate <int m>\r\n\
    std::istream &operator>>(std::istream &os, static_modint<m> &a) {\r\n    long\
    \ long x;\r\n    os >> x;\r\n    a = x;\r\n    return os;\r\n}\r\ntemplate <int\
    \ m>\r\nstd::ostream &operator<<(std::ostream &os, const static_modint<m> &a)\
    \ {\r\n    return os << a.val();\r\n}\r\n\r\nusing modint998244353 = static_modint<998244353>;\r\
    \nusing modint1000000007 = static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n\
    #line 9 \"test/polynomial/Product_of_Polynomial_Sequence.test.cpp\"\n\nusing mint\
    \ = ebi::modint998244353;\n\nint main() {\n    int n;\n    std::cin >> n;\n  \
    \  std::vector<std::vector<mint>> fs(n);\n    int D = 0;\n    for (int i = 0;\
    \ i < n; i++) {\n        int d;\n        std::cin >> d;\n        D += d;\n   \
    \     std::vector<mint> f(d + 1);\n        for (int j = 0; j < d + 1; j++) std::cin\
    \ >> f[j];\n        fs[i] = f;\n    }\n    auto f = ebi::product_of_fps<mint,\
    \ ebi::convolution>(fs);\n    for (int i = 0; i < D + 1; i++) {\n        std::cout\
    \ << f[i] << \" \\n\"[i == D];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/product_of_polynomial_sequence\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../convolution/ntt.hpp\"\
    \n#include \"../../fps/product_of_fps.hpp\"\n#include \"../../utility/modint.hpp\"\
    \n\nusing mint = ebi::modint998244353;\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n    std::vector<std::vector<mint>> fs(n);\n    int D = 0;\n    for (int\
    \ i = 0; i < n; i++) {\n        int d;\n        std::cin >> d;\n        D += d;\n\
    \        std::vector<mint> f(d + 1);\n        for (int j = 0; j < d + 1; j++)\
    \ std::cin >> f[j];\n        fs[i] = f;\n    }\n    auto f = ebi::product_of_fps<mint,\
    \ ebi::convolution>(fs);\n    for (int i = 0; i < D + 1; i++) {\n        std::cout\
    \ << f[i] << \" \\n\"[i == D];\n    }\n}"
  dependsOn:
  - convolution/ntt.hpp
  - math/internal_math.hpp
  - utility/bit_operator.hpp
  - utility/modint_base.hpp
  - fps/product_of_fps.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/polynomial/Product_of_Polynomial_Sequence.test.cpp
  requiredBy: []
  timestamp: '2023-07-29 16:06:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/polynomial/Product_of_Polynomial_Sequence.test.cpp
layout: document
redirect_from:
- /verify/test/polynomial/Product_of_Polynomial_Sequence.test.cpp
- /verify/test/polynomial/Product_of_Polynomial_Sequence.test.cpp.html
title: test/polynomial/Product_of_Polynomial_Sequence.test.cpp
---
