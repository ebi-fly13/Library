---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/binomial.hpp
    title: Binomial Coefficient
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
    path: utility/dynamic_modint.hpp
    title: utility/dynamic_modint.hpp
  - icon: ':heavy_check_mark:'
    path: utility/modint_base.hpp
    title: utility/modint_base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"test/math/Binomial_Coefficient_Prime_Mod.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\n\
    \n#line 2 \"math/binomial.hpp\"\n\n#include <cassert>\n#include <ranges>\n#include\
    \ <vector>\n\nnamespace ebi {\n\ntemplate <class mint> struct Binomial {\n  private:\n\
    \    static void extend(int len) {\n        int sz = (int)fact.size();\n     \
    \   assert(sz <= len);\n        fact.resize(len);\n        inv_fact.resize(len);\n\
    \        for (int i : std::views::iota(sz, len)) {\n            fact[i] = fact[i\
    \ - 1] * i;\n        }\n        inv_fact[len - 1] = fact[len - 1].inv();\n   \
    \     for (int i : std::views::iota(sz, len) | std::views::reverse) {\n      \
    \      inv_fact[i - 1] = inv_fact[i] * i;\n        }\n    }\n\n  public:\n   \
    \ Binomial(int n) {\n        extend(n + 1);\n    }\n\n    static mint c(int n,\
    \ int r) {\n        assert(n < (int)fact.size());\n        if (r < 0 || n < r)\
    \ return 0;\n        return fact[n] * inv_fact[r] * inv_fact[n - r];\n    }\n\n\
    \    static mint p(int n, int r) {\n        assert(n < (int)fact.size());\n  \
    \      if (r < 0 || n < r) return 0;\n        return fact[n] * inv_fact[n - r];\n\
    \    }\n\n    static mint f(int n) {\n        assert(n < (int)fact.size());\n\
    \        return fact[n];\n    }\n\n    static mint inv_f(int n) {\n        assert(n\
    \ < (int)fact.size());\n        return inv_fact[n];\n    }\n\n    static mint\
    \ inv(int n) {\n        assert(n < (int)fact.size());\n        return inv_fact[n]\
    \ * fact[n - 1];\n    }\n\n    static void reserve(int n) {\n        extend(n\
    \ + 1);\n    }\n\n  private:\n    static std::vector<mint> fact, inv_fact;\n};\n\
    \ntemplate <class mint>\nstd::vector<mint> Binomial<mint>::fact = std::vector<mint>(2,\
    \ 1);\n\ntemplate <class mint>\nstd::vector<mint> Binomial<mint>::inv_fact = std::vector<mint>(2,\
    \ 1);\n\n}  // namespace ebi\n#line 1 \"template/template.hpp\"\n#include <algorithm>\n\
    #include <bit>\n#include <bitset>\n#line 5 \"template/template.hpp\"\n#include\
    \ <chrono>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
    \ <cstddef>\n#include <cstdint>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <memory>\n#include <numbers>\n#include <numeric>\n#include <optional>\n\
    #include <queue>\n#include <random>\n#line 25 \"template/template.hpp\"\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <tuple>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#line\
    \ 34 \"template/template.hpp\"\n\n#define rep(i, a, n) for (int i = (int)(a);\
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
    \ :\";\n    debug_out(t...);\n}\n\n}\n#line 2 \"template/int_alias.hpp\"\n\n#line\
    \ 4 \"template/int_alias.hpp\"\n\nnamespace ebi {\n\nusing std::size_t;\nusing\
    \ i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing\
    \ u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\n}\n#line 2 \"template/io.hpp\"\n\n#line 7 \"template/io.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <typename T1, typename T2>\nstd::ostream &operator<<(std::ostream\
    \ &os, const std::pair<T1, T2> &pa) {\n    return os << pa.first << \" \" << pa.second;\n\
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
    \n\n#line 7 \"template/utility.hpp\"\n\nnamespace ebi {\n\ntemplate <class T>\
    \ inline bool chmin(T &a, T b) {\n    if (a > b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n\ntemplate <class T> inline bool chmax(T\
    \ &a, T b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\n\ntemplate <class T> T safe_ceil(T a, T b) {\n    if (a\
    \ % b == 0)\n        return a / b;\n    else if (a >= 0)\n        return (a /\
    \ b) + 1;\n    else\n        return -((-a) / b);\n}\n\ntemplate <class T> T safe_floor(T\
    \ a, T b) {\n    if (a % b == 0)\n        return a / b;\n    else if (a >= 0)\n\
    \        return a / b;\n    else\n        return -((-a) / b) - 1;\n}\n\nconstexpr\
    \ i64 LNF = std::numeric_limits<i64>::max() / 4;\n\nconstexpr int INF = std::numeric_limits<int>::max()\
    \ / 2;\n\nconst std::vector<int> dy = {1, 0, -1, 0, 1, 1, -1, -1};\nconst std::vector<int>\
    \ dx = {0, 1, 0, -1, 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 2 \"utility/dynamic_modint.hpp\"\
    \n\n#line 4 \"utility/dynamic_modint.hpp\"\n\n#line 2 \"utility/modint_base.hpp\"\
    \n\n#line 4 \"utility/modint_base.hpp\"\n\nnamespace ebi {\n\nnamespace internal\
    \ {\n\nstruct modint_base {};\n\ntemplate <class T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \nstruct static_modint_base : modint_base {};\n\ntemplate <class T>\nusing is_static_modint\
    \ = std::is_base_of<internal::static_modint_base, T>;\n\ntemplate <class T>\n\
    using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\n}\
    \  // namespace internal\n\n}  // namespace ebi\n#line 6 \"utility/dynamic_modint.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <int id> struct dynamic_modint : internal::modint_base\
    \ {\n  private:\n    using modint = dynamic_modint;\n\n  public:\n    static void\
    \ set_mod(int p) {\n        assert(1 <= p);\n        m = p;\n    }\n\n    static\
    \ int mod() {\n        return m;\n    }\n\n    modint raw(int v) {\n        modint\
    \ x;\n        x._v = v;\n        return x;\n    }\n\n    dynamic_modint() : _v(0)\
    \ {}\n\n    dynamic_modint(long long v) {\n        v %= (long long)umod();\n \
    \       if (v < 0) v += (long long)umod();\n        _v = (unsigned int)v;\n  \
    \  }\n\n    unsigned int val() const {\n        return _v;\n    }\n\n    unsigned\
    \ int value() const {\n        return val();\n    }\n\n    modint &operator++()\
    \ {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n\
    \    }\n    modint &operator--() {\n        if (_v == 0) _v = umod();\n      \
    \  _v--;\n        return *this;\n    }\n    modint &operator+=(const modint &rhs)\
    \ {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n        return\
    \ *this;\n    }\n    modint &operator-=(const modint &rhs) {\n        _v -= rhs._v;\n\
    \        if (_v >= umod()) _v += umod();\n        return *this;\n    }\n    modint\
    \ &operator*=(const modint &rhs) {\n        unsigned long long x = _v;\n     \
    \   x *= rhs._v;\n        _v = (unsigned int)(x % (unsigned long long)umod());\n\
    \        return *this;\n    }\n    modint &operator/=(const modint &rhs) {\n \
    \       return *this = *this * rhs.inv();\n    }\n\n    modint operator+() const\
    \ {\n        return *this;\n    }\n    modint operator-() const {\n        return\
    \ modint() - *this;\n    }\n\n    modint pow(long long n) const {\n        assert(0\
    \ <= n);\n        modint x = *this, res = 1;\n        while (n) {\n          \
    \  if (n & 1) res *= x;\n            x *= x;\n            n >>= 1;\n        }\n\
    \        return res;\n    }\n    modint inv() const {\n        assert(_v);\n \
    \       return pow(umod() - 2);\n    }\n\n    friend modint operator+(const modint\
    \ &lhs, const modint &rhs) {\n        return modint(lhs) += rhs;\n    }\n    friend\
    \ modint operator-(const modint &lhs, const modint &rhs) {\n        return modint(lhs)\
    \ -= rhs;\n    }\n    friend modint operator*(const modint &lhs, const modint\
    \ &rhs) {\n        return modint(lhs) *= rhs;\n    }\n\n    friend modint operator/(const\
    \ modint &lhs, const modint &rhs) {\n        return modint(lhs) /= rhs;\n    }\n\
    \    friend bool operator==(const modint &lhs, const modint &rhs) {\n        return\
    \ lhs.val() == rhs.val();\n    }\n    friend bool operator!=(const modint &lhs,\
    \ const modint &rhs) {\n        return !(lhs == rhs);\n    }\n\n  private:\n \
    \   unsigned int _v = 0;\n    static int m;\n\n    static unsigned int umod()\
    \ {\n        return m;\n    }\n};\n\ntemplate <int id> int dynamic_modint<id>::m\
    \ = 998244353;\n\n}  // namespace ebi\n#line 6 \"test/math/Binomial_Coefficient_Prime_Mod.test.cpp\"\
    \n\nnamespace ebi {\n\nusing mint = dynamic_modint<0>;\n\nvoid main_() {\n   \
    \ int t, m;\n    std::cin >> t >> m;\n    mint::set_mod(m);\n    Binomial<mint>::reserve(std::min(m\
    \ - 1, 10'000'000));\n    rep(i, 0, t) {\n        int n, k;\n        std::cin\
    \ >> n >> k;\n        std::cout << Binomial<mint>::c(n, k).val() << '\\n';\n \
    \   }\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int\
    \ t = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n  \
    \  }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include \"../../math/binomial.hpp\"\n#include \"../../template/template.hpp\"\
    \n#include \"../../utility/dynamic_modint.hpp\"\n\nnamespace ebi {\n\nusing mint\
    \ = dynamic_modint<0>;\n\nvoid main_() {\n    int t, m;\n    std::cin >> t >>\
    \ m;\n    mint::set_mod(m);\n    Binomial<mint>::reserve(std::min(m - 1, 10'000'000));\n\
    \    rep(i, 0, t) {\n        int n, k;\n        std::cin >> n >> k;\n        std::cout\
    \ << Binomial<mint>::c(n, k).val() << '\\n';\n    }\n}\n\n}  // namespace ebi\n\
    \nint main() {\n    ebi::fast_io();\n    int t = 1;\n    // std::cin >> t;\n \
    \   while (t--) {\n        ebi::main_();\n    }\n    return 0;\n}"
  dependsOn:
  - math/binomial.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  - utility/dynamic_modint.hpp
  - utility/modint_base.hpp
  isVerificationFile: true
  path: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  requiredBy: []
  timestamp: '2023-10-24 00:42:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
layout: document
redirect_from:
- /verify/test/math/Binomial_Coefficient_Prime_Mod.test.cpp
- /verify/test/math/Binomial_Coefficient_Prime_Mod.test.cpp.html
title: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
---
