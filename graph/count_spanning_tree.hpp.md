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
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/count_directed_euler_trail.hpp
    title: Count Directed Euler Trail
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/Counting_Eulerian_Circuits.test.cpp
    title: test/graph/Counting_Eulerian_Circuits.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Counting_Spanning_Trees_Directed.test.cpp
    title: test/graph/Counting_Spanning_Trees_Directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/Counting_Spanning_Trees_Undirected.test.cpp
    title: test/graph/Counting_Spanning_Trees_Undirected.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/count_spanning_tree.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n#line 2 \"graph/base.hpp\"\n\n#line 4 \"graph/base.hpp\"\n\
    #include <iostream>\n#include <ranges>\n#line 7 \"graph/base.hpp\"\n\n#line 2\
    \ \"data_structure/simple_csr.hpp\"\n\n#line 4 \"data_structure/simple_csr.hpp\"\
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
    \ os;\n}\n\n}  // namespace ebi\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n\
    #line 6 \"modint/base.hpp\"\n\nnamespace ebi {\n\ntemplate <class T>\nconcept\
    \ Modint = requires(T a, T b) {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n\
    \    a.inv();\n    a.val();\n    a.pow(std::declval<long long>());\n    T::mod();\n\
    };\n\ntemplate <Modint mint> std::istream &operator>>(std::istream &os, mint &a)\
    \ {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate\
    \ <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const mint &a) {\n\
    \    return os << a.val();\n}\n\n}  // namespace ebi\n#line 9 \"graph/count_spanning_tree.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <Modint mint>\nmint count_spanning_tree(const\
    \ std::vector<std::vector<int>> &g) {\n    const int n = (int)g.size();\n    if\
    \ (n == 1) return 1;\n    std::vector<int> deg(n, 0);\n    for (int i = 0; i <\
    \ n; i++) {\n        for (int j = 0; j < n; j++) {\n            if (i == j) continue;\n\
    \            assert(g[i][j] == g[j][i]);\n            deg[i] += g[i][j];\n   \
    \     }\n    }\n    matrix<mint> L(n - 1, n - 1, 0);\n    for (int i = 1; i <\
    \ n; i++) {\n        for (int j = 1; j < n; j++) {\n            if (i == j)\n\
    \                L[i - 1][j - 1] = deg[i];\n            else\n               \
    \ L[i - 1][j - 1] -= g[i][j];\n        }\n    }\n    return det(L);\n}\n\ntemplate\
    \ <Modint mint, class T> mint count_spanning_tree(const Graph<T> &g) {\n    int\
    \ n = g.node_number();\n    if (n == 1) return 1;\n    std::vector a(n, std::vector<int>(n,\
    \ 0));\n    for (int i = 0; i < n; i++) {\n        for (auto e : g[i]) {\n   \
    \         a[i][e.to]++;\n        }\n    }\n    return count_spanning_tree<mint>(a);\n\
    }\n\ntemplate <Modint mint>\nmint count_directed_spanning_tree(const std::vector<std::vector<int>>\
    \ &g,\n                                  int root, bool in = false) {\n    const\
    \ int n = (int)g.size();\n    if (n == 1) return 1;\n    std::vector<int> d(n,\
    \ 0);\n    for (int i = 0; i < n; i++) {\n        for (int j = 0; j < n; j++)\
    \ {\n            if (i != j) d[i] += in ? g[i][j] : g[j][i];\n        }\n    }\n\
    \    matrix<mint> L(n - 1, n - 1, 0);\n    for (int i = 0; i < n; i++) {\n   \
    \     for (int j = 0; j < n; j++) {\n            int a = i, b = j;\n         \
    \   if (a == root || b == root) continue;\n            if (root < a) a--;\n  \
    \          if (root < b) b--;\n            if (a == b)\n                L[a][b]\
    \ = d[i];\n            else\n                L[a][b] = in ? -g[i][j] : -g[j][i];\n\
    \        }\n    }\n    return det(L);\n}\n\ntemplate <Modint mint, class T>\n\
    mint count_directed_spanning_tree(const Graph<T> &g, int root, bool in = false)\
    \ {\n    const int n = g.node_number();\n    if (n == 1) return 1;\n    std::vector\
    \ d(n, std::vector<int>(n, 0));\n    for (int i = 0; i < n; i++) {\n        for\
    \ (auto e : g[i]) {\n            d[i][e.to]++;\n        }\n    }\n    return count_directed_spanning_tree<mint>(d,\
    \ root, in);\n}\n\n}  // namespace ebi\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../graph/base.hpp\"\
    \n#include \"../matrix/base.hpp\"\n#include \"../modint/base.hpp\"\n\nnamespace\
    \ ebi {\n\ntemplate <Modint mint>\nmint count_spanning_tree(const std::vector<std::vector<int>>\
    \ &g) {\n    const int n = (int)g.size();\n    if (n == 1) return 1;\n    std::vector<int>\
    \ deg(n, 0);\n    for (int i = 0; i < n; i++) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if (i == j) continue;\n            assert(g[i][j] == g[j][i]);\n\
    \            deg[i] += g[i][j];\n        }\n    }\n    matrix<mint> L(n - 1, n\
    \ - 1, 0);\n    for (int i = 1; i < n; i++) {\n        for (int j = 1; j < n;\
    \ j++) {\n            if (i == j)\n                L[i - 1][j - 1] = deg[i];\n\
    \            else\n                L[i - 1][j - 1] -= g[i][j];\n        }\n  \
    \  }\n    return det(L);\n}\n\ntemplate <Modint mint, class T> mint count_spanning_tree(const\
    \ Graph<T> &g) {\n    int n = g.node_number();\n    if (n == 1) return 1;\n  \
    \  std::vector a(n, std::vector<int>(n, 0));\n    for (int i = 0; i < n; i++)\
    \ {\n        for (auto e : g[i]) {\n            a[i][e.to]++;\n        }\n   \
    \ }\n    return count_spanning_tree<mint>(a);\n}\n\ntemplate <Modint mint>\nmint\
    \ count_directed_spanning_tree(const std::vector<std::vector<int>> &g,\n     \
    \                             int root, bool in = false) {\n    const int n =\
    \ (int)g.size();\n    if (n == 1) return 1;\n    std::vector<int> d(n, 0);\n \
    \   for (int i = 0; i < n; i++) {\n        for (int j = 0; j < n; j++) {\n   \
    \         if (i != j) d[i] += in ? g[i][j] : g[j][i];\n        }\n    }\n    matrix<mint>\
    \ L(n - 1, n - 1, 0);\n    for (int i = 0; i < n; i++) {\n        for (int j =\
    \ 0; j < n; j++) {\n            int a = i, b = j;\n            if (a == root ||\
    \ b == root) continue;\n            if (root < a) a--;\n            if (root <\
    \ b) b--;\n            if (a == b)\n                L[a][b] = d[i];\n        \
    \    else\n                L[a][b] = in ? -g[i][j] : -g[j][i];\n        }\n  \
    \  }\n    return det(L);\n}\n\ntemplate <Modint mint, class T>\nmint count_directed_spanning_tree(const\
    \ Graph<T> &g, int root, bool in = false) {\n    const int n = g.node_number();\n\
    \    if (n == 1) return 1;\n    std::vector d(n, std::vector<int>(n, 0));\n  \
    \  for (int i = 0; i < n; i++) {\n        for (auto e : g[i]) {\n            d[i][e.to]++;\n\
    \        }\n    }\n    return count_directed_spanning_tree<mint>(d, root, in);\n\
    }\n\n}  // namespace ebi"
  dependsOn:
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  - matrix/base.hpp
  - modint/base.hpp
  isVerificationFile: false
  path: graph/count_spanning_tree.hpp
  requiredBy:
  - graph/count_directed_euler_trail.hpp
  timestamp: '2024-07-18 01:45:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/Counting_Eulerian_Circuits.test.cpp
  - test/graph/Counting_Spanning_Trees_Undirected.test.cpp
  - test/graph/Counting_Spanning_Trees_Directed.test.cpp
documentation_of: graph/count_spanning_tree.hpp
layout: document
title: Count Spanning Tree
---

## 説明

与えられたグラフについて、全域木の個数を数える。頂点数を $N$ として、 $O(N^3)$ 。

### count_spanning_tree(std::vector<std::vector<int>> g)

$g[i][j] := (i, j)の辺の本数$ とする。
全域木の個数を返す。

### count_spanning_tree(Graph<T> g)

無向グラフ $g$ の全域木の個数を返す。

### count_directed_spanning_tree(std::vector<std::vector<int>> g, int root, bool in)

$g[i][j] := i から j への辺の本数$ とする。
根を $root$ としたときの有向全域木の個数を返す。 $in$ が `true` のときは、全ての辺が根の方を向いている全域木を考える。 $in$ が `false` のときは、根から全頂点に到達できる全域木を考える。

### count_directed_spanning_tree(Graph<T> g, int root, bool in)

グラフ $g$ について、根を $root$ としたときの有向全域木の個数を返す。