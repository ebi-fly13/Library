---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/ImplicitTreap.hpp
    title: data_structure/ImplicitTreap.hpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.hpp
    title: utility/int_alias.hpp
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"test/ImplicitTreap.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \r\n\r\n#line 2 \"data_structure/ImplicitTreap.hpp\"\n\r\n/*\r\n    reference:\
    \ https://www.slideshare.net/iwiwi/2-12188757\r\n               \u5B9F\u88C5\u65B9\
    \u6CD5\u3084Treap\u306E\u30A2\u30A4\u30C7\u30A2\u306A\u3069.\r\n             \
    \  https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\r\n            \
    \   Treap\u3092\u30EA\u30B9\u30C8\u306E\u3088\u3046\u306B\u6271\u3046\u65B9\u6CD5\
    \u3084\u5B9F\u88C5\u6CD5, Monoid\u306E\u8F09\u305B\u65B9\u306A\u3069.\r\n*/\r\n\
    \r\n#include <random>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<\r\n    class S,\r\
    \n    S (*op)(S, S),\r\n    S (*e)(),\r\n    class F,\r\n    S (*mapping)(F, S),\r\
    \n    F (*composition)(F, F),\r\n    F (*id)()>\r\nstruct ImplicitTreap {\r\n\
    private:\r\n    struct Node {\r\n        S val, acc;\r\n        F lazy;\r\n  \
    \      int pri, cnt;\r\n        bool rev;\r\n        Node *lch, *rch;\r\n    \
    \    Node(S val, int pri) : val(val), acc(e()), lazy(id()), pri(pri), cnt(0),rev(false),\
    \ lch(nullptr), rch(nullptr) { }\r\n    };\r\n\r\n    using node_ptr = Node*;\r\
    \n\r\n    node_ptr root;\r\n\r\n    std::random_device rnd;\r\n    std::mt19937\
    \ mt;\r\n    std::uniform_int_distribution<> pri_rnd;\r\n\r\n    int cnt(node_ptr\
    \ t) {\r\n        return t ? t->cnt : 0;\r\n    }\r\n\r\n    void update_cnt(node_ptr\
    \ t) {\r\n        if(t) {\r\n            t->cnt = 1 + cnt(t->lch) + cnt(t->rch);\r\
    \n        }\r\n    }\r\n\r\n    S acc(node_ptr t) {\r\n        return t ? t->acc\
    \ : e();\r\n    }\r\n\r\n    void update_acc(node_ptr t) {\r\n        if(t) {\r\
    \n            t->acc = op(acc(t->lch), t->val);\r\n            t->acc = op(t->acc,\
    \ acc(t->rch));\r\n        }\r\n    }\r\n\r\n    void eval(node_ptr t) {\r\n \
    \       if(t) {\r\n            if(t->lch) {\r\n                t->lch->lazy =\
    \ composition(t->lazy, t->lch->lazy);\r\n                t->lch->acc = mapping(t->lazy,\
    \ t->lch->acc);\r\n            }\r\n            if(t->rch) {\r\n             \
    \   t->rch->lazy = composition(t->lazy, t->rch->lazy);\r\n                t->rch->acc\
    \ = mapping(t->lazy, t->rch->acc);\r\n            }\r\n            t->val = mapping(t->lazy,\
    \ t->val);\r\n            t->lazy = id();\r\n        }\r\n    }\r\n\r\n    void\
    \ pushdown(node_ptr t) {\r\n        if(t && t->rev) {\r\n            t->rev =\
    \ false;\r\n            std::swap(t->lch, t->rch);\r\n            if(t->lch) t->lch->rev\
    \ ^= 1;\r\n            if(t->rch) t->rch->rev ^= 1;\r\n        }\r\n        eval(t);\r\
    \n        update(t);\r\n    }\r\n\r\n    void update(node_ptr t) {\r\n       \
    \ update_cnt(t);\r\n        update_acc(t);\r\n    }\r\n\r\n    node_ptr merge(node_ptr\
    \ l, node_ptr r) {\r\n        pushdown(l);\r\n        pushdown(r);\r\n       \
    \ if(!l || !r) {\r\n            return !l ? r : l;\r\n        }\r\n        if(l->pri\
    \ > r->pri) {\r\n            l->rch = merge(l->rch, r);\r\n            update(l);\r\
    \n            return l;\r\n        }\r\n        else {\r\n            r->lch =\
    \ merge(l, r->lch);\r\n            update(r);\r\n            return r;\r\n   \
    \     }\r\n    }\r\n\r\n    std::pair<node_ptr, node_ptr> split(node_ptr t, int\
    \ key) {\r\n        if(!t) return std::pair<node_ptr, node_ptr>(nullptr, nullptr);\r\
    \n        pushdown(t);\r\n        if(key < cnt(t->lch) + 1) {\r\n            auto\
    \ [l, r] = split(t->lch, key);\r\n            t->lch = r;\r\n            update(t);\r\
    \n            return std::pair<node_ptr, node_ptr>(l, t);\r\n        }\r\n   \
    \     else {\r\n            auto [l, r] = split(t->rch, key-cnt(t->lch)-1);\r\n\
    \            t->rch = l;\r\n            update(t);\r\n            return  std::pair<node_ptr,\
    \ node_ptr>(t, r);\r\n        }\r\n    }\r\n    \r\npublic:\r\n    ImplicitTreap()\
    \ : root(nullptr) {\r\n        mt = std::mt19937(rnd());\r\n        pri_rnd =\
    \ std::uniform_int_distribution<>(0, 1e9);\r\n    }\r\n\r\n    void insert(int\
    \ k, S x) {\r\n        auto [l, r] = split(root, k);\r\n        auto t = merge(l,\
    \ new Node(x, pri_rnd(mt)));\r\n        root = merge(t, r);\r\n    }\r\n\r\n \
    \   void erase(int k) {\r\n        auto [l, r] = split(root, k+1);\r\n       \
    \ auto [nl, nr] = split(l, k);\r\n        root = merge(nl, r);\r\n    }\r\n\r\n\
    \    void reverse(int l, int r) {\r\n        auto [t1, t2] = split(root, l);\r\
    \n        auto [t3, t4] = split(t2, r-l);\r\n        t3->rev ^= 1;\r\n       \
    \ t1 = merge(t1, t3);\r\n        root = merge(t1, t4);\r\n    }\r\n\r\n    void\
    \ apply(int l, int r, F x) {\r\n        auto [t1, t2] = split(root, l);\r\n  \
    \      auto [t3, t4] = split(t2, r-l);\r\n        t3->lazy = composition(x, t3->lazy);\r\
    \n        t3->acc = mapping(x, t3->acc);\r\n        t1 = merge(t1, t3);\r\n  \
    \      root = merge(t1,t4);\r\n    }\r\n\r\n    S prod(int l, int r) {\r\n   \
    \     auto [t1, t2] = split(root, l);\r\n        auto [t3, t4] = split(t2, r-l);\r\
    \n        S ret = t3->acc;\r\n        t1 = merge(t1, t3);\r\n        root = merge(t1,\
    \ t4);\r\n        return ret;\r\n    }\r\n};\r\n\r\n} // namespace ebi\n#line\
    \ 2 \"utility/int_alias.hpp\"\n\r\n#include <cstddef>\r\n#include <cstdint>\r\n\
    \r\nusing i32 = std::int32_t;\r\nusing i64 = std::int64_t;\r\nusing u16 = std::uint16_t;\r\
    \nusing u32 = std::uint32_t;\r\nusing u64 = std::uint64_t;\r\nusing usize = std::size_t;\n\
    #line 2 \"utility/modint.hpp\"\n\r\n/*\r\n    author: noshi91\r\n    reference:\
    \ https://noshi91.hatenablog.com/entry/2019/03/31/174006\r\n    noshi91\u306E\u30D6\
    \u30ED\u30B0\u3067\u516C\u958B\u3055\u308C\u3066\u3044\u308Bmodint\u3092\u5143\
    \u306Binv(), pow()\u3092\u8FFD\u52A0\u3057\u305F\u3082\u306E\u3067\u3059\r\n*/\r\
    \n\r\n#line 10 \"utility/modint.hpp\"\n\r\nnamespace ebi {\r\n\r\ntemplate<std::uint_fast64_t\
    \ Modulus>\r\nclass modint {\r\n  using u64 = std::uint_fast64_t;\r\n\r\npublic:\r\
    \n    u64 a;\r\n\r\n    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus)\
    \ {}\r\n    constexpr u64 &value() noexcept { return a; }\r\n    constexpr const\
    \ u64 &value() const noexcept { return a; }\r\n    constexpr modint operator+(const\
    \ modint rhs) const noexcept {\r\n        return modint(*this) += rhs;\r\n   \
    \ }\r\n    constexpr modint operator-(const modint rhs) const noexcept {\r\n \
    \       return modint(*this) -= rhs;\r\n    }\r\n    constexpr modint operator*(const\
    \ modint rhs) const noexcept {\r\n        return modint(*this) *= rhs;\r\n   \
    \ }\r\n    constexpr modint operator/(const modint rhs) const noexcept {\r\n \
    \       return modint(*this) /= rhs;\r\n    }\r\n    constexpr modint &operator+=(const\
    \ modint rhs) noexcept {\r\n        a += rhs.a;\r\n        if (a >= Modulus) {\r\
    \n            a -= Modulus;\r\n        }\r\n        return *this;\r\n    }\r\n\
    \    constexpr modint &operator-=(const modint rhs) noexcept {\r\n        if (a\
    \ < rhs.a) {\r\n        a += Modulus;\r\n        }\r\n        a -= rhs.a;\r\n\
    \        return *this;\r\n    }\r\n    constexpr modint &operator*=(const modint\
    \ rhs) noexcept {\r\n        a = a * rhs.a % Modulus;\r\n        return *this;\r\
    \n    }\r\n    constexpr modint &operator/=(modint rhs) noexcept {\r\n       \
    \ u64 exp = Modulus - 2;\r\n        while (exp) {\r\n        if (exp % 2) {\r\n\
    \            *this *= rhs;\r\n        }\r\n        rhs *= rhs;\r\n        exp\
    \ /= 2;\r\n        }\r\n        return *this;\r\n    }\r\n    modint pow(u64 n)\
    \ const noexcept {\r\n        modint res = 1;\r\n        modint x = a;\r\n   \
    \     while(n>0){\r\n            if(n&1) res *= x;\r\n            x *= x;\r\n\
    \            n >>=1;\r\n        }\r\n        return res;\r\n    }\r\n    modint\
    \ inv() const {\r\n        return pow(Modulus-2);\r\n    }\r\n\r\n    static u64\
    \ mod() {\r\n        return Modulus;\r\n    }\r\n};\r\n\r\nusing modint998244353\
    \ = modint<998244353>;\r\nusing modint1000000007 = modint<1000000007>;\r\n\r\n\
    } // namespace ebi\n#line 6 \"test/ImplicitTreap.test.cpp\"\n\r\n#include <iostream>\r\
    \n\r\nusing mint = ebi::modint998244353;\r\n\r\nstruct S {\r\n    mint a;\r\n\
    \    int size;\r\n};\r\n\r\nstruct F {\r\n    mint a, b;\r\n    F(mint a, mint\
    \ b) : a(a), b(b) { }\r\n};\r\n\r\nS op(S l, S r) { return S{l.a + r.a, l.size\
    \ + r.size}; }\r\n\r\nS e() { return S{0, 0}; }\r\n\r\nS mapping(F l, S r) { return\
    \ S{r.a * l.a + (mint)r.size * l.b, r.size}; }\r\n\r\nF composition(F l, F r)\
    \ { return F{r.a * l.a, r.b * l.a + l.b}; }\r\n\r\nF id() { return F{1, 0}; }\r\
    \n\r\nint main() {\r\n    ebi::ImplicitTreap<S,op,e,F,mapping,composition,id>\
    \ treap;\r\n    int n,q; std::cin >> n >> q;\r\n    for(int i = 0; i<n; i++) {\r\
    \n        i64 a; std::cin >> a;\r\n        treap.insert(i, {a, 1});\r\n    }\r\
    \n    while(q--) {\r\n        int t; std::cin >> t;\r\n        if(t==0) {\r\n\
    \            int i;\r\n            i64 x;\r\n            std::cin >> i >> x;\r\
    \n            treap.insert(i, {x, 1});\r\n        }\r\n        else if(t==1) {\r\
    \n            int i;\r\n            std::cin >> i;\r\n            treap.erase(i);\r\
    \n        }\r\n        else if(t==2){\r\n            int l,r;\r\n            std::cin\
    \ >> l >> r;\r\n            treap.reverse(l,r);\r\n        }\r\n        else if(t==3)\
    \ {\r\n            int l,r,b,c; std::cin >> l >> r >> b >> c;\r\n            treap.apply(l,r,F(b,c));\r\
    \n        }\r\n        else if(t==4) {\r\n            int l,r; std::cin >> l >>\
    \ r;\r\n            std::cout << treap.prod(l,r).a.value() << std::endl;\r\n \
    \       }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \r\n\r\n#include \"../data_structure/ImplicitTreap.hpp\"\r\n#include \"../utility/int_alias.hpp\"\
    \r\n#include \"../utility/modint.hpp\"\r\n\r\n#include <iostream>\r\n\r\nusing\
    \ mint = ebi::modint998244353;\r\n\r\nstruct S {\r\n    mint a;\r\n    int size;\r\
    \n};\r\n\r\nstruct F {\r\n    mint a, b;\r\n    F(mint a, mint b) : a(a), b(b)\
    \ { }\r\n};\r\n\r\nS op(S l, S r) { return S{l.a + r.a, l.size + r.size}; }\r\n\
    \r\nS e() { return S{0, 0}; }\r\n\r\nS mapping(F l, S r) { return S{r.a * l.a\
    \ + (mint)r.size * l.b, r.size}; }\r\n\r\nF composition(F l, F r) { return F{r.a\
    \ * l.a, r.b * l.a + l.b}; }\r\n\r\nF id() { return F{1, 0}; }\r\n\r\nint main()\
    \ {\r\n    ebi::ImplicitTreap<S,op,e,F,mapping,composition,id> treap;\r\n    int\
    \ n,q; std::cin >> n >> q;\r\n    for(int i = 0; i<n; i++) {\r\n        i64 a;\
    \ std::cin >> a;\r\n        treap.insert(i, {a, 1});\r\n    }\r\n    while(q--)\
    \ {\r\n        int t; std::cin >> t;\r\n        if(t==0) {\r\n            int\
    \ i;\r\n            i64 x;\r\n            std::cin >> i >> x;\r\n            treap.insert(i,\
    \ {x, 1});\r\n        }\r\n        else if(t==1) {\r\n            int i;\r\n \
    \           std::cin >> i;\r\n            treap.erase(i);\r\n        }\r\n   \
    \     else if(t==2){\r\n            int l,r;\r\n            std::cin >> l >> r;\r\
    \n            treap.reverse(l,r);\r\n        }\r\n        else if(t==3) {\r\n\
    \            int l,r,b,c; std::cin >> l >> r >> b >> c;\r\n            treap.apply(l,r,F(b,c));\r\
    \n        }\r\n        else if(t==4) {\r\n            int l,r; std::cin >> l >>\
    \ r;\r\n            std::cout << treap.prod(l,r).a.value() << std::endl;\r\n \
    \       }\r\n    }\r\n}"
  dependsOn:
  - data_structure/ImplicitTreap.hpp
  - utility/int_alias.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/ImplicitTreap.test.cpp
  requiredBy: []
  timestamp: '2021-01-18 11:46:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ImplicitTreap.test.cpp
layout: document
redirect_from:
- /verify/test/ImplicitTreap.test.cpp
- /verify/test/ImplicitTreap.test.cpp.html
title: test/ImplicitTreap.test.cpp
---
