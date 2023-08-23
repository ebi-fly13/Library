---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  - icon: ':heavy_check_mark:'
    path: math/DirichletSeries.hpp
    title: Dirichlet Series
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
    path: utility/modint.hpp
    title: utility/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_totient_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_totient_function
  bundledCode: "#line 1 \"test/math/Sum_of_Totient_Function.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\n\n#line 2 \"graph/template.hpp\"\
    \n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class T> struct\
    \ Edge {\r\n    int to;\r\n    T cost;\r\n    Edge(int _to, T _cost = 1) : to(_to),\
    \ cost(_cost) {}\r\n};\r\n\r\ntemplate <class T> struct Graph : std::vector<std::vector<Edge<T>>>\
    \ {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\n    void add_edge(int\
    \ u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if (directed) return;\r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if (directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\n#line 2 \"math/DirichletSeries.hpp\"\n\r\n#include <functional>\r\n#include\
    \ <numeric>\r\n#line 6 \"math/DirichletSeries.hpp\"\n\r\n#line 2 \"template/int_alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace ebi {\n\nusing std::size_t;\nusing i8 = std::int8_t;\n\
    using u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing u16 = std::uint16_t;\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    \n}\n#line 8 \"math/DirichletSeries.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate\
    \ <class T, int id> struct DirichletSeries {\r\n  private:\r\n    using Self =\
    \ DirichletSeries<T, id>;\r\n\r\n    void set(std::function<T(i64)> f, std::function<T(i64)>\
    \ F) {\r\n        for (int i = 1; i <= K; i++) {\r\n            a[i] = f(i);\r\
    \n        }\r\n        for (int i = 1; i <= L; i++) {\r\n            A[i] = F(N\
    \ / i);\r\n        }\r\n    }\r\n\r\n  public:\r\n    DirichletSeries() : a(K\
    \ + 1), A(L + 1) {}\r\n\r\n    DirichletSeries(std::function<T(i64)> f, std::function<T(i64)>\
    \ F)\r\n        : a(K + 1), A(L + 1) {\r\n        set(f, F);\r\n    }\r\n\r\n\
    \    Self operator+(const Self &rhs) const noexcept {\r\n        return Self(*this)\
    \ += rhs;\r\n    }\r\n    Self operator-(const Self &rhs) const noexcept {\r\n\
    \        return Self(*this) -= rhs;\r\n    }\r\n    Self operator*(const Self\
    \ &rhs) const noexcept {\r\n        return Self(*this) *= rhs;\r\n    }\r\n  \
    \  Self operator/(const Self &rhs) const noexcept {\r\n        return Self(*this)\
    \ /= rhs;\r\n    }\r\n\r\n    Self operator+=(const Self &rhs) noexcept {\r\n\
    \        for (int i = 1; i <= K; i++) {\r\n            a[i] += rhs.a[i];\r\n \
    \       }\r\n        for (int i = 1; i <= L; i++) {\r\n            A[i] += rhs.A[i];\r\
    \n        }\r\n        return *this;\r\n    }\r\n\r\n    Self operator-=(const\
    \ Self &rhs) noexcept {\r\n        for (int i = 1; i <= K; i++) {\r\n        \
    \    a[i] -= rhs.a[i];\r\n        }\r\n        for (int i = 1; i <= L; i++) {\r\
    \n            A[i] -= rhs.A[i];\r\n        }\r\n        return *this;\r\n    }\r\
    \n\r\n    Self operator*=(const Self &rhs) noexcept {\r\n        Self ret;\r\n\
    \        for (int i = 1; i <= K; i++) {\r\n            for (int j = 1; i * j <=\
    \ K; j++) {\r\n                ret.a[i * j] += a[i] * rhs.a[j];\r\n          \
    \  }\r\n        }\r\n        std::vector<T> sum_a = a, sum_b = rhs.a;\r\n    \
    \    for (int i = 1; i < K; i++) {\r\n            sum_a[i + 1] += sum_a[i];\r\n\
    \            sum_b[i + 1] += sum_b[i];\r\n        }\r\n        auto get_A = [&](i64\
    \ x) -> T {\r\n            if (x <= K) {\r\n                return sum_a[x];\r\
    \n            } else {\r\n                return A[N / x];\r\n            }\r\n\
    \        };\r\n        auto get_B = [&](i64 x) -> T {\r\n            if (x <=\
    \ K) {\r\n                return sum_b[x];\r\n            } else {\r\n       \
    \         return rhs.A[N / x];\r\n            }\r\n        };\r\n        for (i64\
    \ l = L, m = 1; l >= 1; l--) {\r\n            i64 n = N / l;\r\n            while\
    \ (m * m <= n) m++;\r\n            m--;\r\n            for (int i = 1; i <= m;\
    \ i++) {\r\n                ret.A[l] +=\r\n                    a[i] * get_B(n\
    \ / i) + (get_A(n / i) - get_A(m)) * rhs.a[i];\r\n            }\r\n        }\r\
    \n        return *this = ret;\r\n    }\r\n\r\n    // c = a / b\r\n    Self operator/=(const\
    \ Self &b) noexcept {\r\n        Self c = *this;\r\n        T inv_a = b.a[1].inv();\r\
    \n        for (int i = 1; i <= K; i++) {\r\n            c.a[i] *= inv_a;\r\n \
    \           for (int j = 2; i * j <= K; j++) {\r\n                c.a[i * j] -=\
    \ c.a[i] * b.a[j];\r\n            }\r\n        }\r\n        std::vector<T> sum_b\
    \ = b.a, sum_c = c.a;\r\n        for (int i = 1; i < K; ++i) {\r\n           \
    \ sum_b[i + 1] += sum_b[i];\r\n            sum_c[i + 1] += sum_c[i];\r\n     \
    \   }\r\n        auto get_B = [&](i64 x) -> T {\r\n            if (x <= K) {\r\
    \n                return sum_b[x];\r\n            } else {\r\n               \
    \ return b.A[N / x];\r\n            }\r\n        };\r\n        auto get_C = [&](i64\
    \ x) -> T {\r\n            if (x <= K) {\r\n                return sum_c[x];\r\
    \n            } else {\r\n                return c.A[N / x];\r\n            }\r\
    \n        };\r\n        for (i64 l = L, m = 1; l >= 1; l--) {\r\n            i64\
    \ n = N / l;\r\n            while (m * m <= n) m++;\r\n            m--;\r\n  \
    \          for (int i = 2; i <= m; i++) {\r\n                c.A[l] -= b.a[i]\
    \ * get_C(n / i);\r\n            }\r\n\r\n            for (int i = 1; i <= m;\
    \ i++) {\r\n                c.A[l] -= c.a[i] * (get_B(n / i) - get_B(m));\r\n\
    \            }\r\n            c.A[l] *= inv_a;\r\n        }\r\n        return\
    \ *this = c;\r\n    }\r\n\r\n    Self pow(u64 n) const {\r\n        Self res;\r\
    \n        res.a[1] = 1;\r\n        std::fill(res.A.begin(), res.A.end(), 1);\r\
    \n        Self x = *this;\r\n        while (n > 0) {\r\n            if (n & 1)\
    \ res = res * x;\r\n            x = x * x;\r\n            n >>= 1;\r\n       \
    \ }\r\n        return res;\r\n    }\r\n\r\n    T get_sum() {\r\n        return\
    \ A[1];\r\n    }\r\n\r\n    static Self zeta() {\r\n        Self ret;\r\n    \
    \    std::fill(ret.a.begin(), ret.a.end(), 1);\r\n        for (int i = 1; i <=\
    \ L; i++) {\r\n            ret.A[i] = N / i;\r\n        }\r\n        return ret;\r\
    \n    }\r\n\r\n    static Self zeta1() {\r\n        Self ret;\r\n        std::iota(ret.a.begin(),\
    \ ret.a.end(), 0);\r\n        T inv2 = T(2).inv();\r\n        for (int i = 1;\
    \ i <= L; i++) {\r\n            i64 n = N / i;\r\n            ret.A[i] = T(n)\
    \ * T(n + 1) * inv2;\r\n        }\r\n        return ret;\r\n    }\r\n\r\n    static\
    \ void set_size(i64 n) {\r\n        N = n;\r\n        if (N <= 10) {\r\n     \
    \       K = N;\r\n            L = 1;\r\n        } else if (N <= 5000) {\r\n  \
    \          K = 1;\r\n            while (K * K < N) K++;\r\n            L = (N\
    \ + K - 1) / K;\r\n        } else {\r\n            L = 1;\r\n            while\
    \ (L * L * L / 50 < N) L++;\r\n            K = (N + L - 1) / L;\r\n        }\r\
    \n    }\r\n\r\n  private:\r\n    static i64 N, K, L;\r\n    std::vector<T> a,\
    \ A;\r\n};\r\n\r\ntemplate <class T, int id> i64 DirichletSeries<T, id>::N = 1000000;\r\
    \ntemplate <class T, int id> i64 DirichletSeries<T, id>::K = 10000;\r\ntemplate\
    \ <class T, int id> i64 DirichletSeries<T, id>::L = 100;\r\n\r\n}  // namespace\
    \ ebi\n#line 1 \"template/template.hpp\"\n#include <algorithm>\n#include <bitset>\n\
    #include <cassert>\n#include <chrono>\n#include <climits>\n#include <cmath>\n\
    #include <complex>\n#include <cstddef>\n#line 10 \"template/template.hpp\"\n#include\
    \ <cstdlib>\n#include <cstring>\n#line 13 \"template/template.hpp\"\n#include\
    \ <iomanip>\n#include <iostream>\n#include <limits>\n#include <map>\n#include\
    \ <memory>\n#line 19 \"template/template.hpp\"\n#include <optional>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <tuple>\n#include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#line 31 \"template/template.hpp\"\n\n#define rep(i, a, n)\
    \ for (int i = (int)(a); i < (int)(n); i++)\n#define rrep(i, a, n) for (int i\
    \ = ((int)(n)-1); i >= (int)(a); i--)\n#define Rep(i, a, n) for (i64 i = (i64)(a);\
    \ i < (i64)(n); i++)\n#define RRep(i, a, n) for (i64 i = ((i64)(n)-i64(1)); i\
    \ >= (i64)(a); i--)\n#define all(v) (v).begin(), (v).end()\n#define rall(v) (v).rbegin(),\
    \ (v).rend()\n\n#line 2 \"template/debug_template.hpp\"\n\n#line 4 \"template/debug_template.hpp\"\
    \n\nnamespace ebi {\n\n#ifdef LOCAL\n#define debug(...)                      \
    \                                \\\n    std::cerr << \"LINE: \" << __LINE__ <<\
    \ \"  [\" << #__VA_ARGS__ << \"]:\", \\\n        debug_out(__VA_ARGS__)\n#else\n\
    #define debug(...)\n#endif\n\nvoid debug_out() {\n    std::cerr << std::endl;\n\
    }\n\ntemplate <typename Head, typename... Tail> void debug_out(Head h, Tail...\
    \ t) {\n    std::cerr << \" \" << h;\n    if (sizeof...(t) > 0) std::cerr << \"\
    \ :\";\n    debug_out(t...);\n}\n\n}\n#line 2 \"template/io.hpp\"\n\n#line 6 \"\
    template/io.hpp\"\n\nnamespace ebi {\n\ntemplate <typename T1, typename T2>\n\
    std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &pa) {\n  \
    \  return os << pa.first << \" \" << pa.second;\n}\n\ntemplate <typename T1, typename\
    \ T2>\nstd::istream &operator>>(std::istream &os, std::pair<T1, T2> &pa) {\n \
    \   return os >> pa.first >> pa.second;\n}\n\ntemplate <typename T>\nstd::ostream\
    \ &operator<<(std::ostream &os, const std::vector<T> &vec) {\n    for (std::size_t\
    \ i = 0; i < vec.size(); i++)\n        os << vec[i] << (i + 1 == vec.size() ?\
    \ \"\" : \" \");\n    return os;\n}\n\ntemplate <typename T>\nstd::istream &operator>>(std::istream\
    \ &os, std::vector<T> &vec) {\n    for (T &e : vec) std::cin >> e;\n    return\
    \ os;\n}\n\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream &os,\
    \ const std::optional<T> &opt) {\n    if (opt) {\n        os << opt.value();\n\
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
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 2 \"utility/modint.hpp\"\n\r\n\
    #line 6 \"utility/modint.hpp\"\n\r\n#line 2 \"utility/modint_base.hpp\"\n\n#line\
    \ 4 \"utility/modint_base.hpp\"\n\nnamespace ebi {\n\nnamespace internal {\n\n\
    struct modint_base {};\n\ntemplate <class T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \nstruct static_modint_base : modint_base {};\n\ntemplate <class T>\nusing is_static_modint\
    \ = std::is_base_of<internal::static_modint_base, T>;\n\ntemplate <class T>\n\
    using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\n}\
    \  // namespace internal\n\n}  // namespace ebi\n#line 8 \"utility/modint.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <int m> struct static_modint : internal::static_modint_base\
    \ {\r\n  private:\r\n    using modint = static_modint;\r\n\r\n  public:\r\n  \
    \  static constexpr int mod() {\r\n        return m;\r\n    }\r\n\r\n    static\
    \ constexpr modint raw(int v) {\r\n        modint x;\r\n        x._v = v;\r\n\
    \        return x;\r\n    }\r\n\r\n    constexpr static_modint() : _v(0) {}\r\n\
    \r\n    constexpr static_modint(long long v) {\r\n        v %= (long long)umod();\r\
    \n        if (v < 0) v += (long long)umod();\r\n        _v = (unsigned int)v;\r\
    \n    }\r\n\r\n    constexpr unsigned int val() const {\r\n        return _v;\r\
    \n    }\r\n\r\n    constexpr unsigned int value() const {\r\n        return val();\r\
    \n    }\r\n\r\n    constexpr modint &operator++() {\r\n        _v++;\r\n     \
    \   if (_v == umod()) _v = 0;\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator--() {\r\n        if (_v == 0) _v = umod();\r\n        _v--;\r\
    \n        return *this;\r\n    }\r\n\r\n    constexpr modint operator++(int) {\r\
    \n        modint res = *this;\r\n        ++*this;\r\n        return res;\r\n \
    \   }\r\n    constexpr modint operator--(int) {\r\n        modint res = *this;\r\
    \n        --*this;\r\n        return res;\r\n    }\r\n\r\n    constexpr modint\
    \ &operator+=(const modint &rhs) {\r\n        _v += rhs._v;\r\n        if (_v\
    \ >= umod()) _v -= umod();\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator-=(const modint &rhs) {\r\n        _v -= rhs._v;\r\n       \
    \ if (_v >= umod()) _v += umod();\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator*=(const modint &rhs) {\r\n        unsigned long long x = _v;\r\
    \n        x *= rhs._v;\r\n        _v = (unsigned int)(x % (unsigned long long)umod());\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator/=(const modint\
    \ &rhs) {\r\n        return *this = *this * rhs.inv();\r\n    }\r\n\r\n    constexpr\
    \ modint operator+() const {\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint operator-() const {\r\n        return modint() - *this;\r\n    }\r\n\r\
    \n    constexpr modint pow(long long n) const {\r\n        assert(0 <= n);\r\n\
    \        modint x = *this, res = 1;\r\n        while (n) {\r\n            if (n\
    \ & 1) res *= x;\r\n            x *= x;\r\n            n >>= 1;\r\n        }\r\
    \n        return res;\r\n    }\r\n    constexpr modint inv() const {\r\n     \
    \   assert(_v);\r\n        return pow(umod() - 2);\r\n    }\r\n\r\n    friend\
    \ modint operator+(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
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
    \ static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 7 \"test/math/Sum_of_Totient_Function.test.cpp\"\
    \n\nnamespace ebi {\n\nusing mint = modint998244353;\n\nvoid main_() {\n    i64\
    \ n;\n    std::cin >> n;\n    using DirichletSeries = DirichletSeries<mint, 0>;\n\
    \    DirichletSeries::set_size(n);\n    mint ans = (DirichletSeries::zeta1() /\
    \ DirichletSeries::zeta()).get_sum();\n    std::cout << ans << '\\n';\n}\n\n}\
    \  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n   \
    \ // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n\n#include \"../../graph/template.hpp\"\n#include \"../../math/DirichletSeries.hpp\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../utility/modint.hpp\"\
    \n\nnamespace ebi {\n\nusing mint = modint998244353;\n\nvoid main_() {\n    i64\
    \ n;\n    std::cin >> n;\n    using DirichletSeries = DirichletSeries<mint, 0>;\n\
    \    DirichletSeries::set_size(n);\n    mint ans = (DirichletSeries::zeta1() /\
    \ DirichletSeries::zeta()).get_sum();\n    std::cout << ans << '\\n';\n}\n\n}\
    \  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n   \
    \ // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n    }\n    return\
    \ 0;\n}"
  dependsOn:
  - graph/template.hpp
  - math/DirichletSeries.hpp
  - template/int_alias.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/io.hpp
  - template/utility.hpp
  - utility/modint.hpp
  - utility/modint_base.hpp
  isVerificationFile: true
  path: test/math/Sum_of_Totient_Function.test.cpp
  requiredBy: []
  timestamp: '2023-08-23 13:42:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/Sum_of_Totient_Function.test.cpp
layout: document
redirect_from:
- /verify/test/math/Sum_of_Totient_Function.test.cpp
- /verify/test/math/Sum_of_Totient_Function.test.cpp.html
title: test/math/Sum_of_Totient_Function.test.cpp
---
