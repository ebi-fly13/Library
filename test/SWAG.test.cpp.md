---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/SWAG.hpp
    title: data_structure/SWAG.hpp
  - icon: ':heavy_check_mark:'
    path: utility/modint.hpp
    title: utility/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/SWAG.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \r\n\r\n#line 2 \"data_structure/SWAG.hpp\"\n\r\n/*\r\n    reference: https://scrapbox.io/data-structures/Sliding_Window_Aggregation\r\
    \n*/\r\n\r\n#include <stack>\r\n#include <cassert>\r\n\r\ntemplate<class Semigroup,\
    \ Semigroup (*op)(Semigroup, Semigroup)>\r\nstruct SWAG {\r\nprivate:\r\n    struct\
    \ Node {\r\n        Semigroup value;\r\n        Semigroup fold;\r\n        Node(Semigroup\
    \ value, Semigroup fold) : value(value), fold(fold) { }\r\n    };\r\n\r\n    void\
    \ move() {\r\n        assert(!back.empty());\r\n        Node p = back.top();\r\
    \n        back.pop();\r\n        front.push(Node(p.value, p.value));\r\n     \
    \   while(!back.empty()) {\r\n            Node p = back.top();\r\n           \
    \ back.pop();\r\n            p.fold = op(p.value, front.top().fold);\r\n     \
    \       front.push(p);\r\n        }\r\n    }\r\n\r\n    std::stack<Node> front,\
    \ back;\r\n\r\npublic:\r\n\r\n    SWAG() { }\r\n\r\n    int size() {\r\n     \
    \   return front.size() + back.size();\r\n    }\r\n\r\n    bool empty() {\r\n\
    \        if(size()==0) return true;\r\n        return false;\r\n    }\r\n\r\n\
    \    void push(Semigroup x) {\r\n        Node node(x,x);\r\n        if(back.size()!=0)\
    \ {\r\n            Node p = back.top();\r\n            node.fold = op(p.fold,\
    \ node.fold);\r\n        }\r\n        back.push(node);\r\n    }\r\n\r\n    void\
    \ pop() {\r\n        assert(!empty());\r\n        if(front.empty()) {\r\n    \
    \        move();\r\n        }\r\n        front.pop();\r\n    }\r\n\r\n    Semigroup\
    \ fold_all() {\r\n        assert(!empty());\r\n        if(front.empty()) {\r\n\
    \            return back.top().fold;\r\n        }\r\n        else if(back.empty()){\r\
    \n            return front.top().fold;\r\n        }\r\n        else{\r\n     \
    \       return op(front.top().fold, back.top().fold);\r\n        }\r\n    }\r\n\
    };\n#line 2 \"utility/modint.hpp\"\n\r\n/*\r\n    author: noshi91\r\n    reference:\
    \ https://noshi91.hatenablog.com/entry/2019/03/31/174006\r\n    noshi91\u306E\u30D6\
    \u30ED\u30B0\u3067\u516C\u958B\u3055\u308C\u3066\u3044\u308Bmodint\u3092\u5143\
    \u306Binv(), pow()\u3092\u8FFD\u52A0\u3057\u305F\u3082\u306E\u3067\u3059\r\n*/\r\
    \n\r\n#include <cstdint>\r\n\r\ntemplate<std::uint_fast64_t Modulus>\r\nclass\
    \ modint {\r\n  using u64 = std::uint_fast64_t;\r\n\r\npublic:\r\n    u64 a;\r\
    \n\r\n    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}\r\n \
    \   constexpr u64 &value() noexcept { return a; }\r\n    constexpr const u64 &value()\
    \ const noexcept { return a; }\r\n    constexpr modint operator+(const modint\
    \ rhs) const noexcept {\r\n        return modint(*this) += rhs;\r\n    }\r\n \
    \   constexpr modint operator-(const modint rhs) const noexcept {\r\n        return\
    \ modint(*this) -= rhs;\r\n    }\r\n    constexpr modint operator*(const modint\
    \ rhs) const noexcept {\r\n        return modint(*this) *= rhs;\r\n    }\r\n \
    \   constexpr modint operator/(const modint rhs) const noexcept {\r\n        return\
    \ modint(*this) /= rhs;\r\n    }\r\n    constexpr modint &operator+=(const modint\
    \ rhs) noexcept {\r\n        a += rhs.a;\r\n        if (a >= Modulus) {\r\n  \
    \          a -= Modulus;\r\n        }\r\n        return *this;\r\n    }\r\n  \
    \  constexpr modint &operator-=(const modint rhs) noexcept {\r\n        if (a\
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
    \ inv() const {\r\n        return pow(Modulus-2);\r\n    }\r\n};\r\n#line 5 \"\
    test/SWAG.test.cpp\"\n\r\n#include <iostream>\r\n\r\nusing mint = modint<998244353>;\r\
    \n\r\nstruct F {\r\n    mint a,b;\r\n    F(mint a, mint b) : a(a), b(b) {  }\r\
    \n};\r\n\r\nF op(F f1, F f2) {\r\n    return F(f2.a*f1.a, f2.a*f1.b+f2.b);\r\n\
    }\r\n\r\nint main() {\r\n    SWAG<F, op> swag;\r\n    int q; std::cin >> q;\r\n\
    \    while(q--){\r\n        int t; std::cin >> t;\r\n        if(t==0){\r\n   \
    \         int a,b; std::cin >> a >> b;\r\n            swag.push(F(a,b));\r\n \
    \       }\r\n        else if(t==1){\r\n            swag.pop();\r\n        }\r\n\
    \        else{\r\n            int x; std::cin >> x;\r\n            if(swag.empty()){\r\
    \n                std::cout << x << std::endl;\r\n                continue;\r\n\
    \            }\r\n            auto f = swag.fold_all();\r\n            std::cout\
    \ << (f.a*(mint)x + f.b).value() << std::endl;\r\n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \r\n\r\n#include \"../data_structure/SWAG.hpp\"\r\n#include \"../utility/modint.hpp\"\
    \r\n\r\n#include <iostream>\r\n\r\nusing mint = modint<998244353>;\r\n\r\nstruct\
    \ F {\r\n    mint a,b;\r\n    F(mint a, mint b) : a(a), b(b) {  }\r\n};\r\n\r\n\
    F op(F f1, F f2) {\r\n    return F(f2.a*f1.a, f2.a*f1.b+f2.b);\r\n}\r\n\r\nint\
    \ main() {\r\n    SWAG<F, op> swag;\r\n    int q; std::cin >> q;\r\n    while(q--){\r\
    \n        int t; std::cin >> t;\r\n        if(t==0){\r\n            int a,b; std::cin\
    \ >> a >> b;\r\n            swag.push(F(a,b));\r\n        }\r\n        else if(t==1){\r\
    \n            swag.pop();\r\n        }\r\n        else{\r\n            int x;\
    \ std::cin >> x;\r\n            if(swag.empty()){\r\n                std::cout\
    \ << x << std::endl;\r\n                continue;\r\n            }\r\n       \
    \     auto f = swag.fold_all();\r\n            std::cout << (f.a*(mint)x + f.b).value()\
    \ << std::endl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - data_structure/SWAG.hpp
  - utility/modint.hpp
  isVerificationFile: true
  path: test/SWAG.test.cpp
  requiredBy: []
  timestamp: '2021-01-06 14:39:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/SWAG.test.cpp
layout: document
redirect_from:
- /verify/test/SWAG.test.cpp
- /verify/test/SWAG.test.cpp.html
title: test/SWAG.test.cpp
---
