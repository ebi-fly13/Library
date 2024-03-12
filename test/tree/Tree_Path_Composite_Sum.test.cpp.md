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
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':heavy_check_mark:'
    path: tree/rerooting.hpp
    title: Rerooting DP
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/tree_path_composite_sum
  bundledCode: "#line 1 \"test/tree/Tree_Path_Composite_Sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\n\n#include <iostream>\n\
    #include <vector>\n\n#line 2 \"graph/base.hpp\"\n\n#include <cassert>\n#line 5\
    \ \"graph/base.hpp\"\n#include <ranges>\n#line 7 \"graph/base.hpp\"\n\n#line 2\
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
    \ id;\n};\n\ntemplate <class E> struct Graph {\n  private:\n    using cost_type\
    \ = E;\n    using edge_type = Edge<cost_type>;\n\n  public:\n    Graph(int n_)\
    \ : n(n_) {}\n\n    Graph() = default;\n\n    void add_edge(int u, int v, cost_type\
    \ c) {\n        edges.emplace_back(u, edge_type{u, v, c, m++});\n    }\n\n   \
    \ void add_undirected_edge(int u, int v, cost_type c) {\n        edges.emplace_back(u,\
    \ edge_type{u, v, c, m});\n        edges.emplace_back(v, edge_type{v, u, c, m});\n\
    \        m++;\n    }\n\n    void read_tree(int offset = 1, bool is_weighted =\
    \ false) {\n        read_graph(n - 1, offset, false, is_weighted);\n    }\n\n\
    \    void read_parents(int offset = 1) {\n        for (auto i : std::views::iota(1,\
    \ n)) {\n            int p;\n            std::cin >> p;\n            p -= offset;\n\
    \            add_undirected_edge(p, i, 1);\n        }\n        build();\n    }\n\
    \n    void read_graph(int e, int offset = 1, bool is_directed = false,\n     \
    \               bool is_weighted = false) {\n        for (int i = 0; i < e; i++)\
    \ {\n            int u, v;\n            std::cin >> u >> v;\n            u -=\
    \ offset;\n            v -= offset;\n            if (is_weighted) {\n        \
    \        cost_type c;\n                std::cin >> c;\n                if (is_directed)\
    \ {\n                    add_edge(u, v, c);\n                } else {\n      \
    \              add_undirected_edge(u, v, c);\n                }\n            }\
    \ else {\n                if (is_directed) {\n                    add_edge(u,\
    \ v, 1);\n                } else {\n                    add_undirected_edge(u,\
    \ v, 1);\n                }\n            }\n        }\n        build();\n    }\n\
    \n    void build() {\n        assert(!prepared);\n        csr = simple_csr<edge_type>(n,\
    \ edges);\n        edges.clear();\n        prepared = true;\n    }\n\n    int\
    \ size() const {\n        return n;\n    }\n\n    const auto operator[](int i)\
    \ const {\n        return csr[i];\n    }\n    auto operator[](int i) {\n     \
    \   return csr[i];\n    }\n\n  private:\n    int n, m = 0;\n\n    std::vector<std::pair<int,\
    \ edge_type>> edges;\n    simple_csr<edge_type> csr;\n    bool prepared = false;\n\
    };\n\n}  // namespace ebi\n#line 2 \"modint/modint.hpp\"\n\r\n#line 5 \"modint/modint.hpp\"\
    \n\r\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#line 6 \"modint/base.hpp\"\
    \n\nnamespace ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b)\
    \ {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n\
    \    a.pow(std::declval<long long>());\n    T::mod();\n};\n\ntemplate <Modint\
    \ mint> std::istream &operator>>(std::istream &os, mint &a) {\n    long long x;\n\
    \    os >> x;\n    a = x;\n    return os;\n}\n\ntemplate <Modint mint>\nstd::ostream\
    \ &operator<<(std::ostream &os, const mint &a) {\n    return os << a.val();\n\
    }\n\n}  // namespace ebi\n#line 7 \"modint/modint.hpp\"\n\r\nnamespace ebi {\r\
    \n\r\ntemplate <int m> struct static_modint {\r\n  private:\r\n    using modint\
    \ = static_modint;\r\n\r\n  public:\r\n    static constexpr int mod() {\r\n  \
    \      return m;\r\n    }\r\n\r\n    static constexpr modint raw(int v) {\r\n\
    \        modint x;\r\n        x._v = v;\r\n        return x;\r\n    }\r\n\r\n\
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
    #line 2 \"tree/rerooting.hpp\"\n\n#line 6 \"tree/rerooting.hpp\"\n\n#line 8 \"\
    tree/rerooting.hpp\"\n\nnamespace ebi {\n\ntemplate <class T, class V, class E,\
    \ E (*e)(), E (*merge)(E, E),\n          E (*put_edge)(T, V), V (*put_root)(int,\
    \ E)>\nstruct rerooting {\n  private:\n    V dfs_sub(int v, int par = -1) {\n\
    \        E ret = e();\n        for (auto &edge : g[v]) {\n            if (edge.to\
    \ == par && g[v].back().to != par)\n                std::swap(g[v].back(), edge);\n\
    \            if (edge.to == par) continue;\n            E val = put_edge(edge.cost,\
    \ dfs_sub(edge.to, v));\n            outs[v].emplace_back(val);\n            ret\
    \ = merge(ret, val);\n        }\n        sub[v] = put_root(v, ret);\n        return\
    \ sub[v];\n    }\n\n    void dfs_all(int v, int par = -1, E rev = e()) {\n   \
    \     int sz = outs[v].size();\n        std::vector<E> lcum(sz + 1, e()), rcum(sz\
    \ + 1, e());\n        for (int i = 0; i < sz; i++) {\n            lcum[i + 1]\
    \ = merge(lcum[i], outs[v][i]);\n            rcum[sz - i - 1] = merge(rcum[sz\
    \ - i], outs[v][sz - i - 1]);\n        }\n        for (int i = 0; i < sz; i++)\
    \ {\n            auto edge = g[v][i];\n            E ret =\n                put_edge(edge.cost,\n\
    \                         put_root(v, merge(merge(lcum[i], rcum[i + 1]), rev)));\n\
    \            dfs_all(edge.to, v, ret);\n        }\n        dp[v] = put_root(v,\
    \ merge(lcum[sz], rev));\n    }\n\n  public:\n    rerooting(int n, const Graph<T>\
    \ &g_) : n(n), g(g_), sub(n), dp(n), outs(n) {\n        dfs_sub(0);\n        dfs_all(0);\n\
    \    }\n\n    V get(int v) const {\n        return dp[v];\n    }\n\n  private:\n\
    \    int n;\n    Graph<T> g;\n    std::vector<V> sub;\n    std::vector<V> dp;\n\
    \    std::vector<std::vector<E>> outs;\n};\n\n}  // namespace ebi\n#line 9 \"\
    test/tree/Tree_Path_Composite_Sum.test.cpp\"\n\nusing mint = ebi::modint998244353;\n\
    \nstd::vector<mint> a;\n\nstruct S {\n    mint sum;\n    mint sz;\n};\n\nS e()\
    \ {\n    return {0, 0};\n}\n\nS merge(S lhs, S rhs) {\n    return {lhs.sum + rhs.sum,\
    \ lhs.sz + rhs.sz};\n}\n\nS put_edge(std::pair<mint, mint> e, S x) {\n    auto\
    \ [b, c] = e;\n    return {b * x.sum + c * x.sz, x.sz};\n}\n\nS put_root(int idx,\
    \ S x) {\n    return {a[idx] + x.sum, x.sz + 1};\n}\n\nint main() {\n    int n;\n\
    \    std::cin >> n;\n    for (int i = 0; i < n; i++) {\n        int val;\n   \
    \     std::cin >> val;\n        a.emplace_back(val);\n    }\n    ebi::Graph<std::pair<mint,\
    \ mint>> g(n);\n    for (int i = 0; i < n - 1; i++) {\n        int u, v, b, c;\n\
    \        std::cin >> u >> v >> b >> c;\n        g.add_edge(u, v, {b, c});\n  \
    \      g.add_edge(v, u, {b, c});\n    }\n    g.build();\n    ebi::rerooting<std::pair<mint,\
    \ mint>, S, S, e, merge, put_edge, put_root>\n        dp(n, g);\n    for (int\
    \ i = 0; i < n; i++) {\n        std::cout << dp.get(i).sum.val() << \" \\n\"[i\
    \ == n - 1];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../graph/base.hpp\"\
    \n#include \"../../modint/modint.hpp\"\n#include \"../../tree/rerooting.hpp\"\n\
    \nusing mint = ebi::modint998244353;\n\nstd::vector<mint> a;\n\nstruct S {\n \
    \   mint sum;\n    mint sz;\n};\n\nS e() {\n    return {0, 0};\n}\n\nS merge(S\
    \ lhs, S rhs) {\n    return {lhs.sum + rhs.sum, lhs.sz + rhs.sz};\n}\n\nS put_edge(std::pair<mint,\
    \ mint> e, S x) {\n    auto [b, c] = e;\n    return {b * x.sum + c * x.sz, x.sz};\n\
    }\n\nS put_root(int idx, S x) {\n    return {a[idx] + x.sum, x.sz + 1};\n}\n\n\
    int main() {\n    int n;\n    std::cin >> n;\n    for (int i = 0; i < n; i++)\
    \ {\n        int val;\n        std::cin >> val;\n        a.emplace_back(val);\n\
    \    }\n    ebi::Graph<std::pair<mint, mint>> g(n);\n    for (int i = 0; i < n\
    \ - 1; i++) {\n        int u, v, b, c;\n        std::cin >> u >> v >> b >> c;\n\
    \        g.add_edge(u, v, {b, c});\n        g.add_edge(v, u, {b, c});\n    }\n\
    \    g.build();\n    ebi::rerooting<std::pair<mint, mint>, S, S, e, merge, put_edge,\
    \ put_root>\n        dp(n, g);\n    for (int i = 0; i < n; i++) {\n        std::cout\
    \ << dp.get(i).sum.val() << \" \\n\"[i == n - 1];\n    }\n}"
  dependsOn:
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  - modint/modint.hpp
  - modint/base.hpp
  - tree/rerooting.hpp
  isVerificationFile: true
  path: test/tree/Tree_Path_Composite_Sum.test.cpp
  requiredBy: []
  timestamp: '2024-03-13 01:44:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/Tree_Path_Composite_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Tree_Path_Composite_Sum.test.cpp
- /verify/test/tree/Tree_Path_Composite_Sum.test.cpp.html
title: test/tree/Tree_Path_Composite_Sum.test.cpp
---
