---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: NTT Convolution
  - icon: ':heavy_check_mark:'
    path: math/binomial.hpp
    title: Binomial Coefficient
  - icon: ':heavy_check_mark:'
    path: math/catalan_convolution.hpp
    title: Catalan's Convolution Formula
  - icon: ':heavy_check_mark:'
    path: math/catalan_number.hpp
    title: Catalan Number
  - icon: ':heavy_check_mark:'
    path: math/internal_math.hpp
    title: math/internal_math.hpp
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/math/Catalan_Convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"math/catalan_convolution.hpp\"\
    \n\n#line 2 \"math/binomial.hpp\"\n\n#include <bit>\n#include <cassert>\n#include\
    \ <iostream>\n#include <ranges>\n#include <vector>\n\n#line 2 \"modint/base.hpp\"\
    \n\n#include <concepts>\n#line 5 \"modint/base.hpp\"\n#include <utility>\n\nnamespace\
    \ ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n    a +\
    \ b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 10 \"\
    math/binomial.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint mint> struct Binomial\
    \ {\n  private:\n    static void extend(int len = -1) {\n        int sz = (int)fact.size();\n\
    \        if (len < 0)\n            len = 2 * sz;\n        else if (len <= sz)\n\
    \            return;\n        else\n            len = std::max(2 * sz, (int)std::bit_ceil(std::uint32_t(len)));\n\
    \        len = std::min(len, mint::mod());\n        assert(sz <= len);\n     \
    \   fact.resize(len);\n        inv_fact.resize(len);\n        for (int i : std::views::iota(sz,\
    \ len)) {\n            fact[i] = fact[i - 1] * i;\n        }\n        inv_fact[len\
    \ - 1] = fact[len - 1].inv();\n        for (int i : std::views::iota(sz, len)\
    \ | std::views::reverse) {\n            inv_fact[i - 1] = inv_fact[i] * i;\n \
    \       }\n    }\n\n  public:\n    Binomial() = default;\n\n    Binomial(int n)\
    \ {\n        extend(n + 1);\n    }\n\n    static mint f(int n) {\n        if (n\
    \ >= (int)fact.size()) [[unlikely]] {\n            extend(n + 1);\n        }\n\
    \        return fact[n];\n    }\n\n    static mint inv_f(int n) {\n        if\
    \ (n >= (int)fact.size()) [[unlikely]] {\n            extend(n + 1);\n       \
    \ }\n        return inv_fact[n];\n    }\n\n    static mint c(int n, int r) {\n\
    \        if (r < 0 || n < r) return 0;\n        return f(n) * inv_f(r) * inv_f(n\
    \ - r);\n    }\n\n    static mint p(int n, int r) {\n        if (r < 0 || n <\
    \ r) return 0;\n        return f(n) * inv_f(n - r);\n    }\n\n    static mint\
    \ inv(int n) {\n        return inv_f(n) * f(n - 1);\n    }\n\n    static void\
    \ reserve(int n) {\n        extend(n + 1);\n    }\n\n  private:\n    static std::vector<mint>\
    \ fact, inv_fact;\n};\n\ntemplate <Modint mint>\nstd::vector<mint> Binomial<mint>::fact\
    \ = std::vector<mint>(2, 1);\n\ntemplate <Modint mint>\nstd::vector<mint> Binomial<mint>::inv_fact\
    \ = std::vector<mint>(2, 1);\n\n}  // namespace ebi\n#line 5 \"math/catalan_convolution.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint> mint catalan_convolution(int pow,\
    \ int n) {\n    return Binomial<mint>::c(n + n + pow - 1, n) * pow *\n       \
    \    Binomial<mint>::inv(n + pow);\n}\n\n}  // namespace ebi\n#line 4 \"test/math/Catalan_Convolution.test.cpp\"\
    \n\n#line 2 \"convolution/ntt.hpp\"\n\n#include <algorithm>\n#include <array>\n\
    #line 8 \"convolution/ntt.hpp\"\n\n#line 2 \"math/internal_math.hpp\"\n\n#line\
    \ 4 \"math/internal_math.hpp\"\n\nnamespace ebi {\n\nnamespace internal {\n\n\
    constexpr int primitive_root_constexpr(int m) {\n    if (m == 2) return 1;\n \
    \   if (m == 167772161) return 3;\n    if (m == 469762049) return 3;\n    if (m\
    \ == 754974721) return 11;\n    if (m == 998244353) return 3;\n    if (m == 880803841)\
    \ return 26;\n    if (m == 924844033) return 5;\n    return -1;\n}\ntemplate <int\
    \ m> constexpr int primitive_root = primitive_root_constexpr(m);\n\n}  // namespace\
    \ internal\n\n}  // namespace ebi\n#line 11 \"convolution/ntt.hpp\"\n\nnamespace\
    \ ebi {\n\nnamespace internal {\n\ntemplate <Modint mint, int g = internal::primitive_root<mint::mod()>>\n\
    struct ntt_info {\n    static constexpr int rank2 =\n        std::countr_zero((unsigned\
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
    \ - 1);\n    return a;\n}\n\n}  // namespace ebi\n#line 2 \"math/catalan_number.hpp\"\
    \n\n#line 5 \"math/catalan_number.hpp\"\n\nnamespace ebi {\n\ntemplate <Modint\
    \ mint> mint catalan_number(int n) {\n    return Binomial<mint>::c(2 * n, n) *\
    \ Binomial<mint>::inv(n + 1);\n}\n\n}  // namespace ebi\n#line 2 \"modint/modint.hpp\"\
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
    \ 2 \"template/io.hpp\"\n\n#line 5 \"template/io.hpp\"\n#include <optional>\n\
    #line 7 \"template/io.hpp\"\n\nnamespace ebi {\n\ntemplate <typename T1, typename\
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
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 9 \"test/math/Catalan_Convolution.test.cpp\"\
    \n\nnamespace ebi {\n\nusing mint = modint998244353;\n\nvoid main_() {\n    const\
    \ int n = 100000;\n    int t = 10;\n    std::vector<mint> c(n);\n    rep(i, 0,\
    \ n) c[i] = catalan_number<mint>(i);\n    std::vector<mint> a = {1};\n    rep(i,\
    \ 1, t) {\n        a = convolution(a, c);\n        a.resize(n);\n        rep(j,\
    \ 0, n) assert(a[j] == catalan_convolution<mint>(i, j));\n    }\n    return;\n\
    }\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n\
    \    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n    }\n    int\
    \ a, b;\n    std::cin >> a >> b;\n    std::cout << a + b << '\\n';\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../math/catalan_convolution.hpp\"\n\n#include \"../../convolution/ntt.hpp\"\
    \n#include \"../../math/catalan_number.hpp\"\n#include \"../../modint/modint.hpp\"\
    \n#include \"../../template/template.hpp\"\n\nnamespace ebi {\n\nusing mint =\
    \ modint998244353;\n\nvoid main_() {\n    const int n = 100000;\n    int t = 10;\n\
    \    std::vector<mint> c(n);\n    rep(i, 0, n) c[i] = catalan_number<mint>(i);\n\
    \    std::vector<mint> a = {1};\n    rep(i, 1, t) {\n        a = convolution(a,\
    \ c);\n        a.resize(n);\n        rep(j, 0, n) assert(a[j] == catalan_convolution<mint>(i,\
    \ j));\n    }\n    return;\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n\
    \    int t = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n\
    \    }\n    int a, b;\n    std::cin >> a >> b;\n    std::cout << a + b << '\\\
    n';\n    return 0;\n}"
  dependsOn:
  - math/catalan_convolution.hpp
  - math/binomial.hpp
  - modint/base.hpp
  - convolution/ntt.hpp
  - math/internal_math.hpp
  - math/catalan_number.hpp
  - modint/modint.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  isVerificationFile: true
  path: test/math/Catalan_Convolution.test.cpp
  requiredBy: []
  timestamp: '2024-02-18 14:20:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/Catalan_Convolution.test.cpp
layout: document
redirect_from:
- /verify/test/math/Catalan_Convolution.test.cpp
- /verify/test/math/Catalan_Convolution.test.cpp.html
title: test/math/Catalan_Convolution.test.cpp
---