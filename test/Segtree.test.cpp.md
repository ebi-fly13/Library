---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/segtree.hpp
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
    \r\n\r\n#line 2 \"data_structure/segtree.hpp\"\n\r\n#include <vector>\r\n#include\
    \ <cassert>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class Monoid, Monoid (*op)(Monoid,\
    \ Monoid), Monoid (*e)()>\r\nstruct segtree {\r\nprivate:\r\n    int n;\r\n  \
    \  int size;\r\n    std::vector<Monoid> data;\r\npublic:\r\n    segtree(int _n)\
    \ : n(_n), size(1) {\r\n        while(size < _n) {\r\n            size <<= 1;\r\
    \n        }\r\n        data.assign(2*size, e());\r\n        return;\r\n    }\r\
    \n\r\n    segtree(const std::vector<Monoid> &v) : size(1) {\r\n        n = (int)v.size();\r\
    \n        while(size < n) {\r\n            size <<= 1;\r\n        }\r\n      \
    \  data.assign(2*size, e());\r\n        std::copy(v.begin(), v.end(), data.begin()\
    \ + size);\r\n        for(int i = size-1; i > 0; i--) {\r\n            data[i]\
    \ = op(data[i<<1|0], data[i<<1|1]);\r\n        }\r\n        return;\r\n    }\r\
    \n\r\n    void set(int p, Monoid x) {\r\n        assert(0 <= p && p < n);\r\n\
    \        p += size;\r\n        data[p] = x;\r\n        while(p > 1) {\r\n    \
    \        p >>= 1;\r\n            data[p] = op(data[p<<1|0], data[p<<1|1]);\r\n\
    \        }\r\n        return;\r\n    }\r\n\r\n    Monoid get(int p) const {\r\n\
    \        assert(0 <= p && p < n);\r\n        return data[p+size];\r\n    }\r\n\
    \r\n    Monoid prod(int l, int r) const {\r\n        assert(0 <= l && l <= r &&\
    \ r <= n);\r\n        Monoid left = e(), right = e();\r\n        l += size;\r\n\
    \        r += size;\r\n        while(l < r) {\r\n            if(l & 1) left =\
    \ op(left, data[l++]);\r\n            if(r & 1) right = op(data[--r], right);\r\
    \n            l >>= 1;\r\n            r >>= 1;\r\n        }\r\n        return\
    \ op(left, right);\r\n    }\r\n\r\n    Monoid all_prod() const {\r\n        return\
    \ data[1];\r\n    }\r\n\r\n    Monoid operator [] (int p) const { return data[size+p];\
    \ }\r\n};\r\n\r\n} // namespace ebi\r\n#line 4 \"test/Segtree.test.cpp\"\n\r\n\
    #include <iostream>\r\n#include <cstdint>\r\n\r\nusing i64 = std::int64_t;\r\n\
    \r\ni64 op(i64 a, i64 b) { return a+b; }\r\ni64 e() { return (i64)0; }\r\n\r\n\
    int main(){\r\n    int n,q; std::cin >> n >> q;\r\n    std::vector<i64> a(n);\r\
    \n    for(int i = 0; i<n; i++){\r\n        std::cin >> a[i];\r\n    }\r\n    ebi::segtree<i64,\
    \ op, e> seg(a);\r\n    while(q--){\r\n        int t;\r\n        std::cin >> t;\r\
    \n        if(t==0){\r\n            int p; i64 x; std::cin >> p >> x;\r\n     \
    \       seg.set(p,seg[p]+x);\r\n        }\r\n        else{\r\n            int\
    \ l,r; std::cin >> l >> r;\r\n            std::cout << seg.prod(l,r) << std::endl;\r\
    \n        }\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\
    \n\r\n#include \"../data_structure/segtree.hpp\"\r\n\r\n#include <iostream>\r\n\
    #include <cstdint>\r\n\r\nusing i64 = std::int64_t;\r\n\r\ni64 op(i64 a, i64 b)\
    \ { return a+b; }\r\ni64 e() { return (i64)0; }\r\n\r\nint main(){\r\n    int\
    \ n,q; std::cin >> n >> q;\r\n    std::vector<i64> a(n);\r\n    for(int i = 0;\
    \ i<n; i++){\r\n        std::cin >> a[i];\r\n    }\r\n    ebi::segtree<i64, op,\
    \ e> seg(a);\r\n    while(q--){\r\n        int t;\r\n        std::cin >> t;\r\n\
    \        if(t==0){\r\n            int p; i64 x; std::cin >> p >> x;\r\n      \
    \      seg.set(p,seg[p]+x);\r\n        }\r\n        else{\r\n            int l,r;\
    \ std::cin >> l >> r;\r\n            std::cout << seg.prod(l,r) << std::endl;\r\
    \n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - data_structure/segtree.hpp
  isVerificationFile: true
  path: test/Segtree.test.cpp
  requiredBy: []
  timestamp: '2021-11-15 18:01:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Segtree.test.cpp
layout: document
redirect_from:
- /verify/test/Segtree.test.cpp
- /verify/test/Segtree.test.cpp.html
title: test/Segtree.test.cpp
---
