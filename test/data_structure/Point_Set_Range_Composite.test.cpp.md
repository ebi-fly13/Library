---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/DynamicSegmentTree.hpp
    title: data_structure/DynamicSegmentTree.hpp
  - icon: ':question:'
    path: modint/base.hpp
    title: modint/base.hpp
  - icon: ':question:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/data_structure/Point_Set_Range_Composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \r\n\r\n#include <iostream>\r\n\r\n#line 2 \"data_structure/DynamicSegmentTree.hpp\"\
    \n\r\n#include <memory>\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class Monoid,\
    \ Monoid (*op)(Monoid, Monoid), Monoid (*e)()>\r\nstruct DynamicSegmentTree {\r\
    \n  private:\r\n    struct Node;\r\n    using node_ptr = std::shared_ptr<Node>;\r\
    \n    struct Node {\r\n        Monoid val;\r\n        node_ptr left, right, par;\r\
    \n        Node(node_ptr _par = nullptr)\r\n            : val(e()), left(nullptr),\
    \ right(nullptr), par(_par) {}\r\n    };\r\n\r\n    node_ptr root;\r\n    int\
    \ n;\r\n\r\n  public:\r\n    DynamicSegmentTree(int _n = 0) : n(1) {\r\n     \
    \   while (n < _n) {\r\n            n <<= 1;\r\n        }\r\n        root = std::make_shared<Node>();\r\
    \n    }\r\n\r\n    void set(int i, Monoid x) {\r\n        int l = 0, r = n;\r\n\
    \        node_ptr now = root;\r\n        while (r - l > 1) {\r\n            int\
    \ mid = (l + r) / 2;\r\n            if (i < mid) {\r\n                if (!now->left)\
    \ {\r\n                    now->left = std::make_shared<Node>(now);\r\n      \
    \          }\r\n                now = now->left;\r\n                r = mid;\r\
    \n            } else {\r\n                if (!now->right) {\r\n             \
    \       now->right = std::make_shared<Node>(now);\r\n                }\r\n   \
    \             now = now->right;\r\n                l = mid;\r\n            }\r\
    \n        }\r\n        now->val = x;\r\n        while (now->par) {\r\n       \
    \     now = now->par;\r\n            now->val = e();\r\n            if (now->left)\
    \ now->val = now->left->val;\r\n            if (now->right) now->val = op(now->val,\
    \ now->right->val);\r\n        }\r\n    }\r\n\r\n    Monoid prod(int tl, int tr,\
    \ int l = 0, int r = -1, node_ptr now = nullptr) {\r\n        if (!now) now =\
    \ root;\r\n        if (r < 0) r = n;\r\n        if (tr <= l || r <= tl) {\r\n\
    \            return e();\r\n        }\r\n        if (tl <= l && r <= tr) {\r\n\
    \            return now->val;\r\n        }\r\n        Monoid val = e();\r\n  \
    \      if (now->left) {\r\n            val = prod(tl, tr, l, (l + r) / 2, now->left);\r\
    \n        }\r\n        if (now->right) {\r\n            val = op(val, prod(tl,\
    \ tr, (l + r) / 2, r, now->right));\r\n        }\r\n        return val;\r\n  \
    \  }\r\n\r\n    Monoid all_prod() {\r\n        return root->val;\r\n    }\r\n\r\
    \n    Monoid get(int i) {\r\n        int l = 0;\r\n        int r = n;\r\n    \
    \    node_ptr now = root;\r\n        while (r - l > 1) {\r\n            int mid\
    \ = (l + r) / 2;\r\n            if (i < mid) {\r\n                if (!now->left)\
    \ return e();\r\n                now = now->left;\r\n                r = mid;\r\
    \n            } else {\r\n                if (!now->right) return e();\r\n   \
    \             now = now->right;\r\n                l = mid;\r\n            }\r\
    \n        }\r\n        return now->val;\r\n    }\r\n};\r\n\r\n}  // namespace\
    \ ebi\n#line 2 \"modint/modint.hpp\"\n\r\n#include <cassert>\r\n#line 5 \"modint/modint.hpp\"\
    \n\r\n#line 2 \"modint/base.hpp\"\n\n#include <concepts>\n#line 5 \"modint/base.hpp\"\
    \n\nnamespace ebi {\n\ntemplate<class T>\nconcept modint = requires (T a, T b)\
    \ {\n    a + b;\n    a - b;\n    a * b;\n    a / b;\n    a.inv();\n    a.val();\n\
    \    a.mod();\n};\n\ntemplate <modint mint>\nstd::istream &operator>>(std::istream\
    \ &os, mint &a) {\n    long long x;\n    os >> x;\n    a = x;\n    return os;\n\
    }\n\ntemplate <modint mint>\nstd::ostream &operator<<(std::ostream &os, const\
    \ mint &a) {\n    return os << a.val();\n}\n\n}  // namespace ebi\n#line 7 \"\
    modint/modint.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate <int m> struct static_modint\
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
    \ static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 7 \"test/data_structure/Point_Set_Range_Composite.test.cpp\"\
    \n\r\nusing mint = ebi::modint998244353;\r\n\r\nstruct F {\r\n    mint a, b;\r\
    \n    F(mint a, mint b) : a(a), b(b) {}\r\n};\r\n\r\nF op(F f1, F f2) {\r\n  \
    \  return F(f2.a * f1.a, f2.a * f1.b + f2.b);\r\n}\r\n\r\nF e() {\r\n    return\
    \ F(1, 0);\r\n}\r\n\r\nint main() {\r\n    int n, q;\r\n    std::cin >> n >> q;\r\
    \n    ebi::DynamicSegmentTree<F, op, e> seg(n);\r\n    for (int i = 0; i < n;\
    \ i++) {\r\n        int a, b;\r\n        std::cin >> a >> b;\r\n        seg.set(i,\
    \ F(a, b));\r\n    }\r\n    while (q--) {\r\n        int t;\r\n        std::cin\
    \ >> t;\r\n        if (t == 0) {\r\n            int p, c, d;\r\n            std::cin\
    \ >> p >> c >> d;\r\n            seg.set(p, F(c, d));\r\n        } else {\r\n\
    \            int l, r, x;\r\n            std::cin >> l >> r >> x;\r\n        \
    \    auto f = seg.prod(l, r);\r\n            std::cout << (f.a * x + f.b).value()\
    \ << std::endl;\r\n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \r\n\r\n#include <iostream>\r\n\r\n#include \"../../data_structure/DynamicSegmentTree.hpp\"\
    \r\n#include \"../../modint/modint.hpp\"\r\n\r\nusing mint = ebi::modint998244353;\r\
    \n\r\nstruct F {\r\n    mint a, b;\r\n    F(mint a, mint b) : a(a), b(b) {}\r\n\
    };\r\n\r\nF op(F f1, F f2) {\r\n    return F(f2.a * f1.a, f2.a * f1.b + f2.b);\r\
    \n}\r\n\r\nF e() {\r\n    return F(1, 0);\r\n}\r\n\r\nint main() {\r\n    int\
    \ n, q;\r\n    std::cin >> n >> q;\r\n    ebi::DynamicSegmentTree<F, op, e> seg(n);\r\
    \n    for (int i = 0; i < n; i++) {\r\n        int a, b;\r\n        std::cin >>\
    \ a >> b;\r\n        seg.set(i, F(a, b));\r\n    }\r\n    while (q--) {\r\n  \
    \      int t;\r\n        std::cin >> t;\r\n        if (t == 0) {\r\n         \
    \   int p, c, d;\r\n            std::cin >> p >> c >> d;\r\n            seg.set(p,\
    \ F(c, d));\r\n        } else {\r\n            int l, r, x;\r\n            std::cin\
    \ >> l >> r >> x;\r\n            auto f = seg.prod(l, r);\r\n            std::cout\
    \ << (f.a * x + f.b).value() << std::endl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - data_structure/DynamicSegmentTree.hpp
  - modint/modint.hpp
  - modint/base.hpp
  isVerificationFile: true
  path: test/data_structure/Point_Set_Range_Composite.test.cpp
  requiredBy: []
  timestamp: '2023-10-26 02:17:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Point_Set_Range_Composite.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Point_Set_Range_Composite.test.cpp
- /verify/test/data_structure/Point_Set_Range_Composite.test.cpp.html
title: test/data_structure/Point_Set_Range_Composite.test.cpp
---
