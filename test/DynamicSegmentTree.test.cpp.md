---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/DynamicSegmentTree.hpp
    title: data_structure/DynamicSegmentTree.hpp
  - icon: ':question:'
    path: utility/modint.hpp
    title: utility/modint.hpp
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
  bundledCode: "#line 1 \"test/DynamicSegmentTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \r\n\r\n#line 2 \"data_structure/DynamicSegmentTree.hpp\"\n\r\n#include <memory>\r\
    \n\r\nnamespace ebi {\r\n\r\ntemplate<class Monoid, Monoid (*op)(Monoid, Monoid),\
    \ Monoid (*e)()>\r\nstruct DynamicSegmentTree {\r\nprivate:\r\n    struct Node;\r\
    \n    using node_ptr = std::shared_ptr<Node>;\r\n    struct Node {\r\n       \
    \ Monoid val;\r\n        node_ptr left, right, par;\r\n        Node(node_ptr _par\
    \ = nullptr) : val(e()), left(nullptr), right(nullptr), par(_par) { }\r\n    };\r\
    \n\r\n    node_ptr root;\r\n    int n;\r\n\r\npublic:\r\n    DynamicSegmentTree(int\
    \ _n = 0) : n(1) {\r\n        while(n<_n) {\r\n            n <<= 1;\r\n      \
    \  }\r\n        root = std::make_shared<Node>();\r\n    }\r\n\r\n    void set(int\
    \ i, Monoid x) {\r\n        int l = 0, r = n;\r\n        node_ptr now = root;\r\
    \n        while(r-l>1) {\r\n            int mid = (l+r)/2;\r\n            if(i<mid)\
    \ {\r\n                if(!now->left) {\r\n                    now->left = std::make_shared<Node>(now);\r\
    \n                }\r\n                now = now->left;\r\n                r =\
    \ mid;\r\n            }\r\n            else {\r\n                if(!now->right)\
    \ {\r\n                    now->right = std::make_shared<Node>(now);\r\n     \
    \           }\r\n                now = now->right;\r\n                l = mid;\r\
    \n            }\r\n        }\r\n        now->val = x;\r\n        while(now->par)\
    \ {\r\n            now = now->par;\r\n            now->val = e();\r\n        \
    \    if(now->left) now->val = now->left->val;\r\n            if(now->right) now->val\
    \ = op(now->val, now->right->val);\r\n        }\r\n    }\r\n\r\n    Monoid prod(int\
    \ tl, int tr, int l = 0, int r = -1, node_ptr now = nullptr) {\r\n        if(!now)\
    \ now = root;\r\n        if(r<0) r = n;\r\n        if(tr<=l || r<=tl) {\r\n  \
    \          return e();\r\n        }\r\n        if(tl<=l && r<=tr) {\r\n      \
    \      return now->val;\r\n        }\r\n        Monoid val = e();\r\n        if(now->left)\
    \ {\r\n            val = prod(tl, tr, l, (l+r)/2, now->left);\r\n        }\r\n\
    \        if(now->right) {\r\n            val = op(val, prod(tl, tr, (l+r)/2, r,\
    \ now->right));\r\n        }\r\n        return val;\r\n    }\r\n\r\n    Monoid\
    \ all_prod() {\r\n        return root->val;\r\n    }\r\n\r\n    Monoid get(int\
    \ i) {\r\n        int l = 0;\r\n        int r = n;\r\n        node_ptr now = root;\r\
    \n        while(r-l>1) {\r\n            int mid = (l+r)/2;\r\n            if(i<mid)\
    \ {\r\n                if(!now->left) return e();\r\n                now = now->left;\r\
    \n                r = mid;\r\n            }\r\n            else{\r\n         \
    \       if(!now->right) return e();\r\n                now = now->right;\r\n \
    \               l = mid;\r\n            }\r\n        }\r\n        return now->val;\r\
    \n    }\r\n};\r\n\r\n} // namespace ebi\n#line 4 \"test/DynamicSegmentTree.test.cpp\"\
    \n\r\n#include <iostream>\r\n\r\n#line 2 \"utility/modint.hpp\"\n\r\n/*\r\n  \
    \  author: noshi91\r\n    reference: https://noshi91.hatenablog.com/entry/2019/03/31/174006\r\
    \n    noshi91\u306E\u30D6\u30ED\u30B0\u3067\u516C\u958B\u3055\u308C\u3066\u3044\
    \u308Bmodint\u3092\u5143\u306Binv(), pow()\u3092\u8FFD\u52A0\u3057\u305F\u3082\
    \u306E\u3067\u3059\r\n*/\r\n\r\n#include <cstdint>\r\n#line 11 \"utility/modint.hpp\"\
    \n\r\nnamespace ebi {\r\n\r\ntemplate<std::uint_fast64_t Modulus>\r\nclass modint\
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
    \ ebi\n#line 8 \"test/DynamicSegmentTree.test.cpp\"\n\r\nusing mint = ebi::modint998244353;\r\
    \n\r\nstruct F {\r\n    mint a, b;\r\n    F(mint a, mint b) : a(a), b(b) {}\r\n\
    };\r\n\r\nF op(F f1, F f2) { return F(f2.a * f1.a, f2.a * f1.b + f2.b); }\r\n\r\
    \nF e() { return F(1, 0); }\r\n\r\nint main() {\r\n    int n, q;\r\n    std::cin\
    \ >> n >> q;\r\n    ebi::DynamicSegmentTree<F, op, e> seg(n);\r\n    for (int\
    \ i = 0; i < n; i++) {\r\n        int a, b;\r\n        std::cin >> a >> b;\r\n\
    \        seg.set(i, F(a, b));\r\n    }\r\n    while (q--) {\r\n        int t;\r\
    \n        std::cin >> t;\r\n        if (t == 0) {\r\n            int p, c, d;\r\
    \n            std::cin >> p >> c >> d;\r\n            seg.set(p, F(c, d));\r\n\
    \        } else {\r\n            int l, r, x;\r\n            std::cin >> l >>\
    \ r >> x;\r\n            auto f = seg.prod(l, r);\r\n            std::cout <<\
    \ (f.a * x + f.b).value() << std::endl;\r\n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \r\n\r\n#include \"../data_structure/DynamicSegmentTree.hpp\"\r\n\r\n#include\
    \ <iostream>\r\n\r\n#include \"../utility/modint.hpp\"\r\n\r\nusing mint = ebi::modint998244353;\r\
    \n\r\nstruct F {\r\n    mint a, b;\r\n    F(mint a, mint b) : a(a), b(b) {}\r\n\
    };\r\n\r\nF op(F f1, F f2) { return F(f2.a * f1.a, f2.a * f1.b + f2.b); }\r\n\r\
    \nF e() { return F(1, 0); }\r\n\r\nint main() {\r\n    int n, q;\r\n    std::cin\
    \ >> n >> q;\r\n    ebi::DynamicSegmentTree<F, op, e> seg(n);\r\n    for (int\
    \ i = 0; i < n; i++) {\r\n        int a, b;\r\n        std::cin >> a >> b;\r\n\
    \        seg.set(i, F(a, b));\r\n    }\r\n    while (q--) {\r\n        int t;\r\
    \n        std::cin >> t;\r\n        if (t == 0) {\r\n            int p, c, d;\r\
    \n            std::cin >> p >> c >> d;\r\n            seg.set(p, F(c, d));\r\n\
    \        } else {\r\n            int l, r, x;\r\n            std::cin >> l >>\
    \ r >> x;\r\n            auto f = seg.prod(l, r);\r\n            std::cout <<\
    \ (f.a * x + f.b).value() << std::endl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - data_structure/DynamicSegmentTree.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/DynamicSegmentTree.test.cpp
  requiredBy: []
  timestamp: '2023-05-08 05:33:08+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DynamicSegmentTree.test.cpp
layout: document
redirect_from:
- /verify/test/DynamicSegmentTree.test.cpp
- /verify/test/DynamicSegmentTree.test.cpp.html
title: test/DynamicSegmentTree.test.cpp
---
