---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/convolution_mod_2_64.hpp
    title: Convolution $\pmod{2^{64}}$
  - icon: ':question:'
    path: convolution/ntt.hpp
    title: NTT Convolution
  - icon: ':question:'
    path: graph/template.hpp
    title: graph/template.hpp
  - icon: ':question:'
    path: math/internal_math.hpp
    title: math/internal_math.hpp
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':x:'
    path: tree/centroid_decomposition.hpp
    title: Centroid Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"test/tree/Frequency_Table_of_Tree_Distance.test.cpp\"\n\
    #define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include <cstdint>\n#include <iostream>\n#include <queue>\n#include <vector>\n\
    \n#line 2 \"convolution/convolution_mod_2_64.hpp\"\n\n#line 5 \"convolution/convolution_mod_2_64.hpp\"\
    \n\n#line 2 \"convolution/ntt.hpp\"\n\n#include <algorithm>\n#include <array>\n\
    #include <bit>\n#include <cassert>\n#line 8 \"convolution/ntt.hpp\"\n\n#line 2\
    \ \"math/internal_math.hpp\"\n\n#line 4 \"math/internal_math.hpp\"\n\nnamespace\
    \ ebi {\n\nnamespace internal {\n\nconstexpr int primitive_root_constexpr(int\
    \ m) {\n    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m\
    \ == 469762049) return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353)\
    \ return 3;\n    if (m == 880803841) return 26;\n    if (m == 924844033) return\
    \ 5;\n    return -1;\n}\ntemplate <int m> constexpr int primitive_root = primitive_root_constexpr(m);\n\
    \n}  // namespace internal\n\n}  // namespace ebi\n#line 2 \"modint/base.hpp\"\
    \n\n#include <concepts>\n#line 5 \"modint/base.hpp\"\n#include <utility>\n\nnamespace\
    \ ebi {\n\ntemplate <class T>\nconcept Modint = requires(T a, T b) {\n    a +\
    \ b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n    a.pow(std::declval<long\
    \ long>());\n    T::mod();\n};\n\ntemplate <Modint mint> std::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <Modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 11 \"\
    convolution/ntt.hpp\"\n\nnamespace ebi {\n\nnamespace internal {\n\ntemplate <Modint\
    \ mint, int g = internal::primitive_root<mint::mod()>>\nstruct ntt_info {\n  \
    \  static constexpr int rank2 = std::countr_zero(uint(mint::mod() - 1));\n\n \
    \   std::array<mint, rank2 + 1> root, inv_root;\n\n    ntt_info() {\n        root[rank2]\
    \ = mint(g).pow((mint::mod() - 1) >> rank2);\n        inv_root[rank2] = root[rank2].inv();\n\
    \        for (int i = rank2 - 1; i >= 0; i--) {\n            root[i] = root[i\
    \ + 1] * root[i + 1];\n            inv_root[i] = inv_root[i + 1] * inv_root[i\
    \ + 1];\n        }\n    }\n};\n\ntemplate <Modint mint> void butterfly(std::vector<mint>&\
    \ a) {\n    static const ntt_info<mint> info;\n    int n = int(a.size());\n  \
    \  int bit_size = std::countr_zero(a.size());\n    assert(n == (int)std::bit_ceil(a.size()));\n\
    \n    // bit reverse\n    for (int i = 0, j = 1; j < n - 1; j++) {\n        for\
    \ (int k = n >> 1; k > (i ^= k); k >>= 1)\n            ;\n        if (j < i) {\n\
    \            std::swap(a[i], a[j]);\n        }\n    }\n\n    for (int bit = 0;\
    \ bit < bit_size; bit++) {\n        for (int i = 0; i < n / (1 << (bit + 1));\
    \ i++) {\n            mint zeta1 = 1;\n            mint zeta2 = info.root[1];\n\
    \            for (int j = 0; j < (1 << bit); j++) {\n                int idx =\
    \ i * (1 << (bit + 1)) + j;\n                int jdx = idx + (1 << bit);\n   \
    \             mint p1 = a[idx];\n                mint p2 = a[jdx];\n         \
    \       a[idx] = p1 + zeta1 * p2;\n                a[jdx] = p1 + zeta2 * p2;\n\
    \                zeta1 *= info.root[bit + 1];\n                zeta2 *= info.root[bit\
    \ + 1];\n            }\n        }\n    }\n}\n\ntemplate <Modint mint> void butterfly_inv(std::vector<mint>&\
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
    \ m;\r\n    }\r\n};\r\n\r\ntemplate <int m>\r\nstd::istream &operator>>(std::istream\
    \ &os, static_modint<m> &a) {\r\n    long long x;\r\n    os >> x;\r\n    a = x;\r\
    \n    return os;\r\n}\r\ntemplate <int m>\r\nstd::ostream &operator<<(std::ostream\
    \ &os, const static_modint<m> &a) {\r\n    return os << a.val();\r\n}\r\n\r\n\
    using modint998244353 = static_modint<998244353>;\r\nusing modint1000000007 =\
    \ static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 9 \"convolution/convolution_mod_2_64.hpp\"\
    \n\nnamespace ebi {\n\nnamespace internal {\n\ntemplate <Modint mint>\nstd::vector<mint>\
    \ multiply_uint64_t(const std::vector<std::uint64_t>& f,\n                   \
    \                 const std::vector<std::uint64_t>& g) {\n    std::vector<mint>\
    \ a, b;\n    a.reserve(f.size());\n    b.reserve(g.size());\n    for (auto x :\
    \ f) a.emplace_back(x % mint::mod());\n    for (auto x : g) b.emplace_back(x %\
    \ mint::mod());\n    return convolution<mint>(a, b);\n}\n\n}  // namespace internal\n\
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
    \ 2 \"graph/template.hpp\"\n\r\n#line 4 \"graph/template.hpp\"\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <class T> struct Edge {\r\n    int to;\r\n    T cost;\r\
    \n    Edge(int _to, T _cost = 1) : to(_to), cost(_cost) {}\r\n};\r\n\r\ntemplate\
    \ <class T> struct Graph : std::vector<std::vector<Edge<T>>> {\r\n    using std::vector<std::vector<Edge<T>>>::vector;\r\
    \n    void add_edge(int u, int v, T w, bool directed = false) {\r\n        (*this)[u].emplace_back(v,\
    \ w);\r\n        if (directed) return;\r\n        (*this)[v].emplace_back(u, w);\r\
    \n    }\r\n};\r\n\r\nstruct graph : std::vector<std::vector<int>> {\r\n    using\
    \ std::vector<std::vector<int>>::vector;\r\n    void add_edge(int u, int v, bool\
    \ directed = false) {\r\n        (*this)[u].emplace_back(v);\r\n        if (directed)\
    \ return;\r\n        (*this)[v].emplace_back(u);\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\n#line 2 \"tree/centroid_decomposition.hpp\"\n\r\n#line 4 \"tree/centroid_decomposition.hpp\"\
    \n\r\n/*\r\n    reference: https://qiita.com/drken/items/4b4c3f1824339b090202\r\
    \n               https://ferin-tech.hatenablog.com/entry/2020/03/06/162311\r\n\
    */\r\n\r\nnamespace ebi {\r\n\r\nstruct centroid_decomposition {\r\n  private:\r\
    \n    int find_centroid(int _root) {\r\n        auto get_size = [&](auto &&self,\
    \ int v, int p = -1) -> int {\r\n            sz[v] = 1;\r\n            for (auto\
    \ nv : g[v])\r\n                if (nv != p && !dead[nv]) {\r\n              \
    \      sz[v] += self(self, nv, v);\r\n                }\r\n            return\
    \ sz[v];\r\n        };\r\n        get_size(get_size, _root);\r\n        auto dfs_centroid\
    \ = [&](auto &&self, int v, int p = -1) -> int {\r\n            for (auto nv :\
    \ g[v])\r\n                if (nv != p && !dead[nv]) {\r\n                   \
    \ if (sz[nv] > sz[_root] / 2) return self(self, nv, v);\r\n                }\r\
    \n            return v;\r\n        };\r\n        return dfs_centroid(dfs_centroid,\
    \ _root);\r\n    }\r\n\r\n    int build(int v = 0, int depth = 0) {\r\n      \
    \  int c = find_centroid(v);\r\n        dead[c] = true;\r\n        for (auto nv\
    \ : g[c])\r\n            if (!dead[nv]) {\r\n                int ch = build(nv,\
    \ depth + 1);\r\n                belong[c].emplace_back(ch);\r\n             \
    \   par[ch] = c;\r\n            }\r\n        dead[c] = false;\r\n        return\
    \ root = c;\r\n    }\r\n\r\n  public:\r\n    centroid_decomposition(const std::vector<std::vector<int>>\
    \ &_g)\r\n        : n(int(_g.size())),\r\n          g(_g),\r\n          dead(n,\
    \ false),\r\n          sz(n, -1),\r\n          par(n, -1),\r\n          belong(n)\
    \ {\r\n        build();\r\n    }\r\n\r\n    std::pair<int, std::vector<std::vector<int>>>\r\
    \n    get_centroid_decomposition_tree() const {\r\n        return {root, belong};\r\
    \n    }\r\n\r\n    int parent(int v) const {\r\n        return par[v];\r\n   \
    \ }\r\n\r\n  private:\r\n    int n;\r\n    int root;\r\n    std::vector<std::vector<int>>\
    \ g;\r\n    std::vector<bool> dead;\r\n    std::vector<int> sz;\r\n    std::vector<int>\
    \ par;\r\n    std::vector<std::vector<int>> belong;\r\n};\r\n\r\n}  // namespace\
    \ ebi\n#line 12 \"test/tree/Frequency_Table_of_Tree_Distance.test.cpp\"\n\nusing\
    \ u64 = uint64_t;\n\nint main() {\n    int n;\n    std::cin >> n;\n    ebi::graph\
    \ g(n);\n    for (int i = 0; i < n - 1; i++) {\n        int a, b;\n        std::cin\
    \ >> a >> b;\n        g.add_edge(a, b);\n    }\n    ebi::centroid_decomposition\
    \ cdtree(g);\n    auto [root, tree] = cdtree.get_centroid_decomposition_tree();\n\
    \    std::vector<bool> dead(n, false);\n    std::vector<u64> ans(n, 0);\n    std::vector<u64>\
    \ cnts;\n    std::vector<u64> depths;\n    auto dfs_depth = [&](auto &&self, int\
    \ v, int par = -1,\n                         int depth = 0) -> void {\n      \
    \  while ((int)cnts.size() <= depth) cnts.emplace_back(0);\n        while ((int)depths.size()\
    \ <= depth) depths.emplace_back(0);\n        cnts[depth]++;\n        depths[depth]++;\n\
    \        for (auto nv : g[v])\n            if (nv != par && !dead[nv]) {\n   \
    \             self(self, nv, v, depth + 1);\n            }\n    };\n    std::queue<int>\
    \ que;\n    que.push(root);\n    while (!que.empty()) {\n        auto v = que.front();\n\
    \        que.pop();\n        cnts.clear();\n        dead[v] = true;\n        for\
    \ (auto nv : tree[v]) que.push(nv);\n        for (auto nv : g[v]) {\n        \
    \    if (dead[nv]) continue;\n            depths.clear();\n            dfs_depth(dfs_depth,\
    \ nv, v, 1);\n            auto self2 = ebi::convolution_mod_2_64(depths, depths);\n\
    \            for (int i = 0; i < (int)self2.size(); i++) ans[i] -= self2[i];\n\
    \        }\n        if (cnts.empty()) continue;\n        cnts[0]++;\n        auto\
    \ cnts2 = ebi::convolution_mod_2_64(cnts, cnts);\n        for (int i = 0; i <\
    \ (int)cnts2.size(); i++) ans[i] += cnts2[i];\n    }\n    for (int i = 1; i <\
    \ n; i++) {\n        ans[i] >>= 1;\n        std::cout << ans[i] << \" \\n\"[i\
    \ == n - 1];\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include <cstdint>\n#include <iostream>\n#include <queue>\n#include <vector>\n\
    \n#include \"../../convolution/convolution_mod_2_64.hpp\"\n#include \"../../graph/template.hpp\"\
    \n#include \"../../tree/centroid_decomposition.hpp\"\n\nusing u64 = uint64_t;\n\
    \nint main() {\n    int n;\n    std::cin >> n;\n    ebi::graph g(n);\n    for\
    \ (int i = 0; i < n - 1; i++) {\n        int a, b;\n        std::cin >> a >> b;\n\
    \        g.add_edge(a, b);\n    }\n    ebi::centroid_decomposition cdtree(g);\n\
    \    auto [root, tree] = cdtree.get_centroid_decomposition_tree();\n    std::vector<bool>\
    \ dead(n, false);\n    std::vector<u64> ans(n, 0);\n    std::vector<u64> cnts;\n\
    \    std::vector<u64> depths;\n    auto dfs_depth = [&](auto &&self, int v, int\
    \ par = -1,\n                         int depth = 0) -> void {\n        while\
    \ ((int)cnts.size() <= depth) cnts.emplace_back(0);\n        while ((int)depths.size()\
    \ <= depth) depths.emplace_back(0);\n        cnts[depth]++;\n        depths[depth]++;\n\
    \        for (auto nv : g[v])\n            if (nv != par && !dead[nv]) {\n   \
    \             self(self, nv, v, depth + 1);\n            }\n    };\n    std::queue<int>\
    \ que;\n    que.push(root);\n    while (!que.empty()) {\n        auto v = que.front();\n\
    \        que.pop();\n        cnts.clear();\n        dead[v] = true;\n        for\
    \ (auto nv : tree[v]) que.push(nv);\n        for (auto nv : g[v]) {\n        \
    \    if (dead[nv]) continue;\n            depths.clear();\n            dfs_depth(dfs_depth,\
    \ nv, v, 1);\n            auto self2 = ebi::convolution_mod_2_64(depths, depths);\n\
    \            for (int i = 0; i < (int)self2.size(); i++) ans[i] -= self2[i];\n\
    \        }\n        if (cnts.empty()) continue;\n        cnts[0]++;\n        auto\
    \ cnts2 = ebi::convolution_mod_2_64(cnts, cnts);\n        for (int i = 0; i <\
    \ (int)cnts2.size(); i++) ans[i] += cnts2[i];\n    }\n    for (int i = 1; i <\
    \ n; i++) {\n        ans[i] >>= 1;\n        std::cout << ans[i] << \" \\n\"[i\
    \ == n - 1];\n    }\n}"
  dependsOn:
  - convolution/convolution_mod_2_64.hpp
  - convolution/ntt.hpp
  - math/internal_math.hpp
  - modint/base.hpp
  - modint/modint.hpp
  - graph/template.hpp
  - tree/centroid_decomposition.hpp
  isVerificationFile: true
  path: test/tree/Frequency_Table_of_Tree_Distance.test.cpp
  requiredBy: []
  timestamp: '2023-10-26 11:41:06+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/tree/Frequency_Table_of_Tree_Distance.test.cpp
layout: document
redirect_from:
- /verify/test/tree/Frequency_Table_of_Tree_Distance.test.cpp
- /verify/test/tree/Frequency_Table_of_Tree_Distance.test.cpp.html
title: test/tree/Frequency_Table_of_Tree_Distance.test.cpp
---
