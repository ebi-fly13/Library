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
    path: matrix/gauss_jordan.hpp
    title: matrix/gauss_jordan.hpp
  - icon: ':heavy_check_mark:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint61.hpp
    title: modint/modint61.hpp
  - icon: ':heavy_check_mark:'
    path: utility/random_number_generator.hpp
    title: Random Number Generator
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/maximum_matching_size.hpp\"\n\n#line 2 \"graph/base.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n#include <ranges>\n#include <vector>\n\
    \n#line 2 \"data_structure/simple_csr.hpp\"\n\n#line 4 \"data_structure/simple_csr.hpp\"\
    \n#include <utility>\n#line 6 \"data_structure/simple_csr.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate <class E> struct simple_csr {\n    simple_csr() = default;\n\n\
    \    simple_csr(int n, const std::vector<std::pair<int, E>>& elements)\n     \
    \   : start(n + 1, 0), elist(elements.size()) {\n        for (auto e : elements)\
    \ {\n            start[e.first + 1]++;\n        }\n        for (auto i : std::views::iota(0,\
    \ n)) {\n            start[i + 1] += start[i];\n        }\n        auto counter\
    \ = start;\n        for (auto [i, e] : elements) {\n            elist[counter[i]++]\
    \ = e;\n        }\n    }\n\n    simple_csr(const std::vector<std::vector<E>>&\
    \ es)\n        : start(es.size() + 1, 0) {\n        int n = es.size();\n     \
    \   for (auto i : std::views::iota(0, n)) {\n            start[i + 1] = (int)es[i].size()\
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
    \    bool prepared = false;\n};\n\n}  // namespace ebi\n#line 2 \"matrix/base.hpp\"\
    \n\n#include <algorithm>\n#line 8 \"matrix/base.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class T> struct matrix;\n\ntemplate <class T> matrix<T> identify_matrix(int\
    \ n) {\n    matrix<T> a(n, n);\n    for (int i = 0; i < n; i++) {\n        a[i][i]\
    \ = 1;\n    }\n    return a;\n}\n\ntemplate <class T> struct matrix {\n  private:\n\
    \    using Self = matrix<T>;\n\n  public:\n    matrix(int n_, int m_, T init_val\
    \ = 0)\n        : n(n_), m(m_), data(n * m, init_val) {}\n\n    matrix(const std::vector<std::vector<T>>\
    \ &a)\n        : n((int)a.size()), m((int)a[0].size()) {\n        data = std::vector(n\
    \ * m);\n        for (int i = 0; i < n; i++) {\n            std::copy(a[i].begin(),\
    \ a[i].end(), data.begin() + i * m);\n        }\n    }\n\n    Self operator+(Self\
    \ &rhs) const noexcept {\n        return Self(*this) += rhs;\n    }\n\n    Self\
    \ operator-(Self &rhs) const noexcept {\n        return Self(*this) -= rhs;\n\
    \    }\n\n    Self operator*(Self &rhs) const noexcept {\n        return Self(*this)\
    \ *= rhs;\n    }\n\n    Self operator/(Self &rhs) const noexcept {\n        return\
    \ Self(*this) /= rhs;\n    }\n\n    friend Self operator*(const T &lhs, const\
    \ Self &rhs) {\n        return Self(rhs) *= lhs;\n    }\n\n    friend Self operator*(const\
    \ Self &lhs, const T &rhs) {\n        return Self(lhs) *= rhs;\n    }\n\n    std::vector<T>\
    \ operator*(const std::vector<T> &rhs) noexcept {\n        assert(m == (int)rhs.size());\n\
    \        std::vector<T> res(n, 0);\n        for (int i = 0; i < n; i++) {\n  \
    \          for (int j = 0; j < m; j++) {\n                res[i] += (*this)[i][j]\
    \ * rhs[j];\n            }\n        }\n        return res;\n    }\n\n    Self\
    \ &operator+=(Self &rhs) noexcept {\n        assert(this->size() == rhs.size());\n\
    \        for (int i = 0; i < n; ++i) {\n            for (int j = 0; j < m; ++j)\
    \ {\n                (*this)[i][j] += rhs[i][j];\n            }\n        }\n \
    \       return *this;\n    }\n\n    Self &operator-=(Self &rhs) noexcept {\n \
    \       assert(this->size() == rhs.size());\n        for (int i = 0; i < n; ++i)\
    \ {\n            for (int j = 0; j < m; ++j) {\n                (*this)[i][j]\
    \ -= rhs[i][j];\n            }\n        }\n        return *this;\n    }\n\n  \
    \  Self &operator*=(Self &rhs) noexcept {\n        int h = n, w = rhs.column_size();\n\
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
    \ + j * m);\n    }\n\n    int rank() const;\n\n    Self transposition() const\
    \ {\n        Self res(m, n);\n        for (int i = 0; i < n; i++) {\n        \
    \    for (int j = 0; j < m; j++) {\n                res[j][i] = (*this)[i][j];\n\
    \            }\n        }\n        return res;\n    }\n\n    std::optional<Self>\
    \ inv() const {\n        assert(row_size() == column_size());\n        Self a\
    \ = *this;\n        Self b = identify_matrix<T>(n);\n        for (int r = 0; r\
    \ < n; r++) {\n            for (int i = r; i < n; i++) {\n                if (a[i][r]\
    \ != 0) {\n                    a.swap(r, i);\n                    b.swap(r, i);\n\
    \                    break;\n                }\n            }\n            if\
    \ (a[r][r] == 0) return std::nullopt;\n            T x = a[r][r].inv();\n    \
    \        for (int j = 0; j < n; j++) {\n                if (r < j) a[r][j] *=\
    \ x;\n                b[r][j] *= x;\n            }\n            for (int i = 0;\
    \ i < n; i++) {\n                if (i == r) continue;\n                for (int\
    \ j = 0; j < n; j++) {\n                    if (r < j) a[i][j] -= a[i][r] * a[r][j];\n\
    \                    b[i][j] -= a[i][r] * b[r][j];\n                }\n      \
    \      }\n        }\n        return b;\n    }\n\n    Self pow(long long k) const\
    \ {\n        assert(row_size() == column_size() && k >= 0);\n        Self res\
    \ = identify_matrix<T>(row_size());\n        Self x = *this;\n        while (k)\
    \ {\n            if (k & 1) res *= x;\n            x *= x;\n            k >>=\
    \ 1;\n        }\n        return res;\n    }\n\n    int row_size() const {\n  \
    \      return n;\n    }\n\n    int column_size() const {\n        return m;\n\
    \    }\n\n    std::pair<int, int> size() const {\n        return {n, m};\n   \
    \ }\n\n  private:\n    int n, m;\n    std::vector<T> data;\n};\n\ntemplate <class\
    \ T> T det(matrix<T> a) {\n    assert(a.row_size() == a.column_size());\n    T\
    \ d = 1;\n    int n = a.row_size();\n    for (int r = 0; r < n; r++) {\n     \
    \   if (a[r][r] == 0) {\n            for (int i = r + 1; i < n; i++) {\n     \
    \           if (a[i][r] != 0) {\n                    a.swap(r, i);\n         \
    \           d = -d;\n                }\n            }\n        }\n        if (a[r][r]\
    \ == 0) return 0;\n        d *= a[r][r];\n        T inv = a[r][r].inv();\n   \
    \     for (int i = r + 1; i < n; i++) {\n            T x = a[i][r] * inv;\n  \
    \          for (int j = r; j < n; j++) {\n                a[i][j] -= x * a[r][j];\n\
    \            }\n        }\n    }\n    return d;\n}\n\ntemplate <class T> std::istream\
    \ &operator>>(std::istream &os, matrix<T> &a) {\n    for (int i = 0; i < a.row_size();\
    \ i++) {\n        for (int j = 0; j < a.column_size(); j++) {\n            os\
    \ >> a[i][j];\n        }\n    }\n    return os;\n}\n\ntemplate <class T>\nstd::ostream\
    \ &operator<<(std::ostream &os, const matrix<T> &a) {\n    for (int i = 0; i <\
    \ a.row_size(); i++) {\n        for (int j = 0; j < a.column_size(); j++) {\n\
    \            os << a[i][j];\n            if (j < a.column_size() - 1) os << '\
    \ ';\n        }\n        if (i < a.row_size() - 1) os << '\\n';\n    }\n    return\
    \ os;\n}\n\n}  // namespace ebi\n#line 2 \"matrix/gauss_jordan.hpp\"\n\n#line\
    \ 4 \"matrix/gauss_jordan.hpp\"\n\nnamespace ebi {\n\ntemplate <class T> int find_pivot(const\
    \ matrix<T> &a, int r, int w) {\n    for (int i = r; i < a.row_size(); i++) {\n\
    \        if (a[i][w] != 0) return i;\n    }\n    return -1;\n}\n\ntemplate <class\
    \ T> int gauss_jordan(matrix<T> &a) {\n    int h = a.row_size(), w = a.column_size();\n\
    \    int rank = 0;\n    for (int j = 0; j < w; j++) {\n        int pivot = find_pivot(a,\
    \ rank, j);\n        if (pivot == -1) continue;\n        a.swap(rank, pivot);\n\
    \        T inv = T(1) / a[rank][j];\n        for (int k = j; k < w; k++) {\n \
    \           a[rank][k] *= inv;\n        }\n        for (int i = 0; i < h; i++)\
    \ {\n            if (i != rank && a[i][j] != 0) {\n                T x = a[i][j];\n\
    \                for (int k = j; k < w; k++) {\n                    a[i][k] -=\
    \ a[rank][k] * x;\n                }\n            }\n        }\n        rank++;\n\
    \    }\n    return rank;\n}\n\ntemplate <class T> int matrix<T>::rank() const\
    \ {\n    matrix<T> a = *this;\n    return gauss_jordan(a);\n}\n\ntemplate <class\
    \ T> int gauss_jordan(matrix<T> &a, std::vector<T> &b) {\n    int h = a.row_size(),\
    \ w = a.column_size();\n    assert(h == (int)b.size());\n    int rank = 0;\n \
    \   for (int j = 0; j < w; j++) {\n        int pivot = find_pivot(a, rank, j);\n\
    \        if (pivot == -1) continue;\n        a.swap(rank, pivot);\n        std::swap(b[rank],\
    \ b[pivot]);\n        T inv = T(1) / a[rank][j];\n        for (int k = j; k <\
    \ w; k++) {\n            a[rank][k] *= inv;\n        }\n        b[rank] *= inv;\n\
    \        for (int i = 0; i < h; i++) {\n            if (i != rank && a[i][j] !=\
    \ 0) {\n                T x = a[i][j];\n                for (int k = j; k < w;\
    \ k++) {\n                    a[i][k] -= a[rank][k] * x;\n                }\n\
    \                b[i] -= b[rank] * x;\n            }\n        }\n        rank++;\n\
    \    }\n    return rank;\n}\n\ntemplate <class T>\nstd::optional<std::vector<std::vector<T>>>\
    \ solve_linear_equations(\n    matrix<T> a, std::vector<T> b) {\n    assert(a.row_size()\
    \ == (int)b.size());\n    int rank = gauss_jordan(a, b);\n    int h = a.row_size(),\
    \ w = a.column_size();\n    for (int i = rank; i < h; i++) {\n        if (b[i]\
    \ != 0) return std::nullopt;\n    }\n    std::vector res(1, std::vector<T>(w,\
    \ 0));\n    std::vector<int> pivot(w, -1);\n    {\n        int p = 0;\n      \
    \  for (int i = 0; i < rank; i++) {\n            while (a[i][p] == 0) p++;\n \
    \           res[0][p] = b[i];\n            pivot[p] = i;\n        }\n    }\n \
    \   for (int j = 0; j < w; j++) {\n        if (pivot[j] == -1) {\n           \
    \ std::vector<T> x(w, 0);\n            x[j] = -1;\n            for (int i = 0;\
    \ i < j; i++) {\n                if (pivot[i] != -1) x[i] = a[pivot[i]][j];\n\
    \            }\n            res.emplace_back(x);\n        }\n    }\n    return\
    \ res;\n}\n\n}  // namespace ebi\n#line 2 \"modint/modint61.hpp\"\n\n#line 4 \"\
    modint/modint61.hpp\"\n#include <cstdint>\n#line 6 \"modint/modint61.hpp\"\n\n\
    #line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#line 6 \"modint/base.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b)\
    \ {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n\
    \    a.pow(std::declval<long long>());\n    T::mod();\n};\n\ntemplate <Modint\
    \ mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long long x;\n\
    \    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <Modint mint>\nstd::ostream\
    \ &operator<<(std::ostream &os, const mint &a) {\n    return os << a.val();\n\
    }\n\n}  // namespace ebi\n#line 8 \"modint/modint61.hpp\"\n\nnamespace ebi {\n\
    \nstruct modint61 {\n  private:\n    using mint = modint61;\n    using u64 = std::uint64_t;\n\
    \    constexpr static u64 m = (1ull << 61) - 1;\n    constexpr static u64 MASK31\
    \ = (1ull << 31) - 1;\n    constexpr static u64 MASK30 = (1ull << 30) - 1;\n\n\
    \  public:\n    constexpr static u64 mod() {\n        return m;\n    }\n\n   \
    \ constexpr modint61() : _v(0) {}\n\n    constexpr modint61(long long v) {\n \
    \       v %= (long long)umod();\n        if (v < 0) v += (long long)umod();\n\
    \        _v = u64(v);\n    }\n\n    constexpr u64 val() const {\n        return\
    \ _v;\n    }\n\n    constexpr u64 value() const {\n        return val();\n   \
    \ }\n\n    constexpr mint &operator++() {\n        _v++;\n        if (_v == umod())\
    \ _v = 0;\n        return *this;\n    }\n\n    constexpr mint &operator--() {\n\
    \        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n   \
    \ }\n\n    constexpr mint &operator+=(const mint &rhs) {\n        _v += rhs._v;\n\
    \        _v = safe_mod(_v);\n        return *this;\n    }\n\n    constexpr mint\
    \ &operator-=(const mint &rhs) {\n        if (_v < rhs._v) _v += umod();\n   \
    \     assert(_v >= rhs._v);\n        _v -= rhs._v;\n        return *this;\n  \
    \  }\n\n    constexpr mint &operator*=(const mint &rhs) {\n        u64 au = _v\
    \ >> 31, ad = _v & MASK31;\n        u64 bu = rhs._v >> 31, bd = rhs._v & MASK31;\n\
    \        u64 mid = ad * bu + au * bd;\n        u64 midu = mid >> 30;\n       \
    \ u64 midd = mid & MASK30;\n        _v = (au * bu * 2 + midu + (midd << 31) +\
    \ ad * bd);\n        _v = safe_mod(_v);\n        return *this;\n    }\n\n    constexpr\
    \ mint &operator/=(const mint &rhs) {\n        return *this *= rhs.inv();\n  \
    \  }\n\n    constexpr mint pow(long long n) const {\n        assert(0 <= n);\n\
    \        mint x = *this, res = 1;\n        while (n) {\n            if (n & 1)\
    \ res *= x;\n            x *= x;\n            n >>= 1;\n        }\n        return\
    \ res;\n    }\n\n    constexpr mint inv() const {\n        assert(_v);\n     \
    \   return pow(umod() - 2);\n    }\n\n    friend mint operator+(const mint &lhs,\
    \ const mint &rhs) {\n        return mint(lhs) += rhs;\n    }\n    friend mint\
    \ operator-(const mint &lhs, const mint &rhs) {\n        return mint(lhs) -= rhs;\n\
    \    }\n    friend mint operator*(const mint &lhs, const mint &rhs) {\n      \
    \  return mint(lhs) *= rhs;\n    }\n    friend mint operator/(const mint &lhs,\
    \ const mint &rhs) {\n        return mint(lhs) /= rhs;\n    }\n    friend bool\
    \ operator==(const mint &lhs, const mint &rhs) {\n        return lhs.val() ==\
    \ rhs.val();\n    }\n    friend bool operator!=(const mint &lhs, const mint &rhs)\
    \ {\n        return !(lhs == rhs);\n    }\n    friend bool operator<(const mint\
    \ &lhs, const mint &rhs) {\n        return lhs._v < rhs._v;\n    }\n    friend\
    \ bool operator>(const mint &lhs, const mint &rhs) {\n        return rhs < lhs;\n\
    \    }\n\n  private:\n    u64 _v = 0;\n\n    constexpr static u64 umod() {\n \
    \       return m;\n    }\n\n    constexpr u64 safe_mod(const u64 &a) {\n     \
    \   u64 au = a >> 61;\n        u64 ad = a & umod();\n        u64 res = au + ad;\n\
    \        if (res >= umod()) res -= umod();\n        return res;\n    }\n};\n\n\
    }  // namespace ebi\n#line 2 \"utility/random_number_generator.hpp\"\n\r\n#line\
    \ 4 \"utility/random_number_generator.hpp\"\n#include <random>\r\n\r\nnamespace\
    \ ebi {\r\n\r\nstruct random_number_generator {\r\n    random_number_generator(int\
    \ seed = -1) {\r\n        if (seed < 0) seed = rnd();\r\n        mt.seed(seed);\r\
    \n    }\r\n\r\n    void set_seed(int seed) {\r\n        mt.seed(seed);\r\n   \
    \ }\r\n\r\n    template <class T> T get(T a, T b) {\r\n        std::uniform_int_distribution<T>\
    \ dist(a, b - 1);\r\n        return dist(mt);\r\n    }\r\n\r\n  private:\r\n \
    \   std::mt19937_64 mt;\r\n    std::random_device rnd;\r\n};\r\n\r\n}  // namespace\
    \ ebi\n#line 8 \"graph/maximum_matching_size.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class T> int maximum_matching_size(const Graph<T> &g) {\n    static random_number_generator\
    \ rng;\n    using mint = modint61;\n    int n = g.node_number();\n    matrix<mint>\
    \ tutte(n, n, 0);\n    for (auto e : g.get_edges()) {\n        mint x = rng.get<std::uint64_t>(0,\
    \ mint::mod());\n        tutte[e.from][e.to] += x;\n        tutte[e.to][e.from]\
    \ -= x;\n    }\n    return tutte.rank() / 2;\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include \"../graph/base.hpp\"\n#include \"../matrix/base.hpp\"\
    \n#include \"../matrix/gauss_jordan.hpp\"\n#include \"../modint/modint61.hpp\"\
    \n#include \"../utility/random_number_generator.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <class T> int maximum_matching_size(const Graph<T> &g) {\n    static random_number_generator\
    \ rng;\n    using mint = modint61;\n    int n = g.node_number();\n    matrix<mint>\
    \ tutte(n, n, 0);\n    for (auto e : g.get_edges()) {\n        mint x = rng.get<std::uint64_t>(0,\
    \ mint::mod());\n        tutte[e.from][e.to] += x;\n        tutte[e.to][e.from]\
    \ -= x;\n    }\n    return tutte.rank() / 2;\n}\n\n}  // namespace ebi"
  dependsOn:
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  - matrix/base.hpp
  - matrix/gauss_jordan.hpp
  - modint/modint61.hpp
  - modint/base.hpp
  - utility/random_number_generator.hpp
  isVerificationFile: false
  path: graph/maximum_matching_size.hpp
  requiredBy: []
  timestamp: '2024-07-18 01:45:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/maximum_matching_size.hpp
layout: document
redirect_from:
- /library/graph/maximum_matching_size.hpp
- /library/graph/maximum_matching_size.hpp.html
title: graph/maximum_matching_size.hpp
---
