---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/rerooting.hpp
    title: rerooting
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
    PROBLEM: https://judge.yosupo.jp/problem/tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/tree_path_composite_sum
  bundledCode: "#line 1 \"test/Tree_Path_Composite_Sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\n\n#line 2 \"tree/rerooting.hpp\"\
    \n\n#include <vector>\n#include <utility>\n#include <cassert>\n\nnamespace ebi\
    \ {\n\ntemplate <class V, class E, E (*e)(), E (*merge)(E, E), E (*put_edge)(int,\
    \ V),\n          V (*put_root)(int, E)>\nstruct rerooting {\n  private:\n    V\
    \ dfs_sub(int v, int par = -1) {\n        E ret = e();\n        for (auto &edge\
    \ : g[v]) {\n            if (edge.first == par && g[v].back().first != par)\n\
    \                std::swap(g[v].back(), edge);\n            auto [nv, index] =\
    \ edge;\n            if (nv == par) continue;\n            E val = put_edge(index,\
    \ dfs_sub(nv, v));\n            outs[v].emplace_back(val);\n            ret =\
    \ merge(ret, val);\n        }\n        sub[v] = put_root(v, ret);\n        return\
    \ sub[v];\n    }\n\n    void dfs_all(int v, int par = -1, E rev = e()) {\n   \
    \     int sz = outs[v].size();\n        std::vector<E> lcum(sz + 1, e()), rcum(sz\
    \ + 1, e());\n        for (int i = 0; i < sz; i++) {\n            lcum[i + 1]\
    \ = merge(lcum[i], outs[v][i]);\n            rcum[sz - i - 1] = merge(rcum[sz\
    \ - i], outs[v][sz - i - 1]);\n        }\n        for (int i = 0; i < sz; i++)\
    \ {\n            auto [nv, index] = g[v][i];\n            E ret = put_edge(\n\
    \                index, put_root(v, merge(merge(lcum[i], rcum[i + 1]), rev)));\n\
    \            dfs_all(nv, v, ret);\n        }\n        dp[v] = put_root(v, merge(lcum[sz],\
    \ rev));\n    }\n\n  public:\n    rerooting(int n, const std::vector<std::pair<int,\
    \ int>> &edges)\n        : n(n), g(n), sub(n), dp(n), outs(n) {\n        for (int\
    \ i = 0; i < (int)edges.size(); i++) {\n            auto [u, v] = edges[i];\n\
    \            g[u].emplace_back(v, i);\n            if ((int)edges.size() == n\
    \ - 1) g[v].emplace_back(u, i);\n        }\n        assert((int)edges.size() ==\
    \ n - 1 || (int)edges.size() == 2 * (n - 1));\n\n        dfs_sub(0);\n       \
    \ dfs_all(0);\n    }\n\n    V get(int v) const {\n        return dp[v];\n    }\n\
    \n  private:\n    int n;\n    std::vector<std::vector<std::pair<int, int>>> g;\n\
    \    std::vector<V> sub;\n    std::vector<V> dp;\n    std::vector<std::vector<E>>\
    \ outs;\n};\n\n}  // namespace ebi\n#line 2 \"utility/modint.hpp\"\n\r\n/*\r\n\
    \    author: noshi91\r\n    reference: https://noshi91.hatenablog.com/entry/2019/03/31/174006\r\
    \n    noshi91\u306E\u30D6\u30ED\u30B0\u3067\u516C\u958B\u3055\u308C\u3066\u3044\
    \u308Bmodint\u3092\u5143\u306Binv(), pow()\u3092\u8FFD\u52A0\u3057\u305F\u3082\
    \u306E\u3067\u3059\r\n*/\r\n\r\n#include <cstdint>\r\n#include <iostream>\r\n\r\
    \nnamespace ebi {\r\n\r\ntemplate <std::uint_fast64_t Modulus> class modint {\r\
    \n    using u64 = std::uint_fast64_t;\r\n\r\n  public:\r\n    u64 a;\r\n\r\n \
    \   constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}\r\n    constexpr\
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
    \n}\r\n\r\n}  // namespace ebi\n#line 5 \"test/Tree_Path_Composite_Sum.test.cpp\"\
    \n\n#line 8 \"test/Tree_Path_Composite_Sum.test.cpp\"\n\nusing mint = ebi::modint998244353;\n\
    \nstd::vector<mint> a, b, c;\n\nstruct S {\n    mint sum;\n    mint sz;\n};\n\n\
    S e() {\n    return {0, 0};\n}\n\nS merge(S lhs, S rhs) {\n    return {lhs.sum\
    \ + rhs.sum, lhs.sz + rhs.sz};\n}\n\nS put_edge(int idx, S x) {\n    return {b[idx]\
    \ * x.sum + c[idx] * x.sz, x.sz};\n}\n\nS put_root(int idx, S x) {\n    return\
    \ {a[idx] + x.sum, x.sz + 1};\n}\n\nint main() {\n    int n;\n    std::cin >>\
    \ n;\n    for (int i = 0; i < n; i++) {\n        int val;\n        std::cin >>\
    \ val;\n        a.emplace_back(val);\n    }\n    std::vector<std::pair<int, int>>\
    \ edges;\n    for (int i = 0; i < n - 1; i++) {\n        int u, v, x, y;\n   \
    \     std::cin >> u >> v >> x >> y;\n        edges.emplace_back(u, v);\n     \
    \   b.emplace_back(x);\n        c.emplace_back(y);\n    }\n    ebi::rerooting<S,\
    \ S, e, merge, put_edge, put_root> dp(n, edges);\n    for (int i = 0; i < n; i++)\
    \ {\n        std::cout << dp.get(i).sum.val() << \" \\n\"[i == n - 1];\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n\n#include \"../tree/rerooting.hpp\"\n#include \"../utility/modint.hpp\"\n\n\
    #include <vector>\n#include <iostream>\n\nusing mint = ebi::modint998244353;\n\
    \nstd::vector<mint> a, b, c;\n\nstruct S {\n    mint sum;\n    mint sz;\n};\n\n\
    S e() {\n    return {0, 0};\n}\n\nS merge(S lhs, S rhs) {\n    return {lhs.sum\
    \ + rhs.sum, lhs.sz + rhs.sz};\n}\n\nS put_edge(int idx, S x) {\n    return {b[idx]\
    \ * x.sum + c[idx] * x.sz, x.sz};\n}\n\nS put_root(int idx, S x) {\n    return\
    \ {a[idx] + x.sum, x.sz + 1};\n}\n\nint main() {\n    int n;\n    std::cin >>\
    \ n;\n    for (int i = 0; i < n; i++) {\n        int val;\n        std::cin >>\
    \ val;\n        a.emplace_back(val);\n    }\n    std::vector<std::pair<int, int>>\
    \ edges;\n    for (int i = 0; i < n - 1; i++) {\n        int u, v, x, y;\n   \
    \     std::cin >> u >> v >> x >> y;\n        edges.emplace_back(u, v);\n     \
    \   b.emplace_back(x);\n        c.emplace_back(y);\n    }\n    ebi::rerooting<S,\
    \ S, e, merge, put_edge, put_root> dp(n, edges);\n    for (int i = 0; i < n; i++)\
    \ {\n        std::cout << dp.get(i).sum.val() << \" \\n\"[i == n - 1];\n    }\n\
    }"
  dependsOn:
  - tree/rerooting.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/Tree_Path_Composite_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-05-11 19:12:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Tree_Path_Composite_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/Tree_Path_Composite_Sum.test.cpp
- /verify/test/Tree_Path_Composite_Sum.test.cpp.html
title: test/Tree_Path_Composite_Sum.test.cpp
---
