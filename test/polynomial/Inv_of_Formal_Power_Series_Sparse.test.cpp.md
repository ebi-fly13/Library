---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/fps_sparse.hpp
    title: Formal Power Series (Sparse)
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  - icon: ':heavy_check_mark:'
    path: utility/modint_base.hpp
    title: utility/modint_base.hpp
  - icon: ':heavy_check_mark:'
    path: utility/modint_func.hpp
    title: utility/modint_func.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse
    links:
    - https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse
  bundledCode: "#line 1 \"test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"fps/fps_sparse.hpp\"\n\
    \n#include <cassert>\n#line 5 \"fps/fps_sparse.hpp\"\n\n#line 2 \"utility/modint_func.hpp\"\
    \n\n#line 5 \"utility/modint_func.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ mint> mint inv(int n) {\n    static const int mod = mint::mod();\n    static\
    \ std::vector<mint> dat = {0, 1};\n    assert(0 <= n);\n    if (n >= mod) n -=\
    \ mod;\n    while (int(dat.size()) <= n) {\n        int num = dat.size();\n  \
    \      int q = (mod + num - 1) / num;\n        dat.emplace_back(dat[num * q -\
    \ mod] * mint(q));\n    }\n    return dat[n];\n}\n\n}  // namespace ebi\n#line\
    \ 7 \"fps/fps_sparse.hpp\"\n\nnamespace ebi {\n\ntemplate <class mint>\nstd::vector<mint>\
    \ mul_sparse(const std::vector<mint> &f,\n                             const std::vector<mint>\
    \ &g) {\n    int n = f.size();\n    int m = g.size();\n    std::vector<std::pair<int,\
    \ mint>> cf, cg;\n    for (int i = 0; i < n; i++) {\n        if (f[i] != 0) cf.emplace_back(i,\
    \ f[i]);\n    }\n    for (int i = 0; i < m; i++) {\n        if (g[i] != 0) cg.emplace_back(i,\
    \ g[i]);\n    }\n    std::vector<mint> h(n + m - 1);\n    for (auto [i, p] : cf)\
    \ {\n        for (auto [j, q] : cg) {\n            h[i + j] += p * q;\n      \
    \  }\n    }\n    return h;\n}\n\ntemplate <class mint>\nstd::vector<mint> inv_sparse(const\
    \ std::vector<mint> &f, int d = -1) {\n    assert(f[0] != 0);\n    if (d < 0)\
    \ {\n        d = f.size();\n    }\n    std::vector<std::pair<int, mint>> ret;\n\
    \    for (int i = 1; i < int(f.size()); i++) {\n        if (f[i] != 0) {\n   \
    \         ret.emplace_back(i, f[i]);\n        }\n    }\n    std::vector<mint>\
    \ g(d);\n    g[0] = f[0].inv();\n    for (int i = 1; i < d; i++) {\n        for\
    \ (auto [k, p] : ret) {\n            if (i - k < 0) break;\n            g[i] -=\
    \ g[i - k] * p;\n        }\n        g[i] *= g[0];\n    }\n    return g;\n}\n\n\
    template <class mint>\nstd::vector<mint> exp_sparse(const std::vector<mint> &f,\
    \ int d = -1) {\n    int n = f.size();\n    if (d < 0) d = n;\n    std::vector<std::pair<int,\
    \ mint>> ret;\n    for (int i = 1; i < n; i++) {\n        if (f[i] != 0) {\n \
    \           ret.emplace_back(i - 1, f[i] * i);\n        }\n    }\n    std::vector<mint>\
    \ g(d);\n    g[0] = 1;\n    for (int i = 0; i < d - 1; i++) {\n        for (auto\
    \ [k, p] : ret) {\n            if (i - k < 0) break;\n            g[i + 1] +=\
    \ g[i - k] * p;\n        }\n        g[i + 1] *= inv<mint>(i + 1);\n    }\n   \
    \ return g;\n}\n\ntemplate <class mint>\nstd::vector<mint> log_sparse(const std::vector<mint>\
    \ &f, int d = -1) {\n    int n = f.size();\n    if (d < 0) d = n;\n    std::vector<mint>\
    \ df(d);\n    for (int i = 0; i < std::min(d, n - 1); i++) {\n        df[i] =\
    \ f[i + 1] * (i + 1);\n    }\n    auto dg = mul_sparse(df, inv_sparse(f));\n \
    \   dg.resize(d);\n    std::vector<mint> g(d);\n    for (int i = 0; i < d - 1;\
    \ i++) {\n        g[i + 1] = dg[i] * inv<mint>(i + 1);\n    }\n    return g;\n\
    }\n\ntemplate <class mint>\nstd::vector<mint> pow_sparse_1(const std::vector<mint>\
    \ &f, long long k,\n                               int d = -1) {\n    int n =\
    \ f.size();\n    assert(n == 0 || f[0] == 1);\n    std::vector<std::pair<int,\
    \ mint>> ret;\n    for (int i = 1; i < n; i++) {\n        if (f[i] != 0) ret.emplace_back(i,\
    \ f[i]);\n    }\n    std::vector<mint> g(d);\n    g[0] = 1;\n    for (int i =\
    \ 0; i < d - 1; i++) {\n        for (const auto &[j, cf] : ret) {\n          \
    \  if (i + 1 - j < 0) break;\n            g[i + 1] +=\n                (mint(k)\
    \ * mint(j) - mint(i - j + 1)) * cf * g[i + 1 - j];\n        }\n        g[i +\
    \ 1] *= inv<mint>(i + 1);\n    }\n    return g;\n}\n\ntemplate <class mint>\n\
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
    \  // namespace ebi\n#line 2 \"utility/modint.hpp\"\n\r\n#line 5 \"utility/modint.hpp\"\
    \n#include <type_traits>\r\n\r\n#line 2 \"utility/modint_base.hpp\"\n\n#line 4\
    \ \"utility/modint_base.hpp\"\n\nnamespace ebi {\n\nnamespace internal {\n\nstruct\
    \ modint_base {};\n\ntemplate <class T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace ebi\n#line 8 \"utility/modint.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\nnamespace internal {\r\n\r\nstruct static_modint_base\
    \ : modint_base {};\r\n\r\ntemplate <class T>\r\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\r\n\r\ntemplate <class T>\r\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\r\
    \n\r\n}  // namespace internal\r\n\r\ntemplate <int m> struct static_modint :\
    \ internal::static_modint_base {\r\n  private:\r\n    using modint = static_modint;\r\
    \n\r\n  public:\r\n    static constexpr int mod() {\r\n        return m;\r\n \
    \   }\r\n\r\n    static constexpr modint raw(int v) {\r\n        modint x;\r\n\
    \        x._v = v;\r\n        return x;\r\n    }\r\n\r\n    constexpr static_modint()\
    \ : _v(0) {}\r\n\r\n    constexpr static_modint(long long v) {\r\n        v %=\
    \ (long long)umod();\r\n        if (v < 0) v += (long long)umod();\r\n       \
    \ _v = (unsigned int)v;\r\n    }\r\n\r\n    constexpr unsigned int val() const\
    \ {\r\n        return _v;\r\n    }\r\n\r\n    constexpr unsigned int value() const\
    \ {\r\n        return val();\r\n    }\r\n\r\n    constexpr modint &operator++()\
    \ {\r\n        _v++;\r\n        if (_v == umod()) _v = 0;\r\n        return *this;\r\
    \n    }\r\n    constexpr modint &operator--() {\r\n        if (_v == 0) _v = umod();\r\
    \n        _v--;\r\n        return *this;\r\n    }\r\n    constexpr modint &operator+=(const\
    \ modint &rhs) {\r\n        _v += rhs._v;\r\n        if (_v >= umod()) _v -= umod();\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator-=(const modint\
    \ &rhs) {\r\n        _v -= rhs._v;\r\n        if (_v >= umod()) _v += umod();\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator*=(const modint\
    \ &rhs) {\r\n        unsigned long long x = _v;\r\n        x *= rhs._v;\r\n  \
    \      _v = (unsigned int)(x % (unsigned long long)umod());\r\n        return\
    \ *this;\r\n    }\r\n    constexpr modint &operator/=(const modint &rhs) {\r\n\
    \        return *this = *this * rhs.inv();\r\n    }\r\n\r\n    constexpr modint\
    \ operator+() const {\r\n        return *this;\r\n    }\r\n    constexpr modint\
    \ operator-() const {\r\n        return modint() - *this;\r\n    }\r\n\r\n   \
    \ constexpr modint pow(long long n) const {\r\n        assert(0 <= n);\r\n   \
    \     modint x = *this, res = 1;\r\n        while (n) {\r\n            if (n &\
    \ 1) res *= x;\r\n            x *= x;\r\n            n >>= 1;\r\n        }\r\n\
    \        return res;\r\n    }\r\n    constexpr modint inv() const {\r\n      \
    \  assert(_v);\r\n        return pow(umod() - 2);\r\n    }\r\n\r\n    friend modint\
    \ operator+(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
    \ += rhs;\r\n    }\r\n    friend modint operator-(const modint &lhs, const modint\
    \ &rhs) {\r\n        return modint(lhs) -= rhs;\r\n    }\r\n    friend modint\
    \ operator*(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
    \ *= rhs;\r\n    }\r\n\r\n    friend modint operator/(const modint &lhs, const\
    \ modint &rhs) {\r\n        return modint(lhs) /= rhs;\r\n    }\r\n    friend\
    \ bool operator==(const modint &lhs, const modint &rhs) {\r\n        return lhs.val()\
    \ == rhs.val();\r\n    }\r\n    friend bool operator!=(const modint &lhs, const\
    \ modint &rhs) {\r\n        return !(lhs == rhs);\r\n    }\r\n\r\n  private:\r\
    \n    unsigned int _v = 0;\r\n\r\n    static constexpr unsigned int umod() {\r\
    \n        return m;\r\n    }\r\n};\r\n\r\ntemplate <int m>\r\nstd::istream &operator>>(std::istream\
    \ &os, static_modint<m> &a) {\r\n    long long x;\r\n    os >> x;\r\n    a = x;\r\
    \n    return os;\r\n}\r\ntemplate <int m>\r\nstd::ostream &operator<<(std::ostream\
    \ &os, const static_modint<m> &a) {\r\n    return os << a.val();\r\n}\r\n\r\n\
    using modint998244353 = static_modint<998244353>;\r\nusing modint1000000007 =\
    \ static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 9 \"test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp\"\
    \n\nusing mint = ebi::modint998244353;\n\nint main() {\n    int n, k;\n    std::cin\
    \ >> n >> k;\n    std::vector<mint> f(n);\n    for (int i = 0; i < k; i++) {\n\
    \        int idx, a;\n        std::cin >> idx >> a;\n        f[idx] = a;\n   \
    \ }\n    auto g = ebi::inv_sparse(f, n);\n    for (int i = 0; i < n; i++) {\n\
    \        std::cout << g[i].val() << \" \\n\"[i == n - 1];\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../fps/fps_sparse.hpp\"\
    \n#include \"../../utility/modint.hpp\"\n\nusing mint = ebi::modint998244353;\n\
    \nint main() {\n    int n, k;\n    std::cin >> n >> k;\n    std::vector<mint>\
    \ f(n);\n    for (int i = 0; i < k; i++) {\n        int idx, a;\n        std::cin\
    \ >> idx >> a;\n        f[idx] = a;\n    }\n    auto g = ebi::inv_sparse(f, n);\n\
    \    for (int i = 0; i < n; i++) {\n        std::cout << g[i].val() << \" \\n\"\
    [i == n - 1];\n    }\n}"
  dependsOn:
  - fps/fps_sparse.hpp
  - utility/modint_func.hpp
  - utility/modint.hpp
  - utility/modint_base.hpp
  isVerificationFile: true
  path: test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
  requiredBy: []
  timestamp: '2023-06-12 01:02:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
layout: document
redirect_from:
- /verify/test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
- /verify/test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp.html
title: test/polynomial/Inv_of_Formal_Power_Series_Sparse.test.cpp
---