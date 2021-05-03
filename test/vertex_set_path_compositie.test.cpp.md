---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/Segtree.hpp
    title: Segtree
  - icon: ':heavy_check_mark:'
    path: data_structure/heavy_light_decomposition.hpp
    title: data_structure/heavy_light_decomposition.hpp
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
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
    \ \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\n\n#line 2 \"\
    data_structure/heavy_light_decomposition.hpp\"\n\n#line 2 \"data_structure/Segtree.hpp\"\
    \n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class Monoid, Monoid\
    \ (*op)(Monoid, Monoid), Monoid (*e)()>\r\nstruct Segtree {\r\nprivate:\r\n  \
    \  std::vector<Monoid> data;\r\n    int n;\r\npublic:\r\n    Segtree(int _n) :\
    \ n(1) {\r\n        while(n<_n){\r\n            n <<= 1;\r\n        }\r\n    \
    \    data.assign(2*n-1, e());\r\n    }\r\n\r\n    Segtree(std::vector<Monoid>\
    \ v) : n(1) {\r\n        int _n = v.size();\r\n        while(n<_n){\r\n      \
    \      n <<= 1;\r\n        }\r\n        data.assign(2*n-1, e());\r\n        for(int\
    \ i = 0; i<_n; i++){\r\n            data[n+i-1] = v[i];\r\n        }\r\n     \
    \   for(int i = n-2; i>=0; i--){\r\n            data[i] = op(data[2*i+1], data[2*i+2]);\r\
    \n        }\r\n    }\r\n\r\n    void set(int p, Monoid x){\r\n        int k =\
    \ n+p-1;\r\n        data[k] = x;\r\n        while(k>0){\r\n            k = (k-1)/2;\r\
    \n            data[k] = op(data[2*k+1], data[2*k+2]);\r\n        }\r\n    }\r\n\
    \r\n    Monoid prod(int tl, int tr, int l=0, int r=-1, int index=0){\r\n     \
    \   if(r<0) r = n;\r\n        if(tr<=l || r<=tl){\r\n            return e();\r\
    \n        }\r\n        if(tl<=l && r<=tr){\r\n            return data[index];\r\
    \n        }\r\n        return op(prod(tl, tr, l, (l+r)/2, 2*index+1), prod(tl,\
    \ tr, (l+r)/2, r, 2*index+2));\r\n    }\r\n\r\n    Monoid all_prod() { return\
    \ data[0]; }\r\n\r\n    Monoid get(int p) { return data[n+p-1]; }\r\n\r\n    Monoid\
    \ operator [] (int p) { return data[n+p-1]; }\r\n};\r\n\r\n} // namespace ebi\n\
    #line 2 \"graph/template.hpp\"\n\r\n#line 4 \"graph/template.hpp\"\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate<class T>\r\nstruct Edge {\r\n    int to;\r\n    T cost;\r\
    \n    Edge(int to, T cost=1) : to(to), cost(cost) { }\r\n};\r\n\r\ntemplate<class\
    \ T>\r\nusing Graph = std::vector<std::vector<Edge<T>>>;\r\n\r\nusing graph =\
    \ std::vector<std::vector<int>>;\r\n\r\n} // namespace ebi\n#line 5 \"data_structure/heavy_light_decomposition.hpp\"\
    \n\n#line 7 \"data_structure/heavy_light_decomposition.hpp\"\n\nnamespace ebi\
    \ {\n\ntemplate<class Monoid, Monoid (*op)(Monoid, Monoid), Monoid (*e)()>\nstruct\
    \ heavy_light_decomposition {\nprivate:\n    int n, t = 0;\n    std::vector<int>\
    \ sz, in, out, nxt, up;\n    graph g;\n    Segtree<Monoid, op, e> seg_l, seg_r;\n\
    \n    void dfs_sz(int v = 0) {\n        sz[v] = 1;\n        for(auto &u : g[v])\
    \ if(u != up[v]) {\n            up[u] = v;\n            dfs_sz(u);\n         \
    \   sz[v] += sz[u];\n            if(sz[u] > sz[g[v][0]] || g[v][0] == up[v]) std::swap(g[v][0],\
    \ u);\n        }\n    }\n\n    void dfs_hld(int v = 0) {\n        in[v] = t++;\n\
    \        for(const auto &u: g[v]) if(u != up[v]) {\n            nxt[u] = (u ==\
    \ g[v][0]) ? nxt[v] : u;\n            sz[u] = (u == g[v][0]) ? sz[v] : sz[v]+1;\n\
    \            dfs_hld(u);\n        }\n        out[v] = t;\n    }\npublic:\n   \
    \ heavy_light_decomposition(int _n) : n(_n), sz(_n, 0), in(_n, 0), out(_n, 0),\
    \ nxt(_n, 0), up(_n, -1), g(_n), seg_l(_n), seg_r(_n) { }\n\n    void add_edge(int\
    \ v, int u) {\n        g[v].emplace_back(u);\n        g[u].emplace_back(v);\n\
    \    }\n\n    void build(int root = 0) {\n        dfs_sz(root);\n        sz.assign(n,\
    \ 0);\n        dfs_hld(root);\n    }\n\n    int lca(int u, int v) {\n        while(nxt[u]\
    \ != nxt[v]) {\n            if(sz[u] > sz[v]) {\n                u = up[nxt[u]];\n\
    \            }\n            else {\n                v = up[nxt[v]];\n        \
    \    }\n        }\n        return (in[u] < in[v]) ? u : v;\n    }\n\n    void\
    \ set(const std::vector<Monoid> &a) {\n        for(int i = 0; i < n; ++i) {\n\
    \            seg_l.set(in[i], a[i]);\n            seg_r.set(n-1-in[i], a[i]);\n\
    \        }\n    }\n\n    void set(int i, Monoid x) {\n        seg_l.set(in[i],\
    \ x);\n        seg_r.set(n-1-in[i], x);\n    }\n\n    Monoid get(int i) {\n  \
    \      return seg_l.get(in[i]);\n    }\n\n    Monoid path_prod(int u, int v) {\n\
    \        Monoid sum_u = e(), sum_v = e();\n        while(nxt[u] != nxt[v]) {\n\
    \            if(sz[u] > sz[v]) {\n                sum_u = op(sum_u, seg_r.prod(n-1-in[u],\
    \ n-in[nxt[u]]));\n                u = up[nxt[u]];\n            }\n          \
    \  else {\n                sum_v = op(seg_l.prod(in[nxt[v]], in[v]+1), sum_v);\n\
    \                v = up[nxt[v]];\n            }\n        }\n        if(in[u] <\
    \ in[v]) {\n            sum_v = op(seg_l.prod(in[u], in[v]+1), sum_v);\n     \
    \   }\n        else {\n            sum_u = op(sum_u, seg_r.prod(n-1-in[u], n-in[v]));\n\
    \        }\n        return op(sum_u, sum_v);\n    }\n};\n\n}\n#line 2 \"utility/modint.hpp\"\
    \n\r\n/*\r\n    author: noshi91\r\n    reference: https://noshi91.hatenablog.com/entry/2019/03/31/174006\r\
    \n    noshi91\u306E\u30D6\u30ED\u30B0\u3067\u516C\u958B\u3055\u308C\u3066\u3044\
    \u308Bmodint\u3092\u5143\u306Binv(), pow()\u3092\u8FFD\u52A0\u3057\u305F\u3082\
    \u306E\u3067\u3059\r\n*/\r\n\r\n#include <cstdint>\r\n#include <iostream>\r\n\r\
    \nnamespace ebi {\r\n\r\ntemplate<std::uint_fast64_t Modulus>\r\nclass modint\
    \ {\r\n  using u64 = std::uint_fast64_t;\r\n\r\npublic:\r\n    u64 a;\r\n\r\n\
    \    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}\r\n    constexpr\
    \ u64 &value() noexcept { return a; }\r\n    constexpr u64 &val() noexcept { return\
    \ a; }\r\n    constexpr const u64 &value() const noexcept { return a; }\r\n  \
    \  constexpr modint operator+(const modint rhs) const noexcept {\r\n        return\
    \ modint(*this) += rhs;\r\n    }\r\n    constexpr modint operator-(const modint\
    \ rhs) const noexcept {\r\n        return modint(*this) -= rhs;\r\n    }\r\n \
    \   constexpr modint operator*(const modint rhs) const noexcept {\r\n        return\
    \ modint(*this) *= rhs;\r\n    }\r\n    constexpr modint operator/(const modint\
    \ rhs) const noexcept {\r\n        return modint(*this) /= rhs;\r\n    }\r\n \
    \   constexpr modint &operator+=(const modint rhs) noexcept {\r\n        a +=\
    \ rhs.a;\r\n        if (a >= Modulus) {\r\n            a -= Modulus;\r\n     \
    \   }\r\n        return *this;\r\n    }\r\n    constexpr modint &operator-=(const\
    \ modint rhs) noexcept {\r\n        if (a < rhs.a) {\r\n        a += Modulus;\r\
    \n        }\r\n        a -= rhs.a;\r\n        return *this;\r\n    }\r\n    constexpr\
    \ modint &operator*=(const modint rhs) noexcept {\r\n        a = a * rhs.a % Modulus;\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator/=(modint rhs)\
    \ noexcept {\r\n        u64 exp = Modulus - 2;\r\n        while (exp) {\r\n  \
    \      if (exp % 2) {\r\n            *this *= rhs;\r\n        }\r\n        rhs\
    \ *= rhs;\r\n        exp /= 2;\r\n        }\r\n        return *this;\r\n    }\r\
    \n    constexpr modint operator-() const { return modint() - *this; }\r\n    bool\
    \ operator==(const u64 rhs) {\r\n        return a == rhs;\r\n    }\r\n    bool\
    \ operator!=(const u64 rhs) {\r\n        return a != rhs;\r\n    }\r\n    constexpr\
    \ modint& operator++() {\r\n        a++;\r\n        if( a == mod() ) a = 0;\r\n\
    \        return *this;\r\n    }\r\n    constexpr modint& operator--() {\r\n  \
    \      if( a == 0 ) a = mod();\r\n        a--;\r\n        return *this;\r\n  \
    \  }\r\n\r\n    modint pow(u64 n) const noexcept {\r\n        modint res = 1;\r\
    \n        modint x = a;\r\n        while(n>0){\r\n            if(n&1) res *= x;\r\
    \n            x *= x;\r\n            n >>=1;\r\n        }\r\n        return res;\r\
    \n    }\r\n    modint inv() const {\r\n        return pow(Modulus-2);\r\n    }\r\
    \n\r\n    static u64 mod() {\r\n        return Modulus;\r\n    }\r\n};\r\n\r\n\
    using modint998244353 = modint<998244353>;\r\nusing modint1000000007 = modint<1000000007>;\r\
    \n\r\ntemplate<std::uint_fast64_t Modulus>\r\nstd::ostream& operator<<(std::ostream&\
    \ os, modint<Modulus> a){\r\n    return os << a.val();\r\n}\r\n\r\n} // namespace\
    \ ebi\n#line 5 \"test/vertex_set_path_compositie.test.cpp\"\n\n#line 8 \"test/vertex_set_path_compositie.test.cpp\"\
    \n\nusing mint = ebi::modint998244353;\n\nusing i64 = std::int64_t;\n\nstruct\
    \ F {\n    mint a,b;\n    F(mint a, mint b) : a(a), b(b) { }\n};\n\nF op(F f1,\
    \ F f2) {\n    return F(f2.a*f1.a, f2.a*f1.b+f2.b);\n}\n\nF e() {\n    return\
    \ F(1,0);\n}\n\nint main() {\n    int n,q;\n    std::cin >> n >> q;\n    std::vector<F>\
    \ f(n, F(1,0));\n    for(int i = 0; i < n; ++i) {\n        int a,b;\n        std::cin\
    \ >> a >> b;\n        f[i] = F(a,b);\n    }\n    ebi::heavy_light_decomposition<F,\
    \ op, e> hld(n);\n    for(int i = 0; i < n-1; ++i) {\n        int u,v;\n     \
    \   std::cin >> u >> v;\n        hld.add_edge(u,v);\n    }\n    hld.build();\n\
    \    hld.set(f);\n    while(q--) {\n        int flag;\n        std::cin >> flag;\n\
    \        if(flag == 0) {\n            int p;\n            int c, d;\n        \
    \    std::cin >> p >> c >> d;\n            hld.set(p, F(c,d));\n        }\n  \
    \      else {\n            int u,v;\n            i64 x;\n            std::cin\
    \ >> u >> v >> x;\n            F f_px = hld.path_prod(u, v);\n            std::cout\
    \ << (f_px.a * x + f_px.b).val() << std::endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"../data_structure/heavy_light_decomposition.hpp\"\n#include \"\
    ../utility/modint.hpp\"\n\n#include <iostream>\n#include <vector>\n\nusing mint\
    \ = ebi::modint998244353;\n\nusing i64 = std::int64_t;\n\nstruct F {\n    mint\
    \ a,b;\n    F(mint a, mint b) : a(a), b(b) { }\n};\n\nF op(F f1, F f2) {\n   \
    \ return F(f2.a*f1.a, f2.a*f1.b+f2.b);\n}\n\nF e() {\n    return F(1,0);\n}\n\n\
    int main() {\n    int n,q;\n    std::cin >> n >> q;\n    std::vector<F> f(n, F(1,0));\n\
    \    for(int i = 0; i < n; ++i) {\n        int a,b;\n        std::cin >> a >>\
    \ b;\n        f[i] = F(a,b);\n    }\n    ebi::heavy_light_decomposition<F, op,\
    \ e> hld(n);\n    for(int i = 0; i < n-1; ++i) {\n        int u,v;\n        std::cin\
    \ >> u >> v;\n        hld.add_edge(u,v);\n    }\n    hld.build();\n    hld.set(f);\n\
    \    while(q--) {\n        int flag;\n        std::cin >> flag;\n        if(flag\
    \ == 0) {\n            int p;\n            int c, d;\n            std::cin >>\
    \ p >> c >> d;\n            hld.set(p, F(c,d));\n        }\n        else {\n \
    \           int u,v;\n            i64 x;\n            std::cin >> u >> v >> x;\n\
    \            F f_px = hld.path_prod(u, v);\n            std::cout << (f_px.a *\
    \ x + f_px.b).val() << std::endl;\n        }\n    }\n}"
  dependsOn:
  - data_structure/heavy_light_decomposition.hpp
  - data_structure/Segtree.hpp
  - graph/template.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/vertex_set_path_compositie.test.cpp
  requiredBy: []
  timestamp: '2021-05-03 17:12:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/vertex_set_path_compositie.test.cpp
layout: document
redirect_from:
- /verify/test/vertex_set_path_compositie.test.cpp
- /verify/test/vertex_set_path_compositie.test.cpp.html
title: test/vertex_set_path_compositie.test.cpp
---
