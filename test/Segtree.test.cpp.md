---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/Segtree.hpp
    title: Segtree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/Segtree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \r\n\r\n#line 2 \"data_structure/Segtree.hpp\"\n\r\n#include <vector>\r\n\r\n\
    namespace ebi {\r\n\r\ntemplate<class Monoid, Monoid (*op)(Monoid, Monoid), Monoid\
    \ (*e)()>\r\nstruct Segtree {\r\nprivate:\r\n    std::vector<Monoid> data;\r\n\
    \    int n;\r\npublic:\r\n    Segtree(int _n) : n(1) {\r\n        while(n<_n){\r\
    \n            n <<= 1;\r\n        }\r\n        data.assign(2*n-1, e());\r\n  \
    \  }\r\n\r\n    Segtree(std::vector<Monoid> v) : n(1) {\r\n        int _n = v.size();\r\
    \n        while(n<_n){\r\n            n <<= 1;\r\n        }\r\n        data.assign(2*n-1,\
    \ e());\r\n        for(int i = 0; i<_n; i++){\r\n            data[n+i-1] = v[i];\r\
    \n        }\r\n        for(int i = n-2; i>=0; i--){\r\n            data[i] = op(data[2*i+1],\
    \ data[2*i+2]);\r\n        }\r\n    }\r\n\r\n    void set(int p, Monoid x){\r\n\
    \        int k = n+p-1;\r\n        data[k] = x;\r\n        while(k>0){\r\n   \
    \         k = (k-1)/2;\r\n            data[k] = op(data[2*k+1], data[2*k+2]);\r\
    \n        }\r\n    }\r\n\r\n    Monoid prod(int tl, int tr, int l=0, int r=-1,\
    \ int index=0){\r\n        if(r<0) r = n;\r\n        if(tr<=l || r<=tl){\r\n \
    \           return e();\r\n        }\r\n        if(tl<=l && r<=tr){\r\n      \
    \      return data[index];\r\n        }\r\n        return op(prod(tl, tr, l, (l+r)/2,\
    \ 2*index+1), prod(tl, tr, (l+r)/2, r, 2*index+2));\r\n    }\r\n\r\n    Monoid\
    \ all_prod() { return data[0]; }\r\n\r\n    Monoid operator [] (int p) { return\
    \ data[n+p-1]; }\r\n};\r\n\r\n} // namespace ebi\n#line 4 \"test/Segtree.test.cpp\"\
    \n\r\n#include <iostream>\r\n#include <cstdint>\r\n\r\nusing i64 = std::int64_t;\r\
    \n\r\ni64 op(i64 a, i64 b) { return a+b; }\r\ni64 e() { return (i64)0; }\r\n\r\
    \nint main(){\r\n    int n,q; std::cin >> n >> q;\r\n    std::vector<i64> a(n);\r\
    \n    for(int i = 0; i<n; i++){\r\n        std::cin >> a[i];\r\n    }\r\n    ebi::Segtree<i64,\
    \ op, e> seg(a);\r\n    while(q--){\r\n        int t;\r\n        std::cin >> t;\r\
    \n        if(t==0){\r\n            int p; i64 x; std::cin >> p >> x;\r\n     \
    \       seg.set(p,seg[p]+x);\r\n        }\r\n        else{\r\n            int\
    \ l,r; std::cin >> l >> r;\r\n            std::cout << seg.prod(l,r) << std::endl;\r\
    \n        }\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\
    \n\r\n#include \"../data_structure/Segtree.hpp\"\r\n\r\n#include <iostream>\r\n\
    #include <cstdint>\r\n\r\nusing i64 = std::int64_t;\r\n\r\ni64 op(i64 a, i64 b)\
    \ { return a+b; }\r\ni64 e() { return (i64)0; }\r\n\r\nint main(){\r\n    int\
    \ n,q; std::cin >> n >> q;\r\n    std::vector<i64> a(n);\r\n    for(int i = 0;\
    \ i<n; i++){\r\n        std::cin >> a[i];\r\n    }\r\n    ebi::Segtree<i64, op,\
    \ e> seg(a);\r\n    while(q--){\r\n        int t;\r\n        std::cin >> t;\r\n\
    \        if(t==0){\r\n            int p; i64 x; std::cin >> p >> x;\r\n      \
    \      seg.set(p,seg[p]+x);\r\n        }\r\n        else{\r\n            int l,r;\
    \ std::cin >> l >> r;\r\n            std::cout << seg.prod(l,r) << std::endl;\r\
    \n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - data_structure/Segtree.hpp
  isVerificationFile: true
  path: test/Segtree.test.cpp
  requiredBy: []
  timestamp: '2021-01-18 10:56:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Segtree.test.cpp
layout: document
redirect_from:
- /verify/test/Segtree.test.cpp
- /verify/test/Segtree.test.cpp.html
title: test/Segtree.test.cpp
---
