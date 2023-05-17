---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: tree/rerooting.hpp
    title: rerooting
  - icon: ':question:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \ outs;\n};\n\n}  // namespace ebi\n#line 2 \"utility/modint.hpp\"\n\r\n#line\
    \ 4 \"utility/modint.hpp\"\n#include <iostream>\r\n#include <type_traits>\r\n\r\
    \nnamespace ebi {\r\n\r\nnamespace internal {\r\n\r\nstruct modint_base {};\r\n\
    struct static_modint_base : modint_base {};\r\n\r\ntemplate <class T> using is_modint\
    \ = std::is_base_of<modint_base, T>;\r\ntemplate <class T> using is_modint_t =\
    \ std::enable_if_t<is_modint<T>::value>;\r\n\r\n}  // namespace internal\r\n\r\
    \ntemplate <int m> struct static_modint : internal::static_modint_base {\r\n \
    \ private:\r\n    using modint = static_modint;\r\n\r\n  public:\r\n    static\
    \ constexpr int mod() {\r\n        return m;\r\n    }\r\n\r\n    static modint\
    \ raw(int v) {\r\n        modint x;\r\n        x._v = v;\r\n        return x;\r\
    \n    }\r\n\r\n    static_modint() : _v(0) {}\r\n\r\n    static_modint(long long\
    \ v) {\r\n        v %= (long long)umod();\r\n        if (v < 0) v += (long long)umod();\r\
    \n        _v = (unsigned int)v;\r\n    }\r\n\r\n    unsigned int val() const {\r\
    \n        return _v;\r\n    }\r\n\r\n    unsigned int value() const {\r\n    \
    \    return val();\r\n    }\r\n\r\n    modint &operator++() {\r\n        _v++;\r\
    \n        if (_v == umod()) _v = 0;\r\n        return *this;\r\n    }\r\n    modint\
    \ &operator--() {\r\n        if (_v == 0) _v = umod();\r\n        _v--;\r\n  \
    \      return *this;\r\n    }\r\n    modint &operator+=(const modint &rhs) {\r\
    \n        _v += rhs._v;\r\n        if (_v >= umod()) _v -= umod();\r\n       \
    \ return *this;\r\n    }\r\n    modint &operator-=(const modint &rhs) {\r\n  \
    \      _v -= rhs._v;\r\n        if (_v >= umod()) _v += umod();\r\n        return\
    \ *this;\r\n    }\r\n    modint &operator*=(const modint &rhs) {\r\n        unsigned\
    \ long long x = _v;\r\n        x *= rhs._v;\r\n        _v = (unsigned int)(x %\
    \ (unsigned long long)umod());\r\n        return *this;\r\n    }\r\n    modint\
    \ &operator/=(const modint &rhs) {\r\n        return *this = *this * rhs.inv();\r\
    \n    }\r\n\r\n    modint operator+() const {\r\n        return *this;\r\n   \
    \ }\r\n    modint operator-() const {\r\n        return modint() - *this;\r\n\
    \    }\r\n\r\n    modint pow(long long n) const {\r\n        assert(0 <= n);\r\
    \n        modint x = *this, res = 1;\r\n        while (n) {\r\n            if\
    \ (n & 1) res *= x;\r\n            x *= x;\r\n            n >>= 1;\r\n       \
    \ }\r\n        return res;\r\n    }\r\n    modint inv() const {\r\n        assert(_v);\r\
    \n        return pow(umod() - 2);\r\n    }\r\n\r\n    friend modint operator+(const\
    \ modint &lhs, const modint &rhs) {\r\n        return modint(lhs) += rhs;\r\n\
    \    }\r\n    friend modint operator-(const modint &lhs, const modint &rhs) {\r\
    \n        return modint(lhs) -= rhs;\r\n    }\r\n    friend modint operator*(const\
    \ modint &lhs, const modint &rhs) {\r\n        return modint(lhs) *= rhs;\r\n\
    \    }\r\n\r\n    friend modint operator/(const modint &lhs, const modint &rhs)\
    \ {\r\n        return modint(lhs) /= rhs;\r\n    }\r\n    friend bool operator==(const\
    \ modint &lhs, const modint &rhs) {\r\n        return lhs.val() == rhs.val();\r\
    \n    }\r\n    friend bool operator!=(const modint &lhs, const modint &rhs) {\r\
    \n        return !(lhs == rhs);\r\n    }\r\n\r\n  private:\r\n    unsigned int\
    \ _v;\r\n\r\n    static constexpr unsigned int umod() {\r\n        return m;\r\
    \n    }\r\n};\r\n\r\ntemplate <int m>\r\nstd::istream &operator>>(std::istream\
    \ &os, static_modint<m> &a) {\r\n    long long x;\r\n    os >> x;\r\n    a = x;\r\
    \n    return os;\r\n}\r\ntemplate <int m>\r\nstd::ostream &operator<<(std::ostream\
    \ &os, const static_modint<m> &a) {\r\n    return os << a.val();\r\n}\r\n\r\n\
    using modint998244353 = static_modint<998244353>;\r\nusing modint1000000007 =\
    \ static_modint<1000000007>;\r\n\r\nnamespace internal {\r\n\r\ntemplate <class\
    \ T>\r\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\r\n\r\ntemplate <class T>\r\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\r\
    \n\r\n}  // namespace internal\r\n\r\n}  // namespace ebi\n#line 5 \"test/Tree_Path_Composite_Sum.test.cpp\"\
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
  timestamp: '2023-05-17 13:24:36+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/Tree_Path_Composite_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/Tree_Path_Composite_Sum.test.cpp
- /verify/test/Tree_Path_Composite_Sum.test.cpp.html
title: test/Tree_Path_Composite_Sum.test.cpp
---
