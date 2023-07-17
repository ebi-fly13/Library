---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/LazySegtree.hpp
    title: data_structure/LazySegtree.hpp
  - icon: ':question:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  - icon: ':question:'
    path: utility/modint_base.hpp
    title: utility/modint_base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/data_structure/Range_Affine_Range_Sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\r\n\
    \r\n#include <iostream>\r\n#include <vector>\r\n\r\n#line 2 \"data_structure/LazySegtree.hpp\"\
    \n\r\n/*\r\n    reference: https://beet-aizu.hatenablog.com/entry/2017/12/01/225955\r\
    \n               https://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html\r\
    \n*/\r\n\r\n#include <cassert>\r\n#line 10 \"data_structure/LazySegtree.hpp\"\n\
    \r\nnamespace ebi {\r\n\r\ntemplate <class S, S (*op)(S, S), S (*e)(), class F,\
    \ S (*mapping)(F, S),\r\n          F (*merge)(F, F), F (*id)()>\r\nstruct LazySegtree\
    \ {\r\n  private:\r\n    std::vector<S> data;\r\n    std::vector<F> lazy;\r\n\
    \    int n;\r\n\r\n    void eval(int index, int l, int r) {\r\n        data[index]\
    \ = mapping(lazy[index], data[index]);\r\n        if (r - l > 1) {\r\n       \
    \     lazy[2 * index + 1] = merge(lazy[index], lazy[2 * index + 1]);\r\n     \
    \       lazy[2 * index + 2] = merge(lazy[index], lazy[2 * index + 2]);\r\n   \
    \     }\r\n        lazy[index] = id();\r\n    }\r\n\r\n    S _prod(int l, int\
    \ r, int nl = 0, int nr = -1, int index = 0) {\r\n        if (nr < 0) nr = n;\r\
    \n        if (nr <= l || r <= nl) {\r\n            return e();\r\n        }\r\n\
    \        eval(index, nl, nr);\r\n        if (l <= nl && nr <= r) {\r\n       \
    \     return data[index];\r\n        }\r\n        return op(_prod(l, r, nl, (nl\
    \ + nr) / 2, 2 * index + 1),\r\n                  _prod(l, r, (nl + nr) / 2, nr,\
    \ 2 * index + 2));\r\n    }\r\n\r\n    void _apply(int l, int r, F f, int nl =\
    \ 0, int nr = -1, int index = 0) {\r\n        if (nr < 0) nr = n;\r\n        eval(index,\
    \ nl, nr);\r\n        if (nr <= l || r <= nl) return;\r\n        if (l <= nl &&\
    \ nr <= r) {\r\n            lazy[index] = merge(f, lazy[index]);\r\n         \
    \   eval(index, nl, nr);\r\n            return;\r\n        }\r\n        _apply(l,\
    \ r, f, nl, (nl + nr) / 2, 2 * index + 1);\r\n        _apply(l, r, f, (nl + nr)\
    \ / 2, nr, 2 * index + 2);\r\n        data[index] = op(data[2 * index + 1], data[2\
    \ * index + 2]);\r\n        return;\r\n    }\r\n\r\n  public:\r\n    LazySegtree(int\
    \ _n) : n(1) {\r\n        while (n < _n) {\r\n            n <<= 1;\r\n       \
    \ }\r\n        data.assign(2 * n - 1, e());\r\n        lazy.assign(2 * n - 1,\
    \ id());\r\n    }\r\n\r\n    LazySegtree(std::vector<S> v) : n(1) {\r\n      \
    \  int _n = v.size();\r\n        while (n < _n) {\r\n            n <<= 1;\r\n\
    \        }\r\n        data.assign(2 * n - 1, e());\r\n        lazy.assign(2 *\
    \ n - 1, id());\r\n        for (int i = 0; i < _n; i++) {\r\n            data[i\
    \ + n - 1] = v[i];\r\n        }\r\n        for (int i = n - 2; i >= 0; i--) {\r\
    \n            data[i] = op(data[2 * i + 1], data[2 * i + 2]);\r\n        }\r\n\
    \    }\r\n\r\n    S prod(int l, int r) {\r\n        return _prod(l, r);\r\n  \
    \  }\r\n\r\n    S all_prod() {\r\n        eval(0, 0, n);\r\n        return data[0];\r\
    \n    }\r\n\r\n    void apply(int l, int r, F f) {\r\n        _apply(l, r, f);\r\
    \n    }\r\n\r\n    S get(int i) {\r\n        int l = 0, r = n;\r\n        int\
    \ k = 0;\r\n        while (r - l > 1) {\r\n            eval(k, l, r);\r\n    \
    \        int mid = (l + r) / 2;\r\n            if (i < mid) {\r\n            \
    \    k = 2 * k + 1;\r\n                r = mid;\r\n            } else {\r\n  \
    \              k = 2 * k + 2;\r\n                l = mid;\r\n            }\r\n\
    \        }\r\n        eval(k, l, r);\r\n        return data[k];\r\n    }\r\n};\r\
    \n\r\n}  // namespace ebi\n#line 2 \"utility/modint.hpp\"\n\r\n#line 5 \"utility/modint.hpp\"\
    \n#include <type_traits>\r\n\r\n#line 2 \"utility/modint_base.hpp\"\n\n#line 4\
    \ \"utility/modint_base.hpp\"\n\nnamespace ebi {\n\nnamespace internal {\n\nstruct\
    \ modint_base {};\n\ntemplate <class T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \nstruct static_modint_base : modint_base {};\n\ntemplate <class T>\nusing is_static_modint\
    \ = std::is_base_of<internal::static_modint_base, T>;\n\ntemplate <class T>\n\
    using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\n}\
    \  // namespace internal\n\n}  // namespace ebi\n#line 8 \"utility/modint.hpp\"\
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
    \n        return *this;\r\n    }\r\n    constexpr modint &operator+=(const modint\
    \ &rhs) {\r\n        _v += rhs._v;\r\n        if (_v >= umod()) _v -= umod();\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator-=(const modint\
    \ &rhs) {\r\n        _v -= rhs._v;\r\n        if (_v >= umod()) _v += umod();\r\
    \n        return *this;\r\n    }\r\n    constexpr modint &operator*=(const modint\
    \ &rhs) {\r\n        unsigned long long x = _v;\r\n        x *= rhs._v;\r\n  \
    \      _v = (unsigned int)(x % (unsigned long long)umod());\r\n        return\
    \ *this;\r\n    }\r\n    constexpr modint &operator/=(const modint &rhs) {\r\n\
    \        return *this = *this * rhs.inv();\r\n    }\r\n\r\n    constexpr modint\
    \ operator+() const {\r\n        return *this;\r\n    }\r\n    constexpr modint\
    \ operator-() const {\r\n        return modint() - *this;\r\n    }\r\n\r\n   \
    \ constexpr modint pow(long long n) const {\r\n        assert(0 <= n);\r\n   \
    \     modint x = *this, res = 1;\r\n        while (n) {\r\n            if (n &\
    \ 1) res *= x;\r\n            x *= x;\r\n            n >>= 1;\r\n        }\r\n\
    \        return res;\r\n    }\r\n    constexpr modint inv() const {\r\n      \
    \  assert(_v);\r\n        return pow(umod() - 2);\r\n    }\r\n\r\n    friend modint\
    \ operator+(const modint &lhs, const modint &rhs) {\r\n        return modint(lhs)\
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
    \ static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 8 \"test/data_structure/Range_Affine_Range_Sum.test.cpp\"\
    \n\r\nusing mint = ebi::modint998244353;\r\n\r\nstruct S {\r\n    mint a;\r\n\
    \    int size;\r\n};\r\n\r\nstruct F {\r\n    mint a, b;\r\n    F(mint a, mint\
    \ b) : a(a), b(b) {}\r\n};\r\n\r\nS op(S l, S r) {\r\n    return S{l.a + r.a,\
    \ l.size + r.size};\r\n}\r\n\r\nS e() {\r\n    return S{0, 0};\r\n}\r\n\r\nS mapping(F\
    \ l, S r) {\r\n    return S{r.a * l.a + (mint)r.size * l.b, r.size};\r\n}\r\n\r\
    \nF merge(F l, F r) {\r\n    return F{r.a * l.a, r.b * l.a + l.b};\r\n}\r\n\r\n\
    F id() {\r\n    return F{1, 0};\r\n}\r\n\r\nint main() {\r\n    int n, q;\r\n\
    \    std::cin >> n >> q;\r\n    std::vector<S> v(n);\r\n    for (int i = 0; i\
    \ < n; i++) {\r\n        int a;\r\n        std::cin >> a;\r\n        v[i] = {a,\
    \ 1};\r\n    }\r\n    ebi::LazySegtree<S, op, e, F, mapping, merge, id> seg(v);\r\
    \n    while (q--) {\r\n        int t;\r\n        std::cin >> t;\r\n        if\
    \ (t == 0) {\r\n            int l, r, b, c;\r\n            std::cin >> l >> r\
    \ >> b >> c;\r\n            seg.apply(l, r, F(b, c));\r\n        } else {\r\n\
    \            int l, r;\r\n            std::cin >> l >> r;\r\n            std::cout\
    \ << seg.prod(l, r).a.value() << std::endl;\r\n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"../../data_structure/LazySegtree.hpp\"\
    \r\n#include \"../../utility/modint.hpp\"\r\n\r\nusing mint = ebi::modint998244353;\r\
    \n\r\nstruct S {\r\n    mint a;\r\n    int size;\r\n};\r\n\r\nstruct F {\r\n \
    \   mint a, b;\r\n    F(mint a, mint b) : a(a), b(b) {}\r\n};\r\n\r\nS op(S l,\
    \ S r) {\r\n    return S{l.a + r.a, l.size + r.size};\r\n}\r\n\r\nS e() {\r\n\
    \    return S{0, 0};\r\n}\r\n\r\nS mapping(F l, S r) {\r\n    return S{r.a * l.a\
    \ + (mint)r.size * l.b, r.size};\r\n}\r\n\r\nF merge(F l, F r) {\r\n    return\
    \ F{r.a * l.a, r.b * l.a + l.b};\r\n}\r\n\r\nF id() {\r\n    return F{1, 0};\r\
    \n}\r\n\r\nint main() {\r\n    int n, q;\r\n    std::cin >> n >> q;\r\n    std::vector<S>\
    \ v(n);\r\n    for (int i = 0; i < n; i++) {\r\n        int a;\r\n        std::cin\
    \ >> a;\r\n        v[i] = {a, 1};\r\n    }\r\n    ebi::LazySegtree<S, op, e, F,\
    \ mapping, merge, id> seg(v);\r\n    while (q--) {\r\n        int t;\r\n     \
    \   std::cin >> t;\r\n        if (t == 0) {\r\n            int l, r, b, c;\r\n\
    \            std::cin >> l >> r >> b >> c;\r\n            seg.apply(l, r, F(b,\
    \ c));\r\n        } else {\r\n            int l, r;\r\n            std::cin >>\
    \ l >> r;\r\n            std::cout << seg.prod(l, r).a.value() << std::endl;\r\
    \n        }\r\n    }\r\n}"
  dependsOn:
  - data_structure/LazySegtree.hpp
  - utility/modint.hpp
  - utility/modint_base.hpp
  isVerificationFile: true
  path: test/data_structure/Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-07-17 14:12:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data_structure/Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Range_Affine_Range_Sum.test.cpp
- /verify/test/data_structure/Range_Affine_Range_Sum.test.cpp.html
title: test/data_structure/Range_Affine_Range_Sum.test.cpp
---
