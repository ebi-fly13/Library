---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: segtree
  - icon: ':heavy_check_mark:'
    path: tree/heavy_light_decomposition.hpp
    title: heavy light decomposition
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/vertex_set_path_compositie.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\n\n#include <iostream>\n\
    #include <vector>\n\n#line 2 \"data_structure/segtree.hpp\"\n\r\n#include <cassert>\r\
    \n#line 5 \"data_structure/segtree.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)()> struct segtree {\r\n  private:\r\n    int\
    \ n;\r\n    int sz;\r\n    std::vector<S> data;\r\n\r\n    void update(int i)\
    \ {\r\n        data[i] = op(data[2 * i], data[2 * i + 1]);\r\n    }\r\n\r\n  public:\r\
    \n    segtree(int n) : segtree(std::vector<S>(n, e())) {}\r\n    segtree(const\
    \ std::vector<S> &v) : n((int)v.size()), sz(1) {\r\n        while (sz < n) sz\
    \ *= 2;\r\n        data = std::vector<S>(2 * sz, e());\r\n        for (int i =\
    \ 0; i < n; i++) {\r\n            data[sz + i] = v[i];\r\n        }\r\n      \
    \  for (int i = sz - 1; i >= 1; i--) update(i);\r\n    }\r\n\r\n    void set(int\
    \ p, S x) {\r\n        assert(0 <= p && p < n);\r\n        p += sz;\r\n      \
    \  data[p] = x;\r\n        while (p > 1) {\r\n            p >>= 1;\r\n       \
    \     update(p);\r\n        }\r\n    }\r\n\r\n    S get(int p) {\r\n        assert(0\
    \ <= p && p < n);\r\n        return data[p + sz];\r\n    }\r\n\r\n    S prod(int\
    \ l, int r) {\r\n        assert(0 <= l && l <= r && r <= n);\r\n        S sml\
    \ = e(), smr = e();\r\n        l += sz;\r\n        r += sz;\r\n        while (l\
    \ < r) {\r\n            if (l & 1) sml = op(sml, data[l++]);\r\n            if\
    \ (r & 1) smr = op(data[--r], smr);\r\n            l >>= 1;\r\n            r >>=\
    \ 1;\r\n        }\r\n        return op(sml, smr);\r\n    }\r\n\r\n    S all_prod()\
    \ {\r\n        return data[1];\r\n    }\r\n\r\n    template <class F> int max_right(int\
    \ l, F f) {\r\n        assert(0 <= l && l < n);\r\n        assert(f(e()));\r\n\
    \        if (l == n) return n;\r\n        l += sz;\r\n        S sm = e();\r\n\
    \        do {\r\n            while (l % 2 == 0) l >>= 1;\r\n            if (!f(op(sm,\
    \ data[l]))) {\r\n                while (l < sz) {\r\n                    l =\
    \ 2 * l;\r\n                    if (f(op(sm, data[l]))) {\r\n                \
    \        sm = op(sm, data[l]);\r\n                        l++;\r\n           \
    \         }\r\n                }\r\n                return l - sz;\r\n       \
    \     }\r\n            sm = op(sm, data[l]);\r\n            l++;\r\n        }\
    \ while ((l & -l) != l);\r\n        return n;\r\n    }\r\n\r\n    template <class\
    \ F> int min_left(int r, F f) {\r\n        assert(0 <= r && r <= n);\r\n     \
    \   assert(f(e()));\r\n        if (r == 0) return 0;\r\n        r += sz;\r\n \
    \       S sm = e();\r\n        do {\r\n            r--;\r\n            while (r\
    \ > 1 && (r % 2)) r >>= 1;\r\n            if (!f(op(data[r], sm))) {\r\n     \
    \           while (r < sz) {\r\n                    r = 2 * r + 1;\r\n       \
    \             if (f(op(data[r], sm))) {\r\n                        sm = op(data[r],\
    \ sm);\r\n                        r--;\r\n                    }\r\n          \
    \      }\r\n                return r + 1 - sz;\r\n            }\r\n          \
    \  sm = op(data[r], sm);\r\n        } while ((r & -r) != r);\r\n        return\
    \ 0;\r\n    }\r\n\r\n    S operator[](int p) const {\r\n        return data[sz\
    \ + p];\r\n    }\r\n};\r\n\r\n}  // namespace ebi\r\n#line 2 \"tree/heavy_light_decomposition.hpp\"\
    \n\n#line 5 \"tree/heavy_light_decomposition.hpp\"\n\nnamespace ebi {\n\nstruct\
    \ heavy_light_decomposition {\n  private:\n    void dfs_sz(int v) {\n        for\
    \ (auto &nv : g[v]) {\n            if (nv == par[v]) continue;\n            par[nv]\
    \ = v;\n            depth[nv] = depth[v] + 1;\n            dfs_sz(nv);\n     \
    \       sz[v] += sz[nv];\n            if (sz[nv] > sz[g[v][0]] || g[v][0] == par[v])\n\
    \                std::swap(nv, g[v][0]);\n        }\n    }\n\n    void dfs_hld(int\
    \ v) {\n        static int t = 0;\n        in[v] = t++;\n        for (auto nv\
    \ : g[v]) {\n            if (nv == par[v]) continue;\n            nxt[nv] = (nv\
    \ == g[v][0] ? nxt[v] : nv);\n            dfs_hld(nv);\n        }\n        out[v]\
    \ = t;\n    }\n\n    // [u, v) \u30D1\u30B9\u306E\u53D6\u5F97 (v \u306F u \u306E\
    \u7956\u5148)\n    std::vector<std::pair<int, int>> ascend(int u, int v) const\
    \ {\n        std::vector<std::pair<int, int>> res;\n        while (nxt[u] != nxt[v])\
    \ {\n            res.emplace_back(in[u], in[nxt[u]]);\n            u = par[nxt[u]];\n\
    \        }\n        if (u != v) res.emplace_back(in[u], in[v] + 1);\n        return\
    \ res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\u5F97 (u \u306F v \u306E\
    \u7956\u5148)\n    std::vector<std::pair<int, int>> descend(int u, int v) const\
    \ {\n        if (u == v) return {};\n        if (nxt[u] == nxt[v]) return {{in[u]\
    \ + 1, in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n        res.emplace_back(in[nxt[v]],\
    \ in[v]);\n        return res;\n    }\n\n  public:\n    heavy_light_decomposition(const\
    \ std::vector<std::vector<int>> &gh,\n                              int root =\
    \ 0)\n        : n(gh.size()),\n          g(gh),\n          sz(n, 1),\n       \
    \   in(n),\n          out(n),\n          nxt(n),\n          par(n, -1),\n    \
    \      depth(n, 0) {\n        dfs_sz(root);\n        dfs_hld(root);\n    }\n\n\
    \    int idx(int u) const {\n        return in[u];\n    }\n\n    int lca(int u,\
    \ int v) const {\n        while (nxt[u] != nxt[v]) {\n            if (in[u] <\
    \ in[v]) std::swap(u, v);\n            u = par[nxt[u]];\n        }\n        return\
    \ depth[u] < depth[v] ? u : v;\n    }\n\n    int distance(int u, int v) const\
    \ {\n        return depth[u] + depth[v] - 2 * depth[lca(u, v)];\n    }\n\n   \
    \ template <class F>\n    void path_noncommutative_query(int u, int v, bool vertex,\n\
    \                                   const F &f) const {\n        int l = lca(u,\
    \ v);\n        for (auto [a, b] : ascend(u, l)) f(a + 1, b);\n        if (vertex)\
    \ f(in[l], in[l] + 1);\n        for (auto [a, b] : descend(l, v)) f(a, b + 1);\n\
    \    }\n\n    template <class F> void subtree_query(int u, bool vertex, const\
    \ F &f) {\n        f(in[u] + int(!vertex), out[u]);\n    }\n\n  private:\n   \
    \ int n;\n    std::vector<std::vector<int>> g;\n    std::vector<int> sz, in, out,\
    \ nxt, par, depth;\n};\n\n}  // namespace ebi\n#line 2 \"utility/modint.hpp\"\n\
    \r\n/*\r\n    author: noshi91\r\n    reference: https://noshi91.hatenablog.com/entry/2019/03/31/174006\r\
    \n    noshi91\u306E\u30D6\u30ED\u30B0\u3067\u516C\u958B\u3055\u308C\u3066\u3044\
    \u308Bmodint\u3092\u5143\u306Binv(), pow()\u3092\u8FFD\u52A0\u3057\u305F\u3082\
    \u306E\u3067\u3059\r\n*/\r\n\r\n#include <cstdint>\r\n#line 11 \"utility/modint.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate <std::uint_fast64_t Modulus> class modint\
    \ {\r\n    using u64 = std::uint_fast64_t;\r\n\r\n  public:\r\n    u64 a;\r\n\r\
    \n    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}\r\n    constexpr\
    \ u64 &value() noexcept {\r\n        return a;\r\n    }\r\n    constexpr u64 &val()\
    \ noexcept {\r\n        return a;\r\n    }\r\n    constexpr const u64 &value()\
    \ const noexcept {\r\n        return a;\r\n    }\r\n    constexpr modint operator+(const\
    \ modint rhs) const noexcept {\r\n        return modint(*this) += rhs;\r\n   \
    \ }\r\n    constexpr modint operator-(const modint rhs) const noexcept {\r\n \
    \       return modint(*this) -= rhs;\r\n    }\r\n    constexpr modint operator*(const\
    \ modint rhs) const noexcept {\r\n        return modint(*this) *= rhs;\r\n   \
    \ }\r\n    constexpr modint operator/(const modint rhs) const noexcept {\r\n \
    \       return modint(*this) /= rhs;\r\n    }\r\n    constexpr modint &operator+=(const\
    \ modint rhs) noexcept {\r\n        a += rhs.a;\r\n        if (a >= Modulus) {\r\
    \n            a -= Modulus;\r\n        }\r\n        return *this;\r\n    }\r\n\
    \    constexpr modint &operator-=(const modint rhs) noexcept {\r\n        if (a\
    \ < rhs.a) {\r\n            a += Modulus;\r\n        }\r\n        a -= rhs.a;\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator*=(const modint\
    \ rhs) noexcept {\r\n        a = a * rhs.a % Modulus;\r\n        return *this;\r\
    \n    }\r\n    constexpr modint &operator/=(modint rhs) noexcept {\r\n       \
    \ u64 exp = Modulus - 2;\r\n        while (exp) {\r\n            if (exp % 2)\
    \ {\r\n                *this *= rhs;\r\n            }\r\n            rhs *= rhs;\r\
    \n            exp /= 2;\r\n        }\r\n        return *this;\r\n    }\r\n   \
    \ constexpr modint operator-() const {\r\n        return modint() - *this;\r\n\
    \    }\r\n    bool operator==(const u64 rhs) {\r\n        return a == rhs;\r\n\
    \    }\r\n    bool operator!=(const u64 rhs) {\r\n        return a != rhs;\r\n\
    \    }\r\n    constexpr modint &operator++() {\r\n        a++;\r\n        if (a\
    \ == mod()) a = 0;\r\n        return *this;\r\n    }\r\n    constexpr modint &operator--()\
    \ {\r\n        if (a == 0) a = mod();\r\n        a--;\r\n        return *this;\r\
    \n    }\r\n\r\n    modint pow(u64 n) const noexcept {\r\n        modint res =\
    \ 1;\r\n        modint x = a;\r\n        while (n > 0) {\r\n            if (n\
    \ & 1) res *= x;\r\n            x *= x;\r\n            n >>= 1;\r\n        }\r\
    \n        return res;\r\n    }\r\n    modint inv() const {\r\n        return pow(Modulus\
    \ - 2);\r\n    }\r\n\r\n    static u64 mod() {\r\n        return Modulus;\r\n\
    \    }\r\n};\r\n\r\nusing modint998244353 = modint<998244353>;\r\nusing modint1000000007\
    \ = modint<1000000007>;\r\n\r\ntemplate <std::uint_fast64_t Modulus>\r\nstd::ostream\
    \ &operator<<(std::ostream &os, modint<Modulus> a) {\r\n    return os << a.val();\r\
    \n}\r\n\r\n}  // namespace ebi\n#line 9 \"test/vertex_set_path_compositie.test.cpp\"\
    \n\nusing mint = ebi::modint998244353;\n\nusing i64 = std::int64_t;\n\nstruct\
    \ S {\n    mint c, d;\n};\n\nS op(S a, S b) {\n    return {b.c * a.c, b.c * a.d\
    \ + b.d};\n}\n\nS e() {\n    return {1, 0};\n}\n\nint main() {\n    int n, q;\n\
    \    std::cin >> n >> q;\n    std::vector g(n, std::vector<int>());\n    std::vector<S>\
    \ fx(n);\n    for (int i = 0; i < n; i++) {\n        int a, b;\n        std::cin\
    \ >> a >> b;\n        fx[i] = {a, b};\n    }\n    for (int i = 0; i < n - 1; i++)\
    \ {\n        int u, v;\n        std::cin >> u >> v;\n        g[u].emplace_back(v);\n\
    \        g[v].emplace_back(u);\n    }\n    ebi::heavy_light_decomposition hld(g);\n\
    \    ebi::segtree<S, op, e> seg1(n);\n    ebi::segtree<S, op, e> seg2(n);\n  \
    \  for (int i = 0; i < n; i++) {\n        int idx = hld.idx(i);\n        seg1.set(idx,\
    \ fx[i]);\n        seg2.set(n - 1 - idx, fx[i]);\n    }\n    S ans = e();\n  \
    \  auto f = [&](int l, int r) -> void {\n        if (l <= r) {\n            ans\
    \ = op(ans, seg1.prod(l, r));\n        } else {\n            ans = op(ans, seg2.prod(n\
    \ - l, n - r));\n        }\n    };\n    while (q--) {\n        int t;\n      \
    \  std::cin >> t;\n        if (t == 0) {\n            int p, c, d;\n         \
    \   std::cin >> p >> c >> d;\n            int idx = hld.idx(p);\n            seg1.set(idx,\
    \ {c, d});\n            seg2.set(n - 1 - idx, {c, d});\n        } else {\n   \
    \         int u, v, x;\n            std::cin >> u >> v >> x;\n            ans\
    \ = e();\n            hld.path_noncommutative_query(u, v, true, f);\n        \
    \    std::cout << (ans.c * x + ans.d).val() << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../data_structure/segtree.hpp\"\
    \n#include \"../tree/heavy_light_decomposition.hpp\"\n#include \"../utility/modint.hpp\"\
    \n\nusing mint = ebi::modint998244353;\n\nusing i64 = std::int64_t;\n\nstruct\
    \ S {\n    mint c, d;\n};\n\nS op(S a, S b) {\n    return {b.c * a.c, b.c * a.d\
    \ + b.d};\n}\n\nS e() {\n    return {1, 0};\n}\n\nint main() {\n    int n, q;\n\
    \    std::cin >> n >> q;\n    std::vector g(n, std::vector<int>());\n    std::vector<S>\
    \ fx(n);\n    for (int i = 0; i < n; i++) {\n        int a, b;\n        std::cin\
    \ >> a >> b;\n        fx[i] = {a, b};\n    }\n    for (int i = 0; i < n - 1; i++)\
    \ {\n        int u, v;\n        std::cin >> u >> v;\n        g[u].emplace_back(v);\n\
    \        g[v].emplace_back(u);\n    }\n    ebi::heavy_light_decomposition hld(g);\n\
    \    ebi::segtree<S, op, e> seg1(n);\n    ebi::segtree<S, op, e> seg2(n);\n  \
    \  for (int i = 0; i < n; i++) {\n        int idx = hld.idx(i);\n        seg1.set(idx,\
    \ fx[i]);\n        seg2.set(n - 1 - idx, fx[i]);\n    }\n    S ans = e();\n  \
    \  auto f = [&](int l, int r) -> void {\n        if (l <= r) {\n            ans\
    \ = op(ans, seg1.prod(l, r));\n        } else {\n            ans = op(ans, seg2.prod(n\
    \ - l, n - r));\n        }\n    };\n    while (q--) {\n        int t;\n      \
    \  std::cin >> t;\n        if (t == 0) {\n            int p, c, d;\n         \
    \   std::cin >> p >> c >> d;\n            int idx = hld.idx(p);\n            seg1.set(idx,\
    \ {c, d});\n            seg2.set(n - 1 - idx, {c, d});\n        } else {\n   \
    \         int u, v, x;\n            std::cin >> u >> v >> x;\n            ans\
    \ = e();\n            hld.path_noncommutative_query(u, v, true, f);\n        \
    \    std::cout << (ans.c * x + ans.d).val() << '\\n';\n        }\n    }\n}"
  dependsOn:
  - data_structure/segtree.hpp
  - tree/heavy_light_decomposition.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/vertex_set_path_compositie.test.cpp
  requiredBy: []
  timestamp: '2023-05-08 16:51:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/vertex_set_path_compositie.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_set_path_compositie.test.cpp
- /verify/test/vertex_set_path_compositie.test.cpp.html
title: test/vertex_set_path_compositie.test.cpp
---
