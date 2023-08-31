---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/ImplicitTreap.hpp
    title: data_structure/ImplicitTreap.hpp
  - icon: ':heavy_check_mark:'
    path: template/int_alias.hpp
    title: template/int_alias.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"test/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp\"\
    \n#define PROBLEM \\\r\n    \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \r\n\r\n#include <iostream>\r\n\r\n#line 2 \"data_structure/ImplicitTreap.hpp\"\
    \n\r\n/*\r\n    reference: https://www.slideshare.net/iwiwi/2-12188757\r\n   \
    \            \u5B9F\u88C5\u65B9\u6CD5\u3084Treap\u306E\u30A2\u30A4\u30C7\u30A2\
    \u306A\u3069.\r\n               https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\r\
    \n               Treap\u3092\u30EA\u30B9\u30C8\u306E\u3088\u3046\u306B\u6271\u3046\
    \u65B9\u6CD5\u3084\u5B9F\u88C5\u6CD5, Monoid\u306E\u8F09\u305B\u65B9\u306A\u3069\
    .\r\n*/\r\n\r\n#include <random>\r\n\r\nnamespace ebi {\r\n\r\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),\r\n          F (*composition)(F,\
    \ F), F (*id)()>\r\nstruct ImplicitTreap {\r\n  private:\r\n    struct Node {\r\
    \n        S val, acc;\r\n        F lazy;\r\n        int pri, cnt;\r\n        bool\
    \ rev;\r\n        Node *lch, *rch;\r\n        Node(S val, int pri)\r\n       \
    \     : val(val),\r\n              acc(e()),\r\n              lazy(id()),\r\n\
    \              pri(pri),\r\n              cnt(0),\r\n              rev(false),\r\
    \n              lch(nullptr),\r\n              rch(nullptr) {}\r\n    };\r\n\r\
    \n    using node_ptr = Node *;\r\n\r\n    node_ptr root;\r\n\r\n    std::random_device\
    \ rnd;\r\n    std::mt19937 mt;\r\n    std::uniform_int_distribution<> pri_rnd;\r\
    \n\r\n    int cnt(node_ptr t) {\r\n        return t ? t->cnt : 0;\r\n    }\r\n\
    \r\n    void update_cnt(node_ptr t) {\r\n        if (t) {\r\n            t->cnt\
    \ = 1 + cnt(t->lch) + cnt(t->rch);\r\n        }\r\n    }\r\n\r\n    S acc(node_ptr\
    \ t) {\r\n        return t ? t->acc : e();\r\n    }\r\n\r\n    void update_acc(node_ptr\
    \ t) {\r\n        if (t) {\r\n            t->acc = op(acc(t->lch), t->val);\r\n\
    \            t->acc = op(t->acc, acc(t->rch));\r\n        }\r\n    }\r\n\r\n \
    \   void eval(node_ptr t) {\r\n        if (t) {\r\n            if (t->lch) {\r\
    \n                t->lch->lazy = composition(t->lazy, t->lch->lazy);\r\n     \
    \           t->lch->acc = mapping(t->lazy, t->lch->acc);\r\n            }\r\n\
    \            if (t->rch) {\r\n                t->rch->lazy = composition(t->lazy,\
    \ t->rch->lazy);\r\n                t->rch->acc = mapping(t->lazy, t->rch->acc);\r\
    \n            }\r\n            t->val = mapping(t->lazy, t->val);\r\n        \
    \    t->lazy = id();\r\n        }\r\n    }\r\n\r\n    void pushdown(node_ptr t)\
    \ {\r\n        if (t && t->rev) {\r\n            t->rev = false;\r\n         \
    \   std::swap(t->lch, t->rch);\r\n            if (t->lch) t->lch->rev ^= 1;\r\n\
    \            if (t->rch) t->rch->rev ^= 1;\r\n        }\r\n        eval(t);\r\n\
    \        update(t);\r\n    }\r\n\r\n    void update(node_ptr t) {\r\n        update_cnt(t);\r\
    \n        update_acc(t);\r\n    }\r\n\r\n    node_ptr merge(node_ptr l, node_ptr\
    \ r) {\r\n        pushdown(l);\r\n        pushdown(r);\r\n        if (!l || !r)\
    \ {\r\n            return !l ? r : l;\r\n        }\r\n        if (l->pri > r->pri)\
    \ {\r\n            l->rch = merge(l->rch, r);\r\n            update(l);\r\n  \
    \          return l;\r\n        } else {\r\n            r->lch = merge(l, r->lch);\r\
    \n            update(r);\r\n            return r;\r\n        }\r\n    }\r\n\r\n\
    \    std::pair<node_ptr, node_ptr> split(node_ptr t, int key) {\r\n        if\
    \ (!t) return std::pair<node_ptr, node_ptr>(nullptr, nullptr);\r\n        pushdown(t);\r\
    \n        if (key < cnt(t->lch) + 1) {\r\n            auto [l, r] = split(t->lch,\
    \ key);\r\n            t->lch = r;\r\n            update(t);\r\n            return\
    \ std::pair<node_ptr, node_ptr>(l, t);\r\n        } else {\r\n            auto\
    \ [l, r] = split(t->rch, key - cnt(t->lch) - 1);\r\n            t->rch = l;\r\n\
    \            update(t);\r\n            return std::pair<node_ptr, node_ptr>(t,\
    \ r);\r\n        }\r\n    }\r\n\r\n  public:\r\n    ImplicitTreap() : root(nullptr)\
    \ {\r\n        mt = std::mt19937(rnd());\r\n        pri_rnd = std::uniform_int_distribution<>(0,\
    \ 1e9);\r\n    }\r\n\r\n    void insert(int k, S x) {\r\n        auto [l, r] =\
    \ split(root, k);\r\n        auto t = merge(l, new Node(x, pri_rnd(mt)));\r\n\
    \        root = merge(t, r);\r\n    }\r\n\r\n    void erase(int k) {\r\n     \
    \   auto [l, r] = split(root, k + 1);\r\n        auto [nl, nr] = split(l, k);\r\
    \n        root = merge(nl, r);\r\n    }\r\n\r\n    void reverse(int l, int r)\
    \ {\r\n        auto [t1, t2] = split(root, l);\r\n        auto [t3, t4] = split(t2,\
    \ r - l);\r\n        t3->rev ^= 1;\r\n        t1 = merge(t1, t3);\r\n        root\
    \ = merge(t1, t4);\r\n    }\r\n\r\n    void apply(int l, int r, F x) {\r\n   \
    \     auto [t1, t2] = split(root, l);\r\n        auto [t3, t4] = split(t2, r -\
    \ l);\r\n        t3->lazy = composition(x, t3->lazy);\r\n        t3->acc = mapping(x,\
    \ t3->acc);\r\n        t1 = merge(t1, t3);\r\n        root = merge(t1, t4);\r\n\
    \    }\r\n\r\n    S prod(int l, int r) {\r\n        auto [t1, t2] = split(root,\
    \ l);\r\n        auto [t3, t4] = split(t2, r - l);\r\n        S ret = t3->acc;\r\
    \n        t1 = merge(t1, t3);\r\n        root = merge(t1, t4);\r\n        return\
    \ ret;\r\n    }\r\n};\r\n\r\n}  // namespace ebi\n#line 2 \"template/int_alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace ebi {\n\nusing std::size_t;\nusing i8 = std::int8_t;\n\
    using u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing u16 = std::uint16_t;\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    \n}\n#line 2 \"utility/modint.hpp\"\n\r\n#include <cassert>\r\n#line 5 \"utility/modint.hpp\"\
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
    \ static_modint<1000000007>;\r\n\r\n}  // namespace ebi\n#line 9 \"test/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp\"\
    \n\r\nusing mint = ebi::modint998244353;\r\n\r\nstruct S {\r\n    mint a;\r\n\
    \    int size;\r\n};\r\n\r\nstruct F {\r\n    mint a, b;\r\n    F(mint a, mint\
    \ b) : a(a), b(b) {}\r\n};\r\n\r\nS op(S l, S r) {\r\n    return S{l.a + r.a,\
    \ l.size + r.size};\r\n}\r\n\r\nS e() {\r\n    return S{0, 0};\r\n}\r\n\r\nS mapping(F\
    \ l, S r) {\r\n    return S{r.a * l.a + (mint)r.size * l.b, r.size};\r\n}\r\n\r\
    \nF composition(F l, F r) {\r\n    return F{r.a * l.a, r.b * l.a + l.b};\r\n}\r\
    \n\r\nF id() {\r\n    return F{1, 0};\r\n}\r\n\r\nusing ebi::i64;\r\n\r\nint main()\
    \ {\r\n    ebi::ImplicitTreap<S, op, e, F, mapping, composition, id> treap;\r\n\
    \    int n, q;\r\n    std::cin >> n >> q;\r\n    for (int i = 0; i < n; i++) {\r\
    \n        i64 a;\r\n        std::cin >> a;\r\n        treap.insert(i, {a, 1});\r\
    \n    }\r\n    while (q--) {\r\n        int t;\r\n        std::cin >> t;\r\n \
    \       if (t == 0) {\r\n            int i;\r\n            i64 x;\r\n        \
    \    std::cin >> i >> x;\r\n            treap.insert(i, {x, 1});\r\n        }\
    \ else if (t == 1) {\r\n            int i;\r\n            std::cin >> i;\r\n \
    \           treap.erase(i);\r\n        } else if (t == 2) {\r\n            int\
    \ l, r;\r\n            std::cin >> l >> r;\r\n            treap.reverse(l, r);\r\
    \n        } else if (t == 3) {\r\n            int l, r, b, c;\r\n            std::cin\
    \ >> l >> r >> b >> c;\r\n            treap.apply(l, r, F(b, c));\r\n        }\
    \ else if (t == 4) {\r\n            int l, r;\r\n            std::cin >> l >>\
    \ r;\r\n            std::cout << treap.prod(l, r).a.value() << std::endl;\r\n\
    \        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \\\r\n    \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \r\n\r\n#include <iostream>\r\n\r\n#include \"../../data_structure/ImplicitTreap.hpp\"\
    \r\n#include \"../../template/int_alias.hpp\"\r\n#include \"../../utility/modint.hpp\"\
    \r\n\r\nusing mint = ebi::modint998244353;\r\n\r\nstruct S {\r\n    mint a;\r\n\
    \    int size;\r\n};\r\n\r\nstruct F {\r\n    mint a, b;\r\n    F(mint a, mint\
    \ b) : a(a), b(b) {}\r\n};\r\n\r\nS op(S l, S r) {\r\n    return S{l.a + r.a,\
    \ l.size + r.size};\r\n}\r\n\r\nS e() {\r\n    return S{0, 0};\r\n}\r\n\r\nS mapping(F\
    \ l, S r) {\r\n    return S{r.a * l.a + (mint)r.size * l.b, r.size};\r\n}\r\n\r\
    \nF composition(F l, F r) {\r\n    return F{r.a * l.a, r.b * l.a + l.b};\r\n}\r\
    \n\r\nF id() {\r\n    return F{1, 0};\r\n}\r\n\r\nusing ebi::i64;\r\n\r\nint main()\
    \ {\r\n    ebi::ImplicitTreap<S, op, e, F, mapping, composition, id> treap;\r\n\
    \    int n, q;\r\n    std::cin >> n >> q;\r\n    for (int i = 0; i < n; i++) {\r\
    \n        i64 a;\r\n        std::cin >> a;\r\n        treap.insert(i, {a, 1});\r\
    \n    }\r\n    while (q--) {\r\n        int t;\r\n        std::cin >> t;\r\n \
    \       if (t == 0) {\r\n            int i;\r\n            i64 x;\r\n        \
    \    std::cin >> i >> x;\r\n            treap.insert(i, {x, 1});\r\n        }\
    \ else if (t == 1) {\r\n            int i;\r\n            std::cin >> i;\r\n \
    \           treap.erase(i);\r\n        } else if (t == 2) {\r\n            int\
    \ l, r;\r\n            std::cin >> l >> r;\r\n            treap.reverse(l, r);\r\
    \n        } else if (t == 3) {\r\n            int l, r, b, c;\r\n            std::cin\
    \ >> l >> r >> b >> c;\r\n            treap.apply(l, r, F(b, c));\r\n        }\
    \ else if (t == 4) {\r\n            int l, r;\r\n            std::cin >> l >>\
    \ r;\r\n            std::cout << treap.prod(l, r).a.value() << std::endl;\r\n\
    \        }\r\n    }\r\n}"
  dependsOn:
  - data_structure/ImplicitTreap.hpp
  - template/int_alias.hpp
  - utility/modint.hpp
  - utility/modint_base.hpp
  isVerificationFile: true
  path: test/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-08-16 10:56:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
- /verify/test/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp.html
title: test/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
---
