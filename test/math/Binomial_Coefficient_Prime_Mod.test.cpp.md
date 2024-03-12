---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: math/binomial.hpp
    title: Binomial Coefficient
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':heavy_check_mark:'
    path: modint/dynamic_modint.hpp
    title: modint/dynamic_modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"test/math/Binomial_Coefficient_Prime_Mod.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\n\
    \n#line 2 \"math/binomial.hpp\"\n\n#include <bit>\n#include <cassert>\n#include\
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
    \ = std::vector<mint>(2, 1);\n\n}  // namespace ebi\n#line 2 \"modint/dynamic_modint.hpp\"\
    \n\n#line 4 \"modint/dynamic_modint.hpp\"\n\n#line 6 \"modint/dynamic_modint.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <int id> struct dynamic_modint {\n  private:\n\
    \    using modint = dynamic_modint;\n\n  public:\n    static void set_mod(int\
    \ p) {\n        assert(1 <= p);\n        m = p;\n    }\n\n    static int mod()\
    \ {\n        return m;\n    }\n\n    modint raw(int v) {\n        modint x;\n\
    \        x._v = v;\n        return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n\
    \n    dynamic_modint(long long v) {\n        v %= (long long)umod();\n       \
    \ if (v < 0) v += (long long)umod();\n        _v = (unsigned int)v;\n    }\n\n\
    \    unsigned int val() const {\n        return _v;\n    }\n\n    unsigned int\
    \ value() const {\n        return val();\n    }\n\n    modint &operator++() {\n\
    \        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n   \
    \ }\n    modint &operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    modint &operator+=(const modint &rhs) {\n \
    \       _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n        return\
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
    \ = 998244353;\n\n}  // namespace ebi\n#line 1 \"template/template.hpp\"\n#include\
    \ <bits/stdc++.h>\n\n#define rep(i, a, n) for (int i = (int)(a); i < (int)(n);\
    \ i++)\n#define rrep(i, a, n) for (int i = ((int)(n)-1); i >= (int)(a); i--)\n\
    #define Rep(i, a, n) for (i64 i = (i64)(a); i < (i64)(n); i++)\n#define RRep(i,\
    \ a, n) for (i64 i = ((i64)(n)-i64(1)); i >= (i64)(a); i--)\n#define all(v) (v).begin(),\
    \ (v).end()\n#define rall(v) (v).rbegin(), (v).rend()\n\n#line 2 \"template/debug_template.hpp\"\
    \n\n#line 4 \"template/debug_template.hpp\"\n\nnamespace ebi {\n\n#ifdef LOCAL\n\
    #define debug(...)                                                      \\\n \
    \   std::cerr << \"LINE: \" << __LINE__ << \"  [\" << #__VA_ARGS__ << \"]:\",\
    \ \\\n        debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\nvoid\
    \ debug_out() {\n    std::cerr << std::endl;\n}\n\ntemplate <typename Head, typename...\
    \ Tail> void debug_out(Head h, Tail... t) {\n    std::cerr << \" \" << h;\n  \
    \  if (sizeof...(t) > 0) std::cerr << \" :\";\n    debug_out(t...);\n}\n\n}  //\
    \ namespace ebi\n#line 2 \"template/int_alias.hpp\"\n\n#line 4 \"template/int_alias.hpp\"\
    \n\nnamespace ebi {\n\nusing ld = long double;\nusing std::size_t;\nusing i8 =\
    \ std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing u16\
    \ = std::uint16_t;\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing\
    \ i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n\n}  // namespace ebi\n#line 2 \"template/io.hpp\"\n\
    \n#line 5 \"template/io.hpp\"\n#include <optional>\n#line 7 \"template/io.hpp\"\
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
    \n\n#line 2 \"graph/base.hpp\"\n\n#line 7 \"graph/base.hpp\"\n\n#line 2 \"data_structure/simple_csr.hpp\"\
    \n\n#line 6 \"data_structure/simple_csr.hpp\"\n\nnamespace ebi {\n\ntemplate <class\
    \ E> struct simple_csr {\n    simple_csr() = default;\n\n    simple_csr(int n,\
    \ const std::vector<std::pair<int, E>>& elements)\n        : start(n + 1, 0),\
    \ elist(elements.size()) {\n        for (auto e : elements) {\n            start[e.first\
    \ + 1]++;\n        }\n        for (auto i : std::views::iota(0, n)) {\n      \
    \      start[i + 1] += start[i];\n        }\n        auto counter = start;\n \
    \       for (auto [i, e] : elements) {\n            elist[counter[i]++] = e;\n\
    \        }\n    }\n\n    simple_csr(const std::vector<std::vector<E>>& es)\n \
    \       : start(es.size() + 1, 0) {\n        int n = es.size();\n        for (auto\
    \ i : std::views::iota(0, n)) {\n            start[i + 1] = (int)es[i].size()\
    \ + start[i];\n        }\n        elist.resize(start.back());\n        for (auto\
    \ i : std::views::iota(0, n)) {\n            std::copy(es[i].begin(), es[i].end(),\
    \ elist.begin() + start[i]);\n        }\n    }\n\n    int size() const {\n   \
    \     return (int)start.size() - 1;\n    }\n\n    const auto operator[](int i)\
    \ const {\n        return std::ranges::subrange(elist.begin() + start[i],\n  \
    \                                   elist.begin() + start[i + 1]);\n    }\n  \
    \  auto operator[](int i) {\n        return std::ranges::subrange(elist.begin()\
    \ + start[i],\n                                     elist.begin() + start[i +\
    \ 1]);\n    }\n\n    const auto operator()(int i, int l, int r) const {\n    \
    \    return std::ranges::subrange(elist.begin() + start[i] + l,\n            \
    \                         elist.begin() + start[i + 1] + r);\n    }\n    auto\
    \ operator()(int i, int l, int r) {\n        return std::ranges::subrange(elist.begin()\
    \ + start[i] + l,\n                                     elist.begin() + start[i\
    \ + 1] + r);\n    }\n\n  private:\n    std::vector<int> start;\n    std::vector<E>\
    \ elist;\n};\n\n}  // namespace ebi\n#line 9 \"graph/base.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <class T> struct Edge {\n    int to;\n    T cost;\n    int id;\n\
    };\n\ntemplate <class E> struct Graph {\n  private:\n    using cost_type = E;\n\
    \    using edge_type = Edge<cost_type>;\n\n  public:\n    Graph(int n_) : n(n_)\
    \ {}\n\n    Graph() = default;\n\n    void add_edge(int u, int v, cost_type c)\
    \ {\n        edges.emplace_back(u, edge_type{v, c, m++});\n    }\n\n    void read_tree(int\
    \ offset = 1, bool is_weighted = false) {\n        read_graph(n - 1, offset, false,\
    \ is_weighted);\n    }\n\n    void read_parents(int offset = 1) {\n        for\
    \ (auto i : std::views::iota(1, n)) {\n            int p;\n            std::cin\
    \ >> p;\n            p -= offset;\n            add_edge(p, i, 1);\n          \
    \  add_edge(i, p, 1);\n        }\n        build();\n    }\n\n    void read_graph(int\
    \ e, int offset = 1, bool is_directed = false,\n                    bool is_weighted\
    \ = false) {\n        for (int i = 0; i < e; i++) {\n            int u, v;\n \
    \           std::cin >> u >> v;\n            u -= offset;\n            v -= offset;\n\
    \            if (is_weighted) {\n                cost_type c;\n              \
    \  std::cin >> c;\n                add_edge(u, v, c);\n                if (!is_directed)\
    \ {\n                    add_edge(v, u, c);\n                }\n            }\
    \ else {\n                add_edge(u, v, 1);\n                if (!is_directed)\
    \ {\n                    add_edge(v, u, 1);\n                }\n            }\n\
    \        }\n        build();\n    }\n\n    void build() {\n        assert(!prepared);\n\
    \        csr = simple_csr<edge_type>(n, edges);\n        edges.clear();\n    \
    \    prepared = true;\n    }\n\n    int size() const {\n        return n;\n  \
    \  }\n\n    const auto operator[](int i) const {\n        return csr[i];\n   \
    \ }\n    auto operator[](int i) {\n        return csr[i];\n    }\n\n  private:\n\
    \    int n, m = 0;\n\n    std::vector<std::pair<int, edge_type>> edges;\n    simple_csr<edge_type>\
    \ csr;\n    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 8 \"template/utility.hpp\"\
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
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 6 \"test/math/Binomial_Coefficient_Prime_Mod.test.cpp\"\
    \n\nnamespace ebi {\n\nusing mint = dynamic_modint<0>;\n\nvoid main_() {\n   \
    \ int t, m;\n    std::cin >> t >> m;\n    mint::set_mod(m);\n    Binomial<mint>::reserve(std::min(m\
    \ - 1, 10'000'000));\n    rep(i, 0, t) {\n        int n, k;\n        std::cin\
    \ >> n >> k;\n        std::cout << Binomial<mint>::c(n, k).val() << '\\n';\n \
    \   }\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int\
    \ t = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n  \
    \  }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include \"../../math/binomial.hpp\"\n#include \"../../modint/dynamic_modint.hpp\"\
    \n#include \"../../template/template.hpp\"\n\nnamespace ebi {\n\nusing mint =\
    \ dynamic_modint<0>;\n\nvoid main_() {\n    int t, m;\n    std::cin >> t >> m;\n\
    \    mint::set_mod(m);\n    Binomial<mint>::reserve(std::min(m - 1, 10'000'000));\n\
    \    rep(i, 0, t) {\n        int n, k;\n        std::cin >> n >> k;\n        std::cout\
    \ << Binomial<mint>::c(n, k).val() << '\\n';\n    }\n}\n\n}  // namespace ebi\n\
    \nint main() {\n    ebi::fast_io();\n    int t = 1;\n    // std::cin >> t;\n \
    \   while (t--) {\n        ebi::main_();\n    }\n    return 0;\n}"
  dependsOn:
  - math/binomial.hpp
  - modint/base.hpp
  - modint/dynamic_modint.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: true
  path: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
  requiredBy: []
  timestamp: '2024-03-12 17:35:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
layout: document
redirect_from:
- /verify/test/math/Binomial_Coefficient_Prime_Mod.test.cpp
- /verify/test/math/Binomial_Coefficient_Prime_Mod.test.cpp.html
title: test/math/Binomial_Coefficient_Prime_Mod.test.cpp
---
