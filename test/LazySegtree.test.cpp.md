---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/LazySegtree.hpp
    title: data_structure/LazySegtree.hpp
  - icon: ':question:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/LazySegtree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \r\n\r\n#line 2 \"data_structure/LazySegtree.hpp\"\n\r\n/*\r\n    reference: https://beet-aizu.hatenablog.com/entry/2017/12/01/225955\r\
    \n               https://atcoder.github.io/ac-library/master/document_ja/lazysegtree.html\r\
    \n*/\r\n\r\n#include <vector>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<\r\n    class\
    \ S,\r\n    S (*op)(S, S),\r\n    S (*e)(),\r\n    class F,\r\n    S (*mapping)(F,\
    \ S),\r\n    F (*merge)(F, F),\r\n    F (*id)()>\r\nstruct LazySegtree {\r\nprivate:\r\
    \n    std::vector<S> data;\r\n    std::vector<F> lazy;\r\n    int n;\r\n\r\n \
    \   void eval(int index, int l, int r) {\r\n        data[index] = mapping(lazy[index],\
    \ data[index]);\r\n        if(r-l>1) {\r\n            lazy[2*index+1] = merge(lazy[index]\
    \ ,lazy[2*index+1]);\r\n            lazy[2*index+2] = merge(lazy[index] ,lazy[2*index+2]);\r\
    \n        }\r\n        lazy[index] = id();\r\n    }\r\n\r\npublic:\r\n    LazySegtree(int\
    \ _n) : n(1) {\r\n        while(n<_n) {\r\n            n <<= 1;\r\n        }\r\
    \n        data.assign(2*n-1, e());\r\n        lazy.assign(2*n-1, id());\r\n  \
    \  }\r\n\r\n    LazySegtree(std::vector<S> v) : n(1) {\r\n        int _n = v.size();\r\
    \n        while(n<_n) {\r\n            n <<= 1;\r\n        }\r\n        data.assign(2*n-1,\
    \ e());\r\n        lazy.assign(2*n-1, id());\r\n        for(int i = 0; i<_n; i++)\
    \ {\r\n            data[i+n-1] = v[i];\r\n        }\r\n        for(int i = n-2;\
    \ i>=0; i--) {\r\n            data[i] = op(data[2*i+1], data[2*i+2]);\r\n    \
    \    }\r\n    }\r\n\r\n    S prod(int l, int r, int nl = 0, int nr = -1, int index\
    \ = 0) {\r\n        if(nr < 0) nr = n;\r\n        if(nr<=l || r<=nl) {\r\n   \
    \         return e();\r\n        }\r\n        eval(index, nl, nr);\r\n       \
    \ if(l<=nl && nr<=r) {\r\n            return data[index];\r\n        }\r\n   \
    \     return op(prod(l, r, nl, (nl+nr)/2, 2*index+1), prod(l, r, (nl+nr)/2, nr,\
    \ 2*index+2));\r\n    }\r\n\r\n    S all_prod() {\r\n        eval(0,0,n);\r\n\
    \        return data[0];\r\n    }\r\n\r\n    void apply(int l, int r, F f, int\
    \ nl = 0, int nr = -1, int index = 0) {\r\n        if(nr<0) nr = n;\r\n      \
    \  eval(index, nl, nr);\r\n        if(nr<=l || r<=nl) return;\r\n        if(l<=nl\
    \ && nr<=r) {\r\n            lazy[index] = merge(f, lazy[index]);\r\n        \
    \    eval(index, nl, nr);\r\n            return;\r\n        }\r\n        apply(l,\
    \ r, f, nl, (nl+nr)/2, 2*index+1);\r\n        apply(l, r, f, (nl+nr)/2, nr, 2*index+2);\r\
    \n        data[index] = op(data[2*index+1], data[2*index+2]);\r\n        return;\r\
    \n    }\r\n};\r\n\r\n} // namespace ebi\n#line 2 \"utility/modint.hpp\"\n\r\n\
    /*\r\n    author: noshi91\r\n    reference: https://noshi91.hatenablog.com/entry/2019/03/31/174006\r\
    \n    noshi91\u306E\u30D6\u30ED\u30B0\u3067\u516C\u958B\u3055\u308C\u3066\u3044\
    \u308Bmodint\u3092\u5143\u306Binv(), pow()\u3092\u8FFD\u52A0\u3057\u305F\u3082\
    \u306E\u3067\u3059\r\n*/\r\n\r\n#include <cstdint>\r\n\r\nnamespace ebi {\r\n\r\
    \ntemplate<std::uint_fast64_t Modulus>\r\nclass modint {\r\n  using u64 = std::uint_fast64_t;\r\
    \n\r\npublic:\r\n    u64 a;\r\n\r\n    constexpr modint(const u64 x = 0) noexcept\
    \ : a(x % Modulus) {}\r\n    constexpr u64 &value() noexcept { return a; }\r\n\
    \    constexpr const u64 &value() const noexcept { return a; }\r\n    constexpr\
    \ modint operator+(const modint rhs) const noexcept {\r\n        return modint(*this)\
    \ += rhs;\r\n    }\r\n    constexpr modint operator-(const modint rhs) const noexcept\
    \ {\r\n        return modint(*this) -= rhs;\r\n    }\r\n    constexpr modint operator*(const\
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
    } // namespace ebi\n#line 5 \"test/LazySegtree.test.cpp\"\n\r\n#include <iostream>\r\
    \n#line 8 \"test/LazySegtree.test.cpp\"\n\r\nusing mint = ebi::modint998244353;\r\
    \n\r\nstruct S {\r\n    mint a;\r\n    int size;\r\n};\r\n\r\nstruct F {\r\n \
    \   mint a, b;\r\n    F(mint a, mint b) : a(a), b(b) { }\r\n};\r\n\r\nS op(S l,\
    \ S r) { return S{l.a + r.a, l.size + r.size}; }\r\n\r\nS e() { return S{0, 0};\
    \ }\r\n\r\nS mapping(F l, S r) { return S{r.a * l.a + (mint)r.size * l.b, r.size};\
    \ }\r\n\r\nF merge(F l, F r) { return F{r.a * l.a, r.b * l.a + l.b}; }\r\n\r\n\
    F id() { return F{1, 0}; }\r\n\r\nint main(){\r\n    int n,q; std::cin >> n >>\
    \ q;\r\n    std::vector<S> v(n);\r\n    for(int i = 0; i<n; i++) {\r\n       \
    \ int a;\r\n        std::cin >> a;\r\n        v[i] = {a,1};\r\n    }\r\n    ebi::LazySegtree<S,op,e,F,mapping,merge,id>\
    \ seg(v);\r\n    while(q--) {\r\n        int t; std::cin >> t;\r\n        if(t==0)\
    \ {\r\n            int l,r,b,c; std::cin >> l >> r >> b >> c;\r\n            seg.apply(l,r,F(b,c));\r\
    \n        }\r\n        else {\r\n            int l,r; std::cin >> l >> r;\r\n\
    \            std::cout << seg.prod(l,r).a.value() << std::endl;\r\n        }\r\
    \n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \r\n\r\n#include \"../data_structure/LazySegtree.hpp\"\r\n#include \"../utility/modint.hpp\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\nusing mint = ebi::modint998244353;\r\
    \n\r\nstruct S {\r\n    mint a;\r\n    int size;\r\n};\r\n\r\nstruct F {\r\n \
    \   mint a, b;\r\n    F(mint a, mint b) : a(a), b(b) { }\r\n};\r\n\r\nS op(S l,\
    \ S r) { return S{l.a + r.a, l.size + r.size}; }\r\n\r\nS e() { return S{0, 0};\
    \ }\r\n\r\nS mapping(F l, S r) { return S{r.a * l.a + (mint)r.size * l.b, r.size};\
    \ }\r\n\r\nF merge(F l, F r) { return F{r.a * l.a, r.b * l.a + l.b}; }\r\n\r\n\
    F id() { return F{1, 0}; }\r\n\r\nint main(){\r\n    int n,q; std::cin >> n >>\
    \ q;\r\n    std::vector<S> v(n);\r\n    for(int i = 0; i<n; i++) {\r\n       \
    \ int a;\r\n        std::cin >> a;\r\n        v[i] = {a,1};\r\n    }\r\n    ebi::LazySegtree<S,op,e,F,mapping,merge,id>\
    \ seg(v);\r\n    while(q--) {\r\n        int t; std::cin >> t;\r\n        if(t==0)\
    \ {\r\n            int l,r,b,c; std::cin >> l >> r >> b >> c;\r\n            seg.apply(l,r,F(b,c));\r\
    \n        }\r\n        else {\r\n            int l,r; std::cin >> l >> r;\r\n\
    \            std::cout << seg.prod(l,r).a.value() << std::endl;\r\n        }\r\
    \n    }\r\n}"
  dependsOn:
  - data_structure/LazySegtree.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/LazySegtree.test.cpp
  requiredBy: []
  timestamp: '2021-01-18 11:46:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LazySegtree.test.cpp
layout: document
redirect_from:
- /verify/test/LazySegtree.test.cpp
- /verify/test/LazySegtree.test.cpp.html
title: test/LazySegtree.test.cpp
---
