---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/convolution_mod_2_64.hpp
    title: Convolution $\pmod{2^{64}}$
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: NTT Convolution
  - icon: ':heavy_check_mark:'
    path: data_structure/simple_csr.hpp
    title: Simple CSR
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: Graph (CSR format)
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
  - icon: ':heavy_check_mark:'
    path: tree/centroid_decomposition.hpp
    title: Centroid Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#line 2 \"convolution/convolution_mod_2_64.hpp\"\n\n#include <cstdint>\n#include\
    \ <vector>\n\n#line 2 \"convolution/ntt.hpp\"\n\n#include <algorithm>\n#include\
    \ <array>\n#include <bit>\n#include <cassert>\n#line 8 \"convolution/ntt.hpp\"\
    \n\n#line 2 \"math/internal_math.hpp\"\n\n#line 4 \"math/internal_math.hpp\"\n\
    \nnamespace ebi {\n\nnamespace internal {\n\nconstexpr int primitive_root_constexpr(int\
    \ m) {\n    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m\
    \ == 469762049) return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353)\
    \ return 3;\n    if (m == 880803841) return 26;\n    if (m == 924844033) return\
    \ 5;\n    return -1;\n}\ntemplate <int m> constexpr int primitive_root = primitive_root_constexpr(m);\n\
    \n}  // namespace internal\n\n}  // namespace ebi\n#line 2 \"modint/base.hpp\"\
    \n\n#include <concepts>\n#include <iostream>\n#include <utility>\n\nnamespace\
    \ ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n    a +\
    \ b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 11 \"\
    convolution/ntt.hpp\"\n\nnamespace ebi {\n\nnamespace internal {\n\ntemplate <Modint\
    \ mint, int g = internal::primitive_root<mint::mod()>>\nstruct ntt_info {\n  \
    \  static constexpr int rank2 =\n        std::countr_zero((unsigned int)(mint::mod()\
    \ - 1));\n\n    std::array<mint, rank2 + 1> root, inv_root;\n\n    ntt_info()\
    \ {\n        root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);\n        inv_root[rank2]\
    \ = root[rank2].inv();\n        for (int i = rank2 - 1; i >= 0; i--) {\n     \
    \       root[i] = root[i + 1] * root[i + 1];\n            inv_root[i] = inv_root[i\
    \ + 1] * inv_root[i + 1];\n        }\n    }\n};\n\ntemplate <Modint mint> void\
    \ butterfly(std::vector<mint>& a) {\n    static const ntt_info<mint> info;\n \
    \   int n = int(a.size());\n    int bit_size = std::countr_zero(a.size());\n \
    \   assert(n == (int)std::bit_ceil(a.size()));\n\n    // bit reverse\n    for\
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
    \ - 1);\n    return a;\n}\n\n}  // namespace ebi\n#line 2 \"modint/modint.hpp\"\
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
    #line 9 \"convolution/convolution_mod_2_64.hpp\"\n\nnamespace ebi {\n\nnamespace\
    \ internal {\n\ntemplate <Modint mint>\nstd::vector<mint> multiply_uint64_t(const\
    \ std::vector<std::uint64_t>& f,\n                                    const std::vector<std::uint64_t>&\
    \ g) {\n    std::vector<mint> a, b;\n    a.reserve(f.size());\n    b.reserve(g.size());\n\
    \    for (auto x : f) a.emplace_back(x % mint::mod());\n    for (auto x : g) b.emplace_back(x\
    \ % mint::mod());\n    return convolution<mint>(a, b);\n}\n\n}  // namespace internal\n\
    \nstd::vector<std::uint64_t> convolution_mod_2_64(\n    const std::vector<std::uint64_t>&\
    \ f, const std::vector<std::uint64_t>& g) {\n    if (f.empty() || g.empty()) return\
    \ {};\n    using i32 = std::int32_t;\n    using i64 = std::int64_t;\n    using\
    \ u64 = std::uint64_t;\n    static constexpr i32 m0 = 998244353;\n    static constexpr\
    \ i32 m1 = 754974721;\n    static constexpr i32 m2 = 167772161;\n    static constexpr\
    \ i32 m3 = 469762049;\n    static constexpr i32 m4 = 880803841;\n    using mint0\
    \ = static_modint<m0>;\n    using mint1 = static_modint<m1>;\n    using mint2\
    \ = static_modint<m2>;\n    using mint3 = static_modint<m3>;\n    using mint4\
    \ = static_modint<m4>;\n\n    auto d0 = internal::multiply_uint64_t<mint0>(f,\
    \ g);\n    auto d1 = internal::multiply_uint64_t<mint1>(f, g);\n    auto d2 =\
    \ internal::multiply_uint64_t<mint2>(f, g);\n    auto d3 = internal::multiply_uint64_t<mint3>(f,\
    \ g);\n    auto d4 = internal::multiply_uint64_t<mint4>(f, g);\n\n    static const\
    \ mint1 inv10 = mint1(m0).inv();\n    static const mint2 inv21 = mint2(m1).inv(),\
    \ inv20 = inv21 / mint2(m0);\n    static const mint3 inv32 = mint3(m2).inv(),\
    \ inv31 = inv32 / mint3(m1),\n                       inv30 = inv31 / mint3(m0);\n\
    \    static const mint4 inv43 = mint4(m3).inv(), inv42 = inv43 / mint4(m2),\n\
    \                       inv41 = inv42 / mint4(m1), inv40 = inv41 / mint4(m0);\n\
    \    int n = d0.size();\n    std::vector<u64> res(n);\n    for (int i = 0; i <\
    \ n; i++) {\n        i64 x0 = d0[i].val();\n        i64 x1 = ((d1[i] - x0) * inv10).val();\n\
    \        i64 x2 = (((d2[i] - x0)) * inv20 - mint2(x1) * inv21).val();\n      \
    \  i64 x3 = ((d3[i] - x0) * inv30 - mint3(x1) * inv31 - mint3(x2) * inv32)\n \
    \                    .val();\n        i64 x4 = ((d4[i] - x0) * inv40 - mint4(x1)\
    \ * inv41 - mint4(x2) * inv42 -\n                  mint4(x3) * inv43)\n      \
    \               .val();\n        res[i] = x0 + m0 * (x1 + m1 * (x2 + m2 * (x3\
    \ + m3 * (u64(x4)))));\n    }\n    return res;\n}\n\n}  // namespace ebi\n#line\
    \ 2 \"graph/base.hpp\"\n\n#line 5 \"graph/base.hpp\"\n#include <ranges>\n#line\
    \ 7 \"graph/base.hpp\"\n\n#line 2 \"data_structure/simple_csr.hpp\"\n\n#line 6\
    \ \"data_structure/simple_csr.hpp\"\n\nnamespace ebi {\n\ntemplate <class E> struct\
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
    };\n\n}  // namespace ebi\n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n\
    \n#define rep(i, a, n) for (int i = (int)(a); i < (int)(n); i++)\n#define rrep(i,\
    \ a, n) for (int i = ((int)(n)-1); i >= (int)(a); i--)\n#define Rep(i, a, n) for\
    \ (i64 i = (i64)(a); i < (i64)(n); i++)\n#define RRep(i, a, n) for (i64 i = ((i64)(n)-i64(1));\
    \ i >= (i64)(a); i--)\n#define all(v) (v).begin(), (v).end()\n#define rall(v)\
    \ (v).rbegin(), (v).rend()\n\n#line 2 \"template/debug_template.hpp\"\n\n#line\
    \ 4 \"template/debug_template.hpp\"\n\nnamespace ebi {\n\n#ifdef LOCAL\n#define\
    \ debug(...)                                                      \\\n    std::cerr\
    \ << \"LINE: \" << __LINE__ << \"  [\" << #__VA_ARGS__ << \"]:\", \\\n       \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\nvoid debug_out()\
    \ {\n    std::cerr << std::endl;\n}\n\ntemplate <typename Head, typename... Tail>\
    \ void debug_out(Head h, Tail... t) {\n    std::cerr << \" \" << h;\n    if (sizeof...(t)\
    \ > 0) std::cerr << \" :\";\n    debug_out(t...);\n}\n\n}  // namespace ebi\n\
    #line 2 \"template/int_alias.hpp\"\n\n#line 4 \"template/int_alias.hpp\"\n\nnamespace\
    \ ebi {\n\nusing ld = long double;\nusing std::size_t;\nusing i8 = std::int8_t;\n\
    using u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing u16 = std::uint16_t;\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    \n}  // namespace ebi\n#line 2 \"template/io.hpp\"\n\n#line 5 \"template/io.hpp\"\
    \n#include <optional>\n#line 7 \"template/io.hpp\"\n\nnamespace ebi {\n\ntemplate\
    \ <typename T1, typename T2>\nstd::ostream &operator<<(std::ostream &os, const\
    \ std::pair<T1, T2> &pa) {\n    return os << pa.first << \" \" << pa.second;\n\
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
    \n\n#line 8 \"template/utility.hpp\"\n\nnamespace ebi {\n\ntemplate <class T>\
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
    \ dx = {0, 1, 0, -1, 1, -1, 1, -1};\n\n}  // namespace ebi\n#line 2 \"tree/centroid_decomposition.hpp\"\
    \n\n#line 7 \"tree/centroid_decomposition.hpp\"\n\nnamespace ebi {\n\nnamespace\
    \ internal {\n\ntemplate <class F>\nvoid centroid_decomposition_dfs_naive(const\
    \ std::vector<int> &par,\n                                      const std::vector<int>\
    \ &original_vs,\n                                      F f) {\n    const int n\
    \ = (int)par.size();\n    assert(par.size() == original_vs.size());\n    int center\
    \ = -1;\n    std::vector<int> sz(n, 1);\n    for (const int v : std::views::iota(0,\
    \ n) | std::views::reverse) {\n        if (sz[v] >= (n + 1) / 2) {\n         \
    \   center = v;\n            break;\n        }\n        sz[par[v]] += sz[v];\n\
    \    }\n    std::vector<int> color(n, -1);\n    std::vector<int> vs = {center};\n\
    \    color[center] = 0;\n    int c = 1;\n    for (const int v : std::views::iota(1,\
    \ n)) {\n        if (par[v] == center) {\n            vs.emplace_back(v);\n  \
    \          color[v] = c++;\n        }\n    }\n    if (center > 0) {\n        for\
    \ (int v = par[center]; v != -1; v = par[v]) {\n            vs.emplace_back(v);\n\
    \            color[v] = c;\n        }\n        c++;\n    }\n    for (const int\
    \ v : std::views::iota(0, n)) {\n        if (color[v] == -1) {\n            vs.emplace_back(v);\n\
    \            color[v] = color[par[v]];\n        }\n    }\n    std::vector<int>\
    \ index_ptr(c + 1, 0);\n    for (const int v : std::views::iota(0, n)) {\n   \
    \     index_ptr[color[v] + 1]++;\n    }\n    for (const int i : std::views::iota(0,\
    \ c)) {\n        index_ptr[i + 1] += index_ptr[i];\n    }\n    auto counter =\
    \ index_ptr;\n    std::vector<int> ord(n);\n    for (auto v : vs) {\n        ord[counter[color[v]]++]\
    \ = v;\n    }\n    std::vector<int> relabel(n);\n    for (const int v : std::views::iota(0,\
    \ n)) {\n        relabel[ord[v]] = v;\n    }\n    std::vector<int> original_vs2(n);\n\
    \    for (const int v : std::views::iota(0, n)) {\n        original_vs2[relabel[v]]\
    \ = original_vs[v];\n    }\n    std::vector<int> relabel_par(n, -1);\n    for\
    \ (int v : std::views::iota(1, n)) {\n        int a = relabel[v];\n        int\
    \ b = relabel[par[v]];\n        if (a > b) std::swap(a, b);\n        relabel_par[b]\
    \ = a;\n    }\n    f(relabel_par, original_vs2, index_ptr);\n    for (const int\
    \ i : std::views::iota(1, c)) {\n        int l = index_ptr[i], r = index_ptr[i\
    \ + 1];\n        std::vector<int> par1(r - l, -1);\n        std::vector<int> original_vs1(r\
    \ - l, -1);\n        for (int v : std::views::iota(l, r)) {\n            par1[v\
    \ - l] = (relabel_par[v] == 0 ? -1 : relabel_par[v] - l);\n            original_vs1[v\
    \ - l] = original_vs2[v];\n        }\n        centroid_decomposition_dfs_naive(par1,\
    \ original_vs1, f);\n    }\n    return;\n}\n\ntemplate <class F>\nvoid one_third_centroid_decomposition(const\
    \ std::vector<int> &par,\n                                      const std::vector<int>\
    \ &original_vs,\n                                      F f) {\n    const int n\
    \ = (int)par.size();\n    assert(n > 1);\n    if (n == 2) return;\n    int center\
    \ = -1;\n    std::vector<int> sz(n, 1);\n\n    for (const int v : std::views::iota(0,\
    \ n) | std::views::reverse) {\n        if (sz[v] >= (n + 1) / 2) {\n         \
    \   center = v;\n            break;\n        }\n        sz[par[v]] += sz[v];\n\
    \    }\n\n    std::vector<int> color(n, -1);\n    std::vector<int> ord(n, -1);\n\
    \    ord[center] = 0;\n    int t = 1;\n    int red = n - sz[center];\n    for\
    \ (int v = par[center]; v != -1; v = par[v]) {\n        ord[v] = t++;\n      \
    \  color[v] = 0;\n    }\n    for (const int v : std::views::iota(1, n)) {\n  \
    \      if (par[v] == center && 3 * (red + sz[v]) <= 2 * (n - 1)) {\n         \
    \   red += sz[v];\n            ord[v] = t++;\n            color[v] = 0;\n    \
    \    }\n    }\n    for (const int v : std::views::iota(1, n)) {\n        if (v\
    \ != center && color[v] == -1 && color[par[v]] == 0) {\n            ord[v] = t++;\n\
    \            color[v] = 0;\n        }\n    }\n    const int n0 = t - 1;\n    for\
    \ (const int v : std::views::iota(1, n)) {\n        if (v != center && color[v]\
    \ == -1) {\n            ord[v] = t++;\n            color[v] = 1;\n        }\n\
    \    }\n    assert(t == n);\n    const int n1 = n - 1 - n0;\n    std::vector<int>\
    \ par0(n0 + 1, -1), par1(n1 + 1, -1), par2(n, -1);\n    std::vector<int> original_vs0(n0\
    \ + 1), original_vs1(n1 + 1),\n        original_vs2(n);\n    for (const int i\
    \ : std::views::iota(0, n)) {\n        int v = ord[i];\n        original_vs2[v]\
    \ = original_vs[i];\n        if (color[i] != 1) {\n            original_vs0[v]\
    \ = original_vs[i];\n        }\n        if (color[i] != 0) {\n            int\
    \ idx = std::max(v - n0, 0);\n            original_vs1[idx] = original_vs[i];\n\
    \        }\n    }\n    for (const int v : std::views::iota(1, n)) {\n        int\
    \ a = ord[v], b = ord[par[v]];\n        if (a > b) std::swap(a, b);\n        par2[b]\
    \ = a;\n        if (color[v] != 1 && color[par[v]] != 1) {\n            par0[b]\
    \ = a;\n        }\n        if (color[v] != 0 && color[par[v]] != 0) {\n      \
    \      par1[b - n0] = std::max(a - n0, 0);\n        }\n    }\n    f(par2, original_vs2,\
    \ n0, n1);\n    one_third_centroid_decomposition(par0, original_vs0, f);\n   \
    \ one_third_centroid_decomposition(par1, original_vs1, f);\n    return;\n}\n\n\
    template <class F>\nvoid one_third_centroid_decomposition_virtual_real(\n    const\
    \ std::vector<int> &par, const std::vector<int> &original_vs,\n    const std::vector<int>\
    \ &is_real, F f) {\n    const int n = (int)par.size();\n    assert(n > 1);\n \
    \   if (n == 2) {\n        if (is_real[0] && is_real[1]) {\n            f(par,\
    \ original_vs, {0, 1});\n        }\n        return;\n    }\n    int center = -1;\n\
    \    std::vector<int> sz(n, 1);\n\n    for (const int v : std::views::iota(0,\
    \ n) | std::views::reverse) {\n        if (sz[v] >= (n + 1) / 2) {\n         \
    \   center = v;\n            break;\n        }\n        sz[par[v]] += sz[v];\n\
    \    }\n\n    std::vector<int> color(n, -1);\n    std::vector<int> ord(n, -1);\n\
    \    ord[center] = 0;\n    int t = 1;\n    int red = n - sz[center];\n    for\
    \ (int v = par[center]; v != -1; v = par[v]) {\n        ord[v] = t++;\n      \
    \  color[v] = 0;\n    }\n    for (const int v : std::views::iota(1, n)) {\n  \
    \      if (par[v] == center && 3 * (red + sz[v]) <= 2 * (n - 1)) {\n         \
    \   red += sz[v];\n            ord[v] = t++;\n            color[v] = 0;\n    \
    \    }\n    }\n    for (const int v : std::views::iota(1, n)) {\n        if (v\
    \ != center && color[v] == -1 && color[par[v]] == 0) {\n            ord[v] = t++;\n\
    \            color[v] = 0;\n        }\n    }\n    const int n0 = t - 1;\n    for\
    \ (const int v : std::views::iota(1, n)) {\n        if (v != center && color[v]\
    \ == -1) {\n            ord[v] = t++;\n            color[v] = 1;\n        }\n\
    \    }\n    assert(t == n);\n    const int n1 = n - 1 - n0;\n    std::vector<int>\
    \ par0(n0 + 1, -1), par1(n1 + 1, -1), par2(n, -1);\n    std::vector<int> original_vs0(n0\
    \ + 1), original_vs1(n1 + 1),\n        original_vs2(n);\n    std::vector<int>\
    \ is_real0(n0 + 1), is_real1(n1 + 1), is_real2(n);\n    for (const int i : std::views::iota(0,\
    \ n)) {\n        int v = ord[i];\n        original_vs2[v] = original_vs[i];\n\
    \        is_real2[v] = is_real[i];\n        if (color[i] != 1) {\n           \
    \ original_vs0[v] = original_vs[i];\n            is_real0[v] = is_real[i];\n \
    \       }\n        if (color[i] != 0) {\n            int idx = std::max(v - n0,\
    \ 0);\n            original_vs1[idx] = original_vs[i];\n            is_real1[idx]\
    \ = is_real[i];\n        }\n    }\n    for (const int v : std::views::iota(1,\
    \ n)) {\n        int a = ord[v], b = ord[par[v]];\n        if (a > b) std::swap(a,\
    \ b);\n        par2[b] = a;\n        if (color[v] != 1 && color[par[v]] != 1)\
    \ {\n            par0[b] = a;\n        }\n        if (color[v] != 0 && color[par[v]]\
    \ != 0) {\n            par1[b - n0] = std::max(a - n0, 0);\n        }\n    }\n\
    \    if (is_real[center]) {\n        color.assign(n, -1);\n        color[0] =\
    \ 0;\n        for (const int v : std::views::iota(1, n)) {\n            if (is_real2[v])\
    \ color[v] = 1;\n        }\n        f(par2, original_vs2, color);\n        is_real0[0]\
    \ = is_real1[0] = is_real2[0] = 0;\n    }\n    color.assign(n, -1);\n    for (const\
    \ int v : std::views::iota(1, n)) {\n        if (is_real2[v]) {\n            color[v]\
    \ = int(v > n0);\n        }\n    }\n    f(par2, original_vs2, color);\n    one_third_centroid_decomposition_virtual_real(par0,\
    \ original_vs0, is_real0,\n                                                  f);\n\
    \    one_third_centroid_decomposition_virtual_real(par1, original_vs1, is_real1,\n\
    \                                                  f);\n    return;\n}\n\n}  //\
    \ namespace internal\n\ntemplate <int MODE, class T, class F>\nvoid centroid_decomposition(const\
    \ Graph<T> &tree, F f) {\n    int n = (int)tree.size();\n    if (n == 1) return;\n\
    \    std::vector<int> bfs_order(n), par(n, -1);\n    bfs_order[0] = 0;\n    int\
    \ l = 0, r = 1;\n    while (l < r) {\n        int v = bfs_order[l++];\n      \
    \  for (auto e : tree[v]) {\n            int nv = e.to;\n            if (nv ==\
    \ par[v]) continue;\n            bfs_order[r++] = nv;\n            par[nv] = v;\n\
    \        }\n    }\n    assert(l == n && r == n);\n    {\n        std::vector<int>\
    \ relabel(n);\n        for (int i : std::views::iota(0, n)) {\n            relabel[bfs_order[i]]\
    \ = i;\n        }\n        std::vector<int> relabel_par(n, -1);\n        for (int\
    \ i : std::views::iota(1, n)) {\n            relabel_par[relabel[i]] = relabel[par[i]];\n\
    \        }\n        std::swap(par, relabel_par);\n    }\n    static_assert(MODE\
    \ == 0 || MODE == 1 || MODE == 2);\n    if constexpr (MODE == 0) {\n        internal::centroid_decomposition_dfs_naive(par,\
    \ bfs_order, f);\n    } else if constexpr (MODE == 1) {\n        internal::one_third_centroid_decomposition(par,\
    \ bfs_order, f);\n    } else {\n        internal::one_third_centroid_decomposition_virtual_real(\n\
    \            par, bfs_order, std::vector<int>(n, 1), f);\n    }\n}\n\n}  // namespace\
    \ ebi\n#line 8 \"test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp\"\n\
    \nnamespace ebi {\n\nvoid main_() {\n    int n;\n    std::cin >> n;\n    Graph<int>\
    \ tree(n);\n    tree.read_tree(0);\n    std::vector<u64> ans(n, 0);\n    ans[1]\
    \ = n - 1;\n    auto calc = [&](const std::vector<int> &par, const std::vector<int>\
    \ &vs,\n                    int n0, int n1) -> void {\n        int sz = (int)par.size();\n\
    \        assert(sz - 1 == n0 + n1);\n        std::vector<int> dist(sz, 0);\n \
    \       for (const int v : std::views::iota(1, sz)) {\n            dist[v] = dist[par[v]]\
    \ + 1;\n        }\n        std::vector<u64> f(sz, 0), g(sz, 0);\n        for (const\
    \ int v : std::views::iota(1, sz)) {\n            if (v < 1 + n0)\n          \
    \      f[dist[v]]++;\n            else\n                g[dist[v]]++;\n      \
    \  }\n        while (!f.empty() && f.back() == 0) f.pop_back();\n        while\
    \ (!g.empty() && g.back() == 0) g.pop_back();\n        auto h = convolution_mod_2_64(f,\
    \ g);\n        for (const int i : std::views::iota(0, (int)h.size())) {\n    \
    \        ans[i] += h[i];\n        }\n    };\n    centroid_decomposition<1>(tree,\
    \ calc);\n    ans.erase(ans.begin());\n    std::cout << ans << '\\n';\n}\n\n}\
    \  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n   \
    \ // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include \"../../convolution/convolution_mod_2_64.hpp\"\n#include \"../../graph/base.hpp\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../tree/centroid_decomposition.hpp\"\
    \n\nnamespace ebi {\n\nvoid main_() {\n    int n;\n    std::cin >> n;\n    Graph<int>\
    \ tree(n);\n    tree.read_tree(0);\n    std::vector<u64> ans(n, 0);\n    ans[1]\
    \ = n - 1;\n    auto calc = [&](const std::vector<int> &par, const std::vector<int>\
    \ &vs,\n                    int n0, int n1) -> void {\n        int sz = (int)par.size();\n\
    \        assert(sz - 1 == n0 + n1);\n        std::vector<int> dist(sz, 0);\n \
    \       for (const int v : std::views::iota(1, sz)) {\n            dist[v] = dist[par[v]]\
    \ + 1;\n        }\n        std::vector<u64> f(sz, 0), g(sz, 0);\n        for (const\
    \ int v : std::views::iota(1, sz)) {\n            if (v < 1 + n0)\n          \
    \      f[dist[v]]++;\n            else\n                g[dist[v]]++;\n      \
    \  }\n        while (!f.empty() && f.back() == 0) f.pop_back();\n        while\
    \ (!g.empty() && g.back() == 0) g.pop_back();\n        auto h = convolution_mod_2_64(f,\
    \ g);\n        for (const int i : std::views::iota(0, (int)h.size())) {\n    \
    \        ans[i] += h[i];\n        }\n    };\n    centroid_decomposition<1>(tree,\
    \ calc);\n    ans.erase(ans.begin());\n    std::cout << ans << '\\n';\n}\n\n}\
    \  // namespace ebi\n\nint main() {\n    ebi::fast_io();\n    int t = 1;\n   \
    \ // std::cin >> t;\n    while (t--) {\n        ebi::main_();\n    }\n    return\
    \ 0;\n}"
  dependsOn:
  - convolution/convolution_mod_2_64.hpp
  - convolution/ntt.hpp
  - math/internal_math.hpp
  - modint/base.hpp
  - modint/modint.hpp
  - graph/base.hpp
  - data_structure/simple_csr.hpp
  - template/template.hpp
  - template/debug_template.hpp
  - template/int_alias.hpp
  - template/io.hpp
  - template/utility.hpp
  - tree/centroid_decomposition.hpp
  isVerificationFile: true
  path: test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp
  requiredBy: []
  timestamp: '2024-03-13 01:44:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp
- /verify/test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp.html
title: test/tree/Frequency_Table_of_Tree_Distance_MODE_1.test.cpp
---
