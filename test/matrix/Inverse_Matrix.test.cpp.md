---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: Graph (CSR format)
  - icon: ':heavy_check_mark:'
    path: matrix/base.hpp
    title: matrix/base.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/inverse_matrix
    links:
    - https://judge.yosupo.jp/problem/inverse_matrix
  bundledCode: "#line 1 \"test/matrix/Inverse_Matrix.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/inverse_matrix\"\n\n#line 2 \"matrix/base.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <ranges>\n\
    #include <vector>\n\nnamespace ebi {\n\ntemplate <class T> struct matrix;\n\n\
    template <class T> matrix<T> identify_matrix(int n) {\n    matrix<T> a(n, n);\n\
    \    for (int i = 0; i < n; i++) {\n        a[i][i] = 1;\n    }\n    return a;\n\
    }\n\ntemplate <class T> struct matrix {\n  private:\n    using Self = matrix<T>;\n\
    \n  public:\n    matrix(int n_, int m_, T init_val = 0)\n        : n(n_), m(m_),\
    \ data(n * m, init_val) {}\n\n    matrix(const std::vector<std::vector<T>> &a)\n\
    \        : n((int)a.size()), m((int)a[0].size()) {\n        data = std::vector(n\
    \ * m);\n        for (int i = 0; i < n; i++) {\n            std::copy(a[i].begin(),\
    \ a[i].end(), data.begin() + i * m);\n        }\n    }\n\n    Self operator+(Self\
    \ &rhs) const noexcept {\n        return Self(*this) += rhs;\n    }\n\n    Self\
    \ operator-(Self &rhs) const noexcept {\n        return Self(*this) -= rhs;\n\
    \    }\n\n    Self operator*(Self &rhs) const noexcept {\n        return Self(*this)\
    \ *= rhs;\n    }\n\n    Self operator/(Self &rhs) const noexcept {\n        return\
    \ Self(*this) /= rhs;\n    }\n\n    friend Self operator*(const T &lhs, const\
    \ Self &rhs) {\n        return Self(rhs) *= lhs;\n    }\n\n    friend Self operator*(const\
    \ Self &lhs, const T &rhs) {\n        return Self(lhs) *= rhs;\n    }\n\n    Self\
    \ &operator+=(Self &rhs) noexcept {\n        assert(this->size() == rhs.size());\n\
    \        for (int i = 0; i < n; ++i) {\n            for (int j = 0; j < m; ++j)\
    \ {\n                data[i][j] += rhs[i][j];\n            }\n        }\n    \
    \    return *this;\n    }\n\n    Self &operator-=(Self &rhs) noexcept {\n    \
    \    assert(this->size() == rhs.size());\n        for (int i = 0; i < n; ++i)\
    \ {\n            for (int j = 0; j < m; ++j) {\n                data[i][j] -=\
    \ rhs[i][j];\n            }\n        }\n        return *this;\n    }\n\n    Self\
    \ &operator*=(Self &rhs) noexcept {\n        int h = n, w = rhs.column_size();\n\
    \        assert(m == rhs.row_size());\n        Self ret(h, w);\n        for (int\
    \ i = 0; i < h; ++i) {\n            for (int k = 0; k < m; ++k) {\n          \
    \      for (int j = 0; j < w; ++j) {\n                    ret[i][j] += (*this)[i][k]\
    \ * rhs[k][j];\n                }\n            }\n        }\n        return *this\
    \ = ret;\n    }\n\n    Self &operator/=(const Self &rhs) noexcept {\n        auto\
    \ ret = rhs.inv();\n        assert(ret);\n        return *this *= ret.value();\n\
    \    }\n\n    Self &operator*=(const T &rhs) noexcept {\n        for (int i =\
    \ 0; i < n; i++) {\n            for (int j = 0; j < m; j++) {\n              \
    \  (*this)[i][j] *= rhs;\n            }\n        }\n        return *this;\n  \
    \  }\n\n    const auto operator[](int i) const {\n        return std::ranges::subrange(data.begin()\
    \ + i * m,\n                                     data.begin() + (i + 1) * m);\n\
    \    }\n\n    auto operator[](int i) {\n        return std::ranges::subrange(data.begin()\
    \ + i * m,\n                                     data.begin() + (i + 1) * m);\n\
    \    }\n\n    void swap(int i, int j) {\n        std::swap_ranges(data.begin()\
    \ + i * m, data.begin() + (i + 1) * m,\n                         data.begin()\
    \ + j * m);\n    }\n\n    Self transposition() const {\n        Self res(m, n);\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = 0; j < m; j++)\
    \ {\n                res[j][i] = data[i][j];\n            }\n        }\n     \
    \   return res;\n    }\n\n    std::optional<Self> inv() const {\n        assert(row_size()\
    \ == column_size());\n        Self a = *this;\n        Self b = identify_matrix<T>(n);\n\
    \        for (int r = 0; r < n; r++) {\n            for (int i = r; i < n; i++)\
    \ {\n                if (a[i][r] != 0) {\n                    a.swap(r, i);\n\
    \                    b.swap(r, i);\n                    break;\n             \
    \   }\n            }\n            if (a[r][r] == 0) return std::nullopt;\n   \
    \         T x = a[r][r].inv();\n            for (int j = 0; j < n; j++) {\n  \
    \              if (r < j) a[r][j] *= x;\n                b[r][j] *= x;\n     \
    \       }\n            for (int i = 0; i < n; i++) {\n                if (i ==\
    \ r) continue;\n                for (int j = 0; j < n; j++) {\n              \
    \      if (r < j) a[i][j] -= a[i][r] * a[r][j];\n                    b[i][j] -=\
    \ a[i][r] * b[r][j];\n                }\n            }\n        }\n        return\
    \ b;\n    }\n\n    Self pow(long long k) const {\n        assert(row_size() ==\
    \ column_size() && k >= 0);\n        Self res = identify_matrix<T>(row_size());\n\
    \        Self x = *this;\n        while (k) {\n            if (k & 1) res *= x;\n\
    \            x *= x;\n            k >>= 1;\n        }\n        return res;\n \
    \   }\n\n    int row_size() const {\n        return n;\n    }\n\n    int column_size()\
    \ const {\n        return m;\n    }\n\n    std::pair<int, int> size() const {\n\
    \        return {n, m};\n    }\n\n  private:\n    int n, m;\n    std::vector<T>\
    \ data;\n};\n\ntemplate <class T> T det(matrix<T> a) {\n    assert(a.row_size()\
    \ == a.column_size());\n    T d = 1;\n    int n = a.row_size();\n    for (int\
    \ r = 0; r < n; r++) {\n        if (a[r][r] == 0) {\n            for (int i =\
    \ r + 1; i < n; i++) {\n                if (a[i][r] != 0) {\n                \
    \    a.swap(r, i);\n                    d = -d;\n                }\n         \
    \   }\n        }\n        if (a[r][r] == 0) return 0;\n        d *= a[r][r];\n\
    \        T inv = a[r][r].inv();\n        for (int i = r + 1; i < n; i++) {\n \
    \           T x = a[i][r] * inv;\n            for (int j = r; j < n; j++) {\n\
    \                a[i][j] -= x * a[r][j];\n            }\n        }\n    }\n  \
    \  return d;\n}\n\ntemplate <class T> std::istream &operator>>(std::istream &os,\
    \ matrix<T> &a) {\n    for (int i = 0; i < a.row_size(); i++) {\n        for (int\
    \ j = 0; j < a.column_size(); j++) {\n            os >> a[i][j];\n        }\n\
    \    }\n    return os;\n}\n\ntemplate <class T>\nstd::ostream &operator<<(std::ostream\
    \ &os, const matrix<T> &a) {\n    for (int i = 0; i < a.row_size(); i++) {\n \
    \       for (int j = 0; j < a.column_size(); j++) {\n            os << a[i][j];\n\
    \            if (j < a.column_size() - 1) os << ' ';\n        }\n        if (i\
    \ < a.row_size() - 1) os << '\\n';\n    }\n    return os;\n}\n\n}  // namespace\
    \ ebi\n#line 2 \"modint/modint.hpp\"\n\r\n#line 5 \"modint/modint.hpp\"\n\r\n\
    #line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#line 5 \"modint/base.hpp\"\
    \n#include <utility>\n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint\
    \ = requires(T a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n   \
    \ a.inv();\n    a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n\
    };\n\ntemplate <Modint mint> std::istream &operator>>(std::istream &os, mint &a)\
    \ {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate\
    \ <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const mint &a) {\n\
    \    return os << a.val();\n}\n\n}  // namespace ebi\n#line 7 \"modint/modint.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <int m> struct static_modint {\r\n  private:\r\
    \n    using modint = static_modint;\r\n\r\n  public:\r\n    static constexpr int\
    \ mod() {\r\n        return m;\r\n    }\r\n\r\n    static constexpr modint raw(int\
    \ v) {\r\n        modint x;\r\n        x._v = v;\r\n        return x;\r\n    }\r\
    \n\r\n    constexpr static_modint() : _v(0) {}\r\n\r\n    template <std::signed_integral\
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
    \n\n#line 5 \"template/utility.hpp\"\n\n#line 2 \"graph/base.hpp\"\n\n#line 7\
    \ \"graph/base.hpp\"\n\n#line 2 \"data_structure/simple_csr.hpp\"\n\n#line 6 \"\
    data_structure/simple_csr.hpp\"\n\nnamespace ebi {\n\ntemplate <class E> struct\
    \ simple_csr {\n    simple_csr() = default;\n\n    simple_csr(int n, const std::vector<std::pair<int,\
    \ E>>& elements)\n        : start(n + 1, 0), elist(elements.size()) {\n      \
    \  for (auto e : elements) {\n            start[e.first + 1]++;\n        }\n \
    \       for (auto i : std::views::iota(0, n)) {\n            start[i + 1] += start[i];\n\
    \        }\n        auto counter = start;\n        for (auto [i, e] : elements)\
    \ {\n            elist[counter[i]++] = e;\n        }\n    }\n\n    simple_csr(const\
    \ std::vector<std::vector<E>>& es)\n        : start(es.size() + 1, 0) {\n    \
    \    int n = es.size();\n        for (auto i : std::views::iota(0, n)) {\n   \
    \         start[i + 1] = (int)es[i].size() + start[i];\n        }\n        elist.resize(start.back());\n\
    \        for (auto i : std::views::iota(0, n)) {\n            std::copy(es[i].begin(),\
    \ es[i].end(), elist.begin() + start[i]);\n        }\n    }\n\n    int size()\
    \ const {\n        return (int)start.size() - 1;\n    }\n\n    const auto operator[](int\
    \ i) const {\n        return std::ranges::subrange(elist.begin() + start[i],\n\
    \                                     elist.begin() + start[i + 1]);\n    }\n\
    \    auto operator[](int i) {\n        return std::ranges::subrange(elist.begin()\
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
    \ 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 6 \"test/matrix/Inverse_Matrix.test.cpp\"\
    \n\nnamespace ebi {\n\nusing mint = modint998244353;\n\nvoid main_() {\n    int\
    \ n;\n    std::cin >> n;\n    matrix<mint> a(n, n);\n    std::cin >> a;\n    auto\
    \ inv_a = a.inv();\n    if (!inv_a) {\n        std::cout << \"-1\\n\";\n    }\
    \ else {\n        std::cout << inv_a.value() << '\\n';\n    }\n}\n\n}  // namespace\
    \ ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n    // std::cin >>\
    \ t;\n    while (t--) {\n        ebi::main_();\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\n\n#include\
    \ \"../../matrix/base.hpp\"\n#include \"../../modint/modint.hpp\"\n#include \"\
    ../../template/template.hpp\"\n\nnamespace ebi {\n\nusing mint = modint998244353;\n\
    \nvoid main_() {\n    int n;\n    std::cin >> n;\n    matrix<mint> a(n, n);\n\
    \    std::cin >> a;\n    auto inv_a = a.inv();\n    if (!inv_a) {\n        std::cout\
    \ << \"-1\\n\";\n    } else {\n        std::cout << inv_a.value() << '\\n';\n\
    \    }\n}\n\n}  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int\
    \ t = 1;\n    // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n  \
    \  }\n    return 0;\n}"
  dependsOn:
  - matrix/base.hpp
  - modint/modint.hpp
  - modint/base.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  isVerificationFile: true
  path: test/matrix/Inverse_Matrix.test.cpp
  requiredBy: []
  timestamp: '2024-05-23 18:52:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/matrix/Inverse_Matrix.test.cpp
layout: document
redirect_from:
- /verify/test/matrix/Inverse_Matrix.test.cpp
- /verify/test/matrix/Inverse_Matrix.test.cpp.html
title: test/matrix/Inverse_Matrix.test.cpp
---
