---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segtree.hpp
    title: segtree
  - icon: ':heavy_check_mark:'
    path: tree/heavy_light_decomposition.hpp
    title: Heavy Light Decomposition
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/data_structure/Vertex_Set_Path_Compositie.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"data_structure/segtree.hpp\"\
    \n\r\n#include <cassert>\r\n#line 5 \"data_structure/segtree.hpp\"\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate <class S, S (*op)(S, S), S (*e)()> struct segtree {\r\n\
    \  private:\r\n    int n;\r\n    int sz;\r\n    std::vector<S> data;\r\n\r\n \
    \   void update(int i) {\r\n        data[i] = op(data[2 * i], data[2 * i + 1]);\r\
    \n    }\r\n\r\n  public:\r\n    segtree(int n) : segtree(std::vector<S>(n, e()))\
    \ {}\r\n    segtree(const std::vector<S> &v) : n((int)v.size()), sz(1) {\r\n \
    \       while (sz < n) sz *= 2;\r\n        data = std::vector<S>(2 * sz, e());\r\
    \n        for (int i = 0; i < n; i++) {\r\n            data[sz + i] = v[i];\r\n\
    \        }\r\n        for (int i = sz - 1; i >= 1; i--) update(i);\r\n    }\r\n\
    \r\n    void set(int p, S x) {\r\n        assert(0 <= p && p < n);\r\n       \
    \ p += sz;\r\n        data[p] = x;\r\n        while (p > 1) {\r\n            p\
    \ >>= 1;\r\n            update(p);\r\n        }\r\n    }\r\n\r\n    S get(int\
    \ p) const {\r\n        assert(0 <= p && p < n);\r\n        return data[p + sz];\r\
    \n    }\r\n\r\n    S prod(int l, int r) const {\r\n        assert(0 <= l && l\
    \ <= r && r <= n);\r\n        S sml = e(), smr = e();\r\n        l += sz;\r\n\
    \        r += sz;\r\n        while (l < r) {\r\n            if (l & 1) sml = op(sml,\
    \ data[l++]);\r\n            if (r & 1) smr = op(data[--r], smr);\r\n        \
    \    l >>= 1;\r\n            r >>= 1;\r\n        }\r\n        return op(sml, smr);\r\
    \n    }\r\n\r\n    S all_prod() const {\r\n        return data[1];\r\n    }\r\n\
    \r\n    template <class F> int max_right(int l, F f) const {\r\n        assert(0\
    \ <= l && l < n);\r\n        assert(f(e()));\r\n        if (l == n) return n;\r\
    \n        l += sz;\r\n        S sm = e();\r\n        do {\r\n            while\
    \ (l % 2 == 0) l >>= 1;\r\n            if (!f(op(sm, data[l]))) {\r\n        \
    \        while (l < sz) {\r\n                    l = 2 * l;\r\n              \
    \      if (f(op(sm, data[l]))) {\r\n                        sm = op(sm, data[l]);\r\
    \n                        l++;\r\n                    }\r\n                }\r\
    \n                return l - sz;\r\n            }\r\n            sm = op(sm, data[l]);\r\
    \n            l++;\r\n        } while ((l & -l) != l);\r\n        return n;\r\n\
    \    }\r\n\r\n    template <class F> int min_left(int r, F f) const {\r\n    \
    \    assert(0 <= r && r <= n);\r\n        assert(f(e()));\r\n        if (r ==\
    \ 0) return 0;\r\n        r += sz;\r\n        S sm = e();\r\n        do {\r\n\
    \            r--;\r\n            while (r > 1 && (r % 2)) r >>= 1;\r\n       \
    \     if (!f(op(data[r], sm))) {\r\n                while (r < sz) {\r\n     \
    \               r = 2 * r + 1;\r\n                    if (f(op(data[r], sm)))\
    \ {\r\n                        sm = op(data[r], sm);\r\n                     \
    \   r--;\r\n                    }\r\n                }\r\n                return\
    \ r + 1 - sz;\r\n            }\r\n            sm = op(data[r], sm);\r\n      \
    \  } while ((r & -r) != r);\r\n        return 0;\r\n    }\r\n\r\n    S operator[](int\
    \ p) const {\r\n        return data[sz + p];\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\r\n#line 2 \"tree/heavy_light_decomposition.hpp\"\n\n#include <algorithm>\n\
    #line 6 \"tree/heavy_light_decomposition.hpp\"\n\nnamespace ebi {\n\nstruct heavy_light_decomposition\
    \ {\n  private:\n    void dfs_sz(int v) {\n        for (auto &nv : g[v]) {\n \
    \           if (nv == par[v]) continue;\n            par[nv] = v;\n          \
    \  depth[nv] = depth[v] + 1;\n            dfs_sz(nv);\n            sz[v] += sz[nv];\n\
    \            if (sz[nv] > sz[g[v][0]] || g[v][0] == par[v])\n                std::swap(nv,\
    \ g[v][0]);\n        }\n    }\n\n    void dfs_hld(int v) {\n        in[v] = t++;\n\
    \        rev[in[v]] = v;\n        for (auto nv : g[v]) {\n            if (nv ==\
    \ par[v]) continue;\n            nxt[nv] = (nv == g[v][0] ? nxt[v] : nv);\n  \
    \          dfs_hld(nv);\n        }\n        out[v] = t;\n    }\n\n    // [u, v)\
    \ \u30D1\u30B9\u306E\u53D6\u5F97 (v \u306F u \u306E\u7956\u5148)\n    std::vector<std::pair<int,\
    \ int>> ascend(int u, int v) const {\n        std::vector<std::pair<int, int>>\
    \ res;\n        while (nxt[u] != nxt[v]) {\n            res.emplace_back(in[u],\
    \ in[nxt[u]]);\n            u = par[nxt[u]];\n        }\n        if (u != v) res.emplace_back(in[u],\
    \ in[v] + 1);\n        return res;\n    }\n\n    // (u, v] \u30D1\u30B9\u306E\u53D6\
    \u5F97 (u \u306F v \u306E\u7956\u5148)\n    std::vector<std::pair<int, int>> descend(int\
    \ u, int v) const {\n        if (u == v) return {};\n        if (nxt[u] == nxt[v])\
    \ return {{in[u] + 1, in[v]}};\n        auto res = descend(u, par[nxt[v]]);\n\
    \        res.emplace_back(in[nxt[v]], in[v]);\n        return res;\n    }\n\n\
    \  public:\n    heavy_light_decomposition(const std::vector<std::vector<int>>\
    \ &gh,\n                              int root = 0)\n        : n(gh.size()),\n\
    \          g(gh),\n          sz(n, 1),\n          in(n),\n          out(n),\n\
    \          nxt(n),\n          par(n, -1),\n          depth(n, 0),\n          rev(n)\
    \ {\n        nxt[root] = root;\n        dfs_sz(root);\n        dfs_hld(root);\n\
    \    }\n\n    int idx(int u) const {\n        return in[u];\n    }\n\n    int\
    \ rev_idx(int i) const {\n        return rev[i];\n    }\n\n    int la(int v, int\
    \ k) const {\n        while (1) {\n            int u = nxt[v];\n            if\
    \ (in[u] <= in[v] - k) return rev[in[v] - k];\n            k -= in[v] - in[u]\
    \ + 1;\n            v = par[u];\n        }\n    }\n\n    int lca(int u, int v)\
    \ const {\n        while (nxt[u] != nxt[v]) {\n            if (in[u] < in[v])\
    \ std::swap(u, v);\n            u = par[nxt[u]];\n        }\n        return depth[u]\
    \ < depth[v] ? u : v;\n    }\n\n    int jump(int s, int t, int i) const {\n  \
    \      if (i == 0) return s;\n        int l = lca(s, t);\n        int d = depth[s]\
    \ + depth[t] - depth[l] * 2;\n        if (d < i) return -1;\n        if (depth[s]\
    \ - depth[l] >= i) return la(s, i);\n        i = d - i;\n        return la(t,\
    \ i);\n    }\n\n    std::vector<int> path(int s, int t) const {\n        int l\
    \ = lca(s, t);\n        std::vector<int> a, b;\n        for (; s != l; s = par[s])\
    \ a.emplace_back(s);\n        for (; t != l; t = par[t]) b.emplace_back(t);\n\
    \        a.emplace_back(l);\n        std::reverse(b.begin(), b.end());\n     \
    \   a.insert(a.end(), b.begin(), b.end());\n        return a;\n    }\n\n    int\
    \ parent(int u) const {\n        return par[u];\n    }\n\n    int distance(int\
    \ u, int v) const {\n        return depth[u] + depth[v] - 2 * depth[lca(u, v)];\n\
    \    }\n\n    int distance_from_root(int v) const {\n        return depth[v];\n\
    \    }\n\n    bool at_path(int u, int v, int s) const {\n        return distance(u,\
    \ v) == distance(u, s) + distance(s, v);\n    }\n\n    template <class F>\n  \
    \  void path_noncommutative_query(int u, int v, bool vertex,\n               \
    \                    const F &f) const {\n        int l = lca(u, v);\n       \
    \ for (auto [a, b] : ascend(u, l)) f(a + 1, b);\n        if (vertex) f(in[l],\
    \ in[l] + 1);\n        for (auto [a, b] : descend(l, v)) f(a, b + 1);\n    }\n\
    \n    std::vector<std::pair<int, int>> path_sections(int u, int v,\n         \
    \                                          bool vertex) const {\n        int l\
    \ = lca(u, v);\n        std::vector<std::pair<int, int>> sections;\n        for\
    \ (auto [a, b] : ascend(u, l)) sections.emplace_back(a + 1, b);\n        if (vertex)\
    \ sections.emplace_back(in[l], in[l] + 1);\n        for (auto [a, b] : descend(l,\
    \ v)) sections.emplace_back(a, b + 1);\n        return sections;\n    }\n\n  \
    \  template <class F>\n    int max_path(int u, int v, bool vertex, F binary_search)\
    \ const {\n        int prev = -1;\n        int l = lca(u, v);\n        for (auto\
    \ [a, b] : ascend(u, l)) {\n            a++;\n            int m = binary_search(a,\
    \ b);\n            if (m == b) {\n                prev = rev[b];\n           \
    \ } else {\n                return (m == a ? prev : rev[m]);\n            }\n\
    \        }\n        if (vertex) {\n            int m = binary_search(in[l], in[l]\
    \ + 1);\n            if (m == in[l]) {\n                return prev;\n       \
    \     } else {\n                prev = l;\n            }\n        }\n        for\
    \ (auto [a, b] : descend(l, v)) {\n            b++;\n            int m = binary_search(a,\
    \ b);\n            if (m == b) {\n                prev = rev[b - 1];\n       \
    \     } else {\n                return m == a ? prev : rev[m - 1];\n         \
    \   }\n        }\n        return v;\n    }\n\n    template <class F> void subtree_query(int\
    \ u, bool vertex, const F &f) {\n        f(in[u] + int(!vertex), out[u]);\n  \
    \  }\n\n    const std::vector<int> &dfs_order() const {\n        return rev;\n\
    \    }\n\n  private:\n    int n;\n    std::vector<std::vector<int>> g;\n    std::vector<int>\
    \ sz, in, out, nxt, par, depth, rev;\n\n    int t = 0;\n};\n\n}  // namespace\
    \ ebi\n#line 2 \"utility/modint.hpp\"\n\r\n#line 5 \"utility/modint.hpp\"\n#include\
    \ <type_traits>\r\n\r\n#line 2 \"utility/modint_base.hpp\"\n\n#line 4 \"utility/modint_base.hpp\"\
    \n\nnamespace ebi {\n\nnamespace internal {\n\nstruct modint_base {};\n\ntemplate\
    \ <class T> using is_modint = std::is_base_of<modint_base, T>;\ntemplate <class\
    \ T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\nstruct static_modint_base\
    \ : modint_base {};\n\ntemplate <class T>\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\ntemplate <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace ebi\n#line 8 \"utility/modint.hpp\"\
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
    \ static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 9 \"test/data_structure/Vertex_Set_Path_Compositie.test.cpp\"\
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
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../data_structure/segtree.hpp\"\
    \n#include \"../../tree/heavy_light_decomposition.hpp\"\n#include \"../../utility/modint.hpp\"\
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
  - utility/modint_base.hpp
  isVerificationFile: true
  path: test/data_structure/Vertex_Set_Path_Compositie.test.cpp
  requiredBy: []
  timestamp: '2023-10-24 00:42:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Vertex_Set_Path_Compositie.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Vertex_Set_Path_Compositie.test.cpp
- /verify/test/data_structure/Vertex_Set_Path_Compositie.test.cpp.html
title: test/data_structure/Vertex_Set_Path_Compositie.test.cpp
---
