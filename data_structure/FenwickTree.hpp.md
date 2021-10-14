---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FenwickTree.test.cpp
    title: test/FenwickTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/segment_intersection.test.cpp
    title: test/geometry/segment_intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/static_range_inversion_query.test.cpp
    title: test/static_range_inversion_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/FenwickTree.hpp\"\n\r\n#include <vector>\r\
    \n#include <cassert>\r\n\r\nnamespace ebi {\r\n\r\ntemplate<class T>\r\nstruct\
    \ FenwickTree {\r\nprivate:\r\n    int n;\r\n    std::vector<T> data;\r\n\r\n\
    public:\r\n    FenwickTree(int _n) : n(_n), data(std::vector<T>(_n+1, T(0))) {\
    \ }\r\n\r\n    void add(int i, T val) {\r\n        i++;\r\n        for(int x =\
    \ i; x <= n; x += x & -x) {\r\n            data[x] += val;\r\n        }\r\n  \
    \  }\r\n\r\n    T prefix_sum(int i) {\r\n        assert(0<=i && i<=n);\r\n   \
    \     T ret = 0;\r\n        for(int x = i; x>0; x -= x & -x) {\r\n           \
    \ ret += data[x];\r\n        }\r\n        return ret;\r\n    }\r\n\r\n    T sum(int\
    \ l, int r) {\r\n        return prefix_sum(r)-prefix_sum(l);\r\n    }\r\n\r\n\
    \    // prefix_sum(x) >= key \u3068\u306A\u308B\u6700\u5C0F\u306Ex\u3092\u8FD4\
    \u3059\u95A2\u6570 O(log N)\r\n    int lower_bound(T key) {\r\n        if(key<=0)\
    \ return 0;\r\n        int x = 0;\r\n        int max = 1;\r\n        while((max<<1)\
    \ <= n) max <<= 1;\r\n        for(int k = max; k>0; k >>= 1) {\r\n           \
    \ if(x+k<=n && data[x+k]<key) {\r\n                x += k;\r\n               \
    \ key -= data[x];\r\n            }\r\n        }\r\n        return x+1;\r\n   \
    \ }\r\n};\r\n\r\n} // namespace ebi\n"
  code: "#pragma once\r\n\r\n#include <vector>\r\n#include <cassert>\r\n\r\nnamespace\
    \ ebi {\r\n\r\ntemplate<class T>\r\nstruct FenwickTree {\r\nprivate:\r\n    int\
    \ n;\r\n    std::vector<T> data;\r\n\r\npublic:\r\n    FenwickTree(int _n) : n(_n),\
    \ data(std::vector<T>(_n+1, T(0))) { }\r\n\r\n    void add(int i, T val) {\r\n\
    \        i++;\r\n        for(int x = i; x <= n; x += x & -x) {\r\n           \
    \ data[x] += val;\r\n        }\r\n    }\r\n\r\n    T prefix_sum(int i) {\r\n \
    \       assert(0<=i && i<=n);\r\n        T ret = 0;\r\n        for(int x = i;\
    \ x>0; x -= x & -x) {\r\n            ret += data[x];\r\n        }\r\n        return\
    \ ret;\r\n    }\r\n\r\n    T sum(int l, int r) {\r\n        return prefix_sum(r)-prefix_sum(l);\r\
    \n    }\r\n\r\n    // prefix_sum(x) >= key \u3068\u306A\u308B\u6700\u5C0F\u306E\
    x\u3092\u8FD4\u3059\u95A2\u6570 O(log N)\r\n    int lower_bound(T key) {\r\n \
    \       if(key<=0) return 0;\r\n        int x = 0;\r\n        int max = 1;\r\n\
    \        while((max<<1) <= n) max <<= 1;\r\n        for(int k = max; k>0; k >>=\
    \ 1) {\r\n            if(x+k<=n && data[x+k]<key) {\r\n                x += k;\r\
    \n                key -= data[x];\r\n            }\r\n        }\r\n        return\
    \ x+1;\r\n    }\r\n};\r\n\r\n} // namespace ebi"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/FenwickTree.hpp
  requiredBy: []
  timestamp: '2021-02-24 01:07:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/segment_intersection.test.cpp
  - test/FenwickTree.test.cpp
  - test/static_range_inversion_query.test.cpp
documentation_of: data_structure/FenwickTree.hpp
layout: document
redirect_from:
- /library/data_structure/FenwickTree.hpp
- /library/data_structure/FenwickTree.hpp.html
title: data_structure/FenwickTree.hpp
---
